*** UID:00000P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
class _AUTOBUF : public LObject
{
public:
    _AUTOBUF();
    virtual ~_AUTOBUF();

    T *Resize(unsigned int count);

private:
    T *m_data;
    unsigned int m_count;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AUTOBUF_unsigned_char

## Status

- Confidence: very strong for concrete behavior, decorated type spelling, class layout, virtual/source lifecycle, and complete emitted declaration; medium-high for exact original header filename/casing and inferred access labels.
- Source-level name: `_AUTOBUF<unsigned char>` for the concrete decorated type; `AUTOBUF` remains the file/source-bucket shorthand.
- Likely source artifact: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- Current validator-generated file: `auto-generated/NexusTK/util/AUTOBUF.cpp`
- Historical legacy generated path: `source-3/simroot_v2/class_AUTOBUF_unsigned_char.cpp`; it is not current validator authority.

## Responsibility

`_AUTOBUF<unsigned char>` is a small owning byte-buffer wrapper used by several unrelated client features. The concrete instantiation owns raw byte payloads for compressed map loading/saving, startup-logo media, login-screen image loading, image decode helpers, profile sidecar refresh, and user/profile look packet parsing. `AUTOBUF<unsigned char>` without the leading underscore is retained only as prose shorthand for the shared file bucket. This concrete class should be treated as shared utility or template support, not as a feature-specific class owned by any one caller.

## Binary Shape

| Offset | Meaning |
| --- | --- |
| `+0x00` | `_AUTOBUF<unsigned char>` vtable / `LObject`-compatible object header |
| `+0x04` | `m_data`, owned byte buffer pointer |
| `+0x08` | `m_count`, byte count for this specialization |

Exact vtable data is now documented at [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e6ab0-0x004e6ad7` | `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *` | [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) now carries formal first-draft C++ for the concrete resize helper. It releases old `m_data`, allocates `byteCount` bytes, stores `m_count` at `+0x08`, stores `m_data` at `+0x04`, and returns the new pointer. |
| `0x004e5c10-0x004e5c2c` | virtual ordinary destructor | [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md) releases `m_data` and delegates base teardown; eight EH cleanup routes prove the shared body is live source. The separate `0x004e62a0` scalar deleting wrapper is compiler-only. |
| `0x004f5640-0x004f566a` | constructor | [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) now carries formal first-draft C++ for `template <> _AUTOBUF<unsigned char>::_AUTOBUF() : LObject(), m_data(0), m_count(0)`. |

## Ownership Notes

`0x004f5640` is physically near `LogoPlayerPane`, but it is type support. A 2026-05-26 IDA caller check reports the standalone constructor's direct code caller as `MapPane::LoadMapFromFile` at `0x00504d49`, where a local AUTOBUF receives a compressed `.cmp` map payload before decompression. `LogoPlayerPane` still embeds the same layout and initializes it inline for segmented Bink data, so physical neighborhood alone should not drive ownership.

IDA callers for `0x004e6ab0` come from `UserLookPane` profile/look packet parsing. A 2026-06-03 IDA vtable-reference pass also finds 21 writes/references to `??_7?$_AUTOBUF@E@@6B@` across image decode wrappers, logo playback, main-menu `LEVEL.BMP` loading, map load/save helpers, profile sidecar refresh, and `UserLookPane` construction/destruction. That broader vtable fan-out confirms the concrete instantiation is shared utility/template support rather than belonging to one feature file.

## Instantiation Evidence

| Evidence site | Interpretation |
| --- | --- |
| `0x004e6ab0-0x004e6ad7` | Concrete resize helper for `_AUTOBUF<unsigned char>`; frees current storage, allocates the requested byte count, updates pointer/count fields, and is called from `UserLookPane` profile/look parsing at `0x0059ffc1` and `0x0059fffe`. |
| `0x004f5640-0x004f566a` | Concrete constructor helper; initializes the `LObject` shell, installs vtable `0x0061b868`, clears fields, and is directly called by `MapPane::LoadMapFromFile` at `0x00504d49` for a local compressed-map payload buffer. |
| `0x004e5c10-0x004e5c2c` | Exact concrete ordinary destructor; releases `m_data`, tails to `LObject` teardown, and is shared by eight exception-cleanup routes. |
| `0x0061b864-0x0061b874` | Exact RTTI/vtable slice for `??_R4?$_AUTOBUF@E@@6B@` / `??_7?$_AUTOBUF@E@@6B@`; the next bytes are string data, so the vtable boundary is tight. |
| 21 vtable references to `0x0061b868` | Cross-feature usage spans image decode wrappers, logo playback, main-menu media, map load/save, profile refresh, and user-look paths, which supports utility/template ownership instead of a pane-specific source file. |
| [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) | Detailed image-loader use site for inline stack construction: vtable writes at `0x004d0651` and cleanup at `0x004d06fa`, buffer pointer/count at `+0x04/+0x08`, allocation size `zpfPayloadSize`, and cleanup after zlib `Uncompress`. |

The class page therefore tracks the concrete emitted instantiation, while [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) remains the source-owner bucket for likely header/template support.

## 2026-06-14 A001 IDA Refresh

Live IDA MCP session `a001_goal2_class_batch` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reports healthy auto-analysis and Hex-Rays state. `lookup_funcs` reconfirms the only modeled concrete helpers as `sub_4E6AB0` at `0x004e6ab0`, size `0x27`, and `sub_4F5640` at `0x004f5640`, size `0x2a`.

`analyze_function 0x004e6ab0` decompiles as a one-block resize helper: it frees field `+0x04`, allocates the requested byte count, stores the count at `+0x08`, stores the new pointer at `+0x04`, and returns the allocated pointer. Backward data-flow to `0x004e6ab0` shows exactly two direct call sites, `0x0059ffc1` and `0x0059fffe`, both inside `sub_59F610`, matching the documented `UserLookPane` profile/look payload use.

`analyze_function 0x004f5640` decompiles as the constructor helper: it calls `sub_4F4A80`, writes `_AUTOBUF<unsigned char>` vtable `0x0061b868`, and clears fields `+0x04` and `+0x08`. Backward data-flow to `0x004f5640` shows the direct caller `0x00504d49` inside `sub_504B90`, matching the documented `MapPane::LoadMapFromFile` local compressed-map buffer use.

Backward data-flow from vtable slot `0x0061b868` again returns 21 vtable-write/reference sites, including the constructor write at `0x004f564f`, map-path writes at `0x00504da4`, `0x00504f7f`, and `0x00505031`, logo/media neighborhood writes around `0x004f5419` through `0x004f5995`, profile/user-look writes at `0x0059f2c9`, `0x0059f5cf`, and `0x005a24c6`, and image/profile helper writes at `0x004d0651`, `0x004d06fa`, `0x004e5c16`, `0x004e62a9`, and `0x00527a37`. This current fan-out keeps the ownership conclusion strong while still leaving exact original template spelling and header split open.

B006's 2026-06-21 ZPF wrapper reanalysis resolves the `0x004d0651` and `0x004d06fa` vtable references as [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) local `_AUTOBUF<unsigned char>` construction and cleanup. The wrapper allocates a temporary FPF buffer with `zpfPayloadSize`, passes it to zlib `Uncompress`, and then frees it. This use site confirms the class layout fields but does not change the unresolved original template spelling/header questions.

## 2026-06-14 C001 Parent-Gate Refresh

Live IDA MCP session `a001_goal2_class_batch` rechecked the constructor child [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) after the A001 class refresh. `server_health` reports the active IDB as `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` still reports `sub_4F5640` at `0x004f5640`, size `0x2a`, and the next function at `0x004f566a`, so the constructor range is tight.

`analyze_function 0x004f5640` reconfirms the one-block constructor body: call `sub_4F4A80`, write `_AUTOBUF<unsigned char>` vtable `0x0061b868`, clear fields `+0x04/+0x08`, and return `this`. It reports exactly one direct code caller, `sub_504B90` at `0x00504d49`, matching the MapPane compressed-map payload use already documented here. This refresh is enough to clear the strict `85/85` direct-parent gate for the constructor child while preserving the open template spelling/header-contract caveat.

## 2026-06-26 B004 Constructor Source-Quality Refresh

B004 read-only MCP session `80de0a67` rechecked [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) and closed the target-scoped C++ blocker. The active IDB was healthy (`auto_analysis_ready:true`, `hexrays_ready:true`), and no IDA write tools were used.

The constructor child is now documented as a single `0x2a`-byte function at `0x004f5640-0x004f566a`: it calls `0x004f4a80`, writes vtable `??_7?$_AUTOBUF@E@@6B@` at `0x0061b868`, clears `+0x04/+0x08`, returns `this`, and has exactly one direct code caller, `0x00504d49` in `MapPane::LoadMapFromFile`. B004 also confirmed the `LObject` base-constructor role of `0x004f4a80`, so source should use `: LObject()` rather than a raw helper call.

The exact concrete source-facing type is `_AUTOBUF<unsigned char>`, proven by decorated symbols `??_7?$_AUTOBUF@E@@6B@` and `??_R4?$_AUTOBUF@E@@6B@`. `AUTOBUF<unsigned char>`, `AutoBuf<unsigned char>`, `AutoBuffer<unsigned char>`, and `class_AUTOBUF_unsigned_char` are rejected as either prose shorthand, unsupported casing expansions, or generator artifacts. The wide `_AUTOBUF<wchar_t>` RTTI/vtable family remains useful template-family evidence but does not change this concrete type name.

Field naming is now `m_data` and `m_count`:

- `m_data` (`+0x04`) is cleared by the constructor, freed by resize and the deleting-destructor path, and used by consumers as the owned payload pointer.
- `m_count` (`+0x08`) is cleared by the constructor and written by resize with the requested payload count; for this specialization it is a byte count.

Rejected field names: `m_buffer` is descriptive but less consistent with existing LogoPlayerPane/ImageLoaders support usage; `m_byteCount` is too narrow for the shared template family because wide AUTOBUF uses the same slot as a character count; `m_capacity` is not safe because the observed layout has no separate current-size/capacity pair.

## 2026-06-27 B007 Resize Source-Quality Refresh

B007 accepted implementation report `tools/leaser/Agents/Agent-B007/research/000188-AUTOBUFUnsignedCharResize-source-quality.md` rechecked the resize child [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) against live IDA MCP session/database `80de0a67` and closed the child-scoped C++ blocker.

The resize child is documented as an exact `0x27`-byte function at `0x004e6ab0-0x004e6ad7`; `0x004e6ad7-0x004e6ae0` is nine `0xcc` alignment bytes before successor `sub_4E6AE0`. Its only callees are `0x005c7799 j_j_j___free_base` and `0x005c7790 unknown_libname_19`, with the latter decompiling as a Microsoft runtime `operator new(size_t)` thunk. The method does not call the project `MemoryMan` wrappers or `MemoryMan::AllocateBufferMemory` / `MemoryMan::FreeBufferMemory`.

The current formal source shape is `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`: release old `m_data`, allocate `new unsigned char[byteCount]`, assign `m_count`, assign `m_data`, and return the new pointer. The binary stores `m_count`/`+0x08` before `m_data`/`+0x04` and preserves the allocator result as the return value. The aggregate class page still keeps its own formal C++ block blank, but that aggregate caveat no longer suppresses the child resize body.

Caller and field proof: xrefs remain exactly `0x0059ffc1` and `0x0059fffe` in `sub_59F610` / `UserLookPane` profile/look parsing. The first branch sets `ecx = esi + 0x0b8c`, passes a zero-extended word count from `esi + 0x0b88`, and immediately copies payload bytes into `dword ptr [esi+0x0b90]`. The alternate branch after the `"JPF"` check uses the same count/destination pattern. The deleting-destructor path at `0x004e62a0` also frees `+0x04` through the same free-base thunk, independently confirming `m_data` and leaving no evidence for a separate capacity field.

Rejected alternatives are preserved here: no `UserLookPane` ownership, no range split/merge, no `MemoryMan` source path, no raw runtime-thunk source names, no `m_capacity`, and no blank formal C++ for the exact resize child.

## 2026-07-20 B004 Complete Source Closure

The Gate-1-accepted UID0002MR pass closes the class-level source blockers that older constructor/resize reports deliberately left open:

- RTTI proves `template <class T> class _AUTOBUF : public LObject` as the strongest human declaration shape for the exact decorated `_AUTOBUF<unsigned char>` type. Public inheritance is inferred from conventional utility use; RTTI directly proves only the one nonvirtual offset-zero base.
- The concrete object is 12 bytes: `LObject`/vptr shell at `+0x00`, owned `T *m_data` at `+0x04`, and element count `unsigned int m_count` at `+0x08`. Private field access is the strongest minimal RAII source shape; protected/public fields are weaker and not required by any source-facing consumer.
- A virtual ordinary destructor declaration is required by the first vtable slot. [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md) provides the exact source body. Compiler output supplies vptr restoration, `LObject` teardown lowering, and scalar deleting wrapper flags.
- Inherited `LObject::GetRuntimeClass` and [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) / `LObject::OnChangeMessage` occupy the remaining slots and are not redundantly redeclared.
- All 21 vtable references remain exact: nine construction writes and twelve cleanup writes spanning image decode, logo/media, menu, map, transport/profile, and UserLookPane paths. The fan-out preserves shared utility/template ownership and rejects every feature-specific owner.
- The vtable body has exactly 21 references. Nine construction/initialization writes are `0x004d0651`, `0x004f5419`, `0x004f564f`, `0x004f57a6`, `0x004f6884`, `0x00504f7f`, `0x0050673b`, `0x00527a37`, and `0x0059f2c9`. Twelve cleanup/destruction writes are `0x004d06fa`, `0x004e5c16`, `0x004e62a9`, `0x004f5544`, `0x004f56b7`, `0x004f5995`, `0x004f68c5`, `0x00504da4`, `0x00505031`, `0x005068a5`, `0x0059f5cf`, and `0x005a24c6`.
- No explicit template-instantiation directive is emitted. The concrete constructor/destructor/resize specializations and natural object uses already force the needed compiler artifacts; an explicit class instantiation could force unsupported members.
- This class page is the sole declaration emitter at position 0. The class closes before `[[CHILDREN]]`; child positions 10, 20, and 30 produce constructor, ordinary destructor, and resize definitions. UID0002MR RTTI/vtable and UID0001WN type authority are false/non-emitting, eliminating duplicate/empty markers.

Rejected alternatives remain explicit: no non-underscored source type, generated filename class name, capacity field, raw runtime/MemoryMan source, feature owner, handwritten RTTI/vtable/scalar deleting wrapper, comment-only compiler marker, or duplicate template/type emitter.

## Reconstruction Notes

- Reconstructable: true as the concrete emitted `_AUTOBUF<unsigned char>` support type.
- Parent: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), now assigned to `NexusTK/util/`.
- C++: the complete accepted class declaration now emits here. Historical blank-class wording is superseded because UID0004TA closes the destructor source gap and the declaration can represent the full concrete lifecycle. Exact original header casing remains bounded uncertainty but no longer blocks structurally valid source.

## Evidence

- IDA MCP `py_eval` on 2026-06-03 confirms exact function bounds `0x004e6ab0-0x004e6ad7` for resize and `0x004f5640-0x004f566a` for the constructor.
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) documents the resize helper freeing the old buffer, allocating the requested byte count, updating fields `+0x04`/`+0x08`, returning the new pointer, and moving the trailing `0x004e6ad7-0x004e6ae0` padding into [UID:0000VN][-ignored](by-memory/-ignored.md). It now carries formal first-draft C++ for `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)`.
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) documents the constructor calling `LObject` setup, installing the vtable, and clearing fields `+0x04`/`+0x08`.
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) documents the exact RTTI locator and three-slot concrete vtable data. IDA MCP callers/disassembly on 2026-05-31 also confirms the constructor caller at `0x00504d49` and resize callers at `0x0059ffc1`/`0x0059fffe`.
- The companion [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) page records the same field layout and caller evidence from map, logo-media, and profile/look code paths.

## Open Questions

- Closed for the concrete decorated type: `_AUTOBUF<unsigned char>` is the source-facing spelling for this instantiation.
- Closed for the concrete resize child: `Resize(unsigned int byteCount)` returns `unsigned char *`, releases old `m_data`, allocates a new byte buffer, updates `m_count` then `m_data`, and is safe to emit through the child page.
- Bounded uncertainty for broader AUTOBUF support: exact original header filename/casing and textual inline/out-of-line placement are not binary-recoverable. The complete generic declaration plus concrete explicit-specialization definitions is the safest nonduplicating project representation.
- Resolved: do not add an explicit class-instantiation directive; existing concrete definitions and object uses account for the emitted helpers/RTTI/vtable without forcing unsupported members.

## Cross-References

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0004TA][0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor](by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md)
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- 2026-05-31: Raised scoring from `60/75` to `68/82` and marked the class reconstructable after adding the exact vtable-data page. Evidence: IDA MCP verified the concrete vtable range, constructor helper, resize helper, and MapPane/UserLookPane caller evidence. Scores remain below final-audit levels because the exact original template spelling/header location and full template contract are not yet settled.
- 2026-06-02: Attached the concrete class to [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) after the file page was assigned to `NexusTK/util/`. C++ remains blank pending final template/header audit.
- 2026-06-03: Raised `COMPLETION` from `68` to `74` and `CONFIDENCE` from `82` to `86` after live IDA MCP corrected both helper exclusive ranges, confirmed the `0x004e6ad7-0x004e6ae0` alignment gap, and expanded vtable-write evidence to 21 cross-feature references. C++ remains blank because exact original template spelling and header/source split are still unresolved.
- 2026-06-06: Raised grading from `74/86` to `78/88`.
  - Before: the class page listed the helper methods and ownership rationale, but the cross-feature instantiation evidence was spread across the file/type/memory pages.
  - After: added an instantiation evidence table tying the resize helper, constructor helper, exact vtable slice, 21-reference vtable fan-out, and `AUTOBUF` file owner together.
  - Evidence: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) is now `84/88`, the vtable data page is `84/88`, and the helper pages record exact IDA-backed ranges and callers. Final C++ remains blank because original template spelling/header placement and the full template contract are still below the 95/95 gate.
- 2026-06-14 A001 Goal 2 class refresh: raised `78/88` to `84/89` after live IDA MCP session `a001_goal2_class_batch` reconfirmed the two concrete helper sizes, one-block constructor/resize behavior, exact direct caller sets, and the 21-site vtable fan-out. The score remained below final-code quality because the full source template declaration, allocator wrapper name, and exact header spelling/casing are still not proven.
- 2026-06-14 C001 parent-gate refresh: raised completion from `84` to `85` after rechecking the constructor child against the same live IDB. The direct child route now clears `85/89` on this class and `86/89` on [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md); final C++ remains blank because the source template declaration is still not source-quality.
- 2026-06-21 B006 ZPF inline use:
  - Score unchanged.
  - Summary/evidence: [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) now documents `0x004d0651`/`0x004d06fa` as local `_AUTOBUF<unsigned char>` vtable writes in the ZPF wrapper, plus `+0x04/+0x08` pointer/count use around zlib `Uncompress`. The source owner stays [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md).
- 2026-06-26 B004 implementation:
  - Raised `85/89` to `87/91`.
  - Closed the concrete type spelling to `_AUTOBUF<unsigned char>`, renamed the documented fields to `m_data` and `m_count`, and recorded rejected type/field alternatives.
  - Updated the constructor method row and reconstruction notes to reflect the formal first-draft C++ now present on [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md).
  - Evidence: B004 MCP session `80de0a67` reconfirmed the `0x004f5640-0x004f566a` one-block body, direct caller `0x00504d49`, decorated `_AUTOBUF<unsigned char>` RTTI/vtable symbols, `LObject` base-constructor lowering, and `m_data`/`m_count` field behavior.
- 2026-06-27 B007 implementation:
  - Raised `87/91` to `88/92`.
  - Updated the resize method row and support notes to reflect the formal first-draft C++ now present on [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md).
  - Separated the aggregate class-page no-code caveat from the child resize code decision: constructor and resize children now emit, while this aggregate still waits for a complete generic declaration/destructor/header pass.
  - Evidence: B007 MCP session `80de0a67` reconfirmed the exact `0x27`-byte resize boundary, nine-byte padding fence, two `UserLookPane` parser callsites, runtime operator-new/free-base lowering, `m_data`/`m_count` stores, returned pointer, destructor same-field release, and rejected `UserLookPane`, `MemoryMan`, raw-thunk, capacity-field, split/merge, and blank-C++ alternatives.
- 2026-07-20 B004 UID0002MR source-closure callback:
  - Raised `88/92` to `92/94`, retained owner/emitter UID0000HM, set emission position 0, and installed the complete accepted class block closed before `[[CHILDREN]]`.
  - Added UID0004TA ordinary destructor, exact virtual/inherited slot contract, 12-byte layout/access rationale, 21-reference 9/12 lifecycle split, source-emission order, compiler-only exclusions, explicit-instantiation rejection, and bounded header/access uncertainty without removing historical research.
