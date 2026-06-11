*** UID:00006G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IMECompositionPane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered files: `source-3/simroot_v2/class_IMECompositionPane.cpp`; `SetCompositionString` is currently emitted in `class_FittingRoomDownloadControlPane.cpp`
- Confidence: strong for behavior and ownership.

## Class Purpose

`IMECompositionPane` displays the active IME composition string near the text caret. It supports dragging the composition popup, accepts composition text from key/IME messages, measures and clamps popup geometry, stores the text buffer, and paints the composition string plus caret rectangle.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `IMECompositionPane` | `0x004e7380-0x004e744d` | Constructs base pane, installs vtables, clears 256-wchar composition buffer, attaches to root pane. |
| `~IMECompositionPane` | `0x004e7450-0x004e746f` | Resets vtables and destroys base pane. |
| `SetCompositionString` | [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) | Measures text, finds focused text-edit caret, positions/clamps composition popup, copies text, updates width, and invalidates. |
| `OnMouseEvent` | `0x004e7640-0x004e7809` | Handles dragging and parent visibility/mode changes. |
| `OnKeyEvent` | `0x004e7810-0x004e7838` | Handles Enter/composition-commit style event and calls `SetCompositionString`. |
| `OnPaint` | `0x004e7840-0x004e7912` | Paints frame/background, composition text, and caret rectangle. |
| `GetCompositionWidth` | `0x004e7920-0x004e7927` | Returns stored composition width. |
| `ScalarDeletingDestructor` | [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) | Deleting destructor wrapper. |

## Evidence Notes

- IDA MCP confirms all listed function starts and sizes.
- IDA xrefs to `0x004e7470` show the direct caller is `IMECompositionPane::OnKeyEvent` at `0x004e782d`.
- Current generated source owns `0x004e7470` through `FittingRoomDownloadControlPane`; the body references [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md), text-edit caret helpers, screen bounds, and the composition text buffer, making IME composition ownership stronger than fitting-room ownership.
- 2026-05-26 recheck records exact helper and storage pages for [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md).
- 2026-06-08 A001 Batch131 split [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) as the exact scalar deleting destructor reached by composition-pane adjustor thunks at `0x004e85f2` and `0x004e85fd`.
- Direct child assignment is now justified for [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md): the child clears `85/89`, and this class now clears `85/88` with constructor/destructor, composition-string, mouse/key/paint, and source-file parent evidence.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-06-08 A001 Batch131 scalar-destructor split:
  - Before: score was `80/86`.
  - Changed to: score `85/88`.
  - Summary/evidence: exact child page [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) now documents the scalar deleting destructor with live IDA caller/callee evidence, closing the strict direct-parent gate for that child.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: composition popup purpose, constructor/destructor/set-string/mouse/key/paint methods, generated-owner correction, text-edit caret relationship, and singleton storage are documented with strong confidence; remaining work is detailed field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECompositionSetCompositionString`, `IMEAdjustorThunks`, `g_pIMEPane`, TextEditPane, and FittingRoom caveat references.
- 2026-06-05: Marked reconstructable and attached to [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the IME composition pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000K5`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e7380`, `0x004e7450`, `0x004e7470`, `0x004e7640`, `0x004e7810`, `0x004e7840`, `0x004e7920`, and `0x004e86c0`, with `SetCompositionString` called from `0x004e782d`. The class score `80/86` and parent score `88/82` meet the 80/80 attachment gate.
