*** UID:000077 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"
#include "InputPanes.h"
#include "../controls/TextEditPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_DIALOGS_INPUTPANES_H
#define NEXUSTK_UI_DIALOGS_INPUTPANES_H

#include "../core/Pane.h"

class Event;
class TextBoxPane;
class TextEditPane;
struct InputKeyEvent;
struct RectBounds;

class LineInputPane : public Pane
{
public:
    LineInputPane(const wchar_t *promptText);
    virtual ~LineInputPane();

    void SetPromptText(const wchar_t *promptText);
    void CopyText(wchar_t *buffer, short maxChars) const;
    short TextLength() const;

    virtual void UpdateChildLayout();
    virtual void AttachChildren();
    virtual void ShowChildren();
    virtual bool HitTestEditChild(int x, int y);
    virtual Pane *GetActiveChild();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool ForwardTextEditEvent(InputKeyEvent *event);
    virtual void OnNoOpInputPaneSlot();
    virtual void OnSubmitInput() {}

protected:
    TextBoxPane *m_promptTextPane;
    TextEditPane *m_textEditPane;
    int m_deferredSubmitPending;
    int m_deferSubmitUntilNextEvent;
};

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LineInputPane

## Status

- UID0000OJ dependency closure: UID000077 is the position-1 InputPanes CPP/H root. CPP includes BlackHole, its own guarded header, and the complete TextEditPane header before children. H includes the complete Pane base before LineInputPane and emits derived declarations only after the base through `[[CHILDREN]]`.
- Confidence: very strong for class role, exact `0x108` layout, IDA boundaries, vtable lifecycle, prompt/text child ownership, the two deferred-submit fields, constructor behavior, and shared cleanup fanout; the remaining uncertainty is lexical rather than structural.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Autogen status: the complete declaration belongs in `InputPanes.h`, while CPP contains only `[[CHILDREN]]` so exact method children emit at namespace scope through [UID:0000K7][InputPanes](by-file/InputPanes.md). The source-facing fields map exactly to complete-object offsets `+0xf8`, `+0xfc`, `+0x100`, and `+0x104`; their spelling is inferred from behavior, but their widths, order, and roles are stable.
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Related derived handler: [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) is now attributed to [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md); it delegates unhandled keys to `LineInputPane::HandleKeyInput`.
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)

## UID0000OJ Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-053 | LineInputPane is the InputPanes formal root with exact CPP include order and one guarded H around complete base-first declarations. |
| C0000OJ-467 | InputPanes H includes Pane before LineInputPane; CPP includes TextEditPane before constructor children; CharInputPane and CharArgsInputPane follow their complete base. |

## Class Purpose

`LineInputPane` is the reusable one-line prompt base. It creates optional label text plus a `TextEditPane`, positions them differently for normal/high-resolution layouts, registers itself as the active line-input pane, forwards most input to the edit child, and handles Enter/Escape/Tab dismissal and owner notification.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f1c00-0x004f2009` | `LineInputPane(const wchar_t *promptText)` | Creates label/edit child panes under two exact asset-layout branches, arms the text-input guard, and updates active line-input/chat state. |
| `0x004f2010-0x004f2092` | shared cleanup/lifecycle body | Restores the three `LineInputPane` vtable views, removes prompt/edit children through the pane manager, and chains to inherited pane cleanup. |
| `0x004f20a0-0x004f22f4` | `SetPromptText` | Measures, creates, updates, and repositions the prompt label text child and paired edit child. |
| `0x004f2320-0x004f242e` | layout update | Recomputes label width and positions label/edit child panes. |
| `0x004f2430-0x004f24b4` | attach children | Attaches and shows label/edit children. |
| `0x004f24c0-0x004f24e4` | show/invalidate children | Invalidates label/edit panes and base pane. |
| `0x004f24f0-0x004f2579` | hit-test adjuster | Adjusts event coordinates for label/edit split and forwards to edit pane. |
| `0x004f2580-0x004f2597` | active-child forwarder | Forwards to the text-edit active interface. |
| `0x004f25a0-0x004f2754` | `HandleKeyOrTextEvent(Event *event)` | Handles Enter/Escape/Tab, deferred-submit state, owner notification, dismissal, active-slot cleanup, and edit-child forwarding. Active generated output omits the body. |
| `0x004f2760-0x004f2783` | text-edit forwarder | Forwards through the text-edit child virtual slot `+0x10`. |
| `0x004f2790` | `OnNoOpInputPaneSlot` | Distinct empty primary `+0x44` leaf slot. |
| `0x0041b6a0` | inline default `OnSubmitInput` | One-byte `retn` reached from primary `+0x48`; derived input panes override the same source virtual. |
| `0x004f2dd0-0x004f2e59` | non-deleting destructor | Dismisses child panes and tears down pane base. |
| `0x004f2e59-0x004f2e6f` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the shared scalar deleting destructor; the same two ABI entries are reused by `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` secondary/tertiary destructor slots. |
| `0x004f2ea0-0x004f2f63` | scalar deleting destructor | Destructor wrapper with conditional delete. |

## Evidence Notes

- IDA MCP confirms every listed function start.
- 2026-05-26 IDA MCP confirms `LineInputPane` vtables at `0x0061ca58`, `0x0061caa8`, and `0x0061cad8`, with constructor/destructor stores in the `0x004f1c00` cluster.
- 2026-06-06 IDA MCP confirms the early lifecycle/prompt sequence: the constructor is `0x004f1c00-0x004f2009`, `0x004f2010-0x004f2092` is the shared cleanup body, [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) is the shared prompt setter, and the intervening spans are `0xcc` alignment padding.
- Historical pre-Gate-2B IDA MCP revalidation kept the base constructor at `[0x004f1c00,0x004f2009)` with 37 callers under raw identity `sub_4F1C00`, untyped receiver/prototype, four blank address/function comment channels, and raw source-argument artifacts. Supervisor Gate 2B saved current `LineInputPane__Constructor` with prototype `LineInputPane *__thiscall(LineInputPane *this, const wchar_t *promptText)` and exact function-regular comment `Constructs the shared line-input pane, its optional prompt label, and its editable text child, then registers the active input pane.` Address-regular, address-repeatable, and function-repeatable comments remain blank; the physical source argument is `promptText: const wchar_t *` and EH `arg_4` remains non-source.
- UID000414 Gate-2B checkpoints `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2` and `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E` are dated history. Catalog entry 0377 records UID00035P prestate/backup SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94` and authoritative saved poststate SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`. The saved type is exactly `0x108` bytes with five members: `_paneBase` `[+0,+0xf8)`, `TextBoxPane *m_promptTextPane` at `+0xf8`, `TextEditPane *m_textEditPane` at `+0xfc`, `int m_deferredSubmitPending` at `+0x100`, and `int m_deferSubmitUntilNextEvent` at `+0x104`. `TextBoxPane` exists only as an incomplete/no-layout type. Exact constructor range, bytes, 37 xrefs, comments, frame, layout branches, and padding remain preserved.
- Decompilation of `0x004f2010` shows cleanup at `this+0xf8` and `this+0xfc`; the prompt setter documents those slots as `m_promptTextPane` and `m_textEditPane`. Constructor writes and `HandleKeyOrTextEvent` reads/writes resolve `+0x100` as `m_deferredSubmitPending` and `+0x104` as `m_deferSubmitUntilNextEvent`.
- IDA confirms the secondary/tertiary destructor entries are two-instruction compiler thunks, not handwritten methods.
- B006 source-routing recheck confirms the LineInputPane-family adjustor subranges are true half-open `0x004f2e59-0x004f2e64` and `0x004f2e64-0x004f2e6f`; generated `virt_meth_*` names for these addresses are vtable-slot pollution, not source method names.
- IDA decompilation of `0x004f25a0` shows real input handling despite an imported/generated body omission; track the omission under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The previously listed `0x005b3e80` non-contiguous helper is not directly owned by `LineInputPane`: live IDA shows it in a `SayToUserNameInputPane` secondary vtable slot, with `LineInputPane::HandleKeyInput` used only as its fallback delegate.
- Primary vtable evidence keeps `+0x44 -> 0x004f2790` and `+0x48 -> 0x0041b6a0` separate. The latter is one instruction, `retn`, and has folded/runtime/no-op uses rather than a unique standalone source body, so the source declaration is the inline empty `virtual void OnSubmitInput() {}` immediately after `OnNoOpInputPaneSlot()`.
- `LineInputPane::HandleKeyOrTextEvent(Event *)` dispatches primary `+0x48` on Enter while retaining Escape, Tab, deferred deletion, owner notification, and text-edit forwarding in the base. [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md) supplies the matching derived slot at `0x0062f744 -> 0x005b1640` as `SayToUserMessageInputPane::OnSubmitInput()`; this does not rename or merge `+0x44`.

## B001-042 Exact Split Evidence

The broad [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) aggregate is now split into exact `LineInputPane` children: [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md), [UID:00035Q][0x004f2010-0x004f2092.LineInputPaneCleanupBody](by-memory/0x004f2010-0x004f2092.LineInputPaneCleanupBody.md), [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md), [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md), [UID:00035T][0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout](by-memory/0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout.md), [UID:00035U][0x004f2430-0x004f24b5.LineInputPaneAttachChildren](by-memory/0x004f2430-0x004f24b5.LineInputPaneAttachChildren.md), [UID:00035V][0x004f24c0-0x004f24e5.LineInputPaneShowChildren](by-memory/0x004f24c0-0x004f24e5.LineInputPaneShowChildren.md), [UID:00035W][0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder](by-memory/0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder.md), [UID:00035X][0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder](by-memory/0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder.md), [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md), [UID:00035Z][0x004f2760-0x004f2783.LineInputPaneTextEditForwarder](by-memory/0x004f2760-0x004f2783.LineInputPaneTextEditForwarder.md), [UID:000360][0x004f2790-0x004f2791.LineInputPaneNoOpVirtual](by-memory/0x004f2790-0x004f2791.LineInputPaneNoOpVirtual.md), [UID:00036D][0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor](by-memory/0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor.md), and [UID:00036E][0x004f2ea0-0x004f2f63.LineInputPaneScalarDeletingDestructor](by-memory/0x004f2ea0-0x004f2f63.LineInputPaneScalarDeletingDestructor.md).

Live B001-042 IDA checks confirm exact half-open child bounds, clean `0xcc` padding between siblings, constructor/destructor vtable stores, prompt/edit child offsets `this+0xf8` and `this+0xfc`, and key-handler owner notification/dismissal behavior. This raises the class to `88/90` and clears the direct-parent gate for all reconstructable `LineInputPane` children. [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md) remains compiler-generated and parent blank.

## Class Layout And Constructor Closure

The recovered complete-object size is exactly `0x108` bytes. The inherited `Pane` subobject and established interface facets occupy `[+0x000,+0x0f8)`. The source-visible tail is contiguous and contains `TextBoxPane *m_promptTextPane` at `+0xf8`, `TextEditPane *m_textEditPane` at `+0xfc`, `int m_deferredSubmitPending` at `+0x100`, and `int m_deferSubmitUntilNextEvent` at `+0x104`; no unexplained tail bytes remain.

[UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) now owns source-ready constructor C++ and initializes all four fields. [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md) independently corroborates the two integer roles through Enter/Escape/Tab and deferred-submit control flow. This layout closes the former field-name/size blocker without fabricating members outside the observed tail.

Score `93/94` reflects the complete declaration, exact size/offsets, source-ready constructor, stable method inventory, and compiler-thunk separation. It remains below final audit only because a few lexical choices and final include order are inferred rather than symbol-proven.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md)

## Changes

- 2026-08-13 B006 UID000401 support callback:
  - Preserved `93/94`, UID0000K7 owner/emitter, exact `0x108` layout, every existing declaration/field/method child, children-only CPP route, and all prior history.
  - Added the accepted inline empty `virtual void OnSubmitInput() {}` immediately after `OnNoOpInputPaneSlot()` in formal H. Documented base primary `+0x44 -> 0x004f2790` as the distinct no-op slot and base `+0x48 -> 0x0041b6a0` as the folded one-byte submit default, with UID000401 `0x0062f744 -> 0x005b1640` as the matching derived override.
  - No standalone `0x0041b6a0` CPP body, target-local key/cancel method, or vtable data was added; inherited Enter/Escape/Tab/deferred-deletion behavior remains on `HandleKeyOrTextEvent(Event *)`.

- 2026-07-30 B008 UID00035P accepted ordinary implementation callback:
  - Raised the class from `91/93` to `93/94`, preserving owner/emitter UID0000K7, reconstructable state, blank optional position, and `[[CHILDREN]]` CPP topology.
  - Added `m_deferredSubmitPending` at `+0x100` and `m_deferSubmitUntilNextEvent` at `+0x104`, completing the exact `0x108` class layout without moving the established `+0xf8/+0xfc` child pointers.
  - Updated the constructor and handler map to the source-facing `LineInputPane(const wchar_t *)` and `HandleKeyOrTextEvent(Event *)` contracts and linked the independent constructor/handler evidence for both trailing fields.

- 2026-07-29 B008 UID000414 accepted ordinary implementation callback:
  - Preserved `91/93`, owner/emitter UID0000K7, reconstructable state, blank optional position, every declaration, field, child, method/evidence section, and all prior history.
  - Moved the complete class declaration from formal CPP to formal H and left only `[[CHILDREN]]` in CPP. This matches the shared `InputPanes.h` declaration plus namespace-scope child definitions expected by the accepted SayInputPane source topology.
  - Revalidated the protected base-constructor prestate at that callback: `[0x004f1c00,0x004f2009)`, 37 callers, then-raw identity/type, four blank comment channels, and raw frame names. No IDA mutation was made by B008 during the ordinary callback.
- 2026-07-30 supervisor Gate 2B reconciliation:
  - Recorded applied `LineInputPane__Constructor`, exact typed prototype/comment, `promptText: const wchar_t *` physical argument, preserved non-source EH `arg_4`, and unchanged 37-xref/range/layout state from action checkpoint `87D34CCD...E46F500F2`; current saved IDB `83C20CE9...C294A9E` reconfirms the same state without drift.
- 2026-07-30 B008 UID00035P supervisor Gate 2B poststate:
  - Catalog entry 0377 and saved IDB `A0D97FC5...4375971` apply the exact five-member `0x108` type, retain incomplete/no-layout `TextBoxPane`, and preserve the constructor's canonical name/prototype/comment/frame and all protected binary evidence.
  - A controlled stack-offset experiment was discarded by restarting MCP before save; the clean accepted transaction made no direct stack edit, so the saved constructor frame remains the literal prestate frame rather than the discarded presentation.

### 2026-07-20 canonical Event-handler synchronization

- Installed complete R8 and changed only the shared key/text slot from provisional `HandleKeyInput(InputKeyEvent *)` to canonical `HandleKeyOrTextEvent(Event *)`.
- Preserved constructor/destructor, prompt/text helpers, `TextEditPane` forwarder, `RectBounds`, fields/layout guard, child definitions, UID00035Y Enter/Escape/Tab behavior, and every independent source/ownership/compiler fact.
- UID000364 Escape handling returns this inherited method's exact Boolean result; printable handling calls it after deferred deletion and UserPane state clear, then invokes CharInputPane `OnAccept`. Those dependencies do not move UID000364 ownership into LineInputPane.
- Scores become `91/93`; owner/emitter UID0000K7, reconstructable true, blank optional position, and source route remain unchanged. The old `InputKeyEvent` method spelling is superseded only for this shared interface slot, not evidence that unrelated TextEdit or filter children changed.

- 2026-07-01 Agent-B011 [UID:0000K7][InputPanes](by-file/InputPanes.md) empty-emitter implementation: raised from `88/90` to `90/91` and inserted the accepted formal `LineInputPane` declaration shell with `TextBoxPane`, `TextEditPane`, method declarations, `m_promptTextPane` at `+0xf8`, `m_textEditPane` at `+0xfc`, and `[[CHILDREN]]`. The old blank-C++/final-gate blocker is superseded by active-gate readiness with explicit inference caveats for field and virtual names.
- 2026-06-11 Agent-B001 B001-042: raised from `86/88` to `88/90` after splitting the broad base aggregate into exact child pages and rechecking boundaries, padding, vtable stores, key handling, prompt/edit child offsets, and destructor ownership with live IDA MCP evidence.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md) because this class is 84/82 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed the constructor/layout/input/destructor cluster from `0x004f1c00` through `0x004f2ea0` and the null virtual at `0x004f2790`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the one-line prompt base is documented with a detailed method map, vtables, compiler adjustors, and missing-body caveat, but exact field names and final source-level C++ remain incomplete. Evidence: IDA-confirmed function starts, input-pane vtable family, destructor thunk notes, and imported/generated body-omission tracking.
- 2026-06-05: Raised confidence from `82` to `84` and corrected the `0x005b3e80` ownership note.
  - Before: this page listed [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) under its former stale `LineInputPaneHistoryNavigation` filename as a non-contiguous `LineInputPane` helper.
  - After: this page treats that helper as [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) code that depends on `LineInputPane::HandleKeyInput` for fallback behavior.
  - Evidence: 2026-06-05 IDA MCP reports the sole function xref to `0x005b3e80` at `0x0062fccc`, the `SayToUserNameInputPane` secondary vtable slot; the function's adjusted offsets match recipient-name history fields initialized by `0x005b3cb0`.
- 2026-06-06: Raised completion/confidence from `84/84` to `86/88` after filling the missing early lifecycle/prompt entries.
  - Before: the class method map jumped from the constructor to layout/update helpers and did not list the shared cleanup body or prompt setter.
  - After: the method map records the corrected constructor end, `0x004f2010` cleanup body, and linked `LineInputPaneSetPromptText` child page, with evidence for the shared child slots at `this+0xf8` and `this+0xfc`.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, `disasm`, and byte checks on 2026-06-06.
