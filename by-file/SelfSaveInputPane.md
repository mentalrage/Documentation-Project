*** UID:0000NM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SelfSaveInputPane

## Status

- Confidence: medium-high for behavior; medium for final source grouping.
- Proposed owner: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), likely as a small command-prompt class.
- Current generated source: `source-3/simroot_v2/class_SelfSaveInputPane.cpp`
- Main address docs: [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md) and [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)

## File Role

`SelfSaveInputPane` is a `CharInputPane`-derived confirmation prompt. It asks for one character, accepts only `y` or `Y`, then sends a one-byte packet with opcode `0x25` through the shared packet queue at `dword_67A7EC`.

The class sits in the same command-input neighborhood as spell and block-list prompt classes. Current evidence favors folding it into [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) rather than creating a final standalone `SelfSaveInputPane.cpp`, even though Wave2 metadata names a one-class source file.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SelfSaveInputPane` constructor body | `0x005b67c0-0x005b67ff`; IDA does not currently model it as a function | Calls `CharInputPane::CharInputPane` with localized string id `0x26` and installs three vtables. |
| `SelfSaveInputPane::OnConfirmInput` | `0x005b6800-0x005b686b` | Requires one-character input, accepts `y`/`Y`, writes opcode `0x25`, and queues a one-byte packet. |
| raw send helper | `0x005b6870-0x005b68b0`; raw code, not an IDA function | Sends opcode `0x25` without reading input. Relationship to the prompt is likely but not proven. |
| factory/open helper | `0x005aa140-0x005aa1bf` | Allocates 264 bytes, constructs the same `CharInputPane`/`SelfSaveInputPane` layout inline, and returns the object. |

## Boundary Notes

- `0x005b68c0` starts the block-list input pane neighborhood. Do not extend this file range into [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
- The generated `g_packetSender` type remains unresolved across the project. Here it is the shared sender at `dword_67A7EC`, tracked as [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and passed into the broad `QueueAndSendPacket` path documented under [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) and [UID:0001QH][client_network](by-meta/client_network.md).
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) is related by feature name but currently has a separate, far earlier `TextBoxPane` island and polluted generated ownership. Do not merge the two solely by name.

## IDA MCP Evidence

2026-05-25 recheck using current `simroot_v2` plus IDA MCP:

- `lookup_funcs` still reports `0x005b67c0` and `0x005b6870` as `Not a function`; raw disassembly confirms complete constructor/send-helper bodies.
- `lookup_funcs` confirms `0x005b6800` as `sub_5B6800` with size `0x6c` and `0x005aa140` as `sub_5AA140` with size `0x80`.
- `callers` reports no direct callers for `0x005b6800`, `0x005b6870`, or `0x005aa140`; `xrefs_to 0x005b6800` reports the vtable data ref at `0x00630608`.
- `dword_67A7EC` has 489 IDA xrefs, with SelfSave-local uses at `0x005b6845` and `0x005b688b`, confirming the sender global is broad network state rather than SelfSave-owned storage.

2026-05-26 recheck using current `simroot_v2` plus IDA MCP:

- Active `class_SelfSaveInputPane.cpp` still emits only the constructor and `OnConfirmInput`; the raw send helper at `0x005b6870` and factory/open helper at `0x005aa140` remain absent from the active source view.
- `lookup_funcs`, `callers`, and `xrefs_to` results are unchanged: `0x005b67c0` and `0x005b6870` are still not modeled functions, `0x005b6800` remains a `0x6c`-byte function with only the vtable data ref, and `0x005aa140` remains a `0x80`-byte function with no direct callers.
- IDA MCP `disasm` reconfirmed the raw helper `0x005b6870-0x005b68b0` writes opcode `0x25`, appends a zero byte, and queues one byte through `dword_67A7EC`.
- IDA MCP `py_eval` reconfirmed 489 xrefs to `dword_67A7EC`.

## Cross-References

- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `76`.
  - Evidence: document covers prompt behavior, proposed ownership, raw constructor/send helper, factory/open helper, packet-sender dependency, boundary notes, two IDA rechecks, and cross-references; confidence is capped by raw unmodeled starts and final grouping under command input panes.
