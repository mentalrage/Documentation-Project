** TARGET-REPORT-UID:0002KK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: UID 0002KK FlyingParcelPaneAnimateStep

Report path: `tools/leaser/Agents/Agent-B001/research/0002KK-FlyingParcelPaneAnimateStep-source-quality.md`

Assignment id: `B001-report-0002KK-flying-parcel-pane-animate-step-20260625`

Target: [UID:0002KK] `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`

Mode: report-only research. No target/support by-* docs, generated files, project-level files, IDA DB state, validator state, or `-coverage-report.md` files were edited in this pass. No leases were taken.

## Current Target State

The assigned target is a complete function range for the FlyingParcelPane timer/update callback:

- Range: `0x00546d70-0x00546dee`, half-open.
- Current metadata at assignment/read time: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, blank optional emitter position.
- Formal C++ block is blank.
- Current Item Summary: `Continues or completes parcel animation, then updates g_pParcelPane.`
- Existing target notes already preserve the key range fact that `0x00546d70` is the function entry, `0x00546dee` is not a function entry, and `0x00546df0` is the next sibling `FlyingParcelPaneDrawParcelOrLetter`.
- Existing target notes also already identify the adjusted tertiary-subobject route: the callback receives `ecx == owner + 0xa4`, and the Pane/FlyingParcelPane owner is recovered as `this - 0xa4`.

The current blank-C++ blocker is stale. The current evidence resolves the method-level naming, field, helper, vtable, layer-removal, and reschedule questions well enough for a first-draft formal C++ body on this by-memory target.

## Documents And Leads Checked

Current target/support docs checked:

- `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`
- `by-class/FlyingParcelPane.md`
- `by-file/ParcelPane.md`
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`
- `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md` [UID:0002R6]
- `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` [UID:0002KL]
- `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md` [UID:0002KJ]
- `by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md` [UID:0002KC]
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` [UID:0001K8]
- `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` [UID:000418]
- `by-type/by-struct/PaneLayout.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`
- `by-memory/0x00556910-0x00557132.ScreenPane.md`
- `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md`
- `by-global/g_pParcelPane.md`
- `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`

Report leads checked:

- Executed/accepted B012 `000058-FlyingParcelPane-class-source-quality.md`
- Executed/accepted B001 `0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md`
- Executed/accepted B002 parcel pane lifecycle/source-quality work

Generated and tracker state checked as read-only context:

- `auto-generated/-ag-research-tracker.md` still has a stale uncovered row for `0002KK` with old `74/84` state.
- `auto-generated/-ag-coverage-report-by-memory.md` still has stale generated coverage for this target until source metadata and executed-report state are refreshed by validator.
- `project-level/-auto-completion-stats.md` still has legacy stale score context for this item.
- `by-memory/-coverage-report.md` has legacy manual coverage context and must not be edited by B001 in this assignment.

The stale generated/manual rows are not direct evidence against the current by-memory target. They should be refreshed through normal validator/report execution or supervisor-owned manual maintenance after implementation, not manually edited by this report-only pass.

## IDA MCP Evidence

IDA MCP was available and responsive during this pass.

- Endpoint/listener status: `127.0.0.1:13337` responded to read-only checks.
- Active MCP session: `80de0a67`.
- IDB/input path reported by `idb_list`: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` reported status `ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, Hex-Rays ready, and strings cache ready.
- Tool schema was checked with `tools/list`; the active schema exposed `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `get_int`, and `make_signature_for_range`.

Function and range evidence:

- `lookup_funcs` request id 4 found `0x00546d70` as `sub_546D70`, size `0x7e` / 126 bytes (Verified with `int_convert.py`).
- `lookup_funcs` found no function at `0x00546dee`.
- `lookup_funcs` found `0x00546df0` as `sub_546DF0`, size `0x7b` / 123 bytes (Verified with `int_convert.py`).
- `get_bytes` request id 18 showed `0x00546d64-0x00546d70` is twelve `0xcc` bytes and `0x00546dee-0x00546df0` is two `0xcc` bytes.
- `make_signature_for_range` request id 16 produced a unique signature for `0x00546d70-0x00546dee`.

Reachability and vtable evidence:

- `analyze_function` request id 5 reported no direct code callers for `0x00546d70`, callees `sub_556D20`, `sub_5975E0`, and `sub_5464B0`, and a single data xref from `0x00621d4c`.
- `xrefs_to` request id 8 confirmed one data xref to `0x00546d70` from `0x00621d4c` and no direct code callers.
- `xref_query` request id 17 confirmed code xrefs to `0x00546d70` total `0` and data xrefs total `1`: `0x00621d4c -> 0x00546d70`.
- `get_bytes` request id 18 at `0x00621d48` returned `96 6e 54 00 70 6d 54 00`, which stores `0x00546e96` followed by the target callback `0x00546d70`.
- `get_int` request id 19 read `0x00621d4c` as `0x00546d70`.

Disassembly/decompilation evidence:

- `disasm` request id 7 showed the target begins with `mov esi, ecx`, uses the adjusted owner as `esi - 0xa4`, compares byte `[esi+0x54]` against `0x1e`, decrements dword `[esi+8]` in the active branch, invalidates via owner vtable slot `+0x20`, increments byte `[esi+0x54]`, schedules through `sub_5975E0(this, 0, 10, 0, 0)`, and returns `al=1` with `retn 0x0c`.
- The completion branch in the same disassembly calls owner vtable slot `+0x38`, calls `sub_556D20(g_pScreenPane, [esi+0x5c])`, calls `sub_5464B0(g_pParcelPane, [esi+0x55], [esi+0x57], [esi+0x56])`, sets `[g_pParcelPane+0xfb] = 1`, invalidates `g_pParcelPane+0x44` through vtable slot `+0x20`, returns `al=1`, and uses `retn 0x0c`.
- `decompile` request id 6 matched the same data flow. The decompiler's raw labels are `sub_556D20`, `dword_67A7CC`, `sub_5464B0`, `unk_69BA28`, and `sub_5975E0`; those are placeholder labels and should not survive in source-facing C++.

Helper/global evidence:

- `analyze_function 0x005975e0` request id 14 confirmed `sub_5975E0` forwards to `g_pTimerMgr` scheduling with this-handler plus four arguments. The current by-memory doc [UID:0001K8] names this wrapper `TimerHandler::ScheduleTimer`.
- `analyze_function 0x00556d20` request id 20 confirmed `sub_556D20` calls the layer-index lookup and layer-list removal path. Current ScreenPane docs identify it as `ScreenPane::RemoveLayer`.
- `analyze_function 0x005464b0` request id 15 confirmed `sub_5464B0` writes ParcelPane slot bytes and invalidates the ParcelPane. Current docs identify it as `ParcelPane::SetParcelSlotData`.
- `analyze_function 0x00544ce0` request id 21 confirmed vtable slot `+0x38` body removes the Pane from its current layer and clears the attached layer pointer, matching `Pane::RemoveFromLayer`.
- `analyze_function 0x00544800` request id 22 confirmed vtable slot `+0x20` is the Pane invalidation path, matching `Pane::InvalidateRect`.
- `get_int` request id 19 confirmed vtable values: `0x00621a08 -> 0x00544800` for `+0x20`, `0x00621a18 -> 0x00544c70` for `+0x30`, `0x00621a20 -> 0x00544ce0` for `+0x38`, and `0x00621a28 -> 0x00544d70` for `+0x40`.
- `get_int` request id 19 and support docs identify `0x0067a7cc` as the global ScreenPane pointer storage and `0x0069ba28` as the global ParcelPane pointer storage. Static image reads are zero-initialized, as expected for runtime-owned pointers.
- `xrefs_to` request id 8 reported nine refs to `0x0069ba28`, including target refs at `0x00546dbc` and `0x00546dd2`.

Numeric constants used in the report were verified with `tools/int_convert.py`, including:

- `0x7e` = 126, function size.
- `0x1e` = 30, frame limit.
- `0xa4` = 164, tertiary timer subobject offset.
- `0x0c` = 12, callback stack cleanup for three explicit parameters.
- `0xac` = 172, owner Pane origin offset.
- `0x54` = 84, tertiary-relative `m_animationFrame`.
- `0xf8` = 248, owner-relative `m_animationFrame`.
- `0x55` = 85 / owner `0xf9`, `m_parcelCountOrState`.
- `0x56` = 86 / owner `0xfa`, `m_rightSlot`.
- `0x57` = 87 / owner `0xfb`, `m_leftSlot`.
- `0x5c` = 92 / owner `0x100`, `m_animationLayer`.
- `0x60` = 96 / owner `0x44`, bounds rectangle.
- `0x20` = 32, vtable slot `Pane::InvalidateRect`.
- `0x38` = 56, vtable slot `Pane::RemoveFromLayer`.
- `0x0a` = 10, timer delay.

## Behavior And Data Flow

This function is a `TimerHandler`/tertiary-subobject callback for `FlyingParcelPane`, not a direct primary-vtable method. The callback receives `ecx` pointing at the tertiary timer/update subobject at owner offset `+0xa4`; source-facing method code should be written as the `FlyingParcelPane` callback while documenting that the binary uses an adjusted subobject `this`.

Active animation path:

1. Read `m_animationFrame` from tertiary-relative `[this+0x54]`, which is owner-relative `+0xf8`.
2. While `m_animationFrame < 30`, decrement owner-relative `+0xac`, the first dword of the inherited Pane origin point.
3. Invalidate the owner Pane bounds at owner `+0x44` through vtable slot `+0x20`, `Pane::InvalidateRect`.
4. Increment `m_animationFrame`.
5. Reschedule the same timer handler through `sub_5975E0(this, 0, 10, 0, 0)`, source-facing `m_timerHandler.ScheduleTimer(0, 10, 0, 0)`.
6. Return `true`.

Completion path:

1. Call owner vtable slot `+0x38`, source-facing `RemoveFromLayer()`.
2. Call `ScreenPane::RemoveLayer(g_pScreenPane, m_animationLayer)` using tertiary-relative `[this+0x5c]`, owner-relative `+0x100`.
3. Call `ParcelPane::SetParcelSlotData(g_pParcelPane, m_parcelCountOrState, m_leftSlot, m_rightSlot)`.
4. Set `g_pParcelPane->m_rightSlotActionEnabled = true` at global ParcelPane offset `+0xfb`.
5. Invalidate `g_pParcelPane->m_bounds` through `Pane::InvalidateRect`.
6. Return `true`.

The raw push order before `sub_5464B0` is right-slot, left-slot, parcel-count/state, then thiscall receiver `g_pParcelPane`; therefore the source-facing call arguments are `(m_parcelCountOrState, m_leftSlot, m_rightSlot)`.

The three explicit callback parameters are unused by the function. The `retn 0x0c` proves a three-argument callback ABI; the source-facing method should keep the parameters in the signature but leave them unnamed unless the project later standardizes exact timer callback parameter names for this class.

## Ownership, Source Placement, And Range

Confirmed direct owner/emitter remains `000058` (`FlyingParcelPane`).

Positive ownership evidence:

- The only route to `0x00546d70` is a data xref from a tertiary/timer-handler vtable slot at `0x00621d4c`, not direct code calls. This matches a callback implementation for a subobject owned by `FlyingParcelPane`.
- The body uses the adjusted owner `this - 0xa4`, and the resulting owner-relative offsets line up with the current FlyingParcelPane layout: `+0xf8` frame, `+0xf9/+0xfa/+0xfb` payload/slot bytes, and `+0x100` layer pointer.
- Sibling docs and MCP evidence form a coherent lifecycle cluster: constructor creates `m_animationLayer`, start/setup writes the payload fields and schedules the timer, this target steps/removes/hands off the animation, and draw renders the flying parcel/letter.
- `g_pParcelPane` is a dependency and handoff target, not the callback owner. The target reads/writes `g_pParcelPane` only after the FlyingParcelPane animation finishes.

Rejected ownership alternatives:

- `ParcelPane` ownership is rejected for this range. Although the completion branch calls `g_pParcelPane->SetParcelSlotData` and sets `g_pParcelPane+0xfb`, the callback's `this` adjustment and field accesses are for the FlyingParcelPane object.
- `ScreenPane` ownership is rejected. The only ScreenPane call is a layer-removal helper on `g_pScreenPane`; it is not the callback receiver or source owner.
- Standalone/raw helper ownership is rejected. The function is vtable-routed and object-stateful, with no raw rel32/caller-only helper pattern.
- A split is not needed. The range is one complete function with padding before and after; the active and completion paths are branches of one callback and should not become separate by-memory children.

Source file placement remains `ParcelPane.cpp` with the private parcel notification pane family. `FlyingParcelPane` is implementation-private/file-local or otherwise local to that family, as already documented by the accepted class/file reports. This target should not create a new source file or public class placement.

## Helper, Field, And Placeholder Reanalysis

The current evidence resolves the source-facing names that previously blocked formal C++.

Best-supported names and interpretations:

- `sub_5975E0` -> `TimerHandler::ScheduleTimer`. The target calls the wrapper on the tertiary timer handler (`ecx == owner + 0xa4`) with timer id `0`, delay `10`, and two zero payload arguments. Existing generated/source style can express this as `m_timerHandler.ScheduleTimer(0, 10, 0, 0)`.
- `sub_556D20` -> `ScreenPane::RemoveLayer`. Helper analysis and ScreenPane docs show it removes a layer entry from ScreenPane's layer list after lookup.
- `sub_5464B0` -> `ParcelPane::SetParcelSlotData`. The helper writes ParcelPane slot bytes, clears related status bytes, optionally ensures the pane is on a layer, and invalidates the ParcelPane.
- Owner vtable slot `+0x20` -> `Pane::InvalidateRect`.
- Owner vtable slot `+0x38` -> `Pane::RemoveFromLayer`.
- Tertiary-relative `+0x54` / owner `+0xf8` -> `m_animationFrame`.
- Tertiary-relative `+0x55` / owner `+0xf9` -> `m_parcelCountOrState`.
- Tertiary-relative `+0x56` / owner `+0xfa` -> `m_rightSlot`.
- Tertiary-relative `+0x57` / owner `+0xfb` -> `m_leftSlot`.
- Tertiary-relative `+0x5c` / owner `+0x100` -> `m_animationLayer`.
- Tertiary-relative `+8` / owner `+0xac` -> inherited `Pane::m_origin.x`, not a FlyingParcelPane-specific countdown or payload field.
- Global `unk_69BA28` -> `g_pParcelPane`.
- Global `dword_67A7CC` -> `g_pScreenPane`.
- `g_pParcelPane +0xfb` -> `m_rightSlotActionEnabled`, matching the accepted ParcelPane slot-action report and current struct layout.

Rejected alternatives:

- Keeping `sub_`, `dword_`, or `unk_` labels is rejected. Each raw label has a current source-facing helper/global name supported by docs and IDA evidence.
- Generic `OnTimer` as the target name is less appropriate than `AnimateStep` for this documentation target. The vtable route is a timer callback, but the source behavior is the flying parcel animation step, and existing target/class docs consistently use `AnimateStep`.
- Naming owner `+0xac` as a private FlyingParcelPane countdown, altitude, or animation-offset field is rejected. Current Pane layout support identifies `+0xac` as inherited Pane origin/position, and the start/animate pair moves that coordinate by 30 units across the animation.
- Treating `+0x100` as a raw screen-layer index is rejected. The constructor allocates/stores a `Layer` pointer, ScreenPane helpers accept a layer entry, and class/layout docs already support `m_animationLayer`.
- Treating `g_pParcelPane+0xfb` as a FlyingParcelPane field is rejected. It is a write through the global ParcelPane pointer after the handoff and matches the accepted ParcelPane field naming.

Remaining uncertainty is limited to exact original spelling rather than behavior: the original source might have used a slightly different member name for `m_timerHandler`, `m_origin`, `m_animationLayer`, or `m_rightSlotActionEnabled`, and might have named the unused callback parameters. That uncertainty does not justify leaving raw placeholders or a blank formal C++ block.

## Sibling Relationship

`FlyingParcelPaneConstructor` [UID:0002KJ] already emits C++ that initializes the same accepted FlyingParcelPane fields and allocates `m_animationLayer`.

`FlyingParcelPaneStartAnimation` [UID:0002R6] writes the payload fields, clears `m_animationFrame`, adjusts inherited origin/position for the initial animation setup, plays a sample, and schedules the timer. Its raw-start/liveness questions are separate from this target, but they do not block formal C++ for this complete vtable-routed callback.

`FlyingParcelPaneDrawParcelOrLetter` [UID:0002KL] renders the flying parcel/letter according to `m_isParcel` and the accepted field layout. Its own high-confidence/C++ gate is separate and should remain documented separately.

This target can therefore be upgraded without forcing a broader class-level C++ declaration or a raw-start reconstruction for the sibling start routine.

## First-Draft C++ Recommendation

This target should receive formal first-draft C++ because:

- It is one complete reconstructable function with stable boundaries and padding.
- Owner/emitter are already `000058`.
- The adjusted-this timer-handler route is understood.
- All helper/global/vtable placeholders used by the body have accepted source-facing names.
- The function has no unresolved branch, no missing callee semantics that affect behavior, and no split/merge blocker.

Insert the following exact body between the target's existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines:

```cpp
bool FlyingParcelPane::AnimateStep(int, int, int)
{
    if (m_animationFrame < 30) {
        --m_origin.x;
        InvalidateRect(&m_bounds);
        ++m_animationFrame;
        m_timerHandler.ScheduleTimer(0, 10, 0, 0);
        return true;
    }

    RemoveFromLayer();
    g_pScreenPane->RemoveLayer(m_animationLayer);
    g_pParcelPane->SetParcelSlotData(m_parcelCountOrState,
                                     m_leftSlot,
                                     m_rightSlot);
    g_pParcelPane->m_rightSlotActionEnabled = true;
    g_pParcelPane->InvalidateRect(&g_pParcelPane->m_bounds);
    return true;
}
```

Signature rationale:

- `bool` matches the callback returning `al=1`.
- The three `int` parameters match `retn 0x0c` and the TimerHandler callback pattern; the body ignores all three, so unnamed parameters are cleaner than speculative names.
- `AnimateStep` is retained because it is the current source-facing method name and accurately describes the body.

Body rationale:

- `m_origin.x` expresses the owner-relative `+0xac` decrement without inventing a FlyingParcelPane-private field.
- `InvalidateRect(&m_bounds)` and `g_pParcelPane->InvalidateRect(&g_pParcelPane->m_bounds)` express the vtable `+0x20` calls.
- `m_timerHandler.ScheduleTimer(0, 10, 0, 0)` expresses the tertiary handler call to `sub_5975E0`.
- `RemoveFromLayer()` expresses the owner vtable `+0x38` call.
- `g_pScreenPane->RemoveLayer(m_animationLayer)` expresses `sub_556D20(g_pScreenPane, [this+0x100])`.
- `SetParcelSlotData(m_parcelCountOrState, m_leftSlot, m_rightSlot)` preserves the source argument order after reversing the raw push order.

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:91`
- `CONFIDENCE:92`
- Preserve `CANONICAL_OWNER:000058`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve `EMITTER_UIDS:000058`
- Preserve blank optional emitter position

Recommended Item Summary:

`Steps the FlyingParcelPane timer animation by moving the pane origin, invalidating and rescheduling until frame 30, then removing the layer and handing slot state to g_pParcelPane.`

Why completion rises from 87 to 91:

- The formal C++ block is no longer blank.
- Raw placeholder helpers/globals now have source-facing names and documented roles.
- The stale blocker around `+0xac`, vtable slots, layer removal, and callback rescheduling is resolved at method level.
- The function has a precise range, no split need, and complete branch coverage.

Why confidence rises from 90 to 92:

- Current MCP evidence confirms boundary, xrefs, vtable route, disassembly, decompilation, helper callees, padding, and global references.
- The current class/file/layout support docs and accepted reports agree on the field layout and source family.
- Remaining uncertainty is original spelling and declaration polish, not behavior or call/data flow.

Why not above 92/95 yet:

- Exact original spelling for the timer-handler member, callback parameter names, and some private field names remains inferred.
- `FlyingParcelPane` class-level declaration and the raw start/draw siblings still have their own broader documentation/C++ gates.
- There is no original source/PDB proof for exact method declaration formatting.

## Target Doc Changes Required If Accepted

For `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`:

- Update `COMPLETION` to `91` and `CONFIDENCE` to `92`.
- Preserve `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, and blank optional emitter position.
- Replace the Item Summary with the recommended summary above, or an equivalently detailed concise summary that includes origin movement, invalidation/reschedule until frame 30, layer removal, and `g_pParcelPane` slot handoff.
- Insert the exact formal C++ body from this report into the existing `RECONSTRUCTION_CPP CODE` block.
- Add a 2026-06-25 IDA MCP evidence note with session `80de0a67`, exact range `0x00546d70-0x00546dee`, function size `0x7e` / 126 (Verified with `int_convert.py`), no function at `0x00546dee`, next function `0x00546df0`, one data xref from `0x00621d4c`, no direct code callers, vtable slot route, padding bytes, helper callees, global refs, and unique range signature.
- Replace stale blank-C++/helper-blocker prose with the resolved helper/source-name analysis for `TimerHandler::ScheduleTimer`, `ScreenPane::RemoveLayer`, `ParcelPane::SetParcelSlotData`, `Pane::InvalidateRect`, `Pane::RemoveFromLayer`, `g_pScreenPane`, and `g_pParcelPane`.
- Preserve the adjusted-this explanation, but make it source-facing: the binary callback receives the tertiary timer-handler subobject at owner `+0xa4`; source docs should still present the body as `FlyingParcelPane::AnimateStep`.
- Preserve negative evidence: no direct code callers, no split need, no function at end boundary, no owner change to `ParcelPane` or `ScreenPane`.
- Update score rationale so it no longer says formal C++ must stay blank pending method-level helper/field investigation.

## Support Doc Changes Required If Accepted

`by-class/FlyingParcelPane.md`:

- Update the `AnimateStep` row/current notes to show this method is first-draft populated and recommend the same `91/92` method state.
- Mention that the method uses the accepted fields `m_animationFrame`, `m_parcelCountOrState`, `m_leftSlot`, `m_rightSlot`, `m_animationLayer`, inherited `m_origin.x`, and the timer handler at `+0xa4`.
- Remove or narrow any class-level no-code prose that lists `AnimateStep` itself as unresolved. Preserve broader class-level caveats for raw `StartAnimation`, draw helper finalization, declaration visibility, and exact private helper placement if they remain true.

`by-file/ParcelPane.md`:

- Mention that [UID:0002KK] no longer has a blank-C++ blocker after this source-quality pass and emits through the ParcelPane/FlyingParcelPane source family.
- Preserve file-level route/source-family context: `FlyingParcelPane` remains implementation-private or local to `ParcelPane.cpp`; raw cleanup/start and class-level declaration caveats are separate.

`by-type/by-struct/ParcelNotificationPaneLayouts.md`:

- Checked during research. The current field names already match this report: `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, `m_animationLayer`, and inherited Pane origin at `+0xac`.
- No edit is required unless the implementation callback finds contradictory wording. If edited, keep the change narrow and do not disturb unrelated ParcelPane layout notes.

`by-global/g_pParcelPane.md` and `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`:

- Checked during research. The target evidence reinforces that `g_pParcelPane` is a handoff dependency, not the owner of UID `0002KK`.
- `by-global/g_pParcelPane.md` already records the zero-initialized storage and target refs at `0x00546dbc` and `0x00546dd2`.
- `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` has body evidence consistent with zero-initialized storage, but its Item Summary may still have stale wording about `ff ff ff ff` / `0xffffffff`. That stale summary is support cleanup, not a target blocker. If the supervisor includes it in the implementation callback, correct only that support summary/body contradiction; otherwise leave it for a focused global cleanup and do not touch coverage reports.

## Generated And Coverage State

Do not manually edit these files:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `project-level/-auto-completion-stats.md`
- `by-memory/-coverage-report.md`
- any other generated/project-level/manual coverage report file

After accepted implementation and scoped validation, validator-owned generated state should refresh from the changed source by-memory metadata and from the executed-report lifecycle command. If the manual `by-memory/-coverage-report.md` row is still maintained, it is supervisor-owned and should not be edited by B001 without an explicit override.

## Open Issues After This Pass

No current-scope blocker remains for UID `0002KK` formal C++ or score movement.

Residual final-audit caveats:

- Exact original parameter names are unknown because the three callback parameters are unused.
- Exact original member spelling for `m_timerHandler`, `m_origin`, `m_animationLayer`, and `m_rightSlotActionEnabled` remains inferred from project-local conventions and support docs.
- Broader class-level C++ declaration quality still depends on the remaining FlyingParcelPane sibling docs and raw start route; this does not block this method-level target.

## Implementation Tracking Checklist

Implementation callback status as of 2026-06-25:

- [x] Target metadata in `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`: updated `COMPLETION:91` and `CONFIDENCE:92`; preserved `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, and blank optional emitter position. Proof: post-validator readback showed lines 1-7 with those exact values.
- [x] Target Item Summary: resolved after supervisor-owned legacy coverage row correction. Supervisor applied the `by-memory/-coverage-report.md` row B001 supplied and validated it with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`, `command_id:000000000886`, `command_timestamp:2026-06-25T01:33:10-04:00`, exit code `0`, `ok:1`. Supervisor then reran `python .\tools\validator.py --mode file --file by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md --apply --queue-timeout 240 --wait-generated`, `command_id:000000000887`, `command_timestamp:2026-06-25T01:33:24-04:00`, exit code `0`, `ok:1`, `generated_refresh:completed`. Supervisor re-read proof confirms the target Item Summary now survives as `Steps the FlyingParcelPane timer animation by moving the pane origin, invalidating and rescheduling until frame 30, then removing the layer and handing slot state to g_pParcelPane.`
- [x] Target formal C++: inserted the exact `bool FlyingParcelPane::AnimateStep(int, int, int)` body from this report between the existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines. Proof: post-validator target readback lines 9-29 and generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` lines 21-40 contain the accepted body with no `sub_`, `dword_`, `unk_`, or decompiler-temporary names.
- [x] Target evidence sections: added the 2026-06-25 IDA MCP evidence note from session `80de0a67`, including exact range `0x00546d70-0x00546dee`, function size `0x7e` / 126 (Verified with `int_convert.py`), no function at `0x00546dee`, next function `0x00546df0`, one data xref from `0x00621d4c`, no direct code callers, vtable slot route, padding bytes, helper callees, global refs, and unique signature. Proof: target `## IDA MCP Evidence` now has the B001 session note and target change log repeats the same evidence.
- [x] Target helper/source-name analysis: replaced stale blank-C++/helper-blocker prose with resolved analysis for `TimerHandler::ScheduleTimer`, `ScreenPane::RemoveLayer`, `ParcelPane::SetParcelSlotData`, `Pane::InvalidateRect`, `Pane::RemoveFromLayer`, `g_pScreenPane`, `g_pParcelPane`, inherited `m_origin.x`, `m_animationLayer`, and `g_pParcelPane->m_rightSlotActionEnabled`. Proof: target `## Reconstruction Notes`, `## Callees And Dependencies`, and `## Changes` carry the accepted source-facing names.
- [x] Target ownership/range/negative evidence: preserved owner/emitter `000058`, documented adjusted tertiary-subobject `this - 0xa4`, preserved no direct code callers, no split needed, no function at end boundary, and rejected owner alternatives `ParcelPane`, `ScreenPane`, and standalone raw helper. Proof: target `## Address Range`, `## Owner And Dispatch`, `## IDA MCP Evidence`, `## Reconstruction Notes`, and `## Score Rationale` contain these details.
- [x] `by-class/FlyingParcelPane.md`: synced method/class notes. Proof: method inventory row for [UID:0002KK] now marks `AnimateStep` as `91/92` with formal first-draft target C++, names the accepted fields/helper route, and preserves class-level caveats for raw `StartAnimation`, raw cleanup/destructor shape, and declaration/source-placement polish.
- [x] `by-file/ParcelPane.md`: synced file-level source-family notes. Proof: overview, migration notes, and `## Changes` now state [UID:0002KK] emits first-draft C++ through the ParcelPane/FlyingParcelPane source family and no longer has an AnimateStep-specific blank-C++ blocker, while preserving implementation-private/file-local and raw sibling caveats.
- [x] `by-type/by-struct/ParcelNotificationPaneLayouts.md`: checked and not edited. Proof: existing field names already match this report (`m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, `m_animationLayer`/`m_screenLayerEntry`, inherited Pane origin `+0xac`); no contradictory wording found.
- [x] Optional support check for `by-global/g_pParcelPane.md` and `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`: checked and not edited. Proof: global handoff/dependency notes already support UID `0002KK`; the by-memory global page still has a stale Item Summary about initial bytes, but the callback explicitly excluded editing that page unless it directly blocked UID `0002KK`.
- [x] Validators after implementation for edited docs:
  - Target command: `python .\tools\validator.py --mode file --file by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md --apply --queue-timeout 240 --wait-generated`; cwd `E:\NTK\GhidraBridge\source-3\project-documentation`; `command_id:000000000861`; `command_timestamp:2026-06-25T01:25:55-04:00`; exit code `0`; `ok:1`; `generated_refresh:completed`; `generated_refresh_command_id:000000000861`; `generated_refresh_timestamp:2026-06-25T01:25:55-04:00`. Scoped warnings remained for stale registry/manual coverage paths (`0001EH`, `0003A1`); no validator state was hand-edited.
  - Class command: `python .\tools\validator.py --mode file --file by-class\FlyingParcelPane.md --apply --queue-timeout 240 --wait-generated`; cwd same; `command_id:000000000862`; `command_timestamp:2026-06-25T01:26:12-04:00`; exit code `0`; `ok:1`; `generated_refresh:completed`; `generated_refresh_command_id:000000000862`; `generated_refresh_timestamp:2026-06-25T01:26:12-04:00`.
  - File command: `python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --queue-timeout 240 --wait-generated`; cwd same; `command_id:000000000864`; `command_timestamp:2026-06-25T01:26:26-04:00`; exit code `0`; `ok:1`; `generated_refresh:completed`; `generated_refresh_command_id:000000000864`; `generated_refresh_timestamp:2026-06-25T01:26:26-04:00`.
- [x] Supervisor verification validators after coverage-row correction:
  - Manual coverage validation: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; `command_id:000000000886`; `command_timestamp:2026-06-25T01:33:10-04:00`; exit code `0`; `ok:1`.
  - Final target validation: `python .\tools\validator.py --mode file --file by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000000887`; `command_timestamp:2026-06-25T01:33:24-04:00`; exit code `0`; `ok:1`; `generated_refresh:completed`.
- [x] Generated refresh readback: generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` was observed at `validator-command-id:000000000874`, `validator-refreshed-at:2026-06-25T01:28:22-04:00` (newer than B001's original validator commands) and still contains the accepted UID `0002KK` C++ body. Supervisor verification after command `000000000887` confirms generated `auto-generated/-ag-coverage-report-by-memory.md` line 1575 now shows [UID:0002KK] with `91% : very-strong` and the accepted Item Summary.
- [x] Generated/manual coverage discipline: no manual edits were made to generated files, project-level files, validator/tool state, IDA DB, or any manual `-coverage-report.md` file by B001. Validator-generated/project-level changes were validator side effects only.
- [x] Lease discipline during implementation callback: B001 initially leased the three editable files, that lease expired during patch retry, then B001 re-leased only `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`, `by-class/FlyingParcelPane.md`, and `by-file/ParcelPane.md` for the immediate edit/validator batch. Release command after validators succeeded for all three files, and readback of `tools/leaser/Agents/current_leases.md` showed no active B001 rows for these paths.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002KK-FlyingParcelPaneAnimateStep-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002KK-FlyingParcelPaneAnimateStep-source-quality.md","timestamp":"2026-06-25T01:39:54","uid":"0002KK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
