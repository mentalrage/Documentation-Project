*** UID:0000JJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ForcedInformMessageDialog

## Status

- Confidence: strong for source contents; medium for exact original path.
- Proposed source path: `login/ForcedInformMessageDialog.cpp`
- Proposed header path: `login/ForcedInformMessageDialog.h`
- Core address range: [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- Support ranges: [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md), [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md), [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md), [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- Current generated file: `source-3/simroot_v2/class_ForcedInformMessageDialog.cpp`

## File Role

This module should own the forced login/main-menu information dialog. It is a specialized modal dialog that displays server/client-supplied text, requires acceptance, and exits the client if the user declines. Its teardown can re-open the login dialog through `EnsureLoginDialogPane_4F8B30`.

The module is separate from the staff credits dialog despite the `DLGSTAFF` resource prefix. `StaffsDialogPane` displays credits from DAT text resources; `ForcedInformMessageDialog` displays a supplied message body and enforces accept/decline behavior.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ForcedInformMessageDialog` | `0x00587bb0-0x005881ed`, `0x0058aa90`, `0x0058aadb-0x0058aaf1`, `0x0058abf0-0x0058acb2` | Mandatory information dialog with accept/decline buttons or key handling. |
| `g_pForcedInformMessageDialog` | [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md) | Active singleton pointer used by constructor, teardown, clear helper, and main-menu cleanup. |
| `EnsureLoginDialogPane_4F8B30` | `0x004f8b30-0x004f8b8d` | Existing [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) called during accepted EPF teardown. Keep implemented with login dialog code. |
| Resource family | `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, palettes | Dialog background resources for EPF and EPD paths. |

## Current Generated Split

| Current emitted owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_ForcedInformMessageDialog.cpp` | `0x00587bb0`, `0x00588080`, `0x00588110`, `0x00588160`, `0x0058abf0` | Keep in `login/ForcedInformMessageDialog.cpp`. |
| omitted from active output | `0x0058aa90` | Account for as compiler-generated constructor EH cleanup that clears `g_pForcedInformMessageDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| disabled `class_ForcedInformMessageDialog.cpp` | `0x0058aadb`, `0x0058aae6` | Keep as compiler-generated destructor adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); `0x0058aadb` is real despite missing generated code. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x00587bb0` size `0x4c3`, `0x00588080` size `0x81`, `0x00588110` size `0x4d`, `0x00588160` size `0x8d`, `0x0058aa90` size `0xb`, `0x0058aadb` size `0xb`, `0x0058aae6` size `0xb`, and `0x0058abf0` size `0xc2`.
- IDA MCP callees for the constructor include `DialogPane` construction, `EPFImageControlPane`, `TextEditControlPane`, `ImageButtonControlPane`, text edit helpers, dialog layout/show helpers, and the screen/dimmer callback path.
- IDA MCP callers for `EnsureLoginDialogPane_4F8B30` are the two `ForcedInformMessageDialog` destructor forms.
- IDA MCP `xrefs_to 0x0069b4a0` confirms `CloseMainMenuDialogSingletons_004F69A0` reads the singleton, while constructor/destructor/support functions write or clear it.
- IDA MCP `xrefs_to 0x0058aadb` and `xrefs_to 0x0058aae6` show vtable data refs at `0x0062d778` and `0x0062d7a8`; both thunks call the scalar deleting destructor with `this - 0xa0` or `this - 0xa4`.
- 2026-05-26 recheck confirms `0x0058aa90` is constructor-unwind cleanup glue and `0x0058aadb-0x0058aaf1` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.
- Current generated code uses inherited helper labels such as `MiniMapDialog`, `FittingRoomUserImageControlPane`, `RankingDialog`, and `ChattingColorPane`. Treat these as base/helper label pollution, not file ownership evidence.

## Migration Notes

- Proposed Wave3 source migration after review: set `class_ForcedInformMessageDialog.cpp` simpath to `login/ForcedInformMessageDialog.cpp`.
- Keep `0x0058aa90` documented as a constructor EH singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Materialize or mark `0x0058aadb` as a real compiler-generated thunk instead of missing code.
- Keep [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) with login dialog code; this file merely calls it during teardown.
- Keep [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) separate even though the ranges are adjacent and interleaved in the binary.

## Cross-References

- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: forced message dialog role, singleton/global ownership, resource family, generated split table, IDA function evidence, teardown/login relationship, compiler-generated helper exclusions, migration notes, and cross-references are documented; confidence is strong with final login path/source placement still medium.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"` to match the documented login/main-menu source placement and allow attached child memory docs to stage under the same parent.
