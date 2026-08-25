*** UID:000308 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChatInputPane;

ChatInputPane *g_pChatInputPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChatInputPane

## Status

- Address: `0x0069bf68`.
- Storage page: [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md)
- Kind: process-wide singleton pointer to [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md).
- Proposed owner module: [UID:0000I5][Chatting](by-file/Chatting.md).
- Evidence basis: live IDA MCP xrefs and disassembly rechecked on 2026-06-07, with B011 current-value refresh on 2026-06-25.

## Role

`g_pChatInputPane` stores the active chat-line input pane. It is checked before opening chat input from user-key paths, written by the raw ChatInputPane constructor body, and cleared by the scalar deleting destructor path.

This is the exact global page for the four-byte storage slot formerly documented only inside the mixed [UID:0002A3][0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals](by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md) range.

Source-facing declaration model:

```cpp
extern ChatInputPane *g_pChatInputPane;
```

B011's 2026-06-25 MCP refresh supersedes the older support-page `0xffffffff` current-value wording for the active IDB: `get_global_value 0x0069bf68` reads `0x0`, `get_bytes 0x0069bf68 size 16` reads all zero bytes, and the same eight lifecycle xrefs remain. The open/create paths check and publish the slot like an active singleton pointer, and the destructor clears it to null; class or file C++ must not encode `reinterpret_cast<ChatInputPane *>(-1)`.

## Lifecycle Evidence

- Current active-IDB value: B011 live IDA MCP session `80de0a67` on 2026-06-25 reads `get_global_value 0x0069bf68 -> 0x0` (command id `305`) and `get_bytes 0x0069bf68 size 16 ->` sixteen zero bytes (command id `306`). The earlier 2026-06-07 `0xffffffff` sample is historical/superseded for current storage and is not source-initializer proof.
- Open/create checks: IDA MCP `xrefs_to 0x0069bf68` reports reads in `sub_5A5BD0` at `0x005a5d0e`, `0x005a5d53`, and `0x005a5d5a`.
- Constructor-style publisher: raw constructor body [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) writes the slot at `0x005b3908`.
- Alternate open path: IDA disassembly of `0x005a95e0-0x005a9686` checks the slot at `0x005a9604`, allocates `0x10c` bytes, calls the line-input base constructor with the `">"` prompt, writes the pointer at `0x005a9646` or zero at `0x005a964d`, installs the three `ChatInputPane` vtables, and initializes the history cursor sentinel at `this+0x108`.
- Teardown: IDA disassembly of `0x005b7980-0x005b79c2` clears the slot at `0x005b7986`, then runs the base cleanup and optional delete path.

## Ownership Decision

Attach this global to [UID:0000I5][Chatting](by-file/Chatting.md), not to a generic keyboard/input module. The storage is a `ChatInputPane` singleton; the owning class page and `Chatting` file page already document the chat history, packet-send, prompt, vtable, and destructor evidence for this pane.

The direct storage page is attached here because both pages clear the corrected `85/85` gate. Formal C++ now carries the source-facing singleton declaration/definition with `NULL` initialization; executable lifecycle behavior still lives on the constructor/destructor pages, and the current zero/null MCP value does not justify a sentinel or explicit fixed-address initializer.

## Assignment Gate

This global page is assigned to [UID:0000I5][Chatting](by-file/Chatting.md), currently `85/88`. The relationship is direct because `g_pChatInputPane` is the file-level singleton for the chat input pane family, and the owner file already clears the corrected parent gate.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) - adjacent no-route raw packet island; semantic neighborhood only.
- [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md)
- [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md)

## Changes

- 2026-06-30 B005 UID0000I5 empty-emitter family callback: inserted formal VC-era singleton definition `ChatInputPane *g_pChatInputPane = NULL;` with an ordinary forward declaration, raised score to `87/90`, and kept owner/emitter route [UID:0000I5][Chatting](by-file/Chatting.md). Accepted evidence: active MCP `supervisor_resume_20260629` reads `0x0069bf68` as zero/null storage with eight xrefs across key-open checks, alternate allocation/publish path, raw constructor write, destructor clear, and the direct parent storage page [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md).
- 2026-06-07 A006 Batch 060 split support:
  - Created as the canonical global page for the `0x0069bf68` ChatInputPane singleton slot split out of the mixed keyboard command-state range.
  - Evidence: IDA MCP `xrefs_to` and disassembly confirmed the then-recorded storage sample, open-path checks, raw constructor write, alternate allocation/publish path, destructor clear, and Chatting owner linkage.
- 2026-06-19 B014 class source-quality sync:
  - Kept owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md) and documented the source-facing declaration as `extern ChatInputPane *g_pChatInputPane`.
  - Evidence: B014 compared the raw constructor write, `0x005a5bd0` and `0x005a95e0` open/allocation branches, and `0x005b7980` destructor clear, then kept the apparent `0xffffffff` static image value as an initializer ambiguity to solve on the storage/global pages rather than in `ChatInputPane` class C++.
- 2026-06-25 B011 accepted implementation support sync:
  - At that time metadata remained `86/88`, owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md), and formal C++ remained blank; the formal global definition and `87/90` score are superseding 2026-06-30 B005 callback updates.
  - Evidence: MCP command ids `304`-`307` prove the current active-IDB value for `0x0069bf68` is zero/null, the adjacent split-map bytes are zero-filled, and the same eight lifecycle xrefs remain. The older `0xffffffff` wording is now historical/superseded rather than current storage truth.
