*** UID:0000AR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "ButtonControlPane.h"
#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"

struct RectBounds;

class PrettyButtonControlPane : public ButtonControlPane
{
public:
    PrettyButtonControlPane(const RectBounds &bounds,
                            const wchar_t *epfResourceName,
                            const wchar_t *paletteResourceName,
                            int normalFrameId,
                            int pressedFrameId,
                            int selectedFrameId,
                            unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane();

    void SetSelected(bool selected);
    void SetCallback(FunctionObject0 *callback);

protected:
    virtual void SetState(unsigned char state);
    virtual int OnPaint();
    virtual bool OnClick(unsigned int action, int x, int y);

private:
    int m_normalFrameId;
    int m_pressedFrameId;
    int m_selectedFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PrettyButtonControlPane

## Status

- Source-ready complete formal H declaration and header preamble at source position `10`, before [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md) H position `20`; formal CPP retains only `[[CHILDREN]]` for definitions.
- Likely source files: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) / `NexusTK/ui/controls/PrettyButtonControlPane.cpp` and `.h`.
- Executable family: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md).
- Exact complete-object size: `0x128` / decimal 296.
- Seven human source definitions emit through this class: constructor, ordinary destructor, `SetSelected`, `SetCallback`, `SetState`, `OnPaint`, and `OnClick`.
- [UID:0004EM][0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor](by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md) and UID0004EJ/UID0004EK are compiler ABI output and remain false/blank.
- [UID:0002UW][0x006222d4-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md) is source-declared/compiler-generated data and emits only its generated-binary marker.

## Class Purpose

`PrettyButtonControlPane` is a reusable styled button that owns EPF and palette resource names, three normal/pressed/selected frame identifiers, selected and visual-state-frame flags, and a nullable zero-argument callback. It renders its configured frame, overlays disabled appearance, schedules visual/click timers, invokes the callback, and releases the callback in its ordinary destructor.

Historical "enable/hover animation state" wording was descriptive but conflated two independent fields. Current caller/writer evidence resolves them as `m_selected` and `m_visualStateFrameActive`.

## Exact Layout And Source Contract

| Offset / span | Size | Source member / subobject | Evidence and disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x10b` | `0x10c` | complete `ButtonControlPane` base | Current accepted base declaration and deleting-wrapper size. |
| `+0x10c..+0x10f` | `4` | `int m_normalFrameId` | Constructor store and default paint branch. |
| `+0x110..+0x113` | `4` | `int m_pressedFrameId` | Constructor store and `m_visualStateFrameActive` paint branch. |
| `+0x114..+0x117` | `4` | `int m_selectedFrameId` | Constructor store and `m_selected` paint branch. |
| `+0x118` | `1` | `bool m_selected` | UID0004E5 direct writer, 42 selection-call xrefs, UID0004E8 reader. |
| `+0x119` | `1` | `bool m_visualStateFrameActive` | UID0004E7 direct writer and UID0004E8 first-priority reader. |
| `+0x11a..+0x11b` | `2` | natural alignment | No source member; aligns the pointer-sized string objects. |
| `+0x11c..+0x11f` | `4` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName` | Constructor helper, paint `c_str`, ordinary/wrapper cleanup. |
| `+0x120..+0x123` | `4` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName` | Constructor helper, paint `c_str`, ordinary/wrapper cleanup. |
| `+0x124..+0x127` | `4` | `FunctionObject0 *m_callback` | Constructor clear, setter replacement, click invocation, ordinary/wrapper delete. |

- The deleting wrapper's bit-4 branch passes `0x128`, and all observed constructor callsites allocate 296 bytes, independently closing the object size.
- `m_controlFlags` at inherited `+0xff` and `m_reservedControlState` at inherited `+0x100` belong to protected [UID:000038][ControlPane](by-class/ControlPane.md) state. They are not duplicate Pretty-owned fields.
- The class contains no explicit raw padding member. The compiler supplies the natural two-byte alignment after the booleans.

## Dependency And Access Requirements

- `ButtonControlPane.h` must be included because a base class must be complete.
- `StringBase.h` must be included because both template instances are by-value members.
- `FunctionObjects.h` must expose the complete virtual `FunctionObject0` type before the ordinary destructor executes `delete m_callback`.
- `RectBounds` is reference-only and can be forward-declared.
- `Event` is not used by a direct PrettyButtonControlPane declaration. Its current forward declaration remains a transitive `ButtonControlPane` responsibility.
- `EPFTileContext`, `FrameDrawRecord`, `g_pEPFLib`, render helpers, and surface callbacks are translation-unit method-definition dependencies, not class-layout members.
- Public constructor/destructor/setters and protected state/paint/click overrides match the accepted class2 and base control-family source surface.
- Direct assignments to protected inherited `m_controlFlags` and `m_reservedControlState` are source-faithful. Duplicate derived fields, invented setters, private inaccessible state, and raw offset writes are rejected.

## Method Notes

| Method | Exact range | Source role |
| --- | --- | --- |
| `PrettyButtonControlPane` | `0x0054b5e0-0x0054b6a4` | [UID:0004E3][0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor](by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md) exact seven-argument constructor: `RectBounds`, two resource names, normal/pressed/selected frame ids, final constructor flag; base construction, two strings, three view stores, 30 direct xrefs, `0x128` allocations, selected/state clear, protected inherited state assignments, and callback clear. |
| `~PrettyButtonControlPane` | `0x0054b6b0-0x0054b6fb` | [UID:0004E4][0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody](by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md) raw non-modeled ordinary source destructor body; human statement is `delete m_callback`, while vtable restoration, string cleanup, and inherited teardown are compiler sequencing. |
| `SetSelected(bool)` | `0x0054b700-0x0054b719` | [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md) writes `m_selected` at `+0x118` and invalidates whole bounds through inherited `Pane::InvalidateRect(NULL)` slot `+0x20`; 42 callers clear old and set new selected controls. |
| `SetCallback(FunctionObject0 *)` | `0x0054b720-0x0054b744` | [UID:0004E6][0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback](by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md) deletes the old callback and stores the replacement at `+0x124`; two direct create-user callback-construction callers. |
| `SetState(unsigned char)` | `0x0054b750-0x0054b7b2` | [UID:0004E7][0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState](by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md) compares inherited `m_visualState` `+0x103`, toggles `m_visualStateFrameActive` `+0x119`, schedules/removes inherited `m_timerHandler` around literal `0x0b`, and delegates to `ControlPane::SetVisualState`. |
| `OnPaint()` | `0x0054b7c0-0x0054b879` | [UID:0004E8][0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint](by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md) selects pressed, selected, or normal frame in that priority, resolves EPF/palette strings, renders into inherited bounds, and when disabled sets color `143`, draw mode `2`, and dispatches the surface bounds callback. |
| `OnClick(unsigned int,int,int)` | `0x0054b880-0x0054b8b9` | [UID:0004E9][0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick](by-memory/0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick.md) accepts action ids `0/1` for timer id `1` after 150 ms and nullable callback invocation, then returns true for all actions; exact original parameter names remain inferred. |

## Exact Child Pages

| Range | Child | Rebuild policy |
| --- | --- | --- |
| `0x0054b5e0-0x0054b6a4` | [UID:0004E3][0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor](by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md) | Source constructor; emits through this class with exact `RectBounds`, selected-state names, and protected inherited-state body assignments. |
| `0x0054b6b0-0x0054b6fb` | [UID:0004E4][0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody](by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md) | Sole human destructor definition; emits `delete m_callback`. |
| `0x0054b700-0x0054b719` | [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md) | Source `SetSelected(bool)`; exact selected semantics. |
| `0x0054b720-0x0054b744` | [UID:0004E6][0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback](by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md) | Source callback ownership/replacement method. |
| `0x0054b750-0x0054b7b2` | [UID:0004E7][0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState](by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md) | Source visual-state/timer override. |
| `0x0054b7c0-0x0054b879` | [UID:0004E8][0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint](by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md) | Source paint method with normalized selected/state field names. |
| `0x0054b880-0x0054b8b9` | [UID:0004E9][0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick](by-memory/0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick.md) | Source click/timer/callback method. |
| `0x0054bb9f-0x0054bbaa` | [UID:0004EJ][0x0054bb9f-0x0054bbaa.PrettyButtonControlPaneSecondaryAdjustorThunk](by-memory/0x0054bb9f-0x0054bbaa.PrettyButtonControlPaneSecondaryAdjustorThunk.md) | False/blank compiler thunk; subtracts `0xa0` and jumps to UID0004EM. |
| `0x0054bbaa-0x0054bbb5` | [UID:0004EK][0x0054bbaa-0x0054bbb5.PrettyButtonControlPaneTertiaryAdjustorThunk](by-memory/0x0054bbaa-0x0054bbb5.PrettyButtonControlPaneTertiaryAdjustorThunk.md) | False/blank compiler thunk; subtracts `0xa4` and jumps to UID0004EM. |
| `0x0054bc40-0x0054bcbd` | [UID:0004EM][0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor](by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md) | `92/94` false/blank compiler deleting wrapper; source cause is this declaration plus UID0004E4. |

## Vtable And Compiler Boundary

- [UID:0002UW][0x006222d4-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md) contains primary, secondary, and tertiary views beginning at `0x006222d8`, `0x00622340`, and `0x00622370`.
- Constructor, raw ordinary destructor, and deleting wrapper store all three view bases.
- Primary deleting cell points directly to UID0004EM; secondary/tertiary deleting cells point to UID0004EJ/UID0004EK.
- Primary slots include `OnPaint` at `0x0062231c` and `SetState` at `0x00622320`; tertiary slot `0x00622374` points to `OnClick`.
- Multiple vtable views do not imply multiple source bases. One public `ButtonControlPane` source base supplies inherited ABI facets; receiver-adjustor thunks are compiler output.
- Do not hand-author vptr stores, RTTI/vtable arrays, deleting wrappers, receiver-adjustor thunks, member/base destructor lowering, SEH/cookie code, or raw addresses.

## Evidence Notes

- Evidence-time live MCP database `64c11373` was healthy with ready auto-analysis, Hex-Rays, and strings cache.
- UID0004E3 constructor is `0xc4`, has 30 code xrefs from three containing functions, and every inspected caller allocates `0x128` bytes.
- UID0004E5 is `0x19`, eight instructions, with 42 code xrefs. Representative callers call it with `0` on the old item and `1` on the new item before storing the selected index, proving selected rather than hover semantics.
- UID0004E8 branch order is exact: `+0x119 -> +0x110`, then `+0x118 -> +0x114`, otherwise `+0x10c`. UID0004E7 writes `+0x119`, and UID0004E5 writes `+0x118`.
- UID0004E6 stores an owned `FunctionObject0 *` at `+0x124`; create-user callers construct zero-argument member-function wrapper objects.
- UID0004E9 uses the adjusted timer facet and callback pointer, schedules timer id `1` for 150 ms on action ids `0/1`, and returns true for all actions.
- UID0004E4 raw destructor and UID0004EM wrapper both delete `+0x124`, destroy strings `+0x120/+0x11c`, and route through inherited teardown.
- UID0004EM is exactly 125 bytes, binary SHA256 `A5038605020B355F8406805F041DC299171738E29A3D4DFF9F89E48A267E246F`, 39 instructions, 7 blocks, complexity 3, and uses object-size immediate `0x128` on its bit-4 no-op branch.
- `RectBounds`, `m_selected`, `m_selectedFrameId`, `m_visualStateFrameActive`, inherited `m_controlFlags`, and inherited `m_reservedControlState` are the coherent source-facing names. Historical `Rect`, hover aliases, `m_state11VisualActive`, `m_constructorFlag`, and `m_reservedState` are superseded.

## Source And Compiler Boundary

Human source:

- this complete declaration;
- UID0004E3-UID0004E9 source definitions.

Compiler/generated-binary output:

- UID0004EJ/UID0004EK thunks;
- UID0004EM deleting wrapper;
- UID0002UW RTTI/vtable data;
- vptr stores, member/base cleanup sequencing, deletion flags/storage release, bit-4 runtime path, SEH/cookies, and return-this ABI.

The ordinary destructor source remains exactly `delete m_callback;`. Full `FunctionObject0` visibility is required for that delete expression. String destruction is implicit from by-value members, and inherited teardown is implicit from the base declaration.

## Generated Source Expectations

- This formal H declaration appears at source position `10`, before class2 H position `20`.
- The class closes in H; formal CPP contains only `[[CHILDREN]]`, so all seven qualified definitions emit at namespace scope.
- Each class1 definition occurs exactly once.
- UID0000AR Empty Emitter Marker is absent.
- UID0004EM target/title/address/comment output is absent.
- UID0002UW emits one generated-binary marker and no raw RTTI/vtable array.
- Class2 declaration/content remains once and unchanged.
- Generated source contains no raw addresses, `sub_` labels, vptr stores, deleting flags, adjustor arithmetic, RTTI arrays, SEH/cookie code, or decompiler syntax.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Complete declaration, exact `0x128` layout, dependency/access closure, all seven source methods, normalized field names, exact destructor/wrapper/thunk/vtable decomposition, source position, and generated route are documented. |
| Confidence | 93 | Constructor allocations/stores, selected callers, state/paint readers/writers, callback ownership, ordinary/wrapper teardown, vtable slots, and accepted base/type contracts converge. Exact original header/private member/parameter spellings remain inferred. |

## Historical Corrections

- Historical Wave3 effective grade `95.9` and `source-3/simroot_v2/class_PrettyButtonControlPane.cpp` are retained only as superseded provenance, not current evidence or source authority.
- Historical class score `76/84`, later `85/86`, `86/88`, and `89/91` reflected progressively resolved range, owner, child, callback, state, paint, click, constructor, and destructor evidence.
- Historical `m_hoverFrameId`, `m_hoverFrameActive`, and `m_state11VisualActive` are superseded by direct selection/state evidence.
- Historical Pretty-owned `m_constructorFlag`/`m_reservedState` are superseded by protected inherited `m_controlFlags`/`m_reservedControlState`.
- Historical blank class formal and generated Empty Emitter Marker represented unresolved declaration debt; the complete declaration now resolves that debt.
- Historical UID0004EM comment-only marker is superseded by exact false/blank compiler policy.
- The corrected family endpoint `0x0054bcbd` remains exact; `0x0054bcbc` is the final operand byte of the deleting wrapper's `retn 4`.

## Cross-References

- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md)
- [UID:0002UW][0x006222d4-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)

## Changes

- 2026-07-16 B003 UID0004EM implementation callback:
  - Raised `89/91 -> 92/93`, retained owner/emitter UID0000MP and reconstructable state, and set source position `10`.
  - Installed the complete `0x128` class declaration with exact dependencies, access, method surface, layout, natural alignment, and class closure before `[[CHILDREN]]`.
  - Normalized class1 selected/state names, resolved inherited protected control state, and synchronized UID0004E3/UID0004E8 source formals.
  - Classified UID0004EM as false/blank compiler output, UID0004EJ/UID0004EK as retained false/blank thunks, UID0002UW as generated-binary data, and UID0004E4 as the sole source destructor.
  - Preserved all prior child ranges, constructor/caller, callback, timer, paint, click, resource, vtable, negative, historical, and endpoint facts at same-or-greater detail.
