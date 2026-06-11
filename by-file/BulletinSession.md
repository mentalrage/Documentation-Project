*** UID:0000HX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BulletinSession

## Status

- Proposed source path: `ui/dialogs/BulletinSession.cpp`
- Proposed header path: `ui/dialogs/BulletinSession.h`
- Core class: [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- Confidence: strong for module responsibility, class ownership, singleton lifecycle, lazy initializer relationship, and vtable declarations; medium for final field names and exact source split with sibling dialog modules.
- Main memory evidence: [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md), [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md), and board/mail read-only data in [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md).

## File Role

`BulletinSession.cpp` should own the session coordinator for the bulletin/mail dialog family. It manages the singleton session object, dispatches board/mail/article packet submodes into concrete dialogs, and owns the dialog-stack operations used by board and mail alert/close paths.

It should sit beside [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Those files own the concrete dialogs; `BulletinSession.cpp` owns the stack and routing policy across them.

## Proposed Contents

| Entity | Range / address | Role |
| --- | --- | --- |
| [UID:00001D][BulletinSession](by-class/BulletinSession.md) | `0x00471150-0x00471ff1`, `0x0047ea90` | Bulletin/mail session lifecycle and packet/dialog dispatch; calls shared [UID:0000IU][DialogSession](by-file/DialogSession.md) stack helpers. |
| [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) | `0x0067adc0` | Process-wide active bulletin session pointer. |
| [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) | `0x0067adc0-0x0067adc4` | Exact `.data` singleton slot with constructor publish/null-clear, destructor/clear writes, lazy-create checks, and UI command consumers documented. |
| BulletinSession vtable/read-only data | within [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) | Source-declared/generated-binary vtable data in the board/mail `.rdata` island; the same page keeps WebBoard strings, board/mail dialog vtables, and sibling dialog ownership visible. |
| `EnsureBulletinSession_5A50A0` | `0x005a50a0-0x005a5103` | Shared lazy initializer used by UI input/panel paths to open the normal bulletin session. |

## Likely Original Source Group

```text
ui/dialogs/BulletinSession.cpp
  class BulletinSession
  calls DialogSession stack helpers
  EnsureBulletinSession_5A50A0
  g_pBulletinSession
  BulletinSession vtable declarations
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
- Do not migrate the caller-biased `MarkForDeletion` method at `0x00544690` as BulletinSession. It is broad pane/dialog infrastructure with many callers.
- Do not migrate the caller-biased `RemoveFromUpdateScheduler` method at `0x00538c40` as BulletinSession. It is [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) called from `UserPane` cleanup/hide paths.
- Do not migrate scattered caller-biased helpers `0x00481ad0`, `0x004ffd40`, or `0x005bd9b0` as BulletinSession. They are now resolved as [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md), [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), and [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md).

## Evidence Notes

- IDA MCP caller checks on 2026-05-24 show `BulletinSession::BulletinSession` is invoked from multiple UI/session paths and from `EnsureBulletinSession_5A50A0`.
- IDA MCP callers show `CloseAllDialogs` is used by board/mail action handlers, while `PushDialog` and `PopCurrentDialog` are called repeatedly from the BulletinSession packet/dialog dispatch core.
- IDA MCP xrefs confirm [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) at `0x0067adc0` as the singleton storage.
- IDA MCP on 2026-05-26 resolves the prior scattered helper pass: `0x00538c40` belongs to BowGauge/UserPane cleanup, `0x00481ad0` to chat-mode selector hit-test, `0x004ffd40` to history viewer page advance, and `0x005bd9b0` to menu-variety selector hit-test.
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md) records thirteen live IDA-bounded functions in the core session island, including constructor singleton/vtable writes, the packet-forwarder vtable slot, and dispatcher/handler call targets into board/mail/article dialogs.
- [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) records the exact `.data` storage bytes, constructor publish/null clear, clear/destructor writes, lazy-create constructor callers, and UI/session guard checks for the singleton.
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) ties the BulletinSession vtable cluster into the broader board/mail `.rdata` island while keeping concrete `BulletinDialog`, board-list, article, transfer-reply, and mail-dialog data assigned to sibling modules.
- 2026-06-07 Batch080 live IDA MCP rechecked the direct class/file route: [UID:00001D][BulletinSession](by-class/BulletinSession.md) covers thirteen cleanly bounded core functions at `0x00471150-0x00471ff1`, scalar deleting destructor `0x0047ea90-0x0047eaef`, and lazy initializer `0x005a50a0-0x005a5103`. The core island has `0xcc` padding on both sides.
- The same pass confirmed the file-owned class data anchors: BulletinSession vtable views at `0x00613b20`, `0x00613b6c`, and `0x00613b9c` are referenced by constructor, non-deleting cleanup, and scalar-deleting destructor paths; `g_pBulletinSession` at `0x0067adc0` has constructor, cleanup, destructor, lazy-initializer, and UI/session guard xrefs.

## Assignment Gate

This source root now clears the corrected parent gate for [UID:00001D][BulletinSession](by-class/BulletinSession.md): both the class and file parent are `85/87`. The assignment is limited to the session coordinator, singleton lifecycle, lazy initializer relationship, and BulletinSession vtable declarations. Concrete board/mail/article dialog implementations stay with [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md); shared stack/list helper implementations stay with [UID:0000IU][DialogSession](by-file/DialogSession.md).

## Cross-References

- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md)
- [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)
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

- 2026-06-06 A008 source-root evidence pass:
  - Before: the page described the session coordinator and helper-pollution exclusions, but did not surface the exact singleton memory page or the board/mail `.rdata` aggregate that now documents BulletinSession vtable data.
  - After: raised from `76/84` to `82/86`, added exact memory/global/read-only-data evidence, and clarified that vtable declarations belong with this source root while concrete board/mail dialog bodies remain in sibling files.
  - Evidence: [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md) records the bounded session functions and dispatch targets; [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) records exact singleton storage/lifetime evidence; [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) records the board/mail vtable/string-data island.
- What existed before: the page documented BulletinSession responsibility and helper ownership pollution but had unevaluated scores.
- What it was changed to: scores were set to `76/84`.
- Summary and evidence: singleton/session routing and dialog-stack relationships are strong; confidence stays below higher levels because concrete dialog files and several generated helper exclusions still need final migration.
- 2026-06-05 path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, which left the file row in error state.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `BulletinSession.cpp` under `ui/dialogs` beside `DialogSession`, `BoardDialogs`, `MailDialogs`, and `BulletinReplyAlerts`; live IDA MCP xrefs to [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) confirm this page owns the singleton session lifecycle.
- 2026-06-07 Batch080 parent-gate pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP rechecked the exact BulletinSession class island, scalar destructor, lazy initializer, three vtable views, singleton lifecycle xrefs, and clean core boundaries. The page now explicitly clears the corrected `85/85` parent gate for [UID:00001D][BulletinSession](by-class/BulletinSession.md) while preserving sibling ownership for board/mail dialogs and shared `DialogSession` helpers.
