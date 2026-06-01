*** UID:0000R0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pGeneralPurposePanel

## Status

- Confidence: strong for address and role.
- Address: `0x0067a874`
- IDA name: `dword_67A874`
- Proposed owner file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)

## Symbol Role

`g_pGeneralPurposePanel` stores the active seven-child in-game side-panel shell. It is written by `GeneralPurposePanel::GeneralPurposePanel`, cleared by the destructor/deleting destructor and the tiny cleanup helper at `0x004b8a90`, and read broadly by map, user, inventory, spell, item, and dialog code that needs to fetch or switch one of the side-panel child panes.

## Evidence

- `GeneralPurposePanel::GeneralPurposePanel` at `0x004b83d0` stores the constructed object in `dword_67A874`.
- `GeneralPurposePanel::~GeneralPurposePanel` at `0x004b8580` and `GeneralPurposePanel::ScalarDeletingDestructor` at `0x004b8b40` clear it.
- [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) at `0x004b8a90` clears it.
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) is called through this global from the map packet dispatcher and many input/menu paths.
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) are called through this global to fetch self-look, user-look, inventory, spell, group, collection, and option panes.

## Ownership Notes

Keep this global with `ui/panels/GeneralPurposePanel.cpp`. Generated references through `SpellOneArgInputPane` are caller/owner pollution around shared side-panel helpers, not evidence that spell input owns the singleton.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, owner, singleton role, constructor/destructor/clear-helper evidence, broad reader behavior, child accessors, active-tab switching, ownership notes, and refs.
