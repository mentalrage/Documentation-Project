*** UID:0001VM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Layout evidence for ProtectedArray<T>.
// The source declaration is represented by template support [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) and exact child bodies.
// Do not emit a separate struct or layout declaration from this evidence page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProtectedArrayLayout

## 2026-08-18 Header Ownership Reconciliation

The accepted layout remains exact and score-neutral: vptr `+0x00`, count `+0x04`, entries `+0x08`, default capacity `+0x0c`, default entry `+0x10`, total `0x10 + sizeof(T)`. Source declaration ownership is now UID0000MU/UID0001WR formal H in `NexusTK/util/ProtectedArray.h`, not stale `ProtectedArray.cpp`; this layout page stays formal-blank to avoid duplication. The unresolved old-human name for one 0x0c record remains historical evidence only.

## Status

- Confidence: very strong for offsets `+0x00`, `+0x04`, `+0x08`, and `+0x10`, strong for `+0x0c` as constructor-initialized reserved/default-capacity state; final semantic name for `+0x0c` remains provisional.
- Related template: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- Autogen parent: attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); the file scores `87/89`, the template support page scores `86/90`, and this layout scores `86/90`, so the direct source parent and supporting template page clear the strict gate.

## Layout

Observed source-level shape:

```text
0x00  void* vtable
+0x04  int count
+0x08  T* entries
+0x0c  int reservedCount_or_defaultCapacity
+0x10  T defaultEntry
```

The accessor methods prove `count` at `+0x04`, `entries` at `+0x08`, and fallback/default entry at `+0x10`. The field at `+0x0c` is constructor-initialized to `0x0a` / 10 (Verified with int_convert.py) for the `GameServerConfig::NationEntry` specialization. The reviewed resize, accessor, and destructor bodies do not use it, so the safest source-quality spelling is provisional `m_reservedCount` or `m_defaultCapacity`; do not call it ordinary current capacity until a body that updates or tests it is found.

## Record Size Evidence

| Element type | Evidence | Size implication |
| --- | --- | --- |
| `HairInfo` | `0x004e5f20` shifts the index left by `4` before adding `entries`. | `sizeof(HairInfo) == 0x10`. |
| `Acc2Info` | `0x004e5f40` computes `(index + index * 4) * 4`. | `sizeof(Acc2Info) == 0x14`. |
| unresolved old-human image-info record | `0x004e5f70` computes `(index + index * 2) * 4`. | `sizeof(record) == 0x0c`; final source-facing type name remains open. |
| `ShoeInfo` | Scalar deleting destructor at `0x004e6240` calls delete with object size `0x20`. | Container size is `0x10 + sizeof(ShoeInfo)`, so `sizeof(ShoeInfo) == 0x10`. |
| `GameServerConfig::NationEntry` | [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) records are 68 bytes. | Nation-entry protected-array object includes the same header plus a 68-byte fallback record. |

## Notes

The image-library constructors and destructors may embed several `ProtectedArray<T>` instances directly inside larger owner objects. Do not infer a standalone allocation for every generated `class_ProtectedArray_struct_*.cpp` file; the source-level distinction is between the reusable template declaration and the owning library's concrete member fields.

2026-05-26 IDA MCP recheck still supports this split. The two accessor functions use `+0x04` as count, `+0x08` as entries, and `+0x10` as fallback/default entry. The `+0x0c` field remains provisional because the reviewed accessor/destructor/resize bodies do not name it or use it as live capacity.

2026-06-29 B012 implementation sync: current MCP session `3fa0535f` reconfirms [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) as the formal generic `ProtectedArray<T>::GetAtOrDefault(int index)` source body. The accessors still prove `m_count` at `+0x04`, `m_entries` at `+0x08`, and fallback/default storage at `+0x10`, with concrete `T` strides `0x10` / 16, `0x14` / 20, and `0x0c` / 12 bytes (Verified with int_convert.py). `search_structs` and `type_query` still find no local IDA type records for the exact original template or the unresolved 12-byte old-human image-info record, so `+0x0c` and final source names remain provisional.

## IDA Verification Notes

- `0x004e5f20` decompiles as a `ProtectedArray<HairInfo>` accessor: it rejects negative indexes or indexes greater than or equal to `this[1]`, returns `this + 0x10` for fallback, and otherwise returns `this[2] + 0x10 * index`.
- `0x004e5f40` is the same accessor pattern for `ProtectedArray<Acc2Info>`, but uses a `0x14` byte element stride.
- `0x004e5f70` is the same accessor pattern for another old-human image-info record and uses a `0x0c` byte element stride.
- `0x004e5a70-0x004e5b6f` disassembly is a sequence of compact ordinary destructor bodies. Representative bodies write the concrete `ProtectedArray<T>` vtable at offset `+0x00`, free the pointer at `+0x08`, and return.
- `0x004e5fa0`, `0x004e6240`, and `0x00514d50` decompile as scalar deleting destructors for concrete `ProtectedArray<T>` instantiations. Each reads `Block[2]`, writes the concrete vtable, frees the backing pointer, and conditionally calls `operator delete` when delete flag bit `1` is set.
- `0x005039f0-0x00503a41` is not currently modeled by IDA as a function, but disassembly shows `GameServerConfig` construction setting the embedded `ProtectedArray<GameServerConfig::NationEntry>` vtable, default record first field at `+0x10`, capacity/reserved field at `+0x0c` to `0x0a`, entries pointer at `+0x08` to null, and count at `+0x04` to zero.
- `0x00514ee0` decompiles as the `ProtectedArray<GameServerConfig::NationEntry>` resize helper: it compares the requested count against `+0x04`, allocates `68 * count` bytes, initializes each record's first 16-bit field to `-1`, copies the overlapping old entries from `+0x08`, frees the old storage, then updates `+0x08` and `+0x04`.

## 2026-06-16 A001 Evidence Refresh

- Live IDA MCP database `b001_mappane_0001AW_20260616` reconfirmed that the ordinary image-info destructor island at `0x004e5a70-0x004e5b6f` is still folded into broad image-library functions, while the next helper starts cleanly at `0x004e5b70`. This keeps the manually split exact destructor island valid.
- Accessor boundaries remain exact: `0x004e5f20` size `0x20` / 32 bytes, `0x004e5f40` size `0x25` / 37 bytes, `0x004e5f70` size `0x25` / 37 bytes, with padding at `0x004e5f65-0x004e5f70` and `0x004e5f95-0x004e5fa0`.
- Accessor decompilation proves the shared header fields: all three compare `index` against `this[1]` / object `+0x04`, return fallback storage `this + 4` dwords / object `+0x10` when out of range, and otherwise return `this[2]` / object `+0x08` plus strides `0x10` / 16, `0x14` / 20, and `0x0c` / 12 bytes. `int_convert.py` verified the documented decimal conversions.
- Scalar deleting destructor boundaries and vtable reachability remain exact: representative image-info destructors `0x004e5fa0` and `0x004e6270` are `0x2f` / 47-byte functions with one data ref each from their concrete vtable slots, and `ProtectedArray<GameServerConfig::NationEntry>` scalar deleting destructor `0x00514d50` is also a `0x2f` function referenced from `0x0061e704`.
- `0x00514ee0` remains the modeled NationEntry resize helper, size `0x8b` / 139 bytes, with the sole parser caller at `0x00503d4f`. Decompilation compares count at `+0x04`, reads/replaces entries at `+0x08`, allocates and copies `68 * count` bytes, initializes each new first word to `-1`, and updates count/entries.
- Section-mapped PE scanning matched IDA reachability: `0x004e5f20` has 105 rel32 calls, `0x004e5f40` has 27, `0x004e5f70` has three, scalar deleting destructors are reached through vtable data refs, and the raw GameServerConfig constructor/destructor/default-seeder starts `0x005039f0`, `0x00503a50`, and `0x00503b60` still have no VA/RVA/rel32 hits.
- `search_structs` for `ProtectedArray` and `NationEntry` returned no local IDA struct/type records. The binary proves the reusable header layout and key concrete strides, but not the original template declaration spelling, header basename, `+0x0c` member name, or the final source-facing name of the 12-byte old-human image-info record.

## 2026-06-29 B002 Empty-Emitter Implementation

This layout support page now carries a formal no-code layout-evidence comment. The source declaration route remains [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) plus exact child bodies, so this page must not emit a separate `struct` or layout declaration. The current layout evidence remains the same: vtable at `+0x00`, count at `+0x04`, entries at `+0x08`, provisional reserved/default-capacity-like state at `+0x0c`, and default/fallback element at `+0x10`.

The score rises to `87/91` because the empty-emitter state is resolved without losing the layout evidence. It stays below final-audit range because no current evidence resolves the original header basename, the final `+0x0c` member name, the 12-byte old-human record type name, or the complete template declaration.

## Cross-References

- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)

## Changes

- 2026-06-16 A001 layout evidence refresh: Raised completion/confidence from `84/89` to `86/90`.
  - Before: the status line cited stale parent scores and the layout page had not incorporated the current 2026-06-16 IDA/PE reachability check.
  - After: synced the direct ProtectedArray file/template support scores, added live IDA boundary/decompile/xref evidence for accessors, deleting destructors, and the NationEntry resize helper, added PE scan evidence including raw-start negative results, and kept the `+0x0c` / 12-byte-record source-name blockers explicit.
  - Evidence: live IDA `lookup_funcs`, `decompile`, `xrefs_to`, `get_bytes`, `search_structs`, current ProtectedArray support docs, local `int_convert.py`, and the read-only section-mapped PE scan.
- 2026-06-19 B008 [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) implementation sync:
  - Score unchanged at `86/90`.
  - Clarified that `+0x0c` is constructor-initialized to `0x0a` / 10 for `ProtectedArray<GameServerConfig::NationEntry>`, but reviewed resize/accessor/destructor bodies do not use it; keep provisional `m_reservedCount` / `m_defaultCapacity` rather than ordinary current capacity.
- 2026-06-29 B012 [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md) implementation sync:
  - Score unchanged at `86/90`.
  - Added current MCP session `3fa0535f` proof that the formal `ProtectedArray<T>::GetAtOrDefault(int index)` body uses only `+0x04` count, `+0x08` entries, and `+0x10` default entry, preserving the unresolved `+0x0c` caveat.
- 2026-06-29 B002 direct empty-emitter implementation:
  - Raised score from `86/90` to `87/91`.
  - Added the formal layout-evidence coverage comment.
  - Summary/evidence: this page remains layout evidence only; source declaration coverage belongs to [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) and exact child bodies, not a separate emitted layout struct.
- 2026-06-06: Attached the reusable template/header layout to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). Scores remain `82/88`; the type has no direct class page, so the file-level template owner is the correct parent.
- 2026-06-08 A003 Batch122: Raised completion/confidence from `82/88` to `84/89`.
  - Before: the layout page proved `0x10` and `0x14` image-info strides but omitted the third accessor.
  - After: added the `0x004e5f70` `0x0c`-stride record-size evidence and IDA verification note while keeping the concrete type name open.
  - Summary/evidence: Batch122 IDA `lookup_funcs`, `decompile`, and byte review confirm the third accessor shares the same `+0x04/+0x08/+0x10` layout and computes a 12-byte element stride.
- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank; the `+0x0c` field was described only as likely capacity/limit with no constructor evidence recorded.
- Changed to: completion `82`, confidence `88`, `RECONSTRUCTABLE:TRUE`; layout notes now record IDA-verified constructor, accessor, destructor, and resize evidence for all core offsets.
- Summary/evidence: IDA MCP decompilation of `0x004e5f20`, `0x004e5f40`, `0x004e5fa0`, `0x004e6240`, `0x00514d50`, and `0x00514ee0`, plus disassembly of `0x004e5a70-0x004e5b6f` and `0x005039f0-0x00503a41`, proves the header layout and concrete template behaviors. Scores remain below `95` because final original member spelling, full template declaration, and all owning module integration details are not yet exhaustively audited.
