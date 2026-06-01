*** UID:0001RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Exchange Dialog Resources

## Status

- Resource family: player exchange/trade dialog UI
- Owner module: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Confidence: strong from IDA MCP resource string decoding and xrefs.

## Resource Set

| Resource | Observed owner/use |
| --- | --- |
| `DLGEXC1.EPF` | Main player exchange dialog layout/background resource loaded by `ExchangeDialog`. |
| `DLGEXC1.PAL` | Palette passed when creating the exchange dialog background image. |

## Evidence Notes

- `ExchangeDialog::ExchangeDialog` creates a `451x371` background image with `DLGEXC1.EPF` and `DLGEXC1.PAL`, then loads the same dialog resource through `LoadDialogResource`.
- The layout places action buttons at the bottom, player labels near the top, item-list scroll panes in the middle, and money controls at y=295.
- `ExchangeAlertPane` uses text/button controls and dynamic sizing rather than a fixed EPF resource in current generated output.

## IDA MCP Evidence

- `0x0061a304` decodes as UTF-16 `DLGEXC1.PAL`; xref `0x004ac9d2` lands in `0x004ac8a0-0x004ad0aa`.
- `0x0061a31c` decodes as UTF-16 `DLGEXC1.EPF`; xrefs `0x004ac9e2` and `0x004acf8a` land in `0x004ac8a0-0x004ad0aa`.
- No IDA evidence in this pass supported the previous `DL_20` / `DL_20.PAL` resource names for this page.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)

## Changes

- Before: resource rows named `DL_20` and `DL_20.PAL`.
- Changed to: `DLGEXC1.EPF` and `DLGEXC1.PAL`; score set to `70/88`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061a304` and `0x0061a31c`.
