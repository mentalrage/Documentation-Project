** TARGET-REPORT-UID:000232 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# FINISHED - [UID:000232] MapPaneObjectEffectDescriptorDispatch Source-Quality Reanalysis Refresh

Target: `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`

Scope: report-only refresh for Agent-B007. No by-* documents were edited by this report pass. The recommended target/support edits below are pending supervisor approval or implementation callback.

Allowed files for this pass:

- Edited: `tools/leaser/Agents/Agent-B007/research/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`
- Not edited: target/support `by-*` docs
- Not edited: `by-memory/-coverage-report.md`

## Final Recommendation

[UID:000232] should be promoted from its current generated/descriptive state to a first-draft C++ ready private `MapPane` object-effect request dispatcher.

Recommended target metadata:

```text
COMPLETION: 89
CONFIDENCE: 90
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q
RECONSTRUCTABLE: TRUE
RECONSTRUCTION_STATUS: reconstructable
```

Recommended source-facing name:

```cpp
void MapPane::RequestObjectEffect(
    unsigned int objectId,
    int effectDescriptorId,
    int timerAction,
    bool compactFlag);
```

Recommended helper names used by this target:

```cpp
void MapPane::CreateEffectObjectPane(
    ObjectPane *target,
    int mapX,
    int mapY,
    EffectInfo effectInfo,
    int timerAction,
    int sequenceIndex,
    bool compactFlag);

void MapPane::ApplyEffectObjectPaneTimerAction(
    EffectObjectPane *effectObject,
    int timerAction);
```

The timer helper body does not read `this`, but all currently observed callers set `ECX` to `MapPane *` before the call. That makes a private `MapPane` member the best ABI/source reconstruction for now. A file-local/static helper remains mechanically possible, but it is a lower-fidelity source guess because it does not explain the caller-side `ECX` setup.

Recommended C++ readiness: yes, first-draft ready. The remaining uncertainties are source-name exactness and minor field-name polish, not control-flow or ownership blockers.

## Current Repository State Checked

The target is still in pre-implementation state:

- `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`
  - Current metadata: `COMPLETION:84`, `CONFIDENCE:88`
  - Current owner/emitter: `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3`
  - Current C++: blank
  - Current body still says final helper names, `EffectInfo` field names, and child collection names need confirmation.

The owner/support docs have advanced since the original target text:

- `by-class/MapPane.md`
  - Current metadata: `88/87`, owner/emitter `0000L3`
  - Now strongly models exact `MapPane` child members and routes generated source through `NexusTK/map/MapPane.cpp`.
- `by-file/MapPane.md`
  - Current metadata: `89/85`
  - Source route: `NexusTK/map/`
- `by-type/by-struct/EffectInfo.md`
  - Current metadata: `86/89`
  - Current fields support this target's accesses:
    - `+0x00 effectKeyOrId`
    - `+0x10 primaryFrameCount`
    - `+0x14 primaryRangeStart`
    - `+0x18 primaryRangeEnd`
    - `+0x28 secondaryFrameCount`
    - `+0x2c secondaryRangeStart`
    - `+0x30 secondaryRangeEnd`
  - The primary/secondary terms are documentation terms, not original-name proof.
- `by-type/by-struct/AttachedObjectRegistryLayout.md`
  - Current metadata: `87/90`
  - Current layout supports the target's list offsets:
    - `+0x170 type2Attachments`
    - `+0x174 type4Attachments`
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`
  - Current support now confirms source-facing child list names:
    - `m_type2AttachedObjects` at `+0x170`
    - `m_type4AttachedObjects` at `+0x174`
  - Confirms insert helpers:
    - `LivingObjectPane::InsertType2AttachedObject` at `0x0053adb0`
    - `LivingObjectPane::InsertType4AttachedObject` at `0x0053ae10`
- `by-class/EffectObjectPane.md`
  - Current metadata: `85/86`
  - Confirms the target's child comparison field:
    - `EffectObjectPane +0x148` stores copied `EffectInfo +0x00`
    - `EffectObjectPane +0x14c` is `m_looping`
- `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`
  - Current metadata: `86/88`
  - Confirms constructor copies effect key/id to `+0x148`, computes looping at `+0x14c`, stores compact/caller flag at `+0x14d`, and clears `+0x14e`.
- `by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md`
  - Current metadata: `88/92`
  - C++ already reconstructs `bool EffectObjectPane::IsLooping() const { return m_looping; }`
  - Confirms all six direct callers, including this target's two reuse checks.
- `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`
  - Current metadata: `86/90`
  - Current name is working/generated, but behavior is now sufficient to use `MapPane::CreateEffectObjectPane` as this target's helper.
- `by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md`
  - Current metadata: `86/90`
  - Current name is source-facing enough for this target, but the doc should clarify that the body ignores `this` even though callers use a `MapPane` thiscall setup.
- `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`
  - Current metadata: `86/89`
  - Sibling dispatcher. Its name/signature should be aligned after UID 000232 is implemented.
- `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md`
  - Current metadata: `88/92`
  - Confirms the 52-byte descriptor copy and direct callers, including this target.
- Caller docs:
  - `by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md`
  - `by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md`
  - `by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md`
  - `by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md`

Generated stats/coverage checked:

- `project-level/-auto-completion-stats.md`
  - Generated `2026-06-19 02:24:02`
  - UID 000232 is still listed as `84/88`, average `86.0`, low reconstructable.
- `auto-generated/-ag-memory-coverage.md`
  - Still routes UID 000232 through `auto-generated/NexusTK/map/MapPane.cpp` with owner/emitter `0000L3`.
- `auto-generated/NexusTK/map/MapPane.cpp`
  - UID 000232 marker is still an empty emitter marker.
- `by-memory/-coverage-report.md`
  - Current supervisor-owned row still says class method `MapPaneObjectEffectDescriptorDispatch`, score `84`, owner generic `MapPane`.
  - This report does not edit that file.
- `project-level/-resolved.md` and `project-level/-unresolved.md`
  - Current generated references still contain raw `sub_50E320` / `sub_50e320` in some support and project-level rows. Those are generated/support cleanup issues, not blockers for this target.

## Competing Report Rechecked

I also re-read the separate Agent-B008 pending report:

`tools/leaser/Agents/Agent-B008/research/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`

Important differences:

- B008 recommends `MapPane::ApplyObjectEffect`.
- B008 recommends score `88/91`.
- B008 models the create helper as taking `EffectInfo` by value.
- B008 treats `MapPane::ApplyEffectObjectPaneTimerAction` as a `MapPane` member despite the body not using `this`.

Disposition:

- I agree with B008 that the create helper should take `EffectInfo` by value. The binary pushes the full 52-byte struct into the helper's argument area. A `const EffectInfo &` source signature would not explain that ABI.
- I agree with B008 that the timer helper can be a private `MapPane` method. The target and coordinate sibling set `ECX` to `MapPane *` before calling it. The unused `this` is an implementation detail, not enough to demote it to a file-local helper.
- I do not recommend replacing `RequestObjectEffect` with `ApplyObjectEffect` for UID 000232. `ApplyObjectEffect` is a good alias, but `RequestObjectEffect` better matches all callers and the observed semantics:
  - Packet callers request an effect by object id and descriptor id.
  - `LivingObjectPaneNameplateSpecialEffectHelpers.md` already has a first-draft C++ caller using `g_pActiveMapPane->RequestObjectEffect(m_objectId, 135, -2, 0);`.
  - The function may create, reuse, extend, stop, cancel, or no-op depending on object lookup, descriptor ranges, existing looping panes, and `timerAction`; it is not only a direct "apply" operation.
  - The name mirrors the external API shape without overcommitting to animation/timer internals.

If the supervisor prefers B008's name globally, `MapPane::ApplyObjectEffect` is safe as an alternative. It should then be applied consistently across UID 000232, `LivingObjectPaneNameplateSpecialEffectHelpers`, packet support docs, coordinate sibling terminology, and generated unresolved references. My B007 recommendation remains `RequestObjectEffect`.

## Binary Evidence Rechecked

IDA MCP was attempted but unavailable:

```text
http://127.0.0.1:13337/mcp
Unable to connect to the remote server
```

I therefore revalidated the target against the local PE:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

Section/range facts:

- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`
- Target range: `0x0050e320-0x0050e4b6`
- Target size: `0x196` bytes
- Bytes before target: `cc cc cc cc cc cc cc cc`
- Prologue bytes: `55 8b ec 83 ec 40 53 56 57 ff 75 0c 8b f9 8d 45`
- Tail: `5f 5e 5b 8b e5 5d c2 10 00`
- Bytes after target: `cc cc cc cc cc cc cc cc cc cc`

Direct rel32 callers to UID 000232:

- `0x005116cc` in draw-objects packet handling
- `0x00511d34` in object-move effect packet handling
- `0x0053bac5` in nameplate special-effect setup
- `0x005a2ee0` in living-object movement processing

No rel32 jump thunks or direct VA/RVA dword pointer references were found for the target.

Instruction-aligned direct calls inside UID 000232:

```text
0x0050e33b -> 0x004de3e0  EffectObjImageLibGetEffectInfo
0x0050e349 -> 0x00532370  ObjectListFindByObjectId
0x0050e385 -> [eax+0x10] indexed child-list access
0x0050e397 -> 0x00538bb0  EffectObjectPane::IsLooping
0x0050e3b2 -> 0x005374d0  ObjectPane map-position helper
0x0050e3ed -> 0x0050ea30  create effect-object helper
0x0050e41b -> [eax+0x10] indexed child-list access
0x0050e42d -> 0x00538bb0  EffectObjectPane::IsLooping
0x0050e444 -> 0x005374d0  ObjectPane map-position helper
0x0050e47e -> 0x0050ea30  create effect-object helper
0x0050e494 -> 0x0050eb90  timer/update helper
0x0050e4a8 -> 0x0050eb90  timer/update helper
```

Direct rel32 callers to dependent helpers:

```text
0x0050ea30 CreateEffectObjectPane:
  0x0050e3ed
  0x0050e47e
  0x0050e945
  0x0050e9e3

0x0050eb90 ApplyEffectObjectPaneTimerAction:
  0x0050e494
  0x0050e4a8
  0x0050ea04
  0x0050ea18

0x00538bb0 EffectObjectPane::IsLooping:
  0x0050e397
  0x0050e42d
  0x0050e8fa
  0x0050e9a0
  0x005a2f48
  0x005a2fa9
```

## Exact Behavior

UID 000232 is a `ret 0x10` thiscall-style `MapPane` method with four stack arguments:

```text
ECX       MapPane *this
[ebp+08]  objectId
[ebp+0c]  effectDescriptorId
[ebp+10]  timerAction
[ebp+14]  compactFlag / caller flag byte
```

High-level flow:

1. Copy the descriptor into a local 52-byte `EffectInfo`:

   ```text
   GetEffectInfo(&localEffectInfo, effectDescriptorId)
   ```

2. Look up the target object pane by id through `MapPane +0x424`:

   ```text
   target = this->m_objectList->FindByObjectId(objectId)
   ```

3. If no target is found, return without creating anything.

4. Process the descriptor's secondary sequence first:

   - Check `EffectInfo +0x28` frame count is positive.
   - If `secondaryRangeStart` and `secondaryRangeEnd` are nonnegative, scan target list `+0x174`.
   - The target list is the living object type-4 attached-object collection.
   - Scan backward from `count - 1` through index `0`.
   - Candidate must have `EffectObjectPane +0x148 == EffectInfo +0x00`.
   - Candidate must return true from `EffectObjectPane::IsLooping()`.
   - On reusable looping candidate, call the timer/update helper and skip creation.
   - On no reusable candidate, obtain target map coordinates and call the create helper with `sequenceIndex == 0`.

5. Process the descriptor's primary sequence second:

   - Check `EffectInfo +0x10` frame count is positive.
   - If `primaryRangeStart` and `primaryRangeEnd` are nonnegative, scan target list `+0x170`.
   - The target list is the living object type-2 attached-object collection.
   - Candidate match and looping requirements are the same as secondary.
   - On reusable looping candidate, call the timer/update helper.
   - On no reusable candidate, obtain target map coordinates and call the create helper with `sequenceIndex == 1`.

6. Return after both sequence checks.

Important control-flow detail:

- Negative range bounds skip the reuse scan, but do not automatically suppress creation. Creation is gated by positive frame count and by the create helper's own `timerAction == -1` early exit.

## Helper Semantics

### CreateEffectObjectPane

Recommended support name:

```cpp
MapPane::CreateEffectObjectPane
```

Observed raw helper range:

```text
0x0050ea30-0x0050eb8a
```

Recommended source signature:

```cpp
void MapPane::CreateEffectObjectPane(
    ObjectPane *target,
    int mapX,
    int mapY,
    EffectInfo effectInfo,
    int timerAction,
    int sequenceIndex,
    bool compactFlag);
```

ABI evidence:

- Returns with `ret 0x4c`.
- Receives the 52-byte `EffectInfo` by value in stack slots `[ebp+0x14]` through `[ebp+0x47]`.
- Receives:
  - `target` at `[ebp+0x08]`
  - `mapX` / `mapY` at `[ebp+0x0c]` / `[ebp+0x10]`
  - `timerAction` at `[ebp+0x48]`
  - `sequenceIndex` at `[ebp+0x4c]`
  - `compactFlag` at `[ebp+0x50]`

Behavior:

- If `timerAction == -1`, returns without creating a pane.
- Uses `sequenceIndex == 0` for the secondary/type-4 sequence.
- Uses `sequenceIndex == 1` for the primary/type-2 sequence.
- Allocates an `EffectObjectPane`.
- Calls the `EffectObjectPane` constructor with:
  - target object
  - map coordinates
  - address of the by-value local `EffectInfo`
  - `sequenceIndex`
  - compact/caller flag
- If target is non-null:
  - `sequenceIndex == 0`: inserts through `LivingObjectPane::InsertType4AttachedObject`
  - `sequenceIndex == 1`: inserts through `LivingObjectPane::InsertType2AttachedObject`
- Inserts the new pane into `MapPane +0x424`.
- Starts the idle timer through `EffectObjectPane::StartIdleTimer`.
- If `timerAction != -2` and selected range bounds are nonnegative, schedules event id `2` on `EffectObjectPane +0xa4`.

Rejected signature alternative:

```cpp
const EffectInfo &effectInfo
```

This is a cleaner modern C++ signature, but it does not match the observed stack ABI. Use by-value in the reconstruction unless the project later chooses intentional source polish over ABI fidelity for this helper.

### ApplyEffectObjectPaneTimerAction

Recommended support name:

```cpp
MapPane::ApplyEffectObjectPaneTimerAction
```

Observed raw helper range:

```text
0x0050eb90-0x0050ec2e
```

Recommended source signature:

```cpp
void MapPane::ApplyEffectObjectPaneTimerAction(
    EffectObjectPane *effectObject,
    int timerAction);
```

Behavior:

- Null `effectObject`: return.
- `timerAction == -1`: invoke the effect pane's first virtual callback with argument `1`, then return.
- `timerAction == 0`: no-op return.
- `timerAction == -2`: cancel event id `2` on the effect pane timer at `+0xa4`, then return.
- Positive `timerAction`:
  - If `EffectObjectPane +0x14e` is set, return without rescheduling.
  - Query current due time for event id `2`.
  - Compare against the timer manager's current tick at `g_pTimerMgr +0x18`.
  - If requested duration is longer than the remaining due window, cancel event id `2` and schedule event id `2` for `timerAction * 1000`.

Naming notes:

- `timerAction` is better than `duration`, `reuseDelay`, or `interval` because the argument is overloaded:
  - `-1` means invoke the pane callback.
  - `-2` means cancel the pane's effect timer.
  - `0` means no-op.
  - positive values mean extend/reschedule in seconds.
- The flag at `EffectObjectPane +0x14e` is still not source-final. In this report, call it `m_timerRescheduleBlocked` or `m_timerLocked` only as a descriptive placeholder.

## Heuristic and Inference Resolution

### Final MapPane method name

Recommended:

```cpp
MapPane::RequestObjectEffect
```

Reasoning:

- The method is externally called by packet handlers and living-object helper code with only an object id and descriptor id.
- It does not always create an effect. It may reuse an existing looping pane, call a timer action, cancel a timer, run a callback, or return without action.
- The existing first-draft `LivingObjectPaneNameplateSpecialEffectHelpers.md` already uses `RequestObjectEffect`.
- The sibling coordinate dispatcher can naturally become `RequestCoordinateEffect`.

Rejected but acceptable alternative:

```cpp
MapPane::ApplyObjectEffect
```

This name is source-plausible and is the B008 recommendation. It is rejected here only because it is less aligned with the request/cancel/reuse semantics and would require changing an already drafted support caller.

Names not recommended:

- `MapPaneObjectEffectDescriptorDispatch`: generated/descriptive, not source-facing.
- `sub_50E320`: raw decompiler name.
- `SpawnObjectEffect`: too creation-specific and does not cover reuse/cancel/no-op paths.
- `PlayObjectEffect`: too animation-specific and does not cover `timerAction == -1` / `-2`.
- `SetObjectEffect`: too state-like and does not express descriptor-driven creation/reuse.

### EffectInfo field names

Use the current `EffectInfo` support names:

```cpp
effectInfo.effectKeyOrId
effectInfo.primaryFrameCount
effectInfo.primaryRangeStart
effectInfo.primaryRangeEnd
effectInfo.secondaryFrameCount
effectInfo.secondaryRangeStart
effectInfo.secondaryRangeEnd
```

Evidence:

- `EffectInfo +0x00` is copied into `EffectObjectPane +0x148` and compared against candidate panes during reuse.
- `EffectInfo +0x10/+0x14/+0x18` control the second pass and type-2 collection.
- `EffectInfo +0x28/+0x2c/+0x30` control the first pass and type-4 collection.
- `EffectObjImageLibGetEffectInfo` and the loader docs establish the 52-byte structure and the two frame/range groups.

Open naming caveat:

- `primary` / `secondary` are current documentation terms. They are useful and internally consistent, but not proven original source names. Do not raise the confidence above 90 solely on these names.

### Child collection semantics

Recommended names in target C++:

```cpp
target->m_type4AttachedObjects
target->m_type2AttachedObjects
```

Mapping:

- `+0x174` / type-4 list is scanned for `sequenceIndex == 0`, corresponding to the descriptor's secondary sequence in this target.
- `+0x170` / type-2 list is scanned for `sequenceIndex == 1`, corresponding to the descriptor's primary sequence in this target.

Evidence:

- `LivingObjectPaneCore.md` now names the lists and insert helpers.
- `AttachedObjectRegistryLayout.md` independently documents the same offsets.
- `CreateEffectObjectPane` inserts sequence 0 through `0x0053ae10` / `InsertType4AttachedObject`.
- `CreateEffectObjectPane` inserts sequence 1 through `0x0053adb0` / `InsertType2AttachedObject`.
- `LivingObjectPaneProcessMovement.md` separately scans `dword_67A748 +0x174/+0x170` for matching `EffectObjectPane +0x148`, reinforcing the list semantics.

### Owner and source placement

Recommended owner:

```text
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q
```

Reasoning:

- The current target is a `MapPane` thiscall method.
- The most specific owner is now `by-class/MapPane.md` UID `00007Q`, not generic source-file owner `0000L3`.
- The generated source route remains `NexusTK/map/MapPane.cpp`.
- The class owner and file owner both exceed the 85 support threshold.

Recommended target source path:

```text
NexusTK/map/MapPane.cpp
```

Recommended `EMITTER_POSITION_OPTIONAL`:

- Leave blank unless the supervisor has a class-ordering policy for `MapPane`.
- Remove the target body's stale "position 36" statement unless a real current emitter position is assigned during implementation.

### Caller and reachability

All currently observed direct callers are source-explainable:

- `MapPaneHandleDrawObjectsPacket`
  - Nested object-effect descriptors in draw-object packet handling.
- `MapPaneHandleObjectMoveEffectPacket`
  - Object-id branch dispatches here; coordinate branch dispatches to the coordinate sibling.
- `LivingObjectPaneNameplateSpecialEffectHelpers`
  - Special effect setup/removal around local nameplate/living object state.
- `LivingObjectPaneProcessMovement`
  - Local-player movement effect path, descriptor `201` / `0xc9`.

No evidence was found for pointer-table dispatch or alternate owners.

### Split decision

Do not split UID 000232.

Reasoning:

- The range has one clean prologue and one logical dispatcher body.
- The two pass blocks are repeated source logic but not separate functions.
- The create/timer behavior is already split into separate helpers at `0x0050ea30` and `0x0050eb90`.
- Bytes before and after are `CC` padding, supporting the current function boundary.

### First-draft C++ readiness

Ready, with local placeholders:

- `ObjectPane::GetMapPosition` or equivalent coordinate helper name still depends on support doc final naming.
- `EffectInfo` primary/secondary field names are source-facing but not original-proof.
- `EffectObjectPane +0x14d/+0x14e` names are still descriptive.
- Exact list type API can be expressed via the project's existing list wrapper pattern; do not invent STL containers in the target C++.

These are polish issues. They do not block first-draft reconstruction.

## Recommended First-Draft C++

This is the exact target-level C++ shape I recommend adding to the target doc. Local list iteration should be adjusted to the project's existing list wrapper names when implemented, but the fields, order, and helper calls should remain as shown.

```cpp
void MapPane::RequestObjectEffect(
    unsigned int objectId,
    int effectDescriptorId,
    int timerAction,
    bool compactFlag)
{
    EffectInfo effectInfo;
    EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId);

    ObjectPane *target = m_objectList.FindByObjectId(objectId);
    if (target == nullptr) {
        return;
    }

    if (effectInfo.secondaryFrameCount > 0) {
        bool reused = false;

        if (effectInfo.secondaryRangeStart >= 0 &&
            effectInfo.secondaryRangeEnd >= 0) {
            for (int i = target->m_type4AttachedObjects.Count() - 1;
                 i >= 0;
                 --i) {
                EffectObjectPane *effectObject =
                    static_cast<EffectObjectPane *>(
                        target->m_type4AttachedObjects.At(i));

                if (effectObject->m_effectKeyOrId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping()) {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused) {
            int mapX;
            int mapY;
            target->GetMapPosition(&mapX, &mapY);
            CreateEffectObjectPane(
                target,
                mapX,
                mapY,
                effectInfo,
                timerAction,
                0,
                compactFlag);
        }
    }

    if (effectInfo.primaryFrameCount > 0) {
        bool reused = false;

        if (effectInfo.primaryRangeStart >= 0 &&
            effectInfo.primaryRangeEnd >= 0) {
            for (int i = target->m_type2AttachedObjects.Count() - 1;
                 i >= 0;
                 --i) {
                EffectObjectPane *effectObject =
                    static_cast<EffectObjectPane *>(
                        target->m_type2AttachedObjects.At(i));

                if (effectObject->m_effectKeyOrId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping()) {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused) {
            int mapX;
            int mapY;
            target->GetMapPosition(&mapX, &mapY);
            CreateEffectObjectPane(
                target,
                mapX,
                mapY,
                effectInfo,
                timerAction,
                1,
                compactFlag);
        }
    }
}
```

Implementation notes for the C++ block:

- Use the repository's established object-list/list wrapper syntax instead of the illustrative `Count()` / `At()` names if support docs expose different exact names.
- If `EffectObjectPane` currently names `+0x148` as `m_effectId` instead of `m_effectKeyOrId`, use the class's current field name and add a support note that the value originates from `EffectInfo::effectKeyOrId`.
- Keep the pass order exactly as secondary/type-4 first, primary/type-2 second.
- Keep create-helper `EffectInfo` by-value.
- Keep `timerAction` as the argument name unless support docs settle on a better exact original name.

## Exact Recommended Target Changes

Apply these changes to:

`by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`

Metadata:

```text
COMPLETION: 89
CONFIDENCE: 90
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q
```

Aliases/title:

- Keep the existing file basename unless the supervisor wants renames.
- In the body, state the source-facing name is `MapPane::RequestObjectEffect`.
- Record `MapPaneObjectEffectDescriptorDispatch` as a generated/descriptive alias only.
- Record raw `sub_50E320` only as a historical IDA/decompiler name.

Behavior section:

- Replace unresolved "source name not final" text with the final recommendation and rejected alternatives.
- Replace provisional list semantics with:
  - `m_type4AttachedObjects` / secondary sequence / pass `0`
  - `m_type2AttachedObjects` / primary sequence / pass `1`
- Replace generic field language with the current `EffectInfo` names.
- Add the direct-caller list from the PE validation.
- Add the note that negative range bounds skip reuse scan but do not prevent creation when frame count is positive.

C++ section:

- Add the first-draft C++ body above or an equivalent body with the project's exact list API.
- Mark C++ readiness as "first-draft ready; source-name confidence capped by heuristic names."

Owner/emitter notes:

- Change from `0000L3` to `00007Q`.
- Keep source file path `NexusTK/map/MapPane.cpp`.
- Remove the old body claim about a fixed emitter position unless implementation assigns a current one.

Score rationale:

```text
Completion 89 because all control flow, callers, helper interactions, child collection semantics, and C++ shape are reconstructed. It remains below 90 only because several source-facing names are inferred rather than original-symbol proven.

Confidence 90 because the binary boundary, direct callers, EffectInfo accesses, list offsets, create/reuse/timer helper calls, and owner placement are independently supported. It remains capped at 90 because IDA MCP was unavailable and original source names for RequestObjectEffect, primary/secondary sequence labels, timerAction, and compactFlag are not directly proven.
```

## Exact Recommended Support-Doc Changes

These are the support edits to apply with the target implementation. Do not broaden scope beyond these unless the supervisor asks for a cleanup batch.

### `by-class/MapPane.md`

Add/update the method entry:

```text
MapPane::RequestObjectEffect(unsigned int objectId, int effectDescriptorId, int timerAction, bool compactFlag)
```

Recommended note:

```text
Requests an object-bound effect by descriptor id. The method looks up the target ObjectPane in m_objectList, processes the descriptor secondary/type-4 sequence first and primary/type-2 sequence second, reuses looping EffectObjectPane children when possible, otherwise creates EffectObjectPane children through MapPane::CreateEffectObjectPane, and applies timer/cancel/callback actions through MapPane::ApplyEffectObjectPaneTimerAction.
```

Add private helpers if not already present:

```text
MapPane::CreateEffectObjectPane(ObjectPane *target, int mapX, int mapY, EffectInfo effectInfo, int timerAction, int sequenceIndex, bool compactFlag)
MapPane::ApplyEffectObjectPaneTimerAction(EffectObjectPane *effectObject, int timerAction)
```

If the supervisor chooses B008's naming, apply `ApplyObjectEffect` consistently instead of `RequestObjectEffect`.

### `by-file/MapPane.md`

Add/update the `NexusTK/map/MapPane.cpp` method list to include:

```text
MapPane::RequestObjectEffect
MapPane::CreateEffectObjectPane
MapPane::ApplyEffectObjectPaneTimerAction
```

Recommended placement note:

```text
UID 000232 belongs with the MapPane object/effect dispatch helpers around the coordinate-effect sibling and effect-object create/timer helpers.
```

### `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`

Update support notes:

- Use `MapPane::CreateEffectObjectPane` as the source-facing helper name.
- State the helper receives `EffectInfo` by value, not by pointer/reference, based on `ret 0x4c` and stack layout.
- State `sequenceIndex == 0` selects the descriptor secondary range and inserts into type-4 attachments.
- State `sequenceIndex == 1` selects the descriptor primary range and inserts into type-2 attachments.
- State `timerAction == -1` suppresses creation.
- State `timerAction == -2` still permits creation but suppresses event-id-2 scheduling.
- Keep C++ blank if the helper itself is not ready for C++ in this implementation batch, but make the naming/signature clear enough for UID 000232 to call it.

### `by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md`

Update support notes:

- Use `MapPane::ApplyEffectObjectPaneTimerAction` as the source-facing helper name.
- Signature should be:

  ```cpp
  void MapPane::ApplyEffectObjectPaneTimerAction(EffectObjectPane *effectObject, int timerAction);
  ```

- Explain that the body does not read `this`, but callers set `ECX` to `MapPane *`, so private MapPane member remains the best current source model.
- Keep the argument name `timerAction`.
- Document the `timerAction` cases:
  - `-1`: invoke effect object callback with argument `1`
  - `-2`: cancel event id `2`
  - `0`: no-op
  - positive: extend/reschedule event id `2` if not blocked by `EffectObjectPane +0x14e`

### `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`

Do not implement unless assigned, but add an alignment note if this support doc is touched:

```text
Object-bound sibling UID 000232 is recommended as MapPane::RequestObjectEffect. The coordinate dispatcher should use parallel terminology, likely MapPane::RequestCoordinateEffect or MapPane::RequestPositionEffect, pending its own report.
```

### `by-type/by-struct/EffectInfo.md`

No mandatory metadata change. Add target usage note if touched:

```text
UID 000232 uses effectKeyOrId (+0x00) to match existing EffectObjectPane children, processes secondaryFrameCount/secondaryRangeStart/secondaryRangeEnd first for type-4 attachments, then primaryFrameCount/primaryRangeStart/primaryRangeEnd for type-2 attachments. The primary/secondary names are descriptive documentation terms, not original source proof.
```

### `by-type/by-struct/AttachedObjectRegistryLayout.md`

No mandatory metadata change. Add cross-reference if touched:

```text
UID 000232 scans target +0x174 type4Attachments when processing EffectInfo's secondary sequence and target +0x170 type2Attachments when processing EffectInfo's primary sequence. The create helper inserts through LivingObjectPane::InsertType4AttachedObject and LivingObjectPane::InsertType2AttachedObject respectively.
```

### `by-class/EffectObjectPane.md`

No mandatory metadata change. Add cross-reference if touched:

```text
UID 000232 compares EffectObjectPane +0x148 against EffectInfo::effectKeyOrId and only reuses a matching pane when EffectObjectPane::IsLooping() reads m_looping (+0x14c) as true.
```

### `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`

No mandatory metadata change. Add note only if the constructor section is already being updated:

```text
MapPane::CreateEffectObjectPane passes the selected sequence index and the address of its by-value EffectInfo argument into the EffectObjectPane constructor. The constructor copies EffectInfo +0x00 to +0x148, sets m_looping at +0x14c from the selected range validity, stores the compact/caller flag at +0x14d, and clears the timer/update flag at +0x14e.
```

### Caller Docs

Recommended caller-support text updates:

- `by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md`
  - Replace `sub_50E320` / generated name with `MapPane::RequestObjectEffect`.
  - State it passes object id, descriptor id, timer action, and compact flag.
- `by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md`
  - Replace `sub_50E320` with `MapPane::RequestObjectEffect`.
  - Preserve the object-id branch vs coordinate-effect sibling branch.
- `by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md`
  - It already uses `RequestObjectEffect`; just ensure signature and argument names match UID 000232.
- `by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md`
  - Replace raw `sub_50E320` mention with `MapPane::RequestObjectEffect`.
  - Preserve descriptor `201` / `0xc9` and later local-player child scans.

### No Support Change Needed

These docs were checked and do not need mandatory edits for UID 000232 implementation:

- `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md`
- `by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md`
- `by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

Only add cross-references there if they are already in the implementation batch.

## Exact Supervisor-Owned Coverage Row

Recommended replacement row for `by-memory/-coverage-report.md` when the supervisor applies coverage updates:

```text
- [UID:000232] [0x0050e320-0x0050e4b6] `MapPane::RequestObjectEffect(unsigned int objectId, int effectDescriptorId, int timerAction, bool compactFlag)` | class method | reconstructable : 89% : strong : MapPane-owned object-effect request dispatcher; copies a 52-byte EffectInfo descriptor, looks up the target ObjectPane by object id, processes secondary/type-4 then primary/type-2 effect sequences, reuses matching looping EffectObjectPane children when present, otherwise creates new EffectObjectPane children through the create helper, and applies timer/cancel/callback actions through the timer-action helper. Confidence remains capped by inferred source names for the request method, sequence labels, timerAction, and compactFlag.
```

If the supervisor adopts B008's name, use this coverage row instead:

```text
- [UID:000232] [0x0050e320-0x0050e4b6] `MapPane::ApplyObjectEffect(unsigned int objectId, int effectDescriptorId, int timerAction, bool compactFlag)` | class method | reconstructable : 88% : strong : MapPane-owned object-effect dispatcher; copies a 52-byte EffectInfo descriptor, looks up the target ObjectPane by object id, processes secondary/type-4 then primary/type-2 effect sequences, reuses matching looping EffectObjectPane children when present, otherwise creates new EffectObjectPane children through the create helper, and applies timer/cancel/callback actions through the timer-action helper. Confidence remains capped by inferred source names for the request/apply method, sequence labels, timerAction, and compactFlag.
```

I recommend the first row.

## Validator Commands After Implementation

Run the focused validators after applying the target/support edits. Adjust paths only if the implementation batch intentionally omits optional support docs.

> Executable block R001 was removed from this report and preserved verbatim in [000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md](000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation edits generated aggregate/report files, then run the applicable project refresh command prescribed by the supervisor before touching `by-memory/-coverage-report.md`. Agent-B007 should not edit that coverage report directly under the current assignment.

## Implementation Checklist

This checklist is intended to be detailed enough for a later implementation callback.

1. Open the target doc and preserve any unrelated current edits.
2. Update target metadata to `89/90`, owner/emitter `00007Q`.
3. Add `MapPane::RequestObjectEffect` as the source-facing method name.
4. Keep `MapPaneObjectEffectDescriptorDispatch` only as a descriptive alias.
5. Add the four-argument signature:

   ```cpp
   void MapPane::RequestObjectEffect(unsigned int objectId, int effectDescriptorId, int timerAction, bool compactFlag)
   ```

6. Update the evidence section with the exact direct callers:
   - `0x005116cc`
   - `0x00511d34`
   - `0x0053bac5`
   - `0x005a2ee0`
7. Update the behavior section to describe:
   - `EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId)`
   - target lookup through `m_objectList`
   - no-op return on missing target
   - secondary/type-4 pass first
   - primary/type-2 pass second
   - backward scans of child lists
   - match on `EffectObjectPane +0x148 == EffectInfo +0x00`
   - reuse requires `IsLooping()`
   - missed reuse creates a new pane at target map coordinates
   - negative range bounds skip reuse scan but do not block creation
8. Add or replace the target C++ block with the first-draft body above.
9. In the C++ block, use the repository's current list API names if exact names exist; otherwise keep list access as pseudocode and mark it as first-draft source form.
10. Add the create helper signature to the target notes, using by-value `EffectInfo`.
11. Add the timer helper signature to the target notes as a private `MapPane` helper.
12. Update `by-class/MapPane.md` with the method and helper entries.
13. Update `by-file/MapPane.md` with the source route and helper grouping.
14. Update `MapPaneCreateEffectObjectPane.md` with by-value `EffectInfo`, pass/sequence mapping, and timer-action semantics.
15. Update `MapPaneApplyEffectObjectPaneTimerAction.md` with the private MapPane method signature, unused-this caveat, and the four `timerAction` cases.
16. If touching `MapPaneCoordinateEffectDescriptorDispatch.md`, add a sibling naming alignment note only; do not rework that target under UID 000232 unless assigned.
17. If touching `EffectInfo.md`, add the UID 000232 usage note and retain primary/secondary naming caveat.
18. If touching `AttachedObjectRegistryLayout.md`, add the UID 000232 type-4/type-2 scan mapping note.
19. If touching `EffectObjectPane.md`, add the `+0x148` / `IsLooping` reuse note.
20. Update caller docs to replace raw `sub_50E320` references with `MapPane::RequestObjectEffect`.
21. Do not edit `by-memory/-coverage-report.md` unless the supervisor explicitly assigns that step.
22. Run the focused validator commands listed above.
23. Re-open any validator-modified files and confirm the target C++ block and metadata survived formatting.
24. If validators expose conflicting owner/emitter policy, keep `00007Q` as the recommended canonical owner and document the conflict rather than silently reverting to `0000L3`.
25. If B008's `ApplyObjectEffect` name is selected by the supervisor, update all support/caller names consistently in the same batch rather than mixing `RequestObjectEffect` and `ApplyObjectEffect`.

## Remaining Open Questions

These are not blockers:

- Original source name for UID 000232 is not proven. Best recommendation is `RequestObjectEffect`; strongest alternative is `ApplyObjectEffect`.
- Original source names for `primary` and `secondary` descriptor groups are not proven. Current names are internally consistent and match support docs.
- Exact names for `timerAction` and `compactFlag` are not proven. Current names are behavior-based and should remain documented as inferred.
- Exact source name for `EffectObjectPane +0x14e` is not proven. This only affects the timer helper's support notes, not UID 000232 control flow.
- IDA MCP could not be reached during this refresh. Local PE/Capstone validation covered boundaries, calls, and ABI evidence, but confidence should remain capped at 90.

## Score Justification

Recommended completion: `89`

- Full function boundary validated.
- All direct callers identified.
- All direct callees and helper interactions identified.
- Effect descriptor field accesses mapped to current `EffectInfo` support names.
- Child collections mapped to current living-object support docs.
- Create/reuse/timer behavior is reconstructable.
- First-draft C++ is ready.
- One point withheld because exact original source names are still inferred.

Recommended confidence: `90`

- Binary evidence, support docs, caller docs, generated stats, and sibling/helper docs agree on owner, behavior, and field/list semantics.
- Confidence remains capped by unavailable IDA MCP and lack of original symbol proof for method/helper/argument names.

## Report Outcome

The existing pending report has been refreshed to current standard. UID 000232 is ready for supervisor review as a `MapPane` class-method implementation candidate with recommended source name `MapPane::RequestObjectEffect`, owner/emitter `00007Q`, score `89/90`, and first-draft C++ readiness.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"000232"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000232"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
