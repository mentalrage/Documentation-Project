*** UID:000022 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CheckBoxTextControlPane : public ControlPane
{
public:
    CheckBoxTextControlPane(bool checked,
                            const wchar_t *label,
                            const RectBounds *bounds);
    virtual ~CheckBoxTextControlPane();

    void SetChecked(bool checked);
    bool GetChecked() const;

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    bool m_checked;
    wchar_t m_label[256];
};

typedef char CheckBoxTextControlPaneSizeMustBe780[
    sizeof(CheckBoxTextControlPane) == 0x30c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheckBoxTextControlPane

## Status

- Confidence: very strong for the complete declaration, exact `0x30c` layout, six semantic methods, three inherited vtable facets, compiler/source split, and reusable-control ownership. The literal historical source filename and private lexical spellings remain bounded inferences.
- Source family: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), emitted as `NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h`; a standalone historical CheckBox file remains a lower-ranked possibility, not an active source blocker.
- IDA MCP rechecked: 2026-06-12.
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- Rebuild handling: source-authored reusable UI-control class attached to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at header position `40`. This page emits the complete formal H declaration; its CPP channel is intentionally blank. Exact children emit constructor `10`, destructor `20`, paint `30`, setter `40`, getter `50`, and [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) `HitTestPart(int,int)` at `60`.

## Class Purpose

`CheckBoxTextControlPane` is a reusable checkbox plus text label control. It stores `bool m_checked` at offset `+0x108`, stores `wchar_t m_label[0x100]` at `+0x10a`, paints on/off EPF tile state, draws the shadowed label text, and tears down through the base control path.

The checked state is exposed by `GetChecked()` at `0x0059e0c0` and mutated by `SetChecked(bool)` at `0x0059e0b0`; [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) also reads/toggles offset `+0x108` directly. The shared five-byte body at `0x004214c0` is instead the terminal virtual `unsigned char HitTestPart(int,int)` returning part code `22`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HitTestPart` | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) | Terminal primary virtual with physical ABI `char __stdcall(int,int)`: returns part code `22` in `AL` and pops eight argument bytes. Twelve primary vtables share the folded body, so the source projection is `unsigned char CheckBoxTextControlPane::HitTestPart(int,int)` while IDA retains a non-class-specific physical name. |
| `CheckBoxTextControlPane` | [UID:0003FE][0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw](by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md) | Raw constructor-shaped bytes ending in `retn 0Ch`: calls the base control constructor with argument `8`, installs three vtables, stores the initial checked flag, and copies the label. IDA does not currently model this as a function; Batch 251 corrected the exclusive end to `0x0059df27`. |
| vtable/base teardown helper | [UID:0003FF][0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper](by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md) | IDA-modeled helper that reinstalls `CheckBoxTextControlPane` vtables and tail-calls the base teardown path at `0x00544580`. |
| `OnPaint` | [UID:0003FG][0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint](by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md) | Draws checkbox tile and label text with shadow effect, selecting tile state from the checked byte. |
| `SetChecked` | [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) | Source-ready raw setter that stores the caller-supplied byte/bool into `m_checked` at `+0x108` and performs no invalidation. IDA does not model the raw entry and no direct refs/pointer hits are currently known; PartySearch toggles the field directly and then invalidates the child separately. |
| `GetChecked` | [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) | IDA-modeled getter that returns `m_checked` from byte `+0x108`; no direct refs are currently known. |
| Adjustor thunks | `0x0059efeb-0x0059f001` | Secondary-base this-adjustors subtract `0xa0` and `0xa4`, then forward to the scalar deleting destructor. |
| Scalar deleting destructor | [UID:0003FJ][0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor](by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md) | Reinstalls class vtables, calls base teardown, and conditionally deletes the `0x30c`-byte object. |

## Layout And Vtable Evidence

| Evidence | Source |
| --- | --- |
| `bool m_checked` at `+0x108` | [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) and [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md) record constructor storage, [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) writes, [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) reads, paint use, and direct `PartySearchEditPane` toggling. |
| `wchar_t m_label[0x100]` at `+0x10a` | The constructor-shaped bytes copy a `0x100` wide-character label, and `OnPaint` scans/draws the buffer twice for shadow and foreground text. |
| Three-view vtable layout | [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) records primary `0x0062e99c`, secondary `0x0062ea04`, and tertiary `0x0062ea34`; [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md) tracks the exact `.rdata` child. |
| Terminal hit-test virtual | [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) returns part code `22`; primary slot parity with `ControlPane::HitTestPart(int,int)` and `retn 8` reject the historical zero-argument `GetControlType` interpretation. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports `0x0059ded0` still has no function object or xrefs, but direct disassembly shows a complete constructor-shaped sequence through `retn 0Ch` at `0x0059df24`.
- The raw constructor calls `sub_4949E0` with argument `8`, stores the checked byte from `[ebp+8]` at `+0x108`, copies the input wide string into `+0x10a` with `_wcscpy_s` and a `0x100` wide-character count, and writes the three class vtables at `0x0059defc`, `0x0059df02`, and `0x0059df0c`.
- IDA MCP decompilation of [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) returns `22`/`0x16`; exact bytes `b0 16 c2 08 00`, two popped arguments, primary terminal-slot parity, and twelve vtable xrefs establish a shared folded hit-test body rather than a zero-argument control-type helper.
- IDA recognizes `0x0059df30-0x0059df4f`, `0x0059df50-0x0059e0ac`, `0x0059efeb-0x0059eff6`, `0x0059eff6-0x0059f001`, and `0x0059f050-0x0059f0a5` as functions.
- `0x0059df30` reinstalls the three class vtables and jumps to `sub_544580`. `0x0059f050` reinstalls the same vtables, calls `sub_544580`, and applies deleting flags through `sub_4F4AC0` or the guarded `0x30c`-byte delete path.
- `OnPaint` resolves `ON` resources through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, scans the `+0x10a` label twice for shadow/foreground text drawing, checks byte `+0x108`, and selects the checkbox tile before rendering through `sub_4B9980`.
- `PartySearchEditPane::PartySearchEditPane` inlines equivalent checkbox/text setup at `0x0059e22f-0x0059e265`, writing the same three vtables, storing byte `+0x108`, and copying the label `Put me on the hunters list`.
- `PartySearchEditPane::OnAction` reads the checked flag from `+0x108` when applying hunters-list settings and toggles that byte directly for command `2`.
- 2026-06-21 B009 local PE/source-quality recheck resolves [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) as source-ready `CheckBoxTextControlPane::SetChecked(bool)`: raw bytes at `0x0059e0b0-0x0059e0c0` store `[ebp+8]` into `this+0x108` and `ret 4`, with zero direct caller/pointer-route evidence. The no-route status caps confidence but does not demote it to no-code because constructor, paint, getter, layout, and PartySearch consumer behavior all corroborate the same generic `m_checked` field.
- 2026-06-05 IDA MCP confirmed the vtable block: RTTI at `0x0062e998`, primary destructor slot `0x0062e99c -> sub_59F050`, paint slot `0x0062e9e0 -> sub_59DF50`, control-type slot `0x0062e9fc -> sub_4214C0`, secondary adjustor `0x0062ea04 -> sub_59EFEB`, and tertiary adjustor `0x0062ea34 -> sub_59EFF6`.
- Vtable-base xrefs tie the class to the raw constructor, the teardown helper, the PartySearch inline setup in `sub_59E0D0`, the scalar deleting destructor, and two surrounding inlined setup sites in `sub_59BC90`.
- [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md) is now a non-emitting executable map. Exact source-bearing children carry ownership for the constructor [UID:0003FE][0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw](by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md), teardown helper [UID:0003FF][0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper](by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md), paint method [UID:0003FG][0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint](by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md), checked setter [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md), checked getter [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md), and scalar deleting destructor [UID:0003FJ][0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor](by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md).
- 2026-06-12 A002 Batch 251 IDA MCP split pass corrected the raw constructor exclusive end to `0x0059df27`, found the previously missed raw checked-state setter at `0x0059e0b0-0x0059e0c0`, and corrected the broad executable map end to `0x0059f0a5`.
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) owns the complete reusable-control source route. The owner H and all six semantic CPP children are source-ready; only the literal original filename remains uncertain.
- Historical pre-UID0002OX-callback state: the 2026-06-29 pass interpreted `0x004214c0` as `GetControlType()` and deferred the class-level declaration/getter. The accepted 2026-08-17 ABI/vtable audit supersedes that source identity without deleting the older byte/xref evidence.

## B001-006 Parent-Gate Audit

This class now clears the active `85/85` direct-parent gate for [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md). Existing documentation was treated as a hypothesis and rechecked against IDA MCP where relevant:

- IDA MCP `decompile 0x004214c0` returns constant `22`/`0x16` and has no callees, matching a control-type virtual slot rather than a checked-state accessor.
- The 2026-06-10 B001 xref audit reports `0x004214c0` has 12 vtable data refs and no ordinary direct code callers; the refs include the `CheckBoxTextControlPane` primary vtable slot at `0x0062e9fc -> 0x004214c0`.
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) documents the `CheckBoxTextControlPane` primary vtable at `0x0062e99c`, with destructor `0x0059f050`, paint `0x0059df50`, control-type slot `0x004214c0`, and secondary/tertiary adjustor slots.
- The class page already records live IDA evidence for constructor-shaped bytes at `0x0059ded0-0x0059df24`, modeled teardown helper `0x0059df30`, paint `0x0059df50`, adjustor thunks `0x0059efeb`/`0x0059eff6`, and scalar deleting destructor `0x0059f050`.
- Checked-state ownership is separated from the type helper: byte `+0x108` is read/toggled by `PartySearchEditPane` and read by `OnPaint`; `0x004214c0` only returns the static control-type value.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 95 | The complete formal H declaration, six semantic methods, exact child order, `0x30c` layout, inherited facets, vtables, PartySearch consumers, raw/inlined constructor liveness, ordinary/compiler destructor split, dependencies, and non-emitting table cause are documented. |
| Confidence | 96 | Constructor-shaped bytes, three live inline copies, paint/get/set paths, direct PartySearch consumers, RTTI PMDs, vtable slots, and exact allocation independently prove the source shape; original filename and private lexical spelling remain bounded caps. |
| Reconstructable | true | The class and exact children represent source-authored control behavior; compiler adjustor/deleting-destructor mechanics remain excluded. |

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md)
- [UID:0003FE][0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw](by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md) `CheckBoxTextControlPaneConstructorRaw`
- [UID:0003FF][0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper](by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md) `CheckBoxTextControlPaneTeardownHelper`
- [UID:0003FG][0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint](by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md) `CheckBoxTextControlPaneOnPaint`
- [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) `CheckBoxTextControlPaneSetCheckedRaw`
- [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) `CheckBoxTextControlPaneGetChecked`
- [UID:0003FJ][0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor](by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md) `CheckBoxTextControlPaneScalarDeletingDestructor`
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-08-17 B001 UID0002OX accepted implementation callback:
  - Raised `90/92 -> 95/96`, moved the complete declaration from the CPP channel to formal H, retained `[[CHILDREN]]`, added the `0x30c` size assertion, and left formal CPP blank.
  - Corrected the terminal virtual from historical `int GetControlType()` to `unsigned char HitTestPart(int,int)`, while preserving the exact five-byte body and twelve-vtable folded-code evidence on UID0002DZ.
  - Closed the source route at header position 40 with child definitions ordered constructor 10, ordinary destructor 20, paint 30, setter 40, getter 50, and HitTestPart 60. Compiler vtables, COL/RTTI, adjustors, and scalar-delete mechanics remain non-emitting.
  - Exact natural layout is `ControlPane` through `+0x108`, `bool m_checked` at `+0x108`, one byte of natural alignment at `+0x109`, `wchar_t m_label[256]` at `+0x10a`, and total size `0x30c`; no explicit padding field is introduced.

- 2026-07-14 B004 UID000470 support implementation:
  - Raised `86/88 -> 90/92`, preserved owner/emitter UID0000NY, position, child bodies, vtable/layout evidence, and source-family caveat.
  - Inserted the accepted complete class declaration with constructor, virtual destructor, paint/control-type methods, checked setter/getter, `bool m_checked`, and `wchar_t m_label[256]`, closed before `[[CHILDREN]]`.
  - Preserved the exact no-invalidation setter behavior, raw-constructor evidence, PartySearch direct-field consumers, and compiler-only adjustor/deleting-destructor disposition without changing any exact child body.

- 2026-06-07 A005 resolved-name cleanup:
  - Before: the paint-resource evidence used only the historical `dword_67A744` label.
  - After: the page records resolved name `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing page evidence already ties the reference to EPF checkbox resource lookup.
- 2026-05-30: Existing class doc mentioned `0x004214c0` as an address-only helper. Changed it to the exact by-memory UID page and clarified that the helper is reusable checkbox-control code, not fitting-room or SimpleUString ownership. Evidence: IDA MCP decompilation/data refs for `0x004214c0` and the split of the historical `0x00421310-0x004216cb` aggregate.
- 2026-06-02 reconstructable evidence update:
  - What existed before: the class page was scored `60/78`, reconstructable metadata was blank, and newer memory/type evidence was only partially reflected.
  - Changed to: scored `72/82`, marked reconstructable, added layout/vtable and score-rationale sections, and linked the exact vtable-data child.
  - Summary/evidence: [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md), [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md), and [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) now provide stronger documented evidence while preserving the unresolved raw-constructor and final source-split caveats.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `30`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed checkbox/text vtable/function evidence while preserving the raw constructor caveat.
- 2026-06-05 live IDA refinement:
  - What existed before: the class page had `72/82` scores and documented the broad behavior, but still carried stale evidence wording and did not spell out the live constructor rows, vtable slots, paint behavior, destructor flags, or inline setup proof.
  - Changed to: scores `82/86`, updated method extents, removed stale source-quality caveats, and added direct live IDA evidence for the raw constructor body, modeled functions, vtable slots, PartySearch inline setup, and destructor/adjustor behavior.
  - Summary/evidence: completion increased because the documented surface now covers the constructor-shaped body, paint, teardown helper, scalar deleting destructor, adjustors, control-type slot, field offsets, and vtable store sites. Confidence increased because live IDA MCP disassembly/xrefs confirm the class identity while still preserving the raw-constructor and final source-split caps. C++ remains blank because the constructor is not an IDA function and the class declaration is not yet 95/95 quality.
- 2026-06-10 B001-006 split-gate repair: Raised scores from `82/86` to `85/87` so [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) has a direct parent that clears the active `85/85` gate. Evidence: IDA MCP rechecked `0x004214c0` as a no-callee `return 22` helper, vtable xrefs include `0x0062e9fc -> 0x004214c0`, and existing class evidence covers the constructor-shaped body, paint, teardown, destructor, adjustor slots, checked-byte field, and label buffer while retaining final-source caveats.
- 2026-06-12 A002 Batch 251 split repair: Added exact method child links [UID:0003FE][0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw](by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md)-[UID:0003FJ][0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor](by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md), documented the corrected constructor/map boundaries and the newly recognized checked setter, and kept the class score at `85/87` because the parent already clears the strict gate while final source split/raw constructor caveats remain.
- 2026-06-21 Rule 26 B009 incorporation: Kept score at `85/87` but refined the class model to name `+0x108` as `bool m_checked` and `+0x10a` as `wchar_t m_label[0x100]`, marked [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) source-ready with no invalidation side effect, and preserved the no-direct-route caveat as a confidence cap rather than a no-code reason.
- 2026-06-29 B002 implementation callback: raised to `86/88`, recorded current live-session proof for [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md), and clarified the C++ disposition: UID0002DZ now emits the formal `int CheckBoxTextControlPane::GetControlType()` body, UID0003FH already emits `SetChecked(bool)`, the class-level C++ block stays blank for target-specific declaration/raw-constructor/source-split reasons, and UID0003FI `GetChecked` remains a future out-of-scope exact method candidate.
