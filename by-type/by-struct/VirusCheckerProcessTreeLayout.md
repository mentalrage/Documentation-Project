*** UID:0001WG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VirusChecker Process Tree Layout

## Status

- Entity kind: object and helper tree layout for [UID:0000FW][VirusChecker](by-class/VirusChecker.md).
- Direct parent: [UID:0000FW][VirusChecker](by-class/VirusChecker.md), with source placement through [UID:0000P5][VirusChecker](by-file/VirusChecker.md).
- Confidence: very strong for the direct base, complete-object size, observed offsets, EBO overlap, container behavior, and owner; exact historical typedef spelling remains unavailable.
- Likely owner header: `security/VirusChecker.h`.
- Evidence basis: IDA MCP decompilation of `0x005c0460`, `0x005c04e0`, `0x005c0940-0x005c0fe1`, and vtable/data xref checks on 2026-05-26 and 2026-05-31; dated MCP session `86fb854e` rechecked the same constructor/destructor/helper facts during the 2026-06-29 B004 cleanup.

## VirusChecker Object

The complete object is exactly `0x0c` bytes. Current RTTI and scalar-delete evidence reconcile the direct empty base with the embedded set wrapper:

| Offset | Size | Field hypothesis | Evidence |
| --- | --- | --- | --- |
| `0x00` | 4 | vptr | Constructor, destructor, and scalar deleting destructor write object vptr `0x006310e0`; the source declares a virtual destructor rather than an explicit vptr. |
| `0x04` | 4 | empty `Singleton<VirusChecker>` base plus `m_modulePaths` header/sentinel pointer | RTTI base PMD is `+0x04`. Empty-base optimization permits the first concrete set word at the same offset; constructor stores the result of `0x005796d0`, and destructor reads/resets/frees the header. This is not a stored Singleton member. |
| `0x08` | 4 | `m_modulePaths` node count | Constructor clears it; insertion helper increments the count through the embedded tree object; destructor clears it after resetting the tree. Avoid the stale generated `m_state` name. |

The selected human-source reconstruction is `ModulePathSet m_modulePaths`, where `ModulePathString` is `mystr::StringBase<char, mystr::mychar_traits<char> >`, `ModulePathLess` is a stateless functor implementing `strcmp(left.c_str(), right.c_str()) < 0`, and `ModulePathSet` is `std::set<ModulePathString, ModulePathLess>`. Exact original private typedef spelling is stripped, but the source type, ordering behavior, and field role are closed; `m_state` is rejected because `+0x08` is the module-path set count.

## Direct Singleton Base And EBO

- The dated MCP session `7be8cc9f` decodes the VirusChecker hierarchy as self plus direct `Singleton<VirusChecker>` only. The base descriptor at `0x00653f54` has PMD `{4,-1,0}` and attributes `0x40`, with no not-visible/private/protected/ambiguous/virtual-base flags.
- Constructor lowering forms the base at `this+0x04`, adjusts by `-0x04` before publishing the complete object, then initializes set storage at `+0x04/+0x08`. This is an empty-base-optimization overlap, not contradictory double ownership of the same word.
- The scalar deleting wrapper frees `0x0c` bytes, independently confirming the complete size and rejecting any extra explicit Singleton pointer/member.
- Source belongs on [UID:0000FW][VirusChecker](by-class/VirusChecker.md) as `public Singleton<VirusChecker>` plus `ModulePathSet m_modulePaths`. This support page remains layout evidence and must not emit raw struct members that duplicate the class declaration.

## Embedded Tree Header

The object fields at `VirusChecker + 0x04/+0x08` behave as an MSVC tree container header/count pair:

| Relative offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `container + 0x00` | header/sentinel node pointer | Constructor stores `sub_5796D0()` here; helpers receive `this + 1` / `a4 + 4`, so the tree wrapper starts at object offset `+0x04`. |
| `container + 0x04` | node count | Constructor clears `VirusChecker + 0x08`; insertion increments `this[1]`; destructor/scalar deleting destructor clear it after resetting the header. |
| `header + 0x00` | leftmost/min node link | Destructor resets this link back to the header sentinel after cleanup. |
| `header + 0x04` | root node link | Destructors pass `*(header + 0x04)` to recursive cleanup; insertion updates this when the first/root node is inserted. |
| `header + 0x08` | rightmost/max node link | Destructor resets this link back to the header sentinel after cleanup. |

## Tree Node

Observed node layout through the string payload:

| Offset | Size | Field hypothesis | Evidence |
| --- | --- | --- | --- |
| `0x00` | 4 | left child | Insertion, traversal, and recursive cleanup follow this as the left branch. |
| `0x04` | 4 | parent | Destructor and insertion use this as the parent/header link. |
| `0x08` | 4 | right child | Traversal and recursive cleanup follow this as the right branch. |
| `0x0c` | 1 | red/black color byte | Insert/rebalance helpers read and write this byte during rotations; root color is forced black after insertion. |
| `0x0d` | 1 | nil/header flag byte | Traversal and cleanup loops stop when this byte is nonzero. |
| `0x0e` | 2 | padding / unused word | Allocation clears `*((WORD *)node + 6)` across `+0x0c/+0x0d`; no separate source-facing use is proven. |
| `0x10` | 4+ | path string payload | Allocation helper copies the path into `node + 0x10`; lookup compares string data through `0x00584540`; cleanup destroys the string at this offset. |

The helper family is consistent with an MSVC-style ordered set/tree storing scanned module path strings. It should remain source-local to `VirusChecker`, not promoted to a general container source file unless wider reuse is proven.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` rechecked the involved function boundaries: constructor `0x005c0460` size `0x80`, destructor `0x005c04e0` size `0xbd`, node insert/allocation helpers from `0x005c0940` through `0x005c0fa0`, and next non-owner function `0x005c0ff0` as `WaitableTimer`.
- 2026-05-31 IDA MCP decompilation of `0x005c0460` stores the singleton at `dword_69BF94`, writes the `VirusChecker` vtable, zeroes `this[1]` and `this[2]`, and stores `sub_5796D0()` into `this[1]`, matching object offsets `+0x04` header pointer and `+0x08` count.
- 2026-05-31 IDA MCP decompilation of `0x005c04e0` reads the header pointer from `this+0x04`, destroys the child tree from `header+0x04`, resets header links at `+0x00/+0x04/+0x08`, clears `this+0x08`, frees the header, and clears `dword_69BF94`.
- 2026-05-31 IDA MCP decompilation of `0x005c0ac0`, `0x005c0b40`, `0x005c0ca0`, and `0x005c0fa0` confirms node links at `+0x00/+0x04/+0x08`, color byte `+0x0c`, header/nil byte `+0x0d`, and copied string payload at `+0x10`.
- 2026-05-31 IDA MCP xrefs confirm the callback chain: `0x005c07b0` references process callback `0x005c0aa0`, and `0x005c0aa0` references module callback `0x005c09f0`.
- 2026-06-11 IDA MCP `lookup_funcs` reconfirmed exact modeled extents for the constructor/destructor and tree helpers from `0x005c0940` through `0x005c0fe1`, with `0x005c0ff0` beginning `WaitableTimer`.
- 2026-06-11 IDA MCP decompilation reconfirmed the wrapper offset: direct path insertion calls `0x005c0ca0(this + 1, ...)`, and the V3 module callback calls `0x005c0ca0(a4 + 4, ...)`, so the tree wrapper is embedded at object offset `+0x04`.
- 2026-06-11 IDA MCP decompilation of `0x005c0b40` reconfirmed node allocation through `0x005c0ac0`, count increment through `this[1]`, left/right insertion, red-black recoloring at `+0x0c`, nil/header tests at `+0x0d`, and rotations through `0x0043ed70` / `0x0043f000`.
- 2026-06-11 IDA MCP decompilation of `0x005c0ca0` reconfirmed lookup-or-insert behavior over string payloads: it walks left/right child links, compares candidate path strings through `0x00584540` and `strcmp`, inserts only when absent, and returns an iterator plus inserted flag.
- 2026-06-11 IDA MCP caller/xref refresh confirms local ownership: `0x005c0ca0` is only called by `0x005c0940` and `0x005c09f0`; `0x005c0fa0` is only called by the non-deleting destructor, scalar deleting destructor, and itself; callback address xrefs are `0x005c07da -> 0x005c0aa0` and `0x005c0aa6 -> 0x005c09f0`.
- 2026-07-23 B005 dated MCP session `7be8cc9f` supersedes prior sessions for hierarchy/layout proof. It decoded COL `0x00653f08`, CHD `0x00653f1c`, Singleton BCD `0x00653f54`, PMD/flags, constructor base adjustment, three vptr stores, and scalar-wrapper 12-byte deallocation.

## Remaining Caveats

- Exact historical spelling of private aliases is unavailable. The implementation-ready source decision uses `ModulePathString`, `ModulePathLess`, and `ModulePathSet` as described above; these are stable human source-facing inferences, not a reason to retain IDA or generic `m_state` labels.
- Keep raw node layout as implementation evidence unless wider source reuse is proven. The compiler's Dinkumware tree lowering should regenerate node links/color/header fields from the standard container rather than handwritten raw-node source.
- Live activation remains unresolved: IDA currently has no direct caller for the constructor/load-helper path, so this layout is documented as reconstructable source-owned code but not yet proven startup-critical.
- No separate formal CPP/H is emitted from this support layout page. The class H channel owns the aliases, comparator, and `ModulePathSet m_modulePaths`; this page records exact analysis layout without duplicating raw node declarations.

## 2026-08-02 Source Model Versus Analysis Layout

- Source model: `VirusChecker` directly inherits `Singleton<VirusChecker>`, privately aliases the ANSI StringBase specialization as `ModulePathString`, compares values with stateless `ModulePathLess`, aliases `std::set<ModulePathString, ModulePathLess>` as `ModulePathSet`, and stores `ModulePathSet m_modulePaths`.
- Analysis model: the complete object is exactly 0x0c bytes; vptr is `+0x00`; empty Singleton PMD and the first concrete set word overlap at `+0x04`; set count is `+0x08`. The set wrapper therefore occupies exactly 8 bytes inside the complete object.
- Compiler-node model: each Dinkumware node is exactly 0x14 bytes, with links at `+0x00/+0x04/+0x08`, color/header bytes at `+0x0c/+0x0d`, two bytes of unused/padding state through `+0x0e/+0x0f`, and StringBase payload pointer at `+0x10`.
- The analysis UDTs are useful for IDA typing but are not source structs. Standard-container construction, unique search/insert, rotations, allocation, EH cleanup, and recursive destruction must be regenerated by the compiler from the class declaration and authored calls.
- The lexical comparator is behavior-backed by the `strcmp` paths in `0x005c0ca0`; lower-case normalization occurs before insertion through the shared header-visible inline ANSI `StringBase<char>::ToLower() const` specialization in `StringBase.h` or an included `.inl`. VirusChecker's inlined form is a consumer and does not move definition placement into `VirusChecker.cpp` or `StringBase.cpp`. This closes the former generic `String`/unspecified-comparator caveat while keeping exact historical private identifier spelling below symbol certainty.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Future IDA-dependent decisions require a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.

## Assignment Gate

Assigned to direct class parent [UID:0000FW][VirusChecker](by-class/VirusChecker.md). The layout clears at `89/94`; the direct class parent clears at `91/93`, and source-file parent [UID:0000P5][VirusChecker](by-file/VirusChecker.md) clears at `90/91`. Exact historical typedef spelling remains unavailable, but the direct base, EBO, size, offsets, and source-facing container decision are implementation-ready.

## Cross-References

- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)

## Changes

- 2026-08-06 B003 UID0001NW placement callback: propagated the shared header-visible StringBase ToLower specialization into the source-vs-analysis layout model and historicalized named MCP sessions without changing any object/node layout decision.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecked constructor/destructor/tree helper boundaries, decompiled object and node field access, verified callback xrefs, and confirmed the next function boundary at `0x005c0ff0`. Scores remain below 95 because final source type names and live activation are still unresolved.
- 2026-06-11 A004 Batch 151 strict-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, and blank `AUTOGEN_PARENT_UID`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, and `AUTOGEN_PARENT_UID:0000FW`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/tree-helper extents, embedded wrapper offset at `VirusChecker + 0x04`, header root/left/right reset behavior, node color/nil/string payload fields, insertion count increment, lookup/insert comparisons, callback xrefs, and local destructor cleanup ownership. The direct class parent [UID:0000FW][VirusChecker](by-class/VirusChecker.md) and file parent [UID:0000P5][VirusChecker](by-file/VirusChecker.md) both clear the strict gate; this support layout page remains blank because the formal class field is emitted on the class page.
- 2026-06-20 B004 Rule 26 support sync, updated 2026-06-29 by B004 dated MCP cleanup: replaced stale `m_state` direction with `m_modulePaths` node-count/header wording and recorded `std::set<String>` / project string-wrapper as the best source-type inference from that dated evidence while keeping exact typedef spelling open. The old local/offline proof source is historical only.
- 2026-07-23 B005 UID0002OT accepted support implementation:
  - Raised completion/confidence from `85/90` to `89/94`; preserved class owner/emitter, reconstructable state, and blank support C++ block.
  - Added direct Singleton RTTI/PMD evidence, exact 12-byte object size, empty-base overlap at `+0x04`, count at `+0x08`, selected `ModulePathSet m_modulePaths` source shape, and the prohibition against raw node/base/vptr members.
  - Historicalized the incomplete view of `+0x04` as only a set pointer while preserving every valid container and node-layout observation.
