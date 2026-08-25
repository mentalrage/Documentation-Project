*** UID:0001WN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AUTOBUF<unsigned char>

## Status

- Confidence: very strong for the concrete `_AUTOBUF<unsigned char>` instantiation, layout, lifecycle, RTTI/vtable contract, and non-emitting type-authority role; medium-high for original header casing/access labels.
- Current entity kind: non-emitting template/type documentation authority; source declaration emits uniquely through [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md).
- Known source helper addresses: destructor `0x004e5c10-0x004e5c2c`, resize `0x004e6ab0-0x004e6ad7`, constructor `0x004f5640-0x004f566a`.
- Exact vtable data: [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- Likely source artifact: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- Exact helper memory doc: [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- Current physical neighborhood: [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- Related class: [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)

## Declaration Hypothesis

`_AUTOBUF<unsigned char>` is an `LObject`-derived or `LObject`-compatible auto-buffer wrapper used to own byte buffers loaded by file and packet helpers. The leading underscore is not just a generated shorthand: it is proven for the concrete instantiation by decorated symbols `??_7?$_AUTOBUF@E@@6B@` and `??_R4?$_AUTOBUF@E@@6B@`. `AUTOBUF<unsigned char>` remains acceptable prose shorthand for the shared file bucket, but not the exact concrete decorated type. Known uses include a stack/local compressed map payload in `MapPane::LoadMapFromFile`, an embedded segmented Bink payload buffer in `LogoPlayerPane`, main-menu/image-loader scratch buffers, and profile/look payload storage in `UserLookPane`.

Likely fields from the local constructor:

| Offset | Meaning |
| --- | --- |
| `+0x00` | vtable pointer for `_AUTOBUF<unsigned char>`; concrete vtable at `0x0061b868` with RTTI locator at `0x0061b864` |
| `+0x04` | `m_data`, owned payload pointer initialized to null |
| `+0x08` | `m_count`, payload count initialized to zero; byte count for this specialization |

## Instantiation Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) | Concrete resize helper for this instantiation; now emits formal first-draft C++ for `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`. It releases old `m_data`, allocates `byteCount` bytes, updates `m_count` then `m_data`, and returns the new pointer. |
| [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) | Concrete constructor helper; calls the `LObject` runtime shell constructor, installs vtable `0x0061b868`, and clears the payload fields. |
| [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md) | Concrete ordinary virtual destructor; releases `m_data`, delegates `LObject` teardown, and is shared by eight exception-cleanup routes. |
| [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) | Exact RTTI/vtable slice for `??_R4?$_AUTOBUF@E@@6B@` and `??_7?$_AUTOBUF@E@@6B@`; the following bytes at `0x0061b874` start string data, so the vtable boundary is tight. |
| [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md) | Concrete class documentation now records the MapPane/UserLookPane call sites, 21-reference vtable fan-out, and utility/template ownership decision. |
| [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) | ImageLoaders ZPF wrapper constructs a stack `_AUTOBUF<unsigned char>` temporary inline, writes the vtable at `0x004d0651` and cleanup vtable at `0x004d06fa`, allocates `zpfPayloadSize` bytes through the runtime allocator, stores pointer/count at `+0x04/+0x08`, and frees during cleanup. |

## Evidence Notes

- IDA decompilation of `0x004f5640` calls `LObject` construction, writes the `_AUTOBUF<unsigned char>` vtable, clears fields `+0x04` and `+0x08`, and returns `this`.
- IDA disassembly of `0x004e6ab0` frees the existing pointer at `+0x04`, allocates the requested byte count, stores the byte count at `+0x08`, and stores the new pointer at `+0x04`.
- 2026-06-03 IDA MCP `py_eval` corrects the helper bounds to `0x004e6ab0-0x004e6ad7` for resize and `0x004f5640-0x004f566a` for the constructor. The resize helper is followed by nine `0xcc` alignment bytes before `sub_4E6AE0`.
- 2026-06-03 IDA MCP reports 21 references/matches for `??_7?$_AUTOBUF@E@@6B@` across image decode, logo, main-menu, map load/save, profile refresh, and user-look paths, so this remains shared template support rather than feature-owned code.
- IDA MCP callers on 2026-05-31 show `0x004e6ab0` called twice from `sub_59F610` at `0x0059ffc1` and `0x0059fffe`; the surrounding disassembly uses `UserLookPane`-sized offsets `+0xb88/+0xb90`, copies packet/profile bytes into the resized buffer, and then decodes or draws the look/profile payload.
- 2026-05-26 IDA caller checks for `0x004f5640` show the direct code caller at `0x00504d49` inside `MapPane::LoadMapFromFile`, immediately before `StdioFile::ReadAll`-style compressed block loading and map-data decompression.
- IDA MCP callers on 2026-05-31 reconfirm `0x004f5640` is called from `sub_504B90` at `0x00504d49`; disassembly shows it constructing a stack/local `_AUTOBUF<unsigned char>` object at `var_63C`, passing it to `sub_582410`, and later restoring the vtable/freeing its buffer during cleanup.
- IDA MCP `py_eval` on 2026-05-31 identifies the exact `_AUTOBUF<unsigned char>` vtable range at `0x0061b864-0x0061b874`: RTTI locator `??_R4?$_AUTOBUF@E@@6B@`, vtable `??_7?$_AUTOBUF@E@@6B@`, slots `0x004e62a0`, `0x004f4b10`, and `0x0041b6c0`, followed by `aZpf` string data at `0x0061b874`.
- The constructor helper is physically adjacent to `LogoPlayerPane` methods, but the visible `LogoPlayerPane` constructor initializes its embedded AUTOBUF at offset `+0x100` inline in current generated source and passes it to `StdioFile::ReadAll`.
- 2026-06-14 A001 live IDA MCP session `a001_goal2_class_batch` reconfirms `sub_4E6AB0` as size `0x27` and `sub_4F5640` as size `0x2a`; both helpers are one-block functions with no internal calls between them. The resize helper frees field `+0x04`, allocates the requested byte count, writes the count at `+0x08`, and writes the new buffer pointer at `+0x04`. The constructor helper calls `sub_4F4A80`, writes vtable `0x0061b868`, and clears fields `+0x04/+0x08`.
- The same A001 data-flow pass reconfirms direct call sites: resize at `0x0059ffc1` and `0x0059fffe` inside `sub_59F610`, constructor at `0x00504d49` inside `sub_504B90`, and 21 backward references to `_AUTOBUF<unsigned char>` vtable `0x0061b868` spanning image decode/media/map/profile/look paths. This improves declaration confidence for the concrete instantiation, but not enough to finalize the full template contract.
- 2026-06-16 C001 live IDA refresh in session `b001_selflookpane_0001H7_20260616` reconfirmed current helper names and exact behavior after safe IDA labeling. `AUTOBUFUnsignedCharResize` at `0x004e6ab0` remains a `0x27`-byte helper with two code xrefs from `0x0059ffc1` and `0x0059fffe` inside `sub_59F610`; decompilation frees `this+0x04`, allocates the requested byte count, writes `this+0x08 = byteCount`, and stores the new pointer at `this+0x04`. `AUTOBUFUnsignedCharConstructor` at `0x004f5640` remains a `0x2a`-byte helper with one code xref from `0x00504d49` inside `sub_504B90`; decompilation calls the LObject shell constructor, writes vtable `0x0061b868`, and clears `this[1]`/`this[2]`. `xrefs_to 0x0061b868` still returns 21 cross-feature vtable refs spanning media/image/map/profile/look consumers. Skipped IDA edits: type/member layout declarations and prototypes remain unsafe because the original template basename, exact header/casing, and full allocator/destructor contract are still not binary-proven.
- 2026-06-21 B006 source-quality pass adds [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) as a detailed inline-construction use site. The ZPF wrapper does not call the out-of-line constructor or resize helper; instead it calls the `LObject` shell, writes `_AUTOBUF<unsigned char>` vtable `0x0061b868`, clears fields, allocates `zpfPayloadSize` bytes, stores pointer/count/capacity at `+0x04/+0x08`, restores the vtable during cleanup, and releases the buffer. This confirms field use but does not settle the final source accessor names.
- 2026-06-26 B004 source-quality refresh in MCP session `80de0a67` closes the target-scoped constructor blocker. `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, and `get_bytes` reconfirm [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) as a one-block `0x2a`-byte concrete constructor: call `0x004f4a80`, write `_AUTOBUF<unsigned char>` vtable `0x0061b868`, zero `+0x04/+0x08`, return `this`, and one direct caller `0x00504d49` in `MapPane::LoadMapFromFile`.
- B004 also decompiled the `0x004f4a80` LObject helper and confirmed it is base-constructor lowering, so source should use `: LObject()` rather than a raw helper call. The constructor child now emits formal first-draft C++ for `template <> _AUTOBUF<unsigned char>::_AUTOBUF() : LObject(), m_data(0), m_count(0)`.
- 2026-06-27 B007 source-quality implementation in MCP session `80de0a67` closes the target-scoped resize blocker. `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, and `callees` reconfirm [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) as a one-block `0x27`-byte concrete resize method with a nine-byte `0xcc` fence at `0x004e6ad7-0x004e6ae0`.
- The resize child releases old storage at `m_data`/`+0x04` through `j_j_j___free_base`, allocates `byteCount` through `unknown_libname_19` / MSVC `operator new(size_t)` lowering, stores `m_count`/`+0x08`, stores `m_data`/`+0x04`, and returns the allocator result. Exactly two callers remain, `0x0059ffc1` and `0x0059fffe` in `UserLookPane` profile/look parsing; both use the embedded object at `esi + 0x0b8c`, count at `esi + 0x0b88`, and destination pointer at `esi + 0x0b90`.
- B007 also rechecked the deleting-destructor path at `0x004e62a0`, which writes `_AUTOBUF<unsigned char>` vtable `??_7?$_AUTOBUF@E@@6B@` and releases `Block[1]` / `+0x04` through the same free-base thunk. This independently confirms the `m_data` field and supports source-level array release for this concrete trivial-byte storage.

## 2026-06-26 Source-Shape Decisions

The current best concrete type name is `_AUTOBUF<unsigned char>`. Rejected alternatives:

- `AUTOBUF<unsigned char>`: useful shorthand for the file bucket, but not the exact decorated type name.
- `AutoBuf<unsigned char>` / `AutoBuffer<unsigned char>`: no decorated-symbol or local documentation support.
- `class_AUTOBUF_unsigned_char`: generated artifact only.

The current best field names are `m_data` and `m_count`. `m_data` is cleared by the constructor, freed by resize/destructor paths, and used by consumers as the owned byte payload pointer. `m_count` is cleared by the constructor, written by resize with the requested payload count, and used as byte count for this specialization. Rejected alternatives: `m_buffer` is less consistent with existing support docs; `m_byteCount` over-specializes a template field that also supports wide characters; `m_capacity` is not safe without a separate size/capacity pair in the 12-byte layout.

The concrete constructor child may emit first-draft C++ because its behavior, source-facing type spelling, base constructor, field names, range, caller, and emitter route are now documented. This template aggregate page still stays blank because it would need the complete generic `_AUTOBUF<T>` declaration, destructor declaration, resize API spelling, allocator wrapper name, and exact header/source split before emitting source-level template code itself.

## 2026-06-27 Resize Source-Shape Decision

The concrete resize child may emit first-draft C++ because its behavior, source-facing type spelling, field names, range, callers, destructor corroboration, and emitter route are now documented. The exact child signature is `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`.

Formal source behavior for the child: release old `m_data`, allocate `new unsigned char[byteCount]`, assign `m_count`, assign `m_data`, and return the new pointer. The source block intentionally uses high-level byte-array storage instead of raw runtime thunk names. The binary lowers allocation to `unknown_libname_19` / `operator new(size_t)` and release to `j_j_j___free_base`; for `unsigned char` there is no element constructor/destructor or array-cookie work visible, and existing project source-shape precedent reconstructs the same runtime allocator/free pattern as source-level array allocation/release.

Rejected alternatives: `UserLookPane` ownership is only a consumer path; `MemoryMan` is not called; `m_capacity` is unsupported by the 12-byte layout; raw `unknown_libname_19` / `j_j_j___free_base` calls would leak compiler/runtime artifacts into source; and the child no longer needs a blank formal C++ block. The aggregate template page still stays blank because the complete generic declaration, destructor declaration, and exact header/casing remain wider AUTOBUF questions.

## 2026-07-20 B004 Complete Template-Disposition Closure

- RTTI symbols prove the exact source-facing concrete type `_AUTOBUF<unsigned char>` and one nonvirtual `LObject` base at offset zero. The type remains 12 bytes with owned pointer `m_data` at +4 and element count `m_count` at +8.
- The exact vtable contains compiler scalar deleting wrapper `0x004e62a0`, inherited `LObject::GetRuntimeClass`, and inherited [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) / `LObject::OnChangeMessage`. Only the virtual ordinary destructor declaration/body belongs in AUTOBUF source.
- All 21 vtable references are classified: nine construction writes and twelve cleanup writes across image, media, menu, map, transport/profile, and UserLookPane consumers. This rejects feature ownership and confirms shared utility/template placement.
- The vtable body has exactly 21 references. Nine construction/initialization writes are `0x004d0651`, `0x004f5419`, `0x004f564f`, `0x004f57a6`, `0x004f6884`, `0x00504f7f`, `0x0050673b`, `0x00527a37`, and `0x0059f2c9`. Twelve cleanup/destruction writes are `0x004d06fa`, `0x004e5c16`, `0x004e62a9`, `0x004f5544`, `0x004f56b7`, `0x004f5995`, `0x004f68c5`, `0x00504da4`, `0x00505031`, `0x005068a5`, `0x0059f5cf`, and `0x005a24c6`.
- [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md) now carries the complete class declaration and injects constructor UID00019E at position 10, destructor UID0004TA at position 20, and resize UID000188 at position 30. This page therefore becomes false/non-emitting with blank emitter/position/formal, eliminating a duplicate Empty Emitter Marker.
- No explicit class-instantiation directive is required or emitted. Concrete definitions and natural uses force the required COMDAT RTTI/vtable/helper artifacts; explicit instantiation risks unsupported members.
- Historical aggregate-blank wording is preserved below as development history but superseded as current state. Exact original header filename/casing and access labels remain bounded inference, not a source-emission blocker.

Rejected alternatives: non-underscored/generated type spellings, feature-specific ownership, `m_capacity`, raw runtime/MemoryMan calls, handwritten RTTI/vtable/scalar deleting wrapper, marker-only type output, and duplicate class/type source emitters.

## Ownership Notes

Do not migrate `0x004f5640` as a `LogoPlayerPane` member. It should become template support, an inline emitted constructor, or a type-support helper under [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md). The direct constructor caller at `0x00504d49` is `MapPane::LoadMapFromFile`, while the resize helper callers are `UserLookPane` profile/look parsing paths; the 21-reference vtable fan-out spans unrelated feature modules.

## Reconstruction Notes

- Reconstructable: false as a source emitter; this page remains the complete concrete template-instantiation documentation record.
- Parent: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), now assigned to `NexusTK/util/`.
- Formal C++ remains blank because UID00000P is the unique complete declaration emitter. The blank block is an intentional no-code disposition, not an unresolved source blocker.
- C++ is intentionally blank for this non-emitting type/template authority because UID00000P already carries the complete recovered generic declaration and UID00019E, UID0004TA, and UID000188 carry the constructor, ordinary destructor, and resize definitions. No broader declaration/destructor pass is pending; only original header casing, inferred access labels, and textual inline placement remain bounded uncertainty.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | Complete non-emitting authority for the exact decorated type, 12-byte layout, fields, three-slot contract, all 21 references with nine-construction/twelve-cleanup classification, and constructor/ordinary-destructor/resize lifecycle, with source emitted uniquely by UID00000P and its children. |
| Confidence | 94 | Exact bytes, decorated symbols, RTTI, layout, helpers, callers, lifecycle, slots, reference addresses, and source-emission route are direct or strongly corroborated; confidence is capped only by original header casing, inferred access labels, and textual inline placement. |
| Parent | `0000HM` | [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) remains the correct utility/template source owner; LogoPlayerPane, MapPane, and UserLookPane are consumers, not direct owners of the instantiation support. |

## Cross-References

- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md)
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- 2026-05-31: Replaced unevaluated `0/0` scoring with IDA-backed `76/86` and marked the type reconstructable. Evidence: IDA MCP verified the constructor, resize helper, direct callers, and exact `_AUTOBUF<unsigned char>` vtable data; completion remains below high-final levels because exact original spelling/header placement and the full template contract are still open.
- 2026-06-02: Attached the template-instantiation documentation to [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) after the file page was assigned to `NexusTK/util/`. No C++ emitted because the final source declaration is not at the 95+ gate.
- 2026-06-06: Raised grading from `76/86` to `78/88`.
  - Before: the page recorded helper behavior, direct callers, and vtable data, but did not link the newer class/file ownership refresh into the template declaration rationale.
  - After: added an instantiation evidence table and clarified that constructor, resize, vtable, MapPane/UserLookPane callers, and 21-reference fan-out all support utility/template ownership under [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md).
  - Evidence: [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md) is now `78/88`; [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) is `84/88`; the exact helper and vtable pages provide IDA-backed boundaries. C++ remains blank because original template spelling/header placement and the full template contract are still unresolved.
- 2026-06-14 A001 Goal 2 support refresh: raised `78/88` to `82/89` after current IDA MCP reconfirmed helper sizes, one-block helper bodies, direct caller sets, and the 21-site vtable fan-out. C++ remains blank because the source template declaration and exact header/casing are still unresolved.
- 2026-06-16 C001 type/template refresh:
  - Before: the page was `82/89` and the current IDA labels still used generated `sub_` names for the two concrete helpers.
  - After: raised to `85/90`, recorded current caller/xref/decompilation evidence, saved `AUTOBUFUnsignedCharResize` and `AUTOBUFUnsignedCharConstructor` in IDA, and documented why type/member/prototype edits remain unsafe.
  - Evidence: live `lookup_funcs`, `xrefs_to`, and decompilation reconfirmed the two helper bodies, vtable ref fan-out, and MapPane/UserLookPane caller split; `rename` dry-run accepted both helper labels and `idb_save` succeeded.
- 2026-06-21 B006 ZPF inline AUTOBUF use:
  - Score unchanged.
  - Summary/evidence: [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) now documents the inline stack `_AUTOBUF<unsigned char>` temporary in the ZPF wrapper, including vtable writes at `0x004d0651`/`0x004d06fa`, `+0x04/+0x08` pointer/count use, `zpfPayloadSize` allocation, and cleanup. This is usage evidence for the concrete instantiation, not a new owner or final template declaration.
- 2026-06-26 B004 implementation:
  - Raised `85/90` to `87/91`.
  - Closed the concrete decorated type spelling to `_AUTOBUF<unsigned char>`, selected `m_data` and `m_count` as the source-facing field names, recorded rejected alternatives, and clarified why this aggregate template page remains blank while [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) now emits first-draft constructor C++.
  - Evidence: B004 MCP session `80de0a67` reconfirmed the `0x004f5640` one-block constructor, `0x00504d49` direct caller, `_AUTOBUF<unsigned char>` decorated RTTI/vtable symbols, `LObject` base-constructor lowering, and resize/destructor-backed `m_data`/`m_count` field behavior.
- 2026-06-27 B007 implementation:
  - Raised `87/91` to `88/92`.
  - Resolved the concrete resize child API/source decision as `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`, with old `m_data` release, `new unsigned char[byteCount]`, `m_count` then `m_data` updates, and returned new pointer.
  - Separated the aggregate template no-code caveat from the child method code decision: constructor and resize children now emit, while this aggregate remains blank pending the complete generic declaration/destructor/header pass.
  - Evidence: B007 MCP session `80de0a67` reconfirmed exact `0x004e6ab0-0x004e6ad7` bounds, nine-byte padding, callee set, two `UserLookPane` callsites, no `MemoryMan`, destructor same-field release, and rejected `UserLookPane`, raw-thunk, `m_capacity`, split/merge, and blank-C++ alternatives.
- 2026-07-20 B004 UID0002MR source-closure callback:
  - Raised `88/92` to `91/94`, retained owner UID0000HM, and changed reconstructable/emitter state to false/blank with blank formal C++.
  - Added UID0004TA, complete lifecycle/slot/RTTI/21-reference evidence, unique UID00000P declaration-emitter route, explicit-instantiation rejection, and bounded header/access uncertainty while preserving all historical consumer and helper research.
