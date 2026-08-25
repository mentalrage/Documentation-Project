*** UID:00009G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../render/NewHumanImageLib.h"
#include "../ui/core/ControlPane.h"

struct MouseEvent;
struct RectBounds;

class NewUserShapeSelectControlPane : public ControlPane
{
public:
    NewUserShapeSelectControlPane(short initialSelectedSlot,
                                  bool useMaleShapeBank,
                                  const RectBounds *bounds,
                                  unsigned char controlFlags);
    virtual ~NewUserShapeSelectControlPane() {}

    virtual bool OnTimerEvent(int timerId, int, int);
    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *outParams,
        unsigned char shapeIndex) const;
    void AdvanceDirection();
    short StepShapeForward();
    short StepShapeBackward();
    short SelectNextPage();
    short SelectPreviousPage();
    bool IsSelected() const;
    void SetSelected(bool selected);

    void SetMaleMode()
    {
        m_bodyMode = 2;
        InvalidateBounds();
    }

    void SetFemaleMode()
    {
        m_bodyMode = 6;
        InvalidateBounds();
    }

    short SelectedShapeSlot() const { return m_selectedShapeSlot; }
    short ShapePage() const { return m_shapePage; }

private:
    int SelectShapeAtPoint(int localY, int localX);

    unsigned short m_reservedShapeState;
    unsigned short m_maxShapeIndex;
    unsigned short m_bodyMode;
    unsigned short m_animationFrame;
    unsigned char m_direction;
    unsigned char m_padding111;
    unsigned short m_animationTick;
    unsigned char m_reservedDrawState;
    unsigned char m_padding115;
    short m_selectedShapeSlot;
    short m_shapePage;
    bool m_mouseTracking;
    unsigned char m_padding11b;

};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewUserShapeSelectControlPane

## Status

- Confidence: very strong for class ownership, the exact `0x11c` layout, three-view vtable/RTTI anchors, authored and compiler-only method inventory, timer/mouse/paint/select behavior, complete header contract, and standalone login/create-user placement. Private source spellings remain inferred where symbols were stripped.
- Likely source file: [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address range: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- Final source pair: `NexusTK/login/NewUserShapeSelectControlPane.cpp` and `NexusTK/login/NewUserShapeSelectControlPane.h`. Historical `source-3/simroot_v2/class_NewUserShapeSelectControlPane.cpp` is retained only as a corrected provenance lead, not source authority.
- Parent attachment: [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md). This class emits the complete declaration at H position 10; exact method bodies remain on [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md).

## Class Purpose

`NewUserShapeSelectControlPane` is the animated body-shape preview/selection control used by newer create-user dialogs. It owns direction cycling, timer-based animation, hit testing, frame painting, point-to-shape selection, and the descriptor-building helper that the dialog uses before packet serialization.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserShapeSelectControlPane` | `0x004fd520` | Constructs the control through `ControlPane(8, bounds)`, seeds selected slot/body mode/page/direction/animation state, stores vtable views, and schedules the 200 ms animation timer. |
| `BuildPreviewParams` | `0x004fd610` | Builds the body-shape render/create-character descriptor from current mode/direction/shape state and a resolved shape index; packet serialization belongs to `NewCreateUserDialogPane`. |
| `AdvanceDirection` | `0x004fd660` | Rotates preview direction. |
| dialog-owned select-male/select-female tails | `0x004fd680`, `0x004fd6a0` | Tails of `NewCreateUserDialogPane` helpers `0x0052d060`/`0x0052d0b0`; set body mode `2`/`6` and invalidate the selector. Not standalone selector methods. |
| `StepShapeForward` / `StepShapeBackward` | `0x004fd6c0`, `0x004fd730` | Retained source-authored signed-short helpers that step selected shape slot state and redraw. They have no surviving inbound xrefs, but exact bodies, class state, neighboring source, and period-compiler fallthrough support ordinary methods rather than compiler glue. |
| `SelectNextPage` | `0x004fd790` | Moves to the next 15-entry page, clamps on the last page, adjusts the selected slot for a short last page, and redraws. |
| `SelectPreviousPage` | `0x004fd850` | Moves to the previous page, clamps at zero/last page, adjusts selected slot on a short last page, and redraws. |
| `IsSelected` / `SetSelected` | `0x004fd8f0`, `0x004fd900` | Retained compatibility API: the getter returns false and the setter is an intentional no-op. |
| `OnTimerEvent` | `0x004fd910` | Advances animation frame and schedules next timer. |
| `OnMouseEvent` | `0x004fd970` | Hit-tests shape area and delegates shape selection. |
| `OnPaint` | `0x004fda30` | Draws current shape preview frames using `g_pEPFLib`, `USERPART.EPF`, `USERPART.PAL`, and `g_pNewHumanImageLib`. |
| `SelectShapeAtPoint` | `0x004fdc90` | Converts local mouse coordinates in `(localY, localX)` order to selected shape slot/page state. |
| Destructor family | `0x0050253a`, `0x00502545`, `0x00502a70` | Compiler adjustors and scalar deleting wrapper represented by [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md) and [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md). The source cause is the ordinary inline empty virtual destructor in the formal H. |

## Exact Class Layout

The constructor allocation and member accesses establish size `0x11c`. [UID:000038][ControlPane](by-class/ControlPane.md) occupies `[+0x000,+0x108)`; the selector adds the following exact tail. Explicit padding is retained because the formal H must reproduce the observed ABI rather than hide unaccounted bytes.

| Offset | Size | Formal member | Evidence-backed role |
| --- | ---: | --- | --- |
| `+0x108` | 2 | `m_reservedShapeState` | Constructor-zeroed selector state; no stronger semantic use survives. |
| `+0x10a` | 2 | `m_maxShapeIndex` | `GetShapeCount()-1`; bounds paint and point selection. |
| `+0x10c` | 2 | `m_bodyMode` | Male/female bank selector; exact mode values 2 and 6. |
| `+0x10e` | 2 | `m_animationFrame` | Four-frame timer animation state. |
| `+0x110` | 1 | `m_direction` | Byte direction advanced modulo four. |
| `+0x111` | 1 | `m_padding111` | Alignment/padding byte. |
| `+0x112` | 2 | `m_animationTick` | Timer tick counter incremented with each animation event. |
| `+0x114` | 1 | `m_reservedDrawState` | Constructor-zeroed draw state; no stronger meaning survives. |
| `+0x115` | 1 | `m_padding115` | Alignment/padding byte. |
| `+0x116` | 2 | `m_selectedShapeSlot` | Selected cell in the current 15-entry page. |
| `+0x118` | 2 | `m_shapePage` | Current shape page. |
| `+0x11a` | 1 | `m_mouseTracking` | Drag-selection state. |
| `+0x11b` | 1 | `m_padding11b` | Tail padding completing size `0x11c`. |

The formal H includes [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) through `NewHumanImageLib.h` because `BuildPreviewParams` returns and writes the complete type. `SetMaleMode`, `SetFemaleMode`, `SelectedShapeSlot`, and `ShapePage` are inline header APIs inferred from their dialog-owned terminal chunks and call shape; they must not be duplicated as out-of-line selector bodies.

## State And Layout Anchors

| Evidence | Class-level meaning |
| --- | --- |
| [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) records constructor initialization through selected shape/page/direction/animation fields, caller-provided `rand()%15` initial slot, `ControlPane(8, bounds)`, and a `200` ms timer registration. | Confirms this class owns the animated body-shape selector state rather than merely delegating to `NewCreateUserDialogPane`. |
| Constructor stores vtable heads at `0x0061d608`, `0x0061d670`, and `0x0061d6a0`; timer/mouse/paint virtual entries point to `0x004fd910`, `0x004fd970`, and `0x004fda30`; `0x0061d608` also references scalar deleting destructor `0x00502a70`. | Confirms class-level ownership for the constructor, virtual handler set, and destructor support. |
| Direction helper `0x004fd660` advances field `+0x110` modulo four. | Supports the preview-facing direction field, while the final source field name remains provisional. |
| Tail chunks `0x004fd680` and `0x004fd6a0` write mode values `2` and `6` at `+0x10c` and redraw through vtable slot `+0x20`. | Records dialog-owned select-male/select-female interaction; they are excluded from standalone selector method emission. |
| Raw helpers `0x004fd6c0-0x004fd72c` and `0x004fd730-0x004fd786` step field `+0x116`, clamp against `g_pNewHumanImageLib` shape counts, and redraw through vtable slot `+0x20`, but have no current inbound xrefs. | Keeps source-bearing retained helpers visible without claiming a live caller. |
| `OnMouseEvent` hit-tests with the project point helper order `PointInRect(y, x, bounds)` and passes `(localY, localX)` to `SelectShapeAtPoint`. | Prevents the common decompiler-order inversion when source C++ is emitted. |
| `SelectShapeAtPoint` at `0x004fdc90-0x004fdd33` converts local mouse coordinates into page/shape selection state and dispatches redraw. | Confirms point-to-shape conversion belongs on this class, not on the surrounding dialog. |
| The exact core range ends at `0x004fdd33`, followed by padding before [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md). | Keeps the class boundary separate from adjacent password-dialog code in the mixed aggregate. |

## Reconstruction State

- Reconstructable: true, because this is NexusTK-owned create-user selector behavior and class declarations must rebuild its vtables/methods.
- Parent: [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md), with [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) as the umbrella family.
- Class CPP remains blank by placement. This page now owns the complete formal H declaration at source position 10; method-body CPP is populated only on exact child [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md). Compiler adjustors, deleting wrapper, and vtable/RTTI data remain non-emitting consequences of that declaration.

## Evidence Notes

- B001 MCP session `80de0a67` confirms the modeled local starts: `0x004fd520`, `0x004fd610`, `0x004fd660`, `0x004fd790`, `0x004fd850`, `0x004fd900`, `0x004fd910`, `0x004fd970`, `0x004fda30`, and `0x004fdc90`; the next function starts at `0x004fdd40` after padding.
- Xref checks show `NewCreateUserDialogPane` constructs this control at `0x0052c7aa`; `BuildPreviewParams` is called from `0x0052d85f`; `AdvanceDirection` is called from `0x0052cedf` and `0x0052d24a`; `SelectNextPage`/`SelectPreviousPage` are called from `0x0052ce6e` and `0x0052cdce`; and `SelectShapeAtPoint` is called from the local mouse handler at `0x004fd9d3`.
- Exact core memory coverage records the constructor, `BuildPreviewParams`, `AdvanceDirection`, retained no-xref raw shape-step helpers, `SelectNextPage`, `SelectPreviousPage`, timer handler, mouse handler, `OnPaint`, and `SelectShapeAtPoint` as one class-method cluster. The physical tails `0x004fd680`/`0x004fd6a0` remain documented but excluded from standalone selector emission.
- Live decompilation confirms the constructor writes class vtables, initializes selector fields through `+0x11a`, schedules a `200` ms timer, and seeds max shape index from `g_pNewHumanImageLib->GetShapeCount() - 1`; paint draws a 5-by-3 selector grid using `USERPART.EPF`/`USERPART.PAL`, `g_pEPFLib`, and `g_pNewHumanImageLib`; point-to-shape maps local pixels into clamped 5-column by 3-row selection state.
- The final standalone `NexusTK/login/NewUserShapeSelectControlPane.{h,cpp}` placement is supported by decorated RTTI, independent method/vtable/compiler islands, a separate consumer class, and a public header dependency. Historical fold proposals into [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) or [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) are rejected because they conflate class identity, compiler support, source ranges, and header ownership.

## Score Rationale

Completion `93` reflects the complete authored/retained/compiler inventory, exact `0x11c` layout, resolved standalone owner/emitter route, complete H declaration, exact core child, inline API causes, packed render-type dependency, and split compiler-support pages. Confidence `94` reflects direct constructor/member accesses, calls, three-view vtables/RTTI, destructor routes, resources/globals, and exact boundary evidence. The remaining margin is limited to stripped private identifier spellings and final build-level comparison; raw labels and source-placement uncertainty no longer block reconstruction.

## Cross-References

- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md)
- [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md)
- [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md)
- [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md)

## Changes

- 2026-08-11 B005 UID0000LY whole-file callback:
  - Raised `85/88 -> 93/94`; owner/emitter remain [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md), with H position 10.
  - Added the exact `0x11c` class layout and compile-closed formal H, including inline mode/accessor APIs and the ordinary empty virtual destructor that regenerates the split compiler support.
  - Finalized `StepShapeForward`/`StepShapeBackward`, compatibility `IsSelected`/`SetSelected`, standalone source placement, exact HumanImageRenderParams dependency, and links to the adjustor/scalar-destructor/type pages. Historical fold and retained-name assumptions remain documented as corrected alternatives.

- 2026-06-25 B001 accepted source-quality synchronization:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized method names and class evidence with accepted [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md): `BuildPreviewParams`, `AdvanceDirection`, `SelectNextPage`, `SelectPreviousPage`, `SelectShapeAtPoint(localY, localX)`, retained `StepShapeForwardRetained`/`StepShapeBackwardRetained`, timer/mouse/paint slots, dialog-owned select-male/select-female tail exclusion, `g_pNewHumanImageLib`, `g_pEPFLib`, `USERPART.EPF`, and `USERPART.PAL`.
- 2026-06-07 (A010): Raised completion from `74` to `80` and attached the class to [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md).
  - Evidence added: exact core range/state model from [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), login/create-user parent rationale, boundary before ChangePasswordDialogPane, reconstruction-state notes, and final-C++ blockers.
  - Limitation: IDA MCP was unavailable earlier in this session, so this pass consolidates existing by-* evidence.
- 2026-06-13 C001 Goal 2 low-completion/low-both pass:
  - Changed from: `COMPLETION:80`, `CONFIDENCE:84`, parent [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, parent unchanged.
  - Evidence: live IDA 9.1 MCP reconfirmed the modeled method starts, raw unmodeled page-step helpers, constructor/helper/vtable/destructor xrefs, decompiled timer/mouse/paint/select behavior, and exact boundary evidence on [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md). This class now clears the strict direct-parent gate for [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md).
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed shape-control constructor/direction/timer/mouse/paint/select/thunk/deleting-destructor starts at `0x004fd520`, `0x004fd660`, `0x004fd910`, `0x004fd970`, `0x004fda30`, `0x004fdc90`, `0x0050253a`, `0x00502545`, and `0x00502a70`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` even though the page already described purpose, method boundaries, caller evidence, destructor family, and create-user relationships.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: IDA confirms all local method starts and the page documents direction cycling, timer animation, hit testing, painting, shape selection, and constructor use by `NewCreateUserDialogPane`; remaining gaps are detailed field layout and unconfirmed direct construction from `NewUserDialogPane2`.
