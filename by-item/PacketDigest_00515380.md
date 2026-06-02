*** UID:0000V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Packet Digest Helper - 0x00515380

## Status

- Confidence: strong for behavior and parent ownership; medium for final source signature and returned-buffer lifetime.
- Proposed owner: [UID:0000L6][MD5](by-file/MD5.md), not [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- Memory range: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- Evidence basis: existing IDA MCP lookup/xref/decompile/callee records in the MD5 and Socket memory pages through 2026-06-01, plus local Socket documentation. Live IDA MCP did not respond during the 2026-06-02 continuation, so this page does not claim a fresh recheck.

## Function Role

`0x00515380` is the packet-facing one-shot MD5 helper. It hashes a byte buffer, finalizes the digest, and returns raw digest bytes to `Socket::BuildEncryptedPacket`.

The packet code does not use the full hex digest. It inserts digest bytes `[13]`, `[3]`, `[11]`, and `[7]` into the encrypted packet trailer, followed by the obfuscated packet nonce/key bytes.

## IDA Evidence

Existing IDA MCP records in [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) identify `0x00515380` as function `sub_515380`, size `0x5c`, ending half-open at `0x005153dc`. The adjacent modeled helper `sub_5153E0` starts at `0x005153e0`, leaving a four-byte `0xcc` alignment gap at `0x005153dc-0x005153df`.

The narrow helper performs the raw-digest variant of the MD5 one-shot wrappers:

| Address / callee | Evidence | Meaning |
| --- | --- | --- |
| `0x00515380-0x005153dc` | IDA function `sub_515380`, size `0x5c` | Packet-facing raw byte digest helper. |
| MD5 constants | Decompilation initializes `0x67452301`, `0xefcdab89`, `0x98badcfe`, and `0x10325476` | Standard MD5 initial state. |
| `0x00515690` | Called by the wrapper | [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) documents this as `Md5Update`. |
| `0x00515750` | Called after update | Documented as `Md5Final`; emits the 16-byte digest. |
| security-cookie check | Listed by the 2026-05-31 item evidence | Compiler epilogue artifact, not MD5 logic. |

## Caller Evidence

IDA xrefs documented in the MD5 helper page show one direct caller for this helper: [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md). That caller is a Socket method, not packet-transform utility code.

The Socket page records the specific trailer behavior:

| Caller operation | Evidence | Result |
| --- | --- | --- |
| Call to `0x00515380` | `SocketBuildEncryptedPacket` calls this helper at `0x00578da5`. | Computes MD5 over the outbound transformed packet bytes. |
| Input length | Socket page documents digest over `output` length `inputLength + 1`. | Includes the packet sequence/control byte in the digest input. |
| Digest byte selection | Socket page documents copies from digest bytes `[13]`, `[3]`, `[11]`, and `[7]`. | Only four raw MD5 bytes are appended; no hex string is used. |
| Trailer placement | Socket page documents digest bytes before obfuscated nonce bytes. | Ties the helper to outbound packet framing, not a general hex API. |

## Placement In MD5 Helper Island

`0x00515380` sits among the one-shot MD5 wrappers:

| Range | Current role |
| --- | --- |
| `0x00515290-0x0051530a` | `Md5StringHex`, string-to-hex wrapper. |
| `0x00515310-0x00515375` | Raw `Md5BytesHex` body with no current IDA function object. |
| `0x00515380-0x005153dc` | This packet-facing raw digest wrapper. |
| `0x005153e0-0x00515445` | `Md5BytesToBuffer`, caller-output-buffer digest wrapper. |

The placement and shared callees make `MD5.cpp` the correct reconstruction parent even though the only direct executable caller is Socket packet framing.

## Ownership Decision

Keep this helper in the shared [UID:0000L6][MD5](by-file/MD5.md) module. `PacketTransform` owns the handshake/key-table setup and repeated-key XOR primitive, but the digest implementation is shared algorithm code with callers outside the socket transform path.

The source-facing name should probably be MD5-specific, such as `Md5BytesRaw` or `Md5BytesDigest`, with `ComputePacketDigest` retained only as the Socket caller's contextual name. Do not move the function under [UID:0000M9][PacketTransform](by-file/PacketTransform.md): the packet transform module should depend on MD5 rather than absorb the hash implementation.

## Rewrite Notes

- The current decompilation suggests a pointer to transient digest storage. Do not blindly preserve that unsafe-looking lifetime in final C++ without checking the exact stack/register behavior.
- A caller-provided 16-byte output buffer or a small returned digest object may be the safer reconstruction signature, but final signature choice must preserve `Socket::BuildEncryptedPacket` byte selection exactly.
- Keep the generated `ComputePacketDigest` name only as a packet-context alias; the underlying function should use an MD5-specific name in the utility module.
- Leave reconstructed C++ blank until the returned-buffer lifetime is proven from raw assembly or reconciled with the neighboring `Md5BytesToBuffer` wrapper at `0x005153e0`.

## Cross-References

- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)

## Changes

- 2026-06-02: Raised from `50/75` to `76/82` and attached to [UID:0000L6][MD5](by-file/MD5.md).
  - Added boundary/alignment evidence, MD5 callee table, Socket caller/trailer evidence, and MD5-island placement table from existing IDA-backed MD5/Socket docs.
  - Left reconstructed C++ blank because the final source signature and returned digest storage lifetime are still unresolved.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/75` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet digest helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper as rebuild-relevant code while staying conservative because the final signature/lifetime model is still open.
  - Evidence: IDA MCP confirms the exact range, sole `Socket::BuildEncryptedPacket` caller, and MD5 update/final callees.
