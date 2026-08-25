*** UID:0000I7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CheckBoxControlPane

## Status

- Confidence: very strong for the standalone source root, complete declaration/method order, behavior, and compiler exclusions.
- Settled module: `ui/controls/CheckBoxControlPane.cpp` with companion `CheckBoxControlPane.h`. The former possible fold into [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is retained only as rejected historical grouping context.
- Documentation basis: exact core memory, vtable data, type/layout docs, IDA/caller evidence, and recovered-output caveats.
- Exact core memory: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- Type/layout docs: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md), [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- Exact vtable data: [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)

## File Role

`CheckBoxControlPane.cpp` owns the reusable toggleable checkbox control. It stores checked state, toggles on left-button-up inside its bounds, forwards inherited EventHandler behavior, paints checked/unchecked frames from a tile/palette pair, tracks inherited visual state, and returns fixed hit-test part `20`.

Confirmed consumers are cross-feature: [UID:0000LE][MiniMap](by-file/MiniMap.md) constructs NPC and portal toggle checkboxes and seeds their state from config bytes, while [UID:000096][NewMailDialog](by-class/NewMailDialog.md) constructs the "Keep a copy" checkbox and reads it while serializing outgoing mail.

[UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md) emits the exact header declaration and CPP include/dependency preamble at position `10`. [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) emits six method definitions at `20`. [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md) emits `HitTestPart(int,int)` at `30`.

Exact source order:

| Position | UID | Source contribution |
| ---: | --- | --- |
| 10 | UID000021 | `CheckBoxControlPane.h` declaration; CPP header/dependency includes and `[[CHILDREN]]` |
| 20 | UID00011S | constructor, SetChecked/GetChecked, HandlePointerOrMouseEvent, OnPaint, SetVisualState |
| 30 | UID0004Y2 | `unsigned char CheckBoxControlPane::HitTestPart(int,int)` |

## Boundary Notes

The class remains related to the generic button/choice-control family, but direct folding into UID0000HY is rejected for current reconstruction. The dedicated method cluster, complete class topology, separate file root, and cross-feature consumers support standalone CheckBox source. Historical fold speculation remains below in Changes so its provenance is not lost.

Recovered-output caveats:

- `class_CheckBoxControlPane.cpp` names the second copied string `labelName`, but IDA/caller evidence shows it is a palette/resource name such as `BUTTON.PAL`.
- The primary vtable references `0x00499ec0`, resolved as the inherited-slot `SetVisualState(unsigned char)` override that historical output omitted.
- The exact vtable data child [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md) confirms all three table views, their constructor/destructor stores, and the next-class boundary at `0x00618578`.
- The recovered disabled companion omitted `0x0049af27` and only emitted `0x0049af32`, but IDA confirms both as 0xb-byte compiler adjustor thunks into scalar deleting destructor `0x0049b110`. They are documented as [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) and should not be migrated as handwritten source.
- The recovered file declared `g_pEPFLib` locally because the paint path consumes it. Global ownership remains with [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / [UID:0000K2][ImageLib](by-file/ImageLib.md).
- Live evidence fixes the exact method inventory: constructor `0x79`, setter `0x10`, getter `0x07`, EventHandler-view pointer/mouse override `0x4D`, paint `0x90`, SetVisualState `0x4E`, and HitTestPart `0x05`. Constructor callers/resources, checked-state access, EPF rendering, exact vtable stores, and complete COL-inclusive `[0x006184d4,0x00618578)` island are documented in the linked children.
- 2026-06-16 C001 live IDA refresh and DB update preserved the same split-candidate evidence and applied source-quality function names: `CheckBoxControlPane_Constructor`, `CheckBoxControlPane_SetChecked`, `CheckBoxControlPane_GetChecked`, `CheckBoxControlPane_OnMouse`, `CheckBoxControlPane_OnPaint`, `CheckBoxControlPane_StateTypeHelper`, `CheckBoxControlPane_GetControlTypeId`, and `CheckBoxControlPane_ScalarDeletingDestructor`. Constructor callers remain `0x00450f60`, `0x0045100d`, and `0x0047d3b4`; setter callers remain the two MiniMap initialization sites; the getter caller remains the NewMail send path at `0x0047dfd0`.
- 2026-07-05 B009 current MCP session `supervisor_recovery_20260705` reconfirmed the same method sizes and call sites but currently reports raw function names (`sub_499D40`, `sub_499EC0`, etc.). Treat C001 names as historical/proposed naming context, not current live-IDB label facts.
- Evidence-only by-item [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md) is false/non-emitting; UID00011S emits the body once.
- [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md) is the exact authored terminal virtual. `mov al,20; retn 8`, its primary slot, and base/sibling contracts reject the former no-argument type-id interpretation.
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md), [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md), and UID0002M9/UID0001X8 RTTI/vtable data are compiler-only and emit no source markers. The implicit virtual derived destructor is their source cause.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | The page records the settled module/header, exact 10/20/30 source order, complete class/core/HitTestPart contributions, layout/vtable/RTTI support, consumers/resources, compiler exclusions, rejected fold, and historical corrections. |
| Confidence | 94 | Direct binary and documentation evidence agree on behavior and standalone source topology. Exact stripped original filename/private spelling remains inferred rather than symbol-proven. |

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md)
- [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-07-26 B002 UID0002M9 source-quality implementation:
  - Changed `86/88 -> 92/94` and settled standalone `NexusTK/ui/controls/CheckBoxControlPane.cpp/.h` as current source placement.
  - Added exact source positions 10/20/30 and linked the complete UID000021 declaration, corrected UID00011S definitions, and exact authored UID0004Y2 HitTestPart child.
  - Corrected state/type and type-id terminology to SetVisualState and HitTestPart, and documented UID00011Z/UID0004Y1/UID0002M9 compiler-only exclusions.
  - Retained prior ButtonControlPane-fold and generated-name assumptions below as rejected historical context rather than deleting them.

- 2026-06-14 A001 Goal 2 low-confidence refresh:
  - Before: `84/82`, with strong class/core/type support but file confidence capped by an under-explained standalone-file versus `ButtonControlPane.cpp` caveat.
  - After: `85/86`, preserving `NexusTK/ui/controls/` as the validator-managed split-candidate root while keeping the broader [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) grouping caveat open.
  - Evidence: live IDA MCP `b001_0003gy` reconfirmed all checkbox method sizes, constructor xrefs, constructor vtable/resource-state stores, paint-time checked/unchecked frame selection, and the three `CheckBoxControlPane` vtable heads; linked class/core/type pages are already at or above `85/85`.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: checkbox behavior, consumers, memory/type/vtable anchors, resource/global caveats, and adjustor-thunk exclusions are documented; confidence is capped by the unresolved standalone-file versus `ButtonControlPane.cpp` grouping.

- 2026-05-31: Grading changed from `82/78` to `84/82`, and `PROPOSED_RECONSTRUCTION_PATH` was set to `NexusTK/ui/controls/`.
  - Before: the page named `ui/controls/CheckBoxControlPane.cpp` in prose but the validator-managed projected path was blank, and exact vtable storage was not split into its own by-memory child.
  - After: the page stages the split-candidate source path under `NexusTK/ui/controls/` and links [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md).
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `CheckBoxControlPane.cpp` under `ui/controls`, while noting the possible fold into `ButtonControlPane.cpp`; IDA MCP checks on 2026-05-31 verify the exact vtable data and recovered-output omissions.

- 2026-06-06 provenance cleanup:
  - Before: the status and boundary notes described the page with direct recovered-source paths and output-provenance wording.
  - Changed to: IDA/by-* documentation basis plus recovered-output caveat wording, without changing scores, path, ownership, or final C++ status.
  - Evidence: the exact core memory, vtable data child, type/layout pages, and consumer references already support the split-candidate page.
- 2026-06-16 C001 IDA/name refresh:
  - Before: `85/86`, with support at gate but the file page still dependent on earlier generated/raw names for the concrete method set.
  - After: `86/88`, preserving `NexusTK/ui/controls/` and the possible [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) fold.
  - Evidence: live IDA reconfirmed exact function sizes, constructor/setter/getter caller sets, vtable refs at `0x006184d8`, `0x00618540`, and `0x00618570`, and the `0x00499d40-0x00499f0e` unique range signature; C001 applied and saved the eight checkbox function names listed above. No globals, prototypes, vtable entries, type members, or source-file merge changes were applied because the final historical split and inherited subobject names remain unresolved.
- 2026-07-05 B009 source-quality implementation:
  - Scores, path, and file metadata unchanged.
  - Recorded that UID00011S now emits first-draft source through [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md) into this `CheckBoxControlPane.cpp` route. The broader [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) fold remains a historical-source caveat, not a current route change.
  - Historical result at that date: added the then-current MCP raw-label caveat, no-duplicate by-item helper disposition, compiler destructor/thunk exclusion, and a future exact type-id child/routing note. The 2026-07-26 UID0002M9 implementation supersedes that last open item with exact authored child UID0004Y2 `CheckBoxControlPane::HitTestPart(int,int)` at source position `30`.
