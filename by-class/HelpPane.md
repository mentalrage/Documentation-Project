*** UID:000063 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HelpPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HelpPane.cpp`
- Confidence: strong.

## Class Purpose

`HelpPane` is the reusable styled tooltip pane. It measures multiline UTF-16 help text, computes a tooltip rectangle from parent scroll position and alignment parameters, clamps the rectangle to screen bounds, creates an embedded [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md), and applies optional [UID:00005C][FontStyle](by-class/FontStyle.md)-compatible state such as foreground/background values and opacity.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HelpPane` | `0x004c6960-0x004c6dac` | Constructs the styled tooltip base and embedded text part. |
| `~HelpPane` | `0x004c6db0-0x004c6e49` | Releases text/style storage, embedded text part, and base pane state. |
| `OnPaintFrame` | `0x004c6e50-0x004c6ea9` | Paints the tooltip background and text region with configured colors. |
| `ScalarDeletingDestructor` | `0x004ce3f0-0x004ce42b` | Deleting destructor wrapper. |

## Evidence Notes

- IDA decompilation shows `HelpPane::HelpPane` constructing a `Pane`, an embedded `HelpPane::SimpleHelpTextPartPane` at offset `0x124`, a `SimpleUString` help text, and a style/vector record.
- The style/vector record is layout-compatible with [UID:00005C][FontStyle](by-class/FontStyle.md): enabled byte, two float fields, two scalar values, and a 16-byte-rule vector triplet.
- IDA shows `SimpleHelpPane2` and the adjacent [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) at `0x004c7680` calling `HelpPane::HelpPane`.
- The generated `HelpPane` source matches the core placement, text measurement, screen clamp, and opacity behavior.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: tooltip purpose, constructor/destructor/paint methods, embedded text part, style compatibility, factory caller, and screen-clamp behavior are documented with strong confidence; remaining work is deeper field-level naming and final C++ reconstruction. Evidence: `HelpPaneCore`, `HelpTooltipDestructorThunks`, `SimpleHelpPane2Factory`, `FontStyle`, and embedded text-part cross-references.
