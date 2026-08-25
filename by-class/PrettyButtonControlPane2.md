*** UID:0000AS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PrettyButtonControlPane2 : public ButtonControlPane
{
public:
    PrettyButtonControlPane2(const RectBounds &bounds,
                             const wchar_t *epfResourceName,
                             const wchar_t *paletteResourceName,
                             int normalFrameId,
                             int pressedFrameId,
                             int selectedFrameId,
                             int disabledFrameId,
                             unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane2();

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
    int m_disabledFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PrettyButtonControlPane2

## Status

- Confidence: strong for constructor/method/vtable boundaries, generic controls placement, exact B011 child split, source-ready constructor behavior, accepted ordinary destructor source shape, accepted callback/state/paint/click field roles, and class2 vtable store evidence; medium-high for exact original parameter and member spellings.
- Likely source files: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) / `NexusTK/ui/controls/PrettyButtonControlPane.cpp` and `.h`; this class contributes formal H at position `20`, while formal CPP retains `[[CHILDREN]]` for definitions.
- Memory range: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- Historical recovered-file lead: `source-3/simroot_v2/class_PrettyButtonControlPane2.cpp`; retained only as superseded search provenance, not current authority.

## Class Purpose

`PrettyButtonControlPane2` is an alternate styled button that stores EPF/PAL resource names and explicit normal/pressed/selected/disabled frame ids. It has animation-state handling, frame painting, click notification, and cleanup for its owned callback and string members.

## Exact Layout And Source Contract

R2 closes the complete object at exactly `0x12c` without raw padding fields or reverse-engineering comments:

| Offset / span | Size | Source member / subobject | Evidence and disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x10b` | `0x10c` | complete `ButtonControlPane` base | R8 and its deleting-wrapper size close the base before the first class2 field. |
| `+0x10c..+0x10f` | `4` | `int m_normalFrameId` | Constructor store; default paint branch. |
| `+0x110..+0x113` | `4` | `int m_pressedFrameId` | Constructor store; frame-active paint branch. |
| `+0x114..+0x117` | `4` | `int m_selectedFrameId` | Constructor store; selected paint branch. |
| `+0x118..+0x11b` | `4` | `int m_disabledFrameId` | Constructor store; disabled paint branch. |
| `+0x11c` | `1` | `bool m_selected` | UID0004EC writes it and UID0004EF reads it. |
| `+0x11d` | `1` | `bool m_visualStateFrameActive` | UID0004EE writes it and UID0004EF reads it. |
| `+0x11e..+0x11f` | `2` | natural alignment | No source member; required before the 32-bit StringBase objects. |
| `+0x120..+0x123` | `4` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName` | Constructor helper, paint `c_str`, destructor cleanup. |
| `+0x124..+0x127` | `4` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName` | Constructor helper, paint `c_str`, destructor cleanup. |
| `+0x128..+0x12b` | `4` | `FunctionObject0 *m_callback` | Constructor clear, setter replacement, click invocation, ordinary destructor delete. |

`ButtonControlPane.h` must be complete because it is the base. `StringBase.h` must be complete because both template instances are by-value members. `FunctionObjects.h` must expose the complete virtual callback type before R6 executes `delete m_callback`. `RectBounds` remains reference-only and can be forward-declared.

Inherited `m_controlFlags` and `m_reservedControlState` belong to protected [UID:000038][ControlPane](by-class/ControlPane.md) state, not duplicate Pretty-owned fields. Current direct stores reject private hidden state plus invented setters, duplicate derived members, or raw offsets. The class closes in formal H; formal CPP contains `[[CHILDREN]]`, so seven qualified source definitions emit at namespace scope. Vptr writes, member/base destructor lowering, scalar deleting wrapper UID0004EL, receiver-adjustor thunks, RTTI/vtables, EH/cookie code, and natural alignment remain compiler output.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PrettyButtonControlPane2` | `0x0054b8c0-0x0054b98d` | Source-ready R3 constructor: calls base `ButtonControlPane`, initializes derived frame/string state, then assigns inherited `m_controlFlags`, owned callback, and inherited `m_reservedControlState` in observed body order. |
| Destructor body | `0x0054b990-0x0054b9da` | Source-ready ordinary destructor body: emits `PrettyButtonControlPane2::~PrettyButtonControlPane2()` through UID0000AS as `delete m_callback;` at complete-object `+0x128`, while class2 vtable restores, `+0x124/+0x120` member cleanup, and `sub_544580` base cleanup remain compiler sequencing with raw/no-xref confidence caps. |
| `SetSelected` | `0x0054b9e0-0x0054b9f8` | Source-ready selected-state setter: writes `bool selected` to `this+0x11c` / `m_selected`, rewrites the inherited invalidation argument to null, and tail-calls `Pane::InvalidateRect(NULL)` through primary slot `+0x20`; no direct class2 xrefs or vtable cell point here, so usage confidence is capped. |
| `SetCallback` | `0x0054ba00-0x0054ba23` | Non-modeled callback replacement helper that releases the prior pointer at `this+0x128`. |
| `SetState` | `0x0054ba30-0x0054ba91` | Source-ready visual-state setter: compares inherited `m_visualState` byte `+0x103`, toggles class2 `m_visualStateFrameActive` byte `+0x11d`, schedules/removes inherited `m_timerHandler` `+0xa4` around raw state literal `0x0b`, and delegates to `ControlPane::SetVisualState`. |
| `OnPaint` | `0x0054baa0-0x0054bb48` | Source-ready R4 paint method: selects configured disabled frame when inherited `m_enabled` is false, otherwise pressed/frame-active, selected, or normal frame; uses normalized `m_visualStateFrameActive` and renders the stored EPF/PAL resources. |
| `OnClick` | `0x0054bb50-0x0054bb89` | Source-ready click handler: action values `0`/`1` schedule timer id `1` after 150 ms and invoke the owned zero-argument callback. |
| Adjustor thunks | `0x0054bb89-0x0054bb9f` | Secondary and tertiary compiler-generated thunks, false/blank on UID0004EH/UID0004EI. |
| Scalar deleting destructor | `0x0054bbc0-0x0054bc3d` | UID0004EL compiler deleting-destructor clone, now false/blank; exact source cause is this virtual destructor declaration plus UID0004EB R6. |

## Exact Child Pages

| Range | Child | Rebuild policy |
| --- | --- | --- |
| `0x0054b8c0-0x0054b98d` | [UID:0004EA][0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor](by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md) | Source-ready constructor; emits `PrettyButtonControlPane2::PrettyButtonControlPane2(...)` after B003 resolved frame/resource/string/callback initialization, vtable stores, two `sub_52C360` callers, padding, and conservative inferred spelling caps. |
| `0x0054b990-0x0054b9db` | [UID:0004EB][0x0054b990-0x0054b9db.PrettyButtonControlPane2DestructorBody](by-memory/0x0054b990-0x0054b9db.PrettyButtonControlPane2DestructorBody.md) | Source-ready ordinary destructor child; emits first-draft `PrettyButtonControlPane2::~PrettyButtonControlPane2()` after B004 resolved owned `m_callback` at `+0x128`, compiler member cleanup at `+0x124/+0x120`, vtable/base destructor sequencing, scalar-wrapper separation, and no-direct-raw-xref confidence caps. |
| `0x0054b9e0-0x0054b9f9` | [UID:0004EC][0x0054b9e0-0x0054b9f9.PrettyButtonControlPane2StateByteVirtualForwarder](by-memory/0x0054b9e0-0x0054b9f9.PrettyButtonControlPane2StateByteVirtualForwarder.md) | Source method child; emits first-draft `PrettyButtonControlPane2::SetSelected(bool selected)` after B011 resolved selected byte `+0x11c` and inherited `Pane::InvalidateRect(NULL)` slot `+0x20`. |
| `0x0054ba00-0x0054ba24` | [UID:0004ED][0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback](by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md) | Source method child; emits first-draft `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` after B013 resolved the callback type through FunctionObjects evidence. |
| `0x0054ba30-0x0054ba92` | [UID:0004EE][0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState](by-memory/0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState.md) | Source method child; emits first-draft `PrettyButtonControlPane2::SetState(unsigned char state)` after B004 resolved inherited `m_visualState` `+0x103`, class2 frame-active byte `+0x11d`, inherited timer facet `+0xa4`, raw state literal `0x0b`, and `ControlPane::SetVisualState` delegation. |
| `0x0054baa0-0x0054bb48` | [UID:0004EF][0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint](by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md) | Source method child; emits first-draft `PrettyButtonControlPane2::OnPaint()` after B005 resolved constructor-backed frame IDs, EPF/PAL string fields, state bytes, helper names, and the configured disabled-frame behavior. |
| `0x0054bb50-0x0054bb89` | [UID:0004EG][0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick](by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md) | Source method child; emits first-draft `PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)` after B006 resolved timer/callback action-handler behavior. |
| `0x0054bb89-0x0054bb94` | [UID:0004EH][0x0054bb89-0x0054bb94.PrettyButtonControlPane2SecondaryAdjustorThunk](by-memory/0x0054bb89-0x0054bb94.PrettyButtonControlPane2SecondaryAdjustorThunk.md) | Non-emitting compiler ABI thunk. |
| `0x0054bb94-0x0054bb9f` | [UID:0004EI][0x0054bb94-0x0054bb9f.PrettyButtonControlPane2TertiaryAdjustorThunk](by-memory/0x0054bb94-0x0054bb9f.PrettyButtonControlPane2TertiaryAdjustorThunk.md) | Non-emitting compiler ABI thunk. |
| `0x0054bbc0-0x0054bc3d` | [UID:0004EL][0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor](by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md) | Compiler-generated deleting clone, `92/94`, false/blank; exact bit1/bit4 behavior and vtable/thunk reachability are documented without emitting ABI source. |

## Evidence Notes

- Historical Wave3 grade `97.6` is retained only as superseded provenance and is not current evidence.
- IDA MCP reports 2 direct constructor xrefs to `0x0054b8c0`.
- 2026-06-11 A002 Batch222 read-only-data pass confirms [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md) covers all three RTTI/vtable views, constructor/destructor store xrefs, and the `PrimeNumberGenerator` successor boundary.
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) remains the source-module parent and is updated by the UID0004EL callback to `90/92`; this class remains the direct parent for the exact vtable-data child.
- A001 2026-06-16 live IDA/PE refresh reconfirmed the `0x0054b8c0` constructor size `0xcd`, two direct constructor branch sites from `0x0052c360`, zero constructor pointer encodings, and constructor decompilation over base construction, three-view vtable stores, frame/resource fields at `+268/+272/+276/+280`, resource strings at `+288/+292`, and state byte `+255`. Paint decompilation confirms configured-frame selection through state bytes around `+257/+284/+285`, but source-grade member/resource/callback names are still unresolved.
- B011 2026-07-02 MCP session `b010_0002r7_20260702` adds the exact class2 split: modeled functions at `0x0054b8c0`, `0x0054ba30`, `0x0054baa0`, `0x0054bb50`, `0x0054bb89`, `0x0054bb94`, and `0x0054bbc0`, plus scoped `insn_query` proof that `0x0054b990-0x0054b9db`, `0x0054b9e0-0x0054b9f9`, and `0x0054ba00-0x0054ba24` are live non-modeled executable spans for destructor, state-byte forwarding, and callback replacement behavior.
- B011 2026-07-03 UID0004EC source-quality callback resolves the class2 selected-state setter blocker: the exact 25-byte raw body at `0x0054b9e0-0x0054b9f9` writes the selected byte at complete-object offset `+0x11c`, rewrites the inherited invalidation argument to null, and tail-calls primary slot `+0x20`, which current MCP/vtable evidence resolves to `0x00544800` / `Pane::InvalidateRect`. The class1 counterpart [UID:0004E5][0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder](by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md) has caller pairs that pass `0` to the old selected button and `1` to the new selected button, supporting `SetSelected(bool selected)` and `m_selected`; UID0004EC itself has no direct xrefs or vtable cell, so the target page keeps the confidence cap.
- B013 2026-07-03 UID0004ED source-quality callback resolves the class2 `SetCallback` blocker: the raw setter deletes and replaces the owned callback at complete-object offset `+0x128` / decimal 296, class2 constructor/destructor/click methods use the same field, the class1 sibling setter has the same body shape, and FunctionObjects docs support `FunctionObject0 *` as the first-draft callback type. UID0004ED now emits through this class; broader class declaration and resource-field naming remain future work.
- B006 2026-07-03 UID0004EG implementation callback resolves the class2 click-handler blocker: live MCP session `9fb70afc` confirms `sub_54BB50` at `0x0054bb50` is a modeled `0x39` / decimal 57 byte function (Verified with `int_convert.py`) with one data xref from vtable slot `0x00622418`, no code callers, eight-byte pre-padding at `0x0054bb48-0x0054bb50`, and successor adjustor thunk at `0x0054bb89`. The handler accepts action values `0` and `1`, schedules the inherited timer facet through `sub_5975E0(this, 1, 150, 0, 0)`, reads adjusted callback field `[this+0x84]` from the tertiary `+0xa4` view, which maps to complete-object `+0x128`, invokes `FunctionObject0::Invoke()` through slot `+0x0c`, and returns true. UID0004EG now emits through this class; exact original action enum and parameter/member spellings remain inferred.
- B004 2026-07-03 UID0004EE implementation callback resolves the class2 visual-state/timer blocker: live MCP session `9fb70afc` confirms `sub_54BA30` at `0x0054ba30` is a modeled `0x62` / decimal 98 byte function (Verified with `int_convert.py`) with one data xref from vtable slot `0x006223c4`, no direct code callers, no xrefs to the slot address, twelve-byte pre-padding at `0x0054ba24-0x0054ba30`, and fourteen-byte post-padding at `0x0054ba92-0x0054baa0`. The method compares inherited visual-state byte `+0x103`, toggles class2 frame-active byte `+0x11d`, schedules/removes inherited timer facet `+0xa4` with 150 ms delay around raw state literal `0x0b`, and delegates final state handling to `ControlPane::SetVisualState`. PE pointer-pattern scanning found the function VA bytes exactly once at file offset `0x220dc4`, with no RVA or slot-address pattern hits. UID0004EE now emits through this class; exact original enum and member spellings remain inferred.
- B005 2026-07-03 UID0004EF implementation callback resolves the class2 paint blocker: live MCP session `9fb70afc` confirms `sub_54BAA0` at `0x0054baa0` is a modeled `0xa8` byte function with one data xref from vtable slot `0x006223c0`, no direct code callers, fourteen-byte pre-padding at `0x0054ba92-0x0054baa0`, and eight-byte post-padding at `0x0054bb48-0x0054bb50`. The constructor supplies frame IDs at `+0x10c/+0x110/+0x114/+0x118` and EPF/PAL string fields at `+0x120/+0x124`; UID0004EC supplies selected byte `+0x11c`; UID0004EE supplies state-11 visual byte `+0x11d`. The accepted source shape emits `PrettyButtonControlPane2::OnPaint()` through this class and preserves class2's disabled behavior: inherited byte `+0x101` selects configured disabled frame `+0x118`, with no class1-style `GrafPort::SetDrawColor`, `+0x70` draw-mode write, or Surface slot `0x0069b3fc` dispatch. Helper roles are `g_pEPFLib`, `ResourceLayoutTable::LookupLayoutEntry`, `EPFTileContext`, and shared `RenderTileFrame`; exact original member spellings remain inferred.
- B003 2026-07-03 UID0004EA implementation callback resolves the class2 constructor blocker: live MCP session `1fc4a5a7` confirms `sub_54B8C0` at `0x0054b8c0` is a modeled `0xcd` / decimal 205 byte function (Verified with `int_convert`) with exact range `0x0054b8c0-0x0054b98d`, two code callers at `0x52c6e1` and `0x52c745` in `sub_52C360`, seven-byte pre-padding at `0x0054b8b9-0x0054b8c0`, and three-byte post-padding at `0x0054b98d-0x0054b990`. The constructor calls base `ButtonControlPane` construction at `0x00494eb0`, calls the string helper at `0x00582560` twice, stores class2 vtables `0x0062237c`, `0x006223e4`, and `0x00622414` at `0x54b91f`, `0x54b925`, and `0x54b92f`, initializes frame IDs `+0x10c/+0x110/+0x114/+0x118`, selected/state word `+0x11c`, EPF/PAL strings `+0x120/+0x124`, constructor flag `+0xff`, callback `+0x128`, and reserved byte `+0x100`, and now emits through this class. Caller snippets pass `DIREC.EPF`, `off_61E3DC`, frame quartets `3,9,3,6` and `4,10,4,7`, and flag `0`; caller ownership, class1 ownership, direct file canonical ownership, parent aggregate emission, base/helper ownership, raw naming, and no-owner/non-emitting routes are rejected. Exact original parameter names, exact `Rect` spelling, `m_constructorFlag`, `m_reservedState`, and the `+0x11d` member spelling remain inferred confidence caps.
- B004 2026-07-03 UID0004EB implementation callback resolves the class2 ordinary destructor blocker: live MCP session `1fc4a5a7` confirms the raw non-modeled body at `0x0054b990-0x0054b9db`, no IDA function start at the raw entry, no direct raw-entry xrefs, no PE pointer-pattern hit for `0x0054b990`, vtable restores at `0x0054b999`, `0x0054b99f`, and `0x0054b9a9`, owned callback release through complete-object `m_callback` at `+0x128`, compiler member cleanup at `+0x124/+0x120`, and tail base cleanup through `sub_544580`. UID0004EB now emits `PrettyButtonControlPane2::~PrettyButtonControlPane2()` through this class as `delete m_callback;`; handwritten vtable stores, handwritten `sub_582B70` calls, handwritten `sub_544580`, raw-helper ownership, FunctionObjects ownership, and scalar-wrapper merge are rejected.

## Source And Compiler Boundary

Source-authored class content is R2 plus the seven routed class2 definitions: constructor, ordinary destructor, `SetSelected`, `SetCallback`, `SetState`, `OnPaint`, and `OnClick`. UID0004EL and UID0004EH/UID0004EI are compiler ABI output; UID0002UX is source-declared but compiler-generated RTTI/vtable data. No handwritten vptr stores, destructor member/base calls, deletion flags, storage release, adjustor thunks, vtable/RTTI arrays, EH/cookie code, or raw addresses belong in source.

The ordinary destructor body remains exactly `delete m_callback;`. Full `FunctionObject0` visibility is required at that definition; pointer-only forward declaration is insufficient for the delete expression. The constructor's inherited assignments remain legal because R7 makes the base state protected. Exact original header basenames, member spellings, and public/protected labels are inferred, but the layout, declaration order, access requirement, and behavior are closed.

## Score Rationale

Completion is `92` because the class now has a complete legal declaration, exact `0x12c` layout, complete dependency order, all seven method declarations/definitions, normalized fields and bounds type, exact source/compiler split, and target/vtable/destructor dispositions while preserving the complete prior child evidence.

Confidence is `93` because constructor stores, ordinary destructor cleanup, setter/readers, paint/click behavior, vtable slots, adjustor routes, scalar-wrapper size, and complete R7/R8 base chain converge on the declaration. Exact original header/member spellings and some access labels remain inferred and cap the score.

## Cross-References

- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)

## Changes

- 2026-07-16 B003 UID0004EL implementation:
  - Raised `89/91 -> 92/93`, retained owner/emitter/file route and reconstructable state, and set source position `20`.
  - Installed exact R2 with complete Button/StringBase/FunctionObject dependencies, canonical `RectBounds`, exact public/protected/private surface, exact `0x12c` layout, class closure before `[[CHILDREN]]`, and seven routed class2 definitions.
  - Synchronized UID0004EA to legal R3 inherited-field body assignments, UID0004EF to normalized `m_visualStateFrameActive`, UID0004EL to false/blank compiler output, UID0004EB as the sole source destructor body, and UID0002UX as compiler-generated data.
  - Historicalized Wave3/simroot, marker-only target, `m_state11VisualActive`, `m_constructorFlag`, `m_reservedState`, and incomplete-class conclusions while preserving every unrelated child range, caller/callee, resource, timer, vtable, negative, and score-cap fact.

- 2026-07-02 B011 implementation callback for accepted UID0001F9 split report:
  - Changed score from `86/88` to `87/89`.
  - Added exact class2 child pages for constructor, non-modeled destructor body, state-byte virtual forwarder, callback replacement, visual state scheduling, paint, click, adjustor thunks, and scalar deleting destructor wrapper.
  - Added B011 MCP evidence for modeled functions at `0x0054b8c0`, `0x0054ba30`, `0x0054baa0`, `0x0054bb50`, `0x0054bb89`, `0x0054bb94`, and `0x0054bbc0`, plus raw spans `0x0054b990-0x0054b9db`, `0x0054b9e0-0x0054b9f9`, and `0x0054ba00-0x0054ba24`.
- 2026-07-03 B013 implementation callback for UID0004ED:
  - Updated the UID0004ED child row from callback-type-blocked C++ to first-draft `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` emission.
  - Added class-level evidence that the class2 callback field is the owned `FunctionObject0` pointer at complete-object offset `+0x128`; the exact target page carries the formal C++ and detailed source-quality evidence.
- 2026-07-03 B011 implementation callback for UID0004EC:
  - Updated the UID0004EC method/child rows from generic state-byte forwarder with blank C++ to source-ready `SetSelected(bool selected)` emission at target score `88/90`.
  - Added class-level evidence for selected byte `+0x11c`, inherited `Pane::InvalidateRect(NULL)` through slot `+0x20`, class1 counterpart caller proof, and the no-direct-xref/no-vtable-ref confidence cap. The exact target page carries the formal C++ and full negative/rejected-alternative ledger.
- 2026-07-03 B006 implementation callback for UID0004EG:
  - Updated the UID0004EG method/child rows from generic click/notification with blank C++ to source-ready `OnClick(unsigned int action, int x, int y)` emission at target score `88/91`.
  - Added class-level evidence for action filter `0/1`, timer id `1` after 150 ms, adjusted callback field `[this+0x84]` mapping to complete `+0x128`, zero-argument `FunctionObject0::Invoke()`, vtable-only reachability from `0x00622418`, and rejected parent-notification/raw-decompiler/no-owner routes.
- 2026-07-03 B004 implementation callback for UID0004EE:
  - Updated the UID0004EE method/child rows from state-name-blocked C++ to source-ready `SetState(unsigned char state)` emission at target score `88/91`.
  - Added class-level evidence for inherited `m_visualState` byte `+0x103`, class2 `m_visualStateFrameActive` byte `+0x11d`, inherited `m_timerHandler` `+0xa4`, raw state literal `0x0b`, 150 ms schedule/remove behavior, `ControlPane::SetVisualState` delegation, vtable-only reachability from `0x006223c4`, PE pointer-pattern negative evidence, and exact original enum/member-name confidence caps.
- 2026-07-03 B005 implementation callback for UID0004EF:
  - Updated the UID0004EF method/child rows from resource/frame-name-blocked C++ to source-ready `OnPaint()` emission at target score `88/90`.
  - Added class-level evidence for constructor-backed normal/state/selected/disabled frame IDs, EPF/PAL strings, selected byte `+0x11c`, state-11 visual byte `+0x11d`, vtable-only reachability from `0x006223c0`, exact padding, helper names, and the rejected class1 disabled-overlay path.
- 2026-07-03 B003 implementation callback for UID0004EA:
  - Changed score from `87/89` to `89/91`.
  - Updated the UID0004EA method/child rows from layout/resource/callback-blocked C++ to source-ready `PrettyButtonControlPane2::PrettyButtonControlPane2(...)` emission at target score `89/91`.
  - Added class-level evidence for live MCP session `1fc4a5a7`, exact constructor range and padding, two `sub_52C360` callers, class2 vtable stores, base/string-helper callees, frame/resource/string/callback field initialization, caller argument roles, rejected ownership/source alternatives, and exact original parameter/member-name confidence caps.
- 2026-07-03 B004 implementation callback for UID0004EB:
  - Updated the UID0004EB method/child rows from destructor-field-name-blocked C++ to source-ready ordinary `PrettyButtonControlPane2::~PrettyButtonControlPane2()` emission at target score `88/91`.
  - Added class-level evidence for raw non-modeled body `0x0054b990-0x0054b9db`, vtable restores, owned `m_callback` at `+0x128`, compiler cleanup at `+0x124/+0x120`, base `Pane` cleanup through `sub_544580`, scalar-wrapper separation, no direct raw-entry xrefs, no PE pointer-pattern hit, and rejected raw-helper/FunctionObjects/scalar-wrapper/handwritten-cleanup routes.
- Before: the containing `PrettyButtonControls` memory page ended at `0x0054bcbc`.
- Changed to: the page ends at `0x0054bcbd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the previous endpoint omitted the final `retn 4` operand byte in the neighboring `PrettyButtonControlPane` destructor.
- Before: completion/confidence metadata were `0/0` despite method map, resource/frame role, constructor xrefs, and endpoint correction.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, state/animation scheduling, EPF/PAL paint, click notification, destructor/thunks, two constructor xrefs, and corrected containing range are documented; remaining gaps are exact fields and reconstructed C++.
- Before: reconstructable owner/emitter metadata were blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000MP`, and `EMITTER_UIDS:0000MP`.
- Evidence: the alternate styled-button class is documented as NexusTK-owned source in the same executable cluster and owning [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) source root, which now has a valid projected path.
- 2026-06-11 A002 Batch222 parent-gate refresh:
  - Before: `76/84`, below the strict direct-parent gate for the exact vtable-data child.
  - Changed to: `85/86`.
  - Summary/evidence: live IDA MCP/current docs confirm constructor/method ranges, two constructor callers, exact vtable child range, all three vtable base store xrefs, source-module routing through [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md), and remaining field/resource/callback naming blockers.
- 2026-06-16 A001 Goal 2 evidence refresh:
  - Before: `85/86`.
  - Changed to: `86/88`.
  - Summary/evidence: live IDA/PE checks reconfirmed constructor size, two direct branches and no pointer encodings to `0x0054b8c0`, exact vtable-store route, constructor field-offset behavior, and configured-frame paint behavior. Final C++ remains blank because source-grade field/resource/callback names are not resolved.
