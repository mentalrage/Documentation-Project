*** UID:0001XC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DescPane virtual-table emission is covered by [UID:00003Q][DescPane](by-class/DescPane.md); do not hand-author table data.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DescPane Vtables

## Status

- Disposition: reconstructable project vtable data
- Owner class: [UID:00003Q][DescPane](by-class/DescPane.md)
- Likely source module: [UID:0000IS][DescPane](by-file/DescPane.md)
- Exact vtable-data page: [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- Confidence: strong for table bases/boundaries, constructor/destructor stores, primary `+0x44` OnPaint identity, inherited primary `+0x24` GetDescription identity/signature, and compiler-generated slot exclusions.
- Autogen status: attached to UID00003Q at position 70. The managed marker
  routes exact child evidence while stating that the compiler emits the table
  dwords from the complete class declaration.

## Vtable Inventory

| View | RTTI / pre-vtable word | Vtable base | Slot range | Notes |
| --- | --- | --- | --- | --- |
| primary `DescPane` view | `0x006189d8` -> `??_R4DescPane@@6B@` | `0x006189dc` | `0x006189dc-0x00618a24` | 18 slots. Slot 0 is non-emitting scalar deleting destructor wrapper `0x0049d840`; inherited `+0x24` is [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md); class-specific `+0x44` / cell `0x00618a20` is `DescPane::OnPaint` at `0x0049d7c0`. |
| secondary view at object `+0xa0` | `0x00618a24` -> `??_R4DescPane@@6B@_0` | `0x00618a28` | `0x00618a28-0x00618a54` | 11 slots. Slot 0 is destructor adjustor thunk `0x0049d81e`. |
| tertiary view at object `+0xa4` | `0x00618a54` -> `??_R4DescPane@@6B@_1` | `0x00618a58` | `0x00618a58-0x00618a60` | 2 slots. Slot 0 is destructor adjustor thunk `0x0049d829`; slot 1 is inherited helper `0x00544e90`. |

The next dword after the tertiary table is `0x006465cc`, `DialogPane` RTTI. Do not read past `0x00618a60` as `DescPane` slots.

## IDA Evidence

- `xrefs_to 0x006189dc` reports vtable stores at raw constructor offset `0x0049d701`, non-deleting destructor offset `0x0049d740`, and scalar deleting destructor offset `0x0049d846`.
- `xrefs_to 0x00618a28` reports stores at raw constructor offset `0x0049d709`, non-deleting destructor offset `0x0049d746`, and scalar deleting destructor offset `0x0049d84c`.
- `xrefs_to 0x00618a58` reports stores at raw constructor offset `0x0049d713`, non-deleting destructor offset `0x0049d750`, and scalar deleting destructor offset `0x0049d856`.
- `xrefs_to 0x0049d7c0` reports the primary-vtable slot at `0x00618a20`.
- `xrefs_to 0x0049d81e` and `xrefs_to 0x0049d829` report secondary and tertiary vtable refs at `0x00618a28` and `0x00618a58`.
- Current `source-3/simroot_v2/class_DescPane.meta_wave3` reports `vtable_count: 0` despite these IDA-confirmed vtables.

## Slot Notes

Primary slots between `0x006189e0` and `0x00618a1c` are inherited Pane/UI-control behavior. UID00012N uses inherited `+0x20` / `Pane::InvalidateRect` with bounds `this+0x44`; it does not dispatch the class-specific paint slot. Inherited primary `+0x24` resolves to fresh [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md), the exact slot called by UID00012O on its borrowed Pane source. DescPane's class-specific override is primary `+0x44` / cell `0x00618a20`, exact `DescPane::OnPaint` at `0x0049d7c0`.

The secondary and tertiary tables are inherited-base views used for destructor dispatch. Their first slots are compiler-generated adjustor thunks; those code ranges are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) because they are not handwritten description-pane behavior.

B005's 2026-06-18 vtable inventory preserves the current best slot roles:

| View | Slot / target | Best identity |
| --- | --- | --- |
| primary `+0x00` / `0x0049d840` | Non-emitting MSVC scalar deleting destructor wrapper generated from source `DescPane::~DescPane()`; do not hand-author as C++. |
| primary `+0x04` / `0x004f4b10` | Inherited `LObject::GetRuntimeClass`-style accessor. |
| primary `+0x08` / `0x0041b6c0` | Inherited/default no-op virtual. |
| primary `+0x0c` / `0x004b8e20` | Inherited `GrafPort::UpdateRenderRegion` / render-region support. |
| primary `+0x10` / `0x0041d680` | Inherited no-op `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` direction. |
| primary `+0x14` through `+0x20` | Inherited `Show`, `Hide`, `GetParentPane`, and `InvalidateRect`; historical `Repaint` for `+0x1c` is superseded. |
| primary `+0x24` / `0x00544a20` | Inherited [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md); shared base default writes wide NUL only for index `-1`. |
| primary `+0x28` through `+0x40` | Inherited Pane bounds/layer/order/event-handler defaults. |
| primary `+0x44` / `0x0049d7c0` | [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md), the class-specific primary override; exact clear/fill and guarded description dispatch body is child-owned. |
| secondary `+0x00` / `0x0049d81e` | Compiler-generated destructor adjustor, subtracts `0xa0` then jumps to scalar deleting destructor. |
| secondary `+0x04` through `+0x28` | Inherited EventHandler pointer/mouse, key/text, IME, packet, system/control, type-19, handler-order, local-pair, screen-pair, and acceptance slots. |
| tertiary `+0x00` / `0x0049d829` | Compiler-generated destructor adjustor, subtracts `0xa4` then jumps to scalar deleting destructor. |
| tertiary `+0x04` / `0x00544e90` | Inherited tertiary event/update default. |

## Source Reconstruction Notes

Use these vtable bases when auditing constructor/destructor compiler output. The raw constructor at `0x0049d6f0` installs all three tables, the source destructor body is at [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md), and the scalar deleting destructor at [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) is compiler glue rather than handwritten source.

Do not hand-emit vtable stores or vtable literal arrays in [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md)'s constructor C++. The correct source-side reconstruction is a polymorphic `DescPane` declaration plus virtual methods; the observed stores at `0x0049d701`, `0x0049d709`, and `0x0049d713` are compiler output. [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) owns the source destructor body. [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) adjustor thunks and [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) scalar deleting destructor remain non-emitting compiler glue and should not become source functions.

## Complete Source Contract

The primary 18-slot order is: scalar deleting destructor,
`LObject::GetRuntimeClass`, change-message default, `UpdateRenderRegion`,
`DrawOnTarget`, `Show`, `Hide`, `GetParentPane`, `InvalidateRect`,
`GetDescription`, `GetScreenBounds`, `SetBounds`, `AddToLayer`,
`InsertInLayer`, `RemoveFromLayer`, `SetPaneOrder`,
`UnregisterEventHandler`, and `DescPane::OnPaint`.

The secondary 11-slot order is: `this-0xa0` deleting-destructor adjustor,
pointer/mouse bridge, key/text bridge, IME bridge, packet bridge,
system/control bridge, type-19 bridge, `ForwardHandlerOrder`,
`GetLocalEventPair`, `GetScreenEventPair`, and `ShouldAcceptEvent`.

The tertiary two-slot order is: `this-0xa4` deleting-destructor adjustor and
inherited `bool OnTimer(int,int,int)` default.

Both internal COL cells are part of UID0002NA. RTTI proves direct Pane
inheritance; EventHandler and TimerHandler are inherited Pane facets at
`+0xa0/+0xa4`. No source declaration may add them as extra direct bases,
explicit vptr members, table arrays, or adjustor functions.

## Score Rationale

Completion/confidence are `92/94` because all three table extents, 31 callable
slots, two internal COL cells, direct inheritance, lifecycle stores, source
override, inherited contracts, adjusted destructor routes, target child,
source position, and no-handwritten-table policy are complete. The remaining
cap is inferred spelling for a small number of inherited source contracts.

## Parent Rationale

Attach this vtable cluster to [UID:00003Q][DescPane](by-class/DescPane.md)
because the three tables are the concrete DescPane virtual views
installed/restored by constructor/destructor paths. The class/file pages record
the same singleton ownership, `OnPaint` override, inherited `GetDescription`
dependency, adjustor thunks, exact vtable-data child, and raw-helper caveats.
This page remains the narrow evidence home for slot order and `.rdata`
boundaries. Its managed marker documents class coverage and preserves
`[[CHILDREN]]`; the compiler, not handwritten C++, emits table data.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md)
- [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md)
- [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md)
- [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md)
- [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md)
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)

## 2026-07-16 B001 UID0002NA Accepted Callback

- Applied `92/94`, position 70, and the exact class-coverage marker plus
  `[[CHILDREN]]`.
- Added the complete 18/11/2 slot contract, both in-range COL cells, direct
  Pane inheritance, EventHandler/TimerHandler facet relationship, exact
  lifecycle stores, and DialogPane boundary.
- Corrected inherited primary `+0x10` to the `DrawOnTarget` direction and
  `+0x1c` to `GetParentPane`; historical draw-style-no-op, Repaint,
  RefreshDescription, and generic handler wording is superseded.
- No literal vtable array, RTTI object, vptr assignment, adjustor body, or
  deleting-wrapper source is emitted.

## Changes

- 2026-07-16 B001 UID0002NA accepted callback:
  - Raised `88/93 -> 92/94`, set position 70, installed the exact managed
    marker/child route, and completed all slot/RTTI/compiler evidence.
- 2026-07-12 B003 UID00012O accepted callback: raised `86/90 -> 88/93`; resolved inherited primary `+0x24` to exact UID0004IX `Pane::GetDescription(int,wchar_t *)` and class-specific primary `+0x44` to UID00012O `DescPane::OnPaint`; preserved all three table ranges, RTTI boundary, constructor/destructor stores, inherited unrelated slots, adjustor/scalar-destructor compiler exclusions, and blank formal vtable block. Historical `RefreshDescription` labels below are prior states superseded by this slot resolution.
- 2026-06-29 B006 setter implementation callback:
  - Before: the slot notes could be read as though the source/index setter reached the `RefreshDescription` slot indirectly.
  - Changed to: explicitly distinguishes UID00012N's inherited primary slot `+0x20` / `Pane::InvalidateRect` dispatch from the `DescPane::RefreshDescription` override at primary `+0x44` / `0x00618a20`.
  - Summary/evidence: B006 current MCP session `46666bf7` confirms the setter calls `call dword ptr [edx+20h]` with `this+0x44`, while `xrefs_to 0x0049d7c0` still shows only the vtable data cell at `0x00618a20`.
- 2026-06-19 B011 destructor implementation callback:
  - Before: slot notes described the primary `0x0049d840` target as a scalar deleting destructor wrapper but did not explicitly mark it no-code/non-emitting or route source destructor emission to [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md).
  - Changed to: primary slot `+0x00` is documented as a non-emitting MSVC scalar deleting destructor wrapper generated from source `DescPane::~DescPane()`, with [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) owning the source destructor body and [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md)/[UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) staying compiler glue.
  - Summary/evidence: accepted B011 report confirms the primary vtable slot `0x006189dc`, adjusted-this thunk routes, delete-flag wrapper behavior, ordinary destructor source body, and generated-vtable/destructor policy.
- 2026-06-18 B005 constructor/vtable policy incorporation:
  - Before: the page identified the three table bases and key slots but did not carry the latest source-policy decision from the B005 report.
  - Changed to: added slot-role inventory, generated-vtable policy, and explicit non-emission guidance for constructor vtable stores and destructor adjustor thunks.
  - Summary/evidence: B005 confirmed the constructor/destructor/scalar-destructor vtable base immediates, RTTI boundaries, refresh slot, scalar destructor slot, secondary/tertiary adjustor slots, and generated source treatment.
- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite the owning class and source file pages already clearing the attachment gate.
  - What changed: attached the vtable cluster to [UID:00003Q][DescPane](by-class/DescPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor/destructor stores to `0x006189dc`, `0x00618a28`, and `0x00618a58`, exact [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md), and the class page support the parent assignment; provider-interface naming and raw non-function starts remain below final-audit level for the full class, while [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) now has staged constructor C++.

- 2026-05-31 exact child split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructability metadata, and described the vtable bases without an exact `by-memory` child page.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and the exact [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md) child page.
  - Summary/evidence: 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword reads reconfirm the three vtable bases, constructor/destructor store xrefs, key slot targets, modeled/raw function split, and boundary before `DialogPane` RTTI at `0x00618a60`; score remains below `95+` because provider-interface naming and raw constructor/setter ownership still need broader final-source audit.
