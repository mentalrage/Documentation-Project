*** UID:0000SZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HandleLegacyMainMenuPacket_4F8D00

## Status

- Confidence: medium for exact protocol role; strong for ownership and range.
- Address range: [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md)
- Symbol kind: file-local pre-login packet helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Current generated evidence: `source-3/simroot_v2/class_MainMenuPane.cpp` declares `HandleLegacyMainMenuPacket_4F8D00` and calls it from `MainMenuPane::OnServerMessage`, but the active generated file does not emit the helper body.

## Behavior

`HandleLegacyMainMenuPacket_4F8D00` handles pre-login server-message opcode `3` from `MainMenuPane::OnServerMessage`.

Observed behavior:

- parses a big-endian 32-bit value from `payload + 1`;
- parses a big-endian 16-bit value from `payload + 5`;
- reads a one-byte string length at `payload + 7`;
- copies the following byte string into a local buffer and NUL-terminates it;
- checks the shared packet/session object at `dword_67A7EC`;
- on a failed status response, constructs an `AlertPane` with localized string id `157` and requests application exit;
- builds an outbound packet beginning with opcode `0x10`, appends the copied text and current menu layout flag, then queues it through the shared packet sender;
- triggers the optional global modal callback at `dword_69AE08`;
- calls `MetaMan::LoadMetaDatAndRequestSync` through [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

The exact packet semantic name is still open. The durable ownership fact is that the only IDA caller is `MainMenuPane::OnServerMessage`, so the helper belongs with the pre-login main-menu module, not with `MetaMan` or packet-buffer utilities.

## Evidence

- IDA MCP `lookup_funcs 0x004f8d00` reports `sub_4F8D00`, size `0x202`.
- IDA MCP callers show a single caller at `0x004f74b7` inside `MainMenuPane::OnServerMessage`.
- IDA MCP callees include shared packet readers/writers, `CashShopRequest` send helpers, `AlertPane` construction, `Application::RequestExit`, `operator_new`, and `MetaMan::LoadMetaDatAndRequestSync`.
- Existing Wave2 report notes `MetaMan::LoadMetaDatAndRequestSync` is called from both `MainMenuPane::OnServerMessage` and this `0x004f8d00` helper path.

## Source Placement

Keep as a private/static helper in `login/MainMenuPane.cpp` or a small adjacent pre-login packet helper in the same module. Do not move this into [UID:0000LC][MetaMan](by-file/MetaMan.md): the metadata manager call is a side effect after this main-menu packet is processed.

## Cross-References

- [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `74/82`.
  - Before: page documented the pre-login packet helper behavior, caller/callee evidence, and source placement but remained unevaluated.
  - After: score reflects documented parsing/sending side effects, sole MainMenuPane caller, MetaMan interaction, and placement decision, with confidence limited by the unresolved exact packet semantic name.
  - Evidence: IDA notes confirm the helper size, single caller from `MainMenuPane::OnServerMessage`, packet readers/writers, alert/exit side path, optional modal callback, and metadata-sync call.
