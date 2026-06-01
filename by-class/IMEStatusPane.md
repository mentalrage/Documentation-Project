*** UID:00006I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IMEStatusPane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_IMEStatusPane.cpp`
- Confidence: strong.

## Class Purpose

`IMEStatusPane` is the small ENG/IME mode label. It measures and positions status text near the lower-right screen edge, updates text on IME mode-change events, and paints a compact framed status indicator.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetText` | `0x004e70f0-0x004e71bc` | Clamps/copies status text, measures width, positions near screen edge, and invalidates. |
| `IMEStatusPane` | `0x004e71c0-0x004e728a` | Constructs base pane, clears text buffer, initializes text as `Closed`, attaches hidden to root pane. |
| `~IMEStatusPane` | `0x004e7290-0x004e72af` | Resets vtables and destroys base pane. |
| `OnIMEModeChange` | `0x004e72b0-0x004e72f8` | Handles IME mode event type `11` and switches text between `IME` and `ENG`. |
| `OnPaintFrame` | `0x004e7300-0x004e737b` | Paints background, outline, and current status text. |
| `ScalarDeletingDestructor` | `0x004e8800-0x004e8855` | Deleting destructor wrapper. |

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- IDA xrefs to `SetText` come from the constructor and mode-change handler.
- `class_IMEStatusPane.cpp.disabled` emits one adjustor thunk body but omits sibling thunk `0x004e8629`; IDA confirms both are real thunks.
- 2026-05-26 IDA MCP recheck records the omitted `0x004e8629` sibling in [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md); treat it as compiler-generated layout evidence, not a handwritten method.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: IME status label purpose, text update/paint lifecycle, constructor/destructor, mode-change handling, and adjustor-thunk caveat are documented with strong confidence; remaining work is detailed field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECandidateQueueAndDestructors`, and `IMEAdjustorThunks` cross-references plus IDA-confirmed method starts.
