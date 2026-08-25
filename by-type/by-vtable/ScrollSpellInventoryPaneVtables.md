*** UID:0001YS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane Vtables
## UID0000NJ Non-Emitting Compiler-Product Closure - 2026-08-16

The primary, EventHandler-adjusted, and TimerHandler-adjusted facets at `0x00623e94`, `0x00623ee0`, and `0x00623f10`, their complete slot semantics, seven RTTI/type objects, and the shared scalar-deleting/adjustor wrappers are compiler products of UID0000CN's class declaration. They remain exact ownership and ABI evidence but are not handwritten source arrays or helper bodies. The shared wrappers serve eight scroll-pane families and are specifically excluded from this compilation unit's authored inventory.

This page is therefore `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps both formal channels blank. The complete virtual declaration on UID0000CN regenerates the tables; UID0003CM preserves the exact physical data range. Existing facet, slot, wrapper, RTTI, constructor-store, and source-placement evidence remains intact below.

## UID0000LU Header Route Cross-Link - 2026-08-15

The established ScrollSpellInventoryPane vtable identities continue to be compiler-covered by the complete class now declared in `ScrollSpellInventoryPane.h`. No vtable words, wrappers, or thunks become handwritten source.

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md).
- Exact vtable-data child: [UID:0003CM][0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData](by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md).
- Selected source file: standalone [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md); the prior fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) is a rejected historical alternative.
- Confidence: strong for vtable bases, constructor stores, installed slots, exact `.rdata` child, and the source virtual declarations that regenerate the tables.
- Evidence owner: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md); this page has no emitter position and blank formal channels.
- Rebuild handling: `source-declared/generated-binary`; the accepted class declaration provides `OnPaint`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `OnTimer`. The compiler/linker regenerates these tables; literal arrays are prohibited.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00623e94` | `0x0055f4a1` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00623ee0` | `0x0055f4a7` | Input/event view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00623f10` | `0x0055f4b1` | Timer/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00623e94` | `+0x44` | `0x0055f890` | `OnPaint`, drawing `SLIDEBG`/`SCRBUTT` scrollbar resources. |
| secondary `0x00623ee0` | `+0x04` | `0x0055f650` | `HandlePointerOrMouseEvent`, the accepted mouse input virtual. |
| secondary `0x00623ee0` | `+0x08` | `0x0055f840` | `HandleKeyOrTextEvent`, the source-authored false-return virtual adjacent to input/timer handlers. |
| secondary `0x00623ee0` | `+0x34` | `0x0055f850` | `OnTimer`, exposed here for repeat/timer handling. |
| tertiary `0x00623f10` | `+0x04` | `0x0055f850` | The same `OnTimer` implementation exposed through the inherited tertiary TimerHandler facet. |

Do not read past `tertiary +0x04` as `ScrollSpellInventoryPane` slots. The next dword at `0x00623f18` is RTTI metadata for the neighboring [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md), not another spell-scrollbar virtual.

B002's 2026-06-18 PE scan found no vtable or pointer-table entry for `0x005608a0`. [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) should be modeled as a non-virtual ordinary instance helper; the relevant vtable use inside the body is the inherited Pane invalidation virtual at primary slot `+0x20`, not a route to the reset helper itself.

B002's 2026-06-20 aggregate reanalysis keeps the same vtable route policy for [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md): secondary `+0x08 -> 0x0055f840` is the source-authored false-return input/event virtual, secondary `+0x34` and tertiary `+0x04` share `0x0055f850` for repeat/timer handling, and no vtable route should be invented for raw setter, hover/active, or reset starts.

## Vtable Data Range

[UID:0003CM][0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData](by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md) is the exact `.rdata` child for this type layout. It starts at the RTTI-adjacent locator pointer before the primary `ScrollSpellInventoryPane` table and ends before the `ScrollNewGroupPane` locator/table family:

| Address | Contents | Meaning |
| --- | --- | --- |
| `0x00623e90` | RTTI complete-object-locator pointer | Included as the prefix word for the primary `ScrollSpellInventoryPane` table. |
| `0x00623e94` | `??_7ScrollSpellInventoryPane@@6B@` | Primary `+0x00` object view. |
| `0x00623ee0` | `??_7ScrollSpellInventoryPane@@6B@_0` | Secondary event/input view at object offset `+0xa0`. |
| `0x00623f10` | `??_7ScrollSpellInventoryPane@@6B@_1` | Tertiary timer/update view at object offset `+0xa4`. |
| `0x00623f18` | next family boundary | `ScrollNewGroupPane` locator prefix; excluded from this type page. |

## Parent And Slot Rationale

[UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) is the type/evidence owner at `89/91` and attaches to standalone [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) at `90/92`. The class records the constructor-installed facets, exact `0x110` tail, complete method map, and raw reset evidence.

Current evidence scores are `94/95` for this semantic-vtable page and `94/96` for exact UID0003CM data; the direct class owner is `89/91`. Both compiler pages are nonreconstructable/no-emitter evidence because all three table views derive from the class declaration.

This vtable page must not emit literal arrays, comments, or duplicate virtual bodies. Both formals are blank; UID0000CN's class declaration and virtual ordering are the only source-level representation.

## IDA MCP Evidence

- Constructor disassembly at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1` installs `0x00623e94`, `0x00623ee0`, and `0x00623f10`.
- `xrefs_to` each vtable base reports the matching constructor store as the direct data reference: `0x0055f4a1 -> 0x00623e94`, `0x0055f4a7 -> 0x00623ee0`, and `0x0055f4b1 -> 0x00623f10`.
- IDA vtable/data references map the primary paint slot to `0x0055f890` at `0x00623ed8`, the secondary mouse slot to `0x0055f650` at `0x00623ee4`, the secondary false-return slot to `0x0055f840` at `0x00623ee8`, and the tertiary repeat slot to `0x0055f850` at `0x00623f14`.
- 2026-06-13 C001 live IDA 9.1 MCP confirmed named vtable symbols `??_7ScrollSpellInventoryPane@@6B@`, `??_7ScrollSpellInventoryPane@@6B@_0`, and `??_7ScrollSpellInventoryPane@@6B@_1` at `0x00623e94`, `0x00623ee0`, and `0x00623f10`; the next named vtable in the band is `??_7ScrollNewGroupPane@@6B@` at `0x00623f1c`.
- The same pass reconfirmed function bounds for constructor `0x0055f450-0x0055f4f1`, mouse handler `0x0055f650-0x0055f831`, false-return virtual `0x0055f840-0x0055f845`, repeat handler `0x0055f850-0x0055f883`, paint handler `0x0055f890-0x0055ff70`, owner constructor `0x0057cf70-0x0057d03f`, and successor `ScrollNewGroupPane` constructor `0x00560900-0x005609a1`.
- The same `xrefs_to` refresh reported the sole direct constructor caller `0x0057d013` inside `sub_57CF70`, matching the class/file ownership evidence that this is a private new-spell-inventory scrollbar.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete despite the confirmed IDA symbols.
- B002 2026-06-18 source-quality recheck specifically searched for a vtable/pointer-table route to raw reset start `0x005608a0` and found none; this closes that route as a current owner/reachability hypothesis for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) without changing the vtable-page score.

## Reconstruction Notes

Model this as the spell-inventory sibling of [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). The layout is nearly identical, but the source is a private feature-specific class routed through standalone [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), not owned by NewSpell and not generic ScrollBar infrastructure.

The source declaration now resolves the inherited-pane facets, standalone route, and four class-specific virtual names. Remaining completion uncertainty is limited to unrecovered original spellings and exact historical source formatting; neither requires raw labels or literal vtable arrays.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page contained useful slot notes but was still scored unevaluated.
  - Changed to: Scored as strong-confidence vtable evidence while keeping completion below final audit because inherited pane-interface slot names and final source placement still need broader review.
  - Evidence: IDA MCP `xrefs_to` confirms direct constructor stores to `0x00623e94`, `0x00623ee0`, and `0x00623f10`; IDA slot mapping ties the class-specific paint, mouse, and timer callbacks to the listed function addresses.
- 2026-06-07: Raised completion from `70` to `74` and attached autogen parent [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md); confidence remains `86`.
  - Before: The page documented the vtable bases and slots but left `AUTOGEN_PARENT_UID` blank.
  - After: The page records the class parent, parent/slot rationale, and no-code policy for this compiler-emitted layout evidence.
  - Evidence: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) is reconstructable at `80/80`, attached to [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), and records the same vtable bases, spell-scrollbar method map, raw reset-helper caveat, and possible fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
- 2026-06-13 C001 type-quality/IDA refresh:
  - Before: the page remained `74/86` even though exact memory child [UID:0003CM][0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData](by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md), direct class parent [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), and source-file parent [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) had since been raised above the strict gate.
  - Changed to: completion `85`, confidence `90`; added the exact `.rdata` child, source-declared/generated-binary rebuild handling, assignment-gate rationale, named vtable/data range, and refreshed live IDA evidence.
  - Evidence: live IDA 9.1 MCP reconfirmed named vtables at `0x00623e94`, `0x00623ee0`, and `0x00623f10`, constructor stores at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1`, slot-function refs for paint/mouse/false-return/repeat handlers, sole constructor caller `0x0057d013` from `NewSpellInventoryPane`, and the next `ScrollNewGroupPane` vtable boundary at `0x00623f18/0x00623f1c`. C++ remains blank because the page documents generated vtable data and inherited virtual declaration shape is not final-audit complete.
- 2026-06-18 B002 support incorporation:
  - Added explicit no-vtable-route note for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md).
  - Evidence: B002's source-quality pass found no vtable or pointer-table entry to `0x005608a0`; `ResetScrollState` is a non-virtual ordinary instance helper whose body calls the inherited Pane invalidation virtual.
- 2026-06-20 B002 aggregate support incorporation:
  - Added aggregate-level confirmation that the source-authored false-return virtual remains at secondary slot `+0x08 -> 0x0055f840`, the repeat/timer handler remains shared by secondary `+0x34` and tertiary `+0x04`, and raw setter/hover/active/reset starts have no vtable route.
  - Evidence: B002 local PE/listing reanalysis of [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) retained the exact slot map and rejected invented routes to raw starts.
- 2026-07-22 B001 UID0001GN implementation callback:
  - Retained `85/90` and owner/emitter [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), set position `30`, and inserted the exact compiler-regenerated-vtable comment.
  - Bound primary `OnPaint`, secondary `HandlePointerOrMouseEvent`/`HandleKeyOrTextEvent`, and tertiary/shared `OnTimer` to the UID0000CN formal while preserving exact bases, stores, slot references, `.rdata` boundary, neighboring ScrollNewGroupPane boundary, and no-reset-helper-vtable-route evidence.
  - Selected standalone UID0000NJ placement and rejected literal table output or duplicate virtual bodies.

## Cross-References

- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md)
