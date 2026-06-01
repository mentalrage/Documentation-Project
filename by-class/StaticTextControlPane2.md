*** UID:0000E4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2

## Status

- Confidence: strong.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x0049a410-0x0049b915`
- Current recovered file: `source-3/simroot_v2/class_StaticTextControlPane2.cpp`

## Class Purpose

`StaticTextControlPane2` is an extended static/help text pane. It measures multiline text, positions and clamps its bounds relative to a target screen coordinate, applies alignment and padding, manages fade/opacity style state, owns an embedded [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md), and forwards layer/show/hide operations to that child pane. Callers can pass a [UID:00005C][FontStyle](by-class/FontStyle.md)-compatible record for style/color/rule configuration.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x0049a410-0x0049a8ab` | constructor | Construct `Pane`, initialize style descriptor and embedded part pane, measure text, clamp bounds, and apply opacity state. |
| `0x0049aa80-0x0049ab17` | layer/show/hide forwarding | Add/remove layer and show/hide both the parent pane and embedded help part. |
| `0x0049ab20-0x0049ab78` | `OnPaint` | Sets text/background color indexes and draws the frame/bounds region. |
| `0x0049b5f0-0x0049b6bb` | scalar deleting destructor | Destroys `SimpleUString`, embedded help pane, style descriptor allocation, and base `Pane`. |
| `0x0049b910-0x0049b915` | `GetControlTypeId` | Returns fixed type id `24`. |

## Evidence Notes

- Wave3 summary identifies measurement, multiline support, alignment, fade/opacity effects, and embedded help tooltip display.
- IDA MCP reports eight direct constructor callers.
- `MiniMapDialog` and `NewMailDialog` build local `FontStyle` objects before constructing static labels with this class.
- Constructor stores text in a fixed `0x20` wide-character buffer before assigning the displayed string. This may be a generated/local-buffer artifact worth checking before final struct layout.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents extended static/help text behavior, constructor/forwarding/paint/destructor/type-id ranges, embedded part-pane ownership, caller evidence, and local-buffer caveat; remaining completion gap is source-ready C++ detail.
- Before: the class index listed the method cluster and fixed type-id helper as ending at `0x0049b914`.
- Changed to: `0x0049b915`.
- Summary/evidence: IDA MCP reports `sub_49B910` size `0x5`, so the `retn 8` helper spans `0x0049b910-0x0049b915`.
