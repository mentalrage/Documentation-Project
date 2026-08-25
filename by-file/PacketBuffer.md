*** UID:0000M8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PacketBuffer

## UID0000KA Packet Consumer - 2026-08-15

The two legacy and two Pane2 packet paths consume existing `PacketBuffer`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `PacketBufferReadUInt16BE` declarations from `network/PacketBuffer.h`; scalar values precede the buffer destination exactly. Inventory owns opcode `0x1C` length 2, opcode `0x66` length 10, and opcode `0x59` help parsing decisions. PacketBuffer retains byte-order/storage helpers; no WritePacket/ReadPacket shim or score change is introduced.

## UID0003YK UInt16BE Source Contract - 2026-08-14

- [UID:0003YK][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md) now emits the independently proved external `PacketBufferReadUInt16BE` API at position `20`: the definition belongs in `NexusTK/network/PacketBuffer.cpp`, and `unsigned short PacketBufferReadUInt16BE(const unsigned char *packet);` belongs in `NexusTK/network/PacketBuffer.h`.
- UID0003WR is the closure-triggering consumer. `RankingCategoryCollection::ParseCategoryListResponse` includes PacketBuffer.h and reads the big-endian signed record count through `PacketBufferReadUInt16BE(packet + 2)` before advancing its own cursor by two bytes. A feature-local redeclaration or Ranking-owned helper body would duplicate shared PacketBuffer ownership and is rejected.
- Exact helper range is `[0x00575480,0x0057549a)`. The body reads two immutable unsigned bytes, combines shifts `8/0`, returns an unsigned 16-bit value, and performs no cursor advance, null check, capacity check, or bounds check. Its 372 inbound references establish a shared network utility rather than a Ranking-specific API.
- Position `20` keeps UInt16BE and UInt32BE reader channels together between scalar writers at `10` and cursor append helpers at `30`. The by-file root remains prose-only; UID0003YK alone owns the formal child CPP/H blocks, avoiding duplicate emission.
- This is an independent partial-family closure. The retained raw UInt24BE and modeled UInt64BE rows remain documented and non-emitting; no speculative declaration or definition is added for either.
- The file score remains `90/91`: the live UInt16BE and UInt32BE dependencies are source-ready and compile-visible, while broader reader/string/host-address APIs and stripped original file/API spellings remain independent caps.

## UID0003YK UInt32BE Source Contract - 2026-07-31

- [UID:0003YK][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md) now emits the independently proved external `PacketBufferReadUInt32BE` API at position `20`: the definition belongs in `NexusTK/network/PacketBuffer.cpp`, and `unsigned int PacketBufferReadUInt32BE(const unsigned char *packet);` belongs in `NexusTK/network/PacketBuffer.h`.
- UID0003WU is the closure-triggering consumer: its generated/ordinary RankingDialog source includes PacketBuffer.h and reads the category id through `PacketBufferReadUInt32BE(packet + 2)`. A feature-local redeclaration or Ranking-owned helper body would duplicate shared PacketBuffer ownership and is rejected.
- Exact source is four unsigned byte loads combined in big-endian order with shifts `24/16/8/0`. Position `20` orders the UInt32BE channels between UID0003YJ scalar writers at `10` and UID0003YM cursor append helpers at `30` without changing those families.
- Historical UID0003WU closure covered only UInt32BE. UID0003WR independently closes UInt16BE; retained raw UInt24BE and modeled UInt64BE remain documented and non-emitting without speculative declarations.
- Command20348 PacketBuffer.h lacked the declaration and PacketBuffer.cpp carried a UID0003YK Empty Emitter Marker. That topology is dated pre-repair evidence; the ordinary formal route is now complete and requires a later supervisor-generated readback of exactly one declaration, one definition, and zero UID0003YK empty markers.
- The file score remains `90/91`: the live UInt32BE dependency is source-ready and compile-visible, while broader reader/string/host-address APIs and stripped original file/API spellings remain independent caps.

## UID0003YJ Scalar Writer Source Contract - 2026-07-28

- [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) is source-ready at `94/94` and emits at position `10` through this file root. Definitions belong in `NexusTK/network/PacketBuffer.cpp`; matching external declarations belong in `NexusTK/network/PacketBuffer.h`.
- The exact external free APIs are `void PacketBufferWriteUInt8(unsigned char value, unsigned char *destination)`, `void PacketBufferWriteUInt16BE(unsigned short value, unsigned char *destination)`, `void PacketBufferWriteUInt24BE(unsigned int value, unsigned char *destination)`, `void PacketBufferWriteUInt32BE(unsigned int value, unsigned char *destination)`, and `void PacketBufferWriteUInt64BE(unsigned __int64 value, unsigned char *destination)`.
- Parameter order is value first and mutable destination second. All results are `void`; no receiver, namespace invention, file-static linkage, destination-first wrapper, cursor/capacity object, signed-width contract, or decompiler-residual return is part of the selected source API.
- Each writer serializes high-order payload bytes first where applicable and writes one local spare zero immediately after payload. Callers overwrite that byte with later fields or exclude it through explicit send lengths; it is never an extra transmitted protocol byte.
- Direct xref totals are `1114/222/2/119/4`. The UInt24 calls at `0x00505ba1`/`0x0050f423` and UInt64 calls at `0x00508945`/`0x00508958`/`0x00514201`/`0x00514214` prove retained rare-width liveness. Exhaustive caller-result analysis proves `void` for all widths.
- Exact range is `[0x00575380,0x00575470)`, with four internal `0xcc` alignment gaps. The decorated MSVC narrow-character runtime helper at `0x00575470` remains outside this source family. Socket, PacketTransform, feature-owner, compiler/runtime, and class-member placements are rejected.
- This source root remains prose-only and must not duplicate child formal blocks. UID0003YJ owns scalar-writer definitions/declarations at position `10`, UID0003YK owns the proved UInt16BE and UInt32BE reader definitions/declarations at position `20`, UID0003YM owns cursor-append definitions/declarations at position `30`, and remaining unresolved reader/string APIs retain independent dispositions.
- File score `90/91` reflects the closed scalar-writer and cursor-append APIs plus stable PacketBuffer.cpp/PacketBuffer.h topology. Remaining caps belong to unresolved reader/string families and stripped original file/API spellings, not the scalar writer contract.

## UID0003YM Cursor Append Source Contract - 2026-07-16

- [UID:0003YM][0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers](by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md) is source-ready at `92/93` and emits through this file root. Definitions belong in `NexusTK/network/PacketBuffer.cpp`; matching declarations belong in `NexusTK/network/PacketBuffer.h`.
- Exact external global/free declaration contracts are `void PacketBufferAppendUInt8(unsigned char value, unsigned char *packet, int *cursor)`, `void PacketBufferAppendUInt16BE(unsigned short value, unsigned char *packet, int *cursor)`, `void PacketBufferAppendUInt24BE(unsigned int value, unsigned char *packet, int *cursor)`, and `void PacketBufferAppendUInt32BE(unsigned int value, unsigned char *packet, int *cursor)`.
- Parameter order is value, mutable unsigned-byte packet base, signed byte-count cursor pointer. Results are `void`; no receiver, class, PacketCursor facade, namespace invention, file-static linkage, destination-first wrapper, capacity object, STL container, bounds check, or null check is part of this API.
- UInt16/UInt24/UInt32 serialize high byte first. Every helper writes one scratch zero immediately after payload and advances only by payload width. Explicit caller send lengths therefore exclude the spare zero.
- Direct xref totals are `29/13/0/9`. UInt8/UInt16/UInt32 callers span MapPane, UserPane, ProfileStorage, TextMenuDialogs, and ItemDialogs, proving shared external utility linkage. The UInt24 helper has no current incoming route but remains a complete aligned source overload beside live siblings.
- UID0003YM's exact names, built-in types, linkage, source/header route, retained UInt24 disposition, and formal C++ are closed. Together with source-ready UID0003YJ and the independent UID0003YK UInt16BE/UInt32BE routes, this sustains the file root at `90/91`; broader reader/string-family and stripped original spelling questions remain the bounded cap.
- This by-file root remains prose-only and carries no `RECONSTRUCTION_CPP` metadata. Exact child pages own emitted definitions; no duplicate target body is added here.

## ObjectStatusBlob helper consumers

- ObjectStatusBlob tagged UID0004LK, full UID0004LL, and partial UID0004LM are direct consumers of this file's canonical `PacketBufferReadUInt16BE` scalar helper at `0x00575480`. Full uses the helper for every packet word while direct bytes remain indexed.
- `0x00575470` is compiler/runtime narrow-byte conversion lowering and is explicitly excluded from the source-level PacketBuffer API. Parser ownership remains UID00009S/UID0000M6; this file supplies only the scalar dependency.
- Existing file score, `NexusTK/network/` route, helper-family inventory, formal child bodies, and Socket/PacketTransform exclusions remain unchanged.


## Status

- Confidence: very strong for utility-module role, helper-family boundaries, and PacketTransform/Socket keep-out decisions; medium-high for exact original filename and API spellings.
- Proposed module: `network/PacketBuffer.cpp`
- Current Wave3 files: recovered single-global files named `PacketBuffer_*.cpp`
- Main address docs: [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) split index, child helper-family pages under that index, and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- Supporting item doc: [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md)
- Evidence basis: existing recovered-file/source-tree leads plus IDA MCP lookup/xref/decompilation/byte checks through 2026-06-25.

## Hypothesis

The original client likely had a small packet-buffer utility source file, or a packet/protocol utility file, containing C-style helpers for big-endian integer read/write, cursor-based appends, and length-prefixed string serialization. These helpers are not methods of `Socket` even though they sit in the same address neighborhood as socket transport code.

`PacketBuffer.cpp` is a better reconstruction target than leaving each helper as an independent recovered file.

## Contents

Likely source-level contents:

- Scalar big-endian write helpers for `uint8`, `uint16`, `uint24`, `uint32`, and `uint64` values.
- Scalar big-endian read helpers for `uint16`, retained raw `uint24`, `uint32`, and `uint64` values.
- Cursor-based append/read helpers for `uint8`, `uint16`, retained raw `uint24`, and `uint32` values.
- One-byte and two-byte length-prefixed ANSI/wide-to-ANSI string writer families.
- One-byte and two-byte length-prefixed packet byte/string reader families.
- A small host-name/address resolution pair currently routed through PacketBuffer as the network utility bucket, with a caveat that it may move if a stronger narrow network-address source appears.
- The `0x00575ac0` string-object-return helper is now documented as retained no-route `PacketBufferReadAnsiString16`; its byte shape, StringBase callees, sibling symmetry, and negative route proof match the PacketBuffer reader family even though IDA still finds no direct xrefs.
- The live two-byte ANSI byte-span reader at `0x00575b50` is now named `PacketBufferReadAnsiBytes16`; MainMenuPane and MapPane case `0x5B` consume it through temporary `StringBase` assignment/release flow.
- Packet nonce/XOR-key initialization belongs with [UID:0000M9][PacketTransform](by-file/PacketTransform.md), not this scalar packet-buffer module.
- B006's 2026-06-20 Socket class pass keeps Socket stateful frame/send/receive methods separate from this scalar packet-buffer module. `Socket::SendEncodedPacket` and receive parsing call PacketBuffer-style helpers, but Socket owns transport state and final framing, while PacketBuffer owns reusable endian/cursor/string serialization helpers only.

## Evidence

- IDA MCP confirms exact helper function starts from `0x00575380` through `0x00575a90`.
- IDA MCP split evidence extends the scalar packet-buffer family through [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md), with padding at `0x00575abb-0x00575ac0` separating it from the preceding helper group and padding at `0x00575b8c-0x00575b90` separating it from packet-transform key setup.
- IDA xrefs show broad helper use across the binary:
  - `WriteByteZ_575380`: 1114 code refs from 662 unique calling functions.
  - `WriteUInt16BEZ_5753A0`: 222 refs from 163 unique functions.
  - `WriteUInt32BEZ_5753F0`: 119 refs from 98 unique functions.
  - `ReadUInt16BE_575480`: 372 refs from 143 unique functions.
  - `ReadUInt32BE_5754C0`: 226 refs from 98 unique functions.
- The helper bodies are stateless scalar formatting/parsing routines, while `Socket` is stateful transport/framing code.
- `PacketWriteWideString_575850` has only six code refs, but it follows the same length-prefixed packet string contract and calls string conversion/destruction helpers.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md) is now separately documented at `NexusTK/network/`, so packet key/nonce/table helpers can stay out of this scalar packet-buffer source without leaving an ownership gap.
- 2026-06-13 A004 live IDA MCP rechecked the two-byte read pair at [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md): `lookup_funcs` reports exact helper sizes `0x82` and `0x3c`, `analyze_function` confirms both use the same big-endian `(first << 8) + second` length decode and caller-cursor advance, `xrefs_to` finds exactly two direct callers to the byte-span helper and none to the string-object helper, and `get_bytes` confirms the surrounding `0xcc` alignment boundaries.
- 2026-06-13 A004 IDA MCP `make_signature_for_range 0x00575ac0-0x00575b8c` returns a unique signature for the whole two-helper range, including its internal alignment run.
- 2026-06-25 B012 implementation of the accepted [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) source-quality report resolves the two-byte reader names and C++ disposition: `0x00575ac0` is retained no-route `PacketBufferReadAnsiString16`, `0x00575b50` is live `PacketBufferReadAnsiBytes16`, both are namespace/free helpers over `StringBase *out`, `const unsigned char *packet`, and `int *cursor`, and [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) now emits formal first-draft C++ while keeping the helper-family range intact.
- Related StringBase documentation now explains the imported string dependencies used by the read helpers: [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) for the `0x00582830` transfer/conversion helper and [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) for the `0x00582a50` bounded ANSI copy and `0x00582b30` release wrappers.
- 2026-06-17 B001 source-quality reanalysis split [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) into exact child helper families and confirmed raw source-style helper starts at `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, and `0x00575930`.
- The same B001 pass confirmed `0x00575470-0x0057547a` is `std::_Narrow_char_traits<char,int>::to_char_type`, a Dinkumware/MSVC runtime helper with 975 broad refs, and should be ignored rather than emitted as PacketBuffer source.
- B001 source-quality reanalysis resolved the trailing-zero convention: numeric and cursor write helpers leave an out-of-band scratch terminator/safety byte, while cursor advances and send lengths count only payload bytes. This rejects treating the zero as an independent protocol field.
- B001 rejected Socket, PacketTransform, and CashShopRequest ownership for these helpers. Socket owns final queue/send transport, PacketTransform owns key/nonce/XOR helpers after the later boundary, and CashShopRequest send-corridor names are stale generated pollution for this range.

## Proposed Placement

```text
network/
  PacketBuffer.h
  PacketBuffer.cpp
```

This module should expose small inline or free helper functions used by feature packet builders, `CashShopRequest` send preparation, and socket decode paths. It should not own feature-specific packet opcodes.

## Source-Quality Decisions And Remaining Limits

- Best current source-facing name family uses descriptive PacketBuffer helper names such as `PacketBufferWriteUInt16BE`, `PacketBufferReadUInt24BE`, `PacketBufferAppendUInt16BE`, `PacketBufferReadUInt32BE`, `PacketBufferAppendWideStringAsAnsi8`, `PacketBufferReadAnsiBytes8`, `PacketBufferReadAnsiString16`, and `PacketBufferReadAnsiBytes16`. These are inferred names, not proven original spellings.
- UID0003YM is a resolved target-specific exception to the broader name/type cap: use the exact UInt8/UInt16BE/UInt24BE/UInt32BE append names and signatures above for current source emission. Original lexical proof remains a confidence cap, not a C++ blocker.
- Trailing zero writes are now treated as scratch-buffer terminators/safety bytes outside counted packet payload. Cursor-based helpers advance by payload width, not by the spare byte.
- Raw no-direct-xref helpers are retained as source-style overload evidence when their bodies match live sibling families. They are not padding. [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) now demonstrates the accepted policy for this exact pair: retained no-route `PacketBufferReadAnsiString16` can emit beside live `PacketBufferReadAnsiBytes16` once names, types, range, and support evidence are strong enough.
- The host-address pair remains under PacketBuffer for now because `network/PacketBuffer.cpp` is the current packet/network utility bucket. A later move to a narrow `NetworkAddress`/`NetUtil` source requires more address-helper evidence.
- The no-direct-xref two-byte string-object reader at `0x00575ac0` is now treated as retained source-style `PacketBufferReadAnsiString16`. Stronger indirect-call evidence would still improve final-audit confidence, but lack of direct xrefs is no longer a source-facing name or C++ blocker for this exact helper pair.

## Score Rationale

- Completion `90`: this page covers the source path, exact child-family split, raw helper starts, runtime exclusion, high-fan-in scalar helpers, source-ready writer/cursor families, the exact compile-visible UInt16BE and UInt32BE reader routes, one-byte and two-byte length-prefixed string/read families, zero semantics, PacketTransform/Socket/CashShop keep-out boundaries, and supporting StringBase dependencies. Broader non-emitted reader/string/host APIs remain explicit caps.
- Confidence `91`: `PacketBuffer.cpp` remains the best direct source root because the helpers are stateless scalar packet serialization/parsing utilities with broad feature callers and no `Socket*` receiver; UInt16BE and UInt32BE now have exact ABIs, source/header placement, and formal source. Confidence remains below final audit because broader original filename/API spellings, retained no-direct-xref overload liveness, and host-address placement are inferred.

## Cross-References

- [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-14 B005 UID0003WR ordinary implementation callback: added the exact UInt16BE PacketBuffer.cpp/PacketBuffer.h route, Ranking parser dependency, helper semantics and ownership evidence, position `20` coordination, and non-emitting UInt24BE/UInt64BE boundary while preserving the prose-only root and `90/91` score.
- 2026-07-31 B009 UID0003WU compile-route repair: added UID0003YK's exact external UInt32BE PacketBuffer.h declaration and PacketBuffer.cpp definition route, position `20`, target dependency proof, partial-family non-invention boundary, and dated command20348 missing-declaration/empty-emitter diagnosis while retaining the `90/91` file score and prose-only root policy.
- 2026-07-16 B002 UID0003YM callback synchronization:
  - Kept `88/89` and `NexusTK/network/`; added exact PacketBuffer.h declarations, PacketBuffer.cpp definition route, value-first types/order, void return, external linkage, spare-zero semantics, caller spread, and retained UInt24 disposition.
  - Closed only UID0003YM-specific blockers. Preserved all StringBase reader evidence, Socket/PacketTransform/CashShop boundaries, host-address caveat, movement consumers, broader API caps, and prose-only by-file policy.
- 2026-06-25 B012 implementation callback for accepted [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) report:
  - Before: this page still said `0x00575ac0` should stay a no-direct-xref overload until stronger evidence appeared and did not record the final `PacketBufferReadAnsiString16` / `PacketBufferReadAnsiBytes16` names.
  - Changed to: preserved score `88/89` because it already exceeds the optional support-score direction and still has broader PacketBuffer API caveats; added the accepted retained-overload proof, final two-byte reader names, type/source-shape direction, and formal-C++ status in the exact [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) child.
  - Evidence: accepted B012 report, current MCP session `80de0a67`, [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) boundaries/padding/no-route and positive-caller evidence, sibling one-byte reader naming convention, and StringBase support docs [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md)/[UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md).
- 2026-06-17 Supervisor execution of B001 report: raised from `86/86` to `88/89` and incorporated the PacketBuffer helper split/index research.
  - Before: the file page still summarized the old broad helper island, left zero semantics and raw helper starts unresolved, and did not record the embedded runtime helper exclusion in source-layout terms.
  - After: the page records the exact [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) split model, raw helper starts, source-facing name directions, trailing-zero convention, string-prefix families, host-address caveat, and PacketBuffer/Socket/PacketTransform/CashShop ownership boundaries.
  - Evidence: B001 report `0001HZ-packetbuffer-helpers-source-quality.md`, child pages [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)-[UID:0003YP][0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers](by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md), live IDA MCP xref/decompilation/byte evidence cited there, and existing PacketBuffer/StringBase/Socket/PacketTransform support docs.
- 2026-06-20 B006 Socket support sync:
  - Added cross-reference that Socket stateful frame/send/receive methods call PacketBuffer helpers but remain Socket-owned; PacketBuffer owns only scalar endian/cursor/string serialization helpers.
- 2026-06-13 A004 Goal 2: Raised from `84/82` to `86/86`, clearing the direct parent gate for [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md).
  - Before: the parent recorded the correct network placement and broad helper family, but still cited older generated-source provenance and kept confidence below the strict child-assignment gate.
  - After: the parent records the 2026-06-13 IDA recheck of the two-byte read helper pair, StringBase dependency links, range-signature/padding evidence, and why PacketBuffer remains the direct source root despite unresolved final names.
  - Evidence: IDA MCP `lookup_funcs`, `analyze_function`, `xrefs_to`, `insn_query`, `get_bytes`, and `make_signature_for_range` for `0x00575ac0-0x00575b8c`, plus existing proposed-source-tree network grouping.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/` and raised confidence from `78` to `82`.
  - Evidence: the page already proposes `network/PacketBuffer.cpp`; the adjacent length-prefixed read helper page and ignored padding ledger confirm the scalar packet-buffer range boundary before packet-transform setup; PacketTransform now has a separate network owner for nonce/key-table helpers.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the utility-module hypothesis, helper families, IDA xref scale, socket/transform boundaries, placement, open questions, and cross-references; confidence remains capped by original helper names and exact filename uncertainty.

## UID0003U6 Movement Packet Consumer Synchronization - 2026-07-15

- Current file metadata remains `88/89` with `NexusTK/network/` ownership. PacketBuffer owns scalar/cursor/string serialization helpers only; UserPane owns movement construction and Socket/packet sender owns queue/send transport.
- [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md), [UID:0003UX][0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket](by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md), and [UID:0003UY][0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket](by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md) are exact movement consumers.
- Raw scalar ABI is value first, destination second. Cursor append ABI is value first, packet base second, cursor pointer third. Destination-first generated convenience calls are historical wrapper style and are not raw binary/source-signature evidence.
- Exact packets remain: blocked opcode `0x69` sends six bytes; waypoint opcode `0x06` sends 16 bytes; normal opcode `0x32` sends nine bytes. For normal movement, `WriteUInt16BE(0x32, packet + 8)` followed by `packet[9] = 0` leaves sent byte eight zero, not a trailing `0x32` marker.
- Cursor helpers advance only by payload width and leave a spare local zero outside sent length. MovementWaypointSegment remains four signed coordinates; shared [UID:0004R0][MapPoint](by-type/by-struct/MapPoint.md) row/column semantics affect caller values but do not change PacketBuffer ownership or writer bodies.
- Status byte/tag corrections belong to UserPane/MapPane (`m_displayStatusByte`, `AllowsMovementStatusTag`, Config bit). PacketBuffer remains type-agnostic; no protocol-specific movement method, STL buffer, hardening guard, or duplicate source root is added.
