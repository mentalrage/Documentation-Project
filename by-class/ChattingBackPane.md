*** UID:00001R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingBackPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingBackPane.cpp`
- Autogen handling: attached to [UID:0000I5][Chatting](by-file/Chatting.md) after the exact constructor/destructor/update child pages and singleton/vtable evidence brought the class above the 80/80 attachment gate; reconstructed C++ remains blank below the final-source gate.

## Class Purpose

`ChattingBackPane` is the translucent background behind the chat display. It follows `ChattingHandlePane` mode/expanded state and adjusts visibility, alpha, and text color.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingBackPane` | [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) | Constructs a `Pane`, sets `g_pChattingBackPane`, installs vtables, and initializes background alpha to `0.6f`. |
| `~ChattingBackPane` body | [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Clears `g_pChattingBackPane` and tail-calls base pane teardown. |
| `UpdateVisibility` | [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) | Reads chat handle state and updates visibility/alpha/text color before refreshing the pane rectangle. |
| `ScalarDeletingDestructor` | `0x00483aa0` | Clears `g_pChattingBackPane` and destroys the base pane. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) | Exact constructor child records the single `InitializeMainUiGraph` allocation/call site, base `Pane` constructor call, `g_pChattingBackPane` store, three vtable writes, `0.6f` alpha initialization, and closed `0xcc` padding. |
| [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Exact destructor-body child records vtable restores, singleton clear at `0x0067add0`, base-destructor tail jump, mirrored scalar-deleting wrapper evidence, and no direct compact-body xrefs. |
| [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) | Exact virtual-method child records the vtable-only slot, `dword_67ADE0 +0x114/+0x118` state gates, `0.7f`/`0.3f` alpha choices, `PaneSetMode` transitions, draw-color setter calls, and surface refresh callback. |
| [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) | Identifies the adjacent UI/chat singleton slot that this class writes, reads through consumers, and clears during teardown. |

## Evidence Notes

- IDA MCP confirms exact ranges for the constructor, destructor body, viewport helper, and update virtual in the `0x00480640-0x004807aa` cluster.
- `xrefs_to 0x00480740` reports a vtable data xref at `0x00614dd4`, supporting the update method as a `ChattingBackPane` virtual.
- The update method reads chat handle/global state at `dword_67ADE0 + 0x114/+0x118`, supporting placement with the chat module while leaving final field names open.

## Score Rationale

- Completion is raised to `82` because the class now has exact constructor, destructor-body, and update-virtual children; documented singleton lifecycle; vtable evidence; source-file ownership through [UID:0000I5][Chatting](by-file/Chatting.md); and explicit final-code blockers.
- Confidence remains `88` because the binary evidence is strong, but source-quality names for the base constructor/destructor helpers, the `dword_67ADE0` chat-handle fields, the `+0x90` alpha member, and the original virtual name are still unresolved.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md)
- [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md)
- [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md)
- [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)

## Changes

- What existed before: the page documented purpose, methods, and chat-module ownership, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: constructor, update, destructor, and chat globals are clear; detailed fields and final header/code form are still light.
- 2026-05-31: Updated completion/confidence from `70/86` to `76/88` after creating exact by-memory pages for the constructor, destructor body, and update virtual and linking the existing viewport helper. Evidence: IDA MCP function iteration, decompilation, xrefs, vtable data audit, and raw byte audit.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor, destructor body, update virtual, and scalar deleting destructor starts at `0x00480640`, `0x004806a0`, `0x00480740`, and `0x00483aa0`, and `callers` shows construction from main chat UI initialization. `AUTOGEN_PARENT_UID` remains blank even though [UID:0000I5][Chatting](by-file/Chatting.md) is the likely owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07 A004: Completion changed from `76` to `82`, confidence remains `88`, and `AUTOGEN_PARENT_UID` was set to [UID:0000I5][Chatting](by-file/Chatting.md).
  - Summary/evidence: added an evidence map for the exact constructor/destructor/update children, singleton slot, and vtable/update behavior; the class now clears the 80/80 attachment gate while final source C++ remains blank.
  - Remaining blockers: source-quality names for the base pane helpers, chat-handle state fields, alpha member, and update virtual remain unresolved.
