*** UID:0000E5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2::SimpleHelpTextPartPane

## Status

- Confidence: strong for embedded subpane behavior; medium for generated class name spelling.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x00499fe0-0x0049a402`, `0x0049b560-0x0049b5a7`, and `0x004bafa0-0x004bb0da`
- Current recovered file: `source-3/simroot_v2/class_StaticTextControlPane2__SimpleHelpTextPartPane.cpp`

## Class Purpose

`SimpleHelpTextPartPane` is the embedded drawing pane inside [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md). It owns the help text string and line offsets, parses line breaks and tab-based inline formatting commands, and draws normal, outlined, or shadowed text lines.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00499fe0-0x0049a07f` | constructor | Construct `Pane`, install vtables, initialize `SimpleUString`, text offsets, and opacity/spacing state. |
| `0x0049a080-0x0049a297` | `OnPaint` | Clear background, set clip/style, parse text, and draw line segments. |
| `0x0049a330-0x0049a402` | `DrawTextLine` | Apply line style and dispatch normal/outlined/shadowed text drawing. |
| `0x0049b560-0x0049b5a7` | scalar deleting destructor | Destroy text string and base pane, then optionally delete. |
| `0x004bafa0-0x004bb069` | `DrawOutlinedText` | Draw text offset in four directions and then center text. |
| `0x004bb080-0x004bb0da` | `DrawShadowedText` | Draw text and an offset shadow. |

## Evidence Notes

- `StaticTextControlPane2` constructs this object as `m_helpTextPart`, not as an independent top-level control.
- IDA MCP reports two direct callers to `DrawTextLine`, both from `SimpleHelpTextPartPane::OnPaint`.

## Current Caveats

- Generated destructor support references unrelated owner names. The text drawing behavior is strong; base-subobject names remain provisional.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:00011U][0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md)
- [UID:00016E][0x004bafa0-0x004bb0da.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0da.SimpleHelpTextPartPaneTextEffects.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Evidence: the page documents embedded-subpane behavior, constructor/paint/draw/destructor/text-effect ranges, owning parent relationship, and caller evidence; confidence remains capped by generated class-name spelling and provisional base-subobject names.
