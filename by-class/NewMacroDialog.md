*** UID:000094 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewMacroDialog : public DialogPane
{
public:
    NewMacroDialog();
    virtual ~NewMacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);

private:
    void SaveMacroEntries();
    void LoadMacroPage(int page);

    int m_currentPage;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewMacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address docs: split parent [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md), with exact method children [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md), [UID:00049K][0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor](by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md), [UID:00049L][0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand](by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand.md), [UID:00049M][0x0053f170-0x0053f179.NewMacroDialogSetHoverControl](by-memory/0x0053f170-0x0053f179.NewMacroDialogSetHoverControl.md), [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md), and [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md)
- Current recovered file: `source-3/simroot_v2/class_NewMacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`NewMacroDialog` is the newer paged macro setup dialog. It owns page switching, hover-control forwarding, compact macro entry load/save, and construction of `NewMacroEditControlPane` rows. Construction supplies initial signed shortcut ordinals `0..9`; `LoadMacroPage` computes `page * 10 + row` and calls the row control's public `SetShortcutIndex(int)` before SetKey, SetSpellMode, and Refresh.

It is part of the [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) source family rather than an option-pane or spell-inventory source. The dialog edits compact shortcut records through [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) rows and [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_compactShortcutRecords[20]` at `+0x28f29c`. The later integrated [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) table at `+0x28f2ec` belongs to `IntegrateMacroDialog` and runtime macro execution, not to these exact NewMacroDialog save/load methods.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md) | `0x0053ed90-0x0053f07f` | Builds the newer macro dialog, current-page field `+0x26c`, first-page compact-record rows, OK button, and page buttons. |
| [UID:00049K][0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor](by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md) | `0x0053f080-0x0053f09f` | Empty source destructor body; binary vtable reset/base teardown is compiler output. |
| [UID:00049L][0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand](by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand.md) | `0x0053f0a0-0x0053f166` | Primary `+0x48` `OnControlCommand(int,int)` override handling OK control `1` and page controls `12` and `13`. |
| [UID:00049M][0x0053f170-0x0053f179.NewMacroDialogSetHoverControl](by-memory/0x0053f170-0x0053f179.NewMacroDialogSetHoverControl.md) | `0x0053f170-0x0053f179` | Primary `+0x58` override forwarding to [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md). |
| [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md) | `0x0053f180-0x0053f203` | Writes current page row key/mode into `m_compactShortcutRecords`. |
| [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) | `0x0053f210-0x0053f2b6` | Computes signed `shortcutIndex = page * 10 + row`, then calls public `SetShortcutIndex`, SetKey, SetSpellMode, and Refresh while loading direct compact records; endpoint includes the final immediate byte. |
| scalar deleting destructor | `0x00542800-0x00542855` | Deleting destructor wrapper. |

## Evidence Notes

- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) records the exact constructor, non-deleting destructor helper, command handler, active-control helper, save, and load-page ranges for the dialog.
- The accepted UID0001DR split moved source-bearing bodies onto exact children [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md)-[UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md), and each child now contains its first-draft formal C++ block.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `NewMacroDialog` primary/secondary/tertiary vtable views at `0x00620e48-0x00620ee0`, with primary `+0x48` `OnControlCommand` and `+0x58` `SetHoverControl` slots plus compiler deleting-destructor support.
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) classifies the `0x005425f7` and `0x00542602` adjustor thunks as compiler/vtable support for `NewMacroDialog::ScalarDeletingDestructor`.
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) documents the `0x00542800-0x00542855` scalar deleting destructor wrapper and explains why the wrapper is ABI output tied to source destructor declarations, not handwritten dialog behavior.
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) now records the row-control getter/setter, page load/save accessors, and vtable/thunk evidence used by this dialog. Its complete public API includes `void SetShortcutIndex(int shortcutIndex)` because `NewMacroDialog` is a distinct caller class and no friendship route exists.
- [UID:0004A9][0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex](by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md) has exactly one direct call at `0x0053f26f` from LoadMacroPage. The caller immediately overwrites EAX at `0x0053f274`, then calls SetKey at `0x0053f27e`, SetSpellMode at `0x0053f28d`, and Refresh at `0x0053f294`, preserving the exact source order and void-return contract.
- The signed ordinal domain is `0..19`: page construction supplies `0..9`, page load computes both ten-row banks, and row paint renders number versus Ctrl-number labels. Historical record-index wording is superseded because the row member is not a retained `CompactShortcutRecord` identifier or pointer.
- A004 live IDA MCP on 2026-06-12 reconfirmed `lookup_funcs` for the constructor (`0x2ef` bytes), source destructor lowering (`0x1f` bytes), primary command override (`0xc6` bytes), primary hover forwarder (`0x9` bytes), `SaveMacroEntries` (`0x83` bytes), `LoadMacroPage` (`0xa6` bytes), and scalar deleting destructor (`0x55` bytes), plus the primary vtable slot at `0x00620e48`. Its historical `OnCommand`/`SetActiveControl` labels are superseded.
- B010 live MCP on 2026-06-28 revalidated control ids `1`, `12`, and `13`, current-page field `+0x26c`, row controls `2..11`, internal calls from `OnControlCommand` to `SaveMacroEntries`/`LoadMacroPage`, and direct storage in [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_compactShortcutRecords[20]` at `+0x28f29c`.
- Current MCP still reports no direct constructor xref to [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md). Preserve this liveness caveat; the vtable, destructor, command, row-control, and compact-storage evidence still support the documented source-shaped class.

## Score Rationale

Completion is `92` because the page now has a complete source-era declaration, exact six-child map, method ranges, primary/adjusted table identity, source/compiler destructor separation, control ids, natural `0x270` layout, row accessors, compact-record storage, and retained constructor-liveness caveat. Confidence is `94` because allocation/layout, vtable slots, helper calls, compact-record paths, and sibling interface contracts converge; exact private helper/member spellings remain inferred.

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). The complete declaration emits at position `40`, closes before `[[CHILDREN]]`, and child pages [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md)-[UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) supply the qualified method bodies without duplication.

## Layout And Source/Compiler Separation

- Allocation size is `0x270`: inherited `DialogPane` occupies `0x26c` and `int m_currentPage` closes the class naturally at `0x270`. No explicit padding or raw-layout member is required.
- The class has six source children: constructor, explicit empty virtual destructor, `OnControlCommand`, `SetHoverControl`, `SaveMacroEntries`, and `LoadMacroPage`.
- Primary `+0x48` cell `0x00620e90 -> 0x0053f0a0` and `+0x58` cell `0x00620ea0 -> 0x0053f170` establish the corrected interfaces. The latter forwards to exact base [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md).
- The source destructor declaration explains the ordinary empty body, scalar deleting wrapper `0x00542800-0x00542855`, and `+0xa0/+0xa4` adjustors. Those ABI forms, vptr stores, delete flags, raw RTTI/vtables, cookies, and SEH remain compiler output.
- Source position `40` follows IntegrateMacroEditControlPane `30` and precedes NewMacroEditControlPane `50`; the declaration is closed before child definitions.
- Historical `OnCommand` and `SetActiveControl` names are retained only in dated evidence/history, not in current source.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md)
- [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md)
- [UID:00049K][0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor](by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md)
- [UID:00049L][0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand](by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand.md)
- [UID:00049M][0x0053f170-0x0053f179.NewMacroDialogSetHoverControl](by-memory/0x0053f170-0x0053f179.NewMacroDialogSetHoverControl.md)
- [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md)
- [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-07-16 B003 UID0004A9 implementation callback:
  - Preserved `92/94`, UID0000KY owner/emitter, position `40`, complete class formal and closure, natural `0x270` layout, all six source children, explicit destructor/compiler separation, storage distinction, helper routes, and no-direct-constructor-xref caveat.
  - Added the bounded private LoadMacroPage-to-public SetShortcutIndex caller link, exact `page * 10 + row` signed `0..19` semantics, call ordering/void-return evidence, constructor `0..9` initialization, and superseded record-index history without changing score, route, or formal C++.

- 2026-07-15 B003 UID00049G callback:
  - Raised `89/91` to `92/94`, set position `40`, and installed the complete natural `0x270` declaration with class closure before `[[CHILDREN]]`.
  - Synchronized `OnControlCommand`/`SetHoverControl`, all six child routes, compact-record/page semantics, explicit source destructor cause, compiler wrapper/thunk exclusions, and the no-direct-constructor-xref caveat.

- 2026-06-28 B010 implementation callback:
  - Raised from `85/88` to `89/91`.
  - Linked exact method children [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md)-[UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) after validator UID assignment and recorded that their formal C++ blocks now own emission.
  - Corrected the direct storage dependency from `MacroHotkeyRecord` to `RegistryConfigUserProfileBlock::m_compactShortcutRecords`, added command ids `1`/`12`/`13`, current-page field `+0x26c`, and preserved the no-direct-constructor-xref caveat.
- 2026-06-12 A004 Batch 243 strict-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, and several one-byte-short method/destructor endpoints inherited from older range notes.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; kept direct parent [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md), which clears `88/85`.
  - Evidence: live IDA MCP confirmed `NewMacroDialog` constructor `0x0053ed90-0x0053f07f`, non-deleting destructor helper `0x0053f080-0x0053f09f`, `OnCommand` `0x0053f0a0-0x0053f166`, `SetActiveControl` `0x0053f170-0x0053f179`, `SaveMacroEntries` `0x0053f180-0x0053f203`, `LoadMacroPage` `0x0053f210-0x0053f2b6`, scalar deleting destructor `0x00542800-0x00542855`, and primary/secondary/tertiary vtable refs.
- 2026-05-28: Changed `LoadMacroPage` from `0x0053f210-0x0053f2b5` to `0x0053f210-0x0053f2b6`.
  - Before: the method map ended one byte before the IDA function end.
  - After: the method map includes the full function, with following alignment documented in `by-memory/-ignored.md`.
  - Evidence: IDA MCP reports `sub_53F210` as `0x0053f210-0x0053f2b6`.
- Before: completion/confidence metadata were `0/0` even though the page already contained role, method-map, vtable, and source-file documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: the page documents the newer macro dialog's ownership, active-control/page-load/save behavior, key method ranges, and vtable family; remaining gaps are detailed control layout/state fields and exact body-level reconstruction.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `72/84`, below the 80/80 parent-attachment gate, even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0053ed90`, `0x0053f080`, `0x0053f0a0`, `0x0053f170`, `0x0053f180`, `0x0053f210`, and `0x00542800`.
- 2026-06-06: Raised completion to `82` and attached `AUTOGEN_PARENT_UID:0000KY`. Evidence: the MacroDialogs parent is `88/82`; the executable range page records exact NewMacroDialog method ranges and boundary padding; the vtable page verifies NewMacroDialog vtable views and override slots; the adjustor/scalar-deleting destructor islands classify the destructor support; and NewMacroEditControlPane now documents the row-control accessor/vtable evidence used by page load/save. Confidence remains `84` because final control-field layout, command ids, and source-facing destructor declarations are still below the final-source gate.
