*** UID:0001R7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BackPane Background Resources

## Status

- Confidence: very strong for named palette strings, frame resource pointers, branch routing, BackPane consumer paths, current-package `FRAME.EPF`/palette provenance, and current all-DAT/loose/executable-literal availability checks; medium for the absent legacy `FRAME.EPD` payload.
- Related file: [UID:0000HO][BackPane](by-file/BackPane.md)
- Related classes: [UID:00000S][BackPane](by-class/BackPane.md), [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks; generated sources are only lead material.
- Resource handling: rebuild packaging must provide both EPF/current-layout and EPD/legacy-layout frame resources plus the palette files used by the paint branch.
- Ownership status: resource consumers and current package payload provenance are documented well enough for reconstruction packaging; the legacy `FRAME.EPD` payload remains unresolved for this audited distribution.

## Confirmed Resources

| Resource | Used by | Notes |
| --- | --- | --- |
| `FRAME.PAL` | `BackPane::OnPaint` | EPF asset-mode palette for the root background frame. |
| `NPAL5.PAL` | `BackPane::OnPaint` and other legacy frame painters | Legacy/non-EPF palette for root background frame drawing. |
| `FRAME.EPF` | `InitializeMainUiGraph_004F7D10` EPF-mode `BackPane` setup | Resource pointer at `0x0061e100`; passed to the main UI graph setup before BackPane creation. |
| `FRAME.EPD` | `InitializeMainUiGraph_004F7D10` legacy-mode `BackPane` setup | Resource pointer at `0x0061e114`; passed to the main UI graph setup for the older resource path. |

## Resource Roles

| Resource | Branch | Reconstruction handling |
| --- | --- | --- |
| `FRAME.EPF` | current/EPF asset branch | Package as the current root backdrop frame archive consumed by [UID:0000HO][BackPane](by-file/BackPane.md) construction through `InitializeMainUiGraph_004F7D10`. |
| `FRAME.EPD` | legacy asset branch | Package as the legacy root backdrop frame archive passed into the same BackPane construction path when the older layout/resource mode is selected. |
| `FRAME.PAL` | current/EPF paint branch | Package with the current root backdrop palette used by `BackPane::OnPaint`. |
| `NPAL5.PAL` | legacy/shared paint branch | Package with legacy frame painters; `BackPane::OnPaint` is one confirmed consumer. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked the current tree for loose matching files. The current package contains the EPF-mode background and both palette operands, but not the legacy `.EPD` operand.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `FRAME.EPF` | `bint1.dat`, entry index `78`, offset `7,716,660`, size `794,928` bytes. | EPF header begins `01 00 00 04 00 03`, consistent with one `1024x768` frame payload for the root background. |
| `FRAME.PAL` | `bint1.dat`, entry index `79`, offset `8,511,588`, size `1,056` bytes. | Payload begins with the `DLPalette` header. |
| `NPAL5.PAL` | `bint2.dat`, entry index `47`, offset `9,158,767`, size `1,056` bytes. | Payload begins with the `DLPalette` header; this remains a shared legacy palette, not BackPane-private data. |
| `FRAME.EPD` | No matching DAT entry or loose file found in the audited current tree. | Keep the legacy branch documented from IDA string/xref evidence, but treat the payload as absent from this distribution. |

2026-06-16 A002 rechecked the current archive/loose/executable evidence using the documented 17-byte DAT entry records. Exact DAT entry matches remain limited to `bint1.dat` `frame.epf` index `78` offset `7,716,660` size `794,928`, `bint1.dat` `frame.pal` index `79` offset `8,511,588` size `1,056`, and `bint2.dat` `NPAL5.PAL` index `47` offset `9,158,767` size `1,056`. The EPF and palette headers still match the earlier audit, no loose `FRAME.*` or `NPAL5.PAL` files exist under `E:\2026\Resources`, and no exact `FRAME.EPD` DAT entry exists in the current archive set. `FRAME.EPD` appears in the three packaged executables only as UTF-16 literals at raw offsets `2,193,174`, `2,214,676`, and `2,281,062`.

## Frame Resource Inputs

`BackPane::BackPane` takes a `const wchar_t* frameFile` and passes it to the global EPF/resource layout table loader. `InitializeMainUiGraph_004F7D10` supplies different frame-resource pointers for EPF and legacy modes.

The generated recovered file previously left the two resource-pointer labels unnamed at `0x0061e100` and `0x0061e114`; IDA MCP direct string decoding resolves them to `FRAME.EPF` and `FRAME.EPD`.

## Runtime Branch Matrix

| Runtime branch | Constructor resource | Paint palette | Rebuild implication |
| --- | --- | --- | --- |
| EPF/current asset mode | `FRAME.EPF` from `InitializeMainUiGraph_004F7D10` | `FRAME.PAL` in `BackPane::OnPaint` | Ship the current root backdrop archive with its palette and preserve the BackPane constructor path that registers it through the resource layout table. |
| Legacy/non-EPF asset mode | `FRAME.EPD` from `InitializeMainUiGraph_004F7D10` | `NPAL5.PAL` in `BackPane::OnPaint` | Ship the legacy root backdrop archive and keep `NPAL5.PAL` available as a shared legacy palette, not as BackPane-private data. |

Both branches construct the root [UID:0000HO][BackPane](by-file/BackPane.md) under the main UI graph. The branch split is resource selection, not a separate pane ownership model.

## Source/Resource Contract

| Contract point | Source-owned behavior | Resource-owned payload | Notes |
| --- | --- | --- | --- |
| Root pane construction | `InitializeMainUiGraph_004F7D10` chooses the current or legacy frame filename and constructs the singleton `BackPane`. | `FRAME.EPF` / `FRAME.EPD` frame archives. | Keep the branch and constructor argument in source; keep frame bytes in resource packaging. |
| Tile-frame registration | `BackPane::BackPane` initializes its `EPFTileContext` and registers the selected frame resource through the layout/resource table. | Frame layouts, tiles, and dimensions supplied by the frame archive. | Resource decoding remains with `ResourceLayoutTable`, `ImageLib`, and `EPFTileContext`. |
| Paint palette choice | `BackPane::OnPaint` branches on the asset-mode flag and passes the selected palette to the draw path. | `FRAME.PAL` for current mode; `NPAL5.PAL` for legacy/shared mode. | `NPAL5.PAL` is not BackPane-private because other legacy painters consume it. |
| Root backdrop ownership | `BackPane.cpp` owns the root backdrop pane and `g_pBackPane` lifecycle. | No C++ array copy of the frame/palette data. | Map rendering, dialog chrome, alert frames, and tab chrome remain separate resource families. |

## Consumer Map

| Consumer | Evidence | Notes |
| --- | --- | --- |
| [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) | BackPane constructor/paint island | Constructs the root backdrop pane and paints the frame through the active palette branch. |
| [UID:0000HO][BackPane](by-file/BackPane.md) | file ownership page | Records `BackPane::BackPane` consuming the constructor frame filename, initializing `EPFTileContext`, and `BackPane::OnPaint` selecting `FRAME.PAL` / `NPAL5.PAL`. |
| [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) | main UI graph setup item | Supplies the EPF-mode and legacy-mode frame-resource pointers before the root BackPane is attached under the main UI graph. |
| [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) / [UID:0000K2][ImageLib](by-file/ImageLib.md) | shared resource lookup owner | BackPane consumes the EPF/EPD registry; resource decoding and layout lookup stay with the image/resource library. |

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms the four documented resource literals and their BackPane/main-UI setup routes.
- `0x0061304c` decodes as UTF-16 `FRAME.PAL`; one xref, `0x00467a12`, lands in `sub_4679E0` / `BackPane::OnPaint` (`0x004679e0`, size `0x68`).
- `0x00610fd0` decodes as UTF-16 `NPAL5.PAL`; four xrefs were observed, including the BackPane paint xref `0x00467a20` plus shared legacy frame/status painters at `0x0046169d`, `0x005b9519`, and `0x005be938`.
- `0x0061e100` decodes as UTF-16 `FRAME.EPF`; one xref, `0x004f7d76`, lands in `sub_4F7D10` / `InitializeMainUiGraph_004F7D10` (`0x004f7d10`, size `0xe1b`).
- `0x0061e114` decodes as UTF-16 `FRAME.EPD`; one xref, `0x004f856c`, lands in the same main-UI graph setup function.

## Reconstruction Notes

- Treat these as resource-packaging requirements, not source-authored C++ data.
- Keep `FRAME.EPF`/`FRAME.EPD` with the root BackPane construction path. Do not merge them with generic frame-part resources such as `FRMPART.EPF` or tab/chrome resources.
- Keep `FRAME.PAL` and `NPAL5.PAL` in the palette/resource inventory. `NPAL5.PAL` is shared by other legacy painters, so this page documents BackPane as a confirmed consumer rather than exclusive owner.
- The current `FRAME.EPF`, `FRAME.PAL`, and `NPAL5.PAL` DAT payloads are audited here; legacy `FRAME.EPD` remains an IDA-referenced but currently absent package payload.

## Rebuild Packaging Boundary

- Package the four named resources as external art assets required by the BackPane startup path.
- Keep source reconstruction limited to the string constants, branch selection, `BackPane` constructor call, and `OnPaint` palette choice.
- Leave EPF/EPD decoding, palette loading, and frame lookup with [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), and [UID:00004I][EPFTileContext](by-class/EPFTileContext.md).
- Do not treat `FRAME.PAL` as proof that `NPAL5.PAL` can be dropped. The legacy path and other shared painters still need separate consumer review.

## Scope Boundaries

- This page covers the root background frame resources consumed by BackPane. It does not claim ownership of dialog frames, tab chrome, alert frames, or frame-part sprites.
- `NPAL5.PAL` is documented here only as a confirmed BackPane legacy-paint dependency. Full shared-palette inventory belongs in broader palette/resource coverage.
- `FRAME.EPF` and `FRAME.EPD` are named from string/xref evidence; current `FRAME.EPF` package placement and one-frame dimensions are audited here, while legacy `FRAME.EPD` payload provenance remains open.
- The `BackGroundPane` class belongs in the same source file, but this resource page is specifically about the root `BackPane` frame/palette resources. BackGroundPane-specific resources should stay with its read-only data/resource evidence if later split out.
- Help popup helpers may anchor against BackPane bounds, but they do not consume `FRAME.EPF`, `FRAME.EPD`, `FRAME.PAL`, or `NPAL5.PAL` directly.

## Open Questions

- Exact frame indices and palette expectations inside the large `FRAME.EPF` payload, beyond its one-frame `1024x768` header.
- Payload provenance for legacy `FRAME.EPD` in another distribution or loose resource source.
- Semantic/visual audit of the three non-BackPane `NPAL5.PAL` code consumers at `0x0046169d`, `0x005b9519`, and `0x005be938`; IDA xrefs prove the current code list, but those consumers still need source-level palette-role documentation outside this BackPane page.
- Whether current and legacy frame archives ship in the same DAT family in every observed package layout.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page records the four confirmed resource names, EPF/legacy branches, constructor and paint resource split, consumers, resource lookup ownership, refreshed IDA string/xref evidence, rebuild packaging boundary, source/resource contract, scope boundaries, current DAT provenance for `FRAME.EPF`, `FRAME.PAL`, and `NPAL5.PAL`, exact all-DAT negative evidence for `FRAME.EPD`, and executable-literal-only evidence for the missing legacy operand. Completion remains capped because legacy `FRAME.EPD` is absent from the audited package, internal frame-index/palette expectations are not fully decoded, and the shared `NPAL5.PAL` consumers need semantic audit outside this page. |
| Confidence `92` | Fresh IDA xrefs identify the frame/palette literals, BackPane paint function, and main-UI setup route; A002 package parsing proves the current EPF/palette payload locations and headers; and the 2026-06-16 all-DAT/loose/executable scan strengthens the negative `FRAME.EPD` provenance. Confidence remains below final-audit range because the legacy payload was not found and exact asset-frame semantics are still not fully documented. |

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- Before: two generated pointer labels for the resources at `0x0061e100` and `0x0061e114` were left unresolved.
- Changed to: concrete `FRAME.EPF` and `FRAME.EPD` resource strings, with completion/confidence raised from `0/0` to `65/85`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061e100` and `0x0061e114`.
- 2026-06-02: Raised from `65/85` to `72/88`.
  - Before: the page named the resources but had limited reconstruction packaging and consumer mapping.
  - After: it records EPF/legacy branch roles, consumer map, resource lookup ownership, packaging caveats, and score rationale.
- 2026-06-07 A002 branch/packaging pass: Raised from `72/88` to `76/88`.
  - Before: the page had the named resources and consumer map but did not separate constructor archive selection from paint palette selection in a compact runtime matrix.
  - After: it records current versus legacy resource branches, rebuild packaging boundaries, shared-resource scope limits, explicit open questions, and the current-session IDA availability caveat.
- 2026-06-07 A002 source/resource contract pass:
  - Before: `COMPLETION:76`, with branch and packaging boundaries documented but no explicit contract table for construction, tile-frame registration, paint palette choice, and root backdrop ownership.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, with a source/resource contract matrix and tighter exclusions for BackGroundPane-specific resources and help popup helpers.
  - Summary/evidence: [UID:0000HO][BackPane](by-file/BackPane.md), [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), and existing IDA-backed resource string/xref notes support the constructor resource branch, `EPFTileContext` registration, paint-palette branch, and root BackPane ownership.
- 2026-06-14 A003 score refresh: Raised completion/confidence from `78/88` to `85/90` after live IDA MCP xrefs reconfirmed `FRAME.PAL`, `NPAL5.PAL`, `FRAME.EPF`, and `FRAME.EPD`; `NPAL5.PAL` remains shared, and frame payload details, DAT placement, and full shared-palette inventory remain below-final blockers.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:90`, with current IDA resource-string evidence but no DAT payload audit on the page.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:91`, with current package provenance for `FRAME.EPF`, `FRAME.PAL`, and `NPAL5.PAL`, plus a negative current-package/loose-file finding for `FRAME.EPD`.
  - Evidence: fixed-table DAT parsing of `bint1.dat` and `bint2.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`; `FRAME.EPF` has a one-frame `1024x768` EPF header and both palettes begin with `DLPalette`.
- 2026-06-16 A002 item/resource completion refresh:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:NONE` remains correct because this is a resource-boundary/provenance page, not a source owner or emitter.
  - Evidence: current all-DAT scan using documented `DATEntryRecord` layout found exact entries only for `frame.epf`, `frame.pal`, and `NPAL5.PAL`; loose-resource search found no standalone `FRAME.*`/`NPAL5.PAL`; executable UTF-16 scan found `FRAME.EPD` only as literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`; live IDA MCP reconfirmed the BackPane paint, main-UI setup, and `NPAL5.PAL` xrefs.
