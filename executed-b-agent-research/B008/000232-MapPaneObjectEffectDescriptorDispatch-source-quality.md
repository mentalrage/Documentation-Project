** TARGET-REPORT-UID:000232 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000232 MapPaneObjectEffectDescriptorDispatch Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: treat `0x0050e320-0x0050e4b6` as a source-authored private `MapPane` method, best source-facing name `MapPane::ApplyObjectEffect(int objectId, int effectId, int timerAction, bool compactEffect)`, emitted through class UID `00007Q` and source file UID `0000L3`.
- Final disposition: no split required. Raise the target from `84/88` to `88/91`, change direct owner/emitter from file UID `0000L3` to class UID `00007Q`, and populate first-draft source-style C++ once the supervisor accepts this report.
- Required action: update the target doc and support docs with the final method/helper names, `EffectInfo` field semantics, child-list offsets, timer-action semantics, compact-flag route, caller evidence, and C++ readiness below. Do not edit `by-memory/-coverage-report.md`; the exact pending row is included in this report.
- Confidence: high for range, ABI, owner/source route, callers, callee roles, pass semantics, helper signatures, and C++ eligibility; medium-high for exact original source names because the binary supports descriptive names but not original symbol spelling.

## Supporting Research

## Target
- Target UID: `000232`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`.
- Source queue/report row: `project-level/-auto-completion-stats.md` currently lists `000232 | 84 | 88 | 86.0`.
- Current documented state: `RECONSTRUCTABLE:TRUE`, `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3`, blank C++.
- Recommended state: `RECONSTRUCTABLE:TRUE`, `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, first-draft C++ ready.

## Executive Recommendation
- Best direct owner: [UID:00007Q][MapPane](../../../../by-class/MapPane.md).
- Best source file route: [UID:0000L3][MapPane](../../../../by-file/MapPane.md), with generated output under `auto-generated/NexusTK/map/MapPane.cpp`.
- Best source-facing method name: `MapPane::ApplyObjectEffect`. This is a descriptive source-quality name, not original-proof. `MapPaneObjectEffectDescriptorDispatch` remains acceptable as the documentation filename, but it is too mechanical for first-draft C++.
- Signature: `void MapPane::ApplyObjectEffect(int objectId, int effectId, int timerAction, bool compactEffect)`.
- The target is a single exact function with no scalar-delete, EH, base-destructor, thunk, or pooled-wrapper content. It should not be split or merged.
- The C++ block should be populated after acceptance because the previous blockers are now resolved or downgraded to non-blocking descriptive-name uncertainty.

## Supervisor Active Recheck
- Direct supervisor assignment in the current conversation names [UID:000232] `MapPaneObjectEffectDescriptorDispatch` and asks for B-agent source-quality/heuristic research only.
- Local `Agent-B008/goal.md` still records [UID:0000YZ] `BalloonObjectPane`, but `research/0000YZ-BalloonObjectPane-source-quality.md` already exists and is a finalized report. The visible active unreported assignment is therefore `000232`; the queued [UID:000234] implementation callback should wait until this report is complete.
- No direct split repair was required. The binary range is exact, followed by ignored padding `0x0050e4b6-0x0050e4c0`, and all source-bearing child/helper ranges called by this method already have separate docs.
- Report-only rule observed: no target/support by-* docs and no coverage report were edited for this phase.

## Inference Research Guidance Check
- `by-structure.md` permits first-draft C++ when `RECONSTRUCTABLE:TRUE`, there is a confirmed nonblank emitter route, and `(completion + confidence) / 2 > 85`. The recommended `88/91` state clears this gate.
- `inference_research.md` was applied by separating direct binary facts, documentation evidence, generated-source leads, and descriptive inference. Original source names are not claimed when only descriptive names are supported.
- Existing documentation was treated as a lead, not proof. The old file-owner route, "final source name unresolved" note, and C++ blocker language were rechecked against local PE/Capstone evidence and the current support docs.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / blocker effect |
| --- | --- | --- | --- |
| Source-facing method name | Target body, caller semantics, sibling coordinate dispatcher, generated `class_MapPane.cpp` and auto-generated `MapPane.cpp` markers. | `MapPane::ApplyObjectEffect` for first-draft C++; documentation can retain `MapPaneObjectEffectDescriptorDispatch`. | Reject `UpdateTileRange` and `TriggerEffect` generated leads because this method neither updates tiles nor broadly triggers arbitrary effects; it applies object-bound effect descriptors. No C++ blocker remains. |
| Signature and calling convention | `retn 0x10`, `thiscall` ECX use, four callers pushing object id/effect id/timer action/compact flag. | `void __thiscall MapPane::ApplyObjectEffect(int objectId, int effectId, int timerAction, bool compactEffect)`. | Reject file-local helper with explicit `MapPane*`: all direct callers load ECX as the MapPane object and the MapPane class/file docs already model siblings as class methods. |
| Direct owner/emitter | MapPane `this` at ECX, `m_objectList` at `+0x424`, class inventory already contains sibling exact helpers [UID:0003TE]/[UID:0003TF]/[UID:0003TG]. | `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`; source file route remains [UID:0000L3]. | Reject direct file owner `0000L3` as too broad for by-structure. Reject EffectObjectPane, ObjectList, TimerMgr, and EffectObjImageLib ownership because they are constructed object/provider/callee dependencies. |
| `EffectInfo` field names | `EffectInfo.md`, `EffectObjectPane` constructor `0x005387b0`, target pass guards, coordinate sibling `0x0050e850`, local-player caller `0x005a2e00`. | Keep/support source-quality names `effectId`, `primaryFrames`, `primaryFrameCount`, `primaryRangeStart`, `primaryRangeEnd`, `secondaryFrames`, `secondaryFrameCount`, `secondaryRangeStart`, `secondaryRangeEnd`. In this target, pass `0` uses secondary fields and pass `1` uses primary fields. | Original field names are not recoverable. Reject generated coordinate/position names for `+0x14/+0x18/+0x2c/+0x30`; the constructor and timer logic use them as valid range/loop bounds, not map coordinates. |
| Child-list field names | `AttachedObjectRegistryLayout.md`, `LivingObjectPane` support docs, disassembly of attachment helpers `0x0053adb0` and `0x0053ae10`. | Target object `+0x174` is `type4Attachments` for pass `0`/secondary sequence; `+0x170` is `type2Attachments` for pass `1`/primary sequence. | Reject generic "child collection A/B" wording now that registry layout support names the fields. Exact original "type2/type4" source names remain descriptive, but are sufficient. |
| MapPane object-list field | `MapPane.md` field glossary, target `this+0x424`, callee [UID:0002CD] `ObjectListFindByObjectId`. | `MapPane::m_objectList` at `+0x424`. | No remaining blocker. |
| Existing child reuse test | Target compares child `+0x148` to `EffectInfo +0x00`, then calls [UID:00023H] `EffectObjectPane::IsLooping()` reading byte `+0x14c`. | Use `EffectObjectPane::m_effectId` and `EffectObjectPane::m_looping`. | Reject stale `LivingObjectPaneGetEntityId` callee name; B003 corrected this and local raw evidence agrees. |
| Create helper `0x0050ea30` | Helper doc, local disassembly, xrefs from object and coordinate dispatchers, `retn 0x4c`. | `void MapPane::CreateEffectObjectPane(ObjectPane *owner, int mapX, int mapY, EffectInfo effectInfo, int timerAction, int attachmentPass, bool compactEffect)`. The `EffectInfo` argument is by value in binary shape. | Reject `EffectObjectPane` constructor ownership for this helper: it allocates, attaches, registers, starts, schedules, and refreshes as a MapPane-side orchestration helper. Reject `const EffectInfo&` in exact signature because callers push the 52-byte struct by value. |
| Reuse/timer helper `0x0050eb90` | Helper doc, local disassembly, direct callers, `retn 8`, ECX set to MapPane though body does not read ECX. | `void MapPane::ApplyEffectObjectPaneTimerAction(EffectObjectPane *effectPane, int timerAction)`. | Reject TimerMgr ownership: TimerMgr owns generic cancel/query/schedule callees, but this function chooses effect-pane action semantics. ECX-unused does not require file-local/no-owner because callers still use MapPane member ABI. |
| Timer/update argument semantics | Create helper, reuse helper, caller constants `-2`, `0`, positive values, TimerMgr queue helper docs. | Name parameter `timerAction`. Semantics: `-1` means close/remove in reuse and suppress create; `-2` means create without timer schedule or cancel event `2` on reuse; `0` is no-op on reuse but can create; positive values schedule or extend event `2` using `1000 * timerAction` when allowed. | Reject vague `updateArg` in final source text. Remaining uncertainty about TimerMgr tick units does not block target C++; the helper docs should phrase compare logic conservatively. |
| Compact flag semantics | Packet callers derive flag for effect IDs `0xa0..0xa2`; create helper forwards it to `EffectObjectPane` constructor, which stores byte `+0x14d`. | Source parameter `compactEffect`; `EffectObjectPane` field provisional `m_compactEffect`/`m_useCompactEffectLayout`. | Reject storage-compaction interpretation. Exact visual effect role is not proven but is not a target C++ blocker because the flag is passed through unchanged. |
| Object coordinate accessor | Target calls `0x005374d0`; support doc says `ObjectPane::GetMapPosition(MapPoint *out) const`, X/Y order still low-level. | First-draft C++ can use `MapPoint position; target->GetMapPosition(&position);`. | Do not introduce raw stack-field names. Exact original struct name may be `POINT`/`MapPoint`, but the helper role is resolved enough. |
| Caller/reachability | Rel32 scan, target docs, packet-handler docs, local-player simroot lead. | Four direct call sites and no absolute pointer/table route: `0x005116cc`, `0x00511d34`, `0x0053bac5`, `0x005a2ee0`. | Reject callback/vtable/table dispatch ownership. Consumer callers outside MapPane do not change the owner because they forward through `g_activeMapPane`. |
| Range/split/merge | Raw PE bytes, padding, ret, xref/callee boundaries, neighboring coverage. | Keep exact single target `0x0050e320-0x0050e4b6`; no split or merge. | Reject merging with `0x0050e4c0` packet aggregate or helper children; there are ten `0xcc` bytes after this function and helpers are already separate functions. |
| Compiler-generated content | Prologue/epilogue, no EH registration, no vtable stores, no scalar-delete pattern, no destructor/base calls. | Entire range is source-authored method body. | Reject scalar deleting destructor, EH support, and thunk interpretations. |
| Generated-output pollution | `auto-generated/NexusTK/map/MapPane.cpp` has empty markers for this family; `simroot_v2/class_MapPane.cpp` has decompiler-style leads. | Do not copy generated names; use source-style class method and helper names from evidence. | Generated source is a lead only and does not block C++ once names are resolved. |

## Evidence Standards Used
- Local PE and Capstone inspection of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` was used because the current IDA MCP endpoint at `http://127.0.0.1:13337/mcp` was unavailable (`Unable to connect to the remote server`).
- Existing IDA-backed by-* documentation was used for current named support items: `EffectInfo`, `EffectObjectPane`, `MapPane`, `ObjectList`, `AttachedObjectRegistryLayout`, `TimerMgrQueueHelpers`, and exact helper children [UID:0003TE]/[UID:0003TF]/[UID:0003TG].
- Direct binary evidence checked: function bytes, exact range/padding, return immediate, direct calls, direct callers, rel32 xrefs, absence of absolute VA pointer refs, helper ABIs, offsets, constants, and adjacent ranges.
- Generated and simroot output was treated as weak evidence for possible naming only; it did not override binary behavior.

## Local PE / Capstone Facts
- PE image base: `0x00400000`.
- `.text` range: `0x00401000-0x0060c4ac`; target lies inside `.text`.
- Target range: `0x0050e320-0x0050e4b6`, size `0x196` / 406 bytes (Verified with `int_convert.py`).
- Target prologue reserves `0x40` stack bytes; the copied `EffectInfo` occupies the 52-byte local region beginning at `ebp-0x40`.
- Target epilogue returns with `retn 0x10`, matching four explicit arguments after `this`.
- Boundary bytes: eight `0xcc` bytes before `0x0050e320`; ten `0xcc` bytes after `0x0050e4b6` before next function `0x0050e4c0`.
- Direct callees observed:
  - `0x004de3e0` `EffectObjImageLib::GetEffectInfo`.
  - `0x00532370` `ObjectList::FindByObjectId`.
  - `0x005374d0` `ObjectPane::GetMapPosition`.
  - `0x00538bb0` `EffectObjectPane::IsLooping`.
  - `0x0050ea30` `MapPane::CreateEffectObjectPane`.
  - `0x0050eb90` `MapPane::ApplyEffectObjectPaneTimerAction`.
- Rel32 callers to `0x0050e320`: `0x005116cc`, `0x00511d34`, `0x0053bac5`, `0x005a2ee0`.
- Absolute VA dword refs to `0x0050e320`, `0x0050ea30`, and `0x0050eb90`: none found in scanned PE sections.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050e320-0x0050e4b6` | [UID:000232](../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) | object-id effect dispatcher, recommended `MapPane::ApplyObjectEffect` | TRUE | recommend [UID:00007Q] | recommend `88/91` | ready for first-draft C++ |
| `0x0050e850-0x0050ea30` | [UID:0003TE](../../../../by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) | coordinate/no-target sibling dispatcher | TRUE | [UID:00007Q] | `86/strong` | support evidence; not edited in report phase |
| `0x0050ea30-0x0050eb8a` | [UID:0003TF](../../../../by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) | create/attach/register/schedule helper | TRUE | [UID:00007Q] | `86/strong` | signature should be expanded with by-value `EffectInfo` |
| `0x0050eb90-0x0050ec2e` | [UID:0003TG](../../../../by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) | reuse/timer-action helper | TRUE | [UID:00007Q] | `86/strong` | signature and timer-action semantics resolved here |
| `0x00538bb0-0x00538bb7` | [UID:00023H](../../../../by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) | `EffectObjectPane::IsLooping()` | TRUE | `EffectObjectPane` | support updated by B003 | confirms child reuse gate |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005116cc` | call from [UID:0003TM] `MapPaneHandleDrawObjectsPacket` | packet path passes object id, effect id, timer action, and compact flag when object-effect mode is enabled |
| `0x00511d34` | call from [UID:0003TO] `MapPaneHandleObjectMoveEffectPacket` | object-id branch of object move/effect packet; coordinate branch calls [UID:0003TE] |
| `0x0053bac5` | wrapper near `0x0053bab0` | forwards `g_activeMapPane`, target id, effect id `0x87` / 135, timer action `-2`, compact flag `0` |
| `0x005a2ee0` | local-player movement path | forwards `g_activeMapPane`, target id, effect id `0xc9` / 201, timer action `0`, compact flag `0` |
| `0x0050e33b` | call to `0x004de3e0` | copies `EffectInfo` for the requested effect id |
| `0x0050e349` | call to `0x00532370` | looks up target object from `MapPane::m_objectList` |
| `0x0050e397`, `0x0050e42d` | calls to `0x00538bb0` | validates reusable child as looping/active |
| `0x0050e3ed`, `0x0050e47e` | calls to `0x0050ea30` | creates missing pass-specific `EffectObjectPane` |
| `0x0050e494`, `0x0050e4a8` | calls to `0x0050eb90` | applies timer action to reused child |

## Behavioral Reconstruction
- The method copies an `EffectInfo` descriptor for `effectId`.
- It finds the target object with `m_objectList->FindByObjectId(objectId)`. If not found, it returns without side effects.
- Pass `0`:
  - Requires `effectInfo.secondaryFrameCount > 0`.
  - Reuse scan is allowed when `effectInfo.secondaryRangeStart >= 0` and `effectInfo.secondaryRangeEnd >= 0`.
  - Scans target `type4Attachments` at `+0x174` from last index down to first.
  - Reuses only candidates with matching `m_effectId` and `IsLooping() == true`.
  - On miss, gets target map position and calls `CreateEffectObjectPane(..., attachmentPass = 0, compactEffect)`.
- Pass `1`:
  - Requires `effectInfo.primaryFrameCount > 0`.
  - Reuse scan is allowed when `effectInfo.primaryRangeStart >= 0` and `effectInfo.primaryRangeEnd >= 0`.
  - Scans target `type2Attachments` at `+0x170`.
  - On miss, calls `CreateEffectObjectPane(..., attachmentPass = 1, compactEffect)`.
- Existing child reuse exits the current pass but does not skip the other pass. The binary can apply/reuse/create both pass `0` and pass `1` effects for one descriptor.

## Helper Signature Details
- `MapPane::CreateEffectObjectPane` at `0x0050ea30` has binary ABI `thiscall`, seven source arguments, and `retn 0x4c`. The 52-byte `EffectInfo` record is passed by value.
- Recommended source signature:
  ```cpp
  void MapPane::CreateEffectObjectPane(
      ObjectPane* owner,
      int mapX,
      int mapY,
      EffectInfo effectInfo,
      int timerAction,
      int attachmentPass,
      bool compactEffect);
  ```
- `MapPane::ApplyEffectObjectPaneTimerAction` at `0x0050eb90` has binary ABI `thiscall`, `retn 8`, and ECX set to the MapPane object by all callers even though the body does not read `this`.
- Recommended source signature:
  ```cpp
  void MapPane::ApplyEffectObjectPaneTimerAction(EffectObjectPane* effectPane, int timerAction);
  ```

## Documentation Evidence And Status
- Target doc currently already records exact range, four callers, descriptor copy, object-list lookup, two passes, create/reuse behavior, and padding. It still leaves source name, field names, child collections, helper names/signatures, and C++ readiness unresolved.
- [UID:00007Q][MapPane](../../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../../by-file/MapPane.md) already list the target and sibling helper children. They should be updated to say UID `000232` is a `MapPane` class method, not merely a file-owned helper.
- [UID:0001U8][EffectInfo](../../../../by-type/by-struct/EffectInfo.md) supports the 52-byte descriptor layout. This target strengthens the field names by proving primary/secondary count and range fields route to pass-specific effect children.
- [UID:000049][EffectObjectPane](../../../../by-class/EffectObjectPane.md) and [UID:00023H] prove `+0x148` as effect id and `+0x14c` as loop/reuse activity.
- [UID:0003TF] and [UID:0003TG] support docs should receive the exact signatures and timer-action wording above.
- `auto-generated/NexusTK/map/MapPane.cpp` currently has empty markers for this method family. This is generated-output pollution, not evidence that no C++ should be emitted.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane Class
- Evidence for: ECX is the MapPane object, the method reads `MapPane::m_objectList` at `+0x424`, all direct call sites pass a MapPane instance, sibling effect descriptor helpers are already class-owned, and source-output route through `MapPane.cpp` is valid.
- Evidence against: exact original method name is not recovered, and two callers live outside the main packet-handler source range. These are not ownership blockers because they forward through `g_activeMapPane`.
- Decision: accept. Use direct class owner/emitter UID `00007Q`.

### 2. [UID:0000L3] MapPane Source File
- Evidence for: physical source route is `MapPane.cpp`; target sits in the MapPane packet/effect address cluster; file inventory already lists the range.
- Evidence against: by-structure prefers the narrow semantic owner when a class method is evident; file ownership loses method-level class layout and source C++ placement.
- Decision: keep as source file route/support, but do not use as direct canonical owner/emitter.

### 3. EffectObjectPane / EffectObjImageLib / ObjectList / TimerMgr / LivingObjectPane
- Evidence for: the target constructs `EffectObjectPane`, reads descriptors from `EffectObjImageLib`, searches `ObjectList`, schedules timers, and scans `LivingObjectPane` attachment fields.
- Evidence against: each is a provider/callee/constructed-object/target object. None receives `this` for the target method, owns the dispatch decision, or explains the MapPane object-list lookup plus sibling coordinate dispatcher pairing.
- Decision: reject as direct owner. Keep all as cross-reference dependencies.

## Negative Evidence Summary
- No pointer-table or vtable data xrefs to the target were found in the local PE scan; the four rel32 callers are ordinary direct calls.
- No scalar deleting destructor, EH registration, constructor unwind, base destructor call, or thunk pattern appears in the target range.
- No split is justified: target ends with `retn 0x10`, then ten `0xcc` bytes precede the next function at `0x0050e4c0`.
- Generated names and decompiler-style names are not source-quality proof. They were checked and rejected where they failed to match behavior.
- Consumer xrefs from local-player and object-pane code do not transfer ownership away from MapPane because they use `g_activeMapPane` and forward into this MapPane method.

## First-Draft C++ Recommendation
The target is ready for first-draft C++ after acceptance. Use source-style C++ that looks like mid-2000s game code, not raw decompiler output. Field/list helper spellings are still descriptive, so the support docs should define them before or during implementation.

```cpp
void MapPane::ApplyObjectEffect(int objectId, int effectId, int timerAction, bool compactEffect)
{
    EffectInfo effectInfo;
    g_pEffectObjImageLib->GetEffectInfo(&effectInfo, effectId);

    LivingObjectPane* target = (LivingObjectPane*)m_objectList->FindByObjectId(objectId);
    if (target == NULL) {
        return;
    }

    if (effectInfo.secondaryFrameCount > 0) {
        EffectObjectPane* effectPane = NULL;

        if (effectInfo.secondaryRangeStart >= 0 && effectInfo.secondaryRangeEnd >= 0) {
            List* attachments = target->m_type4Attachments;
            for (int index = attachments->GetCount() - 1; index >= 0; --index) {
                EffectObjectPane* candidate = (EffectObjectPane*)attachments->GetAt(index);
                if (candidate->m_effectId == effectInfo.effectId && candidate->IsLooping()) {
                    effectPane = candidate;
                    break;
                }
            }
        }

        if (effectPane != NULL) {
            ApplyEffectObjectPaneTimerAction(effectPane, timerAction);
        } else {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(target, position.x, position.y, effectInfo, timerAction, 0, compactEffect);
        }
    }

    if (effectInfo.primaryFrameCount > 0) {
        EffectObjectPane* effectPane = NULL;

        if (effectInfo.primaryRangeStart >= 0 && effectInfo.primaryRangeEnd >= 0) {
            List* attachments = target->m_type2Attachments;
            for (int index = attachments->GetCount() - 1; index >= 0; --index) {
                EffectObjectPane* candidate = (EffectObjectPane*)attachments->GetAt(index);
                if (candidate->m_effectId == effectInfo.effectId && candidate->IsLooping()) {
                    effectPane = candidate;
                    break;
                }
            }
        }

        if (effectPane != NULL) {
            ApplyEffectObjectPaneTimerAction(effectPane, timerAction);
        } else {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(target, position.x, position.y, effectInfo, timerAction, 1, compactEffect);
        }
    }
}
```

Notes for implementation:
- If the project standard names the coordinate struct differently, use the existing `ObjectPane::GetMapPosition` output type.
- If the list accessor names are not final, use the established project names from `List`/attachment registry docs. The source logic should remain last-to-first scan with `GetCount()` and indexed access.
- Do not use modern C++ constructs, lambdas, `auto`, or range-for in this target.

## Recommended Exact Target Doc Changes
- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00007Q`
  - `EMITTER_UIDS:00007Q`
  - Keep `RECONSTRUCTABLE:TRUE`.
- Status:
  - Replace "MapPane helper function" with "private MapPane class method".
  - Replace "Likely source module: [UID:0000L3]" with direct owner [UID:00007Q] and source route [UID:0000L3].
  - Replace the blank-C++ blocker text with "first-draft C++ ready after B008 source-quality recheck."
- Behavior:
  - Name the method `MapPane::ApplyObjectEffect(int objectId, int effectId, int timerAction, bool compactEffect)`.
  - Name `MapPane +0x424` as `m_objectList`.
  - Name target child fields `type4Attachments` at `+0x174` and `type2Attachments` at `+0x170`.
  - Name `EffectObjectPane +0x148` as `m_effectId`, `+0x14c` as `m_looping`, and `+0x14e` as the provisional timer-action/schedule guard.
  - Record pass `0` uses `secondaryFrameCount/secondaryRangeStart/secondaryRangeEnd` and pass `1` uses `primaryFrameCount/primaryRangeStart/primaryRangeEnd`.
  - Record compact flag derivation from packet effect ids `0xa0..0xa2` and storage through `EffectObjectPane +0x14d`.
- Reconstruction notes:
  - Replace "Do not emit final C++" with the accepted first-draft body from this report if approved.
  - Preserve the uncertainty caveat that names are descriptive/source-quality, not original symbol proof.
- Changes:
  - Add a `2026-06-19 B008 source-quality recheck` entry summarizing range, owner/emitter correction, helper signatures, field semantics, caller set, rejected alternatives, and first-draft C++ readiness.

## Recommended Support Doc Changes
- [UID:00007Q][MapPane](../../../../by-class/MapPane.md): update the `000232` row/notes to `MapPane::ApplyObjectEffect`; direct class owner/emitter, source file route [UID:0000L3], and first-draft C++ ready. Add the four caller summary and helper dependency names.
- [UID:0000L3][MapPane](../../../../by-file/MapPane.md): keep the item in the file inventory but clarify it is not a file-owned free helper; it is a MapPane class method emitted through this source file.
- [UID:0001U8][EffectInfo](../../../../by-type/by-struct/EffectInfo.md): add target-specific evidence that `+0x10/+0x14/+0x18` are primary count/range fields and `+0x28/+0x2c/+0x30` are secondary count/range fields; pass `0` maps to secondary/type4, pass `1` maps to primary/type2.
- [UID:0003TF][MapPaneCreateEffectObjectPane](../../../../by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md): add the exact source-style signature with by-value `EffectInfo`, timer-action semantics, attachment pass `0`/`1` mapping, and compact flag pass-through.
- [UID:0003TG][MapPaneApplyEffectObjectPaneTimerAction](../../../../by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md): add the exact signature and conservative timer-action language for `-1`, `-2`, `0`, positive values, event id `2`, and byte `+0x14e`.
- [UID:0003TE][MapPaneCoordinateEffectDescriptorDispatch](../../../../by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md): cross-note the object-id sibling name `ApplyObjectEffect` and shared helper signatures.
- [UID:00023H][EffectObjectPaneIsLooping](../../../../by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md): no ownership change; optionally add that this target and coordinate sibling confirm `IsLooping` is the reuse-active test for matching `m_effectId`.
- [UID:0003TM] and [UID:0003TO] packet-handler docs: replace vague `update argument` wording with `timerAction` when referring to calls to UID `000232`, while preserving packet-field uncertainty if broader packet docs still need it.

## Score / Metadata Recommendation
- Target before: `84/88`, owner/emitter `0000L3`.
- Target after: `88/91`, owner/emitter `00007Q`.
- Score rationale: behavior, range, caller set, helper roles, field semantics, pass semantics, source route, and first-draft C++ are now resolved. Confidence remains below `95` because original symbol/field spelling and compact visual meaning cannot be proven without source symbols.
- Parent/support score changes: no mandatory score change is required for [UID:00007Q] or [UID:0000L3], but both should receive source-quality notes.

## Exact Pending Coverage Text
Do not edit `by-memory/-coverage-report.md` during B-agent report phase. Replace the existing UID `000232` row with:

```markdown
    - [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) 0x0050e320-0x0050e4b6 | class method | MapPane::ApplyObjectEffect : reconstructable : 88% : very strong : B008 source-quality recheck resolves this as a private MapPane object-effect method, recommended owner/emitter [UID:00007Q]; local PE/Capstone confirms exact `0x196` / 406-byte standalone range (Verified with int_convert.py), ten-byte trailing padding, four direct callers, no pointer/table route, `EffectObjImageLib::GetEffectInfo`, `m_objectList->FindByObjectId`, type-4/type-2 attachment scans at target `+0x174`/`+0x170`, `EffectObjectPane::m_effectId`/`IsLooping()` reuse, create helper `0x0050ea30`, timer-action helper `0x0050eb90`, compact effect-id flag `0xa0..0xa2`, and no scalar-delete/EH/base-destructor content.
```

## Validator Needs After Acceptance
Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited file:

> Executable block R001 was removed from this report and preserved verbatim in [000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md](000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If packet-handler wording is edited, also validate the corresponding packet-handler docs. Coverage row application remains supervisor-owned unless the edit ban is lifted.

## IDA Rename / Type / Comment Recommendations
- Rename `sub_50E320` / `FUN_0050e320` to `MapPane_ApplyObjectEffect`; apply prototype `void __thiscall MapPane_ApplyObjectEffect(MapPane *this, int objectId, int effectId, int timerAction, bool compactEffect);`.
- Rename `sub_50EA30` to `MapPane_CreateEffectObjectPane`; prototype with by-value `EffectInfo` and arguments `(ObjectPane *owner, int mapX, int mapY, EffectInfo effectInfo, int timerAction, int attachmentPass, bool compactEffect)`.
- Rename `sub_50EB90` to `MapPane_ApplyEffectObjectPaneTimerAction`; prototype `(EffectObjectPane *effectPane, int timerAction)`.
- Rename/comment attachment helpers `0x0053adb0` and `0x0053ae10` as `LivingObjectPane_AddType2EffectObject` and `LivingObjectPane_AddType4EffectObject` or equivalent descriptive names with medium confidence.
- Type/comment fields:
  - `MapPane +0x424`: `m_objectList`.
  - `EffectInfo +0x00`: `effectId`.
  - `EffectInfo +0x10/+0x14/+0x18`: `primaryFrameCount`, `primaryRangeStart`, `primaryRangeEnd`.
  - `EffectInfo +0x28/+0x2c/+0x30`: `secondaryFrameCount`, `secondaryRangeStart`, `secondaryRangeEnd`.
  - target object `+0x170`: `type2Attachments`.
  - target object `+0x174`: `type4Attachments`.
  - `EffectObjectPane +0x148`: `m_effectId`.
  - `EffectObjectPane +0x14c`: `m_looping`.
  - `EffectObjectPane +0x14d`: provisional `m_compactEffect`.
  - `EffectObjectPane +0x14e`: provisional timer schedule/action guard.

## Open Questions With Attempted Resolution
- Exact original method name: not recoverable from current symbols/generator output. Checked callers, generated names, sibling helper docs, and local binary shape. Best descriptive name `ApplyObjectEffect`; uncertainty affects confidence only, not owner/source route or C++ eligibility.
- Exact compact flag field name: not recoverable. Checked two packet callers, effect-id range `0xa0..0xa2`, create helper forwarding, and constructor store at `+0x14d`. Best name `compactEffect`; no target C++ blocker.
- Exact `EffectInfo` original primary/secondary labels: not recoverable. Checked loader/constructor/target/coordinate/local-player evidence. Current primary/secondary field names are coherent and should be retained as descriptive source-quality names.
- Timer due-time unit in positive reuse helper: local disassembly compares the requested positive value with the current remaining due units before scheduling `1000 * timerAction`. The exact units returned by `TimerMgr` helper `0x00597dc0` remain a TimerMgr support-doc issue, not a blocker for this method because UID `000232` only forwards `timerAction`.
- Attachment list concrete type/API names: exact original list accessor names are not recovered here. Existing list/class docs should provide the local `GetCount`/indexed-access names used in final C++; this uncertainty does not block source logic.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`.
- Modified: none outside the created B008 research report.
- Coverage: not edited; exact replacement row is included above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"000232"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000232-MapPaneObjectEffectDescriptorDispatch-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000232"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
