** TARGET-REPORT-UID:0003UD **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UD **
# 0003UD LivingObjectPaneTryPerformAction Source-Quality Report

## Report Status

- Assignment: `B014-goal2-livingobject-try-perform-action-source-quality-0003UD-20260619`.
- Target: [UID:0003UD] `by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank C++.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0003UD-LivingObjectPaneTryPerformAction-source-quality.md`.
- Work mode: report-only. No by-* documentation file and no `by-memory/-coverage-report.md` file was edited by this pass.

## Executive Recommendation

Update the target to source-quality prose and emit first-draft method C++ in the later implementation callback.

Recommended final source-facing method:

```cpp
void LivingObjectPane::TryPerformAction();
```

The old Wave2 `char LivingObjectPane::TryPerformAction()` signature should be rejected. The method has no source-reliable return value: both live callers use it as a statement and ignore `al`, and the normal early-return paths do not set a return byte. The source behavior is a void "try" method with internal early exits.

Recommended post-incorporation metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Rationale: exact range, two direct caller routes, instruction-level branch logic, key fields/globals, callee relationship, raw-helper relationship, arrow-warning path, and C++ readiness are now resolved. Confidence should remain below final-source/audit levels because the original spellings of the local-player action-mode fields and the exact source names of two equipment classifier helpers are inferred/descriptive.

## Evidence Checked

Governing instructions checked:

- `tools/leaser/Agents/Supervisor.md`.
- `.codex/AGENTS.md`.
- `tools/leaser/Agents/Agent-B014/goal.md`.
- `tools/leaser/Agents/Agent-B014/notes.md`.

Target and support docs checked:

- Target [UID:0003UD] `by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md`.
- [UID:0000KU] `by-file/LivingObjectPane.md`.
- [UID:00007B] `by-class/LivingObjectPane.md`.
- [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- [UID:0003UZ] `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`.
- [UID:0003H5] `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`.
- [UID:0003H4] `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`.
- [UID:0003EB] `by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md`.
- [UID:0003ZS] `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`.
- [UID:0003V9] `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md`.
- [UID:0003JN] `by-memory/0x006309dc-0x006309f4.UserPaneArrowShortageWarningString.md`.
- [UID:0002B5] `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`.
- [UID:0000EA] `by-class/SystemMessagePane.md`.
- [UID:0001J6] `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`.
- [UID:0001OR] `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`.
- [UID:0000QK] `by-global/g_pCollectionData.md`.
- [UID:0002VW] `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`.
- [UID:0001WD] `by-type/by-struct/TimerMgrLayout.md`.
- [UID:0002KZ] `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`.
- [UID:000358] `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`.
- [UID:0003Z5] `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- [UID:0001OR]/[UID:0000QK] local-player/UserPane state pointer docs for `dword_67A748`.
- [UID:0000FQ] `by-class/UserPane.md`.
- B001 `tools/leaser/Agents/Agent-B001/research/00007B-LivingObjectPane-class-source-quality.md`.
- Historical lead only: `by-memory/-report.old.md` around `0x005A58C0` and `0x005ACC30`.

Coverage and generated-output checks:

- `by-memory/-coverage-report.md`: searched for `0003UD`, `005a58c0`, `LivingObjectPaneTryPerformAction`, and `TryPerformAction`. No current target row exists. The parent [UID:0001KM] row exists at the local-player split index, but this target and several nearby exact LivingObjectPane children are missing from the current supervisor-owned report.
- `project-level/-auto-completion-stats.md`: current row is `| 0003UD | 85 | 87 | 86.0 | by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md |`.
- `auto-generated/-ag-memory-coverage.md`: current generated route is `0003UD` emits through owner/emitter `00007B` to `auto-generated/NexusTK/map/LivingObjectPane.cpp`, with no emitted code.
- `auto-generated/NexusTK/map/LivingObjectPane.cpp`: current target output is only an empty emitter marker.
- `auto-generated/NexusTK/map/MapPane.cpp`: contains a generated statement-form call to `TryPerformAction()`, useful only as a generated-output lead.

Fresh local PE evidence checked:

- PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`, image base `0x00400000`.
- Disassembly performed locally with Capstone from the raw PE, not by editing IDA.
- Target bytes mapped through `.text`; `0x005a58c0` file offset `0x001a4cc0`.
- Disassembled target range `0x005a58c0-0x005a5983` and caller contexts around `0x00509092` and `0x005a5f87`.
- Dumped primary `LivingObjectPane` vtable words around `0x0062097c` to confirm vtable slot `+0x70` targets `0x0053b3d0`.

## Exact Target Behavior

The method starts at `0x005a58c0`, returns at `0x005a5982`, and has exclusive end `0x005a5983`. No tail bytes or child split are needed.

Instruction-level behavior:

| Address | Evidence | Source role |
| --- | --- | --- |
| `0x005a58c0-0x005a58c4` | `push esi; mov esi, ecx; push edi; mov edi, [0x67ab80]` | Saves receiver as local-player/LivingObjectPane object and caches `g_pTimerMgr`. |
| `0x005a58ca-0x005a58da` | compares byte `this+0x19a` against `3` and `1`, both jump to return | Action/sprite state gate. Values `1` and `3` suppress a new action. |
| `0x005a58e0-0x005a58f8` | loads word `this+0x182`, calls `0x004e05d0`, compares result with `3` | Classifies the current sprite/equipment attribute. Result `3` selects the faster action delay. |
| `0x005a58f0-0x005a590b` | sets delay `0x1f4`/500 by default, uses `0x64`/100 when classifier result is `3`, compares `g_pTimerMgr->currentTick - this+0x13eaf8` | Local action rate gate. The old "cooldown helper" interpretation is wrong; the delay test is inline. |
| `0x005a590d-0x005a5929` | loads word `this+0x184`, calls `0x004e0630`, checks byte `this+0x13eb3c`, and compares classifier result with `2` | Target/action-mode plus secondary equipment/ammo classifier gate. If target/action mode is nonzero and classifier result is not `2`, the method enters the arrow-warning path. |
| `0x005a592b-0x005a594f` | loads `g_pChattingViewport`, pushes `0x6309dc`, `0x84`, `0x24`, clears `pane+0x130`, calls `0x005854d0`, tail-jumps to `0x00585360` | Arrow-shortage system-message path through `SystemMessagePane` helpers. No action packet is sent and `m_lastActionTick` is not updated on this path. |
| `0x005a5954-0x005a5956` | `mov ecx, esi; call 0x005acc30` | Calls `LivingObjectPane::SendActionPacketWithAutoFace()`. |
| `0x005a595b-0x005a5974` | if byte `this+0x13eb3c` is `1` or `2`, calls vtable slot `+0x70` with arguments `0x1b`, `0xc8`, `0` | Post-action animation/effect dispatch. Vtable dump confirms slot `0x006209ec` targets `0x0053b3d0`, documented as `PlayActionAnimationOrEffect`. |
| `0x005a5977-0x005a597a` | stores `[g_pTimerMgr+0x18]` into `this+0x13eaf8` | Updates last successful action tick. |
| `0x005a5980-0x005a5982` | `pop edi; pop esi; ret` | Void-style early return; no reliable return value. |

The exact packet/action path is therefore:

1. Reject if current action/sprite state byte `+0x19a` is `1` or `3`.
2. Reject if the last successful action tick is too recent. Normal threshold is `500`; classifier result `3` on `+0x182` lowers the threshold to `100`.
3. If `+0x13eb3c` is nonzero and classifier result on `+0x184` is not `2`, show the arrow-shortage system message and return.
4. Otherwise call `SendActionPacketWithAutoFace()`.
5. If `+0x13eb3c` is `1` or `2`, play action/effect `27` with value `200` and facing `0`.
6. Store the current TimerMgr tick into `+0x13eaf8`.

## Caller Route

There are two direct caller sites in the current PE/IDA evidence.

| Caller site | Evidence | Meaning |
| --- | --- | --- |
| `0x00509092` inside [UID:0003ZS] `MapPane::OnTimerEvent` | Disassembly around function `0x00509030`: `mov ecx, dword ptr [0x67a748]; call 0x5a58c0`, followed by scheduling timer event `7` for `0x1f4`/500 ms. | MapPane event `7` action-poll route, but the receiver is the local-player/UserPane state pointer `dword_67A748`, not an arbitrary `m_activeObjectPane` load in the final source-quality reading. The existing MapPane draft using `m_activeObjectPane->TryPerformAction()` is directionally useful but less exact than the instruction evidence. |
| `0x005a5f87` inside [UID:0003V9] `UserPane::OnKeyEvent` | Disassembly around function `0x005a5bd0`: `lea ecx, [esi-0xa0]; call 0x5a58c0`; caller then sets `al=1` and returns handled. | Keyboard/action route from UserPane. The `esi-0xa0` adjustment is the local UserPane/LivingObjectPane subobject/facet correction. |

Both callers ignore the target's return value. This is the strongest signature evidence for `void`.

## Relationship To `0x005acc30`, [UID:0003H5], And [UID:0003EB]

`0x005acc30` / [UID:0003UZ] is the only modeled callee from the target action-send path. The target does not directly perform facing math, does not directly reference the `-1.0f` constant, and does not directly send opcode `0x11` or opcode `0x13`; it delegates that work to `SendActionPacketWithAutoFace()`.

[UID:0003UZ] `0x005acc30-0x005acd85`:

- One direct caller at `0x005a5956`, from this target.
- Reads the same selected-target/action-mode byte family (`this+0x13eb3c`) and local-player target globals documented by [UID:0003H5].
- Looks up the selected target, compares target coordinates with `ObjectPane`/`LivingObjectPane` position fields, computes auto-facing direction, sends opcode `0x11` when facing changes, and sends the action packet opcode `0x13`.
- Uses [UID:0003EB] `0x00630c24` `-1.0f` at refs `0x005accf9` and `0x005acd18`.

[UID:0003H5] `0x005acb20-0x005acc23`:

- Raw no-function/no-route helper.
- Not called by this target.
- Shares the auto-face direction subset with `0x005acc30`: selected-target check, target lookup through `dword_67A764`/`dword_69BF28`, position compare, `1.0f`/`-1.0f` slope thresholds, `this+0x1c5` facing byte, and opcode `0x11` send when direction changes.
- Should remain documented as a retained raw sibling, not as the helper actually invoked by `TryPerformAction`.

[UID:0003EB] `0x00630c24-0x00630c28`:

- Not referenced directly by `0x005a58c0`.
- Connected to this target only through the callee `0x005acc30`.
- Support doc should say this constant belongs to action-facing helpers, but not imply that `TryPerformAction` itself uses slope thresholds.

## Best Source-Quality Names And Types

| Binary name or item | Best current source-facing name/type | Evidence and caveat |
| --- | --- | --- |
| `sub_5A58C0` | `void LivingObjectPane::TryPerformAction()` | Two direct callers use statement form and ignore return; normal early exits do not set a return value. |
| `sub_5ACC30` | `LivingObjectPane::SendActionPacketWithAutoFace()` | One direct caller from `0x005a5956`; support docs already use this name. |
| `sub_4E05D0` | `ClassifyHumanPartFiveBucket(unsigned int id)` / equipment-part five-bucket classifier | [UID:00017R] support identifies this as a NewHumanImageLib local classifier mapping `10000`-wide ranges into buckets `1..5`; here it selects `100` versus `500` tick delay. It is not a cooldown helper. |
| `sub_4E0630` | `ClassifyHumanPartTwoBucket(unsigned int id)` / equipment-part two-bucket classifier | Same support cluster identifies it as a smaller two-bucket classifier. In this target result `2` allows the selected-target action path; non-`2` with action mode nonzero shows arrow-shortage warning. |
| `dword_67AB80` | `TimerMgr *g_pTimerMgr` | Exact global page [UID:0002VW]; TimerMgr layout [UID:0001WD] defines `+0x18` as `currentTick`. |
| `dword_67A748` | `g_pCollectionData` as local-player/UserPane state pointer alias | Exact global page [UID:0001OR] says the storage is UserPane/local-player state; MapPane caller loads it directly as the receiver for this method. The collection name is a view alias, not collection-only ownership. |
| `dword_67ADC4` | `SystemMessagePane *g_pChattingViewport` | Exact global cluster [UID:0002B5] and SystemMessagePane docs identify it as the system-message/chat viewport slot. |
| `unk_6309DC` / `0x006309dc` | `kArrowShortageWarningText` or `kNotEnoughArrowsMessage` | Exact string child [UID:0003JN] currently uses arrow-shortage warning name. Direct xref is this target at `0x005a593a`. |
| `sub_5854D0` | `SystemMessagePane::AppendColoredText(...)` / colored text append helper | [UID:0000EA]/[UID:0001J6] map `0x005854d0-0x0058555a` as colored text append helper. Target passes string, `0x84`, `0x24`. |
| `sub_585360` | `SystemMessagePane::RefreshAndPruneMessages()` / refresh-prune helper | [UID:0000EA]/[UID:0001J6] map `0x00585360-0x005854ac` as refresh/prune helper. Target tail-jumps to it after appending warning. |
| vtable slot `+0x70` | `LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing)` | Vtable word at `0x006209ec` is `0x0053b3d0`; [UID:0003Z5] supplies the source-facing name and signature. |
| field `this+0x19a` | `m_actionGateState` / `m_currentActionState` (descriptive) | Only target evidence: byte values `1` and `3` suppress action. Do not overclaim exact original spelling. |
| field `this+0x182` | `m_spriteAttribute` / primary equipment or sprite attribute id | [UID:0001DE] documents `SetSpriteAttribute` writing `this+0x182`; target reads it as a word and classifies it. The exact source role is broader than the old one-byte wording; target docs should keep offset plus descriptive name. |
| field `this+0x184` | secondary equipment/ammo attribute id (descriptive) | Target reads it as a word, classifies it with the two-bucket helper, and uses it only for the selected-target arrow-warning gate. Best inference is arrow/ammo-capability attribute, but exact source spelling is not proven. |
| field `this+0x13eaf8` | `m_lastActionTick` | Target reads and writes this as the last successful action time. UserPane docs show `HideNameLabel` caching `g_pTimerMgr->currentTick` into the same offset. |
| field `this+0x13eb3c` | `m_pendingTargetActionMode` / `m_selectedTargetActionMode` | This target treats nonzero as target/action mode for the arrow-warning gate and values `1` or `2` as post-action animation modes. [UID:0003H5]/[UID:0003UZ] check this byte while resolving auto-face target state. It is not merely a bool. |
| field `this+0x1c5` | `m_facing` | Not read by this target, but central to callee/raw helper relationship. [UID:0001DE] and [UID:0003Z5] already document it as facing byte. |
| `g_pChattingViewport +0x130` | SystemMessagePane internal update/scroll/list state byte | Target clears it before appending the warning. Existing SystemMessagePane docs do not prove final field spelling; keep descriptive. |

## Heuristic / Inference Reanalysis And Validation

### Generated Names And Stale Names

`sub_5A58C0` is too weak and should be replaced in prose with `LivingObjectPane::TryPerformAction`. The method name is supported by the target title, old integration lead, generated MapPane statement call, and instruction behavior.

The Wave2 `char` return is rejected. The method returns without setting `al` on ordinary early exits and both direct callers ignore the return. The warning path tail-jumps to `SystemMessagePane` refresh, whose return, if any, is also ignored by callers. Source should be `void`.

The old Wave2 phrase "cooldown helpers at `0x004E05D0` / `0x004E0630`" is rejected. Current support docs identify these as NewHumanImageLib equipment/human-part classifiers. The cooldown/rate gate in this target is inline: choose `500` or `100`, subtract `m_lastActionTick` from `g_pTimerMgr->currentTick`, and return if the delta is not greater than the threshold.

Generated MapPane C++ uses `m_activeObjectPane->TryPerformAction()`. Fresh caller disassembly shows the exact event-7 call loads `dword_67A748` as receiver. Because `dword_67A748` is the local-player/UserPane state pointer, final prose should describe the event-7 route as local-player action polling. `m_activeObjectPane` remains a nearby MapPane concept but is not the exact instruction evidence for this call site.

### Ownership And Source Placement

Accepted owner: [UID:00007B] `LivingObjectPane`, emitted through [UID:0000KU] `LivingObjectPane.cpp`.

Evidence:

- Target metadata already routes through [UID:00007B].
- The receiver fields match `LivingObjectPane` local-player action, sprite/equipment, facing, and action-tail state.
- The callee `0x005acc30` is `LivingObjectPane::SendActionPacketWithAutoFace`.
- The post-action vtable slot resolves through the `LivingObjectPane` vtable to `0x0053b3d0`.
- `by-file/LivingObjectPane.md` and `by-class/LivingObjectPane.md` place movement/action packet helpers in `NexusTK/map/LivingObjectPane.cpp`.

Rejected direct owners:

- `UserPane`: rejected as direct owner for the method. UserPane constructs and owns the local-player state pointer and has a keyboard caller, but this body dispatches living-object action/facing behavior and calls LivingObjectPane action helpers. UserPane remains a caller/aggregate-state context.
- `MapPane`: rejected as direct owner. MapPane schedules and polls the action timer, but the method receiver and state are local-player/LivingObjectPane.
- `SystemMessagePanes`: rejected as direct owner. SystemMessagePane helpers are only used for the warning path.
- `NewHumanImageLib`: rejected as direct owner. Its classifiers are dependencies, not the action method owner.

Support-data ownership issue:

- [UID:0003JN] arrow-warning string is currently assigned to [UID:0000P1] `UserPane`. This should be revisited in implementation. The old assignment called `sub_5A58C0` a "UserPane-range helper", but this report resolves `sub_5A58C0` as `LivingObjectPane::TryPerformAction`. Since the string has a single direct xref at `0x005a593a` from this method and no independent string-table evidence, the best direct source owner is now [UID:0000KU] `LivingObjectPane.cpp` as file-level string data, or at minimum the string page must say its only consumer is a LivingObjectPane method. This support correction is not required to emit the target method body, but it is a Rule 26 incorporation item.

### Field And Global Inferences

The local-player offsets above `+0x13e000` are adjusted UserPane/local-player aggregate fields viewed through a LivingObjectPane-compatible receiver. This matches the broader LivingObjectPane class report caveat: the standalone LivingObjectPane pool block is much smaller, while UserPane/local-player state has large arrays and local command fields. The target can still be a LivingObjectPane method because UserPane appears to derive from or embed the LivingObjectPane-compatible base at the relevant receiver view.

`this+0x13eaf8` can be named `m_lastActionTick` with high confidence for this method. It is compared against current tick at method entry and updated only after successful action packet dispatch. It is not updated on the warning path.

`this+0x13eb3c` should not be named only `m_hasSelectedTarget`. It is byte-valued mode state:

- `0` skips the arrow/ammo warning predicate and sends action.
- nonzero plus secondary classifier result not `2` shows arrow warning.
- values `1` and `2` trigger `PlayActionAnimationOrEffect(27, 200, 0)` after send.
- [UID:0003H5]/[UID:0003UZ] use the same byte in selected-target auto-face logic.

Best descriptive name for now: `m_pendingTargetActionMode` or `m_selectedTargetActionMode`.

`this+0x182` and `this+0x184` are not fully final. Existing core docs say `+0x182` is a sprite/config field written by `SetSpriteAttribute`; target reads it as a word and classifies it. `+0x184` is the secondary classifier input tied to arrow availability. The implementation should preserve offsets and descriptive names rather than freeze weapon/ammo field spellings without a broader sprite/equipment layout pass.

### Split And Range Decisions

No child split is needed.

- Exact function range is `0x005a58c0-0x005a5983`.
- Return is at `0x005a5982`.
- The target has a compact single-purpose body: action-state/rate/ammo gate, warning display, action send, optional action effect, tick update.
- The warning literal [UID:0003JN], SystemMessagePane helpers, `0x005acc30`, and raw auto-face helper pages are dependencies/support children, not internal ranges of this target.

### Open-Question Closure

| Prior open question | Resolution |
| --- | --- |
| Final source-facing name/signature | `void LivingObjectPane::TryPerformAction()`. Reject `char` return. |
| Local-player action gating | Closed: gate `+0x19a` values `1`/`3`, tick delta against 500 or 100 based on classifier result, selected-target/ammo warning gate via `+0x13eb3c` and classifier result on `+0x184`. |
| Selected target field names | Best descriptive field is `m_pendingTargetActionMode` / `m_selectedTargetActionMode` at `+0x13eb3c`; exact original spelling cannot be recovered from current evidence, but behavior is no longer open. |
| Facing relationship | Target does not read `m_facing`; `0x005acc30` and [UID:0003H5] use `m_facing` at `+0x1c5` for auto-face packet `0x11`. |
| Action-state field names | `+0x19a` is action/sprite gate state, exact spelling unresolved but role is closed. |
| Relationship to `0x005acc30` | Direct call at `0x005a5956`; callee owns facing math and action packet send. |
| Relationship to [UID:0003H5] | Raw no-route sibling with shared auto-face direction subset; not called by target. |
| Relationship to [UID:0003EB] | Indirect only through `0x005acc30`; target has no direct `-1.0f` ref. |
| Caller route | Closed: MapPane event-7 local-player action polling at `0x00509092`; UserPane key-action route at `0x005a5f87`. |
| Owner/source placement | Direct method owner [UID:00007B] `LivingObjectPane`, file [UID:0000KU] `LivingObjectPane.cpp`; UserPane and MapPane are caller/state contexts. |
| First-draft C++ | Eligible and recommended now in implementation callback. |

## First-Draft C++ Recommendation

First-draft C++ should be emitted now during the implementation callback. This target is a modeled single method, has confirmed owner/emitter metadata, has a score average above the active minimum, has exact branch/callee evidence, and has no split/range blocker.

Suggested draft:

```cpp
void LivingObjectPane::TryPerformAction()
{
    unsigned char actionState = m_actionGateState;
    if (actionState == 3 || actionState == 1)
        return;

    unsigned int delay = 500;
    if (ClassifyHumanPartFiveBucket(m_primarySpriteAttribute) == 3)
        delay = 100;

    unsigned int currentTick = g_pTimerMgr->currentTick;
    if (currentTick - m_lastActionTick <= delay)
        return;

    int secondaryClass = ClassifyHumanPartTwoBucket(m_secondarySpriteAttribute);
    if (m_selectedTargetActionMode != 0 && secondaryClass != 2)
    {
        SystemMessagePane *pane = g_pChattingViewport;
        pane->m_pendingRefreshByte = 0;
        pane->AppendColoredText(kArrowShortageWarningText, 0x84, 0x24);
        pane->RefreshAndPruneMessages();
        return;
    }

    SendActionPacketWithAutoFace();

    if (m_selectedTargetActionMode == 1 || m_selectedTargetActionMode == 2)
        PlayActionAnimationOrEffect(27, 200, 0);

    m_lastActionTick = currentTick;
}
```

Draft caveats to carry into the target doc:

- Field names `m_actionGateState`, `m_primarySpriteAttribute`, `m_secondarySpriteAttribute`, `m_selectedTargetActionMode`, and `m_pendingRefreshByte` are descriptive placeholders.
- Helper names `ClassifyHumanPartFiveBucket` and `ClassifyHumanPartTwoBucket` are support-doc names, not proven original symbols.
- `SystemMessagePane` helper member names should be aligned with [UID:0000EA]/[UID:0001J6]; the target can call them descriptively without freezing final class fields.
- The code must remain in [UID:0003UD], not the broad [UID:0001KM] split index.

## Rejected Alternatives

- Keep C++ blank because helper/field names are imperfect: rejected. The behavior is exact enough for a first-draft method, and Rule 24 favors drafting eligible method bodies when remaining issues are descriptive spelling rather than control-flow uncertainty.
- Emit return type `bool` or `char`: rejected. Caller and body evidence support `void`.
- Treat `0x004e05d0` and `0x004e0630` as cooldown helpers: rejected. They classify equipment/human-part ids; the cooldown test is inline.
- Model the method as `UserPane::TryPerformAction`: rejected. UserPane is caller/local-player state context, while action/facing ownership and emitter route are LivingObjectPane.
- Model the method as `MapPane` active-object logic: rejected. MapPane timer event is a caller only; fresh disassembly loads `dword_67A748` for the receiver.
- Model [UID:0003H5] as the direct auto-face helper called from this target: rejected. The target calls modeled `0x005acc30`, and [UID:0003H5] has no route.
- Move [UID:0003EB] into this target: rejected. The target has no direct xref to the `-1.0f` literal.

## Target And Support Implementation Checklist

Target doc `by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md`:

1. Update scores to `COMPLETION:88` and `CONFIDENCE:90`.
2. Keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
3. Replace open questions with the resolved field/helper/caller table from this report.
4. Add exact instruction evidence for:
   - `+0x19a` values `1`/`3` early return.
   - `+0x182` classifier selecting `500` or `100` tick delay.
   - `g_pTimerMgr->currentTick - +0x13eaf8` rate gate.
   - `+0x184` classifier plus `+0x13eb3c` warning gate.
   - arrow warning call sequence through `g_pChattingViewport`, `0x006309dc`, `0x005854d0`, and `0x00585360`.
   - direct call to `0x005acc30`.
   - vtable slot `+0x70` / `0x0053b3d0` call with `(27, 200, 0)`.
   - `+0x13eaf8` update after successful send.
5. Add caller route evidence:
   - `0x00509092` loads `dword_67A748` and calls target, then schedules timer event `7` for 500 ms.
   - `0x005a5f87` calls target with `ecx = esi - 0xa0` from UserPane key dispatch.
6. Add the first-draft C++ block using descriptive names and caveats above.
7. Add a change entry noting B014 2026-06-19 source-quality reanalysis and stale Wave2 name corrections.

Support docs:

1. `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`:
   - Add the resolved `TryPerformAction` branch behavior, caller route, and C++ readiness under the exact child inventory.
   - Replace any "cooldown helper" wording for `0x004e05d0` / `0x004e0630` with classifier wording.
   - Keep the parent split index non-emitting.

2. `by-class/LivingObjectPane.md` and `by-file/LivingObjectPane.md`:
   - Add or refresh the action helper row with `TryPerformAction`, `SendActionPacketWithAutoFace`, `m_lastActionTick`, `m_selectedTargetActionMode`, and the raw-helper relationship.
   - Preserve the adjusted local-player/UserPane aggregate warning for `+0x13eaf8` and `+0x13eb3c`.

3. `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`:
   - Record that its sole modeled caller is `TryPerformAction` at `0x005a5956`.
   - Add that `TryPerformAction` owns the pre-send rate/ammo gate while this callee owns facing math and action packet send.
   - Keep final C++ blank until its packet writer/field names are ready, unless a separate callback resolves it.

4. `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`:
   - Add a support note that [UID:0003UD] does not call this raw helper; it calls modeled `0x005acc30`.
   - Preserve no-route/raw policy.

5. `by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md`:
   - Add that [UID:0003UD] reaches this constant only indirectly through `0x005acc30`; no direct target xref exists.

6. `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`:
   - Correct or caveat the event-7 first-draft call: instruction evidence at `0x0050908c-0x00509092` loads `dword_67A748` before calling `TryPerformAction`.
   - Keep the higher-level behavior as left-button/action poll and 500 ms reschedule.

7. `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md`:
   - Add the exact call-site evidence `0x005a5f81 lea ecx, [esi-0xa0]; 0x005a5f87 call 0x005a58c0`.

8. `by-memory/0x006309dc-0x006309f4.UserPaneArrowShortageWarningString.md`:
   - Update prose to say the only direct xref is now resolved as `LivingObjectPane::TryPerformAction`, not merely a "UserPane-range helper".
   - Recommended ownership correction candidate: move direct owner/emitter to [UID:0000KU] `LivingObjectPane` file-level data, or explicitly justify keeping [UID:0000P1] despite the only consumer being a LivingObjectPane method.

9. `by-class/SystemMessagePane.md` and `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`:
   - No required score change.
   - Optional: add the `TryPerformAction` warning-path caller to the colored-text append and refresh/prune helper notes.

10. `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`:
    - Optional support note: `0x005a58c0` uses `0x004e05d0` and `0x004e0630` as classifier dependencies for local-player action gating.

11. `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` and `by-global/g_pCollectionData.md`:
    - Optional support note: MapPane event-7 call uses `dword_67A748` directly as the receiver for `LivingObjectPane::TryPerformAction`.

12. `by-memory/-coverage-report.md`:
    - Supervisor-owned only. B014 must not edit it directly.
    - Insert the target row under [UID:0001KM] after the local-player LivingObjectPane command/action children are ordered.

## Exact Supervisor-Owned Coverage Row

Baseline search result: current `by-memory/-coverage-report.md` has no existing row for `0003UD`, `0x005a58c0`, `LivingObjectPaneTryPerformAction`, or `TryPerformAction`.

Exact proposed supervisor-owned row after target incorporation:

```text
        - [UID:0003UD][0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md) 0x005a58c0-0x005a5983 | method | LivingObjectPaneTryPerformAction : reconstructable : 88% : very-strong : B014 2026-06-19 source-quality reanalysis resolves this as `void LivingObjectPane::TryPerformAction()`: direct callers are MapPane event-7 local-player action polling at `0x00509092` with `ecx=dword_67A748` and UserPane key-action dispatch at `0x005a5f87` with `ecx=esi-0xa0`; the method gates action states `this+0x19a` values `1`/`3`, uses `ClassifyHumanPartFiveBucket(this+0x182)` only to select a 500 ms or 100 ms `g_pTimerMgr->currentTick - this+0x13eaf8` delay, uses `ClassifyHumanPartTwoBucket(this+0x184)` plus target/action mode byte `this+0x13eb3c` to choose the arrow-shortage warning path, appends `0x006309dc` through `g_pChattingViewport`/SystemMessagePane helpers `0x005854d0` and `0x00585360`, otherwise calls [UID:0003UZ] `SendActionPacketWithAutoFace`, runs vtable slot `+0x70` / `PlayActionAnimationOrEffect(27, 200, 0)` for mode `1` or `2`, and updates `m_lastActionTick`; stale Wave2 `char` return and "cooldown helper" names are rejected, no child split is needed, and first-draft C++ is ready with descriptive field/helper names.
```

## Validator Baseline Result

Scoped baseline command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003UD-LivingObjectPaneTryPerformAction-source-quality-removed.md](0003UD-LivingObjectPaneTryPerformAction-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Baseline result:

- Exit code `0`.
- `ok: 1`.
- Target result: `ok 0003UD by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md UID header exists`.
- Dry run only; no target/support/generated file was changed.
- The validator also reported expected dry-run/autogen noise such as `stats_incremental_skip`, `autogen_registry_rebuild`, many `autogen_emitter_has_no_code`, `autogen_cpp_noop`, and unchanged autogenerated reports. No target validation failure was reported.

## Files Created Or Modified

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0003UD-LivingObjectPaneTryPerformAction-source-quality.md`

Not modified:

- No by-* documentation files.
- No `by-memory/-coverage-report.md`.
- No auto-generated output files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UD","source_path":"executed-b-agent-research/B014/0003UD-LivingObjectPaneTryPerformAction-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
