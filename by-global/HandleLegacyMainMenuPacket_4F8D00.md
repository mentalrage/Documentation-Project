*** UID:0000SZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HandleLegacyMainMenuPacket_4F8D00

## Status

- Confidence: strong for caller, body, source placement, and side effects; medium for final protocol semantic name.
- Address range: [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md)
- Symbol kind: file-local pre-login packet helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Current source state: source placement is documented, but final C++ is intentionally blank until this reaches the 95/95 reconstruction bar.

## Behavior

`HandleLegacyMainMenuPacket_4F8D00` handles top-level pre-login server-message opcode `3` from `MainMenuPane::OnServerMessage`.

Observed behavior:

- parses a big-endian 32-bit value from `payload + 1`;
- parses a big-endian 16-bit value from `payload + 5`;
- reads a one-byte string length at `payload + 7`;
- copies the following byte string into a local buffer and NUL-terminates it;
- checks the shared packet/session object at [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`;
- when the packet/session status probe succeeds but the returned status byte is false, constructs an `AlertPane` with localized string id `157` and requests application exit through the application object;
- builds an outbound packet beginning with opcode `0x10`, appends the copied text, appends [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, zero-terminates the scratch byte after the sent payload, then queues `length + 2` bytes through the shared packet sender;
- resets/opens the packet/session send state before the queue call;
- triggers the optional global dimmer/modal callback at `dword_69AE08` with flag `1`;
- calls `MetaMan::LoadMetaDatAndRequestSync` through [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

The exact packet semantic name is still open. The durable ownership fact is that the only live IDA caller is the `case 3` path in `MainMenuPane::OnServerMessage`, so the helper belongs with the pre-login main-menu module, not with `MetaMan` or packet-buffer utilities.

## Evidence

- Live IDA MCP on 2026-06-04 confirms `sub_4F8D00` at `0x004f8d00` with size `0x202`.
- IDA MCP `callers 0x004f8d00` reports one direct caller: `0x004f74b7` inside `sub_4F6D80`.
- IDA MCP decompilation of `sub_4F6D80` shows that call is the top-level `case 3` return path for `MainMenuPane::OnServerMessage`, passing `this - 40` and the message payload pointer from `a2 + 12`.
- IDA MCP decompilation of `sub_4F8D00` confirms reads at payload offsets `+1`, `+5`, and `+7`, the bounded local copy from `payload + 8`, the failed-status `AlertPane` / application-exit branch, outbound opcode `0x10`, appended `byte_66DA97`, send length `stringLength + 2`, optional `dword_69AE08` callback, and final `sub_5228F0(dword_69B410)` metadata-sync call.
- IDA MCP callees for `0x004f8d00` include packet helpers `0x00575380`, `0x00575480`, `0x005754c0`, `0x00574b30`, `0x00574b50`, `0x00574bb0`, and `0x00574cd0`, allocator `0x004f4aa0`, `AlertPane` constructor `0x0049feb0`, application-exit helper `0x00464e40`, and metadata sync at `0x005228f0`.
- IDA MCP disassembly confirms the helper is a `thiscall`-shaped function ending with `retn 4`, with the local 256-byte inbound string buffer and larger outbound scratch buffer visible in the stack frame.

## Source Placement

Keep as a private/static helper in `login/MainMenuPane.cpp` or a small adjacent pre-login packet helper in the same module. Do not move this into [UID:0000LC][MetaMan](by-file/MetaMan.md): the metadata manager call is a side effect after this main-menu packet is processed.

## Autogen Status

- Reconstructable: true as a source-owned private helper under the main-menu login module.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The parent records this helper as part of `login/MainMenuPane.cpp`, and the live caller is the `MainMenuPane::OnServerMessage` opcode-`3` dispatch path.
- Code: intentionally blank. The helper body is well described, but the packet semantic name and final source-facing helper/type names are not strong enough for 95+/95+ C++ reconstruction.

## Score Rationale

- Completion is now 84 because the page records the exact boundary, caller dispatch, payload offsets, packet/session interactions, failed-status alert path, outbound opcode shape, layout-flag append, optional callback, metadata-sync side effect, and source placement.
- Confidence is now 88 because live IDA directly proves the single caller, decompiled control flow, callees, stack buffers, and source-owner relationship through `MainMenuPane::OnServerMessage`.
- Remaining uncertainty is the final semantic name for the inbound opcode-`3` packet and a few shared packet/helper type names.

## Cross-References

- [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `74/82`.
  - Before: page documented the pre-login packet helper behavior, caller/callee evidence, and source placement but remained unevaluated.
  - After: score reflects documented parsing/sending side effects, sole MainMenuPane caller, MetaMan interaction, and placement decision, with confidence limited by the unresolved exact packet semantic name.
  - Evidence: IDA notes confirm the helper size, single caller from `MainMenuPane::OnServerMessage`, packet readers/writers, alert/exit side path, optional modal callback, and metadata-sync call.
- 2026-06-04 live IDA refresh:
  - Before: the page still included older non-IDA evidence and did not record the exact top-level dispatch or outbound packet shape from the current database.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Summary/evidence: live IDA MCP reconfirmed `sub_4F8D00` size `0x202`, single direct caller `0x004f74b7`, the `MainMenuPane::OnServerMessage` top-level `case 3` dispatch, payload reads at `+1`/`+5`/`+7`, the copied string from `payload + 8`, the failed-status `AlertPane`/exit branch, outbound opcode `0x10` with appended `byte_66DA97`, optional `dword_69AE08` callback, and final `g_pMetaMan` metadata-sync call. C++ remains blank because the helper has not reached the 95/95 reconstruction threshold.
