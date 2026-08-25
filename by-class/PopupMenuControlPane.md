*** UID:0000AN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:21 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/ControlPane.h"

struct PaneMouseEvent;
struct PaneKeyEvent;
struct RectBounds;
class DialogPane;
class MenuItem;
class MenuPane;

class PopupMenuControlPane : public ControlPane
{
public:
    PopupMenuControlPane(DialogPane *parentDialog, const RectBounds *bounds);
    virtual ~PopupMenuControlPane();

    void AppendItem(MenuItem *item);
    MenuItem *GetItem(int index) const;
    int GetItemCount() const;
    long GetSelectedIndex() const;
    void SetSelectedIndex(long index);

protected:
    virtual void OnDraw();
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual int GetControlType();

private:
    void SelectItemAndNotifyParent(long index);

    MenuPane *m_menuPane;
    long m_selectedIndex;
    DialogPane *m_parentDialog;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PopupMenuControlPane

## Status

- Confidence: very strong for class role, exact child boundaries, three-view vtables, complete tail layout, owned-menu/callback lifetime, public API fanout, draw/input flow, and ordinary/scalar destructor separation.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md), with exact non-contiguous destructor/type-id children.
- Autogen parent: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). The accepted declaration and eleven exact method children replace the former empty class marker.

## Class Purpose

`PopupMenuControlPane` is a `ControlPane`-derived selector that owns a separately allocated `MenuPane`, draws the `POPUPMNU.EPF` selector frame and current item text, and opens the owned menu from mouse or translated-key input. It keeps the owning `DialogPane *` needed by `MenuPane::Show`; MenuPane owns the callback and items, while PopupMenuControlPane owns MenuPane.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0004IM][0x00498040-0x0049812b.PopupMenuControlPaneConstructor](by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md) | `PopupMenuControlPane(DialogPane *, const RectBounds *)` | Constructs base, callback, owned MenuPane, selected sentinel, and parent-dialog state. |
| [UID:0004IN][0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw](by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md) | `virtual ~PopupMenuControlPane()` | Raw ordinary destructor; deletes owned MenuPane and chains to base cleanup. |
| [UID:0004IO][0x00498170-0x0049817f.PopupMenuControlPaneAppendItem](by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md) | `AppendItem(MenuItem *)` | Public append-and-relayout forwarder. |
| [UID:0004IP][0x00498180-0x0049818f.PopupMenuControlPaneGetItem](by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md) | `GetItem(int) const` | Indexed MenuItem accessor. |
| [UID:0004IQ][0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount](by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md) | `GetItemCount() const` | Owned menu item count. |
| [UID:0004IR][0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex](by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md) | `GetSelectedIndex() const` | Returns `m_selectedIndex`. |
| [UID:0004IS][0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw](by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md) | `SelectItemAndNotifyParent(long)` | Retained private method, currently modeled at exact size `0x6f`: source-level setter call matching the optimized code-10 path, then independent literal notification 12. |
| [UID:0004IT][0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex](by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md) | `SetSelectedIndex(long)` | Active callback target and code-10 parent notifier. |
| [UID:0004IU][0x00498270-0x004984bc.PopupMenuControlPaneOnDraw](by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md) | `OnDraw()` | Draws exact resources and selected text; dispatches `MenuItem::GetText` through slot `+0x10` at `0x00498414` into a caller-owned `wchar_t[256]`, passes count `0x100`, ignores status, and draws the destination. |
| [UID:0004IV][0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent](by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md) | `OnMouseEvent(const PaneMouseEvent *)` | Event-kind-3 hit path opens MenuPane; always false. |
| [UID:0004IW][0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown](by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md) | `OnKeyDown(const PaneKeyEvent *)` | Key-down/translated-`0x83` path opens MenuPane. |
| [UID:0002Y9][0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks](by-memory/0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks.md) | Compiler deleting-destructor adjustor pair | Exact `this-0xa0` and `this-0xa4` secondary/tertiary vtable thunks; compiler-only and non-emitting. |
| [UID:0002YA][0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor](by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md) | Compiler complete-object deleting wrapper | Restores all three vptr views, performs destructor lowering, and dispatches hidden flags; semantic class evidence, not a second authored destructor body. |
| [UID:0003LM][0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId](by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md) | `GetControlType()` | Source-authored virtual returning control type `12`. |

## Inheritance, Vtables, And Layout

PopupMenuControlPane derives from ControlPane. MCP evidence collected during session `bf5519ae` and the later CB62 source-quality pass confirms primary vtable base `0x00617fb8`, secondary `0x00618020`, and tertiary `0x00618050`, installed at complete-object offsets `0`, `0xa0`, and `0xa4`. Draw is primary cell `0x00617ffc`, type id is primary cell `0x00618018`, and mouse/key are secondary cells `0x00618024`/`0x00618028`. UID0002Y9's exact `-0xa0`/`-0xa4` adjustors and UID0002YA's complete-object deleting wrapper are `RECONSTRUCTABLE:FALSE`, non-emitting compiler products regenerated from this declaration and UID0004IN's ordinary destructor definition.

The complete object is `0x114` bytes:

| Offset | Field | Evidence |
| --- | --- | --- |
| `+0x108` | `MenuPane *m_menuPane` | Constructor allocation/store; all forwarders/draw/input; ordinary/scalar destruction. |
| `+0x10c` | `long m_selectedIndex` | Constructor `-1`; getter/setter/draw/show flow; callback type. |
| `+0x110` | `DialogPane *m_parentDialog` | Ten constructor call shapes; mouse/key `MenuPane::Show` argument. |

The old `menuType` field claim is rejected: ten call sites pass the surrounding dialog `this` as argument one and stack bounds as argument two. The old `int *parentBlock` spelling was also decompiler-shaped and is superseded by `const RectBounds *`.

## Evidence Notes

- Function sizes in the compact run are `0xeb`, `0x0f`, `0x0f`, `0x0b`, `0x07`, `0x4d`, `0x24c`, `0x5a`, and `0x79`; the ordinary destructor and retained code-12 method were discovered as exact raw bodies of `0x35` and `0x6f` bytes. Current IDA now models both exact ranges. [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md) indexes every source body and exact `0xcc` fence.
- Direct fanout is constructor 10, AppendItem 54, GetItem 11, GetItemCount 12, GetSelectedIndex 17, and SetSelectedIndex 16 code refs plus constructor data binding. Draw/mouse/key/type are vtable-routed as expected.
- The constructor creates `PlainMemberFunctionObject<void (PopupMenuControlPane::*)(long), PopupMenuControlPane, long>` with target `0x00498220`, zero this-adjustment, and popup receiver. [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) owns the folded invoke wrapper; it is not handwritten here.
- `SetSelectedIndex` rejects `-1`/no-change, stores the selection, invalidates bounds, finds this control in DialogPane, and sends code 10. FolderSelectDialog consumes code 10 as selected-text change. UID0004IS source-level calls the setter; the optimized bytes inline its complete update/code-10 path, then use the parent cached before that call for a separate control-index lookup and literal notification 12. MusicControl ignores `notifyCode`, and the checked TerminalSetup/UserInfo handlers also leave their notification parameter unused, so close/commit/accept/dismiss names remain unsupported.
- `OnDraw` uses exact UTF-16 `POPUPMNU.EPF` frames 0/1/2 and `NPAL8.PAL`, selected item text, color `0x25`, disabled mode/color `2/0x8f`, and active mode/color `0/0x80`. At `0x004983ff` it obtains the selected `MenuItem *`; `0x00498404` pushes `0x100`; `0x00498409` addresses local `text`; and `0x00498414` calls `[edx+0x10]`. The physical local spans `+0x90..+0x28f`, proving `wchar_t[256]`. For `StringMenuItem`, cell `0x0061ebc4` resolves that slot to UID0002J9 `GetText`. EAX is not consumed before text drawing, so status-independent drawing is intentional and does not change the callee's `errno_t` contract. Mouse event kind 3 and key kind 8/translated `0x83`/state zero use identical right-edge Show geometry.
- MenuPane owns the callback and all appended items. PopupMenuControlPane owns only MenuPane; ordinary destructor UID0004IN deletes it, while UID0002YA adds compiler hidden-flag dispatch between no free, normal global delete, and the exact-size `0x114` no-op path. UID0002Y9 supplies only the two adjusted vtable entries.
- Current CB62 IDA models UID0004IN as `PopupMenuControlPane_destructor` with `void __thiscall(PopupMenuControlPane *this)`, but it still has no incoming xref. A later bounded current pass models UID0004IS as `PopupMenuControlPane_SelectItemAndNotifyParent`, exact size `0x6f`; it still has zero incoming code/data xrefs, zero VA/RVA pointer hits, no vtable/data slot, and no callback binding. Historical evidence that UID0004IS was raw/unmodeled remains discovery provenance. Unique signatures, class-local fields/calls, exact fences, deleting-wrapper parity, and duplicated setter flow prove source authorship; no-route remains a liveness/name confidence cap rather than a reason to emit compiler wrappers.

## UID0004IS Dedicated Recheck

- The exact `[0x004981b0,0x0049821f)` method is 111 bytes, 49 instructions, and seven coherent blocks, with SHA256 `6DC833EECFD6DDF74E589850D46D0ADA9D992DAD5588742A3C67CC219C3255C7`. Nine predecessor and one successor `0xcc` bytes fence it from the adjacent getter and setter.
- Its ECX receiver, `retn 4`, one four-byte index argument, `m_selectedIndex +0x10c` write, inherited bounds invalidation, and DialogPane calls support inferred private source signature `void SelectItemAndNotifyParent(long index)`. IDA's current `int index` is ABI-equivalent on this 32-bit build.
- Source caches the original parent before calling `SetSelectedIndex(index)`. The executable inlines the setter's conditional state update and code-10 notification, then uses the original cached parent for the independent code-12 lookup. The final lookup deliberately has no added null guard.
- The class declaration now resides in the formal H channel with `#include "../core/ControlPane.h"`; the formal CPP channel contains only `[[CHILDREN]]`. Definitions remain owned by exact child pages, so the generated source keeps one namespace-scope UID0004IS definition while the generated header carries the declaration.

## Ownership, Placement, And Rejected Alternatives

The class is the direct owner because vtables, tail fields, callback binding, allocation size, public callers, parent notifications, and destructor lifetime all converge here. MenuPane, DialogPane, ControlPane, FunctionObjects, EventMan, ResourceLayout, GrafPort, and Surface are support dependencies. Caller-feature ownership, direct file emission bypassing the class, MenuPane ownership of popup forwarders, no-owner raw children, and a new file only for raw islands are rejected.

The accepted source root remains [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) `NexusTK/ui/menu/PopupMenuControls.cpp`. A possible original `PopupMenuControlPane.cpp` split remains only a physical-file confidence cap; current class/file grouping is coherent and no stronger evidence supports moving it.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md)
- [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md)
- [UID:0003LM][0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId](by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md)

## Score Rationale

- Completion `90` reflects the complete class declaration, eleven exact compact children, type-id body, exact fields/layout, callback/lifetime model, caller/resource/input behavior, source route, and formal source. Remaining uncertainty is documented rather than left as a blank-C++ blocker.
- Confidence `92` reflects mutually reinforcing constructor, allocation, vtable, field, callback, caller, consumer, resource, raw-body, and destructor evidence. Exact original private/event spellings, raw active route, shared ResourceLayout public type, and physical file split keep the class below final-audit scoring.

## Changes

- 2026-08-11 B010 UID0002J9 support synchronization:
  - Preserved `90/92`, UID0000MN ownership/emission, position `21`, the complete formal declaration, all eleven authored method routes, layout, callback/lifetime, and historical evidence.
  - Expanded the OnDraw method/evidence rows with the literal slot `+0x10` call, `0x100` count, 256-wide local, UID0002J9/StringMenuItem resolution, ignored status, and caller-owned-buffer contract.
- 2026-08-10 B002 accepted UID0004IS implementation callback:
  - Preserved `90/92`, UID0000MN ownership/emission, the complete `0x114` layout, all method routes, and every historical source-shape conclusion.
  - Replaced stale current raw wording for UID0004IS with the exact current modeled/no-route state and added the source-level setter/code-10 versus independent literal code-12 consumer analysis.
  - Moved the complete `PopupMenuControlPane` declaration from the formal CPP channel to the formal H channel, added `../core/ControlPane.h`, and left only `[[CHILDREN]]` in formal CPP so declarations and qualified definitions reach the correct generated files.

- 2026-07-24 B005 UID0002YA-family accepted implementation callback:
  - Preserved `90/92`, the complete `0x114` declaration/layout, virtual destructor declaration, eleven authored method routes, and PopupMenuControls source parent.
  - Replaced the ambiguous second-destructor/thunk rows with linked UID0002Y9 compiler adjustors and UID0002YA compiler complete-object deleting support; both are now explicitly false/non-emitting, while UID0004IN remains the sole authored destructor body.
  - Added the exact hidden bit-1/bit-4 storage distinction and current CB62 ordinary-destructor model/no-xref state without duplicating ABI bodies in class C++.

- 2026-07-12 B005 accepted UID00011F implementation:
  - Raised `86/88` to `90/92` and replaced the withheld marker with the accepted complete declaration containing constructor, virtual destructor, five public accessors/mutator methods, draw/mouse/key/type virtuals, retained private selection notifier, exact three-field tail, and `[[CHILDREN]]` insertion point.
  - Added validator-assigned exact children UID0004IM-UID0004IW, complete-object layout/vtables, ten constructor shapes, public caller counts, callback/lifetime, code-10/code-12 notification distinction, exact draw resources/states, input geometry, raw liveness negatives, rejected owners/names, and retained PopupMenuControls source route.
  - Historical `menuType`, `parentBlock`, `AddOrLayoutItem`, `GetItemByIndex`, `OnSelectionChanged`, generic Event, and blank-declaration assumptions are explicitly superseded rather than silently removed.

- 2026-06-30 B008 empty-emitter implementation:
  - Score remains `86/88`; set `EMITTER_POSITION_OPTIONAL:21` and populated the formal block with a no-declaration route marker plus `[[CHILDREN]]`.
  - Evidence: B008 MCP/current docs reconfirm constructor ownership of a `MenuPane`, member-function callback binding, draw/input handlers, and scalar deleting destructor ownership, but the owned-menu/callback fields and `ControlPane` base layout are still not source-quality complete enough for a full declaration shell.
  - Source-quality decision: exact PopupMenuControlPane child ranges continue to emit through this class route and [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md); the marker clears the generated empty emitter without speculating fields.
- 2026-06-12 C001 barrier repair:
  - Score unchanged at `86/88`; updated the main memory route to compact core plus exact non-contiguous child pages.
  - Evidence: IDA MCP confirmed the core successor at `0x004985a0`, the `0x0049b8e0-0x0049b8e5` type-id helper, and intervening non-Popup control ownership.
- 2026-06-08 A004 Batch 114 strict parent-gate update:
  - Changed completion from `82` to `86`; confidence remains `88`; kept `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: live IDA rechecked constructor/callback/draw/mouse/key/destructor sizes and behavior, owned `MenuPane` field cleanup, constructor and selection callback fan-in, vtable data ownership, and direct parent [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) at `86/85`. Final C++ remains blank pending full field layout and source-quality names.

- 2026-06-05 live IDA refresh and parent attach:
  - Before: `COMPLETION:76`, `CONFIDENCE:84`, and blank `AUTOGEN_PARENT_UID`; the method map omitted public helper/accessor routines and retained stale generated-source provenance.
  - After: `COMPLETION:82`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000MN`; final C++ remains blank under the 95/95 gate.
  - Evidence: live IDA confirms the exact method starts, constructor callback binding, owned `MenuPane` field use, helper caller fanout, vtable-only draw/input/destructor refs, destructor ownership cleanup, and control type `12`. Parent attachment now satisfies the 80/80 gate because this class is `82/88` and [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) is `84/80`.

- Before: completion/confidence metadata were `0/0` despite class role, method map, source-file placement, IDA boundaries, and callback-helper links.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, drawing, mouse/key event handling, destructor thunks, destructor, control type id, owned `MenuPane`, and selection callback are documented; remaining gaps are field layout and full reconstructed C++.
