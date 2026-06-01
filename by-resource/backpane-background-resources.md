*** UID:0001R7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BackPane Background Resources

## Status

- Confidence: strong for named palette strings; medium for exact frame resource names passed into `BackPane`.
- Related file: [UID:0000HO][BackPane](by-file/BackPane.md)
- Related classes: [UID:00000S][BackPane](by-class/BackPane.md), [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Used by | Notes |
| --- | --- | --- |
| `FRAME.PAL` | `BackPane::OnPaint` | EPF asset-mode palette for the root background frame. |
| `NPAL5.PAL` | `BackPane::OnPaint` and other legacy frame painters | Legacy/non-EPF palette for root background frame drawing. |
| `FRAME.EPF` | `InitializeMainUiGraph_004F7D10` EPF-mode `BackPane` setup | Resource pointer at `0x0061e100`; passed to the main UI graph setup before BackPane creation. |
| `FRAME.EPD` | `InitializeMainUiGraph_004F7D10` legacy-mode `BackPane` setup | Resource pointer at `0x0061e114`; passed to the main UI graph setup for the older resource path. |

## Frame Resource Inputs

`BackPane::BackPane` takes a `const wchar_t* frameFile` and passes it to the global EPF/resource layout table loader. `InitializeMainUiGraph_004F7D10` supplies different frame-resource pointers for EPF and legacy modes.

The generated recovered file names these pointers as `off_61E100` and `off_61E114`; IDA MCP direct string decoding resolves them to `FRAME.EPF` and `FRAME.EPD`.

## IDA MCP Evidence

- `0x0061304c` decodes as UTF-16 `FRAME.PAL`; xref `0x00467a12` lands in `0x004679e0-0x00467a48`.
- `0x00610fd0` decodes as UTF-16 `NPAL5.PAL`; xrefs include `0x00467a20` in `0x004679e0-0x00467a48` plus other shared legacy painters.
- `0x0061e100` decodes as UTF-16 `FRAME.EPF`; xref `0x004f7d76` lands in `0x004f7d10-0x004f8b2b`.
- `0x0061e114` decodes as UTF-16 `FRAME.EPD`; xref `0x004f856c` lands in `0x004f7d10-0x004f8b2b`.

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- Before: `off_61E100` and `off_61E114` were left as unresolved generated pointer names.
- Changed to: concrete `FRAME.EPF` and `FRAME.EPD` resource strings, with completion/confidence raised from `0/0` to `65/85`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061e100` and `0x0061e114`.
