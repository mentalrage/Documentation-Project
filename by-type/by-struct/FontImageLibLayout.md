*** UID:0001UL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No separate layout C++ should be emitted for [UID:0001UL].
// The FontImageLib declaration owns the LObject base at +0x00, empty
// Singleton<FontImageLib> base and first FontSlotStorage at +0x04,
// second slot at +0x4000c, scratch pointer at +0x80014, and scratch
// byte count at +0x80018. RTTI PMD +0x04 and size 0x8001c prove EBO.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 0x8001c FontImageLib layout with LObject +0x00, empty Singleton<FontImageLib> and first FontSlotStorage EBO overlap at +0x04, second slot +0x4000c, scratch pointer/byte count +0x80014/+0x80018, 0x80010 constructor clear, and covered-by class-source disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontImageLib Layout

## Status

- Confidence: strong for field offsets, object size, field consumers, accepted field names used by emitted class/method source, and generated-binary/no-code disposition.
- Owner class: [UID:00005B][FontImageLib](by-class/FontImageLib.md).
- Direct autogen parent: [UID:00005B][FontImageLib](by-class/FontImageLib.md). The child layout is `92/96` and direct class parent is `94/94`, clearing the strict gate without bypassing the class through the file page.
- Rebuild handling: source-declared object layout for the rebuilt `FontImageLib` class; exact binary addresses are evidence, not separate emitted data. The formal C++ block is an exact covered-by no-code proof so generated output does not treat this layout evidence as an unresolved empty marker.
- Evidence: IDA constructor/destructor/load/decode decompilation on 2026-05-26, live IDA MCP recheck on 2026-06-11, and the exact memory pages listed below.

## Layout

```text
0x00000  LObject/vtable base
0x00004  empty Singleton<FontImageLib> base and FontSlotStorage fontSlots[0]
0x4000c  FontSlotStorage fontSlots[1]
0x80014  void *scratchBuffer
0x80018  int scratchBufferBytes
0x8001c  end / observed allocation size
```

Size checks:

```text
0x8001c / 524316 bytes  FontImageLib object allocation (Verified with int_convert.py)
0x80010 / 524304 bytes  constructor memset after the vtable (Verified with int_convert.py)
0x40008 / 262152 bytes  FontSlotStorage stride (Verified with int_convert.py)
```

The application startup caller at `0x00464520` constructs a `0x8001c`-byte object before the constructor at `0x004b5f00`. The constructor clears `0x80010` bytes starting after the vtable and then explicitly clears the two scratch fields at `+0x80014` and `+0x80018`.

RTTI has exactly three hierarchy entries: `FontImageLib`, `LObject`, and direct `Singleton<FontImageLib>`. Singleton PMD `mdisp=4`, `pdisp=-1`, `vdisp=0` proves a direct empty base beginning at `+0x04`; because allocation and all field consumers retain size `0x8001c`, that base uses EBO and overlaps the first `FontSlotStorage` rather than adding bytes.

## Field Evidence Matrix

| Field | Evidence |
| --- | --- |
| `+0x00000` vtable/base | The constructor calls the `LObject` base constructor, then stores the `FontImageLib` vtable. The ordinary and scalar deleting destructors restore the same vtable before cleanup. |
| `+0x00004` and `+0x4000c` font slots | The constructor memset covers both slots, the loader indexes `this + 0x40008 * slot + 0x04`, and both destructors walk exactly two entries at a `0x40008` stride to delete loaded archives. |
| `+0x80014` scratch buffer | The constructor clears it, `DecodeGlyphBitmap` reads/grows/replaces it for decoded glyph bytes, and both destructors free it when non-null. |
| `+0x80018` scratch capacity | The constructor clears it, `DecodeGlyphBitmap` compares requested decoded size against it, and the decoder updates it after allocating a larger scratch buffer. |

## Notes

- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md) is `0x40008` bytes: one `DATFile*`, two 16-bit metrics, and a `0x10000`-entry [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointer table.
- `EnsureFontSlotLoaded` clamps negative font ids and ids greater than or equal to `2` back to slot `0`, formats the archive name as UTF-16 `BARAM%02d.EFT`, and stores the loaded archive pointer in the slot.
- `DecodeGlyphBitmap` grows `scratchBuffer` only when the decoded glyph rectangle needs more bytes than `scratchBufferBytes`, then stores that pointer into the caller's EPFTileContext.
- Both binary destructor forms delete each loaded archive slot and free the scratch buffer; their later [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) clear is compiler-lowered reverse Singleton-base destruction, not an authored field write.
- `GetFontMetrics` and `MeasureGlyphWidth` are consumers rather than new layout writers: both force the appropriate slot to load before reading slot-local metrics or glyph records.
- This page attaches to the class rather than [UID:0000JH][FontImageLib](by-file/FontImageLib.md) because the layout is the concrete private state of the `FontImageLib` class; the file page remains the source-module parent above the class.
- B010's 2026-07-01 implementation accepts `m_fontSlots`, `m_scratchBuffer`, and `m_scratchBufferBytes` as source-facing field names used by emitted constructor/destructor/loader/decoder code. Exact original private spelling remains inferred, but the complete-object offset model is stable and this page should not duplicate the class declaration.

## IDA Evidence

- 2026-06-11 IDA MCP `lookup_funcs` reconfirmed the exact method boundaries used to prove this layout: constructor `0x004b5f00-0x004b5f54`, ordinary destructor `0x004b5f60-0x004b5fe6`, metrics `0x004b5ff0-0x004b6018`, measurement `0x004b6020-0x004b60ae`, loader `0x004b60c0-0x004b61d9`, decoder `0x004b61e0-0x004b6341`, and scalar deleting destructor `0x004b6350-0x004b6409`.
- Constructor decompilation stores [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md), installs the class vtable, zeroes `0x80010` bytes after the vtable, and clears the two trailing scratch fields.
- Ordinary destructor decompilation iterates two slot headers, using a `65538`-dword increment (`0x40008` bytes, Verified with int_convert.py), deletes each loaded archive pointer, frees `this+0x80014`, clears the singleton, and returns through the `LObject` destructor path.
- Loader decompilation indexes the selected slot as `this + 0x40008 * slot + 0x04`, stores the `DATFile` pointer at the slot base, stores 16-bit metrics at the next two fields, and loads the `0x10000` glyph table from the `BARAM%02d.EFT` archive.
- Decoder decompilation reads and updates the scratch pointer/capacity pair at `+0x80014/+0x80018`, then stores the scratch pointer into the caller's EPFTileContext.
- Scalar deleting destructor decompilation repeats the two-slot cleanup and scratch free before honoring the delete flag.

## Score Rationale

- Completion is `92` because direct-parent assignment, exact direct bases/EBO, object/slot sizes, field consumers, constructor/destructor/loader/decoder chain, source declaration route, and compiler exclusions are closed.
- Confidence is `96` because allocation size, clear span, field offsets, RTTI hierarchy/PMD, lifecycle order, and every consumer converge; private member spelling and two resource-record field meanings remain lexical/resource caps only.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md)
- [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md)
- [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md)
- [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md)
- [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `88/92` to `92/96`, retained UID00005B owner/emitter/true, and applied exact R8 covered-by layout comment.
  - Added direct empty Singleton PMD `+4/-1/0` EBO overlap at `+0x04`, exact base/slot/scratch rows, implicit lifecycle effects, and complete source-class/no-separate-layout route while preserving all size, consumer, resource, and historical evidence.

- 2026-06-11 A002 assigned coverage pass for supplemental type target `0001UL`.
  - Before: `COMPLETION/CONFIDENCE` was `76/86`, `AUTOGEN_PARENT_UID` was blank, and the page had the main offsets but not the direct-parent gate or field-by-field proof chain.
  - After: raised to `85/90` and attached to [UID:00005B][FontImageLib](by-class/FontImageLib.md).
  - Summary/evidence: child `85/90` and direct class parent `86/88` clear the strict `85/85` gate. Live IDA MCP reconfirmed the `0x8001c` object allocation path, constructor `0x80010` clear, two `0x40008` font slots at `+0x00004/+0x4000c`, scratch pointer/capacity at `+0x80014/+0x80018`, loader/decode/destructor field use, singleton/vtable lifecycle, and the remaining final private-name caveats.
- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `76/86`.
  - Summary/evidence: IDA MCP constructor/destructor/loader/decode evidence confirms the two-slot layout, slot stride, scratch pointer/capacity fields, singleton cleanup, and exact method boundaries. Final field names and the exact source declaration shape remain below near-final confidence.
- 2026-06-06: Corrected the loader resource format from stale `BA%d` shorthand to `BARAM%02d.EFT`, and recorded that the live assembly clamps negative as well as out-of-range font ids before selecting one of the two slots.
- 2026-06-06: Added decode-helper scratch/context evidence: live IDA for [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) reads/writes `this+0x80014/+0x80018`, writes the scratch pointer into `EPFTileContext+0x04`, and clears the context mask fields at `+0x20/+0x24`.
- 2026-07-01 B010 FontImageLib empty-emitter family implementation:
  - Before: `85/90`, with complete-object layout evidence but a blank formal block that still surfaced as an empty marker.
  - Changed to: `88/92`; inserted the accepted formal covered-by no-code proof comment and documented that the class and `FontSlotStorage` declarations emit the source layout.
  - Summary/evidence: accepted B010 report used live MCP command ids `9-29` plus current constructor/destructor/loader/decoder pages to confirm the complete-object offsets, field consumers, two-slot stride, scratch pointer/capacity, and source-facing field names. This page remains evidence only and does not duplicate emitted class source.
