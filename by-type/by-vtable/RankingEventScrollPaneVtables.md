*** UID:0001YK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Confidence: strong for vtable bases, installed slots, constructor/destructor stores, and table-end boundaries.

## Vtable Bases

| Class view | Base | Raw constructor store | Inline child setup store | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00610a4c` | `0x004598c3` | `0x0045aeb2` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00610a98` | `0x004598e2` | `0x0045aeb8` | Input/control view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00610ac8` | `0x004598ec` | `0x0045aec2` | Event/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00610a4c` | `+0x1c` | `0x005447a0` | Inherited pane owner/parent lookup used by [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) before factorized `RankingEventListPane::SetScrollPosition(0, oldPosition, newPosition)`. |
| primary `0x00610a4c` | `+0x44` | `0x00459ce0` | `OnPaint`, drawing the ranking-event scrollbar track/thumb. |
| secondary `0x00610a98` | `+0x04` | `0x00459a60` | `OnMouseEvent`; receives the `+0xa0` subobject pointer and normalizes to the full object with `ecx - 0xa0`. |
| secondary `0x00610a98` | `+0x08` | `0x00459cd0` | False-return active/effect virtual. |
| tertiary `0x00610ac8` | `+0x04` | `0x00544e90` | Base/default event-update slot reused by this scrollbar. RankingEventScrollPane has no class-specific timer/auto-repeat body here. |

Do not read past primary `+0x44` as primary slots: primary `+0x48` is RTTI metadata for the secondary table. Do not read secondary `+0x2c` or tertiary `+0x08` as scrollbar slots: they are RTTI metadata for the next table. The absolute address at secondary base `+0x34` is the same dword as tertiary `+0x04` because the tertiary table follows the secondary RTTI record.

## IDA MCP Evidence

- `xrefs_to` each vtable base reports raw constructor stores at `0x004598c3`, `0x004598e2`, and `0x004598ec`, and inline `RankingEventListPane` child-construction stores at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`.
- Inline setup evidence also writes the three table bases from modeled `sub_45AE30` at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`; `xrefs_to 0x00610ad4` shows the next `RankingEventListPane` table boundary is separate at `0x0045ae72`, `0x0045af39`, and `0x0045be0c`.
- `lookup_funcs` confirms the vtable-installed virtual targets at `0x00459a60`, `0x00459cd0`, and `0x00459ce0`; it also confirms `0x004598b0`, `0x004598c3`, `0x004598e2`, and `0x004598ec` remain raw non-IDA function addresses.
- `get_bytes` on 2026-06-13 confirms the primary table contains slot `+0x44 -> 0x00459ce0`, the secondary table starts after RTTI at `0x00610a98` and contains `+0x04 -> 0x00459a60` and `+0x08 -> 0x00459cd0`, and the tertiary table at `0x00610ac8` contains `+0x04 -> 0x00544e90`.
- `analyze_function 0x0045ae30` confirms the inline list-pane child setup allocates `0x110` bytes, calls pane setup, installs the three `RankingEventScrollPane` vtables, initializes the scroll fields, and stores the child pointer in the owning `RankingEventListPane` at `+0x108`.
- B003 UID0000Y6 evidence-time MCP database `bf5519ae` read primary slot cell `0x00610a68` as `0x005447a0`; analysis of that shared inherited target confirms the pane association/owner lookup route used at `0x0045ad74`.
- UID0000Y6 itself is nonvirtual and has no vtable/data-cell route. Exactly six direct class-local calls reach it at `0x00459c1c`, `0x00459c38`, `0x0045aad8`, `0x0045aaf4`, `0x0045abab`, and `0x0045abd4`. Do not invent a Y6 vtable slot or treat inherited `+0x1c` as a Y6 virtual entry.

## Reconstruction Notes

Model `RankingEventScrollPane` as a `Pane`-derived private scrollbar with primary, secondary, and tertiary views at `+0x00`, `+0xa0`, and `+0xa4`. Keep it with [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) unless later xrefs prove reuse outside the ranking UI.

The inline child setup inside `RankingEventListPane` is reconstruction-relevant: it duplicates the raw constructor setup rather than directly calling `0x004598b0`. Source reconstruction should preserve the object layout and initial state even if the final idiomatic C++ expresses this as a normal member allocation/constructor call.

## Nonvirtual Interaction And Raw-Liveness Evidence

- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md), [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md), and [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md) are private nonvirtual retained source methods. No primary/secondary/tertiary slot points to their raw starts.
- Exhaustive evidence-time searches found no raw-start code/data xref, immediate, callback table, vtable entry, absolute VA, RVA, file-offset pointer encoding, or relative branch target. Their source liveness is instead proved by modeled OnMouseEvent equivalents and Child 2's exact inlined Child 3 body.
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) is also nonvirtual and has six direct class-local callers. It uses inherited primary slot `+0x1c` only to obtain `GetOwnerPane()` before source-level `SetScrollPosition(0, oldPosition, newPosition)`.
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md) is a private nonvirtual retained reset method. Its call to inherited timer removal through the `+0xa4` subobject does not create a class-specific tertiary vtable method.
- Secondary slots remain exactly `OnMouseEvent` at `+0x04` and always-false `HasActiveEffect` at `+0x08`; tertiary `+0x04 -> 0x00544e90` remains inherited/default. Do not add Y5/Y6/Y7 methods to any vtable or reinterpret adjacent RTTI/resource data as slots.

## Cross-References

- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md)
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md)
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)

## Changes

- 2026-07-12 B005 UID0000Y5 vtable support callback:
  - Before: executed B003 narrow state `86/90`, with inherited `+0x1c` Y6 owner lookup documented but Y5/Y7 private-method liveness and negative slot evidence incomplete.
  - After: `88/92`, formal block still blank/non-emitting, with exhaustive nonvirtual/raw-route exclusions for UID0004J0/UID0004J1/UID0004J2/UID0000Y7 and preserved exact primary/secondary/tertiary boundaries.
  - Preserved: all vtable bases/stores/slot values, RTTI/table-end exclusions, owner/emitter UID0000BO, Y6 `GetOwnerPane` factorization, and rejection of class-specific timer/update slots.

- 2026-07-12 B003 UID0000Y6 narrow vtable support callback:
  - Changed to: prose only; score remains `86/90`, owner/emitter UID0000BO, reconstructable state, and blank formal block remain unchanged.
  - Summary/evidence: added inherited primary slot `+0x1c -> 0x005447a0` owner lookup used by Y6 and explicit negative evidence that Y6 is a nonvirtual, direct-call-only helper with six local callers.
  - Preservation: no raw UID0000Y5/UID0000Y7 slot, split, class declaration, table boundary, or broader B005-owned work was changed.

- 2026-06-13: Raised `COMPLETION` from `78` to `86` and `CONFIDENCE` from `88` to `90`.
  - Before: the page had the right table bases and notable slots, but the evidence did not explicitly record the current byte-level table layout or the next-table boundary.
  - After: the page records live xrefs, raw-address/function lookup status, byte-backed slot layout, inline child setup behavior, and the boundary separating the tertiary view from the next RankingEventListPane table.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `get_bytes`, and `analyze_function 0x0045ae30` on 2026-06-13 confirmed the three bases, slot targets, constructor/setup stores, raw non-function constructor addresses, and handoff boundary.
- 2026-05-31: Grading changed from `0/0` to `78/88`, marked reconstructable, and attached to [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
  - Before: the vtable page had IDA evidence but remained unevaluated and unattached in validator metadata.
  - After: the score reflects verified vtable bases, installed slots, inline child setup stores, and the documented boundary where RTTI data begins.
  - Evidence: IDA MCP dword inspection and `lookup_funcs` confirm the slot targets, raw constructor stores, `RankingEventListPane` inline child stores, and that the tertiary table stops before adjacent `RankingEventListPane` RTTI.
