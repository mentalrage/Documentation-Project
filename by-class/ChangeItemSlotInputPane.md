*** UID:00001J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeItemSlotInputPane

## Status

- Confidence: strong for handler behavior, raw constructor bytes, vtable identity, and module placement; medium for raw-constructor reachability/modeling.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md), methods [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp`

## Class Purpose

`ChangeItemSlotInputPane` is the command prompt for moving an item from one inventory slot letter to another. It expects comma-separated slot letters, validates both against the local inventory slot count, and sends a change-slot packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChangeItemSlotInputPane` | `0x005b2fd0-0x005b3010` | Raw constructor-shaped body; IDA does not recognize this as a function start. |
| `HandleInputEvent` | `0x005b3010-0x005b307c` | Handles the `?` help-panel shortcut by switching `g_pGeneralPurposePanel` to tab `2`, plays sound `0x198`, otherwise delegates to `CharArgsInputPane`. |
| `OnSubmitInput` | `0x005b3080-0x005b3196` | Parses `source,dest` slot letters, validates both against the active user/status inventory slot count, and sends opcode `0x30` subcommand `0`. |

## Evidence Notes

- IDA MCP confirms `0x005b3010` and `0x005b3080`.
- IDA reports no function at `0x005b2fd0`.
- IDA recheck on 2026-05-26 resolves preceding real function `0x005b2f70-0x005b2fcb` as the [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) packet helper, not this class's constructor.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b2fd0-0x005b3010`: localized prompt id `0x2e`, `CharArgsInputPane` base construction, and vtable stores to `0x0062fa44`, `0x0062fa94`, and `0x0062fac4`.
- 2026-05-27 IDA decompilation confirms `OnSubmitInput` reads text through the shared input getter, splits on comma, maps `a-z` to `1-26` and `A-Z` to `27-52`, reads max slots from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) at `+0x284`, and sends `[0x30, 0, source, dest]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- 2026-06-02 IDA MCP refresh confirms `HandleInputEvent` is vtable-reached from secondary slot `0x0062fa9c`, `OnSubmitInput` is vtable-reached from primary slot `0x0062fa8c`, and the raw constructor stores are also duplicated by command/factory construction paths at `0x005a617d/0x005a6185/0x005a618f` and `0x005a9406/0x005a940c/0x005a9416`.
- IDA MCP confirms internal alignment padding at `0x005b307c-0x005b3080` and `0x005b3196-0x005b31a0`, plus the preceding Emotion-helper alignment at `0x005b2fcb-0x005b2fd0`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- What existed before: the page documented behavior, raw constructor evidence, submit parsing, globals, and packet sender usage, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: IDA-confirmed handler/submission behavior and raw constructor disassembly support the class identity; unresolved constructor reachability and final layout keep the page below complete.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Why: exact raw constructor bytes, vtable store/call-site evidence, virtual slot refs, event shortcut behavior, submit parser, packet layout, status-pane slot-count read, and padding boundaries are documented. C++ remains blank because final helper names and source spelling are below the 95% bar.
