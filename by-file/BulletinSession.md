*** UID:0000HX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BulletinSession

## Status

- Proposed source path: `ui/dialogs/BulletinSession.cpp`
- Proposed header path: `ui/dialogs/BulletinSession.h`
- Current generated source: `source-3/simroot_v2/class_BulletinSession.cpp`
- Core class: [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- Confidence: strong for module responsibility; current scattered helper ownership in generated output is polluted.

## File Role

`BulletinSession.cpp` should own the session coordinator for the bulletin/mail dialog family. It manages the singleton session object, dispatches board/mail/article packet submodes into concrete dialogs, and owns the dialog-stack operations used by board and mail alert/close paths.

It should sit beside [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Those files own the concrete dialogs; `BulletinSession.cpp` owns the stack and routing policy across them.

## Proposed Contents

| Entity | Range / address | Role |
| --- | --- | --- |
| [UID:00001D][BulletinSession](by-class/BulletinSession.md) | `0x00471150-0x00471ff1`, `0x0047ea90` | Bulletin/mail session lifecycle and packet/dialog dispatch; calls shared [UID:0000IU][DialogSession](by-file/DialogSession.md) stack helpers. |
| [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) | `0x0067adc0` | Process-wide active bulletin session pointer. |
| `EnsureBulletinSession_5A50A0` | `0x005a50a0-0x005a5102` | Shared lazy initializer used by UI input/panel paths to open the normal bulletin session. |

## Likely Original Source Group

```text
ui/dialogs/BulletinSession.cpp
  class BulletinSession
  calls DialogSession stack helpers
  EnsureBulletinSession_5A50A0
  g_pBulletinSession
```

The concrete article/mail dialog classes probably lived in sibling sources rather than inside this file:

```text
ui/dialogs/BoardDialogs.cpp
ui/dialogs/MailDialogs.cpp
ui/dialogs/BulletinReplyAlerts.cpp
```

## Ownership Notes

- Keep `CloseAllDialogs`, `PushDialog`, `PopCurrentDialog`, `FindPreviousDialog`, and `GetDialogAtIndex` with [UID:0000IU][DialogSession](by-file/DialogSession.md). Their callers cross board and mail dialogs, and their behavior is shared stack management rather than `BulletinSession`-specific packet routing.
- Keep `EnsureBulletinSession_5A50A0` near this file as a source-local or module helper unless later evidence shows a broader UI command dispatcher source owns it.
- Do not migrate the generated `MarkForDeletion` method at `0x00544690` as BulletinSession. It is broad pane/dialog infrastructure with many callers.
- Do not migrate the generated `RemoveFromUpdateScheduler` method at `0x00538c40` as BulletinSession. It is [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) called from `UserPane` cleanup/hide paths.
- Do not migrate scattered generated helpers `0x00481ad0`, `0x004ffd40`, or `0x005bd9b0` as BulletinSession. They are now resolved as [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md), [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), and [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md).

## Evidence Notes

- IDA MCP caller checks on 2026-05-24 show `BulletinSession::BulletinSession` is invoked from multiple UI/session paths and from `EnsureBulletinSession_5A50A0`.
- IDA MCP callers show `CloseAllDialogs` is used by board/mail action handlers, while `PushDialog` and `PopCurrentDialog` are called repeatedly from the BulletinSession packet/dialog dispatch core.
- IDA MCP xrefs confirm [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) at `0x0067adc0` as the singleton storage.
- IDA MCP on 2026-05-26 resolves the prior scattered helper pass: `0x00538c40` belongs to BowGauge/UserPane cleanup, `0x00481ad0` to chat-mode selector hit-test, `0x004ffd40` to history viewer page advance, and `0x005bd9b0` to menu-variety selector hit-test.

## Cross-References

- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)

## Changes

- What existed before: the page documented BulletinSession responsibility and generated helper ownership pollution but had unevaluated scores.
- What it was changed to: scores were set to `76/84`.
- Summary and evidence: singleton/session routing and dialog-stack relationships are strong; confidence stays below higher levels because concrete dialog files and several generated helper exclusions still need final migration.
