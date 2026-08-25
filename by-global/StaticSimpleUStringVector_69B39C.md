*** UID:0003MS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Reconstructed descriptive name; original variable spelling is not recovered.
static std::vector<SimpleUString> StaticSimpleUStringVector_69B39C;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticSimpleUStringVector_69B39C

## Status

- Address range: `0x0069b39c-0x0069b3a8`
- Entity kind: source-declared static vector-like global storage.
- Direct autogen parent: [UID:0000OB][StringUtil](by-file/StringUtil.md).
- Exact storage child: [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md).
- Confidence: very strong for the storage layout, zero-filled initial state, cleanup registration, exact memory boundary, IDA labels, and `SimpleUString` element behavior; strong enough for `StringUtil` source-family ownership; low for the original variable spelling and source purpose.

This page represents the narrow source-level static object behind [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md). The source spelling is not recovered, so the name remains descriptive. The evidence supports a static `std::vector`-like container whose elements are inline 24-byte `SimpleUString` objects, not the existing pointer-backed [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) class.

## Layout

| Storage | Role |
| --- | --- |
| `0x0069b39c-0x0069b3a0` | begin pointer |
| `0x0069b3a0-0x0069b3a4` | end pointer |
| `0x0069b3a4-0x0069b3a8` | capacity / end-of-storage pointer |

Live IDA MCP evidence in the B001 ownership report confirms all three dwords are initially zero. PE section mapping places RVA `0x0029b39c` in the loader-zero-filled `.data` virtual tail, beyond raw-backed file bytes, so the all-zero state is supplied by the loader. Earlier stale `0xffffffff` byte-state notes are superseded.

## Evidence

- The only direct data references to the three control words are in cleanup body `0x0060c160`: begin refs at `0x0060c161`, `0x0060c1d3`, and `0x0060c21c`; end refs at `0x0060c170` and `0x0060c226`; capacity refs at `0x0060c1d9` and `0x0060c230`.
- Raw executable scans found the same VA immediates only at those cleanup-body sites, and found no RVA-style references for `0x0029b39c`, `0x0029b3a0`, or `0x0029b3a4`.
- The cleanup loop walks from begin to end in `0x18` / 24-byte elements, reads each element capacity at offset `+0x14`, frees heap payloads when capacity is at least `8`, resets length/capacity to the empty SSO state, frees the backing vector allocation, and clears all three control words.
- The static initializer wrapper at `0x00419f40` only registers the cleanup body with `atexit`; it does not construct a semantic owner and is compiler/static-lifetime glue.
- 2026-06-16 C001 live IDA MCP recheck in session `b001_selflookpane_0001H7_20260616` reconfirmed bytes `00 00 00 00 00 00 00 00 00 00 00 00`, the `3/2/2` cleanup-only xref split, startup-table-only reachability for `0x00419f40`, and the cleanup body at `0x0060c160`. C001 then saved low-risk descriptive IDA labels `StaticSimpleUStringVector_69B39C`, `RegisterStaticSimpleUStringVectorCleanup_69B39C`, and `StaticSimpleUStringVectorCleanup_69B39C`.
- The nearby startup table places this cleanup registration immediately after [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), then before MemoryMan, TimerMgr, the NCA URL string, image table storage, riding table storage, MetaMan alias string, and MIDI state. The table is heterogeneous, so adjacency alone is not ownership proof, but adjacency plus the 24-byte SSO cleanup pattern supports the StringUtil/SimpleUString source family.
- Boundary checks keep this object exact: the preceding `0x0069b381-0x0069b39c` initialized span has no direct refs to its endpoint candidates, `0x0069b3a8` starts separate MemoryMan storage, and `0x0069b3d0` starts a later NCA URL static string.

## Ownership Decision

This global is parented to [UID:0000OB][StringUtil](by-file/StringUtil.md) because `StringUtil` already owns the shared `SimpleUString` infrastructure and [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md). The element destructor behavior exactly matches the [UID:0000D9][SimpleUString](by-class/SimpleUString.md) SSO layout: 24-byte objects, length at `+0x10`, capacity at `+0x14`, inline capacity `7`, and heap threshold `8`.

The direct memory child should attach here, not directly to `StringUtil`, because the memory page documents exact storage while this page documents the source-declared global object. `StringUtil` remains the source-root parent for the global declaration.

Do not attach this storage to [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md), [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md), MemoryMan, TimerMgr, MiscWorkThread/NCA URL storage, MetaMan, image/riding table storage, MIDI state, `g_emptySimpleUString`, or the existing [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md). Those pages are either compiler/runtime glue, neighboring static objects, siblings, or different container models.

## Reconstruction Notes

The C++ snippet is intentionally descriptive. It captures the source-level shape that best fits the binary evidence, but the original variable name and normal insertion/use path are still unrecovered.

Do not hand-port the cleanup thunk as ordinary project logic. The cleanup body is compiler/static-lifetime support for this global.

## Cross-References

- [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md)
- [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md)

## Changes

- 2026-06-16 C001 global-storage/IDA refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed the zero-filled three-pointer storage, cleanup-only xref graph, static initializer reachability, and inline 24-byte `SimpleUString` cleanup behavior. Saved descriptive IDA labels for the source-level global and its static cleanup/registration wrappers. Owner/emitter remain [UID:0000OB][StringUtil](by-file/StringUtil.md); the C++ declaration stays descriptive because the original variable spelling and normal-use purpose remain unrecovered.
- 2026-06-13 B001/supervisor execution:
  - Created this narrow by-global as the semantic parent for [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md).
  - Parent set to [UID:0000OB][StringUtil](by-file/StringUtil.md) after B001 live IDA/PE evidence proved a zero-filled static vector control block for inline 24-byte `SimpleUString` elements and rejected cleanup thunks, initializer wrappers, neighboring static globals, and the pointer-backed `SimpleUStringVector` class as direct owners.
