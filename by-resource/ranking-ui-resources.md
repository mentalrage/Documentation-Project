*** UID:0001RK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ranking UI Resources

## Status

- Resource family: ranking board, event list, reward dialog, and custom scroll controls
- Owner module: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: very strong from refreshed IDA string/xref routing plus current DAT package provenance; medium for complete shared-resource consumer inventories.

## Resource Set

| Resource | Observed owner/use |
| --- | --- |
| `WBOARDBK.EPF` / `WBOARDBK.PAL` | Ranking dialog/user-list/reward-dialog tiled background fill; also consumed by BrowserDialog/WebBoardDialog content/background draw helpers. |
| `WEBBOARD.EPF` / `WEBBOARD.PAL` | Ranking and reward dialog border frame tiles; also consumed by BrowserDialog/WebBoardDialog frame/chrome draw helpers. |
| `SUBWIN.EPF` / `SUBWIN.PAL` | Event/category card frame and fill in `RankingEventListPane`. |
| `SLIDEBG.EPF` / `SLIDEBG.PAL` | `RankingEventScrollPane` track segments. |
| `SCRBUTT.EPF` / `BUTTON.PAL` | `RankingEventScrollPane` scroll buttons/thumb. |
| `SYMBOLS.EPF` | Reward-info symbol icons. |
| Item object images | Category and reward item icons drawn through `g_pItemObjImageLib`. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format and found every named ranking asset in the current client package:

| Resource | Archive entry | Package evidence |
| --- | --- | --- |
| `WBOARDBK.EPF` | `bint2.dat` entry `wboardbk.epf`, index `123` | Offset `17,283,456`, size `26,428`; EPF table header advertises `1` frame. |
| `WBOARDBK.PAL` | `bint2.dat` entry `wboardbk.pal`, index `124` | Offset `17,309,884`, size `1,056`; payload begins with `DLPalette`. |
| `WEBBOARD.EPF` | `bint2.dat` entry `webboard.epf`, index `125` | Offset `17,310,940`, size `10,780`; EPF table header advertises `8` frames. |
| `WEBBOARD.PAL` | `bint2.dat` entry `webboard.pal`, index `126` | Offset `17,321,720`, size `1,056`; payload begins with `DLPalette`. |
| `SUBWIN.EPF` | `bint2.dat` entry `SUBWIN.epf`, index `91` | Offset `14,368,737`, size `725`; EPF table header advertises `9` frames. |
| `SUBWIN.PAL` | `bint2.dat` entry `SUBWIN.pal`, index `92` | Offset `14,369,462`, size `1,056`; payload begins with `DLPalette`. |
| `SLIDEBG.EPF` | `bint2.dat` entry `slidebg.epf`, index `82` | Offset `10,292,519`, size `448`; EPF table header advertises `12` frames. |
| `SLIDEBG.PAL` | `bint2.dat` entry `slidebg.pal`, index `83` | Offset `10,292,967`, size `1,056`; payload begins with `DLPalette`. |
| `SCRBUTT.EPF` | `bint2.dat` entry `scrbutt.epf`, index `66` | Offset `9,568,029`, size `1,200`; EPF table header advertises `2` frames. |
| `BUTTON.PAL` | `bint0.dat` entry `button.pal`, index `16` | Offset `5,826,330`, size `1,056`; payload begins with `DLPalette`. |
| `SYMBOLS.EPF` | `misc.dat` entry `SYMBOLS.EPF`, index `36` | Offset `20,965,203`, size `39,958`; EPF table header advertises `224` frames. |

This package split supports the existing boundary model: the board, card, scrollbar, and symbol assets are real DAT payloads, while `BUTTON.PAL` and `SYMBOLS.EPF` are shared package assets rather than ranking-private resources.

## Evidence Notes

- `RankingDialog::OnPaint` and `RankingRewardInfoDialog::OnPaint` both use the `WBOARDBK`/`WEBBOARD` board frame family. Do not confuse these `WEBBOARD.EPF` / `WEBBOARD.PAL` frame tiles with [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)'s `WEBBOARD.EPD` / `WEBBOARD.PAD` fixed-art resources.
- `RankingEventListPane::DrawRankingItem` uses `SUBWIN` frame tiles and item-object images for category symbols.
- `RankingEventScrollPane::OnPaint` uses `SLIDEBG` and `SCRBUTT` resources for the custom scrollbar.
- `RankingUserListPane::OnPaint` draws text headers `Rank`, `Name`, `Score`, total count, and from/to timestamps over the board background.

## Resource Role Matrix

| UI surface | Resources | Code owner | Rebuild handling |
| --- | --- | --- | --- |
| Ranking board and user list | `WBOARDBK.EPF`, `WBOARDBK.PAL`, `WEBBOARD.EPF`, `WEBBOARD.PAL` | [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md) | Package as ranking board frame/background art. Keep the similarly named WebBoardOld `WEBBOARD.EPD` / `WEBBOARD.PAD` resources separate. |
| Event/category cards | `SUBWIN.EPF`, `SUBWIN.PAL`, item object images | [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md) | Package as the ranking category card frame/fill resources plus item-icon library dependencies. |
| Custom event scrollbar | `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, `BUTTON.PAL` | [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md) | Package as feature-specific scrollbar track/button art while retaining the shared `BUTTON.PAL` caveat. |
| Reward information dialog | `WBOARDBK.*`, `WEBBOARD.*`, `SYMBOLS.EPF`, item object images | [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) | Package board art with the reward dialog and keep reward symbols/item icons as separate draw dependencies. |

## Source/Asset Contract

| Contract area | Source-owned behavior | Resource-owned payload |
| --- | --- | --- |
| Board tiling and frame assembly | `RankingDialog`, `RankingUserListPane`, and `RankingRewardInfoDialog` choose rectangles, tile counts, and draw ordering for board/background pieces. | `WBOARDBK.*` and ranking `WEBBOARD.*` provide the image and palette frames; do not transcribe frame pixels or palette bytes into C++ docs. |
| Event/category cards | `RankingEventListPane` maps category records, text, item icon ids, and selection state to each visible card. | `SUBWIN.*` supplies the card frame/fill art, while item-object icon imagery remains an [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) dependency. |
| Custom scrollbar | `RankingEventScrollPane` owns hit testing, thumb state, scroll position, and repaint scheduling. | `SLIDEBG.*`, `SCRBUTT.EPF`, and shared `BUTTON.PAL` supply control art only; generic scrollbar semantics do not move to resource pages. |
| Reward symbols and item rewards | `RankingRewardInfoDialog` parses opcode `0x7d` reward rows and chooses symbol/item draw positions. | `SYMBOLS.EPF` and item-image library frames provide visual assets; reward-row structures and packet fields stay in class/memory/type docs. |

## Shared Resource Collision Rules

- Ranking `WEBBOARD.EPF` / `WEBBOARD.PAL` are frame-tile resources for ranking board/reward surfaces, and B002 2026-06-17 confirms BrowserDialog/WebBoardDialog draw helpers also consume the same `WBOARDBK.*` / `WEBBOARD.EPF/PAL` literal family. [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md) owns the old WebBoard fixed-art `WEBBOARD.EPD` / `WEBBOARD.PAD` pair; matching base names do not imply a shared layout or source owner, and resource sharing does not move BrowserDialog/WebBoardDialog callback ownership to Ranking.
- `BUTTON.PAL` is a shared button/control palette. Ranking uses it for `SCRBUTT.EPF`, but final packaging should keep the palette available to other button/control consumers rather than declaring it ranking-private.
- FittingRoomScrollPane::OnDraw [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md)(by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) also consumes `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL` for its custom scrollbar. This confirms shared control-art usage only; source ownership remains [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md) because the constructor, vtable, field layout, and direct helper routes are FittingRoom-local.
- `SYMBOLS.EPF` is recorded here for reward-info icon drawing only. A future full symbol-resource page may own the broader inventory if other consumers need centralized treatment.
- Item object images are dependency edges to the item image library, not part of the ranking resource set. Ranking source should store item ids/counts/text and ask the image library to draw icons.

## Rebuild Packaging Boundary

- Treat all named EPF/PAL assets as resource-derived data, not C++ arrays or generated source.
- Keep source reconstruction focused on resource names, draw helper calls, ranking packet/UI state, and owner class boundaries under [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Keep shared rendering helpers, item image libraries, and button palette handling in their documented shared modules rather than folding them into ranking resource ownership.
- Preserve the distinction between ranking `WEBBOARD.EPF` / `WEBBOARD.PAL` frame tiles and [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md) `WEBBOARD.EPD` / `WEBBOARD.PAD` fixed-art resources.

## Scope Boundaries

- `BUTTON.PAL` and `SYMBOLS.EPF` are shared resources; this page records ranking consumers, not exclusive ownership.
- Item object images are runtime image-library draws through `g_pItemObjImageLib`, so the resource page records the dependency but does not claim an item-icon DAT inventory.
- Ranking text headers and formatted totals are UI literals drawn over the board; they are not separate DAT resource assets on this page.
- Generic draw helpers such as frame tiling, text drawing, clipping, and software-render callbacks are shared rendering code. They are intentionally excluded from this ranking resource page even when generated output placed them near ranking list drawing.

## Open Questions

- Exact frame indices, dimensions, and tile ordering for each ranking EPF/PAL pair.
- Full shared-consumer inventory for `BUTTON.PAL` and `SYMBOLS.EPF`.
- Whether ranking board/event/reward assets are always packed in the same DAT family as the old WebBoard resources.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh verified the resource literals at `0x0060db5c` (`WBOARDBK.EPF`), `0x0060db78` (`WBOARDBK.PAL`), `0x0060db94` (`WEBBOARD.EPF`), `0x0060dbb0` (`WEBBOARD.PAL`), `0x00610b74` (`SUBWIN.EPF`), `0x00610b8c` (`SUBWIN.PAL`), `0x0060ddb0` (`SLIDEBG.EPF`), `0x0060ddc8` (`SLIDEBG.PAL`), `0x0060dde0` (`SCRBUTT.EPF`), `0x0060ddf8` (`BUTTON.PAL`), and `0x00610ca4` (`SYMBOLS.EPF`).
- `WBOARDBK.*` has nine observed xrefs per literal, including ranking/reward/user-list drawing ranges `0x00458b50-0x0045920e`, `0x0045b2e0-0x0045b44c`, `0x0045df90-0x0045ea13`, and `0x0045f3a0-0x0045f945`.
- Ranking `WEBBOARD.EPF` / `WEBBOARD.PAL` have forty-two observed xrefs per literal across ranking and additional board-frame consumers. B002 2026-06-17 identifies the BrowserDialog `0x0046b030`/`0x0046b0d0` and active WebBoard `0x0046dd00`/`0x0046dea0` draw paths as part of those additional consumers, supporting the shared-name collision warning while preserving the separate WebBoardOld `.EPD` / `.PAD` boundary.
- `SUBWIN.*` has forty-five observed xrefs per literal, including `0x0045b630-0x0045bcf7` for ranking event-list card/frame drawing and other card-frame consumers outside ranking.
- `SLIDEBG.*`, `SCRBUTT.EPF`, and `BUTTON.PAL` are referenced from scroll-control drawing ranges including `0x0041dab0-0x0041e1c6` and `0x00459ce0-0x0045a3f6`; `SLIDEBG.*` has forty-two observed xrefs per literal, `SCRBUTT.EPF` has seven, and `BUTTON.PAL` has twenty-nine, confirming the shared control-art caveat.
- `SYMBOLS.EPF` has six observed xrefs, including `0x0045e6d9` in `0x0045df90-0x0045ea13` for ranking reward-symbol drawing and additional symbol/icon users outside ranking.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page separates ranking board, category-card, custom-scrollbar, reward-dialog, shared-palette, symbol, and item-image resource roles, records a source/asset contract plus collision rules, includes refreshed xref counts for each literal family, and now documents current DAT archive entries, offsets, sizes, palette signatures, and EPF frame counts for every named ranking asset. Completion remains capped because all shared `BUTTON.PAL` / `SYMBOLS.EPF` / `SUBWIN.*` / `WEBBOARD.*` consumers and exact per-frame semantics are not fully audited here. |
| Confidence `91` | Fresh 2026-06-14 IDA xrefs and current DAT table parsing strongly identify the listed ranking consumers, package payloads, and shared-resource boundaries. Confidence stays below final because high-count shared resources still need broader consumer inventory before exclusive ownership or exact frame semantics can be asserted. |

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)

## Changes

- 2026-06-17 B002 Browser/WebBoard virtual companion execution:
  - Added BrowserDialog/WebBoardDialog as documented consumers of the shared `WBOARDBK.*` and `WEBBOARD.EPF/PAL` board-frame literals.
  - Preserved the resource/source boundary: shared resource consumption does not make BrowserDialog/WebBoardDialog callback clusters Ranking-owned, and old `WEBBOARD.EPD`/`WEBBOARD.PAD` remains separate.

- What existed before: the page had useful resource grouping but was scored unevaluated and cited generated source as part of confidence.
- Changed to: scored `COMPLETION:75` / `CONFIDENCE:85`, removed generated-source authority wording, and added direct IDA MCP string/xref evidence.
- Summary and evidence: verified UTF-16 literals and xrefs connect the listed resource families to ranking UI draw ranges; score stays below final because exact class/function names and every shared resource user are not fully audited.
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/85` to `78/85`.
  - Before: the page listed the resource set and xrefs but did not separate board, event-card, scrollbar, reward-dialog, shared-palette, and WebBoardOld collision boundaries.
  - After: it records a resource role matrix, rebuild packaging boundary, shared-resource scope boundaries, open questions, and the current-session IDA availability caveat.
- 2026-06-07 A002 source/asset contract pass: Raised completion from `78/85` to `80/85`.
  - Before: the page separated resource roles but did not explicitly state which behavior belongs in ranking source versus resource payloads and shared libraries.
  - After: it records source/asset contract rows for board assembly, event cards, custom scrollbar, and reward symbols/items, plus collision rules for WebBoard naming, `BUTTON.PAL`, `SYMBOLS.EPF`, and item image-library dependencies.
- 2026-06-14 A003 score refresh: Raised completion/confidence from `80/85` to `85/88` after live IDA MCP xrefs confirmed literal counts and shared-resource routing for board, event-card, scrollbar, button-palette, and symbol resources; exact EPF frame layouts, DAT grouping, and complete shared-consumer inventories remain below-gate blockers.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:85` / `CONFIDENCE:88` with DAT grouping and payload evidence still open.
  - Changed to: `COMPLETION:88` / `CONFIDENCE:91`.
  - Evidence: current DAT table parsing found `WBOARDBK.*`, ranking `WEBBOARD.*`, `SUBWIN.*`, `SLIDEBG.*`, and `SCRBUTT.EPF` in `bint2.dat`, `BUTTON.PAL` in `bint0.dat`, and `SYMBOLS.EPF` in `misc.dat`, with offsets, sizes, `DLPalette` palette headers, and EPF table frame counts recorded above. `CANONICAL_OWNER:NONE` remains unchanged because the batch preserves owner decisions and these shared package assets still have broader consumer inventories.
