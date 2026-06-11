*** UID:000063 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HelpPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HelpPane.cpp`
- Confidence: strong for reusable tooltip behavior, exact core method ranges, fade-state helper relationship, and HelpPanes ownership; final field names and source split remain open.

## Class Purpose

`HelpPane` is the reusable styled tooltip pane. It measures multiline UTF-16 help text, computes a tooltip rectangle from parent scroll position and alignment parameters, clamps the rectangle to screen bounds, creates an embedded [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md), and applies optional [UID:00005C][FontStyle](by-class/FontStyle.md)-compatible state such as foreground/background values and opacity.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HelpPane` | `0x004c6960-0x004c6dac` | Constructs the styled tooltip base and embedded text part. |
| `~HelpPane` | `0x004c6db0-0x004c6e49` | Releases text/style storage, embedded text part, and base pane state. |
| `OnPaintFrame` | `0x004c6e50-0x004c6ea9` | Paints the tooltip background and text region with configured colors. |
| `UpdateFadeState` / raw helper | `0x004c6eb0-0x004c6f89` | Updates base and embedded text-pane fade/mode state; currently has no IDA function object or external xrefs. |
| `ScalarDeletingDestructor` | `0x004ce3f0-0x004ce42b` | Deleting destructor wrapper. |

## Evidence Notes

- IDA decompilation shows `HelpPane::HelpPane` constructing a `Pane`, an embedded `HelpPane::SimpleHelpTextPartPane` at offset `0x124`, a `SimpleUString` help text, and a style/vector record.
- The style/vector record is layout-compatible with [UID:00005C][FontStyle](by-class/FontStyle.md): enabled byte, two float fields, two scalar values, and a 16-byte-rule vector triplet.
- IDA shows `SimpleHelpPane2` and the adjacent [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) at `0x004c7680` calling `HelpPane::HelpPane`.
- The generated `HelpPane` source matches the core placement, text measurement, screen clamp, and opacity behavior.
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) now records a 2026-06-06 IDA recheck: no external xrefs into the raw body, four calls to [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and touched offsets matching constructor-initialized fade/style fields and `OnPaintFrame` colors.
- Parent attachment to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is now allowed: the class page is at the 80% completion gate, the parent file is over the gate, and the exact core/fade/helper pages all place the class in the HelpPanes source family.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: tooltip purpose, constructor/destructor/paint methods, embedded text part, style compatibility, factory caller, and screen-clamp behavior are documented with strong confidence; remaining work is deeper field-level naming and final C++ reconstruction. Evidence: `HelpPaneCore`, `HelpTooltipDestructorThunks`, `SimpleHelpPane2Factory`, `FontStyle`, and embedded text-part cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the reusable tooltip pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `78/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004c6960`, `0x004c6db0`, `0x004c6e50`, and `0x004ce3f0`, plus constructor callers from the simple-help factory paths.
- 2026-06-06: Added fade-state helper and parent attachment.
  - Before: completion/confidence were `78/86`; the method list omitted the adjacent raw fade-state helper, and `AUTOGEN_PARENT_UID` was blank because the page was below the completion gate.
  - After: completion/confidence are `80/88`, `AUTOGEN_PARENT_UID` is [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and the method/evidence/cross-reference sections include [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md).
  - Summary/evidence: the 2026-06-06 live IDA recheck for [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) confirmed the exact raw body, no external xrefs, four `PaneSetMode` calls, constructor-backed style fields, and paint-color state matching `HelpPane`.
