*** UID:0000BI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RadioGroupControlPane : public ControlPane
{
public:
    explicit RadioGroupControlPane(const RectBounds *bounds);
    virtual ~RadioGroupControlPane();

    void AddOption(const wchar_t *text, const RectBounds *bounds);
    void SetSelectedIndex(int selectedIndex);
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }

    virtual void OnPaint();

private:
    List *m_options;
    int m_selectedIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RadioGroupControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_RadioGroupControlPane.cpp`
- Parent-gate status: reconstructable class attached to direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md); final file split remains provisional, but the child and direct parent both clear the corrected 85/85 gate.

## Class Purpose

`RadioGroupControlPane` manages a list of radio-button options with labels, selection state, text accessors, hit testing, rendering, and parent notification when the selected option changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inherited `ControlPane` state helpers | [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md), [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md), [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md), [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md), [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md), [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md), [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) | Base `ControlPane` virtual/state helpers inherited by RadioGroup; not RadioGroup-owned source. |
| `RadioGroupControlPane` | `0x00495f70-0x00495fc2` | Constructs the radio group layout/state. |
| `AddOption` | `0x00496010-0x004960e1` | Adds label and rectangle data to the option list. |
| `SetSelectedIndex` / mouse hit | `0x00496110-0x004962fa` | Updates selection and handles mouse-up hit testing. |
| `OnPaint` | `0x00496300-0x0049648d` | Draws each radio option and label with selected/enabled state. Older Ghidra/Wave2 reporting ended this early at `0x0049638f`; current IDA keeps the body through `0x0049648d`. |
| Raw option helpers | [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) | Unpromoted count/fetch/rect-copy helpers and a single-option radio paint helper. |
| Value/text helpers | `0x004967c0` plus unresolved local helpers before the PopupMenu boundary | Value and option/text helper behavior remains tied to the radio group, but the former `0x00498170-0x00498ce0` row is rejected as RadioGroup ownership after the 2026-06-12 boundary audit. |
| Ordinary destructor | [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md) | Exact source definition; authored body is only `delete m_options;`. Compiler restores three vptr views and chains into Pane teardown. |
| Adjustor/deleting support | [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md), [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) | Compiler-only `this-0xa0`/`this-0xa4` adjusted entries and complete-object deleting wrapper; regenerated from the virtual declaration and UID0004X2, never handwritten. |

## Exact Layout, Ownership, And Lifetime

- Complete object size is exactly `0x110`: inherited `ControlPane` occupies `0x108`, `List *m_options` is at `+0x108`, and `int m_selectedIndex` is at `+0x10c`.
- The constructor initializes `m_options` to null and `m_selectedIndex` to zero and installs primary, secondary, and tertiary RadioGroup vptr views at complete-object offsets `0`, `+0xa0`, and `+0xa4`.
- `AddOption` creates the project `List` with element size `0x90`/144 and page capacity `10`, stores it in `m_options`, copies a 16-byte `RectBounds` and `wchar_t[64]` label into each record, and appends that record.
- The exact 144-byte source record is best named `RadioGroupOption`: `RectBounds bounds` at `+0x00` and `wchar_t text[64]` at `+0x10`. Original spelling is inferred, but size, fields, offsets, and consumers are exact.
- Selection and paint methods read/write `m_selectedIndex` and traverse those records. Both ordinary and complete-object deleting cleanup virtually delete `m_options`, proving class ownership rather than borrowed storage.

## Destructor And Compiler Boundary

- Exact ordinary source is [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md) `[0x00495fd0,0x00496005)`, 53 bytes, SHA256 `9929BB84CEC6A83AF73C86DB74EE61C301EE68F35B804B4AFFE33AAB5E3682D1`.
- The body has no inbound xrefs or VA/RVA/raw-offset pointer hits. That negative liveness evidence caps confidence, but coherent class vptr restoration, owned-list cleanup, and Pane tail teardown establish retained source identity.
- The human body is `RadioGroupControlPane::~RadioGroupControlPane() { delete m_options; }`. Vptr writes and the implicit `Pane` base-destructor chain are compiler lowering.
- [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) is a 103-byte complete-object deleting wrapper that repeats derived cleanup, invokes Pane teardown, and dispatches hidden flags between no free, project operator delete, and a `0x110`-byte one-byte no-op path.
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md) contains two exact 11-byte thunks that adjust `this` by `-0xa0` or `-0xa4` before entering UID0002YC.
- Exact three-view RTTI/vtable island `[0x00617e6c,0x00617f10)`, SHA256 `340B72245692165BEB327A9FF5AFC63D990F72AE50436C04BC0931FB7B6E356E`, routes the primary deleting slot to UID0002YC and adjusted slots to UID0002YB. The bytes are compiler data documented under [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md), not a handwritten array.
- The current class formal is intentionally preserved: its virtual destructor declaration is the source cause for UID0004X2, UID0002YB, UID0002YC, and the three vtable views.

## Evidence Notes

- Wave3 reports 22 methods, 19 aggregate ranges, 96.1 effective grade.
- IDA MCP reports 10 direct constructor xrefs to `0x00495f70`.
- 2026-05-25 IDA MCP raw-head inspection shows `0x004964a0-0x0049662f` belongs with RadioGroup option-list rendering glue, despite stale generated `TextButtonControlPane::SetTextResource` ownership at `0x004964e0`.
- The generated summary mentions parent `BrowserPane` notification; preserve that as observed behavior, but not as file ownership evidence.
- 2026-06-07 A007 parent-gate recheck: IDA MCP reports modeled surrounding methods at `0x00495f70-0x00495fc2`, `0x00496010-0x004960e1`, `0x00496110-0x00496185`, `0x00496300-0x0049648d`, `0x00496630-0x004967b1`, and `0x004967c0-0x004967f7`. Constructor/add/selection helpers have broad direct code xrefs, `OnPaint` has a vtable data xref at `0x00617eb4`, and raw helper starts [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) still have no inbound code or data xrefs. The same check reconfirmed radio asset string symbols around `0x00618750` and `0x00618784`.
- 2026-06-12 C001 boundary audit rejects the former `0x00498170-0x00498ce0` later RadioGroup row: live IDA MCP decompiles `0x00498170` and `0x00498180` as tiny forwarders into `MenuPane` helpers `sub_516400` and `sub_5164E0`, with broad menu/dialog callers. That range belongs with [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md) / [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), not this class.
- 2026-06-13 B002 split repair rejects the older `0x00494b50-0x00494c49` RadioGroup state-helper wording. Live IDA/vtable evidence places the modeled `0x00494b80-0x00494c4a` state helpers in base [UID:000038][ControlPane](by-class/ControlPane.md), while [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) is a [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) current-value setter.
- 2026-06-07 A001 Batch094 live IDA recheck reconfirmed function sizes for constructor `0x52`, `AddOption` `0xd1`, selection helper `0x75`, `OnPaint` `0x18d`, successor `SliderControlPane` constructor `0x181`, later text helper `0x0f`, adjustor thunk `0x0b`, and scalar deleting destructor `0x67`.
- 2026-06-07 A001 `xrefs_to` returned ten constructor code xrefs, broad `AddOption` fan-in from browser/object/profile/new-user style setup functions, a large selected-index helper xref set, `OnPaint` vtable data ref `0x00617eb4`, no inbound xrefs to raw helper starts `0x004964a0` or `0x004964e0`, and destructor refs from both adjustors plus primary vtable/data cell `0x00617e70`.
- 2026-06-07 A001 `callees` reconfirmed constructor dependency on the control base constructor, `AddOption` dependency on string/vector helpers, `OnPaint` dependency on `RBUTTON` EPF/palette render helpers and `DrawTextInRect`, and scalar deleting destructor dependency on option-list/base cleanup and delete dispatch.
- 2026-06-07 parent-gate check: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is `86/88` and explicitly owns the radio/choice-control family. This class now clears the corrected `85/85` attachment gate; the exact raw option-helper child can attach to this class, while final C++ remains withheld.
- 2026-07-05 B004 current MCP note for [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md): helper starts `0x004964a0`, `0x004964b0`, `0x004964c0`, and `0x004964e0` still have no inbound route and no VA/RVA pointer encodings. Current raw instructions select `"RBUTTON.EPF"` when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 == 1`, select `"RADIOBUT.EPD"` at `0x00618768` for the non-1 branch, and use `"RBUTTON.PAL"` as the palette. UID00011E therefore remains a formal no-code C++ comment under the RadioGroup route, not standalone helper-body source.

## Score Rationale

- Completion is `92` because the page combines established method bands and exact children with the complete `0x110` layout, owned List lifetime, exact 144-byte option records, ordinary source destructor UID0004X2, compiler thunk/wrapper exclusions, vtable routes, implementation-ready class declaration, and direct inline accessor consumed by UID000479.
- Confidence is `94` because constructor, AddOption, selection, paint, ordinary/deleting cleanup, and three vtable views converge. Zero inbound route to the retained ordinary body, original private/record spelling, and broad `ButtonControlPane.cpp` versus narrower historical source split remain the only material caps.

## Historical 2026-06-30 B010 Empty-Emitter Route Decision

Current MCP lookup reports `sub_495F70` size `0x52` for the constructor/entry point and `sub_49B420` size `0x67` for the scalar deleting destructor. The raw option-helper island [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) remains source-shaped but unrouted: starts `0x004964a0`, `0x004964b0`, `0x004964c0`, and `0x004964e0` are not modeled functions and have no inbound xrefs; live `OnPaint` is `sub_496300` size `0x18d` with vtable data xref `0x00617eb4`.

At that evidence checkpoint, the class emitted `[[CHILDREN]]` while avoiding a then-speculative full declaration and moved from `85/87` to `87/89`. Later constructor/layout work established the current complete class formal, and the 2026-07-25 callback adds the exact ordinary destructor child. The older raw-helper caution remains valid, but it no longer blocks the class declaration or destructor source.

## 2026-07-05 B004 UID00011E Current MCP Note

B004 incorporated current MCP evidence for [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). The raw option-helper starts still have no helper-start route and no VA/RVA pointer encoding, so the target C++ remains the formal no-code comment that routes through this class and [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). The corrected resource branch is: `byte_66DA97 == 1` / `g_useEpfAssets` selects `"RBUTTON.EPF"`; non-1 selects `"RADIOBUT.EPD"` at `0x00618768`; `"RBUTTON.PAL"` remains the palette string.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md)
- [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md)
- [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md)
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md)

## Changes

- 2026-07-25 B005 accepted UID0002YC callback:
  - Raised `90/91 -> 92/94` while preserving owner/emitter UID0000HY, reconstructable state, complete class formal, and unrelated method/boundary evidence.
  - Added exact `0x110` class layout, owned `List *m_options` lifetime, inferred 144-byte `RadioGroupOption` layout, source destructor child UID0004X2, UID0002YB/UID0002YC compiler exclusions, and the exact three-view vtable island.
  - Historicalized only the superseded declaration-withholding conclusion; retained the raw UID00011E helper no-route evidence and broad/narrow file-split caveat.
- 2026-07-14 B004 UID000470 support implementation:
  - Raised `87/89 -> 90/91`, preserved owner/emitter UID0000HY, all exact children, and the no-route/no-body status of UID00011E.
  - Replaced the former withheld-declaration comment with the accepted complete class block, closed the class before `[[CHILDREN]]`, and added only the constructor/add/selection/paint surface plus exact `List *m_options` and `int m_selectedIndex` tail.
  - Added inline `GetSelectedIndex() const` because UID000479 and direct reads prove the operation without requiring a separate source body. Resource-branch and compiler-destructor evidence remain unchanged.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The radio-button group control remained unclassified in autogen coverage despite documented project UI-control behavior and memory evidence.
  - After: The class is reconstructable but unassigned because the class completion score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms modeled starts including `0x00495f70`, `0x00496010`, `0x00496110`, `0x00496300`, `0x004967c0`, `0x00498170`, and destructor thunk/delete-wrapper starts; `0x004964a0` remains a raw helper island as documented.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/84`.
  - Before: The page was unevaluated despite documenting role, method clusters, raw helper ownership, constructor fanout, and generated-owner caveats.
  - After: Scored as moderate-high completion and strong confidence for the radio-button group control.
  - Evidence: Existing method notes, IDA MCP constructor/xref evidence, and raw-head inspection describe the class behavior and helper ownership.
- 2026-06-07 A007 Batch 004 parent-gate recheck:
  - Changed from `78/84` to `82/85`; `AUTOGEN_PARENT_UID` remains blank.
  - Evidence: fresh read-only IDA MCP rechecked constructor/add/selection/paint/successor method boundaries, broad code xrefs to constructor/add/selection helpers, the `OnPaint` vtable data xref, raw option-helper no-xref status, and radio-button asset string symbols. The page still stays below parent-attachment readiness because completion is under `85` and final class layout/source split details remain open.
- 2026-06-07 A001 Batch094 strict parent-gate update:
  - Changed from `82/85` to `85/87`; set `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA reconfirmed exact constructor/add/selection/paint/destructor sizes, broad constructor/add/selection xrefs, `OnPaint` vtable reachability, destructor refs, raw helper no-xref status, and direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) at `86/88`. Final C++ remains blank pending full field layout and source-quality helper names.
- 2026-06-12 C001 Goal 2 boundary correction:
  - Scores and parent unchanged.
  - Removed the stale `0x00498170-0x00498ce0` later-helper ownership claim after live IDA showed `0x00498170`/`0x00498180` are PopupMenu/MenuPane forwarders, not RadioGroup methods.
  - Updated the core memory cross-reference to the corrected [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) range.
- 2026-06-13 B002 state-helper split repair:
  - Scores and parent unchanged.
  - Replaced stale `0x00494b50-0x00494c49` RadioGroup-owned state-helper wording with inherited `ControlPane` state-helper links. Exact ownership is now on [UID:000038][ControlPane](by-class/ControlPane.md) and [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) children rather than this class.
- 2026-07-05 B004 UID00011E support update:
  - Scores and metadata unchanged at `87/89`.
  - Evidence: added the current no helper-start route / no VA-RVA pointer-encoding note for UID00011E, corrected `RBUTTON.EPF` versus `RADIOBUT.EPD` branch semantics, and recorded that UID00011E remains a formal no-code C++ comment.
