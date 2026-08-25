*** UID:0000TG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Shared global declarations are provided by PacketTransform.h.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <stddef.h>

extern int g_packetXorAlternateSize;
extern unsigned int g_packetTransformLut[256];
extern unsigned char g_handshakeSeedBytes[12];
extern unsigned char g_packetNonceScratch[12];
extern char *g_packetTransformKeyText;
extern int g_packetTransformStride;
extern unsigned char g_packetSequenceByte;
extern unsigned char g_packetXorTablePrimary[48];
extern unsigned char g_packetXorTableAlternate[48];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Packet Transform Globals

## Status

- Confidence: strong for addresses, PacketTransform ownership, both exact declaration blocks, string-key producer/consumer/lifetime flow, and ordered helper routes; capped below final-source certainty only by original private spellings, the raw helper's missing inbound route, and separate `PacketTransform.cpp` versus private `Socket.cpp` organization.
- Likely owner: [UID:0000M9][PacketTransform](by-file/PacketTransform.md), with lifetime/reset sequencing from [UID:0000NS][Socket](by-file/Socket.md)
- Related helpers: [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- Exact data ranges: [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) and [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md)
- Evidence basis: IDA MCP disassembly/xref checks and linked packet-transform memory pages.

## Symbols

| Address | Proposed name | Current name surface | Role |
| --- | --- | --- | --- |
| `0x0066fe50` | `g_packetXorAlternateSize` | IDA `Size`, generated `g_packetXorAlternateSize` | Source-ready initialized `int` alternate key length used by `InitializePacketNonce`; initial value is `9`. |
| `0x0066fe54` | `s_packetTransformReserved` | unnamed zero dword | Private reserved zero dword inside the initialized declaration sequence; no xrefs recorded, preserved as `static int` storage rather than ordinary alignment. |
| `0x0066fe58-0x00670257` | `g_packetTransformLut` | IDA/search alias `dword_66FE58`, stale generated `g_packetTransformLut` byte-array forms | Source-ready `unsigned int[256]` lookup table filled by `Socket::HandleSocketCommand` command `13` and consumed as repeated XOR key words. |
| `0x0069ba40-0x0069ba4b` | `g_handshakeSeedBytes` | IDA `byte_69BA40`, generated `g_handshakeSeedBytes` | Scratch copy of the handshake seed block before expansion into the primary table. |
| `0x0069ba4c-0x0069ba57` | `g_packetNonceScratch` | IDA `byte_69BA4C`, generated `g_packetNonceScratch` | 12-byte scratch buffer filled from the one-digest initializer or from `g_packetTransformKeyText` by `InitializePacketNonce`. |
| `0x0069ba58` | `g_packetTransformKeyText` | historical IDA `ArgList`, historical generated `g_processArgList` | Pointer to a 1,025-byte allocation. UID0004MF fills exactly 1,024 transform-key characters plus NUL; nonce initialization reads it modulo 1,024. |
| `0x0069ba5c` | `g_packetTransformStride` | IDA `dword_69BA5C`, generated `g_packetTransformStride` | Primary transform stride copied from the handshake seed length. |
| `0x0069ba60` | `g_packetSequenceByte` | generated `g_networkIoActive` | Outbound packet sequence byte reset by socket setup and consumed by `BuildEncryptedPacket`. |
| `0x0069ba64-0x0069ba93` | `g_packetXorTablePrimary` | IDA `unk_69BA64`, generated `g_packetXorTablePrimary` | Four repeated windows of the mutated handshake seed used as the primary XOR table. |
| `0x0069ba94-0x0069bac4` | `g_packetXorTableAlternate` | IDA `unk_69BA94`, generated `g_packetXorTableAlternate` | Four repeated windows of nonce-derived key bytes used as the alternate XOR table. |

## Exact Range Boundaries

- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) covers the initialized alternate-size dword, unused/alignment dword, and 256-entry dword LUT. Its raw summary starts with `09 00 00 00 00 00 00 00` and ends with repeated `0xfc` through `0xff` dwords, matching the dword-oriented command-13 fill behavior.
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) bounds the mutable handshake seed, nonce scratch, process/key pointer, stride, sequence byte, primary table, and alternate table before the neighboring StartupWindow update globals.
- The two exact memory pages keep the transform state split at its real physical locations: initialized LUT state near `0x0066fe50` and mutable socket/session transform state near `0x0069ba40`.

## Initialized LUT Declaration Decision

- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) is now source-ready for its own initialized declaration block: `int g_packetXorAlternateSize = 9;`, private `static int s_packetTransformReserved = 0;`, and `unsigned int g_packetTransformLut[256]`.
- The exact target range is `0x408` / decimal `1032` bytes (Verified with `int_convert.py`): two leading dwords plus a `0x400` / decimal `1024` byte LUT payload, or `0x100` / decimal `256` dword entries (Verified with `int_convert.py`).
- The reserved dword at `0x0066fe54` is preserved as private source storage rather than dropped as generic alignment. Current docs record no xrefs to it, but ordinary dword-to-dword alignment does not require a four-byte filler slot, so source reconstruction should keep the zero value explicitly.
- The LUT source initializer should remain dword-oriented. Repeated-byte samples at indexes `0`, `1`, `127`, `128`, `254`, and `255` prove values from `0x00000000` through `0xffffffff`; command `13` can overwrite the table later, but the initial state is present in `.data` and should not be represented as a startup fill loop.
- `dword_66FE58` remains useful as an IDA/search alias only. Generated `std::uint8_t[]` / byte-array forms and IDA's undersized `int[130]` type are rejected stale/tool-shaped evidence because command `13` writes dword entries and transform consumers use `+4 * key` / `+4 * blockIndex` addressing.
- The boundary at `0x00670258` is closed by [UID:000287][0x00670258-0x00670260.SocketConnectionStringParsePointers](by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md). The raw `off_670258 -> aConnaddr` label belongs to the next Socket connection-address pointer data, not to this LUT.

## Evidence

- `Socket::HandleSocketCommand` command `13` writes `dword_66FE58[index * 4]` for indexes `0..255`, so byte-array modeling is too weak; source code should treat it as dword-oriented key material.
- `BuildHandshakeBlock` copies the seed into `0x0069ba40`, records the seed length in `0x0069ba5c`, mutates bytes `3` and `6`, copies four windows into `0x0069ba64`, then restores bytes `3` and `6` to `c` and `t`.
- [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) computes one MD5 hex digest, copies its first nine bytes to `g_packetNonceScratch`, and replicates four `g_packetXorTableAlternate` windows.
- [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) double-hashes CP_ACP login-derived text, writes the second digest, and appends 31 successive current-text digests into `g_packetTransformKeyText` for exactly 1,024 characters.
- `InitializePacketNonce` reads the size at `0x0066fe50`, reads the key buffer pointer at `0x0069ba58`, fills `0x0069ba4c`, enforces `size < 12`, terminates the scratch bytes, and copies four windows into `0x0069ba94`.
- `TransformFramePayload` and `BuildEncryptedPacket` pass pointers into `0x0066fe58`, `0x0069ba64`, or `0x0069ba94` to `XorTransformBuffer`.
- `BuildEncryptedPacket` reads and updates `0x0069ba60`; the active generated name is `g_networkIoActive`, but packet-sequence naming is more specific for this transform state.
- 2026-05-26 IDA recheck confirms the same address model: alternate size `0x0066fe50` initializes to `9`; `0x0066fe58` is written as `dword_66FE58[ebx*4]` in the socket command handler; `0x0069ba58` is allocated/freed by Socket lifetime code; `0x0069ba5c` is written by `BuildHandshakeBlock`; `0x0069ba60` is reset by socket paths and advanced by `BuildEncryptedPacket`; and the primary/alternate tables at `0x0069ba64` / `0x0069ba94` are passed to the transform helper.
- 2026-06-05 IDA MCP recheck confirmed xrefs for the alternate size, dword LUT, seed/scratch/pointer fields, and primary/alternate XOR tables across packet nonce, handshake, socket lifetime, and encrypted-packet helpers.
- 2026-06-07 helper-page cleanup attached [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) and [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md) to [UID:0000M9][PacketTransform](by-file/PacketTransform.md); those pages now document the specific reads/writes into the scratch, stride, primary-table, and alternate-table fields listed here.
- 2026-06-07 A001 IDA MCP `py_eval` recheck reconfirms the initialized state block [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md): `0x0066fe50` starts at dword `9`, `0x0066fe54` is an unreferenced zero dword, and `0x0066fe58-0x00670258` is a 256-entry dword LUT from `0x00000000` through `0xffffffff` by repeated-byte words.
- The same 2026-06-07 pass reconfirms current xrefs into the mutable state block [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md): seed bytes at `0x0069ba40`, nonce scratch at `0x0069ba4c`, process/key pointer at `0x0069ba58`, stride at `0x0069ba5c`, packet sequence byte at `0x0069ba60`, primary table at `0x0069ba64`, and alternate table at `0x0069ba94`; `0x0069bac4` begins unrelated StartupWindow update globals.
- 2026-06-16 live IDA MCP reconfirmed the alternate-size/LUT refs: `0x0066fe50` is the `Size` dword with reads from raw string-key setup, `InitializePacketNonce`, `SocketTransformFramePayload`, and `SocketBuildEncryptedPacket`; `0x0066fe58` is written as `dword_66FE58[ebx*4]` from `0x0057615f` in the socket command handler and raw site `0x00576fee`.
- The same pass reconfirmed mutable-state refs: `0x0069ba40` is copied and replicated by `BuildHandshakeBlock`; `0x0069ba58` is written by Socket lifetime at `0x00574899`, read/freed by cleanup paths, written by current source-facing `BuildPacketTransformKeyText`, and consumed by `InitializePacketNonce`.
- IDA function names were safely improved and saved for `0x00575c30` (`PacketTransform_ExpandProcessArgKeyText`), `0x00575cb0` (`InitializePacketNonce`), `0x00577030` (`BuildHandshakeBlock`), and `0x00578e00` (`XorTransformBuffer`). Data names/types were not changed because exact C declarations, fixed capacities, and final source-facing names remain unresolved.
- 2026-06-23 B004 implementation callback resolved the initialized alternate-size/LUT declaration shape for [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) only. A later B004 MCP-backed redo supersedes the earlier live-IDA-outage caveat and reconfirms the declaration without changing this page's score, owner/emitter, or blank parent C++ block.
- 2026-06-23 B004 MCP-backed redo used endpoint `http://127.0.0.1:13337/mcp`, active session `b880584f`, and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. The local PE supplement used SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` and mapped the target to `.data` inside VA `0x0066d000-0x0069ce24`.
- The same redo reconfirmed [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) route evidence at report-level detail: `xrefs_to 0x0066fe50` returned 11 data xrefs (`0x00575bab`, `0x00575bbc`, `0x00575bd3`, `0x00575bec`, `0x00575c06`, `0x00575cbb`, `0x00575d28`, `0x00575d41`, `0x00575d5b`, `0x00578c0e`, and `0x00578d0b`), and the PE scan found 11 `.text` absolute-VA pattern hits for the alternate-size dword with zero RVA/raw-offset hits.
- The redo also reconfirmed the reserved-dword negative evidence: `xrefs_to 0x0066fe54` returned no refs, and the PE scan found zero absolute-VA, RVA, or raw-offset dword-pattern hits. Keep `s_packetTransformReserved` as explicit private source storage with no active behavior claimed.
- The redo reconfirmed the LUT writer and consumer shape: `xrefs_to 0x0066fe58` returned `0x0057615f` inside `sub_575E60` and raw site `0x00576fee`; the PE scan found six `.text` absolute-VA hits for `0x0066fe58`; targeted disassembly of Socket command `13` shows `mov dword_66FE58[ebx*4], ecx` after building repeated-byte dwords; `sub_578B20` and `sub_578C40` pass `4 * sequence + 0x0066fe58` into `sub_578E00`; and `sub_578E00` reads key material with `*(_DWORD *)(key + 4 * (index % stride))`. This preserves `unsigned int g_packetTransformLut[256]` over byte-array or undersized IDA typing.
- Boundary and value proof from the redo: MCP values read `0x0066fe50 = 9`, `0x0066fe54 = 0`, sampled LUT entries `0x00000000`, `0x01010101`, `0x7f7f7f7f`, `0x80808080`, `0xfefefefe`, and `0xffffffff`, and `0x00670258` as the next pointer value rather than a LUT entry. `xrefs_to 0x00670258` returned one data ref at `0x005778cf` inside `sub_577890`, and the PE scan found one `.text` absolute-VA hit at `0x005778d1`, so [UID:000287][0x00670258-0x00670260.SocketConnectionStringParsePointers](by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md) remains the correct successor boundary.
- 2026-07-03 B011 MCP-backed nonce-helper sync used endpoint `http://127.0.0.1:13337/mcp`, active session `31debdf2`, and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; it reconfirmed [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) as current IDA `sub_575CB0`, size `0xd3` / decimal `211`, with exactly two Socket callers, three callees, and formal first-draft C++ through [UID:0000M9][PacketTransform](by-file/PacketTransform.md).
- The B011 sync reconfirmed the mutable/global state flow at report-level detail: `InitializePacketNonce` reads `g_packetXorAlternateSize` / IDA `Size` at `0x0066fe50` (default `9`), reads the pointer historically labeled `g_processArgList` / IDA `ArgList` at `0x0069ba58`, writes nonce-derived bytes and a zero terminator into `g_packetNonceScratch`, preserves the `Size >= 0x0c` range-check failure edge, and copies four windows into `g_packetXorTableAlternate`. Current source-facing code names that pointer `g_packetTransformKeyText`.
- The B011 sync also resolved the target copy helper: `analyze_function 0x00516220` decompiled `sub_516220` as a wrapper returning `memmove(a1, Src, Size)`. `entity_query` returned only `Size` and `ArgList`; therefore `g_packetXorAlternateSize`, `g_packetTransformKeyText`, `g_packetNonceScratch`, and `g_packetXorTableAlternate` remain evidence-backed source-facing names rather than recovered IDB symbols.
- 2026-07-04 B013 MCP-backed mutable-state declaration pass used active session `cbc24146`; `server_health` reported module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. `lookup_funcs` reports `0x0069ba40` and `0x0069bac4` are not functions, `get_bytes 0x0069ba40 size 0x84` returns 132 zero bytes, and sampled `u32le` reads at `0x0069ba40`, `0x0069ba4c`, `0x0069ba58`, `0x0069ba5c`, `0x0069ba60`, `0x0069ba64`, `0x0069ba94`, and `0x0069bac4` all return `0`.
- The current UID0002AL declaration block is source-ready as `unsigned char g_handshakeSeedBytes[12]`, `unsigned char g_packetNonceScratch[12]`, `char *g_packetTransformKeyText`, `int g_packetTransformStride`, `unsigned char g_packetSequenceByte`, private `static unsigned char s_packetTransformSequencePadding[3]`, `unsigned char g_packetXorTablePrimary[48]`, and `unsigned char g_packetXorTableAlternate[48]`. Its earlier B013 `g_processArgList` spelling is preserved only in dated history.
- B013 field xrefs in `cbc24146` are claim-specific: `0x0069ba40` has six refs in `sub_577030`; `0x0069ba4c` has raw `0x00575b90` refs plus `sub_575CB0` refs; `0x0069ba58` has Socket constructor/destructor and transform-helper refs; `0x0069ba5c` has handshake and both Socket transform refs; `0x0069ba60` has reset/command/output refs; `0x0069ba64` has handshake plus inbound/outbound transform refs; `0x0069ba94` has raw string-key, nonce, and inbound/outbound transform refs; and `0x0069bac4` has StartupWindow refs only, preserving the boundary.
- 2026-07-06 B001 MCP session `b001-0001I5` resolves the UID0001I5 `XorTransformBuffer` helper prototype that consumes this global state: current IDB name `sub_578E00`, source-facing name `XorTransformBuffer`, exact `0x00578e00-0x00578e94` range, six direct Socket transform call sites, no callees, source ABI order `source, destination, length, keyData, keyWordCount`, ignored residual return, and formal `void` first-draft helper C++. This removes UID0001I5 from the global-page helper-prototype cap while preserving raw `0x00575b90` and original source-placement uncertainty.
- 2026-07-13 B001 UID000244 reanalysis completes the missing producer/initializer evidence:
  - UID0004ME is a 160-byte / 49-instruction retained helper with one MD5 call, five `MemoryMan::MemmoveWrapper` calls, five exact alternate-size reads, scratch plus four-window writes, CRT free, one unique body, and exhaustive negative start/interior/direct/pointer/callback/EH routes.
  - UID0004MF is a live 122-byte / 40-instruction helper with one MainUiGraph caller, double initial MD5, secure `sprintf_s` seed write, two frees, 31 successive current-text digest appends, per-iteration free, and exactly 1,024 output characters.
  - Socket allocates/frees/nulls 1,025 bytes; UID0004MF fills it; UID0001I0 indexes it modulo 1,024. This resolves `g_packetTransformKeyText` and supersedes current use of the decompiler-generated `g_processArgList` spelling.
  - Declaration/root order is this global aggregate position `10`, initialized UID000286 position `10`, mutable UID0002AL position `20`, then helper bodies at PacketTransform root positions `20/30/40/50/60`.

## Source Ownership

Keep this state with [UID:0000M9][PacketTransform](by-file/PacketTransform.md) or a private packet-transform section of [UID:0000NS][Socket](by-file/Socket.md). The data is protocol transform state, not scalar [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) storage and not feature-send state.

`g_packetTransformKeyText` allocation/free is Socket lifecycle work, but its contents are produced and consumed by PacketTransform helpers. Keep the declaration here, with Socket cross-referenced for its exact 1,025-byte lifetime.

Socket command `13` writes `g_packetTransformLut`, and Socket encode/decode methods read the transform globals, but those consumer/writer facts do not make Socket the declaration owner. The current owner/emitter route through PacketTransform remains stronger because the initialized block belongs to the reusable transform helper/global family.

## Data Issues

- Resolved for [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md): the initialized alternate-size/LUT block should not be reconstructed from generated byte-array aliases. The source-ready declarations are `int g_packetXorAlternateSize`, private `static int s_packetTransformReserved`, and `unsigned int g_packetTransformLut[256]`.
- Remaining caveat: IDA still exposes raw aliases such as `Size` and `dword_66FE58`, and some generated/simroot code still emits byte-array-shaped `g_packetTransformLut` declarations. Keep those as search or stale-output caveats only; they should not override the dword source declaration.
- IDA currently types `dword_66FE58` as `int[130]` in some views; the command-13 fill loop writes 256 dwords, so treat the IDA type as under-sized until the database is corrected.
- Resolved for UID0002AL: the mutable state block owns exact zero-initialized declarations for the handshake seed, nonce scratch, packet-transform key-text pointer, stride, sequence byte plus private padding, and primary/alternate XOR tables.
- Remaining caveats are not declaration blockers: exact original spellings are inferred, the original source could have used a private `Socket.cpp` section, the three-byte post-sequence padding name is source-layout reconstruction, and raw UID0004ME has no recovered inbound route. Its complete retained source body and UID0004MF's live body are resolved.

## Cross-References

- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md)
- [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md)
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: added the source-closed PacketTransform header preamble and exact extern declaration surface consumed by Socket; definitions remain singular in the existing data children. The CPP channel contains a human header-ownership comment plus `[[CHILDREN]]`, preserving all initialized/mutable definitions while preventing a validator empty-emitter marker.

- 2026-07-13 B001 UID000244 global-flow synchronization:
  - Raised `88/90` to `90/92`, set root emitter position `10`, and preserved PacketTransform owner/emitter with blank aggregate C++ because exact data children emit declarations.
  - Replaced current source-facing `g_processArgList` with `g_packetTransformKeyText`; documented 1,025-byte Socket lifetime, exact 1,024-character producer, modulo-1,024 nonce consumer, one-digest nine-byte raw initializer, and positions.
  - Preserved initialized LUT/reserved-dword content, all mutable field boundaries, `g_packetXorAlternateSize`, `g_packetNonceScratch`, `g_packetXorTableAlternate`, Socket/PacketBuffer ownership rejections, and the full B004/B011/B013/B001 evidence chronology.

- 2026-07-06 B001 UID0001I5 helper-prototype sync:
  - Score/metadata unchanged at `88/90`, owner/emitter remain [UID:0000M9][PacketTransform](by-file/PacketTransform.md), and this broad global parent C++ block remains blank because exact initialized declarations live on [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) and exact mutable declarations live on [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md).
  - Summary/evidence: synchronized accepted B001 session `b001-0001I5` evidence for [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md): current IDB `sub_578E00`, source-facing `XorTransformBuffer`, exact range, six direct Socket transform call sites, no callees, source ABI order `source, destination, length, keyData, keyWordCount`, ignored residual return, and formal `void` helper C++. UID0001I5 is no longer part of this page's helper-prototype cap; raw `0x00575b90` liveness/source shape, exact original names, and source-file/private-section placement remain capped.
- 2026-07-04 B013 mutable-state declaration sync:
  - Changed to: score `88/90`; owner/emitter remain [UID:0000M9][PacketTransform](by-file/PacketTransform.md); this broad global parent C++ block remains blank because the exact initialized declarations live on [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) and the exact mutable declarations now live on [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md).
  - Summary/evidence: synchronized accepted B013 session `cbc24146` evidence for UID0002AL: active/healthy IDB, not-a-function endpoints, `0x84` / decimal `132` zero bytes, zero sampled ints, field xrefs, source-ready declarations for seed/scratch/pointer/stride/sequence/padding/primary table/alternate table, consumer decompiles, Socket allocation/free of `g_processArgList`, and StartupWindow successor boundary at `0x0069bac4`.
  - Preserved decisions: PacketTransform global ownership remains stronger than direct Socket ownership; PacketBuffer, StartupWindow merge, raw/no-owner, and aggregate-only alternatives remain rejected. Confidence stays below final-source level because exact original names, raw `0x00575b90` liveness/source shape, and file/private-section placement are still capped. UID0001I5's specific helper prototype was later resolved by B001 on 2026-07-06.
- 2026-07-03 B011 PacketNonceInitialization support sync:
  - Score unchanged at `86/88`; owner/emitter remain [UID:0000M9][PacketTransform](by-file/PacketTransform.md); this global parent C++ block remains blank because exact initialized declarations and exact helper bodies live on their own child targets.
  - Summary/evidence: synchronized accepted [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) report details from current MCP session `31debdf2`: exact `0xd3` / decimal `211` range, two Socket callers, three callees, default alternate size `9`, nonce/key-buffer formula, scratch range-check behavior, `g_packetNonceScratch`, `g_processArgList`, four `g_packetXorTableAlternate` windows, `sub_516220` as `memmove`, and formal first-draft C++ on the exact target. Preserved decisions: source-facing global names remain inferred, Socket direct declaration ownership remains rejected, raw/no-owner routing remains rejected, and exact source-file/private-section plus compiler range-check representation remain confidence caps.
- 2026-06-23 B004 MCP-backed redo support sync:
  - Historical state at that time: score unchanged at `86/88`; owner/emitter remained [UID:0000M9][PacketTransform](by-file/PacketTransform.md); this global parent C++ block remained blank because [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) owned the exact initialized declarations and mutable-state declarations were not yet final. The mutable-state declaration blocker is superseded by the 2026-07-04 B013 sync above.
  - Summary/evidence: replaced the stale B004 live-IDA-outage caveat with the accepted MCP-backed redo facts from session `b880584f`: endpoint/health/IDB path, executable SHA-256, `.data` placement, 11 xrefs/direct PE VA hits to `0x0066fe50`, zero MCP/PE route hits to `0x0066fe54`, dword writer routes to `0x0066fe58`, `XorTransformBuffer` dword key reads, value samples, and [UID:000287][0x00670258-0x00670260.SocketConnectionStringParsePointers](by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md) boundary proof.
  - Preserved decisions: keep `int g_packetXorAlternateSize`, private `static int s_packetTransformReserved`, and `unsigned int g_packetTransformLut[256]`; reject generated byte-array output, undersized IDA typing, direct Socket declaration ownership, PacketBuffer ownership, and no-owner/raw-data-island alternatives. Confidence remains capped by original spellings, reserved-dword intent, exact source-file/private-section placement, and broader helper prototypes rather than MCP availability.
- 2026-06-23 B004 initialized-LUT implementation sync:
  - Historical state at that time: score unchanged at `86/88`; owner/emitter remained [UID:0000M9][PacketTransform](by-file/PacketTransform.md); this global parent C++ block remained blank because [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) owned the exact initialized declarations and mutable-state declarations were not yet final. The mutable-state declaration blocker is superseded by the 2026-07-04 B013 sync above.
  - Summary/evidence: synchronized accepted [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) report details: `0x408` / decimal `1032` byte initialized `.data` block, private reserved zero dword at `0x0066fe54`, `unsigned int g_packetTransformLut[256]`, 256-entry/1024-byte dword sizing, source initializer rationale, repeated-byte proof, rejected byte-array/undersized IDA typing, [UID:000287][0x00670258-0x00670260.SocketConnectionStringParsePointers](by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md) boundary, Socket consumer rejection, and generated/simroot caveats. The original implementation inherited an offline-only B004 outage caveat; that wording is superseded by the MCP-backed redo support sync above.
- 2026-06-07 A001 parent-gate refresh:
  - What existed before: score `82/86`; this blocked assigning the exact initialized LUT child under the corrected `85/85` direct-parent gate.
  - Changed to: score `85/87`.
  - Summary/evidence: fresh IDA MCP `py_eval` reconfirmed the initialized alternate-size/LUT bytes and xrefs, the mutable transform-state xrefs and boundary at `0x0069bac4`, and the helper/file parent relationship now that [UID:0000M9][PacketTransform](by-file/PacketTransform.md) is `88/85`. This historical final-declaration blocker is superseded for the two exact global-data children by the B004 initialized-LUT and B013 mutable-state declaration implementations; helper prototypes and original source placement remain current caps.
- 2026-06-16 C001 global/source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter remain [UID:0000M9][PacketTransform](by-file/PacketTransform.md); final C++ remains blank.
  - Summary/evidence: live IDA reconfirmed alternate-size/LUT refs, mutable-state refs, nonce and handshake decompilation behavior, and Socket lifetime use of `0x0069ba58`; IDA function names for the core helper family were improved and saved. The final C declaration blocker named here is historical for the exact global-data children after the B004 and B013 declaration syncs; original file spelling versus private Socket section and raw-helper liveness remain current caps. UID0001I5's specific helper prototype/order was resolved by B001 on 2026-07-06.
- 2026-06-07 A007 exact range sync:
  - What existed before: the page had the correct address/name/role map and PacketTransform parent attachment, but did not explicitly link the exact initialized LUT range and mutable state range in the status/cross-reference sections, and its score still reflected the pre-split state summary.
  - Changed to: scores `82/86`, explicit exact-range boundary notes for `0x0066fe50-0x00670258` and `0x0069ba40-0x0069bac4`, and cross-links to the now-attached nonce and handshake helper pages.
  - Summary/evidence: the linked memory pages bound the initialized alternate-size/LUT block and mutable handshake/nonce/table block, while the nonce and handshake helper pages document the concrete reads/writes into the fields listed here. This broad global parent C++ block remains blank because exact declarations live on child pages and final source-facing names are not final-audit quality.
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
