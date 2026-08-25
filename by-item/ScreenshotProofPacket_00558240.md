*** UID:0000VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ND | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ND | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall SendScreenshotProofPacket(FILE *stream);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Screenshot Proof Packet - 0x00558240

## Status

- Confidence: very strong for exact ABI, behavior, packet layout, all three callers, owner/source route, and declaration-versus-definition placement.
- Autogen parent: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Exact implementation: [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md); containing range index: [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md).
- Evidence basis: live IDA MCP caller/callee/xref/decompile/disassembly checks.
- Rebuild handling: declaration/index role for a source-authored file-local proof helper. This page emits only `static void __stdcall SendScreenshotProofPacket(FILE *stream);` at ScreenshotCapture.cpp position `5`; exact child UID0004WO emits the sole definition at position `40`.
- Source-channel disposition: the file-local forward declaration remains CPP-only and H remains exactly blank. Publishing it in H would incorrectly expose an internal helper and duplicate the declaration already ordered in `ScreenshotCapture.cpp`.

## Function Role

`0x00558240` builds the client screenshot proof packet. It does not transmit image pixels. The saved screenshot file is reopened by the caller, hashed locally, transformed into a masked digest payload, and sent as opcode `0x83`.

Accepted source-facing name and ABI are `static void __stdcall SendScreenshotProofPacket(FILE *stream)`. This is a high-probability human-source reconstruction from the exact stack ABI, `retn 4`, no receiver, three local callers, and screenshot-specific payload role; raw address suffixes do not belong in final source.

## Behavior

- Input: open `FILE*` for the saved screenshot file.
- Calls [UID:0000L6][MD5](by-file/MD5.md) stream helper `0x00515570` to get a 32-byte lowercase hex digest string.
- Materializes the exact 32-character key `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE` as local `char proofMask[36]`. IDA stores the 32 literal bytes plus NUL as one 33-byte pooled item `[0x006232e0,0x00623301)`; C++ aggregate initialization supplies three additional zero-initialized local bytes at indices `33..35`. Only digest/mask indices `0..31` are XORed.
- Starts a packet with [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) byte writer `0x00575380` and opcode `0x83`.
- Copies 13 masked digest bytes, writes the first padding byte as `(rand() % 10) - 26`, writes the remaining 15 as `rand() % 255`, copies the remaining 19 masked digest bytes, stores a local zero at byte 49, and queues exactly 49 bytes through `CashShopRequest::QueueAndSendPacket` at `0x00574bb0` using [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`. The local terminator is not transmitted.
- Frees the digest string after queuing the packet.

## Caller Evidence

- IDA callers show two modeled function callers: `SaveScreenshotBMP` at `0x00557aa0` and `SaveScreenshotPNG` at `0x00557e80`.
- 2026-05-26 IDA `xrefs_to 0x00558240` also reports a raw code xref at `0x00557a78`, inside the unmodeled JPG screenshot path at `0x00557840-0x00557a95`.
- 2026-05-31 IDA MCP recheck reports function `sub_558240` with exclusive end `0x00558391`, code references from `0x00557a78`, `0x00557e55`, and `0x0055821b`, and callees `0x00515570`, `0x00516030`, `0x00575380`, `0x00516220`, `_rand`, `0x00574bb0`, and `free`. Data refs include the XOR key constants at `0x006232e0`, `0x00623300`, and `0x006232f0`.

Rechecked with live IDA MCP on 2026-06-03:

- `lookup_funcs` reports `sub_558240` as an exact modeled function at `0x00558240-0x00558391`. `0x00558391` is not a function start and `0x005583a0` starts the next modeled function.
- `lookup_funcs` reports modeled screenshot callers at `0x00557aa0-0x00557e73` and `0x00557e80-0x00558239`; `0x00557840` and `0x00557a78` remain raw/non-function starts for the adjacent JPG path.
- `xrefs_to 0x00558240` reports exactly three code references: raw JPG call `0x00557a78`, BMP call `0x00557e55`, and PNG call `0x0055821b`.
- Decompilation confirms `0x00558240` copies the fixed key `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE`, calls the MD5 stream helper `0x00515570(Stream)`, XORs 32 digest bytes, initializes packet state, writes opcode `0x83` through `0x00575380`, copies 13 masked bytes, fills 16 random pad bytes, copies the remaining 19 masked bytes, writes a zero terminator, queues 49 bytes through `0x00574bb0` with [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC` as the receiver, and frees the digest allocation.
- Current IDA readback consolidates the former three XOR-key heads into one `ScreenshotProofMaskLiteral` item `[0x006232e0,0x00623301)`, typed `const char[33]`. That physical item is exactly the 32-character literal plus NUL; it is compiler-pooled evidence for the inferred local `char proofMask[36]`, not a source global. The local array's indices `33..35` are three additional zero-initialized bytes, and the helper XORs only indices `0..31`.
- Callee enumeration confirms the proof helper calls `0x00515570`, `0x00516030`, `0x00575380`, `0x00516220`, `_rand`, `0x00574bb0`, `free`, and the stack-cookie check.
- Data xrefs from the proof helper hit the XOR key fragments at `0x006232e0`, `0x00623300`, and `0x006232f0`, plus packet sender state [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`.
- Raw disassembly around `0x00557a78` confirms the JPG path opens the saved file with `"rb"`, passes that stream to `0x00558240`, then closes it. That makes the raw JPG xref a real third proof-submit path even though IDA does not model `0x00557840` as a function.
- Parent evidence: the proof helper is contained in the `ScreenshotCaptureAndProof` aggregate, is called by BMP/PNG screenshot functions and the adjacent raw JPG screenshot path, consumes screenshot file streams, and emits the screenshot-specific proof packet. The [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) parent is strong enough for autogen attachment.

2026-06-16 A001 refresh:

- Live IDA MCP `lookup_funcs` reconfirmed `sub_558240` at `0x00558240`, size `0x151`, while `0x00557840` remains not a modeled function start.
- Live `analyze_function 0x00558240` reports decompilation for a `FILE*` stream input, copies the same fixed XOR key, calls `sub_515570` / [UID:0000L6][MD5](by-file/MD5.md) `Md5StreamHex`, handles overlap/non-overlap XOR paths over 32 bytes, initializes packet state, writes opcode `0x83` through `0x00575380`, copies 13 masked bytes, fills 16 random bytes, copies 19 masked bytes, writes a zero terminator, queues 49 bytes through `0x00574bb0(dword_67A7EC, packet, 49)`, and frees the digest allocation.
- The same live check reports ordinary modeled callers only from BMP and PNG, while xrefs include the raw JPG callsite at `0x00557a78`. This preserves the documented raw-JPG reachability caveat without weakening `ScreenshotCapture` ownership.
- Support pages checked: [UID:0000L6][MD5](by-file/MD5.md) documents `Md5StreamHex` at `0x00515570`; [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) owns packet scalar writers such as `0x00575380`; [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) owns `dword_67A7EC`; [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns the screenshot workflow and raw JPG/BMP/PNG proof paths.

## Ownership Decision

Keep this helper with [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), not with [UID:0000L6][MD5](by-file/MD5.md), [UID:0000M9][PacketTransform](by-file/PacketTransform.md), or [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). It consumes those lower-level modules but owns screenshot-specific proof-payload layout.

## Source-Quality Questions Resolved

- Packet and MD5 roles: checked MD5, PacketBuffer, packet sender, and ScreenshotCapture support docs. Their lower-level ownership is stable; the screenshot-specific packet layout stays in the file-local helper.
- Reachability: exact xrefs include raw JPG plus modeled BMP/PNG. The raw JPG start remains unmodeled, but its direct call at `0x00557a78` is real and does not weaken proof-helper placement.
- Return/source shape: current IDA prototype is `void __stdcall(FILE *Stream)`, the body consumes no receiver, and `retn 4` proves callee cleanup. The helper is therefore a file-local `static void __stdcall` function, not a class method.
- Declaration/definition split: this semantic item emits only the forward declaration at position `5`; [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) emits the only body at position `40`.
- Proof-mask storage: the human-source form is exactly local `char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";`. The 32-character literal, its pooled NUL, the local array's three additional trailing zeros, and the 32-byte XOR loop are distinct facts; none justifies a separate key object or emitter.

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- 2026-07-24 B004 UID0001G9 implementation callback: raised `86/90 -> 92/94`, set emitter position `5`, added the exact file-local stdcall forward declaration, linked sole-definition child UID0004WO, resolved helper ABI/source shape, documented asymmetric random padding and unsent local terminator, and replaced blank-C++ blockers with the accepted no-duplicate declaration/definition route.

- 2026-07-24 B004 focused C1G9-023 callback: added the complete proof-mask storage distinction: 32 literal characters, one 33-byte pooled item including NUL, local `char[36]` with three additional zero-initialized bytes, and XOR-only indices `0..31`.

- 2026-06-07: Replaced raw screenshot-proof packet sender references with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the proof packet behavior and decompilation evidence used historical `dword_67A7EC` for the queue/send receiver.
  - After: the page links the resolved packet sender while retaining the historical label and exact 49-byte send shape.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and this page's existing live IDA evidence ties the screenshot proof helper to `0x00574bb0(..., packet, 49)`.

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while C++ remains blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, three callsites, MD5/packet/random/free callees, and digest-mask constants. The score remains below 95 because final source-quality C++ depends on fully audited packet, MD5, and screenshot-path ownership.
- 2026-06-03 update: live IDA MCP rechecked the exact function boundary, modeled BMP/PNG callers, raw JPG callsite, MD5/hash-mask/packet/random/free callees, XOR key xrefs, packet sender state, and raw JPG open/proof/close sequence. Completion increased from 70 to 84 and confidence from 85 to 90 because the owner, three proof-submit paths, packet layout, and key/data dependencies are now documented from current IDA evidence and the item is safely attached to `ScreenshotCapture`. The score remains below 95 because final source helper names and packet/request field names are not fully proven.
- 2026-06-16 A001 Goal 2 refresh: completion raised from `84` to `86`; confidence stays `90`. Live IDA MCP reconfirmed the proof helper boundary, three proof xrefs, MD5 stream helper, opcode `0x83` packet layout, random pad span, `g_packetSender` queue call, and dependency-owner split. Final C++ remains blank because source helper spelling, packet-buffer local type, return type, and raw JPG source shape are not final.
