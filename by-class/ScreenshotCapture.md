*** UID:0000CD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ND | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenshotCapture

## Status

- Confidence: very strong that this is a non-emitting source-family index rather than a concrete runtime class. Exact receiver ABI resolves JPG/BMP/PNG as ScreenPane methods, while the proof body is a file-local stdcall helper.
- Likely source file: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Address family: retained JPG [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md), non-emitting exact index [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md), BMP [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md), PNG [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md), and proof [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md).
- Rebuild handling: `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++. This page organizes the feature family only; exact by-memory children and ScreenPane declarations carry reconstruction output through UID0000ND.

## Class Purpose

`ScreenshotCapture` is the documentation/source-family owner for screenshot hotkey helpers. It captures the active render surface, writes a timestamped JPG/BMP/PNG under `Documents\NexusTK\ScreenShots`, posts the saved-file chat/status message, and sends an opcode `0x83` screenshot proof packet derived from the saved file's MD5 digest.

The recovered family has no vtable, constructor, destructor, allocation, global instance, receiver, field layout, RTTI, or persistent object lifecycle for a `ScreenshotCapture` object. The name is therefore a documentation/source-family index, not a class declaration. Current source-facing bodies are exact `ScreenPane::SaveScreenshotJPG/BMP/PNG()` definitions in ScreenshotCapture.cpp plus file-local `SendScreenshotProofPacket`; the former file-local-`ScreenPane*` fallback is retained only as a rejected historical hypothesis.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) | `[0x00557840,0x00557a96)` | Retained/no-direct-start-route ScreenPane method; writes JPEG, posts status, and submits proof. Exact return-byte endpoint and formal body are repaired. |
| [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) | `[0x00557aa0,0x00557e73)` | Exact hotkey-reached ScreenPane method; writes 14/40-byte BMP headers and bottom-up 16-bit rows with RGB565-to-555 conversion. |
| [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) | `[0x00557e80,0x00558239)` | Exact hotkey-reached ScreenPane method; converts top-down RGB555/RGB565 pixels to RGBA8 and calls stock LodePNG. |
| [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) | `[0x00558240,0x00558391)` | Exact file-local `void __stdcall(FILE *)` helper; masks MD5 hex and queues the opcode `0x83` 13+16+19-byte proof payload. |

## Ownership Notes

- This source family previously carried a [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) fallback owner label. The hotkey caller, surface fields, screenshot paths, and proof packet behavior all point away from folder-tree UI.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns hotkey routing. `ScreenshotCapture` owns the capture/write/proof workflow reached by those hotkeys.
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) is the canonical owner of all three capture methods. [UID:0000OC][Surface](by-file/Surface.md) and GrafPort supply inherited render-surface helpers and fields.
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md) and [UID:0000KW][LodePNG](by-file/LodePNG.md) own PNG writing backend code; this class only decides when and where to write a screenshot.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) own packet serialization and queued send dispatch.

## Data Caveats

- Capture fields are reconciled to the accepted ScreenPane/GrafPort layout: inherited `LPDIRECTDRAWSURFACE m_ddSurface` at `+0x18`, inherited `m_surfaceContext` pixel/stride/bounds state beginning at `+0x20`, and ScreenPane `LPDIRECTDRAWSURFACE m_renderSurface` at `+0x108`. They are not ScreenshotCapture-object fields or numeric surface IDs.
- IDA does not model the raw JPG path at `0x00557840` as a function start and still reports no direct modeled caller for that raw start, so use [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) as the address-level ownership anchor.
- 2026-06-04 live IDA MCP recheck: `0x00557840` remains not modeled as a function, while adjacent setters at `0x00557820-0x00557828` and `0x00557830-0x00557838` are modeled 8-byte functions with callers at `0x004f8a8e` and `0x00504849`.
- The class page stays as the `ScreenshotCapture.cpp` source-family index. The source-shape decision is closed: capture declarations belong to ScreenPane; proof declaration/definition are file-local in ScreenshotCapture.cpp.
- B005 source-quality reanalysis ranks `ScreenPane::SaveScreenshotJPG/BMP/PNG` as the best current source-facing method family because EventDispatcher calls modeled BMP/PNG with [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) in `ecx`, the retained JPG body preserves a thiscall-style receiver, and the touched offsets match ScreenPane/surface state. `ScreenshotCapture::SaveScreenshotJPG` is rejected unless a future pass proves a concrete object lifecycle for this page.
- `SendScreenshotProofPacket` remains ScreenshotCapture-owned because all three callers are local capture paths and the payload is screenshot-specific; MD5, PacketBuffer, and Socket remain dependencies only.

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled function boundaries: BMP capture `0x00557aa0-0x00557e73`, PNG capture `0x00557e80-0x00558239`, and proof helper `0x00558240-0x00558391`.
- IDA xrefs show BMP capture callers at `0x004a71b6` and `0x004a7250` inside `EventDispatcher::RouteEventToHandlers` (`0x004a7130`), and PNG capture callers at `0x004a71d1` and `0x004a7296` in the same function.
- The raw JPG body at `[0x00557840,0x00557a96)` remains unmodeled but has live xrefs/calls inside the raw span: JPEG writer call `0x005579d3 -> 0x004efbc0`, fixed-`0x78` secure-format support call `0x00557a08 -> 0x00559af0`, chat/status append `0x00557a48 -> 0x0047f280`, and proof call `0x00557a78 -> 0x00558240`.
- The modeled BMP/PNG paths share the same status/proof pattern: BMP calls non-emitting fixed-`0x78` secure-format support `0x00559af0`, `0x0047f280`, and `0x00558240` at `0x00557de4`, `0x00557e24`, and `0x00557e55`; PNG calls them at `0x005581a6`, `0x005581e6`, and `0x0055821b`.
- 2026-07-05 B001 UID00023T reclassification: [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) is not a `ScreenshotCapture` runtime class method or emitted source helper. It is MSVC/UCRT secure wide-format support consumed by caller-local saved-status formatting; the class/source-family page should preserve ScreenshotCapture as consumer context only.
- PNG capture calls the LodePNG front end at `0x0055817b -> 0x00443e40`; the raw JPG path calls the JPEG writer at `0x005579d3 -> 0x004efbc0`.
- Proof helper data refs at `0x006232e0`, `0x00623300`, and `0x006232f0` resolve to one pooled key item `[0x006232e0,0x00623301)` containing the exact 32-character literal plus NUL. They are compiler materialization refs for local `char proofMask[36]`, whose remaining indices `33..35` are zero-initialized; only indices `0..31` are XORed. The helper queues the final packet through sender global `0x0067a7ec` and call `0x00558370 -> 0x00574bb0`.
- 2026-06-11 B001 follow-up decompiled `0x004a7130` again and reconfirmed `dword_67A7CC` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) is the screenshot receiver for BMP calls at `0x004a71b6` / `0x004a7250` and PNG calls at `0x004a71d1` / `0x004a7296`.
- 2026-06-11 B001 raw-reference scan found no absolute pointer and no direct rel32 call/jump targeting the raw JPG start `0x00557840`, but raw xrefs reconfirmed the JPG path calls to `0x004b9820`, `0x0046bfd0`, `0x004efbc0`, `0x004b98c0`, `0x00559af0`, `0x0047f280`, and `0x00558240`.
- 2026-06-11 B001 proof-helper decompilation established opcode `0x83`, XOR key, 16 inserted random bytes, 49-byte send, and digest free. The 2026-07-24 instruction-level closure refines the inserted bytes to first-byte `(rand() % 10) - 26` plus 15 bytes of `rand() % 255`, and proves the local byte-49 terminator is not sent.
- 2026-06-20 B005 source-quality reanalysis resolved the raw JPG target's first-draft source shape as retained `ScreenPane::SaveScreenshotJPG()` under [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), with exact pre/body/post boundaries, no absolute/direct rel32 route, `.jpg` formatting, [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) call, status/proof parity, and descriptive field/global/helper names.
- Remaining uncertainty is original identifier/file capitalization only. It does not justify a concrete class, raw labels, or blank child C++. Class-level reconstruction remains blank because this page is intentionally non-emitting; exact method/helper bodies belong to the by-memory children.

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md)
- [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md)
- [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## UID0003CJ Compiler-Pool Evidence

[UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) closes the physical source of the screenshot/proof literals without creating a `ScreenshotCapture` class or data object. The directory/BMP/status/JPG/PNG items occupy `0x0062317c-0x006232e0`; the proof mask is one 33-byte local-initializer item at `[0x006232e0,0x00623301)` containing exactly 32 literal characters plus NUL. The current saved IDB names that item `ScreenshotProofMaskLiteral` and types it `const char[33]`; the former vectorized xmmword/byte heads are historical analysis splits. Exact direct refs route those values to UID0001G8/UID0004WM/UID0004WN/UID0004WO.

Source remains the existing file-level organization: three `ScreenPane` member definitions plus file-local `SendScreenshotProofPacket` in ScreenshotCapture.cpp. The exact source is local `char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";`: literal characters occupy indices `0..31`, its NUL occupies index `32`, aggregate initialization supplies three additional zero bytes at indices `33..35`, and only indices `0..31` are XORed. All wide strings remain inline, and no static data member, literal table, resource object, or generated raw pool is justified. Because later UID0003CJ bytes are consumed by ScreenPane cursor and Surface helpers, this non-class page cannot own the aggregate. Preserve this historical/non-emitting class page at `91/93` and its current owner/file relationship.

## Changes

- 2026-07-24 B001 UID0003CJ support synchronization: preserved `91/93`, owner UID0000ND, false/non-emitting metadata, and existing workflow evidence; added exact screenshot/proof pool boundaries, local/inline source shape, cross-module ownership rejection, and no-static-class-data conclusion.

- 2026-07-24 B004 UID0001G9 drift reconciliation: preserved `91/93`, false/non-emitting source-family metadata, exact screenshot child routing, and all UID0003CJ evidence; replaced the stale current-three-head description with the applied one-item `ScreenshotProofMaskLiteral` readback while retaining the historical split as rejected analysis history.

- 2026-07-24 B004 focused C1G9-023 callback: completed the class-level proof-mask evidence with the exact 32-character/33-byte-pool/36-byte-local distinction, three additional zero-initialized local bytes, and 32-byte XOR bound.

- 2026-07-24 B004 UID0001G9 implementation callback: raised `86/88 -> 91/93`, reclassified this page `RECONSTRUCTABLE:FALSE` with blank emitters/C++, closed the no-concrete-class proof, linked corrected JPG and exact children UID0004WM/UID0004WN/UID0004WO, resolved ScreenPane receiver fields and file-local proof ABI, preserved historical alternatives as rejected evidence, and made this page an all-encompassing non-emitting ScreenshotCapture.cpp family index.

- 2026-07-05 B001 UID00023T implementation callback: updated the JPG/BMP/PNG status-formatting evidence to treat [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md) as non-emitting fixed-`0x78` MSVC/UCRT support consumed by ScreenshotCapture paths, not as a ScreenshotCapture class method or emitted helper body.
- 2026-06-20 B005 JPG source-shape sync: raised `85/86 -> 86/88`, documented `ScreenshotCapture` as a source-family owner rather than a proven runtime class, changed the method inventory to preferred `ScreenPane::SaveScreenshotJPG/BMP/PNG`, and recorded the retained/no-direct-caller JPG caveat plus the rejection of `ScreenshotCapture::SaveScreenshotJPG` until a concrete object lifecycle is proven. Class-level C++ remains blank because [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) now carries the method-body draft.
- 2026-05-30: Changed completion/confidence from `0/0` to `78/76`.
  - Before: The page was unevaluated despite documenting BMP/PNG/JPG capture paths, screenshot proof packet behavior, ownership caveats, and data defects.
  - After: Scored as moderate-high completion and confidence because the workflow and module ownership are clear, while class-vs-free-helper shape and the raw JPG path remain unresolved.
  - Evidence: Existing method table, ownership notes, data caveats, IDA recheck notes, and image/network/surface cross-references support the score.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).
  - Summary/evidence: live IDA MCP confirms BMP/PNG/proof function boundaries, EventDispatcher hotkey callers, raw JPG writer/status/proof calls, modeled BMP/PNG status/proof calls, PNG/JPEG writer dependencies, proof XOR key refs, packet sender call, adjacent setter stubs, and raw JPG liveness caveat; parent file [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) is already `88/80` with valid `NexusTK/render/` placement.
  - Remaining gaps: final C++ remains blank because class-vs-free-function shape, the screen/surface `this` layout, helper names, and raw JPG reachability are not yet at the 95/95 threshold.
- 2026-06-11 B001 deeper follow-up: raised `82/84 -> 85/86` after repairing the [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) parent to `88/86`, repairing the two screenshot children in [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), and recording the current EventDispatcher/JPG/proof evidence. This clears the current strict class/file parent gate while keeping final C++ blank for source-shape uncertainty.
