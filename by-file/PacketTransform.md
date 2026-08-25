*** UID:0000M9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PacketTransform

## Status

- Confidence: strong for `PacketTransform.cpp/.h` as the reconstruction parent, exact declaration/function order, helper/global grouping, complete source bodies, and the Socket consumer boundary; exact historical filename spelling remains inferred.
- Proposed module: `network/PacketTransform.cpp`
- Historical generated projections: recovered global files `InitializePacketNonce_00575CB0.cpp`, `BuildHandshakeBlock_00577030.cpp`, and `XorTransformBuffer_00578E00.cpp`, plus related globals emitted near `class_Socket.cpp`; these are retained only as prior naming context, not as evidence for the 2026-06-05 refresh.
- Main address docs: non-emitting split index [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md); exact source children [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) and [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md); [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md); [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md); and [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md).
- Supporting item doc: [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- Global state doc: [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- Digest dependency: [UID:0000L6][MD5](by-file/MD5.md), specifically [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- Evidence basis: existing project documentation and IDA MCP lookup/xref/decompile/disassembly checks on 2026-05-24, 2026-05-25, and the A003 live refresh on 2026-06-05.

## Hypothesis

The original client kept packet transform/key-table support close to Socket. The accepted reconstruction uses `network/PacketTransform.cpp/.h` as the source-closed owner for free helpers, globals, and declarations because this code derives and applies protocol key state rather than doing scalar packet field formatting.

This should not be folded into [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md). `PacketBuffer.cpp` owns endian/string cursor helpers; this module owns handshake seed tables, nonce-derived alternate tables, the packet transform LUT, and the repeated-key XOR primitive used by socket encode/decode.

## Contents

Likely source-level contents:

- `BuildHandshakeBlock` at `0x00577030`: initializes the primary handshake seed/key table and `g_packetTransformStride`; B012's 2026-07-03 current MCP pass confirms the active IDA name is still `sub_577030`, so `BuildHandshakeBlock` is the accepted source-facing docs/C++ name rather than current IDB symbol proof.
- [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) at `0x00575b90`: retained no-route source helper that computes one `Md5StringHex(keyText)`, copies the first nine digest bytes to nonce scratch, replicates four alternate-table windows, and frees the digest with CRT `free`.
- [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) at `0x00575c30`: live CP_ACP-login-derived key builder that double-hashes its seed, writes the second digest with bounded `sprintf_s`, and appends 31 successive MD5 digests for exactly 1,024 characters plus NUL.
- `InitializePacketNonce` at `0x00575cb0`: derives per-packet alternate key bytes from `g_packetTransformKeyText` modulo 1,024 and replicates them into the alternate key table. B011's 2026-07-03 current MCP pass confirms this exact child is first-draft C++ ready through [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md).
- `XorTransformBuffer` at `0x00578e00`: repeated-key XOR helper used by both inbound and outbound transforms. B001's 2026-07-06 MCP pass resolves this exact child as first-draft C++ ready with current IDB name `sub_578E00`, source-facing name `XorTransformBuffer`, source ABI order `source, destination, length, keyData, keyWordCount`, and `void` return disposition.
- Packet transform globals such as the handshake seed bytes, nonce scratch bytes, primary/alternate XOR tables, transform key-text pointer, transform stride, packet sequence byte, `g_packetXorAlternateSize = 9`, the private initialized reserved dword at `0x0066fe54`, and `unsigned int g_packetTransformLut[256]`. [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) supplies mutable declarations for `g_handshakeSeedBytes[12]`, `g_packetNonceScratch[12]`, `g_packetTransformKeyText`, `g_packetTransformStride`, `g_packetSequenceByte`, private sequence padding, `g_packetXorTablePrimary[48]`, and `g_packetXorTableAlternate[48]`.

`Socket::TransformFramePayload` and `Socket::BuildEncryptedPacket` should stay with [UID:0000NS][Socket](by-file/Socket.md), because they are stateful packet encode/decode methods tied to the transport frame buffers and socket send/receive paths. They call the free helpers documented here, and `BuildEncryptedPacket` also depends on the shared [UID:0000L6][MD5](by-file/MD5.md) utility for trailer digest bytes.

B006's 2026-06-20 Socket class pass keeps that split: Socket owns stateful encode/decode, allocation/lifetime, and command dispatch, while this file owns reusable transform helpers/globals such as `InitializePacketTransformAlternateKey`, `BuildPacketTransformKeyText`, `InitializePacketNonce`, `BuildHandshakeBlock`, `XorTransformBuffer`, `g_packetTransformLut`, `g_handshakeSeedBytes`, `g_packetNonceScratch`, `g_packetTransformKeyText`, `g_packetTransformStride`, `g_packetSequenceByte`, and the primary/alternate XOR tables. Raw Socket command `14` queues handshake/seed data into this helper family rather than writing transport output directly.

## Evidence

- IDA MCP confirms exact helper starts and sizes; names are source-facing unless a current-name caveat is stated:
  - `0x00575b90-0x00575c30`, raw 160-byte / 49-instruction `InitializePacketTransformAlternateKey`, complete source body with no recovered inbound route.
  - `0x00575c30-0x00575caa`, size `0x7a` / 122 bytes, 40-instruction `BuildPacketTransformKeyText`, one live caller.
  - `0x00575cb0`, size `0xd3`, `InitializePacketNonce`.
  - `0x00577030`, size `0x10d`, source-facing `BuildHandshakeBlock`; B012 current MCP session `31debdf2` resolves the active IDA name as `sub_577030`.
  - `0x00578e00`, size `0x94`, source-facing `XorTransformBuffer`; B001 current MCP session `b001-0001I5` resolves the active IDB name as `sub_578E00`.
- IDA xrefs show source-facing `BuildHandshakeBlock` / current `sub_577030` is only called by the `Socket` constructor at `0x005747e0` and `Socket::HandleSocketCommand` at `0x00575e60`.
- IDA xrefs show `InitializePacketNonce` is only called by [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) at `0x00578b20` and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) at `0x00578c40`.
- IDA xrefs show `BuildPacketTransformKeyText` at `0x00575c30` is called from [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) after CP_ACP login-name wide-to-multibyte conversion into a 128-byte local buffer.
- IDA xrefs show `XorTransformBuffer` is called three times from `Socket::TransformFramePayload` and three times from `Socket::BuildEncryptedPacket`.
- Existing project documentation imports these helpers as free transform routines used by Socket transform methods rather than as `Socket` methods.
- The helper globals are protocol tables and counters, not packet scalar read/write utilities: `g_packetTransformStride`, `g_packetXorAlternateSize`, `g_packetTransformLut`, `g_packetXorTablePrimary`, `g_packetXorTableAlternate`, `g_packetNonceScratch`, and `g_handshakeSeedBytes`.
- IDA MCP disassembly on 2026-05-25 pins the important globals to [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md): alternate size `0x0066fe50`, dword LUT `0x0066fe58`, handshake seed/scratch block `0x0069ba40-0x0069ba60`, primary table `0x0069ba64`, and alternate table `0x0069ba94`.
- 2026-06-07 A001 IDA MCP `py_eval` recheck confirms the file-level split used for reconstruction parenting: `0x0066fe50` alternate size is read by string-key setup, nonce initialization, and encrypted-packet paths; `0x0066fe58` is the dword LUT used from the socket command/transport cluster; and the mutable state fields `0x0069ba40`, `0x0069ba4c`, `0x0069ba58`, `0x0069ba5c`, `0x0069ba60`, `0x0069ba64`, and `0x0069ba94` are referenced from packet-transform helper families rather than scalar packet-buffer helpers.
- The same 2026-06-07 pass reconfirms the helper boundaries that define this reconstruction module: `0x00575c30-0x00575caa`, `0x00575cb0-0x00575d83`, `0x00577030-0x0057713d`, and `0x00578e00-0x00578e94`, while `Socket` remains the transport-method caller/consumer for frame-level encode/decode.
- B012's 2026-07-03 current MCP session `31debdf2` reconfirms [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md) as current IDA `sub_577030`, size `0x10d` / decimal `269` (Verified with `int_convert.py`), with two direct Socket caller sites (`0x00574880` constructor seed and `0x00576181` command `14`), primary-table writes only, no direct target writes to `0x0069ba94`, and `CC CC CC` padding before `0x00577140`. The exact child now carries target-level first-draft C++ through this PacketTransform route.
- B011's 2026-07-03 evidence-time MCP session `31debdf2` reconfirmed [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) as IDA `sub_575CB0`, size `0xd3` / decimal `211`, with exactly two Socket callers (`0x00578b72` inbound and `0x00578cd2` outbound), callees `sub_516030`, `sub_516220`, and `___report_rangecheckfailure`, default alternate size `9`, nonce/key-buffer index formula `(nonceBase + index * step) % 1024` with `step = nonceMiddle * nonceMiddle` and `step += 3`, scratch writes to `g_packetNonceScratch`, process/key reads through the pointer then source-faced as `g_processArgList` and now named `g_packetTransformKeyText`, four `g_packetXorTableAlternate` window copies, `sub_516220` resolved as a `memmove` wrapper, and thirteen-byte `0xcc` alignment before `nullsub_53`. The exact child carries formal first-draft C++ through this PacketTransform route.
- B013's 2026-07-04 evidence-time MCP session `cbc24146` reconfirmed [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) as source-ready mutable storage: healthy IDB at evidence time, not-a-function endpoints, `0x84` / decimal `132` zero bytes, zero sampled ints, field-specific xrefs, Socket allocation/free for the pointer then source-faced as `g_processArgList` and now named `g_packetTransformKeyText`, consumer decompiles, and clean successor boundary at StartupWindow `0x0069bac4`. The exact child carries formal declarations through the PacketTransform route; exact original names, private `Socket.cpp` source-placement possibility, and padding spelling remain confidence caps.
- B001's 2026-07-13 UID000244 reanalysis resolves the former aggregate blocker at report-level detail:
  - UID000244 is now a `92/94` non-emitting split index; exact source children UID0004ME/UID0004MF own every byte and emit at positions `20/30`.
  - Raw UID0004ME computes one MD5 hex digest, copies exactly the initialized nine-byte alternate size into scratch and four table windows, calls MemoryMan's memmove wrapper five times, frees with CRT `free`, has no EH/compiler scaffold, no start/interior/direct/pointer/duplicate route, and remains retained source rather than suppressed code.
  - Live UID0004MF has one MainUiGraph caller, double initial MD5, secure bounded `"%s"` seed write, two immediate frees, 31 secure `"%s%s"` hash/append/free iterations, and exact 1,024-character output.
  - `g_packetTransformKeyText` replaces stale source-facing `g_processArgList`: Socket owns its 1,025-byte allocation/free lifecycle, the live child fills it, and nonce initialization consumes it modulo 1,024.
  - Deterministic root source order is globals `10`, UID0004ME `20`, UID0004MF `30`, nonce `40`, handshake `50`, and XOR `60`; initialized/mutable global declaration order is `10/20` under UID0000TG.
  - Historical duplicate-string, self-concatenation, raw-body-deferral, and unresolved-global-name claims are preserved only as superseded provenance. Exact original helper/global spellings and separate-file/private-`Socket.cpp` layout remain confidence caps.

## Current Generated-Output Caveats

- Older generated projections disagree about `XorTransformBuffer`: one projection declares it as `extern void XorTransformBuffer(std::uint32_t* src, std::uint32_t* dst, std::uint32_t len, int keyPtr, std::uint32_t step);`, while another defines it as returning `std::uint8_t`. These are now stale generated-output caveats rather than active blockers.
- B001's 2026-07-06 MCP pass resolves [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) as `void XorTransformBuffer(const unsigned char *source, unsigned char *destination, unsigned int length, const void *keyData, unsigned int keyWordCount)`. Current IDB session `b001-0001I5` names the function `sub_578E00`; `XorTransformBuffer` is the accepted source-facing docs/C++ name, not current symbol proof.
- IDA still infers a byte-like residual return over integer-address arguments, but all six live Socket transform callers ignore the return. Socket caller C++ now uses source ABI order `source, destination, length, keyData, keyWordCount`.
- Older generated globals are also inconsistent: `g_packetTransformLut` is emitted as a byte array in stale generated/simroot output even though command `13` writes 256 dwords at `0x0066fe58` and `XorTransformBuffer` reads dword key words from the supplied key pointer.
- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) now carries the source-ready initialized declaration block for this global subset: `int g_packetXorAlternateSize = 9;`, private `static int s_packetTransformReserved = 0;`, and `unsigned int g_packetTransformLut[256]` with a repeated-byte initializer macro. This resolves the LUT fixed capacity as `0x100` / decimal `256` dwords and rejects byte-array or undersized IDA typing for the initialized range.
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) now carries the source-ready mutable declaration block for this global subset. [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) now carries the exact helper body. Generated `auto-generated/NexusTK/network/PacketTransform.cpp` should no longer retain UID0002AL or UID0001I5 empty markers after scoped validation/generation refresh; do not hand-edit generated output.

## Proposed Placement

```text
network/
  PacketTransform.h
  PacketTransform.cpp
```

`Socket.cpp` includes `PacketTransform.h`. The declaration surface is emitted through PacketTransform support owners; definitions remain singular in `PacketTransform.cpp`.

## Keep Out

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): endian field helpers, cursor appends, and string serialization.
- [UID:0000NS][Socket](by-file/Socket.md): transport lifecycle, receive parsing, frame building, and final transport writes.
- Feature packet builders such as clan, mail, board, map, item, and chat send helpers.
- [UID:0000L6][MD5](by-file/MD5.md): digest helpers around `0x005151f0-0x00515f48`, including the packet digest helper called by `BuildEncryptedPacket` at `0x00515380`.

## Open Questions

- Exact original filename spelling is not symbol-proven; `PacketTransform.cpp/.h` is the accepted reconstruction route and is not a blocker.
- Resolved for mutable storage: `g_packetNonceScratch` is `unsigned char[12]`, `g_packetXorTablePrimary` is `unsigned char[48]`, and `g_packetXorTableAlternate` is `unsigned char[48]` through [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md). The source-facing names and three-byte post-sequence padding spelling remain inferred confidence caps.
- Resolved for the initialized LUT: `g_packetTransformLut` is `unsigned int[256]`, a `0x400` / decimal `1024` byte dword table inside the `0x408` / decimal `1032` byte [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) `.data` block. Stale generated byte-array declarations and IDA's undersized `int[130]` type should not be used for final source.
- Resolved semantic name: use `g_packetTransformKeyText`. Socket allocates/frees 1,025 bytes, UID0004MF fills exactly 1,024 characters plus NUL, and UID0001I0 consumes indexes modulo 1,024. Historical `ArgList` / `g_processArgList` is retained only as IDA/generated provenance.
- Resolved for UID0001I5: `XorTransformBuffer` now has a first-draft `void` byte-buffer prototype and body through this PacketTransform route. The exact original helper spelling remains inferred because current B001 IDB naming is `sub_578E00`.
- `PacketTransform.cpp/.h` is the final reconstruction parent because it cleanly groups free helper functions and shared transform globals outside PacketBuffer and Socket member bodies.

## Cross-References

- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md)
- [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## 2026-08-17 B003 UID0000MV Header Closure

`PacketTransform.h` is emitted in deterministic support-owner order. [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md) owns `#pragma once`, `<stddef.h>`, and the nine exact extern declarations: alternate size, 256-dword LUT, 12-byte seed and nonce arrays, key-text pointer, stride, sequence byte, and both 48-byte XOR tables. [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md) owns declarations for `InitializePacketTransformAlternateKey`, `BuildPacketTransformKeyText`, `InitializePacketNonce`, `BuildHandshakeBlock`, and `XorTransformBuffer` with its accepted source ABI.

This header is the complete dependency surface consumed by Socket. It declares but does not duplicate storage or definitions; `PacketTransform.cpp` remains the singular implementation owner. No PacketTransform source is routed through ProtocolSend or PacketBuffer.

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: closed `PacketTransform.h` through the global/helper support owners and made the separate Socket-consumer boundary final.
- 2026-07-13 B001 UID000244 source-quality implementation:
  - Raised `89/85` to `91/90` after exact split/body/global/source-order blockers closed.
  - Added validator-issued UID0004ME/UID0004MF, complete one-digest alternate-key and 1,024-character MD5-chain behavior, raw no-route/unique-body evidence, login caller, secure formatting, digest/free ownership, and deterministic positions.
  - Replaced source-facing `g_processArgList` with `g_packetTransformKeyText` while preserving `g_packetXorAlternateSize`, `g_packetNonceScratch`, `g_packetXorTableAlternate`, later nonce/handshake/XOR work, PacketTransform ownership, Socket/MD5/MemoryMan dependencies, and separate-file uncertainty.
  - Historicalized only the old duplicate-string, self-concatenation, unresolved-global, and aggregate-blank-as-current-blocker conclusions.

- 2026-07-06 B001 UID0001I5 source-quality sync:
  - Changed to: completion `89`, confidence unchanged at `85`, path unchanged at `NexusTK/network/`.
  - Summary/evidence: synchronized accepted [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) details from B001 MCP session `b001-0001I5`: current IDB `sub_578E00`, source-facing `XorTransformBuffer`, exact `0x94` / decimal `148` range, six direct Socket transform call sites, no callees, source ABI order `source, destination, length, keyData, keyWordCount`, ignored residual return, formal `void` helper C++, resolved global/key declaration blocker through UID000286/UID0002AL, and unrelated `UNL.DLL` successor after alignment. Preserved caps: exact original source file versus private `Socket.cpp` section and original symbol spellings remain inferred; raw `0x00575b90` liveness/source shape remains unresolved.
- 2026-07-04 B013 mutable-state declaration sync:
  - Score/path metadata was unchanged at `88/85` and `NexusTK/network/`.
  - Summary/evidence: synchronized accepted UID0002AL details from B013 MCP session `cbc24146`: `0x0069ba40-0x0069bac4` is not a function, is `0x84` / decimal `132` zero-initialized bytes, has field xrefs for seed/scratch/process pointer/stride/sequence/primary table/alternate table, and now supplies formal declarations for the mutable globals through [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md). Generated `PacketTransform.cpp` should refresh away the UID0002AL empty marker after target validation. Preserved caveats: original separate `PacketTransform.cpp` versus private `Socket.cpp`, exact original names, raw `0x00575b90` liveness/source shape, and padding spelling.
- 2026-07-03 B011 PacketNonceInitialization support sync:
  - Score/path metadata unchanged at `88/85` and `NexusTK/network/`.
  - Summary/evidence: synchronized current source-readiness wording for [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md). Current MCP session `31debdf2` resolves the active IDA name as `sub_575CB0`, while `InitializePacketNonce` remains the accepted source-facing docs/C++ name. The exact child now emits formal first-draft C++ through PacketTransform; this file still preserves the original separate file versus private `Socket.cpp` caveat and still rejects direct Socket or PacketBuffer ownership for reusable transform helpers/globals.
- 2026-07-03 B012 BuildHandshakeBlock support sync:
  - Score/path metadata unchanged at `88/85` and `NexusTK/network/`.
  - Summary/evidence: synchronized current-name/source-readiness wording for [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md). Current MCP session `31debdf2` resolves the IDA name as `sub_577030`; `BuildHandshakeBlock` remains the accepted source-facing docs/C++ name. The exact child now emits first-draft C++ through PacketTransform, while this file still preserves the original separate file versus private `Socket.cpp` caveat.
- 2026-06-23 B004 initialized-LUT support sync:
  - Score/path metadata unchanged at `88/85` and `NexusTK/network/`.
  - Summary/evidence: incorporated accepted [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) declaration decision into the file-level view: PacketTransform owns the initialized `g_packetXorAlternateSize`, private reserved dword, and `unsigned int g_packetTransformLut[256]`; Socket remains writer/consumer but not direct declaration owner; `g_packetTransformLut` capacity is no longer an open question; generated byte-array and undersized IDA typing remain stale-output caveats.
- 2026-06-07 A001 parent-gate refresh:
  - Before: confidence was `82`, which was below the corrected `85/85` gate for using this file as the parent of [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md).
  - Changed to: confidence `85`.
  - Summary/evidence: fresh IDA MCP `py_eval` reconfirmed the cohesive transform-helper boundaries, alternate-size/LUT xrefs, mutable transform-state xrefs, and keep-out split from scalar [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) helpers and stateful [UID:0000NS][Socket](by-file/Socket.md) transport methods. Confidence is raised only to the gate because exact original filename versus private Socket section remains open, but `NexusTK/network/PacketTransform.cpp` is justified as the reconstruction parent.
- 2026-06-20 B006 Socket support sync:
  - Added cross-reference that Socket raw command `14` queues handshake/seed data into PacketTransform helper behavior while Socket remains owner of command dispatch and stateful transport methods.
- 2026-06-05: Reframed generated-output references as historical caveats and refreshed evidence wording to rely on existing project docs plus IDA MCP. A003 live IDA confirmed the string-key helper at `0x00575c30` is reached from `0x004f8544`, while the raw `0x00575b90` key-table setup helper remains unmodeled and has no direct xrefs. Scores unchanged because the overall source-file placement ambiguity remains open.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/` and raised confidence from `78` to `82`. Evidence: the page already proposes `network/PacketTransform.cpp`, IDA MCP recheck confirms the modeled helper starts and xref sets, and the only remaining placement ambiguity is whether this was a standalone network helper file or a private `Socket.cpp` section.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `78`.
- Summary/evidence: the page documents helper grouping, transform globals, exact IDA function/xref evidence, generated-output caveats, source placement, keep-out boundaries, open questions, and cross-references; confidence remains capped by uncertainty over a separate source file versus a private `Socket.cpp` section and final helper/global names.
