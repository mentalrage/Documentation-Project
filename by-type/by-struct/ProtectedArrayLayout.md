*** UID:0001VM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArrayLayout

## Status

- Confidence: strong for offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`; final semantic name for `+0x0c` remains provisional.
- Related template: [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md)
- Source-level owner: [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- Autogen parent: attached to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); the file scores `84/80` and this layout scores `82/88`, so both sides satisfy the 80/80 parent gate.

## Layout

Observed source-level shape:

```text
0x00  void* vtable
+0x04  int count
+0x08  T* entries
+0x0c  int capacity_or_reserved_count
+0x10  T defaultEntry
```

The accessor methods prove `count` at `+0x04`, `entries` at `+0x08`, and fallback/default entry at `+0x10`. The field at `+0x0c` is an allocation capacity or reserved-count field; keep the final source name provisional because reviewed bodies prove the offset and initial value, but not the original member spelling.

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

2026-05-26 IDA MCP recheck still supports this split. The two accessor functions use `+0x04` as count, `+0x08` as entries, and `+0x10` as fallback/default entry. The `+0x0c` field remains provisional because the reviewed accessor/destructor bodies do not name it.

## IDA Verification Notes

- `0x004e5f20` decompiles as a `ProtectedArray<HairInfo>` accessor: it rejects negative indexes or indexes greater than or equal to `this[1]`, returns `this + 0x10` for fallback, and otherwise returns `this[2] + 0x10 * index`.
- `0x004e5f40` is the same accessor pattern for `ProtectedArray<Acc2Info>`, but uses a `0x14` byte element stride.
- `0x004e5f70` is the same accessor pattern for another old-human image-info record and uses a `0x0c` byte element stride.
- `0x004e5a70-0x004e5b6f` disassembly is a sequence of compact ordinary destructor bodies. Representative bodies write the concrete `ProtectedArray<T>` vtable at offset `+0x00`, free the pointer at `+0x08`, and return.
- `0x004e5fa0`, `0x004e6240`, and `0x00514d50` decompile as scalar deleting destructors for concrete `ProtectedArray<T>` instantiations. Each reads `Block[2]`, writes the concrete vtable, frees the backing pointer, and conditionally calls `operator delete` when delete flag bit `1` is set.
- `0x005039f0-0x00503a41` is not currently modeled by IDA as a function, but disassembly shows `GameServerConfig` construction setting the embedded `ProtectedArray<GameServerConfig::NationEntry>` vtable, default record first field at `+0x10`, capacity/reserved field at `+0x0c` to `0x0a`, entries pointer at `+0x08` to null, and count at `+0x04` to zero.
- `0x00514ee0` decompiles as the `ProtectedArray<GameServerConfig::NationEntry>` resize helper: it compares the requested count against `+0x04`, allocates `68 * count` bytes, initializes each record's first 16-bit field to `-1`, copies the overlapping old entries from `+0x08`, frees the old storage, then updates `+0x08` and `+0x04`.

## Cross-References

- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)

## Changes

- 2026-06-06: Attached the reusable template/header layout to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md). Scores remain `82/88`; the type has no direct class page, so the file-level template owner is the correct parent.
- 2026-06-08 A003 Batch122: Raised completion/confidence from `82/88` to `84/89`.
  - Before: the layout page proved `0x10` and `0x14` image-info strides but omitted the third accessor.
  - After: added the `0x004e5f70` `0x0c`-stride record-size evidence and IDA verification note while keeping the concrete type name open.
  - Summary/evidence: Batch122 IDA `lookup_funcs`, `decompile`, and byte review confirm the third accessor shares the same `+0x04/+0x08/+0x10` layout and computes a 12-byte element stride.
- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank; the `+0x0c` field was described only as likely capacity/limit with no constructor evidence recorded.
- Changed to: completion `82`, confidence `88`, `RECONSTRUCTABLE:TRUE`; layout notes now record IDA-verified constructor, accessor, destructor, and resize evidence for all core offsets.
- Summary/evidence: IDA MCP decompilation of `0x004e5f20`, `0x004e5f40`, `0x004e5fa0`, `0x004e6240`, `0x00514d50`, and `0x00514ee0`, plus disassembly of `0x004e5a70-0x004e5b6f` and `0x005039f0-0x00503a41`, proves the header layout and concrete template behaviors. Scores remain below `95` because final original member spelling, full template declaration, and all owning module integration details are not yet exhaustively audited.
