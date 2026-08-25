*** UID:0000JJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ForcedInformMessageDialog

## Status

- Confidence: very strong for source contents, one-definition order, split routing, class/global ownership, source/compiler separation, resources, and generated contract; exact original filename and some private spellings remain bounded caps.
- Proposed source path: `login/ForcedInformMessageDialog.cpp`
- Proposed header path: `login/ForcedInformMessageDialog.h`
- Reviewed non-emitting physical core container: [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- Exact source-bearing method children:
  - [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md)
  - [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md)
  - [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md)
  - [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md)
- Exact vtable data: [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md)
- Support ranges: [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md), [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md), [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md), [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- Generated-source policy: emit source through the exact method children, not through the broad [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) aggregate and not through the scalar deleting destructor wrapper [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md).
- One-definition order: semantic global UID0000QY emits at position `0`; class UID00005E emits at position `10`, closes before its `extern` and `[[CHILDREN]]`; the four exact methods then emit once in address order.

## File Role

This module owns the forced login/main-menu information dialog. The dialog displays server/client-supplied UTF-16 message text, requires the user to accept or decline, restores the login dialog during accepted EPF teardown, and requests application exit when the user declines.

The module is separate from the staff credits dialog despite the `DLGSTAFF` resource prefix. `StaffsDialogPane` displays credits from DAT text resources; `ForcedInformMessageDialog` displays a supplied message body and enforces accept/decline behavior.

The module is also separate from [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). The physical executable and `.rdata` neighborhoods are adjacent to system-message panes, but the resource refs, vtable data, singleton, class layout, and login/main-menu teardown path identify a distinct forced-inform dialog source family.

## Proposed Contents

| Entity | Address / page | Role |
| --- | --- | --- |
| `g_pForcedInformMessageDialog` definition | [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md) | Sole external C++03 `NULL` definition with forward declaration, emitted at position 0; physical UID0001PW is storage evidence only. |
| `ForcedInformMessageDialog` class | [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md) | Complete position-10 declaration with direct DialogPane/Singleton bases, exact 0x270 EBO layout, constructor/destructor/control/Event methods, extern declaration, and class closure before children. |
| `ForcedInformMessageDialog::ForcedInformMessageDialog` | [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md) | Source C++03 builds exact EPF/EPD `DLGSTAFF` layouts, preserves duplicated text setup, opens through parent/layer context, and notifies the screen dimmer; Singleton publication is implicit lowering. |
| `ForcedInformMessageDialog::~ForcedInformMessageDialog` | [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md) | Source C++03 contains only the accepted EPF/accepted/main-menu guard and login restoration; Singleton/base lowering performs the clear/cleanup. |
| `ForcedInformMessageDialog::OnControlCommand` | [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md) | Exact primary-slot two-argument control callback: index `2` accepts/closes; index `3` declines/closes/exits; notification argument unused. |
| `ForcedInformMessageDialog::HandleKeyOrTextEvent` | [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md) | Exact secondary-slot `Event *` callback; EventMan translates key/modifiers before key-down gating, A/a accepts, D/d declines/exits, always true. |
| Physical method island | [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) | Reviewed non-emitting split container only. |
| Scalar deleting destructor support | [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) | Compiler-generated wrapper; non-emitting after the ordinary destructor child owns source behavior. |
| Constructor EH singleton clear | [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) | Compiler/EH helper that clears `g_pForcedInformMessageDialog`; no handwritten source body. |
| Destructor adjustor thunks | [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) | Compiler-generated secondary/tertiary thunk entries to the scalar deleting destructor. |
| `ForcedInformMessageDialog` vtable/RTTI data | [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md) | False/non-emitting compiler data regenerated from the class declaration; no raw arrays. |
| `g_pForcedInformMessageDialog` physical slot | [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md) | False/non-emitting loader-zeroed storage evidence for the semantic global. |
| `EnsureLoginDialogPane` call | [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) | Login dialog helper called by accepted forced-inform teardown; ownership stays with `LoginDialogPane`. |
| Resource family | `DLGSTAFF.EPF`, `DLGSTAFF.PAL`, `DLGSTAFF.EPD`, `L"NP"` | Dialog background/palette resources for EPF/current and EPD/legacy modes. |

## Generated Split And Emission Policy

Current generated source should route source-authored behavior only through the exact method children:

| Item | Emission decision |
| --- | --- |
| [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) | Non-emitting split container. Blank formal C++ is deliberate, not a missing implementation. |
| [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md) | Emits constructor source through this file. |
| [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md) | Emits ordinary destructor source through this file. |
| [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md) | Emits button/action callback source through this file. |
| [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md) | Emits key callback source through this file. |
| [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) | Non-emitting scalar deleting destructor support; compiler regenerates equivalent ABI wrapper from the ordinary destructor and class layout. |
| [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) and [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) | Non-emitting compiler support. |
| [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md) and [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md) | Non-emitting compiler/storage records; class/global semantic pages regenerate source and compiler artifacts. |

## Source-Facing Helper And Global Map

The accepted B008 report resolves the relevant raw/generated names for this file route:

| Raw/generated label | Source-facing name used in docs/C++ |
| --- | --- |
| `byte_66DA97` | `g_useEpfAssets` |
| `dword_69B4A0` / `unk_69B4A0` | `g_pForcedInformMessageDialog` |
| `unk_69AE08` | `g_pScreenDimmer` |
| `unk_67ABA4` | `g_pMainMenuPane`; historical source alias `g_pMainUiGraph` is superseded |
| `unk_67AB1C` | `g_pApplication` |
| `this + 0x26c` | `m_bAccepted` |
| `sub_49DB60` | `DialogPane::SetBackgroundResource(...)` |
| `sub_49DC10` | `DialogPane::AddControl(...)` |
| `sub_49DFD0` | `DialogPane::OnCreate(const RectBounds *, int, Pane *, Layer *)` |
| `sub_49E190` | `DialogPane::OnShow(Pane *, Pane *)` |
| `sub_49EAC0` / `sub_49EB90` | `DialogPane::SlideOpenVertical()` / `SlideCloseVertical()` |
| `sub_49DAD0` | `DialogPane::CloseDialog()` |
| `sub_49FC00` | `DialogPane::SetHoverControl(int)` |
| `sub_49DD80` / `sub_49DDD0` | `DialogPane::SetFocusedControl(int)` / `SetPendingControl(int)` |
| `sub_5446B0` | `Pane::SetMode(unsigned char)` |
| `sub_58FC30` / `sub_58F2A0` | `TextEditPane::SetText(...)` / `SetSelectionRange(...)` |
| `sub_498C00` | `TextEditControlPane::SetEditActiveState(bool, bool)` role alias |
| secondary key event offsets / translator | `Event::m_type`, `Event::m_payload.m_key`, and `g_pEventMan->TranslateEventKey(key, modifiers)` |
| `sub_464E40` | `Application::RequestExit()` |

`SetEditActiveState`, `SetControlVisible`, `ScreenDimmer::SetDimmed`, and exact UI control constructor overload spellings remain inferred role-level source names, but they are accepted project-facing names for the first-draft method C++ and should be used instead of raw `sub_` labels.

## Evidence Notes

- B008 accepted report used live MCP session `b001_000241_20260627` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, with `server_health` reporting `status: ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed exact starts/sizes at `0x00587bb0` (`0x4c3`), `0x00588080` (`0x81`), `0x00588110` (`0x4d`), `0x00588160` (`0x8d`), `0x0058aa90` (`0xb`), `0x0058aadb` (`0xb`), `0x0058aae6` (`0xb`), and `0x0058abf0` (`0xc2`).
- The split padding is `0x00588073-0x00588080` / 13 bytes, `0x00588101-0x00588110` / 15 bytes, `0x0058815d-0x00588160` / 3 bytes, and `0x005881ed-0x005881f0` / 3 bytes of `0xcc`.
- Constructor caller evidence remains negative: no incoming code xrefs/callers and no VA/RVA byte-pattern hits for the constructor start. Resource/vtable/singleton/destructor/class evidence still proves constructor identity and source placement.
- `xrefs_to 0x0069b4a0` confirms constructor publish/fallback clear, ordinary destructor clear, singleton-clear helper, scalar wrapper clear, and main-menu cleanup read.
- Vtable reachability is now explicit: button callback via `0x0062d760`, key callback via `0x0062d780`, scalar deleting destructor via `0x0062d718`, and constructor/destructor/scalar stores to the three class views.
- `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, and `L"NP"` are the accepted resource/palette literals for the constructor.
- The scalar deleting destructor and adjustor thunks are compiler output; source should model the ordinary destructor and class layout instead.
- Current session `9b0396a3` and executable SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` close all accepted body/hash/RTTI/PE facts. UID0001PW is loader-zeroed, UID0000QY owns the sole definition, direct Singleton inheritance explains publication/clear, and no explicit singleton assignment belongs in constructor/destructor source.
- Exact authored body hashes are constructor `A82ED3870204B8326E6FF1EE33F00380C74F48D24E0A70106E8D2EB7BF50D1EA`, destructor `EBC61935D70257897C200D163B3347994CFCEB84D373BCFF93140D6C84266CAF`, control command `D85211157B749B492DDBE2832FB48E2ED17BD03F625E6B42188A203FBBF68FB1`, and key/text event `235BDE76233C8DB7042AE38914229C03A41836B52E960345241949D64A97DBD4`.
- Excluded output is explicit: parent split index, physical slot, EH clear helper, adjustor thunks, scalar deleting wrapper, vtable/RTTI data, raw vptr stores, singleton template writes, EH/cookie/guard code, scalar flags, operator-delete scaffolding, raw addresses/offsets, and UID-bearing markers do not emit authored C++.

## Migration Notes

- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`.
- Keep [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) as the owner of `EnsureLoginDialogPane`; this file only calls it during accepted forced-inform teardown.
- Keep [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md) routed through the class page [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md), not directly through this file, because the vtables are class-declaration generated data.
- Keep [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) separate despite adjacency and interleaving.

## Cross-References

- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md)
- [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md)
- [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md)
- [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md)
- [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md)
- [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)

## Changes

- 2026-07-14 B002 UID0002AF callback: synchronized the concrete `0x0067aba4` singleton name to `g_pMainMenuPane` for the restore-login guard; no ForcedInform ownership or behavior changed.

- 2026-07-21 B003 UID0001PW implementation callback: raised to `92/93`, preserved `NexusTK/login/`, synchronized the sole global/class/method order, both validator-preserving callback renames, direct Singleton C++03 source cause, exact resources/hashes/padding, compiler exclusions, and generated one-definition contract without removing the prior B001/B002/B008 source-family history.

- 2026-06-27 B008 accepted implementation callback for `0001J7-ForcedInformMessageDialogCore-source-quality.md`:
  - Score raised from `87/86` to `88/88` to account for exact child source routing, accepted helper/global names, and scalar-wrapper reclassification.
  - Updated method inventory to route generated source through the four exact source-bearing children and not through [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) or [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md).
  - Added accepted source-facing helper/global mapping, live MCP session `b001_000241_20260627` evidence, split-padding facts, constructor no-caller caveat, callback vtable reachability, and support-disposition notes.
- 2026-06-20 B001 EnsureLoginDialogPane caller-context sync:
  - Score unchanged at `87/86`.
  - The two forced-inform destructor call sites remain documented as accepted-teardown restoration calls into the login helper. Ownership and emission stay with [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) / [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), while this file records only the caller relationship.
- 2026-06-12 A002 Batch275 source-owner refresh:
  - Before: `84/80`.
  - Changed to: `87/86`; added exact vtable-data child, strict class-parent routing rationale, and current IDA MCP evidence tying the three vtables, singleton, destructor login restore, and `DLGSTAFF.*` literals to this login/main-menu module.
- 2026-06-01:
  - Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"` to match the documented login/main-menu source placement and allow attached child memory docs to stage under the same parent.
