*** UID:0000CP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollWidget

## Status

- Confidence: strong for recovered behavior and ScrollBar ownership; medium for final helper names.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address range: [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollWidget.cpp`

## Class Purpose

`ScrollWidget` is a small scroll state helper that clamps a target scroll value, tracks whether scrolling is enabled, and notifies its owner through a vtable callback when state changes.

Wave3 metadata ties the imported subset to `ChattingPane` embedded scroll widgets, but live caller evidence and the containing file page keep this with generic scrollbar infrastructure rather than a chat-only module.

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
| `0x0055c310-0x0055c36b` | `SetScrollTargetValue` | Clamp target, adjust current position downward when needed, notify owner. |
| `0x0055c370-0x0055c393` | raw current-position setter | Updates `+0xfe` and notifies through the same callback when the value changes. |
| `0x0055c3a0-0x0055c3ba` | `Enable` | Set enabled flag and notify on transition. |
| `0x0055c3c0-0x0055c3da` | `Disable` | Clear enabled flag and notify on transition. |

## Caller Evidence

IDA MCP `py_eval` on 2026-06-03 confirms:

- `SetScrollTargetValue` has direct calls at `0x0055e8be`, `0x0055e9d0`, and `0x0055ea14`; the latter two are inside the `0x0055e990-0x0055ead5` scroll synchronization helper that reads the horizontal/vertical scroll-widget pointers at `+0xf8/+0xfc`.
- `Enable` is called from `ChattingHandlePane::ChattingHandlePane` at `0x00481cda` and `ChattingHandlePane::OnMouseEvent` at `0x00481e43`.
- `Disable` is called from the same chat-handle paths at `0x00481ce1` and `0x00481e4a`.
- The state-change callback path is consistent across methods: load the vtable from `[ecx]`, push `this + 0x44`, and call the callback slot at `+0x20`.

## Current Caveats

- Current generated `class_ScrollWidget.cpp` repeats the same anonymous-namespace helper names three times. The behavior is understood, but the generated source likely needs codegen cleanup before it can compile as a single translation unit.
- The current-position setter at `0x0055c370` has no IDA function object and no direct xrefs in the live database. Keep it documented as a raw method-shaped body until an owner/caller is recovered.

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
- 2026-06-03: Corrected method ends and attached to ScrollBar.
  - Before: the three method rows used return-address-style ends, the raw current-position setter was missing, and parent/reconstructability metadata was blank.
  - After: raised to `78/80`, marked reconstructable, attached to [UID:0000NF][ScrollBar](by-file/ScrollBar.md) at position `20`, corrected method ends to `0x0055c36b`, `0x0055c3ba`, and `0x0055c3da`, and added the raw `0x0055c370-0x0055c393` setter.
  - Evidence: IDA MCP `py_eval` on 2026-06-03 reports exact function ends, direct caller sets, the shared `this + 0x44` notify callback through vtable slot `+0x20`, and the raw setter body between `SetScrollTargetValue` and `Enable`.
