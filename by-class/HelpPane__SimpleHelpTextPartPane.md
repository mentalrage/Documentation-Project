*** UID:000064 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HelpPane__SimpleHelpTextPartPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HelpPane__SimpleHelpTextPartPane.cpp`
- Confidence: strong.

## Class Purpose

`HelpPane__SimpleHelpTextPartPane` is the embedded text renderer used by [UID:000063][HelpPane](by-class/HelpPane.md). It stores the tooltip text, optionally consumes a style array, and draws each line as normal, outlined, or shadowed text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpTextPartPane` | `0x004c65a0-0x004c6622` | Constructs pane base, vtables, text string, optional style pointer, and default opacity. |
| `DrawText` | `0x004c6630-0x004c6817` | Splits text by CR/LF/tab and draws each line with optional per-line style records. |
| `DrawStyledTextSegment` | `0x004c6880-0x004c6953` | Applies color, font style, and render mode before dispatching normal/outlined/shadowed drawing. |
| `ScalarDeletingDestructor` | `0x004ce620-0x004ce668` | Releases the text string and pane base, then optionally deletes storage. |

## Evidence Notes

- IDA confirms all listed starts and shows `HelpPane::HelpPane` constructing the embedded text part directly.
- This class is not the same recovered owner as [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md), even though both use similar text-effect helper concepts.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: embedded tooltip text renderer role, constructor/draw/destructor methods, style consumption, and distinction from the similarly named StaticTextControlPane helper are documented; remaining work is lower-level draw-state detail and final source reconstruction. Evidence: `HelpPaneCore`, `HelpPane`, and `StaticTextControlPane` cross-references.
