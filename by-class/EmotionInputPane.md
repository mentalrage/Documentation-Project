*** UID:00004B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- IDA MCP refresh on 2026-06-02 confirms constructor callers at `0x005a6138`, `0x005a9390`, and the `?` help/menu reopen path at `0x005b2f38`; `OnCharInput` is reached through vtable data xref `0x0062fa00`.
- IDA MCP confirms two menu-backend branches in `OnCharInput`: when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`, the help/menu path uses `dword_67ADC4` and helpers `0x005854b0`/`0x005854d0`/`0x00585560`/`0x00585360`; otherwise it uses `dword_69B4C8` and helpers `0x00589330`/`0x00589350`/`0x00589470`/`0x005892a0`.
- IDA MCP confirms the adjacent alignment spans `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` are pure `0xcc` bytes, so the class/helper boundary is now proven before `ChangeItemSlotInputPane`.
- Wave3 method notes explicitly state the current code override is a struct definition rather than the function body; track this under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The class belongs with command input panes rather than item action panes.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A008 alias cleanup: normalized the `OnCharInput` `byte_66DA97` menu-backend branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/74`.
  - Summary/evidence: prompt role, constructor, `OnCharInput` behavior, private packet helper, vtable stores, localized menu behavior, and missing emitted-body issue are documented; confidence remains limited because active generated output still lacks the real `OnCharInput` body.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
  - Why: exact constructor/handler/helper ranges, constructor callers, vtable slot evidence, menu-mode branches, packet helper ownership, and padding boundaries are documented. C++ remains blank because final source names and menu object types are not final-source quality.
