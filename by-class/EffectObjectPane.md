*** UID:000049 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/PoolAllocator.h"

// EffectObjectPane class-level source remains intentionally withheld here.
// Exact source-bearing children emit the audited methods and static storage.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectObjectPane

## UID0003Z4 Effect Registration And Lifetime - 2026-07-14

- Preserve current score, owner/emitter route, layout, formal declaration, and public `m_effectId` contract. `m_effectId` at `+0x148` is compared by [UID:0004QK][0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane](by-memory/0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane.md), [UID:0004QL][0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane](by-memory/0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane.md), UID000232 reuse, UID0003Z6 effect-134 removal, and UID0004QH cleanup.
- LivingObjectPane owns two `List *` collections of `EffectObjectPane *`: primary at `+0x170` from creation selector 1/type 2, and secondary at `+0x174` from selector 0/type 4. The add methods scan backward, delete every same-ID object, do not erase stale List slots, then append one pointer.
- `DestroyAttachedObjects` removes each listed pane from active MapPane if present and deletes it; full cleanup later clears surviving owner links through `SetLivingObjectPane(NULL)` and destroys the List objects. These exact phases must not be collapsed into generic container destruction.
- Historical base ObjectPane ID comparison, generic attached-object element types, vector substitution, and type2/type4 source field names are superseded while retained as prior search vocabulary.

## UID0003TF MapPane Creation Contract - 2026-07-15

- Class metadata remains `85/86`, owner/emitter UID0000IZ, reconstructable true, and comment-only formal C++. Completing the MapPane creation helper does not claim a complete EffectObjectPane declaration or change this class's broader source-split score.
- Source-ready [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) uses ordinary `new EffectObjectPane` and passes a borrowed `LivingObjectPane *target`, map row/column, by-value `EffectInfo`, sequence index, and `renderAfterLivingObjects`. The visible pool allocation, vptr stores, cookie/EH paths, constructor-failure return, and TimerHandler adjusted view are compiler/class-allocation lowering rather than handwritten MapPane code.
- Constructor evidence fixes the consumed state: borrowed target `+0x128`; selected `EffectInfo` sequence header `+0x12c..+0x143`; current frame `+0x144=-1`; `m_effectId` `+0x148`; `m_looping` `+0x14c`; `m_renderAfterLivingObjects` `+0x14d`; inferred `m_timerExtensionLocked +0x14e=false`; ObjectPane type `2 * (sequenceIndex != 1) + 2`. Primary/secondary range choice comes from `EffectInfo +0x14/+0x18` versus `+0x2c/+0x30`.
- For a non-null target, UID0003TF registers sequence `0` through `AddSecondaryEffectObjectPane` and sequence `1` through `AddPrimaryEffectObjectPane`; all created panes enter MapPane `m_objectList`, call `StartIdleTimer` for event 1, and conditionally receive event 2 through the complete inherited TimerHandler view at `+0xa4`.
- Vtable `0x0062066c` points to `0x005388c0`, whose source-facing role is `EffectObjectPane::UpdatePosition`: it computes current sprite bounds, offsets them by attached position, and updates inherited bounds. UID0003TF invokes it only for a non-null target, then separately calls inherited `GetBounds` and invalidates the result. The prior `GetEffectBounds` name for `0x005388c0` is superseded; it incorrectly collapsed the virtual update and subsequent bounds-read calls.
- MapPane owns the request/create/reuse decision. EffectObjectPane owns this layout, constructor, update/render/timer methods, RTTI/vtables, and static pool. EffectObjImageLib supplies descriptors/rendering; TimerMgr supplies queue operations. No owner transfer to MapPane, new class source route, or explicit pool API belongs in the target formal body.

## Status

- Confidence: strong for runtime role, method boundaries, vtable/destructor/static-pool ownership, and memory ownership; medium for final source module granularity.
- Proposed source: `render/Effects.cpp` or a nearby object-pane/effects module.
- Historical generated lead, not current evidence: older Wave3/simroot_v2 output staged this class as `source-3/simroot_v2/class_EffectObjectPane.cpp` and summarized it as a visual effect object pane. Treat that as superseded discovery context only; current ownership/source route is based on IDA MCP vtable/RTTI, constructor/destructor, pool, and current by-* evidence.
- Core memory ranges: `0x005387b0-0x00538baa`
- Scalar deleting destructor range: [UID:000382][0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor](by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md)
- Vtable data: [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md)
- Static pool storage: [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md)

## Responsibility

`EffectObjectPane` is a game-object pane for animated effect sprites. It stores an effect id, frame/timeline descriptor, current frame, flags, and optional loop range. Runtime methods resolve sprite bounds, advance frames, trigger lighting state changes, update the parent object, schedule sounds, and render effect sprites through the effect render context.

This class consumes image data loaded by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), but it is not the asset loader itself. It is closer to runtime object/render code and should be cross-linked from [UID:0000IZ][Effects](by-file/Effects.md) and [UID:0000L3][MapPane](by-file/MapPane.md).

Lighting intensity changes are delegated to [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md). Keep that class as the light-source object owner rather than folding it into `EffectObjectPane`.

`EffectObjectPane +0x148` is the copied `EffectInfo +0x00` effect id/key. Byte `+0x14c` is best named `m_looping`: the constructor sets it when the selected sequence range fields are valid, timer event id `2` clears it, and MapPane/local-player callers use [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) as an existing-effect reuse/stop gate. Byte `+0x14d` is the late secondary-effect render selector, best source-facing `m_renderAfterLivingObjects`: exact MapPane render tests it in two mutually exclusive secondary-list passes before versus after living objects. Byte `+0x14e` is independently consumed by UID0003TG as a replacement-blocking predicate and is best described as inferred `m_timerExtensionLocked`; the constructor initializes it false and bounded MapPane/EffectObjectPane searches found no observed nonzero direct writer. Original private spellings remain lexical confidence caps, but all three bytes have distinct evidence-backed roles.

## UID00037V Late-Effect Render Role - 2026-07-14

- [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md) traverses the LivingObjectPane secondary attached-effect list twice. The earlier row pass renders entries whose EffectObjectPane byte `+0x14d` is clear; the later after-living pass renders entries whose byte is set.
- The two exact complementary predicates prove a render-order selector rather than padding, generic active state, loop state, visibility, or effect type. `m_renderAfterLivingObjects` is the best descriptive source name; no symbol survives to prove original spelling.
- `+0x14c` remains independent `m_looping`; inferred `m_timerExtensionLocked +0x14e` independently gates timer replacement. The three adjacent fields must not be collapsed into reuse/lifetime, render-order, or one generic active flag.
- Scores, owner/emitter, class covered/exclusion formal, source route, constructor/render split backlog, and all unrelated effect evidence remain unchanged.

[UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) is now a non-emitting split/container page, not a class-level source body. B010 current MCP session `60724697` confirms that the range spans constructor, existing ordinary destructor child, existing StartIdleTimer child, `UpdatePosition`, frame-bounds helper, TimerHandler-adjusted update/timer handler, render helper, and successor IsLooping child separated by padding and vtable refs. Missing exact child pages should own the constructor, `UpdatePosition`, `GetFrameBounds`, `UpdateEffectAnimation`, and `RenderEffect` bodies when the supervisor authorizes a child-creation pass.

[UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) now emits `MapPane::RequestObjectEffect` and reuses an existing effect pane only when `EffectObjectPane::m_effectId` at `+0x148` equals `EffectInfo::effectKeyOrId` and `IsLooping()` returns true from `m_looping` at `+0x14c`. This is caller-side reuse evidence only; `EffectObjectPane` remains the owner of the runtime object layout and `IsLooping()` accessor, while MapPane owns the request dispatcher.

Source-ready [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) reuses the same public `m_effectId` and `IsLooping()` contract for coordinate effects. It selects the row bucket first, reverse-scans its `EffectObjectPane *` slots, and compares only the pane's map column plus effect id and looping state; it does not add a null check or a second row comparison. If no matching pane exists, it calls UID0003TF with `target == NULL`, the machine-proven row-before-column order, sequence `0`/`1`, and the original timer/render arguments. This is additional MapPane consumer evidence, not a transfer of class ownership or proof that the broader comment-only class declaration is complete.

## UID0003TG Timer-Extension Lock Consumer - 2026-07-15

- Source-ready [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) consumes `m_timerExtensionLocked` only after null, source-delete, zero, and event-2-cancel cases. Every remaining signed action returns when the byte is true and otherwise queries/replaces TimerHandler event 2. The predicate polarity therefore rejects `m_allowTimerExtension`; adjacent independent consumers reject `m_looping` and `m_renderAfterLivingObjects`; the controlled timer side effect rejects padding, visibility, type, and generic-active interpretations.
- The constructor's zero store at `0x0053886e` establishes default false. Bounded current-family searches found no direct nonzero writer, which is preserved as negative evidence rather than converted into a claim that no writer can exist anywhere. The spelling `m_timerExtensionLocked` is inferred, but byte width, offset, zero initialization, polarity, and use are directly evidenced.
- UID0003TG uses ordinary `delete` for action `-1` and typed inherited TimerHandler conversion for queue calls. Scalar deleting-destructor flags, raw `+0xa4` adjustment, and vtable-slot syntax are compiler lowering, not EffectObjectPane declarations or handwritten MapPane source.
- This bounded field-role synchronization does not complete the broader class declaration, change `85/86`, alter UID0000IZ ownership/emission, or replace the comment-only class formal. Exact children remain method-definition owners; MapPane owns the descriptor reuse policy and TimerMgr owns generic queue operations.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x005387b0-0x0053887c` | future child `EffectObjectPaneConstructor` | Constructs the attached object pane state from borrowed LivingObjectPane target, effect id, selected `EffectInfo` frame-sequence header, `renderAfterLivingObjects`, and constructor mode. Covered by non-emitting [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) until an exact child page is authorized. |
| `0x00538880-0x0053889f` | `~EffectObjectPane` ordinary destructor body | Resets the primary EffectObjectPane view plus inherited `+0xa0` EventHandler/pane-handler and `+0xa4` TimerHandler/event adjusted views, then delegates to the attached-object cleanup body. |
| `0x005388a0-0x005388b4` | inferred `StartIdleTimer` | Source-ready helper that schedules timer/event id `1` with zero delay/payload through `TimerHandler::ScheduleTimer(1, 0, 0, 0)` on the inherited `+0xa4` TimerHandler adjusted view; generated BackPane ownership is historical pollution rejected by caller/layout evidence. |
| `0x005388c0-0x00538956` | future child `EffectObjectPaneUpdatePosition` | Uses the active frame entry and `GetSpriteBounds`, falls back to zero bounds when the current frame is invalid, offsets by attached screen position, then calls the inherited virtual bounds setter. Vtable and UID0003TF call order establish `UpdatePosition`, not the superseded `GetEffectBounds` label. Covered by UID0001D9 until split. |
| `0x00538960-0x005389c9` | future child `EffectObjectPaneGetFrameBounds` | Copies active frame bounds or zero bounds into caller-provided rectangles. Covered by UID0001D9 until split. |
| `0x005389d0-0x00538aef` | future child `EffectObjectPaneUpdateEffectAnimation` | TimerHandler-adjusted update/event body that advances frame sequence, handles loop/end removal, updates lighting or map effect state, refreshes parent sprite frame, and schedules the next timer. Covered by UID0001D9 until split. |
| `0x00538af0-0x00538baa` | future child `EffectObjectPaneRenderEffect` | Draws current effect frame through [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), with optional render-context overlay state. Covered by UID0001D9 until split. |
| [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) | `IsLooping` | Seven-byte non-virtual accessor returning byte `+0x14c`; MapPane effect descriptor dispatch and local-player movement effect cleanup call it after matching `+0x148` against the effect descriptor id. |
| [UID:000382][0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor](by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Resets vtables, destroys `AttachedObjectPane`, and optionally frees object memory through the EffectObjectPane pool. |

## Batch233 Parent-Gate Evidence

2026-06-11 A002 live IDA MCP `py_eval` rechecked the specific evidence needed for the direct-parent gate:

- Function boundaries are confirmed for the constructor `0x005387b0-0x0053887c`, non-deleting destructor `0x00538880-0x0053889f`, timer helper `0x005388a0-0x005388b4`, bounds/render/update methods through `0x00538af0-0x00538baa`, scalar deleting destructor `0x0053d100-0x0053d197`, and adjustor thunks `0x0053ced0-0x0053cedb` / `0x0053cedb-0x0053cee6`.
- `xrefs_to 0x0053d100` reports the two adjustor refs at `0x0053ced6` and `0x0053cee1`, plus the primary vtable data ref at `0x006205fc`.
- The three `EffectObjectPane` vtable views at `0x006205fc`, `0x00620674`, and `0x006206a4` are each referenced from the constructor, non-deleting destructor, and scalar deleting destructor, tying the exact `.rdata` child [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md) to this class.
- `xrefs_to 0x0069b90c` reports the static pool constructor wrapper `0x0041a080`, allocation user `0x0050ea30`, constructor-failure free wrapper `0x00514b60`, scalar deleting destructor free at `0x0053d150`, and cleanup wrapper `0x0060c340`, making [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md) a direct class-owned static declaration.
- `xrefs_to 0x005387b0` and `xrefs_to 0x005388a0` both land in `sub_50EA30`, the MapPane object-setup path that allocates from the `EffectObjectPane` pool, constructs the object, inserts it, and starts the idle timer on the same object pointer.
- 2026-06-17 B001 reanalysis resolves [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md) as the ordinary `EffectObjectPane::~EffectObjectPane()` body. The no-direct-xref condition was bounded with IDA xrefs and raw VA/RVA pointer searches, and `+0xa0`/`+0xa4` are now documented as inherited handler adjusted views rather than unknown EffectObjectPane-specific fields.
- 2026-06-25 B002 source-quality implementation resolves [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) enough for exact child C++. Current MCP session `80de0a67` reconfirmed the 20-byte body `push 0; push 0; push 0; push 1; add ecx, 0xa4; call sub_5975E0; retn`, the sole caller at `0x0050eb14` in `MapPane::CreateEffectObjectPane`, no table/pointer route to `0x005388a0`, and the inherited `+0xa4` TimerHandler adjusted-view receiver. The child now emits `void EffectObjectPane::StartIdleTimer() { TimerHandler::ScheduleTimer(1, 0, 0, 0); }` while keeping event id `1` literal until an original constant name is proven.
- 2026-06-29 B015 source-quality implementation resolves [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md) as marker-covered source-declared/generated-binary RTTI/vtable data for this class. Current MCP sessions `agent_b009_0002my_20260628` and `07c55da0` confirm the `0x006205f8` EffectObjectPane RTTI start, primary view `0x006205fc`, inherited `+0xa0` view `0x00620674`, inherited `+0xa4` view `0x006206a4`, constructor/destructor/scalar-destructor vptr-store parity, and `0x006206ac` BowGauge successor boundary. This support text does not use Wave2/Wave3/simroot/recovered-source output as UID000351 evidence.

## Open Questions

- Whether `EffectObjectPane` originally lived in `render/Effects.cpp`, `map/ObjectPane.cpp`, or a small `EffectObjectPane.cpp` companion. Current file route remains [UID:0000IZ][Effects](by-file/Effects.md), and UID0001D9's parent split/container status no longer depends on resolving the exact original file split.
- Several local structs in the generated body should become named private structs or fields once layout evidence is reviewed.
- The render-context overlay plumbing used by `RenderEffect` should be reviewed with active MapPane/render-context globals before an exact render child emits source.
- Final source-facing names for the five missing exact child methods remain child-page work. The aggregate/exact-child emission policy is now resolved: UID0001D9 is non-emitting, while exact method children own source or method-specific no-code proofs.

## Reconstruction State

- `EffectObjectPane` remains attached to [UID:0000IZ][Effects](by-file/Effects.md). The file parent is `90/88`, so the class-to-file relationship clears the strict gate while final source granularity remains below final-audit confidence.
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) is a non-emitting split/container page at `88/91`, with blank formal C++ and blank emitter. It preserves current session `60724697` evidence for function boundaries, xrefs, callees, padding, constructor/update/render/bounds decompiles, generated state, and negative ownership evidence. It should not emit monolithic parent C++.
- Exact source-declared/generated-binary children now attach directly to this class when they individually clear `85/85`: [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md), [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md), and [UID:000382][0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor](by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md). UID000351 now uses a formal covered-by marker because the RTTI/vtable bytes are regenerated from this class declaration and virtual methods, not handwritten as table source.
- Class-level source remains formal comment-only because full class declaration, frame descriptor field names, render-context ownership, pool/scalar deleting wrapper declaration style, and final source module split still need a coordinated final-source audit. Exact child C++ is allowed where child pages clear the gate: [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) emits the source-ready idle-timer method, [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) owns the exact loop accessor, and [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md) now emits the empty ordinary destructor body. Future exact children should own constructor, bounds, frame-bounds, update/timer, and render method bodies.

## 2026-07-04 B010 UID0001D9 Split/Container Callback

B010 applied the accepted UID0001D9 report: the parent core page is now `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal C++. Current MCP session `60724697` revalidated server health, seven in-range function starts plus successor IsLooping, xrefs, callees, padding bytes, and decompiles for constructor, bounds, frame-bounds, update/timer handler, and render helper. The callback preserved negative evidence rejecting monolithic parent C++, MapPane ownership, EffectObjImageLib ownership, TimerMgr/TimerHandler ownership, AttachedObjectPane ownership, raw labels, and generated/simroot decompiler names.

No child pages were created in this callback. The missing exact children remain a supervisor-scoped follow-up: `EffectObjectPaneConstructor`, `EffectObjectPaneUpdatePosition`, `EffectObjectPaneGetFrameBounds`, `EffectObjectPaneUpdateEffectAnimation`, and `EffectObjectPaneRenderEffect`.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md)
- [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md)
- [UID:000382][0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor](by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md)
- [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md)
- [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal class-level output is intentionally comment-only. Current MCP and by-* evidence support the EffectObjectPane source route through the Effects family, exact child methods, the vtable/RTTI child, and static pool storage, but do not yet prove a safe full class declaration with constructor frame descriptor fields, render-context ownership, pool declaration spelling/linkage, scalar deleting wrapper policy, and final source split.

The callback updates the child disposition matrix: [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) owns its first-draft `StartIdleTimer` body; [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) owns the loop accessor; [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md) now emits the exact empty ordinary destructor body; [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md) remains a covered-by marker; and [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md) remains formal comment-only static storage.

## Changes

- 2026-07-15 B004 UID0003TG accepted source-quality callback:
  - Preserved `85/86`, owner/emitter UID0000IZ, reconstructable state, comment-only class formal, source route, method/layout inventory, and all unrelated evidence.
  - Resolved only byte `+0x14e` as inferred `m_timerExtensionLocked` with constructor-zero, true-blocks-replacement polarity, bounded no-observed-nonzero-writer evidence, adjacent-field distinctions, UID0003TG consumer semantics, compiler/source boundary, and rejected aliases. No class declaration, score, metadata, or unrelated formal changed.

- 2026-07-15 Agent-B005 UID0003TE callback:
  - Added the coordinate-effect reuse consumer for `m_effectId` and `IsLooping()`, exact reverse row-bucket scan/match limits, and null-target row-before-column creation relationship.
  - Corrected the UID0003TF constructor contract wording from column/row to row/column while preserving `85/86`, the complete comment-only formal block, class ownership, layout evidence, and declaration caveat.

- 2026-07-15 B001 UID0003TF accepted source-quality callback:
  - Preserved `85/86`, UID0000IZ owner/emitter, comment-only class formal, existing layout, current method union, and all unrelated effect evidence.
  - Added the exact typed constructor contract, `+0x128/+0x12c..+0x14e` state, ordinary-new/pool-lowering boundary, primary/secondary registration, timer-event relationship, and MapPane-versus-EffectObjectPane ownership split.
  - Corrected the `0x005388c0` current source role to `UpdatePosition` and retained `GetEffectBounds` only as a superseded historical label.

- 2026-07-14 B005 UID00037V support synchronization: resolved byte `+0x14d` as the late/after-living secondary-effect render selector from UID0004QY's two complementary list-pass predicates; preserved the stripped-name caveat, score, route, and formal block.

### 2026-06-29 - B015 UID000351 Vtable Marker Implementation

- [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md) changed from `85/88` to `88/92`, owner/emitter still this class, with a formal covered-by marker instead of a handwritten table.
- Summary/evidence: current MCP-backed support records the exact EffectObjectPane RTTI/vtable range, primary and inherited `+0xa0`/`+0xa4` adjusted views, constructor/destructor/scalar-destructor store parity, slot-target liveness, and BowGauge successor boundary. The stale Wave3/simroot recovered-source status text was historicalized; UID000351 support does not cite Wave2/Wave3/simroot/recovered-source output as evidence.
- Class-level formal output remained withheld at that time. The UID000351 marker only resolves the exact vtable/RTTI child emission policy; frame descriptor names, render-context ownership, pool/scalar wrapper declaration style, broader class layout, and final source-module split remain class-wide blockers. B006 2026-06-30 now records a comment-only class-level block.

### 2026-06-25 - B002 StartIdleTimer Source-Quality Implementation

- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) changed from `86/90` to `89/92`, owner/emitter unchanged at this class.
- Summary/evidence: the method table now treats `0x005388a0-0x005388b4` as source-ready inferred `StartIdleTimer`, not merely a candidate. The accepted child C++ calls `TimerHandler::ScheduleTimer(1, 0, 0, 0)` through the inherited `+0xa4` TimerHandler adjusted view. Current MCP session `80de0a67` preserved the exact range/body, sole MapPane creation caller, no pointer/table route, raw `int` versus source `void` rationale, stale BackPane rejection, and the decision to keep event id `1` literal.
- Class-level formal output remained withheld after that child-specific method emission; it did not resolve broader class declaration/layout/source-split blockers. B006 2026-06-30 now records a comment-only class-level block.

### 2026-05-28 - Corrected Core Range Endpoint

- What existed before: the core range and `RenderEffect` row ended at `0x00538ba9`.
- What changed: both now end at IDA exclusive end `0x00538baa`.
- Why: IDA MCP function review shows `sub_538AF0` ending at `0x00538baa`; byte `0x00538ba9` belongs to `RenderEffect`, while `0x00538baa-0x00538bb0` is alignment.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/80`.
  - Summary/evidence: runtime effect-pane role, constructor/bounds/frame/update/render/destructor methods, image-lib and lighting relationships, open source-module questions, and corrected endpoint are documented; remaining work is detailed layout review and render-context ownership.

### 2026-06-01 - Core Child Functions Completed

- What existed before: the class method table omitted the modeled destructor-style body at `0x00538880` and left the `0x005388a0` timer helper as a generated BackPane caveat elsewhere.
- What changed: the table now includes both child methods, and the class is attached to [UID:0000IZ][Effects](by-file/Effects.md) as reconstructable.
- Why: IDA MCP decompilation of the only caller constructs an `EffectObjectPane`, inserts that same object, then calls `0x005388a0`; neighboring vtable/destructor evidence ties `+0xa4` to the EffectObjectPane subobject layout.
- Completion/confidence score update: existed before as `74/80`; updated to `80/84` because core child coverage, caller evidence, and timer ownership are now resolved. Confidence remains below final-audit level pending field-name and source-file split cleanup.

### 2026-06-11 - Batch233 Direct-Parent Repair

- Before: `80/84`; exact children [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md), [UID:000382][0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor](by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md), and [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md) were gated by the class score.
- After: `85/86`; the class now clears the strict direct-parent gate while staying below final-source/C++ emission confidence.
- Summary/evidence: live IDA MCP reconfirmed all core method boundaries, scalar deleting destructor and adjustor references, vtable-store parity across constructor/non-deleting destructor/scalar destructor, static pool xrefs through constructor/allocation/unwind/destructor/cleanup paths, and the MapPane object-setup caller that constructs and starts the same object pointer.

### 2026-06-17 - B001 Destructor Source-Quality Reanalysis

- [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md) is now `86/91` and source-facing as `EffectObjectPane::~EffectObjectPane()`.
- Summary/evidence: B001 rechecked no direct xrefs, raw VA/RVA pointer absence, constructor/scalar-destructor vtable parity, scalar deleting destructor pool-return contrast, inherited AttachedObjectPane tail-jump ownership, and adjacent timer-helper use of the `+0xa4` adjusted handler view. Formal class source remains comment-only/deferred to a coordinated class source pass.

### 2026-06-18 - B003 IsLooping Source-Quality Reanalysis

- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) is now routed to this class instead of `LivingObjectPane`.
- Summary/evidence: raw PE/Capstone checks and existing IDA-backed docs show the seven-byte accessor returns `+0x14c`, while all six callers compare the child `+0x148` effect descriptor id before calling it. Constructor/timer evidence identifies `+0x14c` as loop/reuse-active state on `EffectObjectPane`, so the old `LivingObjectPaneGetEntityId` label is rejected.

### 2026-06-20 - B007 MapPane RequestObjectEffect Support

- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) now uses this class's current field names in first-draft C++: `m_effectId` for the copied `EffectInfo::effectKeyOrId` at `+0x148` and `m_looping` through `IsLooping()` at `+0x14c`.
- Ownership boundary unchanged: MapPane owns the request/create/reuse decision, while `EffectObjectPane` owns the runtime pane layout, loop accessor, timer subobject, and rendering/update methods.
