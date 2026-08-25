*** UID:0001R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Collection UI Resources

## UID0000KA Exact Inventory Use-Site Split - 2026-08-15

The exhaustive inventory audit resolves source use without claiming private payload ownership: legacy uses `ITEMINV.EPD` once and `NPAL6.PAL`/`SPELLBUT.EPD` at exact paint sites; Pane2 uses `ITEMINV.EPF`, `ITEMINV.PAL`, `%c: `, `BUTTON.PAL`, and `INVENBUT.EPF`; NewInventoryPane retains its separate `ITEMINVE.EPF`, `...(%d)`, and shared-frame sites. UID0003BX records every literal range, all xrefs, the zero-route `INV.EPD` suffix view, and four zero-padding spans. Resource payload/package uncertainty remains here; no standalone literal array emits from UID0000KA and the score is unchanged.

## Status

- Resource family: collection list/detail UI EPF/PAL/font resources
- Owner modules: [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Confidence: very strong for the listed string addresses, xref clusters, helper consumers, owner split, and current DAT package provenance; medium-high for final shared-resource ownership and `ITEMINV.EPD` legacy payload placement.

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

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked the read-only client tree for loose duplicates. The collection private resources are current-package entries, mostly in `bint0.dat`, while the shared dialog/font resources stay in their existing shared packages.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `CLTBAR.EPF` / `.PAL` | `bint0.dat` entries `30`/`31`, offsets `8,229,033` / `8,233,237`, sizes `4,204` / `1,056`. | EPF header reports 3 frames of `194x20`; palette begins with `DLPalette`. |
| `CLTENTRY.EPF` / `.PAL` | `bint0.dat` entries `32`/`33`, offsets `8,234,293` / `8,258,926`, sizes `24,633` / `1,056`. | EPF header reports 1 frame of `255x95`; palette begins with `DLPalette`. |
| `CLTICON.EPF` / `.PAL` | `bint0.dat` entries `34`/`35`, offsets `8,259,982` / `8,278,456`, sizes `18,474` / `1,056`. | EPF header reports 2 frames of `95x95`; palette begins with `DLPalette`. |
| `CLTINV.EPF` | `bint0.dat` entry `36`, offset `8,279,512`, size `55,993`. | EPF header reports 1 frame of `192x287`. |
| `CLTLIST.EPF` / `.PAL` | `bint0.dat` entries `37`/`38`, offsets `8,335,505` / `8,350,717`, sizes `15,212` / `1,056`. | EPF header reports 2 frames of `155x48`; palette begins with `DLPalette`. |
| `CLTNAME.EPF` / `.PAL` | `bint0.dat` entries `39`/`40`, offsets `8,351,773` / `8,443,646`, sizes `91,873` / `1,056`. | EPF header reports 7 frames of `254x51`; palette begins with `DLPalette`. |
| `CLTVOL0` through `CLTVOL6` `.EPF` / `.PAL` | `bint0.dat` entries `41` through `54`, offsets `8,444,702` through `10,270,097`. | Seven current volume sprite/palette pairs exist; EPF frame counts are `44`, `30`, `21`, `18`, `30`, `30`, and `24`, each `95x95`, and palettes begin with `DLPalette`. |
| `DLGCLT.EPF` / `.PAL` | `bint1.dat` entries `17`/`18`, offsets `1,467,270` / `1,783,254`, sizes `315,984` / `1,056`. | EPF header reports 1 frame of `668x468`; palette begins with `DLPalette`. |
| `FONTSYMB.EPF` / `.PAL` | `bint1.dat` entries `76`/`77`, offsets `7,715,040` / `7,715,604`, sizes `564` / `1,056`. | EPF header reports 5 frames of `9x11`; palette begins with `DLPalette`. |
| `9X11FONT.BIN` | `bint0.dat` entry `0`, offset `1,092`, size `3,069`. | Shared numeric-font payload used by collection progress rendering. |
| `ITEMINV.EPF` / `ITEMINV.PAL` | `bint2.dat` entries `8`/`9`, offsets `7,168,453` / `7,280,427`, sizes `111,974` / `1,056`. | Shared inventory-frame dependency; `ITEMINV.EPF` reports 2 frames of `192x287`, and the palette begins with `DLPalette`. |
| `ITEMINV.EPD` | No matching DAT entry or loose file found in the audited current tree. | Keep the legacy operand documented from IDA xrefs, but treat the current package payload as unresolved. |

## Owner Split

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md) owns the main five-row collection list resource usage: `CLTINV`, `CLTLIST`, and the inventory-frame interaction with `ITEMINV` resources.
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) owns the detail dialog and private child-control resource family: `DLGCLT`, `CLTNAME`, `CLTBAR`, `CLTENTRY`, `CLTICON`, and `CLTVOL%d`.
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) is the exact source-declared/generated-binary data island for the dialog/control vtables and UTF-16 resource-string constants. The compiler should regenerate RTTI/vtables from class declarations; the source should preserve the resource names and format strings.
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) now emits file-local wide constants for the dialog/control resource names in `CollectionDialogPane.cpp`. This does not transfer payload ownership: `9X11FONT.BIN` and `FONTSYMB.*` stay shared UI font/symbol resources with collection call sites, not collection-private payloads.
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
- 2026-06-14 IDA MCP refresh in IDB `a001_goal2_class_batch` confirmed current helper bounds for `0x0056edc0` (`sub_56EDC0`, collection panel paint/list path), `0x0056fdd0` (`sub_56FDD0`, collection panel setup/asset path), `0x0048c640`, `0x0048d3a0`, `0x0048d4a0`, `0x0048dc30`, `0x0048dd60`, and `0x0048dff0` (detail dialog/control helper cluster).
- The same refresh confirmed `CLTINV.EPF` xrefs from `0x0056ee4c` and `0x0056fe0d`, `ITEMINV.EPD` xref from `0x004ea2f7`, and `ITEMINV.EPF` xrefs from `0x004ebbc7`, `0x004ec10c`, `0x004ee754`, and `0x004eea95`.
- Decompilation of `0x0056edc0` confirms `CLTINV.EPF` is drawn through the collection panel path before group progress rows are rendered; decompilation of `0x0048dff0` confirms the progress-label glyph path handles `/`, `%`, `(`, and `)` through the symbol resource route and draws numeric glyphs from the loaded 9x11 font table.

## Open Questions

- Locate `ITEMINV.EPD` in another distribution, loose resource source, or package version if the legacy inventory-frame branch must be rebuilt from original bytes.
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
| Completion | 89 | The page now documents the collection panel/detail-dialog resource split, exact read-only-data island, refreshed helper/xref evidence, source/resource contracts for panel, dialog, entry, progress, and shared text/symbol dependencies, `CLTVOL%d` format ownership, shared-resource exclusions, current DAT package provenance for the collection EPF/PAL/BIN resources, and the current negative `ITEMINV.EPD` package finding. It remains capped because broad shared font/symbol ownership, final `ITEMINV.*` placement, and visual per-frame semantics are still open. |
| Confidence | 93 | Confidence is very strong because current IDA xrefs, helper bounds, decompilation, owner modules, `.rdata` boundaries, DAT entry names, EPF headers, and palette headers support the documented resource consumers and ownership split. It is capped by unresolved shared-resource ownership and the missing current-package `ITEMINV.EPD` payload. |

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
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:80` / `CONFIDENCE:88` had the source/resource contract but lacked refreshed helper-bound and live decompilation evidence for the panel and progress-label resource paths.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:90` after current IDA MCP confirmed helper bounds, `CLTINV`/`ITEMINV` xrefs, `sub_56EDC0` collection panel drawing, and `sub_48DFF0` symbol/numeric glyph routing.
  - Remaining below gate: DAT archive ownership, payload frame layout, shared font/symbol ownership, and final `ITEMINV.*` placement remain open.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:90`, with code-facing resource identity but unresolved DAT payload provenance.
  - After: raised to `COMPLETION:89`, `CONFIDENCE:93`, with current `bint0.dat`/`bint1.dat`/`bint2.dat` entries for the collection EPF/PAL/BIN resources, `CLTVOL0` through `CLTVOL6` payload pairs, EPF frame-count/dimension headers, `DLPalette` evidence, and a negative current-package/loose-file finding for `ITEMINV.EPD`.
  - Evidence: fixed-table DAT parsing under `E:\2026\Resources\Read_Only\NexusTK\Data`.
- 2026-06-20 B001 Rule 26 read-only-data incorporation:
  - Summary/evidence: [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) now emits source-level file-local constants for the detail-dialog resource strings in `CollectionDialogPane.cpp`; this page preserves the resource payload boundary and keeps `9X11FONT.BIN` / `FONTSYMB.*` as shared UI dependencies rather than collection-private assets.
