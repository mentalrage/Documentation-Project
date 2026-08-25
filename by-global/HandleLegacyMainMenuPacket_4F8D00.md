*** UID:0000SZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// HandleLegacyMainMenuPacket is emitted by exact helper [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md); this address-suffixed global page preserves packet-helper evidence without duplicating the body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HandleLegacyMainMenuPacket_4F8D00

## Status

- Confidence: strong for caller, body, source placement, side effects, and source-facing first-draft body on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md); medium-high for original opcode enum/PDB spelling.
- Address range: [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md)
- Symbol kind: file-local pre-login packet helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Current source state: alias/support page for the source-ready [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) by-memory target. The exact first-draft C++ body lives on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) and should not be duplicated here unless explicitly requested by a later supervisor instruction.

## Behavior

`HandleLegacyMainMenuPacket_4F8D00` is the address-suffixed alias for the source-facing `HandleLegacyMainMenuPacket` helper on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md). It handles top-level pre-login server-message opcode `3` from `MainMenuPane::OnServerMessage`. Current MCP keeps the conservative legacy-main-menu name after rejecting transfer-only, reconnect-only, meta-only, and login-redirect alternatives: the only live caller is the main-menu server-message handler, while the body combines reconnect endpoint parsing, a connection-status query, outbound opcode `0x10` construction, screen-dimmer deletion, and `Meta.dat` sync.

Observed behavior:

- parses a big-endian 32-bit value from `payload + 1`;
- parses a big-endian 16-bit value from `payload + 5`;
- reads a one-byte string length at `payload + 7`;
- copies the following byte string into a local buffer and NUL-terminates it;
- checks the shared packet/session object at [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`;
- when the Socket connection-state probe succeeds, posts command `6` through `Socket::PostReconnectEndpointCommand`, then posts command `0x0c` / 12 through `Socket::PostConnectionStatusQuery(bool *outConnected)`, waits with `Thread::WaitForResult`, and checks the returned boolean;
- when that returned connection/transport availability boolean is false, constructs an `AlertPane` with localized string id `157`, parent/layout reference `pane`, and null primary/secondary button-label pointers, then requests application exit through the application object;
- builds an outbound packet beginning with opcode `0x10`, appends the copied text, appends [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, zero-terminates the scratch byte after the sent payload, then queues `length + 2` bytes through the shared packet sender;
- resets/opens the packet/session send state before the queue call;
- deletes [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) / historical alias `dword_69AE08` if present through the scalar-deleting first virtual slot with flag `1`;
- calls `MetaMan::LoadMetaDatAndRequestSync` through [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

The 2026-06-13 IDA refresh records additional stack and boundary detail useful for future reconstruction: the body is `0x202` / 514 bytes (Verified with int_convert.py), uses a 256-byte inbound string buffer (`0x100` / 256, Verified with int_convert.py), uses a 1023-byte outgoing tail buffer (`0x3ff` / 1023, Verified with int_convert.py), allocates `0x270` / 624 bytes for the failed-status `AlertPane` path (Verified with int_convert.py), requests localized string id `0x9d` / 157 (Verified with int_convert.py), and ends with `retn 4` before fourteen `0xcc` alignment bytes.

The exact opcode enum spelling is not recovered from symbols, but the current source-facing helper name is no longer a blocker: `HandleLegacyMainMenuPacket` is conservative, caller-local, and source-shaped. It belongs with the pre-login main-menu module, not with `MetaMan`, PacketBuffer utilities, Socket, ScreenDimmer, AlertPane, DATFile, or a no-owner bucket.

## Evidence

- Live IDA MCP on 2026-06-04 confirms `sub_4F8D00` at `0x004f8d00` with size `0x202`.
- IDA MCP `callers 0x004f8d00` reports one direct caller: `0x004f74b7` inside `sub_4F6D80`.
- IDA MCP decompilation of `sub_4F6D80` shows that call is the top-level `case 3` return path for `MainMenuPane::OnServerMessage`, passing `this - 40` and the message payload pointer from `a2 + 12`.
- IDA MCP decompilation of `sub_4F8D00` confirms reads at payload offsets `+1`, `+5`, and `+7`, the bounded local copy from `payload + 8`, the failed-status `AlertPane` / application-exit branch, outbound opcode `0x10`, appended [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, send length `stringLength + 2`, optional `dword_69AE08` callback, and final `sub_5228F0(dword_69B410)` metadata-sync call.
- IDA MCP callees for `0x004f8d00` include packet helpers `0x00575380`, `0x00575480`, `0x005754c0`, `0x00574b30`, `0x00574b50`, `0x00574bb0`, and `0x00574cd0`, allocator `0x004f4aa0`, `AlertPane` constructor `0x0049feb0`, application-exit helper `0x00464e40`, and metadata sync at `0x005228f0`.
- IDA MCP disassembly confirms the helper is a `thiscall`-shaped function ending with `retn 4`, with the local 256-byte inbound string buffer and larger outbound scratch buffer visible in the stack frame.
- 2026-06-13 IDA MCP `server_health` reported the active read-only `NexusTK.exe` database with image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- 2026-06-13 `lookup_funcs` reconfirmed `sub_4F8D00` at `0x004f8d00`, size `0x202` / 514 bytes (Verified with int_convert.py), `sub_4F6D80` as the caller function, `0x004f8f02` as not a function, and successor `sub_4F8F10` at `0x004f8f10`.
- 2026-06-13 `analyze_function` reports one caller (`sub_4F6D80`), 13 basic blocks, cyclomatic complexity 2, and a full callee set covering packet readers/writers, `AlertPane`, application-exit, language lookup, `MetaMan` sync, allocator/free, and local string helpers.
- 2026-06-13 `xrefs_to 0x005228f0` reports exactly two code callers for the metadata-sync helper: active `MainMenuPane::OnServerMessage` at `0x004f711b` and this retained/helper body at `0x004f8ed2`.
- 2026-06-13 `xrefs_to 0x0069ae08` reports this helper's optional callback read at `0x004f8ebc`, alongside broader modal/dimmer callback users.
- 2026-06-13 `get_bytes 0x004f8ef8` shows the final `retn 4` sequence and fourteen `0xcc` bytes at `0x004f8f02-0x004f8f10`; `make_signature_for_range 0x004f8d00-0x004f8f02` returned a unique full-range signature.
- 2026-06-25 B001 current MCP ids `10-30` and correction ids `1001-1018` resolve the prior source-quality blockers: sole `MainMenuPane::OnServerMessage` case-3 caller, `DATFile` ctor/dtor local lifetime, exact payload and outbound packet layouts, command-6 reconnect endpoint post, command-12 `Socket::PostConnectionStatusQuery(bool *outConnected)` wrapper, `Thread::WaitForResult`, failed-status `AlertPane(..., NULL, NULL)` button-label tail arguments, `g_pScreenDimmer` deletion, and MetaMan sync are all documented on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md).
- Correction evidence preserves `Socket::QueryTransportState` as the vtable consumer at `0x00576200`: the source-facing target call is the posted-HANDLE wrapper, not a direct vtable consumer call.

## Source Placement

Keep as a private/static helper in `login/MainMenuPane.cpp` or a small adjacent pre-login packet helper in the same module. Do not move this into [UID:0000LC][MetaMan](by-file/MetaMan.md): the metadata manager call is a side effect after this main-menu packet is processed.

## Autogen Status

- Reconstructable: true as a source-owned private helper under the main-menu login module.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The parent records this helper as part of `login/MainMenuPane.cpp`, and the live caller is the `MainMenuPane::OnServerMessage` opcode-`3` dispatch path.
- Code: not duplicated here. [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) owns the first-draft C++ body and this by-global page remains the address-suffixed alias/support page.

## Score Rationale

- Completion remains 86 because this alias page records the exact boundary, caller dispatch, payload offsets, packet/session interactions, failed-status alert path, outbound opcode shape, layout-flag append, screen-dimmer deletion, metadata-sync side effect, source placement, stack-buffer sizes, byte-boundary proof, and current support relationships while deferring emitted C++ to [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md).
- Confidence remains 90 because live IDA and the B001 correction pass directly prove the single caller, decompiled control flow, callees, stack buffers, full-range uniqueness, final epilogue/padding bytes, source-owner relationship through `MainMenuPane::OnServerMessage`, and the source-facing command-12 wrapper name. Remaining uncertainty is limited to original symbol/PDB spellings and the non-used `DATFile` source motivation, not target-source readiness.

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
  - Summary/evidence: live IDA MCP reconfirmed `sub_4F8D00` size `0x202`, single direct caller `0x004f74b7`, the `MainMenuPane::OnServerMessage` top-level `case 3` dispatch, payload reads at `+1`/`+5`/`+7`, the copied string from `payload + 8`, the failed-status `AlertPane`/exit branch, outbound opcode `0x10` with appended [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, optional `dword_69AE08` callback, and final `g_pMetaMan` metadata-sync call. That pass deferred emitted C++ at the time; B001 2026-06-25 later superseded the deferral on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md).
- 2026-06-07 A008 alias cleanup:
  - Normalized the appended mode-byte evidence to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-13 A003 Goal 2 refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`, parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, parent retained.
  - Summary/evidence: live IDA MCP reconfirmed exact `0x202` / 514-byte helper size, sole main-menu caller, one stack argument with `retn 4`, inbound/outbound local buffer sizes, failed-status alert allocation and localized id, outbound opcode `0x10`, `g_useEpfAssets` append, optional `dword_69AE08` callback, two-call-site `MetaMan` sync relationship, fourteen-byte successor padding, and unique full-range signature. That pass deferred emitted C++ at the time; B001 2026-06-25 later resolved source-facing names/types and emitted the target body on [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md).
- 2026-06-25 B001 source-quality implementation sync:
  - Score unchanged at `86/90`; this page remains alias/support-only with no duplicate emitted C++.
  - Summary/evidence: [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md) is now `88/91` with first-draft `HandleLegacyMainMenuPacket` C++. Current MCP ids `10-30` and correction ids `1001-1018` prove the sole case-3 caller, `DATFile` lifetime, payload offsets, `Socket::PostConnectionStatusQuery(bool *outConnected)`, `Thread::WaitForResult`, `AlertPane` button-label nulls, outbound opcode `0x10`, `g_useEpfAssets`, `g_pScreenDimmer` deletion, MetaMan sync, and exact epilogue/padding.
