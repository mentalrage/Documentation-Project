*** UID:0000AR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PrettyButtonControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- Memory range: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- Current recovered file: `source-3/simroot_v2/class_PrettyButtonControlPane.cpp`

## Class Purpose

`PrettyButtonControlPane` is a styled button with frame selection, callback object ownership, enable/hover animation state, EPF rendering, click handling, and scalar deleting destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PrettyButtonControlPane` | `0x0054b5e0-0x0054b6a3` | Initializes frame ids, labels, callback/animation state, and base button state. |
| `SetCallback` | `0x0054b720-0x0054b743` | Replaces callback object and releases previous callback. |
| `SetEnabled` | `0x0054b750-0x0054b7b1` | Toggles enabled state and hover animation scheduling. |
| `OnPaint` | `0x0054b7c0-0x0054b878` | Renders selected EPF frame and disabled overlay. |
| `OnClick` | `0x0054b880-0x0054b8b8` | Handles click, timer scheduling, and parent notification. |
| Destructor/thunks | `0x0054bb9f-0x0054bcbd` | Adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- Wave3 effective grade is 95.9.
- IDA MCP reports 30 direct constructor xrefs to `0x0054b5e0`.

## Cross-References

- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)

## Changes

- Before: the `PrettyButtonControls` memory page and `PrettyButtonControlPane` destructor/thunks ended at `0x0054bcbc`.
- Changed to: both end at `0x0054bcbd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054bcbc` is the final operand byte of the scalar deleting destructor's `retn 4`.
- Before: completion/confidence metadata were `0/0` despite method map, constructor fan-in, endpoint correction, and source/memory links.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, callback setter, enabled-state/animation, paint, click handling, destructor/thunks, 30 constructor xrefs, and endpoint correction are documented; remaining gaps are exact field names and reconstructed C++.
- Before: reconstructable/autogen parent metadata were blank.
- Changed to: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000MP`.
- Evidence: the class page documents NexusTK-owned button behavior, method ranges, constructor fan-in, and the owning [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) source root, which now has a valid projected path.
