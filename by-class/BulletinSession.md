*** UID:00001D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for dialog-flow/session methods, singleton lifecycle, vtable views, exact core bounds, and helper exclusion; medium for final field names and exact original method names.

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
| constructor | `0x00471150-0x0047126c` | Initializes `DialogSession`, sets `g_pBulletinSession`, writes three BulletinSession vtable views, sends initial board/guild-board request or opens an article view immediately. |
| singleton clear helper | `0x00471270-0x00471299` | Restores BulletinSession vtables, clears `g_pBulletinSession`, and chains to `DialogSession` base cleanup. |
| active-state screen-dimmer helper | `0x004712a0-0x004712ac` | Sets the active-state byte at `this + 0x100` and calls the screen-dimmer factory path. |
| `OpenNewArticleDialog` | `0x004712f0-0x004713a6` | Creates/registers `NewArticleDialog` with the active board/session context. |
| `OpenArticleReplyDialog` | `0x004713b0-0x00471476` | Opens reply/compose dialog for an existing article/mail context. |
| packet forwarder thunk | `0x00471480-0x004714a3` | Vtable slot that accepts bulletin payload byte `49` and dispatches to the main packet handler with the adjusted `BulletinSession` pointer. |
| `OpenArticleViewDialog` | `0x00471550-0x00471872` | Dispatches server packet submodes to board list, article list, mail list, article view, mail view, or internal handlers. |
| `OpenArticleEditDialog` provisional | `0x004718a0-0x00471956` | Creates a board-list style dialog for edit/navigation flow. |
| `OpenArticleDeleteDialog` provisional | `0x00471960-0x00471a26` | Creates article-list/delete dialog and stores the active article id. |
| `HandleArticleAction` | `0x00471a30-0x00471bfd` | Handles article read/action packets, including no-article alerts and `ArticleDialog` creation. |
| `HandleListAction` | `0x00471c00-0x00471dcd` | Handles list action packets and opens `NewPredefinedFormArticleDialog` when needed. |
| `OpenSearchDialog` | `0x00471dd0-0x00471e96` | Opens a `MailListDialog`-style search result dialog and stores its dialog id. |
| `HandleSearchResult` | `0x00471ea0-0x00471ff1` | Handles search/read result packets, including mail dialog creation and not-found messages. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated this-adjustor thunks; keep excluded from source-facing docs. |
| scalar deleting destructor | `0x0047ea90-0x0047eaef` | Clears `g_pBulletinSession`, destroys `DialogSession`, and optionally deletes `this`. |
| shared `DialogSession` stack helpers | `0x004a0f40-0x004a1390` | Close/push/pop/previous/get helpers now documented under [UID:00003U][DialogSession](by-class/DialogSession.md); BulletinSession and board/mail dialogs call them. |
| `EnsureBulletinSession_5A50A0` | `0x005a50a0-0x005a5103` | Shared lazy-initializer global/helper; allocates a normal bulletin session if the singleton is absent. |
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
- 2026-06-07 Batch080 live IDA MCP `py_eval` rechecked the current class method inventory: thirteen cleanly bounded functions in `0x00471150-0x00471ff1`, scalar deleting destructor `0x0047ea90-0x0047eaef`, and lazy initializer `0x005a50a0-0x005a5103`. The bytes immediately before `0x00471150` and after `0x00471ff1` are `0xcc` padding, confirming the core island bounds.
- The same pass confirmed BulletinSession vtable views at `0x00613b20`, `0x00613b6c`, and `0x00613b9c`; each has constructor, non-deleting cleanup, and scalar-deleting destructor refs at `0x004711c5/0x004711cb/0x004711d5`, `0x00471270/0x00471276/0x00471280`, and `0x0047ea96/0x0047ea9c/0x0047eaa6`.
- The live singleton xref audit for `0x0067adc0` confirmed constructor writes at `0x004711a2/0x004711a9`, cleanup writes at `0x0047128a`, `0x0047e840`, and `0x0047eab0`, plus six guard/consumer families at `0x00508776`, `0x00513bd3`, `0x005466e8`, `0x005a50c3`, `0x005a60c8`, and `0x005bd0f4`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:0000HX][BulletinSession](by-file/BulletinSession.md). The class is now `85/87`, and the direct file parent is now `85/87`, so both sides clear the corrected `85/85` gate. The assignment is direct because `BulletinSession.cpp` owns the session coordinator class, singleton lifecycle, lazy initializer relationship, and BulletinSession vtable declarations; concrete board/mail/article dialog bodies and shared `DialogSession` stack helpers remain routed to their own source files.

## Score Rationale

- Completion `85`: the page now records the full class method inventory, singleton storage and lifecycle, vtable views, scalar destructor and lazy initializer, clean core bounds, direct file parent, and explicit exclusions for shared stack helpers and caller-biased generated helpers.
- Confidence `87`: ownership and behavior are backed by live IDA MCP and exact by-memory/global pages. Confidence remains below higher levels because final field names, exact original method names, and some generated helper cleanup outside the core still need a layout pass.

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
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor/dialog-open/action/list/destructor starts at `0x00471150`, `0x004712f0`, `0x00471550`, `0x00471a30`, `0x00471c00`, and `0x0047ea90`, and `callers` shows the constructor reached from board/mail/session setup paths. `AUTOGEN_PARENT_UID` remains blank because [UID:0000HX][BulletinSession](by-file/BulletinSession.md) is still below the 80+ completion attachment gate.
- 2026-06-07 Batch080 class coverage pass:
  - Changed score from `80/86` to `85/87`.
  - Set `AUTOGEN_PARENT_UID:0000HX` after also raising the direct [UID:0000HX][BulletinSession](by-file/BulletinSession.md) parent to `85/87`.
  - Evidence: live IDA MCP rechecked the thirteen-function core island, clean `0xcc` boundaries, scalar deleting destructor, lazy initializer, three BulletinSession vtable-view refs, and singleton xrefs. Final C++ remains blank because field/method names and source declarations remain below the final-code gate.
