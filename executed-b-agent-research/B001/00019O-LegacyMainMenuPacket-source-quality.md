** TARGET-REPORT-UID:00019O **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00019O LegacyMainMenuPacket Source-Quality Report

- Agent: B001
- Assignment: B001-report-00019O-legacy-main-menu-packet-20260625
- Target: [UID:00019O] `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md`
- Required report path: `tools/leaser/Agents/Agent-B001/research/00019O-LegacyMainMenuPacket-source-quality.md`
- Report timestamp: 2026-06-25T04:24:20-04:00
- Correction pass timestamp: 2026-06-25T04:35:47-04:00
- MCP endpoint required by supervisor: `http://127.0.0.1:13337/mcp`
- MCP status: available. Session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Report-Only Scope

This is a report-only source-quality assignment. I did not take leases and did not edit by-memory, by-file, by-class, by-global, generated, project-level, validator state/cache, IDA DB, or coverage-report files.

Only this B001 research report was created. The implementation checklist below is intentionally left with implementation items unchecked for supervisor validation and later callback execution.

## Current Recommendation

Raise [UID:00019O] from `COMPLETION:87` / `CONFIDENCE:90` to `COMPLETION:88` / `CONFIDENCE:91`, preserve `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L0`, blank optional metadata, and `Nested:0`, and insert first-draft formal C++ for the retained file-local `MainMenuPane` helper.

The previous blank-C++ blockers are no longer strong enough to hold the page blank:

- The packet-buffer helper names are resolved well enough through the PacketBuffer child pages: `PacketBufferReadUInt32BE`, `PacketBufferReadUInt16BE`, and `PacketBufferWriteUInt8`.
- The sole active caller is current MCP-confirmed: `MainMenuPane::OnServerMessage` dispatches opcode `3` to `sub_4F8D00`.
- The outbound sender path is source-placeable through `g_packetSender`/`Socket` and `Thread` support docs.
- `dword_69AE08` is not an unknown modal callback for this target; exact storage/support docs identify it as `ScreenDimmer *g_pScreenDimmer`, and the target invokes the scalar-deleting first virtual slot with flag `1`, source-facing as `delete g_pScreenDimmer`.
- The metadata side effect is exact enough: `g_pMetaMan->LoadMetaDatAndRequestSync()`.
- The source-facing helper name to implement now is the conservative `HandleLegacyMainMenuPacket`. Current evidence rejects narrower `HandleTransferServerPacket`, `HandleReconnectPacket`, and `HandleMetaSyncPacket` names because the sole caller is the `MainMenuPane::OnServerMessage` case-3 route and the body combines reconnect endpoint parsing, a connection-status query, outbound opcode `0x10` (16, Verified with `tools/int_convert.py`) packet construction, screen-dimmer teardown, and MetaMan sync.
- The source-facing wrapper name to implement for Socket command `0x0c` (12, Verified with `tools/int_convert.py`) is `Socket::PostConnectionStatusQuery(bool *outConnected)`. The existing Socket vtable consumer remains `Socket::QueryTransportState`; the wrapper posts the sync query through `Thread::DispatchRequestAndReturnEvent`, and callers wait through `Thread::WaitForResult`.
- The local `DATFile` and `AlertPane` arguments are source-shaped enough for first-draft C++: `DATFile datFile;` preserves the explicit constructor/destructor lifetime and EH cleanup, while `new AlertPane(..., pane, NULL, NULL)` matches the documented `AlertPane(const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)` signature.

The score should remain capped below 95 because original symbol/PDB spellings for the opcode-3 protocol enum and the command-12 Socket wrapper are not available, and the local `DATFile` source motivation is visible only through required constructor/destructor lifetime rather than a surviving data-use call. These are confidence caps, not formal-C++ blockers.

## Recommended Target Item Summary

Replace the current target `Item Summary` with:

`Source-ready pre-login server-message opcode 3 helper; current MCP confirms sole MainMenuPane case-3 caller, DATFile RAII scratch object, payload +1/+5/+7/+8 parsing, Socket/Thread status handshake, failed-status AlertPane/RequestExit path, outbound opcode 0x10 with g_useEpfAssets, g_pScreenDimmer deletion, MetaMan sync, exact epilogue/padding, and first-draft C++ present.`

## Current MCP Evidence

MCP command ids from session `80de0a67`:

- `10 server_health`: IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; imagebase `0x400000`; auto-analysis, Hex-Rays, and strings cache ready.
- `11 lookup_funcs`: `0x004f8d00` is `sub_4F8D00`, size `0x202`; `0x004f8f02` is not a function; `0x004f8f10` is the next function, size `0x85`; `0x004f74b7` is inside `sub_4F6D80`.
- `12 callees`: `sub_4F8D00` calls `sub_49C130`, `sub_5754C0`, `sub_575480`, `sub_574CD0`, `sub_574B50`, `sub_574B30`, `sub_596760`, `sub_49FEB0`, `sub_464E40`, `sub_575380`, `sub_574CE0`, `sub_574BB0`, `sub_5228F0`, and `sub_49C160`.
- `13 analyze_function 0x004f8d00`: Hex-Rays prototype `char __thiscall(_DWORD *this, unsigned __int8 *payload)`, 514 bytes, one caller `sub_4F6D80`, 13 basic blocks, cyclomatic complexity 2.
- `14 decompile 0x004f8d00`: confirms payload parsing from `payload + 1`, `+5`, `+7`, copied text from `+8`, outbound opcode `0x10`, `g_useEpfAssets` append, `g_packetSender` send path, `dword_69AE08` virtual call with flag `1`, and `g_pMetaMan` sync.
- `15 disasm 0x004f8d00`: exact calls at `0x004f8d39` `DATFile::DATFile`, `0x004f8d4e` `PacketBufferReadUInt32BE`, `0x004f8d59` `PacketBufferReadUInt16BE`, `0x004f8dae` socket connected-state test, `0x004f8dc8` command 6 post, `0x004f8dda` command `0x0c` event-backed request, `0x004f8de6` wait result, `0x004f8e1c` localized string id `0x9d`, `0x004f8e38` application exit request, `0x004f8e46` outbound opcode `0x10`, `0x004f8e89` `g_useEpfAssets`, `0x004f8ea1` send-disabled false, `0x004f8eb7` queue/send, `0x004f8eca` `g_pScreenDimmer` delete-like call, `0x004f8ed2` MetaMan sync, `0x004f8edd` `DATFile::~DATFile`, and `0x004f8eff` `retn 4`.
- `16 decompile 0x004f6d80`: `MainMenuPane::OnServerMessage` dispatches `case 3u` to `sub_4F8D00(this - 40, *(unsigned __int8 **)(a2 + 12))` at `0x004f74b7`.
- `17 xrefs_to`: `0x004f8d00` has exactly one code xref, `0x004f74b7` from `sub_4F6D80`; support globals/helpers have broad xref sets, including `0x0069ae08`, `0x0066da97`, `0x0067a7ec`, `0x0069b410`, and PacketBuffer helpers.
- `18 make_signature_for_range`: full range `0x004f8d00-0x004f8f02` returned a unique wildcard-operands IDA signature.
- `21 xrefs_to`: `MetaMan::LoadMetaDatAndRequestSync` at `0x005228f0` has two code xrefs, including this target at `0x004f8ed2`; Socket helper xrefs confirm this target reaches `0x00574cd0`, `0x00574ce0`, `0x00574b30`, and `0x00574b50`.
- `22 get_bytes`: bytes from `0x004f8ef8` confirm the epilogue and fourteen `0xcc` padding bytes through `0x004f8f10`.
- `23 decompile 0x00574b30`: wrapper dispatches Thread event-backed command `0x0c`, with sync arg pointer and value `1`.
- `24 decompile 0x00596760`: `Thread::WaitForResult` waits the result event, scans/removes the result list entry, closes the handle, and returns the result payload.
- `25 decompile 0x00574b50`: Socket command 6 wrapper takes the reconnect address and port.
- `26 decompile 0x00574ce0`: `Socket::SetSocketSendDisabled` writes the send-disabled flag.
- `27 decompile 0x00574cd0`: `Socket::IsSocketConnectedState` returns whether socket state equals `5`.
- `28 decompile 0x00596a00`: `Thread::DispatchRequestAndReturnEvent` creates an event, queues the request, releases the semaphore, and returns the event handle.
- `29 decompile 0x0049c130`: local object constructor is `DATFile::DATFile`, not an unknown string/local RAII object.
- `30 decompile 0x0049c160`: matching local destructor is `DATFile::~DATFile`.

Correction-pass MCP and local evidence added on 2026-06-25:

- `1001 tools/list`: endpoint still responds and the active schema requires `database` for IDB-backed calls; current `decompile`/`disasm` use singular `addr`.
- `1003 idb_list`: active session remains `80de0a67`, worker PID `26892`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing.
- `1004 server_health`: status `ok`, uptime `80320.017`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready size `2067`.
- `1005 decompile 0x00574b30`: wrapper calls `Thread::DispatchRequestAndReturnEvent` with message id `0x0c`, caller output pointer, fixed sync argument `1`, and zero async args.
- `1006 decompile 0x00576200`: Socket sync vtable handler treats command `12` specially, writing `*out = (mode byte at +240200 == 6) || (socket handle at +120184 != -1)`, and falls back to the base `Thread` sync handler for other ids.
- `1007 decompile 0x00575e60`: Socket async command dispatcher has cases `3`, `4`, `5`, `6`, `7`, `8`, `9`, `10`, `11`, `13`, and `14`; command `12` is absent from the async switch and therefore belongs to the event-backed sync query path.
- `1008 decompile 0x00596a00` and `1009 decompile 0x00596760`: `Thread::DispatchRequestAndReturnEvent` creates/records the wait event and queues the six-dword request; `Thread::WaitForResult` waits, removes the result entry, closes the handle, and returns the stored result payload.
- `1010 xrefs_to`: `0x00574b30` has seven callers (`0x00466ca0`, `0x004f8d00`, twice in `0x0050feb0`, `0x00554210`, `0x00554410`, and `0x0058b470`); the sync consumer `0x00576200` is reached only through Socket vtable data at `0x00624f50`.
- `1011`, `1012`, `1013`, `1014`, and `1015 decompile`: the command-12 callers use the boolean as a reusable current connection/transport availability query before heartbeat send, login/reconnect follow-up send, connection-closed reset, and TerminalPane reconnect-alert flows. This rejects a target-local `PostReconnectResultRequest` name.
- `1016 decompile 0x004f8d00`: reconfirms target payload layout, local `DATFile` constructor/destructor, command-6 reconnect endpoint post, command-12 status query, `AlertPane` allocation with two zero tail arguments, outbound opcode `0x10`, `g_useEpfAssets`, send-disabled reset, `g_pScreenDimmer` deletion, and MetaMan sync.
- `1017 decompile 0x004f6d80` and `1018 xrefs_to`: `MainMenuPane::OnServerMessage` dispatches top-level case `3` to `sub_4F8D00`; `0x004f8d00` has exactly one xref and `0x004f8f10` has none, so the opcode-3 helper remains distinct from the retained transfer-dialog helper.
- Support docs checked in this correction pass: `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`, `by-class/Socket.md`, `by-file/Socket.md`, `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`, `by-class/Thread.md`, `by-file/Thread.md`, `by-class/AlertPane.md`, `by-file/AlertPanes.md`, `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`, `by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md`, `by-memory/0x0049c130-0x0049d2cc.DATFile.md`, `by-class/DATFile.md`, `by-file/DATFile.md`, `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, `by-global/HandleLegacyMainMenuPacket_4F8D00.md`, `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`, and `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`.

## Source-Quality Analysis

The function is a retained private/file-local pre-login packet helper owned by `MainMenuPane` source, not a PacketBuffer, Socket, MetaMan, ScreenDimmer, Application, AlertPane, DATFile, or no-owner page. The sole active inbound route is the opcode `3` branch in `MainMenuPane::OnServerMessage`; no table route or second caller was found.

The payload layout is exact enough for first-draft source:

- `payload[0]` is the server-message opcode consumed by the caller and is not reread here.
- `payload + 1` is a big-endian 32-bit reconnect/address value.
- `payload + 5` is a big-endian 16-bit reconnect/port value.
- `payload[7]` is a one-byte text length.
- `payload + 8` is copied into a 256-byte local byte buffer and null-terminated.

The outgoing packet layout is also exact enough:

- Byte `0` is opcode `0x10`.
- Bytes `1..textLength` copy the inbound text bytes.
- Byte `textLength + 1` is `g_useEpfAssets`.
- Byte `textLength + 2` is a local scratch/null terminator; the queued packet size is only `textLength + 2`.

The connection status path is source-placeable:

- If `g_packetSender->IsSocketConnectedState()` is true, the helper posts Socket command 6 with the reconnect fields.
- It then calls the source-facing command-12 wrapper `Socket::PostConnectionStatusQuery(bool *outConnected)`, waits with `Thread::WaitForResult`, and checks the one-byte boolean result.
- If the status is false, the helper constructs an `AlertPane` with localized string id `0x9d` (157, Verified with `tools/int_convert.py`), parent/layout reference `pane`, and null primary/secondary button-label pointers, then requests application exit.

The local `DATFile` object is current MCP-confirmed at constructor `0x0049c130` and destructor `0x0049c160`. I did not find an explicit use of the object after construction in the target body, but the first-draft C++ should keep a local `DATFile datFile;` so the constructor/destructor pair remains represented.

The `DATFile` local is not a decompiler stack-layout artifact. The target contains real calls to `DATFile::DATFile` and `DATFile::~DATFile`, and the object is covered by the function's EH cleanup state. No `Open`, `Read`, `GetDataPointer`, `ReadAllEntries`, or Meta.dat API call receives its address, so the current source-shaped representation is an intentionally preserved local `DATFile datFile;`, likely retained from source lifetime/RAII structure or a source branch whose data uses compiled away. Omitting it would drop observable constructor/destructor side effects.

## Formal C++ Insertion Text

Insert this exact first-draft block in [UID:00019O]. It belongs on the by-memory target, not duplicated into the by-global alias page unless a later supervisor instruction explicitly requests duplicate emission.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool HandleLegacyMainMenuPacket(MainMenuPane *pane, const unsigned char *payload)
{
    DATFile datFile;
    unsigned char text[256];
    unsigned char packet[1024];

    const unsigned int reconnectAddress = PacketBufferReadUInt32BE(payload + 1);
    const unsigned short reconnectPort = PacketBufferReadUInt16BE(payload + 5);
    const unsigned char textLength = payload[7];

    memcpy(text, payload + 8, textLength);
    text[textLength] = '\0';

    if (g_packetSender->IsSocketConnectedState()) {
        g_packetSender->PostReconnectEndpointCommand(reconnectAddress, reconnectPort);

        bool connectionAvailable = false;
        HANDLE resultEvent = g_packetSender->PostConnectionStatusQuery(&connectionAvailable);
        g_packetSender->WaitForResult(resultEvent);

        if (!connectionAvailable) {
            new AlertPane(g_pLanguageMan->GetLocalizedString(0x9d), pane, NULL, NULL);
            g_pApplication->RequestExit();
        }
    }

    PacketBufferWriteUInt8(0x10, packet);
    memcpy(packet + 1, text, textLength);
    PacketBufferWriteUInt8(g_useEpfAssets, packet + textLength + 1);
    packet[textLength + 2] = '\0';

    g_packetSender->SetSocketSendDisabled(false);
    g_packetSender->QueueAndSendPacket(packet, textLength + 2);

    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;

    g_pMetaMan->LoadMetaDatAndRequestSync();
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Target Doc Edits

If accepted for implementation, update `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md` as follows:

- Set `COMPLETION:88` and `CONFIDENCE:91`.
- Preserve owner/emitter/reconstructable metadata: `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L0`, blank optional metadata, and `Nested:0`.
- Replace the `Item Summary` with the exact summary above.
- Insert the formal C++ block above.
- Replace stale blank-C++/95+ blocker wording. The selected source-facing helper is `HandleLegacyMainMenuPacket`, and the selected command-12 wrapper is `Socket::PostConnectionStatusQuery(bool *outConnected)`.
- Correct any stale "local RAII/string object" wording to current MCP-proven `DATFile` local object and record why it is source-authored lifetime, not a stack artifact.
- Correct the `AlertPane` call description to use null primary/secondary button-label pointers under the documented AlertPane constructor signature.
- Add the current MCP command evidence for ids `10-30` and correction ids `1001-1018`, plus the corrected source-name/type dispositions.
- Keep the target as a source-authored private/file-local `MainMenuPane` helper, with by-global `[UID:0000SZ]` as an alias/support page.

## Recommended Support Doc Synchronization

Update only if the report is accepted and leases are taken for implementation.

- `by-global/HandleLegacyMainMenuPacket_4F8D00.md`: remove stale final-C++-blank / 95+ blocker wording. State that the exact first-draft body lives on [UID:00019O], this page is the address-suffixed alias/support page, and current MCP resolves PacketBuffer helpers, `g_pScreenDimmer`, `g_packetSender`, and `g_pMetaMan` dependencies well enough for the target body.
- `by-file/MainMenuPane.md`: change the `HandleLegacyMainMenuPacket_4F8D00` proposed-content row from "generated prototype only" to source-ready first-draft private/file-local helper, with opcode `3`, outbound opcode `0x10`, `g_useEpfAssets`, `Socket::PostConnectionStatusQuery` / `Thread::WaitForResult`, failed-status `AlertPane`/application-exit path, `g_pScreenDimmer` deletion, and MetaMan sync.
- `by-class/MainMenuPane.md`: replace the stale packet-semantic-name caveat with "first-draft C++ is carried by child [UID:00019O]; conservative `HandleLegacyMainMenuPacket` naming is accepted after rejecting transfer-only/reconnect-only/meta-only alternatives."
- `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`: update the child index row for [UID:00019O] if stale after target implementation. It currently only says "Pre-login server-message opcode `3` helper."
- PacketBuffer helper pages: no required edits found. They already support `PacketBufferReadUInt32BE`, `PacketBufferReadUInt16BE`, and `PacketBufferWriteUInt8`.
- Socket helper pages need synchronization: update `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`, `by-class/Socket.md`, `by-file/Socket.md`, and `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md` so command `0x0c` / `12` is no longer a generic lower-confidence event-backed command. Use the source-facing wrapper name `Socket::PostConnectionStatusQuery(bool *outConnected)`, while preserving `Socket::QueryTransportState` as the vtable consumer at `0x00576200`.
- Thread helper pages: no required edits found. They already support `Thread::DispatchRequestAndReturnEvent`, `Thread::WaitForResult`, `ThreadMessage`, and `ThreadResultEntry`, which remain dependencies of the Socket wrapper.
- AlertPane support pages: no required edits found. They already establish the constructor arguments as message text, layout reference, primary button label, and secondary button label.
- DATFile support pages: no required edits found. They already establish `DATFile::DATFile`, `DATFile::~DATFile`, 20-byte object size, vtable install, and reader method set; [UID:00019O] should only consume that evidence for the local `DATFile datFile;` statement.
- `g_useEpfAssets`, `g_pMetaMan`, `g_pScreenDimmer`, and `g_packetSender` support pages: no required edits found for this assignment beyond using them as dependencies in [UID:00019O].

No generated/project-level/manual coverage file should be edited by B001 during implementation except through approved validators/autogen refresh. Manual coverage rows remain supervisor-owned unless explicitly delegated.

## Validator Plan For Implementation Callback

No validators were run for this report-only pass because no by-* files were edited.

If accepted, recommended scoped validation after the implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00019O-LegacyMainMenuPacket-source-quality-removed.md](00019O-LegacyMainMenuPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After generated output refresh, inspect generated `NexusTK/login/MainMenuPane.cpp` output for exactly one emitted `HandleLegacyMainMenuPacket` body and confirm no stale blank-C++ wording survives in generated summaries.

## Resolved Correction Dispositions

- Inbound opcode `3` packet/helper naming: implement `HandleLegacyMainMenuPacket`. MCP `1017` proves the only inbound route is `MainMenuPane::OnServerMessage` case `3`, and MCP `1018` proves `0x004f8d00` has exactly one xref. Current docs show sibling opcode `0x66` ANSI alert helper and `0x5e` transfer overlay behavior; neither owns this body. Rejected names: `HandleTransferServerPacket` is too narrow because `OpenTransferServerDialog` is a separate retained child at `0x004f8f10`; `HandleReconnectPacket` is too narrow because the body also builds outbound opcode `0x10`, deletes `g_pScreenDimmer`, and requests MetaMan sync; `HandleMetaSyncPacket` is a side-effect name rather than payload-owner name; `HandleLoginServerRedirect` overstates login-success semantics not present in the sole caller.
- Socket command `0x0c` / `12` wrapper naming: implement `Socket::PostConnectionStatusQuery(bool *outConnected)`. MCP `1005` shows the wrapper posts command `12` through `Thread::DispatchRequestAndReturnEvent`; MCP `1006` shows the vtable consumer writes true for mode `6` or a valid socket handle; MCP `1007` shows command `12` is not an async dispatcher case; MCP `1010-1015` show call sites using the boolean as a reusable connection/transport availability result. Rejected names: a raw inherited Thread dispatch call is binary-accurate but decompiler-shaped for target source; `PostReconnectResultRequest` is too target-specific; `IsSocketConnectedState` conflicts with the separate immediate state-byte helper at `0x00574cd0`; direct `QueryTransportState` in the target hides the posted-HANDLE/wait source shape.
- Local `DATFile` object: keep `DATFile datFile;` in formal C++. MCP `1016`, previous target disassembly, and DATFile docs prove explicit constructor/destructor calls and EH cleanup. Rejected explanations: stack-layout artifact is contradicted by real ctor/dtor calls; future Meta.dat/package setup is unsupported because no `Open`, `Read`, `GetDataPointer`, `ReadAllEntries`, or address-passing call uses the object; compiler-generated exception-scope-only storage is too weak because the object has source-class construction semantics. The safest source shape is a named local object preserving required lifetime side effects.
- AlertPane tail arguments: keep `NULL, NULL` as `const wchar_t *primaryButtonText` and `const wchar_t *secondaryButtonText`. `by-class/AlertPane.md` declares `AlertPane(const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)`, `AlertPaneCore` documents optional primary/secondary `TextButtonControlPane` creation, and `DialogOkButtonString` proves button-label arguments are wide UI strings such as `OK`. The two zeros in this target are button-label nulls, not callback pointers or untyped unknowns.

## Changed Files In This Pass

Report-only/correction phase:

- Updated report only: `tools/leaser/Agents/Agent-B001/research/00019O-LegacyMainMenuPacket-source-quality.md`

Implementation callback phase:

- Updated target: `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md`
- Updated alias/support page: `by-global/HandleLegacyMainMenuPacket_4F8D00.md`
- Updated MainMenuPane support pages: `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
- Updated Socket command-12 support pages: `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`, `by-class/Socket.md`, `by-file/Socket.md`, `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`
- Updated this report checklist/proof after leases were released.

Generated-output note: I did not manually edit generated/project-level/coverage files. The scoped file validators reported `generated_refresh: deferred`; the validator queue refreshed generated output afterward. Required generated readback confirmed `auto-generated/NexusTK/login/MainMenuPane.cpp` was refreshed with final `validator-command-id: 000000001257`, `validator-refreshed-at: 2026-06-25T04:55:02-04:00`, and exactly one [UID:00019O] `HandleLegacyMainMenuPacket` body.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read updated B001 `goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` instructions.
- [x] Confirmed IDA MCP availability at `http://127.0.0.1:13337/mcp`.
- [x] Did not spawn subagents.
- [x] Did not take leases during report-only work.
- [x] Did not edit by-* docs, generated/project-level files, validator state/cache, IDA DB, or any coverage-report file.
- [x] Rechecked target [UID:00019O] source-quality blockers with current MCP evidence.
- [x] Checked required support docs: `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, `by-global/HandleLegacyMainMenuPacket_4F8D00.md`, `by-global/g_packetSender.md`, `by-global/g_useEpfAssets.md`, `by-global/g_pMetaMan.md`, `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`, PacketBuffer helper pages, Socket/Thread helper pages, and `g_pScreenDimmer` support pages.
- [x] Provided exact formal first-draft C++ insertion text.
- [x] Provided score/metadata recommendation and support-doc synchronization plan.

Correction pass:

- [x] Confirmed current IDA MCP availability after supervisor rejection: `tools/list` id `1001`, `idb_list` id `1003`, `server_health` id `1004`.
- [x] Investigated Socket command `0x0c` / `12` through wrapper, consumer, Thread event helper, xrefs, and callers (`1005-1015`); selected `Socket::PostConnectionStatusQuery(bool *outConnected)` for formal source and support-doc synchronization.
- [x] Rechecked target and `MainMenuPane::OnServerMessage` opcode-3 route (`1016-1018`); retained `HandleLegacyMainMenuPacket` after rejecting transfer-only, reconnect-only, meta-only, and login-redirect alternatives.
- [x] Rechecked `DATFile` support docs and target ctor/dtor evidence; documented why `DATFile datFile;` is the source-shaped local lifetime representation.
- [x] Rechecked `AlertPane` constructor/signature support docs; documented the two null arguments as primary/secondary button-label pointers.
- [x] Updated the formal C++ recommendation to use `PostConnectionStatusQuery` and `bool connectionAvailable`.
- [x] Updated the implementation checklist to include Socket support-doc synchronization and corrected evidence ids.

Implementation callback pass:

- [x] Took leases only immediately before editing the accepted target/support files, then released them after the edit/validator batch.
- [x] Updated [UID:00019O] to `COMPLETION:88` / `CONFIDENCE:91`, preserving owner/emitter/reconstructable/optional/Nested metadata.
- [x] Replaced [UID:00019O] `Item Summary` with the exact recommended summary.
- [x] Inserted the exact formal `HandleLegacyMainMenuPacket` C++ block in [UID:00019O], including `Socket::PostConnectionStatusQuery(bool *outConnected)` and `bool connectionAvailable`.
- [x] Replaced stale blank-C++/95+ blocker wording in [UID:00019O] and preserved the resolved opcode-3, command-12, DATFile, and AlertPane dispositions.
- [x] Added current MCP evidence ids `10-30` and correction ids `1001-1018` to [UID:00019O].
- [x] Synchronized `by-global/HandleLegacyMainMenuPacket_4F8D00.md` without duplicating emitted C++.
- [x] Synchronized `by-file/MainMenuPane.md` and `by-class/MainMenuPane.md`.
- [x] Synchronized `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`; its child row was stale.
- [x] Synchronized Socket command-12 support docs: `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`, `by-class/Socket.md`, `by-file/Socket.md`, and `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`.
- [x] Ran scoped validators for every changed by-* file. I did not run an explicit `--mode autogen`; file validators reported `generated_refresh: deferred` and the validator queue refreshed generated output.
- [x] Inspected generated output for the emitted helper body and absence of a stale omitted/blank body for [UID:00019O].
- [x] Updated this report checklist with command ids, timestamps, validator exit codes, ok counts, generated-output readback, and lease release proof.
- [x] Released leases immediately after the edit/validator/readback batch.
- [x] Performed one narrow post-release support-wording correction on `by-class/MainMenuPane.md` after a scan found unrelated historical "class-level C++ remains blank" wording in a touched support page; leased that single file, validated it, released it, and updated proof.

Implementation proof:

- Lease proof:
  - Pre-edit lease report checked at `2026-06-25T04:43:23-04:00`; no listed lease overlapped the accepted files.
  - Initial lease command for all nine by-* files returned `Success` for each path.
  - Renewal immediately before validation returned `Success` for each path; lease report showed Agent-B001 leases created `2026-06-25T08:49:52Z`, expiring `2026-06-25T08:54:52Z`.
  - Release command after validation returned `Success` for all nine paths.
  - Final lease report readback at `2026-06-25T04:52:57-04:00` showed no Agent-B001 leases remaining.
  - Narrow correction lease for `by-class/MainMenuPane.md` returned `Success`; post-correction release returned `Success`; final lease report readback showed no Agent-B001 leases.

- Validator proof:

| Local id | Validator command id | Timestamp | File | Exit | ok | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- |
| V001 | `000000001246` | `2026-06-25T04:50:03-04:00` | `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md` | 0 | 1 | deferred |
| V002 | `000000001247` | `2026-06-25T04:50:05-04:00` | `by-global/HandleLegacyMainMenuPacket_4F8D00.md` | 0 | 1 | deferred |
| V003 | `000000001248` | `2026-06-25T04:50:07-04:00` | `by-file/MainMenuPane.md` | 0 | 1 | deferred |
| V004 | `000000001249` | `2026-06-25T04:50:17-04:00` | `by-class/MainMenuPane.md` | 0 | 1 | deferred |
| V005 | `000000001250` | `2026-06-25T04:50:19-04:00` | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | 0 | 1 | deferred |
| V006 | `000000001251` | `2026-06-25T04:50:20-04:00` | `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md` | 0 | 1 | deferred |
| V007 | `000000001252` | `2026-06-25T04:50:27-04:00` | `by-class/Socket.md` | 0 | 1 | deferred |
| V008 | `000000001253` | `2026-06-25T04:50:28-04:00` | `by-file/Socket.md` | 0 | 1 | deferred |
| V009 | `000000001255` | `2026-06-25T04:50:30-04:00` | `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md` | 0 | 1 | deferred |
| V010 | `000000001257` | `2026-06-25T04:55:02-04:00` | `by-class/MainMenuPane.md` | 0 | 1 | deferred |

Validator notes: V004/V005/V010 reported existing `missing_ref_uid 00036Y`; V006/V007/V008/V009 reported existing Socket/ignored-support missing reference warnings. All scoped file validator commands exited `0` with `ok: 1`. No manual generated/project-level/coverage edits were made.

- Final target header/readback:
  - [UID:00019O] now reads `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L0`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
  - [UID:00019O] `Item Summary` reads exactly: `Source-ready pre-login server-message opcode 3 helper; current MCP confirms sole MainMenuPane case-3 caller, DATFile RAII scratch object, payload +1/+5/+7/+8 parsing, Socket/Thread status handshake, failed-status AlertPane/RequestExit path, outbound opcode 0x10 with g_useEpfAssets, g_pScreenDimmer deletion, MetaMan sync, exact epilogue/padding, and first-draft C++ present.`
  - [UID:00019O] C++ readback includes `static bool HandleLegacyMainMenuPacket(MainMenuPane *pane, const unsigned char *payload)`, `DATFile datFile;`, `bool connectionAvailable = false;`, `g_packetSender->PostConnectionStatusQuery(&connectionAvailable);`, `new AlertPane(..., pane, NULL, NULL);`, `delete g_pScreenDimmer;`, and `g_pMetaMan->LoadMetaDatAndRequestSync();`.

- Generated readback:
  - `auto-generated/NexusTK/login/MainMenuPane.cpp` header reads `validator-command-id: 000000001257` and `validator-refreshed-at: 2026-06-25T04:55:02-04:00`.
  - Generated output includes one [UID:00019O] block at `Completion:88 | Confidence:91` with `static bool HandleLegacyMainMenuPacket(...)`, `DATFile datFile;`, and `PostConnectionStatusQuery(&connectionAvailable)`.
  - The generated [UID:00019O] block has no `WAVE3 OMITTED METHOD BODY` marker and no stale blank-C++ wording.
  - Final stale-wording scan across the touched target/support docs and generated `MainMenuPane.cpp` returned no hits for `C++ remains blank`, `95/95`, `95+`, `packet semantic name still open`, lower-confidence command-12 wording, `local RAII/string object`, or `generated prototype only`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00019O-LegacyMainMenuPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00019O-LegacyMainMenuPacket-source-quality.md","timestamp":"2026-06-25T04:56:55","uid":"00019O"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019O-LegacyMainMenuPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00019O-LegacyMainMenuPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
