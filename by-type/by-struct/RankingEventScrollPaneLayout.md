*** UID:0001VO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPaneLayout

## Status

- Confidence: medium-to-strong for local scrollbar fields; base `Pane`/`ControlPane` layout remains inherited.
- Likely owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Parent class: [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- Primary memory evidence: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Vtable evidence: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Closest parallel: [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)

## Layout Hypothesis

`RankingEventScrollPane` extends `Pane` and exposes three vtable views. The local scrollbar state matches the later `ScrollVolumePane` shape closely, with a feature-specific owner callback back into `RankingEventListPane`.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Raw constructor and inline list-pane child setup write `0x00610a4c` after `Pane::Pane(1)`. |
| `+0x44` | 16 | pane bounds rectangle | `OnMouseEvent`, paint, hit-test, and dirty-rect helpers use this inherited rectangle. |
| `+0xa0` | 4 | secondary input/control vtable view | Constructor stores `0x00610a98`; `OnMouseEvent` receives this subobject pointer and subtracts `0xa0` to recover the full object. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x00610ac8`; the only confirmed local slot is the inherited/default `0x00544e90` event-update target. |
| `+0xf8` | 4 | packed flags/state word | Constructor clears this dword; setter island updates the low/current state and invalidates. |
| `+0xfb` | 1 | drag-tracking flag | Hit-test and drag rectangle math switch to drag-anchor mode when this byte is set. |
| `+0xfc` | 1 | orientation | Constructor stores the orientation argument; `0` and nonzero select vertical/horizontal geometry branches. |
| `+0xfe` | 2 | current scroll position | Drag and range helpers read/write this word and clamp it against `+0x100`. |
| `+0x100` | 2 | max scroll position/range | Set-range and drag helpers divide by this word when computing thumb position. |
| `+0x102` | 1 | input/enabled byte | Enable/disable raw helpers set this byte; active-test requires it to be nonzero. |
| `+0x103` | 1 | hover part code | Hover helper invalidates old/new part rectangles and uses `0xff` as none. |
| `+0x104` | 1 | active/pressed part code | Mouse handler and reset helper use `0xff` as none. |
| `+0x108` | 4 or 8 | drag anchor point | Mouse press and drag math store point deltas here before converting to scroll position. |

## State Values

Known scrollbar part codes:

| Code | Meaning |
| --- | --- |
| `0` | collapsed leading edge/arrow region |
| `1` | track before thumb |
| `2` | thumb |
| `3` | track after thumb |
| `4` | collapsed trailing edge/arrow region |
| `0xff` | no hover/active part |

## Evidence Notes

- Constructor bytes at `0x004598b0-0x0045990c` clear `+0xf8/+0xfe`, store `+0xfc`, initialize `+0x102 = 1`, and set `+0x103/+0x104` to `0xff`.
- IDA vtable/xref evidence confirms the three vtable bases at `+0x00`, `+0xa0`, and `+0xa4`. `RankingEventListPane` constructor `0x0045ae30` also allocates a `0x110`-byte scroll child and installs the same three vtables inline at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`.
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md) uses the secondary-vtable subobject pointer and reads/writes hover, active, enabled, orientation, range, and drag fields.
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md), [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md), and [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) agree on the same local offsets.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `78/86`, marked reconstructable, and attached to [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
  - Before: the page contained useful layout evidence but remained unevaluated to validator/stat tooling.
  - After: the score reflects IDA-verified vtable views, `0x110` child allocation, local field offsets, scroll-part state, and matching child method evidence while keeping final field names below final-audit status.
  - Evidence: IDA MCP `lookup_funcs`, vtable dword inspection, raw disassembly at unmodeled helper starts, decompilation of `0x00459a60`, `0x0045ac10`, and `0x0045ae30`, plus existing linked child memory pages.
