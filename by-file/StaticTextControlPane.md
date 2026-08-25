*** UID:0000O8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StaticTextControlPane

## Status

- Confidence: strong for grouping `StaticTextControlPane`, `StaticTextControlPane2`, and the RTTI-proven nested type `StaticTextControlPane2::SimpleHelpTextPartPane`; exact private member spellings remain inferred where symbols are unavailable.
- Proposed module: `ui/controls/StaticTextControlPane.cpp`
- Proposed header: `ui/controls/StaticTextControlPane.h`
- Reviewed source-family inputs: `StaticTextControlPane`, `StaticTextControlPane2`, and `StaticTextControlPane2::SimpleHelpTextPartPane` class pages plus their exact memory ranges.
- Main address clusters: shared helpers at `0x00498dd0-0x00499021`, `0x00499030-0x004991ec`, `0x00499fe0-0x0049b915`, and `0x004bafa0-0x004bb0db`
- Deterministic class emission order: UID0000E3 older StaticTextControlPane `10`; UID0000E4 outer StaticTextControlPane2 `20`; B005-owned UID0000E5 nested route `30` after its ordered callback.

## File Role

This module owns non-editable/static text control panes. The older `StaticTextControlPane` is broadly used by dialogs as a static text control wrapper, while `StaticTextControlPane2` is a newer/extended pane that measures text, clamps its screen bounds, supports alignment, opacity/fade styling, and owns an embedded help-text part pane for outlined or shadowed text rendering.

[UID:0000JI][FontStyle](by-file/FontStyle.md) is a neighboring support type for the same text-control pipeline. Keep it separate for now because it has its own constructor, rule appender, cleanup helper, and cross-feature callers, but it may later fold into this source file if original header/source evidence points that way.

Keep this separate from [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The older static control can wrap or coordinate an embedded text-edit pane, but its public role is display text rather than editable rich text.

Also keep `StaticTextControlPane2::SimpleHelpTextPartPane` separate from [UID:0000JU][HelpPanes](by-file/HelpPanes.md). `HelpPane::SimpleHelpTextPartPane` has a similar display role, but IDA MCP and generated-file locality put it with the tooltip/help overlay cluster around `0x004c65a0`, not with the static text controls around `0x00499fe0`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `StaticTextControlPane` | [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md), [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md), [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) | Broad dialog static text control; fixed type code `19`; UID00011I now emits the source-ready constructor for the embedded TextEditPane setup, while active/inactive state helpers and frame/highlight paint are shared with TextEdit/ExchangeMoneyEdit vtables. |
| `StaticTextControlPane2` | [UID:0004KS][0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor](by-memory/0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor.md), [UID:0004KT][0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor](by-memory/0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor.md), [UID:0004KV][0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition](by-memory/0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition.md), [UID:0004KW][0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer](by-memory/0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer.md), [UID:0004KX][0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer](by-memory/0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer.md), [UID:0004KY][0x0049aae0-0x0049aaf8.StaticTextControlPane2Show](by-memory/0x0049aae0-0x0049aaf8.StaticTextControlPane2Show.md), [UID:0004KZ][0x0049ab00-0x0049ab18.StaticTextControlPane2Hide](by-memory/0x0049ab00-0x0049ab18.StaticTextControlPane2Hide.md), [UID:0004L0][0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint](by-memory/0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint.md), [UID:0004L1][0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState](by-memory/0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState.md), [UID:0004L4][0x0049b910-0x0049b915.StaticTextControlPane2GetControlType](by-memory/0x0049b910-0x0049b915.StaticTextControlPane2GetControlType.md) | Complete extended static/help text source: ControlPane type 8, `wchar_t[40]` with logical copy limit 32, measurement/alignment/screen clamp, parent/child style and lifecycle, fill/frame paint, and two-argument byte-return type virtual. UID00011V is now a non-emitting semantic split index. |
| `StaticTextControlPane2` compiler support | [UID:0004L2][0x0049b019-0x0049b02f.StaticTextControlPane2AdjustorThunks](by-memory/0x0049b019-0x0049b02f.StaticTextControlPane2AdjustorThunks.md), [UID:0004L3][0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor](by-memory/0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor.md), [UID:0004L5][StaticTextControlPane2Vtables](by-type/by-vtable/StaticTextControlPane2Vtables.md), [UID:0004L6][0x00618600-0x006186a4.StaticTextControlPane2VtableData](by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md) | Adjustors remain false/NONE/blank; scalar/vtable declaration artifacts use covered markers. No handwritten deleting-wrapper, thunk, vtable, or RTTI ABI enters this file. |
| `StaticTextControlPane2::SimpleHelpTextPartPane` | split index [UID:00011U][0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore.md); source children [UID:0004L7][0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor](by-memory/0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor.md), [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md), [UID:0004L9][0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw](by-memory/0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw.md), [UID:0004LA][0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw](by-memory/0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw.md), and [UID:0004LB][0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine](by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md); compiler support [UID:0004LC][0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks](by-memory/0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks.md) and [UID:0004LD][0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor.md); shared effects [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md) | By-value nested text-part pane with borrowed `FontStyle *` and owned text storage. It fills inherited bounds, treats CR/LF/tab equally as line delimiters, and draws effect `0` normally, `1` outlined, and `3` shadowed. The two raw children preserve exact inline-equivalent bytes through covered-by-UID00011V comments; adjustors emit no handwritten source, and the scalar wrapper records source-declared/compiler-generated destruction without handwritten ABI. Shared outlined/shadowed effects remain GrafPort-owned. |
| [UID:00005C][FontStyle](by-class/FontStyle.md) | `0x00499f10-0x00499fda`, cleanup at `0x004536e0-0x00453732` | Reusable text-style descriptor passed into `StaticTextControlPane2` constructors by callers such as `MiniMapDialog` and `NewMailDialog`. |
| `g_dialogLayoutSentinel` | global data | Layer/context sentinel currently emitted with `StaticTextControlPane2`. |

## Ownership Decision

Group the three class routes into one static-text controls module. The classes are adjacent in memory, share pane/control infrastructure, and represent two versions of the same UI role. `SimpleHelpTextPartPane` is an embedded by-value nested subpane in `StaticTextControlPane2`, so its complete declaration emits once inside UID0000E4 and its B005-owned method children route through UID0000E5 without a duplicate top-level class definition.

UID0000E4 is B002-owned and was applied first by supervisor command `000000009409`. The B005 callback adopted that verified `92/93` reserve-free outer/nested declaration byte-for-byte without editing UID0000E4, then applied the exclusive UID0000E5/UID00011U nested-method route from accepted report SHA `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`. The synchronized declaration/route blocks remained byte-identical across the ordered callbacks.

Do not merge this into [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) or [UID:0000ON][TextEditPane](by-file/TextEditPane.md). Static text drawing and help text effects are a separate control family even though they reuse font/drawing helpers and, in one generation, a text-edit child.

## Evidence Notes

- IDA MCP reports 100+ direct callers to `StaticTextControlPane::StaticTextControlPane` at `0x00499030`, which matches a generic dialog text control.
- 2026-07-04 B007 source-quality implementation for [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) makes that constructor an emitting source body through [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md). Current MCP session `73c77998` confirms `sub_499030` at `0x00499030-0x004991ec`, size `0x1bc`, predecessor padding `cc` x15, target epilogue `c2 1c 00`, four `cc` bytes before successor `sub_4991F0`, StaticText vtable stores at `0x004990be`, `0x004990c4`, and `0x004990ce`, 104 direct constructor xrefs, and caller samples supporting the seven-argument constructor order.
- Validator generation refresh after the formal constructor block insertion now represents UID00011I with constructor output rather than an Empty Emitter Marker. The remaining UID00011I caps are exact parameter/member/helper names, not a source-output blocker.
- IDA MCP reports the helper band at `0x00498dd0-0x00499021` is vtable-only and shared by TextEdit, StaticText, and ExchangeMoneyEdit vtable cells, so it is split from the constructor page instead of being emitted as an exclusive StaticText-owned range.
- IDA MCP reports eight direct callers to `StaticTextControlPane2::StaticTextControlPane2` at `0x0049a410`; all allocate `0x2a8` and constrain the ten-argument signature. Literals include `NPC`, `Portal`, `X : `, `Y : `, and `Keep a copy `.
- IDA MCP confirms `FontStyle::FontStyle` and `FontStyle::Configure` callers that build style records for `StaticTextControlPane2` labels.
- `StaticTextControlPane2::StaticTextControlPane2` constructs `ControlPane(8,NULL)`, optionally deep-copies FontStyle, measures independent CR/LF/tab segments, computes padded dimensions, aligns/clamps bounds, performs `wcscpy_s(m_textBuffer,32,text)`, initializes the embedded child, and applies exact style state.
- The prior `wchar_t[32]` plus generic 16-byte reserve interpretation is superseded. All allocations/next-member boundaries and the negative member-access audit support one `wchar_t[40]` at `+0x108..+0x157`; no separate RectBounds/FontStyleRule/record/reserve lifecycle exists at `+0x148`.
- Corrected exact helper ends are destructor `0x0049a949`, center helper `0x0049aa71`, and retained style helper `0x0049ac59`. The sole center-helper caller supports `SetCenterPosition`; constructor parity keeps `ApplyStyleState` source-live despite no external entry xref.
- Layer/remove/show/hide preserve exact parent/child ordering and the child overlay context. OnPaint fills with foreground color and frames with background color.
- `GetControlType` is non-const `unsigned char(int,int)`: target/base/sibling terminal slots all use AL plus `ret 8`. Historical `GetControlTypeId` and no-argument forms are rejected aliases.
- Ordinary empty destructor source regenerates member/base cleanup. Scalar/delete flags, two adjustors, vptr writes, RTTI, and raw vtable arrays remain compiler output represented only by exact children/markers.
- `SimpleHelpTextPartPane::OnPaint` treats CR, LF, and tab equally as line delimiters, dispatches empty and nonempty segments, and dispatches the final segment before returning.
- `SimpleHelpTextPartPane::DrawOutlinedText` and `DrawShadowedText` are text effect helpers used by `DrawTextLine`, but live caller fan-out also includes HelpPane and chat/color UI paths, so their source-owner remains shared.

## Current Caveats

- Earlier constructor notes for `0x00499030` were incomplete. B007's UID00011I implementation now records the formal source-ready constructor body; use the exact constructor memory doc as authority for the accepted first-draft C++ and its confidence caps.
- The class summary for `StaticTextControlPane` appears overfit to fitting-room user-image state. Treat fitting-room names in active/inactive helpers as provisional until field ownership is verified.
- Earlier generated-owner labels such as `BowGaugeObjectPane` and `TextButtonExControlPane` were rejected as owner-name pollution. Exact nested-class compiler support is now isolated in [UID:0004LC][0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks](by-memory/0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks.md) and [UID:0004LD][0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor.md); the source model remains an inline empty virtual destructor.
- The broad StaticTextControlPane2 memory filename range remains a non-emitting split index because it also contains FontStyle vector growth/copy, shared EH cleanup, Popup callback, Slider/TextEdit/TargetOption/TextButton/Rectangle/Scrollable ABI/source rows, and alignment. All retain their existing owners; physical adjacency does not merge them into this file's class body.

## FontStyle Header Dependency - 2026-08-17

- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md) owns `FontStyle` by value, accepts `const FontStyle *`, and uses `FontStyleRule`; the generated compilation unit therefore requires the complete `FontStyle.h` definition before the declaration.
- UID0000E4 formal CPP now includes `FontStyle.h`. This leaves `FontStyle.cpp`/`.h` owned by [UID:0000JI][FontStyle](by-file/FontStyle.md) and does not move any FontStyle constructor/GetRule/Configure or compiler vector body into StaticText source.
- Generated verification must confirm `StaticTextControlPane.cpp` includes `FontStyle.h` before first FontStyle use while preserving all existing StaticTextControlPane/StaticTextControlPane2 declarations, definitions, positions, and behavior.

## Cross-References

- [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md)
- [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)
- [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md)
- [UID:00011U][0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore.md)
- [UID:0004L7][0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor](by-memory/0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor.md)
- [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md)
- [UID:0004L9][0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw](by-memory/0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw.md)
- [UID:0004LA][0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw](by-memory/0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw.md)
- [UID:0004LB][0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine](by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md)
- [UID:0004LC][0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks](by-memory/0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks.md)
- [UID:0004LD][0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)
- [UID:0004L5][StaticTextControlPane2Vtables](by-type/by-vtable/StaticTextControlPane2Vtables.md)
- [UID:0004L6][0x00618600-0x006186a4.StaticTextControlPane2VtableData](by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)

## Changes

- 2026-08-17 B010 ArgumentedItemInputDialogs dependency closure:
  - Score remains `92/92`; the existing `NexusTK/ui/controls/StaticTextControlPane.cpp/.h` owner route is unchanged.
  - [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md) now supplies a complete sibling-header declaration and child-definition route, while [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md) emits the exact fixed return-19 body.
  - The declaration uses natural C++ layout for `m_textStateFlags`, `m_textEditPane`, and `m_savedTextPaneState`; it does not introduce reverse-engineering padding or claim the inherited TextEdit destructor wrappers as source-authored StaticText methods.

- 2026-08-17 B006 accepted UID0000JI dependency callback: documented the required shared `FontStyle.h` route through UID0000E4 and the generated include/readback expectation without changing StaticText ownership, metadata, or unrelated source.

- 2026-07-13 B005 UID00011U implementation callback:
  - Preserved the B002 `92/92` file score, `NexusTK/ui/controls/` path, complete reserve-free UID0000E4 outer/nested declaration, and deterministic class order.
  - Added the exact UID00011U corrected split route and UID0004L7-UID0004LD nested source/compiler inventory, including exact half-open ranges, covered raw-helper dispositions, inline-empty destructor model, and shared-effect ownership.
  - Corrected CR/LF/tab to equal delimiters, corrected the shared-effect end to exclusive `0x004bb0db`, and replaced generated-owner pollution with exact adjustor/scalar-wrapper evidence.
- 2026-07-13 B002 accepted UID00011V callback:
  - Raised `88/86 -> 92/92`; preserved `NexusTK/ui/controls/` and file ownership.
  - Added complete UID0000E4 source/compiler inventory with real UIDs, reserve-free layout, corrected ranges, ABI/source dispositions, callers/resources, rejected alternate owners, and exact class order UID0000E3 `10`, UID0000E4 `20`, B005-owned UID0000E5 `30`.
  - Preserved FontStyle in UID0000JI and B005 nested ownership under exact frozen SHA `321CD451...`; no B005-owned page was edited.
- 2026-06-05: A004 raised the file page to `88/86`, added live StaticText2 raw helper coverage, documented text-effect shared fan-out, and recorded sibling rows inside the broad StaticText2 filename range that remain owned by other controls.
- 2026-06-12 C001 Goal 2 split: updated the older StaticTextControlPane contents to separate the shared `0x00498dd0-0x00499021` state/border helper band from the exact `0x00499030-0x004991ec` constructor page.
  - Evidence: live IDA MCP confirmed the helper functions have TextEdit, StaticText, and ExchangeMoneyEdit vtable refs; `0x00499021-0x00499030` is fifteen `0xcc` bytes; and `sub_499030` begins the StaticText constructor at `0x00499030`.
- Before: `StaticTextControlPane2` was listed through `0x0049b914`, and `StaticTextControlPane::GetPaneTypeCode` was listed as `0x0049b920-0x0049b924`.
- Changed to: `StaticTextControlPane2` through `0x0049b915`; `StaticTextControlPane::GetPaneTypeCode` through `0x0049b925`, with a dedicated by-memory page.
- Summary/evidence: IDA MCP reports both fixed-return helpers at `0x0049b910` and `0x0049b920` as size `0x5`, so both previous end-exclusive ranges were one byte short.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers static-text control role, proposed contents, grouping decision, FontStyle relationship, IDA caller evidence, generated-output caveats, range correction, and cross-references; confidence remains capped by exact original class names and incomplete generated constructor body.
- 2026-06-04: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/`.
  - Evidence: the page already proposes `ui/controls/StaticTextControlPane.cpp` and `.h`; live IDA confirms this is a UI control family through adjacent `StaticTextControlPane`/`StaticTextControlPane2` vtables, pane constructors, dialog fan-in, and child control behavior.
  - Score unchanged because this is a parent-path assignment, not new behavioral coverage beyond the existing `86/80` file-page assessment.
- 2026-07-04 B007 source-quality implementation for UID00011I:
  - Score unchanged at `88/86`.
  - Updated the `StaticTextControlPane` proposed contents and evidence notes so [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md) is no longer described as blocked/empty after formal constructor insertion.
  - Preserved that [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) remains a shared helper band and not an exclusive StaticText constructor range.
