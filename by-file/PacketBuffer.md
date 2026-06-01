*** UID:0000M8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PacketBuffer

## Status

- Confidence: strong for utility-module role, medium for exact original filename.
- Proposed module: `network/PacketBuffer.cpp`
- Current Wave3 files: recovered single-global files named `PacketBuffer_*.cpp`
- Main address docs: [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- Supporting item doc: [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md)
- Evidence basis: `simroot_v2` recovered global files, Wave3 xrefs, and IDA MCP lookup/xref checks on 2026-05-23.

## Hypothesis

The original client likely had a small packet-buffer utility source file, or a packet/protocol utility file, containing C-style helpers for big-endian integer read/write, cursor-based appends, and length-prefixed string serialization. These helpers are not methods of `Socket` even though they sit in the same address neighborhood as socket transport code.

`PacketBuffer.cpp` is a better reconstruction target than leaving each helper as an independent recovered file.

## Contents

Likely source-level contents:

- Byte, `uint16`, and `uint32` big-endian write helpers with a trailing zero byte.
- Big-endian `uint16` and `uint32` read helpers.
- Cursor-based append/read helpers.
- Length-prefixed ANSI and wide-to-ANSI string serialization helpers.
- Length-prefixed string read helper.
- Two-byte length-prefixed packet byte/string read helpers.
- Packet nonce/XOR-key initialization belongs with [UID:0000M9][PacketTransform](by-file/PacketTransform.md), not this scalar packet-buffer module.

## Evidence

- IDA MCP confirms exact helper function starts from `0x00575380` through `0x00575a90`.
- IDA xrefs show broad helper use across the binary:
  - `WriteByteZ_575380`: 1114 code refs from 662 unique calling functions.
  - `WriteUInt16BEZ_5753A0`: 222 refs from 163 unique functions.
  - `WriteUInt32BEZ_5753F0`: 119 refs from 98 unique functions.
  - `ReadUInt16BE_575480`: 372 refs from 143 unique functions.
  - `ReadUInt32BE_5754C0`: 226 refs from 98 unique functions.
- The helper bodies are stateless scalar formatting/parsing routines, while `Socket` is stateful transport/framing code.
- `PacketWriteWideString_575850` has only six code refs, but it follows the same length-prefixed packet string contract and calls string conversion/destruction helpers.

## Proposed Placement

```text
network/
  PacketBuffer.h
  PacketBuffer.cpp
```

This module should expose small inline or free helper functions used by feature packet builders, `CashShopRequest` send preparation, and socket decode paths. It should not own feature-specific packet opcodes.

## Open Questions

- Whether the original names were `PacketBufferWriteByte`, `PacketBufferWriteUInt16BE`, and similar, or shorter internal helper names.
- Whether the trailing zero byte is a null terminator convention for queue buffers, a safety byte for string-based send paths, or just a common packet-builder pattern.
- Whether any cursor/string helper names can be recovered from nearby call-site semantics.

## Cross-References

- [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the utility-module hypothesis, helper families, IDA xref scale, socket/transform boundaries, placement, open questions, and cross-references; confidence remains capped by original helper names and exact filename uncertainty.
