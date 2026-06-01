*** UID:0000VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Screenshot Proof Packet - 0x00558240

## Status

- Confidence: strong for behavior; medium for final owner name.
- Proposed owner: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Memory range: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- Evidence basis: generated `SendScreenshotProofPacket_00558240.cpp` plus read-only IDA MCP caller/callee/xref checks on 2026-05-24 and 2026-05-26. `wave3.py` was not executed for this pass.
- Rebuild handling: `source-authored` screenshot anti-cheat/proof helper. It should be rebuilt through screenshot-capture source, but parent attachment and C++ are blank until packet helpers, MD5 ownership, and surrounding screenshot paths are near-final.

## Function Role

`0x00558240` builds the client screenshot proof packet. It does not transmit image pixels. The saved screenshot file is reopened by the caller, hashed locally, transformed into a masked digest payload, and sent as opcode `0x83`.

## Behavior

- Input: open `FILE*` for the saved screenshot file.
- Calls [UID:0000L6][MD5](by-file/MD5.md) stream helper `0x00515570` to get a 32-byte lowercase hex digest string.
- XORs digest bytes with fixed key `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE`.
- Starts a packet with [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) byte writer `0x00575380` and opcode `0x83`.
- Copies 13 masked digest bytes, writes 16 random pad bytes, copies the remaining 19 masked digest bytes, appends a zero terminator, and queues 49 bytes through `CashShopRequest::QueueAndSendPacket` at `0x00574bb0`.
- Frees the digest string after queuing the packet.

## Caller Evidence

- IDA callers show two modeled function callers: `SaveScreenshotBMP` at `0x00557aa0` and `SaveScreenshotPNG` at `0x00557e80`.
- 2026-05-26 IDA `xrefs_to 0x00558240` also reports a raw code xref at `0x00557a78`, inside the unmodeled JPG screenshot path at `0x00557840-0x00557a95`.
- `simroot_v2/recovered/SendScreenshotProofPacket_00558240.cpp` matches the IDA caller/callee shape and records the final semantic name from earlier Wave2 review.
- 2026-05-31 IDA MCP recheck reports function `sub_558240` with exclusive end `0x00558391`, code references from `0x00557a78`, `0x00557e55`, and `0x0055821b`, and callees `0x00515570`, `0x00516030`, `0x00575380`, `0x00516220`, `_rand`, `0x00574bb0`, and `free`. Data refs include the XOR key constants at `0x006232e0`, `0x00623300`, and `0x006232f0`.

## Ownership Decision

Keep this helper with [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), not with [UID:0000L6][MD5](by-file/MD5.md), [UID:0000M9][PacketTransform](by-file/PacketTransform.md), or [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). It consumes those lower-level modules but owns screenshot-specific proof-payload layout.

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, three callsites, MD5/packet/random/free callees, and digest-mask constants. The score remains below 95 because final source-quality C++ depends on fully audited packet, MD5, and screenshot-path ownership.
