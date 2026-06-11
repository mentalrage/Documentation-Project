*** UID:0001VW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000BZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingImageLib Layout

## Status

- Confidence: strong for observed offsets, medium for final field names.
- Owner class: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md).
- Autogen parent: attached to [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md); the class scores `82/80` and this layout scores `82/86`, so both sides satisfy the 80/80 parent gate.
- Evidence: IDA constructor/destructor/definition-loader decompilation and xrefs on 2026-05-26.

## Layout

```text
RidingImageLib
  +0x00  LObject/vtable
  +0x04  RidingDefinition* ridingDefinitions
  +0x08  uint32 ridingDefinitionCount
  +0x0c  ImageFrameTablePackage* ridingEpfPackage
```

The riding definition allocation is MSVC vector-shaped: the object field points at the first [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) element, and the allocation header at pointer `-4` stores the element count used by the destructor iterator.

## Notes

- The constructor writes [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md), constructs the `LObject` base, stores the [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md), zeros `+0x04`, calls `LoadRidingDefinitions`, and stores the `RIDINGS.EPF` frame-table package at `+0x0c`.
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md) reads the first dword of `RIDINGS.DNA` as the riding definition count, allocates `count * 0x0c + 4`, constructs `0x0c`-byte [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) rows, then stores the element pointer at `+0x04` and count at `+0x08`.
- The ordinary and scalar deleting destructors free the `+0x0c` frame-table package, destroy/free the `+0x04` vector block, call `LObject` cleanup, and clear [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md).

## IDA MCP Verification Notes

- 2026-05-31 `lookup_funcs` reports the constructor at `0x004dc690` size `0x92`, ordinary destructor at `0x004dc730` size `0xa8`, and scalar deleting destructor at `0x004e68b0` size `0xd1`; A002's 2026-06-06 recheck confirms the scalar deleting destructor's half-open range is `0x004e68b0-0x004e6981`.
- 2026-05-31 constructor decompilation writes `g_pRidingImageLib` at `0x0069b444`, calls the `LObject` base constructor, stores vtable `0x0061b6f4` at `this+0x00`, clears `this+0x04`, calls the definition parser, and stores the `RIDINGS.EPF` package pointer at `this+0x0c`.
- 2026-05-31 parser decompilation stores the riding definition vector pointer/count at `this+0x04` and `this+0x08`.
- 2026-05-31 ordinary and scalar deleting destructor decompilations both read `this+0x0c` as the frame-table package handle and `this+0x04` as the vector element pointer, then use 12-byte element destruction through `0x00528950`.
- 2026-05-31 xrefs to vtable `0x0061b6f4` land in the constructor, ordinary destructor, and scalar deleting destructor, matching the class lifecycle writes.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0002LA][0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md)

## Changes

- 2026-06-06: Synced the RidingImageLib aggregate reference and scalar deleting destructor endpoint to `0x004e6981`.
  - Evidence: A002 IDA MCP `lookup_funcs` confirmed `sub_4E68B0` size `0xd1`, with `0x004e6980` inside the function and `0x004e6981` outside.

- 2026-06-06: Attached the layout to [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md). Scores remain `82/86`; this parent sync follows the already documented constructor/parser/destructor agreement.
- 2026-05-31: Changed completion/confidence from `0/0` to `82/86` and marked the layout reconstructable.
  - Before: the page had useful observed offsets but was still scored unevaluated and had blank `RECONSTRUCTABLE`.
  - After: the page records fresh IDA MCP constructor/parser/destructor/vtable evidence, is marked `RECONSTRUCTABLE:TRUE`, and remains below 95+ because final source-facing member names and inherited helper names still need a broader audit.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` checks for `0x004dc690`, `0x004dc730`, `0x004e68b0`, `0x004dc420`, `0x0061b6f4`, and `0x0069b444`.
