*** UID:00006M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class Pane;
class TextEditPane;
struct MacroHotkeyRecord;
struct Rect;
struct RectBounds;

class IntegrateMacroEditControlPane : public ControlPane
{
public:
    IntegrateMacroEditControlPane(MacroHotkeyRecord *record, const Rect &bounds);
    virtual ~IntegrateMacroEditControlPane();

    bool IsTextEditActive() const;
    void SetMacroData(MacroHotkeyRecord *record);
    void RefreshDisplay();
    void SyncEditControl();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    void EnterTextEditMode();
    void LeaveTextEditMode();

    MacroHotkeyRecord *m_macroData;
    bool m_pendingTextEditForward;
    bool m_editActive;
    TextEditPane *m_textEdit;
    unsigned char m_savedTextEditState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IntegrateMacroEditControlPane

## Status

- Confidence: very strong for class behavior, current helper/thunk classification, vtable reachability, and macro-record mutation; medium-high for final source-facing helper/member names.
- EventHandler interface status: secondary `+0x04/+0x08/+0x0c` are source-ready `HandlePointerOrMouseEvent(Event *)`, `HandleKeyOrTextEvent(Event *)`, and `HandleImeEvent(Event *)`; the complete class declaration now includes those surfaces and every other qualified definition.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Historical generated-source lead: `source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp`; stale simroot output is behavior lead material only, not current source authority after the UID0001IK split.
- IDA MCP rechecked: 2026-07-19 direct UID0004AK source-quality pass on evidence session `9b0396a3`, preserving the 2026-06-16 class/thunk pass as historical evidence.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`IntegrateMacroEditControlPane` is a control wrapper for integrated macro edit rows used by [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md). It owns a saved [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) pointer, a separately allocated `TextEditPane`, forwarding/edit-active state, row painting, pointer/key/IME dispatch, public layer-add/layer-remove overrides, and explicit source teardown of the owned editor.

## State Fields

| Offset | Meaning |
| --- | --- |
| `+0x108` | current [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) pointer; records with `*(record + 4) == 1` contain editable wide text at `record + 8`. |
| `+0x10c` | pending text-edit forward flag; constructor intentionally leaves it uninitialized, key/text handling tests and clears it before interpreting the event. |
| `+0x10d` | edit-active / forwarding/edit-sync flag checked by [UID:0004AI][0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive](by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md), set by [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md), and cleared before copying editor text back to the macro record; the constructor also intentionally tests it without first initializing it. |
| `+0x10e-0x110` | natural compiler alignment before the pointer; no source padding member. |
| `+0x110` | owned `TextEditPane *`; allocated by the constructor and deleted by the explicit source destructor. |
| `+0x114` | saved text-edit state byte passed by [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md) to the embedded editor state setter before enabling/focusing the editor and selecting the text range. |
| `+0x115-0x118` | natural class-tail alignment; no source padding member. |

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | [UID:0004AG][0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor](by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md) | Builds a `ControlPane(8)` row and creates/configures the embedded `TextEditPane`. |
| raw non-deleting destructor | [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md) | Source destructor semantics for deleting `m_textEdit` at `+0x110`; preserves zero-inbound-xref caveat. |
| `IsTextEditActive` | [UID:0004AI][0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive](by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md) | Raw predicate for text-mode record and edit-active byte `+0x10d`; preserves zero-inbound-xref caveat. |
| `SetMacroData` | [UID:0004AJ][0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData](by-memory/0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData.md) | Stores the macro-record pointer, clears the embedded editor, and seeds it from saved wide text when record type is `1`. |
| `RefreshDisplay` | [UID:0004AK][0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay](by-memory/0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md) | Exact ten-byte public source member called once by `IntegrateMacroDialog::RefreshMacroEditFields` after `SetMacroData`; it passes inherited `GrafPort::m_visibleBounds` at complete-object `+0x44` to `Pane::InvalidateRect` primary slot `+0x20`. |
| `OnPaint` | [UID:0004AL][0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint](by-memory/0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint.md) | Paints the integrated macro row, type indicator, key label, and content text. |
| `HandleKeyOrTextEvent` | [UID:0004AM][0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent.md) | EventHandler `+0x08`; forwards active editing, preserves pending-forward ordering, enters text mode on semicolon, stores item/spell ASCII bindings, and invalidates this pane. |
| `HandlePointerOrMouseEvent` | [UID:0004AN][0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent.md) | EventHandler `+0x04`; forwards the same Event to the embedded editor while edit mode is active and otherwise returns true. |
| `HandleImeEvent` | [UID:0004AO][0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent](by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent.md) | EventHandler `+0x0c`; forwards the same Event to the embedded editor while edit mode is active and otherwise returns true. |
| `EnterTextEditMode` | [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md) | Raw helper setting `+0x10d`, restoring saved text-edit state byte `+0x114`, showing/focusing the editor, and selecting text; preserves zero-inbound-xref caveat. |
| `LeaveTextEditMode` | [UID:0004AQ][0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode](by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md) | Raw helper clearing `+0x10d`, applying edit-control mode `4`, and hiding/deactivating the editor; preserves zero-inbound-xref caveat. |
| `AddToLayer` | [UID:0004AR][0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer](by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md) | Public primary `+0x30` override: attaches this row through Pane first, then conditionally queries owned `m_textEdit` bounds and attaches the child at order zero after this row in the same Layer. The canonical validator path is `0x00580570-0x005805b9`; evidence-time modeled envelope `0x00580550-0x005805b3` remains provenance. |
| `RemoveFromLayer` | [UID:0004AS][0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer](by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md) | Public primary `+0x38` override: conditionally removes owned `m_textEdit` first, then unconditionally removes this row through `Pane::RemoveFromLayer`; the final direct jump is compiler tail-call lowering. |
| `SyncEditControl` | [UID:0004AT][0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl](by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md) | Copies embedded editor text back into the bound macro record and deactivates forwarding mode. |
| `Activate` thunk | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Vtable thunk to `RadioGroupControlPane::Activate` (`0x00494c30`), exposed by IDA as a data-referenced slot. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580690`. |
| scalar deleting destructor | [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md) | Compiler ABI scalar deleting wrapper; non-emitting no-code child whose source destructor semantics are [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md). |

## Evidence Notes

- IDA MCP confirms all listed function starts and vtable-data xrefs for the `0x00580640-0x00580650` thunk run.
- IDA decompiles `SetMacroData` as storing the record at `this[66]`, clearing editor pointer `this[68]`, and loading `record + 8` when `*(record + 4) == 1`.
- IDA decompiles `SyncEditControl` as checking record type `1`, leaving forwarding mode, copying up to 64 units from the embedded editor into `record + 8`, then calling the deactivate path at `0x00494c10`.
- IDA decompiles the method now identified as `HandleKeyOrTextEvent` as forwarding active text editing unless a pending-forward byte is set, clearing that pending byte before event-type testing, setting `*(record + 4) = 1` for semicolon/text-entry mode, or assigning an alphabetic key at `record + 8` with state `2`/`3` depending on the active tab in `g_pGeneralPurposePanel`. The resolved tab mapping is active child index `3` / spell inventory -> state `2` / `S`, and active child index `2` / inventory -> state `3` / `I`.
- Historical disabled generated-output limitation: stale output included only the `0x00580650` adjustor thunk. Current authority is [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md), which documents `0x00580640`, `0x00580645`, and `0x00580650` as reviewed vtable support, plus [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md) for the non-emitting scalar deleting wrapper.
- 2026-06-16 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed every `IntegrateMacroEditControlPane` method/function record from constructor `0x0057fd10` through scalar deleting destructor `0x00580690`, plus the seven-function thunk run `0x00580640-0x00580686`.
- The same pass reconfirmed current reachability: constructor has one direct caller at `0x00541cc5`, `SetMacroData` has one direct caller at `0x00542247`, `SyncEditControl` is a vtable-only target at `0x0062d384`, and the `0x00580640` thunk run has only vtable-data refs plus adjustor-to-destructor code refs.
- Current decompilation of `HandleKeyOrTextEvent`, `SyncEditControl`, and the scalar deleting destructor reconfirmed the record pointer at `this+0x108`, edit/forwarding byte at `this+0x10d`, embedded editor pointer at `this+0x110`, text-mode state `1`, state `2`/`3` tab-driven key assignment, embedded-editor cleanup, and base-control teardown.
- Integrate secondary cells `0x0062d398/0x0062d39c/0x0062d3a0` map exactly to pointer/mouse, key/text, and IME EventHandler positions. The first and third conditionally call the corresponding embedded TextEdit Event method; the middle preserves exact text-edit forwarding, pending state, type-8/type-10 behavior, semicolon transition, ASCII assignment, record updates, and self invalidation.
- Historical `OnKeyEvent`, `ForwardMouseEvent`, and `ForwardFocusEvent` labels and KeyEvent/MouseEvent/FocusEvent parameter shapes are superseded. The complete declaration preserves the corrected Event-based contracts, raw-helper caveats, compiler thunks, and unrelated class facts.

## Ordinary Destructor Source Evidence

- [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md) is the exact 63-byte ordinary-destructor body, SHA256 `97A9BB65E51403BDB2A3D2CA33CE8BEAAFEDC6457C7862D778C18F21AD92C5E7`. It restores the three Integrate vptrs, tests owned `TextEditPane *m_textEdit` at `+0x110`, invokes the child's virtual deleting destructor with flag `1`, nulls the member only on the non-null path, and tail-transfers to `Pane__Destructor`.
- The raw ordinary start has zero inbound code/data/immediate xrefs and no aligned VA/raw-offset pointer match. This caveat does not make it padding: constructor, ordinary body, and scalar wrapper store the same vtable heads `0x0062d32c/0x0062d394/0x0062d3c4`, while [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md) duplicates the cleanup and is live through two adjustor refs plus the primary vtable.
- The source-visible class behavior is an explicit guard, `delete m_textEdit`, and in-branch `m_textEdit = NULL`. Period-correct `NULL` replaces the historical C++11 `nullptr` reconstruction without changing behavior. Vptr stores, implicit `Pane` teardown, scalar flags, adjustor thunks, and storage deletion remain compiler-generated and are not additional class methods or source statements.
- This evidence preserves the complete class declaration and existing `92/94` metadata. The declaration `virtual ~IntegrateMacroEditControlPane();` remains the sole class-level declaration in UID00006M's formal `RECONSTRUCTION_CPP CODE`; UID00006M's formal `RECONSTRUCTION_H CODE` remains blank and no `MacroDialogs.h` is generated. UID0004AH supplies the qualified CPP definition.
- Historical correction: the former phrase "sole H-channel source" was inaccurate because the declaration is physically stored and emitted through UID00006M's formal CPP channel under the current generator design. Preserve that phrase only as superseded history, not current channel authority.

## Layer Lifecycle Source Behavior

- Primary vtable slot `+0x30` is [UID:0004AR][0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer](by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md), matching `Pane::AddToLayer` and the TextEditPane/ScrollablePane child contract. Primary `+0x38` is [UID:0004AS][0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer](by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md), matching `Pane::RemoveFromLayer` and child removal.
- `AddToLayer` preserves exact source order: call Pane with the incoming bounds/order/previous-pane/Layer arguments, then, only when `m_textEdit` is non-null, obtain a local `RectBounds` and attach the child with order zero, previous pane `this`, and the same Layer. The local object's security cookie is compiler lowering, not source syntax.
- `RemoveFromLayer` preserves exact source order: conditionally remove `m_textEdit`, then unconditionally call Pane removal. The method has no source-visible return; the final direct jump and incidental AL value are compiler effects.
- Constructor allocation and the explicit source destructor establish `m_textEdit` at `+0x110` as an owned nullable raw pointer. Neither lifecycle member allocates, frees, nulls, or changes editor visibility.
- Historical `OnAttachToParent(const Rect &, int, int, Pane *)`, `OnHide()`, `ControlPane::OnAttachToParent`, and `ControlPane::OnHide` spellings are rejected. Hide is inherited at exact primary slot `+0x18`, while this class's custom lifecycle pair occupies `+0x30/+0x38`.
- UID0004AR's supervisor-authorized canonical document endpoints are `0x00580570-0x005805b9`; the evidence-time IDA modeled function envelope `0x00580550-0x005805b3`, 99 bytes, remains labeled analysis provenance rather than a second source method.

## RefreshDisplay Source Behavior

- UID0004AK is exactly `[0x0057ffa0,0x0057ffaa)`, ten bytes `8b 11 8d 41 44 50 ff 52 20 c3`, with byte SHA256 `B84326BE49B27E28BFE460034B009BF9787976F75422D964A6ED9ABC0501E4E8`. It is one basic block of complexity one with no frame, branch, EH, explicit result construction, or stack argument.
- The member loads the complete object's primary vptr, forms `this+0x44`, pushes that address, invokes slot `+0x20`, and returns. Current [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md) resolves that inherited primary slot to `Pane::InvalidateRect(const RectBounds *)` at `0x00544800`.
- Current [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) assigns complete-object `+0x44` to inherited `GrafPort::m_visibleBounds`. The exact source behavior is invalidation of this row's own visible bounds, not a parent refresh.
- UID00045L supplies the sole code xref at `0x0054224e`, immediately after `SetMacroData`. The caller restores EAX from its saved receiver immediately afterward, proving the virtual result is incidental; the accepted source contract remains public `void RefreshDisplay()`.
- There is no target data/vtable xref, alternate caller, parent-pointer read, alternate receiver, field write, explicit return construction, branch, string/global access, null rectangle, allocator, exception, packet, destructor, or resource behavior.
- The exact ten-byte sequence has seven comparator sites with mixed dispositions: vtable-only compiler forwarders, owner-specific tails, unreferenced raw ABI evidence, `Pane::Show`, direct-call UID0004AC, and another vtable-only comparator. UID0004AK's direct caller and absence from a vtable establish an ordinary source-authored out-of-line member.
- Four leading and six trailing `0xcc` bytes delimit the standalone member. They remain external alignment and are not emitted as source behavior.
- Historical `RequestParentRefresh`, parent-refresh wording, and inherited `m_bounds`/`m_localBounds` aliases are superseded. No parent is read, and current layout authority names `m_visibleBounds`. Raw vtable-call C++, `InvalidateRect(NULL)`, an integer source return, compiler/no-code treatment, and Pane/GrafPort ownership transfer are rejected by the receiver/argument/caller/source-route evidence.
- `RefreshDisplay` remains the strongest source spelling from the complete class/caller union and its semantic position after record rebinding. Original symbols are stripped, so lexical uncertainty is reflected in confidence `94`; it does not block behavior-identical source emission.

## Complete Source Declaration Evidence

- Allocation size is exactly `0x118`. Inherited `ControlPane` ends at `0x108`; the declared pointer/booleans/pointer/state byte plus natural alignment close the object exactly at `0x118` without raw-layout members.
- The declaration contains all fourteen current qualified source definitions: constructor, destructor, `IsTextEditActive`, `SetMacroData`, `RefreshDisplay`, `SyncEditControl`, `OnPaint`, three Event handlers, public `AddToLayer`, public `RemoveFromLayer`, `EnterTextEditMode`, and `LeaveTextEditMode`.
- Primary, secondary, and tertiary table routes bind the ControlPane, Pane/EventHandler adjusted views, and destructor family to this one class. RTTI and allocation evidence reject a source-local wrapper class or a `TextEditControlPane` member type.
- Exact constructor evidence at [UID:0004AG][0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor](by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md) allocates the lower `TextEditPane` type and stores its pointer at `+0x110`; exact source destructor semantics at [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md) delete that pointer. The scalar wrapper [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md) and adjustor thunks are compiler lowering, not additional source methods.
- Source order position `30` places this class after IntegrateMacroDialog `20` and before NewMacroDialog `40`; the declaration closes before `[[CHILDREN]]`, keeping all fourteen definitions at namespace scope.

## Rejected Alternatives And Score Rationale

- An embedded-by-value editor, `TextEditControlPane *`, explicit vptrs, raw offset fields, explicit padding arrays, handwritten adjustor/scalar wrappers, and a blank class marker are rejected by allocation, constructor, destructor, and table evidence.
- The raw no-inbound-route status of `IsTextEditActive`, `EnterTextEditMode`, and `LeaveTextEditMode` remains an exact reachability caveat; their complete bodies and duplicated inline/family semantics support retained source declarations rather than suppression.
- `RequestParentRefresh`, parent-redraw semantics, `m_bounds`, and `m_localBounds` are retained only as historical rejected assumptions. UID0004AK reads no parent and calls inherited `InvalidateRect` on `m_visibleBounds`.
- `OnAttachToParent`, `OnHide`, `ControlPane::OnAttachToParent`, and `ControlPane::OnHide` are retained only as historical rejected lifecycle assumptions. Exact Pane/TextEditPane primary slots `+0x30/+0x38`, direct base targets, and authored child orchestration establish `AddToLayer`/`RemoveFromLayer`.
- Completion `92` reflects complete natural layout, all fourteen declarations, exact class/source order, fields/types, lifecycle, child inventory, formal closure, and exact UID0004AK body/caller/slot/field/source-disposition closure. Confidence `94` reflects exact allocation, field access, table, constructor/destructor, sibling type, and display-refresh evidence; private member/access spellings remain inferred.
- A PE-section-mapped scan of `NexusTK.exe` found direct `E8` hits to the constructor and `SetMacroData` only at the IDA-confirmed caller sites, a vtable-pointer hit for `SyncEditControl` at `0x0062d384`, and no RVA-pointer hits. This supports the current source-facing model: normal class methods plus compiler-generated vtable support, with no separate raw-start reachability issue for the class.
- Inventory/item macro rows that display a saved item slot should resolve the item name through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) and `LocalInventorySlotRecord::displayName` at `+0x06`; this class owns macro-row editing, not the local-player inventory table.
- 2026-07-06 B006 live MCP recheck for [UID:0004AI][0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive](by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md) used session/database `b001-0001I5`. The exact `0x0057ff40-0x0057ff5b` body is 27 bytes, is not modeled by `lookup_funcs` as an IDA function, has zero inbound `xrefs_to`, and has a unique IDA-format range signature. The body reads `this+0x108`, checks record state `1`, then checks byte `this+0x10d`; [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md) sets the same byte and [UID:0004AQ][0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode](by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md) clears it, so UID0004AI remains a source-authored raw predicate in the text-edit-mode helper cluster despite the no-inbound-xref caveat.
- 2026-07-06 B010 live MCP recheck for [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md) used session/database `b001-0004HT` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` was OK and Hex-Rays was ready. The exact `0x005804c0-0x0058050d` body is 77 bytes (`56 8B F1 80 BE 0D 01 00 00 01 74 3F 8B 8E 10 01 00 00 C6 86 0D 01 00 00 01 85 C9 74 2E 0F B6 86 14 01 00 00 50 E8 C6 41 FC FF 8B 8E 10 01 00 00 6A 01 6A 01 E8 87 E5 00 00 8B 8E 10 01 00 00 68 FF 7F 00 00 6A 00 E8 95 ED 00 00 5E C3`), is bracketed by twelve leading `0xcc` bytes and three trailing `0xcc` bytes, is not modeled by `lookup_funcs` as an IDA function, has zero inbound `xrefs_to`, has a unique IDA-format exact-body signature with a single `find_bytes` hit at `0x5804c0`, and has no VA/RVA pointer-byte hits for `0x005804c0`. The 21-instruction mapping sets `+0x10d`, uses the embedded editor pointer at `+0x110`, passes saved byte `+0x114`, enables/focuses the editor, and selects `0..0x7fff`; this keeps UID0004AP tied to the UID0004AI/UID0004AQ/UID0004AT text-edit-mode helper cluster while preserving the no-inbound-xref caveat.
- 2026-07-07 B004 live MCP recheck for [UID:0004AQ][0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode](by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md) used current session `supervisor-nexustk-20260707` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` was OK. The exact `0x00580510-0x00580545` body is 53 bytes, is not modeled by `lookup_funcs` as an IDA function, cannot be decompiled or queried for callees because no function exists, has zero inbound `xrefs_to`, and has no code-ref, data-ref, VA-pointer, or RVA-pointer route to `0x00580510`. The exact body/signature has a single hit at `0x580510`; the body clears byte `+0x10d`, uses embedded editor pointer `+0x110`, passes state byte `4` to `0x005446b0`, and calls `0x0058ea80` with `false,false` to hide/disable the editor. [UID:0004AT][0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl](by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md) inlines the same leave sequence at `0x5805f9-0x58061a` before copying text, which corroborates the helper behavior without proving a direct caller/xref route.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0004AG][0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor](by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md)
- [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md)
- [UID:0004AI][0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive](by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md)
- [UID:0004AJ][0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData](by-memory/0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData.md)
- [UID:0004AK][0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay](by-memory/0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md)
- [UID:0004AL][0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint](by-memory/0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint.md)
- [UID:0004AM][0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent.md)
- [UID:0004AN][0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent.md)
- [UID:0004AO][0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent](by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent.md)
- [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md)
- [UID:0004AQ][0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode](by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md)
- [UID:0004AR][0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer](by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md)
- [UID:0004AS][0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer](by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md)
- [UID:0004AT][0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl](by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md)
- [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)

## Changes

- 2026-07-19 B002 UID0004AS implementation callback:
  - Installed the complete no-loss class declaration with public `AddToLayer(const RectBounds *, int, Pane *, Layer *)` and `RemoveFromLayer()` overrides while preserving all existing fields, methods, access groups, source order, and class closure before `[[CHILDREN]]`.
  - Synchronized UID0004AR/UID0004AS validator-renamed links, exact primary `+0x30/+0x38` identities, child/base call order, `m_textEdit` ownership/null semantics, UID0004AR canonical-path versus evidence-envelope distinction, compiler cookie/tail exclusions, and historicalized OnAttachToParent/OnHide aliases.

- 2026-07-15 B003 UID00049G callback:
  - Raised `87/88` to `92/94`, set position `30`, and installed the complete natural `0x118` class declaration with all fourteen methods and class closure before `[[CHILDREN]]`.
  - Resolved `TextEditPane *`, `+0x108/+0x10c/+0x10d/+0x110/+0x114` fields, natural internal/tail alignment, explicit source destructor cause, and compiler scalar/thunk exclusions.
  - Preserved counterintuitive constructor omissions for both booleans, raw-helper no-route evidence, Event interface corrections, macro-record behavior, and every existing child/history fact.

- 2026-07-14 B003 UID0004A5 implementation callback: synchronized UID0004AM/UID0004AN/UID0004AO validator-renamed links and exact EventHandler `+0x08/+0x04/+0x0c` roles, preserved the full key/text state machine and forwarding behavior, historicalized stale event labels, and left `87/88`, UID0000KY routing, blank formal, and unrelated Integrate evidence unchanged.
- 2026-07-07 B004 UID0004AQ implementation callback: added current MCP-backed support evidence for the exact 53-byte `LeaveTextEditMode` raw helper, its no-function/no-inbound-xref/no-pointer-route state, unique exact-body hit, `+0x10d` flag clear, `+0x110` editor pointer use, state byte `4`, `false,false` hide/disable call, and UID0004AT inline corroboration. Class score, owner/emitter metadata, and formal C++ were intentionally preserved.
- 2026-07-06 B010 UID0004AP implementation callback: added current MCP-backed support evidence for the exact 77-byte `EnterTextEditMode` raw helper, its no-function/no-inbound-xref state, unique exact-body signature, no VA/RVA pointer-byte hits, `+0x10d`/`+0x110`/`+0x114` field use, `0..0x7fff` selection behavior, and relationship to UID0004AI/UID0004AQ/UID0004AT as the same text-edit-mode helper cluster. Class score and metadata were intentionally preserved.
- 2026-07-06 B006 UID0004AI implementation callback: added current MCP-backed support evidence for the exact 27-byte `IsTextEditActive` raw helper, its no-function/no-inbound-xref state, unique range signature, `+0x108`/`+0x10d` field use, and relationship to UID0004AP/UID0004AQ as the same text-edit-mode helper cluster. Class score and metadata were intentionally preserved.
- 2026-06-29 B001 UID0001IK implementation callback: historicalized the active simroot recovered-file line and disabled generated-output thunk wording as stale generated lead material. Linked exact source children [UID:0004AG][0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor](by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md)-[UID:0004AT][0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl](by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md), preserved raw-helper no-inbound-xref caveats for [UID:0004AH][0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor](by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md), [UID:0004AI][0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive](by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md), [UID:0004AP][0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode](by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md), and [UID:0004AQ][0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode](by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md), and added scalar deleting wrapper [UID:0004AU][0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580690-0x00580701.IntegrateMacroEditControlPaneScalarDeletingDestructor.md) as a non-emitting compiler ABI child.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the item macro display dependency on `LocalInventorySlotRecord::displayName` while preserving macro-record ownership here.
- Completion/confidence score update: existed before as `0/0`; changed to `86/84`. Summary: macro edit-row role, state offsets, embedded TextEditPane relationship, method map, macro record semantics, vtable thunks, decompiled Set/Sync/Key behavior, and generated-output omissions are documented in detail; confidence remains limited by final source-facing representation of thunk/helper slots. Evidence: `MacroEditControlPanes`, `MacroEditControlPaneVtableThunks`, `MacroDialogFamilyVtables`, and `MacroHotkeyRecord`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) because the class is `86/84` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0057fd10`, `0x0057ff60`, `0x0057ffa0`, `0x0057ffb0`, `0x00580320`, `0x00580460`, `0x00580490`, `0x00580550`, `0x005805c0`, `0x005805e0`, `0x00580640`, `0x00580645`, `0x00580650`, and `0x00580690`; current `callers` confirms construction from `IntegrateMacroDialog` at `0x00541cc5`.
- 2026-06-16 A001 low-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`; owner/emitter remain [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed method/thunk function records, constructor and `SetMacroData` direct callers, vtable-only `SyncEditControl` and thunk refs, decompiled macro-record state edits, destructor ownership of the embedded editor, and PE-section-mapped reachability for the constructor/record setter/vtable slots. The remaining blocker is final source spelling for helper/member names and the declarations that regenerate the compiler thunks.
