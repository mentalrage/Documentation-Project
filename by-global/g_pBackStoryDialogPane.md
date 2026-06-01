*** UID:0000Q9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

- Current `simroot_v2/class_BackStoryDialogPane.cpp` emits `g_pBackStoryDialogPane` but does not include a concrete address in the active source view.
- `class_BackStoryDialogPane.meta_wave3` and IDA decompilation show the underlying storage as `dword_69B498`.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 reports:
  - close/check from `CloseMainMenuDialogSingletons` at `0x004f69ce`;
  - constructor writes at `0x005000e5` and `0x005000ec`;
  - clear-helper write at `0x00502390`;
  - scalar destructor write at `0x00502606`.

## Ownership Decision

Declare this with the login/main-menu story dialog module, not with in-game [UID:0000HO][BackPane](by-file/BackPane.md). It is lifecycle-bound to [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md).

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, type/owner, singleton purpose, constructor/clear/destructor xrefs, ownership decision away from in-game `BackPane`, and class/memory/global refs.
