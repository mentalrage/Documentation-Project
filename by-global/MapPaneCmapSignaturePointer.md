*** UID:0002ZJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const char *g_mapPaneCmapSignature = "CMAP";
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapPaneCmapSignaturePointer

## Status

- Address: `0x0066db48`
- Exact storage: `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`.
- Current IDA name: `Buffer`.
- Target: ANSI `CMAP` at `0x0061e6f0` (`aCmap`).
- Kind: source-declared pointer to the MapPane compressed-map cache signature.
- Source owner: [UID:0000L3][MapPane](by-file/MapPane.md) compressed-map load/save support.
- Rebuild handling: source-declared pointer or equivalent address-taken signature constant.
- Assignment: attached to [UID:0000L3][MapPane](by-file/MapPane.md) after the direct file parent reached `89/85`; the associated class page [UID:00007Q][MapPane](by-class/MapPane.md) is `85/85`.

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
- 2026-06-11 A006 IDA MCP recheck reconfirmed the same function boundaries and data facts: `0x00504b90` is the compressed-map load method, `0x00504e00` is the save method, `xrefs_to 0x0066db48` returns only `0x00504ccf` and `0x00504f41`, `xrefs_to 0x0061e6f0` returns only the pointer slot, and `xrefs_to 0x0066db4c` is empty.

## Source Ownership

Keep this with MapPane compressed-map file-format support. The direct file parent now clears the strict assignment gate: [UID:0000L3][MapPane](by-file/MapPane.md) is `89/85`, [UID:00007Q][MapPane](by-class/MapPane.md) is `85/85`, and this page is `89/93`. This is file-level static data rather than a separate class instance field.

This page remains the semantic evidence anchor for [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md). The exact memory child uses [UID:0000L3][MapPane](by-file/MapPane.md) as its generated parent as a tooling fallback because generated memory coverage previously rejected by-global parent UIDs as `autogen_parent_unknown`.

## Cross-References

- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md)
- [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0002ST][0x0061e908-0x0061eadc.MapPaneResourceStrings](by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md)

## Changes

- 2026-06-29 Agent-B004 MapPane empty-emitter callback:
  - Raised score to `90/94` and inserted `static const char *g_mapPaneCmapSignature = "CMAP";`.
  - Evidence: current MCP `241-243` reconfirmed pointer bytes/value `0x0061e6f0`, target ANSI `CMAP`, exactly two refs from the MapPane compressed-map load/save methods, and no refs to the following slot; [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md) now carries the covered-by marker.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split MapPane `CMAP` signature pointer after live IDA confirmed pointer value, target string, two load/save xrefs, and separation from the adjacent StaffsDialogPane pointer.
- 2026-06-07 A002 Batch 078 coverage-error repair: Recorded the current IDA recheck and clarified that this by-global page remains a semantic evidence anchor, not a generated memory parent, until a direct source-file/class parent clears the corrected `85/85` gate or generated memory coverage supports by-global parents.
- 2026-06-11 A006 Batch153: Raised `87/92` to `89/93` and set `AUTOGEN_PARENT_UID:0000L3`.
  - Evidence: live IDA MCP reconfirmed the exact `.data` pointer, `aCmap` target bytes, two load/save xrefs, and empty next-slot xrefs. The direct MapPane file parent is now `89/85`, with MapPane class context at `85/85`, so the strict child/direct-parent assignment gate clears for this source-declared file-level pointer.
