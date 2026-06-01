*** UID:0000LA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MessageDialogs

## Status

- Confidence: strong for packet-driven message/menu-question dialog ownership, medium for whether `Message` lived here or in a nearby message model/overlay file.
- Proposed module folder: `ui/dialogs/`
- Candidate files: `ui/dialogs/MessageDialogs.cpp` and [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md).
- Current generated sources: `class_Message.cpp`, `class_MessageShowPane.cpp`, `class_PursuitMessageDialogPane.cpp`, `class_MessageDialog.cpp`, `class_MessageDialogLarger.cpp`, `class_MenuQuestionDialog.cpp`, `class_MenuQuestionDialogLarger.cpp`, `class_MenuQuestionItemList.cpp`, and `class_MenuQuestionItemListLarger.cpp`.
- Evidence basis: Wave3 class inspection, `simroot_v2` generated source, older Wave2 by-memory report notes for `MessageDialog`/`Motion::HandleDialogPacket`, and targeted IDA MCP function-boundary checks on 2026-05-23.

## Hypothesis

The message and menu-question dialogs were likely implemented as one feature source family rather than one class per generated file. The dispatcher currently emitted as `Motion::HandleDialogPacket` decodes a packet mode byte and instantiates `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, or `MenuQuestionDialogLarger`; those constructors then parse packet payloads, build `DialogPane` controls, and send previous/next/current/selection replies.

Likely structure:

```text
ui/dialogs/MessageDialogs.cpp
```

Possible split:

```text
ui/dialogs/MessageDialogs.cpp
ui/dialogs/MessageShowPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `Message` | `0x00520e30-0x00521d94` | `class_Message.cpp` | Base message object with a sorted entry list and scalar deleting destructor. |
| `MessageShowPane` | `0x00521da0-0x005227c6` | `class_MessageShowPane.cpp`, plus polluted `0x00522530` owner | Floating message overlay pane that wraps wide text, draws shadow/face palette text rows, and tracks `g_pMessageShowPane`; now documented as a split candidate in [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md). |
| [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md) | raw constructor `0x0054cab0-0x0054cae9`, vtables `0x00622428/0x00622488/0x006224b8`, shared destructor glue at `0x00520aa5+` | `class_PursuitMessageDialogPane.cpp` | Tiny message-dialog base/companion class; constructor initializes a blank `DialogPane` shell and installs three vtables. |
| [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) | `0x0054caf0-0x0054cc2f` | omitted from current active simroot output | Shared vtable action handler that parses dialog object-response payloads and sends opcode `0x3a` replies. |
| `MessageDialog` | `0x0054ce10-0x0054db8b` | `class_MessageDialog.cpp` | Normal NPC/system message dialog; parses object/message packet data, builds background/object/text/button controls, and sends navigation replies. |
| `MessageDialogLarger` | `0x0054db90-0x0054e91b` | `class_MessageDialogLarger.cpp` | Larger message dialog variant with portrait/body layout helpers and primary/secondary/tertiary actions. |
| `MenuQuestionDialog` | `0x0054e920-0x0054fa5d` | `class_MenuQuestionDialog.cpp` | Menu-question dialog; parses a selectable item list plus optional description/object art and submits selected menu values. |
| `MenuQuestionDialogLarger` | `0x0054fb30-0x00550c7d` | `class_MenuQuestionDialogLarger.cpp` | Larger menu-question variant with equivalent packet response behavior. Current emitted source omits its constructor body; see [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md). |
| `MenuQuestionItemList` | `0x00550d50-0x00550ec1` | `class_MenuQuestionItemList.cpp` | ListPane-derived row renderer and selection confirmation helper for normal menu-question dialogs. |
| `MenuQuestionItemListLarger` | `0x00550ed0-0x00551021` | `class_MenuQuestionItemListLarger.cpp` | Larger-layout list widget that delegates selection and draws highlighted wide-string entries. |
| [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) | `0x0054c200-0x0054caa9` | currently emitted in `class_Motion.cpp` plus wrapper helpers | Packet dispatcher and allocation-wrapper island for this dialog family; current Motion owner is a generated ownership artifact. |
| dialog navigation helpers | `0x0054cc30-0x0054ce0f` | currently emitted under `class_TextDialog.cpp` | Shared previous/next/current opcode `0x3a` response helpers used by this dialog family and `TextDialog`. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed exact function starts for all listed methods:

- `Message`: `0x00520e30-0x00520ecb`, `0x00520ed0-0x00520ef5`, `0x00521d40-0x00521d94`.
- `MessageShowPane`: `0x00521da0-0x00521fc0`, `0x00521fc0-0x00522025`, `0x00522030-0x00522530`, `0x00522530-0x005226ea`, `0x005226f0-0x005226fa`, `0x005226fb-0x00522706`, `0x00522706-0x00522711`, `0x00522720-0x005227c6`.
- `MessageDialog`: `0x0054ce10-0x0054db3e`, `0x0054db40-0x0054db8b`.
- `MessageDialogLarger`: `0x0054db90-0x0054e8c7`, `0x0054e8d0-0x0054e91b`.
- `MenuQuestionDialog`: `0x0054e920-0x0054f8dd`, `0x0054f8e0-0x0054fa10`, `0x0054fa20-0x0054fa5d`.
- `MenuQuestionDialogLarger`: `0x0054fb30-0x00550afb`, `0x00550b00-0x00550c30`, `0x00550c40-0x00550c7d`.
- `MenuQuestionItemList`: `0x00550d50-0x00550db4`, `0x00550e30-0x00550e3b`, `0x00550e40-0x00550ec1`.
- `MenuQuestionItemListLarger`: `0x00550ed0-0x00550f1f`, `0x00550f90-0x00550f9b`, `0x00550fa0-0x00551021`.

IDA xrefs show the dialog constructors are called from the packet dispatch area around `0x0054c200`, while the virtual/action helpers are referenced from vtables around `0x00622500-0x00622878`.

2026-05-25 IDA MCP recheck:

- `HandleDialogPacket_54C200` reads `packet[1]`: bit `0x10` selects the larger dialog family, and the low nibble selects message versus menu-question variants. Cases `0`/`1` allocate `MessageDialog` or `MessageDialogLarger`; cases `2`/`3` allocate `MenuQuestionDialog` or `MenuQuestionDialogLarger`; all constructors receive `packet + 2` plus a final layout/text-mode flag.
- `MessageDialog::MessageDialog` resolves the current generated ellipsis placeholders: state words are read at `packet + objectDescriptorLength + 10` and `packet + objectDescriptorLength + 12`; the optional text length/data are read at `packet + objectDescriptorLength + 16` and `packet + objectDescriptorLength + 18`.
- `MenuQuestionDialogLarger::MenuQuestionDialogLarger` at `0x0054fb30` still decompiles as a full constructor even though `simroot_v2/class_MenuQuestionDialogLarger.cpp` emits only an omitted-body marker.
- `PursuitMessageDialogPane` constructor bytes at `0x0054cab0-0x0054cae9` still have no IDA function object or direct xrefs, but the instruction sequence is a valid blank `DialogPane` constructor followed by three class-vtable writes. IDA confirms those vtables at `0x00622428`, `0x00622488`, and `0x006224b8`; current generated metadata still reports `vtable_count: 0`.
- `0x0054caf0-0x0054cc2f` is a real shared vtable action handler omitted from current active simroot output. Its vtable refs span `PursuitMessageDialogPane`, `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, and sibling message/menu dialog tables.
- The destructor thunks at `0x00520aa5`/`0x00520ab0` and scalar destructor at `0x00520b70` still have broad vtable reuse, remain shared glue, and are excluded through [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-28 IDA MCP recheck splits the old undocumented `0x0054c1f1-0x0054cab0` gap into dispatcher/wrapper code at [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) plus boundary padding. The wrapper island allocates and calls `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `TextDialog`, `NexonclubProxyDialog`, and `HeadSelectDialog` constructors.

## Ownership Notes

- `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, and `MenuQuestionDialogLarger` should stay together because they are dispatch alternatives from the same dialog-packet handler.
- `PursuitMessageDialogPane` should stay with this source family as a tiny base/companion class. Its constructor at `0x0054cab0` is raw code that IDA does not currently mark as a function, and its generated destructor methods are shared default dialog destructor glue rather than unique message-dialog logic.
- 2026-06-01 IDA MCP recheck reconfirms the raw `PursuitMessageDialogPane` constructor as exact source-owned code: `0x0054cab0-0x0054cae9` calls the base `DialogPane` constructor with empty title and mode args `1, 1`, writes vtables `0x00622428`, `0x00622488`, and `0x006224b8`, and is bracketed by seven-byte `0xcc` alignment gaps.
- 2026-05-26 IDA MCP recheck confirms the raw constructor gap and shared destructor reuse are unchanged; preserve the constructor as reconstructable raw code and keep shared destructor glue out of source-level reconstruction.
- Keep `0x0054caf0` as shared message-dialog source behavior. It is not compiler glue and should not be dropped just because active generated output omits it.
- Re-own the packet dispatcher at `0x0054c200` with this file during migration. It is currently labeled `Motion::HandleDialogPacket`, but IDA callers and callees tie it to message/menu-question dialog construction, not runtime motion/region behavior.
- `MenuQuestionItemList` and `MenuQuestionItemListLarger` are private support widgets for the menu-question constructors and should be kept with the dialog family unless later xrefs show broader reuse.
- `MessageShowPane` is physically near `Message` and behaviorally message-related, but it is a floating overlay rather than a packet dialog. It is now documented as a strong split candidate in [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md).
- Generic popup/menu infrastructure such as `MenuPane`/`MenuVarietyPane` and scrolling system messages such as `SystemMessagePane` are separate clusters; do not merge them into this source file solely because the names include "menu" or "message".
- Shared alert infrastructure belongs in [UID:0000HE][AlertPanes](by-file/AlertPanes.md). Keep only message/NPC packet dialog code here unless a derived alert is tightly coupled to this message family.
- The previous/next/current packet helpers at `0x0054cc30-0x0054ce0f` are shared with [UID:0000OL][TextDialog](by-file/TextDialog.md). Do not treat those helpers as private `TextDialog` methods during migration.
- The current `class_MessageDialog.cpp` emitted source contains placeholder `...` expressions, and `class_MenuQuestionDialogLarger.cpp` omits the constructor body despite Wave3/IDA confirming it. Treat the generated source as behavioral evidence, not migration-ready C++. Track the constructor omission under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The 2026-05-25 recheck confirms these are still current `simroot_v2` data/generation caveats, not stale notes from older output.

## Cross-References

- [UID:000084][Message](by-class/Message.md)
- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md)
- [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:000085][MessageDialog](by-class/MessageDialog.md)
- [UID:000086][MessageDialogLarger](by-class/MessageDialogLarger.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)

## Changes

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page already proposed `ui/dialogs/MessageDialogs.cpp`.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: current source-structure notes place the message/menu-question dialog family under `ui/dialogs/`, and the 2026-06-01 IDA MCP constructor recheck supports keeping `PursuitMessageDialogPane` under this source family for autogen parenting.

## Changes

- Before: the dialog packet dispatcher was documented only as `0x0054c200-0x0054c510`; shared dialog navigation helpers ended at `0x0054ce0e`.
- Changed to: the source-owned dispatcher/allocation-wrapper island is documented as `0x0054c200-0x0054caa9`, and shared dialog navigation helpers end at `0x0054ce0f`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054c200-0x0054c511` is the main dispatcher, `0x0054c570-0x0054caa9` is related dialog allocation wrappers, and `0x0054ce0e` is the final byte of `SendDialogPacketCurrent`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: message/menu-question dialog family, dispatcher/wrapper ownership, `MessageShowPane` split, raw base constructor, shared virtual/navigation helpers, IDA evidence, generated omissions, and ownership notes are documented; confidence is capped by generated source placeholders and final split between message model, overlay pane, and packet-dialog source.
