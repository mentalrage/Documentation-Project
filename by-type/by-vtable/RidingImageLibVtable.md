*** UID:0001YM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RidingImageLib vtable data is compiler-generated from the class declaration
// and virtual destructor. Do not emit a hand-authored source vtable.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md).
- RTTI pointer: `0x0061b6f0` -> `0x00648cb4`.
- Primary vtable: `0x0061b6f4`.
- Exact vtable-data child: [UID:00031E][0x0061b6f0-0x0061b700.RidingImageLibVtableData](by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md).
- Assignment: attached to [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) after this page reached `86/91` and the direct class parent is `89/90`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e68b0` | Compiler-generated `RidingImageLib` scalar deleting wrapper (`0x004e68b0-0x004e6981`); false/non-emitting, regenerated from `virtual ~RidingImageLib()` and the ordinary destructor definition |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `StaticObjImageLib` RTTI pointer at `0x0061b700`.

## Evidence

IDA xrefs to `0x0061b6f4` land at:

- `0x004dc6e9` in [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- `0x004dc75a` in [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- `0x004e68e1` in the scalar deleting destructor

Active `class_RidingImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

2026-05-31 IDA MCP recheck confirms:

- `lookup_funcs` reports slot `0x004e68b0` as a real function of size `0xd1`, slot `0x004f4b10` as a six-byte inherited/shared virtual body, and slot `0x0041b6c0` as `nullsub_18`.
- `xrefs_to 0x0061b6f4` reports exactly the lifecycle vtable stores at `0x004dc6e9`, `0x004dc75a`, and `0x004e68e1`.
- `callers` reports no direct callers for the virtual-slot targets, which is consistent with vtable-only dispatch for this table.

2026-06-06 IDA MCP recheck confirms the slot `0x004e68b0` body is half-open `0x004e68b0-0x004e6981`: `0x004e6980` still resolves to `sub_4E68B0`, while `0x004e6981` is outside the function. The only xref to `0x004e68b0` is the vtable data slot at `0x0061b6f4`.

2026-06-08 Batch 132 IDA MCP recheck confirms the complete vtable-data child:

- Dword reads show `0x0061b6f0 -> ??_R4RidingImageLib@@6B@`, `0x0061b6f4 -> 0x004e68b0`, `0x0061b6f8 -> 0x004f4b10`, and `0x0061b6fc -> 0x0041b6c0`.
- Neighbor dwords prove the exact range: `0x0061b6e0 -> ??_R4MonsterImageLib@@6B@` before this table and `0x0061b700 -> ??_R4StaticObjImageLib@@6B@` after it.
- Xrefs to `0x0061b6f4` remain the constructor vptr store at `0x004dc6e9`, destructor vptr restore at `0x004dc75a`, and scalar-deleting-destructor self-reference at `0x004e68e1`.
- [UID:00031E][0x0061b6f0-0x0061b700.RidingImageLibVtableData](by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md) now owns the exact compiler-emitted dwords, while this page owns the source-level class vtable interpretation.

## 2026-06-30 B008 Compiler-Generated Vtable Disposition

B008's accepted report resolves the empty marker with a proof comment only. The vtable is source-relevant evidence for `RidingImageLib` ownership and virtual destructor behavior, but the rebuilt source should declare the class/virtual destructor and let the compiler regenerate vtable storage. Do not emit hand-authored vtable arrays.

## 2026-08-11 UID0002Y4 Primary-Slot Resolution

- Slot `0x0061b6f4` points to the exact 209-byte compiler scalar deleting wrapper at `0x004e68b0-0x004e6981`, SHA256 `A430FEB2B89FD946C458630446577831E24D9AF6E51CB692D52DAE1394670E2A`. The wrapper has this sole inbound data xref and zero ordinary code callers.
- The slot's current lifecycle evidence remains exact: constructor vptr store `0x004dc6e9`, ordinary-destructor restore `0x004dc75a`, and wrapper self-restore `0x004e68e1`. The complete dword window remains RTTI `0x00648cb4`, wrapper `0x004e68b0`, inherited/shared slot `0x004f4b10`, and `nullsub_18` `0x0041b6c0`.
- [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) is now `93/96`, compiler-generated, `RECONSTRUCTABLE:FALSE`, and non-emitting with blank CPP/H. This vtable page retains source-level class/vtable evidence, but the wrapper itself has no separate authored declaration, definition, or proof-comment output. The class declaration `virtual ~RidingImageLib();` and [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) ordinary destructor are the sole source carriers.
- The wrapper duplicates the ordinary cleanup inline rather than calling `0x004dc730`, then performs compiler-only bit-1/bit-4 optional-deletion handling and returns the receiver. Historical ownership and no-hand-authored-vtable conclusions remain valid; any historical target emitter/proof-comment route is superseded.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md). The child page now reaches `86/91`, the direct class parent is `89/90`, and the file parent [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) is `90/90`. The by-structure relationship is direct: a by-vtable page belongs to the class whose virtual table declaration emits the slot layout.

## Score Rationale

- `COMPLETION:85`: slot addresses, target function bounds, lifecycle xrefs, exact `.rdata` child data, neighbor boundaries, class/file parent chain, and no-final-C++ handling are documented.
- `CONFIDENCE:90`: IDA dword reads, `lookup_funcs`, and xrefs agree with the class, scalar-deleting-destructor, and exact child memory pages. Confidence remains below final-source levels because the inherited/shared virtual slot name is still not final.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00031E][0x0061b6f0-0x0061b700.RidingImageLibVtableData](by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)

## Changes

- 2026-08-11 B006 UID0002Y4 support synchronization:
  - Classified the primary slot target as a compiler-generated false/non-emitting scalar wrapper with no separate source fragment.
  - Preserved the exact slot/window/xrefs and class ownership while linking wrapper generation to the virtual destructor declaration and UID00017G source body.
  - Corrected the wrapper relationship to inline cleanup parity and retained the historical vtable no-hand-authored-storage decision.

- 2026-06-08 A003 Batch132:
  - Before: `78/86`, no parent, and no exact by-memory vtable-data child existed for `0x0061b6f0-0x0061b700`.
  - After: `85/90`, `AUTOGEN_PARENT_UID:0000BZ`, and exact child [UID:00031E][0x0061b6f0-0x0061b700.RidingImageLibVtableData](by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md) documents the compiler-emitted RTTI/vtable dwords.
  - Evidence: live IDA MCP dword reads, `lookup_funcs`, and xrefs reconfirmed the RTTI locator, slot dwords, target function sizes, constructor/destructor/scalar-destructor vptr writes, and Monster/StaticObj neighbor boundaries. The direct class parent and file parent both clear the corrected `85/85` gate.

- 2026-06-06: Synced the scalar deleting destructor slot to the exact `0x004e68b0-0x004e6981` body range and updated the RidingImageLib aggregate reference.
  - Evidence: A002 IDA MCP `lookup_funcs` and `xrefs_to` checks for `0x004e68b0`, `0x004e6980`, `0x004e6981`, and `0x0061b6f4`.

- 2026-05-31: Changed completion/confidence from `0/0` to `78/86` and marked the vtable reconstructable.
  - Before: the page had slot/xref notes but was still scored unevaluated and had blank `RECONSTRUCTABLE`.
  - After: the page records fresh IDA MCP slot and xref verification and is marked `RECONSTRUCTABLE:TRUE`; it remains below 95+ because inherited/shared slot names are not fully audited.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, and `callers` checks for `0x0061b6f4`, `0x004e68b0`, `0x004f4b10`, and `0x0041b6c0`.
