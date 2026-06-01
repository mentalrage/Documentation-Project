*** UID:0000O8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaticTextControlPane

## Status

- Confidence: strong for grouping `StaticTextControlPane`, `StaticTextControlPane2`, and `StaticTextControlPane2::SimpleHelpTextPartPane`; medium for exact original class names.
- Proposed module: `ui/controls/StaticTextControlPane.cpp`
- Proposed header: `ui/controls/StaticTextControlPane.h`
- Current recovered sources: `source-3/simroot_v2/class_StaticTextControlPane.cpp`, `class_StaticTextControlPane2.cpp`, and `class_StaticTextControlPane2__SimpleHelpTextPartPane.cpp`
- Main address clusters: `0x00498dd0-0x004991ec`, `0x00499fe0-0x0049b915`, and `0x004bafa0-0x004bb0da`

## File Role

This module owns non-editable/static text control panes. The older `StaticTextControlPane` is broadly used by dialogs as a static text control wrapper, while `StaticTextControlPane2` is a newer/extended pane that measures text, clamps its screen bounds, supports alignment, opacity/fade styling, and owns an embedded help-text part pane for outlined or shadowed text rendering.

[UID:0000JI][FontStyle](by-file/FontStyle.md) is a neighboring support type for the same text-control pipeline. Keep it separate for now because it has its own constructor, rule appender, cleanup helper, and cross-feature callers, but it may later fold into this source file if original header/source evidence points that way.

Keep this separate from [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The older static control can wrap or coordinate an embedded text-edit pane, but its public role is display text rather than editable rich text.

Also keep `StaticTextControlPane2::SimpleHelpTextPartPane` separate from [UID:0000JU][HelpPanes](by-file/HelpPanes.md). `HelpPane::SimpleHelpTextPartPane` has a similar display role, but IDA MCP and generated-file locality put it with the tooltip/help overlay cluster around `0x004c65a0`, not with the static text controls around `0x00499fe0`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `StaticTextControlPane` | [UID:00011I][0x00498dd0-0x004991ec.StaticTextControlPane](by-memory/0x00498dd0-0x004991ec.StaticTextControlPane.md), [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) | Broad dialog static text control; fixed type code `19`; active/inactive state helpers around an embedded text pane and a vtable-only frame/highlight helper. |
| `StaticTextControlPane2` | `0x0049a410-0x0049b915` in child ranges | Extended static/help text pane with measurement, alignment, opacity/fade, layer forwarding, show/hide, and paint behavior. |
| `StaticTextControlPane2::SimpleHelpTextPartPane` | `0x00499fe0-0x0049a402`, `0x0049b560-0x0049b5a7`, `0x004bafa0-0x004bb0da` | Embedded text-part pane that draws normal, outlined, and shadowed text lines. |
| [UID:00005C][FontStyle](by-class/FontStyle.md) | `0x00499f10-0x00499fda`, cleanup at `0x004536e0-0x00453732` | Reusable text-style descriptor passed into `StaticTextControlPane2` constructors by callers such as `MiniMapDialog` and `NewMailDialog`. |
| `g_dialogLayoutSentinel` | global data | Layer/context sentinel currently emitted with `StaticTextControlPane2`. |

## Ownership Decision

Group the three generated files into one static-text controls module. The classes are adjacent in memory, share pane/control infrastructure, and represent two versions of the same UI role. `SimpleHelpTextPartPane` is an embedded subpane in `StaticTextControlPane2`, so it should not remain a top-level original source module.

Do not merge this into [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) or [UID:0000ON][TextEditPane](by-file/TextEditPane.md). Static text drawing and help text effects are a separate control family even though they reuse font/drawing helpers and, in one generation, a text-edit child.

## Evidence Notes

- IDA MCP reports 104 direct callers to `StaticTextControlPane::StaticTextControlPane` at `0x00499030`, which matches a generic dialog text control.
- IDA MCP reports eight direct callers to `StaticTextControlPane2::StaticTextControlPane2` at `0x0049a410`.
- IDA MCP confirms `FontStyle::FontStyle` and `FontStyle::Configure` callers that build style records for `StaticTextControlPane2` labels.
- `StaticTextControlPane2::StaticTextControlPane2` constructs `Pane`, initializes an embedded `SimpleHelpTextPartPane`, measures text width/line count, clamps the final rectangle to screen dimensions, and applies optional style opacity/fade state.
- `StaticTextControlPane2` forwards add/remove layer and show/hide to `m_helpTextPart`.
- `SimpleHelpTextPartPane::OnPaint` parses line breaks and tab-based formatting commands, then dispatches line drawing.
- `SimpleHelpTextPartPane::DrawOutlinedText` and `DrawShadowedText` are text effect helpers used by `DrawTextLine`.

## Current Caveats

- `class_StaticTextControlPane.cpp` currently emits only a marker and local `TextEditPane` struct for the constructor body at `0x00499030`, despite the range being `0x00499030-0x004991eb` and the method having 104 direct callers. This is tracked in [Wave3 Noticed Problems](../wave3_noticed_problems.md).
- The class summary for `StaticTextControlPane` appears overfit to fitting-room user-image state. Treat fitting-room names in active/inactive helpers as provisional until field ownership is verified.
- `SimpleHelpTextPartPane` destructor support currently references unrelated generated owner names such as `BowGaugeObjectPane` and `TextButtonExControlPane`. Treat those as owner-name pollution.

## Cross-References

- [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:00011I][0x00498dd0-0x004991ec.StaticTextControlPane](by-memory/0x00498dd0-0x004991ec.StaticTextControlPane.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)
- [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md)
- [UID:00011U][0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md)
- [UID:00016E][0x004bafa0-0x004bb0da.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0da.SimpleHelpTextPartPaneTextEffects.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)

## Changes

- Before: `StaticTextControlPane2` was listed through `0x0049b914`, and `StaticTextControlPane::GetPaneTypeCode` was listed as `0x0049b920-0x0049b924`.
- Changed to: `StaticTextControlPane2` through `0x0049b915`; `StaticTextControlPane::GetPaneTypeCode` through `0x0049b925`, with a dedicated by-memory page.
- Summary/evidence: IDA MCP reports both fixed-return helpers at `0x0049b910` and `0x0049b920` as size `0x5`, so both previous end-exclusive ranges were one byte short.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers static-text control role, proposed contents, grouping decision, FontStyle relationship, IDA caller evidence, generated-output caveats, range correction, and cross-references; confidence remains capped by exact original class names and incomplete generated constructor body.
