*** UID:0000QJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCheatDetector

## Status

- Confidence: strong for address and singleton role.
- Address: [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- Likely owner file: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)

## Purpose

`g_pCheatDetector` stores the active process-wide [UID:000020][CheatDetector](by-class/CheatDetector.md) singleton. Startup allocates the object during `Application::Initialize`, the constructor stores the pointer, and destructor/clear helpers reset it.

## Evidence Notes

- IDA MCP decompilation of `0x00483f00` writes `dword_67AB3C = this`.
- IDA MCP decompilation of `0x00483ff0` and `0x00484000` clears `dword_67AB3C`.
- 2026-05-24 IDA recheck found five data refs: startup cleanup at `0x00464ba0`, constructor writes at `0x00483f33` and `0x00483f3a`, clear helper `0x00483ff0`, and scalar deleting destructor `0x0048400f`.
- 2026-05-26 exact memory page: [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md). The same pass kept `0x00483ff0` as a real clear helper omitted by active output.
- Generated active source names the same storage `g_pCheatDetector`.

## Cross-References

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/86`. Summary/evidence: the page documents address/memory page, singleton purpose, startup allocation, constructor/destructor/clear evidence, IDA recheck refs, generated source name, and anticheat refs.
