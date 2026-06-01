*** UID:0001RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerPane Number Resources

## Status

- Confidence: strong for resource names and call site; medium for exact frame atlas layout.
- Related file: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Related class: [UID:0000F3][TimerPane](by-class/TimerPane.md)
- Evidence basis: IDA MCP decompile/string checks.

## Confirmed Resources

| Resource | String address | Used by | Notes |
| --- | --- | --- | --- |
| `NUMBER.EPF` | `0x00670294` | `TimerPane::DrawDigit` | Used when `byte_66DA97 == 1`, the EPF/new asset mode branch. |
| `NUMBER.EPD` | `0x006702ac` | `TimerPane::DrawDigit` | Used by the legacy/non-EPF branch. |

## Frame Semantics

`TimerPane::DrawDigit` passes a frame index to the resource layout table:

- indexes `0..9` are numeric digits;
- index `10` is the colon frame used in `MM:SS` and `HH:MM:SS`;
- each slot advances by `35` pixels;
- the pane height is `70` pixels.

The constructor chooses display width from the display format:

| Display format | Slots | Visual form |
| --- | --- | --- |
| `0` | `2` | `SS` |
| `1` | `5` | `MM:SS` |
| `2` | `8` | `HH:MM:SS` |

## IDA MCP Evidence

- ASCII `NUMBER.EPF` was verified at `0x00670294`, with an xref from `0x00598b6e` inside `0x00598b40-0x00598bd5`.
- ASCII `NUMBER.EPD` was verified at `0x006702ac`, with an xref from `0x00598b7f` inside the same draw helper.
- IDA decompilation of `0x00598b40-0x00598bd5` checks `byte_66DA97 == 1`, then calls the resource layout renderer with `aNumberEpf` in the new/EPF branch and `aNumberEpd` in the legacy branch, passing the digit/frame index argument through unchanged.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- What existed before: the page was scored unevaluated and used generated `simroot_v2` as part of the evidence basis.
- Changed to: scored `COMPLETION:72` / `CONFIDENCE:88`, removed generated-source evidence wording, and added direct IDA MCP resource/xref/decompile evidence.
- Summary and evidence: the digit resource selection is verified in `0x00598b40`; score remains below final because the atlas frame layout has not been exhaustively checked against the asset data.
