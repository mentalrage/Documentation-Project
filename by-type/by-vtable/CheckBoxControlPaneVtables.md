*** UID:0001X8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000021 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane Vtables

## Status

- Entity kind: non-emitting vtable/RTTI layout evidence
- Addresses: `0x006184d8`, `0x00618540`, `0x00618570`
- Exact vtable-data range: [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- Covered class: [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- Related layout owner: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- Confidence: very strong for all 25/11/2 slots, three COLs, seven-base RTTI hierarchy, receiver offsets, stores/restores, source method identities, and compiler-only destructor forms.
- Source disposition: semantic owner remains UID000021, but this page is false/non-emitting with blank position and CPP/H. UID000021 H declares the virtual surface; UID00011S and UID0004Y2 emit authored definitions. The compiler regenerates vtables, RTTI, adjustors, and scalar wrapper.
- Evidence basis: repeated IDA MCP dword/xref/decompile checks plus exact UID0002M9 bytes and accepted ControlPane/CheckBox layout documentation. Stale Wave metadata is not used as evidence.

## Constructor Writes

[UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) writes three vtable pointers:

| Object offset | Vtable | Notes |
| --- | --- | --- |
| `+0x00` | `0x006184d8` | Primary `ControlPane`/paint/visual-state/HitTestPart surface. |
| `+0x0a0` | `0x00618540` | Secondary event/handler surface; deleting destructor adjustor subtracts `0xa0`. |
| `+0x0a4` | `0x00618570` | Tertiary inherited/helper surface; deleting destructor adjustor subtracts `0xa4`. |

Exact compiler child [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md) restores the same three vtable pointers before inherited Pane teardown and hidden deleting-flag dispatch. [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) normalize the two secondary receivers before tail-jumping to it.

## Complete Primary Vtable

The primary callable table is exactly `[0x006184d8,0x0061853c)` with 25 entries. Its ordered source roles are:

| Indices | Targets | Roles |
| --- | --- | --- |
| `0-4` | `0x0049b110`, `0x004f4b10`, `0x0041b6c0`, `0x004b8e20`, `0x0041d680` | compiler deleting entry; inherited GetRuntimeClass, OnChangeMessage, UpdateRenderRegion, DrawOnTarget |
| `5-10` | `0x00544730`, `0x00544750`, `0x005447a0`, `0x00544800`, `0x00544a20`, `0x00544b80` | inherited Show, Hide, GetParentPane, InvalidateRect, GetDescription, GetScreenBounds |
| `11-16` | `0x00544bd0`, `0x00544c70`, `0x00544cb0`, `0x00544ce0`, `0x00544d30`, `0x00544d70` | inherited SetBounds, AddToLayer, InsertInLayer, RemoveFromLayer, SetPaneOrder, UnregisterEventHandler |
| `17-24` | `0x00499e30`, `0x00499ec0`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, `0x0049b8d0` | OnPaint, SetVisualState, inherited Enable/Disable/SetIgnoreHitTesting/Deactivate/Activate, HitTestPart |

The class-specific cells are:

| Slot address | Target | Meaning |
| --- | --- | --- |
| `0x006184d8` | `0x0049b110` | Scalar deleting destructor. |
| `0x0061851c` | `0x00499e30` | `OnPaint`, draws checked/unchecked tile frame. |
| `0x00618520` | [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) / `0x00499ec0` | `SetVisualState(unsigned char)`; UID0000U7 preserves item evidence without duplicate code. |
| `0x00618538` | [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md) | `HitTestPart(int,int)`, unsigned-byte constant result `20`. |

IDA decompiles `0x00499ec0` as the accepted same-slot `SetVisualState` override: it compares inherited `m_visualState` at `+0x103`, handles value `20`, stores changes, and invalidates through inherited slot `+0x20`. It has only the expected primary-table xref.

## Secondary And Tertiary Vtables

| Vtable | Extent | Checkbox-specific slots |
| --- | --- | --- |
| `0x00618540` | `[0x00618540,0x0061856c)`, 11 slots | `0x0049af27`, `0x00499de0`, `0x0041d6b0`, `0x0041d6b0`, `0x00544de0`, `0x00544df0`, `0x00544e00`, `0x004a89f0`, `0x00544e10`, `0x00544e30`, `0x00544e70`: deleting adjustor, CheckBox `HandlePointerOrMouseEvent`, then inherited/default EventHandler routes. |
| `0x00618570` | `[0x00618570,0x00618578)`, 2 slots | `0x0049af32`, `0x00544e90`: TimerHandler deleting adjustor and inherited timer default. |

The IDA disassembly continues into adjacent class vtables after these RTTI records. Do not treat the later `SimpleHelpTextPartPane`, `StaticTextControlPane2`, or `FunctionObject` vtable data as part of `CheckBoxControlPane`.

## Exact Boundary Evidence

- IDA MCP `list_globals *CheckBoxControlPane*` on 2026-05-31 reports vtables at `0x006184d8`, `0x00618540`, and `0x00618570`.
- IDA MCP `py_eval` dword scan on 2026-05-31 confirms the exact child range [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md): `0x006184d4` is the primary RTTI pointer, `0x0061853c` and `0x0061856c` are the secondary/tertiary RTTI locator dwords, and `0x00618578` is the next class RTTI pointer for `SimpleHelpTextPartPane@StaticTextControlPane2`.
- IDA MCP `py_eval` xrefs on 2026-05-31 report constructor vptr stores to the three table bases at `0x00499d5d`, `0x00499d66`, and `0x00499d70`, plus scalar deleting destructor restores at `0x0049b116`, `0x0049b11c`, and `0x0049b126`.

## Complete RTTI Hierarchy

- COL cells `0x006184d4`, `0x0061853c`, and `0x0061856c` point to COL records `0x00646078`, `0x006460d8`, and `0x006460ec` with complete-object offsets `0`, `0xA0`, and `0xA4`.
- All three records use type descriptor `0x0067596c` and CHD `0x0064608c`. CHD attributes are `1`; its base array at `0x0064609c` has seven entries.
- Base order is `CheckBoxControlPane`, `ControlPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`.
- The first five PMDs have `mdisp=0`; EventHandler has `mdisp=0xA0`; TimerHandler has `mdisp=0xA4`. All observed PMDs use `pdisp=-1`, `vdisp=0`, and attributes `0x40`.
- These offsets match UID0001TX and explain the exact secondary/tertiary receiver adjustments without introducing raw multiple-inheritance arithmetic into source.

## Historical Generated-Output Caveats

- Older generated metadata reported no vtables even though IDA confirms all three table bases and constructor/wrapper stores. That stale output is not evidence.
- Historical generated output omitted `0x00499ec0`. UID00011S now emits `SetVisualState`; do not use the old omission or StateTypeHelper alias as owner/name evidence.
- Current disabled output omits the `0x0049af27` body and emits only the `0x0049af32` thunk body. Both are exact [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) and should remain ignored compiler glue.
- B009 current MCP session `supervisor_recovery_20260705` reports raw function names for the method targets even though decorated vtable/RTTI names are present. Historical C001 saved-label notes remain naming context only.

## Owner And Emission Rationale

Semantic owner [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md) is retained because the constructor and scalar wrapper install/restore these concrete views. The page is nevertheless false/non-emitting: the class H declaration and authored method children are the source causes, while the compiler produces vtable arrays, COLs, CHD/PMDs, adjusted deleting entries, and decorated identities. UID0001TX remains the layout companion. Standalone UID0000I7 is the source route; the old ButtonControlPane fold remains rejected historical context.

## Score Rationale

- Completion `94`: all 25/11/2 slots, three COLs, seven-base CHD/PMDs, object-view offsets, stores/restores, class-specific methods, compiler causes, boundaries, source route, and historical corrections are complete.
- Confidence `96`: direct table bytes, RTTI, xrefs, constructor/wrapper writes, method bodies, and base declarations agree. Exact stripped spellings do not change this compiler-layout disposition.

## Cross-References

- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md)
- [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-07-26 B002 UID0002M9 source-quality implementation:
  - Changed `86/91 -> 94/96`, retained semantic owner UID000021, and changed this compiler-layout support page to false/non-emitting with blank position/formals.
  - Incorporated exact 25/11/2 slot sequences, all three COL records, seven-base CHD/PMDs, object-view offsets, stores/restores, and the implicit-destructor source cause.
  - Corrected current method identities to `SetVisualState`, `HandlePointerOrMouseEvent`, and exact child UID0004Y2 `HitTestPart(int,int)`; linked compiler child UID0004Y1.
  - Preserved earlier generated omissions and source-fold uncertainty below as historical evidence, not current blockers.

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage, and the status used the layout page as the proposed owner.
  - What changed: attached the vtable cluster to [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md), raised completion to `86`, and clarified that [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md) is the related layout companion rather than the autogen parent.
  - Summary/evidence: constructor stores at `0x00499d5d`, `0x00499d66`, and `0x00499d70`, destructor restores at `0x0049b116`, `0x0049b11c`, and `0x0049b126`, exact [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md), and the class page's `86/91` score support the parent assignment; final source-file grouping remains open between the split candidate and broader button-control family.

- 2026-05-31: Grading changed from `0/0` to `84/91`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the vtable page had useful slot notes but remained unevaluated and did not point to an exact by-memory data slice.
  - After: the page points to [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md) as the exact primary/secondary/tertiary vtable-data child range.
  - Evidence: IDA MCP `list_globals`, `lookup_funcs`, and `py_eval` on 2026-05-31 reconfirmed table bases, key slot targets, constructor/destructor stores, the vtable-only `0x00499ec0` helper slot, and the boundary before `SimpleHelpTextPartPane@StaticTextControlPane2`.
- 2026-07-05 B009 source-quality support update:
  - Scores and metadata unchanged.
  - Updated the state-helper slot to route source output through [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md), with [UID:0000U7][CheckBoxControlPaneSetVisualState_00499EC0](by-item/CheckBoxControlPaneSetVisualState_00499EC0.md) retained as no-duplicate evidence.
  - Added current MCP raw-label caveat and explicit future routing note for the outside `0x0049b8d0` type-id helper.
