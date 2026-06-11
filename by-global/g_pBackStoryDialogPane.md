*** UID:0000Q9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBackStoryDialogPane

## Status

- Address: `0x0069b498` (`dword_69B498` in IDA)
- Likely type: `BackStoryDialogPane*`
- Likely owner file: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- Confidence: strong

## Purpose

`g_pBackStoryDialogPane` stores the active main-menu back-story dialog singleton. The constructor writes it, the clear helper and scalar deleting destructor clear it, and the main-menu singleton cleanup helper closes it if it is live.

## Evidence

- IDA decompilation shows the underlying storage as `dword_69B498`.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 reports:
  - close/check from `CloseMainMenuDialogSingletons` at `0x004f69ce`;
  - constructor writes at `0x005000e5` and `0x005000ec`;
  - clear-helper write at `0x00502390`;
  - scalar destructor write at `0x00502606`.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b498-0x0069b49c`, bytes `ff ff ff ff`, initialized dword `0xffffffff`, and the same five xrefs: main-menu cleanup read, constructor publish/fallback writes, clear helper, and scalar deleting destructor clear.
- [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md) now documents the exact memory slot and can attach here as the direct global-data parent once both pages clear the corrected `85/85` assignment gate.

## Ownership Decision

Declare this with the login/main-menu story dialog module, not with in-game [UID:0000HO][BackPane](by-file/BackPane.md). It is lifecycle-bound to [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md).

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, type/owner, singleton purpose, constructor/clear/destructor xrefs, ownership decision away from in-game `BackPane`, and class/memory/global refs.
- 2026-06-05: Marked reconstructable under [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md). Evidence: live IDA MCP reports five xrefs to `0x0069b498`; decompilation confirms `0x00500090` writes the singleton, `0x00502390` and `0x00502600` clear it, and `0x004f69a0` closes it through the main-menu singleton cleanup helper.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `86/84`, which left the direct global parent below the supervisor `85/85` confidence gate for the exact memory slot.
  - After: `88/87`.
  - Evidence: live IDA MCP `py_eval` reconfirmed the exact four-byte item, initial bytes/dword, and all five lifecycle xrefs; the exact memory slot page now carries the storage-side evidence while this page owns the canonical global symbol and BackStoryDialogPane source owner.
