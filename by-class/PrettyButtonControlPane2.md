*** UID:0000AS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PrettyButtonControlPane2

## Status

- Confidence: strong.
- Likely source file: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- Memory range: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- Current recovered file: `source-3/simroot_v2/class_PrettyButtonControlPane2.cpp`

## Class Purpose

`PrettyButtonControlPane2` is an alternate styled button that stores EPF/PAL resource names and explicit normal/pressed/hover/disabled frame ids. It has animation-state handling, frame painting, click notification, and cleanup for attached objects and strings.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PrettyButtonControlPane2` | `0x0054b8c0-0x0054b98c` | Constructs frame id/resource-string state and clears attached object pointer. |
| `SetState` | `0x0054ba30-0x0054ba91` | Starts or stops 150 ms hover/press animation scheduling. |
| `OnPaint` | `0x0054baa0-0x0054bb47` | Draws configured EPF frame with palette. |
| `OnClick` | `0x0054bb50-0x0054bb9e` | Handles click action types and notifies parent. |
| Destructor/thunks | `0x0054bb89-0x0054bc3c` | Adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- Wave3 effective grade is 97.6.
- IDA MCP reports 2 direct constructor xrefs to `0x0054b8c0`.

## Cross-References

- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)

## Changes

- Before: the containing `PrettyButtonControls` memory page ended at `0x0054bcbc`.
- Changed to: the page ends at `0x0054bcbd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the previous endpoint omitted the final `retn 4` operand byte in the neighboring `PrettyButtonControlPane` destructor.
- Before: completion/confidence metadata were `0/0` despite method map, resource/frame role, constructor xrefs, and endpoint correction.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, state/animation scheduling, EPF/PAL paint, click notification, destructor/thunks, two constructor xrefs, and corrected containing range are documented; remaining gaps are exact fields and reconstructed C++.
