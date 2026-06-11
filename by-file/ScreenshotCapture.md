*** UID:0000ND | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenshotCapture

## Status

- Confidence: strong for behavior; medium for exact original filename/folder.
- Proposed module: `render/ScreenshotCapture.cpp` or legacy `render/ScreenShot.cpp`
- Current Wave3 files: `class_ScreenshotCapture.cpp` for BMP/PNG capture methods and `recovered/SendScreenshotProofPacket_00558240.cpp` for proof submission. `recovered/WriteRGBA8PNGFile_00443E40.cpp` also exists, but source comparison now identifies that function as stock LodePNG `lodepng_encode32_file`, not screenshot-owned code. IDA also shows a raw JPG capture body at `0x00557840-0x00557a95` that is not in active generated output.
- Main class/source-family owner: [UID:0000CD][ScreenshotCapture](by-class/ScreenshotCapture.md)
- Main address doc: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- Related item: [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- Evidence basis: `simroot_v2` generated source plus read-only IDA MCP lookup/caller/callee checks on 2026-05-24, 2026-05-25, and 2026-05-26. Wave3 data was repaired on 2026-05-24 so `0x00557aa0` and `0x00557e80` now emit under `class_ScreenshotCapture.cpp`.

## File Role

This module owns the user screenshot workflow:

1. Capture the current render surface through the active pane/surface fields.
2. Save a timestamped file under `Documents\NexusTK\ScreenShots`.
3. Emit a local chat/status line with the saved file name.
4. Reopen the saved file and send a digest-derived screenshot proof packet to the server.

This is not filesystem-tree UI code. The old generated ownership placed the capture methods under `FolderTreePane`, but the call path starts in [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) hotkey routing and passes the process-wide active/root pane pointer, while the implementation uses shared surface, image writer, chat, MD5, and network helpers.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `SaveScreenshotJPG` raw/retained path | `0x00557840-0x00557a95` | Creates screenshot directories, writes a JPEG file from the active surface through [UID:0000K4][ImageWriters](by-file/ImageWriters.md), posts the saved-file chat message, and sends screenshot proof; no direct caller currently modeled. |
| `SaveScreenshotBMP` | `0x00557aa0-0x00557e73` | Creates screenshot directories, writes a 16-bit BMP file from the active surface, posts the saved-file chat message, and sends screenshot proof. |
| `SaveScreenshotPNG` | `0x00557e80-0x00558239` | Converts the active 16-bit surface to an RGBA8 buffer, writes PNG through [UID:0000KW][LodePNG](by-file/LodePNG.md) `lodepng_encode32_file`, posts the saved-file chat message, and sends screenshot proof. |
| `SendScreenshotProofPacket` | `0x00558240-0x00558391` | Hashes the saved file stream through [UID:0000L6][MD5](by-file/MD5.md), masks the digest, builds opcode `0x83`, and queues it through the packet send funnel. |
| [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) | `0x00559af0-0x00559b1d` | Local saved-file status formatter used by the JPG/BMP/PNG screenshot paths; wraps CRT secure wide formatting with a fixed `0x78` wide-character destination bound. |

## Evidence

- IDA MCP confirms exact function starts and sizes:
  - `0x00557aa0`, size `0x3d3`, `sub_557AA0`.
  - `0x00557e80`, size `0x3b9`, `sub_557E80`.
  - `0x00558240`, size `0x151`, `sub_558240`.
- IDA disassembly confirms a raw function-shaped JPG path at `0x00557840-0x00557a95`, with a normal prologue/epilogue but no modeled IDA function start.
- IDA callers show both capture functions are triggered only from `EventDispatcher::RouteEventToHandlers` at `0x004a7130`.
- IDA decompilation of the event route shows direct calls to BMP capture on one hotkey path and PNG capture on another, including `Ctrl+Shift+3` and `Ctrl+Shift+4` branches.
- IDA callers show `SendScreenshotProofPacket` is called only by `SaveScreenshotBMP` and `SaveScreenshotPNG`.
- IDA xrefs show the JPG path calls [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) at `0x005579d3`, then runs the same chat/status and proof-submit flow as the modeled BMP/PNG methods.
- 2026-05-26 recheck: current `simroot_v2/class_ScreenshotCapture.cpp` still omits the raw JPG body at `0x00557840`; IDA still reports `0x00557840` as not-a-function with no callers/xrefs.
- 2026-05-26 IDA MCP now models the adjacent flag setters at `0x00557820` and `0x00557830` as 8-byte functions, each with one caller, but this still does not prove JPG capture-path reachability.
- 2026-05-26 IDA MCP `xrefs_to 0x00558240` includes the raw JPG proof call at `0x00557a78` in addition to the modeled BMP and PNG proof calls.
- `SaveScreenshotBMP` writes file and info headers directly with `fwrite`, temporarily swaps the active surface id to the screenshot surface id, refreshes surface info through `0x004b9820`, and restores state after `EndPaint`.
- `SaveScreenshotPNG` allocates a 4-byte-per-pixel buffer, converts from the active 16-bit surface, calls LodePNG `lodepng_encode32_file` at `0x00443e40`, frees the pixel block, and then sends proof.
- Both capture functions format `TK_%04d%02d%02d%02d%02d%02d.bmp/png` under `Documents\NexusTK\ScreenShots`.
- 2026-06-06 IDA MCP `xrefs_to 0x00559af0` confirms the fixed-buffer saved-file status formatter is called by the raw JPG path at `0x00557a08`, BMP path at `0x00557de4`, and PNG path at `0x005581a6`.

## Ownership Decision

Use a dedicated screenshot module rather than `FolderTreePane.cpp`. The capture functions are surface-oriented feature helpers triggered by the event dispatcher and are not part of the folder-tree control's filesystem enumeration, selection, or painting. Wave3 now models this with the `ScreenshotCapture` owner class and `class_ScreenshotCapture.cpp` file.

Keep dependencies separate:

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns the hotkey routing.
- [UID:0000OC][Surface](by-file/Surface.md) owns shared paint/surface helpers such as `UpdateSurfaceInfo` and `EndPaint`.
- [UID:0000KW][LodePNG](by-file/LodePNG.md) owns the PNG writer API at `0x00443e40` and the bundled encoder backend. [UID:0000K4][ImageWriters](by-file/ImageWriters.md) remains relevant for the separate JPEG output wrapper and for older PNG ownership notes, but current source comparison does not support assigning the LodePNG public PNG helpers there.
- [UID:0000L6][MD5](by-file/MD5.md) owns the file-stream digest helper used by proof submission.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) own packet scalar writes and queued send dispatch.

## Open Questions

- Whether the original file name was `Screenshot.cpp`, `ScreenShot.cpp`, `ScreenCapture.cpp`, or a private section of a larger surface/screen source file.
- Whether JPG, BMP, and PNG capture were originally free functions taking a pane/surface pointer, methods on a root screen pane, or methods on a generic surface owner.
- Whether the raw JPG path was reachable through an indirect callback or is retained legacy code.
- Exact semantic owner of `dword_67A7CC`, the pointer passed by the event dispatcher into the capture functions.

## Cross-References

- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md)
- [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0000CD][ScreenshotCapture](by-class/ScreenshotCapture.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-06: Added the saved-file status formatter to the file inventory.
  - Before: `0x00559af0-0x00559b1d` was documented only as a standalone/unassigned formatting helper and did not appear in this file page's proposed contents.
  - After: added [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) as a ScreenshotCapture-local helper.
  - Evidence: live IDA MCP `xrefs_to 0x00559af0` reports the JPG/BMP/PNG screenshot status-message call sites at `0x00557a08`, `0x00557de4`, and `0x005581a6`, and the helper page records the exact CRT formatting wrapper boundary and parent attachment.

- 2026-06-01: Assigned the validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page already proposed `render/ScreenshotCapture.cpp`.
  - After: set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Evidence: the page documents screenshot workflow ownership under the render subsystem, [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) is now attached as a reconstructable child, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/ScreenshotCapture.cpp`.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document includes workflow role, proposed contents, exact IDA ranges, JPG/BMP/PNG behavior, proof-packet ownership, dependency split, ownership decision, open questions, and cross-references; confidence is capped by exact original filename/folder and raw JPG reachability questions.
