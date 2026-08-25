*** UID:0000HM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AUTOBUF

## Status

- Confidence: very strong for utility ownership, byte-buffer role, complete concrete unsigned-char lifecycle, helper boundaries, compiler/source disposition, and cross-feature call evidence; medium-high for exact original filename/casing and whether every definition was textually inline.
- Proposed source artifact: `util/AUTOBUF.h`, `util/AutoBuf.h`, or an adjacent buffer utility header.
- Primary concrete instantiation: [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)

## File Role

`AUTOBUF<T>` is a small owning buffer wrapper. The concrete `_AUTOBUF<unsigned char>` instantiation appears in map `.cmp` loading, startup-logo video loading, login-screen image loading, image decode wrappers, and self-look/profile packet parsing, where it owns raw byte payloads read from files or packets. B006's ZPF wrapper pass adds a detailed image-loader inline stack use: [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) allocates a temporary FPF buffer with `zpfPayloadSize`, uses it as zlib `Uncompress` output, and cleans it up through the `_AUTOBUF<unsigned char>` vtable/destructor path. B005 reanalysis also identifies an Application-owned `_AUTOBUF<wchar_t>` instantiation used as the deferred application error-text buffer at `0x0067a998`.

The concrete support rows currently documented here are the ordinary destructor at `0x004e5c10`, the resize helper at `0x004e6ab0`, the constructor helper at `0x004f5640`, the exact `_AUTOBUF<unsigned char>` vtable-data slice at `0x0061b864-0x0061b874`, and the Application-owned `_AUTOBUF<wchar_t>` static/vtable/deleting-destructor evidence at `0x0067a998`, `0x00612570-0x00612580`, and `0x004632c0-0x0046330b`. The unsigned-char constructor is physically near `LogoPlayerPane`, but IDA confirms it is `_AUTOBUF<unsigned char>` construction rather than a pane method. Its direct code caller is [UID:0000L3][MapPane](by-file/MapPane.md) at `0x00504d49`; `LogoPlayerPane` still uses an embedded AUTOBUF layout but initializes it inline in its constructor.

## Known Concrete Code

| Range | Role |
| --- | --- |
| `0x004e5c10-0x004e5c2c` | `_AUTOBUF<unsigned char>` ordinary virtual destructor; [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md) emits `delete [] m_data` and excludes compiler-generated vptr restoration, base teardown, scalar-deleting flags, and optional object deletion from handwritten source. Eight EH cleanup routes prove this shared body is live. |
| `0x004e6ab0-0x004e6ad7` | `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`; [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) now emits formal first-draft C++. It releases old `m_data`, allocates `new unsigned char[byteCount]`, stores `m_count` at `+0x08`, stores `m_data` at `+0x04`, and returns the new pointer. |
| `0x004f5640-0x004f566a` | `_AUTOBUF<unsigned char>` constructor; [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) now emits formal first-draft C++ for `template <> _AUTOBUF<unsigned char>::_AUTOBUF() : LObject(), m_data(0), m_count(0)`. Used by `MapPane::LoadMapFromFile` for a stack/local compressed-map payload buffer. |
| `0x004632c0-0x0046330b` | Generated `_AUTOBUF<wchar_t>` scalar deleting destructor for the Application error-text static; restores vtable body `0x00612574`, frees the payload pointer at `+0x04`, calls `LObject` teardown, and conditionally dispatches scalar delete based on MSVC deleting-destructor flags. Formal C++ stays blank on the exact function page. |
| `0x0067a998-0x0067a9a4` | Application-owned `_AUTOBUF<wchar_t>` static, best source shape `static _AUTOBUF<wchar_t> s_applicationErrorText;`, with payload pointer at `+0x04` and wide-character count including terminator at `+0x08`. |

## Source-Structure Decision

Use this as shared utility/header support. Do not migrate the constructor as `LogoPlayerPane` behavior, and do not treat `class_AUTOBUF_unsigned_char.cpp` as a feature-specific source file.

For the concrete unsigned-char instantiation, use `_AUTOBUF<unsigned char>` as the decorated source-facing type name. `AUTOBUF` remains this file bucket's shorthand for the shared utility/template source family. The accepted field names are `m_data` for `+0x04` and `m_count` for `+0x08`; `m_buffer`, `m_byteCount`, and `m_capacity` were rejected because they are respectively less consistent with current support usage, too narrow for the wide-character specialization, or unsupported by a separate size/capacity layout.

The concrete unsigned-char source route is now complete and nonduplicating. [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md) emits the closed class declaration at position 0; constructor UID00019E, ordinary destructor UID0004TA, and resize UID000188 emit at positions 10, 20, and 30. UID0002MR remains exact RTTI/vtable evidence and UID0001WN remains the complete template/type authority, but both are false/non-emitting so neither produces duplicate source or an Empty Emitter Marker.

The concrete resize child is source-ready even though this file bucket still has header/template casing uncertainty. Its binary body lowers release to `j_j_j___free_base` and allocation to `unknown_libname_19` / MSVC `operator new(size_t)`, but source uses high-level byte-array ownership (`delete [] m_data` then `new unsigned char[byteCount]`) instead of raw runtime thunk calls. The ordinary destructor uses the same source-facing `delete [] m_data`; its compiler-inserted vptr/base teardown belongs to generated ABI machinery. No `MemoryMan` helper participates in either method: the resize does not call project wrappers `0x004f4aa0`/`0x004f4ac0` or `MemoryMan::AllocateBufferMemory` / `MemoryMan::FreeBufferMemory`.

## Proposed Placement

- Projected reconstruction folder: `NexusTK/util/`.
- Likely source artifact: `util/AUTOBUF.h` or a nearby utility template header.
- Validator handling: this page uses the `by-file` root as the owner bucket even though the original artifact was probably header/template support rather than a standalone `.cpp` implementation.

The `util/` placement is supported by [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md), [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md), and the proposed source-tree utility-container section. The concrete instantiation is used by map loading, startup media, and profile/look parsing, so feature-specific ownership would be misleading.

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md) | Closes the missing ordinary virtual destructor source with an exact shared body, eight EH cleanup routes, and a strict exclusion of scalar-deleting-wrapper and generated base/vptr mechanics. |
| [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) | Confirms the concrete resize helper frees old storage, allocates the requested byte count, updates pointer/count fields, and ends before nine bytes of alignment padding. |
| [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) | Confirms constructor helper behavior and MapPane caller evidence, excluding LogoPlayerPane-only ownership. |
| [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) | Confirms RTTI/vtable data for `_AUTOBUF<unsigned char>`, recreated through declarations rather than copied as source data. |
| [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) | Consolidates field layout, caller spread, and template/header uncertainty. |
| [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md) | B005 resolves this exact generated destructor as `_AUTOBUF<wchar_t>` support for the Application error-text static rather than a bespoke ApplicationErrorState source class. |
| [UID:0003OY][0x00612574-0x00612580.ApplicationErrorStateVtableData](by-memory/0x00612574-0x00612580.ApplicationErrorStateVtableData.md) | Records the `_AUTOBUF<wchar_t>` vtable body and adjacent COL evidence `0x00612570 -> 0x00641ee4` named `??_R4?$_AUTOBUF@_W@@6B@`. |
| [UID:000292][0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics](by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md) | Documents the concrete wide AUTOBUF static storage and separates it from the adjacent Application critical-section storage. |

## Live IDA Evidence

- IDA MCP confirms `sub_4E6AB0` at `0x004e6ab0-0x004e6ad7`, size `0x27`. Decompilation frees `*(this+4)`, allocates the requested byte count through `0x005c7790`, stores the count at `+0x08`, stores the new pointer at `+0x04`, and returns it. The trailing `0x004e6ad7-0x004e6ae0` bytes are nine `0xcc` alignment bytes.
- IDA MCP confirms `sub_4F5640` at `0x004f5640-0x004f566a`, size `0x2a`. Decompilation calls `sub_4F4A80`, installs `_AUTOBUF<unsigned char>` vtable `0x0061b868`, clears fields `+0x04` and `+0x08`, and returns `this`.
- Direct code xrefs place `sub_4E6AB0` only at `sub_59F610` call sites `0x0059ffc1` and `0x0059fffe`, matching `UserLookPane` profile/look payload buffer resizing.
- The direct code xref to `sub_4F5640` is `0x00504d49` inside `sub_504B90` / `MapPane::LoadMapFromFile`, where a stack/local `_AUTOBUF<unsigned char>` object receives a `.cmp` file payload before decompression.
- Vtable data at `0x0061b864-0x0061b874` contains RTTI locator `0x00649194`, first slot `0x004e62a0`, inherited `0x004f4b10`, and `nullsub_18` at `0x0041b6c0`; `0x0061b874` begins adjacent string data and is not part of the vtable.
- The first slot is the compiler scalar deleting wrapper at `0x004e62a0`; the human source destructor is the exact shared body `0x004e5c10-0x004e5c2c`. Its bytes release the owned pointer at `+0x04` and tail into `LObject` teardown, and eight EH cleanup routes establish ordinary-source liveness. The wrapper's hidden flags, optional scalar deletion, vptr write, and guard behavior are compiler-only and are not emitted as source.
- The ordinary destructor body at `0x004e5c10` has eight exact EH cleanup references: `0x005ff92c`, `0x00600f41`, `0x00600f9b`, `0x0060118f`, `0x00602272`, `0x006022a5`, `0x00602356`, and `0x0060a261`. These independent cleanup routes prove shared ordinary-source liveness; they do not make the body padding or authorize handwritten scalar-deleting-wrapper mechanics.
- IDA MCP reports 21 xrefs to `0x0061b868`: `0x004d0651`, `0x004d06fa`, `0x004e5c16`, `0x004e62a9`, `0x004f5419`, `0x004f5544`, `0x004f564f`, `0x004f56b7`, `0x004f57a6`, `0x004f5995`, `0x004f6884`, `0x004f68c5`, `0x00504da4`, `0x00504f7f`, `0x00505031`, `0x0050673b`, `0x005068a5`, `0x00527a37`, `0x0059f2c9`, `0x0059f5cf`, and `0x005a24c6`. This fan-out spans image decode, logo playback, main-menu media, map load/save, profile refresh, and user-look paths.
- B006 resolves the image-decode xrefs `0x004d0651` and `0x004d06fa` to the local `_AUTOBUF<unsigned char>` temporary in [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md). That wrapper calls the `LObject` shell, writes the vtable, stores buffer pointer/count at `+0x04/+0x08`, uses the buffer as the zlib-inflated inner FPF payload, restores the vtable during cleanup, and frees the payload. This is consumer evidence for the utility/template bucket, not a reason to move AUTOBUF under ImageLoaders.
- B005 local IDA export reanalysis on 2026-06-18 identifies the Application-owned wide AUTOBUF instantiation: the complete-object locator pointer at `0x00612570` targets `0x00641ee4` named `??_R4?$_AUTOBUF@_W@@6B@`; the vtable body at `0x00612574-0x00612580` has slots `0x004632c0`, `0x004f4b10`, and `0x0041b6c0`; the static storage at `0x0067a998` stores the vptr, payload pointer, and wide-character count; and the count stores use `wcslen(source) + 1`, so `+0x08` is a character count including the terminator rather than a byte count.

## 2026-06-27 B007 Resize Source-Quality Refresh

B007 accepted implementation report `tools/leaser/Agents/Agent-B007/research/000188-AUTOBUFUnsignedCharResize-source-quality.md` rechecked [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) with live IDA MCP session/database `80de0a67`. The active IDB was `NexusTK.exe.i64` with auto-analysis, Hex-Rays, and strings ready.

The resize child remains exactly `0x004e6ab0-0x004e6ad7`, size `0x27`; `0x004e6ad7` is not a function and `0x004e6ad7-0x004e6ae0` is nine bytes of `0xcc` alignment before `sub_4E6AE0`. Decompilation/disassembly show `this` in `ecx`, old storage release from `+0x04`, stack argument `byteCount`, allocation through `0x005c7790`, `m_count` store at `+0x08`, `m_data` store at `+0x04`, and return of the allocator result.

Allocator/free route: the only callees are `0x005c7799 j_j_j___free_base` and `0x005c7790 unknown_libname_19`. The allocation thunk decompiles as MSVC `operator new(size_t)` lowering through `0x005c74f6`; the release leg is the CRT free-base thunk chain. This confirms the source should not name `MemoryMan` and should not preserve `unknown_libname_19` / `j_j_j___free_base` as source-facing helper calls.

Caller/source-placement route: exactly two code xrefs remain, `0x0059ffc1` and `0x0059fffe` in `sub_59F610` / `UserLookPane` profile/look parsing. Those callsites pass an embedded `_AUTOBUF<unsigned char>` object at `esi + 0x0b8c`, use count `esi + 0x0b88`, and then copy/decode through destination pointer `esi + 0x0b90`. They prove consumer use only; they do not move ownership to `UserLookPane`. The deleting-destructor path at `0x004e62a0` releases the same `+0x04` field through the same free-base thunk, corroborating `m_data` ownership.

Rejected alternatives now recorded for this source bucket: no `UserLookPane` ownership, no range split/merge, no separate `m_capacity` field, no raw runtime-thunk source, no `MemoryMan` source, and no blank formal C++ for the exact resize child.

## 2026-06-26 B004 Constructor Source-Quality Refresh

B004 read-only MCP session `80de0a67` rechecked [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md). The active IDB was healthy and no IDA write tools were used. The constructor range remains exactly `0x004f5640-0x004f566a`, `0x2a` bytes / 42 bytes, with successor `0x004f566a` outside the constructor.

The recheck confirms the source-output shape routed through this AUTOBUF file bucket:

- one basic block;
- call to `0x004f4a80`, now documented as `LObject` base-constructor lowering;
- generated vtable write to `??_7?$_AUTOBUF@E@@6B@` at `0x0061b868`;
- zero stores to `m_data` (`+0x04`) and `m_count` (`+0x08`);
- return of `this`;
- exactly one direct caller, `0x00504d49` inside `MapPane::LoadMapFromFile`;
- decorated RTTI/vtable names `??_R4?$_AUTOBUF@E@@6B@` and `??_7?$_AUTOBUF@E@@6B@`, proving `_AUTOBUF<unsigned char>` as the concrete type.

Rejected source-placement alternatives remain: `LogoPlayerPane` is only physical adjacency, `MapPane` is only a consumer/caller, `StartupLogoPanes`, ImageLoaders, profile/menu, and UserLookPane are consumers proven by vtable references, and no-owner/non-emitting is wrong because this helper is normal reconstructable utility/template support.

## Generated Output Expectation

After the final scoped validator runs with `--wait-generated`, `auto-generated/NexusTK/util/AUTOBUF.cpp` must contain exactly one complete class declaration followed by exactly one constructor, ordinary destructor, and resize definition. It must contain zero Empty Emitter Markers for UID00000P, UID0002MR, UID0001WN, or UID0004TA and no handwritten RTTI/vtable arrays, scalar deleting wrapper, explicit vptr, hidden deleting flags, guard, raw `operator delete`, `nullsub`, or duplicate `LObject` source. Do not edit generated output manually; validator-owned generated coverage/tracker state refreshes from the source by-* docs.

## Batch 012 Parent-Gate Evidence

The exact vtable-data child [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) is directly owned by this utility/template source bucket. Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) and confirmed the preceding `aSDEpf` string terminator, `_AUTOBUF<unsigned char>` RTTI locator at `0x0061b864`, vtable slot dwords at `0x0061b868-0x0061b870`, the 21-reference cross-feature vtable fan-out, and following `aZpf` boundary at `0x0061b874`.

Historically, that evidence was enough to treat this by-file page as an `85/85` direct parent for the vtable-data child under the corrected Batch 012 assignment gate. Current source closure raises this page to `91/94`: the vtable bytes remain `source-declared/generated-binary`, while the complete UID00000P declaration and constructor/ordinary-destructor/resize children supply the human source that causes the compiler/linker to emit the equivalent concrete `_AUTOBUF<unsigned char>` artifact. The vtable child contributes no handwritten C++.

## Cross-References

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)
- [UID:0003OY][0x00612574-0x00612580.ApplicationErrorStateVtableData](by-memory/0x00612574-0x00612580.ApplicationErrorStateVtableData.md)
- [UID:000292][0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics](by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- 2026-07-20 B004 UID0002MR implementation callback:
  - Raised `88/91` to `91/94` after closing the complete concrete unsigned-char source lifecycle while preserving `NexusTK/util/`, the wide specialization, all consumers, and every historical evidence section.
  - Registered and linked ordinary destructor [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md), including exact body/eight-route liveness and strict compiler deleting-wrapper exclusion.
  - Synchronized the single-emitter route: UID00000P emits the complete declaration, UID00019E/UID0004TA/UID000188 emit constructor/destructor/resize at positions 10/20/30, and UID0002MR/UID0001WN remain false/non-emitting compiler/type authorities.
  - Preserved the exact 16-byte RTTI/vtable range, all three slot identities, 21-reference fan-out, byte-array source ownership, runtime-thunk lowering, no-MemoryMan evidence, source-placement reasoning, rejected alternatives, and bounded original-header casing uncertainty.

- 2026-06-21 B006 unsigned-char image decode use:
  - Score unchanged at `86/89`.
  - Summary/evidence: added [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) as a detailed `_AUTOBUF<unsigned char>` inline stack use site, including vtable references `0x004d0651`/`0x004d06fa`, `zpfPayloadSize` allocation, `+0x04/+0x08` field use, zlib `Uncompress` output, and cleanup. Ownership remains the shared utility/template source bucket.

- 2026-06-26 B004 implementation:
  - Raised `86/89` to `87/90`.
  - Updated [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) from blank-C++ pending state to formal first-draft constructor emission through this utility source root.
  - Added the concrete `_AUTOBUF<unsigned char>` spelling, `m_data`/`m_count` field names, rejected field/source-placement alternatives, and generated-refresh expectation for `auto-generated/NexusTK/util/AUTOBUF.cpp`.
  - Evidence: B004 MCP session `80de0a67` reconfirmed the one-block `0x004f5640-0x004f566a` constructor, direct caller `0x00504d49`, decorated RTTI/vtable names, and `LObject` base-constructor lowering.

- 2026-06-27 B007 implementation:
  - Raised `87/90` to `88/91`.
  - Updated [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) from blank-C++ pending state to formal first-draft resize emission through this utility source root.
  - Added source-shape evidence for exact range, two `UserLookPane` parser callsites, runtime operator-new/free-base lowering, destructor same-field release, high-level byte-array allocation/release source syntax, no `MemoryMan` route, no range split/merge, no capacity field, and generated-refresh expectation that `AUTOBUF.cpp` contains both constructor and resize child blocks.
  - Evidence: B007 MCP session `80de0a67` reconfirmed the exact `0x27`-byte resize body, nine-byte `0xcc` fence, `j_j_j___free_base` and `unknown_libname_19` / `operator new(size_t)` callees, `m_count`/`m_data` store order, returned pointer, and parser callsite field context.

- 2026-06-18 B005 wide AUTOBUF incorporation:
  - Score unchanged at `86/89`.
  - Added the Application-owned `_AUTOBUF<wchar_t>` instantiation, including static storage `0x0067a998`, RTTI COL `??_R4?$_AUTOBUF@_W@@6B@` via `0x00612570 -> 0x00641ee4`, vtable body `0x00612574-0x00612580`, and generated deleting destructor [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md).
  - Summary/evidence: B005 resolved the previous ApplicationErrorState wording as a source-quality mismatch. Current source route remains through [UID:0000HG][Application](by-file/Application.md) because the wide specialization is proven only as Application error-text state; this AUTOBUF page records the reusable template/type implication and keeps exact header casing/API below final-source quality.

- What existed before: the page documented shared buffer ownership and constructor/resize evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `64/78`.
- Summary and evidence: byte-buffer role and two concrete code ranges are well supported, but exact original filename/header placement remains medium confidence.
- 2026-06-02:
  - Before: projected reconstruction path was blank, leaving the file root without a source placement.
  - After: scored as `72/86` and assigned `NexusTK/util/`.
  - Summary/evidence: proposed source-tree utility-container rationale, concrete constructor/resize/vtable child pages, and cross-feature caller evidence support utility ownership. C++ remains absent because the likely original artifact is template/header support and exact spelling/casing is not final-audit quality.
- 2026-06-03:
  - Before: the concrete helper rows used stale exclusive-end labels for both AUTOBUF child pages.
  - After: corrected `Resize` to `0x004e6ab0-0x004e6ad7` and constructor to `0x004f5640-0x004f566a` from live IDA function bounds.
  - Summary/evidence: IDA MCP reports `Resize` size `0x27`, constructor size `0x2a`, a nine-byte alignment gap after `Resize`, and 21 vtable references proving this is shared template support.
- 2026-06-04 live IDA refresh:
  - Before: the page was scored `72/86` and still had stale source-output wording despite strong child evidence.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, with C++ still blank.
  - Summary/evidence: live IDA reconfirms exact helper ranges, resize and constructor bodies, the direct MapPane and UserLookPane call sites, exact vtable data through `0x0061b874`, and the 21-reference vtable fan-out across unrelated feature paths. The score remains below final because the exact original spelling/casing and header/template split are not proven to source-quality confidence.
- 2026-06-07 A003 Batch 012 parent gate:
  - What existed before: the page was `84/88`, below the corrected direct-parent assignment gate for [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md).
  - Changed to: `86/89`, added current hash-backed vtable ownership evidence, and documented why this utility/template source bucket directly owns the source declaration effect.
  - Summary/evidence: the source bucket already documents helper ranges, constructor/resize behavior, MapPane/UserLookPane callers, and cross-feature fan-out; the Batch 012 IDA recheck closes the specific vtable-data ownership gate while exact original filename/casing and header/template split remain below final-audit confidence.
