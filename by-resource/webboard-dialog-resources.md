*** UID:0001RT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WebBoard Dialog Resources

## Status

- Confidence: very strong for `WEBBOARD.EPD` / `WEBBOARD.PAD` use by [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md); medium for final resource-file grouping.
- Canonical owner: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)

## Resource Use

| Resource | Observed owner | Notes |
| --- | --- | --- |
| `WEBBOARD.EPD` | [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Fixed-art background image control and dialog resource loaded during the old constructor at `0x0046e640`. |
| `WEBBOARD.PAD` | [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Palette/companion art passed with the old background image control constructor. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format across the current 250 DAT archives and checked for loose files under the same client tree. No current DAT entry or loose file named `WEBBOARD.EPD` or `WEBBOARD.PAD` was found.

The current package does contain basename-colliding WebBoard art in `bint2.dat`: `wboardbk.epf` at entry index `123` / size `26,428`, `wboardbk.pal` at index `124` / size `1,056`, `webboard.epf` at index `125` / size `10,780`, and `webboard.pal` at index `126` / size `1,056`. Those entries support the ranking/shared-webboard collision boundary already documented below, and B002 2026-06-17 confirms BrowserDialog/WebBoardDialog draw helpers consume the EPF/PAL family through `off_60DB5C`/`off_60DB78` and `off_60DB94`/`off_60DBB0`. They still do not satisfy the old constructor's `WEBBOARD.EPD` / `WEBBOARD.PAD` operands. Treat the old fixed-art payloads as version-specific, unpacked elsewhere, or omitted from this current package until another distribution proves their archive location.

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Old fixed-art shell | `WebBoardDialogOld` owns singleton setup, browser-control creation, close control creation, packet/timer startup, bounds `(50,50)-(590,429)`, and the fixed background rectangle `(0,0)-(540,379)`. | `WEBBOARD.EPD` owns the legacy fixed background image payload, but the current package audit did not find that entry. |
| Palette companion | The old constructor owns when the background image control is created and how it is placed behind the browser control. | `WEBBOARD.PAD` owns the companion palette/art data passed with the fixed background control, but the current package audit did not find that entry. |
| Browser content | Active and old WebBoard source owns URL escaping, cookies, board response parsing, browser navigation, and embedded `BrowserControlPane` positioning. | Browser HTML/content payloads and URL strings are not fixed-art WebBoard resources and stay with browser/packet documentation. |
| URL escape helper code | [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) owns old WebBoard URL percent-escape source behavior under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). | The helper's state/charset bytes are support data, not `WEBBOARD.EPD` / `WEBBOARD.PAD` fixed-art resource payloads. |
| Ranking collision | Ranking dialogs own their event-list/reward/web-ranking frame layout and resource lookups. | Ranking `WEBBOARD.EPF`/`WEBBOARD.PAL` are separate assets from old WebBoard `WEBBOARD.EPD`/`WEBBOARD.PAD`. |
| Browser/WebBoard draw helpers | BrowserDialog and active WebBoardDialog own their draw methods and virtual callbacks. | `WBOARDBK.EPF`/`WBOARDBK.PAL` and `WEBBOARD.EPF`/`WEBBOARD.PAL` are shared EPF/PAL board-frame assets used by those draw helpers; this does not merge them with old `WEBBOARD.EPD`/`WEBBOARD.PAD` or move callback ownership to Ranking. |

## Boundary Rules

- Keep this page scoped to the old fixed-art WebBoard dialog resources. Active browser-backed WebBoard behavior has no proven `WEBBOARD.EPD` / `WEBBOARD.PAD` dependency in the current page evidence.
- Do not merge these resources with [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md). The shared base name is a collision, but the extensions, consumers, and UI roles differ.
- Do not move `WebBoardDialogOld` into [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) just because generated output currently places old helpers there; owner evidence belongs to [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
- Browser infrastructure remains with [UID:0000HV][Browser](by-file/Browser.md), [UID:000019][BrowserPane](by-class/BrowserPane.md), and [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md). This resource page only records fixed-art background and palette dependencies.

## Evidence

- IDA MCP decompilation of `0x0046e640` shows a fixed background rectangle `(0,0)-(540,379)`, `WEBBOARD.EPD`, and `WEBBOARD.PAD`.
- The old constructor also loads `WEBBOARD.EPD` before setting dialog bounds `(50,50)-(590,429)`.
- Ranking UI uses similarly named `WEBBOARD.EPF` / `WEBBOARD.PAL` frame tiles, but the old web-board dialog specifically uses `EPD` / `PAD` fixed-art resources.
- B002 2026-06-17 reanalysis ties `WBOARDBK.EPF`/`WBOARDBK.PAL` to BrowserDialog `DrawContentArea` / active WebBoard `DrawContentArea`, and `WEBBOARD.EPF`/`WEBBOARD.PAL` to BrowserDialog `DrawFrameChrome` / active WebBoard `DrawFrameChrome`. These EPF/PAL consumers are separate from the old constructor's `WEBBOARD.EPD`/`WEBBOARD.PAD` fixed-art path.
- B005 2026-06-19 constructor/source-quality execution keeps that resource split active while resolving stale WebBoardDialog draw-helper blockers: [UID:0003V3][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md) should refer to `WBOARDBK.EPF` / `WBOARDBK.PAL`, and [UID:0003V4][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md) should refer to `WEBBOARD.EPF` / `WEBBOARD.PAL`. These accepted names do not merge the active EPF/PAL draw assets with the old fixed-art `WEBBOARD.EPD` / `WEBBOARD.PAD` operands.
- B008 2026-06-19 class source-quality reanalysis reconfirms `WEBBOARD.PAD` at `0x00613ae4` and `WEBBOARD.EPD` at `0x00613b00` as old-only fixed-art resources used by [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md). This supports [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) remaining in [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), not [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) or generic Browser ownership.

## IDA MCP Evidence

- ASCII `WEBBOARD.PAD` was verified at `0x00613ae4`, with an xref from `0x0046e718` inside `0x0046e640-0x0046e8be`.
- ASCII `WEBBOARD.EPD` was verified at `0x00613b00`, with xrefs from `0x0046e725` and `0x0046e803` inside the same constructor.
- IDA decompilation of `0x0046e640-0x0046e8be` constructs the background rectangle `(0,0)-(540,379)`, calls the image-control constructor with `L"WEBBOARD.EPD"` and `L"WEBBOARD.PAD"`, then calls the dialog background/load path again with `L"WEBBOARD.EPD"` before setting bounds `(50,50)-(590,429)`.
- 2026-06-14 IDA MCP refresh in active `NexusTK.exe` confirmed `0x0046e640` as `sub_46E640` with size `0x27e`, `0x0046eaa0` as the old response handler with size `0x3da`, and the current xrefs for `WEBBOARD.PAD` (`0x0046e718`) and `WEBBOARD.EPD` (`0x0046e725`, `0x0046e803`) all inside the old constructor.
- The refreshed decompilation shows `WebBoardDialogOld` installing browser-pane then old-dialog vtables, storing the old singleton, constructing the `WEBBOARD.EPD` / `WEBBOARD.PAD` fixed-art background, creating the close button and browser control, loading `WEBBOARD.EPD` as the dialog background, and sending opcode `0x73` plus timer `0x572` when no direct payload or URL is supplied.
- 2026-06-14 continuation xref check reconfirmed `WEBBOARD.PAD` has exactly one current data xref and `WEBBOARD.EPD` has exactly two current data xrefs, all in `sub_46E640`; no current evidence routes these resources through RankingDialog despite the `WEBBOARD` basename collision.

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
| Completion | 87 | The page records verified `WEBBOARD.EPD`/`WEBBOARD.PAD` strings, exact current xref counts, old-constructor decompilation, fixed-art/browser-control geometry, source/resource ownership, ranking-name collision rules, generated RankingDialog pollution boundary, browser infrastructure exclusion, owner links, and current-package positive/negative asset provenance. It remains capped because the code-referenced legacy `EPD`/`PAD` payloads are not present in the audited package and the active-versus-old source split is still partly hypothetical. |
| Confidence | 92 | The fixed-art resource strings, xrefs, constructor use, WebBoardDialog canonical owner, and current `bint2.dat` basename-collision entries are backed by refreshed IDA xref/decompilation evidence, parent/class docs, and package parsing. Confidence is capped by the missing current-package `WEBBOARD.EPD`/`WEBBOARD.PAD` payloads. |

## Changes

- 2026-06-21 B008 old-class resource-boundary sync:
  - Added the class-report confirmation that `WEBBOARD.EPD`/`WEBBOARD.PAD` are old-only fixed-art constructor resources for [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), preserving [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) ownership and RankingDialog/Browser exclusions.

- 2026-06-20 B004 [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) source/resource boundary sync:
  - Added a source/resource contract row clarifying that `EscapeOldWebBoardUrl` is WebBoardDialog source behavior and not fixed-art WebBoard resource payload.
  - Summary/evidence: old URL escape state/charset data support code emission in [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md); they do not alter the `WEBBOARD.EPD` / `WEBBOARD.PAD` resource boundary.

- 2026-06-17 B002 Browser/WebBoard virtual companion execution:
  - Added BrowserDialog and active WebBoardDialog EPF/PAL draw-helper consumer notes while keeping this page scoped to the old fixed-art `WEBBOARD.EPD`/`WEBBOARD.PAD` boundary.
  - Preserved the collision rule: active/shared `WEBBOARD.EPF/PAL` and old `WEBBOARD.EPD/PAD` are different resource families despite similar names.

- 2026-06-19 B005 constructor/source-quality execution:
  - Added support confirmation that stale resource-name blockers in the active draw helper docs are resolved to `WBOARDBK.EPF`/`WBOARDBK.PAL` for content/background and `WEBBOARD.EPF`/`WEBBOARD.PAL` for frame/chrome, while keeping the old fixed-art `WEBBOARD.EPD`/`WEBBOARD.PAD` boundary intact.

- What existed before: the page had a strong evidence summary but was scored unevaluated.
- Changed to: scored `COMPLETION:78` / `CONFIDENCE:90` and added concrete string/xref/decompilation evidence.
- Summary and evidence: IDA directly confirms the `WEBBOARD.EPD` / `WEBBOARD.PAD` old dialog path and distinguishes it from ranking UI `WEBBOARD.EPF` / `WEBBOARD.PAL`; score remains below final because final source-file grouping is still marked as a hypothesis.
- 2026-06-07 A002 source/resource boundary pass:
  - Before: the page identified the fixed-art resources and ranking-name collision, but did not state source-owned behavior versus asset data or exclude browser infrastructure explicitly.
  - After: raised to `COMPLETION:80` with source/resource contracts, ranking collision rules, generated RankingDialog ownership correction, browser exclusion boundaries, and score rationale.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:80` / `CONFIDENCE:90` documented the old fixed-art resources but still treated current function/xref evidence as older support.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:91` after refreshed IDA MCP confirmed the old constructor bounds, `WEBBOARD.EPD`/`WEBBOARD.PAD` xrefs, fixed background and browser-control construction, dialog background reload, and request/timer fallback path.
  - Remaining below higher score: final resource-file grouping and exact active-versus-old source split remain open.
- 2026-06-14 A002 Goal2 continuation:
  - What existed before: `CANONICAL_OWNER:NONE` despite the page and parent docs identifying [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) as the semantic owner.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:92` and `CANONICAL_OWNER:0000P9` after a direct xref-count refresh reconfirmed the fixed-art resource references are confined to `sub_46E640` and the direct owner page clears the 85/85 gate.
  - No emitter or proposed path fields apply to by-resource pages.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:86` / `CONFIDENCE:92` with archive/package provenance still open.
  - Changed to: `COMPLETION:87` / `CONFIDENCE:92`.
  - Evidence: current DAT table parsing found `webboard.epf`, `webboard.pal`, `wboardbk.epf`, and `wboardbk.pal` in `bint2.dat`, but found no `WEBBOARD.EPD` or `WEBBOARD.PAD` DAT entry or loose file in the audited client tree. This improves the resource-boundary evidence while preserving the unresolved legacy-payload blocker.
