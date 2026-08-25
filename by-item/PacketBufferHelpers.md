*** UID:0000V1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PacketBuffer Helpers

## UID0003YJ Scalar Writer Inventory Closure - 2026-07-28

- [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) is a source-ready `94/94` child emitted through UID0000M8 at position `10`. It owns five external free value-first `void` writers for UInt8, UInt16BE, UInt24BE, UInt32BE, and UInt64BE; definitions are in the child CPP channel and declarations are in its H channel.
- Exact ranges are `[0x00575380,0x00575391)`, `[0x005753a0,0x005753b9)`, `[0x005753c0,0x005753e1)`, `[0x005753f0,0x00575419)`, and `[0x00575420,0x00575470)`. Four internal CC gaps remain alignment, and the decorated runtime successor at `0x00575470` remains excluded.
- Types are unsigned source widths plus mutable `unsigned char *destination`; UInt24 intentionally consumes `unsigned int` low 24 bits. All returns are `void`, as confirmed by exact body semantics and complete result-use accounting rather than decompiler return guesses.
- Every writer emits high-to-low payload bytes where applicable and one spare local zero after payload. Explicit packet lengths and later field overwrites prove that spare zeros are scratch safety, not protocol fields.
- Xref totals are `1114/222/2/119/4`. Rare UInt24 MapPane checksum and UInt64 timestamp/challenge callers prove retained live widths; the full caller census spans all major packet-building source families and establishes shared external utility linkage.
- Selected names are `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteUInt24BE`, `PacketBufferWriteUInt32BE`, and `PacketBufferWriteUInt64BE`. Destination-first wrappers, returning APIs, class members, file-static ownership, cursor/capacity abstractions, Socket/PacketTransform ownership, and raw compiler labels are rejected.
- This aggregate item remains a blank-formal inventory because exact source-bearing by-memory children emit the code. Its `90/92` score records closure of scalar-writer and cursor-append source/header blockers while retaining independent reader/string-family uncertainty.

## UID0003YM Cursor Append Family Readiness - 2026-07-16

- [UID:0003YM][0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers](by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md) is now source-ready at `92/93` with exact external free helpers `PacketBufferAppendUInt8`, `PacketBufferAppendUInt16BE`, retained `PacketBufferAppendUInt24BE`, and `PacketBufferAppendUInt32BE`.
- The target API is value first, mutable `unsigned char *packet` second, and `int *cursor` third, with `void` return. Value types are `unsigned char`, `unsigned short`, `unsigned int`, and `unsigned int`.
- All multi-byte payloads are big-endian. Each helper writes one spare scratch zero after payload and advances the cursor by payload width only. Xref totals remain `29/13/0/9`.
- The raw UInt24 helper has no current incoming route or VA/RVA pointer hit, but its complete body, prologue/return, sibling symmetry, and exact alignment support retained external source emission rather than padding/dead-code exclusion.
- Definitions and declarations route through [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) in PacketBuffer.cpp/PacketBuffer.h. No PacketCursor type, class/member abstraction, file-static helper, feature owner, duplicate source root, or new child is introduced.
- This item page remains `88/91` with blank formal C++ because exact by-memory children own emission. UID0003YM-specific names/types/liveness/formal blockers are closed; broader scalar/read/string/host-address API questions retain their independent caps.

## ObjectStatusBlob scalar-reader consumers

- Registered parser children UID0004LK, UID0004LL, and UID0004LM consume the canonical BE16 helper at `0x00575480`. Tagged and partial each decode one appearance word; full decodes riding, face, Body/Coat, weapon, shield/arrow, decoration, Mantle, Neck, and Shoes words.
- Direct one-byte parser fields remain direct indexing. `0x00575470` is compiler/runtime narrow-character conversion lowering, not another PacketBuffer API.
- This by-item page is the project's class-level PacketBuffer helper support; no separate by-class/PacketBuffer page exists. No formal C++, score, owner/emitter, helper split, or API declaration changes in this synchronization.


## Status

- Confidence: very strong for helper behavior, shared utility role, source split boundaries, and PacketBuffer owner/emitter placement; medium-high for final source names and exact signatures.
- Owner/emitter route: [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), now documented at `88/89`.
- Main address docs: [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- Evidence basis: live IDA MCP lookup, decompilation, callee, byte, signature, and xref checks through 2026-06-25.
- Reconstruction note: C++ intentionally remains blank here because helper emission belongs on exact by-memory child pages. [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) emits the accepted two-byte reader bodies, and UID0003YM emits the complete cursor-append family; broader PacketBuffer API polish remains for other helper families.

## Responsibility

This helper family serializes and parses small packet fields. The common convention is big-endian integer order for multi-byte fields, cursor advancement for append/read helpers, and length-prefixed strings for text payloads.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page consolidates the exact helper-family split, parent/route decision, representative decompile evidence, raw helper starts, high-traffic xref evidence, adjacent runtime-helper exclusion, one-byte/two-byte string-prefix conventions, length-prefixed reader split, padding boundaries, and source-ready UID0003YM cursor-append family. It remains below final audit because other helper families retain API/source-polish blockers. |
| Confidence `91` | Confidence is very strong because live IDA evidence matches exact helper starts/sizes, raw helper bytes, decompiled scalar/string behavior, runtime exclusion, PacketBuffer route, and UID0003YM's exact value-first API. It remains capped below final-source confidence by original spellings and unresolved types/liveness outside the now-closed UID0003YM family. |

## Helper Summary

| Range | Current IDA name | Behavior |
| --- | --- | --- |
| `0x00575380-0x00575391` | `sub_575380` | Writes one byte and a trailing zero byte; raw ABI order is value first, destination second. |
| `0x005753a0-0x005753b9` | `sub_5753A0` | Writes a 16-bit value in big-endian order plus trailing zero. |
| `0x005753c0-0x005753e1` | `sub_5753C0` | Writes the high/middle/low bytes of a 24-bit-style value into a four-byte slot. |
| `0x005753f0-0x00575419` | `sub_5753F0` | Writes a 32-bit value in big-endian order plus trailing zero. |
| `0x00575420-0x00575470` | `sub_575420` | Writes a 64-bit value in big-endian order plus trailing zero. |
| `0x00575470-0x0057547a` | `std::_Narrow_char_traits<char,int>::to_char_type` | Adjacent STL/runtime helper; not PacketBuffer-owned source logic. |
| `0x00575480-0x0057549a` | `sub_575480` | Reads a big-endian 16-bit value. |
| `0x005754a0-0x005754bd` | raw non-function start | Reads a big-endian 24-bit value; retained source-style overload with no direct refs. |
| `0x005754c0-0x005754e6` | `sub_5754C0` | Reads a big-endian 32-bit value. |
| `0x005754f0-0x00575574` | `sub_5754F0` | Reads a big-endian 64-bit value. |
| `0x00575580-0x0057561a` | `sub_575580` | Converts a wide hostname to ANSI, resolves it with `gethostbyname`, and copies four address bytes. |
| `0x00575620-0x0057564e` | raw non-function start | ANSI hostname-to-four-address-byte resolver mirroring the post-conversion body. |
| `0x00575650-0x00575668` | `PacketBufferAppendUInt8` / `sub_575650` | Source-ready external value-first append of one byte plus scratch zero, advancing by one. |
| `0x00575670-0x00575693` | `PacketBufferAppendUInt16BE` / `sub_575670` | Source-ready external value-first big-endian 16-bit append plus scratch zero, advancing by two. |
| `0x005756a0-0x005756cb` | retained `PacketBufferAppendUInt24BE` raw start | Source-ready retained external big-endian 24-bit append plus scratch zero, advancing by three; no current route. |
| `0x005756d0-0x00575703` | `PacketBufferAppendUInt32BE` / `sub_5756D0` | Source-ready external value-first big-endian 32-bit append plus scratch zero, advancing by four. |
| `0x00575710-0x00575723` | `sub_575710` | Cursor read of one byte, advancing by one. |
| `0x00575730-0x0057575d` | `sub_575730` | Cursor read of a big-endian 16-bit value, advancing by two. |
| `0x00575760-0x0057578e` | raw non-function start | Cursor read of a big-endian 24-bit value; retained source-style overload. |
| `0x00575790-0x005757c8` | `sub_575790` | Cursor read of a big-endian 32-bit value, advancing by four. |
| `0x005757d0-0x00575810` | `sub_5757D0` | Writes one-byte ANSI length and copies text bytes. |
| `0x00575810-0x00575841` | raw non-function start | Writes a caller-provided byte span with a one-byte length prefix. |
| `0x00575850-0x005758db` | `sub_575850` | Converts wide text to ANSI, writes one-byte length, and copies bytes. |
| `0x005758e0-0x0057592c` | raw non-function start | Writes `strlen` ANSI text with a two-byte big-endian length prefix. |
| `0x00575930-0x0057596b` | raw non-function start | Writes a caller-provided byte span with a two-byte big-endian length prefix. |
| `0x00575970-0x00575a07` | `sub_575970` | Converts wide text to ANSI, writes a two-byte big-endian length, and copies bytes; live IDA reports no direct code refs. |
| `0x00575a10-0x00575a81` | `sub_575A10` | Reads one-byte length, copies the byte span into a temporary string object, and transfers it to caller storage. |
| `0x00575a90-0x00575abb` | `sub_575A90` | Reads one-byte length and copies the byte span into caller-provided storage. |
| `0x00575ac0-0x00575b42` | `PacketBufferReadAnsiString16` / `sub_575AC0` | Retained no-route two-byte ANSI string reader. Reads a big-endian 16-bit length, copies the payload into an ANSI `StringBase` temporary, transfers/converts it into caller output through the StringBase conversion path, releases the temporary, and returns caller output. |
| `0x00575b50-0x00575b8c` | `PacketBufferReadAnsiBytes16` / `sub_575B50` | Live two-byte ANSI byte-span reader. Reads a big-endian 16-bit length and copies the byte span into caller-provided ANSI `StringBase` storage; direct calls come from MainMenuPane and MapPane packet case `0x5B`. |

## Xref Weight

Live IDA MCP compact xref checks report:

- `sub_575380`: 1114 direct code refs from 178 caller functions.
- `sub_5753A0`: 222 direct code refs from 61 caller functions.
- `sub_5753F0`: 119 direct code refs from 49 caller functions.
- `sub_575480`: 372 direct code refs from 96 caller functions.
- `sub_5754C0`: 226 direct code refs from 70 caller functions.

This caller spread is strong evidence for a shared packet utility module rather than ownership by one feature, UI pane, or socket method.

IDA MCP recheck on 2026-06-04 confirms 21 functions in `0x00575380-0x00575abb` plus the two length-prefixed readers in `0x00575ac0-0x00575b8c`. The broad high-traffic helpers have hundreds to more than a thousand direct call sites, while the narrow string/64-bit variants still fit the packet-buffer utility role. The embedded `std::_Narrow_char_traits<char,int>::to_char_type` runtime helper is explicitly excluded from PacketBuffer source ownership even though it lies inside the address island.

IDA MCP recheck on 2026-06-13 confirms the `0x00575ac0` and `0x00575b50` helper sizes, direct xref split, shared big-endian two-byte length decode, `StringBase` bounded-copy/conversion/release callees, internal `0xcc` padding, and unique signature for the two-helper range. B012's accepted 2026-06-25 source-quality implementation resolves the final source-facing names for this exact pair as `PacketBufferReadAnsiString16` and `PacketBufferReadAnsiBytes16`; broader call-site cleanup still affects other PacketBuffer API spellings.

IDA MCP refresh on 2026-06-14 against database `a001_goal2_class_batch` reconfirms:

- `server_health` reports `NexusTK.exe`, Hex-Rays ready, auto-analysis ready, and image base `0x400000`.
- `lookup_funcs` still reports the 21-function (`0x15`, Verified with int_convert.py) scalar/helper island from `0x00575380` through `0x00575abb`, with the adjacent `std::_Narrow_char_traits<char,int>::to_char_type` runtime helper at `0x00575470` size `0x0a` / 10 (Verified with int_convert.py), and the two length-prefixed readers at `0x00575ac0` size `0x82` / 130 (Verified with int_convert.py) plus `0x00575b50` size `0x3c` / 60 (Verified with int_convert.py).
- `get_bytes` confirms `0x00575abb-0x00575ac0` and `0x00575b8c-0x00575b90` are `0xcc` alignment, preserving the PacketBuffer/PacketTransform split.
- `analyze_component` on representative helpers confirms the core scalar helpers have no callees, `sub_575580` calls `WideCharToMultiByte`, `gethostbyname`, and bounded copy helpers, and the string helpers call the documented `StringBase` copy/conversion/release routines.
- Current `xrefs_to` still caps the high-traffic byte/word/dword helpers at at least 100 direct xrefs with `more:true`, while the rare variants remain narrow: `0x005754f0` has 2 direct refs, `0x00575580` has 1, `0x00575970` has none, `0x00575ac0` has none, and `0x00575b50` has 2.
- Live decompilation reconfirms the big-endian byte layout: byte/word/dword/qword writers store high-order bytes first, the two-byte readers compute `(first << 8) + second`, and string helpers advance the caller cursor by the decoded length.

2026-06-17 B001 source-quality reanalysis adds:

- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) is now a non-emitting split/index rather than one source-emitting aggregate.
- Exact child pages [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)-[UID:0003YP][0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers](by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md) own scalar writer, scalar reader, host-address, cursor append, cursor read, string writer, and one-byte string reader families.
- `0x00575470-0x0057547a` is `std::_Narrow_char_traits<char,int>::to_char_type`, with 975 broad refs, and must be ignored as runtime/STL support.
- Raw starts `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, and `0x00575930` are source-style overload bodies, not padding.
- Trailing zero writes are out-of-band scratch terminators/safety bytes. Cursor helpers advance by payload width and the zero should not be modeled as protocol payload.

## Naming Notes And Best Current Directions

Raw IDA labels remain fallback/search aliases only where child-specific work has not normalized them. The scalar-writer names `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteUInt24BE`, `PacketBufferWriteUInt32BE`, and `PacketBufferWriteUInt64BE` are now the selected source-facing family; reader/string names remain independent inferred directions. Other current directions include `PacketBufferReadUInt16BE`, `PacketBufferReadUInt24BE`, `PacketBufferAppendUInt16BE`, `PacketBufferReadUInt32BE`, `PacketBufferAppendAnsiString8`, `PacketBufferAppendWideStringAsAnsi8`, `PacketBufferAppendAnsiString16`, `PacketBufferAppendWideStringAsAnsi16`, `PacketBufferReadAnsiString8`, `PacketBufferReadAnsiBytes8`, `PacketBufferReadAnsiString16`, and `PacketBufferReadAnsiBytes16`.

For UID0003YM specifically, current accepted source names and signatures are final for callback use: UInt8/UInt16BE/UInt24BE/UInt32BE append helpers with value-first order, built-in unsigned value types, mutable unsigned-byte packet base, signed int cursor pointer, void return, and external PacketBuffer.h/.cpp placement. Exact original lexical proof remains a confidence cap only.

For [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md), `PacketBufferReadAnsiString16` and `PacketBufferReadAnsiBytes16` are accepted final source-facing names for the current first-draft C++ block. The `16` suffix records the two-byte big-endian length prefix width, not UTF-16 payload text. The first helper converts an ANSI temporary into caller output; the second fills caller-provided ANSI `StringBase` storage.

B008's 2026-06-21 [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) recheck adds an ABI-order guardrail for `PacketBufferWriteUInt8`: local disassembly of `0x00575380` reads the byte value from `[ebp+8]` and the destination pointer from `[ebp+0xc]`, with callers pushing destination before value. Destination-first snippets in older feature drafts should be read as source-wrapper/convenience style unless the wrapper is explicitly defined.

The host-address pair is best described as `ResolveHostAddressFromWideName` and `ResolveHostAddressFromAnsiName` while it remains routed through PacketBuffer. Those names are source-role names, not proof of original spelling.

## Cross-References

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- 2026-07-16 B002 UID0003YM callback synchronization:
  - Kept item metadata `88/91`, owner/emitter UID0000M8, reconstructable true, and blank formal C++.
  - Updated the four cursor-append rows and readiness notes with exact source names/types/order, xref and scratch-zero behavior, retained UInt24 disposition, PacketBuffer header/source route, and child-owned formal emission while preserving all unrelated helper-family evidence and caps.
- 2026-06-25 B012 implementation callback for accepted [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) report:
  - Before: the helper table still listed the two-byte readers only as `sub_575AC0`/`sub_575B50`, and the naming notes said final names for this pair waited on broader call-site cleanup.
  - Changed to: table and naming notes now use accepted final names `PacketBufferReadAnsiString16` and `PacketBufferReadAnsiBytes16`, preserve `sub_` names as search aliases only, document the retained no-route/live-caller split, and point formal C++ emission to the exact [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) child page. No score change was applied because this item page already sits at `88/91` and broader helper-family API polish still caps final audit.
  - Evidence: accepted B012 report, current MCP session `80de0a67`, [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) decompilation/disassembly, negative route proof for `0x00575ac0`, positive MainMenuPane/MapPane case `0x5B` callers for `0x00575b50`, and sibling one-byte reader naming convention.
- 2026-06-17 Supervisor execution of B001 report: raised from `85/90` to `88/91` and incorporated the PacketBuffer helper split/index research.
  - Before: the item page listed modeled helper starts but omitted raw helper starts and still summarized the island as a mixed helper family.
  - After: the page records exact child-family ownership, raw source-style overloads, runtime helper exclusion, zero semantics, string-prefix conventions, and best current source-facing names.
  - Evidence: B001 report `0001HZ-packetbuffer-helpers-source-quality.md`, child pages [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)-[UID:0003YP][0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers](by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md), live IDA xref/decompilation/byte evidence cited there, and current PacketBuffer support docs.
- 2026-06-21 B008 [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) support sync:
  - Added the raw ABI-order note for `PacketBufferWriteUInt8` as value-first/destination-second based on `0x00575380` stack argument reads.
  - No score change; final PacketBuffer API spelling and wrapper/declaration style remain source-polish blockers.
- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had complete 2026-06-04/2026-06-13 evidence but still sat below the current score gate and used stale final-code wording.
  - After: the page records the 2026-06-14 live IDA refresh for helper starts/sizes, representative decompilation, high-traffic xref shape, rare helper xref counts, padding boundaries, PacketBuffer owner/emitter route, and source-quality blockers.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `analyze_component`, `xrefs_to`, `get_bytes`, `decompile`, and `int_convert.py` checks.
- 2026-06-13 A004 Goal 2: Refreshed parent-gate and two-byte reader notes after the assigned length-prefixed helper page and [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) were rechecked. No score change at that time; the remaining helper-family naming/signature pass still blocks final-source C++.
- 2026-06-04: Raised from `70/85` to `82/88` and attached to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md).
  - Before: the page covered the main scalar helpers, but it omitted live functions inside the island, left owner/emitter routing blank, and mixed in stale provenance.
  - After: the page records the complete live IDA function inventory for the helper island, separates the embedded STL/runtime helper from PacketBuffer source ownership, documents 24-bit/64-bit/cursor/string variants, and records why PacketBuffer routing is now justified.
  - Evidence: live IDA MCP `py_eval` function enumeration and xrefs, batched decompilation for `0x5753c0`, `0x575420`, `0x5754f0`, `0x575580`, `0x575730`, `0x575790`, `0x575970`, and `0x575a10`, plus existing [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) confidence `82`.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet scalar helpers, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper family as rebuild-relevant packet-buffer code. Parent UID and C++ remain blank because final names and exact grouping with the canonical by-memory pages are not at the `95+` code gate.
  - Evidence: IDA MCP confirms exact helper ranges, no callees for core scalar read/write helpers, high xref weight for shared packet utility functions, and narrower length-prefixed string reader call sets.
