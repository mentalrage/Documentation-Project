*** UID:0000R7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pIMEPane

## Status

- Address: [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Observed aliases: `g_pIMEPane`, `DAT_0069b458`, `dword_69B458`
- Confidence: strong.

## Purpose

`g_pIMEPane` points to the active [UID:00006H][IMEPane](by-class/IMEPane.md). It is used by the pane-side IME UI and text-entry controls to find the active focus-pane list, composition/candidate popup state, caret anchor position, and currently focused input control.

## Evidence Notes

- IDA MCP xrefs to `0x0069b458` include writes in `IMEPane::IMEPane` and clear helpers/destructors at `0x004e85b0` and `0x004e8720`.
- IDA MCP xrefs include IME popup methods `0x004e7470`, `0x004e7640`, `0x004e7930`, `0x004e7b70`, and `0x004e81b0`.
- IDA MCP xrefs include text-entry callers around `0x0058dce0`, `0x0058e140`, `0x0058ea80`, and `0x00595390`, matching text-edit/text-box focus registration.
- 2026-05-26 IDA MCP read-only storage check reports item head `0x0069b458`, size 4, segment `.data`, IDA name `dword_69B458`, and 17 data references. See [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md).

## Ownership Notes

- Keep this global with [UID:0000K5][IMEPanes](by-file/IMEPanes.md), not with [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` feeds IME events from Win32, but this singleton owns the pane-side state and child popup lifetimes.
- `DAT_0069b458` and `dword_69B458` should be normalized to `g_pIMEPane` where current code is using the IME singleton.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:00006H][IMEPane](by-class/IMEPane.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents memory range, aliases, singleton purpose, IME/text-entry xrefs, storage check, ownership notes, alias normalization guidance, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000K5][IMEPanes](by-file/IMEPanes.md). Evidence: live IDA MCP reports 17 xrefs to `0x0069b458`; decompilation confirms constructor `0x004e7f20`, clear helper `0x004e85b0`, and destructor path `0x004e8720` write/clear `dword_69B458`.
