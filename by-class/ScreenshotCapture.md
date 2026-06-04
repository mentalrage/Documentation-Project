*** UID:0000CD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ND | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenshotCapture

## Status

- Confidence: strong for workflow behavior, file ownership, live function boundaries, hotkey callers, proof-packet xrefs, and parent placement; medium for whether the original code used a class, free helper functions, or methods on a screen/surface owner.
- Likely source file: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Address range: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md), plus raw JPG path [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md)
- Parent attachment: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) is `88/80` with projected path `NexusTK/render/`; this class/source-family page is attached because live IDA confirms the screenshot capture/proof workflow and both memory children are already attached to that file.

## Class Purpose

`ScreenshotCapture` is the documentation owner for screenshot hotkey helpers. It captures the active render surface, writes a timestamped BMP or PNG under `Documents\NexusTK\ScreenShots`, posts the saved-file chat/status message, and sends an opcode `0x83` screenshot proof packet derived from the saved file's MD5 digest.

The recovered class has no confirmed vtable, constructor, or persistent object lifecycle. Treat the class name as a source-family owner unless later evidence proves an actual C++ class declaration.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `SaveScreenshotJPG` raw/retained path | `0x00557840-0x00557a95` | Creates screenshot folders, writes a JPEG from the active surface through [UID:0000K4][ImageWriters](by-file/ImageWriters.md), posts chat/status output, and submits screenshot proof; no direct caller currently modeled. |
| `SaveScreenshotBMP` | `0x00557aa0-0x00557e73` | Creates screenshot folders, writes a 16-bit BMP from the active surface, posts chat/status output, and submits screenshot proof. |
| `SaveScreenshotPNG` | `0x00557e80-0x00558239` | Converts the active 16-bit surface to RGBA8, writes PNG through [UID:0000KW][LodePNG](by-file/LodePNG.md), posts chat/status output, and submits screenshot proof. |
| `SendScreenshotProofPacket_558240` | `0x00558240-0x00558391` | File-local helper candidate that hashes the saved stream through [UID:0000L6][MD5](by-file/MD5.md), masks the digest, and queues opcode `0x83`. |

## Ownership Notes

- This source family previously carried a [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) fallback owner label. The hotkey caller, surface fields, screenshot paths, and proof packet behavior all point away from folder-tree UI.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns hotkey routing. `ScreenshotCapture` owns the capture/write/proof workflow reached by those hotkeys.
- [UID:0000OC][Surface](by-file/Surface.md) owns shared render-surface helpers used while temporarily switching the active surface id.
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md) and [UID:0000KW][LodePNG](by-file/LodePNG.md) own PNG writing backend code; this class only decides when and where to write a screenshot.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) own packet serialization and queued send dispatch.

## Data Caveats

- The capture bodies still expose raw field offsets such as `+0x18`, `+0x20`, `+0x28`, `+0x44`, `+0x4c`, `+0x50`, and `+0x108`; these likely belong to an active screen/surface object passed as `this`, not a dedicated screenshot object layout.
- IDA does not model the raw JPG path at `0x00557840` as a function start and still reports no direct modeled caller for that raw start, so use [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) as the address-level ownership anchor.
- 2026-06-04 live IDA MCP recheck: `0x00557840` remains not modeled as a function, while adjacent setters at `0x00557820-0x00557828` and `0x00557830-0x00557838` are modeled 8-byte functions with callers at `0x004f8a8e` and `0x00504849`.
- The class should stay documented as a `ScreenshotCapture.cpp` source module, but final migration should decide whether the C++ declarations become free functions, static helpers, or methods on a screen/render object.
- `SendScreenshotProofPacket_558240` is currently a recovered global/item; keep it linked to this module unless later network ownership review moves proof-packet construction into a protocol source.

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled function boundaries: BMP capture `0x00557aa0-0x00557e73`, PNG capture `0x00557e80-0x00558239`, and proof helper `0x00558240-0x00558391`.
- IDA xrefs show BMP capture callers at `0x004a71b6` and `0x004a7250` inside `EventDispatcher::RouteEventToHandlers` (`0x004a7130`), and PNG capture callers at `0x004a71d1` and `0x004a7296` in the same function.
- The raw JPG body at `0x00557840-0x00557a95` remains unmodeled but has live xrefs/calls inside the raw span: JPEG writer call `0x005579d3 -> 0x004efbc0`, status formatter call `0x00557a08 -> 0x00559af0`, chat/status append `0x00557a48 -> 0x0047f280`, and proof call `0x00557a78 -> 0x00558240`.
- The modeled BMP/PNG paths share the same status/proof pattern: BMP calls `0x00559af0`, `0x0047f280`, and `0x00558240` at `0x00557de4`, `0x00557e24`, and `0x00557e55`; PNG calls them at `0x005581a6`, `0x005581e6`, and `0x0055821b`.
- PNG capture calls the LodePNG front end at `0x0055817b -> 0x00443e40`; the raw JPG path calls the JPEG writer at `0x005579d3 -> 0x004efbc0`.
- Proof helper data refs confirm the XOR key storage at `0x006232e0`, `0x00623300`, and `0x006232f0`; it queues the final packet through sender global `0x0067a7ec` and call `0x00558370 -> 0x00574bb0`.
- Remaining uncertainty is source-shape rather than behavior: no confirmed vtable or constructor exists, the `this` layout still looks like a screen/surface owner, and the raw JPG path has no modeled direct caller. Final reconstruction C++ stays blank.

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/76`.
  - Before: The page was unevaluated despite documenting BMP/PNG/JPG capture paths, screenshot proof packet behavior, ownership caveats, and data defects.
  - After: Scored as moderate-high completion and confidence because the workflow and module ownership are clear, while class-vs-free-helper shape and the raw JPG path remain unresolved.
  - Evidence: Existing method table, ownership notes, data caveats, IDA recheck notes, and image/network/surface cross-references support the score.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).
  - Summary/evidence: live IDA MCP confirms BMP/PNG/proof function boundaries, EventDispatcher hotkey callers, raw JPG writer/status/proof calls, modeled BMP/PNG status/proof calls, PNG/JPEG writer dependencies, proof XOR key refs, packet sender call, adjacent setter stubs, and raw JPG liveness caveat; parent file [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) is already `88/80` with valid `NexusTK/render/` placement.
  - Remaining gaps: final C++ remains blank because class-vs-free-function shape, the screen/surface `this` layout, helper names, and raw JPG reachability are not yet at the 95/95 threshold.
