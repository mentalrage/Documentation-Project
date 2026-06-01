*** UID:0001UL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontImageLib Layout

## Status

- Confidence: strong for field offsets, medium for final field names.
- Owner class: [UID:00005B][FontImageLib](by-class/FontImageLib.md).
- Evidence: IDA constructor/destructor/load/decode decompilation on 2026-05-26.

## Layout

```text
0x00000  LObject/vtable
0x00004  FontSlotStorage fontSlots[2]
0x80014  void* scratchBuffer
0x80018  int scratchBufferBytes
0x8001c  end / allocated size
```

Expanded slot placement:

```text
0x00004  FontSlotStorage fontSlots[0]
0x4000c  FontSlotStorage fontSlots[1]
```

The application allocates `524316` bytes (`0x8001c`) before calling the constructor at `0x00464520`. The constructor clears `0x80010` bytes starting after the vtable and then explicitly clears the two scratch fields.

## Notes

- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md) is `0x40008` bytes: one `DATFile*`, two 16-bit metrics, and a `0x10000`-entry [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointer table.
- `EnsureFontSlotLoaded` clamps any font id greater than or equal to `2` back to slot `0`, formats the archive name as `BA%d`, and stores the loaded archive pointer in the slot.
- `DecodeGlyphBitmap` grows `scratchBuffer` only when the decoded glyph rectangle needs more bytes than `scratchBufferBytes`.
- Both the ordinary and scalar deleting destructors delete each loaded archive slot, free the scratch buffer, and clear [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md).
- IDA MCP `lookup_funcs` confirms the exact `FontImageLib` method boundaries used to prove this layout: constructor `0x004b5f00-0x004b5f54`, ordinary destructor `0x004b5f60-0x004b5fe6`, metrics `0x004b5ff0-0x004b6018`, measurement `0x004b6020-0x004b60ae`, loader `0x004b60c0-0x004b61d9`, decoder `0x004b61e0-0x004b6341`, and scalar deleting destructor `0x004b6350-0x004b6409`.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md)
- [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)

## Changes

- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `76/86`.
  - Summary/evidence: IDA MCP constructor/destructor/loader/decode evidence confirms the two-slot layout, slot stride, scratch pointer/capacity fields, singleton cleanup, and exact method boundaries. Final field names and the exact source declaration shape remain below near-final confidence.
