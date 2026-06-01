*** UID:0000UO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FolderTreePaneOwnerPollution_47f280_58a8e0

## Status

- Confidence: strong that the binary ranges are separate ownership clusters; medium for final source-file owners of every helper.
- Generated-output caveat: existing generated source may group these ranges under `class_FolderTreePane.cpp`, but that is not evidence for original ownership. Use the IDA function clusters and cross-referenced by-memory pages below as the controlling evidence.
- Related file/class docs: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Evidence basis: existing memory docs and IDA MCP function-cluster/xref checks on 2026-05-30.

## Finding

The ranges historically associated with FolderTreePane are not one clean original-source container. IDA separates them into several distinct clusters:

| Address group | Better documentation owner | Notes |
| --- | --- | --- |
| `0x004b1b90-0x004b32c9` and `0x004b3350-0x004b5c3f` | [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | Real filesystem tree control and local tree/sort helpers. IDA lists 20 functions in the first cluster and 29 in the second. |
| `0x0047f280-0x004805d6` | [UID:0000I5][Chatting](by-file/Chatting.md) / [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) | Chat-message add, incoming-message collection, visible-row count, and chat packet subtype `10` decode. IDA lists 15 functions from `sub_47F280` through `sub_47FF80`. |
| `0x004b9820-0x004ba24a`, `0x00557140-0x00559a0f` | [UID:0000OC][Surface](by-file/Surface.md) / [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) / [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) | Generic DirectDraw/surface/presentation helpers, not folder-tree-specific code. IDA xrefs to `0x004b9820` and `0x00557140` come from broad UI/rendering callers rather than FolderTreePane-only methods. |
| `0x00585360-0x0058a6f7` plus neighboring `0x0058a8e0` | [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) / [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) | Help/system-message pane loading, formatted text, packet handling, and message refresh helpers. IDA lists 67 functions in `0x00585360-0x0058a8e0`, with `0x0058a8e0` as a separate following function reached from `0x005896c0`. |

## IDA MCP Evidence

Checked on 2026-05-30:

- `0x004b1b90-0x004b32c9` contains 20 IDA functions ending at `sub_4B3210`; `0x004b3350-0x004b5c3f` contains 29 IDA functions ending at `sub_4B5C20`. These clusters are contiguous around documented FolderTreePane tree-control work.
- `0x0047f280-0x004805d6` contains 15 IDA functions. `sub_47F280` has callers inside the chat cluster and also from screenshot/status paths, which matches a reusable chat-message append path rather than a folder-tree method.
- `0x004b9820-0x004ba24a` contains 7 IDA functions and `0x00557140-0x00559a0f` contains 27 IDA functions. Their xrefs come from rendering, capture, and presentation paths across the UI, not from a FolderTreePane-local call tree.
- `0x00585360-0x0058a8e0` contains 67 IDA functions and is cross-referenced by system/help/message callers. The following `sub_58A8E0` begins at `0x0058a8e0` and is called from `0x005898be` inside `sub_5896C0`, so the exact upper edge should stay tied to the SystemMessagePanes memory page rather than this item.

## Follow-Up

- Do not migrate every historically grouped range to `ui/controls/FolderTreePane.cpp`.
- Split by the verified memory ranges above before any `attach class` or source-file migration.
- Recheck `0x004b5650`, `0x004b1a00`, `0x004b2680`, `0x004b3090`, and [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) when refining FolderTreePane method names and source ownership.
- Keep [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) out of source migration; they are compiler glue and now belong in the ignored ledger.
- Use [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) as the vtable/layout anchor. Treat string-adjacent false virtual rows after the tertiary vtable as data pollution until IDA proves otherwise.

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0` and framed the finding mostly around generated source ownership.
- Changed to: `COMPLETION:60` and `CONFIDENCE:78`, with generated output downgraded to a caveat and IDA function-cluster/xref evidence added as the basis for the split.
- Summary/evidence: IDA MCP on 2026-05-30 confirms separate chat, FolderTreePane, surface/presentation, and system-message clusters by function counts, boundaries, and xrefs; final per-helper source ownership remains medium confidence because this page is a split index rather than detailed documentation for every method.
