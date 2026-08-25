** TARGET-REPORT-UID:0002R1 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Research Report: [UID:0002R1] LivingObjectPaneAnimationTimer

Assignment: `B007-report-0002R1-living-object-pane-animation-timer-20260626`
Target: `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`
Mode: report-only research. No by-* docs, generated files, project-level files, validator/tool state, coverage reports, or IDA database state were edited.

## Result

The target is eligible for implementation. Current source metadata already has [UID:0002R1] at `86/88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007B`, and `EMITTER_UIDS:00007B`. This pass resolves the major source-quality blockers called out in the page: the five timer messages, the adjusted timer-handler owner math, the direct wrappers, the field-name direction, and the first-draft C++ shape.

Recommended target update: raise to `COMPLETION:88`, `CONFIDENCE:89`, keep owner/emitter unchanged, and populate the blank `RECONSTRUCTION_CPP CODE` section with the formal insertion text below. Do not split the target: `0x0053b700-0x0053baa8` is a coherent four-function LivingObjectPane animation/timer cluster with internal `0xcc` alignment.

## IDA MCP Status

IDA MCP was available and used. Active database session `80de0a67` was attached to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x00400000`; server health reported auto-analysis and Hex-Rays ready. The current MCP schema exposed lookup, decompile, disassembly, xref, callee, byte, and analysis tools. It did not expose the older `py_eval` method, but no fallback-only report was needed.

## Evidence Checked

- Target page [UID:0002R1] and direct parent [UID:0001DE] `LivingObjectPaneCore`.
- Direct support docs: [UID:00007B] `LivingObjectPane`, [UID:0000KU] `LivingObjectPane` file, [UID:0000F0] `TimerHandler`, [UID:0001K8] timer schedule/remove wrappers, [UID:0001K9] timer cancel wrappers, [UID:000358] `LivingObjectPane` vtable data.
- Neighbor emitted LivingObjectPane children: sprite-config helpers [UID:0003Z3], movement/action helpers [UID:0003Z5], linked-position/mode helpers [UID:0003Z7], and `TryStepForward` [UID:0003Z8].
- Local-player/UserPane support: walk/directional-animation helpers [UID:0003U7], [UID:0003U8], and [UID:0003VD] `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`. The shorter `0x005a83d0-0x005a8423` path is not the current [UID:0003VD] page.
- Generated rows were checked but not edited. `auto-generated/-ag-memory-coverage.md` treats [UID:0002R1] as emitting through `auto-generated/NexusTK/map/LivingObjectPane.cpp`; coverage/research rows are stale relative to the target page and should be refreshed only by the normal tooling.
- Prior executed B-agent context was checked. B001's LivingObjectPane reports already identify [UID:0002R1] as eligible but blocked by timer/wrapper naming; this report supersedes that blocker. No earlier dedicated [UID:0002R1] report was found in active or archived B-agent research.

## MCP Findings

Function boundaries are exact:

| Range | IDA name | Size | Source role |
| --- | --- | ---: | --- |
| `0x0053b700-0x0053b7b4` | `sub_53B700` | `0xb4` | `PlayAnimation` |
| `0x0053b7b4-0x0053b7c0` | alignment | `0x0c` | `0xcc` padding |
| `0x0053b7c0-0x0053b7cf` | `sub_53B7C0` | `0x0f` | play current-facing animation wrapper |
| `0x0053b7cf-0x0053b7d0` | alignment | `0x01` | `0xcc` padding |
| `0x0053b7d0-0x0053b826` | `sub_53B7D0` | `0x56` | terminal/death animation wrapper |
| `0x0053b826-0x0053b830` | alignment | `0x0a` | `0xcc` padding |
| `0x0053b830-0x0053baa8` | `sub_53B830` | `0x278` | adjusted timer-handler message callback |

`0x0053b6b3-0x0053b700` is not a function. MCP bytes show a lowered jump table/data tail and `0xcc` padding from the preceding action helper. `0x0053baa8` begins trailing `0xcc` padding after the handler.

Incoming routes match source placement:

- `PlayAnimation` is called by `SetSpriteConfig`, `SetFacing`, the action-animation helper, both local wrappers in this target, and the timer handler.
- `0x0053b7c0` has a direct caller from `0x005a3770` (`StartDirectionalAnimation` support path).
- `0x0053b7d0` has packet-dispatch style callers at `0x005089c2` and `0x00513d73`.
- `0x0053b830` has data/vtable evidence at `0x00620a34` and direct code refs from `UserPane::OnAnimationStep` at `0x005a83dc` and `0x005a83ef`.
- The box-step helpers at `0x0053bf40` and `0x0053bf80` confirm `FBSA` scheduling/cancel behavior and are already documented in [UID:0003Z7].

The adjusted owner math is now stable: `sub_53B830` receives the timer-handler subobject at owner `+0xa4`, then recovers the `LivingObjectPane` owner with `this - 0xa4`. Handler-relative field references map to the accepted class fields: `m_isMoving`, `m_facing`, `m_moveFrame`, `m_animationFrame`, `m_animationGroup`, `m_terminalAnimation`, `m_boxRotationStep`, and `m_pendingDamageEffect`.

## Positive And Negative Evidence Summary

Positive evidence supporting implementation:

- Exact IDA function boundaries and sizes exist for all four functions in the target range: `sub_53B700`, `sub_53B7C0`, `sub_53B7D0`, and `sub_53B830`.
- Caller/xref evidence ties `PlayAnimation` to neighboring LivingObjectPane source methods, action helpers, target-local wrappers, and the timer handler.
- Data/vtable evidence at `0x00620a34` and direct refs from `UserPane::OnAnimationStep` route the adjusted timer callback to the embedded TimerHandler view, while the callback body itself mutates LivingObjectPane state.
- TimerMgr wrapper calls match accepted TimerHandler docs: cancel through `0x00597610`, schedule through `0x00597910`, and cancel-all-except through `0x00597630` in adjacent support methods.
- Neighbor accepted C++ already uses the same field and helper family: `m_timerHandler`, `m_spriteConfig`, `m_isMoving`, `m_facing`, `m_moveFrame`, `m_animationFrame`, `m_animationGroup`, `m_pendingDamageEffect`, `ScheduleBoxRotationStep`, `CancelBoxRotationStep`, and `TryStepForward`.
- The five timer ids are all resolved by live decompile behavior and verified decimal/hex/byte/tag conversions from `tools/int_convert.py`.

Negative evidence and rejected repair paths:

- Reject TimerHandler canonical ownership: TimerHandler provides the callback contract and wrappers, but `0x0053b830` subtracts `0xa4` to recover a LivingObjectPane owner and reads/writes LivingObjectPane fields throughout.
- Reject UserPane ownership: UserPane has direct refs into the callback and special-cases some local-player animation messages, but it delegates `FAnD` and default messages to the LivingObjectPane handler and does not own the target state machine.
- Reject MapPane/ObjectImageLib/TimerMgr ownership: those are callees or global services used by this body, not source parents for the animation/timer method cluster.
- Reject a split at `0x0053b830`: it is a separate function internally, but its adjusted-this owner math and local wrapper/caller context make it part of the coherent LivingObjectPane animation/timer child page rather than a TimerHandler page.
- Reject including `0x0053b6b3-0x0053b700`: MCP bytes show a preceding lowered switch/jump-table/data tail plus `0xcc` padding from the action helper, not source code in [UID:0002R1].
- Reject treating internal gaps as code: `0x0053b7b4-0x0053b7c0`, `0x0053b7cf-0x0053b7d0`, `0x0053b826-0x0053b830`, and post-end `0x0053baa8+` are `0xcc` alignment.
- Reject stale SoundManager/browser/audio wrapper names for `0x00597610` and `0x00597630`; current TimerHandler wrapper docs and target callers support generic timer cancel/schedule names.

## Timer Message Decisions

Use these source-facing constant names in [UID:0002R1] and support docs:

Conversion verification command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md](0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| Decimal | Hex | LE bytes / tag | Recommended constant | Behavior |
| ---: | --- | --- | --- | --- |
| `1097094982` | `0x41645746` | `46 57 64 41` / `FWdA` (Verified with `tools/int_convert.py`) | `kLivingTimerForwardStep` | Advances `m_moveFrame` modulo 4; while nonzero reschedules with the original payload and propagates linked-object mode, then calls `TryStepForward` on wrap. |
| `1095975494` | `0x41534246` | `46 42 53 41` / `FBSA` (Verified with `tools/int_convert.py`) | `kLivingTimerBoxStep` | Advances `m_boxRotationStep` modulo 6, reschedules after 200 ms, and invalidates the owner. |
| `1130906729` | `0x43684469` | `69 44 68 43` / `iDhC` (Verified with `tools/int_convert.py`) | `kLivingTimerDirectionDelay` | If still moving, reschedules using `m_spriteConfig.directionDelay`; otherwise commits `m_facing`, optionally plays facing animation, and invalidates. |
| `1148076358` | `0x446e4146` | `46 41 6e 44` / `FAnD` (Verified with `tools/int_convert.py`) | `kLivingTimerFrameAnimation` | Advances `m_animationFrame` inside `m_animationGroup`; on terminal completion removes by object id, otherwise chains back to facing animation; nonterminal frames reschedule by frame delay. |
| `1382368353` | `0x52654461` | `61 44 65 52` / `aDeR` (Verified with `tools/int_convert.py`) | `kLivingTimerRefresh` | Clears `m_pendingDamageEffect` and refreshes owner bounds when the delayed damage/effect payload is nonzero. |

`UserPane::OnAnimationStep` support needs a note that `0x14` remains a UserPane-local movement-step event, while `FWdA` and `FAnD` are now resolved as LivingObjectPane timer-message constants. `FAnD` and default timer messages delegate to `LivingObjectPane`'s adjusted handler.

## Owner And Source Placement

Keep `CANONICAL_OWNER:00007B` and `EMITTER_UIDS:00007B`. TimerHandler owns the generic callback contract and wrapper machinery, but this target owns the `LivingObjectPane` state machine using the embedded/adjusted TimerHandler view at `+0xa4`. UserPane is a caller/delegator, not the owner. MapPane, ObjectImageLib, TimerMgr, and linked-object helpers are dependencies.

The source file remains `NexusTK/map/LivingObjectPane.cpp` through [UID:0000KU]. The class page [UID:00007B] should continue to keep broad class C++ blank while exact child pages emit.

## Field And Wrapper Name Decisions

Accepted or recommended names:

- `PlayAnimation` for `0x0053b700`.
- `PlayFacingAnimation` for `0x0053b7c0`. This is more precise than a generic directional bridge because the body is only `PlayAnimation(m_facing + 1)`.
- `PlayDeathAnimation` for `0x0053b7d0`, with the caveat that the exact original spelling may have been terminal/removal oriented. The field should stay `m_terminalAnimation` for consistency with class/core docs.
- `HandleTimerMessage` for `0x0053b830`, described as the LivingObjectPane implementation of the TimerHandler callback contract. A generic `OnTimer` note can remain in TimerHandler docs, but the target page should keep the more specific handler name already used by old Wave2 notes and the target title.
- `m_boxRotationStep` at `+0x1d4`, matching the class field table.
- `m_pendingDamageEffect` at `+0x1f8` for this path, with a note that class-level render docs also call the same tail field `m_renderEffectState` in rendering contexts.

Rejected alternatives:

- Stale `SoundManager::CancelTimer` or browser/audio wrapper names for `0x00597610`/`0x00597630`.
- Assigning [UID:0002R1] to TimerHandler just because the callback uses the TimerHandler subobject.
- Splitting `0x0053b830` out as a separate TimerHandler class page; the body mutates LivingObjectPane fields and uses the adjusted owner.
- Treating `0x0053b6b3-0x0053b700` as part of this target.

## Exact Formal RECONSTRUCTION_CPP CODE Insertion

The fenced C++ below is the exact intended content for [UID:0002R1]'s formal `RECONSTRUCTION_CPP CODE` block. It is not an illustrative snippet and should not be copied into prose or any support page. If this report is accepted, insert the C++ text only between:

- `*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***`
- `*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***`

Do not insert the Markdown fence itself.

```cpp
void LivingObjectPane::PlayAnimation(unsigned int animationGroup)
{
    if (m_spriteConfig.kind != 1)
        return;

    m_timerHandler.CancelTimer(kLivingTimerFrameAnimation);

    const ImageFrameGroup *frameGroup = g_pObjectImageLib->GetFrameGroup(m_spriteConfig.imageId - 0x8000, animationGroup);
    if (frameGroup->frameCount == 0)
    {
        if (animationGroup == 0)
            g_pActiveMapPane->RemoveObjectPaneById(m_objectId);
        return;
    }

    m_animationFrame = 0;
    m_animationGroup = animationGroup;

    const ImageFrame *frame = frameGroup->GetFrame(0);
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerFrameAnimation, frame->delay, 0, 0);
    g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::PlayFacingAnimation()
{
    PlayAnimation(m_facing + 1);
}

void LivingObjectPane::PlayDeathAnimation()
{
    m_terminalAnimation = true;
    PlayAnimation(0);
    g_pActiveMapPane->ClearLivingObjectReferences(this);
}

bool LivingObjectPane::HandleTimerMessage(int timerId, int arg0, int arg1)
{
    switch (timerId)
    {
    case kLivingTimerForwardStep:
        m_moveFrame = (m_moveFrame + 1) % 4;
        if (m_moveFrame != 0)
        {
            g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerForwardStep, arg1, arg0, arg1);
            PropagateLinkedObjectMode(m_facing);
            return true;
        }

        TryStepForward();
        return true;

    case kLivingTimerBoxStep:
        m_boxRotationStep = (m_boxRotationStep + 1) % 6;
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerBoxStep, 200, 0, 0);
        g_pActiveMapPane->InvalidateObject(this);
        return true;

    case kLivingTimerDirectionDelay:
        if (m_isMoving)
        {
            g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerDirectionDelay, m_spriteConfig.directionDelay, arg0, 0);
            return true;
        }

        m_facing = static_cast<unsigned char>(arg0);
        if (m_spriteConfig.kind == 1)
            PlayAnimation(static_cast<unsigned char>(arg0) + 1);
        g_pActiveMapPane->InvalidateObject(this);
        return true;

    case kLivingTimerFrameAnimation:
    {
        const ImageFrameGroup *frameGroup = g_pObjectImageLib->GetFrameGroup(m_spriteConfig.imageId - 0x8000, m_animationGroup);
        ++m_animationFrame;

        if (m_animationFrame == frameGroup->frameCount)
        {
            if (m_terminalAnimation)
                g_pActiveMapPane->RemoveObjectPaneById(m_objectId);
            else
            {
                m_animationFrame = 0;
                PlayAnimation(m_facing + 1);
            }
            return true;
        }

        const ImageFrame *frame = frameGroup->GetFrame(m_animationFrame);
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerFrameAnimation, frame->delay, 0, 0);
        Invalidate(false);
        g_pActiveMapPane->InvalidateObject(this);
        return true;
    }

    case kLivingTimerRefresh:
        if (m_pendingDamageEffect != 0)
        {
            m_pendingDamageEffect = 0;
            Invalidate(&m_bounds);
        }
        return true;

    default:
        return false;
    }
}
```

Implementation note for the next pass: `ImageFrameGroup`, `GetFrameGroup`, and `ClearLivingObjectReferences` are source-facing helper declarations inferred from this target and support pages. If an implementation pass prefers to avoid introducing `ClearLivingObjectReferences`, it can inline the MapPane reference clears documented by the `0x0053b7d0` decompile; the target report recommendation is to keep the C++ source-shaped and avoid raw global-field writes.

## Recommended Documentation Edits

For `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`:

- Raise score to `88/89`.
- Populate only the formal `RECONSTRUCTION_CPP CODE` block with the exact C++ insertion above.
- Set or revise the `Item Summary` to carry: animation playback wrappers and adjusted TimerHandler message callback with verified `FWdA`/`FBSA`/`iDhC`/`FAnD`/`aDeR` timer constants, exact padding/range evidence, LivingObjectPane `+0xa4` owner math, and first-draft C++.
- Update Status to say the prior C++ blocker is resolved by this B007 MCP pass, with remaining confidence cap only for exact original helper/type spellings.
- Replace old session wording with current IDA MCP session `80de0a67`.
- Add the exact alignment ranges from the table above.
- Add the timer-message table and constant-name decisions from this report, including `(Verified with tools/int_convert.py)` markings.
- Record the adjusted owner math: handler `this` is `LivingObjectPane + 0xa4`, owner is recovered with `this - 0xa4`.
- Add or strengthen the positive/negative evidence summary: rejected TimerHandler/UserPane/MapPane/ObjectImageLib/TimerMgr ownership, rejected split at `0x0053b830`, and rejected inclusion of `0x0053b6b3-0x0053b700`.

For support docs:

- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`: update the child row for [UID:0002R1] to note first-draft C++ readiness; carry the five verified timer constants; record adjusted TimerHandler owner math at `+0xa4`; add/confirm `m_boxRotationStep` at `+0x1d4`; keep `m_terminalAnimation` at `+0x1d0`; keep the `m_pendingDamageEffect` / render-tail caveat at `+0x1f8`; add a B007 change note with session `80de0a67`.
- `by-class/LivingObjectPane.md`: update the [UID:0002R1] inventory/status wording from blocked by timer names to ready/implemented after B007; keep broad class C++ blank; carry the `+0xa4` adjusted TimerHandler owner math and field-name decisions for `+0x1d0`, `+0x1d4`, and `+0x1f8`; keep the confidence cap for exact original helper/type spellings.
- `by-file/LivingObjectPane.md`: update the exact child/source-route wording to reflect [UID:0002R1] as an emitting child through `NexusTK/map/LivingObjectPane.cpp` with verified timer constants and formal C++ in the exact child page; keep broad file C++ blank.
- `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`: replace stale "event tags unresolved" wording with a split decision: `0x14` remains a UserPane-local movement-step event, while `FWdA` (`0x41645746`) and `FAnD` (`0x446e4146`) are resolved LivingObjectPane timer constants; keep this UserPane page's formal C++ blank because local-player movement fields and helper signatures remain outside [UID:0002R1]'s scope.
- `by-memory/0x005a2530-0x005b8395.UserPane.md`: update the [UID:0003VD] aggregate rows/open item so they no longer say all event tags are unresolved; carry the same split decision for `0x14` versus `FWdA`/`FAnD`; keep broad UserPane aggregate C++ blank.
- `by-class/UserPane.md`: update the `OnAnimationStep` row so `0x41645746`/`0x446e4146` are no longer described as unresolved; say `0x14` and local movement field/helper naming remain the blocker for [UID:0003VD] C++.
- `by-file/UserPane.md`: update the `OnAnimationStep` / [UID:0003VD] support wording the same way: `FWdA`/`FAnD` resolved to LivingObjectPane timer constants; `0x14` and local-player field/helper names still block UserPane C++.
- No edit is recommended for `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` or `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`. Those pages were read as support evidence and already contain the generic wrapper semantics needed here. Only touch them if the supervisor explicitly requests a cross-link-only support sync; if touched, do not rename wrappers or change semantics.
- Generated tracker/coverage rows should be refreshed only by validators/executed-report tooling after accepted by-* edits; do not hand-edit generated files.

## Required Validator Commands After Implementation

Run these scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after the corresponding by-* edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md](0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor later explicitly requests optional TimerHandler wrapper cross-link edits, also run:

> Executable block R003 was removed from this report and preserved verbatim in [0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md](0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Score Rationale

Completion `88`: exact boundaries, owner/emitter route, TimerHandler adjustment, all five timer ids, field mapping, wrapper roles, caller/vtable routes, range padding, and formal first-draft C++ are now documented. This is a clear improvement over the previous `86` state because the explicit blocker on timer-message names and wrapper declarations is resolved.

Confidence `89`: behavior is strongly proven by live IDA MCP decompilation, xrefs, callees, bytes, and neighboring accepted docs. It should not be raised to `90+` yet because exact original spellings for `PlayFacingAnimation`, `PlayDeathAnimation`, `ImageFrameGroup`/`GetFrameGroup`, and the MapPane reference-clear helper are inferred rather than symbol-proven.

## Implementation Checklist (Completed)

- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: set `COMPLETION:88` and `CONFIDENCE:89`; preserve `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007B`. Proof: target metadata now records `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007B`; validator command `000000002216` re-applied the same completion/confidence/owner state.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: insert only the exact formal C++ from this report between the existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers; do not insert the Markdown fence and do not place the code in prose. Proof: the formal block now contains the report's `LivingObjectPane::PlayAnimation`, `PlayFacingAnimation`, `PlayDeathAnimation`, and `HandleTimerMessage` insertion text only, with no Markdown fence.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: update `Item Summary`, Status, Address Range, MCP/IDA Evidence, Timer Message Decisions, Owner/Source Placement, Field/Wrapper Names, Rejected Alternatives, and Score Rationale with the exact facts in this report. Proof: those sections now carry the IDA MCP session `80de0a67`, live decompile/xref evidence, owner/emitter and source-placement rationale, accepted names/fields, rejected candidates, and score rationale.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: carry the exact function/padding boundaries `0x0053b700-0x0053b7b4`, `0x0053b7b4-0x0053b7c0`, `0x0053b7c0-0x0053b7cf`, `0x0053b7cf-0x0053b7d0`, `0x0053b7d0-0x0053b826`, `0x0053b826-0x0053b830`, `0x0053b830-0x0053baa8`, and post-end padding at `0x0053baa8+`. Proof: target Address Range now has the exact function/padding table, including post-end padding exclusion.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: carry the negative boundary evidence that `0x0053b6b3-0x0053b700` is a preceding lowered switch/jump-table/data tail plus padding, not part of this target. Proof: target boundary notes now explicitly exclude `0x0053b6b3-0x0053b700` as predecessor switch/jump-table/data tail plus padding.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: carry all five timer constants with `(Verified with tools/int_convert.py)` markings: `FWdA`/`0x41645746`, `FBSA`/`0x41534246`, `iDhC`/`0x43684469`, `FAnD`/`0x446e4146`, and `aDeR`/`0x52654461`. Proof: target timer-message table carries all five constants and marks each conversion `(Verified with tools/int_convert.py)`.
- [x] Edit `by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md`: carry adjusted TimerHandler owner math (`this == owner + 0xa4`, owner recovered with `this - 0xa4`) and rejected owner/split candidates: TimerHandler, UserPane, MapPane, ObjectImageLib, TimerMgr, and separate `0x0053b830` split. Proof: target Owner/Source Placement, Field/Wrapper Names, and Rejected Alternatives sections document the `+0xa4` adjustment and reject TimerHandler, UserPane, MapPane, ObjectImageLib, TimerMgr, and a separate `0x0053b830` child split.
- [x] Edit `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`: update the [UID:0002R1] child row to first-draft C++ ready; carry the verified timer constants and `+0xa4` adjusted TimerHandler owner math; update/confirm field rows for `+0x1d0` `m_terminalAnimation`, `+0x1d4` `m_boxRotationStep`, and `+0x1f8` `m_pendingDamageEffect` / render-tail caveat; add a B007/session `80de0a67` change note. Proof: core page [UID:0002R1] child row, timer constants table, field table, core anchors, function/padding rows, and Changes entry now carry those details.
- [x] Edit `by-class/LivingObjectPane.md`: update [UID:0002R1] status/inventory wording from blocked-by-timer-names to ready/implemented after B007; keep broad class C++ blank; carry field decisions for `+0xa4`, `+0x1d0`, `+0x1d4`, and `+0x1f8`. Proof: class page status/readiness, method-family, TimerHandler relationship, field rows, and Changes entry now record [UID:0002R1] as ready/emitting in the exact child while broad class C++ remains blank.
- [x] Edit `by-file/LivingObjectPane.md`: update the exact child/source-route wording for [UID:0002R1] to say it emits through the exact child page in `NexusTK/map/LivingObjectPane.cpp`, with verified timer constants and formal C++ in the child; keep broad file C++ blank. Proof: file page source-route note, proposed contents, method-family rows, IDA evidence, and Changes entry now route emission through the exact child and keep broad file C++ blank.
- [x] Edit `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`: update Status/Behavior/Evidence/C++ Readiness/Changes as needed so `0x14` remains UserPane-local/unresolved, while `FWdA` (`0x41645746`) and `FAnD` (`0x446e4146`) are resolved LivingObjectPane timer constants; keep this page's formal C++ blank. Proof: UserPane child page now identifies `FWdA`/`FAnD` as LivingObjectPane timer constants, preserves `0x14` and local field/helper blockers, supersedes the stale unresolved-tag assumption, and leaves formal C++ blank.
- [x] Edit `by-memory/0x005a2530-0x005b8395.UserPane.md`: update [UID:0003VD] aggregate rows/open items so they no longer claim all event tags are unresolved; preserve that `0x14` and local movement field/helper names still block aggregate/UserPane C++. Proof: UserPane aggregate [UID:0003VD] row, naming table, child/split policy, open question, confidence rationale, and Changes entry now carry the accepted split.
- [x] Edit `by-class/UserPane.md`: update the `OnAnimationStep` row to remove `0x41645746`/`0x446e4146` from the unresolved list and identify them as `FWdA`/`FAnD` LivingObjectPane timer constants; keep `0x14` unresolved/local and keep [UID:0003VD] C++ blank. Proof: class page `OnAnimationStep` row, emission policy, evidence note, and Changes entry now make that split and preserve the blank formal C++ disposition.
- [x] Edit `by-file/UserPane.md`: update the `OnAnimationStep` / [UID:0003VD] support wording with the same split: `FWdA`/`FAnD` resolved, `0x14` plus local-player field/helper names still block UserPane C++. Proof: file page `OnAnimationStep`/`OnClipBounds` row, exact split/C++ policy bullet, and Changes entry now carry that support wording.
- [x] Do not edit `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` or `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` unless the supervisor explicitly requests optional cross-links; if that happens, add only a cross-link to [UID:0002R1] and do not change wrapper names/semantics. Proof: excluded because the callback explicitly said not to edit TimerHandler wrapper pages; no optional wrapper files were changed and no optional validators were needed.
- [x] Do not manually edit `auto-generated/*`, any `-coverage-report.md`, validator state, project-level files, generated C++ output, IDA DB state, or unrelated by-* pages. Proof: no manual edits were made to generated files, coverage reports, validator state/cache/tool state, project-level files, generated C++ output, IDA DB state, or unrelated by-* pages; validator-owned side effects are recorded below.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-01`, local timestamp `2026-06-26T07:58:59Z`; validator `command_id: 000000002216`, `command_timestamp: 2026-06-26T03:59:00-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-02`, local timestamp `2026-06-26T07:59:15Z`; validator `command_id: 000000002217`, `command_timestamp: 2026-06-26T03:59:15-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-class/LivingObjectPane.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-03`, local timestamp `2026-06-26T07:59:30Z`; validator `command_id: 000000002219`, `command_timestamp: 2026-06-26T03:59:30-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-file/LivingObjectPane.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-04`, local timestamp `2026-06-26T07:59:40Z`; validator `command_id: 000000002221`, `command_timestamp: 2026-06-26T03:59:40-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-05`, local timestamp `2026-06-26T07:59:50Z`; validator `command_id: 000000002222`, `command_timestamp: 2026-06-26T03:59:50-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-memory/0x005a2530-0x005b8395.UserPane.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-06`, local timestamp `2026-06-26T07:59:59Z`; validator `command_id: 000000002223`, `command_timestamp: 2026-06-26T04:00:00-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-07`, local timestamp `2026-06-26T08:00:10Z`; validator `command_id: 000000002224`, `command_timestamp: 2026-06-26T04:00:10-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] From `E:\NTK\GhidraBridge\source-3\project-documentation`, run `python .\tools\validator.py --mode file --file by-file/UserPane.md --apply --queue-timeout 240` and record exit code, `command_id`, `command_timestamp`, and `ok` count. Proof: local id `B007-VAL-0002R1-08`, local timestamp `2026-06-26T08:00:20Z`; validator `command_id: 000000002226`, `command_timestamp: 2026-06-26T04:00:20-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] If optional TimerHandler wrapper cross-link edits are explicitly requested, also run the two optional validator commands listed in this report and record the same result fields. Proof: not applicable; optional cross-link edits were not explicitly requested and the callback explicitly said not to edit the TimerHandler wrapper pages.
- [x] After validators, report any validator-owned generated side effects instead of manually editing generated files; supervisor should handle accepted-report execution with `execute_report` only after Rule 26 verification. Proof: all eight validators returned `generated_refresh: deferred`; validator-owned `projected_stats_update`, reference-index, canonical/autogen registry, and UID-link updates were left to validator lifecycle output only. No manual generated/state/coverage edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002R1-LivingObjectPaneAnimationTimer-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002R1-LivingObjectPaneAnimationTimer-source-quality.md","timestamp":"2026-06-26T04:05:46","uid":"0002R1"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002R1-LivingObjectPaneAnimationTimer-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002R1-LivingObjectPaneAnimationTimer-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002R1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
