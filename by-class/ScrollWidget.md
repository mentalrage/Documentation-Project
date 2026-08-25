*** UID:0000CP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ScrollWidget class routing is documented here; exact target/current/enable/disable method bodies emit through child pages.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollWidget

## Status

- Confidence: strong for recovered behavior and ScrollBar ownership; medium for final helper names.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address range: split out of [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) into exact children [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md), [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md), [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md), and [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md).

## Class Purpose

`ScrollWidget` is a small scroll state helper that clamps a target scroll value, tracks whether scrolling is enabled, and notifies its owner through a vtable callback when state changes.

Existing ScrollBar and input-core documentation keeps this with generic scrollbar infrastructure rather than a chat-only module: `ScrollablePane` synchronization calls the target setter, while `ChattingHandlePane` supplies direct enable/disable callers.

## Autogen Status

- Parent file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Parent position: `20`, between [UID:0000CM][ScrollPane](by-class/ScrollPane.md) and [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- Reconstructable: `TRUE`
- C++ emission: formal method C++ is now present on [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md), [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md), [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md), and [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md). UID00042Z emits first-draft `SetScrollCurrentValue(short currentPosition)`; the method name is inferred from the target title, sibling `SetScrollTargetValue`, and `m_currentPosition`, not proven as original spelling.

The class-page attachment matches [UID:0000NF][ScrollBar](by-file/ScrollBar.md), which owns the generic `ScrollPane`/`ScrollWidget`/`ScrollablePane` family. The mixed [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) range records the same helper boundaries and keeps the raw setter-shaped bodies explicit.

## Observed State

Important state from metadata and generated code:

```text
+0x20  notify callback in vtable
+0xfe  current position
+0x100 target position
+0x102 enabled flag
```

`SetScrollTargetValue` clamps targets to `0..30000` (`0x7530`, Verified with int_convert.py), immediately lowers current position if the target moves below it, and emits notifications for meaningful target changes.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md) `0x0055c310-0x0055c36b` | `SetScrollTargetValue` | Clamp target, adjust current position downward when needed, invalidate inherited bounds, and emit formal C++ `CXX-04`. |
| [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) `0x0055c370-0x0055c397` | `SetScrollCurrentValue` first-draft current-position setter | Updates `+0xfe`, tail-calls the same inherited `InvalidateRect(&m_bounds)` route through slot `+0x20` when the value changes, and returns through the local no-change tail; formal C++ is now present on the child. |
| [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md) `0x0055c3a0-0x0055c3ba` | `Enable` | Set enabled flag and invalidate inherited bounds on transition; emits formal C++ `CXX-06`. |
| [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) `0x0055c3c0-0x0055c3da` | `Disable` | Clear enabled flag and invalidate inherited bounds on transition; emits formal C++ `CXX-07`. |

## Caller Evidence

IDA MCP `py_eval` on 2026-06-03 confirms:

- `SetScrollTargetValue` has direct calls at `0x0055e8be`, `0x0055e9d0`, and `0x0055ea14`; the latter two are inside the `0x0055e990-0x0055ead5` scroll synchronization helper that reads the horizontal/vertical scroll-widget pointers at `+0xf8/+0xfc`.
- `Enable` is called from `ChattingHandlePane::ChattingHandlePane` at `0x00481cda` and `ChattingHandlePane::OnMouseEvent` at `0x00481e43`.
- `Disable` is called from the same chat-handle paths at `0x00481ce1` and `0x00481e4a`.
- The state-change callback path is consistent across methods: load the vtable from `[ecx]`, push `this + 0x44`, and call the callback slot at `+0x20`.
- 2026-07-03 B006 MCP session `31debdf2` reconfirmed [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) as modeled `sub_55C3C0`, size `0x1a`, with exactly the same `+0x102` enabled-byte clear and inherited `InvalidateRect(&m_bounds)` route through `this+0x44` / vtable slot `+0x20`; `xrefs_to` again reports `0x00481ce1` and `0x00481e4a` as ChattingHandlePane consumer paths, not owner evidence, and `get_bytes` confirms the pre/post `0xcc` padding.

## Current Caveats

- The current-position setter at `0x0055c370-0x0055c397` still has no IDA function object, direct xrefs, or VA/RVA pointer-byte hits in current MCP session `b6b3c97e`. Those negatives cap confidence and original-name certainty, but no longer block formal C++ because the body, `+0xfe` field, owner/emitter route, and inherited invalidation call are byte- and sibling-verified.
- B004 `NC-05` is historicalized: the split pass kept [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) blank because no source-facing setter name or callable route was recovered. B001 supersedes that disposition with first-draft `SetScrollCurrentValue(short currentPosition)` while preserving the no-route caveat as a score cap.

## Score Rationale

Completion is now `86` because the page has source ownership, parent metadata, state layout, corrected method boundaries, caller evidence, notification-callback behavior, raw setter caveat aligned with the file and memory pages, all exact child method bodies emitted, and a formal class-route comment marker. Remaining gaps are final helper names, direct evidence for the raw setter, and source-quality declarations.

Confidence is now `86` because independent local docs and the 2026-06-14 live IDA MCP pass agree on ScrollBar ownership, the `0x0055c310-0x0055c3da` helper span, direct setter/enable/disable callers, the `this + 0x44` callback path, and the exact raw setter no-change tail. Confidence remains capped by the lack of a direct xref/function object for `0x0055c370`.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md)
- [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md)
- [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md)
- [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md)

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
- 2026-06-14: Corrected the raw current-position setter tail and raised the support page to the Goal 2 gate.
  - Before: the raw setter row stopped at `0x0055c393`, before the no-change `pop; ret` tail, and the page was `82/84`.
  - After: corrected the raw setter span to `0x0055c370-0x0055c397`, raised to `85/86`, kept the [UID:0000NF][ScrollBar](by-file/ScrollBar.md) parent route, and kept C++ blank.
  - Evidence: live IDA MCP `lookup_funcs` reports no function at `0x0055c370`; `insn_query` shows the compare/write/callback sequence plus the `0x0055c393-0x0055c397` no-change tail; `xref_query` still reports no direct xrefs to the raw start; `analyze_batch` confirms `SetScrollTargetValue` caller/callee/constant evidence; and `int_convert.py` verifies `0x7530` as decimal `30000`.
- 2026-06-26 B004 implementation callback:
  - Before: the class depended on the mixed [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) parent for `ScrollWidget` method details.
  - After: exact children [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md), [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md), [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md), and [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) carry the target/current/enable/disable bodies; [UID:00042Y][0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md), [UID:000430][0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md), and [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) include formal C++ while [UID:00042Z][0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) records no-code proof `NC-05`. Score unchanged at `85/86`.
  - Evidence: accepted B004 report and live MCP session `80de0a67` confirmed direct `ScrollWidget` ownership, `+0xfe/+0x100/+0x102` state, inherited `InvalidateRect(&m_bounds)` route through slot `+0x20`, direct caller sets, and raw setter no-route cap.
- 2026-06-29 B001 UID00042Z empty-emitter implementation callback:
  - Before: UID00042Z was still an active blank emitter under historical `NC-05`.
  - After: class score unchanged at `85/86`; UID00042Z now emits first-draft `SetScrollCurrentValue(short currentPosition)` through this class and [UID:0000NF][ScrollBar](by-file/ScrollBar.md). B004 `NC-05` remains historical only, and the no-function/no-xref/no-pointer-route facts remain confidence caps.
  - Evidence: accepted B001 report and MCP session `b6b3c97e` reconfirmed no function object at `0x0055c370`, zero direct xrefs, zero VA/RVA pointer hits, the exact 39-byte compare/write/invalidate body, pre/post padding, and sibling `SetScrollTargetValue` evidence for `m_currentPosition` and `InvalidateRect(&m_bounds)`.
- 2026-07-01 B007 empty-emitter callback:
  - Before: the class route page was `85/86` with a blank formal block, even though exact target/current/enable/disable method bodies emit from children.
  - After: raised completion to `86` and inserted the formal class-route comment marker with `[[CHILDREN]]` without duplicating child method bodies.
- 2026-07-03 B006 UID000431 callback:
  - Before: [UID:000431][0x0055c3c0-0x0055c3da.ScrollWidgetDisable](by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) still carried split-created score `85/88` even though the formal `ScrollWidget::Disable()` body was correct and generated.
  - After: UID000431 is raised to `88/91`; this class page score is unchanged because the class already documented the ScrollWidget route, field band, caller evidence, and child emission. The accepted report preserves `ScrollWidget` ownership, rejects ChattingHandlePane ownership and parent aggregate emission, and keeps exact original member spelling/class declaration exposure as confidence caps rather than blockers.
  - Evidence: B006 MCP session `31debdf2` reconfirmed `sub_55C3C0` size `0x1a`, direct xrefs `0x00481ce1`/`0x00481e4a`, the `+0x102` enabled-byte clear, the inherited bounds invalidation through `this+0x44` and slot `+0x20`, and pre/post `0xcc` padding.
