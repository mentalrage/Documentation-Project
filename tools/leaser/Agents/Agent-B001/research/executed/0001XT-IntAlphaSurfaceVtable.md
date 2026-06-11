# 0001XT IntAlphaSurfaceVtable Ownership Research

Revision: B001-003 / B001-004 audit / supervisor override active recheck / inference guidance review / finalized-top-format, 2026-06-08

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0001XT] `by-type/by-vtable/IntAlphaSurfaceVtable.md`
- Current recommendation: assign [UID:0001XT] to [UID:00006K] `by-class/IntAlphaSurface.md`.
- Recommended status/classification: RTTI-backed class vtable artifact; source-authored/reconstructable type metadata owned by the `IntAlphaSurface` class page.
- Confidence: `82/100` for parent assignment; RTTI/class identity confidence `90/100`; vtable slot/boundary confidence `94/100`.
- Concrete next action: A-agent or supervisor should set [UID:0001XT] `AUTOGEN_PARENT_UID` to [UID:00006K] if current lease/status permits, and include the RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec` in the target page evidence.
- Report state: final for B001 ownership recommendation; follow-up required by A-agent/supervisor to apply the parent. Not blocked.

## Supporting Research

## Target

- Target UID: `0001XT`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\IntAlphaSurfaceVtable.md`
- Current documented score: `COMPLETION:85`, `CONFIDENCE:88`
- Current autogen parent: blank
- Current supervisor classification/context: Batch 124 raised the page from `82/87` to `85/88` but left it `reviewed-85-but-ownership-unknown` because vtable stores point through the AlphaMaskSurface constructor/helper/view path while virtual targets are provisional IntAlphaSurface release/destructor methods.

## Executive Recommendation

Assign [UID:0001XT] `IntAlphaSurfaceVtable` to [UID:00006K] `by-class/IntAlphaSurface.md`.

Confidence: `82/100`.

The decisive ownership signal is live IDA RTTI attached immediately before the vtable. IDA shows `0x006112e8` points to the complete object locator `??_R4IntAlphaSurface@@6B@`, which points to type descriptor `??_R0?AVIntAlphaSurface@@@8` and class hierarchy descriptor `??_R3IntAlphaSurface@@8`. The vtable slots at `0x006112ec` and `0x006112f0` point to the `IntAlphaSurface` scalar deleting destructor and release slot. Constructor/view stores through the `AlphaMaskSurface`-documented region are important, but they are object-construction writes of this same vtable, not stronger evidence than the vtable's own RTTI identity.

The best forced fallback is [UID:0000K8] `by-file/IntAlphaSurface.md` if type pages must attach to a by-file parent. The better direct semantic parent is the class page [UID:00006K], which already attaches to [UID:0000K8].

Do not create a new source owner for this target. Existing `IntAlphaSurface` and `AlphaMaskSurface` source nodes already model the split, and live RTTI makes the vtable's class identity stronger than a new generic `AlphaSurfaceVtable` or `SurfaceVtable` grouping.

B001-004 audit note: this report does not recommend a new owner, so the new-file contents mandate does not apply as an active recommendation. The rejected new/merged-owner option below still lists likely full contents and explicit exclusions so future source-tree refactors have a scoped evidence trail.

## B001 Supervisor Override Active Recheck

Fresh read-only IDA MCP `py_eval` on 2026-06-08 reconfirmed the direct class-identity evidence. The vtable at `0x006112ec` is named `off_6112EC`; the preceding locator pointer at `0x006112e8` points to `0x00641e9c` named `??_R4IntAlphaSurface@@6B@`; the complete object locator points to type descriptor `0x006744ec` named `??_R0?AVIntAlphaSurface@@@8` and class hierarchy descriptor `0x00641eb0` named `??_R3IntAlphaSurface@@8`. The printable type descriptor bytes include `.?AVIntAlphaSurface@@`.

The slot and store evidence also reconfirmed the recommendation: slot `0x006112ec` points to `0x00463270` (`sub_463270` destructor), slot `0x006112f0` points to `0x00462260` (`sub_462260` release), slots `0x006112f4` and `0x006112f8` are zero, and `0x006112fc` starts unrelated following data. Vtable stores occur at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`, but those stores are construction/destruction writes of the IntAlphaSurface vtable, not evidence for an AlphaMaskSurface owner.

This override pass leaves the active recommendation unchanged and stronger: assign [UID:0001XT] to [UID:00006K] `by-class/IntAlphaSurface.md`. Do not defer for original-source proof and do not create a new vtable grouping; live RTTI is the direct owner signal.

## Inference Research Guidance Check

Applied `Agent-B001\inference_research.md` on 2026-06-08. A read-only IDA MCP string/segment breadcrumb scan found no `.pdb`, `RSDS`, `NB10`, `.cpp`, or `.cxx` strings and no debug/PDB segment. That means this report still cannot prove the original physical source file from compilation-unit metadata. The recommendation is intentionally a class/type ownership recommendation, not a claim that a standalone original `IntAlphaSurface.cpp` is proven.

Evidence ladder classification:

- Confirmed binary facts: the vtable's complete object locator, type descriptor, and class hierarchy descriptor all name `IntAlphaSurface`; the two live slots point to the documented destructor/release methods; store xrefs write this vtable into surface objects during construction/view/destruction paths.
- Very strong class-owner inference: [UID:00006K] `IntAlphaSurface` is the direct semantic parent for the vtable artifact because RTTI is ABI metadata attached to the vtable itself.
- Medium source-file inference: [UID:0000K8] `by-file/IntAlphaSurface.md` remains the best file-level fallback, but physical source-file split with AlphaMaskSurface-family code is still not confirmed.
- Weak evidence deliberately rejected: constructor/view stores in AlphaMaskSurface-documented ranges are construction sites, not stronger ownership evidence than the vtable's own RTTI.

Counter-evidence checked: AlphaMaskSurface and AlphaMaskSurface file docs explain real nearby constructor/view-helper activity, but no vtable slot or RTTI record names AlphaMaskSurface; no debug/source metadata proves a different file; neighboring `0x004632c0` is excluded. Next verification that would change confidence: matching PDB/linker-map source ownership, or corrected class/file docs proving IntAlphaSurface is intentionally declared inside an AlphaMaskSurface source owner while retaining IntAlphaSurface as the vtable's class parent.

## IDA MCP Evidence

Live IDA MCP evidence from 2026-06-08:

- Vtable base: `0x006112ec`, IDA name `off_6112EC`.
- Vtable locator pointer at `0x006112e8`: dword `0x00641e9c`, IDA name `??_R4IntAlphaSurface@@6B@`.
- Slot `0x006112ec`: dword `0x00463270`, IDA function `sub_463270`, documented as `IntAlphaSurface::ScalarDeletingDestructor`.
- Slot `0x006112f0`: dword `0x00462260`, IDA function `sub_462260`, documented as `AlphaSurfaceReleaseOwnedPixels` / `IntAlphaSurface::ReleaseOwnedPixels`.
- Slots `0x006112f4` and `0x006112f8`: both zero.
- `0x006112fc` transitions to unrelated following data (`0x3fe00000`), so the confirmed vtable payload is two live slots plus two null dwords.

RTTI details from live IDA:

- Complete object locator `0x00641e9c` is named `??_R4IntAlphaSurface@@6B@`.
- COL `+0x0c` points to `0x006744ec`, named `??_R0?AVIntAlphaSurface@@@8`.
- The type descriptor printable bytes contain `.?AVIntAlphaSurface@@`.
- COL `+0x10` points to `0x00641eb0`, named `??_R3IntAlphaSurface@@8`.
- The class hierarchy descriptor has one base-class entry: `??_R1A@?0A@EA@IntAlphaSurface@@8`, whose type descriptor is also `??_R0?AVIntAlphaSurface@@@8`.

Function boundary facts:

- `0x00462120` / `0x0046212c` / `0x00462160`: no IDA function object.
- `0x00462170-0x00462227`: `sub_462170`, active constructor/helper that writes `off_6112EC`.
- `0x00462260-0x00462282`: `sub_462260`, release slot body.
- `0x00462320-0x004623b5`: `sub_462320`, clipped view helper.
- `0x004623c0-0x00462514`: `sub_4623C0`, view initializer/helper, also owns the EH cleanup tail chunk that contains `0x00462237`.
- `0x00463270-0x004632b1`: `sub_463270`, scalar deleting destructor.
- `0x004632c0-0x0046330b`: separate neighboring function, already excluded from this vtable/class family.

Vtable base write xrefs:

| Store | IDA function | Meaning |
| --- | --- | --- |
| `0x0046212c` | no function | raw/default constructor-shaped block writes `off_6112EC` into `this + 0x00` |
| `0x0046217b` | `sub_462170` | active width/height constructor/helper writes `off_6112EC` |
| `0x00462237` | tail chunk of `sub_4623C0` | EH cleanup restores `off_6112EC` before releasing owned pixels |
| `0x00462415` | `sub_4623C0` | view initializer writes `off_6112EC` into destination view object |
| `0x0046327a` | `sub_463270` | destructor resets/restores `off_6112EC` before release/delete logic |

Slot target xrefs:

- `xrefs_to 0x00463270` reports the vtable slot at `0x006112ec`.
- `xrefs_to 0x00462260` reports the vtable slot at `0x006112f0`.
- No direct code callers were observed for either virtual target, which is expected for vtable-dispatched release/destructor methods.

Representative store-window observations:

- Raw `0x0046212c`: writes `off_6112EC`, clears `+0x14/+0x18/+0x1c/+0x20`, sets byte `+0x24` to `1`, and initializes bounds via `sub_4B7C50`.
- `0x0046217b` in `sub_462170`: writes `off_6112EC` at constructor entry, then follows width/height allocation setup.
- `0x00462415` in `sub_4623C0`: writes `off_6112EC` into a destination view object, initializes fields, then builds full/clipped non-owning view state.
- `0x0046327a` in `sub_463270`: writes `off_6112EC`, tests ownership byte `+0x24`, frees pixel pointer `+0x14` if owned/non-null, clears it, then conditionally deletes object storage.

## Documentation Evidence And IDA Status

Existing documentation is treated as prior inference, not ground truth.

- [UID:0001XT] `by-type/by-vtable/IntAlphaSurfaceVtable.md` documents the vtable address, slot targets, store xrefs, and ownership uncertainty. IDA confirms the slot values, store xrefs, null slots, function boundaries, and neighboring `0x004632c0` exclusion. IDA strengthens the direct `IntAlphaSurface` case through RTTI evidence that the target page mentions only indirectly.
- [UID:00006K] `by-class/IntAlphaSurface.md` is scored `85/89`, reconstructable, and attached to [UID:0000K8] `by-file/IntAlphaSurface.md`. IDA confirms its vtable RTTI, destructor/release slot, active constructor/helper, raw default-constructor caveat, and view-helper stores. IDA leaves final source split with `AlphaMaskSurface` partly uncertain, but does not leave the vtable class identity uncertain.
- [UID:0000K8] `by-file/IntAlphaSurface.md` is scored `85/88` with path `NexusTK/render/`. IDA confirms this is a plausible file/source node for the vtable, destructor, release slot, and related constructor/view helpers. IDA does not prove the original source had a standalone `IntAlphaSurface.cpp`.
- [UID:00000C] `by-class/AlphaMaskSurface.md` is scored `84/89` and attached to [UID:0000HF]. IDA confirms many functions documented under AlphaMaskSurface write the same vtable. IDA contradicts using that fact alone as direct vtable ownership because the RTTI for the vtable is `IntAlphaSurface`, not `AlphaMaskSurface`.
- [UID:0000HF] `by-file/AlphaMaskSurface.md` is scored `82/89`, path `NexusTK/render/`, and documents the alpha-mask surface/blitter family. IDA confirms this file as the broader alpha-surface helper family, but its score is below the direct parent completion gate and the vtable's RTTI does not name AlphaMaskSurface.
- [UID:0001TP] `AlphaMaskSurfaceLayout` is attached to `AlphaMaskSurface` and documents the shared object layout. IDA confirms the offsets. This supports shared layout, not vtable ownership by AlphaMaskSurface.
- [UID:0000TX] `AlphaSurfaceReleaseOwnedPixels_00462260.md` is attached to [UID:0000K8] `IntAlphaSurface`. IDA confirms slot-1 vtable-only identity and owned-pixel release behavior.
- [UID:0000YP] `0x00463270-0x004632b1.IntAlphaSurface.md` is attached to [UID:00006K] `IntAlphaSurface`. IDA confirms the destructor slot and class-local teardown behavior.
- [UID:0002NM] `0x004623c0-0x00462514.InitAlphaSurfaceView.md` is attached to [UID:0000HF] `AlphaMaskSurface`, but explicitly says final split versus `IntAlphaSurface` is provisional. IDA confirms it writes the IntAlphaSurface vtable into a destination view object.
- [UID:0000OC] `Surface.md` is a broader `NexusTK/render/Surface.cpp` review bucket. IDA supports it for generic surface/presentation helpers, but not for this class-specific RTTI-backed vtable.

## Ranked Ownership Analysis

### 1. [UID:00006K] `by-class/IntAlphaSurface.md`

Recommendation rank: best direct parent.

Evidence for:

- IDA RTTI immediately before the target vtable names `IntAlphaSurface`: `??_R4IntAlphaSurface@@6B@`, `??_R0?AVIntAlphaSurface@@@8`, and `??_R3IntAlphaSurface@@8`.
- The vtable's live slots point to the two methods already documented as IntAlphaSurface release/destructor behavior: `0x00463270` and `0x00462260`.
- The class page already owns the exact destructor child [UID:0000YP] and is scored `85/89`, clearing the direct parent gate.
- The release-slot by-item [UID:0000TX] is already attached to the IntAlphaSurface file node, consistent with this class ownership.
- A vtable is a class/type declaration artifact; direct class ownership is more semantically precise than file ownership when a class page exists and clears the gate.

Evidence against / uncertainty:

- Several vtable stores occur inside ranges currently documented under `AlphaMaskSurface`, including the active constructor/helper at `0x00462170` and the view initializer at `0x004623c0`.
- Existing docs warn that the source split between IntAlphaSurface and AlphaMaskSurface remains provisional.
- The original source may have placed `IntAlphaSurface` declarations in `AlphaMaskSurface.h/.cpp` rather than a standalone `IntAlphaSurface.cpp`.

Conclusion: despite source-file uncertainty, the vtable's direct class/type owner is `IntAlphaSurface`. Constructor stores are normal consequences of constructing objects with this vtable and do not outweigh RTTI.

Confidence: `82/100`.

### 2. [UID:0000K8] `by-file/IntAlphaSurface.md`

Recommendation rank: best file-level fallback.

Evidence for:

- The file page is scored `85/88` and path-projected to `NexusTK/render/`.
- It already proposes the destructor, release slot, view initializer, active constructor/helper, raw constructor-shaped block, and vtable as contents or near-family evidence.
- IDA RTTI and slot targets support the `IntAlphaSurface` name more strongly than `AlphaMaskSurface` for this vtable.

Evidence against / uncertainty:

- A by-file page is less direct than a class page for a vtable artifact.
- The original source file split may have folded IntAlphaSurface into `AlphaMaskSurface.cpp` or a shared render surface source; the file page itself preserves that caveat.

Conclusion: use this only if tooling policy requires type pages to parent to by-file rather than by-class. Otherwise [UID:00006K] is the better direct owner.

Confidence: `76/100`.

### 3. [UID:00000C] `by-class/AlphaMaskSurface.md`

Recommendation rank: plausible but rejected as direct vtable parent.

Evidence for:

- IDA confirms the active constructor/helper at `0x00462170` writes `off_6112EC`.
- IDA confirms the raw/default constructor-shaped block at `0x00462120` writes `off_6112EC`.
- IDA confirms `sub_4623C0` view initialization writes `off_6112EC` at `0x00462415`.
- The shared object layout [UID:0001TP] is currently attached to `AlphaMaskSurface`.

Evidence against:

- The class page is `84/89`, below the `85/85` direct parent gate for the target as currently scored.
- The vtable RTTI does not name AlphaMaskSurface; it names IntAlphaSurface.
- Constructor/view writes prove the function constructs or initializes an object with this vtable, not that the vtable declaration belongs to AlphaMaskSurface.
- Existing documentation explicitly marks the `IntAlphaSurface` relationship as provisional, so using AlphaMaskSurface would preserve the old ambiguity instead of resolving it.

Conclusion: strong family context and possible source-file colocation, but not the best direct vtable owner.

Confidence: `48/100`.

### 4. [UID:0000HF] `by-file/AlphaMaskSurface.md`

Recommendation rank: broader file-family fallback, rejected as direct parent now.

Evidence for:

- IDA confirms this file's documented constructor/view/helper ranges are the most active writers of the target vtable.
- The proposed source tree lists `render/AlphaMaskSurface.cpp` and says it may include `IntAlphaSurface` pending constructor/caller recovery.
- The alpha-mask file page owns many related helpers and the POD buffer-view layout.

Evidence against:

- The file page is `82/89`, below the direct parent completion gate.
- Vtable RTTI and slot targets point to IntAlphaSurface.
- Parent assignment to this file would obscure the class-specific RTTI signal and conflict with already assigned IntAlphaSurface destructor/release ownership.

Conclusion: plausible final physical `.cpp` colocation, not the direct type owner for [UID:0001XT].

Confidence: `45/100`.

### 5. [UID:0000OC] `by-file/Surface.md`

Recommendation rank: rejected broad owner.

Evidence for:

- Surface is a valid render-wide helper bucket and source-tree node for shared render/presentation functions.
- AlphaMaskSurface and IntAlphaSurface are documented as nearby specialized surface modules.

Evidence against:

- The target is not a generic callback table or broad render helper; it has exact class RTTI.
- Surface.cpp is intentionally a migration review bucket for generic surface code, not a proof that every render surface type/vtable belongs there.
- Assigning a class vtable to Surface would erase the strong `IntAlphaSurface` RTTI and slot evidence.

Conclusion: not a direct owner.

Confidence: `20/100`.

### 6. New shared `AlphaSurfaceTypes`, `AlphaSurfaceRuntime`, or merged `AlphaMaskSurfaceAndIntAlphaSurface` owner

Recommendation rank: considered but not recommended.

Evidence for:

- The constructor/view/helper stores and layout are shared across docs named AlphaMaskSurface and IntAlphaSurface.
- A real original source file could have declared both classes and helper functions in one `AlphaMaskSurface.cpp` or shared alpha-surface header.
- The existing file split is explicitly provisional.

Evidence against:

- Existing project structure already has both `AlphaMaskSurface.cpp` and `IntAlphaSurface.cpp`, so a new owner would duplicate rather than clarify current modeling.
- IDA provides exact RTTI for `IntAlphaSurface`, making a new class/type owner unnecessary for the vtable itself.
- The broad contents of a merged owner are already documented as the current [UID:0000HF] `AlphaMaskSurface` plus [UID:0000K8] `IntAlphaSurface` split; the open question is physical source colocation, not a missing conceptual owner.

If a new/merged owner were ever created, likely contents would include:

- [UID:0000HF] `by-file/AlphaMaskSurface.md`, source path `NexusTK/render/AlphaMaskSurface.cpp`
- [UID:0000K8] `by-file/IntAlphaSurface.md`, source path `NexusTK/render/IntAlphaSurface.cpp`
- [UID:00000C] `by-class/AlphaMaskSurface.md`
- [UID:00006K] `by-class/IntAlphaSurface.md`
- [UID:0001XT] `by-type/by-vtable/IntAlphaSurfaceVtable.md`, `0x006112ec`
- [UID:0001TP] `by-type/by-struct/AlphaMaskSurfaceLayout.md`
- [UID:0001TQ] `by-type/by-struct/AlphaSurfaceBufferView.md`
- [UID:0000YK] `by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md`
- [UID:0000YL] `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
- [UID:0000YM] `by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md` as compiler-generated cleanup, not source method
- [UID:0000TX] `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`
- [UID:0000U3] `by-item/BuildClippedAlphaSurfaceView_00462320.md`
- [UID:0002NM] `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`
- [UID:0000YN] `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`
- [UID:0000YO] `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`
- [UID:0000YP] `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`

Items that should not belong to that new/merged owner:

- [UID:0000YQ] `0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`, because IDA ties it to vtable `0x00612574` and application error-state cleanup, not `off_6112EC`.
- Generic [UID:0000OC] `Surface.md` callback/presentation helpers, because they are broader render infrastructure with different globals/callback tables.
- Asset library consumers such as `LightObjImageLib`, `MonsterImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, and `NewHumanImageLib`; IDA caller evidence shows they consume alpha-surface helpers but do not own the vtable.

Conclusion: no new owner is needed for this target. If the project later merges files, do it as a broader render-source refactor, not as a prerequisite for assigning [UID:0001XT].

Confidence for creating a new owner now: `25/100`.

## Negative Evidence

- No IDA evidence shows an `AlphaMaskSurface` RTTI locator or type descriptor for `0x006112ec`.
- No vtable slot points to an AlphaMaskSurface-named method; the live slots point to the IntAlphaSurface destructor/release pair.
- No direct code callers target `0x00463270` or `0x00462260`; both are vtable-only, reinforcing type ownership rather than feature-callsite ownership.
- The only evidence favoring AlphaMaskSurface is vtable stores in constructor/view code and current documentation naming for those functions. That is weaker than RTTI for direct vtable ownership.
- The neighboring `0x004632c0` function has a different vtable and is already excluded.

## Final Recommendation

Set [UID:0001XT] `by-type/by-vtable/IntAlphaSurfaceVtable.md` `AUTOGEN_PARENT_UID` to [UID:00006K] `by-class/IntAlphaSurface.md`.

Supervisor override wording: this should be applied as a direct parent assignment if current lease/status permits. The only remaining uncertainty is physical original source-file colocation with AlphaMaskSurface-family code, and that uncertainty is not strong enough to block class ownership of the vtable artifact.

Do not create a new owner. Do not assign to [UID:00000C] `AlphaMaskSurface` or [UID:0000HF] `AlphaMaskSurface.md` despite constructor/view stores, because live RTTI names `IntAlphaSurface` and the target slots are the IntAlphaSurface release/destructor pair. Keep the existing file-level caveat that the physical original source may have colocated IntAlphaSurface with AlphaMaskSurface, but use class ownership for this vtable artifact.

Recommended wording for applying agents/supervisor:

```text
Parent [UID:0001XT] IntAlphaSurfaceVtable to [UID:00006K] IntAlphaSurface. Live IDA RTTI at 0x006112e8 points to ??_R4IntAlphaSurface@@6B@ and type descriptor ??_R0?AVIntAlphaSurface@@@8; slots 0/1 point to 0x00463270 and 0x00462260, the documented IntAlphaSurface destructor/release pair. AlphaMaskSurface constructor/view stores are construction sites for the same vtable, not stronger declaration ownership.
```

## Follow-Up Actions

- A-agent or supervisor: apply the parent assignment from [UID:0001XT] to [UID:00006K] if no newer lease/status conflicts exist.
- A-agent: update [UID:0001XT] evidence wording to include the live RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec` because that is the strongest direct owner signal.
- A-agent: keep the source-file split caveat in [UID:0000K8] and [UID:0000HF]; parent assignment to the class does not prove a standalone original `IntAlphaSurface.cpp`.
- A-agent: do not move [UID:0002NM] or [UID:0000YK] solely because this vtable attaches to IntAlphaSurface. Those pages involve constructor/view-helper source placement and need separate source-owner review.
- Supervisor: if a later broader render-source merge is considered, evaluate it as a file/source-tree refactor over the full alpha-surface family listed above, not as a blocker for this vtable assignment.

## Confidence

- Vtable slot/boundary confidence: `94/100`. IDA confirms slot values, null slots, function boundaries, and slot-only xrefs.
- RTTI ownership confidence: `90/100`. IDA confirms the COL, type descriptor, and class hierarchy names for `IntAlphaSurface`.
- Recommendation confidence: `82/100`. The direct class owner is strongly supported; confidence is below 90 only because current docs still have a real unresolved physical source-file split between `IntAlphaSurface` and `AlphaMaskSurface`.
