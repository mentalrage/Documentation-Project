*** UID:0000M9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PacketTransform

## Status

- Confidence: strong for `PacketTransform.cpp` as the reconstruction parent and helper/global grouping; medium for whether the original source used a separate file name versus a private `Socket.cpp` section.
- Proposed module: `network/PacketTransform.cpp`
- Historical generated projections: recovered global files `InitializePacketNonce_00575CB0.cpp`, `BuildHandshakeBlock_00577030.cpp`, and `XorTransformBuffer_00578E00.cpp`, plus related globals emitted near `class_Socket.cpp`; these are retained only as prior naming context, not as evidence for the 2026-06-05 refresh.
- Main address docs: [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md), [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md), [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md), and [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- Supporting item doc: [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- Global state doc: [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- Digest dependency: [UID:0000L6][MD5](by-file/MD5.md), specifically [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- Evidence basis: existing project documentation and IDA MCP lookup/xref/decompile/disassembly checks on 2026-05-24, 2026-05-25, and the A003 live refresh on 2026-06-05.

## Hypothesis

The original client likely kept packet transform/key-table support close to `Socket`, either as private helpers in `Socket.cpp` or as a small companion protocol file. For reconstruction, `network/PacketTransform.cpp` is the clearest owner for the free helper functions and transform globals because this code derives and applies protocol key state rather than doing scalar packet field formatting.

This should not be folded into [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md). `PacketBuffer.cpp` owns endian/string cursor helpers; this module owns handshake seed tables, nonce-derived alternate tables, the packet transform LUT, and the repeated-key XOR primitive used by socket encode/decode.

## Contents

Likely source-level contents:

- `BuildHandshakeBlock` at `0x00577030`: initializes the primary handshake seed/key table and `g_packetTransformStride`.
- String-key setup helpers at `0x00575b90-0x00575caa`: populate transform scratch/alternate-table state from process/login text and expand the login/process string in `g_processArgList`.
- `InitializePacketNonce` at `0x00575cb0`: derives the per-packet alternate key bytes from `g_processArgList` and replicates them into the alternate key table.
- `XorTransformBuffer` at `0x00578e00`: repeated-key XOR helper used by both inbound and outbound transforms.
- Packet transform globals such as the handshake seed bytes, nonce scratch bytes, primary/alternate XOR tables, transform stride, packet sequence byte, and packet transform LUT.

`Socket::TransformFramePayload` and `Socket::BuildEncryptedPacket` should stay with [UID:0000NS][Socket](by-file/Socket.md), because they are stateful packet encode/decode methods tied to the transport frame buffers and socket send/receive paths. They call the free helpers documented here, and `BuildEncryptedPacket` also depends on the shared [UID:0000L6][MD5](by-file/MD5.md) utility for trailer digest bytes.

## Evidence

- IDA MCP confirms exact helper starts and sizes:
  - `0x00575b90`, raw helper ending at `0x00575c30`, packet transform string-key table setup.
  - `0x00575c30`, size `0x7a`, login/process string expansion helper.
  - `0x00575cb0`, size `0xd3`, `InitializePacketNonce`.
  - `0x00577030`, size `0x10d`, `BuildHandshakeBlock`.
  - `0x00578e00`, size `0x94`, `XorTransformBuffer`.
- IDA xrefs show `BuildHandshakeBlock` is only called by the `Socket` constructor at `0x005747e0` and `Socket::HandleSocketCommand` at `0x00575e60`.
- IDA xrefs show `InitializePacketNonce` is only called by [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) at `0x00578b20` and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) at `0x00578c40`.
- IDA xrefs show the login/process string expansion helper at `0x00575c30` is called from [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) after login-name wide-to-multibyte conversion.
- IDA xrefs show `XorTransformBuffer` is called three times from `Socket::TransformFramePayload` and three times from `Socket::BuildEncryptedPacket`.
- Existing project documentation imports these helpers as free transform routines used by Socket transform methods rather than as `Socket` methods.
- The helper globals are protocol tables and counters, not packet scalar read/write utilities: `g_packetTransformStride`, `g_packetXorAlternateSize`, `g_packetTransformLut`, `g_packetXorTablePrimary`, `g_packetXorTableAlternate`, `g_packetNonceScratch`, and `g_handshakeSeedBytes`.
- IDA MCP disassembly on 2026-05-25 pins the important globals to [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md): alternate size `0x0066fe50`, dword LUT `0x0066fe58`, handshake seed/scratch block `0x0069ba40-0x0069ba60`, primary table `0x0069ba64`, and alternate table `0x0069ba94`.
- 2026-06-07 A001 IDA MCP `py_eval` recheck confirms the file-level split used for reconstruction parenting: `0x0066fe50` alternate size is read by string-key setup, nonce initialization, and encrypted-packet paths; `0x0066fe58` is the dword LUT used from the socket command/transport cluster; and the mutable state fields `0x0069ba40`, `0x0069ba4c`, `0x0069ba58`, `0x0069ba5c`, `0x0069ba60`, `0x0069ba64`, and `0x0069ba94` are referenced from packet-transform helper families rather than scalar packet-buffer helpers.
- The same 2026-06-07 pass reconfirms the helper boundaries that define this reconstruction module: `0x00575c30-0x00575caa`, `0x00575cb0-0x00575d83`, `0x00577030-0x0057713d`, and `0x00578e00-0x00578e94`, while `Socket` remains the transport-method caller/consumer for frame-level encode/decode.

## Current Generated-Output Caveats

- Older generated projections disagree about `XorTransformBuffer`: one projection declares it as `extern void XorTransformBuffer(std::uint32_t* src, std::uint32_t* dst, std::uint32_t len, int keyPtr, std::uint32_t step);`, while another defines it as returning `std::uint8_t`.
- IDA shows `Socket::BuildEncryptedPacket` passes payload/key buffers in a byte-buffer context, so those generated prototypes are retained only as caveats pending final source typing.
- IDA decompiles `0x00578e00` as a byte-returning helper over integer addresses. The source-facing prototype should be normalized before migration, likely as a byte-buffer helper with a byte return value that callers may ignore.
- Older generated globals are also inconsistent: `g_packetTransformLut` is emitted as a byte array even though command `13` writes 256 dwords at `0x0066fe58` and `XorTransformBuffer` reads dword key words from the supplied key pointer.

## Proposed Placement

```text
network/
  PacketTransform.h
  PacketTransform.cpp
```

`Socket.cpp` should include the private declarations or header for these helpers. If later source-layout evidence proves the original project used one large socket source file, this module can fold back into `Socket.cpp` as a private helper section without changing class ownership.

## Keep Out

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): endian field helpers, cursor appends, and string serialization.
- [UID:0000NS][Socket](by-file/Socket.md): transport lifecycle, receive parsing, frame building, and final transport writes.
- Feature packet builders such as clan, mail, board, map, item, and chat send helpers.
- [UID:0000L6][MD5](by-file/MD5.md): digest helpers around `0x005151f0-0x00515f48`, including the packet digest helper called by `BuildEncryptedPacket` at `0x00515380`.

## Open Questions

- Whether the original filename was a distinct protocol/crypto helper file, a private `Socket.cpp` section, or a broader network utility file.
- Exact fixed capacities for `g_packetXorTablePrimary`, `g_packetXorTableAlternate`, `g_packetNonceScratch`, and `g_packetTransformLut`.
- Final semantic name for `g_processArgList`; it is allocated and freed by `Socket`, but consumed as transform key material.
- The exact original filename is still not final; `PacketTransform.cpp` is the reconstruction parent because it cleanly groups the free helper functions and shared transform globals outside `PacketBuffer` and Socket method bodies.

## Cross-References

- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-07 A001 parent-gate refresh:
  - Before: confidence was `82`, which was below the corrected `85/85` gate for using this file as the parent of [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md).
  - Changed to: confidence `85`.
  - Summary/evidence: fresh IDA MCP `py_eval` reconfirmed the cohesive transform-helper boundaries, alternate-size/LUT xrefs, mutable transform-state xrefs, and keep-out split from scalar [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) helpers and stateful [UID:0000NS][Socket](by-file/Socket.md) transport methods. Confidence is raised only to the gate because exact original filename versus private Socket section remains open, but `NexusTK/network/PacketTransform.cpp` is justified as the reconstruction parent.
- 2026-06-05: Reframed generated-output references as historical caveats and refreshed evidence wording to rely on existing project docs plus IDA MCP. A003 live IDA confirmed the string-key helper at `0x00575c30` is reached from `0x004f8544`, while the raw `0x00575b90` key-table setup helper remains unmodeled and has no direct xrefs. Scores unchanged because the overall source-file placement ambiguity remains open.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/` and raised confidence from `78` to `82`. Evidence: the page already proposes `network/PacketTransform.cpp`, IDA MCP recheck confirms the modeled helper starts and xref sets, and the only remaining placement ambiguity is whether this was a standalone network helper file or a private `Socket.cpp` section.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `78`.
- Summary/evidence: the page documents helper grouping, transform globals, exact IDA function/xref evidence, generated-output caveats, source placement, keep-out boundaries, open questions, and cross-references; confidence remains capped by uncertainty over a separate source file versus a private `Socket.cpp` section and final helper/global names.
