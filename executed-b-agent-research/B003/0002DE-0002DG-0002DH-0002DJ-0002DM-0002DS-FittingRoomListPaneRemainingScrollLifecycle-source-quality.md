** TARGET-REPORT-UID:0002DE **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: FittingRoomListPane Remaining Scroll/Lifecycle Cluster

Assignment: `B003-goal2-fittingroom-listpane-remaining-scroll-lifecycle-source-quality-0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-20260618`

Targets:
- [UID:0002DE] `by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md`
- [UID:0002DG] `by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md`
- [UID:0002DH] `by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md`
- [UID:0002DJ] `by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md`
- [UID:0002DM] `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`
- [UID:0002DS] `by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md`

## Finalized Report / Current Recommendation

All six targets should remain source-bearing `FittingRoomListPane` children owned and emitted through [UID:000053] `FittingRoomListPane` under [UID:0000JE] `FittingRoom` / `auto-generated/NexusTK/cashshop/FittingRoom.cpp`. The current `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`, and `RECONSTRUCTABLE:TRUE` metadata are correct.

The current "blank parent because FittingRoomListPane is below threshold" / "Do not emit final C++ yet" wording is stale for these six pages. Each target already has a nonblank emitter route and a current combined score of `86.0`, so all six clear the active code-entry gate recorded in `by-structure.md`. The supervisor should populate first-draft C++ for all six after applying the score and source-quality notes below. Remaining uncertainty is limited to original source spelling for a few virtual names and event/timer parameter names; it does not block first-draft code.

Source placement should not move to generic `Pane`, `EventHandler`, `TimerHandler`, `FittingRoomScrollPane`, or a standalone scrollbar helper. The `Pane`/`EventHandler`/`TimerHandler` code explains inherited vtable shape and callback subobject adjustments, but these bodies are FittingRoom-local virtual overrides or direct helper callbacks on the `FittingRoomListPane` complete object. The embedded scroll child is [UID:000054] `FittingRoomScrollPane`, stored at list offset `+0x11c`, but these six functions belong to the owning list pane because they position, attach, invalidate, or synchronize that child from the list pane's own vtable/callback slots.

## Evidence Checked

- Read current supervisor and agent instructions:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - `tools/leaser/Agents/Agent-B003/notes.md`
  - `by-structure.md`
  - `inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Read all six target pages and confirmed current metadata: each is `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`, and blank `RECONSTRUCTION_CPP`.
- Rechecked support docs:
  - [UID:000053] `by-class/FittingRoomListPane.md`
  - [UID:000054] `by-class/FittingRoomScrollPane.md`
  - [UID:0000JE] `by-file/FittingRoom.md`
  - [UID:0002DF] `FittingRoomListPaneUpdateScrollBar`
  - [UID:0002DL] `FittingRoomListPaneOnPaint`
  - [UID:0002DN] `FittingRoomListPaneOnInputEvent`
  - [UID:0002DQ] `ValidateFittingSelectionIndex`
  - [UID:0002DO] `FittingRoomListPaneOnInputEventJumpTables`
  - [UID:0002DT]/[UID:0002DP]/[UID:0002DU] slot geometry reports/docs
  - [UID:0002DR] `FittingRoomSelectionVectorHelpers`
  - [UID:00006T] `ItemCatalog`
  - [UID:00028I] `g_pFittingRoomDialog`
  - `by-class/Pane.md`, `by-class/EventHandler.md`, and `by-class/TimerHandler.md`
  - `by-memory/0x00544460-0x00545086.PaneCore.md`
  - `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
  - `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`
- Rechecked current generated state:
  - `auto-generated/-ag-memory-coverage.md` lists all six as `emits` through `000053` to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
  - `project-level/-auto-completion-stats.md` lists all six at `84/88`, combined `86.0`.
  - `by-memory/-coverage-report.md` rows still carry stale blank-parent/below-threshold wording.
  - `auto-generated/NexusTK/cashshop/FittingRoom.cpp` already contains first-draft C++ for adjacent [UID:0002DF], [UID:0002DL], [UID:0002DN], [UID:0002DQ], [UID:0002DT], [UID:0002DP], [UID:0002DU], and `FittingRoomScrollPane` support methods, but not these six targets.
- Performed a read-only PE byte/xref/vtable recheck against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`:
  - `.text` VA range `0x00401000-0x0060c600`, `.rdata` VA range `0x0060d000-0x0066c200`, `.data` VA range `0x0066d000-0x0069ce24`.
  - Direct call/jmp or VA pointer scan results:
    - `0x0041ed00`: no direct code caller; `.rdata` pointer at `0x0060dd1c`.
    - `0x0041ed90`: no direct code caller; `.rdata` pointer at `0x0060dd3c`.
    - `0x0041f0b0`: direct calls at `0x0041fd74` and `0x0041fd8f`; no `.rdata` function pointer.
    - `0x0041f220`: no direct code caller; `.rdata` pointer at `0x0060dd40`.
    - `0x0041fba0`: no direct code caller; `.rdata` pointer at `0x0060dd80`.
    - `0x00420840`: no direct code caller; `.rdata` pointer at `0x0060ddac`.
  - Direct caller scan for shared helpers:
    - `FittingRoomListPane::UpdateScrollBar` `0x0041ee10` has callers at `0x0041eb01`, `0x0041ed71`, `0x0041f0e8`, `0x0041f1ed`, `0x0041f26f`, `0x0041f4cd`, `0x0041fc02`, `0x004208b5`, and `0x00420921`.
    - `Pane::AddToLayer` `0x00544c70` is called by `0x0041f246` in [UID:0002DJ].
    - `Pane::RemoveFromLayer` `0x00544ce0` is tail-jumped by adjacent [UID:0002DK] at `0x0041f291`, supporting the lifecycle slot family.
    - `TimerHandler::ScheduleTimer` `0x005975e0` is called by `0x004208cf` and `0x0042093b` in [UID:0002DS].
    - `TimerHandler::CancelTimer` candidate `0x00597610` is called by [UID:0002DU] at `0x00420dc4`, supporting the shared list-pane timer facet naming.
    - `ItemCatalog::GetItemCount` / catalog count helper `0x00422690` is called by [UID:0002DM] at `0x0041fc49`.
    - `std::ctype<char>::do_narrow` helper `0x004a8b10` is called by [UID:0002DM] at `0x0041fbcb`.
- Rechecked relevant vtable slots:
  - `FittingRoomScrollPane` primary vtable around `0x0060dc88` maps inherited slots used here:
    - `+0x20` -> `0x00544800` `Pane::InvalidateRect` / invalidation virtual.
    - `+0x28` -> `0x00544b80` screen-bounds getter.
    - `+0x2c` -> `0x00544bd0` `Pane::SetBounds`.
    - `+0x30` -> `0x00544c70` `Pane::AddToLayer`.
    - `+0x38` -> `0x00544ce0` `Pane::RemoveFromLayer`.
  - `FittingRoomListPane` primary vtable around `0x0060dd10` maps:
    - slot `+0x0c` -> `0x0041ed00` [UID:0002DE].
    - slot `+0x2c` -> `0x0041ed90` [UID:0002DG].
    - slot `+0x30` -> `0x0041f220` [UID:0002DJ].
    - slot `+0x38` -> `0x0041f290` adjacent detach/remove sibling.
    - slot `+0x20` remains inherited `Pane::InvalidateRect`.
  - `FittingRoomListPane` EventHandler secondary vtable slot at `0x0060dd80` points to [UID:0002DM].
  - `FittingRoomListPane` TimerHandler tertiary vtable slot at `0x0060ddac` points to [UID:0002DS].

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Owner/Emitter

Validated current docs:
- The owner/emitter route through [UID:000053] `FittingRoomListPane` is correct for all six targets. The functions either sit in the class primary vtable, the class EventHandler secondary vtable, the class TimerHandler tertiary vtable, or are direct calls from [UID:0002DN] `OnInputEvent`.
- [UID:0000JE] `FittingRoom` remains the source file owner for generated output. `by-file/FittingRoom.md` already places both `FittingRoomListPane` and `FittingRoomScrollPane` under `NexusTK/cashshop/FittingRoom.cpp`.

Rejected alternatives:
- Generic `Pane` ownership is rejected. [UID:0002DG] and [UID:0002DJ] override base pane slot shapes, but their `.rdata` pointers are in the `FittingRoomListPane` vtable and they manipulate `this+0x11c` list-pane child state.
- Generic `EventHandler` ownership is rejected for [UID:0002DM]. The callback receives the EventHandler secondary pointer and subtracts `0xa0`, but this is the known pane-derived callback facet pattern. The source-facing method is still a `FittingRoomListPane` method.
- Generic `TimerHandler` ownership is rejected for [UID:0002DS]. The callback receives the TimerHandler tertiary pointer and subtracts `0xa4`, but state reads/writes go to `FittingRoomListPane` fields and the embedded scroll pane.
- `FittingRoomScrollPane` ownership is rejected. The child scroll pane is operated on, but the vtable/callback entries are on the owning list pane, and the state mirrored to the child originates from list `m_scrollPosition`.
- Standalone scrollbar helper ownership is rejected. No non-FittingRoom constructor/vtable route or external caller was found for these bodies.

Impact:
- Keep `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`, and `RECONSTRUCTABLE:TRUE`.
- Populate first-draft C++ in all six target pages because all clear the current code-entry gate.

### Rectangle, Point, Bounds, And Layer Helpers

Resolved/high-probability helper names:
- `0x004b7c30` is the shared point initializer, best source name `SetPoint` / `InitPoint`. In [UID:0002DG] it builds the render origin from incoming rectangle top/left and writes it to the inherited origin field at `this+0xac`.
- `0x004b7c50` is the shared rectangle initializer, best source name `SetRectLTRB` / `InitRectBounds`. In [UID:0002DE] it initializes both the local client rectangle and the child scrollbar rectangle.
- `0x004b7e10` is the rectangle offset helper, best source name `OffsetRect`. In [UID:0002DG] it offsets the copied incoming rectangle by the negative render origin before redispatching to the `+0x0c` bounds/update slot.
- `0x004b8e20` is the inherited `GrafPort`/pane render-region update helper used after child positioning in [UID:0002DE]. Best descriptive source name is `GrafPort::UpdateRenderRegion` or `Pane::UpdateRenderRegion`; the local vtable slot `+0x0c` is the overriding update/render-region method for `FittingRoomListPane`.
- `0x00544c70` is `Pane::AddToLayer`. [UID:0002DJ] forwards its four incoming arguments to this base helper, then attaches the child scroll pane.
- Child virtual slot `+0x28` is `Pane::GetScreenBounds` / bounds getter. [UID:0002DJ] calls it on `m_scrollPane` into a stack `RectBounds`.
- Child virtual slot `+0x2c` is `Pane::SetBounds`. [UID:0002DE] calls it on `m_scrollPane` with the right-edge scrollbar rectangle and second argument `0`.
- Child virtual slot `+0x30` is `Pane::AddToLayer`. [UID:0002DJ] calls it on `m_scrollPane` with child bounds, order/flags `0`, previous pane `this`, and the original fourth attach/layer argument.
- Child/list virtual slot `+0x20` is `Pane::InvalidateRect` / `Invalidate`. [UID:0002DH] and [UID:0002DS] use it after changing child current position and list scroll state.

Rejected alternatives:
- Treating [UID:0002DE]'s first local client rectangle as an emitted layout side effect is rejected. The body constructs a zero-origin client rectangle with width/height from incoming bounds, but the local rectangle is not consumed before the child rect and base update path. It should be documented as constructed but currently unused in this body.
- Naming `0x004b8e20` as a FittingRoom-only helper is rejected. It is inherited UI/GrafPort support and is called through broader pane/bounds update paths.

Impact:
- Support docs should record the resolved child slot identities and base helper names.
- These names are descriptive but strong enough for first-draft C++ because the helper roles and argument flow are exact.

### [UID:0002DE] OnResize / UpdateRenderRegion

Validated behavior:
- Primary vtable-only entry at `.rdata 0x0060dd1c`, no direct code caller.
- Builds a local zero-origin client rectangle from incoming bounds dimensions. The rectangle is not reused by the remaining body.
- Builds the child scroll-pane rectangle as:
  - `left = bounds->right - 16`
  - `top = bounds->top + 21`
  - `right = bounds->right - 3`
  - `bottom = bounds->bottom - 21`
- Reads `m_scrollPane` at `this+0x11c` and calls child slot `+0x2c` (`Pane::SetBounds`) with that rectangle and second argument `0`.
- Calls inherited bounds/render update helper `0x004b8e20` with the original incoming bounds pointer.
- Calls [UID:0002DF] `FittingRoomListPane::UpdateScrollBar`.

Best source-facing name/signature:
- Current doc name `FittingRoomListPane::OnResize` remains acceptable and matches support docs.
- Slot identity is also consistent with an overridden `UpdateRenderRegion` / bounds-update virtual. If the supervisor normalizes names to base vtable semantics, record `OnResize` as the historical/descriptive alias and `UpdateRenderRegion` as the slot role. The code body is unchanged.
- Signature should be `void FittingRoomListPane::OnResize(const RectBounds* bounds)` or equivalent one-argument bounds update method. The function ends with `ret 4`.

Remaining uncertainty:
- Exact original source spelling of the slot is not proven. This caps confidence below the mid-90s but does not block C++.

### [UID:0002DG] OnMovePane / SetBounds

Validated behavior:
- Primary vtable-only entry at `.rdata 0x0060dd3c`, no direct code caller.
- Occupies the slot corresponding to inherited `Pane::SetBounds` (`+0x2c`).
- Ends with `ret 8`; the second argument is not used by the body.
- Builds a point from incoming rectangle top/left, writes the inherited origin field at `this+0xac`, copies the full incoming rectangle, offsets it by the negative origin, and dispatches the localized rectangle through this object's slot `+0x0c` ([UID:0002DE] / update-render-region slot).

Best source-facing name/signature:
- The strongest slot-based name is `FittingRoomListPane::SetBounds(const RectBounds* bounds, int flags)`.
- The current target/support name `OnMovePane` is still a defensible descriptive alias because the behavior is the pane move/bounds-change override. If the supervisor preserves historical target names, keep the doc title as `OnMovePane` but add that it is the `Pane::SetBounds` vtable override.

Rejected alternatives:
- A standalone move notification callback is weaker than `SetBounds` because the body exactly matches the inherited set-bounds/localize-then-update shape and uses the primary vtable slot matching `Pane::SetBounds`.
- A FittingRoomScrollPane method is rejected because all writes and virtual dispatch use the list pane complete object.

Impact:
- Raise enough to populate C++; keep a confidence cap because the original source name may have been `SetBounds`, `OnMovePane`, or a project-specific bounds update name.

### [UID:0002DH] OnScrollPositionChanged

Validated behavior:
- Direct calls from [UID:0002DN] at `0x0041fd74` and `0x0041fd8f`; no vtable pointer found.
- Ends with `ret 0xc`: three stack arguments.
- First argument is unused in this body. OnInputEvent passes zero at the observed call sites, so it is probably a sender/reserved pointer or callback context.
- Second and third arguments are old and new scroll positions. The body compares the two 16-bit values and returns immediately if unchanged.
- On change, writes new position to list `m_scrollPosition` at `this+0x108`.
- Mirrors new position to child scroll pane `m_currentPosition` at child `+0xfe` when it differs, invalidating the child after the write.
- Calls [UID:0002DF] `UpdateScrollBar`.
- Invalidates the list pane after synchronization.

Best source-facing name/signature:
- `void FittingRoomListPane::OnScrollPositionChanged(FittingRoomScrollPane* sender, short oldPosition, short newPosition)` is the most useful source-facing signature.
- If the supervisor wants to preserve observed argument use exactly, use `void FittingRoomListPane::OnScrollPositionChanged(void* sender, short oldPosition, short newPosition)` and document that current callers pass zero for `sender`.

Rejected alternatives:
- Treating this as a generic scroll-pane method is rejected because direct callers are list-pane input paths and the function writes the list-pane `m_scrollPosition` before mirroring to the child.

Impact:
- Direct callers and exact state synchronization make this target stronger than the current score. Populate C++.

### [UID:0002DJ] OnInsertPane / AddToLayer Override

Validated behavior:
- Primary vtable-only entry at `.rdata 0x0060dd40`, no direct code caller.
- Occupies the slot corresponding to inherited `Pane::AddToLayer` (`+0x30`).
- Ends with `ret 0x10`: four stack arguments.
- Forwards all four original arguments to base `Pane::AddToLayer` at `0x00544c70`.
- Reads `m_scrollPane` at `this+0x11c`.
- Calls child slot `+0x28` (`Pane::GetScreenBounds`) into a stack `RectBounds`.
- Calls child slot `+0x30` (`Pane::AddToLayer`) with child bounds, `0`, previous pane `this`, and the original fourth attach/layer argument.
- Calls [UID:0002DF] `UpdateScrollBar`.

Best source-facing name/signature:
- Strongest slot-based name is `FittingRoomListPane::AddToLayer(const RectBounds* bounds, int order, Pane* previousPane, Layer* layerOrContext)`.
- Current doc name `OnInsertPane` remains acceptable as the higher-level lifecycle role. If historical names are preserved, document it as the list-pane insert/attach override for the base `Pane::AddToLayer` slot.

Rejected alternatives:
- Treating child slot `+0x28/+0x30` as custom FittingRoomScrollPane callbacks is rejected; the scroll-pane vtable inherits the same `Pane::GetScreenBounds` and `Pane::AddToLayer` slots.
- Treating the four arguments as fully solved original names is too strong. The role is exact, but base-layer helper parameter names remain inherited-support uncertainty.

Impact:
- Populate C++; confidence remains below `90+` because layer/attach parameter names are inherited and not source-spelling-proven.

### [UID:0002DM] OnKeyScroll

Validated behavior:
- EventHandler secondary vtable entry at `.rdata 0x0060dd80`, no direct code caller.
- Receiver `ecx` is the EventHandler secondary subobject. The body uses complete-object fields at `ecx - 0xa0`, matching the pane-derived EventHandler pattern documented in `EventHandler.md` and `FittingRoomScrollPane.md`.
- Guards on `event + 4 == 8`, matching EventMan key-down event type from the executed input report and support docs.
- Calls `std::ctype<char>::do_narrow` at `0x004a8b10` on the key byte at `event + 8`, with fallback/default byte at `event + 0x10a`.
- Handles only normalized key bytes `0x93` and `0x94`, and only when the fallback/modifier byte at `event + 0x10a` is zero.
- `0x93` scrolls one page up:
  - row mode (`m_displayMode == FittingRoomListDisplayMode_Rows`) subtracts `26`;
  - grid mode subtracts `3`;
  - clamps at zero.
- `0x94` scrolls one page down:
  - row mode adds `26`;
  - grid mode adds `3`;
  - queries total active-category item count through `g_pFittingRoomDialog` / `FittingRoomDialogItemState` / `ItemCatalog::GetItemCount`;
  - row-mode max is `totalItems - 26`;
  - grid-mode max is `ceil(totalItems / 6) - 3`;
  - clamps negative max/current back to zero through the same pattern used by [UID:0002DF].
- On handled key, calls [UID:0002DF] `UpdateScrollBar`, invalidates the list pane, and returns handled/true.
- Non-key events, unsupported keys, and nonzero fallback/modifier byte return unhandled/false without side effects.

Best source-facing names/types:
- Source-facing receiver should be `bool FittingRoomListPane::OnKeyScroll(EventRecord* event)` or the project-local event type used by [UID:0002DN]. Do not preserve the decompiler's `this - 0xa0` in source C++.
- Event type constant should be documented as `EventType_KeyDown = 8`, matching the input report's type `3` left-button release and type `7` mouse-wheel mapping.
- Key constants should be descriptive: `kFittingRoomKeyPageUp = 0x93` and `kFittingRoomKeyPageDown = 0x94`, or project-level `EventKey_PageUp/PageDown` if the supervisor has a broader key enum. The numeric values are exact; original enum names are not proven.
- The byte at `event+0x10a` should remain `fallback/modifier byte` until the global event structure is finalized. The behavior is exact: nonzero blocks page scrolling, and the byte is passed as `do_narrow` fallback/default.

Rejected alternatives:
- Treating key codes `0x93/0x94` as Windows `VK_PRIOR/VK_NEXT` values is rejected because the numeric values do not match Win32 `VK_PRIOR=0x21` / `VK_NEXT=0x22`. They are project/EventMan key codes after event normalization.
- Treating `this+0x10a` enabled-item count as the scroll-range source is rejected. Page-down max uses total active-category item count, consistent with [UID:0002DF] `UpdateScrollBar`, not the enabled-item counter.

Impact:
- Populate C++; remaining uncertainty is event struct field spelling and global key enum naming, not behavior.

### [UID:0002DS] OnScrollStep

Validated behavior:
- TimerHandler tertiary vtable entry at `.rdata 0x0060ddac`, no direct code caller.
- Receiver `ecx` is the TimerHandler tertiary subobject. The complete `FittingRoomListPane` object is `ecx - 0xa4`.
- Ends with `ret 0xc`; only the first argument is semantically used as the scroll-step direction/timer event id. The remaining two callback arguments are unused.
- Direction `1` decrements the child/list scroll current position by one and clamps at zero.
- Direction `2` increments the child/list scroll current position by one and clamps to child `m_maxPosition` at `+0x100`.
- Other direction values return false/unhandled without scheduling another timer.
- When the clamped position changes:
  - writes list `m_scrollPosition` at `this+0x108`;
  - mirrors child `m_currentPosition` at child `+0xfe`;
  - invalidates child when the mirrored child value changes;
  - calls [UID:0002DF] `UpdateScrollBar`;
  - invalidates the list pane.
- For handled directions, schedules the next repeat timer through `TimerHandler::ScheduleTimer` at `0x005975e0` with `(eventId = direction, interval = 50, payload1 = 0, payload2 = 0)`. This happens even if the direction was handled but the current value was already clamped and no position changed.

Best source-facing names/types:
- Source-facing receiver should be `bool FittingRoomListPane::OnScrollStep(int direction, int arg1, int arg2)` or equivalent timer callback method on `FittingRoomListPane`. Do not preserve the decompiler's `this - 0xa4`.
- Direction constants should be descriptive: `kFittingRoomScrollStepUp = 1` and `kFittingRoomScrollStepDown = 2`. Numeric mapping is exact.
- `50` is the repeat interval/delay value passed to the generic timer scheduler. The exact unit is governed by `TimerMgr`; current support docs should call it interval/delay, not a timer id.

Rejected alternatives:
- Treating `direction` as a scroll amount is rejected because only exact values `1` and `2` are accepted, and the timer is rescheduled using the same value as event id.
- Treating the callback as generic `TimerHandler` source is rejected because all state is list-pane and child scroll-pane state, with only the inherited scheduling helper from `TimerHandler`.

Impact:
- Populate C++; confidence remains capped by original direction enum and timer callback parameter names.

### List/Grid Math Consistency With Executed Reports

The six targets are consistent with the executed [UID:0002DF]/[UID:0002DN]/slot-geometry conclusions:
- `m_scrollPosition` is list `this+0x108`.
- `m_enabledItemCount` is list `this+0x10a`, but it is not the scroll-range source for [UID:0002DM].
- `m_displayMode` is list `this+0x10c`, with `FittingRoomListDisplayMode_Rows` and `FittingRoomListDisplayMode_Grid`.
- `m_scrollPane` is list `this+0x11c`.
- Row page size is `26`.
- Grid page size is `3` visible rows, with `6` columns, so grid max uses `ceil(totalItems / 6) - 3`.
- Scroll max/current clamp remains `0..30000` in the broader `UpdateScrollBar` path.
- Child scroll-pane current/range/visible fields remain `+0xfe`, `+0x100`, and `+0x102`.
- `this+0xa0` is the EventHandler facet used by [UID:0002DM].
- `this+0xa4` is the TimerHandler facet used by [UID:0002DS] and slot-layout cleanup.
- `this+0x124` remains the provisional pending timer/event id field from [UID:0002DU], not used directly by the current six targets.

## Recommended Metadata And Score Changes

Recommended target metadata:

| UID | Current | Recommended | Owner/emitter | Rationale |
| --- | --- | --- | --- | --- |
| `0002DE` | `84/88` | `86/90` | keep `000053` / `000053` | Exact vtable slot, bounds math, child SetBounds slot, inherited update helper, and UpdateScrollBar call are solved. Original source spelling `OnResize` vs update-render-region remains a confidence cap. |
| `0002DG` | `84/88` | `87/90` | keep `000053` / `000053` | Slot identity as `Pane::SetBounds` override, origin/localization flow, and virtual redispatch are solved. Name alias `OnMovePane` vs `SetBounds` remains the only material cap. |
| `0002DH` | `84/88` | `87/90` | keep `000053` / `000053` | Direct call sites, three-argument signature, old/new guard, list-child synchronization, and invalidation/update sequence are exact. First unused argument name remains provisional. |
| `0002DJ` | `84/88` | `86/90` | keep `000053` / `000053` | Slot identity as AddToLayer/insert override, base forwarding, child GetScreenBounds/AddToLayer slots, and UpdateScrollBar call are solved. Inherited layer parameter names remain provisional. |
| `0002DM` | `84/88` | `86/89` | keep `000053` / `000053` | EventHandler facet, key-event guard, key codes, page-size math, ItemCatalog count route, clamp, invalidation, and UpdateScrollBar call are solved. Event structure field names and original key enum names remain caps. |
| `0002DS` | `84/88` | `86/89` | keep `000053` / `000053` | TimerHandler facet, direction values, child/list synchronization, invalidation, UpdateScrollBar call, and repeat timer scheduling are solved. Original direction enum/timer callback parameter names remain caps. |

Support metadata:
- Keep [UID:000053] `FittingRoomListPane` at `85/87` unless the supervisor wants a class-level score bump after this incorporation. The class page still carries broad item-part enum and preview-field naming blockers from the executed paint/input scope; this report does not solve those unrelated class-wide blockers.
- Keep [UID:0000JE] `FittingRoom` at its current score. Source placement is validated, but no file-level split/owner change is needed.
- No `EMITTER_POSITION_OPTIONAL` changes are required.

## First-Draft C++ Recommendation

The following code is suitable for the six target `RECONSTRUCTION_CPP` blocks after supervisor incorporation. Reuse the existing constants and field names already emitted by adjacent FittingRoomListPane/FittingRoomScrollPane pages: `FittingRoomListDisplayMode_Rows`, `FittingRoomListDisplayMode_Grid`, `kFittingRoomRowPageSize`, `kFittingRoomGridPageRows`, `kFittingRoomGridColumns`, and `kFittingRoomMaxScroll`. If the generated file already defines these helpers, do not duplicate the definitions.

Recommended additional constants if not already declared by support code:

```cpp
static const unsigned char kFittingRoomKeyPageUp = 0x93;
static const unsigned char kFittingRoomKeyPageDown = 0x94;
static const int kFittingRoomScrollStepUp = 1;
static const int kFittingRoomScrollStepDown = 2;
static const int kFittingRoomScrollStepRepeatInterval = 50;
```

[UID:0002DE] recommended C++:

```cpp
void FittingRoomListPane::OnResize(const RectBounds* bounds)
{
    RectBounds clientBounds;
    SetRectLTRB(&clientBounds,
                0,
                0,
                bounds->right - bounds->left,
                bounds->bottom - bounds->top);

    RectBounds scrollBounds;
    SetRectLTRB(&scrollBounds,
                bounds->right - 16,
                bounds->top + 21,
                bounds->right - 3,
                bounds->bottom - 21);

    m_scrollPane->SetBounds(&scrollBounds, 0);
    UpdateRenderRegion(bounds);
    UpdateScrollBar();
}
```

Supervisor note for [UID:0002DE]: if inherited support uses `GrafPort::UpdateRenderRegion` or `Pane::UpdateRenderRegion` instead of unqualified `UpdateRenderRegion`, use the local project spelling. The first `clientBounds` construction is retained because it exists in the binary even though this body does not consume it afterward.

[UID:0002DG] recommended C++ using the existing target name:

```cpp
void FittingRoomListPane::OnMovePane(const RectBounds* bounds, int flags)
{
    (void)flags;

    Point origin;
    SetPoint(&origin, bounds->top, bounds->left);
    SetPoint(&m_origin, origin.x, origin.y);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -origin.y, -origin.x);
    OnResize(&localBounds);
}
```

Supervisor note for [UID:0002DG]: the slot identity supports renaming this method to `SetBounds` in formal C++ if the supervisor standardizes inherited pane virtual names. In that case, only the method name should change:

```cpp
void FittingRoomListPane::SetBounds(const RectBounds* bounds, int flags)
```

[UID:0002DH] recommended C++:

```cpp
void FittingRoomListPane::OnScrollPositionChanged(FittingRoomScrollPane* sender,
                                                  short oldPosition,
                                                  short newPosition)
{
    (void)sender;

    if (oldPosition == newPosition) {
        return;
    }

    m_scrollPosition = newPosition;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_currentPosition != newPosition) {
        scrollPane->m_currentPosition = newPosition;
        scrollPane->Invalidate();
    }

    UpdateScrollBar();
    Invalidate();
}
```

[UID:0002DJ] recommended C++ using the existing target name:

```cpp
void FittingRoomListPane::OnInsertPane(const RectBounds* bounds,
                                       int order,
                                       Pane* previousPane,
                                       Layer* layerOrContext)
{
    Pane::AddToLayer(bounds, order, previousPane, layerOrContext);

    RectBounds childBounds;
    m_scrollPane->GetScreenBounds(&childBounds);
    m_scrollPane->AddToLayer(&childBounds, 0, this, layerOrContext);

    UpdateScrollBar();
}
```

Supervisor note for [UID:0002DJ]: the slot identity supports renaming this method to the inherited `AddToLayer` override if project style requires it. The exact fourth parameter name remains inherited-support provisional; the observed binary passes the original fourth argument to the child attach call.

[UID:0002DM] recommended C++:

```cpp
bool FittingRoomListPane::OnKeyScroll(EventRecord* event)
{
    if (event->type != EventType_KeyDown) {
        return false;
    }

    const unsigned char key = NarrowEventKeyByte(event->keyByte, event->fallbackByte);
    if (event->fallbackByte != 0) {
        return false;
    }

    const bool rowMode = (m_displayMode == FittingRoomListDisplayMode_Rows);
    const short pageSize = static_cast<short>(
        rowMode ? kFittingRoomRowPageSize : kFittingRoomGridPageRows);

    if (key == kFittingRoomKeyPageUp) {
        short nextPosition = static_cast<short>(m_scrollPosition - pageSize);
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    if (key == kFittingRoomKeyPageDown) {
        FittingRoomDialog* dialog = g_pFittingRoomDialog;
        FittingRoomDialogItemState* itemState = &dialog->m_itemState;
        const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);
        const short totalItems = itemState->GetItemCount(category);

        short nextPosition = static_cast<short>(m_scrollPosition + pageSize);
        const int maxPosition = rowMode
            ? (totalItems - pageSize)
            : (((totalItems + (kFittingRoomGridColumns - 1)) / kFittingRoomGridColumns)
                - pageSize);

        if (nextPosition > maxPosition) {
            nextPosition = static_cast<short>(maxPosition);
        }
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    return false;
}
```

Supervisor note for [UID:0002DM]: `NarrowEventKeyByte` is a source-facing wrapper name for the observed `std::ctype<char>::do_narrow` call at `0x004a8b10`. If the event support docs settle exact field names, replace `keyByte` and `fallbackByte` with those names. Keep the semantics: key at `event+8`, fallback/modifier/default byte at `event+0x10a`, and nonzero fallback/modifier rejects page scrolling.

[UID:0002DS] recommended C++:

```cpp
bool FittingRoomListPane::OnScrollStep(int direction, int arg1, int arg2)
{
    (void)arg1;
    (void)arg2;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    short nextPosition = scrollPane->m_currentPosition;

    if (direction == kFittingRoomScrollStepDown) {
        ++nextPosition;
        if (nextPosition > scrollPane->m_maxPosition) {
            nextPosition = scrollPane->m_maxPosition;
        }
    } else if (direction == kFittingRoomScrollStepUp) {
        --nextPosition;
        if (nextPosition < 0) {
            nextPosition = 0;
        }
    } else {
        return false;
    }

    if (scrollPane->m_currentPosition != nextPosition) {
        m_scrollPosition = nextPosition;
        scrollPane->m_currentPosition = nextPosition;
        scrollPane->Invalidate();

        UpdateScrollBar();
        Invalidate();
    }

    m_timerHandler.ScheduleTimer(direction, kFittingRoomScrollStepRepeatInterval, 0, 0);
    return true;
}
```

Supervisor note for [UID:0002DS]: source should use the complete-object `FittingRoomListPane` method and normal timer member/facet name, not the decompiler's adjusted `ecx - 0xa4`. If the inherited class exposes timer scheduling as `TimerHandler::ScheduleTimer`, use that spelling with receiver `this+0xa4`.

## Exact Supervisor Changes Required

Apply these as supervisor-owned changes only. B003 did not edit target docs or generated files.

### Target Metadata

For each target, update only the metadata value lines as follows:

```text
[UID:0002DE] COMPLETION:86, CONFIDENCE:90, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
[UID:0002DG] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
[UID:0002DH] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
[UID:0002DJ] COMPLETION:86, CONFIDENCE:90, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
[UID:0002DM] COMPLETION:86, CONFIDENCE:89, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
[UID:0002DS] COMPLETION:86, CONFIDENCE:89, CANONICAL_OWNER:000053, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000053
```

Populate each target `RECONSTRUCTION_CPP` block with the corresponding first-draft C++ above.

### Target Page Section Updates

In each target page's `## Reconstruction Status`, replace stale blank-C++/below-threshold wording with this target-specific common paragraph, adjusted by UID/name:

```text
2026-06-18 B003 source-quality reanalysis: This target now clears the active first-draft C++ gate (`RECONSTRUCTABLE:TRUE`, nonblank emitter route through [UID:000053], and combined completion/confidence above 85). Keep source placement under [UID:000053] `FittingRoomListPane` / [UID:0000JE] `FittingRoom.cpp`; do not reroute to generic Pane/EventHandler/TimerHandler or to FittingRoomScrollPane. Populate the formal C++ block with the B003 first-draft body while preserving the remaining confidence caps for original source spelling and inherited support parameter names.
```

Add the following target-specific facts to the `## Behavior` or `## Raw Code Evidence` sections:

[UID:0002DE]:
```text
- The child scrollbar rectangle is `right - 16, top + 21, right - 3, bottom - 21`; child virtual slot `+0x2c` is inherited `Pane::SetBounds`.
- The zero-origin client rectangle is constructed from incoming width/height but is not consumed later in this body before the inherited render-region update and `UpdateScrollBar` call.
- `0x004b8e20` is best treated as inherited `GrafPort`/pane render-region update support, not a FittingRoom-local helper.
```

[UID:0002DG]:
```text
- This body occupies the inherited `Pane::SetBounds`/move slot (`+0x2c`) and ends with `ret 8`; the second argument is unused.
- It writes the inherited render origin at `this+0xac`, copies and offsets the input rectangle by the negative origin, then redispatches through list-pane slot `+0x0c` to update local bounds/render region.
- Keep `OnMovePane` as the historical/descriptive name if desired, but record `SetBounds` as the slot role.
```

[UID:0002DH]:
```text
- Direct callers at `0x0041fd74` and `0x0041fd8f` pass a reserved/sender argument plus old and new 16-bit scroll positions.
- The first argument is unused; current call sites pass zero.
- On change, the body writes list `m_scrollPosition` (`this+0x108`), mirrors child `m_currentPosition` (`m_scrollPane+0xfe`), invalidates child/list panes, and calls `UpdateScrollBar`.
```

[UID:0002DJ]:
```text
- This body occupies the inherited `Pane::AddToLayer`/insert slot (`+0x30`) and ends with `ret 0x10`.
- It forwards its four incoming arguments to base `Pane::AddToLayer`, fetches child screen bounds through child slot `+0x28`, attaches the child through child slot `+0x30` with previous pane `this` and the original fourth attach/layer argument, then calls `UpdateScrollBar`.
- Keep `OnInsertPane` as the historical/descriptive name if desired, but record `AddToLayer` as the slot role.
```

[UID:0002DM]:
```text
- The receiver is the `EventHandler` secondary facet at `this+0xa0`; source C++ should use a normal `FittingRoomListPane` method rather than preserving the decompiler adjustment.
- Event type `8` is key-down. The key byte at `event+8` is normalized through `std::ctype<char>::do_narrow` using the byte at `event+0x10a` as fallback/default; a nonzero `event+0x10a` rejects page scrolling.
- Exact handled key values are `0x93` page-up and `0x94` page-down. These are project/EventMan key values, not Win32 `VK_PRIOR/VK_NEXT`.
- Row-mode page size is `26`; grid-mode page size is `3` rows with `6` columns. Page-down max uses total active-category item count from the same ItemCatalog route as `UpdateScrollBar`, not `m_enabledItemCount`.
```

[UID:0002DS]:
```text
- The receiver is the `TimerHandler` tertiary facet at `this+0xa4`; source C++ should use a normal `FittingRoomListPane` method and timer member/facet rather than preserving the decompiler adjustment.
- Direction `1` decrements/up and clamps to zero; direction `2` increments/down and clamps to child `m_maxPosition` (`m_scrollPane+0x100`); all other direction values return false without rescheduling.
- Handled directions reschedule the repeat timer through `TimerHandler::ScheduleTimer(direction, 50, 0, 0)`. The first argument is the direction/event id; `50` is the repeat interval/delay value.
```

### Support Doc Updates

In `by-class/FittingRoomListPane.md`, update the method table rows for these targets to preserve current names but add slot/callback roles:

```text
| [UID:0002DE][0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize](by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md) | `OnResize` / render-region update slot | Positions the right-edge scroll child at `(right-16, top+21, right-3, bottom-21)`, dispatches child `Pane::SetBounds`, runs inherited render-region update, and recomputes scroll range. |
| [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md) | `OnMovePane` / `SetBounds` override | Writes inherited origin `this+0xac`, localizes the incoming bounds rectangle, then redispatches through the list-pane render-region/update slot. |
| [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md) | `OnScrollPositionChanged` | Direct input-scroll callback that synchronizes list `m_scrollPosition` with child `m_currentPosition`, invalidates changed panes, and refreshes scroll range. |
| [UID:0002DJ][0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane](by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md) | `OnInsertPane` / `AddToLayer` override | Forwards to base layer attach, inserts the embedded scroll pane through child `GetScreenBounds`/`AddToLayer` slots, and refreshes scroll range. |
| [UID:0002DM][0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll](by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md) | `OnKeyScroll` | EventHandler-facet key-down callback for project key values `0x93`/`0x94`, using row page size `26` or grid page size `3` and the active ItemCatalog count for max clamp. |
| [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md) | `OnScrollStep` | TimerHandler-facet repeat callback: direction `1` scrolls up, direction `2` scrolls down, handled directions reschedule `ScheduleTimer(direction, 50, 0, 0)`. |
```

Add this evidence bullet near the existing 2026-06-18 B003 class evidence bullets:

```text
- 2026-06-18 B003 remaining scroll/lifecycle source-quality reanalysis of [UID:0002DE], [UID:0002DG], [UID:0002DH], [UID:0002DJ], [UID:0002DM], and [UID:0002DS] resolves the right-edge child bounds formula, inherited point/rect/offset/render-region helper roles, child virtual slot identities (`GetScreenBounds`, `SetBounds`, `AddToLayer`, `Invalidate`), list scroll fields `+0x108/+0x10c/+0x11c`, EventHandler and TimerHandler adjusted receiver source shape, key-down type `8`, project key values `0x93/0x94`, scroll-step directions `1/2`, repeat timer interval `50`, and consistency with the executed UpdateScrollBar/InputEvent/slot-geometry page-size math. Scores remain class-level `85/87` unless the supervisor chooses a class score bump; remaining class blockers are still broader item-part/preview/event-field spelling issues, not these six children.
```

In `by-class/FittingRoomScrollPane.md`, no score change is needed. Optionally add this cross-note near the owner/list synchronization paragraph:

```text
- The owner list pane's [UID:0002DH] and [UID:0002DS] methods write list `m_scrollPosition` and mirror child `m_currentPosition`/`m_maxPosition`; this validates the existing `FittingRoomScrollPane +0xfe/+0x100` current/range field names and keeps synchronization ownership on `FittingRoomListPane`.
```

In `by-file/FittingRoom.md`, no score change is required. Optionally add this support note:

```text
- 2026-06-18 B003 remaining FittingRoomListPane lifecycle/key/timer reanalysis keeps `OnResize`, `OnMovePane`/`SetBounds`, `OnScrollPositionChanged`, `OnInsertPane`/`AddToLayer`, `OnKeyScroll`, and `OnScrollStep` under `NexusTK/cashshop/FittingRoom.cpp`; the generic Pane/EventHandler/TimerHandler helpers explain inherited/callback mechanics but do not own these FittingRoom-local methods.
```

### Validation Commands For Supervisor

After applying the supervisor changes and regenerating derived output, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-FittingRoomListPaneRemainingScrollLifecycle-source-quality-removed.md](0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-FittingRoomListPaneRemainingScrollLifecycle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected:
- Coverage rows show scores `86`, `87`, `87`, `86`, `86`, `86` for the six UIDs and no stale below-threshold/blank-parent wording.
- Target pages no longer contain stale final-C++ blockers for these six.
- Generated `FittingRoom.cpp` contains first-draft bodies for all six targets.

## Coverage Report Replacement Text

Replace the six existing rows in `by-memory/-coverage-report.md` under the FittingRoom list-pane section with these rows. Preserve surrounding indentation and unrelated rows.

```text
        - [UID:0002DE][0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize](by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md) 0x0041ed00-0x0041ed88 | method | FittingRoomListPaneOnResize : reconstructable : 86% : strong : Source-quality reanalysis confirms exact vtable-only ownership, right-edge scroll-child rectangle `(right-16, top+21, right-3, bottom-21)`, child `Pane::SetBounds` slot use, inherited render-region update, UpdateScrollBar refresh, and first-draft C++ readiness; exact original slot name remains `OnResize` versus render-region-update spelling cap.
        - [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md) 0x0041ed90-0x0041ee03 | method | FittingRoomListPaneOnMovePane : reconstructable : 87% : strong : Source-quality reanalysis confirms exact vtable-only ownership, inherited `Pane::SetBounds` slot role, origin write at `this+0xac`, localized bounds copy/offset, redispatch through list slot `+0x0c`, and first-draft C++ readiness; `OnMovePane` remains a descriptive alias for the move/bounds override.
        - [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md) 0x0041f0b0-0x0041f0fd | callback | FittingRoomListPaneOnScrollPositionChanged : reconstructable : 87% : strong : Source-quality reanalysis confirms two OnInputEvent caller sites, three-argument callback shape, unused sender/reserved argument, old/new scroll guard, list `m_scrollPosition` and child `m_currentPosition` synchronization, child/list invalidation, UpdateScrollBar refresh, and first-draft C++ readiness.
        - [UID:0002DJ][0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane](by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md) 0x0041f220-0x0041f286 | method | FittingRoomListPaneOnInsertPane : reconstructable : 86% : strong : Source-quality reanalysis confirms exact vtable-only ownership, inherited `Pane::AddToLayer` slot role, base layer-helper forwarding, child `GetScreenBounds`/`AddToLayer` virtual slot identities, final UpdateScrollBar refresh, and first-draft C++ readiness; inherited layer-parameter names remain provisional.
        - [UID:0002DM][0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll](by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md) 0x0041fba0-0x0041fcc5 | method | FittingRoomListPaneOnKeyScroll : reconstructable : 86% : strong : Source-quality reanalysis confirms EventHandler-facet receiver adjustment, key-down event type `8`, `std::ctype<char>::do_narrow` key normalization, project key values `0x93`/`0x94`, row/grid page sizes `26`/`3`, active ItemCatalog count route, clamp behavior, UpdateScrollBar refresh, invalidation, and first-draft C++ readiness; event-field and key-enum spellings remain provisional.
        - [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md) 0x00420840-0x00420949 | method | FittingRoomListPaneOnScrollStep : reconstructable : 86% : strong : Source-quality reanalysis confirms TimerHandler-facet receiver adjustment, direction `1` up/decrement and `2` down/increment semantics, child current/range clamp, list/child synchronization, UpdateScrollBar refresh, child/list invalidation, repeat scheduling through `TimerHandler::ScheduleTimer(direction, 50, 0, 0)`, and first-draft C++ readiness; direction enum and timer callback parameter names remain provisional.
```

No replacement is needed in `auto-generated/-ag-memory-coverage.md`; those rows already show `emits` through `000053` to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`. The generated coverage file should update naturally after the target pages receive nonblank C++.

## Remaining Blockers

These blockers should remain explicit confidence caps, not C++ blockers:

- Exact original source spelling for [UID:0002DE] slot name is not proven. `OnResize` is consistent with current docs and behavior; `UpdateRenderRegion` / `OnUpdateRenderRegion` is consistent with vtable slot role and inherited helper use. Evidence checked: primary vtable slot, child bounds positioning, inherited update helper, and no direct callers. No stronger inference is possible without original symbols or more source-named analogs.
- Exact original source spelling for [UID:0002DG] and [UID:0002DJ] is not proven. Slot evidence strongly supports `SetBounds` and `AddToLayer` override roles; existing names `OnMovePane` and `OnInsertPane` are descriptive lifecycle aliases. Evidence checked: primary vtable slot offsets, base helper identities, return stack cleanup sizes, and child/layer dispatches.
- Inherited `Pane::AddToLayer` parameter names remain provisional. Evidence checked: [UID:0002DJ] forwards four incoming args to `0x00544c70`, then uses original arg4 for child attach; `PaneCore` support shows previous-pane/layer-context behavior but not final source spelling.
- Global event structure field names are not fully solved. Evidence checked: [UID:0002DM] reads event type at `+4`, key byte at `+8`, fallback/modifier/default byte at `+0x10a`, and [UID:0002DN] uses event type `3`/`7`, mouse coordinates, and wheel delta. The behavior is exact, but final event-field names should be coordinated by the EventMan/EventHandler owner.
- Key constants `0x93` and `0x94` are exact but original enum names are not proven. Rejected Win32 `VK_PRIOR/VK_NEXT` names because their numeric values do not match. Use descriptive project constants until EventMan key enum names are resolved.
- Timer callback parameter names for [UID:0002DS] remain provisional. Evidence checked: `ret 0xc`, only first argument used as direction/event id, TimerHandler schedule call uses `(direction, 50, 0, 0)`. Exact unused parameter names require broader `TimerMgr` callback signature resolution.
- Timer interval unit for `50` should be recorded as scheduler interval/delay, not over-specified as milliseconds unless the `TimerMgr` owner has proven units. Evidence checked: `TimerHandler::ScheduleTimer` wrapper docs and FittingRoomScrollPane timer body using analogous `30` repeat interval.

None of these blockers justify keeping formal C++ blank. They cap final confidence and original-name precision only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-FittingRoomListPaneRemainingScrollLifecycle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002DE"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-FittingRoomListPaneRemainingScrollLifecycle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002DE-0002DG-0002DH-0002DJ-0002DM-0002DS-FittingRoomListPaneRemainingScrollLifecycle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002DE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
