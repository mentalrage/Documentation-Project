*** UID:000087 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MessageShowPane

## Status

- Confidence: strong for class role and method boundaries; medium for final source-file grouping.
- Likely source file: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), or a compact section of [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Main address range: [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- Generated recovered file lead: `source-3/simroot_v2/class_MessageShowPane.cpp` (not authoritative; IDA MCP is the evidence source for boundaries/behavior).
- Parent/C++ status: reconstructable and attached to [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md). Keep final class C++ blank until the `MessageShowPane.cpp` versus `MessageDialogs.cpp` source split, base/interface names, and helper names reach final-source quality.

## Class Purpose

`MessageShowPane` is a floating message overlay pane. It copies wide text into an internal buffer, measures and wraps lines to a 288-pixel width, anchors the pane near the right edge of the play area, and emits layered text buttons for shadow/face palette drawing.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00521da0-0x00521fc0` | `MessageShowPane::MessageShowPane(wchar_t* messageText)` | Builds the pane, installs vtables, updates `g_pMessageShowPane`, counts/wraps lines, and adds the pane to `g_pRenderLayer1`. |
| `0x00521fc0-0x00522025` | `MessageShowPane::~MessageShowPane()` | Removes the pane from its layer, clears the global pointer, and destroys the base pane state. |
| `0x00522030-0x00522530` | `BuildMessageTextButtons()` | Draws wrapped text rows using shadow and face palettes. |
| [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) | `SetWrappedText` | Replaces overlay text, recomputes wrap metrics, reapplies bounds, and refreshes text rows; IDA verifies it is only called by the message overlay packet handler when `g_pMessageShowPane` already exists. |
| [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) | `ClearMessageShowPaneSingleton` / EH cleanup | Tiny helper that clears `g_pMessageShowPane`; referenced from the constructor unwind path and ignored as standalone source. |
| [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) | destructor adjustor thunks | Compiler secondary/tertiary thunks into scalar deleting destructor; ignore for handwritten source. |
| [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) | `ScalarDeletingDestructor(char flags)` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- Generated Wave3/simroot output has historically graded this class high and once marked `0x005226fb` as missing; treat that only as history. IDA resolves `0x005226fb-0x00522711` as adjustor thunks, so do not treat it as an unnamed project method.
- IDA MCP confirms every method listed above as an exact function start.
- Generated source references `g_applyMessagePaneBorder`, `g_pMessageShowPane`, `g_pRenderLayer1`, and `g_wszNewline`.
- IDA confirms `0x00522530` as a real helper called from message overlay packet handler `0x005ac070`. Current `simroot_v2` now emits it under `MessageShowPane`, while older owner data under `FittingRoomDownloadControlPane` remains a data-history caveat rather than authority.
- [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) is the active overlay singleton at [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md).
- 2026-05-31 live IDA MCP recheck: `xrefs_to 0x0069b4f4` reports constructor, destructor, EH cleanup, scalar-deleting destructor, packet-handler, and UI cleanup references; `decompile` confirms those reads/writes and shows the constructor text-wrap/layout flow.

## Cross-References

- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md)
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md)
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md)
- [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-06-06 A008:
  - Before: the class was reconstructable but unassigned even though its exact methods, singleton lifecycle, and packet-handler consumer path were documented.
  - After: changed completion/confidence to `85/85`, set `AUTOGEN_PARENT_UID` to [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), and kept final C++ blank under the documented final-source gate.
  - Evidence: the file page now clears the 80/80 parent gate at `85/80` with exact method, destructor, vtable/read-only, singleton, and packet-handler evidence while preserving the open final split caveat.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the floating message overlay has detailed construction, wrapping, redraw, singleton, layer, text-button, helper, thunk, and global evidence, but final source-file grouping remains medium confidence. Evidence: linked `MessageAndMessageShowPane` range, exact helper/destructor memory pages, IDA-confirmed starts, `g_pMessageShowPane`, `g_pRenderLayer1`, and corrected ownership of `SetWrappedText`.
- 2026-05-31 metadata/evidence update: changed `RECONSTRUCTABLE` from blank to `TRUE` and confidence from `82` to `84`. Summary/evidence: live IDA MCP xrefs/decompilation verified the class-owned singleton lifecycle and packet-handler consumer path. Parent/code autogen fields remain blank because the final source-file split and final C++ source shape are not at the `95+` gate.
- 2026-05-31 SetWrappedText ownership clarification: updated the method row to rely on IDA caller/xref evidence instead of generated owner output. Summary/evidence: [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) now records live IDA `lookup_funcs`, `callers`, `xrefs_to`, `callees`, and `decompile` evidence.
