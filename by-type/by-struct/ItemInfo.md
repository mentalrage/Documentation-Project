*** UID:0001UT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ItemInfo
{
    int itemTableId;
    int paletteSlot;
    float alpha;
    int lightImageIndex;
    bool allowPaletteFilter;
    unsigned char reserved[3];
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemInfo

## UID0003TX Light-Image Field Integration - 2026-07-16

- The exact `0x14` render-table row remains `itemTableId +0x00`, `paletteSlot +0x04`, `alpha +0x08`, one signed int at `+0x0c`, `allowPaletteFilter +0x10`, and three padding bytes. Only the source-facing `+0x0c` identity changes from provisional `renderFlagsOrMode` to `lightImageIndex`.
- UID0002QN is the direct semantic consumer: it resolves `status.m_appearanceId + 0x4000` through `ProtectedArray<ItemInfo>::GetAtOrDefault`, tests `lightImageIndex >= 0`, and passes that exact value to `MapPane::AttachObjectLighting` with half-tile offsets.
- The embedded fallback row's `-1` at `+0x0c` now has exact semantics: no object light is attached. This independently matches constructor/reload initialization and rejects flags, mode, pointer, frame-count, and generic render-state interpretations.
- Existing palette, alpha, filter, `ITEM.TBL`/`ITEM.TBD`, constructor/reload, availability-refresh, draw, and 20-byte-stride evidence remains valid and is preserved. The field rename does not change layout or resource decoding.
- Historical `renderFlagsOrMode` remains a superseded descriptive alias from before a direct consumer was recovered. Exact original spelling is inferred, which caps confidence at `92`, but behavior and compile-visible type are closed.
- No runtime wrapper or accessor is introduced. MapPane reaches the protected-array row through the accepted ItemObjImageLib friendship, and compiler copy/index lowering remains outside handwritten source.

## Status

- Confidence: strong for size, owner, constructor read order, fallback initialization, and draw-method consumption; medium-high overall because final source-facing field names remain provisional.
- Owner file: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Owner/emitter route: attached to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md). The file root clears the strict route gate; the formal block emits the source-ready row using `itemTableId`, `paletteSlot`, `alpha`, `lightImageIndex`, and `allowPaletteFilter`. Exact lexical spelling remains inferred, but `+0x0c` semantics are no longer a code blocker.
- Source resources: `ITEM.TBL` / `ITEM.TBD`.
- Size: `0x14` bytes.
- Primary IDA evidence: 2026-05-31 decompilation of `ItemObjImageLib::ItemObjImageLib` and draw methods at `0x004dee50`, `0x004defc0`, `0x004df1e0`, and `0x004df2c0`.

## Scope Caveat

This page documents the render image-table `ItemInfo` used by [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) and `ProtectedArray<ItemInfo>`. It is not necessarily the broader gameplay item database record returned by item/inventory systems.

## Layout

```text
ItemInfo
  +0x00  int itemTableId
  +0x04  int paletteSlot
  +0x08  float alpha
  +0x0c  int lightImageIndex
  +0x10  uint8 allowPaletteFilter
  +0x11  uint8[3] padding
```

## Notes

- The constructor reads five fields per row: int, int, float, int, int. The final int is collapsed to a boolean byte at offset `+0x10`.
- `DrawItemImage` and sibling draw methods use `+0x04` as the palette slot for palette category `10`, `+0x08` as the alpha/tint mode selector, and `+0x10` as the palette-filter allow flag.
- Current draw methods do not visibly consume `+0x00` beyond copying the row, so `itemTableId` remains descriptive. UID0002QN directly consumes `+0x0c` as signed `lightImageIndex`, while `paletteSlot`, `alpha`, and `allowPaletteFilter` retain their draw/availability-helper support.
- The fallback row embedded in [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) is initialized to `-1`, `-1`, `0.0`, `-1`, `0`.
- Historical B008 2026-06-19 draw-signature reanalysis confirmed `paletteSlot`, `alpha`, and `allowPaletteFilter` while then retaining `renderFlagsOrMode`; UID0003TX/UID0002QN supersede only that old `+0x0c` alias with direct `lightImageIndex` semantics. `itemTableId` remains descriptive.
- [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) is the direct producer-side evidence for `allowPaletteFilter`: for each successfully resolved `ITEM.EPF` / `ITEM.EPD` frame, it obtains `DLPalette *` through `GetSlotPalette(10, paletteSlot, 0)`, calls `EPFTileContext::ContainsIndexedPixelInRanges`, and stores the returned bool at row `+0x10`. The field spelling remains descriptive rather than symbol-proven; `hasPaletteFilterPixels` was considered but is not a stronger evidence-backed replacement.
- The default/fallback row lives at object `+0x14` because it is `ProtectedArray<ItemInfo>::m_defaultEntry`, not because `ItemObjImageLib` declares a second top-level `ItemInfo` member.

## IDA Evidence

- `ItemObjImageLib::ItemObjImageLib` at `0x004dec30-0x004dee1b` reads each table row with four integer reads and one float read: offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and a final integer collapsed to byte `+0x10`.
- The constructor writes each row as a 16-byte copy plus a dword at `+0x10`, confirming the `0x14` stride.
- Draw paths load records as `*(_OWORD*)record` plus `*(record+16)`, confirm fallback at object offset `+0x14`, use `+0x04` as the palette slot input to `PaletteLib` category `10`, branch on float `+0x08`, and test the byte form of `+0x10` when palette filtering is active.
- 2026-05-31 IDA vtable/global xrefs tie the consumer methods back to [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md), not to the broader gameplay item database.
- 2026-06-14 live IDA MCP rechecked the current modeled family: constructor `0x004dec30` is size `0x1eb`, draw methods `0x004dee50`, `0x004defc0`, `0x004df1e0`, and `0x004df2c0` are sizes `0x16a`, `0x214`, `0xd7`, and `0x195`, table reload helper `0x004df500` is size `0x168`, scalar deleting destructor `0x004e6580` is size `0x5c`, and the ordinary destructor start `0x004dee20` plus frame-availability helper start `0x004df670` still report `Not a function`.
- Current constructor and `0x004df500` decompilation both allocate or resize the entry buffer with `20 * count`, read each row as int, int, float, int, int, collapse the final integer to a byte at row `+0x10`, copy the first `0x10` bytes as an `OWORD`, and write the final dword/byte storage at `+0x10`.
- The raw `0x004df670` disassembly iterates entries by adding `0x14`, chooses the fallback row at object `+0x14` when the index is out of range, queries `ITEM.EPF`/`ITEM.EPD` resource data through the EPF image library, resolves palette category `0x0a`, and writes the availability/filter result to row offset `+0x10`.
- Draw decompilation for `0x004dee50` and `0x004defc0` indexes records with `entryBase + 20 * itemIndex`, copies the record into locals as `0x10` bytes plus the `+0x10` flag, passes `DWORD1(record)` to palette category `10`, branches on the float at record `+0x08`, and uses the `+0x10` byte to allow drawing even when palette/filter availability would otherwise block the path.

## Score Rationale

Completion is `85` because the row size, read order, fallback row, table reload helper, raw availability-refresh helper, draw consumers, resource split, file-level route, and first-draft formal declaration are now documented with current IDA evidence. Confidence is `89` because constructor, reload, raw helper, and draw paths independently agree on the `0x14` stride and field offsets; it remains below final-audit range because `+0x00` and `+0x0c` still lack recovered original source names and the exact header-vs-source declaration placement remains provisional.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)

## Changes

- 2026-07-12 B005 UID0003ND source-quality callback:
  - Score, declaration, field names, owner, and emitter unchanged. Added direct producer semantics for `allowPaletteFilter` from current MCP-backed UID0003ND and preserved its inferred-name caveat instead of making an unsupported support-wide rename.
- 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation:
  - Added the first-draft `struct ItemInfo` formal declaration using `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, `allowPaletteFilter`, and three reserved bytes. Provisional `+0x00` / `+0x0c` names remain a confidence caveat, not a no-code blocker.
- 2026-06-14 A002 score pass: raised from `82/86` to `85/89` after live IDA MCP reconfirmed constructor/reload row reads, `20 * count` allocation, fallback at object `+0x14`, draw-method field consumption, the raw `0x004df670` availability refresh writing row `+0x10`, and the `ItemObjImageLib.cpp` route. Reconstruction C++ remains blank because final field names and declaration placement are not source-quality.
- 2026-06-18 B005 source-quality sync: renamed provisional `+0x00` / `+0x0c` descriptive fields from `resourceKeyOrId` / `frameOrRenderFlags` to `itemTableId` / `renderFlagsOrMode` after constructor/helper reanalysis. These names are first-draft descriptive labels for constructor C++; exact original spellings remain below final-audit confidence.
- 2026-06-19 B008 source-quality sync: kept score `85/89`, added draw-signature support for `paletteSlot`, `alpha`, and `allowPaletteFilter`, preserved the `itemTableId` / `renderFlagsOrMode` caveats, and clarified that the object-level fallback row is the embedded protected-array default entry.
- 2026-06-06: Attached the row layout to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) because the page documents it as the render-table row owned by that module and both pages clear the parent gate. No score changes were made.
- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite a usable layout sketch.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA constructor decompilation proves the 20-byte row stride and row read order, draw methods prove palette/alpha/filter field usage, and `ItemObjImageLib` vtable/global xrefs prove this is the render image-table row rather than a gameplay inventory item record. Scores remain below final level because the original field names for `+0x00` and `+0x0c` remain provisional.
