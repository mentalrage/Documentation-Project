** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch 3

## Finalized Report / Current Recommendation

- Current recommendation: create the next bounded executable MapPane child-split batch for [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md): [UID:0003TE] `0x0050e850-0x0050ea30`, [UID:0003TF] `0x0050ea30-0x0050eb8a`, and [UID:0003TG] `0x0050eb90-0x0050ec2e`.
- Final disposition: [UID:0001AW] remains `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, and blank final C++ after this batch because later source-bearing leaves remain unsplit.
- Required action: supervisor should create the three child pages, add two ignored padding entries, add the exact parent/support/coverage rows below, validate, then rerun `memory_ranges.py report`.
- Confidence: strong for the three executable child ranges, MapPane source ownership, direct callee/caller evidence, and padding boundaries; medium-high for final source-facing names, which should stay provisional and keep C++ blank.

## Target

- Target UID: [UID:0001AW]
- Target path: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- Current state checked: `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, final C++ blank.
- Current direct owner: [UID:00007Q][MapPane](../../../../../by-class/MapPane.md); source file owner [UID:0000L3][MapPane](../../../../../by-file/MapPane.md).
- Prior executed children: [UID:0003TB] `0x0050e4c0-0x0050e68d`, [UID:0003TC] `0x0050e690-0x0050e805`, and [UID:0003TD] `0x0050e810-0x0050e848`.
- Generated report state: `auto-generated/by-memory-tool-report.md` is clean for Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan, but still lists [UID:0001AW] largest reconstructable leaves `0x005104c7-0x00513800` and `0x0050e848-0x00510400`.

## Executive Recommendation

The next executable batch should split the first coherent effect-object descriptor cluster after [UID:0003TD]:

| Proposed UID | Range | File | Role | Score | Owner / Emitter | Create now |
| --- | --- | --- | --- | --- | --- | --- |
| `0003TE` | `0x0050e850-0x0050ea30` | `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md` | MapPane coordinate/no-target effect descriptor dispatcher | `86/89` | [UID:00007Q] | Yes |
| `0003TF` | `0x0050ea30-0x0050eb8a` | `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md` | MapPane private helper that allocates/constructs/registers an `EffectObjectPane` from descriptor data | `86/90` | [UID:00007Q] | Yes |
| `0003TG` | `0x0050eb90-0x0050ec2e` | `by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md` | MapPane private helper that applies reuse/timer actions to an existing `EffectObjectPane` | `86/90` | [UID:00007Q] | Yes |

These children are source-authored MapPane helper functions even though they use `EffectObjImageLib`, allocate `EffectObjectPane`, and call timer-manager helpers. The provider/constructed-object/timer owners remain separate support owners; the source routing of these three bodies is MapPane because the bodies are helper logic for MapPane packet/effect handling.

Do not reclassify [UID:0001AW] as a non-emitting split index yet. The following parent leaves remain source-bearing or unresolved after this batch: `0x0050ec30-0x00510400`, raw [UID:0001AX] `0x00510400-0x005104c7`, the broad `0x005104c7-0x00513800`, [UID:0001AY], raw [UID:0001AZ], and [UID:0001B0]. The parent remains a reconstructable aggregate until enough exact children carry the remaining source.

## Supervisor Active Recheck

- Current assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation3-0001AW-20260616`.
- Hard restriction honored: this report recommends exact by-* and coverage changes but does not directly edit by-* documentation, generated reports, IDA DB, or `by-memory/-coverage-report.md`.
- UID allocation assumption: current `tools/validator.ini` state was read as `last_used_uid = 0003TD`. If no other UID is allocated first, use `0003TE`, `0003TF`, and `0003TG`. If that assumption changes before supervisor execution, allocate the next three UIDs and mechanically replace every `0003TE`/`0003TF`/`0003TG` reference in this batch.

## Evidence Standards Used

- IDA MCP live session evidence from `b001_mappane_0001AW_20260616`: function lookup, function analysis, direct callers/xrefs, decompilation observations, and byte signatures for padding.
- Documentation evidence: parent [UID:0001AW], sibling [UID:000232], [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`, [UID:000049] `EffectObjectPane`, [UID:0001DA] `EffectObjectPaneStartIdleTimer`, [UID:0002HA] `EffectObjImageLibGetEffectInfo`, `EffectInfo`, and timer-manager support docs.
- Generated-report evidence: `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, and `auto-generated/by-memory-tool-report.md`.
- No Wave2/Wave3 source output was used for source reconstruction; existing project documentation was used only as evidence to be checked against IDA facts.

## IDA MCP Facts

### Function / Range Facts

`lookup_funcs` over `0x0050e840-0x0050f040` reports:

| Start | IDA name | Size | End-exclusive | Batch decision |
| --- | --- | ---: | --- | --- |
| `0x0050e850` | `sub_50E850` | `0x1e0` | `0x0050ea30` | Create [UID:0003TE] |
| `0x0050ea30` | `sub_50EA30` | `0x15a` | `0x0050eb8a` | Create [UID:0003TF] |
| `0x0050eb90` | `sub_50EB90` | `0x9e` | `0x0050ec2e` | Create [UID:0003TG] |
| `0x0050ec30` | `sub_50EC30` | `0x1a0` | `0x0050edd0` | Roadmap only for a later batch |
| `0x0050edd0` | `sub_50EDD0` | `0x125` | `0x0050eef5` | Roadmap only for a later batch |
| `0x0050ef00` | `sub_50EF00` | `0x129` | `0x0050f029` | Roadmap only for a later batch |
| `0x0050f030` | `sub_50F030` | `0x100` | `0x0050f130` | Roadmap only for a later batch |

### Padding Facts

- `make_signature_for_range 0x0050eb8a-0x0050eb90` returned six `0xcc` bytes after `sub_50EA30` and before `sub_50EB90`.
- `make_signature_for_range 0x0050ec2e-0x0050ec30` returned two `0xcc` bytes after `sub_50EB90` and before `sub_50EC30`.
- Existing prior batch padding `0x0050e848-0x0050e850` already proves the [UID:0003TE] start is cleanly separated from [UID:0003TD].

### Xref / Caller Facts

| Item | IDA facts | Meaning |
| --- | --- | --- |
| `sub_50E850` | One direct caller at `0x00511d51` inside `sub_511C90`; direct callees include `sub_505290`, `sub_50EB90`, `sub_4B7E80`, `sub_5374D0`, `sub_50EA30`, `sub_532550`, `sub_5325B0`, `sub_4DE3E0`, and `sub_538BB0`. | Live coordinate/no-target effect descriptor route from a MapPane packet helper. |
| `sub_50EA30` | Direct callers at `0x0050e3ed`, `0x0050e47e`, `0x0050e945`, and `0x0050e9e3`, from sibling object-descriptor and coordinate-descriptor dispatchers. Direct callees include `PoolAllocator_Allocate`, `sub_5387B0`, `sub_5388A0`, `sub_5314A0`, `sub_53AE10`, `sub_53ADB0`, and `sub_597910`. | Shared MapPane create/apply helper for effect object children. |
| `sub_50EB90` | Direct callers at `0x0050e494`, `0x0050e4a8`, `0x0050ea04`, and `0x0050ea18`, from sibling object-descriptor and coordinate-descriptor dispatchers. Direct callees include `sub_597DC0`, `sub_597B80`, and `sub_597910`. | Shared MapPane reuse/timer-action helper for existing effect object children. |

### Decompilation / Behavior Facts

- `sub_511C90` reads packet fields through `sub_5754C0` and `sub_575480`. When the target object id is zero it calls `sub_50E850` at `0x00511d51`; when an object id exists and lookup succeeds it calls sibling [UID:000232] `sub_50E320`. This proves `sub_50E850` is the coordinate/no-target counterpart to the existing object-id effect descriptor dispatcher.
- `sub_50E850` copies a 52-byte `EffectInfo` descriptor through `sub_4DE3E0` / [UID:0002HA], checks coordinate feasibility, scans existing child collections through `sub_5325B0` / `sub_532550`, compares effect descriptor ids, gates existing objects through `sub_538BB0`, reuses matching children through `sub_50EB90`, and creates missing children through `sub_50EA30`.
- `sub_50EA30` allocates from [UID:0002WO] `EffectObjectPanePoolStaticStorage`, constructs `EffectObjectPane` via `sub_5387B0`, attaches it to pass-specific target collections through `sub_53AE10` / `sub_53ADB0`, inserts it through MapPane object/list logic via `sub_5314A0`, starts idle timer [UID:0001DA] through `sub_5388A0`, optionally queues event id `2` through `sub_597910`, then refreshes bounds/virtual state.
- `sub_50EB90` is a null-guarded existing-effect action helper: `-1` invokes the first virtual slot with argument `1`, `-2` cancels timer event id `2`, and positive values compare/extend the queued due tick before canceling and rescheduling timer event id `2` when the effect object flag permits it.

## Documentation Evidence And IDA Status

- [UID:000232][MapPaneObjectEffectDescriptorDispatch](../../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) already documents `0x0050ea30` as the create/apply helper and `0x0050eb90` as the reuse/timer helper. The batch3 IDA evidence confirms these are shared helpers used by both object-id and coordinate/no-target effect descriptor routes.
- [UID:0002HA][EffectObjImageLibGetEffectInfo](../../../../../by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) records caller `0x0050e89d` inside `0x0050e850`, proving descriptor-provider linkage for the new [UID:0003TE] child.
- [UID:000049][EffectObjectPane](../../../../../by-class/EffectObjectPane.md) records that `xrefs_to 0x005387b0` and `xrefs_to 0x005388a0` land in `sub_50EA30`, proving [UID:0003TF] constructs and starts a separate `EffectObjectPane` object but does not own the `EffectObjectPane` class source.
- [UID:0001DA][EffectObjectPaneStartIdleTimer](../../../../../by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) records the sole caller at `0x0050eb14` inside `sub_50EA30`, matching [UID:0003TF].
- Timer-manager support docs record `sub_597DC0`, `sub_597B80`, and `sub_597910` as generic timer queue helpers. Their use in [UID:0003TG] is a callee dependency, not ownership evidence for TimerMgr.
- [UID:0001AW], [UID:00007Q], and [UID:0000L3] already route the packet/effect helper family through MapPane and list `0x0050ea30` as an unresolved helper. This batch resolves the next three concrete functions without changing parent ownership.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for: all three functions sit inside [UID:0001AW], are reached from MapPane packet/effect flows, share helper calls with existing MapPane sibling [UID:000232], read/modify MapPane object-list state, and are adjacent to the prior MapPane packet helper children [UID:0003TB]-[UID:0003TD].
- Evidence against: the create helper constructs `EffectObjectPane`, uses `EffectObjImageLib`, and schedules TimerMgr events.
- Decision: accept. Those are dependencies and constructed targets, not source owners for the MapPane helper bodies.

### 2. [UID:000049] EffectObjectPane

- Evidence for: [UID:0003TF] allocates/constructs `EffectObjectPane`, calls its timer-start helper, and [UID:0003TG] operates on existing `EffectObjectPane` timer state.
- Evidence against: callers are MapPane effect descriptor dispatchers; the bodies choose/create/reuse effect panes from MapPane packet data and MapPane object/list context. `EffectObjectPane` owns its constructor, timer helper, pool, vtable, and class methods, not MapPane's decision/routing helpers.
- Decision: reject as direct owner. Keep as support/callee/constructed class.

### 3. [UID:00004A] EffectObjImageLib / [UID:0000IY] EffectObjImageLib file

- Evidence for: [UID:0003TE] and sibling [UID:000232] call `GetEffectInfo` and consume the descriptor table.
- Evidence against: `EffectObjImageLib` only provides descriptor records; it does not own packet dispatch, object lookup, or effect object creation/routing.
- Decision: reject as direct owner. Keep as descriptor-provider support.

### 4. TimerMgr / timer helpers

- Evidence for: [UID:0003TF] queues event id `2`; [UID:0003TG] cancels/finds/reschedules event id `2`.
- Evidence against: timer functions are generic callees. The source decision about which `EffectObjectPane` timer action to apply belongs to the MapPane effect descriptor route.
- Decision: reject as direct owner. Keep as support/callee.

## Blockers Investigated

### Final Source Names

- Evidence checked: IDA callee names, current [UID:000232] wording, [UID:0002HA] `EffectInfo` descriptor docs, [UID:000049] `EffectObjectPane` docs, and MapPane parent/source docs.
- Resolution: function roles are clear enough to create source-quality child pages with provisional names.
- Remaining blocker: original source-facing names for the effect descriptor type, child collection fields, timer/update argument, and helper names are not recoverable safely from current docs/IDA alone. Final C++ should remain blank for all three children.

### Reachability / Liveness

- Evidence checked: direct caller/xref sets for `0x0050e850`, `0x0050ea30`, and `0x0050eb90`; caller decompilation at `sub_511C90`; sibling [UID:000232] caller/callee evidence.
- Resolution: all three selected functions have direct modeled code callers. They are not raw unreferenced islands and should be reconstructable source-bearing children.

### Range And Padding

- Evidence checked: `lookup_funcs` sizes, `lookup_func` negative checks around non-starts, and byte signatures for `0x0050eb8a-0x0050eb90` and `0x0050ec2e-0x0050ec30`.
- Resolution: the three half-open child ranges and two ignored padding ranges are exact enough for supervisor execution.

### Source Owner

- Evidence checked: MapPane class/file docs, sibling MapPane effect descriptor docs, `EffectObjectPane` support docs, `EffectObjImageLib` support docs, and timer helper docs.
- Resolution: MapPane is the best direct owner/emitter for all three children. EffectObjectPane, EffectObjImageLib, and TimerMgr remain support owners only.

### Parent Reclassification

- Evidence checked: generated largest-leaf report and current [UID:0001AW] child inventory.
- Resolution: do not reclassify [UID:0001AW] yet. This batch reduces the `0x0050e848-0x00510400` leaf but leaves `0x0050ec30-0x00510400` plus the later broad leaf and raw duplicate bodies.

### IDA DB Edit Safety

- Evidence checked: IDA function objects already exist at `0x0050e850`, `0x0050ea30`, and `0x0050eb90`; current names are still decompiler/generated names; source-facing names are provisional.
- Resolution: no IDA DB edit is recommended. Renaming in IDA now would overstate final source names. No function creation is required.

## Executable Supervisor Batch

### Create Child Page [UID:0003TE]

Path: `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`

```markdown
*** UID:0003TE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY CODE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050e850-0x0050ea30 MapPane Coordinate Effect Descriptor Dispatch

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private packet/effect helper child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneCoordinateEffectDescriptorDispatch`. A likely source-facing role is a private coordinate/no-target counterpart to [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md).
- Confidence: strong for boundary, caller, MapPane ownership, descriptor-provider call, existing-child scan, and create/reuse helper calls; medium-high for final source-facing helper and field names.
- Reconstruction note: C++ intentionally blank. `EffectInfo` field names, packet argument names, child collection names, and helper names are still provisional.

## Address Range

- Start: `0x0050e850`
- End: `0x0050ea30` end-exclusive
- IDA function: `sub_50E850`
- IDA size: `0x1e0` bytes
- Preceded by ignored padding `0x0050e848-0x0050e850` after [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md).
- Followed immediately by [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md).

## Behavior

This helper handles the coordinate/no-target effect descriptor path for MapPane packet processing. Its direct caller reads packet fields and uses this path when no target object id is present. The helper:

- obtains current MapPane view/coordinate state through the `0x00505290` helper;
- validates packet coordinates through `0x004b7e80`;
- copies a 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor through [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md);
- runs two descriptor-controlled passes over existing effect-object child collections obtained through `0x00532550` / `0x005325b0`;
- compares existing child descriptor ids against the copied descriptor and applies an active/gate helper at `0x00538bb0`;
- reuses a matching child through [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md);
- creates/applies a missing child through [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md).

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50E850` at `0x0050e850`, size `0x1e0`, 26 basic blocks, cyclomatic complexity 17.
- `analyze_function` reports direct callees: `sub_505290`, `sub_50EB90`, `sub_4B7E80`, `sub_5374D0`, `sub_50EA30`, `sub_532550`, `sub_5325B0`, `sub_4DE3E0`, `sub_538BB0`, and `@__security_check_cookie@4`.
- `xrefs_to` / caller review reports direct call site `0x00511d51` inside `sub_511C90`.
- Decompilation of the caller shows packet-field reads through `sub_5754C0` and `sub_575480`; when object id is absent the caller invokes this helper, and when object id exists and lookup succeeds it invokes sibling [UID:000232].
- [UID:0002HA][EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) records caller `0x0050e89d` inside this function, confirming the descriptor-provider route.

## Ownership Decision

This is MapPane source. The function is reached from MapPane packet handling, uses MapPane coordinate/object-list context, and delegates descriptor storage, effect-object construction, and timer mechanics to separate support owners. Do not attach it to `EffectObjectPane`, `EffectObjImageLib`, or TimerMgr.

## Rejected Owners

- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md): constructed/reused object class, not owner of this MapPane descriptor-dispatch body.
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md): descriptor provider only.
- TimerMgr support: generic callee utilities only.

## Score Rationale

Completion is `86` because the page records exact range, direct caller, decompiled role, descriptor provider, create/reuse callees, ownership, rejected alternatives, and final-C++ blockers. Confidence is `89` because the range and behavior are strongly IDA-backed, while final source-facing names and field names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch3 recommendation: create this exact child from the remaining [UID:0001AW] broad leaf. Parent remains reconstructable because later source-bearing leaves remain unsplit.
```

### Create Child Page [UID:0003TF]

Path: `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`

```markdown
*** UID:0003TF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY CODE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050ea30-0x0050eb8a MapPane Create EffectObjectPane

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private packet/effect helper child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneCreateEffectObjectPane`.
- Confidence: strong for exact range, callers, `EffectObjectPane` allocation/construction path, insertion/attachment behavior, timer scheduling, and MapPane ownership; medium-high for final parameter and field names.
- Reconstruction note: C++ intentionally blank. The source-facing `EffectInfo` field names, child collection names, map/object-list helpers, and timer argument names need a final naming pass.

## Address Range

- Start: `0x0050ea30`
- End: `0x0050eb8a` end-exclusive
- IDA function: `sub_50EA30`
- IDA size: `0x15a` bytes
- Preceded by [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md).
- Followed by ignored padding `0x0050eb8a-0x0050eb90` before [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md).

## Behavior

This helper creates and registers an `EffectObjectPane` for MapPane effect descriptor routes. It is called by both the object-id dispatcher [UID:000232] and the coordinate/no-target dispatcher [UID:0003TE]. The helper:

- exits without creating a pane when the timer/update argument is `-1`;
- selects descriptor coordinate/duration fields based on the effect pass;
- converts positive duration values to milliseconds;
- allocates from [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md);
- constructs [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) through `0x005387b0`;
- attaches the new pane to the pass-specific target-object child collection when a target object is present;
- inserts/registers the object through MapPane object/list state via `0x005314a0`;
- starts the `EffectObjectPane` idle timer through [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md);
- optionally schedules timer event id `2` on the embedded timer subobject at `+0xa4`;
- refreshes bounds/virtual state after registration.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50EA30` at `0x0050ea30`, size `0x15a`, 22 basic blocks, cyclomatic complexity 9.
- `xrefs_to` reports direct call sites at `0x0050e3ed`, `0x0050e47e`, `0x0050e945`, and `0x0050e9e3`, from [UID:000232] and [UID:0003TE].
- `analyze_function` reports direct callees including `PoolAllocator_Allocate`, `sub_5387B0`, `sub_5388A0`, `sub_5314A0`, `sub_53AE10`, `sub_53ADB0`, and `sub_597910`.
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) records that `xrefs_to 0x005387b0` and `xrefs_to 0x005388a0` both land in this function.
- [UID:0001DA][EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) records the sole direct caller at `0x0050eb14` inside this function.
- B001 byte-signature review confirms the following `0x0050eb8a-0x0050eb90` bytes are six `0xcc` padding bytes, not part of this child.

## Ownership Decision

This body belongs to MapPane because it is the MapPane effect descriptor helper that decides when and how to create a map effect object from packet/descriptor context. `EffectObjectPane` owns the constructed object's constructor, timer helper, vtable, and pool storage; it does not own the MapPane packet-side creation decision.

## Rejected Owners

- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md): owns the constructed class and timer helper, not the MapPane descriptor routing helper.
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md): descriptor provider only.
- TimerMgr support: generic queue callee only.

## Score Rationale

Completion is `86` because exact range, callers, allocation/construction path, object/list insertion, timer scheduling, owner decision, rejected owners, and padding are documented. Confidence is `90` because callers/callees and support docs strongly triangulate the behavior; confidence stays below final-source quality because parameter and field names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)
- [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch3 recommendation: create this exact child from the remaining [UID:0001AW] broad leaf. Parent remains reconstructable because later source-bearing leaves remain unsplit.
```

### Create Child Page [UID:0003TG]

Path: `by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md`

```markdown
*** UID:0003TG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY CODE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050eb90-0x0050ec2e MapPane Apply EffectObjectPane Timer Action

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private packet/effect helper child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneApplyEffectObjectPaneTimerAction`.
- Confidence: strong for exact range, callers, timer event behavior, ownership, and padding; medium-high for final action/field names.
- Reconstruction note: C++ intentionally blank. The final source names for the action argument, effect-pane flag at `+0x14e`, timer subobject at `+0xa4`, and timer event id `2` require final naming.

## Address Range

- Start: `0x0050eb90`
- End: `0x0050ec2e` end-exclusive
- IDA function: `sub_50EB90`
- IDA size: `0x9e` bytes
- Preceded by ignored padding `0x0050eb8a-0x0050eb90` after [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md).
- Followed by ignored padding `0x0050ec2e-0x0050ec30` before the later roadmap-only function at `0x0050ec30`.

## Behavior

This helper applies an update/timer action to an existing reusable `EffectObjectPane` found by the MapPane effect descriptor dispatchers:

- null effect pointer: return without side effects;
- action `-1`: invoke the effect object's first virtual slot with argument `1`;
- action `-2`: cancel queued timer event id `2` for the embedded timer subobject at `EffectObjectPane + 0xa4`;
- positive action: when the flag byte at `EffectObjectPane + 0x14e` does not block updates, query the currently queued due tick, compare it against current tick state, and extend/reschedule event id `2` by `1000 * action` only when the requested delay exceeds the current remaining due time.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50EB90` at `0x0050eb90`, size `0x9e`, 14 basic blocks, cyclomatic complexity 6.
- `xrefs_to` reports direct call sites at `0x0050e494`, `0x0050e4a8`, `0x0050ea04`, and `0x0050ea18`, from [UID:000232] and [UID:0003TE].
- `analyze_function` reports direct callees `sub_597DC0`, `sub_597B80`, and `sub_597910`.
- Timer-manager support docs record the event-cancel, due-tick lookup, and scheduling callees as generic timer helpers. They are dependencies rather than direct owners of this body.
- B001 byte-signature review confirms `0x0050eb8a-0x0050eb90` as six `0xcc` bytes and `0x0050ec2e-0x0050ec30` as two `0xcc` bytes.

## Ownership Decision

This body belongs to MapPane because it is the reuse/timer-action helper selected by MapPane effect descriptor dispatchers for existing effect-object children. TimerMgr owns the generic queue operations; `EffectObjectPane` owns the object layout and timer subobject; MapPane owns this source decision.

## Rejected Owners

- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md): target object class, not the MapPane dispatch helper.
- TimerMgr support pages: generic timer queue utilities only.
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md): no direct descriptor lookup happens in this helper.

## Score Rationale

Completion is `86` because exact range, direct callers, timer behavior, ownership, rejected owners, and padding are documented. Confidence is `90` because the function is short, directly called by two known MapPane descriptor routes, and has only timer-manager dependencies; final source confidence is limited by unresolved field/action names.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch3 recommendation: create this exact child from the remaining [UID:0001AW] broad leaf. Parent remains reconstructable because later source-bearing leaves remain unsplit.
```

## Exact Parent Edits For Supervisor

### [UID:0001AW] Header Metadata

No metadata change:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:00007Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007Q
final C++ blank
```

### [UID:0001AW] Exact Child Pages And Nesting

In `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, insert these rows after the existing [UID:0003TD] row and before [UID:0001AX]:

```markdown
| [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) | Exact modeled MapPane coordinate/no-target effect descriptor dispatcher; copies an `EffectInfo` record, scans existing effect-object collections, and routes to the create/reuse helpers. |
| [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) | Exact modeled MapPane private create/apply helper that allocates, constructs, attaches, registers, starts, and optionally schedules an `EffectObjectPane`. |
| [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) | Exact modeled MapPane private reuse/timer helper that applies `-1`, `-2`, or positive timer actions to an existing `EffectObjectPane`. |
```

### [UID:0001AW] Current Exact Boundary Inventory

In the boundary table, insert the `0x0050e850` row after the current `0x0050e810` row; replace the current `0x0050ea30` row; and insert the `0x0050eb90` row after it:

```markdown
| `0x0050e850` | `sub_50E850` | `0x1e0` | Exact child [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md); MapPane coordinate/no-target effect descriptor dispatcher called from `sub_511C90`, paired with the object-id effect dispatcher [UID:000232]. |
| `0x0050ea30` | `sub_50EA30` | `0x15a` | Exact child [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md); shared MapPane create/apply helper that allocates, constructs, inserts, starts, and optionally schedules an `EffectObjectPane`. |
| `0x0050eb90` | `sub_50EB90` | `0x9e` | Exact child [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md); shared MapPane reuse/timer helper for existing effect-object children. |
```

### [UID:0001AW] Evidence

Add this bullet after the existing 2026-06-16 B001 continuation live IDA MCP evidence bullet:

```markdown
- 2026-06-16 B001 continuation batch3 live IDA MCP session `b001_mappane_0001AW_20260616`: `lookup_funcs` reports `sub_50E850` size `0x1e0`, `sub_50EA30` size `0x15a`, and `sub_50EB90` size `0x9e`. `analyze_function(0x0050e850)` reports caller `0x00511d51` inside `sub_511C90` and callees including `EffectObjImageLibGetEffectInfo`, `0x0050ea30`, and `0x0050eb90`; caller decompilation shows the no-object-id effect descriptor route. `analyze_function(0x0050ea30)` reports calls to the `EffectObjectPane` pool, constructor, idle timer, object/list insertion, child-collection attachment, and timer scheduling. `analyze_function(0x0050eb90)` reports timer event `2` cancel/due/schedule callees and direct callers from both effect descriptor dispatchers. `make_signature_for_range` confirms `0x0050eb8a-0x0050eb90` as six `0xcc` bytes and `0x0050ec2e-0x0050ec30` as two `0xcc` bytes.
```

### [UID:0001AW] Cross-References

Insert after [UID:0003TD]:

```markdown
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
```

### [UID:0001AW] Changes

Add a new top change entry:

```markdown
- 2026-06-16 B001 continuation split batch3: create exact children [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md), [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md), and [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md), plus ignored alignment ranges `0x0050eb8a-0x0050eb90` and `0x0050ec2e-0x0050ec30`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because the remaining broad leaves still need exact children.
```

## Exact Support Doc Edits For Supervisor

### [UID:00007Q] `by-class/MapPane.md`

No metadata change. Add these links to the cross-reference list after [UID:0003TD]:

```markdown
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
```

Add this top change entry:

```markdown
- 2026-06-16 B001 continuation split batch3:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/effect children [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md), [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md), and [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md). The children document the MapPane-owned coordinate effect descriptor route, effect-object create/apply helper, and existing-effect timer action helper while keeping `EffectObjectPane`, `EffectObjImageLib`, and TimerMgr ownership separate.
```

### [UID:0000L3] `by-file/MapPane.md`

No metadata change. Add the same three links to the memory/item cross-reference list after [UID:0003TD]:

```markdown
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
```

Add this top change entry:

```markdown
- 2026-06-16 B001 continuation split batch3:
  - Score unchanged at `89/85`.
  - Added exact children [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md), [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md), and [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) under the MapPane packet/effect family. `EffectObjectPane`, `EffectObjImageLib`, and TimerMgr remain callee/provider/constructed-object source owners rather than owners of these MapPane methods.
```

### EffectObjectPane / EffectObjImageLib / Timer Support Docs

No direct support-doc score or metadata changes are required. Existing support docs already record the relevant caller/provider facts:

- [UID:000049][EffectObjectPane](../../../../../by-class/EffectObjectPane.md) records `sub_50EA30` xrefs to constructor and idle timer.
- [UID:0001DA][EffectObjectPaneStartIdleTimer](../../../../../by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) records sole caller `sub_50EA30`.
- [UID:0002HA][EffectObjImageLibGetEffectInfo](../../../../../by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) records caller `0x0050e89d` inside `0x0050e850`.

## Exact Ignored Ledger Edits For Supervisor

In `by-memory/-ignored.md`, insert these entries after the existing `0x0050e848-0x0050e850` entry:

```markdown
- `0x0050eb8a-0x0050eb90` - alignment padding after `MapPaneCreateEffectObjectPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows six `0xcc` bytes at `0x0050eb8a-0x0050eb90`; `lookup_funcs` reports `sub_50EA30` at `0x0050ea30` size `0x15a`, and the next modeled function starts at `0x0050eb90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) and [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md).

- `0x0050ec2e-0x0050ec30` - alignment padding after `MapPaneApplyEffectObjectPaneTimerAction`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows two `0xcc` bytes at `0x0050ec2e-0x0050ec30`; `lookup_funcs` reports `sub_50EB90` at `0x0050eb90` size `0x9e`, and the next modeled function starts at `0x0050ec30`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
```

## Exact Coverage Report Edits For Supervisor

In `by-memory/-coverage-report.md`, insert these rows after the existing `0x0050e848-0x0050e850` padding row and before the current [UID:0001AX] row:

```markdown
        - [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) 0x0050e850-0x0050ea30 | class method/private helper | MapPaneCoordinateEffectDescriptorDispatch : reconstructable : 86% : strong : Exact modeled `sub_50E850` child split from MapPanePacketHandlers; handles coordinate/no-target effect descriptor dispatch from MapPane packet helper `sub_511C90`, copies a 52-byte EffectInfo descriptor through EffectObjImageLib, validates map coordinates, scans existing effect-object child collections, reuses a matching EffectObjectPane through `0x0050eb90`, or creates one through `0x0050ea30`. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); EffectObjImageLib and EffectObjectPane remain provider/constructed-object owners. Final C++ blank pending final descriptor and collection field names.
        - [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) 0x0050ea30-0x0050eb8a | class method/private helper | MapPaneCreateEffectObjectPane : reconstructable : 86% : strong : Exact modeled `sub_50EA30` child split from MapPanePacketHandlers; allocates from the EffectObjectPane pool, constructs an EffectObjectPane, attaches it to target/pass-specific child collections, inserts it into MapPane object/list state, starts its idle timer, optionally schedules timer event `2`, and refreshes bounds. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); EffectObjectPane owns the constructed object, pool storage, constructor, and timer helper. Final C++ blank pending final EffectInfo/field/helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050eb8a-0x0050eb90 | padding | MapPaneCreateEffectObjectPane to MapPaneApplyEffectObjectPaneTimerAction alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows six `0xcc` bytes after `sub_50EA30` end-exclusive `0x0050eb8a` and before next modeled function `sub_50EB90` starts at `0x0050eb90`.
        - [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) 0x0050eb90-0x0050ec2e | class method/private helper | MapPaneApplyEffectObjectPaneTimerAction : reconstructable : 86% : strong : Exact modeled `sub_50EB90` child split from MapPanePacketHandlers; applies update arguments to reusable EffectObjectPane entries, invoking the first virtual slot for `-1`, canceling timer event `2` for `-2`, and extending/rescheduling timer event `2` for positive delays when the effect pane flag permits it. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); TimerMgr remains generic timer owner. Final C++ blank pending final timer-field/action names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050ec2e-0x0050ec30 | padding | MapPaneApplyEffectObjectPaneTimerAction to next MapPane helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows two `0xcc` bytes after `sub_50EB90` end-exclusive `0x0050ec2e` and before next modeled function `sub_50EC30` starts at `0x0050ec30`.
```

No parent [UID:0001AW] coverage row replacement is required.

## Validation Order

1. Confirm no UID allocation happened after `0003TD`; if it did, remap the proposed UIDs consistently before applying.
2. Create child pages [UID:0003TE], [UID:0003TF], and [UID:0003TG].
3. Apply [UID:0001AW] parent child-table, boundary, evidence, cross-reference, and change-note edits.
4. Apply [UID:00007Q] and [UID:0000L3] support cross-reference/change-note edits.
5. Apply `by-memory/-ignored.md` padding entries.
6. Apply `by-memory/-coverage-report.md` nested rows exactly under [UID:0001AW].
7. Validate the three new child pages with `validator.py --mode file --file <child> --apply --lock-timeout -1`.
8. Validate [UID:0001AW], [UID:00007Q], [UID:0000L3], `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.
9. Rerun `python .\tools\memory_ranges.py report` from `source-3/project-documentation`.
10. Confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`; confirm the `0x0050e848-0x00510400` broad leaf shrinks to start at `0x0050ec30` or equivalent after nested child insertion.

## IDA DB Recommendation

No IDA DB edit is recommended. IDA already has function objects at `0x0050e850`, `0x0050ea30`, and `0x0050eb90`; the proposed names are documentation names and remain provisional. Creating or renaming functions in IDA would not add safety for this batch.

## Roadmap Items Not Included In This Executable Batch

The following items should stay roadmap-only until a later bounded batch can give each child 85/85+ evidence:

- `0x0050ec30-0x0050edd0` (`sub_50EC30`): likely next MapPane effect/object helper, but not fully researched in this batch.
- `0x0050edd0-0x0050eef5` (`sub_50EDD0`): current parent docs say it is called from the combat/status packet helper; it needs its own caller/callee pass before creation.
- `0x0050ef00-0x0050f029` and `0x0050f030-...`: leave for later range and behavior confirmation.
- [UID:0001AX] and [UID:0001AZ] raw duplicate bodies remain below the current child creation/update confidence for any reclassification work.
- The later `0x005104c7-0x00513800` broad leaf remains a separate heavy source-split problem and blocks parent reclassification.

## Final Recommendation

Create [UID:0003TE], [UID:0003TF], and [UID:0003TG] now using the exact markdown above, add two ignored padding rows, and update the parent/support/coverage docs as specified. Keep [UID:0001AW] reconstructable and emitting through [UID:00007Q] after this batch. Do not add final C++ and do not edit IDA.

## Changed Files

- Created by B001 in this assignment: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch3.md`
- Direct by-* docs changed by B001: none
- Generated reports changed by B001: none
- IDA DB changed by B001: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch3.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
