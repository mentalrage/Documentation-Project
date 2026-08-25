*** UID:00038M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated SelfLookPane and SelfLookPane2 RTTI and vtable data; no manual source arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Source-local SelfLookPane/SelfLookPane2 vtable family with exact table ranges/stores, SelfLookPane2 primary +0x44 UID0003RB void OnPaint, primary +0x48 UID0003QZ OnActivate, secondary +0x04 UID0003RD HandlePointerOrMouseEvent, +0x08 UID0003RC HandleKeyOrTextEvent, +0x10 UID0003RE HandlePacketEvent, sibling contracts, compiler-generated no-manual-array formal disposition, and UID0000NL route. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SelfLookPane Family Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `SelfLookPane` and `SelfLookPane2` vtable layouts only.
- Disposition: reconstructable type/layout documentation parented to the shared SelfLookPane source module. The comment-only formal block is the exact compiler no-code proof: MSVC emits vtable/RTTI storage from class virtual declarations, and this page must not emit manual arrays.
- Source candidate: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md).
- Created from B001-048 split research of [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Evidence |
| --- | --- | --- | --- | --- | --- |
| `SelfLookPane` | [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) | `0x00624188` | `0x006241d8` | `0x00624208` | Constructor stores at `0x00565640`, `0x0056564c`, `0x00565658`; cleanup stores at `0x0056580b`, `0x00565811`, `0x0056581b`; scalar destructor stores at `0x00573762`, `0x00573768`, `0x00573772`. |
| `SelfLookPane2` | [UID:00038N][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) | `0x006246f8` | `0x00624748` | `0x00624778` | Constructor stores at `0x0056feb3`, `0x0056febc`, `0x0056fec8`; cleanup stores at `0x0057005b`, `0x00570061`, `0x0057006b`; scalar destructor stores at `0x00573672`, `0x00573678`, `0x00573682`. |

## Exact Primary Paint Slot

| Class | Primary cell | Offset | Exact target | Source contract |
| --- | --- | ---: | --- | --- |
| `SelfLookPane2` | `0x0062473c` | `+0x44` from `0x006246f8` | [UID:0003RB][0x00570fc0-0x00571c05.SelfLookPane2OnPaint](by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md) | exact `virtual void SelfLookPane2::OnPaint()` |

- UID0003RB has zero direct code callers and one exact data pointer at the primary `+0x44` cell. Virtual dispatch is its complete liveness route.
- The no-argument `this` receiver, plain `ret`, ignored branch-dependent EAX values, rendering body, and sibling paint-slot contracts establish `void`, not `bool` or `int`.
- The source-visible cause is UID0000CV's corrected virtual declaration plus UID0003RB's exact out-of-class body. The cell remains compiler-generated; no manual array or raw function pointer belongs in source.

## Corrected Primary Activation Slot

| Class | Primary cell | Offset | Exact target | Source contract |
| --- | --- | ---: | --- | --- |
| `SelfLookPane` | primary base `0x00624188` plus `0x48` | `+0x48` | `0x00565890` | sibling `OnActivate(const unsigned char *)` |
| `SelfLookPane2` | `0x00624740` | `+0x48` from `0x006246f8` | [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) | exact `void SelfLookPane2::OnActivate(const unsigned char *)` |
| `UserLookPane` | sibling family primary `+0x48` | `+0x48` | `0x0059f610` | independently accepted OnActivate body |

The target has zero direct code callers and one data xref, the `0x00624740` cell. The GeneralPurposePanel2/Pane activation dispatcher supplies the indirect packet-pointer call contract. The former generic key-action/OnDraw characterization is historical and rejected: UID0003QZ contains packet decoding and pane state updates but no draw primitive.

## Exact Secondary EventHandler Slots

| Class | Secondary cell | Offset | Exact target | Source contract |
| --- | --- | ---: | --- | --- |
| `SelfLookPane2` | `0x0062474c` | `+0x04` from `0x00624748` | [UID:0003RD][0x00571cc0-0x005720ff.SelfLookPane2HandlePointerOrMouseEvent](by-memory/0x00571cc0-0x005720ff.SelfLookPane2HandlePointerOrMouseEvent.md) | exact `bool SelfLookPane2::HandlePointerOrMouseEvent(Event *)` |
| `SelfLookPane2` | `0x00624750` | `+0x08` from `0x00624748` | [UID:0003RC][0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent](by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md) | exact `bool SelfLookPane2::HandleKeyOrTextEvent(Event *)` |
| `SelfLookPane2` | `0x00624758` | `+0x10` from `0x00624748` | [UID:0003RE][0x00572120-0x005725ed.SelfLookPane2HandlePacketEvent](by-memory/0x00572120-0x005725ed.SelfLookPane2HandlePacketEvent.md) | exact `bool SelfLookPane2::HandlePacketEvent(Event *)` |

- Secondary locator `0x00624744` precedes base `0x00624748`. The relevant cells are `0x0062474c -> 0x00571cc0`, `0x00624750 -> 0x00571c10`, and `0x00624758 -> 0x00572120`; each is the corresponding method's sole data xref, with zero ordinary code callers or duplicate pointer routes.
- Dispatch uses the EventHandler facet at complete-object `+0xa0`. Each method recovers the complete `SelfLookPane2` object as needed, returns bool in `AL`, and uses `retn 4`; receiver adjustment is compiler lowering rather than an explicit source field or manual thunk.
- UID0003RD reads Event pointer coordinates and implements the complete cursor/left-button state machine. UID0003RC reads the Event key union and implements translated Page Up/Page Down navigation. UID0003RE reads `event->m_payload.m_packet.m_data` at Event `+0x0c` and dispatches seven packet opcodes.
- The exact source cause is the three corrected virtual declarations in UID0000CV plus the three child definitions. Historical `HandleEvent(const PanelMouseEvent *)`, `HandleKeyEvent(const PanelKeyEvent *)`, `OnPacketEvent(const PanelPacketEvent *)`, generic helper names, and manual table representations are rejected.

## Boundary Evidence

- The `SelfLookPane` table group is exact at `0x00624188-0x00624210`; the next owner is `GroupListPane`.
- The `SelfLookPane2` table group is exact at `0x006246f4-0x00624780`; it sits inside the broader mixed [UID:0002V1][0x006245dc-0x00624788.CollectionLookLineVtableData](by-memory/0x006245dc-0x00624788.CollectionLookLineVtableData.md) island.
- Both groups are part of the broad [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) inventory, but that broad page is cross-source and must not be used as a direct autogen parent.
- UID0003QZ ends before four `cc` bytes and UID00038N is bounded by neighboring CollectionPane2/LineIterator data. No target body, padding, RTTI/COL cell, secondary/tertiary table, thunk, or neighboring table is reclassified into this type page.

## Compiler And Source Disposition

- Primary/secondary/tertiary bases and exact constructor/cleanup/scalar-destructor stores are evidence for inheritance and virtual declarations.
- RTTI/COL headers, raw vtable cells, adjustor entries, and linker table placement are compiler-generated. Source reconstruction is the virtual declarations in UID0000CV and exact child method definitions, not hand-authored pointer arrays. R3 records that compiler source cause without emitting storage.
- UID0003RB, UID0003QZ, UID0003RD, UID0003RC, and UID0003RE remain emitted by UID0000CV through UID0000NL. UID00038N remains an exact memory child routed through this source-local vtable family; the broad UID0001Y0 cross-source inventory is evidence only.
- No ownership transfer to GeneralPurposePanel2, Pane, SpelledPane, LegendPane, ProfilePane, or UserLookPane follows from the shared activation slot shape.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). This source-local vtable family spans both `SelfLookPane` and `SelfLookPane2`, so the shared file/module page is the narrowest single direct source parent rather than either one class page. The parent file is `92/94`, and this page is `91/95`; exact memory children [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) and [UID:00038N][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) route here without using the broad cross-source [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Score Rationale

Completion `91` and confidence `95` are justified by live IDA store refs, exact table boundaries, the exact `0x0062473c -> UID0003RB void OnPaint`, `0x00624740 -> UID0003QZ OnActivate`, `0x0062474c -> UID0003RD HandlePointerOrMouseEvent`, `0x00624750 -> UID0003RC HandleKeyOrTextEvent`, and `0x00624758 -> UID0003RE HandlePacketEvent` contracts, matching memory-child/class evidence, explicit R3 compiler no-code disposition, and the repaired source-module parent. Confidence remains below perfect because the original physical source split and some inherited/common pane slot names lack symbols.

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)

## Changes

- 2026-07-16 Agent-B004 UID0003RD callback: retained `91/95`, owner/emitter UID0000NL, reconstructable state, blank position, and the exact compiler-generated no-manual-array formal comment; added the secondary `+0x04` UID0003RD `HandlePointerOrMouseEvent(Event *)` and `+0x10` UID0003RE `HandlePacketEvent(Event *)` identities around the preserved `+0x08` UID0003RC key/text slot, with exact EventHandler receiver/return/source-cause and rejected legacy-name evidence.

- 2026-07-14 B002 UID0003RB callback: raised `90/94` to `91/95`; added the exact SelfLookPane2 primary `+0x44` UID0003RB cell, void paint ABI, virtual-only liveness, class/body source cause, and compiler no-manual-array disposition while preserving all accepted B004/B003 family data and the comment-only formal block.
- 2026-07-14 Agent-B003 UID0003RC callback: raised `89/93` to `90/94`; inserted exact R3 comment-only no-code formal, added the secondary locator/base/`+0x08` UID0003RC cell, exact EventHandler signature/receiver ABI, sole-route and source-declaration cause, and rejected historical/manual-table alternatives. Preserved owner/emitter UID0000NL, reconstructable state, blank position, every SelfLookPane/SelfLookPane2 range/store, primary UID0003QZ evidence, broad UID0001Y0 relationship, source route, and compiler exclusions. No RTTI or vtable array is emitted.

- 2026-07-14 Agent-B003 UID0003QZ callback: raised `87/91` to `89/93`; resolved SelfLookPane2 primary `+0x48` cell `0x00624740` as UID0003QZ `OnActivate(const unsigned char *)`, linked sibling slot contracts, recorded zero direct callers/indirect dispatcher semantics, and made the compiler-generated no-manual-array disposition explicit. Preserved owner/emitter UID0000NL, reconstructable state, blank position/formal, exact table ranges/stores, broad UID0001Y0 evidence route, and all neighboring boundaries.

- 2026-06-11 Agent-A001 Batch 232:
  - Before: `86/91`, parent blank pending source-chain repair.
  - Changed to: `87/91`, `AUTOGEN_PARENT_UID:0000NL`.
  - Evidence: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) now clears the strict parent gate at `85/89`; live IDA rechecked the `SelfLookPane`/`SelfLookPane2` table bases and store refs while Batch 232 routed exact memory children through this source-local vtable family.
- 2026-06-11 supervisor implementation of B001-048: created source-local vtable family page so the broad LookPane vtable inventory no longer has to pretend one page owns self-look, spelled, legend, and user-look vtables.
