*** UID:0000V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Packet Digest Helper - 0x00515380

## Status

- Confidence: strong for behavior, parent ownership, exact caller consumption, and returned stack-buffer behavior; medium for final source signature.
- Proposed owner: [UID:0000L6][MD5](by-file/MD5.md), not [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- Memory range: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- Evidence basis: existing IDA MCP lookup/xref/decompile/callee records in the MD5 and Socket memory pages through 2026-06-13, live IDA MCP `lookup_funcs`, `analyze_function`, and `disasm` checks on 2026-06-14, and an A001 2026-06-16 live IDA/PE reachability refresh.

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

## 2026-07-26 B001 Transient-Pointer Contract Resolution

Exact source ownership and behavior now live on [UID:0004XE][0x00515380-0x005153dc.Md5BytesRaw](by-memory/0x00515380-0x005153dc.Md5BytesRaw.md). The helper constructs a local `MD5`, updates/finalizes it, and deliberately returns `md5.digest`, a pointer into that local stack object. The sole call at `0x00578da5` immediately consumes bytes in the exact order `digest[13]`, `digest[3]`, `digest[11]`, and `digest[7]` before later stack use can overwrite the storage.

That lifetime is undefined by modern C++ rules but is the observed executable contract. Reconstruction must not silently replace it with a caller output buffer, static/heap storage, hidden sret, value object, or safe container. This item documents the packet-facing consumption only; it does not duplicate the MD5 wrapper body and does not change PacketTransform/Socket ownership of the consumer.

The former open question about a "safe source representation" is therefore resolved: faithful first-draft source is the direct local-digest pointer return on UID0004XE, paired with this exact immediate indexed consumption. The remaining uncertainty is only the unrecoverable original wrapper spelling, not behavior or source placement.

## 2026-06-14 Stack Return Evidence

Live IDA MCP session `a001_goal2_class_batch` reconfirmed `sub_515380` as size `0x5c`, prototype `char *__cdecl(void *Src, int)`, with exactly one caller `sub_578C40`.

Disassembly resolves the previously open returned-buffer lifetime question enough to document the binary behavior:

| Address | Instruction / effect | Meaning |
| --- | --- | --- |
| `0x00515390-0x005153a3` | Pushes `length` and `Src`; loads `ecx = &context` | Sets up an MD5 context on the stack and passes input to `Md5Update`. |
| `0x0051539c-0x005153b7` | Stores `0x67452301`, `0xefcdab89`, `0x98badcfe`, `0x10325476`; clears bit count | Initializes standard MD5 state. |
| `0x005153be` | Calls `sub_515690` | Updates the stack MD5 context with caller-provided bytes. |
| `0x005153c3-0x005153c6` | Loads `ecx = &context`; calls `sub_515750` | Finalizes into the digest field inside the same stack context. |
| `0x005153ce` | `lea eax, [ebp+var_18]` | Returns a pointer to the 16-byte digest storage inside the callee's stack frame. |
| `0x005153d3` | Calls `__security_check_cookie` before returning | Compiler security-cookie epilogue; not hash logic. |

The sole caller [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) consumes that transient pointer immediately after the call:

| Caller address | Operation | Meaning |
| --- | --- | --- |
| `0x00578da5` | Calls `sub_515380(output, inputLength + 1)` | Hashes the transformed outbound packet prefix. |
| `0x00578dad` | Reads `[eax+0x0d]` | First trailer digest byte. |
| `0x00578db4` | Reads `[eax+0x03]` | Second trailer digest byte. |
| `0x00578dbb` | Reads `[eax+0x0b]` | Third trailer digest byte. |
| `0x00578dc3` | Reads `[eax+0x07]` | Fourth trailer digest byte. |

This confirms the binary's unsafe-looking return-storage behavior rather than resolving it into a safe final source signature. A final reconstruction may intentionally preserve the original warning-prone pattern or refactor through an equivalent caller-local digest buffer, but that decision still needs source-quality integration with the MD5 utility declarations and Socket packet builder.

## 2026-06-16 Reachability Refresh

A001 rechecked the current IDA database and read-only PE bytes for the unresolved caller/source-shape blockers:

- `lookup_funcs` still reports `sub_515380` at `0x00515380`, size `0x5c`; `0x005153dc` is not a function and `sub_5153E0` begins at `0x005153e0`.
- `analyze_function` reconfirms one basic block, prototype `char *__cdecl(void *Src, int)`, MD5 constants `0x67452301`, `0xefcdab89`, `0x98badcfe`, and `0x10325476`, callees `0x00515690`/`0x00515750` plus the security-cookie check, and exactly one caller at `0x00578c40`.
- `disasm` reconfirms the return is `lea eax, [ebp+var_18]` before the cookie epilogue, so the transient stack-digest behavior is a real binary fact.
- `xrefs_to` and the PE scan both find exactly one direct `E8` reference to this helper, at `0x00578da5`; the scan found no absolute VA/RVA pointer references to `0x00515380`.
- The same PE scan found no direct call, branch, absolute VA, or RVA reference to raw sibling starts `0x00515310` or `0x00515450`, keeping those siblings separate from this live packet-facing digest wrapper.

This resolves the reachability question for this helper: it is a live MD5 utility called only by Socket outbound packet framing. The remaining blocker is source representation, not behavior: the docs still cannot safely choose between preserving the original stack-return idiom and rewriting Socket to use the neighboring caller-buffer digest wrapper.

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

## Current Dependency Boundary

| Neighbor or consumer | Current role | Boundary decision |
| --- | --- | --- |
| [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) | Parent MD5 helper island with modeled wrappers, raw wrapper starts, update/final/transform, caller map, and padding evidence. | This item is the packet-facing raw-digest wrapper inside the MD5 island, not a separate packet module. |
| [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) | Raw byte-buffer-to-hex wrapper with no current IDA function object or callers. | Keeps the byte-buffer hex API separate from this raw-digest API; the two wrappers share MD5 update/final behavior but return different representations. |
| `0x005153e0-0x00515445` inside [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) | Modeled bytes-to-caller-buffer wrapper used by [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). | Best comparison point for finalizing this helper's safer C++ signature because it proves the module already has a caller-supplied 16-byte digest-buffer variant. |
| [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) and `0x00515570` stream wrapper | File/stream hex digest path used by screenshot proof and fallback file hashing. | Confirms MD5.cpp is a shared utility across packet, registry, startup, and screenshot code; it should not be folded into Socket or PacketTransform. |
| [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) | Sole direct caller of `0x00515380`; consumes bytes `[13]`, `[3]`, `[11]`, and `[7]` for outbound frame trailer. | Socket owns packet framing and digest-byte placement; MD5 owns the digest calculation. |
| [UID:0000M9][PacketTransform](by-file/PacketTransform.md) and [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md) | Own nonce/key-table setup, string-key expansion, repeated-key XOR, transform LUT, and transform globals. | PacketTransform depends on MD5 for trailer digest bytes but does not own this helper's algorithm or source placement. |

## Rewrite Notes

- The current disassembly confirms a pointer to transient stack digest storage: `0x005153ce` returns `&var_18`, and `Socket::BuildEncryptedPacket` reads bytes from that pointer immediately at `0x00578dad`, `0x00578db4`, `0x00578dbb`, and `0x00578dc3`. Do not blindly turn this into a normal long-lived pointer API.
- A caller-provided 16-byte output buffer or a small returned digest object may be the safer reconstruction signature. The neighboring `Md5BytesToBuffer` wrapper proves a caller-buffer variant already exists, but the final signature choice must still preserve `Socket::BuildEncryptedPacket` byte selection exactly.
- Keep the generated `ComputePacketDigest` name only as a packet-context alias; the underlying function should use an MD5-specific name in the utility module.
- Leave reconstructed C++ blank until the returned-buffer lifetime is proven from raw assembly or reconciled with the neighboring `Md5BytesToBuffer` wrapper at `0x005153e0`.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Documents exact range, MD5 state initialization, update/final callees, sole Socket caller, digest byte order, MD5-vs-PacketTransform ownership, neighbor-wrapper boundaries, generated route to `MD5.cpp`, stack-return behavior, and current PE reachability/pointer checks. Still below final-code level because final source signature and integration with the safer buffer wrapper are unresolved. |
| Confidence | 89 | Strong from fresh IDA function analysis/disassembly, Socket caller disassembly, PE reachability checks, and existing MD5/Socket memory pages. Capped because the source-level representation of the original unsafe return-storage pattern remains a reconstruction decision. |

## Cross-References

- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)

## Changes

- 2026-07-26 B001 UID0001B6 callback:
  - Kept this packet item on its existing owner/emitter route and score, linked exact source child UID0004XE, recorded the complete transient stack-pointer contract and immediate byte order `13/3/11/7`, rejected behavior-changing safety rewrites, and avoided duplicating the MD5 helper body here.

- 2026-06-16 A001 packet/path item refresh:
  - Raised completion/confidence from `85/88` to `86/89`.
  - Evidence: live IDA MCP reconfirmed the `0x00515380-0x005153dc` function, sole `0x00578da5` caller, MD5 constants/callees, stack-digest return, and adjacent `0x005153e0` function start. A read-only PE scan found only that direct `E8` call and no absolute VA/RVA references to this helper or the raw sibling starts `0x00515310` and `0x00515450`.
  - Routing: owner/emitter remains [UID:0000L6][MD5](by-file/MD5.md); [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) remains the sole Socket caller. Final C++ remains blank because the exact safe source representation of the stack-return digest pointer is still unresolved.

- 2026-06-14 A003 Goal 2 low-confidence item refresh:
  - Raised completion/confidence from `80/84` to `85/88`.
  - Evidence: live IDA MCP reconfirmed `sub_515380` size `0x5c`, sole caller `sub_578C40`, standard MD5 initialization, calls to `Md5Update`/`Md5Final`, and disassembly showing `lea eax, [ebp+var_18]` as the returned digest pointer. Caller disassembly at `0x00578da5-0x00578dc7` confirms immediate consumption of digest bytes `[13]`, `[3]`, `[11]`, and `[7]`.
  - Routing: owner/emitter remains [UID:0000L6][MD5](by-file/MD5.md); generated item coverage resolves it to `auto-generated/NexusTK/util/MD5.cpp` with no dead end.
  - C++ remains blank because the source-quality representation of the confirmed stack-return behavior is still unresolved.

- 2026-06-02: Raised from `50/75` to `76/82` and attached to [UID:0000L6][MD5](by-file/MD5.md).
  - Added boundary/alignment evidence, MD5 callee table, Socket caller/trailer evidence, and MD5-island placement table from existing IDA-backed MD5/Socket docs.
  - Left reconstructed C++ blank because the final source signature and returned digest storage lifetime are still unresolved.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/75` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet digest helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper as rebuild-relevant code while staying conservative because the final signature/lifetime model is still open.
  - Evidence: IDA MCP confirms the exact range, sole `Socket::BuildEncryptedPacket` caller, and MD5 update/final callees.
- 2026-06-07 A009: Raised completion/confidence from `76/82` to `80/84`.
  - Before: the page documented the helper's range, caller, MD5 ownership, and trailer byte order, but did not summarize the current boundary against the newer raw MD5 helper pages, the modeled bytes-to-buffer wrapper, screenshot/file/stream digest paths, and PacketTransform keep-out docs.
  - After: added a dependency-boundary table and sharpened the rewrite blocker around transient digest storage versus a caller-buffer/source-object signature. C++ remains blank because the exact return-storage lifetime and final source-facing signature are still below the final-source gate.
