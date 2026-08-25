*** UID:00006D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ImageButtonControlPane : public ButtonControlPane
{
public:
    ImageButtonControlPane(int imageId, const RectBounds *bounds);
    virtual void SetVisualState(unsigned char visualState);
    virtual void Enable();
    virtual void Disable();

protected:
    virtual void OnPaint();

private:
    int m_imageId;
    int m_imageState;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ImageButtonControlPane

## 2026-08-14 B003 Combined Header Closure

- The class declaration moved from CPP into the combined ButtonControlPane H channel. It now includes the constructor, `SetVisualState`, Enable, Disable, protected OnPaint, and exact two-int storage; CPP remains the child-emission marker only.
- This declaration closes ChangePasswordDialogPane's construction and action-button calls while retaining all body children and compiler destructor/thunk dispositions. UID00006D advances from `89/92` to `92/94`.

## Status

- Confidence: strong.
- Direct source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_ImageButtonControlPane.cpp`

## Class Purpose

`ImageButtonControlPane` is the generic EPF image-button control derived from ButtonControlPane. It constructs over an image id and pane definition, tracks image/press state, overrides inherited Enable/Disable to select normal/disabled image states, and paints an EPF sprite frame based on state and skin mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ImageButtonControlPane` | `0x00495bf0-0x00495ca5` | Constructs the image button and installs the three ImageButton vtable views. |
| `SetState` | `0x00495cd0-0x00495d0b` | Changes image-button state and invalidates/refreshes through the control vtable. |
| `Enable` | `0x00495d10-0x00495d76` | Inherited slot `+0x4c`; when disabled, selects normal image state 0 and performs the base enabled-state transition/refresh. |
| `Disable` | `0x00495d80-0x00495de6` | Inherited slot `+0x50`; when enabled, selects disabled image state 2 and performs the base disabled-state transition/refresh. |
| `OnPaint` | `0x00495df0-0x00495f6c` | Selects EPF image frames and draws the current state through the image/surface helpers. |
| Destructor/thunks | `0x0049af69-0x0049af7f`, `0x0049b290-0x0049b2e5` | Compiler adjustor thunks and scalar deleting destructor wrapper. |

## Evidence Notes

- 2026-06-07 IDA MCP enumerates the six modeled ImageButton method bodies in `0x00495bf0-0x00495f70` at starts `0x00495bf0`, `0x00495cb0`, `0x00495cd0`, `0x00495d10`, `0x00495d80`, and `0x00495df0`. The `0x00495cb0-0x00495cc9` body is the adjacent [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md), not an ImageButton method.
- The constructor currently has 306 direct code xrefs from 74 unique caller functions, confirming this as a reusable generic UI control rather than a feature-dialog local helper.
- Fresh current MCP decompilation resolves the constructor's two explicit arguments as `(int imageId, const RectBounds *bounds)`: it forwards `bounds` to the base control constructor and stores `imageId` at object offset `+0x10c`. This declaration is now formal support for exact callers including [UID:0004I7][0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor](by-memory/0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor.md).
- The primary ImageButton RTTI/vtable cells are `0x00617dc8 -> ??_R4ImageButtonControlPane@@6B@` and `0x00617dcc -> 0x0049b290`. Secondary vtable cells `0x00617e34 -> 0x0049af69` and `0x00617e64 -> 0x0049af74` route through the adjustor thunks.
- IDA xrefs show the constructor writes vtable cells at `0x00495c6f`, `0x00495c75`, and `0x00495c7f`; the scalar deleting destructor resets the same cells at `0x0049b296`, `0x0049b29c`, and `0x0049b2a6`.
- Virtual slot data references bind `OnPaint` to `0x00617e10`, `SetState` to `0x00617e14`, `Enable` to `0x00617e18`, and `Disable` to `0x00617e1c`. The latter two override inherited primary slots `+0x4c/+0x50` and inspect inherited `m_enabled` at `+0x101`; historical mouse-enter/leave labels are rejected because neither body consumes an event.
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) obtains the selector-1 ImageButton and tail-dispatches these overrides according to the ListPane selection count. This is an enablement contract, not hover handling.
- `OnPaint` calls the image/surface helper family at `0x00457a60`, `0x004d02f0`, `0x004b9980`, and `0x004b9660`, consistent with EPF image-frame drawing rather than text or checkbox rendering.

## Assignment Gate

The class routes through [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). The target-required source surface is complete as a ButtonControlPane-derived declaration with constructor and virtual Enable/Disable overrides. Constructor, SetState, OnPaint, destructor-wrapper routing, broad constructor fanout, and unresolved non-target field spellings remain preserved in their existing inventories; this callback does not invent additional bodies or fields.

## 2026-06-30 B010 Empty-Emitter Route Decision

The formal block now emits a route comment plus `[[CHILDREN]]` so exact constructor/method/destructor children can surface through this class while the full declaration remains withheld. Current MCP evidence used by the accepted report includes `sub_495BF0` size `0xb5` for the constructor family and `sub_49B290` size `0x55` for the scalar deleting destructor wrapper. The wrapper is handled by [UID:0002XZ][0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md) as generated ABI code, not as a hand-authored class body.

Score moves from `85/88` to `87/89` because the page now has a formal route marker and wrapper disposition. Owner, emitter, reconstructable state, and source-file parent remain unchanged.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)

## Changes

- 2026-07-13 B005 UID0004BP source-quality callback:
  - Raised `87/89 -> 89/92` while preserving owner, emitter, route, constructor, SetState, OnPaint, destructor/compiler evidence, broad fanout, and unresolved non-target field-name caveats.
  - Replaced the incomplete class shell with the accepted target-required ButtonControlPane-derived declaration and exact virtual Enable/Disable declarations.
  - Corrected `0x00495d10/0x00495d80` from stale OnMouseEnter/OnMouseLeave labels to inherited slots `+0x4c/+0x50`, documented normal/disabled image states and inherited `m_enabled`, and linked the AddItemDialog target consumer.

- 2026-07-12 B002 UID0001ZG constructor dependency sync:
  - Before: the formal block withheld the constructor declaration and described its signature as unresolved.
  - Changed to: added `ImageButtonControlPane(int imageId, const RectBounds *bounds)` without changing score, owner, emitter, or route.
  - Evidence: fresh MCP decompilation of `0x00495bf0` proves argument order, bounds forwarding, image-id storage at `+0x10c`, and generic reuse across 306 direct code xrefs; UID0004I7 consumes the exact declaration.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed image-button methods at `0x00495bf0`, `0x00495cd0`, `0x00495d10`, `0x00495df0`, adjustor thunks at `0x0049af69`/`0x0049af74`, and the deleting-destructor wrapper containing `0x0049b2a0`. Left `AUTOGEN_PARENT_UID` blank because both this class and likely parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) are below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: generic EPF image-button role, constructor/state/mouse/paint/destructor method inventory, broad reuse evidence, and source-module placement are documented with strong confidence; remaining work is detailed field layout and final C++ reconstruction. Evidence: `ButtonChoiceControlCore`, `ButtonControlPane`, Wave3 method-grade summary, and IDA constructor xref count.
- 2026-06-07 Agent-A002 Batch 091 parent-gate pass:
  - Before: `74/86`, reconstructable but unassigned, with stale method endpoints and no written vtable-slot assignment evidence.
  - Changed to: `85/88` and `AUTOGEN_PARENT_UID:0000HY`.
  - Summary/evidence: live IDA MCP rechecked exact method endpoints, confirmed 306 direct constructor code xrefs from 74 unique caller functions, mapped primary/secondary vtable cells at `0x00617dcc`, `0x00617e34`, and `0x00617e64`, separated the adjacent `SelectionControlPane` helper, and verified direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) already clears `86/88`.
