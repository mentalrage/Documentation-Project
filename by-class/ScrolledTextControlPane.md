*** UID:0000CI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrolledTextControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- Main address ranges: `0x004ff040-0x004ff3fc` and `0x00502b60-0x00502c0c`
- Current recovered file: `source-3/simroot_v2/class_ScrolledTextControlPane.cpp`

## Class Purpose

`ScrolledTextControlPane` is a control type `8` widget for auto-scrolling text. It loads text from a DAT/resource path, uses a temporary [UID:0000EO][TextEditPane](by-class/TextEditPane.md) to render the content to an embedded tile/image context, then scrolls that pre-rendered text image during timer ticks.

Its picture-resource sibling is [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md), which keeps the same timer/scrolling control role but loads EPF frame and palette resources instead of DAT text.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x004ff040-0x004ff283` | constructor | Load DAT text, convert through `TextEditScrap`, render with a temporary `TextEditPane`, copy image context, and start timer. |
| `0x004ff290-0x004ff2fb` | destructor | Destroy embedded tile context and pane state. |
| `0x004ff300-0x004ff356` | `OnTimerTick` | Increment scroll position, wrap, invalidate, and notify parent. |
| `0x004ff360-0x004ff3fc` | `OnDraw` | Fill background and blit the scrolled text image from embedded render context. |
| `0x00502b60-0x00502c0c` | scalar deleting destructor | Deleting-destructor wrapper around the same resource cleanup. |

## Evidence Notes

- Constructor summary: loads DAT text into an internal `TextEditPane` and initializes scroll state.
- IDA MCP reports four direct constructor callers.
- `OnTimerTick` increments by one and wraps to zero after maximum scroll.

## Cross-References

- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- [UID:00019W][0x004ff040-0x00502c0c.ScrolledTextControlPane](by-memory/0x004ff040-0x00502c0c.ScrolledTextControlPane.md)
- [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NI`.
  - Before: The DAT-text scroller remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ScrolledTextControlPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms the constructor/destructor/timer/draw/deleting-destructor starts at `0x004ff040`, `0x004ff290`, `0x004ff300`, `0x004ff360`, and `0x00502b60`; parent [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md) records the same DAT-text scroller ownership.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/84`.
  - Before: The page was unevaluated despite documenting DAT text loading, temporary `TextEditPane` rendering, timer wrapping, paint behavior, and destructor range.
  - After: Scored as high completion and strong confidence for the auto-scrolling text control.
  - Evidence: Existing method-family table, constructor caller evidence, timer behavior, and text/picture control cross-references support the score.
