*** UID:000021 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "CheckBoxControlPane.h"

#include "../core/Event.h"
#include "../../render/EPFTileContext.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "ControlPane.h"

class Event;
struct RectBounds;

class CheckBoxControlPane : public ControlPane
{
public:
    CheckBoxControlPane(const RectBounds *bounds,
                        const wchar_t *tileName,
                        const wchar_t *paletteName,
                        short checkedFrame,
                        short uncheckedFrame);

    void SetChecked(bool checked);
    bool GetChecked() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);
    virtual unsigned char HitTestPart(int x, int y);

private:
    wchar_t m_tileName[16];
    wchar_t m_paletteName[16];
    short m_checkedFrame;
    short m_uncheckedFrame;
    bool m_checked;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane

## Status

- Confidence: very strong for the complete layout, virtual surface, authored children, compiler causes, and standalone source route.
- Source file: [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), settled as `NexusTK/ui/controls/CheckBoxControlPane.cpp` with companion `CheckBoxControlPane.h`.
- Parent/C++ status: source position `10`. The formal H block owns the one complete class declaration; the formal CPP block owns only the source/header/dependency preamble and `[[CHILDREN]]`. [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) emits six definitions at position `20`, and [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md) emits the terminal virtual at position `30`.
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Exact core memory: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Adjustor thunks: [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- Scalar deleting wrapper: [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md)
- Terminal authored virtual: [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md)
- Exact vtable data: [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- Type/layout docs: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md), [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- Documentation basis: IDA-confirmed constructor/caller/helper evidence, exact core/vtable/thunk memory docs, and type/layout pages.

## Class Purpose

`CheckBoxControlPane` is a reusable toggleable control consumed by MiniMap and NewMail. It stores checked state, toggles after a left-button-up event inside its bounds, invalidates through inherited Pane/ControlPane behavior, paints checked/unchecked EPF tile frames from a tile/palette pair, tracks inherited visual state, and identifies its hit-test part as `20`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CheckBoxControlPane` | `[0x00499d40,0x00499db9)` | Calls `ControlPane(7, bounds)`, copies two bounded 16-wide-character resource names, stores checked/unchecked frame ids, and initializes `m_checked=false`. |
| `SetChecked` / `GetChecked` | `[0x00499dc0,0x00499dd7)` | Writes or reads the exact checked-state byte at `+0x14C`. |
| `HandlePointerOrMouseEvent` | `[0x00499de0,0x00499e2d)` | Receives the EventHandler view at complete object `+0xA0`; on event type `3` inside `m_bounds`, toggles `m_checked`, invalidates, and forwards to `EventHandler::HandlePointerOrMouseEvent`. |
| `OnPaint` | `[0x00499e30,0x00499ec0)` | Prepares client drawing, selects the checked/unchecked frame, looks it up through `g_pEPFLib`, and renders with `m_paletteName`. |
| `SetVisualState` | `[0x00499ec0,0x00499f0e)` | Overrides the inherited same-slot virtual, compares/stores `m_visualState` at `+0x103`, handles value `20`, and invalidates null/current bounds. [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md) is evidence-only. |
| `HitTestPart` | `[0x0049b8d0,0x0049b8d5)` | Exact UID0004Y2 two-coordinate byte-return virtual; always returns `20`. |

## Evidence Notes

- IDA MCP reports 3 direct constructor xrefs.
- `0x00499ec0` is a real `0x4E`-byte SetVisualState override referenced only from primary vtable slot `0x00618520`; the inherited same-slot declaration and body resolve the earlier StateTypeHelper alias.
- Exact vtable-data UID0002M9 includes the primary COL at `0x006184d4`, all 25/11/2 slots, constructor/wrapper stores for all three table bases, seven-base RTTI/PMDs, and the successor boundary at `0x00618578`.
- 2026-05-26 IDA MCP recheck confirms `0x0049af27` and `0x0049af32` as 0xb-byte compiler adjustor thunks into scalar deleting destructor `0x0049b110`; these are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-25 IDA MCP caller checks identify two constructor calls from [UID:0000LE][MiniMap](by-file/MiniMap.md) and one from [UID:000096][NewMailDialog](by-class/NewMailDialog.md). `SetChecked` is MiniMapDialog-only in current evidence, while `GetChecked` is read by `NewMailDialog::SendMail`.
- Confirmed callers pass `L"ONOFFBUT.EPF"` and `L"BUTTON.PAL"`, so the second string field is a palette/resource name, not a visible label.
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md) fixes object size `0x150`: inherited complete/EventHandler/TimerHandler views at `0`, `+0xA0`, and `+0xA4`, tile name at `+0x108`, palette name at `+0x128`, frame words at `+0x148/+0x14A`, checked byte at `+0x14C`, and natural tail alignment.
- 2026-07-05 B009 live MCP session `supervisor_recovery_20260705` reconfirmed exact six-function core boundaries, vtable-only mouse/paint/state/type-id slots, constructor/destructor vtable stores, `0xcc` padding gaps, MiniMap/NewMail constructor/setter/getter call sites, and UTF-16LE resource bytes for `ONOFFBUT.EPF` and `BUTTON.PAL`.
- Current B009 MCP evidence reports raw function labels (`sub_499D40`, `sub_499EC0`, etc.). Historical C001 saved-label notes remain useful naming context but should not be described as current live-IDB labels unless a later safe IDA-label pass re-applies them.
- Adjustor thunks UID00011Z and scalar wrapper UID0004Y1 remain compiler-generated glue. The inherited virtual destructor makes the implicit derived destructor virtual; no explicit CheckBox cleanup body is needed because the class has no destructible derived field.
- The full 25-entry primary, 11-entry EventHandler, and 2-entry TimerHandler vtable surfaces are documented by UID0002M9/UID0001X8. The class H block declares only source-facing overrides; it does not reproduce inherited slots, vtable arrays, COLs, PMDs, or receiver-adjustor details.
- Standalone `CheckBoxControlPane.cpp/.h` is the highest-probability current source route. The former possible fold into `ButtonControlPane.cpp` is retained in historical Changes and the related file page but is rejected as current ownership because the CheckBox method cluster is physically separate and already has a coherent dedicated source topology.

## Score Rationale

- Completion `93`: complete declaration, exact `0x150` fields, all seven authored methods, source order, caller/resource behavior, RTTI/vtable relationships, compiler-only exclusions, standalone source route, and historical corrections are incorporated.
- Confidence `95`: direct method/layout/vtable/RTTI/caller evidence supports the declaration and source causes. Exact stripped private spellings and original filename proof remain inferred, so confidence stops below certainty without leaving raw names in source.

## Cross-References

- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
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
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)

## Changes

- 2026-07-26 B002 UID0002M9 source-quality implementation:
  - Changed `86/91 -> 93/95`, set source position `10`, and installed the exact formal class H plus CPP include/dependency preamble and `[[CHILDREN]]` topology.
  - Settled standalone UID0000I7 `CheckBoxControlPane.cpp/.h` as the current route; retained the ButtonControlPane fold only as rejected historical context.
  - Corrected `OnMouse`/state-helper/type-id names to `HandlePointerOrMouseEvent`, `SetVisualState`, and exact child UID0004Y2 `HitTestPart(int,int)`.
  - Added exact `0x150` layout/facet relationships, 25/11/2 virtual evidence, implicit-destructor compiler cause, and exact UID00011Z/UID0004Y1 no-code exclusions without removing earlier research.

- What existed before: the page had detailed constructor/state/mouse/paint/helper/destructor evidence, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `84/90`.
- Summary and evidence: layout, vtables, exact memory, omitted helper, caller evidence, resource names, and control type id are documented; remaining work is mainly final source-file split and exact field names.

- 2026-05-31: Grading changed from `84/90` to `86/91`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the class page referenced vtable evidence but did not link an exact by-memory vtable-data child.
  - After: the class page links [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md) as the exact vtable-data range.
  - Evidence: IDA MCP `list_globals`, `lookup_funcs`, and `py_eval` on 2026-05-31 reconfirmed the three table bases, slot targets, constructor/destructor vptr stores, and next-class boundary.

- 2026-06-06 provenance cleanup:
  - Before: the status/evidence sections still used a direct recovered-source path and output-provenance evidence.
  - After: replaced that with IDA/by-* documentation basis and recovered-output caveats; parent attachment remains blank because the final split between [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) and [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is still documented as open.
  - Evidence: exact core memory, destructor/thunk memory, adjustor thunks, vtable data, type/layout pages, and caller evidence already support the `86/91` score while final-source C++ remains below the `95/95` gate.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md) pointed at this class, but the class had no autogen parent, leaving the child layout blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), the validator-managed split-candidate file root for `NexusTK/ui/controls/CheckBoxControlPane.cpp`.
  - Evidence: [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) is assigned to that generated source root at `84/82`; this class is `86/91`; and the exact core memory, vtable-data child, layout page, omitted helper, caller/resource evidence, and control type id all align with the staged file. The original-source grouping caveat remains because the broader [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) family may still be the historical owner.
- 2026-07-05 B009 source-quality implementation:
  - Scores and metadata unchanged.
  - Historical result at that date: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) emitted first-draft source for constructor, accessors, mouse, paint, and the then-named state/type helper through this class route into `CheckBoxControlPane.cpp`.
  - Historical caveat at that date: the possible [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) fold and a future exact type-id child/routing pass remained under consideration. The 2026-07-26 UID0002M9 implementation supersedes those current-state conclusions: the route is standalone `CheckBoxControlPane.cpp/.h`, `0x00499ec0` is `SetVisualState`, and exact authored child UID0004Y2 is `HitTestPart(int,int)`.
