*** UID:0000R1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Exact storage: [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md)

## Symbol Role

`g_pGeneralPurposePanel2` stores the smaller alternate one-child side-panel shell. The constructor stores it, teardown paths clear it, and user/message code reads it to reach the embedded system-message pane cluster.

## Evidence

- `GeneralPurposePanel2::GeneralPurposePanel2` at `0x004b8830` stores the constructed object in `dword_69B358`.
- `GeneralPurposePanel2::~GeneralPurposePanel2` at `0x004b88f0` and `GeneralPurposePanel2::ScalarDeletingDestructor` at `0x004b8aa0` clear it.
- [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) at `0x004b8a80` clears it.
- `GeneralPurposePanel2::GetChildPaneByIndex` at `0x004b8950` returns the single child pane.
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) is called from `UserPane::OnServerMessage` at `0x005a771b`.
- Batch 039 live IDA MCP recheck on 2026-06-07 confirmed the exact four-byte storage page [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md): initial dword `0xffffffff`, 14 direct refs, constructor/fallback writes at `0x004b8872`/`0x004b8879`, clear paths at `0x004b8925`, `0x004b8a80`, and `0x004b8adc`, and neighboring dword boundaries before `g_pTotemFrame`.

## Ownership Notes

Keep this global in the same source module as `GeneralPurposePanel2`. The switch helper at `0x004b89a0` belongs with the same one-child panel shell even though it needs a focused migration review.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, owner, alternate side-panel role, constructor/destructor/clear-helper evidence, child accessor/switch helper, migration caveat, and refs.
- 2026-06-05: Marked reconstructable under [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). Evidence: live IDA MCP reports 14 xrefs to `0x0069b358`; decompilation confirms `0x004b8830` stores `dword_69B358`, while `0x004b88f0`, `0x004b8a80`, and `0x004b8aa0` clear it from the `GeneralPurposePanel2` lifecycle.
- 2026-06-07: Raised confidence from `84` to `86` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
