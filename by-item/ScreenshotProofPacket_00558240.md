*** UID:0000VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ND | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Screenshot Proof Packet - 0x00558240

## Status

- Confidence: strong for behavior; medium for final owner name.
- Autogen parent: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Memory range: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- Evidence basis: live IDA MCP caller/callee/xref/decompile/disassembly checks.
- Rebuild handling: `source-authored` screenshot anti-cheat/proof helper. It should be rebuilt through screenshot-capture source, but C++ is blank until packet helpers, MD5 ownership, and surrounding screenshot paths are near-final.

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
- 2026-05-31 IDA MCP recheck reports function `sub_558240` with exclusive end `0x00558391`, code references from `0x00557a78`, `0x00557e55`, and `0x0055821b`, and callees `0x00515570`, `0x00516030`, `0x00575380`, `0x00516220`, `_rand`, `0x00574bb0`, and `free`. Data refs include the XOR key constants at `0x006232e0`, `0x00623300`, and `0x006232f0`.

Rechecked with live IDA MCP on 2026-06-03:

- `lookup_funcs` reports `sub_558240` as an exact modeled function at `0x00558240-0x00558391`. `0x00558391` is not a function start and `0x005583a0` starts the next modeled function.
- `lookup_funcs` reports modeled screenshot callers at `0x00557aa0-0x00557e73` and `0x00557e80-0x00558239`; `0x00557840` and `0x00557a78` remain raw/non-function starts for the adjacent JPG path.
- `xrefs_to 0x00558240` reports exactly three code references: raw JPG call `0x00557a78`, BMP call `0x00557e55`, and PNG call `0x0055821b`.
- Decompilation confirms `0x00558240` copies the fixed key `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE`, calls the MD5 stream helper `0x00515570(Stream)`, XORs 32 digest bytes, initializes packet state, writes opcode `0x83` through `0x00575380`, copies 13 masked bytes, fills 16 random pad bytes, copies the remaining 19 masked bytes, writes a zero terminator, queues 49 bytes through `0x00574bb0(dword_67A7EC, packet, 49)`, and frees the digest allocation.
- Callee enumeration confirms the proof helper calls `0x00515570`, `0x00516030`, `0x00575380`, `0x00516220`, `_rand`, `0x00574bb0`, `free`, and the stack-cookie check.
- Data xrefs from the proof helper hit the XOR key fragments at `0x006232e0`, `0x00623300`, and `0x006232f0`, plus packet sender state `dword_67A7EC`.
- Raw disassembly around `0x00557a78` confirms the JPG path opens the saved file with `"rb"`, passes that stream to `0x00558240`, then closes it. That makes the raw JPG xref a real third proof-submit path even though IDA does not model `0x00557840` as a function.
- Parent evidence: the proof helper is contained in the `ScreenshotCaptureAndProof` aggregate, is called by BMP/PNG screenshot functions and the adjacent raw JPG screenshot path, consumes screenshot file streams, and emits the screenshot-specific proof packet. The [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) parent is strong enough for autogen attachment.

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
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while C++ remains blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, three callsites, MD5/packet/random/free callees, and digest-mask constants. The score remains below 95 because final source-quality C++ depends on fully audited packet, MD5, and screenshot-path ownership.
- 2026-06-03 update: live IDA MCP rechecked the exact function boundary, modeled BMP/PNG callers, raw JPG callsite, MD5/hash-mask/packet/random/free callees, XOR key xrefs, packet sender state, and raw JPG open/proof/close sequence. Completion increased from 70 to 84 and confidence from 85 to 90 because the owner, three proof-submit paths, packet layout, and key/data dependencies are now documented from current IDA evidence and the item is safely attached to `ScreenshotCapture`. The score remains below 95 because final source helper names and packet/request field names are not fully proven.
