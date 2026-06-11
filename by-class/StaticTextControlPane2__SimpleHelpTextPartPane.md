*** UID:0000E5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2::SimpleHelpTextPartPane

## Status

- Confidence: strong for embedded subpane behavior; medium-high for exact source-level nested class spelling.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x00499fe0-0x0049a402`, `0x0049b560-0x0049b5a7`, and `0x004bafa0-0x004bb0da`

## Class Purpose

`SimpleHelpTextPartPane` is the embedded drawing pane inside [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md). It owns the help text string and line offsets, parses line breaks and tab-based inline formatting commands, and draws normal, outlined, or shadowed text lines.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00499fe0-0x0049a07f` | constructor | Construct `Pane`, install vtables, initialize `SimpleUString`, text offsets, and opacity/spacing state. |
| `0x0049a080-0x0049a297` | `OnPaint` | Clear background, set clip/style, parse text, and draw line segments. |
| `0x0049a2a0-0x0049a2c0` | raw line-layout setter | Store text-offset/spacing fields at offsets `+0xfc`, `+0x100`, and `+0x104`. |
| `0x0049a2d0-0x0049a32e` | raw opacity/state applier | Apply the optional style pointer at offset `+0x108` to the child pane state and opacity. |
| `0x0049a330-0x0049a402` | `DrawTextLine` | Apply line style and dispatch normal/outlined/shadowed text drawing. |
| `0x0049b560-0x0049b5a7` | scalar deleting destructor | Destroy text string and base pane, then optionally delete. |
| `0x004bafa0-0x004bb069` | `DrawOutlinedText` | Draw text offset in four directions and then center text. |
| `0x004bb080-0x004bb0da` | `DrawShadowedText` | Draw text and an offset shadow. |

## Evidence Notes

- `StaticTextControlPane2` constructs this object as `m_helpTextPart`, not as an independent top-level control.
- Live IDA reports two direct callers to `DrawTextLine`, both from `SimpleHelpTextPartPane::OnPaint`.
- `DrawTextLine` dispatches mode byte `0` to normal drawing, mode byte `1` to the outlined-text helper, and mode byte `3` to the shadowed-text helper.
- The outlined/shadowed helpers are shared with the HelpPane text renderer and chat/color UI callers, so their memory page remains parentless even though this class is one confirmed consumer.

## Current Caveats

- The text drawing behavior is strong; final nested class spelling and base-subobject names remain provisional.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:00011U][0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Evidence: the page documents embedded-subpane behavior, constructor/paint/draw/destructor/text-effect ranges, owning parent relationship, and caller evidence; confidence remains capped by generated class-name spelling and provisional base-subobject names.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, paint, draw-line, destructor, outlined-text, and shadowed-text helpers at `0x00499fe0`, `0x0049a080`, `0x0049a330`, `0x0049b560`, `0x004bafa0`, and `0x004bb080`. This is custom embedded UI drawing code, but class confidence is `78`, so the parent UID stays blank.
- 2026-06-05: A004 raised the class to `84/86`, attached it to [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md), removed stale recovered-file provenance, added the raw line-layout and opacity/state helpers, and documented shared text-effect fan-out.
  - Reasoning: the owning file and class now meet the parent gate, and live IDA evidence proves the embedded-subpane method set and shared text-effect helpers.
  - Summary and evidence: `0x00499fe0`, `0x0049a080`, `0x0049a330`, `0x0049b560`, `0x004bafa0`, and `0x004bb080` are modeled IDA functions; live caller checks show `DrawTextLine` is reached from `OnPaint`, outlined/shadowed helpers are also consumed by HelpPane/chat-color paths, and the final source spelling remains below final-reconstruction confidence.
