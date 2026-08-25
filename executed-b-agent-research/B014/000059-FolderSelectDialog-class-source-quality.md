** TARGET-REPORT-UID:000059 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000059 FolderSelectDialog Class Source-Quality Reanalysis

Agent: B014
Assignment: B014 report-only first pass
Date: 2026-06-19

Target: [UID:000059] `by-class/FolderSelectDialog.md`
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\000059-FolderSelectDialog-class-source-quality.md`

Report-only compliance: this pass does not edit any `by-*` documentation file and does not edit `by-memory/-coverage-report.md`. The only intended writes are this report and `tools/leaser/Agents/Agent-B014/notes.md`.

## Executive Recommendation

[UID:000059] `FolderSelectDialog` is source-quality enough for class-level C++ scaffolding now, but its method-body C++ should wait until the aggregate method island [UID:000154] is split into exact children. The class owner/emitter should remain [UID:0000JF] `FolderSelectDialog` in `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Recommended target metadata after callback implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000JF`
- `EMITTER_UIDS:0000JF`
- Keep generated destination `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

The previous blockers are now either resolved or narrowed:

- The class owns a modal folder picker dialog, not a MusicControlDialog method body and not a FolderTreePane control body.
- `this+0x1fc` should be described as inherited `DialogPane` control-manager/list infrastructure, not a dedicated `FolderSelectDialog` data member.
- `this+0x26c` is best named `m_folderTreePane`.
- `this+0x270` is best named `m_resultCallback` or `m_selectionCallback`; it is an owned function-object callback pointer that receives the selected/empty folder string.
- `0x004b1a00-0x004b1b05` is a real FolderSelectDialog drive-list population helper with no live inbound route in the checked binary. It should stay with FolderSelectDialog, but formal callable method-body emission should be deferred or explicitly marked retained/no-entry after child split.
- The two drive-root data items are file-owned by FolderSelectDialog: [UID:0003BG] is the read-only `L"X:\\"` literal; [UID:00027D] is the mutable file/static drive-root buffer.
- Destructor labels that name `boost::exception` or `TransferReplyAlert` are generated/decompiler owner pollution. The source object is `FolderSelectDialog::~FolderSelectDialog()` plus compiler-generated adjustor/scalar-deleting destructor forms.

## Evidence Checked

Documentation checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B014/goal.md`
- `by-class/FolderSelectDialog.md`
- `by-file/FolderSelectDialog.md`
- `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`
- `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`
- `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`
- `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`
- `by-class/FolderTreePane.md`
- `by-file/FolderTreePane.md`
- `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`
- `by-class/MusicControlDialog.md`
- `by-file/MusicControlDialog.md`
- `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`
- `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`
- `by-type/by-struct/DialogPaneLayout.md`
- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`
- `by-memory/0x00516ff0-0x0051706b.StringMenuItemConstructor.md`
- `by-memory/0x00517070-0x005170ba.StringMenuItemCopyText.md`
- `by-project-structure/proposed-source-tree.md`
- `by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md`
- `wave3_data_issues.md`
- Current rows in `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-memory/-coverage-report.md`, and `auto-generated/-coverage-report.md`.

Binary/export evidence checked:

- Cached function export `resources/exported_data/functions/0x004b1590.json`.
- Cached function export `resources/exported_data/functions/0x004b1920.json`.
- Cached function export `resources/exported_data/functions/0x004b1a00.json`.
- Cached function export `resources/exported_data/functions/0x004b1b20.json`.
- Raw PE bytes from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Raw PE section map: image base `0x400000`; `.text` VA `0x401000`, vsize `0x20b4ac`; `.rdata` VA `0x60d000`, vsize `0x5f0be`; `.data` VA `0x66d000`, vsize `0x2fe24`.
- Raw absolute-reference and rel32 call/jump scans for the target function starts, vtables, drive-root literal, mutable drive-root buffer, and key FolderTreePane helper calls.
- Scoped validator baseline for the target class page.

## Boundary And Reachability Recheck

The class-level target [UID:000059] points to aggregate memory [UID:000154] `0x004b1590-0x004b1b87.FolderSelectDialog`. The aggregate is source-authored but mixes constructor, EH cleanup/padding, virtual command handling, a retained/no-entry helper, adjustor thunks, and a scalar-deleting destructor. Exact boundaries from PE bytes and cached IDA/Ghidra exports:

- `0x004b1585-0x004b1590`: eleven bytes of `0xcc` before the constructor.
- `0x004b1590-0x004b18d6`: constructor body, size `0x346`, returns with `ret 8`.
- `0x004b18d6-0x004b1920`: constructor EH cleanup/vtable cleanup tail and padding. It contains real cleanup instructions followed by `0xcc`; do not model as an independent source method.
- `0x004b1920-0x004b1a00`: `FolderSelectDialog::OnCommand`, size `0xe0`, vtable slot referenced at `0x0061a4a4`.
- `0x004b1a00-0x004b1b05`: drive-list population helper, size `0x105`, real function prologue/SEH/cookie, no direct caller or pointer reference found.
- `0x004b1b05-0x004b1b10`: adjustor thunk, bytes subtract `0xa0` from `this` and jump to `0x004b1b20`.
- `0x004b1b10-0x004b1b1b`: adjustor thunk, bytes subtract `0xa4` from `this` and jump to `0x004b1b20`.
- `0x004b1b1b-0x004b1b20`: five bytes of `0xcc`.
- `0x004b1b20-0x004b1b87`: scalar-deleting destructor body, size `0x67`, returns with `ret 4`.
- `0x004b1b87-0x004b1b90`: nine bytes of `0xcc`; next function is `FolderTreePane::FolderTreePane`.

Reachability and data references:

- Constructor `0x004b1590` has one rel32 caller at `0x0052986d` in MusicControlDialog command handling.
- `OnCommand` `0x004b1920` has no normal call xref; it is reached through vtable slot `0x0061a4a4`.
- Drive-list helper `0x004b1a00` has zero rel32 and zero absolute inbound references in the checked PE. It is not a vtable slot.
- Destructor `0x004b1b20` is reached by the two adjustor thunks at `0x004b1b05` and `0x004b1b10`, and by vtable data at `0x0061a45c`.
- Vtable heads/data references: `0x0061a45c -> 0x004b1b20`, `0x0061a4a4 -> 0x004b1920`, `0x0061a4bc -> 0x004b1b05`, `0x0061a4ec -> 0x004b1b10`.
- Vtable table pointers are written by constructor/cleanup/destructor at `0x004b1603`, `0x004b160d`, `0x004b1617`, `0x004b18eb`, `0x004b18f5`, `0x004b18ff`, `0x004b1b2e`, `0x004b1b38`, `0x004b1b42`.
- Read-only drive-root literal [UID:0003BG] `0x0061a4f4-0x0061a4fc` has one checked code reference at `0x004b173b`.
- Mutable drive-root buffer [UID:00027D] `0x0066da88-0x0066da90` has four checked references: constructor write/use at `0x004b1841` and `0x004b185c`, helper write/use at `0x004b1a8d` and `0x004b1aab`.
- `FolderTreePane::FolderTreePane` `0x004b1b90` is called at `0x004b178b`.
- `FolderTreePane::SelectNodeByPath` `0x004b2730` is called at `0x004b18b1`.
- `FolderTreePane::BuildSelectedPath`/selected-path construction `0x004b3090` is called at `0x004b197f`.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Best-supported owner: [UID:0000JF] `FolderSelectDialog`, source `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Evidence:

- [UID:000059] already has `CANONICAL_OWNER:0000JF`, `RECONSTRUCTABLE:TRUE`, and emitter `0000JF`.
- [UID:0000JF] file documentation assigns `NexusTK/ui/dialogs/FolderSelectDialog.cpp` and already owns the dialog, drive-list population, callback dispatch, vtable/data children, and drive-root buffer.
- [UID:0003MD] MusicControlDialog command handling constructs this dialog from command id `7`, but that is caller evidence, not ownership evidence.
- [UID:0000JG] `FolderTreePane` owns the reusable tree control beginning at `0x004b1b90`; the dialog constructs and hosts it but does not own the tree-control source body.

Rejected alternatives:

- Fold into `MusicControlDialog`: rejected because MusicControlDialog only allocates the dialog and supplies a concrete callback. FolderSelectDialog has its own vtables, constructor, command handling, destructor, and data children.
- Fold FolderTreePane into FolderSelectDialog: rejected because FolderTreePane has a separate class/file assignment, reusable tree/template helpers, a substantial method island beginning at `0x004b1b90`, and source-tree docs place it under `NexusTK/ui/controls/FolderTreePane.cpp`.
- Treat `0x004b1a00` as a compiler thunk: rejected because it has a normal function prologue, SEH/cookie setup, WinAPI calls, control-list calls, allocation, and a source-shaped loop. The unresolved part is only its inbound route.

### Constructor Signature And Callback Type

Best source-facing constructor:

```cpp
FolderSelectDialog::FolderSelectDialog(FolderSelectCallback *callback,
                                       const wchar_t *initialPath);
```

Where `FolderSelectCallback` should be tied to the existing FunctionObjects documentation. The most precise project-level spelling must come from the canonical FunctionObjects support pages; for this class report the safest source-facing role is an owning pointer to a function object that receives a selected path string.

Recommended placeholder until type spelling is synchronized:

```cpp
using FolderSelectCallback = FunctionObjectT<SimpleUString>;
```

or, if the project standard uses a base callback interface:

```cpp
using FolderSelectCallback = FunctionObject<void (const SimpleUString &)>;
```

Evidence:

- Constructor decompilation stores parameter `a2` at `this+0x270`.
- Destructor calls the callback object's virtual destructor with deleting flag `1`, so FolderSelectDialog owns the callback pointer.
- `OnCommand` invokes callback virtual slot `+12`.
- MusicControlDialog command id `7` allocates a 24-byte plain member function object for `MusicControlDialog::FolderPathSelected` at `0x00529ee0`, then passes that object to FolderSelectDialog.
- On OK, FolderSelectDialog builds a selected path through FolderTreePane helper `0x004b3090` and passes it to the callback.
- On cancel, FolderSelectDialog constructs an empty string object via `0x00582b20` and passes that to the callback.

Rejected names:

- `FolderSelectDialog::Show(currentPath, callback)` as a proven binary method: rejected for this class source pass. That shape appears as a higher-level draft in MusicControlDialog docs, but the checked binary route is allocation plus constructor call at `0x0052986d`.
- `MusicControlDialogCallback *` as the class field type: rejected because the caller supplies one concrete callback type, but the dialog behavior depends only on a string callback base/interface.

### Field And Member Name Recommendations

Best-supported class fields:

- `this+0x26c`: `FolderTreePane *m_folderTreePane`.
- `this+0x270`: `FolderSelectCallback *m_resultCallback` or `FolderSelectCallback *m_selectionCallback`; prefer `m_resultCallback` because both OK and cancel dispatch a result string.

Inherited/base field use:

- `this+0x1fc` should not be presented as a dedicated FolderSelectDialog field. [UID:DialogPaneLayout] describes `DialogPane+0x1fc` as the inherited control manager/list pointer. FolderSelectDialog uses that inherited manager to retrieve the drive-list control at control id/index `0`.
- Source-friendly local/helper name for the actual drive-list control: `driveList`, `GetDriveListControl()`, or `m_driveListControl` only if later constructor evidence proves a stored member exists. Current binary evidence supports a managed child control, not a separate class field.

Evidence:

- Constructor stores the `FolderTreePane` allocation at `this+0x26c`.
- Constructor stores the callback at `this+0x270`.
- Constructor and drive helper obtain a control through `this+0x1fc` and virtual/control-list calls rather than loading a separate `this+` field dedicated to the drive list.
- `OnCommand` drive notification branch uses the control manager to read the selected drive-list item, copies its label with `StringMenuItemCopyText`, and sends it to `FolderTreePane::SetRootNodeName`.

Rejected/generated names:

- `field_26C`, `mbr_26c`, `field_270`, `mbr_270`: replace with `m_folderTreePane` and `m_resultCallback`.
- `asc_66DA88`: replace with a file/static drive-root buffer name, preferably `s_driveRootBuffer` or `s_driveRootName`.
- Any generated `ChattingColorPane`, `TransferReplyAlert`, or `boost::exception` names in this area are owner pollution and must not be propagated into FolderSelectDialog source.

### Drive-List Helper Liveness And Source Shape

Best source-facing name: `FolderSelectDialog::PopulateDriveList()`.

Alternative acceptable names: `RefreshDriveList()`, `BuildDriveList()`, or file-local `PopulateDriveList(FolderSelectDialog *)`. Prefer `PopulateDriveList()` because the function appends logical drive menu entries and selects the current drive; it does not respond to later drive changes except by rebuilding the list.

Evidence:

- `0x004b1a00` has a normal stack frame, EH/cookie setup, and real body, not thunk/padding.
- It obtains the inherited control manager/list through `this+0x1fc`.
- It calls `GetLogicalDrives`.
- It calls `GetCurrentDirectoryA`.
- It computes the current drive with `_toupper`.
- It loops over 32 possible drive bits.
- It writes the first wide character of `s_driveRootBuffer`/`asc_66DA88`.
- It allocates a `StringMenuItem` and calls `StringMenuItem::StringMenuItem`.
- It appends the item to the drive-list control.
- It selects the current drive using count/get/set helpers.
- It duplicates the constructor's drive-list population sequence.
- It has zero checked rel32 inbound references and zero checked abs32 pointer references.

Best inference:

- Keep this function assigned to FolderSelectDialog source. The helper is source-authored or source-shaped retained code, even though the checked binary has no direct route to it.
- Do not classify it as compiler-generated.
- Do not use it as proof that constructor source definitely calls `PopulateDriveList()`, because constructor contains an in-place duplicate drive loop and no call to `0x004b1a00`.
- For formal C++ body emission, either split it as a retained no-entry helper with an explicit no-caller note, or defer the helper body until an implementation callback can decide whether to emit a private method declaration without a call site.

Rejected alternatives:

- "Dead padding": rejected by real API/control/menu work.
- "Virtual method": rejected by zero vtable slot evidence.
- "DialogPane base helper": rejected because it writes FolderSelectDialog drive-root buffer, allocates drive-list `StringMenuItem` entries, and duplicates FolderSelectDialog constructor behavior.

### FolderTreePane Source Split

Best split:

- `FolderSelectDialog.cpp` owns the dialog, drive-list control setup, callback handling, drive-root data, and OK/cancel/drive-change command routing.
- `FolderTreePane.cpp` owns the reusable filesystem tree pane, tree/vector/template helpers, filesystem enumeration, sorting, painting, selected iterator, selected-path construction, `SetRootNodeName`, `SelectNodeByPath`, and `SetSelection`.

Evidence:

- Constructor call at `0x004b178b` creates a `FolderTreePane` of size `0x17c` and stores it at `this+0x26c`.
- [UID:0000JG] and [UID:0000JF] already separate `FolderTreePane.cpp` and `FolderSelectDialog.cpp` in proposed source-tree docs.
- `FolderTreePane` docs identify internal fields: embedded tree at `+0x130`, selected iterator at `+0x170`, icon/tile context at `+0x148`.
- `OnCommand` only calls `FolderTreePane::BuildSelectedPath` and `FolderTreePane::SetRootNodeName`; it does not inline tree ownership.
- The generated `FolderTreePane` area is known polluted with unrelated chat/surface/system-message content. That pollution must not be allowed to pull FolderTreePane or unrelated helpers back into FolderSelectDialog.

Rejected alternative:

- A monolithic `FolderSelectDialogAndTree.cpp`: rejected because the observed object model, file docs, and proposed source tree support a dialog/control split.

### Drive-Root Data Ownership

Best names:

- [UID:0003BG] `0x0061a4f4-0x0061a4fc`: `kDefaultDriveRootLiteral` or simply source literal `L"X:\\"`.
- [UID:00027D] `0x0066da88-0x0066da90`: `s_driveRootBuffer` or `s_driveRootName`; prefer `s_driveRootBuffer` because constructor/helper mutate the first character.

Ownership:

- [UID:0003BG] and [UID:00027D] should stay under [UID:0000JF] `FolderSelectDialog`, not FolderTreePane and not MusicControlDialog.

Evidence:

- [UID:0003BG] bytes are `58 00 3a 00 5c 00 00 00`, UTF-16 `X:\`, and only the constructor reads it at `0x004b173b`.
- [UID:00027D] starts with the same UTF-16 `X:\` content and is mutated at constructor/helper write sites.
- The mutable buffer is used as the string argument when constructing drive-list menu items.
- Current by-memory coverage row for [UID:00027D] is stale because it says the item remains unassigned due to a lower parent gate. That should be repaired once this report is accepted, because [UID:0000JF] now clears the assignment threshold and is the strongest owner.

### Destructor, Thunks, And Generated Labels

Best source-facing destructor:

```cpp
FolderSelectDialog::~FolderSelectDialog();
```

Compiler-generated/non-source forms:

- `0x004b1b05`: secondary adjustor thunk, subtracts `0xa0`, jumps to scalar-deleting destructor.
- `0x004b1b10`: tertiary adjustor thunk, subtracts `0xa4`, jumps to scalar-deleting destructor.
- `0x004b1b20`: scalar-deleting destructor body. It restores vtables, deletes the callback if present, invokes DialogPane cleanup, and conditionally releases object memory according to the deleting flag.

Evidence:

- Vtable slots point at the destructor body and thunks.
- Destructor restores all three vtable pointers.
- Destructor reads `this+0x270` and invokes callback virtual destructor with deleting flag `1`.
- It calls a base cleanup currently mislabeled in generated/decompiler output; support docs identify this as DialogPane cleanup/destruction context, not `boost::exception` and not `TransferReplyAlert`.

Rejected labels:

- `boost::exception::~exception`: decompiler type pollution.
- `TransferReplyAlert::~DialogPane` or `TransferReplyAlert` base ownership: generated owner pollution.
- Handwritten thunk source: rejected because the thunks are compiler-generated adjustor/scalar-deleting artifacts.

### Helper Name Recommendations

Names that are high-confidence from support docs and local evidence:

- `0x0049d8a0`: `DialogPane::DialogPane` or DialogPane constructor helper.
- `0x0049dc10`: `DialogPaneEnsureControlManagerAndAdd`.
- `0x0049ddd0`: `DialogPaneSetPendingControl`.
- `0x0049dfd0`: DialogPane create/layout/show-on-layer helper; use the canonical existing support-doc name until final source naming is accepted.
- `0x0049e190`: DialogPane show/open helper; use the canonical existing support-doc name.
- `0x0049dad0`: Dialog close/remove helper; source-facing role `CloseDialog` or `DialogPane::Close`.
- `0x004b1b90`: `FolderTreePane::FolderTreePane`.
- `0x004b25e0`: `FolderTreePane::SetRootNodeName`.
- `0x004b2730`: `FolderTreePane::SelectNodeByPath`.
- `0x004b3090`: `FolderTreePane::BuildSelectedPath` or `FolderTreePane::GetSelectedPath`; prefer the existing support-doc name if already standardized.
- `0x00516ff0`: `StringMenuItem::StringMenuItem`.
- `0x00517070`: `StringMenuItem::CopyText` or `StringMenuItemCopyText`.
- `0x00582b20`: empty/simple string constructor used for cancel result.
- `0x00582b70`: string destructor for temporary result.

Names still needing support-doc synchronization before final C++:

- The exact concrete class of the drive-list child control allocated in the constructor. Existing decompilation names point toward `PopupMenuControlPane`/menu control behavior, but this report should not invent a final class name beyond `driveList`/drive-list control unless the control-pane docs have accepted the exact type.
- The exact spelling of the callback base/interface template. The behavior and ownership are resolved; the final type spelling must match FunctionObjects support docs.
- The exact source names for `0x00498170`, `0x00498190`, `0x00498180`, `0x004981a0`, and `0x00498220`. Their roles are append item, item count, get item by index, selected index, and set selected index respectively; final names should be synchronized with the owning menu/control list support docs.

### Generated-Source Pollution Rejections

Reject these as source-quality evidence for this class:

- Generated `ChattingColorPane` or Chatting color names in MusicControl/FolderSelect context.
- Generated `TransferReplyAlert` labels attached to DialogPane cleanup/destruction.
- Generated `boost::exception` type names on the FolderSelectDialog destructor.
- Generated `class_FolderTreePane.cpp` content that pulls in chat, surface, help, or system-message behavior.
- Raw names `sub_4B1A00`, `FUN_004b1a00`, `asc_66DA88`, `mbr_26c`, `mbr_270`, or `field_1fc` as final documentation/source names.

### Open-Question Closure

Callback type exact spelling:

- Closed enough for ownership and class layout: it is an owned string-result function object stored at `+0x270`, destroyed by FolderSelectDialog, and invoked through virtual slot `+12`.
- Not safe to freeze to a C++ template spelling in this class report alone. Use `FolderSelectCallback` alias in first-draft class C++ and link to FunctionObjects support docs for canonical spelling.

Drive-list field:

- Closed: `+0x1fc` is inherited DialogPane control-manager/list infrastructure. A direct `m_driveList` field is not proven. Use local/helper name `driveList` for the child control obtained through the manager.

Drive-list helper route:

- Closed as no-entry in the checked binary: PE rel32 and abs32 scans found no inbound route; IDA cached xrefs report no callers. The helper is still source-shaped and should remain documented under FolderSelectDialog.
- Implementation decision remains whether to split it as a retained private helper with no call site or keep it as evidence-only until a later source pass.

FolderTreePane split:

- Closed: keep separate under [UID:0000JG] and `NexusTK/ui/controls/FolderTreePane.cpp`.

Destructor labels:

- Closed: source destructor belongs to FolderSelectDialog; thunks are compiler-generated; generated labels naming unrelated classes are pollution.

First-draft method bodies:

- Eligible in principle, but defer formal method-body emission until [UID:000154] child split. The class page can safely receive class-level declarations and field names now.

## First-Draft C++ Recommendation

Recommendation: emit class-level first-draft C++ for [UID:000059] now, but do not emit full method bodies from the unsplit aggregate [UID:000154]. Put method bodies in exact method children after split, or keep them as documented pseudocode in [UID:000154] until split is accepted.

Reason:

- [UID:000059] passes the B-agent C++ readiness gate: reconstructable true, `(85 + 86) / 2 = 85.5`, and emitter route [UID:0000JF] exists.
- Class docs are the correct place for type/member declarations, source split, and child relationships.
- The aggregate method island contains multiple functions plus compiler artifacts. Emitting formal method bodies directly from the aggregate risks mixing constructor body, cleanup tail, no-entry helper, thunks, and destructor.

Class-level draft suitable for target incorporation after callback acceptance:

```cpp
// Placeholder alias. Replace with the canonical FunctionObjects spelling.
using FolderSelectCallback = FunctionObjectT<SimpleUString>;

class FolderSelectDialog : public DialogPane
{
public:
    FolderSelectDialog(FolderSelectCallback *callback, const wchar_t *initialPath);
    virtual ~FolderSelectDialog();

    virtual void OnCommand(int commandId, int notifyCode);

private:
    void PopulateDriveList(); // retained helper at 0x004b1a00; no inbound route found.

    FolderTreePane *m_folderTreePane;          // this+0x26c
    FolderSelectCallback *m_resultCallback;    // this+0x270, owned
};
```

Method-body notes for later child implementation:

- Constructor body should build DialogPane controls, create the drive-list child, create OK/cancel controls, create `FolderTreePane` with a current-drive root, populate the drive-list, set pending control id `2`, and optionally select `initialPath`.
- `OnCommand(1, *)` is OK: build selected path from `m_folderTreePane`, invoke `m_resultCallback`, and close the dialog.
- `OnCommand(2, *)` is cancel: invoke `m_resultCallback` with an empty string and close the dialog.
- `OnCommand(0, 10)` is drive-list selection change: copy the selected drive-list item text and call `FolderTreePane::SetRootNodeName`.
- `PopulateDriveList()` loops through `GetLogicalDrives()`, formats `s_driveRootBuffer[0] = L'A' + driveIndex`, appends `StringMenuItem` entries, and selects the current drive. Since no inbound route exists, do not invent a constructor call to this helper unless implementation deliberately models it as retained no-entry code.
- Destructor body should delete/destroy `m_resultCallback`. DialogPane/base cleanup and scalar delete flag handling are compiler-generated around the source destructor.

## Score Recommendation

Recommended [UID:000059] target score: `88/90`.

Justification:

- Ownership/source placement is now strong: FolderSelectDialog stays in [UID:0000JF], not MusicControlDialog and not FolderTreePane.
- Exact class fields are mostly resolved: `m_folderTreePane` and `m_resultCallback` are supported by direct stores/uses; `+0x1fc` is corrected to inherited DialogPane control infrastructure.
- Callback behavior is resolved at the semantic level: owned function object, selected/empty path result, concrete MusicControlDialog callback only at caller side.
- Drive-root data ownership is resolved.
- Destructor/thunk/generated-label pollution is resolved.
- Drive helper `0x004b1a00` is correctly classified as source-shaped/no-entry, not ignored or compiler-only.

Why not higher:

- The drive-list helper's source route remains no-entry in the checked binary, so formal source shape is still a policy decision.
- The exact callback template/interface spelling must be synchronized with FunctionObjects support docs.
- The exact drive-list child control type and menu/control helper names need support-doc alignment before final method-body C++.
- [UID:000154] should be split before formal method-body C++.

Recommended support score adjustments if accepted:

- [UID:0000JF] `FolderSelectDialog` file: `87/90` or `88/90`, because file ownership and support data are now stronger but method split is still pending.
- [UID:000154] aggregate method island: `88/91` if retained as aggregate evidence, or split into children and let exact constructor/OnCommand/destructor children carry method-body C++.
- [UID:00027D] mutable drive-root buffer: `87/92`, because owner assignment is now clear and the existing coverage text is stale.
- [UID:00025C] mixed FolderSelect/FolderTree read-only aggregate: leave non-emitting/mixed or split-only; do not let it emit direct C++.

## Implementation Checklist For Later Callback

Target [UID:000059] `by-class/FolderSelectDialog.md`:

- Update metadata to recommended `88/90` if supervisor accepts.
- Add or expand `## Heuristic / Inference Reanalysis And Validation`.
- Replace generated/raw field names with `m_folderTreePane` and `m_resultCallback`.
- Clarify that `+0x1fc` is inherited DialogPane control-manager/list infrastructure, not a dedicated class field.
- Add class-level C++ declarations with `FolderSelectCallback` placeholder/alias and `[[CHILDREN]]`.
- Document that method bodies should come from split children of [UID:000154].
- Record rejected generated labels: `boost::exception`, `TransferReplyAlert`, `ChattingColorPane`, `asc_66DA88`, `sub_4B1A00`.

Support [UID:0000JF] `by-file/FolderSelectDialog.md`:

- Sync source placement and score.
- Add the best names `m_folderTreePane`, `m_resultCallback`, `s_driveRootBuffer`, `PopulateDriveList`.
- State that drive helper `0x004b1a00` is source-shaped but no-entry.
- State that FolderTreePane remains separate under [UID:0000JG].
- State that MusicControlDialog owns only the concrete caller/callback binding.

Support [UID:000154] `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`:

- Prefer splitting into exact children:
  - constructor `0x004b1590-0x004b18d6`
  - constructor EH cleanup/padding `0x004b18d6-0x004b1920` as compiler/artifact note
  - `OnCommand` `0x004b1920-0x004b1a00`
  - retained/no-entry `PopulateDriveList` helper `0x004b1a00-0x004b1b05`
  - adjustor thunks `0x004b1b05-0x004b1b1b`
  - scalar-deleting destructor `0x004b1b20-0x004b1b87`
- If not split immediately, keep aggregate C++ blank and add no-code proof for method bodies until split.
- Add raw PE references and exact no-entry proof for `0x004b1a00`.

Support [UID:0003BF] `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`:

- Keep non-handwritten vtable data ownership under [UID:000059].
- Ensure slots name `FolderSelectDialog::~FolderSelectDialog`, `FolderSelectDialog::OnCommand`, and adjustor thunks without unrelated class labels.

Support [UID:0003BG] `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`:

- Name as `kDefaultDriveRootLiteral` or source literal `L"X:\\"`.
- Keep owner [UID:0000JF].

Support [UID:00027D] `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`:

- Replace stale "unassigned because parent below gate" language.
- Name as `s_driveRootBuffer` or `s_driveRootName`.
- Keep owner [UID:0000JF].
- Mention both constructor and helper write/use xrefs.

Support [UID:0000JG]/[UID:00000K] FolderTreePane docs:

- Sync the source split note only; do not move FolderTreePane helpers to FolderSelectDialog.
- Confirm `FolderTreePane::SetRootNodeName`, `SelectNodeByPath`, and `BuildSelectedPath` names used by FolderSelectDialog.

Support MusicControlDialog/FunctionObjects docs:

- Keep `MusicControlDialog` as caller and concrete callback owner only.
- If MusicControlDialog draft uses `FolderSelectDialog::Show`, mark it as source-level convenience unless a separate wrapper is proven. The checked route is allocation plus constructor.
- Keep the plain member function object wrapper owned by FunctionObjects/MusicControlDialog support docs, not FolderSelectDialog.

Generated docs and auto-generated outputs:

- Do not manually edit `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- After accepted by-* edits, run validator regeneration and confirm the generated root remains `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Do not copy generated polluted labels back into source-quality docs.

Supervisor-owned coverage:

- Update `by-class/-coverage-report.md` row for [UID:000059].
- Update `by-file/-coverage-report.md` row for [UID:0000JF] if supervisor accepts file-score change.
- Update `by-memory/-coverage-report.md` rows for [UID:000154], [UID:00027D], and possibly mixed aggregate [UID:00025C] if support docs are updated.
- Do not let B014 edit coverage directly during this report-only pass.

## Exact Supervisor-Owned Coverage Row Text

Target by-class replacement row:

```md
- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality reanalysis resolves the constructor/callback signature, inherited control-manager versus drive-list field distinction, FolderTreePane member/callback fields, drive-list helper liveness/no-route status, drive-root literal/buffer ownership, destructor/thunk label pollution, MusicControl callback flow, generated-source pollution, and FolderSelectDialog/FolderTreePane source split; keep owner/emitter [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), add class-level first-draft C++ with child route, and split [UID:000154] before formal method-body C++.
```

Recommended by-file support row if [UID:0000JF] is updated:

```md
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality reanalysis keeps `NexusTK/ui/dialogs/FolderSelectDialog.cpp` as the owner for the modal folder picker, resolves callback ownership, `m_folderTreePane`/`m_resultCallback`, inherited drive-list control-manager access, `PopulateDriveList` no-entry helper status, drive-root literal/buffer data, destructor/thunk pollution, and the FolderTreePane/MusicControl split; method-body C++ should follow exact [UID:000154] child splits.
```

Recommended by-memory support row for [UID:000154] if the aggregate remains:

```md
    - [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md) : reconstructable : 88% : very strong : B014 2026-06-19 raw PE/IDA source-quality reanalysis confirms the exact source-authored dialog island, constructor caller at `0x0052986d`, OnCommand vtable slot `0x0061a4a4`, constructor body `0x004b1590-0x004b18d6` plus EH cleanup/padding through `0x004b1920`, OnCommand `0x004b1920-0x004b1a00`, retained no-entry drive helper `0x004b1a00-0x004b1b05` with zero abs32/rel32 inbound route, compiler adjustor thunks `0x004b1b05`/`0x004b1b10`, scalar deleting destructor `0x004b1b20-0x004b1b87`, fields `+0x26c`/`+0x270`, inherited control-manager use at `+0x1fc`, drive-root data, and recommends splitting exact method/helper children before formal method C++.
```

Recommended by-memory support row for [UID:00027D]:

```md
    - [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) 0x0066da88-0x0066da90 | mutable wide-character buffer | FolderSelectDriveRootBuffer : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis assigns this file-local/static mutable `FolderSelectDialog` drive-root buffer to [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md); raw bytes are UTF-16 `X:\`, constructor and retained drive helper mutate the first WCHAR at `0x004b1841`/`0x004b1a8d` and pass the buffer at `0x004b185c`/`0x004b1aab`, so source should name it `s_driveRootBuffer`/`s_driveRootName` and keep it out of FolderTreePane or MusicControlDialog.
```

Recommended by-memory note for mixed [UID:00025C] if touched:

```md
    - [UID:00025C][0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData](by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md) 0x0061a45c-0x0061a5c4 | vtable/string/table-data | FolderSelectTreeReadOnlyData : ignored/non-emitting : 86% : very strong : B014 2026-06-19 follow-up should treat this as a mixed FolderSelectDialog/FolderTreePane aggregate only; exact children [UID:0003BF], [UID:0003BG], and neighboring FolderTreePane RTTI/vtable/string items carry ownership, while the aggregate must not emit C++ or blur the FolderSelectDialog/FolderTreePane source split.
```

Current exact rows observed before this report:

```md
- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) : reconstructable : 85% : strong : Modal folder picker attached to FolderSelectDialog source; method boundaries, MusicControl caller, callback flow, drive helper caveat, exact vtable child, read-only drive-root string, mutable drive-root buffer xrefs, touched offsets, generated alias cleanup, and final field/helper blockers documented.
```

```md
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) : reconstructable : 86% : strong : Modal folder picker dialog with `NexusTK/ui/dialogs/` path assigned; IDA MCP rechecked method boundaries, MusicControl caller, callback flow, drive helper, vtable/string children, mutable drive-root buffer child [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), destructor thunks, and FolderTreePane split caveat.
```

```md
    - [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md) : reconstructable : 76% : strong : Source-authored folder-picker dialog island; 2026-06-01 IDA MCP recheck confirms function boundaries, music-dialog caller, drive-list helper behavior, and the no-direct-caller caveat for `0x004b1a00`.
```

## Exact Validator Commands

Baseline command already run:

> Executable block R001 was removed from this report and preserved verbatim in [000059-FolderSelectDialog-class-source-quality-removed.md](000059-FolderSelectDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Baseline result:

- Exit code: `0`.
- Mode: `file`.
- Apply: `False`.
- Scanned markdown files: `1`.
- `ok: 1`.
- Target check: `ok 000059 by-class/FolderSelectDialog.md UID header exists`.
- Dry-run/autogen result included `autogen_cpp_noop 0000JF auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp unchanged`.
- No target-specific validator failure was observed.
- Global dry-run output still reported existing non-target counters such as generated children fallback/conflict categories; those are not blockers for this target report.

Recommended callback validation after accepted edits:

> Executable block R002 was removed from this report and preserved verbatim in [000059-FolderSelectDialog-class-source-quality-removed.md](000059-FolderSelectDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:000154] is split, add validator runs for each new exact child file created by the implementation callback, especially constructor, `OnCommand`, retained drive helper, and destructor children.

## Final Report-Only Status

This report is ready for supervisor review. No by-* documentation files were edited during this pass. `by-memory/-coverage-report.md` was not edited during this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/000059-FolderSelectDialog-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"000059"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000059-FolderSelectDialog-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/000059-FolderSelectDialog-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000059"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
