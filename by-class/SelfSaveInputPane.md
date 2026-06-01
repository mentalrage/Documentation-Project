*** UID:0000CW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfSaveInputPane

## Status

- Confidence: medium-high.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) or generated quarantine page [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_SelfSaveInputPane.cpp`
- Current Wave3 grade: `97.5`
- Current Wave3 coverage: 2 modeled methods.

## Class Purpose

`SelfSaveInputPane` is a [UID:00001P][CharInputPane](by-class/CharInputPane.md) derivative for self-save confirmation. It requires a single-character answer and sends opcode `0x25` only when the user enters `y` or `Y`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005b67c0-0x005b67ff` | Calls `CharInputPane::CharInputPane` with localized string id `0x26` and installs three `SelfSaveInputPane` vtables. IDA currently does not model this start as a function. |
| `OnConfirmInput` | `0x005b6800-0x005b686b` | Checks input length, reads one UTF-16 character, accepts `y`/`Y`, builds packet opcode `0x25`, and queues a one-byte send. |

## Evidence Notes

- 2026-05-25 IDA MCP recheck confirms the same boundary shape: raw constructor at `0x005b67c0`, real handler at `0x005b6800`, raw send helper at `0x005b6870`, and real factory at `0x005aa140`.
- 2026-05-26 IDA MCP recheck reports the same shape: `0x005b67c0` and `0x005b6870` are still not IDA functions, `0x005b6800` is still size `0x6c`, and `0x005aa140` is still size `0x80`.
- IDA confirms `0x005b6800` as a real function and shows a vtable data reference from `0x00630608`.
- IDA MCP confirms three `SelfSaveInputPane` vtable views at `0x006305c0`, `0x00630610`, and `0x00630640`, with stores in both the factory/open helper at `0x005aa140` and raw constructor-shaped bytes at `0x005b67c0`.
- IDA reports `0x005b67c0` as "Not a function", but disassembly is constructor-shaped and matches the generated source.
- IDA vtable xrefs show a separate factory at `0x005aa140` installing the same `SelfSaveInputPane` vtables inline.
- The adjacent raw helper at `0x005b6870` sends the same opcode `0x25` without checking input; it should be reviewed with this class before migration.
- Sender storage is the shared [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`, not a SelfSave-specific global.
- Current `simroot_v2/class_SelfSaveInputPane.cpp` still omits the `0x005b6870` raw helper and the `0x005aa140` factory/open helper.

## Cross-References

- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `76`.
- Evidence: the page documents the confirmation role, vtable family, constructor-shaped bytes, real input handler, opcode behavior, shared packet sender, and factory/open-helper caveats; completion remains limited because the raw send helper and factory ownership still need final placement.
