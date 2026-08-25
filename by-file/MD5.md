*** UID:0000L6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MD5

## Status

- Confidence: very strong for algorithm, exact class layout, complete body split, cross-subsystem utility ownership, source/header placement, caller contracts, data order, and formal output; strong for inferred original private spellings and exact historical filename.
- Proposed module: `NexusTK/util/MD5.cpp` with sibling `NexusTK/util/MD5.h`.
- Current generated source route: non-range class/source container [UID:0004X5][MD5](by-class/MD5.md) emits through this file root and assembles all exact data/function children without `sub_`, `dword_`, `MD5Context`, or duplicated bodies.
- Main address doc: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- Related item doc: [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- Raw helper docs: [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) and [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md)
- Evidence basis: `simroot_v2` generated callers plus IDA MCP lookup/xref/decompile/instruction checks on 2026-05-24, 2026-05-25, 2026-05-31, the 2026-06-16 A001 file-confidence refresh, the 2026-06-25 B005 file-helper implementation, and the 2026-06-26 B007 bytes-helper implementation. `wave3.py` was not executed for this pass.

## 2026-07-26 B001 Complete Source Model

The implemented source model is a project-owned C++ class `MD5`, exact size `0x68`, under `NexusTK/util/MD5.cpp` and `.h`. The class stores `unsigned int state[4]` at `+0x00`, `unsigned int count[2]` at `+0x10`, `unsigned char buffer[64]` at `+0x18`, and public `unsigned char digest[16]` at `+0x58`. The constructor calls private `Init`; `Update` and `Final` are public; `Transform`, `Encode`, and `Decode` are private. No vtable/base/padding/endian field is present.

[UID:0004X5][MD5](by-class/MD5.md) owns CPP/H framing, class declaration, includes, and conventional MD5 round macros. It emits through this file root at position `0`. Its direct source-order children are [UID:00027R][0x0066ddd8-0x0066de18.Md5PaddingBlock](by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md) position `0`, [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) position `10`, and [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md) position `20`. The out-of-range data and endian sibling never become children of UID0001B6.

UID0001B6 emits these exact in-range children in address order:

| Position | UID | Source entity | Exact range |
| ---: | --- | --- | --- |
| `0` | [UID:0004XC][0x005151f0-0x00515284.Md5DigestToHexString](by-memory/0x005151f0-0x00515284.Md5DigestToHexString.md) | free wrapper | `0x5151f0-0x515284` |
| `10` | [UID:0004XD][0x00515290-0x0051530a.Md5StringHex](by-memory/0x00515290-0x0051530a.Md5StringHex.md) | free wrapper | `0x515290-0x51530a` |
| `20` | [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) | raw free wrapper | `0x515310-0x515375` |
| `30` | [UID:0004XE][0x00515380-0x005153dc.Md5BytesRaw](by-memory/0x00515380-0x005153dc.Md5BytesRaw.md) | free transient-pointer wrapper | `0x515380-0x5153dc` |
| `40` | [UID:0004XF][0x005153e0-0x00515445.Md5BytesToBuffer](by-memory/0x005153e0-0x00515445.Md5BytesToBuffer.md) | free output-buffer wrapper | `0x5153e0-0x515445` |
| `50` | [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) | raw file wrapper; actual end `0x515569` | `0x515450-0x515569` |
| `60` | [UID:0004XG][0x00515570-0x0051565b.Md5StreamHex](by-memory/0x00515570-0x0051565b.Md5StreamHex.md) | free stream wrapper | `0x515570-0x51565b` |
| `70` | [UID:0004XH][0x00515660-0x00515684.MD5Init](by-memory/0x00515660-0x00515684.MD5Init.md) | raw member | `0x515660-0x515684` |
| `80` | [UID:0004XI][0x00515690-0x00515744.MD5Update](by-memory/0x00515690-0x00515744.MD5Update.md) | member | `0x515690-0x515744` |
| `90` | [UID:0004XJ][0x00515750-0x00515831.MD5Final](by-memory/0x00515750-0x00515831.MD5Final.md) | member | `0x515750-0x515831` |
| `100` | [UID:0004XK][0x00515840-0x00515f48.MD5Transform](by-memory/0x00515840-0x00515f48.MD5Transform.md) | member | `0x515840-0x515f48` |

Every executable body now has one exact source destination. Free wrappers contribute H declarations through their exact children; method declarations occur only in the class page. The static writable `PADDING` declaration is emitted once before `Final`. `%02x` is identified as `Md5HexFormatLiteral`, and the 37-byte failure text as `Md5FailureDigestLiteral`; their exact data pages retain existing range dispositions while wrapper source embeds the literal text without duplicate data children.

Caller contracts remain distinct: PacketTransform/startup use `Md5StringHex`; RegistryConfig uses `Md5BytesToBuffer`; screenshot proof uses `Md5StreamHex`; path/stream failure returns the shared 36-character sentinel text; and the packet builder consumes `Md5BytesRaw` indices `13`, `3`, `11`, and `7` immediately. `Md5BytesRaw` deliberately returns `md5.digest` from a local object. That unsafe transient pointer is exact behavior and must not be replaced with safer storage.

Raw starts `0x515310`, `0x515450`, `0x515660`, `0x515f50`, and `0x515fa0` have no direct xref, absolute/RVA pointer, or rel32 route; positive controls recover expected modeled calls. Complete bounded bodies, exact `0xcc` fences, inline duplicates, and family behavior resolve their source roles. All alignment fences remain non-source and are excluded from function/page ranges.

Historical `MD5Context`, manually repeated wrapper initialization, free `Md5Encode`/`Md5Decode`, blank aggregate source, and an unresolved "safe" raw-digest signature are superseded. They remain documented as prior assumptions, but current source uses class `MD5`, member Encode/Decode, nested exact children, and the observed transient-pointer contract.

## Hypothesis

The original client likely had a small shared MD5 utility module rather than packet-local digest code. The helper island initializes the standard MD5 state constants, applies 64-byte transforms, finalizes with MD5 padding and bit-count handling, and exposes one-shot wrappers for strings, byte buffers, file paths, and open `FILE*` streams.

This should not be folded into [UID:0000M9][PacketTransform](by-file/PacketTransform.md). `Socket::BuildEncryptedPacket` consumes one raw digest wrapper at `0x00515380`, but the same MD5 family is also used by startup/minimap update handling and screenshot proof packet generation.

## Contents

Likely source-level contents:

| Address | Proposed name | Role |
| --- | --- | --- |
| `0x005151f0-0x00515284` | `Md5DigestToHexString` | Formats a 16-byte digest as a lowercase 32-byte hex string and returns a heap copy. |
| [UID:0003J1][0x0061ead4-0x0061eadc.Md5HexFormatString](by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md) | `"%02x"` literal | File-local format literal used by `Md5DigestToHexString` for each digest byte. |
| `0x00515290-0x0051530a` | `Md5StringHex` | Hashes a NUL-terminated ANSI string and returns a heap hex string. |
| `0x00515310-0x00515375` | [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) | Source-ready raw unmodeled helper that hashes a byte buffer and returns a heap hex string through formal child C++ `Md5BytesHex(char *bytes, unsigned int byteCount)`. The no-function/no-route state remains a liveness cap, not a child C++ blocker. |
| `0x00515380-0x005153dc` | `Md5BytesRaw` / `ComputePacketDigest` | Hashes a byte buffer and returns raw digest bytes consumed by packet encoding. |
| `0x005153e0-0x00515445` | `Md5BytesToBuffer` | Hashes a byte buffer and copies the 16-byte digest into a caller-supplied output buffer. |
| `0x00515450-0x00515569` | [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) | Source-ready raw unmodeled helper that opens a path in binary mode, hashes file contents, and returns a heap hex string or the shared MD5 fallback literal. The linked filename preserves the legacy final-byte suffix, while the actual exclusive end is `0x00515569`. |
| `0x00515570-0x0051565b` | `Md5StreamHex` | Hashes an existing `FILE*` stream in 1024-byte chunks and returns a heap hex string. |
| `0x00515690-0x00515744` | `Md5Update` | Updates bit count, buffers partial blocks, and calls the transform helper on full blocks. |
| `0x00515750-0x00515831` | `Md5Final` | Appends padding and bit length, emits the digest, and clears context storage. |
| `0x00515840-0x00515f48` | `Md5Transform` | MD5 compression transform with the standard constants and rotation schedule. |
| [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md) | `Md5Encode` / `Md5Decode` | Source-ready raw little-endian byte/word conversion helpers with formal first-draft C++; no current direct xrefs, VA/RVA pointer hits, or direct `E8/E9` routes, so no-route remains a liveness/confidence cap rather than a child C++ blocker. |

## Evidence

- IDA decompilation of the one-shot wrappers initializes `0x67452301`, `0xefcdab89`, `0x98badcfe`, and `0x10325476`.
- `Md5Update` tracks the 64-bit input bit count at context offsets `0x10` and `0x14`, keeps a 64-byte staging buffer near context offset `0x18`, and calls `Md5Transform` for complete blocks.
- `Md5Final` appends MD5 padding from the static padding table near `0x0066ddd8`, appends the 8-byte bit length, writes the 16-byte digest, and clears the context.
- `Md5Transform` contains the expected 64-step MD5 compression constants and rotate/add/xor patterns.
- `Md5DigestToHexString` formats each digest byte with `%02x`, appends into a local buffer, and returns `_strdup(Source)`.
- [UID:0003J1][0x0061ead4-0x0061eadc.Md5HexFormatString](by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md) is the exact `.rdata` child for that `%02x` format string. C001 live IDA decompilation of `0x005151f0` reconfirmed the reference at `0x00515235`.
- IDA xrefs show `Md5BytesRaw` at `0x00515380` is only called by `Socket::BuildEncryptedPacket`.
- IDA xrefs show `Md5StringHex` at `0x00515290` is called from `StartupWindow::RunUpdateCheck` and PacketTransform key-material helpers. The exact PacketTransform inventory is four static call sites: raw [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) calls at `0x00575b9f`; live [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) calls at `0x00575c38`, `0x00575c40`, and `0x00575c77`.
- The raw call hashes the input key text once and uses the returned 32-character lowercase digest to seed the nine-byte alternate-key state. The live calls compute `MD5(MD5(keyText))` at `0x00575c38`/`0x00575c40`, then the static loop call at `0x00575c77` hashes the entire current key text on each of 31 iterations before the helper appends that 32-character digest.
- Every `Md5StringHex` result in these two PacketTransform bodies is heap-owned `_strdup` output and is released with CRT `free`: one raw digest, both initial live digests, and one live loop digest per iteration. The loop executes 31 times, but it remains one static call site, so the exact static inventory is four rather than 34.
- IDA xrefs show `Md5BytesToBuffer` at `0x005153e0` is called from [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) at `0x004928ba`, where it writes a 16-byte digest buffer during registry/CLSID setup.
- `simroot_v2/recovered/SendScreenshotProofPacket_00558240.cpp` calls `sub_515570`, matching the `Md5StreamHex` wrapper.
- The 2026-05-31 IDA MCP recheck confirmed the modeled helper starts and sizes still match this split: `sub_5151F0` (`0x94`), `sub_515290` (`0x7a`), `sub_515380` (`0x5c`), `sub_5153E0` (`0x65`), `sub_515570` (`0xeb`), `sub_515690` (`0xb4`), `sub_515750` (`0xe1`), and `sub_515840` (`0x708`). It also reconfirmed that `0x00515310`, `0x00515450`, `0x00515f50`, and `0x00515fa0` are raw function-shaped starts with no IDA function object, and that the MD5 padding block at `0x0066ddd8` is referenced from `Md5Final` at `0x005157bb`.
- The 2026-06-10 A002 IDA MCP parent-gate recheck reconfirmed the cross-subsystem caller map: `Md5StringHex` (`0x00515290`) from `sub_575C30` and `StartupWindow__RunUpdateCheck`, `Md5BytesRaw` (`0x00515380`) from `sub_578C40`, `Md5BytesToBuffer` (`0x005153e0`) from `RegistryConfig::LoadFromRegistry` (`sub_4926A0`), and `Md5StreamHex` (`0x00515570`) from `SendScreenshotProofPacket_558240`.
- The same recheck confirmed the internal MD5 chain remains local to this utility island: wrappers call `Md5Update` (`0x00515690`) and `Md5Final` (`0x00515750`), `Md5Update` calls `Md5Transform` (`0x00515840`), and `Md5Final` references the padding block at `0x0066ddd8`. The raw endian helper starts at `0x00515f50` and `0x00515fa0` still have no function objects or direct xrefs, but their byte/word conversion loops and padding-bounded placement support them as retained MD5 utility siblings.
- The 2026-06-13 A001 target refresh reconfirmed `Md5FilePathHex` as half-open `0x00515450-0x00515569`, `0x119` = 281 bytes (Verified with `int_convert.py`), with no function object or start xrefs, a unique body signature, seven `0xcc` padding bytes before `Md5StreamHex`, `_fopen_s("rb")`, chunked `_fread`, `Md5Update`, `Md5Final`, `_fclose`, `Md5DigestToHexString`, and fallback-literal sharing with the stream helper.
- 2026-06-16 A001 live IDA MCP reconfirmed the current modeled/raw split: modeled helpers at `0x005151f0`, `0x00515290`, `0x00515380`, `0x005153e0`, `0x00515570`, `0x00515690`, `0x00515750`, and `0x00515840`; raw non-functions at `0x00515310`, `0x00515450`, `0x00515f50`, and `0x00515fa0`.
- The same refresh reconfirmed `Md5StringHex` callers in packet key expansion and `StartupWindow`, one `Md5BytesRaw` caller at `0x00578da5`, one `Md5BytesToBuffer` caller at `0x004928ba`, one `Md5StreamHex` caller at `0x00558278`, and internal `Md5Update`/`Md5Final` xrefs from both modeled wrappers and raw helper bodies (`fn:null` at the raw-call sites).
- A read-only PE scan found no direct call/branch or VA/RVA pointer references to the raw starts `0x00515310` and `0x00515450`, but found the single direct call to `0x00515380` at `0x00578da5`, matching IDA xrefs and keeping the unmodeled wrappers separate from the live packet-facing digest wrapper.
- 2026-06-25 B005 source-quality implementation raised [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) to `89/91` and inserted formal first-draft `Md5FilePathHex(const char *path)` C++ in the child. Current MCP session `80de0a67` reconfirmed the `0x00515450-0x00515569` half-open raw body, no function object, no raw-start xrefs, unique `0x119`-byte body signature, seven `0xcc` padding bytes, `0x474` stack frame, `0x400` buffer, `_fopen_s("rb")`, chunked `_fread` / `Md5Update` loop, `Md5Final`, `_fclose`, `Md5DigestToHexString`, and fallback literal sharing with `Md5StreamHex`.
- The same B005 pass checked source-shape blockers rather than leaving them as blank-C++ excuses. The raw file-path helper still has no direct code/data xref, VA/RVA pointer, or direct `E8/E9` PE route to `0x00515450`; control scans found the expected stream-helper call at `0x00558278` and packet-digest call at `0x00578da5`. That negative evidence is a liveness/confidence cap for this wrapper, not evidence against MD5 utility ownership or target-level C++ readiness.
- 2026-06-26 B007 source-quality implementation raised [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) to `89/91` and inserted formal first-draft `Md5BytesHex(char *bytes, unsigned int byteCount)` C++ in the child. Current MCP session `80de0a67` reconfirmed the `0x00515310-0x00515375` half-open raw body, no function object, no raw-start xrefs, unique `0x65` = 101-byte body (Verified with `tools/int_convert.py`), `0x70` = 112-byte frame (Verified with `tools/int_convert.py`), six-byte pre-padding, eleven-byte post-padding, standard MD5 constants, bit-count zeroing, raw `Md5Update` / `Md5Final` / `Md5DigestToHexString` call sites, and modeled sibling support for the conservative `char *Src, unsigned int` signature.
- The B007 pass checked the remaining route/source-shape blockers directly rather than leaving `Md5BytesHex` as a blank-C++ excuse. The raw bytes helper still has no direct code/data xref, VA/RVA pointer, or direct `E8/E9` PE route to `0x00515310`; the same PE scan found expected routes to `Md5BytesRaw`, `Md5StreamHex`, `Md5DigestToHexString`, `Md5Update`, and `Md5Final`. That negative evidence remains a liveness/confidence cap for this wrapper, not evidence against MD5 utility ownership or target-level C++ readiness.
- 2026-07-02 B001 source-quality implementation raised [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md) to `89/91` and inserted formal first-draft `Md5Encode` / `Md5Decode` C++ in the child. Current MCP evidence recorded initial health-ready session `supervisor_resume_20260629`, a transient timeout/restart, and replacement health-ready session `1f24c222` against the same NexusTK IDB/input. The pass reconfirmed no IDA function objects at `0x00515f50` or `0x00515fa0`, modeled neighbors `sub_515840` and `sub_516000`, padding at `0x00515f48-0x00515f50`, `0x00515f9c-0x00515fa0`, and `0x00515ff2-0x00516000`, exact callee-cleaned `retn 0Ch` word-to-byte and byte-to-word little-endian loops, no direct xrefs, no VA/RVA pointer-byte hits, and no local PE direct `E8/E9` route hits to either raw start.
- The B001 pass used positive controls to prove the negative route evidence: local PE scanning found the packet-facing `Md5BytesRaw` call at `0x00578da5 -> 0x00515380`, the stream helper call at `0x00558278 -> 0x00515570`, expected calls into `Md5Update`, `Md5Final`, and `Md5Transform`, and the `MemoryMan` boundary call at `0x00419f75 -> 0x00516000`. Therefore UID `000237` no-route remains a liveness/confidence cap, not a reason to blank target-level C++ or move ownership out of MD5.

## Ownership Decision

Use `util/MD5.cpp` and `util/MD5.h` as the reconstruction owner. The helper family has exact class state plus file-scope wrappers, is used across startup, network, registry, file, and screenshot paths, and is algorithm-specific enough to remain a separate utility module.

`network/PacketTransform.cpp` should call into this module for packet trailer digest bytes but should not own the MD5 implementation. `app/StartupWindow.cpp` and the [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md) should also depend on this utility module.

The two string-key helpers likewise remain PacketTransform-owned consumers, not MD5-owned bodies. `Md5StringHex` and the internal hash implementation remain under this MD5 utility route; [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) and [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) remain owned/emitted by PacketTransform because they mutate PacketTransform state and use MD5 only as a utility dependency.

The 2026-06-10 A002 strict-gate audit keeps [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md) attached here. The child is now `85/88`, and this file's current `86/85` score clears the direct parent side of the `85/85` assignment gate. The exact original filename/folder remains a documented caveat, but the source-level owner is still this MD5 utility module rather than PacketTransform, RegistryConfig, StartupWindow, ScreenshotCapture, or MemoryMan.

## Caveats

- IDA currently does not materialize function objects for the raw starts at `0x00515310` and `0x00515450`, even though disassembly shows complete helper bodies there. The 2026-06-16, 2026-06-25, and 2026-06-26 IDA/PE checks found no direct xrefs, direct calls/branches, absolute VA pointers, or RVA pointers to those starts. Treat both raw hex wrappers as source-ready retained MD5 helpers whose no-route state is a liveness cap, not a target-level code-entry blocker.
- `Md5BytesRaw` returns a pointer to transient local digest storage. The raw body and sole immediate consumer resolve the exact faithful C++ signature; preserve the unsafe return rather than choosing a different "safe" contract.
- Final broad MD5 module C++ remains capped by the unresolved broader helper set: `Md5BytesRaw` needs a safe stack/digest-return representation, and exact `MD5Context`/method/member spelling is inferred rather than proven from original metadata. UID `000237` endian-helper liveness remains provisional as a no-route caveat, but it no longer blanks that child's target-level C++. This file-level caveat also no longer blanks child-level C++ for [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md), [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md), or [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md).
- The adjacent [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) are not part of this MD5 module despite address proximity.

## Cross-References

- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md)
- [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md)
- [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md)
- [UID:0003J1][0x0061ead4-0x0061eadc.Md5HexFormatString](by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-26 B001 UID0001B6 full source callback:
  - Raised `89/88 -> 93/93`; documented `MD5.cpp` and `MD5.h`, exact `0x68` class layout, complete class/method/free-wrapper split, validator-assigned class/child UIDs, deterministic top-level and in-range source order, literal/data roles, all cross-subsystem caller contracts, raw no-route evidence, protected fences, and transient-pointer behavior.
  - Superseded historical `MD5Context`, manual wrapper initialization, free endian-helper, blank aggregate, and unresolved safe-return assumptions without deleting their earlier evidence.

- 2026-07-13 B001 UID000244 support synchronization:
  - Added the exact four-static-call-site `Md5StringHex` inventory for PacketTransform: raw `0x00575b9f` and live `0x00575c38`, `0x00575c40`, and `0x00575c77`. Recorded one-digest raw seeding, live double-hash initialization, 31 dynamic executions of the single loop call site, CRT-free ownership for every returned digest, and the MD5-provider/PacketTransform-consumer ownership boundary. Score, reconstruction path, and existing source content are unchanged.

- 2026-07-02 B001 source-ready endian-helper update:
  - What existed before: `COMPLETION:89`, `CONFIDENCE:88`, with UID `000237` documented as raw `Md5Encode` / `Md5Decode` candidates whose no-function/no-route/signature caveat still blocked target-level C++.
  - Changed to: score unchanged for this MD5 file page; UID `000237` is now recorded as source-ready with formal first-draft `Md5Encode` / `Md5Decode` C++ through `NexusTK/util/MD5.cpp`.
  - Summary/evidence: B001 MCP session `1f24c222` reconfirmed the exact raw endian helper bodies, no function objects at `0x00515f50` and `0x00515fa0`, padding-bounded split, callee-cleaned `retn 0Ch` loops, no direct xrefs, no VA/RVA pointer-byte hits, and no local PE direct route hits; positive controls found live routes to `Md5BytesRaw`, `Md5StreamHex`, `Md5Update`, `Md5Final`, `Md5Transform`, and `MemoryMan`. No-route remains a liveness cap for UID `000237`, not a child C++ blocker. The broader file-level C++ caveat remains for `Md5BytesRaw` and exact `MD5Context`/helper spelling.

- 2026-06-26 B007 source-ready bytes-to-hex wrapper update:
  - What existed before: `COMPLETION:88`, `CONFIDENCE:87`, with [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md) documented as a raw no-function/no-route helper whose C++ remained blank.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`. The file now records that UID `0001B7` has formal first-draft `Md5BytesHex(char *bytes, unsigned int byteCount)` C++ and remains owned/emitted by this MD5 utility module.
  - Summary/evidence: B007 MCP session `80de0a67` reconfirmed the exact `0x00515310-0x00515375` body, no IDA function object, no raw-start xrefs, unique `0x65` signature, `0x70` stack frame, six-byte pre-padding, eleven-byte post-padding, standard MD5 constants, raw `Md5Update`, `Md5Final`, and `Md5DigestToHexString` calls, and modeled sibling support for the conservative `char *Src, unsigned int` source-facing signature. A read-only PE scan found no call/pointer route to `0x00515310` while finding control calls to `Md5StreamHex`, `Md5BytesRaw`, `Md5DigestToHexString`, `Md5Update`, and `Md5Final`; therefore no-route remains a wrapper liveness cap, not a reason to blank target-level C++ or move ownership out of MD5.

- 2026-06-25 B005 source-ready file-path wrapper update:
  - What existed before: `COMPLETION:87`, `CONFIDENCE:86`, with [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) documented as a raw no-function/no-route helper whose C++ remained blank.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:87`. The file now records that UID `0001B8` has formal first-draft `Md5FilePathHex(const char *path)` C++ and remains owned/emitted by this MD5 utility module.
  - Summary/evidence: B005 MCP session `80de0a67` reconfirmed the exact `0x00515450-0x00515569` body, no IDA function object, no raw-start xrefs, unique `0x119` signature, `0x474` stack frame, `0x400` chunk buffer, `_fopen_s("rb")`, chunked `_fread` / `Md5Update`, `Md5Final`, `_fclose`, `Md5DigestToHexString`, shared fallback literal, and seven-byte padding. A read-only PE scan found no call/pointer route to `0x00515450` while finding control calls to `Md5StreamHex` and `Md5BytesRaw`; therefore no-route remains a wrapper liveness cap, not a reason to blank target-level C++ or move ownership out of MD5.

- 2026-06-10 A002 parent-gate refresh:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:82`; the page had strong MD5 grouping evidence but did not clear the strict confidence gate for already-attached memory children.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed the cross-subsystem caller map, internal `Md5Update`/`Md5Final`/`Md5Transform` chain, padding-data reference, and raw endian helper sibling placement. The exact original filename/folder caveat remains, so confidence only rises to the minimum parent-gate level rather than near-final.
- 2026-06-12 C001 Batch C001-018:
  - Score unchanged at `86/85`.
  - Added exact [UID:0003J1][0x0061ead4-0x0061eadc.Md5HexFormatString](by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md) after live IDA decompiled `Md5DigestToHexString` and tied `%02x` to this utility module.
- 2026-06-13 A001 Goal 2 boundary support:
  - Score unchanged at `86/85`.
  - Corrected the [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) contents row to use the half-open `0x00515450-0x00515569` body while preserving the legacy filename suffix.
  - Summary/evidence: live IDA MCP reconfirmed the raw helper's no-function/no-start-xref status, unique body signature, exact padding before `Md5StreamHex`, and MD5 file-open/read/finalize/hex behavior.
- 2026-06-16 A001 file-confidence refresh:
  - What existed before: `86/85`, with strong MD5 grouping but only older file-root caller/reachability wording for raw starts and packet-facing digest liveness.
  - Changed to: `87/86`.
  - Summary/evidence: live IDA MCP reconfirmed modeled helper sizes, raw non-function starts, caller map across packet transform/startup/registry/screenshot paths, internal update/final/transform xrefs, and raw-body calls as `fn:null`; a read-only PE scan found no direct calls/branches or VA/RVA pointer hits for raw `0x00515310`/`0x00515450`, and exactly one direct call to `0x00515380` at `0x00578da5`. Final C++ remains blocked by exact source signatures and the packet digest stack-return representation.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: MD5 utility hypothesis, one-shot wrappers, raw helpers, transform/update/final behavior, caller evidence, ownership decision, caveats, and network/screenshot/startup refs are documented; confidence is capped by raw unmodeled helper starts and final original filename/folder uncertainty.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `MD5.cpp` under `util`, and the current IDA MCP recheck confirms a cross-subsystem MD5 helper island rather than ownership by packet, startup, registry, or screenshot modules.
