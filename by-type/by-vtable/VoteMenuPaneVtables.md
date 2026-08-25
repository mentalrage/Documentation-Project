*** UID:0001Z1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VoteMenuPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md).
- Likely source file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md).
- Confidence: very strong for all three vtable bases, exact table boundaries,
  constructor/destructor stores, class-specific virtual slots, adjustor
  thunks, RTTI/string boundaries, and declaration-level source causation.
- Semantic owner: [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), which
  emits its declaration through [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md).
  This page is `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps exact blank
  Destination 3 because vtable arrays, RTTI records, adjustors, and scalar
  wrappers are compiler output rather than standalone handwritten source.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00622ff8` | `0x00555913` | `+0x00` | Primary `Pane` view. |
| secondary | `0x0062304c` | `0x00555919` | `+0xa0` | Inherited EventHandler facet: pointer/mouse then key/text event slots. |
| tertiary | `0x0062307c` | `0x00555923` | `+0xa4` | Inherited TimerHandler/event-update facet. |

The same vtables are reinstalled by the non-deleting destructor at `0x00555950-0x005559bc` and the scalar deleting destructor at `0x00556320-0x005563cd`. B014's direct PE/Capstone recheck reconfirmed these as constructor/destructor lifecycle stores, not independent caller evidence for the raw constructor.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00622ff8` | `+0x00` | `0x00556320` | `VoteMenuPane::ScalarDeletingDestructor`. |
| primary `0x00622ff8` | `+0x44` | `0x00555af0` | `OnPaint`, draws Promote/Demote labels and highlight state. |
| primary `0x00622ff8` | `+0x48` | `0x00555c70` | Exact `VoteMenuPane::DrawBackground` virtual: 113 bytes, 39 instructions, one block, full-byte SHA256 `04DF87088E9AEBFF0C23EA55C65C93EDEFEF470865D40A5BA719A9B208183E40`, and no direct code caller. |
| primary `0x00622ff8` | `+0x4c` | `0x00555cf0` | SUBWIN border drawing helper. |
| secondary `0x0062304c` | `+0x00` | `0x00556228` | Adjustor thunk into `0x00556320` with `this - 0xa0`. |
| secondary `0x0062304c` | `+0x04` | `0x005559c0` | `HandlePointerOrMouseEvent(Event *)`, canonical Event type/y/x state machine, row hit testing, and vote submission. |
| secondary `0x0062304c` | `+0x08` | `0x00555ae0` | `HandleKeyOrTextEvent(Event *)`, one unused Event pointer, one `Pane::MarkForDeletion` call, and false return. |
| tertiary `0x0062307c` | `+0x00` | `0x00556233` | Adjustor thunk into `0x00556320` with `this - 0xa4`. |
| tertiary `0x0062307c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x50` as a `VoteMenuPane` virtual: it is RTTI metadata for the secondary table. Secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` falls into adjacent wide string menu text such as `Look`, `Trade`, `Info`, `Promote`, and `Demote`.

Secondary slots `+0x0c` through `+0x28` are inherited/default EventHandler entries, not additional VoteMenuPane source methods. EventHandler's accepted declaration order fixes `+0x04` before `+0x08`; this interface/table contract outranks the historical `OnMouseEvent` and dismiss labels. The target at `0x00555ae0` adjusts by `-0xa0`, while TimerHandler begins at `+0xa4`, so TimerHandler ownership is excluded.

## IDA MCP Evidence

- `list_globals *VoteMenuPane*` reports vtables at `0x00622ff8`, `0x0062304c`, and `0x0062307c`, plus RTTI records at `0x0064ece0`, `0x0064ed90`, and `0x0064eda4`.
- Raw constructor disassembly at `0x005558d0-0x00555945` stores the three bases at `0x00555913`, `0x00555919`, and `0x00555923`.
- IDA xrefs to the vtable bases also report non-deleting destructor stores at `0x00555975`, `0x0055597b`, and `0x00555985`, and scalar deleting destructor stores at `0x0055634c`, `0x00556352`, and `0x0055635c`.
- `lookup_funcs` confirms modeled functions at `0x00555950`, `0x005559c0`, `0x00555ae0`, `0x00555af0`, `0x00555c70`, `0x00555cf0`, `0x00556020`, `0x00556070`, `0x00556100`, `0x00556228`, `0x00556233`, and `0x00556320`; it still reports constructor start `0x005558d0` as `Not a function`.
- `xrefs_to`/IDA `py_eval` show `0x00556070` and `0x00556100` are direct callees from the `HandlePointerOrMouseEvent` implementation, not vtable slots.
- Current `class_VoteMenuPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete despite active source placeholders for `VoteMenuPane_vtable`, `VoteMenuPane_vtable2`, and `VoteMenuPane_vtable3`.
- 2026-06-14 live IDA MCP `lookup_funcs` reconfirmed every modeled slot/helper in this cluster: non-deleting destructor `0x00555950` size `0x6c`, the method now reconstructed as `HandlePointerOrMouseEvent` at `0x005559c0` size `0x115`, target `HandleKeyOrTextEvent` at `0x00555ae0` size `0x10`, `OnPaint` `0x00555af0` size `0x178`, background draw `0x00555c70` size `0x71`, border draw `0x00555cf0` size `0x322`, item-rect helper `0x00556020` size `0x4d`, hit-test helper `0x00556070` size `0x8b`, submit helper `0x00556100` size `0x111`, adjustor thunks `0x00556228`/`0x00556233` size `0x0b` each, and scalar deleting destructor `0x00556320` size `0xad`; raw constructor start `0x005558d0` still reports `Not a function`.
- 2026-06-14 `xrefs_to` reconfirmed all three vtable bases are written by the raw constructor (`0x00555913`, `0x00555919`, `0x00555923`) and restored by both destructor forms (`0x00555975/0x0055597b/0x00555985` and `0x0055634c/0x00556352/0x0055635c`). The hit-test helper has only `OnMouseEvent` code xrefs at `0x00555a0d` and `0x00555aa8`; submit has only the `OnMouseEvent` call at `0x00555a32`; the scalar deleting destructor is referenced by both adjustor thunks and the primary vtable.
- 2026-07-16 B002 UID0002LV recheck proves primary cell `0x00623040`
  (`0x00622ff8 + 0x48`) is the sole target xref for
  `VoteMenuPane::DrawBackground`. The raw constructor, ordinary destructor,
  and scalar deleting wrapper install/restore the primary base at
  `0x00555913`, `0x00555975`, and `0x0055634c`. This is exact virtual
  liveness, not a direct-call or separate source-owner route.
- The target body initializes `EPFTileContext`, loads `SUBWIN.EPF` entry 8,
  copies inherited `m_visibleBounds`, stores inherited `m_drawMode = 1`,
  directly insets the local bounds, and calls inherited
  `DrawTiledBackground` with `SUBWIN.PAL`. Those source declarations cause the
  primary slot; no handwritten table or wrapper source is needed here.

## Score Rationale

Raised from `85/90` to `90/93`. The page now closes the exact class/file route,
three table bases, every known lifecycle store, slot inventory, target virtual
liveness, direct-helper exclusions, adjustor/scalar distinctions, RTTI/string
boundaries, and source-declaration causation. The historical
reconstructable/emitting blank-marker state is superseded: compiler-emitted
vtable support is semantic class-owned but non-reconstructable/non-emitting.
The score remains below 95 because raw-constructor symbol recovery and complete
original inherited-table declarations are not final-symbol proven.

## Reconstruction Notes

Model `VoteMenuPane` as a `Pane`-derived menu popup with three vtable views at
`+0x00`, `+0xa0`, and `+0xa4`. The class declaration and exact virtual child
bodies regenerate these tables. The hit-test and packet-submit helpers remain
ordinary private helpers in the same source module, not virtual functions and
not `BulletinSession` behavior.

UID0003CY owns the exact physical COL/three-view data range only as compiler-generated support. This page and UID0003CY remain false/non-emitting with blank CPP/H: the VoteMenuPane declaration, virtual definitions, destructor, and inheritance cause the compiler to regenerate all cells, RTTI, deleting wrappers, and adjustor thunks without handwritten arrays or ABI source.

2026-06-17 B003 source-quality pass recommends first-draft C++ for the source-authored virtuals and private helpers on their exact by-memory pages. The scalar deleting destructor and adjustor thunks remain compiler-generated ABI artifacts and should stay blank for formal C++ while still documenting vtable/source-layout evidence.

2026-06-19 B014 class source-quality implementation keeps this page as generated-binary support. [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) now emits the class declaration and destructor prototype that cause these tables/thunks to be regenerated by the compiler; this page should not emit vtable arrays, adjustor thunk bodies, or scalar deleting destructor C++.

## Parent And Slot Rationale

Retain [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) as semantic owner.
The class is `90/92` and emits through the `91/92` file
[UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md). Those pages document the
same three-view popup layout, singleton lifecycle, constructor/destructor
stores, source virtuals, and helper ownership correction away from
`BulletinSession`. This vtable page is attached for semantic organization and
binary evidence only; blank emitter/position/formal metadata prevents an Empty
Emitter Marker or handwritten ABI source.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md)
- [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md)
- [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md)
- [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md)
- [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md)
- [UID:0001G1][0x00556228-0x0055623e.VoteMenuPaneDestructorThunks](by-memory/0x00556228-0x0055623e.VoteMenuPaneDestructorThunks.md)
- [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)

## Changes

- 2026-08-15 B008 UID0002LT accepted implementation callback:
  - Retained `90/93`, semantic owner UID0000FX, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal channels, and all three exact table bases and lifecycle stores.
  - Labeled secondary `+0x04`/`+0x08` as `HandlePointerOrMouseEvent(Event *)`/`HandleKeyOrTextEvent(Event *)`, identified `+0x0c..+0x28` as inherited/default EventHandler slots, and preserved the `+0xa0` versus TimerHandler `+0xa4` distinction.
  - Historical event/dismiss labels are superseded. No vtable array, RTTI record, deleting wrapper, adjustor thunk, raw table cell, or Empty Emitter Marker was added to source.

- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/88`, with correct vtable evidence but completion still capped at the old attachment threshold.
  - Changed to: `85/90`.
  - Summary/evidence: live IDA MCP reconfirmed raw constructor non-function status, all modeled slot/helper sizes, vtable-base writes/restores from constructor/destructors, adjustor-thunk references, and direct `OnMouseEvent` ownership of hit-test/submit helpers. C++ remains blank because the vtables are compiler-emitted and final class declaration/helper names remain below source-quality.
- 2026-06-17 B003 support refresh:
  - Summary/evidence: recorded the accepted source-quality distinction between source-authored virtual/helper pages that now carry draft C++ and compiler-generated scalar deleting destructor/adjustor glue that remains blank for formal C++. Score is unchanged because this vtable cluster itself is a compiler-emitted metadata/support page.
- 2026-06-19 B014 class source-quality sync:
  - Summary/evidence: recorded that the class declaration/prototype layer is now emitted by [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), while this vtable page remains no-code generated-binary support. The three vtable base immediates are lifecycle stores in the raw constructor, ordinary destructor, and scalar deleting destructor, not a raw-constructor caller route.
- 2026-05-31 scoring and reconstructable flag:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP xrefs confirm the vtable bases are installed by the raw constructor and restored by both destructor forms; lookup/decompile evidence ties the slots to the exact VoteMenuPane methods and compiler-generated adjustor thunks.
- 2026-06-07 parent attachment update:
  - Before: the vtable cluster was reconstructable and cross-linked to `VoteMenuPane`, but it remained unassigned in autogen type coverage.
  - Changed to: `COMPLETION:80` and `AUTOGEN_PARENT_UID:0000FX`; reconstruction C++ remains blank and confidence stays `88`.
  - Summary/evidence: [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) and [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) now provide the 80/80+ parent chain and document the same vtable stores, slots, singleton lifecycle, and helper ownership correction.
- 2026-07-16 B002 UID0002LV implementation callback:
  - Changed `85/90`, reconstructable true, emitter UID0000FX to `90/93`,
    semantic owner UID0000FX, `RECONSTRUCTABLE:FALSE`, blank emitter and
    position, and exact blank Destination 3.
  - Preserved all table/slot/store/thunk/RTTI/boundary evidence, added the exact
    UID0002LV primary-slot liveness and body-source causation, and
    historicalized the former compiler-support Empty Emitter Marker.
