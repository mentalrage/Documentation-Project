*** UID:0000V3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Free-helper declarations are provided by PacketTransform.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InitializePacketTransformAlternateKey(char *keyText);
void BuildPacketTransformKeyText(char *keyText);
void InitializePacketNonce(unsigned short nonceBase,
                           unsigned char nonceMiddle);
void BuildHandshakeBlock(size_t seedLength, void *seedBlock);
void XorTransformBuffer(const unsigned char *source,
                        unsigned char *destination,
                        unsigned int length,
                        const void *keyData,
                        unsigned int keyWordCount);
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Packet Transform Helpers

## Status

- Confidence: very strong for exact helper behavior, boundaries, caller/data flow, split, and current source shapes; medium-high for exact original filenames and private identifier spellings.
- Likely source module: [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- Related class: [UID:0000DD][Socket](by-class/Socket.md)
- Related globals: [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- Exact initialized state: [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md)
- Exact mutable state: [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md), now source-ready for exact mutable global declarations.
- Evidence basis: local generated-output context plus IDA MCP lookup/xref/decompile/disassembly checks on 2026-05-24, 2026-05-25, 2026-06-02, 2026-06-14, and an A001 2026-06-16 live IDA/PE reachability refresh.

## Helpers

| Address | Current name | Role |
| --- | --- | --- |
| `0x00575b90` | [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) | Retained no-route helper; one MD5 digest, first nine bytes to scratch, four alternate-table windows, CRT free. |
| `0x00575c30` | [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) | Live login-derived helper; double-hash seed plus 31 successive digest appends into `g_packetTransformKeyText`. |
| `0x00575cb0` | `InitializePacketNonce` | Derives the alternate per-packet XOR table from nonce bytes and process/key material. |
| `0x00577030` | source-facing `BuildHandshakeBlock` / current IDA `sub_577030` | Builds the primary handshake seed table and records the primary transform stride. |
| `0x00578e00` | source-facing `XorTransformBuffer` / current IDA `sub_578E00` | Applies repeated-key XOR to dword blocks and trailing bytes; first-draft C++ ready after B001 session `b001-0001I5`. |

The packet digest helper at `0x00515380` is intentionally excluded from this table. It is the packet-facing wrapper in the shared [UID:0000L6][MD5](by-file/MD5.md) utility family.

## Call Relationships

- `BuildHandshakeBlock` is called by the [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) constructor and by `Socket::HandleSocketCommand` command `14`.
- `BuildPacketTransformKeyText` is called once by [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) after CP_ACP login-name conversion into a 128-byte local buffer.
- `InitializePacketNonce` is called by [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md).
- `XorTransformBuffer` is called three times by `Socket::TransformFramePayload` and three times by `Socket::BuildEncryptedPacket`.
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) additionally calls [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md) after the XOR passes, then copies selected digest bytes into the outbound trailer.

## Behavioral Notes

- `BuildHandshakeBlock` copies an incoming seed block, mutates bytes 3 and 6, copies the seed into four consecutive primary table windows, restores bytes 3 and 6 to literal `c` and `t`, then frees the seed block. B012's 2026-07-03 target pass confirms current IDA session `31debdf2` still names this function `sub_577030`; `BuildHandshakeBlock` is the accepted source-facing documentation/C++ name rather than current IDB symbol proof.
- `InitializePacketTransformAlternateKey` calls `GetMemoryMan`, computes one heap `Md5StringHex(keyText)`, copies exactly `g_packetXorAlternateSize` bytes (initialized to nine) to `g_packetNonceScratch`, copies that prefix to four `g_packetXorTableAlternate` windows, and frees the digest through CRT `free`.
- `BuildPacketTransformKeyText` computes `firstDigest = Md5StringHex(keyText)` and `secondDigest = Md5StringHex(firstDigest)`, writes the second digest with `sprintf_s(..., 1025, "%s", ...)`, frees both, then performs exactly 31 `Md5StringHex(currentText)` / bounded `"%s%s"` append / free iterations. The output is exactly 1,024 characters plus NUL, not a duplicate or self-concatenation.
- `InitializePacketNonce` uses `nonceMiddle * nonceMiddle` and an incrementing offset to index `g_packetTransformKeyText` modulo 1,024, writes scratch bytes, preserves the `Size >= 12` range-check failure edge before terminating them with zero, and copies the scratch bytes into four alternate table windows. B011's exact child remains first-draft C++ ready through [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md).
- `XorTransformBuffer` processes `len >> 2` dword blocks with `key[index % step]`, then handles one to three trailing bytes from the next key word. B001's 2026-07-06 MCP-backed pass resolves the exact helper prototype as `void XorTransformBuffer(const unsigned char *source, unsigned char *destination, unsigned int length, const void *keyData, unsigned int keyWordCount)` with source ABI order `source, destination, length, keyData, keyWordCount`.
- The shared global state is address-backed: source-ready initialized alternate size `0x0066fe50`, private reserved zero dword `0x0066fe54`, dword LUT `0x0066fe58`, handshake seed `0x0069ba40`, nonce scratch `0x0069ba4c`, packet-transform key-text pointer `0x0069ba58`, stride `0x0069ba5c`, sequence byte `0x0069ba60`, primary table `0x0069ba64`, and alternate table `0x0069ba94`.
- [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) now resolves the initialized declaration subset as `int g_packetXorAlternateSize = 9;`, private `static int s_packetTransformReserved = 0;`, and `unsigned int g_packetTransformLut[256]`. The prior global-declaration blocker is no longer active for UID0001I5.
- The exact writable state block [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) resolves the mutable declaration subset as `unsigned char g_handshakeSeedBytes[12]`, `unsigned char g_packetNonceScratch[12]`, `char *g_packetTransformKeyText`, `int g_packetTransformStride`, `unsigned char g_packetSequenceByte`, private `static unsigned char s_packetTransformSequencePadding[3]`, `unsigned char g_packetXorTablePrimary[48]`, and `unsigned char g_packetXorTableAlternate[48]`. Socket allocates/frees 1,025 bytes, UID0004MF fills 1,024 characters plus NUL, and UID0001I0 consumes indexes modulo 1,024.

## Signature Status

Historical generated output was inconsistent for UID0001I5:

- the recovered helper body returns `std::uint8_t`;
- `class_Socket.cpp` declares it as returning `void`;
- some `Socket::BuildEncryptedPacket` call sites pass byte pointers while the extern declaration expects `std::uint32_t*` and `int`.

B001's 2026-07-06 pass resolves the exact UID0001I5 source-facing form as a `void` byte-buffer helper with source ABI order `source, destination, length, keyData, keyWordCount`. Current MCP session `b001-0001I5` reports the IDB name as `sub_578E00`, not `XorTransformBuffer`, so `XorTransformBuffer` remains the accepted source-facing docs/C++ name rather than current IDB symbol proof. IDA still infers a `char __stdcall(int, int, unsigned int, int, int)` signature from residual `EAX`, but all six live callers ignore the return value; the helper's source role is side-effect-only buffer transformation.

The initialized LUT and mutable declarations are no longer blockers: UID000286 resolves `g_packetTransformLut` as `unsigned int[256]`, and UID0002AL resolves exact zero-initialized storage including `g_packetTransformKeyText`. UID0004ME/UID0004MF now resolve the raw/live helper split and complete bodies. Remaining uncertainty is limited to original private spellings and separate-file versus private-`Socket.cpp` placement.

IDA MCP rechecks on 2026-05-31 and 2026-06-02 confirm `0x00575c30-0x00575caa`, `0x00575cb0-0x00575d83`, `0x00577030-0x0057713d`, and `0x00578e00-0x00578e94` as real functions with the caller relationships listed above. The same rechecks report `0x00575b90` as not modeled as an IDA function, so the string-key helper remains a raw/IDA-missed helper range until its exact boundary and source shape are separately verified.

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed the same cluster:

- `lookup_funcs` reports no modeled function at `0x00575b90`, then modeled helpers at `0x00575c30` size `0x7a`, `0x00575cb0` size `0xd3`, `0x00577030` size `0x10d`, and `0x00578e00` size `0x94`.
- `xrefs_to` still reports no direct xrefs to raw start `0x00575b90`; one xref to `0x00575c30` at `0x004f8544`; two xrefs to nonce initialization at `0x00578b72` and `0x00578cd2`; two xrefs to handshake setup at `0x00574880` and `0x00576181`; and six xrefs to `XorTransformBuffer` at `0x00578bb2`, `0x00578bed`, `0x00578c26`, `0x00578d27`, `0x00578d67`, and `0x00578d99`.
- Targeted decompilation reconfirmed the `0x00575c30` login/process text expander uses `"%s"` followed by a 31-iteration (`0x1f`, verified with `int_convert.py`) `"%s%s"` expansion loop; `InitializePacketNonce` derives scratch bytes from `nonceMiddle * nonceMiddle` and copies the scratch block into four alternate-table windows; `BuildHandshakeBlock` copies a seed into four primary-table windows and records the stride; `XorTransformBuffer` handles `len >> 2` dword blocks plus `len & 3` trailing bytes with key-index modulo stride. B011's later 2026-07-03 session `31debdf2` adds current proof that `sub_516220` is a `memmove` wrapper, the nonce helper has exactly two Socket callers and three callees, and the exact target can carry formal first-draft C++.

2026-06-16 A001 live IDA/PE refresh adds source-quality evidence for the remaining blockers:

- Current IDA names from the 2026-06-16 session included `PacketTransform_ExpandProcessArgKeyText` at `0x00575c30`, `InitializePacketNonce` at `0x00575cb0`, `BuildHandshakeBlock` at `0x00577030`, and `XorTransformBuffer` at `0x00578e00`; B012's 2026-07-03 session `31debdf2` supersedes the current-name state for `0x00577030` only, resolving it as `sub_577030` while retaining `BuildHandshakeBlock` as the source-facing docs/C++ name.
- `lookup_funcs` still reports no function at raw `0x00575b90`, while `insn_query` over `0x00575b90-0x00575c30` decodes a complete stack-frame helper ending in `retn 4` and writing four alternate-table windows through `0x0069ba94`.
- `xrefs_to` and the PE scan agree on reachability: no direct call, branch, absolute VA, or RVA reference targets raw `0x00575b90`; modeled direct calls are one to `0x00575c30`, two to `0x00575cb0`, two to `0x00577030`, and six to `0x00578e00`.
- Current decompilation reconfirms `0x00575c30` as a login/process string expander with `"%s"` and `"%s%s"`, `InitializePacketNonce` as the alternate nonce-table builder, `BuildHandshakeBlock` as the primary table/stride builder, and `XorTransformBuffer` as the leaf repeated-key XOR primitive.

The raw-start route remains negative after exhaustive start/interior xrefs, control-route, pointer-encoding, duplicate-body, table/callback, and EH/compiler checks. UID0004ME is retained/unrouted project source because its complete one-argument body, MD5/MemoryMan calls, global writes, unique bytes, and clean boundaries are independently source-shaped. No later route discovery is required to emit the accepted body; no-route evidence remains a confidence cap.

2026-06-02 IDA MCP `xrefs_to` reconfirms:

| Helper | Direct xrefs |
| --- | --- |
| `0x00575c30` | `0x004f8544` in [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) |
| `0x00575cb0` | `0x00578b72` in [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md), `0x00578cd2` in [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) |
| `0x00577030` | `0x00574880` in [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), `0x00576181` in [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md) |
| `0x00578e00` | `0x00578bb2`, `0x00578bed`, `0x00578c26` in `SocketTransformFramePayload`; `0x00578d27`, `0x00578d67`, `0x00578d99` in `SocketBuildEncryptedPacket` |

## Ownership Decision

These helpers should be reconstructed as packet/protocol transform support, not as [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) scalar helpers and not as feature send code. `Socket` owns the methods that decide when to decode or encode packets; `PacketTransform` owns the reusable key-table and XOR operations.

The overview reconstructed C++ block remains blank because it is a family inventory, not an original standalone source body. Exact children UID0004ME, UID0004MF, UID0001I0, UID0001I2, UID0002AL, and UID0001I5 carry their own complete bodies/declarations. Blank overview C++ prevents duplicate output and no longer signals an unresolved source blocker.

The overview remains PacketTransform-owned/emitted for inventory routing, while exact source is ordered as globals `10`, UID0004ME `20`, UID0004MF `30`, nonce `40`, handshake `50`, and XOR `60`. Socket, MD5, MemoryMan, and PacketBuffer remain context/dependency/adjacency rather than direct owners.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `91` | The overview now ties every helper to exact source children, complete string-key behavior, MD5/formatter/free roles, globals and lifecycle, caller/xrefs, raw negative-route proof, deterministic order, and no-duplicate aggregate policy. |
| Confidence `93` | Direct IDA/PE evidence and exact child pages resolve behavior, split, source shapes, globals, owner, and all active C++ blockers. Original private names and file organization remain inferred. |

## Cross-References

- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md)
- [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md)
- [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md)
- [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: added the complete PacketTransform helper declaration surface for the Socket consumer; exact function definitions remain owned by their existing child pages. The CPP channel contains only a human header-ownership comment so this intentional H-only support node does not produce a validator empty-emitter marker.

- 2026-07-13 B001 UID000244 helper-family synchronization:
  - Raised `88/90` to `91/93` after exact children UID0004ME/UID0004MF closed the raw/live split, MD5, formatter, global naming, and C++ blockers.
  - Added the complete one-digest nine-byte alternate initializer, double-hash seed, 31 successive digest appends, 1,025-byte lifecycle, 1,024-character output, MainUiGraph caller, raw no-route/unique-body evidence, and root position order.
  - Replaced current source-facing `g_processArgList` with `g_packetTransformKeyText`; retained old `ArgList`/`g_processArgList`, duplicate-string, self-concatenation, and raw-deferral wording only in dated historical change records.
  - Preserved later nonce/handshake/XOR/global evidence and kept overview C++ blank solely because exact children emit.

- 2026-07-06 B001 UID0001I5 source-quality sync:
  - Raised completion/confidence from `87/89` to `88/90`.
  - Summary/evidence: synchronized exact child [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) with B001 MCP session `b001-0001I5`: active/healthy IDB, current IDB `sub_578E00`, source-facing `XorTransformBuffer`, exact `0x94` / decimal `148` range, six direct Socket transform call sites, no callees, dword-key modulo loop, tail-byte paths, source ABI order `source, destination, length, keyData, keyWordCount`, ignored residual return, formal `void` helper C++, and boundary before the unrelated `UNL.DLL` helper. This overview C++ block remains blank because raw `0x00575b90` liveness/source shape and aggregate placement remain unresolved; UID0001I5 is no longer part of the helper-prototype blocker.
- 2026-07-04 B013 mutable-state declaration sync:
  - Score/metadata were unchanged at `87/89`, owner/emitter [UID:0000M9][PacketTransform](by-file/PacketTransform.md), and this overview C++ block remained blank.
  - Summary/evidence: synchronized exact child [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) with B013 current MCP session `cbc24146`: active/healthy IDB, not-a-function target endpoints, `0x84` / decimal `132` zero bytes, zero sampled ints, field xrefs, consumer decompiles, Socket allocation/free of `g_processArgList`, clean StartupWindow successor boundary, and formal declarations for seed, scratch, process pointer, stride, sequence byte, private padding, and primary/alternate tables. This overview's aggregate no-code policy remains limited to raw `0x00575b90` liveness/source shape and does not block the exact UID0002AL data declarations.
- 2026-07-03 B011 PacketNonceInitialization support sync:
  - Score/metadata unchanged at `87/89`, owner/emitter [UID:0000M9][PacketTransform](by-file/PacketTransform.md), and this overview C++ block remains blank.
  - Summary/evidence: synchronized the exact child [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) with B011 current MCP session `31debdf2`: current IDA resolves `0x00575cb0` as `sub_575CB0`, while `InitializePacketNonce` remains the accepted source-facing docs/C++ name; B011 reconfirmed size `0xd3` / decimal `211`, two Socket callers, three callees, default alternate size `9`, key-buffer formula, scratch range-check behavior, `g_packetNonceScratch`, `g_processArgList`, four `g_packetXorTableAlternate` windows, `sub_516220` as `memmove`, and following `0xcc` alignment. The exact child now has formal first-draft C++, so this overview's aggregate no-code policy is limited to unresolved family-wide prototypes/raw `0x00575b90` liveness and does not block that exact child.
- 2026-07-03 B012 BuildHandshakeBlock support sync:
  - Score/metadata unchanged at `87/89`, owner/emitter [UID:0000M9][PacketTransform](by-file/PacketTransform.md), and this overview C++ block remains blank.
  - Summary/evidence: synchronized the exact child [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md) with B012 current MCP session `31debdf2`: current IDA resolves `0x00577030` as `sub_577030`, while `BuildHandshakeBlock` remains the accepted source-facing docs/C++ name; the child now has formal first-draft C++, so this overview's aggregate no-code policy is limited to unresolved family-wide prototypes/raw `0x00575b90` liveness and does not block that exact child.
- 2026-06-23 B004 initialized-LUT support sync:
  - Score/metadata unchanged at `87/89`, owner/emitter [UID:0000M9][PacketTransform](by-file/PacketTransform.md), and blank C++.
  - Summary/evidence: linked [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) as exact initialized state, recorded that `g_packetTransformLut` is now source-ready as `unsigned int[256]`, preserved the rejected generated byte-array/undersized IDA typing caveat, and kept helper C++ blocked at that time by raw `0x00575b90` liveness plus unresolved helper prototypes. UID0001I5's specific helper prototype was later resolved by B001 on 2026-07-06.
- 2026-06-16 A001 packet/path item refresh:
  - Raised completion/confidence from `85/88` to `87/89`.
  - Evidence: live IDA reconfirmed current names/sizes for `PacketTransform_ExpandProcessArgKeyText`, `InitializePacketNonce`, then-source-facing `BuildHandshakeBlock`, and `XorTransformBuffer`; B012's 2026-07-03 current MCP session supersedes only the current-name state for `0x00577030`, resolving it as `sub_577030`; `insn_query` decoded raw `0x00575b90-0x00575c30`; `xrefs_to` and a PE direct-reference scan confirmed no direct reachability to raw `0x00575b90` and exact modeled direct-call counts for the live helpers.
  - Routing: owner/emitter remains [UID:0000M9][PacketTransform](by-file/PacketTransform.md). Final overview C++ remained blank because raw-helper liveness, final prototypes, transform-global names, and original separate-file versus private `Socket.cpp` placement were source-quality blockers at that time. UID0001I5's specific helper prototype and transform-global declaration blockers were later resolved by B001/B004/B013; raw `0x00575b90` and aggregate source placement remain capped.

- 2026-06-02: Raised grading to `74/82` and attached to [UID:0000M9][PacketTransform](by-file/PacketTransform.md) after setting the parent projected path. IDA MCP rechecked helper starts and xrefs: `0x00575b90` remains raw/no-function, while `0x00575c30`, `0x00575cb0`, `0x00577030`, and `0x00578e00` retain the documented function ranges and callers. C++ remains blank because final prototypes and raw helper shape are still unresolved.
- 2026-06-07 A009 overview synchronization: raised to `82/86`, added the exact mutable-state page and score rationale, and aligned the overview with the stronger child pages for string-key setup, nonce initialization, handshake setup, XOR transform, transform globals, Socket callers, and digest exclusion. C++ remains blank because the raw `0x00575b90` helper liveness and final prototypes are not source-quality.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/70` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented packet transform helpers, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the group as rebuild-relevant packet transform code, while staying below high confidence because `0x00575b90` is still not an IDA-modeled function and final signatures remain open.
  - Evidence: IDA MCP confirms the exact modeled helper ranges and call relationships for `0x00575c30`, `0x00575cb0`, `0x00577030`, and `0x00578e00`, while also confirming the no-function caveat at `0x00575b90`.
- 2026-06-14 A001: Raised completion/confidence from `82/86` to `85/88`.
  - Before: the overview depended on prior child-page synchronization for the helper cluster.
  - After: added a current live IDA MCP refresh for modeled helper sizes, raw/no-xref status, xrefs, decompiled string expansion, nonce/handshake table replication, and XOR block/trailing-byte behavior.
  - Evidence: `lookup_funcs`, `analyze_function`, `xrefs_to`, targeted decompile checks, and `int_convert.py` for the 31/`0x1f` loop count. Final overview C++ remains blank because raw-helper liveness and aggregate source placement remain below source-quality evidence; exact UID0001I5 helper C++ is now resolved separately.
