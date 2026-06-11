*** UID:00006H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IMEPane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_IMEPane.cpp`
- Confidence: strong.

## Class Purpose

`IMEPane` is the process-level pane-side IME coordinator. It stores [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md), tracks focused text-entry panes in an embedded `List`, creates and destroys composition/candidate child panes in response to IME events, and provides `SetFocusPane` for text controls.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IMEPane` | `0x004e7f20-0x004e7ff5` | Constructs root IME pane, installs vtables, initializes focus list, stores singleton, and shows hidden/root pane. |
| `~IMEPane` | `0x004e8000-0x004e8098` | Marks child panes for deletion, destroys focus list, clears singleton, and tears down base pane. |
| `SetFocusPane` | `0x004e80a0-0x004e810b` | Removes an existing focus entry and optionally pushes the supplied pane into the focus list. |
| `UpdateFocusCaretAnchor` | [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) | Raw helper that derives candidate/composition anchor fields from the last focused text-entry pane. |
| `IsIMESupported` | `0x004e81a0-0x004e81a5` | Returns true. |
| `HandleIMEMessage` | `0x004e81b0-0x004e8433` | Creates/deletes composition and candidate child panes and dispatches candidate messages. |
| `ClearIMEPaneSingleton` | [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) | Tiny file-local helper that clears [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md). |
| `ScalarDeletingDestructor` | [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) | Deleting destructor wrapper for root IME pane cleanup. |

## Evidence Notes

- IDA MCP confirms all listed function starts and sizes.
- IDA xrefs to `0x004e7f20` show construction from the application startup path at `0x004f639e`.
- IDA xrefs to `0x004e80a0` include text-edit and self-save text input paths at `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, and `0x00595463`.
- IDA xrefs to `0x0069b458` show reads/writes across `IMEPane`, composition, candidate, text-edit, and startup/teardown paths.
- 2026-05-26 IDA MCP storage check confirms [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) as a 4-byte `.data` singleton with 17 data references.
- 2026-06-08 A001 Batch131 split the raw focus/caret anchor helper and scalar deleting destructor into exact pages. [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) reads the focus-list count at `this+0x110` and calls text-entry geometry helpers; [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) is reached by the two IMEPane adjustor thunks and clears child/list/singleton state.
- [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) is file-local static cleanup support for this source family rather than an `IMEPane` method, but it is listed here because it clears this class's singleton.
- Direct child assignments are now justified for [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) and [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md): both children clear `85/85`, and this class now clears `85/90`.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md)
- [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md)
- [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md)
- [UID:00006J][InputMan](by-class/InputMan.md)

## Changes

- 2026-06-08 A001 Batch131 focus/destructor split:
  - Before: score was `82/88`.
  - Changed to: score `85/90`.
  - Summary/evidence: exact child pages [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) and [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) now document the raw focus/caret helper and scalar deleting destructor with live IDA caller/callee/disassembly evidence; [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md) documents the associated file-local singleton cleanup helper.
- Completion/confidence score update: existed before as `0/0`; changed to `82/88`. Summary: process-level IME coordinator role, singleton, focus list, composition/candidate child lifecycle, methods, startup/focus xrefs, and storage evidence are documented with strong confidence; remaining gaps are mainly full internal field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECandidateQueueAndDestructors`, `IMEAdjustorThunks`, `g_pIMEPane`, and InputMan references.
- 2026-06-05: Marked reconstructable and attached to [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the process-level IME pane coordinator unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000K5`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e7f20`, `0x004e8000`, `0x004e80a0`, `0x004e81a0`, `0x004e81b0`, `0x004e85b0`, and `0x004e8720`; constructor caller remains the application startup path at `0x004f639e`. The class score `82/88` and parent score `88/82` meet the 80/80 attachment gate.
