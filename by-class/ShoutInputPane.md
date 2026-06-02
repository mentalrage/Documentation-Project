*** UID:0000D5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ShoutInputPane

## Status

- Confidence: strong for confirmed behavior, constructor boundary, vtable slots, and `SayInputPanes` ownership.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md), submit body [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md), plus helper at [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_ShoutInputPane.cpp`

## Class Purpose

`ShoutInputPane` is the shout chat input pane. It uses the shout prefix prompt, trims and normalizes text, and sends opcode `0x0e`, subtype `1`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateShoutInputPane` | `0x005a5710-0x005a5791` | Allocates and initializes a shout input pane from the mode-opening flow. |
| `ShoutInputPane` | [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) | Raw constructor-shaped body; IDA reports no function object but disassembly proves prompt/base-constructor/vtable initialization. |
| `OnSubmitInput` | `0x005b4260-0x005b43bc` | Sends opcode `0x0e`, subtype `1` shout chat packet. |

## Evidence Notes

- IDA MCP confirms `0x005a5710` and `0x005b4260`.
- IDA MCP reports no function at `0x005b4220`, but 2026-06-02 raw disassembly proves [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) as the constructor-shaped body.
- Constructor evidence: prompt string `L"! "` at `0x00630a6c`, base constructor call `0x004f1c00`, primary vtable `0x0062fd00`, secondary vtable `0x0062fd50`, tertiary vtable `0x0062fd80`.
- Vtable evidence: primary slot `0x0062fd48 -> 0x005b4260`; creator helper `0x005a5710` references the same prompt and vtable addresses.
- `OpenInputPaneForCurrentMode` calls `CreateShoutInputPane` when chat mode is `1`.

## Reconstruction Notes

This class is reconstructable and attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). Leave C++ blank until the base input-pane layout, subobject names, singleton/global names, and packet helper names are final-source quality.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md)
- [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `76`.
- Evidence: the page documents chat purpose, file ownership, confirmed submit/factory helpers, opcode/subtype behavior, and constructor-boundary caveat; confidence remains capped because the projected constructor is not an IDA function.
- 2026-06-02 constructor split:
  - Before: the constructor was only listed as an IDA-missing projected start at `0x005b4220`.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and linked exact raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md).
  - Evidence: IDA raw disassembly confirms the prompt string, base constructor call, vtable stores, creator xrefs, and submit vtable slot.
