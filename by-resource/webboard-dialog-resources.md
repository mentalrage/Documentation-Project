*** UID:0001RT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WebBoard Dialog Resources

## Status

- Confidence: strong for `WEBBOARD.EPD` / `WEBBOARD.PAD` use by [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md); medium for final resource-file grouping.
- Owner hypothesis: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)

## Resource Use

| Resource | Observed owner | Notes |
| --- | --- | --- |
| `WEBBOARD.EPD` | [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Fixed-art background image control and dialog resource loaded during the old constructor at `0x0046e640`. |
| `WEBBOARD.PAD` | [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Palette/companion art passed with the old background image control constructor. |

## Evidence

- IDA MCP decompilation of `0x0046e640` shows a fixed background rectangle `(0,0)-(540,379)`, `WEBBOARD.EPD`, and `WEBBOARD.PAD`.
- The old constructor also loads `WEBBOARD.EPD` before setting dialog bounds `(50,50)-(590,429)`.
- Ranking UI uses similarly named `WEBBOARD.EPF` / `WEBBOARD.PAL` frame tiles, but the old web-board dialog specifically uses `EPD` / `PAD` fixed-art resources.

## IDA MCP Evidence

- ASCII `WEBBOARD.PAD` was verified at `0x00613ae4`, with an xref from `0x0046e718` inside `0x0046e640-0x0046e8be`.
- ASCII `WEBBOARD.EPD` was verified at `0x00613b00`, with xrefs from `0x0046e725` and `0x0046e803` inside the same constructor.
- IDA decompilation of `0x0046e640-0x0046e8be` constructs the background rectangle `(0,0)-(540,379)`, calls the image-control constructor with `L"WEBBOARD.EPD"` and `L"WEBBOARD.PAD"`, then calls the dialog background/load path again with `L"WEBBOARD.EPD"` before setting bounds `(50,50)-(590,429)`.

## Cross-References

- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

- What existed before: the page had a strong evidence summary but was scored unevaluated.
- Changed to: scored `COMPLETION:78` / `CONFIDENCE:90` and added concrete string/xref/decompilation evidence.
- Summary and evidence: IDA directly confirms the `WEBBOARD.EPD` / `WEBBOARD.PAD` old dialog path and distinguishes it from ranking UI `WEBBOARD.EPF` / `WEBBOARD.PAL`; score remains below final because final source-file grouping is still marked as a hypothesis.
