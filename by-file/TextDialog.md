*** UID:0000OL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextDialog

## Status

- Confidence: very strong for class behavior, exact TextDialog children, corrected proxy boundary, Pursuit base dependency, inherited navigation route, and the source-ready `OnControlCommand` implementation.
- Proposed module: `ui/dialogs/TextDialog.cpp`
- Reconstruction route: `NexusTK/ui/dialogs/TextDialog.cpp` with class declaration in `TextDialog.h`.
- Main memory range: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md). Shared navigation definitions live under Pursuit/MessageDialogs and are inherited dependencies, not TextDialog-owned ranges.

## File Role

`TextDialog` is a packet-driven plain text/input dialog used by NPC/message flows. RTTI proves it directly derives from [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), whose declaration is emitted through [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). TextDialog parses inherited dialog packet fields, builds the UI with optional object art, static text, text-entry controls, and buttons, then sends opcode `0x3a` replies.

[UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) is source-ready as `TextDialog::OnControlCommand(int controlIndex, int notifyCode)`. Primary-vtable slot `+0x48` proves the virtual identity. The implementation reads child `6` as a `TextEditControlPane`, builds the inline typed-text reply for control `1`, calls inherited previous/next/current helpers for controls `2/3/4`, closes after every handled route, and leaves the default route as a no-op.

Keep this separate from [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md). Text-menu classes submit menu selections with opcode `0x39`; `TextDialog` handles free text and message navigation through the message-dialog opcode family.

Keep this translation unit separate from [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), but consume its shared Pursuit declaration. The previous/next/current definitions at `0x0054cc30-0x0054ce0f` emit once as protected Pursuit methods from MessageDialogs and are inherited by TextDialog. Historical generated TextDialog staging is preserved only as provenance.

B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) owns four factory wrapper call sites into this class: `TextDialog(payload, true, false)`, `TextDialog(payload, false, false)`, `TextDialog(payload, true, true)`, and `TextDialog(payload, false, true)`. This page keeps the constructor internals, final flag names, and text-dialog behavior under TextDialog ownership.

Keep this separate from [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) and [UID:0000OQ][TextPad](by-file/TextPad.md). Those classes also use text-edit controls, but `EditablePaperPane` is item/paper packet UI and `TextPad` is a local full-screen text pad with file/formatting commands.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TextDialog` | `0x00552110-0x005534a0` | Packet parser, layout builder, source-ready `OnControlCommand`, no-route raw submit-packet island evidence, and compiler support spans. The class/header parent emits declarations/includes while exact by-memory children emit source bodies. |
| inherited Pursuit navigation methods | [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) | Shared previous/next/current opcode `0x3a` methods emitted through Pursuit/MessageDialogs and called from TextDialog actions through inheritance; no duplicate TextDialog definitions. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x0054cc30-0x0054cccf` | `SendDialogPacketPrevious` | Shared navigation helper; see [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md). |
| `0x0054ccd0-0x0054cd6f` | `SendDialogPacketNext` | Shared navigation helper. |
| `0x0054cd70-0x0054ce0f` | `SendDialogPacketCurrent` | Shared navigation helper. |
| `0x00552110-0x0055317a` | `TextDialog::TextDialog` | Parses dialog packet fields and builds normal/high-resolution layouts with `DLGMSG5`, `DLGMSG51`, or `DLGMSG6` resources. |
| `0x00553180-0x00553338` | `TextDialog::OnControlCommand` | Source-ready virtual override. Control `1` reads edit child `6`, converts text, sends opcode `0x3a` with inherited dialog fields, and closes; controls `2/3/4` navigate and close; default is a no-op. |
| `0x00553338-0x00553348` | action switch table | Compiler-generated target table for `OnControlCommand`; ignored support data. |
| `0x00553350-0x00553495` | no-route raw submit-packet island | Source-shaped TextDialog-family opcode `0x3a` reply clone with no current caller/pointer route; B007 found no VA/RVA/direct-branch route into the body, so it is not emitted from this file yet. |

## Ownership Notes

- This file should own the main `TextDialog` class.
- The navigation methods belong to shared base [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md). TextDialog inherits `m_dialogType`, `m_dialogId`, `m_dialogState`, `m_dialogPageIndex`, and the three protected send methods; this file does not own or duplicate their definitions.
- Do not fold this range into [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md). IDA confirms `0x00552110` installs `TextDialog` vtables after the head-selection class ends.
- Do not describe `0x00553338-0x005534a0` as only local switch/alignment. Live IDA byte review shows `0x00553338-0x00553348` is the action switch table, `0x00553348-0x00553350` and `0x00553495-0x005534a0` are `0xcc` padding, and `0x00553350-0x00553495` is source-shaped TextDialog packet-helper-like code with no current xrefs or owner/emitter route.
- Do not attach `0x005534a0-0x00553609` to this file. [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) proves it is a [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) reply callback installed by the proxy constructor at `0x00553895`; `0x00553610` starts the proxy constructor.
- 2026-05-24 `simroot_v2` recheck emitted navigation helpers as TextDialog methods, while IDA callers crossed into message/menu and proxy paths. Historical B012 no-owner/no-emitter treatment correctly rejected that false private route before the receiver was proven. Current Pursuit RTTI/layout evidence closes the receiver without changing TextDialog ownership.
- Shared default destructor note: TextDialog primary vtable slot `0x00622958` uses [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), with secondary/tertiary slots routed through [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md). These are compiler-generated. TextDialog needs no explicit destructor declaration/body; its implicitly declared virtual destructor follows the Pursuit/DialogPane base contract.
- 2026-06-16 B001 source-split audit reconfirmed `0x00552110` size `0x106a`, `0x00553180` size `0x1b8`, the `0x00553338-0x00553348` switch table, the no-xref raw helper at `0x00553350-0x00553495`, and neighboring proxy callback `0x005534a0` size `0x169`.
- 2026-06-21 B007 source-quality recheck of [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md) found no absolute VA pointer, no real RVA pointer, and no direct branch/call route to `0x00553350` or into the raw body. If a route appears later, the best source role is a private text-reply sender, but current file emission must still omit the raw island.

## Source-Ready Method And Dependencies

`TextDialog.cpp` consumes the class declaration emitted by [UID:0000EL][TextDialog](by-class/TextDialog.md). The class has direct public `PursuitMessageDialogPane` inheritance, exact size `0x278`, no source-proven added fields, and no explicit TextDialog destructor declaration. Its header declares the constructor and `virtual void OnControlCommand(int controlIndex, int notifyCode)` exactly once.

The source module requires `MemoryMan`, packet-buffer writers, the packet sender/Socket surface, `TextEditControlPane`, `WideCharToMultiByte`, and wide-string length support. The accepted class-parent source includes `MemoryMan.h`, `PacketBuffer.h`, `Socket.h`, `TextEditControlPane.h`, `<windows.h>`, and `<wchar.h>`, then expands exact child definitions through `[[CHILDREN]]`.

The inline control-1 packet is exactly opcode `0x3a`, `m_dialogType`, big-endian `m_dialogId`, big-endian `m_dialogState`, big-endian `m_dialogPageIndex + 1`, subtype `2`, one-byte converted length, and converted bytes. The sent length is `convertedLength + 12`; local terminators are not sent. Compiler security/range helpers remain compiler output rather than handwritten source.

Original resource constant names for control indices `1..4` and child index `6`, original local spellings, and exact include order are not preserved. The reconstruction keeps exact numeric values and uses project-consistent human names rather than IDA labels. Those lexical uncertainties cap confidence below final-audit 95 but do not block the source-ready method.

## Cross-References

- [UID:0000EL][TextDialog](by-class/TextDialog.md)
- [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md)
- [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md)
- [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md)

## Changes

- 2026-08-01 Agent-B009 UID0003VR implementation callback:
  - Raised `89/90 -> 90/92` without changing reconstruction path or file ownership.
  - Replaced historical `HandleDialogAction` wording with source-ready `TextDialog::OnControlCommand` and its exact vtable/ABI/control/packet/close behavior.
  - Added the class/header ownership, source dependencies, child-emitter placement, compiler/source split, and lexical negative-evidence record.
  - Preserved one-copy Pursuit navigation ownership, the separate no-route raw island, and the NexonclubProxy callback exclusion.

- 2026-07-16 Agent-B004 UID0001FE support callback:
  - Raised confidence `88 -> 90` with completion retained at `89`.
  - Corrected the source dependency to RTTI-proven Pursuit inheritance and inherited packet/navigation state.
  - Replaced historical no-owner helper wording with one-copy Pursuit/MessageDialogs emission and preserved all TextDialog-specific body/no-route blockers.
- 2026-07-01 Agent-B010 implementation callback: added support note for [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) four TextDialog wrapper call forms while preserving TextDialog ownership of constructor internals and final flag names.
- Earlier boundary correction: `TextDialogCore` was once widened to `0x00553609`, and shared dialog navigation helpers were corrected to end at `0x0054ce0f`.
- Superseded by later ownership evidence: the current file-level TextDialog core ends at `0x005534a0`; [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) owns the old tail.
- 2026-06-16 Supervisor execution of B001 reports `0001FJ-textdialog-core-source-split-audit.md` and `0001FJ-textdialog-core-source-quality.md`: raised from `88/87` to `89/88`, replaced the broad local switch/alignment tail with exact switch-table/no-route raw-island/padding evidence, added exact child links, and preserved the proxy callback exclusion.
- 2026-06-21 Rule 26 incorporation of B007 report `0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`: score unchanged; added the raw PE no-route recheck and kept the TextDialog source file from emitting the retained raw submit-packet island.
- 2026-07-04 B012 UID0001FG support sync: updated shared navigation-helper wording from current TextDialog emission to historical/generated staging only. [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) now remains reconstructable but no-emitter/no-owner until a shared dialog receiver/helper declaration exists; private TextDialog methods, private MessageDialogs methods, DialogPane base methods, PacketBuffer/Socket/ProtocolSend ownership, and splitting into three child emitters are rejected.
