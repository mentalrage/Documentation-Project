*** UID:0000QY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ForcedInformMessageDialog;

ForcedInformMessageDialog *g_pForcedInformMessageDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked C++03 definition of the loader-zeroed ForcedInformMessageDialog singleton pointer; emitted first in ForcedInformMessageDialog.cpp, with physical address evidence retained non-emitting under UID0001PW. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pForcedInformMessageDialog

## Status

- Confidence: very strong for singleton address, type, external linkage, zero initializer, sole-definition route, declaration order, and owner.
- Address: `0x0069b4a0`
- Primary memory doc: [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- Owner class: [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- Likely owner source: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)

## Symbol Role

`g_pForcedInformMessageDialog` stores the active forced information dialog. This semantic page owns the sole source definition at emitter position `0`, before the class declaration and child definitions in `ForcedInformMessageDialog.cpp`. Physical page UID0001PW records address/storage evidence but is false and non-emitting. Direct `Singleton<ForcedInformMessageDialog>` inheritance explains constructor publication and teardown clears as template/compiler lowering rather than authored assignments.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b4a0` reports:
  - read from `CloseMainMenuDialogSingletons_004F69A0` at `0x004f69ec`;
  - constructor writes at `0x00587c17` and `0x00587c1e`;
  - non-deleting destructor clear at `0x005880e2`;
  - singleton clear helper at `0x0058aa90`;
  - scalar deleting destructor clear at `0x0058ac59`.
- IDA MCP `xrefs_to 0x0058aa90` reports a constructor-context xref at `0x00608f3b`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x0058aa90` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pForcedInformMessageDialog` itself reconstructable project data.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed exactly six refs to `0x0069b4a0`: main-menu cleanup read at `0x004f69ec`, constructor publish/fallback clear at `0x00587c17`/`0x00587c1e`, non-deleting destructor clear at `0x005880e2`, constructor cleanup helper at `0x0058aa90`, and scalar deleting destructor clear at `0x0058ac59`.
- 2026-06-14 decompilation confirms constructor `sub_587BB0` is `0x4c3` / 1219 bytes (Verified with int_convert.py), publishes/fallback-clears the singleton, installs the three `ForcedInformMessageDialog` vtable views, branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), builds the forced-inform dialog UI, and removes the screen dimmer when appropriate.
- 2026-06-14 decompilation confirms non-deleting destructor `sub_588080` is `0x81` / 129 bytes, clear helper `sub_58AA90` is `0xb` / 11 bytes, and scalar deleting destructor `sub_58ABF0` is `0xc2` / 194 bytes (Verified with int_convert.py). Both destructor paths may call the login-file helper [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) before clearing the singleton when EPF mode, the accepted-dialog flag, and the login-return guard are set; [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) is the recovered alias for that exact helper.
- 2026-06-14 decompilation confirms `CloseMainMenuDialogSingletons_004F69A0` (`0x91` / 145 bytes, Verified with int_convert.py) reads this singleton among the pre-login/main-menu dialog cleanup sequence and closes it through `sub_49DAD0` when present.
- Current healthy MCP session `9b0396a3` reconfirmed four zero bytes and exactly the same six references. PE section arithmetic places RVA `0x29b4a0` `0x20ca0` bytes beyond raw-backed `.data`, proving loader-zero initialization and rejecting historical `0xffffffff` as current source state.
- Main-menu cleanup is a distinct translation-unit read, so this cannot be a file-local `static` or class-static replacement. The source-ready route is an externally linked namespace/global definition with a forward declaration, while class/header users receive `extern ForcedInformMessageDialog *g_pForcedInformMessageDialog;` from the class destination.
- Definition order is fixed: this position-0 block must precede UID00005E at position 10, and UID00005E closes its class before `extern` and `[[CHILDREN]]`. This prevents duplicate definitions and incomplete-type order failures.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md), which surfaces to `auto-generated/NexusTK/login/ForcedInformMessageDialog.cpp` without a dead end.
- Completion is `92` because the page now includes the exact C++03 definition, declaration order, externally linked one-definition route, zero-fill proof, complete six-ref lifecycle, and physical-versus-semantic disposition.
- Confidence is `94` because current IDA bytes/xrefs, PE mapping, RTTI Singleton cause, cross-TU consumer, and generated routing agree. It remains below certainty only because the original declaration-header spelling is not symbol-proven.

## Cross-References

- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents singleton address, memory doc, owner, constructor/destructor/main-menu cleanup xrefs, EH cleanup helper classification, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md). Evidence: live IDA MCP reports six xrefs to `0x0069b4a0`, covering main-menu cleanup, constructor writes, non-deleting destructor clear, constructor cleanup helper, and scalar deleting destructor clear.
- 2026-06-14 A003 goal2 score pass: raised `86/84` to `87/90`.
  - Evidence: live IDA MCP reconfirmed the six-ref singleton map, constructor/destructor/clear-helper/main-menu cleanup decompilation, EPF-mode return-to-login behavior through [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) / recovered alias [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md), EH helper classification, and non-dead-ended ForcedInformMessageDialog owner/emitter route.
  - Code-entry decision: no reconstruction C++ was added; the route and numeric gate are present, but final declaration, constructor parameters, and dialog layout field names remain below source-quality evidence.
- 2026-07-21 B003 UID0001PW implementation callback: raised to `92/94`, assigned emitter position `0`, installed the sole external C++03 `NULL` definition with forward declaration, proved loader-zero initialization and cross-TU linkage, and routed physical UID0001PW to false/non-emitting storage evidence while preserving the full six-reference lifecycle and historical conclusions.
