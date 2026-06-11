*** UID:0001RT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Old fixed-art shell | `WebBoardDialogOld` owns singleton setup, browser-control creation, close control creation, packet/timer startup, bounds `(50,50)-(590,429)`, and the fixed background rectangle `(0,0)-(540,379)`. | `WEBBOARD.EPD` owns the legacy fixed background image payload. |
| Palette companion | The old constructor owns when the background image control is created and how it is placed behind the browser control. | `WEBBOARD.PAD` owns the companion palette/art data passed with the fixed background control. |
| Browser content | Active and old WebBoard source owns URL escaping, cookies, board response parsing, browser navigation, and embedded `BrowserControlPane` positioning. | Browser HTML/content payloads and URL strings are not fixed-art WebBoard resources and stay with browser/packet documentation. |
| Ranking collision | Ranking dialogs own their event-list/reward/web-ranking frame layout and resource lookups. | Ranking `WEBBOARD.EPF`/`WEBBOARD.PAL` are separate assets from old WebBoard `WEBBOARD.EPD`/`WEBBOARD.PAD`. |

## Boundary Rules

- Keep this page scoped to the old fixed-art WebBoard dialog resources. Active browser-backed WebBoard behavior has no proven `WEBBOARD.EPD` / `WEBBOARD.PAD` dependency in the current page evidence.
- Do not merge these resources with [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md). The shared base name is a collision, but the extensions, consumers, and UI roles differ.
- Do not move `WebBoardDialogOld` into [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) just because generated output currently places old helpers there; owner evidence belongs to [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
- Browser infrastructure remains with [UID:0000HV][Browser](by-file/Browser.md), [UID:000019][BrowserPane](by-class/BrowserPane.md), and [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md). This resource page only records fixed-art background and palette dependencies.

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
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now records verified `WEBBOARD.EPD`/`WEBBOARD.PAD` strings, xrefs, old-constructor rectangles, source/resource ownership, ranking-name collision rules, generated RankingDialog pollution boundary, browser infrastructure exclusion, and owner links. It remains below high completion because final resource-file grouping and active-versus-old source split are still hypotheses. |
| Confidence | 90 | The fixed-art resource strings, xrefs, constructor use, and old WebBoard owner are IDA-backed in existing evidence. Confidence is capped by unresolved original file grouping and broader asset packaging questions. |

## Changes

- What existed before: the page had a strong evidence summary but was scored unevaluated.
- Changed to: scored `COMPLETION:78` / `CONFIDENCE:90` and added concrete string/xref/decompilation evidence.
- Summary and evidence: IDA directly confirms the `WEBBOARD.EPD` / `WEBBOARD.PAD` old dialog path and distinguishes it from ranking UI `WEBBOARD.EPF` / `WEBBOARD.PAL`; score remains below final because final source-file grouping is still marked as a hypothesis.
- 2026-06-07 A002 source/resource boundary pass:
  - Before: the page identified the fixed-art resources and ranking-name collision, but did not state source-owned behavior versus asset data or exclude browser infrastructure explicitly.
  - After: raised to `COMPLETION:80` with source/resource contracts, ranking collision rules, generated RankingDialog ownership correction, browser exclusion boundaries, and score rationale.
