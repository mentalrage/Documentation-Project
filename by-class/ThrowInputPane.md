*** UID:0000EY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for ThrowInputPane; exact Throw method bodies are documented in [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThrowInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b5960` help override is `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, otherwise use the existing base handler.
- Throw construction, selected-slot/target/packet behavior, children, vtable/compiler evidence, scores, route, formal block, and history remain unchanged. Stale `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` wording is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_ThrowInputPane.cpp`
- Reconstruction routing: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting range inventory, so it is not this class's C++ blocker. Future class source work should stay on this class or exact method/raw children.

## Class Purpose

`ThrowInputPane` is the item-throw prompt. It accepts a single inventory slot letter, validates the slot against inventory limits and player state, and sends the throw item packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ThrowInputPane` | `0x005b5890-0x005b5957` | Constructs the prompt with player name and installs vtables. |
| `OnCharInput` | `0x005b5960-0x005b59cc` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b59d0-0x005b5aac` | Converts slot letter and sends opcode `0x17`. |

## Evidence Notes

- Wave3 generated source shows the same slot-letter mapping used by neighboring item panes.
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x23`, calls `CharInputPane::CharInputPane`, gets the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, formats the prompt, and installs vtables `0x006301ec`, `0x0063023c`, and `0x0063026c`.
- IDA decompilation of `0x005b59d0` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, the accepted value is bounded by [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, and [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) offset `+0x3ec0` must be zero before sending.
- The packet is opcode `0x17`, mode byte `0`, selected slot byte, length `3`, sent through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The confirmation variant sends the same opcode with mode byte `1`.
- This is the direct throw action. [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md) is the confirmation prompt variant.
- 2026-06-25 B010 source-quality implementation confirms [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) as a no-code range inventory; the direct throw class behavior remains owned here and by exact child pages such as [UID:0003NX][0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw](by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact routed children can assemble under this route. Throw method source remains routed through the exact Throw/Use/Eat range and helper pages.
- Route proof: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) covers Throw constructor `0x005b5890-0x005b5957`, key handler `0x005b5960-0x005b59cc`, and submit path `0x005b59d0-0x005b5aac`. Exact retained raw helper evidence is [UID:0003NX][0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw](by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records Throw vtable slots.
- Rejected emission: a whole-class declaration/body would duplicate exact method/helper ranges while those remain separately documented.

## Changes

- 2026-06-07 A008 alias cleanup:
  - Before: constructor evidence used bare `dword_67A748` wording for the local-player name source.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the global page records `0x0067a748` as a broad player/client-state pointer, including item-command prompt views and the `+0x3ec0` busy gate.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented throw prompt constructor, character-input handler, and submit handler starts at `0x005b5890`, `0x005b5960`, and `0x005b59d0`; this page and parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) both met the then-current parent gate. No C++ was emitted in that pass; current routing treats [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) as a no-code range inventory rather than this class's source blocker.
- 2026-06-25 B010 Throw/Use/Eat aggregate source-quality sync:
  - Score unchanged at `86/90`.
  - Updated routing language so [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting inventory, not a class C++ blocker.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:90`.
  - Summary/evidence: scored from IDA-confirmed constructor/input/submit methods, prompt id, vtables, slot validation, packet opcode/mode bytes, and direct links to the relevant globals and confirmation variant.
