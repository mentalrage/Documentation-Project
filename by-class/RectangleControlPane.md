*** UID:0000BT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RectangleControlPane.h"
#include "../../render/Surface.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "ControlPane.h"

struct RectBounds;

class RectangleControlPane : public ControlPane
{
public:
    RectangleControlPane(int drawColor, const RectBounds *bounds);
    virtual ~RectangleControlPane();

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: very strong for the complete declaration, four authored definitions, `0x108` layout, three inherited views, and standalone CPP/H route.
- Settled source file: [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md), `NexusTK/ui/controls/RectangleControlPane.cpp` with sibling H.
- Vtable layout: [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md)
- Exact vtable data: [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)

## Class Purpose

`RectangleControlPane` is a simple solid-rectangle visual control. It derives from `ControlPane`, adds no data members, applies inherited draw color, fills its bounds through the shared rectangle draw path, and returns fixed hit-test part `21` from the terminal `HitTestPart(int,int)` override.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Source constructor is now first-draft C++ ready as `RectangleControlPane(int drawColor, const RectBounds *bounds) : ControlPane(8, bounds) { SetDrawColor(drawColor); }`; compiler vptr stores remain binary output. |
| `~RectangleControlPane` | [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) | Authored out-of-line empty ordinary destructor child; compiler output restores the three Rectangle vtable views and tail-jumps to inherited [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown. |
| `OnPaint` | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Copies inherited bounds with `GetBounds(&bounds)` and calls Surface-owned slot 7 directly as `g_pfnFillRect(this, &bounds)`; primary-vtable position and current project convention settle the source-facing name. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler-generated destructor adjustor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Compiler-generated MSVC deleting-destructor wrapper; no handwritten source body or emitter route. |
| `HitTestPart(int,int)` | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md) | Terminal primary-vtable override; ignores both coordinates and returns unsigned byte part `21`. |

## Evidence Notes

- Live IDA confirms the only ordinary constructor caller at `0x0045252c`, inside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Live IDA confirms vtable data refs to OnPaint at `0x00618478`, HitTestPart at `0x00618494`, the secondary/tertiary adjustor thunks at `0x0061849c` and `0x006184cc`, and the primary destructor wrapper slot at `0x00618434`.
- The constructor calls `ControlPane` base construction with kind `8`, installs the three Rectangle vtables as compiler output, and applies the constructor color argument through the inherited draw-state setter at `0x004b9660`; [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) documents that helper as active draw-color state writing `this+0x74`, not generated `FittingRoomListPane::SetTextColor` ownership.
- Paint [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) copies the inherited Pane rectangle at `this+0x44` through `GetBounds` at `0x004b8e00`, then dispatches [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot 7 directly as `g_pfnFillRect(this, &bounds)`. The installed callback ABI is `void (__thiscall *)(GrafPort *, const RectBounds *)`: `this` remains the ECX receiver and the bounds pointer is the sole stack argument, exactly matching the observed `call dword ptr ds:0x0069b3fc`.
- `Surface.h` owns `SurfaceFillRectProc` and the `extern g_pfnFillRect` declaration, so the CPP preamble includes `../../render/Surface.h`. The generated GrafPort inheritance chain exposes `GetBounds` and `SetDrawColor` but no `FillRect` member. Inventing `GrafPort::FillRect` would therefore misrepresent both the binary's direct-global call and the current declaration owner.
- The paint body is not an invalidation helper, cleanup, or destructor path. BackPane, Pane, GrafPort, SurfaceRenderCallbackTable, and MiniMap evidence stay dependency/consumer context; the method owner and emitter remain RectangleControlPane.
- [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) carries the authored out-of-line empty ordinary destructor source body. It has zero helper-start xrefs and no raw pointer/EH route, restores vtables `0x00618434`/`0x0061849c`/`0x006184cc`, tail-jumps to `0x00544580`, and has no Rectangle-specific cleanup.
- [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) is no-code compiler ABI glue: it is reached by primary vtable slot `0x00618434` and adjustor thunks `0x0049afc1`/`0x0049afcc`, has no ordinary direct callers, restores the three Rectangle vtable views, calls [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown at `0x00544580`, optionally frees storage through [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), and contains no Rectangle-specific field/resource cleanup. B010 local PE/Capstone reanalysis additionally confirms the nine-byte prepad at `0x0049b487-0x0049b490`, eleven-byte postpad at `0x0049b4e5-0x0049b4f0`, `this-0xa0`/`this-0xa4` thunk routes, and the `flags & 4` compiler/runtime guarded size-delete path through `0x0041b6a0` with object size `0x108`. The source-level destructor semantics belong to [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md), not to a source method named after the scalar deleting wrapper.
- The formal CPP owns the sibling class header include, the Surface callback declaration include, and child expansion; the formal H remains the one complete unchanged class declaration. UID00011P, UID0004HL, UID00011R, and renamed UID000128 own the four definitions. Scalar deletion, adjustors, vtables, RTTI, padding, and EH cleanup remain compiler-generated/no-code.
- Historical 2026-06-11 Agent-A006 evidence reconfirmed the modeled method bounds: constructor `0x00499c60-0x00499cd2`, ordinary destructor child [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md), paint virtual `0x00499d00-0x00499d37`, scalar deleting destructor `0x0049b490-0x0049b4e5`, and a then-misidentified terminal virtual at `0x0049b8f0-0x0049b8f5`. Current evidence resolves the latter as `HitTestPart(int,int)`.
- The same dated recheck found the sole constructor caller at `0x0045252c` in the minimap dialog setup path; vtable-base stores to `0x00618434`, `0x0061849c`, and `0x006184cc`; `OnPaint`/terminal-slot data refs at `0x00618478` and `0x00618494`; and scalar destructor refs from the two adjustor thunks plus the primary vtable slot.

## Ordinary Destructor Source And Compiler Boundary

- The exact ordinary function is a unique 31-byte thiscall with no arguments, locals, direct start xrefs, raw image pointer, vtable slot, constructor-EH route, or class-specific side effect. Its three vptr restores and Pane tail-chain are compiler mechanics generated from the class destructor.
- Constructor EH cleanup at `0x005fd191` bypasses UID0004HL and reaches Pane teardown through thunk `0x00421370`. The ordinary function is therefore not retained merely as an unwind helper.
- The three complete-object locators encode view offsets `0`, `0xa0`, and `0xa4`; the RTTI hierarchy lists RectangleControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler. Those facts explain the primary and two secondary destructor views.
- Primary virtual destruction enters compiler wrapper UID000125; secondary and tertiary views enter UID000122 adjustors before that wrapper. The class source must not declare or emit those ABI helper names or explicit vptr/base/delete operations.
- Same-family CheckBoxControlPane has equivalent three-view and scalar-wrapper machinery but no standalone ordinary destructor in its source-method island. Combined with Rectangle source order constructor, standalone destructor, OnPaint, this supports an explicitly authored out-of-line empty destructor rather than an implicit compiler-only destructor.
- Historical "empty/default" and unresolved explicit-versus-implicit wording is superseded, not erased. In-class inline, C++11 defaulted, non-empty, compiler-only, wrapper-owned, and inherited-Pane-owned alternatives remain rejected.
- Class score is now `94/95`; UID0000N1 owner/emitter route and reconstructable state remain unchanged. Position `10` owns the complete class CPP/H preamble before method children.

## Parent-Gate Decision

This class now clears the `85/85` direct-parent gate for [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md). The exact vtable child is a `RectangleControlPane` class artifact, not a file-level free object and not owned by the mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate. Keep this class attached to [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md), which already clears the file-level gate.

## Cross-References

- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md)
- [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md)
- [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)

## 2026-08-16 B006 Complete Class Reconciliation

- Exact complete-object size is `0x108`; multiple views begin at `0`, `0xA0`, and `0xA4`. The class adds no members beyond inherited ControlPane/Pane/GrafPort/LObject/EventHandler/TimerHandler state.
- Source position `10` emits the CPP preamble and complete H declaration. Constructor, ordinary destructor, OnPaint, and HitTestPart emit at positions `20`, `30`, `40`, and `50`.
- The constructor calls `ControlPane(8,bounds)` and inherited `SetDrawColor(drawColor)`. Its three vptr stores are compiler mechanics. The sole ordinary caller is the MiniMap dialog path at `0x0045252c`, which is a consumer rather than owner.
- The ordinary destructor source is intentionally empty and out of line. The two adjustors and scalar deleting wrapper are generated from that virtual destructor and the three-view hierarchy; their explicit vptr, base teardown, flag, and deallocation operations must not appear in human source.
- OnPaint copies inherited bounds and directly invokes Surface-owned `g_pfnFillRect(this, &bounds)`; no GrafPort member wrapper is declared or inferred. HitTestPart has `retn 8`, ignores two integer coordinates, and returns `21`; named CheckBox and Scrollable same-slot overrides settle that ABI and supersede the historical type-id label.
- UID0002OE and UID0003IT remain class-owned binary/type evidence but are non-reconstructable and non-emitting because the compiler materializes their vtables/RTTI from this declaration.
- Exact original source spelling/file debug records are unavailable. The selected names and protected/public layout are the highest-probability human source form and intentionally replace raw IDA labels rather than preserving them.

## Changes

- 2026-08-16 B006 Surface dependency closure callback:
  - Added the required `../../render/Surface.h` CPP include while leaving the formal H byte-for-byte semantically unchanged.
  - Replaced the earlier source-facing `FillRect` member shorthand with exact direct-global `g_pfnFillRect(this, &bounds)` dispatch. Existing Surface declarations and the observed ECX-plus-one-stack-argument call establish this route; the generated GrafPort header chain has no callable `FillRect` member.
  - Preserved `94/95`, UID0000N1 owner/emitter routing, source positions, complete class layout, all four authored definitions, and every compiler-product exclusion.

- 2026-07-14 B001 UID0004HL source-quality callback:
  - Preserved class score, owner/emitter route, reconstructable state, and formal C++.
  - Replaced current empty/default wording with the authored out-of-line empty destructor disposition and incorporated exact pointer/xref/EH negatives, RTTI view layout, compiler wrapper/base boundary, CheckBox comparator, source order, and rejected/historical alternatives.

- 2026-07-05 B001 implementation callback for `00011Q-RectangleControlPaneCore-source-quality.md`:
  - Linked the exact ordinary destructor child [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md), which owns the empty/default `RectangleControlPane::~RectangleControlPane()` source body.
  - Preserved the distinction that [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) and [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) are no-code compiler-generated destructor glue.
- 2026-06-21 B007 scalar deleting destructor Rule 26 incorporation:
  - No class score change. Updated the non-deleting destructor helper endpoint from `0x00499cfe` to half-open `0x00499cff`, changed scalar deleting destructor wording from source-like destructor/delete wrapper to no-code MSVC compiler wrapper, and recorded the ordinary destructor versus deleting wrapper source-placement decision.
  - Evidence incorporated: [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) has vtable/adjustor-only inbound reachability, base [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown, MemoryMan-backed [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), a guarded no-free branch, and no Rectangle-specific source cleanup. The accepted source-facing destructor placement is the ordinary helper now documented as [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md)/class declaration; no source method should be emitted for the scalar deleting wrapper.
- 2026-06-21 B010 scalar deleting destructor Rule 26 recheck:
  - No class score change. Expanded the scalar deleting destructor evidence to include local PE/Capstone confirmation of the `0x55` body, nine-byte prepad, eleven-byte postpad, `this-0xa0`/`this-0xa4` adjustor routes, primary vtable pointer route, delete-flag behavior, `0x004f4ac0` normal delete path, and `0x0041b6a0` guarded size-delete path with object size `0x108`.
  - Source placement remains unchanged: the class/file declaration or ordinary helper now documented as [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) is the only appropriate destructor source surface; [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) has no owner/emitter and must not produce a comment-only generated marker.
- 2026-06-19 B005 paint implementation support update:
  - No class score change. Updated the paint row and evidence notes to match [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md)'s accepted `86/90` first-draft C++ state.
  - Evidence incorporated: `OnPaint` as best current source-facing name with `Paint` as the likely alternate, vtable-only reachability at `0x00618478`, inherited Pane `+0x44` bounds copy via `0x004b8e00`, `FillRect` over [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc`, rejection of generated invalidation and cleanup/destructor interpretations, and RectangleControlPane owner/emitter routing.
- 2026-06-19 B004 constructor source-quality implementation support update:
  - No class score change. Updated the constructor row and evidence notes to match [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md)'s accepted `88/92` first-draft C++ state.
  - Evidence incorporated: exact source constructor shape `RectangleControlPane(int drawColor, const RectBounds *bounds) : ControlPane(8, bounds)`, three Rectangle vtable installs as compiler output, inherited draw-color setter call writing `this+0x74`, MiniMapDialog as the sole consumer rather than owner, and current-gate wording replacing the stale class-level `95/95` no-code blocker.
- 2026-06-12 A004 Batch 331:
  - No score change. Replaced the mixed vtable-layout reference with exact source-local child [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md), which routes directly to this class; the old [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) page remains a non-emitting mixed-owner index.
- 2026-06-05 A004 live refresh:
  - Before: the class still carried recovered-source provenance, blank parent metadata, and older stale-tool caveats.
  - After: raised from `82/84` to `84/88`, attached to [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md), removed stale provenance, added the omitted `0x00499ce0` helper, and kept final C++ blank.
  - Evidence: live IDA confirms constructor/helper/paint/destructor/type-id sizes, constructor caller, vtable refs, color setter, bounds/draw callback path, adjustor-thunk routing, and source-file parent eligibility.

- 2026-06-11 Agent-A006 Batch 147 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - After: `COMPLETION:85`, `CONFIDENCE:89`.
  - Evidence: live IDA reconfirmed all modeled method bounds, the single minimap constructor caller, constructor/helper/destructor stores to all three Rectangle vtable bases, paint/type-id slot data refs, and scalar destructor refs. This raises the direct class parent enough for exact vtable-data child [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) while preserving final-source caveats for inherited slot names and exact member spelling.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/84`.
  - Before: The page was unevaluated despite documenting constructor, paint, destructor thunk handling, type id, vtables, and generated teardown pollution.
  - After: Scored as high completion and strong confidence for a small visual control.
  - Evidence: Existing method notes, IDA caller/vtable evidence, destructor thunk classification, and control-pane cross-references support the score.
