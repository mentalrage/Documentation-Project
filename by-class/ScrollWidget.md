*** UID:0000CP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollWidget

## Status

- Confidence: strong for recovered behavior; medium for final source-file grouping.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address range: [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollWidget.cpp`

## Class Purpose

`ScrollWidget` is a small scroll state helper that clamps a target scroll value, tracks whether scrolling is enabled, and notifies its owner through a vtable callback when state changes.

Wave3 metadata ties the imported subset to `ChattingPane` embedded scroll widgets, but the class is generic enough to keep with scrollbar infrastructure until wider ownership evidence is recovered.

## Observed State

Important state from metadata and generated code:

```text
+0x20  notify callback in vtable
+0xfe  current position
+0x100 target position
+0x102 enabled flag
```

`SetScrollTargetValue` clamps targets to `0..30000`, immediately lowers current position if the target moves below it, and emits notifications for meaningful target changes.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x0055c310-0x0055c36a` | `SetScrollTargetValue` | Clamp target, adjust current position downward when needed, notify owner. |
| `0x0055c3a0-0x0055c3b9` | `Enable` | Set enabled flag and notify on transition. |
| `0x0055c3c0-0x0055c3d9` | `Disable` | Clear enabled flag and notify on transition. |

## Current Caveats

- Current generated `class_ScrollWidget.cpp` repeats the same anonymous-namespace helper names three times. The behavior is understood, but the generated source likely needs codegen cleanup before it can compile as a single translation unit.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented generic scroll target behavior, observed state offsets, method roles, and generated source caveats.
  - After: changed completion/confidence to `72/76`.
  - Evidence: existing method table, observed state, `ScrollPaneInputCore` reference, and codegen caveat support moderate-high documentation with unresolved final source grouping.

- 2026-05-28: Corrected the containing `ScrollPaneInputCore` memory page endpoint from `0x0055c642` to `0x0055c643`.
  - Before: the containing page omitted the final byte of `ScrollPane::OnScrollTimer`.
  - After: `ScrollWidget` remains inside the same input-core page; the page now covers the full IDA-modeled timer helper too.
  - Evidence: IDA MCP reports `sub_55C610` as `0x0055c610-0x0055c643`.
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
