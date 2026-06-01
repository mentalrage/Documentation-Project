*** UID:0001YM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md).
- RTTI pointer: `0x0061b6f0` -> `0x00648cb4`.
- Primary vtable: `0x0061b6f4`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e68b0` | `RidingImageLib::DeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `StaticObjImageLib` RTTI pointer at `0x0061b700`.

## Evidence

IDA xrefs to `0x0061b6f4` land at:

- `0x004dc6e9` in [UID:00017F][0x004dc420-0x004e6980.RidingImageLib](by-memory/0x004dc420-0x004e6980.RidingImageLib.md)
- `0x004dc75a` in [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- `0x004e68e1` in the scalar deleting destructor

Active `class_RidingImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

2026-05-31 IDA MCP recheck confirms:

- `lookup_funcs` reports slot `0x004e68b0` as a real function of size `0xd1`, slot `0x004f4b10` as a six-byte inherited/shared virtual body, and slot `0x0041b6c0` as `nullsub_18`.
- `xrefs_to 0x0061b6f4` reports exactly the lifecycle vtable stores at `0x004dc6e9`, `0x004dc75a`, and `0x004e68e1`.
- `callers` reports no direct callers for the virtual-slot targets, which is consistent with vtable-only dispatch for this table.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)
- [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `78/86` and marked the vtable reconstructable.
  - Before: the page had slot/xref notes but was still scored unevaluated and had blank `RECONSTRUCTABLE`.
  - After: the page records fresh IDA MCP slot and xref verification and is marked `RECONSTRUCTABLE:TRUE`; it remains below 95+ because inherited/shared slot names are not fully audited.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, and `callers` checks for `0x0061b6f4`, `0x004e68b0`, `0x004f4b10`, and `0x0041b6c0`.
