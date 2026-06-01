*** UID:0000NP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Session

## Status

- Confidence: low for existence as a generic network file; strong that current `Session` names are feature/dialog-specific.
- Proposed module: `network/Session.cpp` only if a distinct game-session owner is recovered.
- Current recovered source: none as a clean source unit; `simroot_v2` has `DialogSession` and `BulletinSession`, not a generic `Session` owner.
- Primary notes: [UID:0001QH][client_network](by-meta/client_network.md)

## File Role

`Session.cpp` remains a source-tree placeholder. The current network model has stronger anchors for [UID:0000NS][Socket](by-file/Socket.md), [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), [UID:0000M9][PacketTransform](by-file/PacketTransform.md), [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). No separate session class or cohesive source island has been proven yet.

Current generated `Session` evidence belongs elsewhere:

- `class_DialogSession.cpp` and `class_DialogInSession.cpp` are UI/dialog session stack code and are documented under [UID:0000IU][DialogSession](by-file/DialogSession.md), with exact memory at [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md).
- `class_BulletinSession.cpp` is board/mail social-dialog session code and is documented under [UID:0000HX][BulletinSession](by-file/BulletinSession.md), with exact memory at [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md).
- The game transport state is already covered by [UID:0000NS][Socket](by-file/Socket.md), while the broad request/send queue is covered by [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md).

Therefore `network/Session.cpp` should remain a planning placeholder, not a migration target.

## Proven Session-Labeled Ranges

| Range | Owner | Disposition |
| --- | --- | --- |
| [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) | [UID:0000IU][DialogSession](by-file/DialogSession.md) | Dialog stack/session pane infrastructure. |
| [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) | [UID:0000IU][DialogSession](by-file/DialogSession.md) | Legacy cross-link page for stack helpers; final owner is DialogSession, not generic Session. |
| [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md) | [UID:0000HX][BulletinSession](by-file/BulletinSession.md) | Board/mail session coordinator. |
| [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) | [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) | Bulletin/mail singleton storage, not generic network-session storage. |

## Boundary Rules

- Keep `Socket.cpp` as the stateful transport owner.
- Keep feature packet senders with feature modules unless a focused pass proves shared session ownership.
- Keep `ProtocolSend.cpp` as a separate placeholder for possible shared outbound wrappers.
- Do not move `DialogSession`, `DialogInSession`, or `BulletinSession` here; their `Session` naming is UI/social-dialog behavior, not network-session ownership.

## Promotion Criteria

Promote this placeholder to a real source module only if later evidence shows a generic logged-in game-session owner, such as:

- a class or global state object that bridges login/server selection, socket state, character/session identity, and map/game packet dispatch;
- a source/import path or historical name pointing to `Session.cpp` or `GameSession.cpp`;
- a method cluster that owns session lifecycle separately from `Socket`, `Application`, `MainMenuPane`, and `MapPane`.

## Cross-References

- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `80` and confidence to `72`.
  - Evidence: document clearly records the placeholder status, proven session-labeled ranges, boundary rules, promotion criteria, and network/session cross-references; confidence stays lower because a distinct original generic `Session.cpp` source unit is not yet proven.
