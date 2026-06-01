*** UID:00001D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BulletinSession

## Status

- Likely source file: [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- Core address range: [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md); uses shared [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- Singleton global: [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) at `0x0067adc0`
- Current recovered file: `source-3/simroot_v2/class_BulletinSession.cpp`
- Confidence: strong for dialog-flow/session methods; low for current generated scattered helpers outside the core.

## Class Purpose

`BulletinSession` is the board/mail session manager behind the nested bulletin dialog flow. It owns the global session pointer, creates board/article/mail dialogs from server packets or UI commands, and calls shared `DialogSession` stack helpers to manage close/back/previous-dialog behavior for article and mail reply/delete flows.

The concrete board and mail dialog classes belong in [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). `BulletinSession` is the coordinator above those dialog modules.

## Observed State

```text
BulletinSession
  DialogSession base/subobject
  board/mail mode flags
  current article/list/search dialog ids
  selected article/mail identifiers
  inherited DialogSession stack/list
```

Generated fields such as `m_searchDialogId`, `m_isGuildBoard`, and article-id members are useful orientation, but the final layout still needs a struct pass.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00471150-0x0047126b` | Initializes `DialogSession`, sets `g_pBulletinSession`, sends initial board/guild-board request or opens an article view immediately. |
| singleton clear helper | `0x00471270-0x00471298` | Clears `g_pBulletinSession`; currently not emitted as an active class method. |
| `OpenNewArticleDialog` | `0x004712f0-0x004713a5` | Creates/registers `NewArticleDialog` with the active board/session context. |
| `OpenArticleReplyDialog` | `0x004713b0-0x00471475` | Opens reply/compose dialog for an existing article/mail context. |
| `OpenArticleViewDialog` | `0x00471550-0x00471871` | Dispatches server packet submodes to board list, article list, mail list, article view, mail view, or internal handlers. |
| `OpenArticleEditDialog` provisional | `0x004718a0-0x00471955` | Creates a board-list style dialog for edit/navigation flow. |
| `OpenArticleDeleteDialog` provisional | `0x00471960-0x00471a25` | Creates article-list/delete dialog and stores the active article id. |
| `HandleArticleAction` | `0x00471a30-0x00471bfc` | Handles article read/action packets, including no-article alerts and `ArticleDialog` creation. |
| `HandleListAction` | `0x00471c00-0x00471dcc` | Handles list action packets and opens `NewPredefinedFormArticleDialog` when needed. |
| `OpenSearchDialog` | `0x00471dd0-0x00471e95` | Opens a `MailListDialog`-style search result dialog and stores its dialog id. |
| `HandleSearchResult` | `0x00471ea0-0x00471ff0` | Handles search/read result packets, including mail dialog creation and not-found messages. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated this-adjustor thunks; keep excluded from source-facing docs. |
| scalar deleting destructor | `0x0047ea90-0x0047eaee` | Clears `g_pBulletinSession`, destroys `DialogSession`, and optionally deletes `this`. |
| shared `DialogSession` stack helpers | `0x004a0f40-0x004a1390` | Close/push/pop/previous/get helpers now documented under [UID:00003U][DialogSession](by-class/DialogSession.md); BulletinSession and board/mail dialogs call them. |
| `EnsureBulletinSession_5A50A0` | `0x005a50a0-0x005a5102` | Shared lazy-initializer global/helper; allocates a normal bulletin session if the singleton is absent. |
| `GetMenuIndexFromPoint` generated artifact | `0x005bd9b0-0x005bda3b` | Resolved away from BulletinSession; this is [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) ten-row hit-test support. |

## Generated Ownership Caveats

`class_BulletinSession.cpp` currently attaches several methods that should not be migrated as BulletinSession-specific without another owner pass:

- `0x00544690` is a broad pane/dialog `MarkForDeletion` helper with very wide caller fanout.
- `0x00538c40` is now resolved as [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md), called from `UserPane` cleanup/hide paths through [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md).
- `0x00481ad0` is now resolved as [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).
- `0x004ffd40` is now resolved as [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md).
- `0x005bd9b0` is now resolved as [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md).
- `0x005556f0` is now resolved as a [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) five-row hit-test helper.
- `0x00556070` and `0x00556100` are now resolved as [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) hit-test/submit helpers.

## Evidence Notes

- `source-3/simroot_v2/class_BulletinSession.meta_wave3` identifies the imported source file as `BulletinSession.cpp` and records the session summary.
- IDA MCP on 2026-05-24 confirms the major function starts and sizes from `0x00471150` through `0x00471ea0`, the destructor at `0x0047ea90`, and the shared `DialogSession` stack helpers at `0x004a0f40-0x004a1390`.
- IDA MCP callers show the stack helpers are called directly from BulletinSession methods and board/mail/article dialog flows, but the helpers operate on `DialogSession` fields and should stay with [UID:00003U][DialogSession](by-class/DialogSession.md).
- IDA MCP xrefs to `0x0067adc0` show singleton writes in constructor/destructor/clear paths and reads from lazy-initializer and UI packet/input paths.
- IDA MCP on 2026-05-26 resolves the prior scattered follow-up helpers: `0x00538c40` to BowGauge/UserPane cleanup, `0x00481ad0` to chat-mode selector hit-test, `0x004ffd40` to history viewer page advance, and `0x005bd9b0` to menu-variety selector hit-test.

## Cross-References

- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)

## Changes

- What existed before: the page had detailed method, singleton, generated-ownership, and evidence notes, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `80/86`.
- Summary and evidence: core session flow, dialog stack helper separation, singleton global, and several wrong-owner helper resolutions are documented; final struct layout and some generated scattered helpers still need cleanup before this can approach complete.
