*** UID:0000TG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Packet Transform Globals

## Status

- Confidence: strong for addresses and packet-transform ownership; medium for final source-facing names and exact C types.
- Likely owner: [UID:0000M9][PacketTransform](by-file/PacketTransform.md), with lifetime/reset sequencing from [UID:0000NS][Socket](by-file/Socket.md)
- Related helpers: [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- Exact data ranges: [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) and [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md)
- Evidence basis: IDA MCP disassembly/xref checks and linked packet-transform memory pages.

## Symbols

| Address | Proposed name | Current name surface | Role |
| --- | --- | --- | --- |
| `0x0066fe50` | `g_packetXorAlternateSize` | IDA `Size`, generated `g_packetXorAlternateSize` | Alternate key length used by `InitializePacketNonce`; initial value is `9`. |
| `0x0066fe58-0x00670257` | `g_packetTransformLut` | IDA `dword_66FE58`, generated `g_packetTransformLut` | 256-entry dword lookup table filled by `Socket::HandleSocketCommand` command `13` and consumed as repeated XOR key words. |
| `0x0069ba40-0x0069ba4b` | `g_handshakeSeedBytes` | IDA `byte_69BA40`, generated `g_handshakeSeedBytes` | Scratch copy of the handshake seed block before expansion into the primary table. |
| `0x0069ba4c-0x0069ba57` | `g_packetNonceScratch` | IDA `byte_69BA4C`, generated `g_packetNonceScratch` | 12-byte scratch buffer filled from `g_processArgList` by `InitializePacketNonce`. |
| `0x0069ba58` | `g_processArgList` | IDA `ArgList`, generated `g_processArgList` | Pointer to the 1024-byte process/key buffer allocated by `Socket::Socket` and read by nonce/key-material helpers. |
| `0x0069ba5c` | `g_packetTransformStride` | IDA `dword_69BA5C`, generated `g_packetTransformStride` | Primary transform stride copied from the handshake seed length. |
| `0x0069ba60` | `g_packetSequenceByte` | generated `g_networkIoActive` | Outbound packet sequence byte reset by socket setup and consumed by `BuildEncryptedPacket`. |
| `0x0069ba64-0x0069ba93` | `g_packetXorTablePrimary` | IDA `unk_69BA64`, generated `g_packetXorTablePrimary` | Four repeated windows of the mutated handshake seed used as the primary XOR table. |
| `0x0069ba94-0x0069bac4` | `g_packetXorTableAlternate` | IDA `unk_69BA94`, generated `g_packetXorTableAlternate` | Four repeated windows of nonce-derived key bytes used as the alternate XOR table. |

## Exact Range Boundaries

- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) covers the initialized alternate-size dword, unused/alignment dword, and 256-entry dword LUT. Its raw summary starts with `09 00 00 00 00 00 00 00` and ends with repeated `0xfc` through `0xff` dwords, matching the dword-oriented command-13 fill behavior.
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) bounds the mutable handshake seed, nonce scratch, process/key pointer, stride, sequence byte, primary table, and alternate table before the neighboring StartupWindow update globals.
- The two exact memory pages keep the transform state split at its real physical locations: initialized LUT state near `0x0066fe50` and mutable socket/session transform state near `0x0069ba40`.

## Evidence

- `Socket::HandleSocketCommand` command `13` writes `dword_66FE58[index * 4]` for indexes `0..255`, so byte-array modeling is too weak; source code should treat it as dword-oriented key material.
- `BuildHandshakeBlock` copies the seed into `0x0069ba40`, records the seed length in `0x0069ba5c`, mutates bytes `3` and `6`, copies four windows into `0x0069ba64`, then restores bytes `3` and `6` to `c` and `t`.
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md) copies process/login-derived key text into `0x0069ba4c` and `0x0069ba94`, and expands login/process text through `ArgList` at `0x0069ba58`.
- `InitializePacketNonce` reads the size at `0x0066fe50`, reads the key buffer pointer at `0x0069ba58`, fills `0x0069ba4c`, enforces `size < 12`, terminates the scratch bytes, and copies four windows into `0x0069ba94`.
- `TransformFramePayload` and `BuildEncryptedPacket` pass pointers into `0x0066fe58`, `0x0069ba64`, or `0x0069ba94` to `XorTransformBuffer`.
- `BuildEncryptedPacket` reads and updates `0x0069ba60`; the active generated name is `g_networkIoActive`, but packet-sequence naming is more specific for this transform state.
- 2026-05-26 IDA recheck confirms the same address model: alternate size `0x0066fe50` initializes to `9`; `0x0066fe58` is written as `dword_66FE58[ebx*4]` in the socket command handler; `0x0069ba58` is allocated/freed by Socket lifetime code; `0x0069ba5c` is written by `BuildHandshakeBlock`; `0x0069ba60` is reset by socket paths and advanced by `BuildEncryptedPacket`; and the primary/alternate tables at `0x0069ba64` / `0x0069ba94` are passed to the transform helper.
- 2026-06-05 IDA MCP recheck confirmed xrefs for the alternate size, dword LUT, seed/scratch/pointer fields, and primary/alternate XOR tables across packet nonce, handshake, socket lifetime, and encrypted-packet helpers.
- 2026-06-07 helper-page cleanup attached [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) and [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md) to [UID:0000M9][PacketTransform](by-file/PacketTransform.md); those pages now document the specific reads/writes into the scratch, stride, primary-table, and alternate-table fields listed here.
- 2026-06-07 A001 IDA MCP `py_eval` recheck reconfirms the initialized state block [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md): `0x0066fe50` starts at dword `9`, `0x0066fe54` is an unreferenced zero dword, and `0x0066fe58-0x00670258` is a 256-entry dword LUT from `0x00000000` through `0xffffffff` by repeated-byte words.
- The same 2026-06-07 pass reconfirms current xrefs into the mutable state block [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md): seed bytes at `0x0069ba40`, nonce scratch at `0x0069ba4c`, process/key pointer at `0x0069ba58`, stride at `0x0069ba5c`, packet sequence byte at `0x0069ba60`, primary table at `0x0069ba64`, and alternate table at `0x0069ba94`; `0x0069bac4` begins unrelated StartupWindow update globals.

## Source Ownership

Keep this state with [UID:0000M9][PacketTransform](by-file/PacketTransform.md) or a private packet-transform section of [UID:0000NS][Socket](by-file/Socket.md). The data is protocol transform state, not scalar [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) storage and not feature-send state.

`g_processArgList` allocation/free is Socket lifecycle work, but its contents are consumed by the nonce/key transform helpers. Keep the pointer documented here and cross-reference Socket for lifetime.

## Data Issues

- Existing declaration aliases conflict: `g_packetTransformLut` is sometimes modeled as a byte array even though IDA shows dword writes and dword key consumption.
- IDA currently types `dword_66FE58` as `int[130]`; the command-13 fill loop writes 256 dwords, so treat the IDA type as under-sized until the database is corrected.
- The exact physical packet-transform state block is now documented as [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md). `g_packetXorTableAlternate` ends before the StartupWindow update globals at `0x0069bac4`.

## Cross-References

- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md)
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)

## Changes

- 2026-06-07 A001 parent-gate refresh:
  - What existed before: score `82/86`; this blocked assigning the exact initialized LUT child under the corrected `85/85` direct-parent gate.
  - Changed to: score `85/87`.
  - Summary/evidence: fresh IDA MCP `py_eval` reconfirmed the initialized alternate-size/LUT bytes and xrefs, the mutable transform-state xrefs and boundary at `0x0069bac4`, and the helper/file parent relationship now that [UID:0000M9][PacketTransform](by-file/PacketTransform.md) is `88/85`. Final C declarations and source-facing names still cap confidence below final-source quality.
- 2026-06-07 A007 exact range sync:
  - What existed before: the page had the correct address/name/role map and PacketTransform parent attachment, but did not explicitly link the exact initialized LUT range and mutable state range in the status/cross-reference sections, and its score still reflected the pre-split state summary.
  - Changed to: scores `82/86`, explicit exact-range boundary notes for `0x0066fe50-0x00670258` and `0x0069ba40-0x0069bac4`, and cross-links to the now-attached nonce and handshake helper pages.
  - Summary/evidence: the linked memory pages bound the initialized alternate-size/LUT block and mutable handshake/nonce/table block, while the nonce and handshake helper pages document the concrete reads/writes into the fields listed here. Final C++ remains blank because final source-facing names and C declarations are not final-audit quality.
- 2026-05-30 grading update:
  - What existed before: packet-transform globals had detailed address/name/role mapping, ownership notes, data issues, and range-bound changes but were still unevaluated by completion/confidence.
  - Changed to: score is now `80/84`.
  - Summary/evidence: documented state covers the transform LUT, handshake seed bytes, nonce scratch, process key buffer, stride/sequence byte, primary/alternate XOR tables, helper consumers, Socket lifetime, and known generated type/name conflicts; remaining uncertainty is final C types and source-facing names.
- 2026-06-05: Marked reconstructable and attached to [UID:0000M9][PacketTransform](by-file/PacketTransform.md).
  - Reason: live IDA MCP recheck confirms this source-declared mutable protocol transform state is consumed by packet-transform helpers, with Socket only owning part of the allocation/free lifetime.

- 2026-05-28 packet-transform data bound:
  - What existed before: `g_packetXorTableAlternate` was documented as `0x0069ba94+`, with exact capacity open and the next named symbol described as far away.
  - Changed to: the alternate table is bounded as `0x0069ba94-0x0069bac4`, inside [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md).
  - Summary/evidence: IDA MCP range audit of `0x0069ba3c-0x0069bec4` showed the packet-transform xrefs end before the `StartupWindow` globals at `0x0069bac4`; coverage now splits the old UNKNOWN row into exact subranges.
