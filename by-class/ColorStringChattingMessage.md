*** UID:00002Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ColorStringChattingMessage

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)

## Class Purpose

`ColorStringChattingMessage` is the chat message render object. It stores wide text, foreground/background palette IDs, optional custom RGB colors, and draw behavior for both low-resolution and high-resolution chat layouts.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002GD][0x00483490-0x00483541.ColorStringChattingMessageConstructor](by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md) | `0x00483490-0x00483541` | Allocates/copies wide text and stores color/custom RGB state. |
| [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md) | `0x00483550-0x004835a9` | Releases the owned text buffer and destroys the base object. |
| [UID:0002GF][0x004835b0-0x0048362b.ColorStringChattingMessageClone](by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md) | `0x004835b0-0x0048362b` | Allocates a duplicate message object preserving text and colors. |
| [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) | `0x00483630-0x0048369a` | Measures wrapped wide text and returns at least one display line. |
| [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md) | `0x004836a0-0x004839c0` | Draws low-res `CHATBACK` background/text or high-res outlined/custom-color text, including switch/mapping tail tables. |
| [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md) | `0x00483e60-0x00483ef7` | Scalar deleting destructor wrapper is documented inside the shared compiler-generated chat UI destructor glue family. |

## Evidence Notes

- IDA MCP confirms exact constructor, destructor body, clone, line-count, draw, and scalar deleting destructor ranges.
- IDA vtable data points `0x0061526c` to scalar deleting destructor `0x00483e60`, `0x00615278` to clone `0x004835b0`, `0x0061527c` to line count `0x00483630`, and `0x00615280` to draw `0x004836a0`.
- `FolderTreePane::AddChattingMessage` constructs this class before adding it to the message collection.
- `ChattingPane::OnPaint` dispatches through message objects when painting visible chat lines.
- `Draw` owns the jump table at `0x0048391c-0x00483930` and the byte-map table at `0x00483930-0x004839bf`; `0x004839bf-0x004839c0` is one alignment byte before the destructor-glue family.
- `Draw` calls the generic [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), so those helpers are not hair-color-list-local methods.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001X][ChattingPane](by-class/ChattingPane.md)
- [UID:0002GD][0x00483490-0x00483541.ColorStringChattingMessageConstructor](by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md)
- [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md)
- [UID:0002GF][0x004835b0-0x0048362b.ColorStringChattingMessageClone](by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md)
- [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md)
- [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md)
- [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)

## Changes

- What existed before: the page documented chat message object purpose, core methods, callers, and shared draw helper dependency, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, clone, draw, destructor, chat-pane usage, and helper ownership caveat are documented; exact object layout and source-level declaration remain incomplete.
- 2026-05-31: Updated completion/confidence from `76/86` to `86/91`.
  - Before: method notes used start addresses only and did not separate the destructor body, line-count virtual, draw tail tables, or scalar deleting wrapper context.
  - After: exact by-memory child pages cover constructor, destructor body, clone, line-count, draw-with-tail-tables, and the scalar deleting wrapper inside the shared chat UI destructor glue family.
  - Summary and evidence: IDA MCP function iteration, decompilation, vtable data review, draw tail-table xrefs, and cleanup-glue review support the split; remaining uncertainty is mostly final source-level field names and generated-wrapper naming.
- 2026-06-05: Marked reconstructable and attached to [UID:0000I5][Chatting](by-file/Chatting.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000I5`.
  - Evidence: live IDA MCP confirms modeled method starts at `0x00483490`, `0x00483550`, `0x004835b0`, `0x00483630`, `0x004836a0`, and `0x00483e60`, with chat callers into constructor/destructor paths; this class and the parent file both meet the 80% completion/confidence attachment gate.
- 2026-06-05: Removed the stale recovered-source pointer from the status block so this page relies only on project-documentation and live IDA evidence.
