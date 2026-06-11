*** UID:0000E4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2

## Status

- Confidence: strong.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- Main address ranges: `0x0049a410-0x0049b915`

## Class Purpose

`StaticTextControlPane2` is an extended static/help text pane. It measures multiline text, positions and clamps its bounds relative to a target screen coordinate, applies alignment and padding, manages fade/opacity style state, owns an embedded [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md), and forwards layer/show/hide operations to that child pane. Callers can pass a [UID:00005C][FontStyle](by-class/FontStyle.md)-compatible record for style/color/rule configuration.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x0049a410-0x0049a8ac` | constructor | Construct `Pane`, initialize style descriptor and embedded part pane, measure text, clamp bounds, and apply opacity state. |
| `0x0049a8b0-0x0049a945` | raw non-deleting destructor helper | Destroy the embedded text part and local rule-vector storage, then chain base pane teardown. |
| `0x0049a950-0x0049aa6d` | raw bounds/update helper | Recompute aligned bounds, clamp against screen dimensions, and forward the rectangle to parent/child pane virtuals. |
| `0x0049aa80-0x0049ab17` | layer/show/hide forwarding | Add/remove layer and show/hide both the parent pane and embedded help part. |
| `0x0049ab20-0x0049ab78` | `OnPaint` | Sets text/background color indexes and draws the frame/bounds region. |
| `0x0049ab80-0x0049ac57` | raw style-state applier | Reapply parent style state and propagate the child style/opacity state to the embedded text part. |
| `0x0049b5f0-0x0049b6bb` | scalar deleting destructor | Destroys `SimpleUString`, embedded help pane, style descriptor allocation, and base `Pane`. |
| `0x0049b910-0x0049b915` | `GetControlTypeId` | Returns fixed type id `24`. |

## Evidence Notes

- Live IDA on 2026-06-05 identifies measurement, multiline support, alignment, fade/opacity effects, and embedded help tooltip display from constructor and helper bodies.
- IDA MCP reports eight direct constructor callers.
- `MiniMapDialog` and `NewMailDialog` build local `FontStyle` objects before constructing static labels with this class.
- Constructor stores text in a fixed `0x20` wide-character buffer before assigning the displayed string. This may be a generated/local-buffer artifact worth checking before final struct layout.
- The broad historical range overlaps sibling rows that remain owned elsewhere: SliderControlPane destructor `0x0049b5b0`, TextEditControlPane destructor [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md), TargetOptionEditControlPane destructor `0x0049b740`, TextButtonControlPane destructor `0x0049b7a0`, RectangleControlPane type id [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md), and ScrollableControlPane type id [UID:0002PE][0x0049b900-0x0049b905.ScrollableControlPaneTypeId](by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md).

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)

## Changes

- 2026-06-05: A004 raised the class to `88/90`, removed stale recovered-file provenance, added live raw helper/destructor coverage at `0x0049a8b0`, `0x0049a950`, and `0x0049ab80`, and documented the sibling rows inside the broad historical range.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents extended static/help text behavior, constructor/forwarding/paint/destructor/type-id ranges, embedded part-pane ownership, caller evidence, and local-buffer caveat; remaining completion gap is source-ready C++ detail.
- Before: the class index listed the method cluster and fixed type-id helper as ending at `0x0049b914`.
- Changed to: `0x0049b915`.
- Summary/evidence: IDA MCP reports the type-id helper at `0x0049b910` as size `0x5`, so the `retn 8` helper spans `0x0049b910-0x0049b915`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, layer/show/hide forwarding, paint, scalar deleting destructor, and type-id helper at `0x0049a410`, `0x0049aa80`, `0x0049ab20`, `0x0049b5f0`, and `0x0049b910`; both class (`86/88`) and parent file (`86/80`) meet the 80/80 gate.
