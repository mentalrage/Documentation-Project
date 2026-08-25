*** UID:0000A2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"
#include "../../input/InputMan.h"
#include "Layer.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_PANE_H
#define NEXUSTK_UI_CORE_PANE_H

#include "../../render/GrafPort.h"
#include "../../util/TimerHandler.h"
#include "EventHandler.h"
#include "RectBounds.h"
#include "Region.h"

class Layer;
class Message;
struct RuntimeClass;

class Pane : public GrafPort, public EventHandler, public TimerHandler
{
public:
    explicit Pane(unsigned char mode);
    virtual ~Pane();
    virtual void OnChangeMessage(LObject *owner, Message *message);
    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void DrawOnTarget(GrafPort *target, const RectBounds *bounds,
                              const RectBounds *clipBounds);
    virtual void Show();
    virtual void Hide();
    virtual Pane *GetParentPane();
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void GetDescription(int descriptionId, wchar_t *description);
    virtual RectBounds *GetScreenBounds(RectBounds *outBounds) const;
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *previousBounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void InsertInLayer(RectBounds *bounds, int order,
                               Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void SetPaneOrder(Pane *beforePane, Pane *afterPane);
    virtual void UnregisterEventHandler();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool HandleType19Event(Event *event);
    virtual void GetLocalOffset(Point *offset);
    virtual void GetScreenOffset(Point *offset);
    virtual bool ShouldAcceptEvent() const;
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void SetMode(unsigned char mode);
    bool IsAttachedToLayer() const;
    void SetFocusRegistration(bool active);
    void MarkForDeletion();
    void NotifyPaneMessageHandled(bool handled);

protected:
    void CaptureMouse();
    void ReleaseMouseCapture();

    Layer *m_layer;
    Point m_origin;
    bool m_visible;
    unsigned char m_mode;
    Pane *m_redrawPeerPane;
    unsigned int m_redrawState;
    bool m_redrawPending;
    Region m_pendingMotionRegion;
    bool m_inMotionPaint;
    Region m_motionRegion;
    unsigned int m_inputRegistrationState;
    bool m_pendingDelete;
    bool m_hasPendingMotionRegion;
    bool m_drawOnTarget;
};

typedef char PaneSizeMustBe248[sizeof(Pane) == 0xf8 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Pane

## UID0000KB Mouse Capture Declaration Closure - 2026-08-15

- InventoryScrollPane's pointer handler calls the inherited nonvirtual Pane methods `CaptureMouse()` on accepted press and `ReleaseMouseCapture()` when the active interaction ends. Existing Pane and consumer evidence establishes those normal source-facing declarations; adjusted facets or local ScrollInventoryPane wrappers are not source methods.
- The two declarations belong in Pane's protected section before data members. They add no fields, virtual slots, bodies, or ownership changes, and the exact `0xf8` size assertion remains unchanged.
- The formal H insertion closes declaration visibility for InventoryScrollPane while preserving all prior multiple-inheritance, bounds, layer, timer, event and deletion contracts.

## UID0000KA Inherited Declaration Closure - 2026-08-15

The complete Pane header now exposes two already-documented inherited helpers consumed by InventoryPane source: `MarkForDeletion()` for the InterfaceEfx lifetime path and `NotifyPaneMessageHandled(bool)` after opcode `0x59` help handling. These are declarations of existing Pane behavior; they add no fields, vtable cells, source bodies, or ownership transfer, and the exact 0xF8 size assertion remains unchanged. `InventoryPane.cpp` continues to own only its feature behavior.

## C134 Header Assembly Closure

The canonical multiple-inheritance declaration is emitted once under `NEXUSTK_UI_CORE_PANE_H`. Guarded GrafPort, TimerHandler, EventHandler, RectBounds, and Region headers provide all complete bases and by-value members before the `0xf8` assertion. Pane method bodies continue through the CPP child route; the H channel intentionally omits an empty child marker so generated source contains no invalid attachment attribute.

## UID000090 Complete Pane Dependency And Source-Child Closure - 2026-07-31

- The exact `0xf8` Pane layout is now emitted from complete bases rather than forward declarations: `GrafPort` occupies `+0x000..+0x09f`, the EventHandler facet is at `+0x0a0`, the TimerHandler facet is at `+0x0a4`, and Pane-owned state occupies `+0x0a8..+0x0f7`. `LObject` is visible through complete `GrafPort.h`; it is not duplicated locally.
- The five previously corrected primary declarations remain unchanged. Six concrete EventHandler overrides, `GetLocalOffset`, `GetScreenOffset`, `ShouldAcceptEvent`, `OnTimer`, and `SetFocusRegistration` are now declared explicitly so Pane is a concrete source class and its three compiler-emitted vtable views follow from ordinary C++.
- The tail fields are exact by offset and role: `m_layer +0xa8`, `m_origin +0xac`, `m_visible +0xb4`, `m_mode +0xb5`, natural alignment `+0xb6..+0xb7`, `m_redrawPeerPane +0xb8`, `m_redrawState +0xbc`, `m_redrawPending +0xc0`, `m_pendingMotionRegion +0xc4`, `m_inMotionPaint +0xd8`, `m_motionRegion +0xdc`, `m_inputRegistrationState +0xf0`, and the three terminal booleans at `+0xf4..+0xf6`; natural tail alignment ends the object at `0xf8`.
- Bounds remain inherited as `GrafPort::m_visibleBounds`; the historical Pane-local `m_bounds` declaration was layout-incompatible and is preserved only as a rejected assumption. The Pane.cpp preamble includes complete `InputMan` and `Layer` declarations because exact children call their members; PCH-only and forward-only member-call routes are rejected.
- Exact children are `[0x00544db0,0x00544e09)` default event handlers, `[0x00544e10,0x00544e25)` local offset, `[0x00544e30,0x00544e66)` screen offset, `[0x00544e70,0x00544e8a)` event acceptance, `[0x00544e90,0x00544e95)` timer default, and `[0x00544ea0,0x00544eda)` focus registration. Compiler alignment between those ranges remains excluded from handwritten source.

## UID0003ZT Complete Base And Facet Visibility - 2026-07-23

- The complete Pane declaration belongs in `NexusTK/ui/core/Pane.h`, which includes `GrafPort.h`, `EventHandler.h`, and `TimerHandler.h` before defining Pane.
- GrafPort supplies the complete graphics/base layout; EventHandler and TimerHandler supply the inherited event and timer facets used by concrete panes. Those includes do not transfer ownership of any dependency into Pane.
- MapPane inherits these facets through Pane. Its source uses `HandleSystemOrControlEvent(Event *)`, explicit inherited `TimerHandler::CancelTimer`/`ScheduleTimer`, and inherited `CaptureMouse`/`ReleaseMouseCapture`; it does not declare an embedded `m_timerHandler` or MapPane-local capture helpers.
- Member-access code still includes complete Event.h separately because EventHandler.h uses pointer-only forward declarations.
- At the 2026-07-23 checkpoint this source-header closure still preserved the then-blank broad formal policy. The accepted 2026-07-30 UID0002MZ callback supersedes only that declaration deferral: formal H now carries the complete current `Pane` declaration, including inherited `InvalidateRect(const RectBounds *)`, while formal CPP keeps the owner include and `[[CHILDREN]]` route. The `90/91` score, [UID:0000MC][Pane](by-file/Pane.md) owner/emitter, Layer/GrafPort/layout/method/default/compiler facts, and every existing child relationship remain unchanged.

## Layer Consumer Synchronization - 2026-07-14

Pane remains a public API client of [UID:000073][Layer](by-class/Layer.md), not the owner of Layer source. The accepted routes are exact: Pane::AddToLayer calls [UID:0004NT][0x004f0630-0x004f083c.LayerAddChildAfter](by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md) at `0x00544c93`; InsertInLayer calls [UID:0004NU][0x004f0840-0x004f0a5d.LayerAddChildBefore](by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md) at `0x00544cc6`; destructor/remove paths call [UID:0004NV][0x004f0a60-0x004f0b3d.LayerRemoveChild](by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md) at `0x0054460a/0x00544d19/0x00544fe1`; IsAttachedToLayer calls [UID:0004NZ][0x004f0d20-0x004f0d93.LayerContainsPane](by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md) at `0x00544c60`; invalidation calls [UID:0004O0][0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion](by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md) at `0x005449c3`; parent lookup calls UID0004O9 at `0x005447ae`; and screen-offset routes call UID0004OA at `0x005447d3/0x00544e46`.

Layer borrows Pane pointers. Pane visibility and traversal-blocking accessors initialize distinct LayerNode bytes `+0x28/+0x29`; paneFlags is a separate byte `+0x04`. The raw Layer GetPaneFlags/GetChildList members preserve an attached-pane precondition and do not add defensive null results. Scores and route are unchanged; the later UID0002MZ callback replaces only the historical blank-declaration policy with the complete formal H above.

## Status

- Confidence: strong for base-class ownership, layout/vtables, core method families, and the exact `GetDescription` default; broad unrelated helper/header spellings remain incomplete.
- Likely source file: [UID:0000MC][Pane](by-file/Pane.md)
- Main address range: [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- Type docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_Pane.cpp`

## Class Purpose

`Pane` is the base class for most UI elements. It inherits or embeds `GrafPort` at the front of the object, then layers on event handling, timer handling, visibility, dirty-region, clip-region, and layer-membership behavior.

## Observed State

IDA-confirmed offsets and generated-name hints are consolidated in [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). Important state includes:

```text
0x000  GrafPort base
0x0a0  EventHandler secondary view
0x0a4  Timer/event tertiary view
0x0a8  attached Layer*
0x0ac  Point m_origin.y
0x0b0  Point m_origin.x
0x0b4  visible flag
0x0b5  pane mode byte
0x0c4  pending/alternate motion Region
0x0d8  in-paint/motion-lock byte
0x0dc  clip Region
0x0f0  input/focus registration state
0x0f4  dismissed/deletion marker
0x0f5  pane flags
0x0f8  first derived-class field

Inherited `GrafPort` state lives in the leading subobject and remains documented on [UID:00005V][GrafPort](by-class/GrafPort.md) and [UID:0000JR][GrafPort](by-file/GrafPort.md). Pane-facing uses of that leading state include `+0x44` as `GrafPort::m_visibleBounds` and inherited region/draw-state fields used by dirty, clip, and backing-store helpers. The Pane-owned origin is `Point m_origin`, with Y at `+0xac` and X at `+0xb0`, matching the accepted `Point { int y; int x; }` declaration. Do not treat legacy generated duplicate offsets such as `0x64/0x68/0x6c/0x78/0x79` as separate Pane-owned fields; the Pane-owned additions are the `+0xa0..+0xf7` fields documented in [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md).
```

## Bounds And Origin Source Contract - 2026-07-16

- Primary slot `+0x28` is `GetScreenBounds(RectBounds *)`. It obtains the pane's screen offset through the EventHandler view, copies inherited `GrafPort::m_visibleBounds`, and offsets the output into screen coordinates.
- Primary slot `+0x2c` is `SetBounds(const RectBounds *, const RectBounds *)`. The Pane base ignores its second argument, initializes a local `Point` from top/Y and left/X, copies it into `m_origin` in Y/X order, localizes a stack rectangle by negative X/Y, and dispatches primary `+0x0c`.
- Primary slot `+0x0c` is `UpdateRenderRegion(const RectBounds *)`.
- `Point m_origin` is exact source-facing inherited state: `m_origin.y` at `+0xac`, `m_origin.x` at `+0xb0`. This order is independently used by ObjectPane UID0003XX, LoginDialog, IMEComposition, MapPane, FittingRoom UID0002DG, and FlyingParcel owner-normalized paths.
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) is the source-ready ObjectPane `UpdateRenderRegion` override. [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) is the source-ready ObjectPane `SetBounds` override and adds object-data propagation after directly updating inherited state.
- Historical FlyingParcel `m_origin.x` at owner `+0xac`, swapped FittingRoom point order, and generic `m_bounds`/`m_localBounds` ownership are superseded. At that evidence checkpoint this bounded clarification alone did not justify replacing the broad blank Pane class formal or changing the `90/91` score; the later UID0002MZ dependency audit independently supplied the complete formal H now present above.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/destruction | `0x00544460`, `0x00544580`, scalar wrapper `0x00544f50` | Initializes `GrafPort`, handlers, regions, mode/visibility state; ordinary `Pane::~Pane` at `0x00544580-0x00544687` releases Pane-owned dispatcher/layer/region/handler state and chains to `GrafPort` cleanup. The older `0x004b8d20` reference is `GrafPort` cleanup, not the Pane ordinary destructor. |
| Mode state | [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) | Exact mode-byte setter for `+0xb5`; calls primary vtable slot `+0x20` / `0x00544800` `Pane::InvalidateRect` with local bounds when the mode changes. |
| Description virtual | [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) | Exact primary slot `+0x24` default `void Pane::GetDescription(int selectedIndex, wchar_t *outDescription)`: writes one wide NUL only for sentinel index `-1`, otherwise returns without writing. DescPane consumes the virtual through a borrowed Pane pointer. |
| Collapse/switch-out | [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) | Exact `Pane::Collapse()` child; calls `RemoveFromLayer`, builds an all-zero `RectBounds`, and calls inherited `UpdateRenderRegion`. Only GeneralPurposePanel switch methods call it. |
| Visibility/redraw | `0x00544730-0x005448ab` | Show, hide, repaint, and dirty-region invalidation. |
| Parent/layer lookup | `0x005447a0` | Exact primary virtual `Pane::GetParentPane()`: reads the attached `Layer *` at `+0xa8` and calls the Layer parent-pane lookup. Historical vtable text calling this specific slot `Repaint` is superseded. |
| Dirty/motion paint state | `0x00544690-0x00544b7d` | Deferred deletion marker, active/pending motion-region copy/subtract, motion comparison, begin-paint, and end-paint helpers used by layer traversal. |
| Bounds/layer membership | `0x00544b80-0x00544d70` | `GetScreenBounds`, base `SetBounds` using Y/X `Point m_origin` and localized RectBounds, attached-layer test at `0x00544c50`, and add/insert/remove from `Layer`. |
| Default virtuals/thunks | `0x0041d680`, `0x0041b6a0`, `0x00544db0-0x00544e90`, `0x00544f2e-0x00544f44` | Three-argument no-op `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` direction, empty OnPaint default, exact EventHandler default family, true-return OnTimer default, and compiler-generated destructor adjustors. |
| Deferred deletion integration | `0x00469180` via [UID:00000W][BlackHole](by-class/BlackHole.md) | Pane close/replacement paths call a global helper that invokes `RemoveFromLayer`, `UnregisterEventHandler`, timer cleanup, and deferred deletion queueing. |

## Evidence Notes

- UID0002NB's complete inherited primary map resolves `+0x04` as
  `LObject::GetRuntimeClass`, `+0x08` as the default change-message hook,
  `+0x0c` as `GrafPort::UpdateRenderRegion`, `+0x10` as the stripped
  three-argument no-op `DrawOnTarget` direction, and `+0x44` as the empty
  Pane OnPaint default.
- The EventHandler facet at `+0xa0` follows the exact 11-slot pointer/key/IME/packet/system/type-19/order/pair/acceptance contract. The TimerHandler facet at `+0xa4` carries the inherited `OnTimer(int,int,int)` true default.
- EventHandler and TimerHandler are inherited facets through Pane, not additional direct source bases or explicit vptr fields in derived class declarations.

- IDA MCP reports 95 direct constructor call sites.
- Generated source shows many feature panes calling `Pane::Pane` directly.
- `Pane::AddToLayer` calls `Layer::AddChildAfter`; `Pane::InsertInLayer` calls `Layer::AddChildBefore`; removal paths call `Layer::RemoveChild`.
- IDA maps pane vtable offsets `+0x38` and `+0x40` to `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`; [UID:00000W][BlackHole](by-class/BlackHole.md) uses those virtuals before queueing panes for deferred deletion.
- 2026-07-13 B004 split [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) as an exact source child. Complete live analysis proves the `+0x38` remove call, four zero rectangle stores, `+0x0c` UpdateRenderRegion call, plain return, exact callers UID00015X/UID00015Y, and boundary before compiler adjustor thunks.
- Pane has no primary `+0x48` slot. Its exact 18-slot primary table ends at `+0x44 Pane::OnPaint`; `0x00621a30` is the following secondary complete-object-locator pointer. Panel switch code uses a separate pure `OnActivate(const unsigned char *packetData)` contract introduced by PanelPane, not by Pane.
- 2026-06-17 B002 source-quality reanalysis confirms [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as `void Pane::SetMode(unsigned char mode)`: it writes `+0xb5` only when changed and dispatches primary vtable slot `+0x20`, `0x00621a08 -> 0x00544800`, with `this + 0x44`; the slot is `Pane::InvalidateRect`.
- 2026-07-12 B003 UID00012O callback split [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) from PaneCore. Complete 21-byte disassembly proves the `-1` test, one 16-bit NUL store, source-level void return, no receiver-field access, no code callers/callees, and exact padding. Primary slot `+0x24`, 382 vtable data refs, and [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md) prove the class method and concrete consumer. IDA's standalone `__stdcall` presentation is an unused-this artifact, not a static function.
- IDA maps `Pane` vtable bases at `0x006219e8`, `0x00621a34`, and `0x00621a64`; the secondary and tertiary destructor slots are the adjustor thunks `0x00544f2e` and `0x00544f39`.
- 2026-06-12 A004 split [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) as the source-local `Pane` vtable page. Live IDA MCP reconfirmed the three decorated bases, constructor/destructor/scalar-destructor store triads, adjustor thunk sizes, and the `0x00621a6c` `PanelPane` successor boundary.
- IDA caller checks tie the `0x00544690-0x00544b7d` dirty/motion helpers to `Layer` recursion and shared surface presentation. Current generated `class_MapPane.cpp` ownership for these helpers should not be treated as source-file evidence.
- 2026-06-20 B006 AboveFrame support sync records [UID:000005][AboveFrame](by-class/AboveFrame.md)'s `OnNotify()` path as another concrete `Pane::MarkForDeletion` consumer. The old generated `BulletinSession` owner label for `0x00544690` is caller/name pollution; this remains a Pane deferred-deletion helper.
- The base [UID:00004N][EventHandler](by-class/EventHandler.md) methods at `0x004a8970-0x004a8a84` are shared UI event infrastructure used by pane-derived handlers and [UID:00004M][EventDispatcher](by-class/EventDispatcher.md); the next bytes are the documented padding before [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md).

## Score Rationale

Completion `92` and confidence `94` reflect exact SetMode, GetDescription, Collapse, six default/facet/focus children, resolved UpdateRenderRegion, the exact 18-slot primary extent through `+0x44 OnPaint`, vtable routes, consumers, boundaries, owner/emitter, and managed child C++. The accepted UID0002MZ and UID000090 callbacks close the former partial-declaration and broad helper/header objections: formal H now consumes complete GrafPort, EventHandler, TimerHandler, Point/Region and LObject-visible dependencies with the exact `0xf8` layout, while formal CPP owns the exact Pane/InputMan/Layer include route and `[[CHILDREN]]` compositor; List and the six source-bearing Pane child pages have explicit declaration/body ownership. Exact method bodies remain child-owned. The remaining score cap is limited to stripped original lexical spellings, access specifiers, and exact historical source-file organization rather than incomplete first-draft Pane dependency/header work.

## Activation Contract Ownership Correction

- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) and exact [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md) bytes place Pane's primary callable extent at `[0x006219e8,0x00621a30)`, 18 dwords from destructor `+0x00` through `Pane::OnPaint` at `+0x44`.
- Cell `0x00621a30` is not callable; it is the complete-object-locator pointer for Pane's secondary EventHandler facet whose vtable begins at `0x00621a34`. The tertiary TimerHandler COL/table remain at `0x00621a60/0x00621a64`.
- The independently recovered PhotoPane primary table inherits the same Pane contract and likewise ends after `+0x44 PhotoPane::OnPaint`, with its secondary COL pointer immediately following. PhotoPane has no OnActivate entry.
- [UID:0000A4][PanelPane](by-class/PanelPane.md) introduces `virtual void OnActivate(const unsigned char *packetData)` as a new pure `+0x48` contract. PanelPane-derived implementations preserve the earlier packet-pointer signature evidence; ownership alone moves from Pane to PanelPane.
- Historical correction: the 2026-07-13 Pane pass correctly rejected a `bool showChild` signature and characterized eight derived activation implementations, but it mistook secondary RTTI metadata for a Pane slot. That valid behavioral research is retained under PanelPane while the false Pane ownership is superseded.

## Cross-References

- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md)
- [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md)
- [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- [UID:0000A4][PanelPane](by-class/PanelPane.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)

## DescPane Vtable Support Synchronization - 2026-07-16

- The bounded source-facing direction for primary slot `+0x10` /
  `0x0041d680` is
  `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`.
- Direct evidence is exact ABI/no-op behavior (`retn 0x0c`), the Layer caller
  argument flow, broad derived-table fanout, and weather-pane overrides that
  perform target drawing with the same three pointer arguments.
- The original lexical spelling is stripped; `RenderToTarget` remains a
  weaker alternative. This naming uncertainty does not change the exact ABI,
  default no-op behavior, current `90/91` score, owner/emitter route, blank
  broad class formal, or any current B004/B005 Pane union.
- Primary `+0x1c` remains exact `GetParentPane`, not Repaint. EventHandler and
  TimerHandler remain inherited facets rather than extra direct bases.

## Runtime-Class Inheritance Reconciliation

- Pane does not declare or define a separate `GetRuntimeClass` override. It inherits `const RuntimeClass *LObject::GetRuntimeClass() const` from [UID:00007D][LObject](by-class/LObject.md).
- A complete ordinary/generated source search found only the former LObject and Pane declarations; live IDA contains only `LObject__GetRuntimeClass` at `0x004f4b10`. Every inspected Pane-derived vtable uses that inherited address.
- The former line `virtual RuntimeClass *GetRuntimeClass();` was therefore a redundant, non-const declaration with no implementation. Removing only that line is compile-consistent and avoids inventing a Pane override or changing Pane's binary layout.
- Completion/confidence remain `92/94`; canonical owner/emitter UID0000MC and reconstructable true are unchanged.

## Changes

- 2026-08-15 B005 UID0000KB source-contract callback: inserted protected `CaptureMouse()` and `ReleaseMouseCapture()` declarations before Pane data members, retained `92/94`, and preserved the exact 0xf8 layout and existing body ownership.

- 2026-08-01 Agent-B004 UID0003OO support callback:
  - Removed only the unsupported redundant `Pane::GetRuntimeClass` declaration after repository-wide source and live-vtable audits found no derived implementation.
  - Retained all Pane virtuals, fields, metadata, score, owner/emitter route, and formal source structure unchanged.

- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Preserved `90/91`, owner/emitter UID0000MC, the broad blank class formal, and all current layout/method/layer/event/timer/deletion evidence.
  - Replaced the false Pane-owned `+0x48 OnActivate` statement with the exact 18-slot primary endpoint and secondary-COL identity at `0x00621a30`.
  - Retained the established pointer-valued activation behavior and moved its source ownership to PanelPane, with PhotoPane's inherited 18-slot table as independent corroboration.

- 2026-07-16 B001 UID0002NA bounded support synchronization:
  - Preserved `90/91`, owner/emitter UID0000MC, blank broad formal, and the
    complete current B004/B005 Pane union.
  - Added only the accepted `DrawOnTarget` direction and preserved exact
    `GetParentPane`, EventHandler, TimerHandler, Layer, bounds, and source
    evidence.
- 2026-07-16 B004 UID0002NB accepted support synchronization:
  - Preserved `90/91`, owner/emitter UID0000MC, blank broad class formal, and every unrelated method/layout/layer/event/timer/deletion fact.
  - Corrected exact primary `+0x1c` / `0x005447a0` to `Pane::GetParentPane()`, recorded the inherited primary/default EventHandler/TimerHandler contracts used by DialogSession/DialogInSession, and rejected extra direct bases or handwritten vptr/adjustor source.
- 2026-07-16 Agent-B005 UID0003XX accepted callback:
  - Preserved `90/91`, owner/emitter UID0000MC, blank broad class formal, complete method/layout/vtable/layer/event/timer/deletion history, and all unrelated content.
  - Added bounded `GrafPort::m_visibleBounds`, `Point m_origin.y/m_origin.x`, `GetScreenBounds`, base `SetBounds`, and `UpdateRenderRegion` source-contract evidence.
  - Linked source-ready ObjectPane UID0003XW/UID0003XX and historicalized stale X-first/synthetic bounds aliases without adding fields, declarations, or source bodies to this class page.
- 2026-07-13 B004 accepted UID00015Y callback: raised `89/89 -> 90/91`; added exact UID0004KU Collapse child, `+0x0c` UpdateRenderRegion and `+0x48` OnActivate contracts, caller/negative evidence, and score rationale while preserving the blank class formal block and all unrelated Pane state/method history.
- 2026-07-12 B003 UID00012O accepted callback: raised `88/86 -> 89/89`; added exact UID0004IX `Pane::GetDescription(int,wchar_t *)` method inventory/default semantics, primary `+0x24` route, 382-vtable-ref evidence, DescPane consumer, ABI/no-code-caller negatives, padding, and score rationale. All unrelated Pane methods, ownership, source route, layout, and blank class formal block remain unchanged.
- 2026-06-18 B002 PaneCore source-quality execution: updated the class method-family and state notes to match [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)'s split/index reclassification. The ordinary `Pane` destructor is `0x00544580-0x00544687`; stale `0x004b8d20` Pane-destructor wording is rejected as inherited `GrafPort` cleanup. Pane-owned state is the `+0xa0..+0xf7` extension block from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), while the leading inherited `GrafPort` state remains in GrafPort docs.

- 2026-06-20 B006 AboveFrame support sync: score unchanged; documented `AboveFrame::OnNotify()` as a `Pane::MarkForDeletion` consumer and rejected generated `BulletinSession` ownership for that helper.

- 2026-06-17 B002 `PaneSetMode` support sync:
  - What existed before: the class page still described [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)'s side effect as an unresolved `+0x20` notification.
  - Changed to: records `Pane::SetMode(unsigned char)` as an exact class-owned/emitted child and names `+0x20` as `Pane::InvalidateRect`; source enum names for mode constants remain provisional.
  - Evidence: B002 live IDA review resolved vtable entry `0x00621a08 -> 0x00544800`, confirmed the target body and caller usage, and populated first-draft C++ in the child page.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000MC][Pane](by-file/Pane.md) because this class is 88/86 and the parent file is 88/84. Live IDA MCP on `NexusTK.exe` confirmed core constructor/destructor/mode/visibility/dirty/layer/default/thunk starts at `0x00544460`, ordinary destructor `0x00544580`, `0x005446b0`, `0x00544730`, `0x00544690`, `0x00544b80`, `0x00544c50`, `0x0041d680`, `0x00544e90`, `0x00544f2e`, and `0x00544f39`; later B002 review corrected the older `0x004b8d20` destructor reference to `GrafPort` cleanup.
- 2026-06-12 A004 Batch 336: Added exact source-local [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) as the preferred vtable type page while retaining [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) as a non-emitting mixed-owner index.
- Before: the `PaneCore` memory page reference ended at `0x00545085`.
- Changed to: the page ends at `0x00545086`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545085` is the final operand byte of `sub_544F50`'s `retn 4`.
- Before: completion/confidence metadata were `0/0` even though the page already documented the base UI class purpose, layout offsets, method families, vtables, caller evidence, and derived infrastructure relationships.
- Changed to: `COMPLETION:88` and `CONFIDENCE:86`.
- Evidence: core offsets, construction/destruction, visibility/redraw, dirty/motion paint state, bounds/layer membership, virtual thunk material, deferred deletion integration, vtable bases, and event infrastructure are documented; remaining work is mostly raw body-level C++ and exhaustive per-caller relationship coverage.

## 2026-07-31 B002 Formal ABI Declaration Repair

- Five stale declarations are historicalized in favor of exact family-wide binary contracts: three-argument DrawOnTarget, output-buffer GetDescription, two-rectangle SetBounds, and four-argument AddToLayer/InsertInLayer.
- The NewGroupPane primary vtable and bodies independently confirm the two-rectangle SetBounds and four-argument AddToLayer shapes; this is not a target-local speculative overload.
- The repair preserves inheritance, existing Pane fields, every unrelated declaration, and [[CHILDREN]]. Score rises to 92/94 because the formal base declaration no longer contradicts exact derived ABI evidence.

## 2026-08-12 B003 MapNamePane Constructor Visibility Repair

- The H-channel constructor is now `explicit Pane(unsigned char mode);`, matching the recovered constructor direction and the pervasive derived-source pattern `Pane(0)` through `Pane(4)`. `MapNamePane::MapNamePane()` specifically delegates to `Pane(1)`.
- The former parameterless `Pane();` declaration was a stale visibility defect: it contradicted both the physical constructor ABI and the already-reconstructed derived initializers. This repair changes no class field, virtual slot, size guard, inheritance edge, CPP body, or unrelated API.
- `explicit` is appropriate for the single-byte mode constructor and prevents unintended implicit conversion while retaining the late-1990s/mid-2000s source shape used by the surrounding project.

## 2026-08-16 HistoryViewingPane SetPaneOrder ABI Repair

- Formal H now declares `virtual void SetPaneOrder(Pane *beforePane, Pane *afterPane);`. Exact body `0x00544d30-0x00544d6f` forwards the two nullable Pane facets, and the History constructor pushes `g_pScreenPane` then `NULL`, yielding source call `SetPaneOrder(NULL, g_pScreenPane)`.
- The former `Pane *referencePane, bool placeAfter` declaration is retained only as a superseded historical interpretation. Treating the second physical pointer as bool would truncate the source contract and contradict multiple two-Pane call sites; no overload is added.
## FolderSelectDialog Shared RTTI Dependencies R09/R15

These existing Pane-owned compiler RTTI records are reached from the FolderSelectDialog base array. The edge is dependency evidence only; it does not transfer source ownership or change Pane formal declarations.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R09 | `0x640540-0x64055c` BCD: TD `0x6739a0`, contained `4`, PMD `0/-1/0`, attrs `0x40`, CHD `0x64055c` | `xref_query.total=373`; FolderSelectDialog graph edge `0x647838`; outgoing TD `0x6739a0` and CHD `0x64055c` | Pane-owned compiler RTTI; FolderSelectDialog only references it. |
| R15 | `0x6739a0-0x6739b4` TypeDescriptor `??_R0?AVPane@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVPane@@` | `xref_query.total=5`, including BCD edge `0x640540`; outgoing vfptr `0x635078` | Pane-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
