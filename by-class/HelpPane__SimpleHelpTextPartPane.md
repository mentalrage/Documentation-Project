*** UID:000064 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HelpPane__SimpleHelpTextPartPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Confidence: strong for class ownership, method boundaries, style-state behavior, and destructor linkage; final private helper names and exact source spelling remain open.

## Class Purpose

`HelpPane__SimpleHelpTextPartPane` is the embedded text renderer used by [UID:000063][HelpPane](by-class/HelpPane.md). It stores the tooltip text, optionally consumes a style array, applies per-style opacity/mode state, and draws each line as normal, outlined, or shadowed text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpTextPartPane` | `0x004c65a0-0x004c6622` | Constructs pane base, vtables, text string, optional style pointer, and default opacity. |
| `DrawText` | `0x004c6630-0x004c6817` | Splits text by CR/LF/tab and draws each line with optional per-line style records. |
| raw style-state helper | `0x004c6820-0x004c687e` | No modeled function object or external entry; checks the style pointer at `this +0xfc`, updates pane mode through [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and mirrors accepted opacity into `this +0x90`. |
| `DrawStyledTextSegment` | `0x004c6880-0x004c6953` | Applies color, font style, and render mode before dispatching normal/outlined/shadowed drawing. |
| `ScalarDeletingDestructor` | `0x004ce620-0x004ce668` | Releases the text string and pane base, then optionally deletes storage. |

## Evidence Notes

- Live IDA on 2026-06-05 confirms modeled starts and sizes for the constructor (`0x82`), text draw path (`0x1e7`), styled segment helper (`0xd3`), and scalar deleting destructor (`0x48`).
- The text draw path calls [UID:00005C][FontStyle](by-class/FontStyle.md)'s bounded rule lookup at `0x00499f60`, normal text drawing helpers, the draw callback slot at `0x0069b3fc`, and the local styled segment helper.
- The styled segment helper dispatches to the same shared outlined/shadowed text-effect helpers used by StaticText2: `0x004bafa0` and `0x004bb080`.
- The 2026-06-06 [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) refresh splits the gap between `DrawText` and `DrawStyledTextSegment` into padding, a raw style-state helper at `0x004c6820-0x004c687e`, and padding. The helper has no external xrefs, but its internal behavior matches the class' style-pointer/opacity fields and calls [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) with modes `1` and `3`.
- IDA confirms all listed starts and shows `HelpPane::HelpPane` constructing the embedded text part directly.
- This class is not the same recovered owner as [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md), even though both use similar text-effect helper concepts.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)

## Changes

- 2026-06-05: A004 raised the page to `82/86`, attached it to [UID:0000JU][HelpPanes](by-file/HelpPanes.md), removed stale recovered-file provenance, and added live evidence for the four method starts, FontStyle rule lookup, and shared outlined/shadowed text-effect calls.
- 2026-06-06 A001 raw style-state helper sync: raised completion/confidence to `84/88`, added the exact `0x004c6820-0x004c687e` helper row, and tied the class' style pointer/opacity fields to the newly documented [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) caller evidence in [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md).
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: embedded tooltip text renderer role, constructor/draw/destructor methods, style consumption, and distinction from the similarly named StaticTextControlPane helper are documented; remaining work is lower-level draw-state detail and final source reconstruction. Evidence: `HelpPaneCore`, `HelpPane`, and `StaticTextControlPane` cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the embedded tooltip text renderer unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; parent attachment was deferred at that time because the class score was below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004c65a0`, `0x004c6630`, `0x004c6880`, and `0x004ce620`, matching the documented embedded HelpPane text-renderer role.
