*** UID:0000R1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pGeneralPurposePanel2

## Status

- Confidence: strong for address and role.
- Address: `0x0069b358`
- IDA name: `dword_69B358`
- Proposed owner file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)

## Symbol Role

`g_pGeneralPurposePanel2` stores the smaller alternate one-child side-panel shell. The constructor stores it, teardown paths clear it, and user/message code reads it to reach the embedded system-message pane cluster.

## Evidence

- `GeneralPurposePanel2::GeneralPurposePanel2` at `0x004b8830` stores the constructed object in `dword_69B358`.
- `GeneralPurposePanel2::~GeneralPurposePanel2` at `0x004b88f0` and `GeneralPurposePanel2::ScalarDeletingDestructor` at `0x004b8aa0` clear it.
- [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) at `0x004b8a80` clears it.
- `GeneralPurposePanel2::GetChildPaneByIndex` at `0x004b8950` returns the single child pane.
- [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md) is called from `UserPane::OnServerMessage` at `0x005a771b`.

## Ownership Notes

Keep this global in the same source module as `GeneralPurposePanel2`. Current generated output already emits the constructor/destructor/global-data lines in `class_GeneralPurposePanel2.cpp`, but omits the switch helper at `0x004b89a0`.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, owner, alternate side-panel role, constructor/destructor/clear-helper evidence, child accessor/switch helper, generated omission caveat, and refs.
