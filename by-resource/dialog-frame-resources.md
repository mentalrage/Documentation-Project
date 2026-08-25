*** UID:0004SY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Dialog Frame Resources

## Status

- Scope: base DialogPane background and border frame resources, paired palettes, package provenance, complete direct caller inventory, and source-literal versus pooled-storage contract.
- Canonical semantic owner: [UID:0000IT][DialogPane](by-file/DialogPane.md), with class surface on [UID:00003T][DialogPane](by-class/DialogPane.md).
- Rebuild handling: resource-derived payloads plus ordinary source-authored inline resource-name literals. Physical executable string storage is compiler/linker generated and is not reproduced as raw arrays.
- Confidence: very strong for names, bytes, xrefs, frame roles, geometry, package evidence, callers, source placement, and BrowserDialog fallback; strong for the retained legacy EPD distribution history.

## Resource Mode Matrix

| Asset mode | Frame resource | Palette | Tile size | Background role | Border roles | Package state |
| --- | --- | --- | --- | --- | --- | --- |
| current EPF | `DLGFRAME.EPF` | `PAL01.PAL` | 14x14 | frame 8 tiled inside a one-pixel inset | frames 1/6 top/bottom, 3/4 left/right, 0/2/5/7 corners | both payloads present |
| legacy EPD | `DLGFRAME.EPD` | `NPAL8.PAL` | 16x16 | frame 8 tiled over full bounds | frames 1/6 top/bottom, 3/4 left/right, 0/2/5/7 corners | palette present; exact EPD payload absent from current package |

The two branches preserve different geometry and palette families. The absent current `DLGFRAME.EPD` payload is not evidence that the legacy source branch should be removed: the executable contains exact live operands, all frame indices, and BrowserDialog fallback calls.

## Exact Package Provenance

| Resource | Archive entry | Archive SHA256 | Payload SHA256 | Header/result |
| --- | --- | --- | --- | --- |
| `DLGFRAME.EPF` | `bint1.dat`, index 24, offset 2,132,439, size 2,178 | `3CB659CDA1F5F72A9551B16899C5D485D9E6A87CD15BBF54F2C76C2A55C81242` | `C99689CA4A5D1281A8A780F22F7BA2D788DC5F826CD1FE8EB1ADF0329C81917D` | `09 00 0E 00 0E 00`: nine frames, 14x14 |
| `PAL01.PAL` | `bint2.dat`, index 56, offset 9,276,430, size 1,056 | `3434EC989A3D26790CD48A96DE150DC643B26DAAA2544FF033C0CD21C5072929` | `C7CFBF37537C0E6A5772799D6980FE53B1C77D50C02639749F164AB5FC69CA1A` | payload starts with ASCII `DLPalette` |
| `DLGFRAME.EPD` | no exact entry in any current DAT and no exact loose file under `E:\NTK\Resources` | not applicable | not applicable | retained executable literal and complete 16x16 source behavior |
| `NPAL8.PAL` | shared legacy palette support | existing palette authority | existing palette authority | exact legacy partner selected by DialogPane code |

Package checks parsed every `E:\NTK\Resources\NexusTK\Data\*.dat` entry table and performed exact loose-file searches under `E:\NTK\Resources`.

## Physical String Storage

- Parent [UID:0003AX][0x00618ce0-0x00618d2c.DialogFrameResourceStrings](by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md) is an exact 76-byte non-emitting `.rdata` index.
- [UID:0004ST][0x00618ce0-0x00618cfc.DialogFrameEpfResourceString](by-memory/0x00618ce0-0x00618cfc.DialogFrameEpfResourceString.md) stores the true UTF-16 `DLGFRAME.EPF` sequence, terminator, and two-byte alignment.
- [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md) stores the true UTF-16 `PAL01.PAL` sequence and terminator.
- [UID:0004SV][0x00618d10-0x00618d2c.DialogFrameEpdResourceString](by-memory/0x00618d10-0x00618d2c.DialogFrameEpdResourceString.md) stores the true UTF-16 `DLGFRAME.EPD` sequence, terminator, and two-byte alignment.
- IDA suffix views `GFRAME.EPF`, `L01.PAL`, and `GFRAME.EPD` start two UTF-16 code units inside the true strings. Each has zero xrefs and zero absolute/RVA pointer hits; none is a source resource name.
- The three physical pages are non-reconstructable and blank because ordinary wide literals in the owning methods regenerate the pooled storage.

## DialogPane Caller And Behavior Matrix

| Source method | Exact range / UID | Resource uses | Behavior |
| --- | --- | --- | --- |
| `DialogPane::SetBackgroundResource` | [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md) | caller-provided resource and frame index | resolves one layout entry, releases the embedded context, copies row stride/bounds/mask count, allocates and copies encoded-mask bytes |
| `DialogPane::DrawBackground` | [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md) | EPF/EPD frame 8 and PAL01/NPAL8 | current one-pixel-inset tiled background, legacy full-bounds tiled background, or custom encoded-mask fill |
| `DialogPane::DrawBorder` | [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md) | EPF/EPD frames 0-7 and PAL01/NPAL8 | 14/16-pixel do-while edge tiling plus four corners; suppressed for custom encoded-mask backgrounds |

- `ResourceLayoutTable::LookupLayoutEntry` loads each frame into `EPFTileContext`.
- `GrafPort::DrawTiledBackground` tiles frame 8.
- `GrafPort::RenderTileFrame` renders each edge/corner.
- `InitRectBounds` and `OffsetRect` build and advance exact source/destination rectangles.
- `SetDrawColor`, `FillRect`, and `g_pfnFillRle` implement the custom encoded-mask path.
- The embedded context is one `EPFTileContext` at `+0x23c..+0x263`, followed by background width/state at `+0x264` and a Boolean at `+0x268`.

## Complete PAL01 Consumer Inventory

The one physical `PAL01.PAL` sequence has 23 direct operands in sixteen containing functions:

| Containing function/source family | Operand role |
| --- | --- |
| `DialogPane::DrawBackground` | one current background palette operand |
| `DialogPane::DrawBorder` | eight current edge/corner palette operands |
| EmployeeQuantityInputDialogPane constructor | `DLGEXC3.EPF` palette at `0x004a4803` |
| AddItemDialog constructor | `DLGEXC2.EPF` palette at `0x004ae55d` |
| AddItemWithCountDialog constructor | `DLGEXC3.EPF` palette at `0x004af0e8` |
| BackStoryDialogPane constructor | `STORY.EPF` palette at `0x00500150` |
| TextMenuDialog constructor | `DLGMERC1.EPF` palette at `0x005181b7` |
| TextInputMenuDialog constructor | `DLGMERC2.EPF` palette at `0x00519b1e` |
| ServerItemMenuDialog constructor | `DLGMERC3.EPF` palette at `0x0051a935` |
| ClientItemMenuDialog constructor | `DLGMERC1.EPF` palette at `0x0051bb34` |
| ServerSpellMenuDialog constructor | `DLGMERC1.EPF` palette at `0x0051cd38` |
| ClientSpellMenuDialog constructor | `DLGMERC1.EPF` palette at `0x0051dd8b` |
| ArgumentedMenuMenuDialog constructor | `DLGMERC3.EPF` palette at `0x0051eddd` |
| ArgumentedItemQuantityInputDialogPane constructor | `DLGEXC3.EPF` palette at `0x0051fd23` |
| ArgumentedItemConfirmInputDialogPane constructor | `DLGEXC3.EPF` palette at `0x0052017e` |
| NumberInputDialog constructor | `DLGEXC3.EPF` palette at `0x00530704` |

This page is the central full-consumer authority, but each source family retains its own inline literal and feature-resource ownership. No exported palette-name global is introduced.

## BrowserDialog Override And Fallback Boundary

- [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md) owns browser-specific current-layout art.
- BrowserDialog's content-area override calls base `DialogPane::DrawBackground` at `0x0046b0af` in legacy mode.
- BrowserDialog's frame-chrome override calls base `DialogPane::DrawBorder` at `0x0046b49b` in legacy mode.
- These direct calls prove inherited fallback behavior. They do not make BrowserDialog the owner of base frame resources or methods.

## Source And Payload Boundary

- Source owns method control flow, frame indices, geometry, palette/resource names, and custom-background behavior.
- DAT/resource packaging owns the EPF/EPD/PAL payload bytes.
- Compiler/linker pooling owns the exact executable UTF-16 storage and interior suffix views.
- No raw string array, palette payload, frame payload, vtable/RTTI record, relocation cell, or absolute address belongs in reconstructed C++.
- No standalone `DialogFrameResources.cpp`, exported name pointer, or file-local constant array is supported.

## Evidence, Alternatives, And Score

- Positive evidence: exact bytes and subrange hashes, 41 true-start operands, zero interior xrefs, exact package hashes/headers, exact method bodies and virtual slots, Browser fallback calls, and matching layout consumers.
- Negative evidence: no pointer table, no data reference/address taking, no relocation, no constant accessor, no duplicate full terminated sequence, and no current DLGFRAME.EPD package entry.
- Rejected ownership alternatives: BrowserDialog, ResourceLayoutTable, GrafPort, Surface callbacks, MemoryMan, palette library, DAT loader, alert resources, and feature dialogs.
- Completion 92 covers exact physical/source/resource/caller boundaries and complete source-era rebuild handling.
- Confidence 94 is capped by stripped lexical names and missing legacy EPD distribution history, not by any current resource or caller fact.

## Related Documentation

- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)

