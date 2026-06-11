*** UID:0000UO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePaneOwnerPollution_47f280_58a8e0

## Status

- Confidence: strong that the binary ranges are separate ownership clusters; medium for final source-file owners of every helper.
- Owner-label caveat: any stale grouping that treats these ranges as one FolderTreePane source container is not evidence for original ownership. Use the IDA function clusters and cross-referenced by-memory pages below as the controlling evidence.
- Related file/class docs: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Evidence basis: existing memory docs and IDA MCP function-cluster/xref checks on 2026-05-30.
- Reconstruction handling: this item is a routing/owner-pollution ledger, not a source-emitting parent. Keep it non-reconstructable here; the source-authored code remains reconstructable in the linked `by-memory` and `by-file` owners.

## Finding

The ranges historically associated with FolderTreePane are not one clean original-source container. IDA separates them into several distinct clusters:

| Address group | Better documentation owner | Notes |
| --- | --- | --- |
| `0x004b1b90-0x004b32c9` and `0x004b3350-0x004b5c3f` | [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | Real filesystem tree control and local tree/sort helpers. IDA lists 20 functions in the first cluster and 29 in the second. |
| `0x0047f280-0x004805d6` | [UID:0000I5][Chatting](by-file/Chatting.md) / [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) | Chat-message add, incoming-message collection, visible-row count, and chat packet subtype `10` decode. IDA lists 15 functions from `sub_47F280` through `sub_47FF80`. |
| `0x004b9820-0x004ba24a`, `0x00557140-0x00559a0f` | [UID:0000OC][Surface](by-file/Surface.md) / [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) / [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) | Generic DirectDraw/surface/presentation helpers, not folder-tree-specific code. IDA xrefs to `0x004b9820` and `0x00557140` come from broad UI/rendering callers rather than FolderTreePane-only methods. |
| `0x00585360-0x0058a6f7` plus neighboring `0x0058a8e0` | [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) / [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) | Help/system-message pane loading, formatted text, packet handling, and message refresh helpers. IDA lists 67 functions in `0x00585360-0x0058a8e0`, with `0x0058a8e0` as a separate following function reached from `0x005896c0`. |

## Canonical Owner Map

| Polluted range or label | Current durable owner | Evidence strength | Migration rule |
| --- | --- | --- | --- |
| Real folder-tree core `0x004b1b90-0x004b32c9` | [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | Strong: constructor caller, selected-path caller, selection method body, vtable stores, and `TREEICON.EPF` evidence are documented. | Keep in `ui/controls/FolderTreePane.cpp`. |
| Folder tree/sort/template helpers `0x004b3350-0x004b5c3f` | [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) | Strong for folder-tree relationship; completion still limited by broad traversal/sort helper spans. | Keep near FolderTreePane; split remaining broad helper spans before final C++. |
| Chat-message methods labeled `FolderTreePane` at `0x0047f280` and `0x0047f370` | [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) and [UID:0000I5][Chatting](by-file/Chatting.md) | Very strong for chat UI neighborhood; the exact child pages [UID:0002EQ][0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage.md) and [UID:0002ER][0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage.md) remain named with the stale owner for traceability. | Do not migrate into FolderTreePane; resolve final chat class/source owner inside the chat UI pass. |
| Surface paint helpers `0x004b9820-0x004ba24a` | [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) under provisional [UID:0000OC][Surface](by-file/Surface.md) | Strong for shared rendering use; exact `Surface.cpp` versus `GrafPort.cpp` split remains open. | Keep out of FolderTreePane; refine with Surface/GrafPort rather than UI tree-control work. |
| Presentation/screenshot/cursor area `0x00557140-0x00559aef` | [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), plus screenshot children | Medium-high: modeled/raw inventory and alignment are documented; final split spans Surface, ScreenPane/cursor, screenshot, and presentation traversal. | Keep out of FolderTreePane; split children before parent attachment or C++. |
| System/help/message pane range `0x00584ea0-0x0058af3b` | [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) and [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) | Strong for listed function boundaries and interleaved forced-inform exclusions. | Keep out of FolderTreePane; continue system-message child splits separately. |

## IDA MCP Evidence

Checked on 2026-05-30:

- `0x004b1b90-0x004b32c9` contains 20 IDA functions ending at `sub_4B3210`; `0x004b3350-0x004b5c3f` contains 29 IDA functions ending at `sub_4B5C20`. These clusters are contiguous around documented FolderTreePane tree-control work.
- `0x0047f280-0x004805d6` contains 15 IDA functions. `sub_47F280` has callers inside the chat cluster and also from screenshot/status paths, which matches a reusable chat-message append path rather than a folder-tree method.
- `0x004b9820-0x004ba24a` contains 7 IDA functions and `0x00557140-0x00559a0f` contains 27 IDA functions. Their xrefs come from rendering, capture, and presentation paths across the UI, not from a FolderTreePane-local call tree.
- `0x00585360-0x0058a8e0` contains 67 IDA functions and is cross-referenced by system/help/message callers. The following `sub_58A8E0` begins at `0x0058a8e0` and is called from `0x005898be` inside `sub_5896C0`, so the exact upper edge should stay tied to the SystemMessagePanes memory page rather than this item.

## Current Decision

- This item should remain a narrow owner-pollution index until the stale `FolderTreePane` generated labels are either renamed in the canonical pages or fully retired.
- It should not be promoted into a `by-memory` source range because it intentionally spans unrelated address neighborhoods.
- It should not emit reconstructed C++ or act as an autogen parent. The linked canonical pages own the reconstructable code and should receive parent attachments only when their own confidence/source owner thresholds are met.
- The practical migration rule is now clear: use [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) only for filesystem tree-control code and local tree/template support; route chat, surface/presentation, screenshot, and system-message ranges to their own owners.

## Destination Status Snapshot

- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) are now parent-attached around the real filesystem tree control. Their accepted contents are the core range, tree/sort helpers, vector support helpers, [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md), [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), and [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).
- The two exact chat child pages [UID:0002EQ][0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage.md) and [UID:0002ER][0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage.md) deliberately retain the stale `FolderTreePane` label for traceability, but their durable owner context is [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) / [UID:0000I5][Chatting](by-file/Chatting.md).
- The surface/presentation rows are not a single destination module yet: [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) is shared render support, while [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) still spans presentation, cursor/screen traversal, and screenshot-adjacent children.
- The system-message range is owned by [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) / [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md); do not use physical proximity to `0x0058a8e0` as FolderTreePane evidence.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 76 | The page now records the polluted address groups, durable canonical owners, current destination status, migration rules, and linked supporting pages. It remains below high completion because surface/presentation and some chat/system-message destination pages still need final source-owner decisions and generated-label retirement. |
| Confidence | 88 | Confidence is strong that the listed ranges are not one FolderTreePane source container and that the real FolderTreePane owner is now narrowed to the filesystem tree-control family. It is capped below final-audit levels because several destination owners still have unresolved exact source-file splits or broad aggregate spans. |
| Reconstructable | FALSE | This item is documentation routing state. The real source-authored code is marked reconstructable on the linked canonical memory/file pages where appropriate. |

## Follow-Up

- Do not migrate every historically grouped range to `ui/controls/FolderTreePane.cpp`.
- Split by the verified memory ranges above before any `attach class` or source-file migration.
- Recheck `0x004b5650`, `0x004b1a00`, `0x004b2680`, `0x004b3090`, and [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) when refining FolderTreePane method names and source ownership.
- Keep [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) out of source migration; they are compiler glue and now belong in the ignored ledger.
- Use [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) as the vtable/layout anchor. Treat string-adjacent false virtual rows after the tertiary vtable as data pollution until IDA proves otherwise.
- When stale generated `FolderTreePane` labels are finally retired from the chat child pages, revisit this item and either downgrade it to a historical note or move any remaining routing facts into the destination owner pages.

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `FALSE`, and the reconstruction-handling text was updated to match.
  - Before: the page explicitly said it should not emit source but left validator metadata blank, so it remained unclassified.
  - After: it is explicitly non-reconstructable as a standalone item because it is a routing/owner-pollution ledger.
  - Evidence: the page maps the actual source-authored ranges to their canonical FolderTreePane, ChattingUI, Surface, SurfacePresentation, and SystemMessagePanes pages; this item intentionally spans unrelated address neighborhoods and should not generate C++.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0` and framed the finding mostly around stale source ownership labels.
- Changed to: `COMPLETION:60` and `CONFIDENCE:78`, with stale labels downgraded to a caveat and IDA function-cluster/xref evidence added as the basis for the split.
- Summary/evidence: IDA MCP on 2026-05-30 confirms separate chat, FolderTreePane, surface/presentation, and system-message clusters by function counts, boundaries, and xrefs; final per-helper source ownership remains medium confidence because this page is a split index rather than detailed documentation for every method.
- 2026-06-02 canonical owner-map update:
  - What existed before: the page listed the major polluted groups but did not explicitly map each one to its current durable owner or explain why this item should not become an autogen/code parent.
  - Changed to: scored `72/86`, added the canonical owner map, current routing decision, and score rationale, while leaving source emission out of this routing item.
  - Summary/evidence: linked pages [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md), [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md), [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), and [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) now carry the reconstructable evidence for the individual ranges.
- 2026-06-07 A009 destination-status pass:
  - What existed before: the page had a durable owner map but did not record that the real FolderTreePane class/file are now parent-attached or that the chat pollution has exact child pages retaining stale names for traceability.
  - Changed to: scored `76/88`, added the destination status snapshot, and clarified when this routing item can be reduced after generated-label retirement.
  - Summary/evidence: existing by-file/by-class/by-memory/by-type pages now support the real filesystem tree-control owner, chat child-page routing, surface/presentation split caveats, and system-message ownership without making this item a source-emitting parent.
