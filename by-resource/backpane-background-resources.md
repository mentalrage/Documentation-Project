*** UID:0001R7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BackPane Background Resources

## Status

- Confidence: strong for named palette strings; medium for exact frame resource names passed into `BackPane`.
- Related file: [UID:0000HO][BackPane](by-file/BackPane.md)
- Related classes: [UID:00000S][BackPane](by-class/BackPane.md), [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks; generated sources are only lead material.
- Resource handling: rebuild packaging must provide both EPF/current-layout and EPD/legacy-layout frame resources plus the palette files used by the paint branch.
- Ownership status: resource consumers are documented well enough for reconstruction packaging; final asset payload verification remains outside this page.

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

## Frame Resource Inputs

`BackPane::BackPane` takes a `const wchar_t* frameFile` and passes it to the global EPF/resource layout table loader. `InitializeMainUiGraph_004F7D10` supplies different frame-resource pointers for EPF and legacy modes.

The generated recovered file names these pointers as `off_61E100` and `off_61E114`; IDA MCP direct string decoding resolves them to `FRAME.EPF` and `FRAME.EPD`.

## Consumer Map

| Consumer | Evidence | Notes |
| --- | --- | --- |
| [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) | BackPane constructor/paint island | Constructs the root backdrop pane and paints the frame through the active palette branch. |
| [UID:0000HO][BackPane](by-file/BackPane.md) | file ownership page | Records `BackPane::BackPane` consuming the constructor frame filename, initializing `EPFTileContext`, and `BackPane::OnPaint` selecting `FRAME.PAL` / `NPAL5.PAL`. |
| [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) | main UI graph setup item | Supplies the EPF-mode and legacy-mode frame-resource pointers before the root BackPane is attached under the main UI graph. |
| [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) / [UID:0000K2][ImageLib](by-file/ImageLib.md) | shared resource lookup owner | BackPane consumes the EPF/EPD registry; resource decoding and layout lookup stay with the image/resource library. |

## IDA MCP Evidence

- `0x0061304c` decodes as UTF-16 `FRAME.PAL`; xref `0x00467a12` lands in `0x004679e0-0x00467a48`.
- `0x00610fd0` decodes as UTF-16 `NPAL5.PAL`; xrefs include `0x00467a20` in `0x004679e0-0x00467a48` plus other shared legacy painters.
- `0x0061e100` decodes as UTF-16 `FRAME.EPF`; xref `0x004f7d76` lands in `0x004f7d10-0x004f8b2b`.
- `0x0061e114` decodes as UTF-16 `FRAME.EPD`; xref `0x004f856c` lands in `0x004f7d10-0x004f8b2b`.

## Reconstruction Notes

- Treat these as resource-packaging requirements, not source-authored C++ data.
- Keep `FRAME.EPF`/`FRAME.EPD` with the root BackPane construction path. Do not merge them with generic frame-part resources such as `FRMPART.EPF` or tab/chrome resources.
- Keep `FRAME.PAL` and `NPAL5.PAL` in the palette/resource inventory. `NPAL5.PAL` is shared by other legacy painters, so this page documents BackPane as a confirmed consumer rather than exclusive owner.
- The actual DAT payload bytes and frame counts are not audited here; this page documents names, consumers, and rebuild packaging role.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `72` | The page records the four confirmed resource names, EPF/legacy branches, consumers, resource lookup ownership, IDA string/xref evidence, packaging notes, and caveats. Completion remains capped because payload-level asset contents and all shared `NPAL5.PAL` consumers are not fully audited here. |
| Confidence `88` | IDA-backed UTF-16 decoding and xrefs strongly identify the resource names and BackPane consumer paths. Confidence remains below final-audit range because exact asset payload formats/frame IDs are not documented on this page. |

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- Before: `off_61E100` and `off_61E114` were left as unresolved generated pointer names.
- Changed to: concrete `FRAME.EPF` and `FRAME.EPD` resource strings, with completion/confidence raised from `0/0` to `65/85`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061e100` and `0x0061e114`.
- 2026-06-02: Raised from `65/85` to `72/88`.
  - Before: the page named the resources but had limited reconstruction packaging and consumer mapping.
  - After: it records EPF/legacy branch roles, consumer map, resource lookup ownership, packaging caveats, and score rationale.
