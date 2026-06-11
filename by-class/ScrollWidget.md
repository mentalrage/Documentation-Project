*** UID:0000CP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Class Purpose

`ScrollWidget` is a small scroll state helper that clamps a target scroll value, tracks whether scrolling is enabled, and notifies its owner through a vtable callback when state changes.

Existing ScrollBar and input-core documentation keeps this with generic scrollbar infrastructure rather than a chat-only module: `ScrollablePane` synchronization calls the target setter, while `ChattingHandlePane` supplies direct enable/disable callers.

## Autogen Status

- Parent file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Parent position: `20`, between [UID:0000CM][ScrollPane](by-class/ScrollPane.md) and [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- Reconstructable: `TRUE`
- C++ emission: intentionally blank until final helper names and raw setter ownership are settled.

The class-page attachment matches [UID:0000NF][ScrollBar](by-file/ScrollBar.md), which owns the generic `ScrollPane`/`ScrollWidget`/`ScrollablePane` family. The mixed [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) range records the same helper boundaries and keeps the raw setter-shaped bodies explicit.

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

- The current-position setter at `0x0055c370` has no IDA function object and no direct xrefs in the live database. Keep it documented as a raw method-shaped body until an owner/caller is recovered.
- Final source-level helper names remain open. The behavior is understood well enough for parent attachment, but not for C++ reconstruction under the current confidence gate.

## Score Rationale

Completion is now `82` because the page has source ownership, parent metadata, state layout, method boundaries, caller evidence, notification-callback behavior, and the raw setter caveat aligned with the file and memory pages. Remaining gaps are final helper names, direct evidence for the raw setter, and source-quality declarations.

Confidence is now `84` because independent local docs agree on ScrollBar ownership, the `0x0055c310-0x0055c3da` helper span, direct setter/enable/disable callers, the `this + 0x44` callback path, and the unresolved raw setter. Confidence remains capped by the lack of a direct xref/function object for `0x0055c370`.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
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
- 2026-06-03: Corrected method ends and attached to ScrollBar.
  - Before: the three method rows used return-address-style ends, the raw current-position setter was missing, and parent/reconstructability metadata was blank.
  - After: raised to `78/80`, marked reconstructable, attached to [UID:0000NF][ScrollBar](by-file/ScrollBar.md) at position `20`, corrected method ends to `0x0055c36b`, `0x0055c3ba`, and `0x0055c3da`, and added the raw `0x0055c370-0x0055c393` setter.
  - Evidence: IDA MCP `py_eval` on 2026-06-03 reports exact function ends, direct caller sets, the shared `this + 0x44` notify callback through vtable slot `+0x20`, and the raw setter body between `SetScrollTargetValue` and `Enable`.
- 2026-06-07: Reconciled the class page with ScrollBar and input-core documentation.
  - Before: the page still cited generated-source state directly and lacked explicit autogen-status/score-rationale sections.
  - After: raised to `82/84`, added parent/autogen status and score rationale, moved sibling class references into cross-references, and kept C++ blank.
  - Evidence: [UID:0000NF][ScrollBar](by-file/ScrollBar.md) and [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) agree on ownership, half-open helper ranges, direct caller evidence, callback slot behavior, and the unresolved raw current-position setter.
