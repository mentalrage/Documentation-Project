*** UID:000064 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete nested declaration is emitted once by HelpPane. Preserve all exact
// HelpPane::SimpleHelpTextPartPane method children without duplicating the class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HelpPane__SimpleHelpTextPartPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: exact children [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md), [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md), [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md), and [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md), with non-emitting parent split index [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) and destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Confidence: strong for HelpPanes ownership, exact child method boundaries, field roles, style-state behavior, and destructor linkage; final historical spelling of the private helper/virtual name remains open.

## Class Purpose

`HelpPane__SimpleHelpTextPartPane` is the embedded text renderer used by [UID:000063][HelpPane](by-class/HelpPane.md). It stores the tooltip text, borrows the parent `FontStyle` object, applies per-style opacity/mode state, and draws each line as normal, outlined, or shadowed text.

## Class Layout

The complete nested declaration is emitted once inside the position-5 [UID:000063][HelpPane](by-class/HelpPane.md) formal. This position-6 page is the semantic class route and child insertion point; it intentionally does not duplicate the class. The accepted surface is constructor, empty virtual destructor, primary-slot `OnPaint`, private signed-short `DrawStyledTextSegment`, owned `SimpleUString m_text`, and borrowed `FontStyle *m_fontStyle`.

- `+0xf8` is the owned tooltip text, best modeled as `SimpleUString m_text`; constructor calls the string constructor, the parent assigns text through the string assignment helper, and the destructor wrapper destroys only this owned member.
- `+0xfc` is a borrowed `FontStyle *m_fontStyle` / `m_style` pointer, not a direct style-run array and not owned allocation storage. [UID:000063][HelpPane](by-class/HelpPane.md) stores the same physical pointer at parent `HelpPane +0x220` after setting it to the parent `FontStyle` block at `HelpPane +0xfc`.
- `+0x90` is inherited `GrafPort`/`Pane` alpha storage; the raw style-state helper and parent style-state counterpart copy accepted text opacity here.
- `+0x8c` is inherited text-alignment storage; `DrawStyledTextSegment` copies per-rule `FontStyleRule +0x0c` into this field before drawing.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpTextPartPane` | [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md) | Constructs pane base, vtables, text string, optional style pointer, and default opacity. |
| `OnPaint` | [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md) | Primary-vtable `+0x44` override; splits text by CR/LF/tab and draws every empty/final segment with optional per-line style records. |
| raw style-state helper | [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md) | Descriptive name `ApplyStyleOpacityState` / `ApplyStyleStateFromFontStyle`; no modeled function object or external entry; checks borrowed `m_fontStyle` at `this +0xfc`, updates pane mode through [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and mirrors accepted opacity into inherited alpha at `this +0x90`. |
| `DrawStyledTextSegment` | [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md) | Applies color, font style, and render mode before dispatching normal/outlined/shadowed drawing. |
| `ScalarDeletingDestructor` | [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md) | Compiler scalar deleting destructor wrapper; releases the text string and pane base, optionally deletes storage, and keeps formal C++ blank. |

## Rule Record Semantics

For this consumer, `FontStyle::GetRule(index, &rule)` copies one 16-byte `FontStyleRule` record:

- rule `+0x00` / `m_textColor` feeds text color setup.
- rule `+0x04` / `m_secondaryColor` feeds the background, outline, or shadow color role depending on effect.
- rule `+0x08` low byte / `m_effect` selects normal text (`0`), outlined text (`1`), or shadowed/special text (`3`).
- rule `+0x0c` / `m_alignment` is copied into inherited text alignment at child `+0x8c`.

## Evidence Notes

- Live IDA on 2026-06-05 confirms modeled starts and sizes for the constructor (`0x82`), text draw path (`0x1e7`), styled segment helper (`0xd3`), and scalar deleting destructor (`0x48`).
- The text draw path calls [UID:00005C][FontStyle](by-class/FontStyle.md)'s bounded rule lookup at `0x00499f60`, normal text drawing helpers, the draw callback slot at `0x0069b3fc`, and the local styled segment helper.
- The styled segment helper dispatches to the same shared outlined/shadowed text-effect helpers used by StaticText2: `0x004bafa0` and `0x004bb080`.
- The 2026-06-06 [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) refresh splits the gap between `DrawText` and `DrawStyledTextSegment` into padding, a raw style-state helper at `0x004c6820-0x004c687e`, and padding. The helper has no external xrefs, but its internal behavior matches the class' style-pointer/opacity fields and calls [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) with modes `1` and `3`.
- The 2026-06-20 supervisor Rule 26 split created exact child pages [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md), [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md), [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md), and [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md); [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) is now a non-emitting split index over this class and [UID:000063][HelpPane](by-class/HelpPane.md).
- IDA confirms all listed starts and shows `HelpPane::HelpPane` constructing the embedded text part directly.
- This class is not the same recovered owner as [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md), even though both use similar text-effect helper concepts.
- B013 PE route recheck of read-only `NexusTK.exe` confirms the raw `0x004c6820-0x004c687e` helper still has no external direct/conditional/short branch entry and no absolute VA dword pointer into the range; positive controls still find absolute refs for `0x004c6630` and `0x004ce620`. The one unaligned full-image byte-pattern hit at `0x004c687a` is inside `.text` and does not establish a callable source route.

## Source Emission Policy

- The formal class page emits only a no-standalone class marker plus `[[CHILDREN]]` because method bodies now belong to exact by-memory children. Class-level emission remains declaration/source-shape evidence until a broader header/layout pass is ready.
- [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md), [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md), and [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md) are source-authored method bodies and may carry first-draft C++.
- [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md) stays blank because no external entry route is proven even though a source-style `ApplyStyleOpacityState()` shape is understood.
- [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md) stays blank because the binary wrapper and adjustor thunks are MSVC ABI output; source C++ is the ordinary virtual destructor.

## Rejected Alternatives

- `StaticTextControlPane2__SimpleHelpTextPartPane` is not the owner. Its similarly named text part has different parentage and different field offsets.
- GrafPort text effects are dependencies, not HelpPane-owned methods.
- `m_styleRuns` / `m_styleArray` is too narrow for `+0xfc`; the pointer routes to the full parent `FontStyle` object.
- `OnPaint` is accepted by the primary-vtable `+0x44` slot and parallel StaticText nested-pane control. Historical descriptive `DrawText` is retained only as superseded provenance.

## 2026-06-19 Parent Counterpart Link

- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) is the parent `HelpPane` counterpart to this class' raw text-part style-state helper at `0x004c6820-0x004c687e`. It must not be re-owned to `HelpPane__SimpleHelpTextPartPane`.
- Preserve the nested text-part field direction from the destructor/style work: `+0xf8` is the owned text (`SimpleUString` / `m_text` direction), `+0xfc` is a borrowed `FontStyle *m_fontStyle` / `m_style` pointer, and inherited pane alpha/scalar storage is at child `+0x90`.
- The parent stores an alias to the borrowed style pointer at `HelpPane +0x220`. [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) reads text opacity from `[HelpPane +0x220] + 0x08`, calls [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) on the child at `HelpPane +0x124`, and writes accepted text opacity to `HelpPane +0x1b4`, which is the embedded child's inherited alpha field at child `+0x90`.
- The branch relationship is consistent but not identical: this class' raw helper sets child mode `1` when opacity is not greater than zero and mode `3` when `0.0f < opacity <= 1.0f`; the parent helper also copies base fill/frame paint colors and base alpha before reaching the child branch. That extra parent behavior is why [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) stays with [UID:000063][HelpPane](by-class/HelpPane.md) / [UID:0000JU][HelpPanes](by-file/HelpPanes.md).

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce620-0x004ce668` wrapper to [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md) at `86/91`, owner/emitter [UID:000064].
- Source-facing name is `virtual HelpPane::SimpleHelpTextPartPane::~SimpleHelpTextPartPane()`. The wrapper and `+0xa0/+0xa4` adjustor thunks are compiler ABI output and formal wrapper C++ remains blank.
- The wrapper validates the nested text member at `+0xf8` as `m_text` of type `SimpleUString`, borrowed style pointer direction at `+0xfc` as `FontStyle *m_fontStyle`, primary vtable slot `0x0061aad4`, and secondary/tertiary views `0x0061ab20/0x0061ab50`.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md)
- [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md)
- [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md)
- [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md)
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-20 supervisor Rule 26 HelpPaneCore split execution:
  - Raised completion from `84` to `85` because the exact constructor/draw/raw-helper/styled-segment child pages now exist and the class no longer depends on a mixed aggregate for range ownership.
  - Added exact child links [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md), [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md), [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md), and [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md), preserving B001's method-name, raw-helper, style-pointer, opacity, and helper-ownership evidence.
  - Recorded that [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) is now a non-emitting split index shared with [UID:000063][HelpPane](by-class/HelpPane.md).

- 2026-06-21 B013 source-quality incorporation:
  - Raised completion/confidence from `85/88` to `87/89`.
  - Resolved `+0xfc` to borrowed `FontStyle *m_fontStyle` instead of a direct style-run array, added inherited `+0x8c` text-alignment and `+0x90` alpha decisions, recorded per-rule `FontStyleRule` field consumption, added the PE no-route proof for the raw style-state helper, and clarified class-vs-method C++ emission policy.

- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added the accepted no-standalone class marker plus `[[CHILDREN]]` insertion point to the formal block.
  - Preserved the class page as declaration/layout evidence while exact children [UID:0003ZU][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md), [UID:0003ZV][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md), [UID:0003ZW][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md), [UID:0003ZX][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md), and [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md) own constructor/draw/raw-helper/styled-segment/destructor-wrapper emission decisions.

- 2026-06-19 B012 parent counterpart sync:
  - Cross-linked [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) as the parent `HelpPane` style-state counterpart to this class' raw text-part helper at `0x004c6820-0x004c687e`.
  - Preserved the child-owned field direction for `+0xf8` text, `+0xfc` borrowed `FontStyle *`, inherited alpha `+0x90`, and the parent alias at `HelpPane +0x220`; did not move [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) to this class.

- 2026-06-05: A004 raised the page to `82/86`, attached it to [UID:0000JU][HelpPanes](by-file/HelpPanes.md), removed stale recovered-file provenance, and added live evidence for the four method starts, FontStyle rule lookup, and shared outlined/shadowed text-effect calls.
- 2026-06-06 A001 raw style-state helper sync: raised completion/confidence to `84/88`, added the exact `0x004c6820-0x004c687e` helper row, and tied the class' style pointer/opacity fields to the newly documented [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) caller evidence in [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md).
- 2026-06-17 B003 destructor-wrapper split sync: added exact scalar wrapper child [UID:0003Z0][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded nested text/style field evidence.
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: embedded tooltip text renderer role, constructor/draw/destructor methods, style consumption, and distinction from the similarly named StaticTextControlPane helper are documented; remaining work is lower-level draw-state detail and final source reconstruction. Evidence: `HelpPaneCore`, `HelpPane`, and `StaticTextControlPane` cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the embedded tooltip text renderer unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; parent attachment was deferred at that time because the class score was below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004c65a0`, `0x004c6630`, `0x004c6880`, and `0x004ce620`, matching the documented embedded HelpPane text-renderer role.

## UID0003ZY Nested Source Closure - 2026-07-21

- Current metadata is `92/94`, owner/emitter [UID:0000JU][HelpPanes](by-file/HelpPanes.md), `RECONSTRUCTABLE:TRUE`, route position `6`. The nested declaration is emitted exactly once inside HelpPane before `[[CHILDREN]]`.
- Exact child object size is `0x100`: Pane base through `+0xf7`, owned `SimpleUString m_text` at `+0xf8`, and borrowed `FontStyle *m_fontStyle` at `+0xfc`. Inherited `m_textAlign` and `m_alpha` at `+0x8c/+0x90` are consumed by style draw/state code and are not duplicate members.
- Authored child methods are constructor position `10`, `OnPaint` position `20`, and private `DrawStyledTextSegment` position `40`; the ordinary virtual destructor is an empty inline declaration. UID0003ZW remains a covered no-entry copy of the child-opacity tail already authored by HelpPane::ApplyStyleState, and UID0003Z0 remains compiler scalar-wrapper output.
- OnPaint clears/fills visible bounds, seeds the exact default rule, processes CR/LF/tab independently, draws empty segments and the unconditional tail, uses signed-short counts, and selects per-line style or plain drawing. Styled drawing sets alignment/colors, constructs the exact 12-pixel rectangle from visible bounds, and dispatches effects `0/1/3`.
- Historical DrawText, standalone nested declaration, direct style-array, owned FontStyle pointer, independent raw helper, and authored scalar-wrapper interpretations are superseded while their dated evidence remains intact.
