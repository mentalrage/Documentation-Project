*** UID:00001E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ButtonControlPane

## Status

- Confidence: strong for base button role, medium for generated helper names.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_ButtonControlPane.cpp`
- Autogen status: class page remains unclassified because no source-quality class declaration or field map is ready; the file page is assigned to `NexusTK/ui/controls/ButtonControlPane.cpp`.

## Class Purpose

`ButtonControlPane` is the base clickable button control above `ControlPane`. It installs button-specific vtables, initializes pressed/selected flags, handles selected-state redraw, and contains key-activation evidence reused by derived button classes.

[UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) treats this as the generic button/choice-control module under `ui/controls`, grouping the base button with image/text/checkbox/radio/slider/selection helpers while keeping passive progress controls and unrelated visual controls split out.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x00494f37` | Constructs the base `ControlPane`, installs button vtables, clears button state. |
| `SetControlSelected` | `0x00494f40-0x00494f63` | Updates selected state and invalidates/redraws if it changed. |
| `OnKeyPress` | `0x00494f70-0x0049500c` | Space/Enter activation evidence; Wave3 keeps polluted derived-owner naming here. |

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) | Places the class in `NexusTK/ui/controls/ButtonControlPane.cpp`, with possible later split only if original-source evidence proves it. |
| core neighborhood | [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) | Confirms the base button methods sit inside the generic button/choice-control family, not a feature dialog. |
| vtable/read-only data | [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md) | Lists `ButtonControlPane` among the generic control-pane family vtables and records representative xrefs including `sub_494EB0`. |
| destructor/thunks | [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | The destructor/thunk band maps `ButtonControlPane`, text/image/radio/slider/check controls, and exclusions through vtable ownership instead of generated owner labels. |
| derived fan-in | IDA evidence summarized in [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) | Constructor callers include generic derived controls such as image, gender, direction, and pretty buttons. |

## Boundaries And Exclusions

- `ButtonControlPane` itself is bounded inside the larger choice-control aggregate at `0x00494eb0-0x0049500c`.
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) is nearby but explicitly excluded: it owns the passive progress indicator at `0x00494c80-0x00494eaf` and should not be merged into this class just because of address locality.
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) and [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) are related button modules; they are not proof that base `ButtonControlPane` should absorb every text or pretty-button implementation.
- Generated fitting-room names around this family are owner pollution. Current docs assign the generic button base by behavior, vtables, and broad constructor fan-in.

## Evidence Notes

- Wave3 reports 3 methods, class summary "Control widget for a clickable button", and aggregate ranges at `0x00494eb0-0x00494f37` and `0x00494f40-0x00494f63`.
- IDA MCP reports 9 direct xrefs to `0x00494eb0` from derived control constructors, including image, gender, direction, and pretty buttons.
- The generated `InitializeFittingRoomUserImage(true)` name is probably helper/owner pollution and should not be treated as fitting-room ownership.
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) records a 2026-06-01 boundary audit that keeps `0x00494eb0-0x0049500d` as the base button helper band.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) records destructor/thunk ownership by vtable data and documents known generated teardown-name pollution.
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md) records the broader control-family vtable island that includes `ButtonControlPane`.

## Open Questions

- Final field names for pressed/selected/key-activation state are not yet source-quality.
- The class declaration is still below the reconstruction-code gate because the exact inheritance/subobject view and destructor slot layout need a final class-layout pass.
- Final source split between base `ButtonControlPane.cpp` and separate text/pretty/specialized button modules remains partly provisional.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- What existed before: the page documented the base button role, methods, and owner-pollution caveat, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `66/76`.
- Summary and evidence: constructor, selected-state update, key activation, and derived-constructor xrefs are covered; final helper names, event semantics, and class layout remain only partially documented.
- 2026-06-02 documentation expansion:
  - What existed before: the class page lagged the stronger file and memory pages, with only a compact method list and owner-pollution note.
  - Changed to: scores `72/82`, plus source-module placement, autogen status, ownership/layout evidence table, boundary/exclusion notes, vtable/read-only data evidence, destructor/thunk evidence, and explicit open questions.
  - Summary/evidence: existing documentation ties the base class to `NexusTK/ui/controls/ButtonControlPane.cpp`, the `ButtonChoiceControlCore` method neighborhood, the control-pane vtable island, and the destructor/thunk band. C++ and `RECONSTRUCTABLE` remain blank because the source-quality class declaration and exact field names are not final.
