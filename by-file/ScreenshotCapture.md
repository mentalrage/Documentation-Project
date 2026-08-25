*** UID:0000ND | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScreenshotCapture

## Status

- Confidence: very strong for behavior, file ownership, exact split, ScreenPane receivers, file-local proof ABI, declarations, source order, dependencies, and duplicate-free emitter routing.
- Proposed module: `NexusTK/render/ScreenshotCapture.cpp`. Historical `ScreenShot.cpp` capitalization remains search context only.
- Expected generated source: one proof forward declaration, retained JPG method, BMP method, PNG method, and one proof definition in positions `5/10/20/30/40`. UID0001G9 and UID0000CD are non-emitting indexes. Stock LodePNG and JPEG/MD5/packet implementations remain in their own source modules.
- Main class/source-family owner: [UID:0000CD][ScreenshotCapture](by-class/ScreenshotCapture.md)
- Main address doc: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- Related item: [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- Exact emitted children: [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md), [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md), [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md), and [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md).
- Evidence basis: `simroot_v2` generated source plus read-only IDA MCP lookup/caller/callee checks on 2026-05-24, 2026-05-25, 2026-05-26, and B001 follow-up checks on 2026-06-11. Wave3 data was repaired on 2026-05-24 so `0x00557aa0` and `0x00557e80` now emit under `class_ScreenshotCapture.cpp`.

## File Role

This module owns the user screenshot workflow:

1. Capture the current render surface through the active pane/surface fields.
2. Save a timestamped file under `Documents\NexusTK\ScreenShots`.
3. Emit a local chat/status line with the saved file name.
4. Reopen the saved file and send a digest-derived screenshot proof packet to the server.

This is not filesystem-tree UI code. The old generated ownership placed the capture methods under `FolderTreePane`, but the call path starts in [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) hotkey routing and passes the process-wide active/root pane pointer, while the implementation uses shared surface, image writer, chat, MD5, and network helpers.

The capture routines use the root [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) / `ScreenPane` object as their receiver. The accepted emitted source shape is `void ScreenPane::SaveScreenshotJPG()`, `void ScreenPane::SaveScreenshotBMP()`, and `void ScreenPane::SaveScreenshotPNG()` implemented in this feature module. Direct thiscall ABI, accepted ScreenPane/GrafPort fields, and hotkey receiver setup reject a concrete `ScreenshotCapture` object and make file-local helpers taking `ScreenPane*` only a historical weaker alternative.

## Source Order And Dependencies

Exact output order:

1. [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md) emits `static void __stdcall SendScreenshotProofPacket(FILE *stream);` at position `5`.
2. [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) emits `ScreenPane::SaveScreenshotJPG` at position `10`.
3. [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) emits `ScreenPane::SaveScreenshotBMP` at position `20`.
4. [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) emits `ScreenPane::SaveScreenshotPNG` at position `30`.
5. [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) emits the sole proof definition at position `40`.

Logical project/header dependencies are ScreenPane, BrowserControlPane, ChattingPane, EventMan, MD5, Socket/packet sender, and the public LodePNG API. Platform/runtime dependencies are Windows/Shell path APIs, stdio, stdlib, string, and time. Use project/PCH equivalents where the reconstructed build centralizes them. Do not paste LodePNG, JPEG, MD5, EventDispatcher, browser blit, or Socket implementation into this source.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) | `[0x00557840,0x00557a96)` | Retained method with corrected endpoint; writes JPEG, status, and proof. No direct raw-start route is currently known. |
| [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) | `[0x00557aa0,0x00557e73)` | Writes exact 14/40-byte headers and bottom-up 16-bit rows, composites browser content, posts status, and sends proof. |
| [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) | `[0x00557e80,0x00558239)` | Converts captured RGB555/RGB565 to top-down RGBA8, calls `lodepng_encode32_file`, posts status, and sends proof. |
| [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) | `[0x00558240,0x00558391)` | File-local `void __stdcall(FILE *)`; masks MD5 hex and sends exact opcode `0x83` 13+16+19 payload. |
| [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md) | `0x0045ef20-0x0045ef50` | Reviewed non-emitting fixed-256 MSVC/UCRT secure array-overload support consumed by JPG/BMP/PNG caller-local timestamp filename expressions; this file does not own or emit UID0003X8. |
| [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) | `0x00559af0-0x00559b1d` | Reviewed non-emitting fixed-`0x78` MSVC/UCRT secure wide-format support consumed by JPG/BMP/PNG saved-status formatting; this file owns the caller-local status formatting expressions, not UID00023T as an emitted helper body. |

## Evidence

- IDA MCP confirms exact function starts and sizes:
  - `0x00557aa0`, size `0x3d3`, `sub_557AA0`.
  - `0x00557e80`, size `0x3b9`, `sub_557E80`.
  - `0x00558240`, size `0x151`, `sub_558240`.
- IDA disassembly confirms a raw function-shaped JPG path at `[0x00557840,0x00557a96)`, with a normal prologue, return byte at `0x00557a95`, and no modeled IDA function start.
- IDA callers show both capture functions are triggered only from `EventDispatcher::RouteEventToHandlers` at `0x004a7130`.
- IDA decompilation of the event route shows direct calls to BMP capture on one hotkey path and PNG capture on another, including `Ctrl+Shift+3` and `Ctrl+Shift+4` branches.
- IDA modeled callers show BMP/PNG, while direct xrefs prove exactly three real proof calls: raw JPG `0x00557a78`, BMP `0x00557e55`, and PNG `0x0055821b`.
- IDA xrefs show the JPG path calls [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) at `0x005579d3`, then runs the same chat/status and proof-submit flow as the modeled BMP/PNG methods.
- 2026-05-26 recheck: current `simroot_v2/class_ScreenshotCapture.cpp` still omits the raw JPG body at `0x00557840`; IDA still reports `0x00557840` as not-a-function with no callers/xrefs.
- 2026-05-26 IDA MCP now models the adjacent flag setters at `0x00557820` and `0x00557830` as 8-byte functions, each with one caller, but this still does not prove JPG capture-path reachability.
- 2026-05-26 IDA MCP `xrefs_to 0x00558240` includes the raw JPG proof call at `0x00557a78` in addition to the modeled BMP and PNG proof calls.
- All capture bodies save inherited `m_ddSurface`, select ScreenPane `m_renderSurface`, refresh `m_surfaceContext`, optionally composite `g_activeBrowserControlPane`, call `EndPaint`, and restore the DirectDraw pointer. The former surface-ID interpretation is rejected.
- `SaveScreenshotPNG` allocates a 4-byte-per-pixel buffer, converts from the active 16-bit surface, calls LodePNG `lodepng_encode32_file` at `0x00443e40`, frees the pixel block, and then sends proof.
- Both capture functions format `TK_%04d%02d%02d%02d%02d%02d.bmp/png` under `Documents\NexusTK\ScreenShots`.
- B001's 2026-07-12 UID0003X8 review proves the filename route is compiler/header support selected by destination extent: raw JPG `0x0055794e`, BMP `0x00557bae`, and PNG `0x00557f94` pass 256-wide filename buffers to fixed-256 UID0003X8, while fixed-260 UID0002UA handles path arrays. UID0003X8 is `90/92`, owner `NONE`, reconstructable false, blank emitters/code; callers retain secure formatting expressions.
- 2026-07-05 B001 UID00023T reclassification: current MCP `xrefs_to 0x00559af0` confirms the fixed-buffer secure-format support body is consumed by the raw JPG path at `0x00557a08`, BMP path at `0x00557de4`, and PNG path at `0x005581a6`; `xref_query` reports zero data refs and pointer-byte scans report zero VA/RVA hits. Treat the body as runtime/header support, not as `ScreenshotCapture` source content.
- 2026-06-11 B001 follow-up decompiled [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) hotkey routing at `0x004a7130` again: it loads `dword_67A7CC` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) and calls BMP at `0x004a71b6` / `0x004a7250` and PNG at `0x004a71d1` / `0x004a7296`.
- 2026-06-11 B001 raw reference scan found no absolute pointer and no direct rel32 call/jump targeting the raw JPG start `0x00557840`, but raw xrefs reconfirmed the JPG path's calls to `0x004b9820`, `0x0046bfd0`, `0x004efbc0`, `0x004b98c0`, `0x00559af0`, `0x0047f280`, and `0x00558240`.
- 2026-06-11 B001 proof-helper decompilation established MD5, mask, opcode `0x83`, 16 inserted random bytes, 49-byte queue, and digest free. The 2026-07-24 closure proves the exact first random expression `(rand() % 10) - 26`, 15 subsequent `%255` bytes, 13+16+19 partition, and local-only byte-49 terminator.
- 2026-06-20 B005 source-quality reanalysis resolves the best current source-facing JPG shape as retained `ScreenPane::SaveScreenshotJPG()` under this file owner. The raw body has no absolute/direct rel32 route to `0x00557840`, but it preserves `ecx` as a receiver, touches ScreenPane surface fields, mirrors BMP/PNG setup/status/proof flow, calls [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md), and uses source-facing roles `g_surfaceUsesRgb565Pixels`, `g_screenWidth`, `g_screenHeight`, `g_activeBrowserControlPane`, `g_pChattingDisplayPane`, `g_pEventMan`, `g_pfnWideOpenFile`, and `g_pfnCreateDirectoryW`.

## Ownership Decision

Use a dedicated screenshot module rather than `FolderTreePane.cpp`. The capture functions are surface-oriented feature helpers triggered by the event dispatcher and are not part of the folder-tree control's filesystem enumeration, selection, or painting. Current reconstruction should model `ScreenshotCapture.cpp` as a feature/source-file owner, not as proof of a concrete `ScreenshotCapture` runtime object.

The capture helpers use the root ScreenPane object as their receiver, so ScreenPane is an important data-owner dependency. That receiver evidence does not by itself make the screenshot save/status/proof workflow a ScreenPane source-file owner. Keep the workflow in this dedicated screenshot module while keeping EventDispatcher, Surface, ImageWriters/LodePNG, MD5, PacketBuffer, CashShopRequest, and non-emitting UID0003X8/UID00023T secure-format support as dependencies. `ScreenshotCapture::SaveScreenshotJPG`, a standalone `ScreenshotJpegCapturePath` source name, and either fixed wrapper as a direct `ScreenshotCapture` helper body are rejected unless later source evidence proves a concrete class/object, different original naming, or a project-visible formatting API.

Keep dependencies separate:

- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns the hotkey routing.
- [UID:0000OC][Surface](by-file/Surface.md) owns shared paint/surface helpers such as `UpdateSurfaceInfo` and `EndPaint`.
- [UID:0000KW][LodePNG](by-file/LodePNG.md) owns the PNG writer API at `0x00443e40` and the bundled encoder backend. [UID:0000K4][ImageWriters](by-file/ImageWriters.md) remains relevant for the separate JPEG output wrapper and for older PNG ownership notes, but current source comparison does not support assigning the LodePNG public PNG helpers there.
- [UID:0000L6][MD5](by-file/MD5.md) owns the file-stream digest helper used by proof submission.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) own packet scalar writes and queued send dispatch.

## Closed Questions And Residual Caveats

- Source filename: use `ScreenshotCapture.cpp` because it is the established project source root and cohesive physical feature cluster. Keep `ScreenShot.cpp` only as historical search context.
- Capture shape: use `ScreenPane::SaveScreenshotJPG/BMP/PNG`; thiscall ABI and [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) receiver setup outweigh the file-local-pointer fallback.
- Raw JPG liveness: no direct/pointer route to `0x00557840` is known. Preserve the complete source-authored retained method because its internal writer/status/proof calls and exact boundary are real; this caveat does not alter ownership or output.
- Receiver global: `dword_67A7CC` is [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), and ScreenPane UID0000CB is the canonical method owner.
- Remaining uncertainty is original spelling and whole-product compile/link equivalence, not a blocker to this source layout or first-draft code.

## Cross-References

- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md)
- [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md)
- [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0000CD][ScreenshotCapture](by-class/ScreenshotCapture.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md)
- [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md)
- [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## UID0003CJ Screenshot And Proof Literal Source Shape

[UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) is a non-emitting physical literal pool, not an additional ScreenshotCapture data emitter. The ScreenshotCapture-owned use-site subset is exact:

| Pool range | Source use |
| --- | --- |
| `0x0062317c-0x006231aa` | 46-byte `%s\\NexusTK\\ScreenShots`, referenced by JPG `0x005578c2`, BMP `0x00557b22`, and PNG `0x00557f08`. |
| `0x006231b0-0x006231f0` | 64-byte BMP filename format, ref `0x00557ba8`. |
| `0x006231f0-0x0062325c` | one 108-byte status format, refs `0x00557a02`, `0x00557dde`, `0x005581a0`; the former IDA three-item split is false. |
| `0x00623260-0x006232a0` | 64-byte JPG filename format, ref `0x00557948`. |
| `0x006232a0-0x006232e0` | 64-byte PNG filename format, ref `0x00557f8e`. |
| `0x006232e0-0x00623301` | one 33-byte pooled proof-mask item containing exactly 32 literal characters plus NUL. The current saved IDB names it `ScreenshotProofMaskLiteral` and types it `const char[33]`, with all three vectorized/local-initializer refs preserved at `0x00558253`, `0x00558269`, and `0x0055825d`; historical xmmword/byte heads are superseded analysis splits. |

The JPG/BMP/PNG formals retain these wide values inline. [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) retains exact local source `char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";`, not two xmmword globals plus a byte. The literal supplies 32 characters at local indices `0..31` and its NUL at index `32`; C++ aggregate initialization supplies three additional zero-initialized local bytes at indices `33..35`, and only indices `0..31` participate in XOR. The first screenshot/proof pool subrange through `0x00623304` has SHA256 `47993566152F4C2802E704DC612F9A80DB4D0B8D839DF137BD46C6B0AFFBDBCF`.

UID0003CJ also contains cursor and Surface-only values, so ScreenshotCapture cannot canonically own the whole pool. Preserve this file at `92/93`, its exact four emitted children/order, and its sole method/helper bodies. Do not add static literal globals, a pool array, or duplicate formal output.

## Changes

- 2026-07-24 B001 UID0003CJ support synchronization: preserved `92/93`, exact child ordering, source path, dependencies, and formals; added exact screenshot/proof pool ranges, refs, combined-literal corrections, source-local reconstruction, hash, and rejection of whole-pool ownership/duplicate emission.

- 2026-07-24 B004 UID0001G9 drift reconciliation: preserved `92/93`, exact child order, file route, dependencies, and all source bodies; recorded the current applied one-item proof-mask IDA readback without creating any source global or duplicate emitter.

- 2026-07-24 B004 focused C1G9-023 callback: completed the file-level proof-mask source shape with the exact 32-character literal, 33-byte pooled item including NUL, 36-byte local array with three additional zero-initialized bytes, and XOR-only indices `0..31`.

- 2026-07-24 B004 UID0001G9 implementation callback:
  - Raised `89/88 -> 92/93` and fixed the source root at `NexusTK/render/ScreenshotCapture.cpp`.
  - Recorded exact positions `5/10/20/30/40`, corrected JPG endpoint, real child UIDs, complete declaration/include/dependency ordering, and sole-definition routing.
  - Reconciled ScreenPane/GrafPort pointer fields, exact EventDispatcher hotkeys, BMP/PNG conversion behavior, proof random-byte/terminator semantics, non-emitting secure-format wrappers, no concrete ScreenshotCapture object, and all rejected duplicate/dependency ownership routes.

- 2026-07-12 B001 UID0003X8 implementation callback:
  - Added UID0003X8 as a non-emitting dependency/cross-reference for JPG/BMP/PNG caller-local timestamp filename expressions, with exact calls `0x0055794e`, `0x00557bae`, and `0x00557f94` and 256-wide buffer evidence.
  - Preserved ScreenshotCapture file ownership, scores, module path, caller workflows, and all UID00023T content. UID0003X8 remains owner `NONE`, reconstructable false, blank emitters/code and is not proposed file content.

- 2026-07-05 B001 UID00023T implementation callback:
  - Before: the file inventory and evidence described [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) as a ScreenshotCapture-local saved-file formatter/helper.
  - After: kept ScreenshotCapture as the consumer/source-feature context for JPG/BMP/PNG saved-status formatting, but reworded UID00023T as non-emitting fixed-`0x78` MSVC/UCRT secure-format support with no direct `ScreenshotCapture` emitted helper body.
  - Evidence: current B001 MCP refresh records exact code xrefs at `0x00557a08`, `0x00557de4`, and `0x005581a6`, zero data refs, zero VA/RVA pointer hits, fixed `0x78` count, local stdio options, `___stdio_common_vswprintf_s`, and same-family fixed-wrapper precedent.
- 2026-06-20 B005 JPG source-shape incorporation:
  - Before: `88/86`, with the raw JPG body documented as omitted generated output but still capped by class-vs-free-helper ambiguity.
  - After: `89/88`; documented `ScreenPane` as the capture receiver, kept this page as the screenshot feature/source-file owner, changed the contents table to `ScreenPane::SaveScreenshotJPG/BMP/PNG`, and recorded the B005 no-route/retained-JPG evidence plus source-facing helper/global names. [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) now carries the first-draft JPG C++ body.
- 2026-06-06: Added the saved-file status formatter to the file inventory.
  - Before: `0x00559af0-0x00559b1d` was documented only as a standalone/unassigned formatting helper and did not appear in this file page's proposed contents.
  - After: added [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) as a ScreenshotCapture-local helper.
  - Evidence: live IDA MCP `xrefs_to 0x00559af0` reports the JPG/BMP/PNG screenshot status-message call sites at `0x00557a08`, `0x00557de4`, and `0x005581a6`, and the helper page records the exact CRT formatting wrapper boundary and parent attachment.

- 2026-06-01: Assigned the validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page already proposed `render/ScreenshotCapture.cpp`.
  - After: set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Evidence: the page documents screenshot workflow ownership under the render subsystem, [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) is now attached as a reconstructable child, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/ScreenshotCapture.cpp`.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document includes workflow role, proposed contents, exact IDA ranges, JPG/BMP/PNG behavior, proof-packet ownership, dependency split, ownership decision, open questions, and cross-references; confidence is capped by exact original filename/folder and raw JPG reachability questions.
- 2026-06-11 B001 deeper follow-up:
  - Before: `88/80`, which left existing [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) and [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md) attachments below the current strict parent `85/85` gate.
  - After: `88/86`; screenshot workflow ownership and dependencies are now sufficiently documented for the current gate, while final filename/folder and class-vs-free-helper uncertainty remain below final-source C++ quality.
  - Evidence: EventDispatcher hotkey decompilation, raw JPG no-pointer/no-direct-call scan, JPG key-call xrefs, BMP/PNG/proof function decompilation, proof-packet xrefs, and proposed-source-tree placement.
