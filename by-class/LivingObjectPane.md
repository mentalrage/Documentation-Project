*** UID:00007B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LivingObjectPane.h"
#include "../util/PoolAllocator.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_LIVINGOBJECTPANE_H
#define NEXUSTK_MAP_LIVINGOBJECTPANE_H

#include "ObjectPane.h"
#include "../ui/core/FrameMgr.h"

class Motion;
class List;
class AttachedObjectPane;
class BalloonObjectPane;
class EffectObjectPane;
class HitBarObjectPane;
class DamageNumberObjectPane;
class ObjectInfoObjectPane;
class BowGaugeObjectPane;
class FittingRoomListPane;
class NewInventoryPane;
class GrafPort;
struct NxRect;

class LivingObjectPane : public ObjectPane
{
public:
    enum TimerMessage
    {
        kLivingTimerForwardStep = 0x41645746,
        kLivingTimerBoxStep = 0x41534246,
        kLivingTimerDirectionDelay = 0x43684469,
        kLivingTimerFrameAnimation = 0x446e4146,
        kLivingTimerRefresh = 0x52654461
    };

    class BoxRotator : public FrameHandler
    {
    public:
        explicit BoxRotator(LivingObjectPane *owner) : m_owner(owner) {}
        virtual ~BoxRotator() {}

        virtual void Advance(int frame);
        void Start();
        void Stop();

    private:
        friend class LivingObjectPane;
        LivingObjectPane *m_owner;
    };

    LivingObjectPane(
        int objectId,
        int mapX,
        int mapY,
        const ObjectStatusBlob &objectStatus,
        unsigned char facing);
    LivingObjectPane(int objectId, int mapX, int mapY, unsigned char facing);
    virtual ~LivingObjectPane();

    void GetSpriteConfig(ObjectStatusBlob *out) const;
    bool SetSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    void InitializeSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    bool HasGMNameSuffix() const;

    void SetMovingState(bool moving);
    void DestroyAllLinkedObjects();
    void DestroyAttachedObjects();
    void SetBalloonObjectPane(BalloonObjectPane *pane);
    void AddPrimaryEffectObjectPane(EffectObjectPane *pane);
    void AddSecondaryEffectObjectPane(EffectObjectPane *pane);
    void SetHitBarObjectPane(HitBarObjectPane *pane);
    void SetDamageNumberObjectPane(DamageNumberObjectPane *pane);
    void SetObjectInfoObjectPane(ObjectInfoObjectPane *pane);
    void UnregisterAttachedObjectPane(AttachedObjectPane *pane);

    void AddMotion(Motion *effect);
    void RemoveMotion(Motion *effect);
    void ClearAllEffects();
    void SetCurrentMotion(Motion *effect);
    void SetHighlightState(bool highlighted);
    void ShowDamageEffect(int value, short soundId);
    bool BeginMoveTo(int x, int y, unsigned char facing, short stepDelay);
    void SetFacing(unsigned char facing);
    void PlayAnimation(unsigned int animationGroup);
    void PlayFacingAnimation();
    void PlayDeathAnimation();
    void RequestNameplateEffect();
    void RemoveSpecialEffect();
    void ScheduleBoxRotationStep();
    void CancelBoxRotationStep();
    void ApplyLinkedObjectMode(int mode);
    void SyncPositionToLinkedObjects();
    void RefreshAllLinkedObjects();

    virtual void GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const;
    virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target, const RectBounds *bounds);
    virtual void SetMapPosition(int x, int y);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void PlayActionAnimationOrEffect(
        unsigned action,
        int value,
        unsigned char facing);
    virtual void ShowName();
    virtual void HideName();
    virtual void PropagateLinkedObjectMode(int mode);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    friend class MapPane;
    friend class Motion;
    friend class BowGaugeObjectPane;
    friend class FittingRoomListPane;
    friend class NewInventoryPane;

    bool TryStepForward();

protected:
    unsigned char m_nameState;
    wchar_t m_nameBuffer[33];
    unsigned int m_objectInfoType;
    List *m_primaryEffectObjectPanes;
    List *m_secondaryEffectObjectPanes;
    ObjectStatusBlob m_objectStatus;
    List *m_activeEffects;
    Motion *m_currentEffect;
    bool m_isMoving;
    unsigned char m_facing;
    signed char m_moveFrame;
    unsigned int m_animationFrame;
    unsigned int m_animationGroup;
    bool m_terminalAnimation;
    bool m_nameVisible;
    unsigned int m_boxRotationStep;
    BalloonObjectPane *m_balloonObjectPane;
    HitBarObjectPane *m_hitBarObjectPane;
    DamageNumberObjectPane *m_damageNumberObjectPane;
    ObjectInfoObjectPane *m_objectInfoObjectPane;
    bool m_highlighted;
    unsigned int m_boxRotationPhase;
    BoxRotator m_boxRotator;
    unsigned int m_renderEffectState;
    RectBounds m_bounds;
};

typedef char LivingObjectPaneSizeMustBe524[
    sizeof(LivingObjectPane) == 0x20c ? 1 : -1];

#endif // NEXUSTK_MAP_LIVINGOBJECTPANE_H
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001PY BowGauge Paint Access - 2026-07-21

- The complete managed declaration adds only the forward declaration `class BowGaugeObjectPane;` and `friend class BowGaugeObjectPane;`; every prior method, field, access section, offset, size guard, owner/emitter route, and child insertion point remains byte-for-byte unchanged.
- [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) directly reads protected `m_nameVisible` at `+0x1d1` through `g_pUserPane`. Friendship is the narrow C++03 source-safe route that preserves the observed access without exposing the field publicly or inventing a getter absent from the binary.
- BowGauge remains owned/emitted by [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) and [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). This friendship does not move BowGauge code, storage, or lifecycle into LivingObjectPane.cpp and adds no layout bytes.
- Rejected alternatives are a public `m_nameVisible`, a new accessor, opaque cast, duplicate field, UserPane ownership of BowGauge paint, or source colocation used as a substitute for compile-visible access. None is supported by a callable binary method or the exact standalone BowGauge source route.
- Scores remain `92/93`; this bounded access declaration removes the BowGauge compile blocker while preserving the complete current MapPane/Motion/shared LivingObjectPane union.

## UID0003UJ / UID00030B Ownership Exclusion - 2026-07-16

- [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) is current retained source-bearing `UserPane::TryDispatchFunctionKeyShortcut(short,unsigned int)` at `92/93`, owner/emitter UID0000FQ. It is not a LivingObjectPane member, declaration, source child, blank/no-code target, or covered-by range.
- [UID:00030B][0x0069bf74-0x0069bf78.g_lastFunctionKeyTick](by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md) is current zero-initialized UserPane.cpp file-scope storage at `90/92`, owner/emitter UID0000P1, position `5`. It is not a LivingObjectPane class field or LivingObjectPane.cpp support declaration.
- The target receiver calls current UserPane-only `UseCommandSlot` and sits in the UserPane source island. The standalone LivingObjectPane layout ends at `0x20c`; no class field, method, vtable slot, or source dependency on this page owns the legacy shortcut state.
- Exact target behavior is signed-short row selection, unsigned wrap-aware debounce, direct Config legacy rows, signed-low-byte classification, nonalpha return, ASCII slots `1..52`, and classifier-accepted non-ASCII `0xff`. No write to the zero-initialized global is invented.
- No surviving entry route exists, but that negative evidence now supports retained legacy UserPane liveness classification rather than LivingObjectPane ownership or formal suppression. Historical B015/B001 LivingObjectPane/no-writer/blank conclusions below remain dated provenance only.
- The complete LivingObjectPane declaration, `0x20c` layout, linked-object/effect/timer/render methods, scores, owner/emitter UID0000KU, size guard, vtable cause, and every unrelated child remain unchanged.

## UserPane Action-Tail Ownership Correction - 2026-07-15

- UID0003H5 `UserPane::SendAutoFaceDirectionPacket`, UID0003UZ `UserPane::SendActionPacketWithAutoFace`, and UID0003EB `UserPaneActionNegativeOneFloatConstant` are not current LivingObjectPane-owned inventory. Their receiver offsets beyond the `0x20c` standalone LivingObjectPane layout belong to the UserPane extension.
- UID0003H5 and UID0003UZ emit through UID0000FQ/UID0000P1 UserPane; UID0003EB is compiler-pooled support owned/emitted by UID0000P1 and covered by those two method literals.
- The complete LivingObjectPane class declaration above and all unrelated LivingObjectPane methods, fields, vtable evidence, and dependencies remain unchanged. Older action-tail ownership claims below are retained only where explicitly labeled historical/superseded.

## UID0003Z4 Linked-Object Source Closure - 2026-07-14

- The complete class declaration now exposes the exact primary/secondary EffectObjectPane pointer Lists at `+0x170/+0x174` and typed Balloon, HitBar, DamageNumber, and ObjectInfo singleton pointers at `+0x1d8/+0x1dc/+0x1e0/+0x1e4`.
- The target split is [UID:0004QF][0x0053aaf0-0x0053ab1a.LivingObjectPaneSetSpriteAttribute](by-memory/0x0053aaf0-0x0053ab1a.LivingObjectPaneSetSpriteAttribute.md), [UID:0004QG][0x0053ab20-0x0053ab3a.LivingObjectPaneSetMovingState](by-memory/0x0053ab20-0x0053ab3a.LivingObjectPaneSetMovingState.md), [UID:0004QH][0x0053ab40-0x0053ad03.LivingObjectPaneDestroyAllLinkedObjects](by-memory/0x0053ab40-0x0053ad03.LivingObjectPaneDestroyAllLinkedObjects.md), [UID:0004QI][0x0053ad10-0x0053ad9f.LivingObjectPaneDestroyAttachedObjects](by-memory/0x0053ad10-0x0053ad9f.LivingObjectPaneDestroyAttachedObjects.md), [UID:0004QJ][0x0053ada0-0x0053adb0.LivingObjectPaneSetBalloonObjectPane](by-memory/0x0053ada0-0x0053adb0.LivingObjectPaneSetBalloonObjectPane.md), [UID:0004QK][0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane](by-memory/0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane.md), [UID:0004QL][0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane](by-memory/0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane.md), [UID:0004QM][0x0053ae70-0x0053ae80.LivingObjectPaneSetHitBarObjectPane](by-memory/0x0053ae70-0x0053ae80.LivingObjectPaneSetHitBarObjectPane.md), [UID:0004QN][0x0053ae80-0x0053ae90.LivingObjectPaneSetDamageNumberObjectPane](by-memory/0x0053ae80-0x0053ae90.LivingObjectPaneSetDamageNumberObjectPane.md), and [UID:0004QO][0x0053ae90-0x0053aeb4.LivingObjectPaneSetObjectInfoObjectPane](by-memory/0x0053ae90-0x0053aeb4.LivingObjectPaneSetObjectInfoObjectPane.md).
- Following [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) uses the same typed fields and the public ObjectPane type accessor. Full cleanup calls the retained private detach helper, preserves exact delete/detach/null/list order, and retains the effect-ID 134 special cleanup.
- Protected placement is required by already accepted UserPane source that reads inherited movement/effect fields. MapPane and Motion friendship remain unchanged. The declaration adds no layout bytes and preserves exact size `0x20c`.
- Historical `m_type2AttachedObjects`, `m_type4AttachedObjects`, linked ground/shadow/EPF/nameplate fields, `DestroyLinkedObjects`, `ClearAttachedObjects`, and generic Insert/Set aliases are rejected by concrete type-2/4/6/7/8/9 constructor and unregister evidence. They remain search provenance only and are not current source names.

## UID00037X MapPane Screen-Interpolation Support - 2026-07-14

- The complete managed declaration adds only `friend class MapPane` and preserves the existing `friend class Motion`, all methods, exact `0x20c` layout, size guard, and `[[CHILDREN]]` placement.
- UID0004Q8 directly reads `m_isMoving` at `+0x1c4`, `m_facing` at `+0x1c5`, and signed `m_moveFrame` at `+0x1c6` after ObjectPane type `kObjectPaneTypeLiving` selects this class. It applies direction-to-tile offset and tile-pixel interpolation without binary accessor calls.
- Friendship records that binary-proven direct access without exposing movement state publicly or inventing getters. It does not move GetObjectScreenPoint into LivingObjectPane and does not alter Motion's independent friend access.
- Scores, owner/emitter, source route, class size, vtable surface, timer/effect/link fields, and all unrelated evidence remain unchanged.

## Historical / Superseded UID0002QY Accepted Callback Synchronization - 2026-07-14

- At the UID0002QY callback stage, this became the authoritative source-facing `class LivingObjectPane : public ObjectPane` declaration, preserving inherited EventHandler and TimerHandler adjusted views through Pane, the exact `0x128` base boundary, the naturally aligned `0x20c` complete-object size, children insertion point, and unrelated child work.
- That declaration established the 68-byte ObjectStatusBlob at `+0x178`, `List *m_activeEffects` at `+0x1bc`, `Motion *m_currentEffect` at `+0x1c0`, animation/name/link/render fields, and embedded eight-byte BoxRotator at `+0x1f0` without cloning a LivingSpriteConfig overlay or inventing an inter-class timer-handler member.
- `friend class Motion;` remains the source-legal access route for Motion::OnTimer and the Motion helpers. Protected access, nested Motion, public raw fields, opaque casts, invented accessors, a forward-only token, and a partial duplicate class remain rejected.
- The then-used `ClearAttachedObjects` declaration is superseded by current `DestroyAttachedObjects` and `DestroyAllLinkedObjects`; the `AddMotion`, `RemoveMotion`, `SetCurrentMotion`, and `ApplyLinkedObjectMode` declarations remain current. UserPane-only large-offset functions remain excluded from this `0x20c` base.
- That callback raised metadata to `92/93` while retaining owner/emitter UID0000KU and reconstructable true. Current metadata and the exact typed linked-object declarations are in the managed block above.

# LivingObjectPane

## NewInventoryPane Protected-Field Route - 2026-08-16

- [UID:000544][0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket](by-memory/0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket.md) directly reads inherited `g_pUserPane->m_nameVisible` before sending opcode `0x08`.
- `friend class NewInventoryPane;` is the narrow C++03 source route for that observed protected-state access. It does not publicize `m_nameVisible`, add a getter, duplicate storage, change layout, or transfer ownership.
- Existing `92/93` metadata remains justified: this is a declaration/access synchronization, not new LivingObjectPane behavior.
## UID0000LU Owner Header Placement - 2026-08-15

The existing complete LivingObjectPane declaration was moved to `map/LivingObjectPane.h`; its CPP includes that owner header before all existing children. The header retains the full `0x20c` class, nested BoxRotator, fields, virtuals, friends, and ObjectPane inheritance rather than introducing a reduced target-only declaration.

This route is owned by UID00007B under file UID0000KU. The earlier report token UID000096 referred to NewMailDialog and is corrected here; NewSpell uses the actual LivingObjectPane owner and inherited `GetObjectId`/`GetMapPosition` contracts.

## UID0003TX Object-Info Type Field Integration - 2026-07-16

- The complete `0x20c` LivingObjectPane declaration and all shared method/field content remain unchanged except the size-neutral source-facing rename at `+0x16c`: `m_nameStateToken` is superseded by `unsigned int m_objectInfoType`.
- UID0003TX is the direct producer: after the by-value MapPane factory returns a LivingObjectPane, the handler stores the packet object-info type at `+0x16c`, then branches on the same value to choose ObjectInfo label behavior. No consumer supports token, counter, pointer, or name-state semantics.
- The fixed 33-wide `m_nameBuffer` at `+0x12a` remains separate from this dword. The target copies its ACP-converted name there before storing `m_objectInfoType`.
- MapPane friendship remains the compile-visible source route for direct writes to `m_nameBuffer`, `m_objectInfoType`, transient state, and linked overlay slots. No accessor or runtime wrapper is invented.
- Existing linked-object/effect methods, `ObjectStatusBlob` state, `m_objectInfoObjectPane` at `+0x1e4`, Motion integration, `0x20c` size guard, and `[[CHILDREN]]` order are preserved byte-for-byte around this rename.
- Historical `m_nameStateToken` references remain useful only as a superseded alias. Vtable stores, adjustors, scalar deleting wrappers, allocation/free lowering, and owner cleanup are compiler-generated or exact child-owned and remain outside the class declaration.

## UID0003TH Status And Hit-Bar Slot Consumer - 2026-07-15

- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md) consumes `m_objectStatus.m_statusKind`, `GetMapPosition`, and the typed `m_hitBarObjectPane` owner slot while creating a temporary HitBarObjectPane from the MapPane opcode-`0x13` route.
- The helper selects style `1` only for `ObjectStatusBlob::HumanObject` and style `0` otherwise, obtains this object's map row/column, and installs the constructed pane with `SetHitBarObjectPane`. That setter is the direct borrowed-pointer store at `+0x1dc` already modeled by the exact setter child.
- UID0003TH does not read, remove, or delete a preexisting `m_hitBarObjectPane` before overwriting the slot. Later timer/destructor paths retain their existing cleanup responsibilities.
- Score `92/93`, owner/emitter UID0000KU, complete layout and formal C++, all field offsets/types, and every unrelated method/consumer remain unchanged.

## Current UID0002QY Source Boundary - 2026-07-14

- Current declaration authority: the managed block above is the complete source-facing `class LivingObjectPane : public ObjectPane`, size `0x20c`, with MapPane, Motion, and BowGaugeObjectPane friendship, Motion-pointer List/current Motion fields, ObjectStatusBlob, nested BoxRotator, exact method surface, and `[[CHILDREN]]`.
- Current ownership boundary: LivingObjectPane.cpp owns only the `0x20c` base-class source family and unchanged UID0003UU file-local message-show helper. The 33 large-offset local-player methods are UserPane members; UID0003UT and UID0003H4 are UserPane.cpp file-local/static helpers.
- Current exclusion: no current LivingObjectPane class method, owner/emitter route, declaration, recommendation, or blank/no-code policy applies to those 35 moved UserPane pages.
- Current evidence retention: all valid base-layout, Motion, rendering, timer, RTTI, vtable, constructor/destructor, caller, negative-route, and packet evidence nested below remains retained; only the prior local-player ownership/qualification and blank-body conclusions are superseded.

## Historical / Superseded Assumptions - Pre-2026-07-14

- Date/source: the nested LivingObjectPane class material below records earlier source-quality passes incorporated before the final UID0002QY UserPane ownership and integration repair.
- Rejected claim: UserPane-only large-offset bodies belonged to LivingObjectPane/LivingObjectPane.cpp, retained reverse-engineering qualifiers/placeholders, or required blank/no-code treatment because a direct route or declaration was missing.
- Disproof evidence: the complete LivingObjectPane object ends at `+0x20c`; receiver-bearing moved bodies use UserPane-only `+0x134000..+0x13eb84` state, the two no-receiver helpers cluster with UserPane source, and the complete UID0000FQ/UID0000P1 declaration/definition route compiles those bodies without an access or type gap.
- Accepted replacement: 33 UserPane members and two UserPane.cpp file-local/static helpers, each with its current nonblank managed body. UID0003UU remains the explicit unchanged LivingObjectPane.cpp exception.
- Evidence preservation: factual bytes, ranges, callers, xrefs, fields, ABI, packet behavior, negative evidence, and provenance below remain valid evidence unless a nested sentence states one of the rejected conclusions above.

### Status

- Confidence: strong for source/file/class ownership, primary method families, scattered accessor ownership, vtable/static-pool evidence, and local-player inventory dispatch ownership; medium-high for class-level field names and adjusted local-player layout; medium for original names and reachability of several raw local-player helper-shaped bodies.
- Likely source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Historical generated projection notes remain useful only as prior naming/search context, not as evidence for the 2026-06-05 score update.
- Autogen status: reconstructable class attached to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md); broad class C++ is intentionally blank until the class declaration, base/subobject layout, adjusted local-player fields, packet-tail structs, and complete virtual prototype list are source-quality. B001's 2026-06-26 supervisor-verification rework resolved the render children far enough for formal first-draft child C++ in [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md), [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md), and [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md). B007's 2026-06-26 timer pass resolves [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) as ready/emitting in the exact child with verified timer constants and adjusted `TimerHandler` owner math. B007's 2026-07-04 [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) pass raises the construction/cleanup child to `87/90` with current MCP session `nexustk_supervisor_20260704` evidence and a target-specific no-code proof; UID0002R0 remains an expected Empty Emitter Marker because it spans two constructor variants plus the ordinary destructor/cleanup body and exact declarations are not source-ready. These exact-child updates do not make this broad class page a declaration source yet.

B001's 2026-07-08 accepted [UID:0002WL][0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) callback resolves the exact static-pool child as `static PoolAllocator g_livingObjectPanePool(0x20c, 0x20);`. The declaration is target-local static data under the LivingObjectPane source route; it does not make this broad class page emit a full class declaration.

### Class Purpose

`LivingObjectPane` represents a living map actor. It owns actor position, facing, render bounds, sprite configuration, animation state, linked ground/shadow/EPF/nameplate objects, active effects, movement prediction history, spell/command slot dispatch, and network packets that mutate or report living-object state.

It is a gameplay map object class, not a generic UI panel. It derives through the pane/object-pane stack and is rendered by [UID:00007Q][MapPane](by-class/MapPane.md), but most of its behavior is entity state and server protocol handling.

The nested `LivingObjectPane::BoxRotator` helper is represented by [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md). B009's 2026-06-26 recheck resolves it as a FrameHandler-style nested helper, not a stale Boost-derived or standalone generated class. Its compiler-generated scalar deleting destructor [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) is marker-covered by [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md), while [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) remains the source-authored callback child.

### Active Effects, Movement, And Action Effects

[UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md) is now a direct `88/90` exact child emitted through this class. B005's 2026-07-06 source-quality callback keeps the owner/emitter route on [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) / [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), with no broad class C++ change.

The child covers raw active-effect helpers at `0x0053b060`, `0x0053b0e0`, and `0x0053b190`, `ClearAllEffects`, highlight/BoxRotator toggling, damage refresh, `BeginMoveTo`, `SetFacing`, and `PlayActionAnimationOrEffect`. Live MCP session `18aed30a` records the key source-quality repairs: `ClearAllEffects` clears both pending damage/effect state `+0x1f8` and current effect `+0x1c0`; `BeginMoveTo` preserves the conditional moving branch, inline highlight restart, ObjectPane position-setter call, and `FWdA` schedule payload `(stepDelay, facing, stepDelay)`; animated action groups use a provisional word at `+0x12a` rather than stale generated `m_stepCode`; and the non-animated action path inlines active-effect trim/insert before unconditionally scheduling the Motion timer view with `effect != 0 ? effect->GetTimerHandler() : 0`.

The raw helper starts remain no-route/private helper bodies, not standalone pages. The primary vtable slot `+0x70` at `0x006209ec` points to `0x0053b3d0`, and B014's [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md) confirms a live virtual action route for `PlayActionAnimationOrEffect(27, 200, 0)`. B003's [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) remains the owner of the constructed Motion object reached from `0x0053b5f9`; Motion, TimerMgr/TimerHandler, MapPane, SoundManager, ObjectPane, UserPane, and raw packet helpers are dependencies or callers, not owners of this child.

B001's 2026-07-14 [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) pass closes the bounded owner-field ambiguity used by that lifetime. `+0x1bc` is a `List *` of active Motion/effect pointers; `+0x1c0` is the current Motion/effect pointer, not an effect count or timer handle; and `+0x1d1` is the name-visible byte. `Motion::OnTimer` snapshots the list count once, dereferences element storage, removes exactly one matching pointer, clears any nonzero current pointer on completion, queues the primary Motion object for deferred deletion, and refreshes the active MapPane. While active it reschedules the secondary TimerHandler view, discards the scheduler return, and publishes primary `this` to `+0x1c0`. This bounded synchronization does not change the LivingObjectPane score, owner/emitter route, broad blank class declaration, or unrelated tail-layout blockers.

The tail `0x0053b6b3-0x0053b700` is switch/table/padding output attached to [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md), not [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) code. The exact child emits first-draft C++; this broad class page still keeps `RECONSTRUCTION_CPP CODE` blank because the full class declaration, base/subobject layout, adjusted local-player/UserPane fields, packet structs, and full virtual prototype list remain class-level blockers.

### Local-Player Movement History

The local-player extension range uses a movement-history / movement-prediction ring that older pages called "linked records." The best current names are `m_movementHistoryRecords` / short alias `m_movementHistory` at adjusted `this+0x13eb14`, `m_movementHistoryCapacity` at `this+0x13eb18`, and `m_movementHistoryWriteIndex` at `this+0x13eb1c`. Constructor evidence allocates `0x400` bytes for `0x40` records of stride `0x10`, initializes the capacity to `0x40`, clears each record's active byte, and starts the write index at zero.

The recommended record model is `LocalMovementHistoryRecord { active, tileY, tileX, direction }`: byte `+0` marks an active record, dword `+4` stores tile Y, dword `+8` stores tile X, and byte `+0x0c` stores the direction/facing byte. [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) returns a record only when byte `+0` is nonzero and now emits first-draft retained raw-helper C++ as `GetActiveMovementHistoryRecordByIndex(unsigned char)`, with `GetActiveLinkedRecordByIndexRaw` kept as a historical/search alias because no direct entry route is proven. [UID:0003UF][0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords](by-memory/0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords.md) clears every record's active byte and now has matching first-draft clear-all C++. [UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md) is the route-proven indexed clear: it accepts signed `int recordIndex`, rejects negative and `>= m_movementHistoryCapacity` values, and clears only `m_movementHistoryRecords[recordIndex].active`, leaving coordinate/direction payload bytes and `m_movementHistoryWriteIndex` untouched. [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md) and its live opcode `0x04` dispatcher duplicate clear the same first-byte active flag for every record after applying the server-authoritative warp/correction position.

[UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md) has direct movement-handler callers at `0x005ab2f4` in [UID:0003UP][0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket](by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md) and `0x005ab641` in [UID:0003UQ][0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket](by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md). Those handlers parse payload `+0x0a` as a low-seven-bit history index, compare active/coordinate/direction fields, and call the indexed clear after match or correction paths. Mismatch/correction paths call [UID:0003UF][0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords](by-memory/0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords.md) first at `0x005ab2ea` or `0x005ab637`, then share the indexed clear epilogue.

[UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) proves the same ring also acts as a waypoint/history queue for opcode `0x06` movement path packets. Target-local names `m_waypointHistoryRecords`, `m_waypointHistoryCapacity`, and `m_waypointHistoryWriteIndex` are the best aliases when discussing that helper's `LivingObjectWaypointHistoryRecord` role; class-wide docs can retain `m_movementHistory` / `LocalMovementHistoryRecord` because [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) uses the same storage for fixed opcode `0x32` facing-history records. [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) stores the current coordinate copied from `ObjectPane+0x104` at record `+4`, the coordinate copied from `ObjectPane+0x100` at record `+8`, and `waypointKind` at record `+0x0c`; axis labels should remain offset-based until the shared `MapPoint` convention is finalized.

The large offsets `+0x1340f8`, `+0x13eb08`, `+0x13eb0c`, `+0x13eb10`, `+0x13eb14`, `+0x13eb18`, and `+0x13eb1c` are local-player/UserPane aggregate offsets viewed through adjusted `LivingObjectPane` code, not evidence that every base `LivingObjectPane` instance has a compact object layout that large. The `+0x13eb08/+0x13eb0c/+0x13eb10` group is the direct-message/whisper recipient-history state; the `+0x13eb14` group is the movement-history ring.

### Local-Player Viewport Position

[UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) is now an exact source-ready child as `MapPoint *LivingObjectPane::GetViewportPosition(MapPoint *outPosition) const`. It is a leaf thiscall accessor at `0x005a2de0-0x005a2dfb` that copies the cached viewport row/column pair from adjusted local-player fields into a caller-owned `MapPoint` and returns that pointer.

The accepted field/order model is:

| Adjusted offset | Source-facing name | Output slot | Evidence |
| --- | --- | --- | --- |
| `+0x13ead8` | `m_viewportColumn`; aliases `m_viewportX` / `m_viewportOffsetX` | element 1 / `outPosition->x` | Loaded by [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) and written to `[out+4]`; [UID:0003UE][0x005a5a90-0x005a5b79.UserPaneWarpToPosition](by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md) stores its third viewport argument here. |
| `+0x13eadc` | `m_viewportRow`; aliases `m_viewportY` / `m_viewportOffsetY` | element 0 / `outPosition->y` | Loaded by [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) and written to `[out+0]`; [UID:0003UE][0x005a5a90-0x005a5b79.UserPaneWarpToPosition](by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md) stores its fourth viewport argument here. |

This resolves the old target-level blank-C++ blocker for the exact child. It does not make this broad class page a declaration source: base/subobject layout, adjusted local-player/UserPane aggregation, packet structs, and the full virtual prototype list still keep class-level C++ blank.

### Local-Player Screen Position Cache

[UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) resolves the local-player screen-position cache method as `void LivingObjectPane::UpdateScreenPosition()`. The method is called once from [UID:00037V][0x00509470-0x0050a4fd.MapPaneRenderViewCore](by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md) at `0x00509563`, after the render path loads the active local pane from `MapPane+0x418`. The caller context stays `MapPane`, but the receiver and emitted method body are `LivingObjectPane`.

The method reads inherited `ObjectPane` map coordinates through [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md), converts them through `m_mapPane` at adjusted `+0x1340f8`, builds a facing direction vector from `m_facing` at `+0x1c5`, scales that vector by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), interpolates it with signed `m_moveFrame` at `+0x1c6` and `4 * g_movementSubstepScale`, then writes the local screen center and two screen-space `RectBounds` caches.

Current adjusted local-player field direction from that method:

| Offset | Best current name direction | Confidence | Evidence / caveat |
| --- | --- | --- | --- |
| `+0x3ec4` | `m_localPlayerHitRadius` | Medium-high role, medium original spelling | Initialized from `2 * g_mapTilePixelWidth`; [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) and `UserPane::OnClipBounds` use it as a symmetric half-extent/radius. Descriptive name only. |
| `+0x1340cc` | `m_screenY` / `m_cachedScreenY` | High role, medium original spelling | Written after MapPane map-to-screen conversion, signed movement interpolation, and half-tile-height centering. Large adjusted local-player/UserPane aggregate offset. |
| `+0x1340d0` | `m_screenX` / `m_cachedScreenX` | High role, medium original spelling | Written after MapPane map-to-screen conversion, signed movement interpolation, and half-tile-width centering. Large adjusted local-player/UserPane aggregate offset. |
| `+0x1340d8` | `m_screenHitBounds` | High role, medium original spelling | Full symmetric `RectBounds` initialized as `(x-r, y-r, x+r, y+r)` through `InitRectBounds`. |
| `+0x1340e8` | `m_screenLowerHitBounds` | Medium-high role, medium original spelling | Lower-body/lower-half `RectBounds` initialized as `(x-r, y, x+r, y+r)`. Geometry differs from the full bounds, so do not merge them. |
| `+0x1340f8` | `m_mapPane` | Very high | Cached `MapPane *` copied from `g_activeMapPane` by `UserPane` construction and used by [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) for map-to-screen, direction-to-tile-offset, and direction-offset pixel-scaling helpers. |

This screen cache is a consumer of the local movement state maintained by movement prediction and packet helpers. It does not read or write `m_movementHistoryRecords`, `m_movementHistoryCapacity`, or `m_movementHistoryWriteIndex`.

### Local-Player Inventory Slots

[UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) is source-quality as `LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`. The exact body sign-extends the stack byte argument, adds adjusted local-player base `+0x133f08`, multiplies by `0x1fc`, and returns the record pointer without bounds checks or item-id lookup. Normal UI flows validate one-based selectors before calling; the helper indexes the supplied signed byte directly.

The best source-facing field direction is `m_inventorySlots` at adjusted offset `+0x133f08`, with `LocalInventorySlotRecord` stride `0x1fc`. Confirmed record fields are `active` at `+0x00`, `itemId` at `+0x02`, `iconStyle` at `+0x04`, `displayName` at `+0x06`, `quantityOrCount` at `+0x1e8`, `quantityPromptFlag` at `+0x1ec`, and `targetMode` at `+0x1f8`. The original type/member spellings are not symbol-proven, but these names are the accepted reconstruction names for exact child C++ and support docs.

This helper is not owned by `InventoryPane`, item dialogs, `ClientItemMenuDialog`, or `UserPane` directly. Those paths are broad consumers: B006 found 39 direct calls across employee item commands, AddEmployeeItemDialog, MyItemListPane, add/mix item dialogs, item-help/preview panes, legacy/New/InventoryPane2 drawing and visible-index mapping, client item menus, macro edit-control painting, and system-message formatting. It is also not the command/spell slot table: that separate view remains `g_pUserPane + 0x13a6ec + slot * 0x148`.

[UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) is source-ready as `void LivingObjectPane::UseInventorySlot(unsigned char slot)`. It validates one-based slots `1..52`, obtains the `LocalInventorySlotRecord`, rejects null/inactive records, and interprets `targetMode`: value `0` sends the slot/action to this pane's `m_objectId`; value `1` sends to the current selected pane only when `m_selectedObjectActive == 1` and the selected pane is non-null; failed mode `1` and all remaining modes enter explicit ItemWho selection. That path reads GeneralPurposePanel child index `3` state `m_active +0xfa`, performs normal source construction `new ItemWhoInputPane(slot)` only when inactive, fetches child index `3` again, and calls `SetInputModeFlag(true)`.

The exact target has eight direct code xrefs: legacy InventoryPane `0x004eab81`, NewInventoryPane `0x004ed711`/`0x004ed7fc`, InventoryPane2 `0x004ef0e1`, MapPane keyboard input `0x005070c1`, retained raw compact shortcut mode-zero call `0x005a3ac6`, integrated `ExecuteHotkeyAction` inventory mode `0x005a3ba1`, and UseInputPane submit `0x005b5e51`. These are seven calls in six modeled functions plus one call in a no-entry retained raw body. No caller consumes a semantic result and incompatible exit `AL` residues confirm source `void`.

The expanded allocation, `LineInputPane` base setup, three vtable writes, `Which target?` prompt, `m_itemSlot +0x108`, saved-target lookup/fallback/highlight/save operations, allocator-null branch, EH cleanup funclets, delete, and base cleanup are compiler output for the inlined ItemWho constructor. Final source keeps one ordinary constructor call and no handwritten vtable/EH/delete wrappers. [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md) remains shared packet support rather than class ownership. `UseSpellSlot` is superseded generated history; the paired command/spell method remains `UseCommandSlot`.

### Local-Player Command Slots

[UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md) is source-quality as first-draft `void LivingObjectPane::UseCommandSlot(unsigned char slot)`. It is the spell/command-slot counterpart to [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md), not a generated `SpellManager::SelectSpell` method and not a final `UseSpellSlot` name.

The method validates one-based slots `1..52`, checks adjusted local-player guard byte `+0x13ead4`, indexes `SpellCommandSlotRecord` data at `+0x13a6ec + 0x148 * slot`, tests record byte `+0` as active/populated, switches on record dword `+4` as input kind, reads prompt/name text at `+0x13a794 + 0x148 * slot`, and stores the selected slot byte to prompt panes at `+0x108`.

Accepted record-kind map: `1` string prompt, `2` target/who prompt or immediate targeted opcode `0x0f` send, `3` four-number prompt, `4` three-number prompt, `5` immediate no-argument opcode `0x0f` packet, `6` two-number prompt, `7` one-number prompt, and `8` spell-slot character prompt. The eight direct callers are raw config-hotkey call `0x005a3ab8`, modeled hotkey calls `0x005a3bf2`/`0x005a3c28`/`0x005a3c4e`, raw function-key debounce calls `0x005a92c6`/`0x005a92eb`/`0x005a92ff`, and `SpellSpellInputPane::OnAccept` call `0x005b62bd`. The adjacent switch table `0x005a4908-0x005a4928` and padding `0x005a4928-0x005a4930` are compiler output and must not become class source declarations.

### Historical Local-Player Action Dispatch Ownership Snapshot - Superseded

[UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md) is now source-quality as first-draft `void LivingObjectPane::TryPerformAction()`. The method has two direct statement-form callers: [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) event `7` loads `dword_67A748` / `g_pUserPane` as the receiver, and [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md) calls with `ecx = esi - 0xa0`. This rejects the old `char` return and confirms this is a `LivingObjectPane` action method reached through adjusted local-player/UserPane state.

The accepted field and helper model for this action method is:

| Offset / helper | Best current role | Caveat |
| --- | --- | --- |
| `+0x19a` | `m_actionGateState` / current action-state byte; values `1` and `3` suppress action | Exact original spelling unknown. |
| `+0x182` | primary sprite/equipment attribute id | Read as a word and classified by `ClassifyHumanPartFiveBucket`; existing sprite-config docs also write this offset. |
| `+0x13eaf8` | `m_lastActionTick` | Compared against [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md) `currentTick` and updated only after a successful action send. |
| `+0x184` | secondary sprite/equipment or ammo-capability attribute id | Read as a word and classified by `ClassifyHumanPartTwoBucket`; descriptive name only. |
| `+0x13eb3c` | `m_selectedTargetActionMode` / `m_pendingTargetActionMode` | Mode byte: nonzero participates in the warning gate, values `1` and `2` also trigger post-action animation. |
| `0x004e05d0` / `0x004e0630` | NewHumanImageLib five-bucket and two-bucket classifiers | Not cooldown helpers; this method implements the 500 ms / 100 ms rate gate inline. |

The historical warning-path analysis remains valid at the instruction level. Its ownership conclusion is superseded: [UID:0003UZ][0x005acc30-0x005acd85.UserPaneSendActionPacketWithAutoFace](by-memory/0x005acc30-0x005acd85.UserPaneSendActionPacketWithAutoFace.md) is UserPane source, calls [UID:0003H5][0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket](by-memory/0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket.md), and reaches [UID:0003EB][0x00630c24-0x00630c28.UserPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.UserPaneActionNegativeOneFloatConstant.md) as compiler-pooled UserPane support. These are dependencies/historical context here, not LivingObjectPane inventory.

When `m_selectedTargetActionMode` is `1` or `2`, [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md) dispatches vtable slot `+0x70` as `PlayActionAnimationOrEffect(27, 200, 0)`, implemented by [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md). This confirms the action/effect virtual relationship without making `Motion` or SystemMessagePanes the action method owner.

### Superseded Local-Player Compact Shortcut Dispatcher Ownership

[UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) is not a current `LivingObjectPane` member. Fresh target-specific evidence assigns the retained exact child to [UID:0000FQ][UserPane](by-class/UserPane.md), emitted through [UID:0000P1][UserPane](by-file/UserPane.md) as `UserPane::DispatchConfiguredShortcutHotkey(short, int)`. It reads direct Config `m_compactShortcutRecords` at `g_pConfig + 0x28f29c`; rows contain `wchar_t code` and `unsigned char isSpellMode` with natural tail alignment.

The useful B013 behavior remains historical evidence: selector `0` maps to row `9`, `1..9` to rows `0..8`, `10` to row `19`, and `11..19` to rows `10..18`; signed-low-byte classification maps lowercase to slots `1..26`, uppercase to `27..52`, preserves the `0xff` alpha fallback, and returns on non-alpha. Nonzero `isSpellMode` calls [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md), while zero calls [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md).

Route scans remain negative for the target start/end and positive for its callees and successor, so the body is retained dead/legacy UserPane source rather than an ordinary live entry. The former LivingObjectPane qualification/file route, nested profile record, key/mode/reserved shape, named unused parameter, and current class attachment are superseded provenance. The standalone LivingObjectPane object ends at `+0x20c`; UserPane-only local-player extension state and the paired UserPane callees establish the derived source boundary without changing any genuine LivingObjectPane method, field, layout, vtable, score, or route here.

### Local-Player Message Show Packet Helper

[UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) belongs to the `LivingObjectPane.cpp` local-player packet-helper neighborhood, but it is not an ordinary `LivingObjectPane` class method. The only proven caller is [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) opcode `0x58` at `0x005a8172`; that callsite seeds `ecx = ebx - 0xa0`, but the callee is `ret 4`, loads the packet pointer from `[ebp+8]`, and never reads or writes `LivingObjectPane` fields.

Use this class page as context only: [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) now routes through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) as a file-local/static helper. Its packet layout is `payload[1]` show/close flag, `payload+2` big-endian text byte length, and `payload+4` narrow text. The helper copies into a `char[0x8000]`, converts through `MultiByteToWideChar(CP_ACP,0,...)` into `WCHAR[0x8000]`, updates an existing [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) through `MessageShowPane::SetWrappedText`, constructs a new `MessageShowPane`, or deletes the current overlay through the scalar-deleting destructor flag path. [UID:0000P1][UserPane](by-file/UserPane.md) owns the dispatcher case, and [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md) owns the overlay class/singleton methods.

### Render Frame Method Rework

B001's accepted 2026-06-26 [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md) rework keeps the parent as a non-emitting split/index at `88/90` and treats the three exact children as the source-bearing vtable method pages under this class:

| Child | Score after rework | Source role | C++ disposition |
| --- | --- | --- | --- |
| [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md) | `89/89` | Main living-object render vtable method with map overlay predicates, standing/elevation adjustment, human/monster image draw split, optional marker overlay frames, and `RectBounds`/`GrafPort` helper evidence. | Formal first-draft C++ now emits as `LivingObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)` with inferred MapPane predicate, translated-clip, marker-table, and image-helper names. |
| [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md) | `88/89` | Compact sprite-frame draw vtable method with vtable refs `0x006209e0`/`0x0062ef70` and human/monster dispatch through `0x004db100`/`0x004e0900`. | Formal first-draft C++ now emits as `LivingObjectPane::DrawSpriteFrame(GrafPort *target, const RectBounds *bounds)` using `MonsterImageLib::RenderMonster` and `NewHumanImageLib::RenderHuman` call shapes. |
| [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) | `88/89` | Render-bounds vtable helper with MapPane coordinate conversion, human/monster image dimension helpers, standing/elevation state, and caller `RectBounds` output. | Formal first-draft C++ now emits as `LivingObjectPane::ComputeRenderBounds(RectBounds *outBounds)` and preserves the live output-pointer return contract. |

Live MCP session `80de0a67` supplied the accepted evidence: `server_health` `ok`, schema-correct calls, exact child starts/sizes (`0x1fc`, `0x91`, `0xf6`), vtable/data refs, pre/post `0xcc` padding, and no decorated child source names from `entity_query`. The supervisor-verification rework therefore uses inferred source-facing names for the child formal bodies and records those names on [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md); the lack of decorated names remains a broad declaration caveat, not a reason to leave the child bodies blank.

The overlay marker table correction also belongs with this class context. `0x00620b90` is the UTF-16 `BGAUGE.EPF` / `BGAUGE.pal` resource string neighborhood, not the three-row frame-index table. The rows consumed by [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md) as immediate constants are [UID:0003CC][0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables](by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md) row bases `0x00620c10`, `0x00620c2c`, and `0x00620c48` (decimal bases `6425616`, `6425644`, and `6425672`, verified with `int_convert.py`). That table keeps [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) ownership because IDA reports no direct table xrefs; `LivingObjectPane` is an immediate-constant consumer only.

### Source-Quality Class Declaration Readiness

Do not emit a formal class declaration from this page yet. A by-class page should emit declarations, not method bodies, and the exact method bodies already belong in child by-memory pages. A placeholder class would freeze unresolved choices that the current evidence deliberately keeps open:

- Exact declaration spelling for the timer owner at `+0xa4`. B007 proves the adjusted `TimerHandler` view and callback math (`handler this = owner + 0xa4`, owner recovery `this - 0xa4`), but whether the original header spelled this as an embedded member, facet, inherited adjusted base, or helper subobject remains open.
- The base-class stack and adjusted vtable views from [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md), including final virtual prototypes.
- The `+0x178..+0x1bc` sprite/config block, active-effect/list fields, sprite descriptor/render target declarations, image-library helper signatures, and complete source-facing vtable prototype list. The 2026-06-26 B001 verification rework resolves the three render children enough for first-draft child formal C++, but this page still should not freeze a full class declaration.
- The `0x20c` standalone `LivingObjectPane` pool block versus local-player/UserPane aggregate fields at `+0x13ebxx`, which are reached through adjusted local-player code rather than proving a huge base `LivingObjectPane` object.
- Packet-buffer, movement-history, linked-record, command-slot, inventory-slot, and protocol-tail helper types.
- Raw/no-route helper starts such as `0x005a9250`, `0x005ac1b0`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`, `0x005acb20`, and `0x005a87b0`, retained-duplicate children such as [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md), and routed but non-member local helpers such as [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md), which must not be represented as normal live virtual/member methods from the class declaration without matching receiver evidence. UID0003UA, UID0003UJ, and [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) are excluded from this current LivingObjectPane inventory because their retained exact children belong to UserPane; this preserves their no-live-entry or duplicate-body evidence without polluting this class declaration.

Existing C++ in exact children such as [UID:0003Z3][0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers](by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md), [UID:0003Z4][0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers](by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md), [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md), [UID:0003Z6][0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers](by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md), [UID:0003Z7][0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers](by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md), [UID:0003Z8][0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward](by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md), [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md), [UID:0003ZA][0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods](by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md), and [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) remains child-owned. The class page should keep names, evidence, and blockers in prose until the declaration is source-quality.

B008's UID0003Z3 support sync keeps that child source-ready at `88/90` through the LivingObjectPane file route: `0x0053a700`, `0x0053a8c0`, `0x0053a900`, and `0x0053a9f0` remain LivingObjectPane sprite/config methods, while `0x0053a6b0` is now documented as shared/free `RemapMovementDirectionForMapScroll` because live MCP xrefs show MapPane/UserPane movement callers and no `this` receiver. The raw `0x0053a6f0-0x0053a6fb` island inside UID0003Z3 remains no-code/no-function proof, not a class method.

### Source-Facing Field And Helper Name Direction

These names are strong enough for documentation and search, not for a final emitted declaration.

| Offset/data | Best current name direction | Confidence | Evidence / caveat |
| --- | --- | --- | --- |
| `+0xa4` | `m_timerHandler` or `m_timerFacet` | High role, medium original spelling | Animation and movement methods schedule/cancel through TimerHandler/TimerMgr. B007 proves the adjusted callback view: the callback receives `owner + 0xa4` and recovers `LivingObjectPane` with `this - 0xa4`; exact declaration spelling remains unresolved. |
| `+0xf8` | `m_objectType` | High | Inherited ObjectPane field; living object type is `3`. |
| `+0xfc` | `m_objectId` / `m_serial` | High | Inherited ObjectPane id/serial field. |
| `+0x100` / `+0x104` | `m_mapX` / `m_mapY` | High | Inherited ObjectPane map coordinates; axis labels remain tied to shared map-point convention. |
| `+0x108` | `m_objectDataRect` | High | Inherited ObjectPane data rectangle. |
| `+0x118` | `m_attachedObject` | Medium-high | Inherited attached-object pointer. |
| `+0x11c` | `m_attachmentHeight` / `m_elevationOffset` | Medium | Render/attachment height style field; exact source spelling unresolved. |
| `+0x120` | `m_objectImage` / `m_imageState` | Medium | Object-image state; exact type unresolved. |
| `+0x124` | `m_transientObjectFlag` | Medium | Broad inherited flag; final semantics still open. |
| `+0x126` | `m_nameBuffer` | Medium-high role, medium original spelling | [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) treats this as the actor-owned UTF-16 name buffer base, starts scanning at `this+0x12a`, computes the final two-code-unit suffix, and calls `_wcsicmp(..., L"GM")`. `m_nameBuffer` is the accepted source-facing direction for the first-draft child C++, but exact original field spelling and any inherited/base-class declaration remain unresolved. |
| `+0x170` / `+0x174` | `m_type2AttachedObjects` / `m_type4AttachedObjects` | Medium-high | Attached-list family; exact enum/source names unknown. |
| `+0x178..+0x1bc` | `m_spriteConfig` / `m_livingSpriteConfig` | Medium-high | Sprite/config helpers cover a 68-byte style block; [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md), [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md), and [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) all consume it in the render path; final struct layout unresolved. |
| `+0x1bc` / `+0x1c0` | `m_activeEffects` / `m_currentEffect` | High | [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md) allocates/inserts/schedules Motion objects, while [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) proves `+0x1bc` is a `List *` of active effect pointers and `+0x1c0` is the current primary Motion/effect pointer. The scheduler return is ignored, rejecting historical timer-handle/count/state interpretations. |
| `+0x1c4` | `m_isMoving` / `m_movementActive` | Medium-high | Movement, position-sync, sprite-config, and render children test or set movement-active state. |
| `+0x1c5` | `m_facing` | High | Facing byte used by movement, render, and action paths. |
| `+0x1c6` | `m_moveFrame` / `m_stepFrame` | Medium-high | Movement/forward-step frame state; render children use it for moving-frame draw/bounds selection. |
| `+0x1c8` / `+0x1cc` | `m_animationFrame` / `m_animationGroup` | Medium-high / Medium | Animation frame and group/id fields used by sprite draw and bounds helpers; source enum unresolved. |
| `+0x1d0` / `+0x1d1` | `m_terminalAnimation` / `m_nameVisible` | Medium-high / High | Death/terminal animation flag set by `PlayDeathAnimation` and consumed by the `FAnD` frame-animation timer before object removal; `ShowName`/`HideName` own the adjacent name-visible byte. |
| `+0x1d4` / `+0x1ec` | `m_boxRotationStep` / `m_boxRotationPhase` | Medium-high / High | `FBSA` timer callback advances `m_boxRotationStep` modulo six; [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) separately advances owner phase `+0x1ec` modulo four. |
| `+0x1d8..+0x1e4` | `m_groundObject`, `m_shadowObject`, `m_epfObject`, `m_nameplateObject` | Medium-high | Linked visual objects created/refreshed by the linked-object helpers. |
| `+0x1e8` | `m_markerOverlayEnabled` / `m_selectionOverlayMode` | Medium-low | Render methods read overlay/selection-style state; exact semantics open. |
| `+0x1f0` / `+0x1f4` | `m_boxRotator` / `m_boxRotator.m_owner` | High | Nested FrameHandler-style helper subobject and owner pointer. The scalar deleting destructor delete size `8` and constructor stores support vptr plus `LivingObjectPane *m_owner`; stale Boost naming is rejected. |
| `+0x1f8` | `m_pendingDamageEffect`, `m_refreshPayload`, or `m_renderEffectState` | Medium-high role, medium original spelling | `ShowDamageEffect` stores this dword and schedules `aDeR`; the timer callback clears it and invalidates bounds. Main render child forwards the same tail dword to `NewHumanImageLib::Draw` and `MonsterImageLib::RenderMonsterImage`, so final spelling must wait for a full tail-layout audit. |

| Local-player adjusted offset | Best current name direction | Confidence | Evidence / caveat |
| --- | --- | --- | --- |
| `+0x3ec4` | `m_localPlayerHitRadius` | Medium-high role, medium original spelling | Used by [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) as the half-extent for both screen bounds; constructor-side evidence initializes it from `2 * g_mapTilePixelWidth`. |
| `+0x1340cc` / `+0x1340d0` | `m_screenY` / `m_screenX`, aliases `m_cachedScreenY` / `m_cachedScreenX` | High role, medium original spelling | [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) writes these after ObjectPane map-position read, MapPane screen conversion, signed `m_moveFrame` interpolation, and half-tile centering. |
| `+0x1340d8` / `+0x1340e8` | `m_screenHitBounds` / `m_screenLowerHitBounds` | High role, medium original spelling | [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) initializes these as full symmetric and lower-half/lower-body screen `RectBounds`; both are adjusted local-player/UserPane aggregate fields. |
| `+0x1340f8` | `m_mapPane` | Very high | Cached active `MapPane *`; [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) calls map-to-screen, direction-to-tile-offset, and direction-offset pixel-scaling helper paths through it. This is an adjusted local-player/UserPane aggregate field, not standalone base-object size proof. |
| `+0x13ead8` / `+0x13eadc` | `m_viewportColumn` / `m_viewportRow`; aliases `m_viewportX` / `m_viewportY` or `m_viewportOffsetX` / `m_viewportOffsetY` | High role, medium original spelling | [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) reads these as the cached viewport row/column pair and emits first-draft C++ for row/y-first output. [UID:0003UE][0x005a5a90-0x005a5b79.UserPaneWarpToPosition](by-memory/0x005a5a90-0x005a5b79.UserPaneWarpToPosition.md) stores the third viewport argument to `+0x13ead8` and fourth viewport argument to `+0x13eadc`. |
| `+0x133f08` | `m_inventorySlots` / `LocalInventorySlotRecord` table, stride `0x1fc` | High for offset/stride and major fields; medium-high for original spelling | [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) computes `this+0x133f08+slot*0x1fc` from a signed byte slot selector. Known fields are `active`, `itemId`, `iconStyle`, `displayName`, `quantityOrCount`, `quantityPromptFlag`, and `targetMode`. This is an adjusted local-player/UserPane aggregate field, not standalone base-object size proof. |
| `+0x13eb08` | `m_recentWhisperRecipients` / outgoing direct-message recipient history | Medium-high | Constructed as `List(0x40, 0x0a)` in `UserPane` setup. `sub_5A4B60` deduplicates/caps/inserts here and sets selector byte `+0x13eb10 = 1` after the user enters or confirms a direct-message recipient. |
| `+0x13eb0c` | `m_incomingWhisperSenderHistory` / incoming fallback whisper sender history | High | [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) accepts opcode `0x0a` subtype `0`, extracts the sender before the `L"\" "` delimiter, deduplicates/caps this `List(0x40, 0x0a)` to ten entries, inserts at index `1`, and clears selector byte `+0x13eb10`. |
| `+0x13eb10` | `m_whisperHistorySource` / current whisper-history source selector | Medium-high | `sub_5A4B60` sets this byte to `1` for outgoing/recent-recipient history. [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) clears it to `0` after recording an incoming sender. `SayToUserNameInputPane` constructor/history navigation uses the byte to choose `+0x13eb08` versus `+0x13eb0c`. |
| `+0x13eb14` | Prefer `m_movementHistoryRecords`; short alias `m_movementHistory`; older B001 aliases `m_linkedRecordArray` / `m_localLinkedRecordArray`, and B002 local alias `m_linkedRecords`, are historical/search aliases | Medium-high | Used by active-record getter/clear/update, opcode `0x04` [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md), live indexed clear [UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md), and later waypoint/facing-history packets. This is an adjusted local-player/UserPane aggregate field, not standalone `LivingObjectPane` layout proof. |
| `+0x13eb18` | Prefer `m_movementHistoryCapacity`; older B001 alias `m_linkedRecordCount` is historical/search alias | High | Paired count/capacity for `+0x13eb14`; opcode `0x04` retained helper/live duplicate loop over this count to clear every record's active byte. |
| `+0x13eb1c` | `m_movementHistoryWriteIndex` | Medium-high | Later B008/B003 packet-helper evidence uses it as the history write index/status token source. |
| `+0x13eb20` | Prefer `m_deferredUserListPacket`; generic alias `m_deferredPacketBuffer` | High | Freed/replaced by [UID:0003UK][0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md), which B002 resolves as `CopyDeferredUserListPacket`; all six direct calls are opcode `0x36` user-list deferred-payload staging calls, not movement-history logic. |
| `+0x13eb24` | `m_deferredUserListPacketSize` | High | Byte count paired with `+0x13eb20`; [UID:0003UK][0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md) stores the incoming `packetSize` argument immediately before copying with `memmove`. |
| `+0x13eb28` | `m_userListPacketTick` | Medium-high | Packet timing/debounce field near pending user-list state; [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md)/[UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) support docs tie it to opcode `0x36` staging. |
| `+0x13eb2c` | Prefer `m_userListDeferUntilTick`; alias `m_nextUserListRefreshTick` | Medium-high | Tiered opcode `0x36` callers set this to current tick plus `30000`, `60000`, `90000`, or `150000` before/dependent on deferred payload handling. |
| `+0x13eb30` | `m_skipNextUserListPacket` | Medium-high | Byte/boolean one-shot skip/defer flag from user-list packet handling. |

| File-level item | Best source-facing name direction | Confidence | Notes |
| --- | --- | --- | --- |
| [UID:00030B][0x0069bf74-0x0069bf78.g_lastFunctionKeyTick](by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md) `0x0069bf74` | Historical cross-family dependency only | Very strong current exclusion | Zero-initialized UserPane.cpp storage, read twice by UID0003UJ with no writer/pointer/second consumer; not a LivingObjectPane field or source declaration. |
| [UID:0003EB][0x00630c24-0x00630c28.UserPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.UserPaneActionNegativeOneFloatConstant.md) `0x00630c24` | external UserPane compiler-pooled `-1.0f` support | High for disposition | Dependency/history only; not a LivingObjectPane-owned file item or authored standalone scalar. |
| [UID:0002WL][0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) `0x0069b894` | `g_livingObjectPanePool` | High for role, medium-high for exact spelling | Static pool storage with `0x20c` block size and `0x20` chunk count; exact child now carries target-local first-draft declaration `static PoolAllocator g_livingObjectPanePool(0x20c, 0x20);`. Exact original linkage/spelling remains inferred, and broad class C++ remains blank. |
| [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) / [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) | `LivingObjectPane::vftable`, `LivingObjectPane::BoxRotator::vftable` | High | Source-declared/generated-binary. Do not hand-author table bytes; final declarations should regenerate vtables. |

### Raw / Retained Local-Player Helpers

B001's 2026-06-19 local PE scan of `E:\NTK\Resources\NexusTK\NexusTK.exe` used rel32 call/jump, absolute VA, and RVA scans over `.text` (`0x00401000-0x0060c4ac`). It found zero routes to the raw starts below, while positive controls in the same scan found ordinary live calls to neighboring modeled functions. Treat these as source-shaped or retained helper bodies only where their child pages prove behavior; do not treat them as ordinary live methods.

| Range/start | Source-facing direction | Route result | Decision |
| --- | --- | --- | --- |
| `0x005a3a20` [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) | Historical LivingObjectPane lead; current `UserPane::DispatchConfiguredShortcutHotkey` | 0 rel32, 0 absVA, 0 RVA | Retained UserPane source, excluded from current LivingObjectPane ownership; calls UserPane command/inventory dispatchers from direct Config compact rows. |
| `0x005a9250` [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) | Historical cross-family retained helper; current `UserPane::TryDispatchFunctionKeyShortcut` | 0 / 0 / 0 | Exact `92/93` source-bearing UserPane member with complete formal C++. B015 no-route/no-writer evidence remains valid, but current UserPane-only callee/source-island evidence resolves owner/emitter UID0000FQ and source file UID0000P1. Signed-short row mapping, direct Config storage, nonalpha return, ASCII slots, classifier-accepted `0xff`, and zero-initialized UID00030B are current; LivingObjectPane ownership and formal deferral are superseded. |
| `0x005aaff0` [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md) | `HandleWarpPacket` / `ApplyMovementCorrectionPacketRaw` | 0 / 0 / 0 | Retained opcode `0x04` warp/movement-correction helper. No direct route to standalone `0x005aaff0`; live [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) inline case `0x005a7989-0x005a7a27` duplicates the same four signed big-endian packet-word reads, `WarpToPosition`, MapPane no-op hook, movement-history active-byte clear loop, and false return. |
| `0x005ac1b0` [UID:0003UV][0x005ac1b0-0x005ac27c.UserPaneHandlePositionSyncPacket](by-memory/0x005ac1b0-0x005ac27c.UserPaneHandlePositionSyncPacket.md) | `HandlePositionSyncPacketRaw` | 0 / 0 / 0 | Raw retained server position-sync helper; parses unused `packet[1]` plus BE16 `targetX/targetY/viewportColumn/viewportRow` at `packet+2/+4/+6/+8`, gates mutation on `m_isMoving == 0`, calls `WarpToPosition`, `m_mapPane->RecenterAndSendPosition(..., false)`, MapPane object update, `RefreshAllLinkedObjects`, and `g_pTimerMgr` cleanup for `m_mapPane+0xa4`; [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) resolves the viewport pair as third argument -> `+0x13ead8` -> output element 1 / column and fourth argument -> `+0x13eadc` -> output element 0 / row; formal C++ remains blank because no caller/table/pointer route is proven. |
| `0x005ac7e0` [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) | `SendMovementWaypointPacketRaw` / `SendWaypointPacketRaw` | 0 / 0 / 0 | Raw waypoint/path packet helper; behavior documented, route not proven. |
| `0x005ac9a0` [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) | `SendFaceDirectionPacket` / `SendFacingOrLinkedRecordPacketRaw` | 0 / 0 / 0 | Raw facing/history helper; later docs favor fixed opcode `0x32` facing-history wording while preserving original-name uncertainty. |
| `0x005acae0` [UID:0003H4][0x005acae0-0x005acb1f.UserPaneSendDirectionPacket](by-memory/0x005acae0-0x005acb1f.UserPaneSendDirectionPacket.md) | `SendDirectionPacket` | 0 / 0 / 0 | External UserPane.cpp file-local helper dependency. Its two direct source callers are ProcessMovement and UID0003H5; it is not LivingObjectPane class inventory. |
| `0x005acb20` [UID:0003H5][0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket](by-memory/0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket.md) | `UserPane::SendAutoFaceDirectionPacket` | 0 / 0 / 0 | External UserPane source dependency with a retained out-of-line body and live UID0003UZ inline equivalent; not LivingObjectPane inventory. |
| `0x005acfe0-0x005ad02c` | `SendUIPanelSwitchAckPacket` | 4 rel32 calls from [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) / no other direct calls found | Private helper candidate for [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md); B004 decoded calls at `0x005abdf3`, `0x005abe65`, `0x005abe9c`, and `0x005abec3`, all from the UI-panel switch handler. The helper writes packet bytes `{0x2d, 0x00}` with packet byte writer `0x00575380`, writes an unsent local terminator byte at offset `2`, sends explicit length `2` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), and should become an exact `LivingObjectPane` support child when UID allocation is available. |
| `0x005a87b0` [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) | `GetActiveMovementHistoryRecordByIndex` / historical `GetActiveLinkedRecordByIndexRaw` | 0 / 0 / 0 | Exact retained raw helper over `m_movementHistoryRecords` / `m_movementHistoryCapacity`; first-draft exact-child C++ is populated, but no direct entry route is proven. |
| `0x005abb20` [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) | `UserPane::HandleUserListPacket` (excluded retained duplicate) | 0 / 0 / 0 | Exact retained UserPane member body. Live opcode `0x36` is duplicated inline in [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md); zero entry routes do not transfer this method or its `+0x13eb20..+0x13eb30` state into LivingObjectPane. |

Positive controls from the same scan found `0x005a4530` from eight rel32 sites (`0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, `0x005b62bd`), `0x005a3e30` from eight rel32 sites (`0x004eab81`, `0x004ed711`, `0x004ed7fc`, `0x004ef0e1`, `0x005070c1`, `0x005a3ac6`, `0x005a3ba1`, `0x005b5e51`), `0x005a58c0` from two sites, `0x005acc30` from `0x005a5956`, and `0x005a5a90` from twelve sites. That proves the negative raw-helper results are not a failed scan.

### Historical Assumptions Superseded

- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) was once considered a `LivingObjectPane` scattered accessor. It is now `EffectObjectPane::IsLooping() const`, reading `EffectObjectPane +0x14c` after callers compare `+0x148` effect id; it remains only a dependency/callee context.
- `0x00537bc0` was once considered a scattered `LivingObjectPane` accessor. It belongs to [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) based on caller branch behavior where `object+0xf8 == 0` reaches `ItemObjectPane` and `object+0xf8 == 3` takes the `LivingObjectPane` branch.
- `0x005a8b80-0x005a8c5c` setters and live `0x005a8c60` option packet helper were once suspected `LivingObjectPane` word-slot helpers. [UID:00027W][0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC](by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md) resolved this island to OptionPane/NewOptionPane support, not `LivingObjectPane`.
- Generated `SoundManager::CancelTimer` / `SoundManager::CancelPendingTimersExceptEvent` names for `0x00597610` and `0x00597630` are stale. Those wrappers forward through `g_pTimerMgr` and belong to TimerHandler/TimerMgr.
- Older generated local struct/class redeclarations in `LivingObjectPane` output are artifacts, not original header evidence.
- Older `90/90` or `95/95` code-entry text is stale. The active code rule is average score greater than `85` with a valid emitter plus source-quality readiness. Exact child [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) now clears that child-level bar and emits first-draft `HasGMNameSuffix() const`, but the broad class page still should not emit a declaration because base/subobject layout, vtable prototypes, adjusted local-player fields, packet-tail structs, and many helper names remain unresolved.

### Method Families

| Family | Address evidence | Role |
| --- | --- | --- |
| Scattered accessors | [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md), `0x005374d0`, `0x005376c0`, `0x005376d0` | `HasGMNameSuffix() const`, position/type/id accessors, and animation-state setter. B004's 2026-06-23 MCP-backed pass confirmed [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) as a `0x3d` real function with one direct caller at `0x0050a552`, one callee `__wcsicmp`, direct `aGm` / `L"GM"` literal xref at `0x00514ec5`, suffix math from `this+0x126`/`this+0x12a`, and no target VA/RVA/raw-offset pointer hits beyond the direct rel32 caller route. The method now has first-draft child C++ using inferred `m_nameBuffer`; MapPane remains the caller/consumer, not owner. The former [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) scattered-accessor candidate is now resolved as `EffectObjectPane::IsLooping`, not a `LivingObjectPane` method. |
| Core construction/destruction | [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) | Constructor variants, ordinary destructor cleanup, and class-owned compiler-generated scalar deleting destructor wrapper evidence. B007's current `nexustk_supervisor_20260704` pass confirms UID0002R0 has three aligned bodies (`0x0053a110`, `0x0053a360`, `0x0053a5a0`), direct callers from `sub_505E00`, `sub_5A2530`, `sub_5A2C60`, `sub_5B8230`, and an unwind path, plus an expected generated Empty Emitter Marker. Final source should express the normal destructor/pool policy only after exact declarations are source-ready, not a handwritten scalar-delete method or a premature UID0002R0 body. |
| Vtable and nested-helper data | [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md), [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) | Exact read-only RTTI/vtable children for `LivingObjectPane::BoxRotator` and `LivingObjectPane`; both now route through the direct class/nested-class gate. [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) first slot points to [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) generated-wrapper marker, and second slot points to [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) source-authored callback. |
| Render/sprite state | [UID:0003Z3][0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers](by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md), [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md), [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), [UID:0003Z6][0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers](by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md), [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md), [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md), [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md), [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) | Opposite-direction helper, render bounds, sprite config, facing, action animation/effect dispatch, animation playback, death animation, timer callbacks, nameplate/effect helpers, main draw, compact sprite draw, and render-bounds vtable methods. [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) now carries exact-child formal C++ for `PlayAnimation`, `PlayFacingAnimation`, `PlayDeathAnimation`, and adjusted `HandleTimerMessage`, with verified `FWdA`/`FBSA`/`iDhC`/`FAnD`/`aDeR` constants. The three render children also carry exact MCP evidence and formal first-draft C++ in their own child pages; broad class declaration C++ remains blank until full layout/prototype coverage is ready. |
| Linked object/effect ownership | [UID:0003Z4][0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers](by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md), [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md), [UID:0003Z6][0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers](by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md), [UID:0003Z7][0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers](by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md) | Destroys, replaces, syncs, refreshes, propagates, and deregisters linked or attached overlay objects, clears/removes active effects, and preserves raw/no-xref helper treatment inside source-bearing clusters. [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) is the owner-side attached-overlay deregistration method: `AttachedObjectPane::~AttachedObjectPane` is the sole caller through `AttachedObjectPane +0x128`, while MapPane construction/update paths create overlays and call the companion `LivingObjectPane` registration helpers. |
| Movement state machine | [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md), [UID:0003Z7][0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers](by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md), [UID:0003Z8][0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward](by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md) | Begins movement, schedules/cancels timer callbacks through [UID:0000F1][TimerMgr](by-class/TimerMgr.md), sets actor map position, syncs linked objects, refreshes linked objects, propagates linked modes, and steps forward. |
| Local movement and commands | `0x005a2de0-0x005a8e66`, including [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md), [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md), and [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) | Viewport position, movement send path, walk animation setup, source-ready `UseInventorySlot` and paired `UseCommandSlot`, action gate, warp, movement-history lookup/cleanup, screen update, and movement packet send. UID0001KN owns direct-self, selected-object, and explicit ItemWho target routes; compiler-expanded ItemWho construction/EH is reduced to its normal source constructor call. |
| Local player settings and server packets | `0x005a9310-0x005ad441` | Deferred user-list packet copy, settings packet, spell slot updates, server entry/login state, movement acks, chat/user-list/panel packets, linked-object packets, and action/attack packets. [UID:0003UK][0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md) is now `CopyDeferredUserListPacket`: it replaces `+0x13eb20/+0x13eb24` and is called only by opcode `0x36` user-list deferred-payload tiers at the six known call sites, so it should not be grouped with movement-history ring helpers. [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) is the live opcode `0x0a` subtype-zero incoming whisper/sender-history updater. [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) is the live opcode `0x3e` UI-panel switch/open handler reached from [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) at `0x005a7ddc`; it reads `payload[1]`, uses [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) to choose EPF/current versus legacy action tables, switches GeneralPurposePanel inventory/spell tabs, opens the normal BulletinSession for action `6`, sends private ACK helper `0x005acfe0`, and writes the self-look child field `+0x232c` for actions `4`, `7`, and `8`. Raw packet-tail helper [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) is the retained no-route opcode `0x06` movement waypoint/path helper; [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) is the retained no-route fixed opcode `0x32` movement/facing-history helper. Both keep formal C++ blank without a route or retained-helper emission policy. |

### Key Relationships

- [UID:00009R][ObjectPane](by-class/ObjectPane.md) is the base game-object pane below `LivingObjectPane`; keep generic object data/bounds/attachment logic there.
- [UID:00007Q][MapPane](by-class/MapPane.md) owns spatial lookup, map bounds, visible tile conversion, and object insertion/removal. `LivingObjectPane` calls those APIs while keeping actor-side position and prediction state.
- [UID:0000FQ][UserPane](by-class/UserPane.md) owns the local user UI surface. Its constructor/destructor wraps a `LivingObjectPane` subobject, but world movement and command packet functions stay with `LivingObjectPane`.
- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) owns the virtual dispatcher route for server opcode `0x3e`, but [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) owns the packet body. The dispatcher adjusts `ecx` to `ebx - 0xa0` before the direct call, so `UserPane` is a caller/dispatcher owner, not the method owner.
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), inventory panes, and spell input panes call into `LivingObjectPane` for current slot data or command execution.
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md), [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), BulletinSession, Socket, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and frame/panel globals are dependencies of [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md), not owner routes out of `LivingObjectPane`.
- [UID:0000I5][Chatting](by-file/Chatting.md) and [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) are support/consumer modules for `LivingObjectPane::HandleChatMessagePacket`, not owners. [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) uses Chatting-owned delimiter string `0x00615284` / `L"\" "` to split `sender" message` text, then writes incoming/fallback sender history at adjusted `+0x13eb0c` for `SayToUserNameInputPane` to consume.
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md) / [UID:0000F1][TimerMgr](by-class/TimerMgr.md) provide the generic callback scheduler used by `LivingObjectPane` sprite, facing, movement, and animation state. Older generated `SoundManager::CancelTimer` labels for the generic timer-wrapper functions at `0x00597610` and `0x00597630` are stale and should not be treated as audio-module dependency evidence. B007's timer pass confirms `TimerHandler` is a helper/scheduler dependency for [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), not the canonical owner: the adjusted callback view at `+0xa4` recovers the `LivingObjectPane` owner and dispatches `FWdA`, `FBSA`, `iDhC`, `FAnD`, and `aDeR`.

### Destructor Wrapper Policy

[UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) carries the ordinary constructor/destructor source semantics for the core lifetime cluster, but currently stays no-code/blank at `87/90`: the page contains two constructor variants plus the ordinary destructor/cleanup body, and exact constructor signatures, sprite/config type spelling, nested `BoxRotator` declaration shape, and helper prototypes are not yet final-source quality. [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) remains class-owned because the primary vtable slot `0x0062097c`, adjusted thunks `0x0053cf3e`/`0x0053cf49`, ordinary-cleanup duplication, and pool free xref `0x0053d542` are all `LivingObjectPane` lifetime evidence. It is compiler-generated ABI glue with a Rule 28 comment-only emitted marker covered by [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), so broad class C++ must not add a source method such as `LivingObjectPane::ScalarDeletingDestructor(char)`.

### Boundary Caveats

- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) should be treated as a non-emitting split/index, not as a class-level C++ source block. Exact child pages carry source ownership for individual `LivingObjectPane` methods. The broad span also contains non-Living object-pane sibling ranges and raw/no-xref helper-shaped bodies, so it cannot be used as a final class declaration or method-body source unit.
- IDA confirms the main function starts for the core and movement clusters, but several older projected helper starts in the local-player tail are not IDA function starts: `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, and `0x005ac9a0`. UID0003UJ is now an explicit retained-source exception with complete UserPane C++; its no-entry status no longer implies blank output or LivingObjectPane ownership. B010's 2026-06-21 pass resolves `0x005ac1b0` semantically as retained no-route `HandlePositionSyncPacketRaw`: it parses unused `packet[1]`, BE16 `targetX/targetY/viewportColumn/viewportRow` at `packet+2/+4/+6/+8`, checks `m_isMoving`, then calls `WarpToPosition`, MapPane recenter/update, linked-object refresh, and TimerMgr cleanup, while B006's [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) pass resolves the second pair's store/output order as column then row. Formal C++ remains blank for that distinct target because no caller/table/pointer route is proven. B003's 2026-06-19 pass resolves `0x005ac7e0` semantically as retained no-route `SendMovementWaypointPacketRaw` / opcode `0x06` waypoint/path packet helper with no IDA function object, rel32 caller, VA/RVA pointer, vtable route, or fallthrough route. B008's 2026-06-19 pass resolves `0x005ac9a0` semantically as the raw no-route opcode `0x32` `SendFaceDirectionPacket(unsigned char direction)` / movement-facing packet helper while keeping formal C++ blank because the live `0x005a2e00` movement process appears to inline equivalent logic.
- `0x0053d030` has been projected as a separate `LivingObjectPane__BoxRotator` class. The vtable name, constructor subobject stores at `LivingObjectPane + 0x1f0`, owner pointer at `+0x1f4`, owner state use at `+0x1ec`, FrameHandler destructor path, and [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md) callback support treating it as `LivingObjectPane::BoxRotator`, a nested/private FrameHandler-style helper. The scalar deleting destructor itself is compiler-generated marker-covered ABI output, not a source method to paste into the class declaration.
- Older generated output contains repeated local struct/class redeclarations. Treat those as generated artifacts, not original header-layout evidence.
- Older generated output also contains timer calls under `SoundManager::*` names. IDA rechecks on 2026-05-24 show the underlying bodies forward through `g_pTimerMgr`, so source migration should name the dependency through `TimerHandler`/`TimerMgr` instead.
- The paired hotkey dispatch helper names are now source-role separated. [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state `2` / `.usr` `S` from the spell-inventory tab routes to [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md), while state `3` / `.usr` `I` from the inventory tab routes to [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md). Generated `UseSpellSlot` is stale historical output and should not be revived for either helper.
- Historical correction (2026-08-01): older research described [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) as a modeled `LivingObjectPane` helper and treated its zero caller/xref/table/pointer route as a reason to suppress source output. That ownership and no-code conclusion is rejected. The complete-object receiver recovered by subtracting `0xa0`, the matching inline opcode-`0x36` body in [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), the UserPane-only helper/dialog dependencies, and the adjusted `+0x13eb20..+0x13eb30` state establish retained `UserPane::HandleUserListPacket` source. The zero-route result remains valid duplicate-body/liveness history only. `m_deferredUserListPacket`, `m_deferredUserListPacketSize`, `m_userListPacketTick`, `m_userListDeferUntilTick`, and `m_skipNextUserListPacket` are current UserPane fields and must not be emitted or owned by `LivingObjectPane`; only the old adjusted-local-player observations remain here as historical evidence.
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) should no longer be counted as a `LivingObjectPane` scattered accessor. MapPane and local-player callers reach it while scanning effect-child collections, but the receiver is an `EffectObjectPane`; `+0x148` is the copied effect descriptor id and `+0x14c` is the effect loop/reuse-active flag.

### Cross-References

- [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md)

- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md)
- [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md)
- [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md)
- [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md)
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) - related dependency/ownership correction; no longer a `LivingObjectPane` method.
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md)
- [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- [UID:0003Z3][0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers](by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md)
- [UID:0003Z4][0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers](by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md)
- [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md)
- [UID:0003Z6][0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers](by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md)
- [UID:0003Z7][0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers](by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md)
- [UID:0003Z8][0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward](by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md)
- [UID:0003Z9][0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance](by-memory/0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md)
- [UID:0003ZA][0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods](by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md)
- [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md)
- [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md)
- [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md)
- [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md)
- [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md)
- [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md)
- [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md)

### Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | Purpose, method families, key relationships, exact core/local-player links, scattered accessor pages, raw-route audit, stale ownership corrections, class-field/source-quality direction, and no-code proof are documented. Completion remains capped by missing final declaration, vtable prototype list, full local-player packet struct layout, and formal class C++. |
| Confidence `88` | Source/file/class routing is strongly supported by file/core/local/vtable/static-pool evidence, constructor/destructor vptr stores, exact child docs, and fresh PE route scans with positive controls. Confidence stays below final-source level because several raw helper original names are inferred/descriptive and local-player adjusted layout still needs declaration-level proof. |

### Changes

- 2026-07-14 B001 UID0002QY bounded support synchronization:
  - Preserved the class score, owner/emitter metadata, blank formal C++, and every unrelated field/layout blocker.
  - Resolved only the Motion lifetime fields: `+0x1bc` active-effects `List *`, `+0x1c0` current Motion/effect pointer, and existing `+0x1d1` name-visible state; added reciprocal `Motion::OnTimer` behavior, ignored scheduler-return negative evidence, one-element unlink, current-pointer clear/publication, deferred deletion, and MapPane refresh.

- 2026-07-13 B002 UID0001KN source-quality synchronization:
  - Added the accepted `void LivingObjectPane::UseInventorySlot(unsigned char slot)` method role, exact `1..52` guard, inventory-record fields and modes, complete modeled/raw caller inventory, packet and ItemWho outcomes, `void` proof, inlined-constructor/compiler-EH disposition, source ownership, and paired `UseCommandSlot` boundary.
  - Preserved this broad class page's `86/88` score and blank class-level formal C++; UID0001KN emits through its exact by-memory child. Historical `UseSpellSlot`, seven-modeled-caller, and unresolved-constructor wording is superseded for UID0001KN only.
- 2026-07-08 B001 accepted [UID:0002WL][0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) implementation:
  - Narrowed the static-pool name direction from `s_livingObjectPanePool`/`g_livingObjectPanePool` to inferred `g_livingObjectPanePool`, with exact original spelling still caveated.
  - Recorded that UID0002WL carries target-local first-draft C++ `static PoolAllocator g_livingObjectPanePool(0x20c, 0x20);` while this broad class page keeps its formal C++ block blank pending the full declaration/layout/prototype audit.
- 2026-07-06 B005 accepted [UID:0003Z5][0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers](by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md) implementation:
  - Added the active-effect, movement, and action-effect support section for the exact child now at `88/90`, including the B005 live MCP repairs for `ClearAllEffects`, `BeginMoveTo`, `PlayActionAnimationOrEffect`, raw no-route helpers, and `0x0053b6b3-0x0053b700` table/padding handling.
  - Preserved the class-level blank C++ policy: UID0003Z5 emits through its exact by-memory child, while broad `LivingObjectPane` still needs the larger declaration/layout/prototype audit before class C++ can be asserted.

- 2026-07-04 B007 accepted [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) implementation:
  - Updated class support text for the current `87/90` UID0002R0 no-code decision, current MCP session `nexustk_supervisor_20260704`, three aligned constructor/destructor bodies, direct caller evidence, expected generated Empty Emitter Marker, and continued [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) covered-by relationship.
  - Preserved the class-level blank C++ policy and rejected UserPane/ObjectPane/TimerHandler/BoxRotator/no-owner/source-ready-C++ alternatives for the construction/cleanup cluster.
- 2026-06-26 B006 accepted [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) implementation:
  - Added the local-player viewport position section and source-facing field rows for `+0x13ead8` / `m_viewportColumn` and `+0x13eadc` / `m_viewportRow`.
  - Recorded that the exact child emits `MapPoint *LivingObjectPane::GetViewportPosition(MapPoint *outPosition) const` while broad class C++ remains blank pending the full declaration/layout/prototype audit.
- 2026-06-26 B007 accepted [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) implementation:
  - Updated class status/readiness, field directions, method-family notes, and TimerHandler relationship so [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md) is no longer blocked by unresolved timer names.
  - Recorded adjusted `+0xa4` timer-owner math, fields `+0x1d0`, `+0x1d4`, and `+0x1f8`, verified timer constants `FWdA`/`FBSA`/`iDhC`/`FAnD`/`aDeR`, and exact-child formal C++ placement while keeping broad class C++ blank.
- 2026-06-26 B001 accepted [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md) implementation:
  - Added the render-frame child map for [UID:0003NU][0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md), [UID:0003NV][0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame](by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md), and [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md), now revised by supervisor verification to scores `89/89`, `88/89`, and `88/89`.
  - Updated class readiness wording: `GrafPort`/render context, `RectBounds`, helper-call shapes, marker-table names, and vtable slot names are resolved enough for child formal first-draft C++; broad class C++ remains blank because the whole class declaration/layout/prototype audit is still larger than the render-child repair.
  - Corrected the overlay table route: `0x00620b90` is the `BGAUGE` string neighborhood; the immediate-constant rows are [UID:0003CC][0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables](by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md) at `0x00620c10`, `0x00620c2c`, and `0x00620c48`, with `LivingObjectPane` as consumer and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) preserved as source owner.
- 2026-06-25 B001 accepted [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) implementation:
  - Added the destructor wrapper policy: [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) is class-owned generated-binary ABI glue with a Rule 28 marker covered by [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), and final class source should model the normal destructor/pool policy rather than a handwritten scalar-delete method.
- 2026-06-22 Rule 26 incorporation from B015 [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md):
  - Updated the raw-helper route table with the behavior-resolved retained function-key shortcut helper, corrected body extent through `0x005a930a`, no-live-route/no-tick-writer evidence, [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) legacy shortcut dependency, and the then-current blank-formal decision. The 2026-07-16 UID0003UJ callback supersedes the owner/formal conclusion while retaining the evidence.
- 2026-06-22 Rule 26 incorporation from B015 [UID:0003H4][0x005acae0-0x005acb1f.UserPaneSendDirectionPacket](by-memory/0x005acae0-0x005acb1f.UserPaneSendDirectionPacket.md):
  - Expanded the raw-helper route table from a generic no-route opcode `0x11` note to the exact direction/facing serializer, including [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) route, length `2`, no-live-route evidence, and the no-`this` caveat that blocks ordinary member-method C++.
- 2026-06-22 Rule 26 support sync from B013 [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md):
  - Added the compact shortcut dispatcher section, accepted `DispatchConfiguredShortcutHotkey(short, int)` as retained exact-child source, recorded selector/key/mode behavior, and separated the executable helper's LivingObjectPane ownership from RegistryConfig's compact-record storage ownership.
  - Updated class-declaration caveats so the raw no-route helper can emit through its exact child while the broad class declaration still avoids asserting a live caller or full layout declaration.
- 2026-06-22 Rule 26 support sync from B014 [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md):
  - Added the local-player action dispatch section, promoted `TryPerformAction` to first-draft exact-child C++ status, documented exact caller routes through MapPane event `7` and UserPane key dispatch, and rejected stale `char` return / cooldown-helper interpretations.
  - Recorded the action field model for `+0x19a`, `+0x182`, `+0x13eaf8`, `+0x184`, and `+0x13eb3c`, plus the arrow-warning, `SendActionPacketWithAutoFace`, raw auto-face sibling, indirect `-1.0f` constant, and `PlayActionAnimationOrEffect(27, 200, 0)` relationships.
- 2026-06-21 Rule 26 support sync from B009 [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md):
  - Updated the movement-history section and raw-helper route table for [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) as retained `GetActiveMovementHistoryRecordByIndex(unsigned char)` with first-draft exact-child C++, while preserving no-entry-route and `LinkedRecord` alias caveats.
  - Recorded that [UID:0003UF][0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords](by-memory/0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords.md) now has matching first-draft active-byte clear-all C++ after the same field-name blocker was resolved.
- 2026-06-21 Rule 26 support sync from B011 [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md):
  - Added the no-`this` packet-helper section: `0003UU` remains in the LivingObjectPane source neighborhood but is a file-local/static helper through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), not an emitted `LivingObjectPane::` method.
  - Recorded the exact dispatcher route, packet layout, MessageShowPane singleton dependency, and class-declaration blocker so future class C++ does not turn the helper into a member method.
- 2026-06-21 Rule 26 support sync from B008 [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md):
  - Added the local-player screen-position/cache section and field model for `m_localPlayerHitRadius`, `m_screenY`, `m_screenX`, `m_screenHitBounds`, `m_screenLowerHitBounds`, and `m_mapPane`.
  - Recorded that `UpdateScreenPosition` consumes ObjectPane map coordinates, MapPane coordinate helpers, `m_facing`, signed `m_moveFrame`, `g_movementSubstepScale`, and tile dimensions, while leaving movement-history fields untouched.
- 2026-06-21 Rule 26 support sync from B010 [UID:0003UV][0x005ac1b0-0x005ac27c.UserPaneHandlePositionSyncPacket](by-memory/0x005ac1b0-0x005ac27c.UserPaneHandlePositionSyncPacket.md):
  - Expanded the raw retained helper inventory for `0x005ac1b0` from generic no-route wording to exact packet/body facts: unused `packet[1]`, BE16 fields at `packet+2/+4/+6/+8`, `m_isMoving` gate, `WarpToPosition`, `m_mapPane` recenter/object update, linked-object refresh, and TimerMgr cleanup through `m_mapPane+0xa4`.
  - Preserved the class declaration no-code policy: the route/liveness scan found no rel32, absolute VA, or RVA route to `0x005ac1b0`, so this helper must not appear as a normal live class method until route evidence or retained-helper emission policy changes.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added `m_inventorySlots` / `LocalInventorySlotRecord` as the adjusted local-player inventory table at `+0x133f08`, stride `0x1fc`.
  - Recorded source-facing field names `active`, `itemId`, `iconStyle`, `displayName`, `quantityOrCount`, `quantityPromptFlag`, and `targetMode`; kept original spellings caveated and retained the large-offset UserPane/local-player aggregate warning.
  - Documented that the helper is class-owned by `LivingObjectPane` but broadly consumed by inventory panes, dialogs, macros, item menus, and system messages.
- 2026-06-21 Rule 26 support sync from B010 [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md):
  - Added the `UseCommandSlot` command/spell-slot method model, including slot guard `+0x13ead4`, `SpellCommandSlotRecord` base `+0x13a6ec + 0x148 * slot`, record fields `active` and `inputKind`, case map `1..8`, exact caller list, switch-table boundary, and rejection of generated `SpellManager`/`g_pSpellMan`/`UseSpellSlot` names.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `00007B-LivingObjectPane-class-source-quality.md`:
  - Raised [UID:00007B] from `85/85` to `86/88`, kept `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and kept class C++ blank.
  - Incorporated the report's class-level no-code proof, source-facing field/helper name direction, raw local-player route-scan table, positive-control call sites, stale ownership corrections, source-declared/generated-binary vtable/static-pool policy, and adjusted local-player/UserPane layout warning.
  - Preserved later accepted B008/B003 movement-history names as preferred over the older B001 `linkedRecord` aliases, while keeping the older aliases as historical search terms.
- 2026-06-20 B001 [UID:0003UR][0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket](by-memory/0x005ab860-0x005aba7b.UserPaneHandleChatMessagePacket.md) support sync:
  - Added source-facing adjusted local-player fields `m_recentWhisperRecipients` at `+0x13eb08`, `m_incomingWhisperSenderHistory` at `+0x13eb0c`, and `m_whisperHistorySource` at `+0x13eb10`.
  - Recorded that opcode `0x0a` subtype-zero chat-message handling updates reply/name-entry history rather than visible chat display, with `Chatting` as string-data owner and `SayInputPanes` as consumer.
- 2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) support sync:
  - Added opcode `0x3e` UI-panel switch/open handler details to the local-player server-packet family, including `payload[1]` action-byte dispatch, EPF/current versus legacy action tables, GeneralPurposePanel inventory/spell tab dependencies, SelfLookPane child `+0x232c` writes, normal BulletinSession action `6`, and private ACK helper `0x005acfe0`.
  - Preserved ownership boundaries: `UserPane` owns the server-message dispatcher, while `GeneralPurposePanel`, `SelfLookPane`, BulletinSession, Socket, and layout globals are dependencies of the `LivingObjectPane` packet body.
- 2026-06-19 B003 [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md) support sync:
  - Added `SendMovementWaypointPacketRaw` / opcode `0x06` movement waypoint/path packet as a retained no-route local-player packet-tail helper owned by `LivingObjectPane`.
  - Added waypoint-specific aliases `m_waypointHistoryRecords`, `m_waypointHistoryCapacity`, `m_waypointHistoryWriteIndex`, `LivingObjectWaypointSegment`, and `LivingObjectWaypointHistoryRecord` while preserving B008's broader `m_movementHistory` / `LocalMovementHistoryRecord` naming for the shared ring.
  - Recorded the no-route policy and source-placement decision: `m_mapPane`, MapPane, `g_pConfig`, Socket, and PacketBuffer are dependencies, not owner routes; formal C++ remains blank until a route or retained raw-helper emission policy is approved.
- 2026-06-18 B001 Rule 26 source-quality incorporation:
  - Kept score and metadata at `85/85`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KU`.
  - Added the [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) split/index caveat so the class does not inherit aggregate C++ emission from the broad mixed range. Exact core methods should be represented by child by-memory pages, and the class declaration remains blocked by local-player tail/raw starts and incomplete object layout.
  - Added the executable B001 child split pages [UID:0003Z3][0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers](by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md)-[UID:0003ZA][0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods](by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md) to the method-family and cross-reference inventories, including the raw/no-xref helper clusters and the nested BoxRotator advance callback.
- 2026-06-26 B009 [UID:0002T6][0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md) support sync:
  - Kept class score/metadata unchanged.
  - Added the FrameHandler-style `BoxRotator` relationship, vptr/owner layout proof, generated-wrapper marker policy, and stale Boost/standalone-class rejection.

- 2026-06-19 B008 [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) support sync:
  - Added the movement-history field/record model for `m_movementHistory`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, and `LocalMovementHistoryRecord::active/tileY/tileX/direction`.
  - Clarified that large local-player offsets are adjusted UserPane/local-player aggregate offsets, not compact base-class layout fields.

- 2026-06-20 B002 [UID:0003UK][0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.UserPaneCopyDeferredUserListPacket.md) support sync:
  - Replaced the old movement-buffer framing with `CopyDeferredUserListPacket` / deferred opcode `0x36` user-list payload-copy semantics.
  - Raised confidence in `m_deferredUserListPacket`, `m_deferredUserListPacketSize`, `m_userListPacketTick`, `m_userListDeferUntilTick`, and `m_skipNextUserListPacket`; kept movement-history fields separately at `+0x13eb14/+0x13eb18/+0x13eb1c`.
  - Updated the local-player packet-tail caveat for raw no-route `0x005ac9a0` as fixed opcode `0x32` movement/facing-history support, distinct from opcode `0x11` direction helper [UID:0003H4][0x005acae0-0x005acb1f.UserPaneSendDirectionPacket](by-memory/0x005acae0-0x005acb1f.UserPaneSendDirectionPacket.md).
- 2026-06-20 B002 [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md) support sync:
  - Reframed `0x005aaff0` from unresolved raw movement-correction helper to retained opcode `0x04` `HandleWarpPacket` / `ApplyMovementCorrectionPacketRaw`, with the live [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) inline duplicate as route proof.
  - Added the payload layout, `PacketBufferReadUInt16BE`, `WarpToPosition`, MapPane no-op hook, movement-history active-byte clear semantics, and the class-declaration caveat that exact child C++ does not make the broad class declaration source-quality.
- 2026-06-20 B003 [UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md) support sync:
  - Updated the movement-history section to prefer `m_movementHistoryRecords`, documented [UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md) as route-proven `ClearMovementHistoryRecordByIndex(int)`, added direct callers `0x005ab2f4`/`0x005ab641`, and closed the child C++ blocker to descriptive naming uncertainty rather than unresolved layout.

- 2026-06-18 B003 source-quality correction:
  - Removed [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) from the active `LivingObjectPane` scattered-accessor set.
  - Evidence: B003 showed the call receivers are effect-child objects, not the owning living actor; the body reads byte `EffectObjectPane +0x14c`, while callers separately compare dword `EffectObjectPane +0x148` against the effect descriptor id before calling it.

- 2026-06-16 B001 retry raw linked-record helper:
  - Scores remain `85/85`.
  - Added [UID:0003VE][0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex](by-memory/0x005a87b0-0x005a87d5.UserPaneGetActiveMovementHistoryRecordByIndex.md) as a local movement/linked-record helper.
  - Evidence: raw byte audit decodes `this+0x13eb14/0x13eb18` linked-record pointer/count logic, no pointer/rel32 xrefs to the raw helper start, and adjacency to [UID:0003UF][0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords](by-memory/0x005a87e0-0x005a8809.UserPaneClearAllMovementHistoryRecords.md)/[UID:0003UG][0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex](by-memory/0x005a8810-0x005a8832.UserPaneClearMovementHistoryRecordByIndex.md).
- 2026-06-16 B001 source-shape execution:
  - Scores unchanged at `85/85`.
  - Added [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) to the linked object/effect ownership family as the attached-overlay deregistration method. [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) remains the only live caller/source-use context.
  - Evidence: B001 reconfirmed the sole `AttachedObjectPane::~AttachedObjectPane` call, receiver field setup in `LivingObjectPane` constructors, same-field replacement/cleanup helpers, MapPane registration caller pairs, zero standalone pointer encodings, and compiler switch tables that belong to the exact method body rather than a separate source item.

- 2026-06-05: Raised completion/confidence from `82/78` to `84/80`, marked the class reconstructable, and attached it to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md). Reframed generated-output references as historical caveats and added live IDA evidence for the GM suffix scattered accessor. C++ remains blank because the class declaration, field names, and local-player packet-tail boundaries are not final-source quality.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the gameplay actor page has broad, detailed coverage of purpose, method families, dependencies, nested helper, timer misnames, and packet/movement caveats, but confidence is capped by unresolved local-player tail boundaries and source-level naming. Evidence: documented core/local-player memory ranges, accessor pages, `BoxRotator` nesting, `MapPane`/`UserPane`/`TimerMgr` relationships, and explicit generated-artifact exclusions.
- 2026-06-11 Batch 197 strict-gate repair:
  - Before: `84/80`, attached under the old gate and too low to support exact 85/85 children.
  - After: `85/85`; [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) can attach directly to this class.
  - Evidence: current IDA confirms [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) as a 451-byte exact helper with seven modeled callers, one raw xref, packet-send and target-pane callees, and inventory hotkey/use-input relationships.
- 2026-06-12 A003 Batch270:
  - Kept scores at `85/85` but added direct vtable-child evidence for [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) and [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md).
  - Evidence: Batch270 rechecked the `BoxRotator@LivingObjectPane` RTTI/vtable boundary, constructor stores into the nested helper subobject, the main `LivingObjectPane` RTTI/vtable views, and the strict route through [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md).
- 2026-06-12 A002 Batch315:
  - Removed stale `0x00537bc0` scattered-accessor ownership. Live caller decompilation shows that helper belongs to [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), because `sub_513310` calls it from the non-living `object+0xf8 == 0` branch and reserves the `object+0xf8 == 3` branch for LivingObjectPane updates.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (00007B)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete 0x20c declaration is preserved and adds only class FittingRoomListPane plus narrow friendship. This legalizes the inherited m_nameVisible read without exposing unrelated internals or inventing g_pGlobalState.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-093 | 00007B | `g_pGlobalState->fittingRoomInputLocked` is rejected. Storage 0x0067a748 is `UserPane *g_pUserPane`, and the byte tested at inherited +0x1d1 is `LivingObjectPane::m_nameVisible`; exact source is `!g_pUserPane->m_nameVisible`. | Certain for address/type/field, strong for lexical condition | UID0001OR/UID0000QK singleton evidence, UID0000FQ complete UserPane, UID00007B exact field layout, direct compare. | UID0002DN formal; UID00007B complete friend formal; UID0000KU/UID0000P1/UID0000QK support. | reject-invalid | implemented |
| C2E6-094 | 00007B | `friend class FittingRoomListPane` is the narrow legal access route for inherited protected `m_nameVisible`; no getter, public field, duplicate global-state struct, or raw offset is supported. | Strong | Existing MapPane/Motion/BowGauge friend pattern and direct no-callee field read. | UID00007B complete formal; UID0000KU source/header prose. | incorporate | implemented |
