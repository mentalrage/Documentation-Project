*** UID:0001YK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Confidence: strong for vtable bases and installed slots.

## Vtable Bases

| Class view | Base | Raw constructor store | Inline child setup store | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00610a4c` | `0x004598c3` | `0x0045aeb2` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00610a98` | `0x004598e2` | `0x0045aeb8` | Input/control view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00610ac8` | `0x004598ec` | `0x0045aec2` | Event/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00610a4c` | `+0x44` | `0x00459ce0` | `OnPaint`, drawing the ranking-event scrollbar track/thumb. |
| secondary `0x00610a98` | `+0x04` | `0x00459a60` | `OnMouseEvent`; receives the `+0xa0` subobject pointer and normalizes to the full object with `ecx - 0xa0`. |
| secondary `0x00610a98` | `+0x08` | `0x00459cd0` | False-return active/effect virtual. |
| tertiary `0x00610ac8` | `+0x04` | `0x00544e90` | Base/default event-update slot reused by this scrollbar. RankingEventScrollPane has no class-specific timer/auto-repeat body here. |

Do not read past primary `+0x44` as primary slots: primary `+0x48` is RTTI metadata for the secondary table. Do not read secondary `+0x2c` or tertiary `+0x08` as scrollbar slots: they are RTTI metadata for the next table. The absolute address at secondary base `+0x34` is the same dword as tertiary `+0x04` because the tertiary table follows the secondary RTTI record.

## IDA MCP Evidence

- `list_globals *RankingEventScrollPane*` reports the three vtables at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`, plus matching RTTI records.
- `xrefs_to` each vtable base reports raw constructor stores at `0x004598c3`, `0x004598e2`, and `0x004598ec`, and inline `RankingEventListPane` child-construction stores at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`.
- `lookup_funcs` confirms the vtable-installed virtual targets at `0x00459a60`, `0x00459cd0`, and `0x00459ce0`; it also confirms `0x004598b0` remains a raw non-IDA function start.
- Disassembly of `0x0045ae30` allocates `0x110` bytes, calls `Pane::Pane(1)`, installs the three `RankingEventScrollPane` vtables, initializes the scroll fields, and stores the child pointer in the owning `RankingEventListPane` at `+0x108`.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete despite the confirmed IDA symbols.

## Reconstruction Notes

Model `RankingEventScrollPane` as a `Pane`-derived private scrollbar with primary, secondary, and tertiary views at `+0x00`, `+0xa0`, and `+0xa4`. Keep it with [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) unless later xrefs prove reuse outside the ranking UI.

The inline child setup inside `RankingEventListPane` is reconstruction-relevant: it duplicates the raw constructor setup rather than directly calling `0x004598b0`. Source reconstruction should preserve the object layout and initial state even if the final idiomatic C++ expresses this as a normal member allocation/constructor call.

## Cross-References

- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `78/88`, marked reconstructable, and attached to [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
  - Before: the vtable page had IDA evidence but remained unevaluated and unattached in validator metadata.
  - After: the score reflects verified vtable bases, installed slots, inline child setup stores, and the documented boundary where RTTI data begins.
  - Evidence: IDA MCP dword inspection and `lookup_funcs` confirm the slot targets, raw constructor stores, `RankingEventListPane` inline child stores, and that the tertiary table stops before adjacent `RankingEventListPane` RTTI.
