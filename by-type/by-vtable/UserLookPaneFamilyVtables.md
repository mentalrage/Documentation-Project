*** UID:00038Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserLookPane Family Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `UserLookPane`, `MoreInfoPane`, and `ProfilePane` vtable layouts in the user-look/profile source family.
- Disposition: reconstructable type/layout documentation.
- Direct parent: [UID:0000P0][UserLookPane](by-file/UserLookPane.md), which B001-048 confirms clears the strict `85/85` gate.
- Created from B001-048 split research of [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Evidence |
| --- | --- | --- | --- | --- | --- |
| `UserLookPane` | [UID:00038R][0x0062eccc-0x0062ed58.UserLookPaneVtableData](by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md) | `0x0062eccc` | `0x0062ed1c` | `0x0062ed4c` | Constructor stores at `0x0059f297`, `0x0059f29d`, `0x0059f2a9`; cleanup stores at `0x0059f52c`, `0x0059f532`, `0x0059f53c`; scalar destructor stores at `0x005a2423`, `0x005a2429`, `0x005a2433`. |
| `MoreInfoPane` | [UID:00038S][0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData](by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md) | `0x0062ed58` | `0x0062edd0` | `0x0062ee00` | Constructor stores at `0x0059f338`, `0x0059f33e`, `0x0059f348`; destructor-neighborhood refs at `0x005a231c`, `0x005a2324`, `0x005a232e`. |
| `ProfilePane` | [UID:00038T][0x0062ee0c-0x0062eebc.ProfilePaneVtableData](by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md) | `0x0062ee0c` | `0x0062ee84` | `0x0062eeb4` | Constructor stores at `0x0059f3ce`, `0x0059f3d4`, `0x0059f3de`; destructor-neighborhood refs at `0x005a239c`, `0x005a23a4`, `0x005a23ae`. |

## Boundary Evidence

- The exact local vtable span is `0x0062eccc-0x0062eebc`; the following `0x0062eebc-0x0062ef0c` bytes are user-look/profile resource string data, not vtable data.
- All three class families are documented under [UID:0000P0][UserLookPane](by-file/UserLookPane.md); that file page is the direct source owner for this source-local vtable family.
- This page is the assigned type/layout parent for the exact user-look vtable-data children under UID00038Q.

## Exact UserLook Primary View

| Relative slot | Cell | Target | Resolved source role |
| --- | --- | --- | --- |
| `+0x44` | `0x0062ed10` | `0x005a0640` | UID0003RM `virtual void UserLookPane::OnDraw()`, complete four-mode render source. |
| `+0x48` | `0x0062ed14` | `0x0059f610` | UID0003RK `virtual void UserLookPane::OnActivate(const unsigned char *)`, complete packet/layout source. |

- Cell `0x0062ed10` is the sole xref to UID0003RM; no ordinary code caller, second vtable slot, duplicate body, or alternate class owner exists. The primary pane contract and complete UID0000FP declaration resolve source ABI `void OnDraw()`; historical `RenderUserLook` and int-return decompiler residue are superseded.
- The source declaration regenerates this primary slot next to accepted `OnActivate`. UID0003RM owns the method body, while this type page and UID00038R remain blank because raw vtable dwords/RTTI are compiler-generated.

## Exact UserLook Secondary View

| Relative slot | Cell | Target | Resolved source role |
| --- | --- | --- | --- |
| `+0x00` | `0x0062ed1c` | `0x005a23d5` | Destructor adjustor for the EventHandler facet. |
| `+0x04` | `0x0062ed20` | `0x005a1580` | UID0003RN `bool OnMouseEvent(Event *)`, including previous/next view navigation. |
| `+0x08` | `0x0062ed24` | `0x005a19a0` | UID0003RO `bool HandleKeyOrTextEvent(Event *)`, translating and consuming unmodified PageUp/PageDown. |

- The secondary receiver is complete `UserLookPane + 0xa0`. UID0003RO raw `m_viewMode` access at facet `+0xd24` therefore resolves to complete-object `+0xdc4`; calls to view helpers recover the complete object by subtracting `0xa0`.
- Cell `0x0062ed24` is the sole xref to the exact key body; no ordinary caller or duplicate slot/body exists. Mouse cases 2/3 mirror the key handler's previous/next mode graph.
- The vtable dwords remain compiler-generated from the complete UserLookPane declaration, including `virtual void OnDraw();`, `virtual bool OnMouseEvent(Event *event);`, and `virtual bool HandleKeyOrTextEvent(Event *event);`. This page emits no hand-authored vtable C++, no method-body duplicate, and no broad-index ownership transfer.

## Exact Local Child Event Slots

| Class | Primary `+0x60` | Secondary `+0x04` | Secondary `+0x08` | Source disposition |
| --- | --- | --- | --- | --- |
| `MoreInfoPane` | `0x0062edb8 -> 0x005a2350`, exact `bool OnMouseEvent(Event *)` | inherited pointer/mouse dispatcher | `0x0062edd8 -> 0x005a2340`, exact `bool HandleKeyOrTextEvent(Event *)` | Two local false-return source overrides; raw tables remain compiler-generated. |
| `ProfilePane` | `0x0062ee6c -> 0x005a23d0`, exact `bool OnMouseEvent(Event *)` | inherited pointer/mouse dispatcher | `0x0062ee8c -> 0x005a23c0`, exact `bool HandleKeyOrTextEvent(Event *)` | Two local false-return source overrides; raw tables remain compiler-generated. |

The primary `+0x64` TextEditPane key route remains inherited and distinct for both local classes. Historical `OnKeyEvent` spellings for the secondary `+0x08` bodies are superseded by the exact EventHandler-facet contract.

## Assignment Gate

Owner/emitter [UID:0000P0][UserLookPane](by-file/UserLookPane.md), reconstructable true, blank optional position/formal, and source-local ownership remain correct. At `89/93` with current direct file parent `92/93`, both pages clear the strict parent gate.

## Score Rationale

Completion `89` and confidence `93` are supported by exact vtable boundaries, complete primary OnDraw/OnActivate and secondary/local event slot maps, constructor/cleanup/destructor store refs, complete-object adjustment, sole xrefs, and agreement between the executable island, class/file pages, exact data children, and live IDA evidence.

## Cross-References

- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md)
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)

## Changes

- 2026-07-20 B002 UID0003RM accepted callback: raised `87/91 -> 89/93`; retained owner/emitter UID0000P0, reconstructable true, blank position/formal; added exact primary `+0x44 void OnDraw` and adjacent `+0x48 OnActivate`, sole-xref/ABI/declaration-cause evidence, and preserved the complete secondary/local-pane union with no handwritten vtable data.

- 2026-07-16 B001 UID00023W accepted callback: synchronized UserLook, MoreInfo, and Profile primary/secondary event names and bool returns, added the complete local-child slot map and neighboring inherited routes, and preserved blank compiler-data C++.
- 2026-07-13 B005 UID0003RO accepted callback support sync: preserved `87/91`, UID0000P0 ownership/emission, and blank formal block; added the exact secondary destructor-adjustor/mouse/key slot map, complete-object `+0xa0` adjustment, sole key xref, declaration-generated disposition, and current UID0000P0 `90/90` gate truth, superseding stale `88/85` wording.
- 2026-06-11 supervisor implementation of B001-048: created source-local UserLookPane vtable page and prepared exact memory children for direct layout parenting.
