*** UID:00007I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MacroDialog : public DialogPane
{
public:
    MacroDialog();
    virtual ~MacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MacroDialog

## Status

- Confidence: strong; the class declaration, source-owned methods, binary-only destructor wrappers, and exact fieldless `0x26c` layout are separated.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address docs: split parent [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md), with exact method children [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md), [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md), and [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md)
- Generated recovery hint: `source-3/simroot_v2/class_MacroDialog.cpp`; use as a lead only, not authority.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`MacroDialog` is the older keyboard macro setup dialog in the [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) source family. It builds the older macro setup UI and handles its OK control command by copying the edited rows back to the profile block before closing. It is opened from [UID:00009V][OptionPane](by-class/OptionPane.md) / [UID:0000M7][OptionPane](by-file/OptionPane.md) rather than being implemented inside the option-pane source itself.

The class sits at the front of the contiguous [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) executable island, before `SpellMacroDialog` and `NewMacroDialog`. The module-level file page records this as the older generation of the macro-dialog family, while the newer paged dialog and integrated macro dialog have separate class pages.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md) | `0x0053e520-0x0053e8cf` | Builds the older macro dialog, EPF/EPD resource layout, OK button, and ten text edit controls backed by `m_profileTextSlots`; both layout branches call inherited `SetHoverControl(2)` through exact base child UID0004RI. |
| [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md) | `0x0053e8d0-0x0053e8ef` | Empty source destructor body; binary vtable reset/base teardown is compiler output. |
| [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md) | `0x0053e8f0-0x0053e959` | Current source identity is `MacroDialog::OnControlCommand(int controlIndex, int notifyCode)`: command `1` reads child controls `2..11`, writes ten `m_profileTextSlots`, and closes/removes the dialog. The historical `SaveMacros` title described behavior but incorrectly hid the virtual control-handler ABI. It does not call [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md). |
| scalar deleting destructor | `0x005427a0-0x005427f5` | Deleting destructor wrapper in the shared dialog-destructor island. |

## Evidence Notes

- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) records the exact older `MacroDialog` constructor, explicit empty destructor lowering, `OnControlCommand`, and padding boundaries before `SpellMacroDialog`.
- The accepted UID0001DR split moved source-bearing bodies onto exact children [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md), [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md), and [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md); each child now contains its first-draft formal C++ block.
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) places this class in `NexusTK/ui/dialogs/MacroDialogs.cpp` and records why the implementation stays in the macro-dialog source family despite being opened by `OptionPane`.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `MacroDialog` primary, secondary, and tertiary vtable views at `0x00620d10-0x00620da8`; the primary table contains scalar deleting destructor slot `0x005427a0` and `OnControlCommand` slot `0x0053e8f0`.
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) classifies the related secondary/tertiary destructor adjustor support as compiler/vtable glue rather than handwritten macro behavior.
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) owns the scalar deleting destructor wrapper for this class; the source reconstruction should declare the destructor, not hand-port the wrapper body as feature logic.
- A004 live IDA MCP on 2026-06-12 reconfirmed `lookup_funcs` for the constructor (`0x3af` bytes), non-deleting destructor helper (`0x1f` bytes), the `0x69`-byte handler then labeled `SaveMacros`, and scalar deleting destructor (`0x55` bytes), plus constructor caller `0x0053e0f1` and the primary vtable slot at `0x00620d10`.
- B010 live MCP on 2026-06-28 revalidated the same three method ranges and resolved the body-level storage route: the constructor binds ten text controls to [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_profileTextSlots` at `g_pConfig + 0x28de9c`, and the handler then labeled `SaveMacros` copies child controls `2..11` back to those ten rows on control index `1`. B005's UID0001AV caller audit confirms that this method then closes/removes the pane but has no SaveUserSettings call; the former dirty-settings claim is rejected. The inherited slot analysis now establishes its source identity as `OnControlCommand`.
- UID00049C callsites `0x0053e6ce` and `0x0053e844` pass control id `2` to exact [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md). `MacroDialog` primary slot `+0x58` inherits that base body; it does not declare or emit a duplicate override. The helper deactivates the old child, activates child `2`, then stores the id, while `OnControlCommand` remains the separate primary `+0x48` override.

### Current class-shape and ABI evidence

- The constructor allocation caller requests decimal `620` bytes (`0x26c`), and the scalar deleting destructor wrapper uses `0x26c` for flag-`4` array-cookie traversal. The inherited `DialogPane` state reaches through `+0x268`; no constructor, handler, destructor, or vtable evidence identifies a `MacroDialog`-specific data member. The source-facing class is therefore fieldless, with its natural complete-object size inherited from `DialogPane` rather than expressed as raw padding members.
- Construction begins with the `DialogPane` constructor and installs the three `MacroDialog` vptr views. This proves direct public inheritance from `DialogPane`; it does not support a second source base, composition wrapper, or copied base fields.
- Primary vtable `0x00620d10`, secondary view `0x00620d70`, and tertiary view `0x00620da0` identify the complete object. Primary `+0x08` routes through scalar wrapper [UID:00038C][0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor](by-memory/0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor.md), while primary `+0x48` routes to the `0x0053e8f0` control handler. Secondary/tertiary destructor adjustors at `0x005425e1` and `0x005425ec` are compiler glue and do not become source declarations.
- The source declaration uses a public explicit virtual destructor because the ordinary destructor body at [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md) is a distinct out-of-line source obligation and deleting through the polymorphic base is supported. `OnControlCommand(int, int)` is public to match the accepted `DialogPane` interface and the exact two-stack-argument virtual call ABI; inventing a private helper or `SaveMacros()` member would contradict the slot and callers.
- The historical `SaveMacros` name remains provenance for the body-level effect, but the current source-facing method identity is `OnControlCommand`. The second integer is accepted as `notifyCode` even though this body does not consume it, because callers and the inherited virtual contract supply both arguments.
- Compiler artifacts remain excluded from the declaration: no vptr stores, adjustor thunks, scalar-delete flags, storage deletion, SEH setup, RTTI arrays, or raw offsets belong in human-written class C++.
- Validator command `000000013040` generated the historical pre-callback state with no `class MacroDialog`, one UID00007I Empty Emitter Marker, and target definitions emitted without a preceding complete class declaration. Position `10` plus the managed declaration and `[[CHILDREN]]` after the closing `};` supplies the class before qualified child definitions without nesting definitions inside it.

## Dependencies And State

| Dependency | Role |
| --- | --- |
| [UID:00009V][OptionPane](by-class/OptionPane.md) / [UID:0000M7][OptionPane](by-file/OptionPane.md) | Opens the older macro setup flow; does not own this class implementation. |
| [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) | Proposed source owner and parent for the older, spell, newer, integrated, and edit-control macro family. |
| [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) | Exact method-island evidence for this class and its neighboring macro dialog generations. |
| [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) | Source-declared/generated-binary vtable and RTTI evidence for method slots and destructor support. |
| [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) | Owns `m_profileTextSlots[10][0x80]` at `+0x28de9c`, the direct storage read/written by the constructor and control-handler child bodies. |

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). The class and direct file parent satisfy the strict attachment gate, and source-bearing method bodies emit from the exact children. The managed block owns only the complete fieldless class declaration; `[[CHILDREN]]` follows the closing `};`, so qualified definitions remain at namespace scope. Destructor wrappers, adjustors, vtables, RTTI, cookies, and raw layout arrays remain compiler-owned and are not emitted as handwritten source.

## Score Rationale

Completion is `91` because the page has a complete source-facing declaration, direct `DialogPane` inheritance, exact `0x26c` fieldless layout proof, constructor/destructor/control-handler declarations, managed child placement, source ownership, exact child UIDs, vtable identity, destructor-island separation, option-pane opener, command id `1`, child-control ids `2..11`, direct `m_profileTextSlots` storage, and the exact inherited UID0004RI helper route. Confidence is `93` because allocation size, wrapper stride, base extent, three vtable views, exact `+0x48` handler and inherited `+0x58` slots, callers, and distinct ordinary/scalar destructor bodies agree. The remaining cap reflects inferred original parameter spellings and access labels, not a missing source shape or binary route.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md)
- [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md)
- [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md)

## Changes

- 2026-07-15 B003 UID00049G implementation callback: preserved `91/93`, owner/emitter UID0000KY, true, position `10`, and exact R20 class declaration/closure. Added only bounded UID00049C evidence that both layout branches call inherited `DialogPane::SetHoverControl(2)` through UID0004RI and kept the distinct `+0x48` OnControlCommand override, all fieldless `0x26c`/destructor/source facts, and unrelated history unchanged.

- 2026-07-15 B003 [UID:00049D][0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor](by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md) implementation callback:
  - Raised `88/90` to `91/93`, set source order position `10`, and installed the complete fieldless `MacroDialog : public DialogPane` declaration.
  - Closed the class before `[[CHILDREN]]`; source children therefore emit as namespace-scope qualified definitions.
  - Added the exact `0x26c` allocation/wrapper/base-layout proof, three-view vtable routing, ordinary/source destructor versus scalar/adjustor compiler split, and `OnControlCommand(int, int)` virtual ABI. Historical `SaveMacros` wording is retained only as superseded behavioral provenance.
  - Preserved all unrelated constructor, profile storage, option-pane, family, and source-ownership evidence.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, metadata, and formal block remain unchanged. Corrected the stale dirty-save statement: UID00049E copies ten profile text rows and closes/removes, but is not a SaveUserSettings caller.

- 2026-06-28 B010 implementation callback:
  - Raised from `85/88` to `88/90`.
  - Linked exact method children [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md)-[UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md) after validator UID assignment and recorded that their formal C++ blocks now own emission.
  - Replaced the prior unresolved `MacroHotkeyRecord` dependency with direct `RegistryConfigUserProfileBlock::m_profileTextSlots` storage evidence from the accepted UID0001DR split.
- 2026-06-12 A004 Batch 243 strict-gate repair:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`, and one-byte-short method/destructor endpoints inherited from older range notes.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; kept direct parent [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md), which clears `88/85`.
  - Evidence: live IDA MCP confirmed `MacroDialog` constructor `0x0053e520-0x0053e8cf`, non-deleting destructor helper `0x0053e8d0-0x0053e8ef`, handler then labeled `SaveMacros` `0x0053e8f0-0x0053e959`, scalar deleting destructor `0x005427a0-0x005427f5`, constructor caller `0x0053e0f1`, and the primary/secondary/tertiary vtable refs in the macro dialog family. The current source identity for that handler is `OnControlCommand`.
- 2026-06-07: Raised completion/confidence from `74/82` to `80/84` and attached `AUTOGEN_PARENT_UID:0000KY`. The class page now records the MacroDialogs parent, exact method island, vtable-slot evidence, destructor/adjustor island separation, option-pane opener, macro-record dependency, and final-C++ gate. Live IDA MCP was unavailable after three connection attempts during this pass, so the score remains conservative and the new claims are limited to existing UID-backed documentation.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms the older macro dialog constructor/save/destructor functions are NexusTK-owned UI behavior. Kept `AUTOGEN_PARENT_UID` blank because this class is `74/82`, below the 80/80 parent-attachment gate, even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0053e520` (`sub_53E520`, size `0x3af`), `0x0053e8d0` (`sub_53E8D0`, size `0x1f`), `0x0053e8f0` (`sub_53E8F0`, size `0x69`), and `0x005427a0` (`sub_5427A0`, size `0x55`); `callers` confirms the constructor is called at `0x0053e0f1` in `sub_53DDB0`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: the older macro setup dialog has purpose, source owner, vtable family, opening path, and main methods documented, but method-level behavior remains comparatively brief. Evidence: linked macro-dialog memory range, constructor/save/destructor method map, and `OptionPane::OnOptionCommand` ownership evidence.
