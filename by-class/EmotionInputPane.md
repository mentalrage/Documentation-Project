*** UID:00004B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmotionInputPane

## Status

- Confidence: medium; behavior is understood from IDA boundaries/decompilation, but the current emitted `OnCharInput` body is missing.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Address range: [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), helper [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_EmotionInputPane.cpp`

## Class Purpose

`EmotionInputPane` is the command prompt for choosing an emotion. It formats a localized prompt with the maximum emotion count and handles character input for emotion indices and the emotion menu shortcut.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EmotionInputPane` | `0x005b29c0-0x005b2a70` | Constructs the `CharInputPane`, installs vtables, and formats the prompt. |
| `OnCharInput` | `0x005b2a70-0x005b2f68` | Reads one character, lowercases `A-Z`, maps `a` through `p` through the emotion packet helper, and opens the localized emotion menu on `?`; emitted code is incomplete. |
| `SendEmotionPacket` | `0x005b2f70-0x005b2fcb` | Private helper called only by `OnCharInput`; writes opcode `0x1d` and queues the normalized emotion selector packet. |

## Evidence Notes

- IDA MCP confirms both function starts.
- IDA MCP confirms three `EmotionInputPane` vtable views at `0x0062f9b8`, `0x0062fa08`, and `0x0062fa38`, installed by constructor stores at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`.
- IDA MCP recheck on 2026-05-26 confirms the adjacent packet helper at `0x005b2f70` is only called by `OnCharInput`.
- IDA MCP decompile on 2026-05-26 confirms `OnCharInput` uses the shared one-character input helpers `0x004f2310`/`0x004f2300`, calls `SendEmotionPacket` from `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, and uses localized string ids `31` plus `15-30` when building the help/menu list.
- Wave3 method notes explicitly state the current code override is a struct definition rather than the function body; track this under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The class belongs with command input panes rather than item action panes.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/74`.
  - Summary/evidence: prompt role, constructor, `OnCharInput` behavior, private packet helper, vtable stores, localized menu behavior, and missing emitted-body issue are documented; confidence remains limited because active generated output still lacks the real `OnCharInput` body.
