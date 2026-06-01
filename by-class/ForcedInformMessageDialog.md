*** UID:00005E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ForcedInformMessageDialog

## Status

- Confidence: strong for class behavior and boundaries; medium for exact original filename.
- Likely source file: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- Core address range: [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- Support ranges: [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md), [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md), [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md)
- Current recovered source: `source-3/simroot_v2/class_ForcedInformMessageDialog.cpp`

## Class Purpose

`ForcedInformMessageDialog` is a mandatory informational dialog that blocks the user until they accept or decline. In the newer EPF asset mode it shows `DLGSTAFF.EPF`, an embedded [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md), and Accept/Decline buttons. Accept closes the dialog and can restore the login dialog during teardown; decline closes the dialog and requests application exit. In the older EPD mode it shows `DLGSTAFF.EPD` with text-only content and uses keyboard handling.

The class is login/main-menu adjacent. Its destructor calls [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) when accepted in EPF mode and the login/cursor state is active. The main-menu singleton cleanup helper also reads `g_pForcedInformMessageDialog`.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x00587bb0-0x00588073` | Builds EPF or EPD dialog layout, injects message text into a text edit control, shows the dialog, and notifies the screen/dimmer input object if present. |
| Non-deleting destructor | `0x00588080-0x00588101` | Reinstalls vtables, optionally ensures the login dialog exists, clears `g_pForcedInformMessageDialog`, and chains to inherited cleanup. |
| `OnButtonResponse` | `0x00588110-0x0058815d` | Accept button marks accepted and closes; decline marks declined, closes, and requests application exit. |
| `OnKeyInput` | `0x00588160-0x005881ed` | Secondary-subobject key handler; `A` accepts and `D` declines/exits. |
| Singleton clear helper | [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) | Real `0xb` constructor EH cleanup helper that clears `g_pForcedInformMessageDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), but active generated source omits it. |
| Adjustor thunks | [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) | Two real `0xb` destructor adjustor thunks; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), and `0x0058aadb` is currently emitted as missing code. |
| Scalar deleting destructor | [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) | Deleting destructor form of the same teardown, including optional login-dialog restoration and singleton clear. |

## Layout Notes

- Imported notes identify the struct size as 624 bytes.
- Three vtables are installed at offsets `0`, `0xa0`, and `0xa4`.
- `m_bAccepted` is a byte at offset `0x26c`.
- EPF path layout is `318x456`, centered from `g_screenWidth` and `g_screenHeight`.
- EPD path layout is `267x367`, fixed at approximately `(363,100)-(630,467)`.

## Evidence Notes

- IDA MCP confirms real function starts at `0x00587bb0`, `0x00588080`, `0x00588110`, `0x00588160`, `0x0058aa90`, `0x0058aadb`, `0x0058aae6`, and `0x0058abf0`.
- IDA MCP `callers 0x004f8b30` reports calls from the non-deleting destructor and scalar deleting destructor, confirming the login-dialog reactivation path.
- IDA MCP `xrefs_to 0x0069b4a0` reports the main-menu cleanup helper, constructor writes, destructor clears, singleton clear helper, and scalar deleting destructor use of `g_pForcedInformMessageDialog`.
- IDA MCP `xrefs_to 0x0058aadb` and `xrefs_to 0x0058aae6` show secondary vtable data refs at `0x0062d778` and `0x0062d7a8`, proving both thunks are real.
- 2026-05-26 recheck: `0x0058aa90` and `0x0058aadb-0x0058aaf1` are compiler-generated cleanup/thunk spans, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- IDA MCP reports no direct constructor/callback callers in the current database. Treat this as an unresolved reachability question; virtual dispatch and singleton cleanup evidence still support the class.

## Source Layout Decision

Place this as `login/ForcedInformMessageDialog.cpp` or a nearby pre-login dialog source. It should not be absorbed into [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) even though it is address-adjacent to the system-message pane family. The behavior, resources, singleton, and login-dialog teardown path are a mandatory login/main-menu notice, not system-message viewport rendering.

## Cross-References

- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)
- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/84`. Summary: dialog behavior, EPF/EPD modes, singleton, login teardown path, constructor/destructor/button/key methods, layout offsets, resource ownership, and IDA evidence are documented in detail; remaining uncertainty is exact original filename and unresolved direct reachability. Evidence: core range `0x00587bb0-0x005881ed`, singleton/global cross-references, destructor/support ranges, IDA xrefs to `g_pForcedInformMessageDialog`, and forced-inform resource page.
