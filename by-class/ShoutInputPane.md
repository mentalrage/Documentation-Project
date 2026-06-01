*** UID:0000D5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ShoutInputPane

## Status

- Confidence: strong for confirmed behavior; medium for constructor boundary.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md), plus helper at [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_ShoutInputPane.cpp`

## Class Purpose

`ShoutInputPane` is the shout chat input pane. It uses the shout prefix prompt, trims and normalizes text, and sends opcode `0x0e`, subtype `1`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateShoutInputPane` | `0x005a5710-0x005a5791` | Allocates and initializes a shout input pane from the mode-opening flow. |
| `ShoutInputPane` | `0x005b4220` | Wave3 projected constructor; IDA reports this is not a function. |
| `OnSubmitInput` | `0x005b4260-0x005b43bc` | Sends opcode `0x0e`, subtype `1` shout chat packet. |

## Evidence Notes

- IDA MCP confirms `0x005a5710` and `0x005b4260`.
- IDA MCP reports no function at `0x005b4220`.
- `OpenInputPaneForCurrentMode` calls `CreateShoutInputPane` when chat mode is `1`.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `76`.
- Evidence: the page documents chat purpose, file ownership, confirmed submit/factory helpers, opcode/subtype behavior, and constructor-boundary caveat; confidence remains capped because the projected constructor is not an IDA function.
