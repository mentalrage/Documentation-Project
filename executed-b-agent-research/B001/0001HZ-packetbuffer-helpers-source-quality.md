** TARGET-REPORT-UID:0001HZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001HZ PacketBuffer Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Assignment: `B001-goal2-packetbuffer-helpers-source-quality-0001HZ-20260617`.
- Target: [UID:0001HZ] `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`.
- Current state: `82/88`, owner/emitter [UID:0000M8] `PacketBuffer`, `RECONSTRUCTABLE:TRUE`, blank formal C++.
- Current recommendation: reclassify [UID:0001HZ] as a non-emitting PacketBuffer split/index, then create exact child pages for source-bearing helper families and ignored rows for the embedded runtime helper/padding.
- Recommended [UID:0001HZ] metadata after supervisor execution: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000M8`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`.
- Confidence: high for the structural recommendation; medium-high for exact original API spellings.

Report-only constraint honored: B001 did not edit by-* documentation, generated reports, generated source, source files, IDA DB, or `by-memory/-coverage-report.md`. No lease was required for this research report inside B001's own folder.

## Executive Recommendation

[UID:0001HZ] should not remain a reconstructable/emitting by-memory item. It is a helper island, not one C++ body, and it includes:

- multiple independent PacketBuffer-style scalar/cursor/string helper functions;
- raw source-authored helper starts that the current page omits because IDA does not model them as functions;
- one embedded third-party/runtime Dinkumware helper at `0x00575470-0x0057547a`;
- internal alignment gaps that are currently only partly documented.

The best repair is a non-emitting parent/index at [UID:0001HZ] plus child pages:

| Proposed child range | Proposed page name | Route | Recommended state |
| --- | --- | --- | --- |
| `0x00575380-0x00575470` | `PacketBufferScalarBigEndianWriteHelpers` | [UID:0000M8] `PacketBuffer` | `87/91`, reconstructable, emitter `0000M8` |
| `0x00575470-0x0057547a` | `std::_Narrow_char_traits<char,int>::to_char_type` | ignored/runtime | ignored, `100/95` |
| `0x00575480-0x00575574` | `PacketBufferScalarBigEndianReadHelpers` | [UID:0000M8] `PacketBuffer` | `87/91`, reconstructable, emitter `0000M8` |
| `0x00575580-0x0057564e` | `PacketBufferHostAddressResolutionHelpers` | [UID:0000M8] `PacketBuffer` initially; source text should say network-address utility | `85/88`, reconstructable, emitter `0000M8` |
| `0x00575650-0x00575703` | `PacketBufferCursorAppendBigEndianHelpers` | [UID:0000M8] `PacketBuffer` | `86/90`, reconstructable, emitter `0000M8` |
| `0x00575710-0x005757c8` | `PacketBufferCursorReadBigEndianHelpers` | [UID:0000M8] `PacketBuffer` | `86/90`, reconstructable, emitter `0000M8` |
| `0x005757d0-0x00575a07` | `PacketBufferStringWriteHelpers` | [UID:0000M8] `PacketBuffer` | `85/88`, reconstructable, emitter `0000M8` |
| `0x00575a10-0x00575abb` | `PacketBufferOneByteStringReadHelpers` | [UID:0000M8] `PacketBuffer` | `86/90`, reconstructable, emitter `0000M8` |

Do not create a new `NetworkAddress.cpp` owner for `0x00575580`/raw `0x00575620` in this pass. The functions are network-address helpers rather than packet serialization helpers, but the current source-tree model has `network/PacketBuffer.cpp` as the broader C-style packet/network utility bucket, the pair sits physically inside this helper island, and there is not enough evidence for a standalone source file from only this pair.

## Evidence Standards Used

Evidence checked:

- Existing docs: target [UID:0001HZ], [UID:0000M8] `PacketBuffer`, [UID:0000V1] `PacketBufferHelpers`, [UID:000243] `PacketBufferLengthPrefixedReadHelpers`, [UID:0001I0] `PacketNonceInitialization`, [UID:0000M9] `PacketTransform`, [UID:0000NS]/[UID:0000DD] `Socket`, [UID:0000I0]/[UID:00001H] `CashShopRequest`, [UID:0001QH] `client_network`, [UID:0002BR] `StructuredHostPortIdLauncherParser`, and proposed source tree notes.
- Existing B-agent research: profile sidecar report evidence for source-facing cursor helper names such as `PacketBufferAppendByte`, `PacketBufferAppendUInt16`, and `PacketBufferAppendWideStringAsAnsi`.
- Live IDA MCP session `b003_00018a_ime_comp_20260617`: `lookup_funcs`, `analyze_function`, `xrefs_to`, `xref_query`, `find`, `find_bytes`, `get_bytes`, and `insn_query`.
- Negative evidence: direct code/data/immediate/VA/RVA searches for `0x00575970` and `0x00575ac0`; direct xref searches for the newly identified raw helper starts; two broad `insn_query` branch scans timed out and are recorded below as non-blocking because narrower code-ref and byte searches succeeded.

Generated C++ was not used as authority. Existing generated/source-tree notes were treated only as source-layout context.

## IDA MCP Facts

Modeled function inventory from live `lookup_funcs`:

- `0x00575380`, `sub_575380`, size `0x11`: byte write plus one spare zero byte.
- `0x005753a0`, `sub_5753A0`, size `0x19`: 16-bit big-endian write plus spare zero.
- `0x005753c0`, `sub_5753C0`, size `0x21`: 24-bit big-endian write plus spare zero.
- `0x005753f0`, `sub_5753F0`, size `0x29`: 32-bit big-endian write plus spare zero.
- `0x00575420`, `sub_575420`, size `0x50`: 64-bit big-endian write plus spare zero.
- `0x00575470`, `std::_Narrow_char_traits<char,int>::to_char_type`, size `0x0a`: runtime helper, not PacketBuffer source.
- `0x00575480`, `sub_575480`, size `0x1a`: 16-bit big-endian read.
- `0x005754c0`, `sub_5754C0`, size `0x26`: 32-bit big-endian read.
- `0x005754f0`, `sub_5754F0`, size `0x84`: 64-bit big-endian read.
- `0x00575580`, `sub_575580`, size `0x9a`: wide hostname to four address bytes.
- `0x00575650`, `sub_575650`, size `0x18`: cursor append byte plus spare zero.
- `0x00575670`, `sub_575670`, size `0x23`: cursor append 16-bit big-endian plus spare zero.
- `0x005756d0`, `sub_5756D0`, size `0x33`: cursor append 32-bit big-endian plus spare zero.
- `0x00575710`, `sub_575710`, size `0x13`: cursor read byte.
- `0x00575730`, `sub_575730`, size `0x2d`: cursor read 16-bit big-endian.
- `0x00575790`, `sub_575790`, size `0x38`: cursor read 32-bit big-endian.
- `0x005757d0`, `sub_5757D0`, size `0x40`: append one-byte-length ANSI string from `strlen`.
- `0x00575850`, `sub_575850`, size `0x8b`: convert wide string to ANSI and append one-byte-length bytes.
- `0x00575970`, `sub_575970`, size `0x97`: convert wide string to ANSI and append two-byte-length bytes; no direct refs found.
- `0x00575a10`, `sub_575A10`, size `0x71`: read one-byte-length bytes into a temporary string object then transfer to caller output.
- `0x00575a90`, `sub_575A90`, size `0x2b`: read one-byte-length bytes into caller storage.

Raw non-function helper starts found by `get_bytes` plus `insn_query`:

- `0x005754a0-0x005754bd`: raw 24-bit big-endian reader between `sub_575480` and `sub_5754C0`; no IDA function object and no direct refs.
- `0x00575620-0x0057564e`: raw ANSI hostname resolver, mirroring the post-conversion body of `sub_575580`; no function object and no direct refs.
- `0x005756a0-0x005756cb`: raw cursor append 24-bit big-endian plus spare zero; no function object and no direct refs.
- `0x00575760-0x0057578e`: raw cursor read 24-bit big-endian; no function object and no direct refs.
- `0x00575810-0x00575841`: raw append caller-provided byte span with one-byte length; no function object and no direct refs.
- `0x005758e0-0x0057592c`: raw append ANSI `strlen` string with two-byte big-endian length; no function object and no direct refs.
- `0x00575930-0x0057596b`: raw append caller-provided byte span with two-byte big-endian length; no function object and no direct refs.

Xref totals from live `xref_query`:

- High-traffic modeled helpers: `0x00575380` has 1114 code refs, `0x005753a0` has 222, `0x005753f0` has 119, `0x00575480` has 372, and `0x005754c0` has 226.
- Narrow modeled helpers: `0x005753c0` has 2, `0x00575420` has 4, `0x005754f0` has 2, `0x00575580` has 1, `0x00575650` has 29, `0x00575670` has 13, `0x005756d0` has 9, `0x00575710` has 19, `0x00575730` has 16, `0x00575790` has 8, `0x005757d0` has 12, `0x00575850` has 6, `0x00575a10` has 5, `0x00575a90` has 6, and `0x00575b50` has 2.
- Runtime helper `0x00575470` has 975 code refs and is broadly called outside PacketBuffer.
- No direct code refs: raw starts `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, `0x00575930`, modeled `0x00575970`, and neighboring `0x00575ac0`.

Boundary bytes:

- `0x00575377-0x00575380` remains nine `0xcc` bytes after `GetConnectionStatus`.
- `0x00575abb-0x00575ac0` remains five `0xcc` bytes before [UID:000243].
- Internal `0xcc` alignment exists between most helpers; several current "padding" assumptions were stale because they skipped raw code starts at `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, and `0x00575930`.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Emitting Policy

Best inference: [UID:0001HZ] should become a non-emitting split/index.

Evidence checked: function starts/sizes, raw code inside current inventory gaps, embedded runtime helper, internal alignment, PacketBuffer/Socket/PacketTransform source pages, and current coverage row. Rejected alternative: keep [UID:0001HZ] reconstructable/emitting as one PacketBuffer C++ block. That would emit a Dinkumware runtime helper and hide raw source-authored overloads inside undocumented gaps. Rejected alternative: keep current page but merely add evidence and C++. That still makes one by-memory item responsible for many unrelated function bodies and runtime support.

Impact: raise documentation quality to `88/90`, but set `RECONSTRUCTABLE:FALSE` and blank emitters. Exact child helper-family pages should own source emission later.

### Helper Names And Signatures

Recommended source-facing names are descriptive/inferred, not proven original names:

| Address | Best source-facing name/signature direction | Evidence and rejected alternatives |
| --- | --- | --- |
| `0x00575380` | `PacketBufferWriteUInt8(std::uint8_t value, std::uint8_t* out)` | Writes `out[0]=value`, `out[1]=0`; high fan-in. Reject `WriteByteZ` as final API spelling because the zero is buffer safety, not a separate protocol field. |
| `0x005753a0` | `PacketBufferWriteUInt16BE(std::uint16_t value, std::uint8_t* out)` | Writes high byte, low byte, spare zero via a little-endian word store. |
| `0x005753c0` | `PacketBufferWriteUInt24BE(std::uint32_t value, std::uint8_t* out)` | Writes `BYTE2`, `BYTE1`, low byte, spare zero. Use `UInt24` because callers pass 32-bit values but only three payload bytes persist. |
| `0x005753f0` | `PacketBufferWriteUInt32BE(std::uint32_t value, std::uint8_t* out)` | Writes four big-endian bytes plus spare zero. |
| `0x00575420` | `PacketBufferWriteUInt64BE(std::uint64_t value, std::uint8_t* out)` | Writes eight big-endian bytes plus spare zero; four refs total. |
| `0x00575480` | `PacketBufferReadUInt16BE(const std::uint8_t* in)` | Decompiled `(in[0] << 8) + in[1]`. |
| raw `0x005754a0` | `PacketBufferReadUInt24BE(const std::uint8_t* in)` | Raw bytes decode three-byte big-endian read; no refs. Best kept as retained overload evidence, not dead code unless later PE-level proof says otherwise. |
| `0x005754c0` | `PacketBufferReadUInt32BE(const std::uint8_t* in)` | Decompiled four-byte big-endian read. |
| `0x005754f0` | `PacketBufferReadUInt64BE(const std::uint8_t* in)` | Decompiled eight-byte big-endian read. |
| `0x00575580` | `ResolveHostAddressFromWideName(const wchar_t* host, void* out4)` | Converts wide host to ANSI, calls `gethostbyname`, copies four bytes. `PacketBufferResolveHostAddressW` is acceptable as current route name, but source prose should mark this as a network-address utility rather than packet serialization. |
| raw `0x00575620` | `ResolveHostAddressFromAnsiName(const char* host, void* out4)` | Same gethost/copy body without conversion; no refs. |
| `0x00575650` | `PacketBufferAppendUInt8(std::uint8_t value, std::uint8_t* base, int* cursor)` | Writes at `base + *cursor`, spare zero, advances cursor by one. Prior profile research used `PacketBufferAppendByte`; both are acceptable, but `UInt8` matches numeric family. |
| `0x00575670` | `PacketBufferAppendUInt16BE(std::uint16_t value, std::uint8_t* base, int* cursor)` | Writes big-endian bytes and advances by two. |
| raw `0x005756a0` | `PacketBufferAppendUInt24BE(std::uint32_t value, std::uint8_t* base, int* cursor)` | Raw 24-bit append; no refs. |
| `0x005756d0` | `PacketBufferAppendUInt32BE(std::uint32_t value, std::uint8_t* base, int* cursor)` | Writes four bytes and advances by four. |
| `0x00575710` | `PacketBufferReadUInt8(const std::uint8_t* base, int* cursor)` | Reads byte and advances cursor by one. |
| `0x00575730` | `PacketBufferReadUInt16BE(const std::uint8_t* base, int* cursor)` | Reads two bytes and advances by two. |
| raw `0x00575760` | `PacketBufferReadUInt24BE(const std::uint8_t* base, int* cursor)` | Raw 24-bit cursor read; no refs. |
| `0x00575790` | `PacketBufferReadUInt32BE(const std::uint8_t* base, int* cursor)` | Reads four bytes and advances by four. |
| `0x005757d0` | `PacketBufferAppendAnsiString8(const char* text, std::uint8_t* base, int* cursor)` | Writes one-byte `strlen` prefix, copies bytes, advances by prefix plus length. Reject "null-terminated packet string" because the copied payload is length-prefixed, not terminated. |
| raw `0x00575810` | `PacketBufferAppendBytes8(const void* src, std::uint8_t length, std::uint8_t* base, int* cursor)` | Raw explicit one-byte-length byte span append; no refs. |
| `0x00575850` | `PacketBufferAppendWideStringAsAnsi8(const wchar_t* text, std::uint8_t* base, int* cursor)` | Uses StringBase conversion to ANSI then one-byte prefix. Prior profile research uses this name. |
| raw `0x005758e0` | `PacketBufferAppendAnsiString16(const char* text, std::uint8_t* base, int* cursor)` | Raw `strlen` string append with two-byte big-endian length; no refs. |
| raw `0x00575930` | `PacketBufferAppendBytes16(const void* src, std::uint16_t length, std::uint8_t* base, int* cursor)` | Raw explicit two-byte-length byte span append; no refs. |
| `0x00575970` | `PacketBufferAppendWideStringAsAnsi16(const wchar_t* text, std::uint8_t* base, int* cursor)` | Modeled wide-to-ANSI two-byte-length writer; no refs. |
| `0x00575a10` | `PacketBufferReadAnsiString8(StringBase* out, const std::uint8_t* base, int* cursor)` | One-byte length into temporary string object then transfer. |
| `0x00575a90` | `PacketBufferReadAnsiBytes8(void* outStorage, const std::uint8_t* base, int* cursor)` | One-byte length into caller-provided storage. |

### Trailing-Zero Semantics

Best inference: the zero writes are scratch-buffer terminators/safety bytes outside the counted packet length, not independent protocol fields.

Evidence checked: scalar helpers write one spare zero after the numeric payload while cursor helpers advance only by the payload byte count. `QueueAndSendPacket` separately copies caller bytes and appends one zero before posting command `8`. String append helpers write a zero after the length prefix before copying payload bytes; for non-empty strings that placeholder is overwritten by the first payload byte. This rejects "the protocol sends a trailing zero after every field." It supports "packet builders keep stack/local scratch buffers C-string-safe while using explicit send lengths."

Impact: helper names should not include `Z` unless a local doc wants a low-level behavior mnemonic. Source-facing C++ should treat the zero as implementation detail.

### Packet String Length Conventions

Best inference: PacketBuffer has two string-length families:

- one-byte length prefixes for common ANSI/wide-to-ANSI strings and one-byte readers;
- two-byte big-endian length prefixes for larger/alternate string or byte-span writers, plus [UID:000243] two-byte readers.

Evidence checked: `0x005757d0`, `0x00575810`, and `0x00575850` increment cursor by one before copying; `0x005758e0`, `0x00575930`, and `0x00575970` store high/low length bytes and increment by two. [UID:000243] mirrors the two-byte read side. The helpers do not clamp lengths; caller-side validation must supply values that fit the selected prefix width.

### `sub_575580` Source Placement

Best inference: keep the address-resolution pair under current [UID:0000M8] `PacketBuffer` source route, but document it as a generic network-address helper and not as packet serialization.

Evidence checked: `0x00575580` has one live caller, [UID:0002BR] `StructuredHostPortIdLauncherParser`, which parses `/host:`, `/portno:`, and `/id:` from the command line and stores the resolved four-byte host at `this+0x2915b4`. The raw ANSI variant at `0x00575620` mirrors the post-conversion body and has no refs. No `Socket*`, packet-transform global, or CashShopRequest state is touched. Rejected `Socket.cpp` because there is no Socket receiver/lifetime state and the caller is RegistryConfig startup parsing before transport setup. Rejected `CashShopRequest` and `PacketTransform` because neither owns name resolution. Rejected immediate new `NetworkAddress.cpp` because only this pair currently justifies it; the existing `PacketBuffer.cpp` file page already acts as the small network packet/protocol utility bucket.

Impact: child page can be `85/88` under `PacketBuffer`, with an explicit caveat that a later broader network utility split could move it if more address helpers are found.

### `sub_575970` No-Direct-Xref Liveness

Best inference: treat `0x00575970` as a retained source-authored overload, not an active live helper and not compiler/runtime code.

Evidence checked:

- `xrefs_to` and `xref_query` report zero direct code refs.
- IDA `find type=code_ref`, `find type=data_ref`, and `find type=immediate` for `0x00575970` report zero matches.
- `find_bytes` found no little-endian VA bytes `70 59 57 00` and no RVA bytes `70 59 17 00`.
- Two broad `insn_query` branch scans for direct call/jump operands timed out under the shared worker; this is weaker than a completed full branch scan, but the successful `find code_ref`/`xrefs_to` negative results cover modeled direct refs.
- The body is behaviorally symmetric with live `0x00575850` and raw `0x005758e0`/`0x00575930` two-byte string helpers, calls the same StringBase conversion/copy/release family, and is bounded by `0xcc` alignment.

Rejected alternatives: ignored/dead padding is rejected because the body is coherent source-style packet writer code. Runtime/compiler helper is rejected because the body calls project StringBase helpers and `_memmove`, and belongs to the same string serialization family. Direct source emission is deferred because no current caller proves the overload is used.

Impact: keep in the `PacketBufferStringWriteHelpers` child at a conservative `85/88`, blank formal C++ initially.

### Runtime Helper Treatment

Best inference: `0x00575470-0x0057547a` must be ignored/runtime, not PacketBuffer-owned.

Evidence checked: IDA name is `std::_Narrow_char_traits<char,int>::to_char_type`, decompilation is only `return *(char*)arg;`, and live `xref_query` reports 975 code refs across many unrelated functions. Rejected inclusion in PacketBuffer C++ because this is Dinkumware/MSVC STL support that should come from the toolchain.

Impact: the current target cannot remain fully reconstructable over the whole byte range.

### Ownership Boundaries

Best route:

- `PacketBuffer.cpp`: scalar/cursor/string packet byte helpers and the address-resolution pair for now.
- `Socket.cpp`: `QueueAndSendPacket`, transport command handling, final send/receive/framing, and `g_packetSender` lifetime.
- `PacketTransform.cpp`: nonce/key/XOR helper families after the `0x00575b90`/`0x00575cb0` boundary and transform globals.
- `CashShopRequest.cpp`: cash-shop/download request payload helpers only; stale generated send-corridor ownership should not pull PacketBuffer helpers there.

Evidence checked: support docs for [UID:0000M8], [UID:0000NS]/[UID:0000DD], [UID:0000M9], [UID:0000I0]/[UID:00001H], [UID:0001QH], current xref distribution, and caller shape. Rejected a generic `ProtocolSend.cpp` owner because these are serialization primitives used by many features rather than feature packet builders or sender interface methods.

## Function / Child Inventory

| Range / Item | Role | Current IDA status | Xref total | Recommended route |
| --- | --- | --- | ---: | --- |
| `0x00575380-0x00575470` | scalar big-endian writers, `8/16/24/32/64` | five modeled funcs | 1114/222/2/119/4 | PacketBuffer child |
| `0x00575470-0x0057547a` | `std::_Narrow_char_traits<char,int>::to_char_type` | modeled runtime func | 975 | ignored/runtime |
| `0x00575480-0x00575574` | scalar big-endian readers, `16/24/32/64` | three modeled funcs plus raw `0x5754a0` | 372/0/226/2 | PacketBuffer child |
| `0x00575580-0x0057564e` | wide/ANSI host-to-address bytes | one modeled func plus raw `0x575620` | 1/0 | PacketBuffer child with network-address caveat |
| `0x00575650-0x00575703` | cursor append `8/16/24/32` | three modeled funcs plus raw `0x5756a0` | 29/13/0/9 | PacketBuffer child |
| `0x00575710-0x005757c8` | cursor read `8/16/24/32` | three modeled funcs plus raw `0x575760` | 19/16/0/8 | PacketBuffer child |
| `0x005757d0-0x00575a07` | one-byte/two-byte ANSI/wide string writers | three modeled funcs plus raw `0x575810/0x5758e0/0x575930` | 12/0/6/0/0/0 | PacketBuffer child |
| `0x00575a10-0x00575abb` | one-byte string readers | two modeled funcs | 5/6 | PacketBuffer child |

## Ranked Ownership Analysis

### 1. [UID:0000M8] `PacketBuffer`

Evidence for:

- Existing file page and by-item helper page already define `network/PacketBuffer.cpp` as the shared C-style packet field read/write/append/string utility module.
- Live IDA confirms broad cross-feature caller distribution for scalar helpers and no Socket/CashShop receiver state in the helper bodies.
- Prior source-quality reports use these helpers as dependencies, not owners of feature packet builders.
- The proposed source tree explicitly lists `network/PacketBuffer.cpp`.

Evidence against:

- The hostname resolver pair is network-address utility logic, not packet buffer serialization.
- Exact original filename/API names remain inferred.

Decision: keep `PacketBuffer` as direct source route for source-bearing children. Document the host resolver caveat and consider a later `NetworkAddress`/`NetUtil` split only if more helpers appear.

### 2. [UID:0000NS]/[UID:0000DD] `Socket`

Evidence for:

- Same neighborhood as Socket transport and QueueAndSendPacket; send path consumes buffers built by these helpers.

Evidence against:

- Helper bodies are stateless free functions with broad feature callers and no `Socket*`.
- Socket docs place scalar PacketBuffer helpers outside `Socket.cpp`.
- `sub_575580` caller is RegistryConfig startup parser, not Socket.

Decision: reject Socket ownership.

### 3. [UID:0000M9] `PacketTransform`

Evidence for:

- Physically adjacent transform helper ranges begin soon after the target.

Evidence against:

- PacketTransform owns nonce/key/XOR helpers and mutable transform globals, not scalar packet field serialization.
- Padding and [UID:000243] separate PacketBuffer readers before transform setup.

Decision: reject PacketTransform ownership for [UID:0001HZ].

### 4. [UID:0000I0]/[UID:00001H] `CashShopRequest`

Evidence for:

- Stale generated send-corridor names historically attached some network helpers to CashShopRequest.

Evidence against:

- Current Socket/CashShop docs correct that pollution: `g_packetSender` lifetime is Socket, and PacketBuffer helpers are shared dependencies.
- The target helpers have broad non-cash-shop callers.

Decision: reject CashShopRequest ownership.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001HZ].

Reason: [UID:0001HZ] should become `RECONSTRUCTABLE:FALSE` and non-emitting. It is a split/index over many helper bodies and includes one runtime helper that must not be hand-emitted as NexusTK source.

Do not populate formal C++ for the proposed child pages in the first supervisor split pass. Although several children would clear the current numeric code-entry gate, the child pages do not exist yet, and the source-facing `PacketBuffer.h` API policy still needs one coordinated decision for:

- exported names versus file-local names;
- `std::uint8_t*`/`char*`/`void*` buffer spelling;
- `int*` versus `std::size_t*` cursor type;
- whether retained no-xref overloads should emit as live helpers, review-only helpers, or remain documented without C++;
- whether the host-address helper pair stays in `PacketBuffer.cpp` or later moves to a narrow network utility source.

Review-only source direction for later C++:

```cpp
// PacketBuffer.cpp source direction, not formal target code for this pass.
void PacketBufferWriteUInt16BE(unsigned value, unsigned char* out);
void PacketBufferAppendUInt16BE(unsigned value, unsigned char* base, int* cursor);
int PacketBufferReadUInt16BE(const unsigned char* base, int* cursor);
void PacketBufferAppendWideStringAsAnsi8(const wchar_t* text, unsigned char* base, int* cursor);
bool ResolveHostAddressFromWideName(const wchar_t* host, void* outAddressBytes);
```

If the supervisor chooses to create one child per individual helper rather than the helper-family pages above, the high-traffic modeled helpers `0x00575380`, `0x005753a0`, `0x005753f0`, `0x00575480`, and `0x005754c0` are the safest first formal-C++ candidates. The raw/no-xref variants and host resolver should remain blank initially.

## Support Docs To Update

Recommended support-doc updates if accepted:

- [UID:0001HZ] target: reclassify as non-emitting split/index; replace "21 functions" with a modeled-plus-raw inventory; state that omitted raw helper starts were found at `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, and `0x00575930`.
- [UID:0000M8] `PacketBuffer`: update helper-family inventory, trailing-zero semantics, and note that `network/PacketBuffer.cpp` currently also carries the small host-address utility pair.
- [UID:0000V1] `PacketBufferHelpers`: update helper summary with raw helpers, xref totals, string prefix convention, and runtime helper exclusion.
- [UID:000243] `PacketBufferLengthPrefixedReadHelpers`: no score change required, but add a cross-note that two-byte write-side overloads live in the `PacketBufferStringWriteHelpers` child after split.
- [UID:0001QH] `client_network`: refine PacketBuffer conventions to say numeric helpers leave an out-of-band scratch terminator; do not describe it as protocol payload.
- `by-memory/-ignored.md`: add ignored entries for `0x00575470-0x0057547a` runtime helper and inter-child padding rows if the split uses exact family children.
- Generated state after supervisor edits: refresh `auto-generated/by-memory-tool-report.md`, `project-level/-auto-completion-stats.md`, and validator state through normal validator/memory-range commands.

No IDA DB edits are required. A future C-agent may optionally define raw functions at `0x005754a0`, `0x00575620`, `0x005756a0`, `0x00575760`, `0x00575810`, `0x005758e0`, and `0x00575930`, but documentation can proceed without modifying IDA.

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly from this report.

Placement context: replace the existing [UID:0001HZ] row immediately after the existing `0x00575377-0x00575380` padding row and before the existing `0x00575abb-0x00575ac0` padding row. Keep the existing `0x00575abb-0x00575ac0` row after this block.

Use normal UID assignment for new child pages. Replace `<UID-PB-...>` placeholders with validator-assigned UIDs before applying docs or coverage rows.

```text
    - [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) 0x00575380-0x00575abb | packet helper split index | PacketBufferHelpers : not_reconstructable : 88% : very-strong : B001 2026-06-17 source-quality reanalysis reclassifies this overbroad PacketBuffer helper island as a non-emitting split/index; live IDA confirmed modeled scalar/cursor/string helpers, omitted raw 24-bit/address/string overload starts, `std::_Narrow_char_traits<char,int>::to_char_type` runtime exclusion, exact padding, broad xref distribution, no-direct-ref retained overloads, PacketBuffer/Socket/PacketTransform/CashShop boundaries, and blank aggregate final C++ policy.
        - [UID:<UID-PB-SCALAR-WRITE>][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) 0x00575380-0x00575470 | helper family | PacketBufferScalarBigEndianWriteHelpers : reconstructable : 87% : very-strong : Exact PacketBuffer scalar writer family for 8/16/24/32/64-bit big-endian values; live IDA confirms modeled starts `0x00575380`, `0x005753a0`, `0x005753c0`, `0x005753f0`, and `0x00575420`, xref totals 1114/222/2/119/4, spare zero byte outside counted packet payload, and internal alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00575470-0x0057547a | runtime helper | std::_Narrow_char_traits<char,int>::to_char_type : ignored : 100% : very-strong : Dinkumware/MSVC char-traits helper; live IDA names the function, decompiles it as a one-byte load, and reports 975 broad code refs outside PacketBuffer, so it must come from the toolchain rather than NexusTK source.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0057547a-0x00575480 | padding | PacketBuffer runtime helper to scalar read helper alignment : ignored : 100% : strong : Live IDA/raw bytes confirm six `0xcc` alignment bytes.
        - [UID:<UID-PB-SCALAR-READ>][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md) 0x00575480-0x00575574 | helper family | PacketBufferScalarBigEndianReadHelpers : reconstructable : 87% : very-strong : Exact PacketBuffer scalar reader family for 16/24/32/64-bit big-endian values; live IDA confirms modeled `0x00575480`, `0x005754c0`, `0x005754f0`, raw retained `0x005754a0` 24-bit reader, xref totals 372/0/226/2, and internal alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00575574-0x00575580 | padding | PacketBuffer scalar readers to host address helpers alignment : ignored : 100% : strong : Live IDA/raw bytes confirm twelve `0xcc` alignment bytes.
        - [UID:<UID-PB-HOST-ADDR>][0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers](by-memory/0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md) 0x00575580-0x0057564e | network address helper pair | PacketBufferHostAddressResolutionHelpers : reconstructable : 85% : strong : Wide and ANSI hostname-to-four-address-byte helpers; live IDA confirms modeled `0x00575580` converts wide host text before `gethostbyname`, raw `0x00575620` mirrors the ANSI post-conversion resolver, only one live caller from StructuredHostPortIdLauncherParser, no direct refs to the raw ANSI variant, and no Socket/PacketTransform/CashShop state.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0057564e-0x00575650 | padding | Host address helpers to cursor append helpers alignment : ignored : 100% : strong : Live IDA/raw bytes confirm two `0xcc` alignment bytes.
        - [UID:<UID-PB-CURSOR-APPEND>][0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers](by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md) 0x00575650-0x00575703 | helper family | PacketBufferCursorAppendBigEndianHelpers : reconstructable : 86% : very-strong : Exact cursor append family for 8/16/24/32-bit big-endian values; live IDA confirms modeled `0x00575650`, `0x00575670`, `0x005756d0`, raw retained `0x005756a0` 24-bit append, xref totals 29/13/0/9, cursor advances by payload width while leaving a spare zero byte.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00575703-0x00575710 | padding | Cursor append helpers to cursor read helpers alignment : ignored : 100% : strong : Live IDA/raw bytes confirm thirteen `0xcc` alignment bytes.
        - [UID:<UID-PB-CURSOR-READ>][0x00575710-0x005757c8.PacketBufferCursorReadBigEndianHelpers](by-memory/0x00575710-0x005757c8.PacketBufferCursorReadBigEndianHelpers.md) 0x00575710-0x005757c8 | helper family | PacketBufferCursorReadBigEndianHelpers : reconstructable : 86% : very-strong : Exact cursor read family for 8/16/24/32-bit values; live IDA confirms modeled `0x00575710`, `0x00575730`, `0x00575790`, raw retained `0x00575760` 24-bit read, xref totals 19/16/0/8, and cursor advances by decoded payload width.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005757c8-0x005757d0 | padding | Cursor read helpers to string write helpers alignment : ignored : 100% : strong : Live IDA/raw bytes confirm eight `0xcc` alignment bytes.
        - [UID:<UID-PB-STRING-WRITE>][0x005757d0-0x00575a07.PacketBufferStringWriteHelpers](by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md) 0x005757d0-0x00575a07 | helper family | PacketBufferStringWriteHelpers : reconstructable : 85% : strong : Exact PacketBuffer one-byte and two-byte length-prefixed ANSI/wide-to-ANSI string writer family; live IDA confirms modeled `0x005757d0`, `0x00575850`, `0x00575970`, raw retained `0x00575810`, `0x005758e0`, and `0x00575930`, xref totals 12/0/6/0/0/0, StringBase conversion/release callees, zero direct code/data/immediate/VA/RVA refs to `0x00575970`, and blank initial formal C++ pending API-name/cursor-type policy.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00575a07-0x00575a10 | padding | PacketBuffer string write helpers to one-byte string readers alignment : ignored : 100% : strong : Live IDA/raw bytes confirm nine `0xcc` alignment bytes.
        - [UID:<UID-PB-STRING-READ8>][0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers](by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md) 0x00575a10-0x00575abb | helper pair | PacketBufferOneByteStringReadHelpers : reconstructable : 86% : very-strong : Exact one-byte length-prefixed reader pair; live IDA confirms modeled `0x00575a10` string-object transfer helper and `0x00575a90` caller-storage helper, xref totals 5/6, StringBase bounded-copy/conversion/release callees, cursor advancement, internal alignment, and boundary before existing `0x00575abb-0x00575ac0` padding.
```

## Validation Commands For Supervisor

No validator commands were run by B001 because this was report-only and no by-* files were edited.

Suggested supervisor commands after creating child pages and applying docs/coverage:

> Executable block R001 was removed from this report and preserved verbatim in [0001HZ-packetbuffer-helpers-source-quality-removed.md](0001HZ-packetbuffer-helpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also run scoped `validator.py --mode file --apply` on each new child page after it receives a real UID.

## Negative Evidence Summary

Checked and rejected:

- One-body aggregate emission: rejected by multiple helper functions, omitted raw starts, and runtime helper inclusion.
- Socket ownership: rejected because helper bodies are stateless and no `Socket*` state is touched.
- PacketTransform ownership: rejected because transform globals/key/nonce behavior begins after the PacketBuffer reader area.
- CashShopRequest ownership: rejected as stale generated send-corridor pollution.
- Treating `0x00575970` as active/lively: not proven; direct xref/code_ref/data_ref/immediate/VA/RVA evidence is negative.
- Treating `0x00575970` or raw string variants as padding/dead junk: rejected because they are coherent source-style string writer overloads aligned with live siblings.
- New `NetworkAddress.cpp` owner now: rejected as under-evidenced; keep a caveat on the host-address child.

## Follow-Up Actions

Supervisor actions:

- Apply [UID:0001HZ] non-emitting split/index metadata and update target evidence.
- Create child pages or assign an A/C agent to create them with the exact ranges above.
- Apply support-doc updates and the coverage block with real UIDs.
- Refresh memory ranges/rescore.

A-agent actions:

- After split, document each child page with the helper names/signatures above and preserve no-xref caveats for retained overloads.
- Keep formal C++ blank in the initial split pass unless a coordinated `PacketBuffer.h` naming/type policy is accepted.

B001 future work:

- No further B001 research is required unless the supervisor rejects the non-emitting split/index policy or wants a deeper one-helper-per-page C++ migration plan.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for [UID:0001HZ] as `88/90` non-emitting after split-index repair; medium-high for child scores because raw no-xref overloads cap string/address children.
- Remaining uncertainty: original exact helper names, whether retained raw/no-xref overloads were source-used through an unrecovered dispatch path, whether host-address helpers later deserve a narrow network utility source, and final C++ typedef choices.

No same-task blocker remains for supervisor execution or rejection review.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001HZ-packetbuffer-helpers-source-quality.md`.
- Modified: none outside B001 research.
- Leases used: none.
- IDA DB edits: none.
- Validator commands run: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001HZ-packetbuffer-helpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001HZ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001HZ-packetbuffer-helpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001HZ-packetbuffer-helpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001HZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
