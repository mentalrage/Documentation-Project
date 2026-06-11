*** UID:000308 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChatInputPane

## Status

- Address: `0x0069bf68`.
- Storage page: [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md)
- Kind: process-wide singleton pointer to [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md).
- Proposed owner module: [UID:0000I5][Chatting](by-file/Chatting.md).
- Evidence basis: live IDA MCP xrefs and disassembly rechecked on 2026-06-07.

## Role

`g_pChatInputPane` stores the active chat-line input pane. It is checked before opening chat input from user-key paths, written by the raw ChatInputPane constructor body, and cleared by the scalar deleting destructor path.

This is the exact global page for the four-byte storage slot formerly documented only inside the mixed [UID:0002A3][0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals](by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md) range.

## Lifecycle Evidence

- Static image value: IDA MCP `py_eval` on 2026-06-07 reads `0x0069bf68` as `0xffffffff`.
- Open/create checks: IDA MCP `xrefs_to 0x0069bf68` reports reads in `sub_5A5BD0` at `0x005a5d0e`, `0x005a5d53`, and `0x005a5d5a`.
- Constructor-style publisher: raw constructor body [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md) writes the slot at `0x005b3908`.
- Alternate open path: IDA disassembly of `0x005a95e0-0x005a9686` checks the slot at `0x005a9604`, allocates `0x10c` bytes, calls the line-input base constructor with the `">"` prompt, writes the pointer at `0x005a9646` or zero at `0x005a964d`, installs the three `ChatInputPane` vtables, and initializes the history cursor sentinel at `this+0x108`.
- Teardown: IDA disassembly of `0x005b7980-0x005b79c2` clears the slot at `0x005b7986`, then runs the base cleanup and optional delete path.

## Ownership Decision

Attach this global to [UID:0000I5][Chatting](by-file/Chatting.md), not to a generic keyboard/input module. The storage is a `ChatInputPane` singleton; the owning class page and `Chatting` file page already document the chat history, packet-send, prompt, vtable, and destructor evidence for this pane.

The direct storage page can attach here once both pages clear the corrected `85/85` gate. Final C++ remains blank until the surrounding chat input class, base input hierarchy, and initializer semantics are final-source quality.

## Assignment Gate

This global page is assigned to [UID:0000I5][Chatting](by-file/Chatting.md), currently `85/88`. The relationship is direct because `g_pChatInputPane` is the file-level singleton for the chat input pane family, and the owner file already clears the corrected parent gate.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md)
- [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md)
- [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md)

## Changes

- 2026-06-07 A006 Batch 060 split support:
  - Created as the canonical global page for the `0x0069bf68` ChatInputPane singleton slot split out of the mixed keyboard command-state range.
  - Evidence: IDA MCP `xrefs_to` and disassembly confirm static `0xffffffff` storage, open-path checks, raw constructor write, alternate allocation/publish path, destructor clear, and Chatting owner linkage.
