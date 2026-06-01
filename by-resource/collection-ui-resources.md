*** UID:0001R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Collection UI Resources

## Status

- Resource family: collection list/detail UI EPF/PAL/font resources
- Owner modules: [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Confidence: strong for the listed string addresses and xref clusters; owner grouping remains less complete than code-level ownership.

## Resource Set

| Resource | Observed owner/use |
| --- | --- |
| `CLTINV.EPF` / `ITEMINV.EPF` / `ITEMINV.EPD` | Main collection inventory/list background in `CollectionPane` and related item inventory views. |
| `CLTLIST.EPF` / `CLTLIST.PAL` | Five-row collection summary slot frames. |
| `DLGCLT.EPF` / `DLGCLT.PAL` | Collection detail dialog background. |
| `CLTNAME.EPF` / `CLTNAME.PAL` | Selected collection name image in the dialog header. |
| `CLTBAR.EPF` / `CLTBAR.PAL` | Progress bar left/fill/right sprites. |
| `CLTENTRY.EPF` / `CLTENTRY.PAL` | Entry cell background. |
| `CLTICON.EPF` / `CLTICON.PAL` | Locked/unavailable entry icons. |
| `CLTVOL%d.EPF` / `CLTVOL%d.PAL` | Per-volume collected entry sprites. |
| `FONTSYMB.EPF` / `FONTSYMB.PAL` | Progress-label punctuation glyphs for `/`, `%`, `(`, and `)`. |
| `9X11FONT.BIN` | Numeric glyph table loaded by `CollectionBarControlPane`. |

## Evidence Notes

- `CollectionPane::OnPaint` loads `ITEMINV.EPF`/`ITEMINV.EPD`, `CLTINV.EPF`, and `CLTLIST.EPF`/`CLTLIST.PAL`.
- `CollectionDialogPane::BuildCollectionUI` creates `DLGCLT`, `CLTNAME`, bar, and six entry controls.
- `CollectionEntryControlPane` formats `CLTVOL%d` filenames from the collection volume id at player-data record `+0x3ec9`.
- `CollectionBarControlPane` uses `CLTBAR`, `FONTSYMB`, and `9X11FONT.BIN`.

## IDA MCP Evidence

- `CLTINV.EPF` at `0x00624ac8` xrefs from `0x0056edc0-0x0056f655` and `0x0056fdd0-0x0056fe41`.
- `ITEMINV.EPD` at `0x0061c8f8` xrefs from `0x004ea2a0-0x004ea945`; `ITEMINV.EPF` at `0x0061c94c` xrefs from `0x004ebb20-0x004ec913` and `0x004ee6f0-0x004eee5c`.
- `DLGCLT`, `CLTNAME`, `CLTENTRY`, `CLTICON`, `CLTVOL%d`, `CLTBAR`, `FONTSYMB`, and `9X11FONT.BIN` all decode as UTF-16 strings in the `0x00616704-0x006168b0` cluster and xref into the `0x0048c640`, `0x0048d3a0`, `0x0048d4a0`, `0x0048dc30`, `0x0048dd60`, and `0x0048dff0` collection UI helper ranges.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)

## Changes

- Before: page was scored `0/0` and one evidence note described `ITEMINV.PAL` where IDA evidence shows `ITEMINV.EPD`/`ITEMINV.EPF` in the checked paths.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with the item-image resource note corrected and IDA MCP address/xref evidence added.
- Evidence: IDA MCP direct UTF-16 decode and xrefs for the collection resource string cluster.
