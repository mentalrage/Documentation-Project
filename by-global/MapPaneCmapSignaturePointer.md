*** UID:0002ZJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapPaneCmapSignaturePointer

## Status

- Address: `0x0066db48`
- Exact storage: `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`.
- Current IDA name: `Buffer`.
- Target: ANSI `CMAP` at `0x0061e6f0` (`aCmap`).
- Kind: source-declared pointer to the MapPane compressed-map cache signature.
- Proposed source owner: MapPane compressed-map load/save support.
- Rebuild handling: source-declared pointer or equivalent address-taken signature constant.

## Role

MapPane's compressed map-cache loader compares the first four file bytes against this signature, and the save path writes the same signature before dimensions and the zlib-compressed tile payload.

## Evidence

- 2026-06-07 A007 IDA MCP reads `0x0066db48` as `0x0061e6f0`.
- The target bytes decode as ANSI `CMAP`.
- `xrefs_to 0x0066db48` reports exactly two refs: `0x00504ccf` in the compressed-map load method and `0x00504f41` in the compressed-map save method.
- The load instruction window passes this pointer to `_strncmp` with count `4`.
- The save instruction window passes this pointer to `_fwrite` with element size `1` and count `4`.
- The target literal is referenced only by this pointer slot.
- 2026-06-07 A002 Batch 078 IDA MCP recheck reconfirmed the storage item as `.data` `Buffer`, size `4`, bytes `f0 e6 61 00`, target `aCmap` as `.rdata` size `5` with bytes `43 4d 41 50 00`, exactly two slot xrefs, and an unreferenced next dword at `0x0066db4c`.

## Source Ownership

Keep this with MapPane compressed-map file-format support. The broad MapPane file/class pages remain below the strict parent confidence gate due unresolved companion splits, packet/weather boundaries, and generated field names, so this exact by-global page remains unassigned upward.

This page is the evidence anchor for [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md), but that memory child leaves `AUTOGEN_PARENT_UID` blank because generated memory coverage currently rejects by-global parent UIDs as `autogen_parent_unknown`.

## Cross-References

- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md)
- [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0002ST][0x0061e908-0x0061eadc.MapPaneResourceStrings](by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md)

## Changes

- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split MapPane `CMAP` signature pointer after live IDA confirmed pointer value, target string, two load/save xrefs, and separation from the adjacent StaffsDialogPane pointer.
- 2026-06-07 A002 Batch 078 coverage-error repair: Recorded the current IDA recheck and clarified that this by-global page remains a semantic evidence anchor, not a generated memory parent, until a direct source-file/class parent clears the corrected `85/85` gate or generated memory coverage supports by-global parents.
