*** UID:0000R3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pHistoryViewingPane

## Status

- Confidence: strong for singleton address and class owner.
- Address: `0x0069b494`
- Primary memory doc: [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- Owner class: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Likely owner source: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)

## Symbol Role

`g_pHistoryViewingPane` stores the active full-screen story/history viewer opened from the pre-login main menu. The constructor writes it, the main-menu singleton cleanup helper checks it and marks the viewer for deletion, the tiny helper at `0x005023b0` clears it, and the scalar deleting destructor clears it during teardown.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b494` reports constructor writes at `0x004ffdd6` and `0x004ffddd`, a main-menu cleanup read at `0x004f69dd`, singleton clear at `0x005023b0`, and destructor clear at `0x0050278d`.
- 2026-05-26 recheck classifies `0x005023b0` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pHistoryViewingPane` itself reconstructable project data.
- `CloseMainMenuDialogSingletons_004F69A0` marks this singleton for deletion when a main-menu cleanup pass runs.
- IDA also reports a data xref at `0x004ffefa` outside a named function; treat this as constructor-adjacent unwind/support data until reviewed more deeply.

## Open Questions

- Whether the retained launch wrappers at `0x004f90c0` and `0x004f9140` are live callback targets or dead retained helpers; direct xref lookup currently reports none.

## Cross-References

- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, memory doc, owner, full-screen viewer singleton role, constructor/main-menu cleanup/clear/destructor xrefs, EH cleanup classification, and open launch-wrapper question.
- 2026-06-05: Marked reconstructable under [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md). Evidence: live IDA MCP reports six xrefs to `0x0069b494`; decompilation confirms constructor `0x004ffd80`, cleanup helper `0x005023b0`, and scalar deleting destructor `0x00502760` write/clear `dword_69B494`.
