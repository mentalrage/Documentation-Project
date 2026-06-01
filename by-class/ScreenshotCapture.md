*** UID:0000CD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenshotCapture

## Status

- Confidence: strong for behavior and file ownership; medium for whether the original code used a class or free helper functions.
- Likely source file: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Address range: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md), plus raw JPG path [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md)
- Current recovered file: `source-3/simroot_v2/class_ScreenshotCapture.cpp`
- Current Wave3 class grade: incomplete; active output still carries raw render-surface fields and unresolved helper/global names.

## Class Purpose

`ScreenshotCapture` is the current recovered owner for screenshot hotkey helpers. It captures the active render surface, writes a timestamped BMP or PNG under `Documents\NexusTK\ScreenShots`, posts the saved-file chat/status message, and sends an opcode `0x83` screenshot proof packet derived from the saved file's MD5 digest.

The recovered class has no confirmed vtable, constructor, or persistent object lifecycle. Treat the class name as a source-family owner unless later evidence proves an actual C++ class declaration.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `SaveScreenshotJPG` raw/retained path | `0x00557840-0x00557a95` | Creates screenshot folders, writes a JPEG from the active surface through [UID:0000K4][ImageWriters](by-file/ImageWriters.md), posts chat/status output, and submits screenshot proof; no direct caller currently modeled. |
| `SaveScreenshotBMP` | `0x00557aa0-0x00557e73` | Creates screenshot folders, writes a 16-bit BMP from the active surface, posts chat/status output, and submits screenshot proof. |
| `SaveScreenshotPNG` | `0x00557e80-0x00558239` | Converts the active 16-bit surface to RGBA8, writes PNG through [UID:0000KW][LodePNG](by-file/LodePNG.md), posts chat/status output, and submits screenshot proof. |
| `SendScreenshotProofPacket_558240` | `0x00558240-0x00558391` | File-local helper candidate that hashes the saved stream through [UID:0000L6][MD5](by-file/MD5.md), masks the digest, and queues opcode `0x83`. |

## Ownership Notes

- This source family was previously polluted by a generated [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) fallback owner. The hotkey caller, surface fields, screenshot paths, and proof packet behavior all point away from folder-tree UI.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns hotkey routing. `ScreenshotCapture` owns the capture/write/proof workflow reached by those hotkeys.
- [UID:0000OC][Surface](by-file/Surface.md) owns shared render-surface helpers used while temporarily switching the active surface id.
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md) and [UID:0000KW][LodePNG](by-file/LodePNG.md) own PNG writing backend code; this class only decides when and where to write a screenshot.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) own packet serialization and queued send dispatch.

## Data Caveats

- `class_ScreenshotCapture.cpp` still uses raw field offsets such as `+0x18`, `+0x20`, `+0x28`, `+0x44`, `+0x4c`, `+0x50`, and `+0x108`; these likely belong to an active screen/surface object passed as `this`, not a dedicated screenshot object layout.
- Current generated output omits the raw JPG path at `0x00557840`; use the memory doc as the ownership anchor until Wave3/IDA function recovery is updated.
- 2026-05-26 IDA MCP recheck: `0x00557840` is still not an IDA function and has no callers/xrefs, while the adjacent setters at `0x00557820` and `0x00557830` are now modeled 8-byte functions. Active `class_ScreenshotCapture.cpp` still omits the JPG body.
- The class should stay documented as a `ScreenshotCapture.cpp` source module, but final migration should decide whether the C++ declarations become free functions, static helpers, or methods on a screen/render object.
- `SendScreenshotProofPacket_558240` is currently a recovered global/item; keep it linked to this module unless later network ownership review moves proof-packet construction into a protocol source.

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
