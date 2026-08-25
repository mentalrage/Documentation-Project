** TARGET-REPORT-UID:0002R5 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:0002R5] FlyingParcelPaneCleanupDestructorBody

## Assignment

- Agent: B004.
- Assignment id: `B004-report-0002R5-flying-parcel-pane-cleanup-destructor-body-source-quality-20260626`.
- Target: [UID:0002R5][by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md](../../../../../by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md).
- Required disposition for this turn: report only. I made no target/support by-* edits, generated edits, project-level generated edits, coverage-report edits, validator/tool-state edits, or IDA database writes in this pass.
- Workflow: project-level `ntk-b-agent-workflow` skill, no subagents, no leases because this is report-only.

## Recommendation

Implement after supervisor validation.

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `92` |
| `CANONICAL_OWNER` | `000058` | `000058` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `000058` | `000058` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| `Nested` | `4` | `4` |
| Formal C++ | blank | populate exact ordinary destructor body |

Recommended item summary:

```text
Source-ready ordinary `FlyingParcelPane::~FlyingParcelPane()` cleanup body; deletes owned `Layer *m_animationLayer` at `+0x100`, with compiler lowering restoring vtables and tail-jumping into Pane base teardown.
```

Recommended formal `RECONSTRUCTION_CPP CODE` block for the target page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FlyingParcelPane::~FlyingParcelPane()
{
    delete m_animationLayer;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is the best current source-facing shape. The source body has one explicit ownership release. The vtable stores, explicit null test, virtual deleting-destructor call through the helper's first vtable slot, `Pane` base teardown, and scalar-delete storage-free path are compiler lowering and ABI wrapper behavior, not handwritten source statements for this target.

## Current Target State

The target currently has `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++, and `Nested:4`.

The page already documents the correct high-level role: a raw, non-IDA-promoted, non-deleting `FlyingParcelPane` cleanup destructor body. Its stale blocker is the statement that final C++ should remain blank until destructor/source route coordination with [UID:0001EN][FlyingParcelPaneScalarDeletingDestructor](../../../../../by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md). That coordination is now resolved for this target: [UID:0002R5] is the source-bearing ordinary destructor body, while [UID:0001EN] remains the compiler-generated scalar deleting destructor wrapper.

## Live IDA MCP Session

IDA MCP was available and responsive. This is not a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp` version `1.0.0`.
- Session id: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`.
- Imagebase: `0x400000`.
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size:2067`, backend worker PID `26892`, `is_analyzing:false`.

MCP request ids used as evidence in this pass:

- `21` `lookup_funcs`: target/raw boundary and scalar/base function status.
- `22` `xrefs_to`: raw start, vtable bases, scalar wrapper, adjustor thunks, and base teardown references.
- `24` `callees`: modeled callees for base teardown and scalar wrapper.
- `31` through `35` `disasm`: raw cleanup, base teardown, and scalar wrapper disassembly.
- `36` through `38` `decompile`: base teardown and scalar wrapper decompile; raw target decompile failure because the target start has no function.
- `41` `get_bytes`: predecessor padding, exact 53-byte target body, successor padding.
- `42` `insn_query`: exact target instruction list with `fn:null`.
- `45` `make_signature_for_range`: unique target signature.
- `46` `get_bytes`: vtable slot dwords for the FlyingParcelPane table family.

## Target Boundary And Bytes

Live MCP confirms the split is exact and should not be changed.

- `0x00546b74-0x00546b80`: twelve `0xcc` bytes after [UID:0002KJ][FlyingParcelPaneConstructor](../../../../../by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md).
- `0x00546b80-0x00546bb5`: 53-byte cleanup body. `tools/int_convert.py 0x35` confirms decimal `53`.
- `0x00546bb5-0x00546bc0`: eleven `0xcc` bytes before [UID:0002R6][FlyingParcelPaneStartAnimation](../../../../../by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md).

Request `41` returned exact body bytes:

```text
56 8b f1 8b 8e 00 01 00 00 c7 06 cc 1c 62 00 c7 86 a0 00 00 00 18 1d 62 00 c7 86 a4 00 00 00 48 1d 62 00 85 c9 74 06 8b 01 6a 01 ff 10 8b ce 5e e9 cb d9 ff ff
```

Request `45` returned a unique IDA-format signature for `0x00546b80-0x00546bb5`:

```text
56 8B F1 8B 8E ? ? ? ? C7 06 CC 1C 62 00 C7 86 ? ? ? ? ? ? ? ? C7 86 ? ? ? ? ? ? ? ? 85 C9 74 ? 8B 01 6A 01 FF 10 8B CE 5E E9
```

Request `42` returned 14 body instructions, all with `fn:null`, proving IDA still does not model the raw body as a function:

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x00546b80` | `push esi` | Raw body prologue fragment. |
| `0x00546b81` | `mov esi, ecx` | Preserve `this`. |
| `0x00546b83` | `mov ecx, [esi+100h]` | Load the owned helper pointer at `+0x100`. |
| `0x00546b89` | store `??_7FlyingParcelPane@@6B@` | Restore primary FlyingParcelPane vtable view. |
| `0x00546b8f` | store `??_7FlyingParcelPane@@6B@_0` | Restore secondary view at `+0xa0`. |
| `0x00546b99` | store `??_7FlyingParcelPane@@6B@_1` | Restore tertiary view at `+0xa4`. |
| `0x00546ba3-0x00546ba5` | `test ecx, ecx`; conditional branch | Compiler null guard for pointer deletion. |
| `0x00546ba7-0x00546bab` | load helper vtable, push `1`, indirect call | Deleting virtual destructor call for the owned helper. |
| `0x00546bad-0x00546baf` | restore `ecx == this`; pop `esi` | Prepare base teardown. |
| `0x00546bb0` | `jmp sub_544580` | Tail jump to `Pane` base teardown. |

## Vtable And Destructor Route

Live MCP request `46` read the relevant vtable slot dwords:

| Address | Bytes | Little-endian target | Meaning |
| --- | --- | --- | --- |
| `0x00621ccc` | `d0 6e 54 00` | `0x00546ed0` | Primary `FlyingParcelPane` destructor slot targets scalar deleting wrapper [UID:0001EN]. |
| `0x00621d18` | `8b 6e 54 00` | `0x00546e8b` | Secondary destructor slot targets adjustor thunk. |
| `0x00621d48` | `96 6e 54 00` | `0x00546e96` | Tertiary destructor slot targets adjustor thunk. |
| `0x00621d4c` | `70 6d 54 00` | `0x00546d70` | Tertiary update slot targets `AnimateStep`. |
| `0x00621d10` | `f0 6d 54 00` | `0x00546df0` | Draw slot targets `DrawParcelOrLetter`. |

Request `22` confirms the vtable bases have writes from the constructor, this raw cleanup body, and the scalar wrapper:

- `0x00621ccc`: constructor write at `0x00546afb`, raw cleanup write at `0x00546b89`, scalar wrapper write at `0x00546edc`.
- `0x00621d18`: constructor write at `0x00546b01`, raw cleanup write at `0x00546b8f`, scalar wrapper write at `0x00546ee2`.
- `0x00621d48`: constructor write at `0x00546b0b`, raw cleanup write at `0x00546b99`, scalar wrapper write at `0x00546eec`.

The route distinction is now decisive:

- [UID:0002R5] contains the ordinary complete-object/non-deleting destructor body: derived vtable restore, owned helper release, then base teardown.
- [UID:0001EN] at `0x00546ed0-0x00546f37` contains the scalar deleting destructor wrapper: it duplicates the cleanup, calls base teardown normally, then tests delete flags and may free object storage through `0x004f4ac0`.
- [UID:0001EM] adjustor thunks route secondary and tertiary destructor slots to the scalar wrapper.
- The source destructor body belongs in [UID:0002R5], not in the scalar wrapper or adjustor thunks.

## Raw Start Reachability

Live MCP and local read-only PE scanning agree that `0x00546b80` is not reached as a normal directly-called function start.

- Request `21` reports `0x00546b80` is not a function, while `0x00544580` is `sub_544580` and `0x00546ed0` is `sub_546ED0`.
- Request `22` reports no xrefs to `0x00546b80`.
- Request `38` fails to decompile `0x00546b80` because there is no function object.
- A read-only scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found:
  - absolute VA dword hits for `0x00546b80`: `0`
  - RVA dword hits for `0x00146b80`: `0`
  - direct `E8`/`E9` branch hits to `0x00546b80`: `0`

This negative evidence remains important, but it is no longer a formal C++ blocker. The same local source policy has already been accepted for ordinary cleanup destructor bodies such as [UID:0002PT] `LogoPlayerPaneCleanupDestructor` and [UID:0002PM] `LogoPaneCleanupDestructor`: a raw complete-object destructor body can be source-bearing even when the vtable dispatch route points to the scalar deleting destructor wrapper and no ordinary direct xref to the raw body survives.

## Helper Field And Source-Facing Name Decision

Recommended source-facing field/type for `this + 0x100`:

- `Layer *m_animationLayer`

Evidence:

- [UID:0002KJ][FlyingParcelPaneConstructor](../../../../../by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) now emits a formal constructor body that allocates a `Layer` and stores it in `m_animationLayer`.
- [UID:000058][FlyingParcelPane](../../../../../by-class/FlyingParcelPane.md) accepts `+0x100` as `m_animationLayer` / `m_screenLayerEntry`.
- [UID:0002KK][FlyingParcelPaneAnimateStep](../../../../../by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) uses `m_animationLayer` when removing the layer through `ScreenPane`.
- [UID:0002R6][FlyingParcelPaneStartAnimation](../../../../../by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) documents the same object as the ScreenPane layer attachment entry.
- The cleanup body's null check and deleting virtual call are exactly the compiler lowering for releasing an owned polymorphic pointer.

Rejected alternatives:

- `m_screenLayerEntry` as the formal field name: useful descriptive alias in prose, but weaker for emitted C++ because the constructor and accepted method C++ already use `m_animationLayer`.
- `m_layer`, `m_helper`, `m_layerEntry`, or `m_renderLayer`: less tied to current accepted support docs and constructor C++.
- Raw `this + 0x100` in the formal source: rejected because the project already has a stable source-facing member name.
- Explicit source-level null check before deletion: rejected as decompiler-shaped. The binary null guard is normal compiler lowering for deleting a pointer; the formal source should express ownership directly.
- Manual call to the helper's deleting destructor vslot: rejected as ABI lowering, not source.

## Source Shape Decision

The target should emit ordinary destructor source C++.

Positive evidence:

- The body is exact, unique, and padding-bounded.
- The body has destructor-lowering shape: derived vtable stores, owned member release, base destructor tail jump.
- The scalar wrapper duplicates this cleanup and adds only deleting-destructor flag/object-free behavior.
- The primary vtable slot points to the scalar wrapper, while the raw body contains the source destructor's complete non-deleting cleanup sequence.
- The constructor owns the same helper pointer and current accepted formal constructor C++ names it `m_animationLayer`.
- Local accepted destructor precedents put handwritten destructor source in the ordinary cleanup page, not in the scalar deleting wrapper.

Rejected source dispositions:

- Keep [UID:0002R5] blank as no-code compiler glue: rejected because this range contains the only ordinary source destructor body for the owned animation layer release.
- Move source C++ to [UID:0001EN]: rejected because [UID:0001EN] includes MSVC delete flags and optional object-storage free that source C++ should not hand-author.
- Use a comment-only generated-template/ABI marker: rejected because this is not template glue, not a pure adjustor thunk, and not source already covered by another exact child.
- Merge [UID:0002R5] into [UID:0001EL] or [UID:0002R6]: rejected by exact padding and role boundaries.
- Create a standalone cleanup helper name: rejected because the vtable stores, base teardown, and scalar-wrapper parity prove destructor lowering for `FlyingParcelPane`.

## Relation To Neighboring Pages

### [UID:0001EL] `FlyingParcelPaneRawLifecycleAndStart`

[UID:0001EL] should remain a non-emitting split/index over `0x00546b80-0x00546d64`. It should be updated only to state that its first child [UID:0002R5] is now source-ready and carries the ordinary destructor formal block; [UID:0002R6] remains the raw start/configure method with its own unresolved source-shape/caller-route caveats. The aggregate itself should not emit duplicate destructor source.

### [UID:0002R6] `FlyingParcelPaneStartAnimation`

[UID:0002R6] is the successor raw method after eleven `0xcc` bytes. This report does not change its source status. The only recommended implementation action is a contradiction check: do not let old aggregate/file wording continue to imply that both raw lifecycle children are equally blank because destructor factoring is unresolved. The StartAnimation-specific no-direct-route and method-signature caveats remain independent.

### [UID:000058] `FlyingParcelPane`

The class page should be updated to remove destructor shape as a child-level C++ blocker. It can still keep the class-level formal block blank because declaration visibility, StartAnimation source shape, helper prototypes, inherited virtual declarations, and private/file-local class exposure remain broader class questions. The method inventory should state that [UID:0002R5] now owns/emits the source destructor body, while [UID:0001EN] and adjustor thunks are compiler destructor dispatch/delete glue.

### Parcel notification vtables and layout support

[UID:0002OH][ParcelNotificationVtableData](../../../../../by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) and [UID:0001YE][ParcelNotificationVtableFamily](../../../../../by-type/by-vtable/ParcelNotificationVtableFamily.md) already document the primary/secondary/tertiary FlyingParcelPane slots. They should receive a short clarification only if the implementation touches support docs broadly: vtable destructor slots point to scalar wrapper/thunks, while the ordinary source destructor cleanup body is [UID:0002R5].

[UID:0001VI][ParcelNotificationPaneLayouts](../../../../../by-type/by-struct/ParcelNotificationPaneLayouts.md) should receive a short ownership clarification if accepted: `+0x100` is source-facing `Layer *m_animationLayer`; constructor allocates it, animation/start/draw support uses it as the ScreenPane layer, and [UID:0002R5] source C++ deletes it. Score can remain unchanged.

## Score Rationale

Recommended target score: `COMPLETION:90`, `CONFIDENCE:92`.

Completion moves from `85` to `90` because the current pass resolves the page's live source-quality blocker:

- exact range and padding are live-MCP confirmed;
- the 53-byte body has exact bytes, instruction list, and unique signature;
- owner/emitter remain proven through FlyingParcelPane vtable writes and existing class/file route;
- scalar wrapper and adjustor-thunk relationship is decisive;
- `+0x100` has a best source-facing field/type decision aligned with accepted constructor and method pages;
- first-draft formal C++ is now safe for the target;
- no-code/comment-only alternatives are rejected with target-specific proof.

Confidence moves from `88` to `92` because live MCP, existing support docs, vtable data, scalar-wrapper decompile, and read-only PE no-route scanning agree. It should not go higher because:

- IDA still does not promote `0x00546b80` as a function;
- no direct raw-start caller/pointer route was recovered;
- exact original private member spelling and class declaration visibility remain inferred;
- the sibling raw StartAnimation page still has unresolved source-shape/caller-route caveats.

These remaining issues cap final-audit confidence but do not justify blank target C++.

## Recommended Target Doc Changes

For [UID:0002R5][by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md](../../../../../by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md):

- Set `COMPLETION:90`.
- Set `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:000058`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:000058`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `Nested:4`.
- Replace the formal C++ block with the exact marker/block content above.
- Update `Item Summary` to the recommended source-ready ordinary destructor summary.
- Replace stale "blank until coordinated" language with the current source policy:
  - [UID:0002R5] is the ordinary source destructor body.
  - [UID:0001EN] is the scalar deleting destructor wrapper.
  - vtable stores, null guard, helper vslot call, and base tail jump are compiler lowering around the handwritten ownership release.
- Add B004 2026-06-26 evidence for MCP session `80de0a67`, request ids `21`, `22`, `24`, `31-38`, `41`, `42`, `45`, and `46`; read-only PE no-route scan; field/name decision; rejected alternatives; score rationale; generated-refresh expectation; and change entry.

## Recommended Support-Doc Changes

### [UID:000058] `by-class/FlyingParcelPane.md`

Recommended metadata: raise from `87/90` to `88/91` if the destructor-source detail is incorporated. Keep owner/emitter/reconstructable and class formal C++ blank.

Required content updates:

- Method table: mark [UID:0002R5] as ordinary source-ready `FlyingParcelPane` destructor body with formal C++ in the child page.
- Layout notes: keep `+0x100` as `Layer *m_animationLayer` / `m_screenLayerEntry`, but prefer `m_animationLayer` for emitted C++ because constructor, animation, and destructor children now converge on that name.
- No-code proof: remove destructor shape from the class-level formal-C++ blocker list. Keep class formal C++ blank for declaration visibility, private/file-local exposure, StartAnimation source shape, helper prototypes, inherited virtual names, and broader class declaration concerns.
- Destructor family note: [UID:0001EN] scalar wrapper and [UID:0001EM] adjustor thunks are compiler-generated dispatch/delete glue; [UID:0002R5] is the source destructor body.

### [UID:0000MF] `by-file/ParcelPane.md`

Recommended score: keep `88/88`.

Required content updates:

- Update the FlyingParcelPane method/source notes to say the cleanup destructor child [UID:0002R5] now emits formal ordinary destructor C++.
- Preserve the existing source-file placement under `NexusTK/ui/panels/ParcelPane.cpp`.
- Remove any remaining implication that raw cleanup and raw start are both blocked by a shared destructor/source-route problem. [UID:0002R6] remains independently unresolved; [UID:0002R5] does not.

### [UID:0001EL] `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md`

Recommended score: keep `88/91`.

Required content updates:

- Keep the aggregate non-emitting (`RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++).
- Update the child table/notes for `0x00546b80-0x00546bb5` to state that [UID:0002R5] now carries source-ready ordinary destructor C++.
- Keep `0x00546bb5-0x00546bc0` as padding and [UID:0002R6] as a separate raw start method.
- State that the aggregate must not emit duplicate destructor source.

### [UID:0001EN] `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`

Recommended score: keep `86/91`.

Required content updates:

- Keep formal C++ blank.
- Update the no-code proof to say source destructor emission now belongs to [UID:0002R5].
- Preserve scalar wrapper facts: primary vtable dispatch, duplicated cleanup, delete-flags parameter, optional object free through `0x004f4ac0`, and `0x104` guard/size path.
- Do not hand-author scalar deleting destructor source.

### [UID:0001VI] `by-type/by-struct/ParcelNotificationPaneLayouts.md`

Recommended score: keep unchanged.

Required content updates:

- Add or refresh a short `FlyingParcelPane` `+0x100` note: source-facing `Layer *m_animationLayer`, constructor allocation, ScreenPane attachment/removal role, and ordinary destructor release by [UID:0002R5].
- Preserve `m_screenLayerEntry` only as a descriptive alias where useful.

### [UID:0002OH] `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`

Recommended score: keep unchanged.

Required content updates:

- Add a vtable-route clarification if not already present at equal detail: primary destructor slot `0x00621ccc` points to scalar wrapper [UID:0001EN], secondary/tertiary destructor slots point to adjustor thunks, and the ordinary source destructor body is [UID:0002R5].

### [UID:0001YE] `by-type/by-vtable/ParcelNotificationVtableFamily.md`

Recommended score: keep unchanged.

Required content updates:

- Mirror the vtable-route clarification from the vtable-data page if the family page currently implies that the vtable slot itself owns source destructor emission.

### Check-only / no-edit unless contradiction

Do not edit these pages unless implementation finds stale contradictory wording not covered above:

- [UID:0002KJ][FlyingParcelPaneConstructor](../../../../../by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md): already emits the constructor and names `m_animationLayer`.
- [UID:0002R6][FlyingParcelPaneStartAnimation](../../../../../by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md): sibling raw method, no source-status change in this report.
- [UID:0002KK][FlyingParcelPaneAnimateStep](../../../../../by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md): already emits method C++ using `m_animationLayer`.
- [UID:0002KL][FlyingParcelPaneDrawParcelOrLetter](../../../../../by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md): unrelated draw child, no contradiction found in report review.

## Generated And Coverage State

Do not hand edit generated or coverage files.

Pre-implementation generated state was stale relative to the target:

- Before implementation, `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` had an empty emitter marker for [UID:0002R5].
- Before implementation, the generated marker still showed stale score text for [UID:0002R5] (`Completion:78 Confidence:86` in the generated output observed during the report pass), while the manual target page was already `85/88`.
- After implementation and scoped validators with `--wait-generated`, the generated ParcelPane output was expected to gain the `FlyingParcelPane` ordinary destructor body from [UID:0002R5] and refresh the target score marker. The implementation checklist below records the completed generated-refresh observation.
- Generated tracker/coverage/project-level stats may update after validation. They must not be manually edited in a B-agent implementation callback.
- Manual `by-memory/-coverage-report.md` and any `-coverage-report.md` file remain out of scope.

## Implementation Tracking Checklist

Implementation callback completed by B004 on 2026-06-26. Each checked item below is incorporated, already present at equal-or-greater detail, or explicitly narrowed with proof.

- [x] Acquire short leases only for the immediate edit batch. If another active lease blocks any target/support edit, stop and report `PAUSED_LEASE_CONFLICT` with exact lease details.
  - Proof: B004 successfully leased the target/support batch, refreshed the lease window immediately before validation, and did not edit through another agent lease. A first relative-path lease attempt from `tools/leaser` failed before creating any lease. Final release proof is below.
- [x] Edit [by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md](../../../../../by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md):
  - [x] Set `COMPLETION:90`.
  - [x] Set `CONFIDENCE:92`.
  - [x] Keep `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:4`.
  - [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` marker/block from this report.
  - [x] Replace stale "blank until destructor coordination" wording with the resolved ordinary-destructor/source-wrapper split.
  - [x] Add MCP session `80de0a67` evidence, exact bytes, instruction list, unique signature, vtable route, scalar-wrapper parity, no raw-start xrefs/pointers, read-only PE no-route scan, field/name decision, rejected alternatives, score rationale, generated-refresh expectation, and B004 2026-06-26 change entry.
  - Proof: target header now has `90/92`, unchanged owner/emitter/reconstructable/Nested fields, and the formal destructor block. Sections `2026-06-26 B004 Live MCP Recheck`, `Reconstruction Notes`, `Score Rationale`, `Generated Refresh Expectation`, and `Changes` preserve the accepted facts.
- [x] Edit [by-class/FlyingParcelPane.md](../../../../../by-class/FlyingParcelPane.md):
  - [x] Raise to `COMPLETION:88`, `CONFIDENCE:91`.
  - [x] Update method inventory, layout note for `+0x100`, destructor family note, class-level no-code proof, rejected generated/source-shape alternatives, and change entry.
  - Proof: class metadata is `88/91`; the method table, accepted fields, B004 evidence bullet, class-level no-code proof, assignment gate, and 2026-06-26 change entry now state that [UID:0002R5] emits the ordinary destructor while scalar wrapper/thunks remain compiler glue.
- [x] Edit [by-file/ParcelPane.md](../../../../../by-file/ParcelPane.md):
  - [x] Add the source-ready [UID:0002R5] destructor note under the FlyingParcelPane/ParcelNotificationPanes material.
  - [x] Preserve `ParcelPane.cpp` source route and score.
  - [x] Remove wording that treated destructor source shape as unresolved for [UID:0002R5].
  - Proof: file score remains `88/88`; the FlyingParcelPane source-route notes now say [UID:0002R5] emits `FlyingParcelPane::~FlyingParcelPane()` through `ParcelPane.cpp`, while raw `StartAnimation` remains independently unresolved.
- [x] Edit [by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md](../../../../../by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md):
  - [x] Keep aggregate non-emitting/blank.
  - [x] Update the [UID:0002R5] child row and notes to source-ready ordinary destructor body.
  - [x] Preserve split boundaries and [UID:0002R6] independent raw-start caveats.
  - Proof: aggregate remains non-emitting/blank; child table marks `0x00546b80-0x00546bb5` as source-ready, preserves padding and [UID:0002R6] split caveats, and adds a B004 change entry.
- [x] Edit [by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md](../../../../../by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md):
  - [x] Keep formal C++ blank.
  - [x] Add/refresh proof that [UID:0001EN] is the scalar deleting wrapper and [UID:0002R5] owns source destructor emission.
  - Proof: wrapper page remains blank formal C++; `Final C++ Gate`, behavior, parent/ownership, score rationale, and change entry now point source emission to [UID:0002R5].
- [x] Edit [by-type/by-struct/ParcelNotificationPaneLayouts.md](../../../../../by-type/by-struct/ParcelNotificationPaneLayouts.md):
  - [x] Add/refresh `Layer *m_animationLayer` at `+0x100` ownership/release note.
  - [x] Keep score unchanged.
  - Proof: layout page records constructor allocation, ScreenPane attachment/removal, ordinary destructor release, and preserves `m_screenLayerEntry` as prose alias only.
- [x] Edit [by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md](../../../../../by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md):
  - [x] Add/refresh vtable-route clarification for scalar wrapper/thunks versus ordinary source destructor body.
  - [x] Keep score unchanged.
  - Proof: vtable data page now states `0x00621ccc` routes to [UID:0001EN], `0x00621d18/0x00621d48` route to adjustor thunks, and [UID:0002R5] owns the ordinary source-bearing cleanup body.
- [x] Edit [by-type/by-vtable/ParcelNotificationVtableFamily.md](../../../../../by-type/by-vtable/ParcelNotificationVtableFamily.md):
  - [x] Mirror the vtable-route clarification.
  - [x] Keep score unchanged.
  - Proof: family page mirrors the scalar-wrapper/thunk route and source destructor ownership distinction.
- [x] Check [by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md](../../../../../by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md), [by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md](../../../../../by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), [by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md](../../../../../by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md), and [by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md](../../../../../by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) for contradiction only.
  - Proof: constructor already emits `m_animationLayer = new Layer` and needed no edit; `StartAnimation` keeps independent raw-start caveats and needed no edit; draw page had no destructor/lifecycle contradiction and needed no edit. `AnimateStep` did contain stale "raw cleanup/start source-entry policy" wording, so it was edited to narrow the residual caveat to raw `StartAnimation` only and validated as a changed by-* file.
- [x] Do not manually edit auto-generated files, project-level generated outputs, coverage-report files, validator/tool state, or IDA DB.
  - Proof: by-* docs and this B004 report were the only manual edits. Validator-owned generated refresh updated generated outputs; no manual coverage-report/tool-state/IDA DB edits were made.
- [x] Run scoped validators with `--wait-generated` for every changed by-* file from `source-3/project-documentation`. Final command set included the check-only page that required a contradiction fix:

> Executable block R001 was removed from this report and preserved verbatim in [0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality-removed.md](0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Record each validator command id, timestamp, exit code, `ok` count, warnings, and generated refresh state.
  - Proof: all validators exited `0`, `ok:1`, `generated_refresh: completed`. Each run repeated known unrelated diagnostics `autogen_registry_stale:147` and `memory_coverage_metadata_missing_file:145`; no target-specific failure was reported.
  - `by-memory\0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md`: command_id `000000002798`, timestamp `2026-06-26T15:21:54-04:00`, exit `0`, ok `1`.
  - `by-class\FlyingParcelPane.md`: command_id `000000002799`, timestamp `2026-06-26T15:22:06-04:00`, exit `0`, ok `1`.
  - `by-file\ParcelPane.md`: command_id `000000002800`, timestamp `2026-06-26T15:22:18-04:00`, exit `0`, ok `1`.
  - `by-memory\0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md`: command_id `000000002801`, timestamp `2026-06-26T15:22:29-04:00`, exit `0`, ok `1`.
  - `by-memory\0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`: command_id `000000002802`, timestamp `2026-06-26T15:22:41-04:00`, exit `0`, ok `1`.
  - `by-type\by-struct\ParcelNotificationPaneLayouts.md`: command_id `000000002803`, timestamp `2026-06-26T15:22:53-04:00`, exit `0`, ok `1`.
  - `by-memory\0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`: command_id `000000002804`, timestamp `2026-06-26T15:23:04-04:00`, exit `0`, ok `1`.
  - `by-type\by-vtable\ParcelNotificationVtableFamily.md`: command_id `000000002805`, timestamp `2026-06-26T15:23:16-04:00`, exit `0`, ok `1`.
  - `by-memory\0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`: command_id `000000002807`, timestamp `2026-06-26T15:23:28-04:00`, exit `0`, ok `1`.
- [x] Inspect generated refresh observations for [UID:0002R5] in `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` without editing generated files.
  - Proof: generated header reports `validator-command-id: 000000002807`, `validator-refreshed-at: 2026-06-26T15:23:28-04:00`, source by-file `0000MF`; [UID:0002R5] marker now shows `Completion:90 | Confidence:92` and contains `FlyingParcelPane::~FlyingParcelPane()` with the accepted destructor body.
- [x] Release leases immediately after the edit/validator batch and record proof that no active B004 leases remain.
  - Proof: `python .\tools\leaser\leaser.py B004 unlease` succeeded for all nine leased paths after validation. `tools/leaser/Agents/current_leases.md` read at `2026-06-26T15:23:55-04:00` contained no B004 rows.
- [x] Update this checklist with checked items and proof during the implementation callback only.

## Final Implementation Status

Implementation callback complete. The accepted target/support by-* docs are updated at report-level detail; the one check-only contradiction in `FlyingParcelPaneAnimateStep` was fixed and validated; constructor, StartAnimation, and draw check-only pages required no edit. Validators passed for every changed by-* file with `--wait-generated`, generated ParcelPane output refreshed through the validator, and no active B004 leases remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md","timestamp":"2026-06-26T15:35:04","uid":"0002R5"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002R5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
