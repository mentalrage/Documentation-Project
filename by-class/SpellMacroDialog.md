*** UID:0000DP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellMacroDialog : public DialogPane
{
public:
    SpellMacroDialog();
    virtual ~SpellMacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellMacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address docs: split parent [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md), with exact method children [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md), [UID:00049G][0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor](by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md), [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md), and [UID:00049I][0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl](by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md)
- Current recovered file: `source-3/simroot_v2/class_SpellMacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`SpellMacroDialog` is the spell-specific macro setup dialog. It constructs ten spell macro edit controls, saves selected spell keys through its primary `+0x48` `OnControlCommand` override, and forwards primary `+0x58` hover-control changes through `SetHoverControl`.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md) | `0x0053e960-0x0053ecd0` | Builds spell macro dialog controls and ten `SpellMacroEditControlPane` rows seeded from `m_legacyShortcutText`. |
| [UID:00049G][0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor](by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md) | `0x0053ecd0-0x0053ecef` | Empty source destructor body; binary vtable reset/base teardown is compiler output. |
| [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md) | `0x0053ecf0-0x0053ed7a` | Handles OK command `1`, reads `GetSpellKey()`, writes all ten `m_legacyShortcutText` rows, closes/removes the dialog, and calls [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) only when `g_activeMapPane != NULL`. |
| [UID:00049I][0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl](by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md) | `0x0053ed80-0x0053ed89` | Primary `+0x58` override forwarding `controlId` to [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md). |
| [UID:00038H][0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor](by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md) | `0x00542a00-0x00542a55` | Compiler-generated scalar deleting wrapper covered by the virtual source destructor. |

## Evidence Notes

- A004 live IDA MCP on 2026-06-12 confirmed `lookup_funcs` sizes for constructor `0x370` / decimal `880`, source destructor lowering `0x1f`, primary `+0x48` handler `0x8a` / decimal `138`, primary `+0x58` forwarder `0x9`, and scalar deleting destructor `0x55` / decimal `85`. Historical `OnConfirm`/`SetVisible` labels from that pass are superseded by current slot/body evidence.
- `xrefs_to(0x00620dac)` ties the primary `SpellMacroDialog` vtable to constructor store `0x0053e9a1`, non-deleting destructor store `0x0053ecd0`, and scalar deleting destructor store `0x00542a06`.
- `callers(0x0053e960)` reports constructor reference `0x0053e0c6` inside [UID:00007I][MacroDialog](by-class/MacroDialog.md) / option-command macro setup flow; this supports keeping the class in [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md).
- The accepted UID0001DR split moved source-bearing bodies onto exact children [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md)-[UID:00049I][0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl](by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md), and each child now contains its first-draft formal C++ block.
- B010 live MCP on 2026-06-28 revalidated the spell constructor/handler cluster and resolved the storage route: the constructor creates ten `SpellMacroEditControlPane` rows from [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_legacyShortcutText` at `g_pConfig + 0x28e89c`; current `OnControlCommand` calls [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md) `GetSpellKey`, writes the key word and a zero terminator into those rows, and closes/removes the dialog. B005's UID0001AV pass corrected the final gate: `0x0067a764` is `g_activeMapPane`, not dirty state, and the profile write runs only while that pointer is non-null.

## Layout, RTTI, And Source Shape

- Allocation size is exactly `0x26c`, matching inherited `DialogPane` layout with no Spell-specific data member. The declaration is intentionally fieldless and does not add guessed padding or reverse-engineered offset members.
- Constructor `0x0053e960` installs primary, secondary, and tertiary Spell vtable views at `0x00620dac`, `0x00620e0c`, and `0x00620e3c`; the ordinary destructor lowering and scalar wrapper touch the same triad.
- Decorated RTTI identifies `SpellMacroDialog` and its `DialogPane` base. Primary/secondary/tertiary COL and PMD evidence supports one public source inheritance edge rather than multiple handwritten bases.
- Primary `+0x48` cell `0x00620df4 -> 0x0053ecf0` is `OnControlCommand(int,int)`. Primary `+0x58` cell `0x00620e04 -> 0x0053ed80` is protected `SetHoverControl(int)`.
- The explicit virtual destructor declaration explains the out-of-line empty source body [UID:00049G][0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor](by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md), the compiler scalar deleting wrapper [UID:00038H][0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor](by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md), and adjusted-view thunks without handwritten ABI code.
- Source order position `60` follows MacroDialog `10`, IntegrateMacroDialog `20`, IntegrateMacroEditControlPane `30`, NewMacroDialog `40`, and NewMacroEditControlPane `50`. The class closes before `[[CHILDREN]]`, so all qualified method definitions emit at namespace scope.

## Rejected Alternatives And Confidence Caps

- Spell-specific fields, allocation above `0x26c`, direct compact-record ownership, secondary source bases, raw vptr fields, and explicit alignment members are rejected by allocation/layout/constructor evidence.
- `OnConfirm`, `SetVisible`, and `SetActiveControl` are superseded descriptive aliases. The exact family primary slots establish `OnControlCommand` and `SetHoverControl`.
- Handwritten scalar flags, vptr stores, base destructor calls, delete calls, adjustor thunks, RTTI arrays, cookies, and SEH are compiler output and excluded from this declaration.
- Public constructor/destructor/command and protected hover setter are the strongest source-facing access model. Exact original access-label and constant spellings remain inferred and cap confidence below final-audit maximum without blocking code.

## Score Rationale

Completion is `92` because the class now has a complete source-era declaration, exact child UIDs and source names, fieldless `0x26c` layout proof, constructor/caller/storage behavior, primary/adjusted vtable and RTTI evidence, source-order placement, and source/compiler destructor separation. Confidence is `94` because allocation, table cells, destructor family, storage behavior, and sibling interface contracts are mutually reinforcing; only exact original access/constant spellings remain inferred.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md)
- [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md)
- [UID:00049G][0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor](by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md)
- [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md)
- [UID:00049I][0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl](by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:00038H][0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor](by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md)
- [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md)

## Changes

- 2026-07-15 B003 UID00049G callback:
  - Raised `88/91` to `92/94`, set source order position `60`, and installed the complete fieldless class declaration with the class closed before `[[CHILDREN]]`.
  - Synchronized exact `OnControlCommand`/`SetHoverControl` children, `0x26c` layout, RTTI/vtable cells, explicit source destructor cause, compiler wrapper/thunk exclusions, and historical stale-name corrections.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, metadata, and formal class block remain unchanged. Replaced the stale dirty-settings interpretation with the exact ten-row write -> close/remove -> `g_activeMapPane`-gated `SaveUserSettings` semantics.

- 2026-06-28 B010 implementation callback:
  - Raised from `85/89` to `88/91`.
  - Linked exact method children [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md)-[UID:00049I][0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl](by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md) after validator UID assignment and recorded that their formal C++ blocks now own emission.
  - Added the resolved `m_legacyShortcutText` and `GetSpellKey` save evidence from the accepted UID0001DR split.
- 2026-06-12 A004 Batch 247 strict-gate repair:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`, with method rows carrying one-byte-short half-open endpoints.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`; kept direct parent [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md), which clears `88/85`.
  - Evidence: live IDA MCP reconfirmed constructor/non-deleting destructor/confirm/visibility/scalar-deleting destructor sizes, vtable refs through `0x00620dac`, and the constructor call from the macro setup path.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `86`.
- Evidence: the page documents ownership, main range, vtable family, role, constructor/destructor/confirm/visibility/scalar-destructor map, and edit-control relationship; completion remains below high-exhaustive because detailed evidence notes and source-ready C++ are still sparse.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) because the class is `80/86` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0053e960`, `0x0053ecd0`, `0x0053ecf0`, `0x0053ed80`, and `0x00542a00`; current `callers` confirms the constructor reference at `0x0053e0c6`.
