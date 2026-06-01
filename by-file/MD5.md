*** UID:0000L6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MD5

## Status

- Confidence: strong for algorithm and helper grouping; medium for exact original filename/folder.
- Proposed module: `NexusTK/util/MD5.cpp`
- Current Wave3 files: no dedicated recovered MD5 source file; callers reference raw `sub_515xxx` helpers or the generated `ComputePacketDigest` name in `class_Socket.cpp`.
- Main address doc: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- Related item doc: [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- Raw helper docs: [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) and [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md)
- Evidence basis: `simroot_v2` generated callers plus IDA MCP lookup/xref/decompile/instruction checks on 2026-05-24, 2026-05-25, and 2026-05-31. `wave3.py` was not executed for this pass.

## Hypothesis

The original client likely had a small shared MD5 utility module rather than packet-local digest code. The helper island initializes the standard MD5 state constants, applies 64-byte transforms, finalizes with MD5 padding and bit-count handling, and exposes one-shot wrappers for strings, byte buffers, file paths, and open `FILE*` streams.

This should not be folded into [UID:0000M9][PacketTransform](by-file/PacketTransform.md). `Socket::BuildEncryptedPacket` consumes one raw digest wrapper at `0x00515380`, but the same MD5 family is also used by startup/minimap update handling and screenshot proof packet generation.

## Contents

Likely source-level contents:

| Address | Proposed name | Role |
| --- | --- | --- |
| `0x005151f0-0x00515284` | `Md5DigestToHexString` | Formats a 16-byte digest as a lowercase 32-byte hex string and returns a heap copy. |
| `0x00515290-0x0051530a` | `Md5StringHex` | Hashes a NUL-terminated ANSI string and returns a heap hex string. |
| `0x00515310-0x00515375` | [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) | Raw unmodeled helper that hashes a byte buffer and returns a heap hex string. |
| `0x00515380-0x005153dc` | `Md5BytesRaw` / `ComputePacketDigest` | Hashes a byte buffer and returns raw digest bytes consumed by packet encoding. |
| `0x005153e0-0x00515445` | `Md5BytesToBuffer` | Hashes a byte buffer and copies the 16-byte digest into a caller-supplied output buffer. |
| `0x00515450-0x00515568` | [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) | Raw unmodeled helper that opens a path in binary mode, hashes file contents, and returns a heap hex string. |
| `0x00515570-0x0051565b` | `Md5StreamHex` | Hashes an existing `FILE*` stream in 1024-byte chunks and returns a heap hex string. |
| `0x00515690-0x00515744` | `Md5Update` | Updates bit count, buffers partial blocks, and calls the transform helper on full blocks. |
| `0x00515750-0x00515831` | `Md5Final` | Appends padding and bit length, emits the digest, and clears context storage. |
| `0x00515840-0x00515f48` | `Md5Transform` | MD5 compression transform with the standard constants and rotation schedule. |
| [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md) | `Md5Encode` / `Md5Decode` candidates | Raw little-endian byte/word conversion helpers; no current direct xrefs. |

## Evidence

- IDA decompilation of the one-shot wrappers initializes `0x67452301`, `0xefcdab89`, `0x98badcfe`, and `0x10325476`.
- `Md5Update` tracks the 64-bit input bit count at context offsets `0x10` and `0x14`, keeps a 64-byte staging buffer near context offset `0x18`, and calls `Md5Transform` for complete blocks.
- `Md5Final` appends MD5 padding from the static padding table near `0x0066ddd8`, appends the 8-byte bit length, writes the 16-byte digest, and clears the context.
- `Md5Transform` contains the expected 64-step MD5 compression constants and rotate/add/xor patterns.
- `Md5DigestToHexString` formats each digest byte with `%02x`, appends into a local buffer, and returns `_strdup(Source)`.
- IDA xrefs show `Md5BytesRaw` at `0x00515380` is only called by `Socket::BuildEncryptedPacket`.
- IDA xrefs show `Md5StringHex` at `0x00515290` is called from `StartupWindow::RunUpdateCheck` and a network/key-material function around `0x00575c30`.
- IDA xrefs show `Md5BytesToBuffer` at `0x005153e0` is called from [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) at `0x004928ba`, where it writes a 16-byte digest buffer during registry/CLSID setup.
- `simroot_v2/recovered/SendScreenshotProofPacket_00558240.cpp` calls `sub_515570`, matching the `Md5StreamHex` wrapper.
- The 2026-05-31 IDA MCP recheck confirmed the modeled helper starts and sizes still match this split: `sub_5151F0` (`0x94`), `sub_515290` (`0x7a`), `sub_515380` (`0x5c`), `sub_5153E0` (`0x65`), `sub_515570` (`0xeb`), `sub_515690` (`0xb4`), `sub_515750` (`0xe1`), and `sub_515840` (`0x708`). It also reconfirmed that `0x00515310`, `0x00515450`, `0x00515f50`, and `0x00515fa0` are raw function-shaped starts with no IDA function object, and that the MD5 padding block at `0x0066ddd8` is referenced from `Md5Final` at `0x005157bb`.

## Ownership Decision

Use `util/MD5.cpp` as the reconstruction owner. The helper family has no class state, is used across startup, network, and screenshot proof paths, and is algorithm-specific enough to deserve a separate utility file.

`network/PacketTransform.cpp` should call into this module for packet trailer digest bytes but should not own the MD5 implementation. `app/StartupWindow.cpp` and the [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md) should also depend on this utility module.

## Caveats

- IDA currently does not materialize function objects for the raw starts at `0x00515310` and `0x00515450`, even though disassembly shows complete helper bodies there. The 2026-05-25 xref check found no direct refs to those starts, so treat them as unmodeled possibly-unused utility wrappers until a broader binary/codegen pass says otherwise.
- `Md5BytesRaw` decompiles as returning a pointer to transient digest storage. Preserve the packet behavior when rewriting, but review the raw assembly before choosing the final safe C++ signature.
- The adjacent [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) are not part of this MD5 module despite address proximity.

## Cross-References

- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md)
- [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md)
- [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: MD5 utility hypothesis, one-shot wrappers, raw helpers, transform/update/final behavior, caller evidence, ownership decision, caveats, and network/screenshot/startup refs are documented; confidence is capped by raw unmodeled helper starts and final original filename/folder uncertainty.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `MD5.cpp` under `util`, and the current IDA MCP recheck confirms a cross-subsystem MD5 helper island rather than ownership by packet, startup, registry, or screenshot modules.
