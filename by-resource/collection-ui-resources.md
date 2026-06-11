*** UID:0001R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Collection UI Resources

## Status

- Resource family: collection list/detail UI EPF/PAL/font resources
- Owner modules: [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Confidence: strong for the listed string addresses, xref clusters, and owner split; exact DAT packaging/source-asset provenance remains open.

## Resource Set

| Resource | Owner/use | Rebuild handling |
| --- | --- | --- |
| `CLTINV.EPF` / `ITEMINV.EPF` / `ITEMINV.EPD` | Main collection inventory/list background in [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and related item inventory views. | Resource-derived payloads; source keeps the wide-string names and loader calls. |
| `CLTLIST.EPF` / `CLTLIST.PAL` | Five-row collection summary slot frames drawn by `CollectionPane::OnPaint`. | Resource-derived payloads owned by the main collection panel path. |
| `DLGCLT.EPF` / `DLGCLT.PAL` | Detail-dialog background created by [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md). | Resource-derived payloads with source-declared string constants in the dialog file. |
| `CLTNAME.EPF` / `CLTNAME.PAL` | Selected collection name image in the dialog header. | Dialog-private resource names in [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md). |
| `CLTBAR.EPF` / `CLTBAR.PAL` | Progress bar left/fill/right sprites used by `CollectionBarControlPane`. | Private detail-dialog control resources. |
| `CLTENTRY.EPF` / `CLTENTRY.PAL` | Entry cell background for each six-entry page slot. | Private detail-dialog control resources. |
| `CLTICON.EPF` / `CLTICON.PAL` | Locked/unavailable entry icons in `CollectionEntryControlPane`. | Private detail-dialog control resources. |
| `CLTVOL%d.EPF` / `CLTVOL%d.PAL` | Per-volume collected entry sprites formatted from the collection group volume id. | Patterned resource names; payload source/packaging still needs asset-side proof. |
| `FONTSYMB.EPF` / `FONTSYMB.PAL` | Progress-label punctuation glyphs for `/`, `%`, `(`, and `)`. | Shared UI symbol resources with collection call sites, not collection-private ownership. |
| `9X11FONT.BIN` | Numeric glyph table loaded by `CollectionBarControlPane`. | Shared UI numeric-font resource with collection call sites, not collection-private ownership. |

## Owner Split

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md) owns the main five-row collection list resource usage: `CLTINV`, `CLTLIST`, and the inventory-frame interaction with `ITEMINV` resources.
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) owns the detail dialog and private child-control resource family: `DLGCLT`, `CLTNAME`, `CLTBAR`, `CLTENTRY`, `CLTICON`, and `CLTVOL%d`.
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) is the exact source-declared/generated-binary data island for the dialog/control vtables and UTF-16 resource-string constants. The compiler should regenerate RTTI/vtables from class declarations; the source should preserve the resource names and format strings.
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) explains why `CLTVOL%d` is keyed from the group type/volume byte at group offset `+0x3ec9`.

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned payload |
| --- | --- | --- |
| Main collection panel | `CollectionPane` owns the five-row summary list, hit testing, scroll child interaction, request-or-open behavior, and inventory-frame selection. | `CLTINV.EPF`, `CLTLIST.EPF`/`.PAL`, and `ITEMINV.*` provide visual payloads; `ITEMINV.*` remains a shared inventory-frame dependency until a broader inventory resource page owns it. |
| Detail dialog shell | `CollectionDialogPane` owns dialog construction, selected-group display, page/entry control creation, and header/name placement. | `DLGCLT.*` and `CLTNAME.*` provide dialog background/header payloads. |
| Entry and progress controls | `CollectionEntryControlPane` and `CollectionBarControlPane` own slot state, locked/unavailable decisions, progress math, and draw ordering. | `CLTENTRY.*`, `CLTICON.*`, `CLTBAR.*`, and formatted `CLTVOL%d.*` payloads provide entry, icon, bar, and per-volume visuals. |
| Shared text/symbol resources | Collection bar formatting owns the progress-label string shape `%d/%d (%d%%)` and selects glyphs through the shared font/symbol resources. | `FONTSYMB.*` and `9X11FONT.BIN` stay shared UI dependencies with collection call sites, not collection-private payloads. |

## Boundary Rules

- Keep [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) as separate owners: the former owns the compact panel/list resources, while the latter owns the detail-dialog private controls.
- Treat `CLTVOL%d` as a source-level format-string contract tied to [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md), not as a single literal asset filename.
- Do not fold `FONTSYMB.*` or `9X11FONT.BIN` into collection ownership. If their broader consumer set is audited later, promote them to a shared font/symbol resource page and keep this page as a consumer.
- Keep the exact byte/string inventory on [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md). This page summarizes resource roles and ownership boundaries rather than replacing per-address `.rdata` documentation.

## Evidence Notes

- `CollectionPane::OnPaint` loads `ITEMINV.EPF`/`ITEMINV.EPD`, `CLTINV.EPF`, and `CLTLIST.EPF`/`CLTLIST.PAL`.
- `CollectionDialogPane::BuildCollectionUI` creates `DLGCLT`, `CLTNAME`, bar, and six entry controls.
- `CollectionEntryControlPane` formats `CLTVOL%d` filenames from the collection volume id at player-data record `+0x3ec9`.
- `CollectionBarControlPane` uses `CLTBAR`, `FONTSYMB`, and `9X11FONT.BIN`.
- The `FONTSYMB.*` and `9X11FONT.BIN` xrefs are evidence that collection controls consume the shared UI font/symbol resources; they do not prove that collection owns those payloads or should duplicate them in rebuild packaging.

## IDA MCP Evidence

- `CLTINV.EPF` at `0x00624ac8` xrefs from `0x0056edc0-0x0056f655` and `0x0056fdd0-0x0056fe41`.
- `ITEMINV.EPD` at `0x0061c8f8` xrefs from `0x004ea2a0-0x004ea945`; `ITEMINV.EPF` at `0x0061c94c` xrefs from `0x004ebb20-0x004ec913` and `0x004ee6f0-0x004eee5c`.
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) now owns the exact collection dialog `.rdata` island: current IDA MCP byte/string review confirms the `CollectionDialogPane` RTTI locator at `0x006164f0`, vtable labels from `0x006164f4` through `0x006166cc`, and the UTF-16 string cluster from `0x006166d4` through `0x006168b0`.
- `DLGCLT`, `CLTNAME`, `CLTENTRY`, `CLTICON`, `CLTVOL%d`, `CLTBAR`, `FONTSYMB`, and `9X11FONT.BIN` all decode as UTF-16 strings in the `0x00616704-0x006168b0` cluster and xref into the `0x0048c640`, `0x0048d3a0`, `0x0048d4a0`, `0x0048dc30`, `0x0048dd60`, and `0x0048dff0` collection UI helper ranges.

## Open Questions

- Confirm which DAT/archive families physically contain each collection EPF/PAL/BIN payload. The current evidence proves code-facing resource names and owners, not installer/source-asset provenance.
- Decide whether `ITEMINV.*` should stay listed as a shared inventory-frame dependency here or move to a broader inventory UI resource page once that resource family is audited.
- Split shared UI font/symbol resources into their own durable resource page if later review finds broad enough ownership outside collection controls.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now documents the collection panel/detail-dialog resource split, exact read-only-data island, source/resource contracts for panel, dialog, entry, progress, and shared text/symbol dependencies, `CLTVOL%d` format ownership, shared-resource exclusions, and DAT/provenance open questions. It remains below high completion because DAT archive ownership, full payload frame layout, broad shared font/symbol ownership, and final `ITEMINV.*` placement are still open. |
| Confidence | 88 | Confidence remains strong because string addresses, xref clusters, owner modules, and `.rdata` boundaries are IDA-backed in linked docs. It is capped by unresolved DAT payload provenance and shared-resource ownership. |

## Changes

- Before: page was scored `0/0` and one evidence note described `ITEMINV.PAL` where IDA evidence shows `ITEMINV.EPD`/`ITEMINV.EPF` in the checked paths.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with the item-image resource note corrected and IDA MCP address/xref evidence added.
- Evidence: IDA MCP direct UTF-16 decode and xrefs for the collection resource string cluster.
- 2026-06-05: Added the exact [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) cross-reference and corrected the memory evidence to include the `0x006164f0` `CollectionDialogPane` RTTI locator boundary.
- 2026-06-06: Raised completion/confidence from `70/85` to `78/88`, split main-panel resources from detail-dialog private resources, added rebuild-handling notes for source-declared string constants versus resource-derived payloads, and documented shared-font/non-private ownership caveats.
  - Before: the page listed resources and xrefs but did not distinguish panel/dialog/shared-resource ownership or rebuild packaging boundaries.
  - After: resource rows now identify owner/use and rebuild handling, with open questions for DAT packaging provenance, `ITEMINV.*` ownership, and possible shared font/symbol promotion.
- 2026-06-07 A002 source/resource contract pass:
  - Before: the page had the owner split and rebuild handling, but did not spell out the source-owned behavior versus resource-owned payload contract for panel, dialog, entry, progress, and shared text/symbol resources.
  - After: raised to `COMPLETION:80` with source/resource contracts, boundary rules for `CLTVOL%d`, shared font/symbol exclusions, exact `.rdata` ownership linkage, and score rationale.
