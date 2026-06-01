*** UID:0000QY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pForcedInformMessageDialog

## Status

- Confidence: strong for singleton address and owner.
- Address: `0x0069b4a0`
- Primary memory doc: [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- Owner class: [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- Likely owner source: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)

## Symbol Role

`g_pForcedInformMessageDialog` stores the active forced information dialog. It is written during construction, read by the main-menu cleanup helper, cleared by both destructor forms, and also cleared by a small helper at `0x0058aa90`.

## Evidence Notes

- Imported Wave2 notes identify `g_pForcedInformMessageDialog` at `0x0069b4a0`.
- IDA MCP `xrefs_to 0x0069b4a0` reports:
  - read from `CloseMainMenuDialogSingletons_004F69A0` at `0x004f69ec`;
  - constructor writes at `0x00587c17` and `0x00587c1e`;
  - non-deleting destructor clear at `0x005880e2`;
  - singleton clear helper at `0x0058aa90`;
  - scalar deleting destructor clear at `0x0058ac59`.
- Active generated `class_ForcedInformMessageDialog.cpp` emits constructor/destructor singleton use but omits the `0x0058aa90` clear helper.
- IDA MCP `xrefs_to 0x0058aa90` reports a constructor-context xref at `0x00608f3b`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x0058aa90` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pForcedInformMessageDialog` itself reconstructable project data.

## Cross-References

- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents singleton address, memory doc, owner, constructor/destructor/main-menu cleanup xrefs, EH cleanup helper classification, and class/file/memory refs.
