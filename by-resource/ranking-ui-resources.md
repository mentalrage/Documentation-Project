*** UID:0001RK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ranking UI Resources

## Status

- Resource family: ranking board, event list, reward dialog, and custom scroll controls
- Owner module: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Confidence: strong from IDA string, xref, and resource-use evidence.

## Resource Set

| Resource | Observed owner/use |
| --- | --- |
| `WBOARDBK.EPF` / `WBOARDBK.PAL` | Ranking dialog/user-list/reward-dialog tiled background fill. |
| `WEBBOARD.EPF` / `WEBBOARD.PAL` | Ranking and reward dialog border frame tiles. |
| `SUBWIN.EPF` / `SUBWIN.PAL` | Event/category card frame and fill in `RankingEventListPane`. |
| `SLIDEBG.EPF` / `SLIDEBG.PAL` | `RankingEventScrollPane` track segments. |
| `SCRBUTT.EPF` / `BUTTON.PAL` | `RankingEventScrollPane` scroll buttons/thumb. |
| `SYMBOLS.EPF` | Reward-info symbol icons. |
| Item object images | Category and reward item icons drawn through `g_pItemObjImageLib`. |

## Evidence Notes

- `RankingDialog::OnPaint` and `RankingRewardInfoDialog::OnPaint` both use the `WBOARDBK`/`WEBBOARD` board frame family. Do not confuse these `WEBBOARD.EPF` / `WEBBOARD.PAL` frame tiles with [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)'s `WEBBOARD.EPD` / `WEBBOARD.PAD` fixed-art resources.
- `RankingEventListPane::DrawRankingItem` uses `SUBWIN` frame tiles and item-object images for category symbols.
- `RankingEventScrollPane::OnPaint` uses `SLIDEBG` and `SCRBUTT` resources for the custom scrollbar.
- `RankingUserListPane::OnPaint` draws text headers `Rank`, `Name`, `Score`, total count, and from/to timestamps over the board background.

## IDA MCP Evidence

- UTF-16 resource literals were verified at `0x0060db5c` (`WBOARDBK.EPF`), `0x0060db78` (`WBOARDBK.PAL`), `0x0060db94` (`WEBBOARD.EPF`), `0x0060dbb0` (`WEBBOARD.PAL`), `0x00610b74` (`SUBWIN.EPF`), `0x00610b8c` (`SUBWIN.PAL`), `0x0060ddb0` (`SLIDEBG.EPF`), `0x0060ddc8` (`SLIDEBG.PAL`), `0x0060dde0` (`SCRBUTT.EPF`), `0x0060ddf8` (`BUTTON.PAL`), and `0x00610ca4` (`SYMBOLS.EPF`).
- `WBOARDBK.*` has xrefs from ranking/reward/user-list drawing ranges including `0x00458b50-0x0045920e`, `0x0045b2e0-0x0045b44c`, `0x0045df90-0x0045ea13`, and `0x0045f3a0-0x0045f945`.
- `SUBWIN.*` is referenced from `0x0045b630-0x0045bcf7`, matching the event-list card/frame drawing path.
- `SLIDEBG.*`, `SCRBUTT.EPF`, and `BUTTON.PAL` are referenced from scroll-control drawing ranges including `0x0041dab0-0x0041e1c6` and `0x00459ce0-0x0045a3f6`; `BUTTON.PAL` is shared by additional button/control code.
- `SYMBOLS.EPF` is referenced from `0x0045df90-0x0045ea13`, matching reward-symbol drawing, and is also shared by other symbol/icon users.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)

## Changes

- What existed before: the page had useful resource grouping but was scored unevaluated and cited generated source as part of confidence.
- Changed to: scored `COMPLETION:75` / `CONFIDENCE:85`, removed generated-source authority wording, and added direct IDA MCP string/xref evidence.
- Summary and evidence: verified UTF-16 literals and xrefs connect the listed resource families to ranking UI draw ranges; score stays below final because exact class/function names and every shared resource user are not fully audited.
