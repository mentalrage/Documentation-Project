*** UID:00005E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class ForcedInformMessageDialog : public DialogPane,
                                  public Singleton<ForcedInformMessageDialog>
{
public:
    ForcedInformMessageDialog(const wchar_t *messageText, Pane *parentPane, Layer *layer);
    virtual ~ForcedInformMessageDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    bool m_bAccepted;
};

extern ForcedInformMessageDialog *g_pForcedInformMessageDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete C++03 declaration for the 0x270 ForcedInformMessageDialog with direct DialogPane and Singleton bases, EBO-overlapped m_bAccepted storage, exact constructor/destructor/control/Event declarations, external singleton declaration, and class closure before child definitions. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ForcedInformMessageDialog

## Status

- Confidence: very strong for direct bases, 0x270 layout, method ABI/signatures, split child routing, vtable reachability, and source file parent; original private parameter spellings remain a bounded cap.
- Likely source file: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- Reviewed physical core container: [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- Exact source-bearing method children:
  - [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md)
  - [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md)
  - [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md)
  - [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md)
- Exact vtable data: [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md)
- Support ranges: [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md), [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md), [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md)
- Autogen status: class declaration emits through [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) with `[[CHILDREN]]`; exact method children own formal method bodies.

## Class Purpose

`ForcedInformMessageDialog` is a mandatory informational dialog that blocks the user until they accept or decline. In EPF/current asset mode it shows `DLGSTAFF.EPF`, `DLGSTAFF.PAL`, a read-only/hidden [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md), and Accept/Decline buttons. In EPD/legacy asset mode it shows `DLGSTAFF.EPD` with legacy palette literal `L"NP"` and text-only content.

Accept closes the dialog and allows accepted teardown to restore the login dialog when EPF/main-UI state is active. Decline closes the dialog and requests application exit through [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) / [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md).

## Method Notes

| Method or role | Address / page | Notes |
| --- | --- | --- |
| Constructor | [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md) | Source C++03: `ForcedInformMessageDialog(const wchar_t *messageText, Pane *parentPane, Layer *layer)`, EPF/EPD layout, text insertion, parent/layer open path, focus ids `2/2/3`, and optional screen-dimmer notification. Direct Singleton publication is implicit base-template lowering, not an authored assignment. |
| Non-deleting destructor | [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md) | Source C++03: accepted EPF/main-UI teardown condition calls `EnsureLoginDialogPane()` only. Reverse Singleton/base cleanup and global clear are compiler/base output. |
| `OnControlCommand` | [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md) | Primary-vtable slot `+0x48`, `retn 8`; control index `2` accepts/closes, index `3` declines/closes/exits, and `notifyCode` is unused. Constructor image ids `14/22` remain separate resource ids. |
| `HandleKeyOrTextEvent` | [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md) | Secondary EventHandler slot `+0x08`, `retn 4`; EventMan translates key/modifiers before the key-down test, `A/a` accepts, `D/d` declines/exits, and the method always returns true. Secondary `this` adjustment remains compiler lowering. |
| Singleton clear helper | [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) | Real `0xb` compiler/EH cleanup helper that clears `g_pForcedInformMessageDialog`; non-emitting support. |
| Adjustor thunks | [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) | Two real `0xb` destructor adjustor thunks for `this-0xa0` and `this-0xa4`; non-emitting support. |
| Scalar deleting destructor | [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) | Non-emitting compiler-generated scalar deleting wrapper. Source destructor behavior now belongs to the non-deleting destructor child. |

## Layout Notes

| Offset | Size | Source entity | Evidence/disposition |
| --- | ---: | --- | --- |
| `0x000-0x26b` | `0x26c` | `DialogPane` direct base | inherited primary/EventHandler/TimerHandler facets; vtable views at `+0`, `+0xa0`, and `+0xa4` |
| `0x26c` | EBO | `Singleton<ForcedInformMessageDialog>` direct base | RTTI BCD PMD `(0x26c,-1,0)` with attribute `0x40`; no data member |
| `0x26c` | 1 | `bool m_bAccepted` | legal EBO overlap; constructor defaults true, accept/decline handlers write it, destructors test it |
| `0x26d-0x26f` | 3 | natural tail alignment | represented by the compiler; no explicit padding member |
| total | `0x270` | complete object | allocation/scalar-wrapper size and layout evidence |

RTTI CHD records eight bases. The exact vtable-data child is `0x0062d714-0x0062d7b0`, `0x9c` bytes / 156 decimal. EPF path layout is `318x456`, centered from `g_screenWidth` and `g_screenHeight`; EPD path layout is `267x367`, fixed at `(363,100)-(630,467)`.

## Source-Facing Dependency Names

The accepted report replaces raw/global labels in this class context with project source-facing names:

- `g_useEpfAssets` for `byte_66DA97`;
- `g_pScreenDimmer` for `unk_69AE08`;
- `g_pForcedInformMessageDialog` for `dword_69B4A0`;
- `g_pMainMenuPane` for `dword_67ABA4` (historical `g_pMainUiGraph` alias superseded);
- `g_pApplication` for `unk_67AB1C`;
- `g_screenWidth` / `g_screenHeight` for centered EPF bounds;
- `DialogPane::SetBackgroundResource`, `AddControl`, `OnCreate`, `OnShow`, `SetHoverControl`, `SetFocusedControl`, `SetPendingControl`, `SlideOpenVertical`, `SlideCloseVertical`, and `CloseDialog`;
- `TextEditControlPane::SetMaxLines`, `SetMaxLength`, `SetEditActiveState`, `GetTextEditPane`, and `SetControlVisible`;
- `TextEditPane::SetText` and `SetSelectionRange`;
- `ScreenDimmer::SetDimmed(bool)` as the accepted role alias for the constructor's virtual singleton notification;
- `Event::m_type`, `Event::m_payload.m_key.m_key`, `Event::m_payload.m_key.m_modifiers`, `kEventKeyDown`, and `EventMan::TranslateEventKey(key, modifiers)`.

These names are inferred/project-facing where original symbols are unavailable. They are now strong enough for first-draft C++ and should replace `sub_`, `dword_`, and `unk_` labels in source-facing documentation.

## Evidence Notes

- B008 accepted report used live MCP session `b001_000241_20260627`, with `server_health` reporting `status: ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` confirmed exact method starts/sizes at `0x00587bb0` (`0x4c3`), `0x00588080` (`0x81`), `0x00588110` (`0x4d`), and `0x00588160` (`0x8d`), plus support starts at `0x0058aa90`, `0x0058aadb`, `0x0058aae6`, and `0x0058abf0`.
- The physical parent [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) now records exact split padding and is non-emitting.
- Constructor direct callers remain absent in the active IDB, with no incoming code refs and no VA/RVA byte-pattern hits for the start. This caps confidence but no longer blocks source-ready constructor C++ because parent/layer parameters are resolved through `DialogPane::OnCreate`/`OnShow` semantics and the class identity is corroborated by vtables, singleton, resources, and destructor parity.
- Callback reachability is vtable-proven: button callback at `0x0062d760 -> 0x00588110`, key callback at `0x0062d780 -> 0x00588160`, and scalar deleting destructor at `0x0062d718 -> 0x0058abf0`.
- RTTI CHD has eight bases and records direct `Singleton<ForcedInformMessageDialog>` PMD `(0x26c,-1,0)`. Together with size `0x270`, vtable views `0/+0xa0/+0xa4`, and the `m_bAccepted` access, this closes the direct-inheritance/EBO layout without raw padding fields or offset comments in source.
- The scalar deleting destructor wrapper and adjustor thunks are non-emitting generated-binary support after source behavior moved to the ordinary destructor child.
- `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, and legacy `L"NP"` resource/palette literals are documented by current resource string refs and constructor use.

## Source Layout Decision

Place this class in `login/ForcedInformMessageDialog.cpp` / `.h` or a nearby pre-login dialog source. It should not be absorbed into [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) even though the executable and `.rdata` ranges are adjacent to the system-message pane family. The behavior, resources, singleton, vtable data, and login-dialog teardown path are a mandatory login/main-menu notice, not system-message viewport rendering.

## Cross-References

- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md)
- [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md)
- [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md)
- [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md)
- [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md)
- [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)
- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md)

## Changes

- 2026-07-14 B002 UID0002AF callback: synchronized the class dependency name for `0x0067aba4` to `g_pMainMenuPane`; all destructor and dialog semantics remain unchanged.

- 2026-07-21 B003 UID0001PW implementation callback: raised to `93/94`, assigned position `10`, installed the complete direct-`DialogPane`/`Singleton` C++03 declaration, corrected both virtual method contracts, documented the exact 0x270 EBO layout and eight-base RTTI, moved `[[CHILDREN]]` after the class/extern declarations, and preserved all resource, method, dependency, and historical evidence.

- 2026-06-27 B008 accepted implementation callback for `0001J7-ForcedInformMessageDialogCore-source-quality.md`:
  - Raised class score from `87/87` to `89/89`.
  - Added class-level declaration C++ with constructor, destructor, `OnButtonResponse`, `OnKeyInput`, `m_bAccepted`, and `[[CHILDREN]]`.
  - Updated method rows to exact source-bearing child pages, preserved secondary-view key-handler lowering, replaced raw/global helper labels with accepted source-facing names, and documented that the scalar deleting destructor is non-emitting compiler support.
- 2026-06-12 A002 Batch275 vtable boundary and parent-gate refresh:
  - Before: `86/84`.
  - Changed to: `87/87`; exact vtable-data child added, locator-inclusive boundaries and xrefs recorded, and direct file parent [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) refreshed to `87/86`.
- 2026-06-05:
  - Marked reconstructable and attached to [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) because the class and file chain satisfied the then-active parent gate. Current owner/emitter route remains valid; method emission now goes through exact children.
