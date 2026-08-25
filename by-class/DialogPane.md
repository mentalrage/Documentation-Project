*** UID:00003T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DialogPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../../render/EPFTileContext.h"
#include "Pane.h"

class ControlPane;
class Event;
class Layer;
class List;

class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    int FindControlIndex(const ControlPane *control) const;
    void SetSelectionVisualState(int controlId, unsigned char state);
    void CloseDialog();

protected:
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, short frameIndex);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    ControlPane *GetChildControl(int controlIndex) const;

    template <class T>
    T *GetChild(int controlIndex) const
    {
        return static_cast<T *>(GetChildControl(controlIndex));
    }

    virtual void DrawBackground();
    virtual void DrawBorder();
    char HitTestControls(int mouseY, int mouseX, int *outControlId);
    void DispatchInputToControl(Event *event, int controlId);
    void SavePosition(const RectBounds *unusedBounds);
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    virtual void SetHoverControl(int controlId);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RefreshActionButtonState();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginY;
    int m_dragOriginX;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinX;
    int m_dragClampMinY;
    int m_dragClampMaxX;
    int m_dragClampMaxY;
    EPFTileContext m_backgroundTileContext;
    int m_backgroundImageWidth;
    bool m_hasCustomBackground;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogPane

## 2026-08-23 UID0003KO Focused Activation Source Closure

- [UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md) now carries the exact out-of-line `DialogPane::ActivateFocusedControl()` body for `DialogPane.cpp`. The protected declaration `void ActivateFocusedControl();` above remains exactly once between `SetHoverControl` and `ActivatePendingControl`; no target H fragment, class-body copy, new field, include, or declaration is added.
- The method returns for focused id `-1` or a disabled child, then calls public `SetSelectionVisualState(m_focusedControlId, 11)`, renders, sleeps `0x85`, conditionally calls the prior selected child's `SetVisualState(10)`, clears `m_selectedControlId`/`m_selectionVisualState` to `-1`/`10`, renders again, and dispatches this class's primary `+0x48` `OnControlCommand(m_focusedControlId, 11)`. The final receiver is `DialogPane`; it is not the focused `ControlPane`.
- The source body is exact range `[0x0049de70,0x0049df14)`, 164 bytes and 47 instructions, bounded by nine and twelve `0xcc` bytes. IDA currently names its entry `loc_49DE70` and models it as a shared tail of `TextMenuItemList__OnItemActivated` at `0x00519840`; this presentation defect changes neither class ownership nor the source route.
- Nine live virtual consumers tail-forward to the body after loading their non-owning dialog owner: TextMenu, ServerItemMenu, ClientItemMenu, ServerSpellMenu, ClientSpellMenu, ArgumentedMenu, two menu-question list variants, and ServerSelectMenu `OnItemActivated`. Wrapper owner offsets are `+0x154`, `+0x158`, or `+0x14c`, and every wrapper has a vtable-cell route. They are forwarding consumers, not class/source owners.
- [UID:0003KP][0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl](by-memory/0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md) remains a separate isomorphic pending-id method. No split, merge, range, layout, owner/emitter, score, vtable, or unrelated source change follows from closing UID0003KO.

## 2026-08-18 ObjectImage Selection-State Visibility Closure

- SetSelectionVisualState(int controlId, unsigned char state) is declared exactly once in public immediately after FindControlIndex. The former protected declaration has been removed without moving or duplicating the body.
- The direct non-derived ObjectImageButtonPane call 0x00520870 -> 0x0049de00 requires public access. Its visual-state sequence is controlIndex/state 11, render, delay, then -1/state 10 before command dispatch.
- The method body remains owned by [UID:0003KN][0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState](by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md). This declaration-only visibility correction changes no class size, vtable, score, owner, or source body.
- The accepted support set contains 16 direct references; ObjectImage is one consumer and does not transfer method ownership.

## 2026-08-14 B003 Header Route Closure

- The formal CPP now includes `DialogPane.h` before `[[CHILDREN]]`; the H is guarded and directly includes complete `EPFTileContext` plus base `Pane`, with exact forwards for ControlPane, Event, Layer, and List.
- This preserves all existing DialogPane methods, storage, and child declarations while making `ChangePasswordDialogPane.h` independently compile-visible. UID00003T/UID0000IT remain the declaration/source owners at `93/96`.

## Status

- Confidence: very strong for class role, complete declaration, vtable ownership, exact Event-family overrides, primary paint/background/border route, control/list union, and file parent route.
- Likely source file: [UID:0000IT][DialogPane](by-file/DialogPane.md)
- Main address range: [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- Type docs: [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Exact vtable data: [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md)

## Complete Virtual Contract

- `OnPaint()` is the primary `+0x44` override at `0x0049f090`. It invokes primary `+0x50/+0x54` to draw the background and border before focus/selection painting.
- `HandleImeEvent(Event *)` is the secondary `+0x0c` override at `0x0049ea60`, between key/text and packet handling in the exact EventHandler order.
- `DrawBackground()` is the protected primary `+0x50` virtual at exact [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md).
- `DrawBorder()` is the protected primary `+0x54` virtual at exact [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md).
- These four declarations were the only missing source declarations required by the `DialogInSession` 23-slot primary and 11-slot secondary tables. Existing `OnControlCommand`, `UpdateActionButton`, and `SetHoverControl` ordering is preserved, so the class declaration regenerates `+0x48/+0x4c/+0x50/+0x54/+0x58` without artificial vtable source.
- `HandlePacketEvent(Event *)` remains inherited as the false default at `0x0041d6b0`; it is not a new DialogPane declaration in this bounded correction.
- Current recovered file: `source-3/simroot_v2/class_DialogPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000IT][DialogPane](by-file/DialogPane.md).
  The H channel now emits the complete declaration with
  `[[CHILDREN]]`; exact method bodies remain on exact by-memory pages such as
  [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md),
  [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md),
  [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md),
  and [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md).
  [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md)
  now carries formal method-body C++ for `GetControlCount() const`.
  [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md)
  carries the exact `SetHoverControl(int)` body.
  [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md),
  UID0004SW, and UID0004SX carry the exact background setup/draw bodies.
  [UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md)
  carries the exact `AddControl(ControlPane *)` body in the CPP channel.
  [UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md)
  carries the exact `ActivateFocusedControl()` body in the CPP channel, with nine live item-list `OnItemActivated` forwarding consumers and final DialogPane `OnControlCommand` dispatch.
  Remaining uncertainty is final original spelling for the generic control-list field,
  visual-state enum names, and unrelated helper signatures,
  not class ownership or source placement.

## Class Purpose

`DialogPane` is the base dialog class. It owns dialog title/config state, modal registration, control tracking, creation/destruction hooks, and saved-position behavior. Feature dialogs should derive from it or embed it rather than owning these common routines.

The accepted background source surface is now complete. `SetBackgroundResource(const wchar_t *, short)` builds an owned mask-only `EPFTileContext`; `DrawBackground()` selects current `DLGFRAME.EPF`/`PAL01.PAL`, legacy `DLGFRAME.EPD`/`NPAL8.PAL`, or the custom mask callback; `DrawBorder()` draws all eight frame parts in 14- or 16-pixel modes and suppresses chrome for custom masks. [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) carries package provenance, frame roles, the full PAL01 consumer inventory, and the source-literal/pooling boundary.

The UID0002Q4 LoginDialogPane dependency resolved the target-required input declarations at the historical `90/92` checkpoint. Current Event/EventHandler documentation and vtable families support `HandlePointerOrMouseEvent(Event *)`, `HandleKeyOrTextEvent(Event *)`, and virtual `UpdateActionButton()`, replacing stale `InputEvent`/`OnInputEvent`/`OnKeyInput` declaration spellings. Bounded decompile of `0x0049fb10` proves `char HitTestControls(int mouseY, int mouseX, int *outControlId)`: it walks controls, skips ignored hit testing, encodes disabled hits with the signed high bit, writes `-1` and returns `10` on miss. Exact function `0x0049fda0-0x0049fe12`, not `0x0049fc00`, temporarily translates an Event's pointer coordinates for one child, dispatches it, and restores them, supporting `DispatchInputToControl(Event *, int)`. Function `0x0049fa60` reads current bounds and updates configured dialog position. UID000312 proves the physical one-argument ABI `SavePosition(const RectBounds *unusedBounds)`: callers push a bounds pointer, the callee ends in `retn 4`, and this build intentionally ignores the supplied pointer while recomputing bounds.

[UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md) independently closes the neighboring helper contract. Its exact 76-byte body reads `m_activeControlId`, deactivates the old child, activates the incoming child, and stores the new id; it performs no Event-coordinate access. Primary `DialogPane` slot `+0x58` points to this body, Macro/Integrate inherit it, Spell/New forward to it, all four dialog constructors pass control id `2`, and the exact source method matches the preserved protected virtual declaration above. Primary `+0x48` remains the distinct two-argument `OnControlCommand` slot. These declarations add no new fields or duplicate bodies to the class page.

`StoreClampRect` has the exact accepted declaration `void StoreClampRect(const RectBounds *bounds)`. Fresh UID00040C dependency decompilation of `sub_49DAE0` confirms one pointer-sized explicit argument: the helper sets byte `this+0x229` and copies four dwords from the supplied rectangle into `this+0x22c..+0x238`. The prior four-int declaration was incompatible with both this ABI and BrowserDialog's direct `StoreClampRect(&dialogBounds)` call. [UID:0003KD][0x0049dae0-0x0049db14.DialogPaneStoreClampRect](by-memory/0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md) remains the exact body owner; this class page supplies only the corrected declaration.

The PopupMenuControlPane dependency resolves two additional public control surfaces. [UID:0003KJ][0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById](by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md) iterates the manager's four-byte ControlPane pointer entries and compares each stored pointer to the supplied `ControlPane *`; it does not read or compare a numeric control id. Its accepted declaration is public `int FindControlIndex(const ControlPane *control) const`. Public access is required because PopupMenuControlPane is not derived from DialogPane and calls this helper through a `DialogPane *`.

B004's UID00012T source-quality implementation resolves the underlying object as generic [UID:000079][List](by-class/List.md), not a source-distinct `DialogControlManager`. [UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md) allocates `0x14` bytes and constructs `List(4, 20)` at `+0x1fc`; accepted List slots are `GetElementAt +0x10`, `Append +0x18`, and `RemoveAt +0x1c`. The control helper surface therefore uses `AddControl(ControlPane *)`, protected `RemoveControl(ControlPane *)`, protected `RemoveControl(int controlIndex)`, public `FindControlIndex(const ControlPane *) const`, and `GetControlCount() const`. The retained `m_controlManager` spelling is a field-role alias whose type is `List *`.

The accepted UID0003KH source-quality pass closes the AddControl body and API rather than preserving an unsupported overload. Live prototype and stack evidence prove `void __thiscall(DialogPane *, ControlPane *)`; exactly 800 direct code xrefs span 88 modeled dialog construction/layout functions plus one unmodeled call site, and no caller supplies a category byte or second explicit argument. The method lazily evaluates `new List(sizeof(ControlPane *), 20)` when `m_controlManager` is null, then performs `Append(1, &control)`. The List owns the copied pointer slot and backing storage, while DialogPane retains ownership of each pointed-to `ControlPane` and drains/destroys those controls during cleanup. Allocation cleanup at `0x005fd4fe` and the security-cookie/frame-handler path at `0x005fd509` are compiler lowering of the ordinary new-expression, not source API.

Historical correction: the earlier `AddControl(unsigned char category, ControlPane *control)` declaration and source-distinct `DialogControlManager` theory were reasonable provisional interpretations before exact List and caller evidence was complete. Current function/name inventory finds only the one-pointer AddControl function; all 800 inbound xrefs are code calls, there are no data or indirect routes, and neither the method nor its callers supply/read category state. The obsolete category declaration is therefore removed, while the accepted one-pointer declaration remains exactly once.

The UID00010X dependency rebase preserves that finalized generic-List/removal content and adds only the protected child-access contract used by accepted collection-dialog source: `GetChildControl(int) const` plus inline `GetChild<T>(int) const`. The template is a source-era typed cast over the existing control-list access surface and does not add owned storage. `SetHoverControl(int)` is declared virtual because `CollectionDialogPane` overrides the primary vtable slot at `+0x58` with exact no-op body [UID:0004JH][0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp](by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md).

[UID:0003KI][0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer](by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md) now supplies the exact protected pointer-overload body. Source composes public `FindControlIndex(control)` with guarded protected `RemoveControl(controlIndex)`; the binary expands UID0003KJ's null/count/GetElementAt first-match lookup and UID00012T's one-element RemoveAt wrapper. Null manager, empty/no-match, and duplicate behavior therefore remain exact, and all ten MiniMap teardown call sites prove removal is non-owning because each caller destroys and clears its saved pointer afterward. The old `SelectControlById` basename and direct private List loop are retained only as historical/expanded evidence, not current source identity.

Primary DialogPane vtable slot `+0x48` accepts `(controlIndex, notifyCode)` and is source-facing `virtual void OnControlCommand(int controlIndex, int notifyCode)`. [UID:0004IT][0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex](by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md) sends code 10 after selection change; [UID:0004IS][0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw](by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md) independently sends code 12. FolderSelectDialog's override consumes code 10 as selected-text change, confirming the two-argument notification surface without proving a stronger semantic name for code 12.

## Observed State

IDA-confirmed offsets and generated-name hints are consolidated in [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md). Current known inherited state includes:

```text
0x000  Pane base
0x0f8  wchar_t m_title[128]
0x1f8  unsigned short m_dialogConfigId
0x1fc  List *m_controlManager // four-byte ControlPane * elements
0x200  int m_focusedControlId
0x204  int m_pendingControlId
0x208  unsigned char m_isTitleDragActive
0x209  unsigned char m_savedPaneMode
0x20c  int m_dragOriginY
0x210  int m_dragOriginX
0x214  int m_activeControlId
0x218  unsigned char m_pressedControlActive
0x21c  int m_pressedControlId
0x220  unsigned char m_pressedHitType
0x224  int m_selectedControlId
0x228  unsigned char m_selectionVisualState
0x229  unsigned char m_clampDragToBounds
0x22c  int m_dragClampMinX
0x230  int m_dragClampMinY
0x234  int m_dragClampMaxX
0x238  int m_dragClampMaxY
0x23c  EPFTileContext m_backgroundTileContext (through 0x263)
0x264  int m_backgroundImageWidth
0x268  bool m_hasCustomBackground
0x269..0x26b  natural tail padding
```

`List *` is exact for `+0x1fc`; `m_controlManager` remains an inferred role spelling rather than a distinct type. The exact 0x28-byte [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) occupies `+0x23c..+0x263`; UID0003KG copies its row stride, bounds, encoded-mask count, and owned encoded-mask pointer. UID0004SW/UID0004SX read that same context. Therefore the former overlapping `DialogBackgroundState` placeholder and separate `+0x240/+0x248/+0x24c/+0x25c/+0x260` member rows are superseded. The trailing int/bool names are best descriptive spellings; `+0x269..+0x26b` is natural alignment, not a raw member. Derived/browser tails such as `+0x26c`, `+0x278`, and `+0x27c` are not base `DialogPane` state.

B001's 2026-06-24 [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) pass resolved `GetControlCount() const` as a tiny source-authored leaf. B004 now closes its former type blocker: it reads `m_controlManager` at `this+0x1fc`, returns zero when the `List *` is null, and otherwise returns the List count through accepted inline `List::GetCount() const`, which regenerates the direct `+0x0c` load.

B015's ModelessDialogPane reanalysis historically described the inherited slots as `m_dragStartX/Y` and top/left/bottom/right bounds. UID000312 exact operands supersede those aliases: Y/X occupy `+0x20c/+0x210`, and minX/minY/maxX/maxY occupy `+0x22c/+0x230/+0x234/+0x238`. Broader canonical names `m_activeControlId` and `m_selectionVisualState` remain shared across keyboard and mouse consumers.

B008's ForcedInformMessageDialog incorporation accepts two source-facing control-helper aliases used by recovered dialog constructors: `AddControl(ControlPane *control)` is the one-argument form for default-category control insertion, and `SetHoverControl(int controlId)` names the inherited `+0x214` hover/active-control slot setter. These aliases do not move ownership away from the existing `DialogControlPaneHelpers` exact-child band; they only allow exact dialog children to avoid generated helper names.

## Generic Control Refresh Route

- `0x0049fe20-0x0049feae` is source-facing `DialogPane::RefreshActionButtonState()`. It snapshots the focused control's enabled state, dispatches virtual `UpdateActionButton()` through primary slot `+0x4c`, then invalidates the focused control's expanded bounds only when enabled state changed. It does not change focus and is not merely `RedrawSelectedControl`.
- `DialogPane::OnCreate` calls this wrapper at `0x0049e119`. For AddItemDialog construction, UID0004BM reaches `OnCreate` at `0x004ae8b5` after all controls and AddItem vtables exist, so UID0004BP runs synchronously even though the constructor has no direct call to `0x004aea40`.
- The wrapper has ten direct caller functions: `0x0049e119` inside OnCreate plus callers at `0x0049e240`, `0x0049e6e0`, `0x0049ea60`, `0x004a0840`, `0x004ad320`, `0x004ade60`, `0x004fae90`, `0x0059b0f0`, and `0x0059b110`. They span base input/focus/selection, modeless, exchange, login, and user-info paths.
- Only dynamic AddItem-family receivers whose slot points to `0x004aea40` reach [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md): AddItem `0x00619ed8`, AddEmployee `0x00619120`, and AddMixing `0x0061a170`. AddItemWithCount `0x0061a038` points to its distinct `0x004af480` override; other dialogs likewise use their own dynamic slots.
- The target method then uses this class's protected `GetChild<T>(int)` over exact `List *m_controlManager` to resolve zero-based insertion indexes `1` and `3`. This route adds no new DialogPane declaration or body and changes no class score.
- Historical wording that no direct constructor call means no constructor-time refresh is superseded. The no-direct-call fact remains valid; the synchronous virtual route is the complete current interpretation.

## UID000312 Declaration And Helper Closure

- The H channel now reflects the exact inherited storage order consumed by ModelessDialogPane: Y then X drag origins and minX/minY/maxX/maxY clamp values. The earlier opposite order remains documented in dated layout history as a superseded assumption.
- `SavePosition(const RectBounds *unusedBounds)` preserves the physical explicit argument even though this build does not read it. Converting it to a zero-argument method would mismatch every observed `retn 4` call.
- `RefreshActionButtonState()` is the highest-probability human source name for `0x0049fe20`. Historical `UpdateFocusedControl` and `RedrawSelectedControl` names incorrectly imply behavior the function does not perform.
- `SetSelectionVisualState` remains a child-owned exact body at [UID:0003KN][0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState](by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md). The class declares it once; this page does not duplicate its implementation.
- Original lexical spellings are stripped. These names are inference-backed source reconstruction, not claims of recovered symbols, and intentionally avoid raw offsets or analyzer labels.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Constructor/destructor | `0x0049d8a0`, `0x0049d9f0`, `0x0048c350-0x0048c38b` | Source declares `DialogPane` constructor and `virtual ~DialogPane()`; the ordinary cleanup body decrements the active-dialog byte, drains/destroys four-byte `ControlPane *` elements, tears down the generic `List *m_controlManager` and `m_tileContext`, while the scalar deleting destructor wrapper is compiler ABI glue. |
| vtable adjustor thunks | `0x0048c27b-0x0048c291` | Two IDA-confirmed 0xb-byte secondary/tertiary destructor thunks. |
| Control helper band | [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) | Non-emitting inventory of exact class-owned control helpers, now split into [UID:0003KD][0x0049dae0-0x0049db14.DialogPaneStoreClampRect](by-memory/0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md)-[UID:0003KP][0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl](by-memory/0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md) and [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md). UID0003KH emits exact protected `AddControl(ControlPane *)`; UID0003KI emits protected `RemoveControl(ControlPane *)` through factorized UID0003KJ/UID00012T semantics; UID0003KK emits exact `GetControlCount() const`. The DialogCategorySwitch child is separate control-state behavior and does not justify a category-bearing AddControl overload. |
| Lifecycle | `0x0049dfd0-0x0049e231` | Create, show, destroy, hide, modal registration. |
| Slide animation | `0x0049eac0-0x0049f081` | Shared `SlideOpenVertical`, `SlideCloseVertical`, `SlideOpenHorizontal`, `SlideCloseHorizontal`, retained raw `SlideShrink`, and retained raw `SlideExpand` helpers. [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) now carries the six method bodies; current Ranking/Clan generated owner labels are caller-provenance pollution. |
| Position/config/control handling | `0x0049e6e0-0x0049fead` | Dialog config layout, child-control dispatch, focus/hover/selection behavior, including generic refresh wrapper `0x0049fe20` and dynamic primary slot `+0x4c` dispatch. |
| Input surface and derived overrides | `0x0049e240`, `0x0049e6e0`; derived [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md), and [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) | `DialogPane` owns the inherited input/control dispatch and key/focus selection handlers. Browser/WebBoard HWND reposition and WebBoard key/request overrides are derived consumers, not base `DialogPane` methods. |

IDA `list_globals` confirms `DialogPane` vtable bases at `0x00618a64`, `0x00618ac4`, and `0x00618af4`. The tertiary table is short and ends before neighboring `AlertPane` RTTI.

2026-06-11 A003 live IDA MCP reconfirmed the exact vtable-data child now named [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md). A004 Batch 336 repaired the filename/header range to the `0x00618afc` exclusive boundary and split [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md) as the source-local type owner. `py_eval`/`get_int` evidence verified the primary RTTI locator at `0x00618a60`, vtable bases at `0x00618a64`/`0x00618ac4`/`0x00618af4`, constructor stores at `0x0049d8e0`/`0x0049d8e6`/`0x0049d8f0`, cleanup/destructor stores at `0x0049da17`/`0x0049da1d`/`0x0049da27`, and the `0x00618afc` `AlertPane` RTTI boundary. This plus [UID:0000IT][DialogPane](by-file/DialogPane.md) at `86/85` clears the strict `85/85` direct-parent gate for exact `DialogPane` vtable children.

Compiler ABI support stays non-handwritten: do not emit scalar-deleting destructor flags, secondary/tertiary adjustor thunk bodies, literal vtable dwords, or explicit destructor vtable restores. Those are regenerated from the declaration, virtual method set, member layout, and base-class destruction.

## Cross-References

- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Score Rationale

- Completion is `93` because the complete declaration now resides in the H channel, contains exactly one supported `AddControl(ControlPane *)` declaration and one `[[CHILDREN]]` marker, and routes the exact UID0003KH out-of-line body through the CPP child without duplicating it. All prior control, list, animation, layout, child, and compiler-boundary facts remain intact.
- Confidence is `96` because exact vtable cells, bounded method bodies, UID0003KH's typed ABI and all-800-caller inventory, generic List construction/Append/destruction semantics, and the DialogPane source route jointly reject the category overload and custom manager. Remaining uncertainty is limited to unrelated helper/visual-state lexical spellings and lack of original PDB/source identifiers.

## Changes

- 2026-08-23 B005 UID0003KO accepted support callback:
  - Preserved `93/96`, owner/emitter UID0000IT, reconstructable true, blank position, complete H/CPP formal, layout, vtable contract, and all unrelated source/history.
  - Added UID0003KO to the source-ready child inventory with exact focused-id/enable gating, state-11 pulse, two renders, `Sleep(0x85)`, neutral reset, terminal DialogPane `OnControlCommand`, exact range/padding/shared-tail caveat, and nine live forwarding families.
  - Verified the existing protected `void ActivateFocusedControl();` declaration remains exactly once; no class code or declaration was duplicated.

- 2026-07-28 B004 UID0003KH accepted implementation callback:
  - Raised `92/94 -> 93/96`, preserved owner/emitter UID0000IT, reconstructable true, blank position, every unrelated method/member/history line, and moved the complete declaration from CPP to H.
  - Removed only the unsupported category AddControl declaration, retained exactly one `void AddControl(ControlPane *control);` and one `[[CHILDREN]]`, and kept class CPP blank so the exact UID0003KH child owns the body.
  - Added exact one-pointer ABI, `List(sizeof(ControlPane *), 20)`, `Append(1, &control)`, List-slot versus pointed-to-control ownership, 800 direct caller/zero indirect-data route, compiler-lowering boundary, source placement, and historical category/custom-manager rejection.

- 2026-07-16 B003 UID0003AX accepted implementation:
  - Retained `92/94`, owner/emitter UID0000IT, reconstructable true, blank position, all unrelated declarations, and class closure before `[[CHILDREN]]`.
  - Applied exact R7 by replacing `m_tileContext` plus overlapping `DialogBackgroundState` with `EPFTileContext m_backgroundTileContext`, `int m_backgroundImageWidth`, and `bool m_hasCustomBackground`.
  - Linked exact UID0003KG/UID0004SW/UID0004SX bodies, frame/palette package roles, Browser fallback, and natural `+0x269..+0x26b` tail padding.
  - Preserved complete lifecycle/input/control/list/animation/compiler/vtable history and public/protected access.

- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed completion `91 -> 92` with confidence `94` unchanged; preserved owner/emitter UID0000IT, reconstructable true, blank position, complete control/list/animation/layout union, and every unrelated current declaration.
  - Added only `virtual void OnPaint()`, `virtual bool HandleImeEvent(Event *)`, protected `virtual void DrawBackground()`, and protected `virtual void DrawBorder()` to the managed formal.
  - Added exact `+0x44/+0x0c/+0x50/+0x54` body/table evidence and preserved OnControlCommand/UpdateActionButton/SetHoverControl order so derived DialogInSession vtables regenerate without handwritten ABI data.

- 2026-07-15 B003 UID00049G implementation callback: raised `90/92` to `91/94`; preserved owner/emitter UID0000IT, true, blank position, the complete R19 managed declaration, layout, public/protected access, `[[CHILDREN]]`, and all unrelated history. Linked exact UID0004RI and its inherited/overridden `+0x58` evidence, corrected stale coordinate-dispatch prose from `0x0049fc00` to `0x0049fda0`, and preserved the separate `+0x48` `OnControlCommand` contract.

- 2026-07-14 B004 UID000470 bounded support implementation:
  - Preserved `90/92`, owner/emitter UID0000IT, the complete finalized class block, every public/protected helper, field, `[[CHILDREN]]`, child ownership, and unrelated implementation history.
  - Changed only `SetBackgroundResource(const wchar_t *resourceName, const wchar_t *paletteName)` to `SetBackgroundResource(const wchar_t *resourceName, short frameIndex)`. Live constructor call `0x0049db60` receives `(L"US", 0)`, directly proving the second argument is a numeric frame selector rather than a palette string.
  - No body, score, ownership, layout, control-container, or unrelated declaration change was made.

- 2026-07-14 B005 UID0002Q4 support implementation: preserved `90/92`, owner/emitter UID0000IT, all prior B002/B003/B004/B005/B011 declarations, exact fields, helper evidence, `[[CHILDREN]]`, and unrelated history. Replaced only stale formal `OnInputEvent(InputEvent *)`/`OnKeyInput(InputEvent *)` with current `HandlePointerOrMouseEvent(Event *)`/`HandleKeyOrTextEvent(Event *)`, added virtual `UpdateActionButton()`, and added protected `HitTestControls(y,x,out-id)`, `DispatchInputToControl(Event *,int)`, and `SavePosition()`. Resumed bounded evidence proves signed-char disabled-hit encoding/miss 10, temporary child coordinate translation/restoration, and configured-position storage; LoginDialogPane UID0004PS/UID0004PT are exact derived consumers. No score, owner, emitter, field, or unrelated C++ change was made.

- 2026-07-13 B002 made-by scrolled-text access synchronization:
  - Score, owner/emitter, declaration contents, fields, methods, and children remain otherwise unchanged.
  - Moved the existing `CloseDialog()` declaration from protected to public exactly once. [UID:0004MC][0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent](by-memory/0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent.md) is an unrelated `ControlPane`-derived caller through `g_pNewHistoryDialog`, so protected access is compile-incompatible and no friendship is evidenced.
  - Evidence: accepted UID00019X report C20-C21/Destination 8, singleton read at `0x004ff6eb`, and direct close call order in the exact timer CFG.

- 2026-07-13 B005 UID0004BP support sync: preserved `90/92`, the complete managed class declaration, every accepted helper/field, and source route; added exact `0x0049fe20` dynamic `+0x4c` behavior, all ten caller functions, constructor `OnCreate` reachability, AddItem-family routes, AddItemWithCount override exclusion, and the historical direct-call-versus-synchronous-refresh distinction. No C++ change.

- 2026-07-13 B004 UID00010X direct-dependency callback: preserved `90/92`, owner/emitter/reconstructable state, complete managed block, finalized B005 public `OnControlCommand`/`FindControlIndex`, generic `List *` field, both accepted removal overloads, fields, and all unrelated methods.
  - Accepted additions only: protected `ControlPane *GetChildControl(int) const`, inline `GetChild<T>(int) const`, and `virtual` on `SetHoverControl(int)`.
  - Evidence: collection-dialog constructors repeatedly use typed child retrieval; [UID:0004JH][0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp](by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md) occupies the inherited `+0x58` slot. No raw List expression, new owned container, score change, or unrelated C++ inflation was introduced.

- 2026-07-12 B003 UID0003KI support implementation:
  - Raised `89/91 -> 90/92`; preserved owner/emitter UID0000IT, reconstructable true, the complete class declaration, and all unrelated B005/B011 content.
  - Added renamed UID0003KI as exact protected source-ready `RemoveControl(ControlPane *)`, its factorization through public UID0003KJ and protected UID00012T, first-match/null/duplicate semantics, and ten-caller non-owning teardown proof.

- 2026-07-12 B004 UID00012T support implementation:
  - Preserved finalized B005 command `000000008656` metadata `89/91`, public `OnControlCommand(int controlIndex, int notifyCode)`, public `FindControlIndex(const ControlPane *control) const`, every unrelated declaration/field, and `[[CHILDREN]]` placement.
  - Replaced stale protected `SelectControlById` / `SwitchControlCategory` declarations with protected pointer/index `RemoveControl` overloads and changed only the `+0x1fc` concrete type from placeholder `DialogControlManager *` to exact `List *`.
  - Added exact `List(4, 20)`, four-byte `ControlPane *`, `GetElementAt`/`Append`/`RemoveAt`, UID00012T index/count/void-return, destructor drain, and inline count-accessor evidence without changing the class score or source route.

- 2026-07-12 B005 UID00011F DialogPane support implementation:
  - Raised `88/89` to `89/91` and applied the accepted complete managed class block without removing prior declarations, fields, `StoreClampRect(const RectBounds *)`, or `[[CHILDREN]]` placement.
  - Added public `OnControlCommand(int controlIndex, int notifyCode)` and public `FindControlIndex(const ControlPane *control) const`; removed the contradicted protected `FindControlIndexById(int)` declaration.
  - Evidence: UID0003KJ compares stored ControlPane pointers, PopupMenuControlPane is a non-derived caller, popup code-10/code-12 paths use the two-argument parent slot, and FolderSelectDialog consumes code 10. Numeric-id lookup and protected accessibility are retained only as superseded assumptions.

- 2026-07-12 B005 UID00040C dependency-signature implementation callback:
  - Score, owner/emitter, reconstructable state, and every other formal declaration/field remain unchanged at `88/89`.
  - Changed only `StoreClampRect(int minY, int minX, int maxY, int maxX)` to `StoreClampRect(const RectBounds *bounds)` in the complete managed class block.
  - Added one-pointer ABI and four-dword copy evidence from `sub_49DAE0`, preserved exact body ownership in UID0003KD, and removed this resolved signature from the class's generic uncertainty wording.

- 2026-06-06 parent attachment sync:
  - What existed before: the class page was `82/84` and reconstructable but had
    no parent, while the exact memory aggregate [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
    pointed to this class as its parent.
  - What it was changed to: attached the class to [UID:0000IT][DialogPane](by-file/DialogPane.md)
    at position `10`, keeping C++ blank under the final-source gate.
  - Summary/evidence: [UID:0000IT][DialogPane](by-file/DialogPane.md) is an
    `86/80` file root projected to `NexusTK/ui/core/`, and the class page
    already passes the 80/80 child-side gate.
- 2026-05-27: The input-override row previously listed `0x0046d3b0` as an unresolved DialogPane/derived split. Changed it to point to the `WebBoardDialog` virtual-companion memory page because IDA vtable slot `0x00613654` points to `0x0046d3b0` inside the `WebBoardDialog` vtable family, and the body manipulates embedded browser-control state.
- 2026-05-27: The input-override row also previously kept `0x0046d4b0` in the unresolved DialogPane/derived split. Changed it to point to the `WebBoardDialog` input/request helper page because IDA vtable slot `0x00613658` points to `0x0046d4b0` in the same `WebBoardDialog` vtable family.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/84`.
  - Summary/evidence: base dialog role, major layout offsets, constructor/destructor/lifecycle/animation/control/input families, vtable bases, and corrected derived input-owner split are documented; remaining uncertainty is mostly provisional field naming after `0x208` and final source-facing helper names.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the constructor/lifecycle/control method anchors and vtable stores for the common base dialog class. Parent/code autogen remains blank because the final C++ shape is not at the required near-final threshold.
- 2026-06-11 A003 Batch 209 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`; the exact `DialogPane` vtable child could not attach directly because the class page did not clear `85/85`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP reconfirmed the exact [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md) child, constructor/destructor vtable-store xrefs, the `AlertPane` boundary, and the existing [UID:0000IT][DialogPane](by-file/DialogPane.md) `86/85` file parent. Remaining helper/field final-name caveats keep the class below higher scores.
- 2026-06-12 Agent-A001 Goal 2:
  - Kept score `85/86`.
  - Recorded direct ownership of the [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) exact-child split. The class parent already clears the strict gate, so exact helper children now route here rather than bypassing to the file parent.
- 2026-06-19 B011 source-quality pass:
  - Changed score from `85/86` to `88/89` and populated declaration-only first-draft C++.
  - Summary/evidence: B011 resolved class declaration readiness under [UID:0000IT][DialogPane](by-file/DialogPane.md), direct control-helper child ownership, source-facing field-name directions for control-manager/focus/pending/active/drag/selection/clamp/tile/background state, Browser/WebBoard derived input override exclusions, DialogPane slide helper ownership, ordinary destructor versus compiler scalar-deleting/adjustor glue policy, and three-view vtable declaration handling. Method bodies remain on exact by-memory pages until helper signatures and support types are normalized.
- 2026-06-22 B015 ModelessDialogPane support sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: recorded ModelessDialogPane-specific role aliases for inherited drag/hover/pressed/selection/clamp slots without changing the shared declaration. This preserves B015's source-quality field inferences while keeping the B011 broader `DialogPane` names that are supported by keyboard/control paths.
- 2026-06-24 B001 accepted implementation:
  - Score unchanged at `88/89`.
  - Historical summary/evidence: synchronized [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) with the class declaration and established null-zero/direct-`+0x0c` behavior. Its provisional `DialogControlManager` type wording is superseded by B004's exact generic List proof; the no-incoming-route evidence remains valid.
- 2026-06-28 B008 ForcedInformMessageDialog support sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: added declaration aliases for default-category `AddControl(ControlPane *control)` and `SetHoverControl(int controlId)` so accepted exact dialog children can use source-facing helper names while the helper bodies remain owned by [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md).
- 2026-06-28 B008 DialogPane slide-animation implementation:
  - Score unchanged at `88/89`; this class page remains declaration-only with `[[CHILDREN]]`.
  - Summary/evidence: synchronized accepted [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) implementation. The slide child now carries six formal method bodies after MCP session `supervisor_20260628_resume` verified the corrected `0x0049f081` exclusive end, the four modeled helper sizes, the raw `SlideShrink`/`SlideExpand` no-xref caveat, and the `0x0049f07e` `retn 4` bytes. Helper spellings such as `CanRunSlideAnimation`, `OffsetPresentationRegion`, and `RenderPresentation` remain first-draft support-name decisions on the exact child.
## FolderSelectDialog Shared RTTI Dependencies R08/R14

These are existing DialogPane-owned compiler RTTI records reached from the FolderSelectDialog seven-base array. They are dependency edges only and add no FolderSelectDialog source or DialogPane formal-source change.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R08 | `0x640790-0x6407ac` BCD, `??_R1A@?0A@EA@DialogPane@@8`: TD `0x673a70`, contained `5`, PMD `0/-1/0`, attrs `0x40`, CHD `0x6407ac` | `xref_query.total=118`; FolderSelectDialog graph edge `0x647834`; outgoing TD `0x673a70` and CHD `0x6407ac` | DialogPane-owned compiler RTTI; FolderSelectDialog only references it. |
| R14 | `0x673a70-0x673a8c` TypeDescriptor `??_R0?AVDialogPane@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVDialogPane@@` | `xref_query.total=4`, including BCD edge `0x640790`; outgoing vfptr `0x635078` | DialogPane-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
