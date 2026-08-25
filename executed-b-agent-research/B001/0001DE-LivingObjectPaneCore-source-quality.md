** TARGET-REPORT-UID:0001DE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001DE LivingObjectPaneCore Source-Quality Report

Assignment id: `B001-goal2-livingobjectpane-core-source-quality-0001DE-00007B-0000KU-20260618`

Primary target: [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

Report-only output. No by-* documentation, generated source, generated reports, IDA database, or `by-memory/-coverage-report.md` files were edited.

## Finalized Report / Current Recommendation

Recommended supervisor action: convert [UID:0001DE] from a reconstructable/emitting aggregate into a non-emitting mixed split/index.

Recommended metadata for [UID:0001DE]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: the address span `0x0053a110-0x0053d818` is not one source-emitting unit. It contains `LivingObjectPane` methods, exact `LivingObjectPane` child pages, exact nested `LivingObjectPane::BoxRotator` children, raw/no-xref helper-shaped islands, compiler switch/table/alignment bytes, and unrelated object-pane source families (`LightingObjectPane`, `AttachmentAnchorResolver`, `SoundObjectPane`, object-pane companion destructor thunks, `DamageNumberObjectPane`, `EffectObjectPane`, `FlyingObjectPane`, `ItemObjectPane`, `HitBarObjectPane`, `Motion`, `ObjectInfoObjectPane`, `StaticObjectPane`). A single formal C++ block on [UID:0001DE] would either duplicate exact child pages or emit code owned by other classes/files.

[UID:00007B] `LivingObjectPane` and [UID:0000KU] `LivingObjectPane` should remain the class/file roots for exact `LivingObjectPane` children. Do not raise [UID:00007B] above `85/85` from this pass alone: the core helper names are now mostly resolved, but the class declaration and local-player packet-tail/raw starts still cap class-level C++ readiness. [UID:0000KU] can remain `88/85`; add the split-index caveat below but do not change the file path `NexusTK/map/`.

## Evidence Checked

- Read current supervisor and B001 rules, [UID:0001DE], [UID:00007B], [UID:0000KU], and the referenced support pages.
- Checked exact child/support pages:
  - [UID:0002R0] construction/cleanup, [UID:0001DF] attached-object detach registry, [UID:0002R1] animation timer, [UID:0002R2] render-method aggregate, [UID:0003NU]/[UID:0003NV]/[UID:0003NW] render exact children, [UID:0002T6] BoxRotator scalar deleting destructor, [UID:0002R3] LivingObjectPane scalar deleting destructor.
  - [UID:0001KM] local-player split index, [UID:0003VE]/[UID:0003UF]/[UID:0003UG] linked-record helpers, [UID:0003UJ] raw function-key debounce helper, [UID:00030B] `g_lastFunctionKeyTick`.
  - [UID:000233] GM suffix check, [UID:00023H] `this+0x14c` byte accessor, [UID:000357]/[UID:000358] vtable data, [UID:00007C] `LivingObjectPane::BoxRotator`.
  - Timer support [UID:0001K9], [UID:0000F0], [UID:0000F1].
  - Non-owner boundary pages [UID:0001DG], [UID:0001DJ], [UID:0001DN], and [UID:0003HS].
- Checked local raw IDA export JSON under `source-3/core/data/readonly/prewave/exported-functions` for all requested starts and adjacent helper starts.
- Generated a local function inventory for `0x0053a110-0x0053d818` from the export cache.
- Ran a section-aware `.text` rel32 branch scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for requested helper starts. Results:
  - `0x0053a6b0`: direct branches from `0x005058c6`, `0x0050be3b`, `0x005a843a`, `0x005a8515`, `0x005a857a`, `0x005a862a`.
  - `0x0053a9f0`: direct branch from `0x00506052`.
  - `0x0053adb0`: direct branch from `0x0050eafe`.
  - `0x0053ae10`: direct branch from `0x0050eaef`.
  - `0x0053ae90`: direct branch from `0x0050fe38`.
  - `0x0053c070`: direct branches from `0x005a859e`, `0x005a876a`.
  - `0x0053c1d0`: direct branches from `0x0053bf25`, `0x0053c5a3`, `0x005a823d`, `0x005ab17c`, `0x005ab2c5`, `0x005ab3e2`, `0x005ab4dd`, `0x005ab612`, `0x005ab72f`, `0x005ac24e`.
  - `0x0053c290`: direct branch from `0x005a9244`.
  - `0x0053bec0`, `0x0053d7c0`, `0x0053d800`, and `0x0053d810`: no direct branch hits in `.text`; their durable routes are data/vtable refs recorded by the export cache.
  - Additional no-xref helper starts `0x0053ad10`, `0x0053b060`, `0x0053b0e0`, `0x0053b190`, and `0x0053bfa0`: no direct branch hits.

## Heuristic / Inference Reanalysis And Validation

### Aggregate / Split Decision

Best direction: [UID:0001DE] should become a non-emitting split/index, not a source-bearing aggregate.

Evidence:

- [UID:0002R2] already models the correct local policy: it is a non-emitting aggregate for `0x0053bb20-0x0053beb6`, while exact children [UID:0003NU]/[UID:0003NV]/[UID:0003NW] carry the source-bearing render methods.
- [UID:0001KM] already models the analogous local-player policy: a broad mixed neighborhood was converted to a non-emitting split index while exact children carry source ownership.
- [UID:0001DN] already models the analogous destructor-island policy: mixed-owner destructor spans become non-reconstructable split inventories with exact children.
- [UID:0001DE] contains non-Living source families inside its physical address span. The `0x0053c5e0-0x0053c6a1` range belongs to `LightingObjectPane`; `0x0053ca20-0x0053ce3c` belongs to `SoundObjectPane`; `0x0053d660-0x0053d7bd` belongs to `SoundObjectPane` and `StaticObjectPane`; the old `0x00537bc0` candidate is [UID:0003HS] `ItemObjectPane`.

Rejected alternative: keep [UID:0001DE] `RECONSTRUCTABLE:TRUE` with formal C++ blank. That preserves stale generated coverage and leaves the supervisor with a code-entry contradiction: the target is routed and at/near the gate, but its formal C++ cannot be valid because it spans exact children and other owners.

Rejected alternative: emit one large `LivingObjectPane.cpp` draft from [UID:0001DE]. That would duplicate exact children and would incorrectly absorb Lighting/Sound/Static/Item/ObjectInfo/Motion ranges.

Impact: [UID:0001DE] should not be a C++ emitter. Existing exact children and proposed exact children should emit through [UID:00007B], [UID:00007C], or [UID:0000KU] as appropriate.

### Raw Helper Starts And Source-Facing Names

Recommended source-facing names and signatures for the `LivingObjectPane`-owned starts are below. Names are descriptive/source-safe, not claimed as recovered original spellings.

| Range | Recommended name/signature | Evidence and disposition |
| --- | --- | --- |
| `0x0053a6b0-0x0053a6db` | `static unsigned char LivingObjectPane_GetOppositeDirection(unsigned char dir)` or private `OppositeDirection` helper | Pure `__stdcall` helper, no receiver, maps `0->2`, `1->3`, `2->0`, `3->1`, default `2`; six direct callers from MapPane/UserPane animation paths. File-level [UID:0000KU] private helper, not a class method. |
| `0x0053a700-0x0053a8b7` | `void LivingObjectPane::GetRenderBounds(Rect *imageRect, Rect *screenRect) const` | Vtable/data ref `0x006209cc`, one code caller `0x005a885c`; computes image/screen rectangles from sprite config, map state, and cached BoxRotator rect. |
| `0x0053a8c0-0x0053a8fe` | `void LivingObjectPane::GetSpriteConfig(LivingSpriteConfig *out) const` | Copies 68 bytes from `this+0x178..+0x1bc` to caller output; many callers. |
| `0x0053a900-0x0053a9ee` | `bool LivingObjectPane::SetSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)` | Direct callers `0x00505f75`, `0x0051362c`; copies config, cancels timer messages `aDeR` and `iDhC`, optionally calls `TryStepForward` and `PlayAnimation`, invalidates map object. |
| `0x0053a9f0-0x0053aae9` | `void LivingObjectPane::InitializeSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)` | Direct caller `0x00506052`; resets movement/frame/highlight/name-visible fields, schedules frame animation when config kind is animated, sets owner backlink at `+0x1f4`. |
| `0x0053aaf0-0x0053ab1a` | `void LivingObjectPane::SetSpriteAttribute(unsigned char value)` | Writes one field inside the sprite/config block (`this+0x182`) and invalidates when changed. Keep exact semantic name below final source level. |
| `0x0053ab20-0x0053ab3a` | `void LivingObjectPane::SetMovingState(bool moving)` | Writes movement-active byte `+0x1c4`; clears movement-frame byte `+0x1c6` when false. |
| `0x0053ab40-0x0053ad03` | `void LivingObjectPane::DestroyLinkedObjects()` | Deletes/unregisters objects in list fields `+0x170/+0x174`, deletes singleton slots `+0x1d8/+0x1dc/+0x1e0/+0x1e4`, clears linked owner refs, deletes special id `134`, and destroys the two list objects. |
| `0x0053ad10-0x0053ad9f` | `void LivingObjectPane::RawDestroyAttachmentListsOnly()` | Ghidra-only raw helper shape; no IDA name/callers and no direct branch hits. Deletes only list fields `+0x170/+0x174` after unregistering children from the active map. Keep as a raw/no-xref child candidate, not formal C++. |
| `0x0053ada0-0x0053adb0` | `void LivingObjectPane::SetLinkedGroundObject(ObjectPane *pane)` | Direct callers `0x0050e1df`, `0x0051192c`; stores singleton slot `+0x1d8`. Name is high-probability based on existing core docs and the attached-object type-6 singleton. |
| `0x0053adb0-0x0053ae06` | `void LivingObjectPane::InsertType2AttachedObject(AttachedObjectPane *pane)` | Direct caller `0x0050eafe`; de-duplicates entries in list `+0x170` by child object id at `+0x148`/`+0x328` decompiler view, deletes replaced child, inserts new pointer. |
| `0x0053ae10-0x0053ae66` | `void LivingObjectPane::InsertType4AttachedObject(AttachedObjectPane *pane)` | Direct caller `0x0050eaef`; same de-dup/insert behavior for list `+0x174`. |
| `0x0053ae70-0x0053ae80` | `void LivingObjectPane::SetLinkedShadowObject(ObjectPane *pane)` | Direct callers `0x0050e63e`, `0x0050e7b6`, `0x0050ee81`; stores singleton slot `+0x1dc`. |
| `0x0053ae80-0x0053ae90` | `void LivingObjectPane::SetLinkedEpfObject(ObjectPane *pane)` | Direct callers `0x0050efb5`, `0x00512ad7`; stores singleton slot `+0x1e0`, whose cleanup/refresh is gated by `byte_66DA97 == 1`. |
| `0x0053ae90-0x0053aeb4` | `void LivingObjectPane::ReplaceLinkedNameplateObject(ObjectPane *pane)` | Direct caller `0x0050fe38`; deletes the old singleton at `+0x1e4` before storing the new one. High-probability nameplate/attached singleton based on the type-9 singleton role. |
| `0x0053b060-0x0053b0df` | `void LivingObjectPane::RawAddActiveEffect(ObjectPane *effect)` | Raw/no-xref helper; trims active-effect list `+0x1bc` beyond two retained entries, cancels timer state on deleted effects, inserts new effect, and updates current-effect pointer. Do not emit until a route is proven. |
| `0x0053b0e0-0x0053b12b` | `void LivingObjectPane::RawRemoveActiveEffect(ObjectPane *effect)` | Raw/no-xref helper; scans list `+0x1bc` and removes the matching effect. |
| `0x0053b130-0x0053b184` | `void LivingObjectPane::ClearAllEffects()` | Eight direct callers; deletes all entries in active-effect list `+0x1bc` and clears current-effect state. |
| `0x0053b190-0x0053b1a8` | `void LivingObjectPane::RawSetCurrentEffect(ObjectPane *effect)` | Raw/no-xref setter for current-effect pointer `+0x1c0`. |
| `0x0053b1b0-0x0053b1f7` | `void LivingObjectPane::SetHighlightState(bool highlighted)` | 89 callers; toggles byte `+0x1e8`, starts/stops `BoxRotator` state at `+0x1f0`, then invalidates. |
| `0x0053b200-0x0053b272` | `void LivingObjectPane::ShowDamageEffect(int value, short soundId)` | Plays a sound/status cue via `0x0057a5c0`, stores refresh payload at `+0x1f8`, invalidates, and schedules timer event `aDeR` after 120 ms unless the animated human sprite range suppresses it. |
| `0x0053b280-0x0053b35a` | `bool LivingObjectPane::BeginMoveTo(int x, int y, unsigned char facing, short stepCode)` | Cancels forward-step timer, attempts immediate movement, sets facing/movement state, invalidates/schedules movement follow-up. |
| `0x0053b360-0x0053b3c7` | `void LivingObjectPane::SetFacing(unsigned char facing)` | If movement is active, schedules direction-delay event `iDhC`; otherwise stores facing, plays standing animation when animated, and invalidates. |
| `0x0053b3d0-0x0053b6b3` | `void LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing)` | For animated sprites, maps action codes to animation groups. For non-animated sprites, constructs a `Motion`/effect object, maintains the active-effect list, schedules the effect handler, and removes old excess effects. |
| `0x0053b6b3-0x0053b700` | lowered switch/data plus padding | Not an independent source function; belongs to the preceding action helper and alignment before [UID:0002R1]. |
| `0x0053bab0-0x0053bacb` | `void LivingObjectPane::RequestNameplateEffect()` | Direct caller `0x0050fae9`; asks MapPane helper `0x0050e320` for descriptor/effect id `135` tied to this actor id. |
| `0x0053bad0-0x0053bb1d` | `void LivingObjectPane::RemoveSpecialEffect()` | Scans attached list `+0x174` and deletes the child whose object id is `134`. |
| `0x0053bec0-0x0053bf38` | `void LivingObjectPane::SetMapPosition(int x, int y)` | Vtable/data refs only (`0x006209e4`, `0x0062ef74`); updates position fields `+0x100/+0x104`, calls active MapPane relocation helper, invalidates before/after, cancels forward-step timer, refreshes linked objects, and clears movement-active byte. |
| `0x0053bf40-0x0053bf77` | `void LivingObjectPane::ScheduleBoxRotationStep()` | Cancels then schedules event `FBSA` on the embedded timer-handler subobject. |
| `0x0053bf80-0x0053bf91` | `void LivingObjectPane::CancelBoxRotationStep()` | Cancels event `FBSA` through `TimerHandler` wrapper `0x00597610`. |
| `0x0053bfa0-0x0053c070` | `void LivingObjectPane::RawPropagateLinkedObjectMode(int mode)` | Raw/no-xref helper; propagates virtual slot `+0x6c` to singleton/list linked objects but does not invalidate `this`. Keep as child candidate without formal C++. |
| `0x0053c070-0x0053c1c9` | `void LivingObjectPane::SyncPositionToLinkedObjects()` | Direct callers `0x005a859e`, `0x005a876a`; copies owner `x/y` to linked singleton/list objects and calls MapPane relocation helper for list children. |
| `0x0053c1d0-0x0053c286` | `void LivingObjectPane::RefreshAllLinkedObjects()` | Ten direct branches; calls virtual slot `+0x70` on linked singleton/list objects, with EPF singleton gated by `byte_66DA97 == 1`. |
| `0x0053c290-0x0053c367` | `void LivingObjectPane::PropagateLinkedObjectMode(int mode)` | Vtable/data ref `0x006209f8` and direct jump/call from `0x005a9244`; invalidates `this`, then propagates virtual slot `+0x6c` to linked objects. |
| `0x0053c390-0x0053c5da` | `bool LivingObjectPane::TryStepForward()` | Called from sprite/move/timer/settings paths; computes next tile from facing, tests bounds/passability, moves owner and linked objects, refreshes linked objects, returns true when blocked/failed. |
| `0x0053d7c0-0x0053d7f4` | `void LivingObjectPane::BoxRotator::Advance()` | Vtable slot `0x00620974`; reads owner pointer at `[this+4]`, increments owner rotation phase `+0x1ec` modulo four, calls frame handler `0x004b6d30(this, 10)`, invalidates owner. |
| `0x0053d800-0x0053d808` | `void LivingObjectPane::ShowName()` | Vtable slot `0x006209f0`; sets byte `+0x1d1` (`+465`) to `1`. |
| `0x0053d810-0x0053d818` | `void LivingObjectPane::HideName()` | Vtable slot `0x006209f4`; clears byte `+0x1d1`. |

### Field / Layout Naming

Best defensible field names for the core range:

| Offset | Recommended descriptive name | Evidence |
| --- | --- | --- |
| `+0xa4` | `m_timerHandler` or embedded `TimerHandler` view | Constructors install a timer-handler style adjusted vtable; timer handler at `0x0053b830` receives `this+0xa4` and recovers owner with `this-0xa4`. |
| `+0x170` | `m_type2AttachedObjects` | [UID:0001TR] and `0x0053adb0` prove this is the plural list for attached object type `2`; detach helper removes matching objects from this list. |
| `+0x174` | `m_type4AttachedObjects` | Same list behavior for attached object type `4`; `0x0053ae10`, `0x0053bad0`, and detach helper use it. |
| `+0x178..+0x1bc` | `m_spriteConfig` | Constructors copy/default 68 bytes; `GetSpriteConfig` copies exactly this block; sprite/render/animation paths consume it. |
| `+0x1bc` | `m_activeEffects` | List pointer used by active-effect add/remove/clear helpers and action/effect spawning. |
| `+0x1c0` | `m_currentEffect` | Raw setter and active-effect cleanup compare/clear this pointer. |
| `+0x1c4` | `m_isMoving` | Set by `SetMovingState`; movement and sprite config paths test it. |
| `+0x1c5` | `m_facing` | `SetFacing`, animation timer, and render helpers use it as a direction byte. |
| `+0x1c6` | `m_moveFrame` | Cleared when movement stops and advanced by timer `FWdA`. |
| `+0x1c8` | `m_animationFrame` | Animation-frame timer advances it. |
| `+0x1cc` | `m_animationGroup` or `m_animationId` | Used with image-frame lookups during animation. |
| `+0x1d0` | `m_terminalAnimation` or `m_deadState` | Terminal/death animation wrapper writes it; caller-side GM cleanup checks this neighborhood. Keep descriptive, not original. |
| `+0x1d1` | `m_nameVisible` | `ShowName`/`HideName` set/clear byte `+465`. |
| `+0x1d8` | `m_linkedGroundObject` | Singleton type `6`; setter `0x0053ada0`, refresh/sync/cleanup all use it. |
| `+0x1dc` | `m_linkedShadowObject` | Singleton type `7`; setter `0x0053ae70`, refresh/sync/cleanup all use it. |
| `+0x1e0` | `m_linkedEpfObject` | Singleton type `8`; all refresh/cleanup paths gate it on `byte_66DA97 == 1`. |
| `+0x1e4` | `m_linkedNameplateObject` | Singleton type `9`; `0x0053ae90` deletes old object before replacing. |
| `+0x1e8` | `m_highlighted` or `m_selectedHighlight` | `SetHighlightState` toggles this byte and starts/stops BoxRotator. |
| `+0x1ec` | `m_boxRotationPhase` | `BoxRotator::Advance` increments it modulo four. |
| `+0x1f0` | `m_boxRotator` | Constructor stores `??_7BoxRotator@LivingObjectPane@@6B@` here; [UID:00007C]/[UID:000357] confirm nested helper. |
| `+0x1f4` | `m_boxRotator.m_owner` | Constructors store owning `LivingObjectPane *`; `0x0053d7c0` reads `[this+4]`. |
| `+0x1f8` | `m_pendingDamageEffect` or `m_refreshPayload` | `ShowDamageEffect` stores a payload and schedules refresh event `aDeR`. |
| `+0x13eb14` | `m_linkedRecords` | [UID:0003VE] computes `base + index * 0x10` from this pointer. |
| `+0x13eb18` | `m_linkedRecordCount` | [UID:0003VE]/[UID:0003UF]/[UID:0003UG] use it as the count bound. |

Rejected field-name alternative: naming `+0x170/+0x174` as ground/shadow lists. The evidence only proves attached-object type `2` and type `4` plural lists. The ground/shadow/EPF/nameplate names fit the singleton slots `+0x1d8/+0x1dc/+0x1e0/+0x1e4`, not the plural lists.

Rejected field-name alternative: naming `byte_66DA97` as an attachment flag. [UID:0000SW] and [UID:0001TR] show this is the broader EPF/legacy asset-mode selector; the attachment code only consumes it.

### Timer / Generated Name Reanalysis

The current [UID:0001DE], [UID:00007B], [UID:0000KU], and [UID:0001K9] docs are correct to reject generated `SoundManager::CancelTimer` / `SoundManager::CancelPendingTimersExceptEvent` names for `0x00597610` and `0x00597630`. The wrappers load `g_pTimerMgr` and forward to timer-queue removal helpers. `LivingObjectPane` is a timer owner/consumer, not an audio owner.

No support-doc correction is needed for this stale label beyond preserving the warning in [UID:0001DE] after it becomes a split/index.

### BoxRotator Reanalysis

Resolved: `0x0053d7c0-0x0053d7f4` is not a generic LivingObjectPane tail helper. It is the second virtual slot of `LivingObjectPane::BoxRotator`.

Evidence:

- [UID:000357] records vtable slot `0x00620974 -> 0x0053d7c0`.
- Constructors store the BoxRotator vtable at `LivingObjectPane + 0x1f0` and owner pointer at `+0x1f4`.
- The body reads `[this+4]`, increments owner `+0x1ec`, calls `0x004b6d30(this, 10)`, and invalidates owner through virtual slot `+0x20`.

Recommended source form: private nested helper `LivingObjectPane::BoxRotator`, with callback-like method `Advance()` or `OnTimer()`. Keep `LivingObjectPane__BoxRotator` only as a generated/search name.

### Local-Player Tail / Function-Key Reanalysis

Current [UID:0001KM], [UID:0003UJ], and [UID:00030B] conclusions remain valid:

- `0x005a9250-0x005a9307` is function-shaped but not an IDA function start, has no entry xrefs or pointer values, and reads `g_lastFunctionKeyTick` without any known writer.
- Active `UserPane::OnKeyEvent` dispatches function/macro digit keys through `0x005a3ae0`, not through `0x005a9250`.
- The best source-layout inference keeps [UID:00030B] in `LivingObjectPane.cpp` because prewave/Wave3 classify the orphan helper as `LivingObjectPane` and the raw body dispatches through `0x005a4530`.

Impact: local-player raw starts still cap [UID:00007B] class-level C++ readiness. This pass resolves the core [UID:0001DE] split decision but does not make a final class declaration safe.

### `0x00537bc0` Exclusion

Validated: `0x00537bc0-0x00537be9` is [UID:0003HS] `ItemObjectPaneRecordStateUpdate`, not a `LivingObjectPane` accessor.

Evidence:

- [UID:0003HS] records the caller branch in `sub_513310`: the helper is called only from the `object+0xf8 == 0` non-living/item path after the `object+0xf8 == 3` LivingObjectPane path is bypassed.
- The helper writes item fields `this+0x128/+0x12a`, matching `ItemObjectPane`.

No LivingObjectPane support page should re-add `0x00537bc0`.

## Open Questions Resolved Or Remaining

Resolved:

- [UID:0001DE] should not emit formal C++ as an aggregate.
- `0x0053a6b0` is a private/static opposite-direction helper, not padding.
- `0x0053a9f0`, `0x0053adb0`, `0x0053ae10`, `0x0053ae90`, `0x0053c070`, `0x0053c1d0`, and `0x0053c290` are reachable method/helper bodies with the caller evidence listed above.
- `0x0053bec0`, `0x0053d800`, and `0x0053d810` are vtable-routed methods with no ordinary direct branch callers in the local branch scan.
- `0x0053d7c0` is the BoxRotator virtual callback.
- `0x0053ad10`, `0x0053b060`, `0x0053b0e0`, `0x0053b190`, and `0x0053bfa0` are function-shaped raw helpers with no current direct-branch route; they should be documented as raw child candidates, not silently folded into aggregate C++.
- `+0x1d8/+0x1dc/+0x1e0/+0x1e4` are the singleton linked ground/shadow/EPF/nameplate-style fields; `+0x170/+0x174` are plural type-2/type-4 attached-object lists.

Remaining:

- Exact original field names are not proven; use descriptive names above.
- Exact original spellings for the active-effect raw helpers are not proven because they have no entry xrefs.
- [UID:00007B] final class declaration remains blocked by local-player tail/raw starts and the incomplete 524-byte object layout, not by the [UID:0001DE] core split decision.
- Exact final source names for `PlayActionAnimationOrEffect`, `PropagateLinkedObjectMode`, and the active-effect helpers should be refined when their caller-side semantics are audited. The current descriptive names are sufficient for child-page source-quality documentation, but not for a 95+ final class declaration.

## First-Draft C++ Recommendation

Do not populate [UID:0001DE] formal C++.

Target-specific no-code proof:

1. The [UID:0001DE] physical span is mixed-owner. A formal C++ block there would necessarily include methods from `LightingObjectPane`, `SoundObjectPane`, `StaticObjectPane`, `ItemObjectPane`, `Motion`, `ObjectInfoObjectPane`, and other object-pane families that are already routed to different class/file roots.
2. The span already has exact source-bearing children. Emitting parent C++ would duplicate [UID:0002R0], [UID:0001DF], [UID:0002R1], [UID:0003NU]/[UID:0003NV]/[UID:0003NW], [UID:0002T6], and [UID:0002R3].
3. Several in-span helper-shaped starts have no current direct branch, data xref, or IDA function route (`0x0053ad10`, `0x0053b060`, `0x0053b0e0`, `0x0053b190`, `0x0053bfa0`). A parent formal C++ body would invent reachability and public/private placement.
4. The correct source-emitting unit is `NexusTK/map/LivingObjectPane.cpp` through exact child pages and class/file roots, not the broad memory aggregate.

Draft signatures for exact child pages, not for the [UID:0001DE] formal block:

```cpp
struct LivingSpriteConfig;
struct Rect;
class ObjectPane;
class AttachedObjectPane;

static unsigned char OppositeDirection(unsigned char dir);

void LivingObjectPane::GetRenderBounds(Rect *imageRect, Rect *screenRect) const;
void LivingObjectPane::GetSpriteConfig(LivingSpriteConfig *out) const;
bool LivingObjectPane::SetSpriteConfig(const LivingSpriteConfig *config, unsigned char facing);
void LivingObjectPane::InitializeSpriteConfig(const LivingSpriteConfig *config, unsigned char facing);
void LivingObjectPane::SetSpriteAttribute(unsigned char value);
void LivingObjectPane::SetMovingState(bool moving);
void LivingObjectPane::DestroyLinkedObjects();
void LivingObjectPane::SetLinkedGroundObject(ObjectPane *pane);
void LivingObjectPane::InsertType2AttachedObject(AttachedObjectPane *pane);
void LivingObjectPane::InsertType4AttachedObject(AttachedObjectPane *pane);
void LivingObjectPane::SetLinkedShadowObject(ObjectPane *pane);
void LivingObjectPane::SetLinkedEpfObject(ObjectPane *pane);
void LivingObjectPane::ReplaceLinkedNameplateObject(ObjectPane *pane);
void LivingObjectPane::ClearAllEffects();
void LivingObjectPane::SetHighlightState(bool highlighted);
void LivingObjectPane::ShowDamageEffect(int value, short soundId);
bool LivingObjectPane::BeginMoveTo(int x, int y, unsigned char facing, short stepCode);
void LivingObjectPane::SetFacing(unsigned char facing);
void LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing);
void LivingObjectPane::RequestNameplateEffect();
void LivingObjectPane::RemoveSpecialEffect();
void LivingObjectPane::SetMapPosition(int x, int y);
void LivingObjectPane::ScheduleBoxRotationStep();
void LivingObjectPane::CancelBoxRotationStep();
void LivingObjectPane::SyncPositionToLinkedObjects();
void LivingObjectPane::RefreshAllLinkedObjects();
void LivingObjectPane::PropagateLinkedObjectMode(int mode);
bool LivingObjectPane::TryStepForward();
void LivingObjectPane::ShowName();
void LivingObjectPane::HideName();

void LivingObjectPane::BoxRotator::Advance();
```

The raw/no-xref helpers should get documentation child pages before any C++:

```cpp
// Child-page names only; do not emit until reachability/source shape is proven.
void LivingObjectPane::RawDestroyAttachmentListsOnly();
void LivingObjectPane::RawAddActiveEffect(ObjectPane *effect);
void LivingObjectPane::RawRemoveActiveEffect(ObjectPane *effect);
void LivingObjectPane::RawSetCurrentEffect(ObjectPane *effect);
void LivingObjectPane::RawPropagateLinkedObjectMode(int mode);
```

## Exact Supervisor Changes Required

### [UID:0001DE] Metadata And Status

Apply the metadata recommended in the first section.

Replace the `## Status` body with:

```markdown
## Status

- Disposition: reviewed non-emitting mixed split/index for the `0x0053a110-0x0053d818` object-pane neighborhood.
- Entity kind: broad memory-range inventory containing `LivingObjectPane` source methods, exact `LivingObjectPane` child pages, nested `LivingObjectPane::BoxRotator` children, raw/no-xref helper-shaped bodies, compiler alignment/lowered switch data, and unrelated object-pane sibling ranges.
- Source routing: exact `LivingObjectPane` children route through [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) or [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md); `LivingObjectPane::BoxRotator` children route through [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md). Non-Living sibling ranges route to their own class/file roots.
- Rebuild handling: this page is not a source-emitting item. Keep this aggregate C++ blank and reconstruct exact child methods only.
- Confidence: strong for split/index disposition, child/source routing, raw helper inventory, BoxRotator tail resolution, timer-wrapper ownership, and non-Living overlap exclusions; medium for exact original spellings of several helper names and raw/no-xref helper reachability.
```

Replace [UID:0001DE] score rationale with:

```markdown
## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page now classifies the broad span as a non-emitting split/index, records exact existing children, resolves the requested raw/helper/tail starts, separates raw/no-xref helper candidates from routed methods, preserves compiler switch/alignment handling, and excludes Lighting/Sound/Static/Item/ObjectInfo/Motion sibling ranges from LivingObjectPane ownership. Completion is below final because several exact child pages still need to be created/refreshed for individual methods and raw no-xref helpers. |
| Confidence `90` | Local export JSON, current by-* support pages, vtable-data pages, direct branch scan, timer-wrapper docs, and sibling owner pages all support the split decision and most helper names. Confidence is not final because exact original spellings and raw-helper source reachability remain unresolved for a few helper-shaped bodies. |
```

### [UID:00007B] Support Text

No metadata change recommended; keep `85/85`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KU`, `EMITTER_UIDS:0000KU`, blank class C++.

Add this paragraph under `## Boundary Caveats`:

```markdown
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) should be treated as a non-emitting split/index, not as a class-level C++ source block. Exact child pages carry source ownership for individual `LivingObjectPane` methods. The broad span also contains non-Living object-pane sibling ranges and raw/no-xref helper-shaped bodies, so it cannot be used as a final class declaration or method-body source unit.
```

### [UID:0000KU] Support Text

No metadata change recommended; keep `88/85` and path `NexusTK/map/`.

Add this paragraph under `## Boundary Notes`:

```markdown
- Do not emit [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) as one `LivingObjectPane.cpp` block. It is a broad memory split/index. Source-bearing `LivingObjectPane` methods should be split into exact children routed through [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), while nested `BoxRotator` children route through [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md), and non-Living sibling ranges remain with their own object-pane files.
```

### Child Page Creation / Refresh Plan

Existing exact child pages should remain:

| UID | Range | Keep as |
| --- | --- | --- |
| [UID:0002R0] | `0x0053a110-0x0053a6a6` | `LivingObjectPaneConstructionAndCleanup`, owner/emitter [UID:00007B]. |
| [UID:0001DF] | `0x0053aec0-0x0053b011` | `LivingObjectPaneAttachedObjectDetachRegistry`, owner/emitter [UID:00007B]. |
| [UID:0002R1] | `0x0053b700-0x0053baa8` | `LivingObjectPaneAnimationTimer`, owner/emitter [UID:00007B]. |
| [UID:0002R2] | `0x0053bb20-0x0053beb6` | non-emitting render-method split aggregate. |
| [UID:0003NU] | `0x0053bb20-0x0053bd1c` | `LivingObjectPaneRenderFrame`, owner/emitter [UID:00007B]. |
| [UID:0003NV] | `0x0053bd20-0x0053bdb1` | `LivingObjectPaneDrawSpriteFrame`, owner/emitter [UID:00007B]. |
| [UID:0003NW] | `0x0053bdc0-0x0053beb6` | `LivingObjectPaneComputeRenderBounds`, owner/emitter [UID:00007B]. |
| [UID:0002T6] | `0x0053d030-0x0053d053` | `LivingObjectPaneBoxRotatorScalarDeletingDestructor`, owner/emitter [UID:00007C]. |
| [UID:0002R3] | `0x0053d430-0x0053d589` | `LivingObjectPaneScalarDeletingDestructor`, owner/emitter [UID:00007B]. |

Recommended new exact children, with supervisor-assigned UIDs:

| Range | Title | Owner | Emitter | Score |
| --- | --- | --- | --- | --- |
| `0x0053a6b0-0x0053a6db` | `LivingObjectPaneOppositeDirectionHelper` | [UID:0000KU] | [UID:0000KU] | `86/88` |
| `0x0053a700-0x0053a8b7` | `LivingObjectPaneGetRenderBounds` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053a8c0-0x0053a8fe` | `LivingObjectPaneGetSpriteConfig` | [UID:00007B] | [UID:00007B] | `87/89` |
| `0x0053a900-0x0053a9ee` | `LivingObjectPaneSetSpriteConfig` | [UID:00007B] | [UID:00007B] | `87/89` |
| `0x0053a9f0-0x0053aae9` | `LivingObjectPaneInitializeSpriteConfig` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053aaf0-0x0053ab1a` | `LivingObjectPaneSetSpriteAttribute` | [UID:00007B] | [UID:00007B] | `85/87` |
| `0x0053ab20-0x0053ab3a` | `LivingObjectPaneSetMovingState` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053ab40-0x0053ad03` | `LivingObjectPaneDestroyLinkedObjects` | [UID:00007B] | [UID:00007B] | `87/89` |
| `0x0053ad10-0x0053ad9f` | `LivingObjectPaneRawDestroyAttachmentListsOnly` | [UID:00007B] | [UID:00007B] | `84/86` |
| `0x0053ada0-0x0053adb0` | `LivingObjectPaneSetLinkedGroundObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053adb0-0x0053ae06` | `LivingObjectPaneInsertType2AttachedObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053ae10-0x0053ae66` | `LivingObjectPaneInsertType4AttachedObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053ae70-0x0053ae80` | `LivingObjectPaneSetLinkedShadowObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053ae80-0x0053ae90` | `LivingObjectPaneSetLinkedEpfObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053ae90-0x0053aeb4` | `LivingObjectPaneReplaceLinkedNameplateObject` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053b060-0x0053b0df` | `LivingObjectPaneRawAddActiveEffect` | [UID:00007B] | [UID:00007B] | `84/86` |
| `0x0053b0e0-0x0053b12b` | `LivingObjectPaneRawRemoveActiveEffect` | [UID:00007B] | [UID:00007B] | `84/86` |
| `0x0053b130-0x0053b184` | `LivingObjectPaneClearAllEffects` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053b190-0x0053b1a8` | `LivingObjectPaneRawSetCurrentEffect` | [UID:00007B] | [UID:00007B] | `83/86` |
| `0x0053b1b0-0x0053b1f7` | `LivingObjectPaneSetHighlightState` | [UID:00007B] | [UID:00007B] | `87/89` |
| `0x0053b200-0x0053b272` | `LivingObjectPaneShowDamageEffect` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053b280-0x0053b35a` | `LivingObjectPaneBeginMoveTo` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053b360-0x0053b3c7` | `LivingObjectPaneSetFacing` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053b3d0-0x0053b6b3` | `LivingObjectPanePlayActionAnimationOrEffect` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053bab0-0x0053bacb` | `LivingObjectPaneRequestNameplateEffect` | [UID:00007B] | [UID:00007B] | `85/87` |
| `0x0053bad0-0x0053bb1d` | `LivingObjectPaneRemoveSpecialEffect` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053bec0-0x0053bf38` | `LivingObjectPaneSetMapPosition` | [UID:00007B] | [UID:00007B] | `86/90` |
| `0x0053bf40-0x0053bf77` | `LivingObjectPaneScheduleBoxRotationStep` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053bf80-0x0053bf91` | `LivingObjectPaneCancelBoxRotationStep` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053bfa0-0x0053c070` | `LivingObjectPaneRawPropagateLinkedObjectMode` | [UID:00007B] | [UID:00007B] | `84/86` |
| `0x0053c070-0x0053c1c9` | `LivingObjectPaneSyncPositionToLinkedObjects` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053c1d0-0x0053c286` | `LivingObjectPaneRefreshAllLinkedObjects` | [UID:00007B] | [UID:00007B] | `87/89` |
| `0x0053c290-0x0053c367` | `LivingObjectPanePropagateLinkedObjectMode` | [UID:00007B] | [UID:00007B] | `86/89` |
| `0x0053c390-0x0053c5da` | `LivingObjectPaneTryStepForward` | [UID:00007B] | [UID:00007B] | `86/88` |
| `0x0053d7c0-0x0053d7f4` | `LivingObjectPaneBoxRotatorAdvance` | [UID:00007C] | [UID:00007C] | `87/91` |
| `0x0053d800-0x0053d808` | `LivingObjectPaneShowName` | [UID:00007B] | [UID:00007B] | `86/90` |
| `0x0053d810-0x0053d818` | `LivingObjectPaneHideName` | [UID:00007B] | [UID:00007B] | `86/90` |

Compiler/lowered/padding spans to keep non-emitting/ignored under the split index:

- `0x0053a6a6-0x0053a6b0`, `0x0053a6db-0x0053a700`, `0x0053a8b7-0x0053a8c0`, `0x0053a8fe-0x0053a900`, `0x0053a9ee-0x0053a9f0`, `0x0053aae9-0x0053aaf0`, `0x0053ab1a-0x0053ab20`, `0x0053ab3a-0x0053ab40`, `0x0053ad03-0x0053ad10`, `0x0053ad9f-0x0053ada0`, `0x0053ae06-0x0053ae10`, `0x0053ae66-0x0053ae70`, `0x0053aeb4-0x0053aec0`.
- `0x0053b012-0x0053b060` includes switch-table/data support for [UID:0001DF] and alignment; do not promote as source code.
- `0x0053b6b3-0x0053b700` is lowered switch/data plus padding for the action-animation/timer boundary.
- Known `0xcc` alignments listed in [UID:0001DE] and exact child pages should remain ignored.

## Superseded Initial Coverage Draft - Excluded From Application

This is the rejected initial coverage draft preserved only for traceability. It is not supervisor-owned replacement text. Do not copy any row from this section into `by-memory/-coverage-report.md`; use `## Continuation Coverage Text` below. The original unassigned UID placeholders have been rewritten as `[SUPERSEDED-UNASSIGNED]` in this historical block so no placeholder can be mistaken for a live row.

Historical rejected draft was:

```markdown
    - [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) 0x0053a110-0x0053d818 | mixed source-family split index | LivingObjectPaneCore : ignored : 88% : strong : Non-emitting split/index for the broad object-pane neighborhood; exact LivingObjectPane children, BoxRotator children, raw/no-xref helper candidates, compiler padding/lowered data, and non-Living sibling ranges are classified here, but no formal C++ should be emitted from the aggregate.
        - [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) 0x0053a110-0x0053a6a6 | method-cluster | LivingObjectPaneConstructionAndCleanup : reconstructable : 86% : strong : Constructor variants and non-deleting cleanup body with exact boundaries, class owner route, vtable stores, BoxRotator setup at `+0x1f0`, registry/list setup, active-effect cleanup, linked-object cleanup, and map-global cleanup evidence.
        - [SUPERSEDED-UNASSIGNED][0x0053a6b0-0x0053a6db.LivingObjectPaneOppositeDirectionHelper](by-memory/0x0053a6b0-0x0053a6db.LivingObjectPaneOppositeDirectionHelper.md) 0x0053a6b0-0x0053a6db | private helper | LivingObjectPaneOppositeDirectionHelper : reconstructable : 86% : strong : Static/file helper that maps a four-direction byte to the opposite direction; six direct callers from MapPane/UserPane animation paths and no callees.
        - [SUPERSEDED-UNASSIGNED][0x0053a700-0x0053a8b7.LivingObjectPaneGetRenderBounds](by-memory/0x0053a700-0x0053a8b7.LivingObjectPaneGetRenderBounds.md) 0x0053a700-0x0053a8b7 | method | LivingObjectPaneGetRenderBounds : reconstructable : 86% : strong : Vtable/caller-backed render-bounds helper using sprite config, map coordinate state, image dimensions, and cached BoxRotator rectangle state.
        - [SUPERSEDED-UNASSIGNED][0x0053a8c0-0x0053a8fe.LivingObjectPaneGetSpriteConfig](by-memory/0x0053a8c0-0x0053a8fe.LivingObjectPaneGetSpriteConfig.md) 0x0053a8c0-0x0053a8fe | accessor | LivingObjectPaneGetSpriteConfig : reconstructable : 87% : strong : Copies the 68-byte sprite/config block from `this+0x178..+0x1bc` to the caller output.
        - [SUPERSEDED-UNASSIGNED][0x0053a900-0x0053a9ee.LivingObjectPaneSetSpriteConfig](by-memory/0x0053a900-0x0053a9ee.LivingObjectPaneSetSpriteConfig.md) 0x0053a900-0x0053a9ee | method | LivingObjectPaneSetSpriteConfig : reconstructable : 87% : strong : Replaces sprite config/facing state, coordinates animation timers through TimerHandler/TimerMgr wrappers, optionally steps movement, plays animation, and invalidates map object state.
        - [SUPERSEDED-UNASSIGNED][0x0053a9f0-0x0053aae9.LivingObjectPaneInitializeSpriteConfig](by-memory/0x0053a9f0-0x0053aae9.LivingObjectPaneInitializeSpriteConfig.md) 0x0053a9f0-0x0053aae9 | method | LivingObjectPaneInitializeSpriteConfig : reconstructable : 86% : strong : Initializes sprite config, facing, movement/frame/highlight/name-visible state, schedules animated-frame timer when needed, and restores owner/self pointers.
        - [SUPERSEDED-UNASSIGNED][0x0053ab40-0x0053ad03.LivingObjectPaneDestroyLinkedObjects](by-memory/0x0053ab40-0x0053ad03.LivingObjectPaneDestroyLinkedObjects.md) 0x0053ab40-0x0053ad03 | method | LivingObjectPaneDestroyLinkedObjects : reconstructable : 87% : strong : Deletes/unregisters plural attached-object lists and singleton linked objects, clears owner refs, removes special effect id `134`, and destroys the list containers.
        - [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md) 0x0053aec0-0x0053b012 | helper-method | AttachedObjectDetachRegistry : reconstructable : 88% : strong : LivingObjectPane attached-overlay deregistration method; sole live caller is `AttachedObjectPane::~AttachedObjectPane`, while constructor/setup and neighboring cleanup/replacement helpers prove LivingObjectPane owns registry list fields `+0x170/+0x174` and singleton slots `+0x1d8/+0x1dc/+0x1e0/+0x1e4`.
        - [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) 0x0053b700-0x0053baa8 | method-cluster | LivingObjectPaneAnimationTimer : reconstructable : 86% : strong : Animation playback wrappers and embedded timer-handler callback cluster with verified TimerMgr events, owner offset math, vtable/caller evidence, and stale SoundManager name rejection.
        - [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md) 0x0053bb20-0x0053beb6 | render-method split index | LivingObjectPaneRenderFrameMethods : ignored : 88% : strong : Non-emitting render-method aggregate; exact child pages carry the three vtable methods and alignment coverage.
            - [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md) 0x0053bb20-0x0053bd1c | method | LivingObjectPaneRenderFrame : reconstructable : 86% : strong : Main living-object render method with vtable refs, map/render mode checks, human/monster draw split, and optional marker overlay behavior.
            - [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md) 0x0053bd20-0x0053bdb1 | method | LivingObjectPaneDrawSpriteFrame : reconstructable : 85% : strong : Compact sprite-frame draw method with vtable refs and human/object image draw dispatch.
            - [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) 0x0053bdc0-0x0053beb6 | method | LivingObjectPaneComputeRenderBounds : reconstructable : 86% : strong : Vtable bounds helper that combines map coordinates, sprite frame dimensions, standing/elevation state, and writes caller rectangle output.
        - [SUPERSEDED-UNASSIGNED][0x0053bec0-0x0053bf38.LivingObjectPaneSetMapPosition](by-memory/0x0053bec0-0x0053bf38.LivingObjectPaneSetMapPosition.md) 0x0053bec0-0x0053bf38 | vtable-method | LivingObjectPaneSetMapPosition : reconstructable : 86% : strong : Vtable-routed map-position setter that relocates the object through MapPane, invalidates before/after, cancels forward-step timer, refreshes linked objects, and clears movement state.
        - [SUPERSEDED-UNASSIGNED][0x0053c070-0x0053c1c9.LivingObjectPaneSyncPositionToLinkedObjects](by-memory/0x0053c070-0x0053c1c9.LivingObjectPaneSyncPositionToLinkedObjects.md) 0x0053c070-0x0053c1c9 | method | LivingObjectPaneSyncPositionToLinkedObjects : reconstructable : 86% : strong : Copies owner position to singleton/list linked objects and invokes map relocation for attached-list children; two direct local-player animation callers.
        - [SUPERSEDED-UNASSIGNED][0x0053c1d0-0x0053c286.LivingObjectPaneRefreshAllLinkedObjects](by-memory/0x0053c1d0-0x0053c286.LivingObjectPaneRefreshAllLinkedObjects.md) 0x0053c1d0-0x0053c286 | method | LivingObjectPaneRefreshAllLinkedObjects : reconstructable : 87% : strong : Calls refresh/update virtual slot `+0x70` on all linked singleton/list objects, with EPF singleton gated by `byte_66DA97 == 1`; ten direct branches.
        - [SUPERSEDED-UNASSIGNED][0x0053c290-0x0053c367.LivingObjectPanePropagateLinkedObjectMode](by-memory/0x0053c290-0x0053c367.LivingObjectPanePropagateLinkedObjectMode.md) 0x0053c290-0x0053c367 | vtable-method | LivingObjectPanePropagateLinkedObjectMode : reconstructable : 86% : strong : Vtable/jump-routed linked-object mode propagator; invalidates owner and calls virtual slot `+0x6c` on linked objects.
        - [SUPERSEDED-UNASSIGNED][0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward](by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md) 0x0053c390-0x0053c5da | method | LivingObjectPaneTryStepForward : reconstructable : 86% : strong : Movement step helper that tests direction, map bounds/passability, moves owner and linked objects, refreshes linked objects, and returns blocked/failed status.
        - [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) 0x0053d030-0x0053d053 | scalar-deleting-destructor | LivingObjectPaneBoxRotatorScalarDeletingDestructor : reconstructable : 85% : strong : Exact nested `LivingObjectPane::BoxRotator` scalar deleting destructor with vtable slot evidence, constructor vptr stores, owner pointer setup, and size-8 conditional delete.
        - [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) 0x0053d430-0x0053d589 | scalar-deleting-destructor | LivingObjectPaneScalarDeletingDestructor : reconstructable : 86% : strong : LivingObjectPane scalar deleting destructor with vtable/data refs, cleanup callees, map-global cleanup, linked-object/effect teardown, and pool free target `0x0069b894`.
        - [SUPERSEDED-UNASSIGNED][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) 0x0053d7c0-0x0053d7f4 | nested-helper-method | LivingObjectPaneBoxRotatorAdvance : reconstructable : 87% : strong : Second `LivingObjectPane::BoxRotator` vtable slot; reads owner pointer, advances owner rotation phase `+0x1ec` modulo four, calls frame handler, and invalidates owner.
        - [SUPERSEDED-UNASSIGNED][0x0053d800-0x0053d808.LivingObjectPaneShowName](by-memory/0x0053d800-0x0053d808.LivingObjectPaneShowName.md) 0x0053d800-0x0053d808 | vtable-method | LivingObjectPaneShowName : reconstructable : 86% : strong : Tiny vtable-routed method that sets name-visible byte `this+0x1d1`.
        - [SUPERSEDED-UNASSIGNED][0x0053d810-0x0053d818.LivingObjectPaneHideName](by-memory/0x0053d810-0x0053d818.LivingObjectPaneHideName.md) 0x0053d810-0x0053d818 | vtable-method | LivingObjectPaneHideName : reconstructable : 86% : strong : Tiny vtable-routed method that clears name-visible byte `this+0x1d1`.
```

Replacement for the stale [UID:0001KM] row:

```markdown
    - [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | mixed source-family split index | LivingObjectPaneLocalPlayerExtensions : ignored : 88% : strong : Non-emitting split index for the local-player movement/command/server-packet neighborhood; exact children carry LivingObjectPane/UserPane/SayInputPanes/Chatting/Quit/SelfSave ownership, while raw projected starts such as `0x005a9250` remain documented as no-xref candidates.
        - [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) 0x005a87b0-0x005a87d5 | raw helper | LivingObjectPaneGetActiveLinkedRecordByIndexRaw : reconstructable : 85% : strong : Function-shaped linked-record lookup with pointer/count fields at `this+0x13eb14/+0x13eb18`, 0x10-byte records, active-byte test, no entry xrefs, and adjacency to linked-record cleanup helpers.
        - [UID:0003UF][0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords](by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md) 0x005a87e0-0x005a8809 | helper | LivingObjectPaneClearAllLinkedRecords : reconstructable : 85% : strong : Clears local movement/linked-record activity state for the linked-record array owned by LivingObjectPane.
        - [UID:0003UG][0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex](by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md) 0x005a8810-0x005a8832 | helper | LivingObjectPaneClearLinkedRecordByIndex : reconstructable : 85% : strong : Clears one local movement/linked-record entry by index, paired with the all-record cleanup helper.
```

Replacement for stale vtable rows:

```markdown
        - [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) 0x0062096c-0x00620978 | vtable-data | LivingObjectPaneBoxRotatorVtableData : reconstructable : 88% : strong : Exact `LivingObjectPane::BoxRotator` RTTI/vtable child with slots to the scalar deleting destructor and `0x0053d7c0` callback, constructor vptr stores at `LivingObjectPane+0x1f0`, owner pointer setup at `+0x1f4`, and direct nested-class route through [UID:00007C].
        - [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) 0x00620978-0x00620a38 | vtable-data | LivingObjectPaneVtableData : reconstructable : 87% : strong : Exact `LivingObjectPane` RTTI and three vtable views with constructor/destructor vptr refs, neighboring BoxRotator/Lighting boundaries, and direct class route through [UID:00007B].
```

Replacement for stale [UID:00030B] row:

```markdown
    - [UID:00030B][0x0069bf74-0x0069bf78.g_lastFunctionKeyTick](by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md) 0x0069bf74-0x0069bf78 | global-data | g_lastFunctionKeyTick : reconstructable : 86% : strong : Zero-filled function-key debounce tick dword assigned to `LivingObjectPane.cpp` as legacy/orphan support for raw helper `0x005a9250-0x005a9307`; live evidence shows two read-only refs, no known writer, no entry/pointer refs into the raw helper, and active UserPane key handling dispatches elsewhere.
```

Rows [UID:000233] and [UID:00023H] are already directionally current and do not require coverage replacement from this assignment. [UID:00023H] should remain below final-source level until `this+0x148/+0x14c` field names are promoted.

## Continuation: Executable Child Split Package

Supervisor review accepted the parent split/index decision and the helper/source-name/field evidence, but rejected the original child-page recommendation because the coverage text used unassigned placeholder UIDs and the proposed child pages were not executable enough. This continuation supersedes the placeholder coverage draft above. Do not apply any earlier historical coverage text.

The executable plan is to create validator-assigned child pages using exact filenames, then update parent/support/coverage references through the standard TMP workflow or after real UIDs exist. The earlier per-function table remains valid research detail, but it is not the immediate child creation plan. To avoid dozens of tiny live pages before validation, create these source-shaped exact child pages first:

| Proposed file | Range | Immediate disposition |
| --- | --- | --- |
| `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | `0x0053a6b0-0x0053aae9` | source-bearing method/helper cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:0000KU]. |
| `by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md` | `0x0053aaf0-0x0053aeb4` | source-bearing method/helper cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |
| `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md` | `0x0053b060-0x0053b6b3` | source-bearing method/helper cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |
| `by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md` | `0x0053bab0-0x0053bb1d` | source-bearing method cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |
| `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | `0x0053bec0-0x0053c367` | source-bearing method/helper cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |
| `by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md` | `0x0053c390-0x0053c5da` | exact source-bearing method, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |
| `by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md` | `0x0053d7c0-0x0053d7f4` | exact nested helper method, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007C]. |
| `by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md` | `0x0053d800-0x0053d818` | exact tiny vtable method cluster, `RECONSTRUCTABLE:TRUE`, emitter [UID:00007B]. |

Validator/TMP workflow:

1. Create the files above under `source-3/project-documentation/by-memory/`.
2. Do not hand-write or guess UIDs. Let `tools/validator.py --mode file --file <child> --apply` assign each UID.
3. For the page bodies below, do not add a placeholder UID line. If the supervisor creates the child file from the body first, the validator should insert the real `*** UID:... ***` header above the `COMPLETION` line. If the supervisor validates an empty/stub file first, paste the body below the validator-assigned UID header.
4. Parent/support docs may reference the new children before UIDs are known only with TMP links such as `[TMP:"by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md"]`. Validate the edited parent/support file so the validator resolves those TMP references.
5. `by-memory/-coverage-report.md` should not be edited by B001. Supervisor should either wait until validator-assigned UIDs exist and then insert real UID rows, or insert the TMP rows from this continuation only after the target files exist and then validate the coverage file to resolve TMP links.
6. The original per-function micro-pages from the earlier report should wait. They are valid future splits only if later agents need one page per tiny method; they are not required to apply the accepted parent split.

Parent/support edits that should wait until children exist:

- [UID:0001DE] child inventory rows for the eight new pages should wait until the files exist; use TMP references or real UIDs.
- [UID:00007B] method-family references to the eight new pages should wait until the files exist; use TMP references or real UIDs.
- [UID:0000KU] proposed contents/major-method rows should wait until the files exist; use TMP references or real UIDs.
- `by-memory/-coverage-report.md` child rows must wait until the files exist and should use only real validator-assigned UIDs or the TMP links in this continuation.

### Draft Child Page: Sprite Config Helpers

Create file:

```text
by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned char LivingObjectPane_OppositeDirection(unsigned char direction)
{
    switch (direction)
    {
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    default:
        return 2;
    }
}

void LivingObjectPane::GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const
{
    if (g_pActiveMapPane == 0)
        return;

    if (m_spriteConfig.kind != 0)
    {
        if (g_pActiveMapPane->IsHighResolutionMode())
        {
            if (m_spriteConfig.frameGroup < 9 && m_isMoving)
                g_pObjectImageLib->GetFrameBounds(m_spriteConfig, m_facing + 5, m_moveFrame, imageRect, &m_boxRotatorRect);
            else
                g_pObjectImageLib->GetFrameBounds(m_spriteConfig, m_spriteConfig.frameGroup, m_animationFrame, imageRect, &m_boxRotatorRect);

            AdjustRectForBoxRotation(*imageRect, m_boxRotatorRect, screenRect);
            NxPoint mapPoint;
            g_pActiveMapPane->GetObjectScreenPoint(this, &mapPoint);
            OffsetRectByPoint(&m_boxRotatorRect, mapPoint);
        }
        else
        {
            if (m_spriteConfig.frameGroup < 9 && m_isMoving)
                g_pObjectImageLib->GetFrameBounds(m_spriteConfig, m_facing + 5, m_moveFrame, imageRect, 0);
            else
                g_pObjectImageLib->GetFrameBounds(m_spriteConfig, m_spriteConfig.frameGroup, m_animationFrame, imageRect, 0);
            *screenRect = *imageRect;
        }
        return;
    }

    if (g_pActiveMapPane->IsHighResolutionMode())
    {
        g_pHumanImageLib->GetFrameBounds(m_spriteConfig, m_facing, m_spriteConfig.bodyFrame, m_moveFrame, imageRect, &m_boxRotatorRect, 0, m_isMoving, m_spriteConfig.palette);
        AdjustRectForBoxRotation(*imageRect, m_boxRotatorRect, screenRect);
        NxPoint mapPoint;
        g_pActiveMapPane->GetObjectScreenPoint(this, &mapPoint);
        OffsetRectByPoint(&m_boxRotatorRect, mapPoint);
    }
    else
    {
        g_pHumanImageLib->GetFrameBounds(m_spriteConfig, m_facing, m_spriteConfig.bodyFrame, m_moveFrame, imageRect, 0, 0, m_isMoving, m_spriteConfig.palette);
        *screenRect = *imageRect;
    }
}

void LivingObjectPane::GetSpriteConfig(LivingSpriteConfig *out) const
{
    *out = m_spriteConfig;
}

bool LivingObjectPane::SetSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)
{
    if (m_spriteConfig.kind != config->kind)
    {
        const bool wasNotMoving = !m_isMoving;
        m_spriteConfig = *config;
        if (!wasNotMoving && TryStepForward())
            return true;

        m_timerHandler.CancelPendingTimersExceptEvent(kLivingTimerRefresh);
        m_moveFrame = 0;
        if (config->kind == 1)
            PlayAnimation(facing + 1);
    }

    m_spriteConfig = *config;
    m_facing = facing;
    m_timerHandler.CancelTimer(kLivingTimerDirectionDelay);
    OnSpriteConfigChanged();
    g_pActiveMapPane->InvalidateObject(this);
    return false;
}

void LivingObjectPane::InitializeSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)
{
    m_spriteConfig = *config;
    m_facing = facing;
    m_isMoving = false;
    m_moveFrame = 0;
    m_animationFrame = 0;
    m_highlighted = false;
    OnSpriteConfigChanged();
    m_nameVisible = false;
    m_animationGroup = facing + 1;

    if (m_spriteConfig.kind == 1)
    {
        const ImageFrame *frame = g_pObjectImageLib->GetFrame(m_spriteConfig.imageId - 0x8000, facing + 1, 0);
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerFrameAnimation, frame->delay, 0, 0);
    }

    m_linkedOwnerBackPointer = 0;
    m_boxRotationPhase = 0;
    m_boxRotatorOwner = this;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053a6b0-0x0053aae9 LivingObjectPane Sprite Config Helpers

## Status

- Disposition: reconstructable `LivingObjectPane.cpp` method/helper cluster.
- Owner: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), because this exact cluster contains one file-local/static direction helper plus `LivingObjectPane` methods.
- Source route: emits through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
- Parent split index: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).
- C++ handling: eligible and supplied. The draft uses descriptive names and should be refined when final class fields are promoted.

## Address Range

`0x0053a6b0-0x0053aae9`, exclusive end.

| Range | Current name | Signature | Role |
| --- | --- | --- | --- |
| `0x0053a6b0-0x0053a6db` | `sub_53A6B0` | `char __stdcall(char)` | File-local opposite-direction helper. |
| `0x0053a6db-0x0053a700` | alignment | raw `0xcc` / gap | Not source code. |
| `0x0053a700-0x0053a8b7` | `sub_53A700` | `void __thiscall(int, int *, _OWORD *)` | Render/image rectangle helper. |
| `0x0053a8b7-0x0053a8c0` | alignment | raw gap | Not source code. |
| `0x0053a8c0-0x0053a8fe` | `sub_53A8C0` | `int __thiscall(int, int)` | Sprite-config copy accessor. |
| `0x0053a8fe-0x0053a900` | alignment | raw gap | Not source code. |
| `0x0053a900-0x0053a9ee` | `sub_53A900` | `char __thiscall(char *, int, char)` | Set/replace sprite config and facing. |
| `0x0053a9ee-0x0053a9f0` | alignment | raw gap | Not source code. |
| `0x0053a9f0-0x0053aae9` | `sub_53A9F0` | `int __thiscall(char *, int, char)` | Initial sprite-config setup/reset helper. |

## Behavior

- `0x0053a6b0` maps a four-direction byte to the opposite direction and has no callees.
- `0x0053a700` computes sprite/image rectangles. It branches between human-image and object/monster-image libraries, considers high-resolution map mode, uses moving-frame state, and adjusts cached BoxRotator rectangle state.
- `0x0053a8c0` copies the 68-byte config block from `this+0x178..+0x1bc`.
- `0x0053a900` replaces sprite config, cancels living timer events, optionally calls `TryStepForward`, starts animation for animated config kind `1`, stores facing, triggers the virtual refresh path, and invalidates the map object.
- `0x0053a9f0` initializes the same sprite block and resets movement/name/highlight/animation state. When config kind is `1`, it resolves frame delay through image helpers and schedules timer event `FAnD`.

## Evidence

- Export JSON confirms exact sizes: `0x2b`, `0x1b7`, `0x3e`, `0xee`, and `0xf9`.
- `.text` branch scan found direct calls to `0x0053a6b0` from `0x005058c6`, `0x0050be3b`, `0x005a843a`, `0x005a8515`, `0x005a857a`, and `0x005a862a`.
- Export xrefs for `0x0053a700` are a code caller at `0x005a885c` and data/vtable ref `0x006209cc`.
- Export xrefs for `0x0053a900` are code callers `0x00505f75` and `0x0051362c`.
- Export xref for `0x0053a9f0` is code caller `0x00506052`.
- Callees include image-library helpers `0x004db330`, `0x004db5c0`, `0x004e09e0`, `0x00528af0`, `0x00528d00`, map rect helpers `0x0050ab70`, `0x0050b080`, timer wrappers `0x00597610`, `0x00597630`, scheduler `0x00597910`, and map invalidation `0x00506980`.

## Touched Fields / Globals

- `this+0x178..+0x1bc`: `m_spriteConfig`.
- `this+0x1c4`: `m_isMoving`.
- `this+0x1c5`: `m_facing`.
- `this+0x1c6`: `m_moveFrame`.
- `this+0x1c8/+0x1cc`: animation frame/group.
- `this+0x1d1`: name-visible byte reset by initialization.
- `this+0x1e8`: highlight byte reset by initialization.
- `this+0x1ec/+0x1f4`: BoxRotator owner/phase setup.
- `dword_67A760`, `dword_69B440`, `dword_67A764`, `dword_67AB80`: image library, object image table, active map pane, timer manager.

## Rejected Alternatives

- Not padding: every function has export JSON and direct or vtable references.
- Not `MapPane`: callers use these helpers, but the state read/written is `LivingObjectPane` sprite/config state.
- Not `SoundManager`: timer calls target TimerHandler/TimerMgr wrappers, not audio code.

## Per-Child Checklist

- Branch scan: positive for `0x0053a6b0` and `0x0053a9f0`; `0x0053a700` has vtable/data plus one code caller.
- Generated-name rejection: `sub_` names replaced with descriptive source names; generated `SoundManager` timer labels rejected.
- Field/type names: uses `LivingSpriteConfig`, `NxRect`, `m_spriteConfig`, movement/facing frame fields, TimerHandler.
- Caller/no-caller: all executable starts have code or vtable refs.
- Owner/source placement: file-level [UID:0000KU] because cluster contains a static helper plus class methods.
- Rejected alternatives: padding, MapPane ownership, SoundManager ownership.

## Score Rationale

Completion `86`: exact boundaries, callers/xrefs, callees, behavior, fields, timer ownership, and C++ draft are documented. Confidence `88`: direct branch/vtable evidence and neighboring docs agree; exact original field names remain descriptive.
```

### Draft Child Page: Linked Object Setup Helpers

Create file:

```text
by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::SetSpriteAttribute(unsigned char value)
{
    if (m_spriteConfig.attribute == value)
        return;

    m_spriteConfig.attribute = value;
    g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::SetMovingState(bool moving)
{
    m_isMoving = moving;
    if (!moving)
        m_moveFrame = 0;
}

void LivingObjectPane::DestroyLinkedObjects()
{
    DestroyAttachedList(m_type2AttachedObjects, true);
    DestroyAttachedList(m_type4AttachedObjects, true);

    DeleteObjectPane(m_linkedGroundObject);
    m_linkedGroundObject = 0;

    ClearAttachedOwnerRefs(m_type2AttachedObjects);
    ClearAttachedOwnerRefs(m_type4AttachedObjects);

    DeleteObjectPane(m_linkedShadowObject);
    m_linkedShadowObject = 0;
    DeleteObjectPane(m_linkedEpfObject);
    m_linkedEpfObject = 0;
    DeleteObjectPane(m_linkedNameplateObject);
    m_linkedNameplateObject = 0;

    RemoveSpecialEffect();

    DeleteObjectPane(m_type2AttachedObjects);
    DeleteObjectPane(m_type4AttachedObjects);
    m_type2AttachedObjects = 0;
    m_type4AttachedObjects = 0;
}

void LivingObjectPane::RawDestroyAttachmentListsOnly()
{
    DestroyAttachedList(m_type2AttachedObjects, true);
    DestroyAttachedList(m_type4AttachedObjects, true);
}

void LivingObjectPane::SetLinkedGroundObject(ObjectPane *pane)
{
    m_linkedGroundObject = pane;
}

void LivingObjectPane::InsertType2AttachedObject(AttachedObjectPane *pane)
{
    RemoveAttachedObjectWithObjectId(m_type2AttachedObjects, pane->GetObjectId(), true);
    m_type2AttachedObjects->Insert(1, pane);
}

void LivingObjectPane::InsertType4AttachedObject(AttachedObjectPane *pane)
{
    RemoveAttachedObjectWithObjectId(m_type4AttachedObjects, pane->GetObjectId(), true);
    m_type4AttachedObjects->Insert(1, pane);
}

void LivingObjectPane::SetLinkedShadowObject(ObjectPane *pane)
{
    m_linkedShadowObject = pane;
}

void LivingObjectPane::SetLinkedEpfObject(ObjectPane *pane)
{
    m_linkedEpfObject = pane;
}

void LivingObjectPane::ReplaceLinkedNameplateObject(ObjectPane *pane)
{
    DeleteObjectPane(m_linkedNameplateObject);
    m_linkedNameplateObject = pane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053aaf0-0x0053aeb4 LivingObjectPane Linked Object Setup Helpers

## Status

- Disposition: reconstructable `LivingObjectPane` linked-object and state helper cluster.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), emitted through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
- Parent split index: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).
- Raw/no-xref handling: `0x0053ad10` is source-shaped and included in this cluster as `RawDestroyAttachmentListsOnly`; it is `RECONSTRUCTABLE:TRUE` through the cluster, but not recommended as a separate emitting page until reachability is proven.
- C++ handling: eligible and supplied. Raw helper is present as a private helper body because the bytes are source-shaped but no caller is proven.

## Address Range

`0x0053aaf0-0x0053aeb4`, exclusive end.

| Range | Current name | Signature | Role |
| --- | --- | --- | --- |
| `0x0053aaf0-0x0053ab1a` | `sub_53AAF0` | `int __thiscall(_WORD *, unsigned __int8)` | Set sprite/config attribute and invalidate. |
| `0x0053ab20-0x0053ab3a` | `sub_53AB20` | `char __thiscall(_BYTE *, char)` | Set/clear moving state. |
| `0x0053ab40-0x0053ad03` | `sub_53AB40` | `void __thiscall(_DWORD *)` | Destroy linked attached objects and singleton overlays. |
| `0x0053ad10-0x0053ad9f` | Ghidra-only `FUN_0053ad10` | `undefined __fastcall(int)` | Raw/no-xref list-only destroy helper. |
| `0x0053ada0-0x0053adb0` | `sub_53ADA0` | `int __thiscall(_DWORD *, int)` | Store singleton slot `+0x1d8`. |
| `0x0053adb0-0x0053ae06` | `sub_53ADB0` | `int __thiscall(_DWORD *, int)` | De-duplicate and insert into list `+0x170`. |
| `0x0053ae10-0x0053ae66` | `sub_53AE10` | `int __thiscall(_DWORD *, int)` | De-duplicate and insert into list `+0x174`. |
| `0x0053ae70-0x0053ae80` | `sub_53AE70` | `int __thiscall(_DWORD *, int)` | Store singleton slot `+0x1dc`. |
| `0x0053ae80-0x0053ae90` | `sub_53AE80` | `int __thiscall(_DWORD *, int)` | Store singleton slot `+0x1e0`. |
| `0x0053ae90-0x0053aeb4` | `sub_53AE90` | `int __thiscall(_DWORD *, int)` | Delete/replace singleton slot `+0x1e4`. |

## Behavior

The cluster owns small state setters and attached/linked object replacement helpers. The plural lists at `+0x170/+0x174` hold attached object type `2` and type `4` lists. The singleton slots at `+0x1d8/+0x1dc/+0x1e0/+0x1e4` hold linked ground/shadow/EPF/nameplate-style objects. Insert helpers remove an existing attached object with the same object id before inserting the new pointer.

## Evidence

- Export JSON confirms all IDA ranges except `0x0053ad10`, where Ghidra decodes a function-shaped raw helper.
- Branch scan positives:
  - `0x0053adb0`: `0x0050eafe`.
  - `0x0053ae10`: `0x0050eaef`.
  - `0x0053ae90`: `0x0050fe38`.
- Export xrefs:
  - `0x0053ada0`: `0x0050e1df`, `0x0051192c`.
  - `0x0053ae70`: `0x0050e63e`, `0x0050e7b6`, `0x0050ee81`.
  - `0x0053ae80`: `0x0050efb5`, `0x00512ad7`.
- Branch scan for `0x0053ad10` found no direct branch; export reports no IDA caller. Ghidra body deletes entries in `+0x170/+0x174` lists after unregistering them from the active map.
- [UID:0001TR] and [UID:0001DF] confirm the same fields in detach-helper and constructor/setup evidence.

## Touched Fields / Globals

- `+0x170`: `m_type2AttachedObjects`.
- `+0x174`: `m_type4AttachedObjects`.
- `+0x1d8`: `m_linkedGroundObject`.
- `+0x1dc`: `m_linkedShadowObject`.
- `+0x1e0`: `m_linkedEpfObject`.
- `+0x1e4`: `m_linkedNameplateObject`.
- `+0x1c4/+0x1c6`: moving/move-frame bytes.
- `dword_67A764`: active map pane used for unregister/invalidate.

## Rejected Alternatives

- The plural list fields are not ground/shadow lists; they match attached object type `2` and type `4` removal in [UID:0001DF].
- `0x0053ad10` is not promoted to a standalone public helper because it has no direct branch, pointer, or IDA function route.
- These helpers are not `AttachedObjectPane` methods. `AttachedObjectPane` is a caller/source-use context; the receiver fields are initialized and cleaned by `LivingObjectPane`.

## Per-Child Checklist

- Branch scan: positive for insert/replace helpers; negative for `0x0053ad10`.
- Generated-name rejection: `sub_`/Ghidra names replaced with descriptive linked-object names.
- Field/type names: list fields `m_type2AttachedObjects`/`m_type4AttachedObjects`; singleton fields `m_linkedGroundObject`, `m_linkedShadowObject`, `m_linkedEpfObject`, `m_linkedNameplateObject`.
- Caller/no-caller: all non-raw helpers have callers; raw list-only helper has explicit no-xref proof.
- Owner/source placement: [UID:00007B] class in `LivingObjectPane.cpp`.
- Rejected alternatives: AttachedObjectPane ownership, ground/shadow plural-list naming, standalone raw helper emission.

## Score Rationale

Completion `86`: exact ranges, caller/no-caller evidence, field roles, cleanup/insert behavior, and C++ draft are documented. Confidence `88`: field ownership is corroborated by constructor/detach/helper evidence; raw no-xref helper remains lower confidence but contained.
```

### Draft Child Page: Effect Movement And Action Helpers

Create file:

```text
by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::RawAddActiveEffect(ObjectPane *effect)
{
    while (m_activeEffects->Count() > 2)
    {
        ObjectPane *oldEffect = m_activeEffects->At(m_activeEffects->Count() - 3);
        if (oldEffect != 0)
            oldEffect->CancelTimersAndDelete();
        m_activeEffects->RemoveAt(m_activeEffects->Count() - 3, true);
        if (m_currentEffect == oldEffect)
            m_currentEffect = 0;
    }

    m_activeEffects->Insert(1, effect);
}

void LivingObjectPane::RawRemoveActiveEffect(ObjectPane *effect)
{
    for (int i = 0; i < m_activeEffects->Count(); ++i)
    {
        if (m_activeEffects->At(i) == effect)
        {
            m_activeEffects->RemoveAt(i, true);
            break;
        }
    }
}

void LivingObjectPane::ClearAllEffects()
{
    for (int i = 0; i < m_activeEffects->Count(); ++i)
        DeleteObjectPane(m_activeEffects->At(i));
    m_activeEffects->Clear();
    m_currentEffect = 0;
}

void LivingObjectPane::RawSetCurrentEffect(ObjectPane *effect)
{
    if (m_currentEffect != effect)
        m_currentEffect = effect;
}

void LivingObjectPane::SetHighlightState(bool highlighted)
{
    if (m_highlighted == highlighted)
        return;

    m_highlighted = highlighted;
    if (highlighted)
        m_boxRotator.Start();
    else
        m_boxRotator.Stop();
    Invalidate(false);
}

void LivingObjectPane::ShowDamageEffect(int value, short soundId)
{
    g_pSoundManager->PlaySample(soundId, 100);
    if (m_spriteConfig.kind == 1 && m_spriteConfig.imageId > 0x8173 && m_spriteConfig.imageId < 0x8187)
        return;

    m_pendingDamageEffect = value;
    Invalidate(&m_bounds);
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerRefresh, 120, 0, 0);
}

bool LivingObjectPane::BeginMoveTo(int x, int y, unsigned char facing, short stepCode)
{
    m_facing = facing;
    m_timerHandler.CancelTimer(kLivingTimerForwardStep);

    if (TryStepForward())
        return true;

    if (m_highlighted)
        SetHighlightState(true);

    m_targetX = x;
    m_targetY = y;
    m_stepCode = stepCode;
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerForwardStep, 1, 0, 0);
    g_pActiveMapPane->InvalidateObject(this);
    return false;
}

void LivingObjectPane::SetFacing(unsigned char facing)
{
    if (m_isMoving)
    {
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerDirectionDelay, m_spriteConfig.directionDelay, facing, 0);
        return;
    }

    m_facing = facing;
    if (m_spriteConfig.kind == 1)
        PlayAnimation(facing + 1);
    g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing)
{
    if (m_spriteConfig.kind == 1)
    {
        if (m_animationGroup != 0 && m_animationGroup <= 8)
        {
            switch (action)
            {
            case 0:  PlayAnimation(m_facing + 5); break;
            case 1:  PlayAnimation(m_facing + 13); break;
            case 2:  if (!m_stepCode) PlayAnimation(m_facing + 17); break;
            case 3:  if (!m_stepCode) PlayAnimation(m_facing + 21); break;
            case 4:  if (!m_stepCode) PlayAnimation(m_facing + 25); break;
            case 5:  if (!m_stepCode) PlayAnimation(m_facing + 29); break;
            case 6:  return;
            case 25: PlayAnimation(m_facing + 9); break;
            default: if (!m_stepCode) PlayAnimation(4); break;
            }
        }
        return;
    }

    if (action == 25)
        return;
    if (m_nameVisible && action != 27 && action != 4 && action != 6)
        return;
    if (action == 27)
        ClearAllEffects();

    Motion *effect = g_motionPool.Alloc();
    if (effect != 0)
        effect->Construct(this, action, static_cast<short>(value), facing);

    RawAddActiveEffect(effect);
    if (effect != 0)
        g_pTimerMgr->ScheduleTimer(effect->GetTimerHandler(), 0, 0, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053b060-0x0053b6b3 LivingObjectPane Effect Movement And Action Helpers

## Status

- Disposition: reconstructable `LivingObjectPane` active-effect, highlight, damage, movement, facing, and action-animation cluster.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Raw/no-xref handling: `0x0053b060`, `0x0053b0e0`, and `0x0053b190` have no direct branch hits and are kept inside this cluster as private helper bodies, not standalone pages.
- C++ handling: eligible and supplied. The draft is source-style and uses descriptive names; exact original helper names remain inferred.

## Address Range

`0x0053b060-0x0053b6b3`, exclusive end. The prior `0x0053b012-0x0053b060` bytes remain switch/data/alignment support for [UID:0001DF], not this child.

| Range | Role |
| --- | --- |
| `0x0053b060-0x0053b0df` | Raw add/trim active-effect list helper. |
| `0x0053b0e0-0x0053b12b` | Raw remove active effect helper. |
| `0x0053b130-0x0053b184` | Clear all active effects. |
| `0x0053b190-0x0053b1a8` | Raw current-effect setter. |
| `0x0053b1b0-0x0053b1f7` | Highlight/BoxRotator toggle. |
| `0x0053b200-0x0053b272` | Damage/refresh effect helper. |
| `0x0053b280-0x0053b35a` | Begin move-to helper. |
| `0x0053b360-0x0053b3c7` | Facing setter. |
| `0x0053b3d0-0x0053b6b3` | Action animation/effect helper. |

## Evidence

- Export JSON decodes all functions; Ghidra decodes raw no-xref functions at `0x0053b060`, `0x0053b0e0`, and `0x0053b190`.
- Branch scan found no direct branches to the raw starts `0x0053b060`, `0x0053b0e0`, `0x0053b190`.
- `0x0053b130` has eight callers, including destructors, movement/warp paths, and action helper.
- `0x0053b1b0` has 89 callers; it toggles `this+0x1e8` and starts/stops BoxRotator state at `this+0x1f0`.
- `0x0053b200` callers are from packet/render update path `0x00512960`.
- `0x0053b280` callers include `0x005119f0` and `0x00507c90`.
- `0x0053b360` callers include `0x00511ad0`, `0x005a2e00`, and `0x00507c90`.
- `0x0053b3d0` has no ordinary direct caller in the Ghidra caller list but has internal source behavior and helper callees; it is part of the vtable/source family recorded by [UID:0001DE].

## Touched Fields / Globals

- `+0x1bc`: active-effect list.
- `+0x1c0`: current active effect.
- `+0x1c4/+0x1c5/+0x1c6`: moving/facing/move-frame state.
- `+0x1e8`: highlight state.
- `+0x1f0`: BoxRotator subobject.
- `+0x1f8`: pending damage/refresh payload.
- `dword_67A7D0`: sound manager sample play path.
- `dword_67AB80`: timer manager scheduler.
- `dword_67A764`: active map pane invalidation.
- `byte_69B984`: Motion/effect pool allocator.

## Rejected Alternatives

- Raw no-xref helpers should not be marked padding; they decode into list/effect operations over known `LivingObjectPane` fields.
- The damage helper is not a SoundManager-owned helper merely because it plays a sound; receiver state and scheduling are `LivingObjectPane`.
- The action helper should not be split into Motion ownership; it allocates/constructs Motion effects but owns the actor action dispatch.

## Per-Child Checklist

- Branch scan: raw helpers negative; named method starts have caller/export evidence.
- Generated-name rejection: generated `sub_` names replaced by active-effect, movement, facing, and action names.
- Field/type names: active-effect list/current-effect, movement bytes, BoxRotator, TimerHandler, Motion.
- Caller/no-caller: raw no-xref status explicit; public methods have callers or source-family/vtable context.
- Owner/source placement: [UID:00007B] class under `LivingObjectPane.cpp`.
- Rejected alternatives: padding, SoundManager ownership, Motion ownership.

## Score Rationale

Completion `86`: exact function map, raw/no-xref treatment, behavior, state fields, callers, and draft C++ are recorded. Confidence `88`: linked fields and call/callee evidence are strong; raw helper original names remain inferred.
```

### Draft Child Page: Nameplate Special Effect Helpers

Create file:

```text
by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::RequestNameplateEffect()
{
    g_pActiveMapPane->RequestObjectEffect(m_objectId, 135, -2, 0);
}

void LivingObjectPane::RemoveSpecialEffect()
{
    if (m_type4AttachedObjects == 0)
        return;

    for (int i = 0; i < m_type4AttachedObjects->Count(); ++i)
    {
        ObjectPane *pane = m_type4AttachedObjects->At(i);
        if (pane != 0 && pane->GetObjectId() == 134)
        {
            DeleteObjectPane(pane);
            return;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053bab0-0x0053bb1d LivingObjectPane Nameplate Special Effect Helpers

## Status

- Disposition: reconstructable `LivingObjectPane` helper pair.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Parent split index: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).
- C++ handling: eligible and supplied.

## Address Range

`0x0053bab0-0x0053bb1d`, exclusive end. The following bytes up to `0x0053bb20` are alignment before [UID:0002R2].

| Range | Current name | Signature | Role |
| --- | --- | --- | --- |
| `0x0053bab0-0x0053bacb` | `sub_53BAB0` | `void __thiscall(int *)` | Request/create nameplate or object effect id `135`. |
| `0x0053bad0-0x0053bb1d` | `sub_53BAD0` | `void __thiscall(_DWORD *)` | Remove attached special effect id `134` from list `+0x174`. |

## Evidence

- `0x0053bab0` has direct caller `0x0050fae9`.
- `0x0053bad0` has two callers in export data.
- `0x0053bab0` calls MapPane helper `0x0050e320(dword_67A764, this[63], 135, -2, 0)`.
- `0x0053bad0` scans list `this[93]` / offset `+0x174` and deletes the child whose object id at `+0x148` decompiler view equals `134`.

## Touched Fields / Globals

- `this+0xfc` / decompiler `this[63]`: actor/object id used for MapPane request.
- `this+0x174`: `m_type4AttachedObjects`.
- `dword_67A764`: active MapPane.
- Constants `134` and `135`: paired special effect/nameplate descriptors.

## Rejected Alternatives

- Not MapPane-owned: MapPane services the effect request, but actor id and attached-list ownership are `LivingObjectPane`.
- Not generic attached-object code: the constants and owner list tie this helper pair to living actor visual effects.

## Per-Child Checklist

- Branch scan/caller evidence: direct caller for `0x0053bab0`; export callers for `0x0053bad0`.
- Generated-name rejection: `sub_` names replaced with nameplate/special-effect roles.
- Field/type names: active MapPane, attached type-4 list, object id.
- Owner/source placement: [UID:00007B].
- Rejected alternatives: MapPane ownership and generic attached helper ownership.

## Score Rationale

Completion `86`: exact boundaries, callers, constants, touched list/global, behavior, and C++ draft are documented. Confidence `88`: caller/callee and field evidence are direct; final original method names remain inferred.
```

### Draft Child Page: Linked Position And Mode Helpers

Create file:

```text
by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::SetMapPosition(int x, int y)
{
    if (m_tileX == x && m_tileY == y)
        return;

    g_pActiveMapPane->MoveObject(this, m_tileY, m_tileX, y, x);
    Invalidate(false);
    m_tileX = x;
    m_tileY = y;
    Invalidate(false);
    m_timerHandler.CancelTimer(kLivingTimerForwardStep);
    RefreshAllLinkedObjects();
    m_isMoving = false;
}

void LivingObjectPane::ScheduleBoxRotationStep()
{
    m_timerHandler.CancelTimer(kLivingTimerBoxStep);
    g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerBoxStep, 1, 0, 0);
}

void LivingObjectPane::CancelBoxRotationStep()
{
    m_timerHandler.CancelTimer(kLivingTimerBoxStep);
}

void LivingObjectPane::RawPropagateLinkedObjectMode(int mode)
{
    PropagateLinkedModeNoInvalidate(mode);
}

void LivingObjectPane::SyncPositionToLinkedObjects()
{
    SyncOneLinkedObjectPosition(m_linkedGroundObject);
    SyncAttachedListPositions(m_type2AttachedObjects);
    SyncAttachedListPositions(m_type4AttachedObjects);
    SyncOneLinkedObjectPosition(m_linkedShadowObject);
    if (g_useEpfAssets)
        SyncOneLinkedObjectPosition(m_linkedEpfObject);
    SyncOneLinkedObjectPosition(m_linkedNameplateObject);
}

void LivingObjectPane::RefreshAllLinkedObjects()
{
    RefreshOneLinkedObject(m_linkedGroundObject);
    RefreshAttachedList(m_type2AttachedObjects);
    RefreshAttachedList(m_type4AttachedObjects);
    RefreshOneLinkedObject(m_linkedShadowObject);
    if (g_useEpfAssets)
        RefreshOneLinkedObject(m_linkedEpfObject);
    RefreshOneLinkedObject(m_linkedNameplateObject);
}

void LivingObjectPane::PropagateLinkedObjectMode(int mode)
{
    g_pActiveMapPane->InvalidateObject(this);
    PropagateLinkedModeNoInvalidate(mode);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053bec0-0x0053c367 LivingObjectPane Linked Position And Mode Helpers

## Status

- Disposition: reconstructable `LivingObjectPane` linked-position/mode helper cluster.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Raw/no-xref handling: `0x0053bfa0-0x0053c070` has no direct branch hits and is kept as a private no-invalidate propagation helper within this cluster. It is not recommended as a separate child until a route is proven.
- C++ handling: eligible and supplied.

## Address Range

`0x0053bec0-0x0053c367`, exclusive end.

| Range | Role |
| --- | --- |
| `0x0053bec0-0x0053bf38` | Vtable-routed map position setter. |
| `0x0053bf40-0x0053bf77` | Schedule box-rotation timer event. |
| `0x0053bf80-0x0053bf91` | Cancel box-rotation timer event. |
| `0x0053bfa0-0x0053c070` | Raw/no-xref linked-object mode propagation without owner invalidation. |
| `0x0053c070-0x0053c1c9` | Sync linked objects to owner position. |
| `0x0053c1d0-0x0053c286` | Refresh all linked objects through virtual slot `+0x70`. |
| `0x0053c290-0x0053c367` | Vtable/jump-routed linked-object mode propagation with owner invalidation. |

## Evidence

- `0x0053bec0` has data/vtable refs `0x006209e4` and `0x0062ef74`; no direct `.text` branch hits.
- `0x0053bf40` has five callers; `0x0053bf80` has two callers.
- Branch scan for `0x0053bfa0` is negative; Ghidra decodes calls to linked-object virtual slot `+0x6c`.
- Branch scan for `0x0053c070` found `0x005a859e` and `0x005a876a`.
- Branch scan for `0x0053c1d0` found ten direct branches including `0x0053bf25`, `0x0053c5a3`, movement correction paths `0x005ab090`/`0x005ab410`, and raw `0x005ac24e`.
- Branch scan for `0x0053c290` found `0x005a9244`; export also records data/vtable ref `0x006209f8`.

## Touched Fields / Globals

- `+0x100/+0x104`: actor map tile x/y.
- `+0x170/+0x174`: attached type-2/type-4 lists.
- `+0x1d8/+0x1dc/+0x1e0/+0x1e4`: linked singleton objects.
- `+0x1c4`: movement-active byte.
- `byte_66DA97` / [UID:0000SW] `g_useEpfAssets`: EPF singleton gate.
- `dword_67A764`: active map pane.
- `dword_67AB80`: timer manager.

## Rejected Alternatives

- `0x0053bec0` is not dead code; it is vtable-routed.
- `0x0053bfa0` is not padding; it decodes the same linked-object propagation loop as the routed helper but lacks the owner invalidation.
- `+0x170/+0x174` remain attached-object lists, not singleton ground/shadow fields.

## Per-Child Checklist

- Branch scan: vtable-only for `0x0053bec0`; negative raw helper at `0x0053bfa0`; positive direct branches for sync/refresh/propagate.
- Generated-name rejection: names describe map position, timer, linked sync, refresh, mode propagation.
- Field/type names: tile position, attached lists, linked singleton fields, TimerHandler, `g_useEpfAssets`.
- Caller/no-caller: no-caller raw helper and vtable-only method explicitly classified.
- Owner/source placement: [UID:00007B].
- Rejected alternatives: dead code, padding, wrong field names.

## Score Rationale

Completion `86`: exact ranges, vtable/direct/raw reachability, linked field roles, timer handling, and C++ draft are documented. Confidence `89`: repeated field/loop patterns across helpers strongly validate names; raw helper route remains less certain.
```

### Draft Child Page: Try Step Forward

Create file:

```text
by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool LivingObjectPane::TryStepForward()
{
    if (!m_isMoving)
        return false;

    m_moveFrame = 0;
    m_isMoving = false;

    NxPoint delta = DirectionToTileDelta(m_facing);
    const int nextX = m_tileX + delta.x;
    const int nextY = m_tileY + delta.y;

    MapBounds bounds;
    g_pActiveMapPane->GetVisibleMapBounds(&bounds);
    if (!IsPointInRect(nextY, nextX, bounds))
    {
        g_pActiveMapPane->RejectMove(m_objectId);
        return true;
    }

    const int oldX = m_tileX;
    const int oldY = m_tileY;
    m_tileX = nextX;
    m_tileY = nextY;

    g_pActiveMapPane->MoveObject(this, oldY, oldX, nextY, nextX);
    OnLinkedObjectModeChanged(m_facing);
    SyncPositionToLinkedObjects();
    RefreshAllLinkedObjects();
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053c390-0x0053c5da LivingObjectPane Try Step Forward

## Status

- Disposition: reconstructable exact `LivingObjectPane` movement helper.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Parent split index: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).
- C++ handling: eligible and supplied.

## Address Range

`0x0053c390-0x0053c5da`, exclusive end.

## Behavior

Attempts to consume the movement-active byte, compute the next tile from the facing byte, test map bounds/passability, update owner tile coordinates, move the object in the active map pane, propagate mode/facing to linked objects, sync linked-object positions, refresh linked objects, and return a boolean blocked/failed status.

## Evidence

- Export JSON reports `sub_53C390`, size `0x24a`, signature `char __thiscall(int)`.
- Callers: `0x0053a900`, `0x0053b280`, `0x0053b830`, and `0x005aa480`.
- Callees include direction/point helper `0x004b7c30`, map delta helper `0x00505080`, bounds helper `0x00505290`, bounds test `0x004b7e80`, active map relocation `0x00505940`, linked refresh `0x0053c1d0`, and map rejection/cleanup `0x005060f0`.
- Decompilation clears `+0x1c4/+0x1c6`, computes next tile from `+0x100/+0x104` and facing `+0x1c5`, calls virtual slot `+0x7c` on success, updates linked list/singleton positions, and calls `RefreshAllLinkedObjects`.

## Touched Fields / Globals

- `+0x100/+0x104`: tile x/y.
- `+0x1c4/+0x1c5/+0x1c6`: movement/facing/frame state.
- `+0x170/+0x174`: attached-object lists.
- `+0x1d8/+0x1dc/+0x1e0/+0x1e4`: linked singleton objects.
- `byte_66DA97`: EPF linked-object gate.
- `dword_67A764`: active map pane.

## Rejected Alternatives

- Not a packet parser: callers include timer/config paths and local settings, but body mutates local map position and linked visual objects.
- Not MapPane-owned: MapPane supplies bounds/relocation services; `LivingObjectPane` owns the actor movement state.

## Per-Child Checklist

- Branch scan: positive through export callers.
- Generated-name rejection: `sub_53C390` replaced with `TryStepForward`.
- Field/type names: tile position, direction byte, linked object fields.
- Caller/no-caller: four callers documented.
- Owner/source placement: [UID:00007B].
- Rejected alternatives: packet parser and MapPane ownership.

## Score Rationale

Completion `86`: exact boundary, callers/callees, movement behavior, touched state, and C++ draft are documented. Confidence `88`: behavior is strongly supported; exact map helper type names remain descriptive.
```

### Draft Child Page: BoxRotator Advance

Create file:

```text
by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::BoxRotator::Advance(int)
{
    LivingObjectPane *owner = m_owner;
    owner->m_boxRotationPhase = (owner->m_boxRotationPhase + 1) % 4;
    SetFrameDelay(10);
    owner->Invalidate(false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053d7c0-0x0053d7f4 LivingObjectPane BoxRotator Advance

## Status

- Disposition: reconstructable exact nested helper method.
- Owner/emitter: [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md), nested under [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Source placement: nested/private helper in `LivingObjectPane.cpp`, not a standalone gameplay file.
- C++ handling: eligible and supplied.

## Address Range

`0x0053d7c0-0x0053d7f4`, exclusive end.

## Behavior

Reads the owner pointer from `[this+4]`, advances owner field `+0x1ec` modulo four, calls helper/base method `0x004b6d30(this, 10)`, and invalidates the owning `LivingObjectPane` through virtual slot `+0x20`.

## Evidence

- Export JSON reports `sub_53D7C0`, size `0x34`, signature `int __thiscall(_DWORD *, int)`.
- `.text` branch scan found no direct branch callers.
- Export xrefs show data/vtable ref `0x00620974`.
- [UID:000357] records `0x00620974` as the second slot of `??_7BoxRotator@LivingObjectPane@@6B@`.
- [UID:00007C] records constructor setup at `LivingObjectPane+0x1f0`, owner pointer at `+0x1f4`, and owner rotation phase at `+0x1ec`.

## Touched Fields / Globals

- `BoxRotator+0x04`: owner pointer.
- `LivingObjectPane+0x1ec`: box rotation phase.
- `LivingObjectPane` virtual slot `+0x20`: invalidate/refresh.

## Rejected Alternatives

- Not a top-level `LivingObjectPane` method: durable route is `BoxRotator` vtable slot.
- Not padding/tail filler: exact function and vtable ref exist.
- Not independent class file: decorated vtable name places it as `BoxRotator@LivingObjectPane`.

## Per-Child Checklist

- Branch scan: no direct branch; vtable data route at `0x00620974`.
- Generated-name rejection: `sub_53D7C0` replaced with nested `BoxRotator::Advance`.
- Field/type names: owner pointer, box rotation phase.
- Owner/source placement: [UID:00007C] under `LivingObjectPane.cpp`.
- Rejected alternatives: top-level method, padding, standalone helper file.

## Score Rationale

Completion `87`: exact range, vtable route, constructor field setup, owner-state mutation, and C++ draft are documented. Confidence `91`: decorated RTTI/vtable and constructor evidence strongly identify the nested helper.
```

### Draft Child Page: Name Visibility Vtable Methods

Create file:

```text
by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md
```

Full page body after validator assigns the UID:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LivingObjectPane::ShowName()
{
    m_nameVisible = true;
}

void LivingObjectPane::HideName()
{
    m_nameVisible = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0053d800-0x0053d818 LivingObjectPane Name Visibility Vtable Methods

## Status

- Disposition: reconstructable exact `LivingObjectPane` tiny vtable method pair.
- Owner/emitter: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Parent split index: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).
- C++ handling: eligible and supplied.

## Address Range

`0x0053d800-0x0053d818`, exclusive end.

| Range | Current name | Signature | Role |
| --- | --- | --- | --- |
| `0x0053d800-0x0053d808` | `sub_53D800` | `void __thiscall(_BYTE *)` | Set name-visible byte. |
| `0x0053d808-0x0053d810` | alignment | raw `0xcc` | Not source code. |
| `0x0053d810-0x0053d818` | `sub_53D810` | `void __thiscall(_BYTE *)` | Clear name-visible byte. |

## Evidence

- Export JSON reports both exact 8-byte functions.
- `.text` branch scan found no direct branch callers.
- Export xrefs show data/vtable refs `0x006209f0 -> 0x0053d800` and `0x006209f4 -> 0x0053d810`.
- Bodies are exact byte writes: `this[465] = 1` and `this[465] = 0`.
- [UID:0001DE] raw byte review records `0x0053d818-0x0053d820` as alignment before the next owner range.

## Touched Fields / Globals

- `this+0x1d1` / byte `465`: `m_nameVisible`.

## Rejected Alternatives

- Not helper padding: both functions have vtable refs.
- Not nameplate object creation/removal: no allocation or attached-list access; only toggles the visibility byte.

## Per-Child Checklist

- Branch scan: no direct branch; vtable data refs present.
- Generated-name rejection: `sub_53D800`/`sub_53D810` replaced with `ShowName`/`HideName`.
- Field/type names: `m_nameVisible`.
- Owner/source placement: [UID:00007B].
- Rejected alternatives: padding and nameplate object ownership.

## Score Rationale

Completion `86`: exact boundaries, vtable refs, byte behavior, field name, and C++ draft are documented. Confidence `90`: the body is trivial and vtable-routed; only original virtual slot names are inferred.
```

## Continuation Coverage Text

This replacement text is executable because it uses exact filenames and TMP links. Apply only after the proposed child files exist. If the supervisor validates children first and has real UIDs, replace each TMP link with the validator-resolved UID link before insertion. Do not insert unassigned placeholder UID rows.

Placement: replace the existing [UID:0001DE] block under the `0x0053a110` coverage placement, preserving already-existing accepted child rows as needed.

```markdown
    - [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) 0x0053a110-0x0053d818 | mixed source-family split index | LivingObjectPaneCore : ignored : 88% : strong : Non-emitting split/index for the broad object-pane neighborhood; exact LivingObjectPane children, BoxRotator children, raw/no-xref helper candidates, compiler padding/lowered data, and non-Living sibling ranges are classified here, but no formal C++ should be emitted from the aggregate.
        - [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) 0x0053a110-0x0053a6a6 | method-cluster | LivingObjectPaneConstructionAndCleanup : reconstructable : 86% : strong : Constructor variants and non-deleting cleanup body with exact boundaries, class owner route, vtable stores, BoxRotator setup at `+0x1f0`, registry/list setup, active-effect cleanup, linked-object cleanup, and map-global cleanup evidence.
        - [TMP:"by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md"] 0x0053a6b0-0x0053aae9 | method/helper cluster | LivingObjectPaneSpriteConfigHelpers : reconstructable : 86% : strong : Opposite-direction helper plus render-bounds, sprite-config copy, sprite-config set, and sprite-config initialization helpers; exact callers/vtable refs, sprite block `+0x178..+0x1bc`, timer ownership, and first-draft C++ documented.
        - [TMP:"by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md"] 0x0053aaf0-0x0053aeb4 | method/helper cluster | LivingObjectPaneLinkedObjectSetupHelpers : reconstructable : 86% : strong : Sprite attribute/moving setters, linked-object destruction, raw list-only cleanup, attached-list insert/replace helpers, and singleton ground/shadow/EPF/nameplate setters; field roles and raw/no-xref handling documented.
        - [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md) 0x0053aec0-0x0053b012 | helper-method | AttachedObjectDetachRegistry : reconstructable : 88% : strong : LivingObjectPane attached-overlay deregistration method; sole live caller is `AttachedObjectPane::~AttachedObjectPane`, while constructor/setup and neighboring cleanup/replacement helpers prove LivingObjectPane owns registry list fields `+0x170/+0x174` and singleton slots `+0x1d8/+0x1dc/+0x1e0/+0x1e4`.
        - [TMP:"by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md"] 0x0053b060-0x0053b6b3 | method/helper cluster | LivingObjectPaneEffectMovementAndActionHelpers : reconstructable : 86% : strong : Active-effect raw helpers, clear effects, highlight/BoxRotator toggle, damage effect, begin move-to, facing setter, and action animation/effect helper; raw no-xref starts and first-draft C++ documented.
        - [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) 0x0053b700-0x0053baa8 | method-cluster | LivingObjectPaneAnimationTimer : reconstructable : 86% : strong : Animation playback wrappers and embedded timer-handler callback cluster with verified TimerMgr events, owner offset math, vtable/caller evidence, and stale SoundManager name rejection.
        - [TMP:"by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md"] 0x0053bab0-0x0053bb1d | method cluster | LivingObjectPaneNameplateSpecialEffectHelpers : reconstructable : 86% : strong : Nameplate/effect request helper and special-effect removal helper using active MapPane, object id, constants `134`/`135`, and attached type-4 list `+0x174`.
        - [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md) 0x0053bb20-0x0053beb6 | render-method split index | LivingObjectPaneRenderFrameMethods : ignored : 88% : strong : Non-emitting render-method aggregate; exact child pages carry the three vtable methods and alignment coverage.
            - [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md) 0x0053bb20-0x0053bd1c | method | LivingObjectPaneRenderFrame : reconstructable : 86% : strong : Main living-object render method with vtable refs, map/render mode checks, human/monster draw split, and optional marker overlay behavior.
            - [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md) 0x0053bd20-0x0053bdb1 | method | LivingObjectPaneDrawSpriteFrame : reconstructable : 85% : strong : Compact sprite-frame draw method with vtable refs and human/object image draw dispatch.
            - [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) 0x0053bdc0-0x0053beb6 | method | LivingObjectPaneComputeRenderBounds : reconstructable : 86% : strong : Vtable bounds helper that combines map coordinates, sprite frame dimensions, standing/elevation state, and writes caller rectangle output.
        - [TMP:"by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md"] 0x0053bec0-0x0053c367 | method/helper cluster | LivingObjectPaneLinkedPositionAndModeHelpers : reconstructable : 86% : strong : Map-position setter, BoxRotator timer schedule/cancel, raw linked-mode propagation, linked position sync, linked object refresh, and routed linked-mode propagation; vtable/direct/raw reachability documented.
        - [TMP:"by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md"] 0x0053c390-0x0053c5da | method | LivingObjectPaneTryStepForward : reconstructable : 86% : strong : Movement step helper that tests direction, map bounds/passability, moves owner and linked objects, refreshes linked objects, and returns blocked/failed status.
        - [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) 0x0053d030-0x0053d053 | scalar-deleting-destructor | LivingObjectPaneBoxRotatorScalarDeletingDestructor : reconstructable : 85% : strong : Exact nested `LivingObjectPane::BoxRotator` scalar deleting destructor with vtable slot evidence, constructor vptr stores, owner pointer setup, and size-8 conditional delete.
        - [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) 0x0053d430-0x0053d589 | scalar-deleting-destructor | LivingObjectPaneScalarDeletingDestructor : reconstructable : 86% : strong : LivingObjectPane scalar deleting destructor with vtable/data refs, cleanup callees, map-global cleanup, linked-object/effect teardown, and pool free target `0x0069b894`.
        - [TMP:"by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md"] 0x0053d7c0-0x0053d7f4 | nested-helper-method | LivingObjectPaneBoxRotatorAdvance : reconstructable : 87% : strong : Second `LivingObjectPane::BoxRotator` vtable slot; reads owner pointer, advances owner rotation phase `+0x1ec` modulo four, calls frame handler, and invalidates owner.
        - [TMP:"by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md"] 0x0053d800-0x0053d818 | vtable-method cluster | LivingObjectPaneNameVisibilityVtableMethods : reconstructable : 86% : strong : Tiny vtable-routed ShowName/HideName pair that sets and clears name-visible byte `this+0x1d1`.
```

Coverage/support rows for the earlier micro-page list should wait. Do not add rows for individual micro-pages such as `0x0053a8c0-0x0053a8fe` unless those micro-pages are later created and validated with their own UIDs.

## Continuation Compliance Checklist

- Executable child creation plan: eight concrete `by-memory` filenames are listed, with validator-owned UID assignment and TMP reference workflow. Parent/support/coverage edits are explicitly delayed until child files exist, unless the supervisor uses TMP links and validates them.
- Full child content: each of the eight proposed child pages has a complete body draft with metadata, exact range, owner/emitter route, signatures/calling conventions, behavior, raw evidence, caller or no-caller proof, touched fields/globals/resources, rejected alternatives, C++ readiness, score rationale, and a per-child evidence checklist.
- First-draft C++: every proposed child clears the combined code gate and has an emitter, so each child page draft includes a first-draft C++ body. The broad parent [UID:0001DE] remains non-emitting with the already accepted target-specific no-code proof.
- Raw/no-xref routing: `0x0053ad10`, `0x0053b060`, `0x0053b0e0`, `0x0053b190`, and `0x0053bfa0` are not proposed as standalone children in this executable split. They are documented as private source-shaped helpers inside reconstructable cluster pages with `RECONSTRUCTABLE:TRUE`, nonblank cluster emitters, and draft helper bodies; no separate `RECONSTRUCTABLE:FALSE` raw child is recommended.
- Historical coverage draft: the earlier unassigned-UID coverage block is explicitly excluded from application and retained only as superseded traceability. The applyable coverage replacement is only `## Continuation Coverage Text`, and it uses real existing UIDs plus TMP links for concrete filenames.
- Edit ban compliance: B001 did not edit `by-memory/-coverage-report.md`, by-* docs, generated reports/source, or IDA DB in this continuation; all supervisor-owned edits remain written as pending report text.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001DE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
