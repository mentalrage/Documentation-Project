*** UID:0001UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FontSlotStorage is declared before FontImageLib by [UID:00005B][FontImageLib](by-class/FontImageLib.md).
// This page remains exact per-font-slot layout evidence only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 0x40008 FontSlotStorage declaration with DATFile pointer, two 16-bit metrics, 0x10000 FontGlyphRecord pointer table, loader/destructor consumers, two-object embedding, and one leading declaration through UID00005B; this page emits only a covered-by comment. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontSlotStorage

## Status

- Confidence: strong for size, offsets, loader/destructor consumers, direct class ownership, declaration order, and covered-by route; final historical field names and exact metric meanings remain capped.
- Owner/direct autogen parent: [UID:00005B][FontImageLib](by-class/FontImageLib.md). This struct is the per-font slot storage embedded twice in the `FontImageLib` object.
- Rebuild handling: source-declared class-private struct layout; the binary bytes are evidence for a C++ declaration, not standalone data to emit.
- C++ reconstruction status: the complete struct is declared exactly once after `FontGlyphRecord` and before the by-value `FontImageLib` member by [UID:00005B][FontImageLib](by-class/FontImageLib.md). This page emits R11 covered-by text only, preventing a duplicate late declaration while retaining exact slot evidence.
- Size: `0x40008` bytes / 262152 bytes (Verified with int_convert.py).
- Assignment gate: child `92/94` and direct class parent [UID:00005B][FontImageLib](by-class/FontImageLib.md) `94/94` clear the strict gate, so the struct remains class-owned rather than bypassing through the file page.

## Layout

```text
FontSlotStorage
  +0x00000  DATFile* archiveFile
  +0x00004  unsigned short maxCellWidth
  +0x00006  unsigned short maxCellHeightMinus4
  +0x00008  FontGlyphRecord* glyphTable[0x10000]
  +0x40008  end
```

Size checks:

```text
0x10000 / 65536 glyph entries (Verified with int_convert.py)
0x40000 / 262144 glyph-table bytes (Verified with int_convert.py)
4 + 2 + 2 + 0x40000 == 0x40008 / 262152 bytes (Verified with int_convert.py)
```

## Field Evidence Matrix

| Field | Evidence |
| --- | --- |
| `+0x00000 archiveFile` | [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) checks the slot-window dword at `+0x04` before loading and returns the slot base at `slotWindow + 0x04`; the ordinary and scalar deleting destructors walk both slots and call the stored archive object's deleting destructor when this pointer is non-null. |
| `+0x00004 maxCellWidth` | The loader reads two bytes from the DAT entry into `slotWindow + 0x08`, which is `FontSlotStorage + 0x04`. The exact display meaning remains a metric-name hypothesis until resource-level confirmation. |
| `+0x00006 maxCellHeightMinus4` | The loader reads two bytes into `slotWindow + 0x0a` / struct `+0x06`, then subtracts `4`. The stored value is therefore the second archive metric after adjustment, not the raw resource word. |
| `+0x00008 glyphTable[0x10000]` | The loader reads `0x10000` 32-bit relative offsets and writes either `0` or `DATFile::GetDataPointer() + offset` at `slotWindow + 0x0c + 4 * glyphId`, which is `FontSlotStorage + 0x08 + 4 * glyphId`. [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md) consumes the table through `EnsureFontSlotLoaded(...)[4 * glyphId + 8]`. |

## Behavior

[UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) initializes this structure lazily. It opens `BARAM00.EFT` or `BARAM01.EFT` using the UTF-16 format `BARAM%02d.EFT`, reads the two 16-bit maximum cell metrics, subtracts four from the height field, then reads `0x10000` relative offsets. Nonzero offsets are resolved against the `DATFile` payload base and stored as [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointers.

The `archiveFile` pointer doubles as the loaded flag. Destructors test it before dispatching the archive object's virtual deleting destructor.

## 2026-06-11 A009 Live IDA Recheck

- IDB: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` reconfirmed the supporting method bounds: loader `0x004b60c0-0x004b61d9` (`0x119` bytes), measurement `0x004b6020-0x004b60ae`, decoder `0x004b61e0-0x004b6341`, ordinary destructor `0x004b5f60-0x004b5fe6`, and scalar deleting destructor `0x004b6350-0x004b6409`.
- Loader disassembly confirms the signed/upper-bound slot clamp, `imul esi, edx, 40008h`, loaded-flag test at `[slotWindow+4]`, return of `slotWindow+4`, metric reads at `[slotWindow+8]` and `[slotWindow+0x0a]`, `add word ptr [slotWindow+0x0a], 0xfffc`, and the `0x10000`-iteration glyph-offset loop.
- Loader decompilation reconfirms `DATFile` allocation/construction, virtual `Open`, `GetDataPointer`, virtual `Read`, and storing each nonzero glyph offset as a pointer relative to the payload base.
- Measurement decompilation reconfirms the table consumer expression `EnsureFontSlotLoaded(...)[4 * glyphId + 8]`, tying the struct's `+0x08` pointer table to [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) records.

## Score Rationale

- Completion is `92` because direct class assignment, rebuild handling, declaration order, covered-by routing, verified size arithmetic, field evidence, loader/disassembler proof, destructor ownership, and measurement consumers are closed.
- Confidence is `94` because live IDA evidence, class/layout pages, constructor clear span, loader, and destructors agree on the `0x40008` stride, two-object embedding, and field roles. The two metric names and historical declaration spelling remain inferred caps.

## Cross-References

- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `90/91` to `92/94`, preserved UID00005B owner/emitter, and replaced the duplicate late struct formal with exact R11 covered-by text.
  - The complete declaration now occurs once before the by-value class member in UID00005B. Exact `0x40008` size, fields, `0x10000` table, BARAM loader, two-slot embedding, destructor consumers, uncertain metric spelling, and historical evidence remain preserved here.

- 2026-05-31: Reconstructable status and score updated.
  - Before: `RECONSTRUCTABLE` was blank and completion/confidence were `0/0`.
  - After: marked `RECONSTRUCTABLE:TRUE` with completion/confidence `78/88`.
  - Summary/evidence: IDA MCP decompilation of `FontImageLib::EnsureFontSlotLoaded` proves the `0x40008` slot size, DATFile pointer-as-loaded-flag, two 16-bit metrics, and `0x10000` pointer table; destructor pages prove slot cleanup behavior.
- 2026-06-06: Corrected producer resource names from stale `BA0` / `BA1` shorthand to `BARAM00.EFT` / `BARAM01.EFT`, following the live IDA literal evidence recorded on [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md).
- 2026-06-11 A009 Batch 156 struct evidence pass:
  - Before: `COMPLETION/CONFIDENCE` was `78/88` and `AUTOGEN_PARENT_UID` was blank.
  - After: raised to `85/90` and attached to [UID:00005B][FontImageLib](by-class/FontImageLib.md).
  - Summary/evidence: child `85/90` and direct class parent `86/88` clear the strict gate. Live IDA MCP reconfirmed the loader, measurement, decoder, and destructor boundaries; loader disassembly proves the `0x40008` stride, loaded-flag/archive pointer, two metric reads, second-metric minus-four adjustment, `0x10000` glyph-offset loop, and return of the slot base. Measurement decompilation confirms the `+0x08` glyph pointer table consumer.
- 2026-06-29 B001 UID0002HP implementation callback:
  - Before: `85/90` with formal C++ blank.
  - Changed to: `90/91` with exact formal `FontSlotStorage` declaration emitted through [UID:00005B][FontImageLib](by-class/FontImageLib.md).
  - Summary/evidence: accepted constructor report uses MCP session `3fa0535f` to prove `memset(this+4,0,0x80010)`, and this struct's `0x40008` size makes two slots exactly match that clear span. Field names remain source-facing inferred names, with `maxCellHeightMinus4` preserving the loader's minus-four adjustment.
