*** UID:0000V3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Packet Transform Helpers

## Status

- Confidence: strong for behavior, medium for exact original filenames.
- Likely source module: [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- Related class: [UID:0000DD][Socket](by-class/Socket.md)
- Related globals: [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- Evidence basis: `simroot_v2` generated output and IDA MCP lookup/xref/decompile/disassembly checks on 2026-05-24, 2026-05-25, and 2026-06-02.

## Helpers

| Address | Current name | Role |
| --- | --- | --- |
| `0x00575b90` | raw/IDA-missed helper | Copies process/login-derived key text into transform scratch and alternate-table windows. |
| `0x00575c30` | `sub_575C30` | Expands login/process text into `g_processArgList` for transform key material. |
| `0x00575cb0` | `InitializePacketNonce` | Derives the alternate per-packet XOR table from nonce bytes and process/key material. |
| `0x00577030` | `BuildHandshakeBlock` | Builds the primary handshake seed table and records the primary transform stride. |
| `0x00578e00` | `XorTransformBuffer` | Applies repeated-key XOR to dword blocks and trailing bytes. |

The packet digest helper at `0x00515380` is intentionally excluded from this table. It is the packet-facing wrapper in the shared [UID:0000L6][MD5](by-file/MD5.md) utility family.

## Call Relationships

- `BuildHandshakeBlock` is called by the [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) constructor and by `Socket::HandleSocketCommand` command `14`.
- `sub_575C30` is called by [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) after login-name conversion.
- `InitializePacketNonce` is called by [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md).
- `XorTransformBuffer` is called three times by `Socket::TransformFramePayload` and three times by `Socket::BuildEncryptedPacket`.
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) additionally calls [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md) after the XOR passes, then copies selected digest bytes into the outbound trailer.

## Behavioral Notes

- `BuildHandshakeBlock` copies an incoming seed block, mutates bytes 3 and 6, copies the seed into four consecutive primary table windows, restores bytes 3 and 6 to literal `c` and `t`, then frees the seed block.
- The `0x00575b90-0x00575caa` string-key helpers copy login/process text into the transform scratch/alternate table area and expand that text into the global key-material buffer at `0x0069ba58`.
- `InitializePacketNonce` uses `nonceMiddle * nonceMiddle` and an incrementing offset to index a 1024-byte key/process buffer, writes the scratch bytes, terminates them with zero, and copies the scratch bytes into four alternate table windows.
- `XorTransformBuffer` processes `len >> 2` dword blocks with `key[index % step]`, then handles one to three trailing bytes from the next key word.
- The shared global state is address-backed: alternate size `0x0066fe50`, dword LUT `0x0066fe58`, handshake seed `0x0069ba40`, nonce scratch `0x0069ba4c`, process/key pointer `0x0069ba58`, stride `0x0069ba5c`, sequence byte `0x0069ba60`, primary table `0x0069ba64`, and alternate table `0x0069ba94`.

## Signature Caveat

Current generated output is still inconsistent:

- the recovered helper body returns `std::uint8_t`;
- `class_Socket.cpp` declares it as returning `void`;
- some `Socket::BuildEncryptedPacket` call sites pass byte pointers while the extern declaration expects `std::uint32_t*` and `int`.

IDA decompiles the helper as returning a byte and using integer-address source, destination, and key pointers. A safer source-facing declaration is likely byte-buffer oriented, for example `std::uint8_t XorTransformBuffer(const std::uint8_t* src, std::uint8_t* dst, std::uint32_t length, const std::uint8_t* keyBytes, std::uint32_t keyDwordStride)`, with internal dword reads where alignment is known or intentionally tolerated.

IDA MCP rechecks on 2026-05-31 and 2026-06-02 confirm `0x00575c30-0x00575caa`, `0x00575cb0-0x00575d83`, `0x00577030-0x0057713d`, and `0x00578e00-0x00578e94` as real functions with the caller relationships listed above. The same rechecks report `0x00575b90` as not modeled as an IDA function, so the string-key helper remains a raw/IDA-missed helper range until its exact boundary and source shape are separately verified.

2026-06-02 IDA MCP `xrefs_to` reconfirms:

| Helper | Direct xrefs |
| --- | --- |
| `0x00575c30` | `0x004f8544` in [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) |
| `0x00575cb0` | `0x00578b72` in [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md), `0x00578cd2` in [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) |
| `0x00577030` | `0x00574880` in [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), `0x00576181` in [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md) |
| `0x00578e00` | `0x00578bb2`, `0x00578bed`, `0x00578c26` in `SocketTransformFramePayload`; `0x00578d27`, `0x00578d67`, `0x00578d99` in `SocketBuildEncryptedPacket` |

## Ownership Decision

These helpers should be reconstructed as packet/protocol transform support, not as [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) scalar helpers and not as feature send code. `Socket` owns the methods that decide when to decode or encode packets; `PacketTransform` owns the reusable key-table and XOR operations.

The reconstructed C++ block remains blank. The overview is now attached to [UID:0000M9][PacketTransform](by-file/PacketTransform.md), but final helper prototypes and the raw `0x00575b90` source shape are not final-source quality.

## Cross-References

- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)

## Changes

- 2026-06-02: Raised grading to `74/82` and attached to [UID:0000M9][PacketTransform](by-file/PacketTransform.md) after setting the parent projected path. IDA MCP rechecked helper starts and xrefs: `0x00575b90` remains raw/no-function, while `0x00575c30`, `0x00575cb0`, `0x00577030`, and `0x00578e00` retain the documented function ranges and callers. C++ remains blank because final prototypes and raw helper shape are still unresolved.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/70` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented packet transform helpers, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the group as rebuild-relevant packet transform code, while staying below high confidence because `0x00575b90` is still not an IDA-modeled function and final signatures remain open.
  - Evidence: IDA MCP confirms the exact modeled helper ranges and call relationships for `0x00575c30`, `0x00575cb0`, `0x00577030`, and `0x00578e00`, while also confirming the no-function caveat at `0x00575b90`.
