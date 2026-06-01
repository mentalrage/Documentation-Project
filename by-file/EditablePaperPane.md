*** UID:0000IX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EditablePaperPane

## Status

- Confidence: strong for the class/module boundary, medium for the final placement of the tiny uncalled paper-open wrappers near `0x005128a0`.
- Proposed module: `ui/dialogs/EditablePaperPane.cpp`
- Proposed header: `ui/dialogs/EditablePaperPane.h`
- Current recovered source: `source-3/simroot_v2/class_EditablePaperPane.cpp`
- Main memory range: [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- Type docs: [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- Exact vtable data: [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)
- Related support docs: [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md), [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)

## File Role

`EditablePaperPane` is the packet-opened in-game paper document pane. It parses editable and read-only paper packets, builds a tiled `LINE001.EPD` paper frame, embeds a [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md), and serializes edited text back to the server with opcode `0x23`.

Keep this separate from [UID:0000OL][TextDialog](by-file/TextDialog.md). `TextDialog` is the NPC/message free-text dialog family, while `EditablePaperPane` owns item/paper document presentation, paper dimensions, line-break normalization, and the paper save packet.

Keep this separate from [UID:0000OQ][TextPad](by-file/TextPad.md). `TextPad` is a full-screen local text pad/editor with file command prefixes; `EditablePaperPane` is a server-packet paper UI.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `EditablePaperPane` | `0x00545170-0x00545e3b` | Main paper pane class, packet parsing, control setup, save serialization, draw hooks, and destructor thunks. |
| vtable family | [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md) | Primary dialog view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| paper-open wrapper candidates | `0x005128a0`, `0x00512900` | Small uncalled wrappers that allocate 640 bytes and construct mode `0` or mode `1` `EditablePaperPane`; source owner remains open. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00545170-0x00545217` | `EditablePaperPane::EditablePaperPane` | Constructs a modal `DialogPane`, installs three vtables, and dispatches mode `0` to editable parsing or mode `1` to read-only parsing. |
| `0x00545220-0x0054524b` | `OnDialogAction` | Action `0` saves editable paper content, then dismisses the pane through `PaneManager`. |
| `0x00545250-0x0054565b` | `InitializePaperContent` | Normalizes tabs to carriage returns, creates the close/action button and text edit control, sets limits, layout, parent, focus, and slide-open state. |
| `0x00545660-0x00545767` | `ParseEditablePacket` | Reads paper id, flags, width, height, text length, and multibyte text; converts to wide text. |
| `0x00545770-0x00545877` | `ParseReadOnlyPacket` | Reads read-only dimensions, centered flag, and text payload; converts to wide text. |
| `0x00545880-0x005459a7` | `SavePaperContent` | Reads text control content, converts carriage returns back to tabs, writes opcode `0x23`, paper id, length, and multibyte text. |
| `0x005459b0-0x00545d46` | `DrawBorder` | Loads `LINE001.EPD` frames `0..7` and tiles the border/corners. |
| `0x00545d50-0x00545dc1` | `DrawBackground` | Loads `LINE001.EPD` frame `8`, deflates the fill rect by the 16-pixel border, clears the overlay flag, and fills the interior. |
| [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) | adjustor thunks | Two real 0xb destructor adjustor thunks forwarding to `0x00545e00` with `this - 160` and `this - 164`. |
| `0x00545e00-0x00545e3b` | scalar deleting destructor | Calls `DialogPane` cleanup and conditionally deletes `this`. |

## Ownership Notes

- `MapPane::HandlePacket` constructs the pane for opcode `0x1b` in editable mode and opcode `0x35` in read-only mode.
- IDA also confirms small wrappers at `0x005128a0` and `0x00512900` that allocate and construct the same class, but both currently have no direct callers. Keep them as review targets near [UID:0000L3][MapPane](by-file/MapPane.md) packet handling or this file; do not use them alone to infer a separate source file.
- Disabled generated `0x0045004e` is not an `EditablePaperPane` method. IDA places it inside [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md), a binary-search/lower-bound helper with callers in the LodePNG helper island.
- The generated disabled rows `0x00545ddd` and `0x00545de8` are real compiler adjustor thunks, not missing code; see [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md). These adjustor wrappers are excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), while the scalar deleting destructor remains reconstructable.
- 2026-05-26 IDA MCP recheck confirms `0x0045004e` is still an interior instruction of the LodePNG lower-bound helper, confirms the `EditablePaperPane` adjustor pair as `this - 0xa0` / `this - 0xa4` wrappers into `0x00545e00`, and confirms `TextPad` owns the only direct caller to `0x00595be0`.
- 2026-05-26 IDA MCP vtable recheck confirms the tertiary table at `0x00621b90` owns only `0x00545de8` and inherited `0x00544e90`; the following dword at `0x00621b98` begins adjacent `LINE001.EPD` string/data, not another paper-pane virtual.

## Cross-References

- [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: packet-opened paper pane role, function map, vtable/adjustor evidence, false LodePNG ownership exclusion, text-edit/resource dependencies, wrapper caveats, and cross-references are documented; confidence remains below maximum because the tiny uncalled paper-open wrappers still need final source placement.
