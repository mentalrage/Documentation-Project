** TARGET-REPORT-UID:0001JC **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Report: [UID:0001JC] TerminalPaneStreamParser

Report path: `tools/leaser/Agents/Agent-B009/research/0001JC-TerminalPaneStreamParser-source-quality.md`

Target: `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`

Assignment: `B009-report-0001JC-TerminalPaneStreamParser-source-quality-20260627`

## Executive Decision

[UID:0001JC] is a real `TerminalPane` source method reached through vtable/data slot `0x0062da80`. Keep:

- `CANONICAL_OWNER:0000OI`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OI`
- source route: `NexusTK/login/TerminalPane.cpp`

Recommended score after implementation: `COMPLETION:88`, `CONFIDENCE:90` from current `86/88`.

Recommended source-facing method name and callback/virtual slot name:

- `TerminalPane::ParseTerminalStream(SocketPacket *packet)`

Recommended formal C++ disposition:

- Emit the exact first-draft method body in the "Formal C++ Disposition After Amendment" section below.
- Do not use a formal no-code marker for this target.
- Keep the source signature `char TerminalPane::ParseTerminalStream(SocketPacket *packet)` and the `SocketPacket` fields documented here.

This resolves the current blank-C++ blocker. The previously cited dependencies were rechecked: the adjusted virtual slots are inherited `DialogPane::OnDestroy()` and `DialogPane::OnHide()`, the `TerminalPane` class page already carries the method/state shape, and the shared receive wrapper can be documented without inventing a target-local packet type.

## Live IDA MCP Provenance

MCP evidence is current and not fallback-only.

- MCP endpoint used read-only through the project MCP JSON-RPC interface.
- Current `idb_list` active session: `b001_000241_20260627`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health(database=b001_000241_20260627)`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- No IDA DB edits, renames, comments, starts, prototypes, or saves were performed.
- No leases were taken.
- No target/support `by-*` docs, generated reports, generated C++ files, coverage reports, validator state, or tool state were edited in this report-first pass.

Live MCP calls used for this report:

- `lookup_funcs` for `0x0058b130`, `0x0058b44b`, `0x0062da80`, and all target callees listed below.
- Amendment recheck `lookup_funcs`/`decompile` for adjusted slot targets `0x0049e1c0` and `0x0049e210`.
- `analyze_function 0x0058b130`.
- `decompile 0x0058b130`.
- `callees 0x0058b130`.
- `xrefs_to` for `0x0058b130`, `0x00574d40`, parser literals, `"baram"`, and `0x0062da80`.
- `get_string` for parser and `"baram"` literals.
- `get_int` for `0x0062da48`, `0x0062da50`, `0x0062da80`, `0x0067a7ec`, and `0x0069bdf8`.
- `get_bytes 0x0058b3e0 size 112` as a tail/success-path byte check.

## Current Target State

The target page currently records:

- UID: `0001JC`
- Range: `0x0058b130-0x0058b44b` in filename/prose, modeled function size `0x31c` with half-open end `0x0058b44c`
- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000OI`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OI`
- blank formal `RECONSTRUCTION_CPP CODE`

The generated tracker/coverage material is stale relative to the target page. It still lists the target around `82/84` and no emitted code. Do not manually edit generated reports; refresh them only through the scoped validators during an accepted implementation callback.

## Direct MCP Facts

`lookup_funcs` resolves:

| Address | IDA name | Size | Report use |
| --- | --- | ---: | --- |
| `0x0058b130` | `sub_58B130` | `0x31c` | Target parser function. |
| `0x0058b44b` | `sub_58B130` | `0x31c` | Last byte belongs to same function; half-open end is `0x0058b44c`. |
| `0x0062da80` | not a function | n/a | Data/vtable slot pointing at parser. |
| `0x00574cf0` | `sub_574CF0` | `0x10` | Socket connection flag setter. |
| `0x00574c40` | `sub_574C40` | `0x61` | Socket string-command queue helper. |
| `0x00574cb0` | `sub_574CB0` | `0x15` | Socket single-byte command helper. |
| `0x00574c20` | `sub_574C20` | `0x15` | Socket mode-byte command helper. |
| `0x00596620` | `sub_596620` | `0x13e` | Thread queue-drain helper used on `g_packetSender`. |
| `0x00574bb0` | `sub_574BB0` | `0x63` | Socket packet-copy/send funnel. |
| `0x00574d40` | `sub_574D40` | `0x104` | `SendPositionUpdate`. |
| `0x0057a5c0` | `sub_57A5C0` | `0xff` | `SoundManager::PlaySample`. |
| `0x004f6700` | `sub_4F6700` | `0x204` | `MainMenuPane` construction path. |
| `0x0049dad0` | `sub_49DAD0` | `0x0d` | Close/deferred close wrapper. |
| `0x00443a00` | `sub_443A00` | `0x2e` | Safe format wrapper used like `_sprintf_s`. |
| `0x0049e1c0` | `sub_49E1C0` | `0x42` | `DialogPane::OnDestroy()` inherited slot, TerminalPane primary vtable `+0x38`. |
| `0x0049e210` | `sub_49E210` | `0x22` | `DialogPane::OnHide()` inherited slot, TerminalPane primary vtable `+0x40`. |

`xrefs_to` confirms:

- `0x0058b130` has exactly one direct inbound reference: data xref at `0x0062da80`.
- `0x0062da80` itself has no inbound xrefs; it is the vtable/data cell rather than an invoked code address.
- `0x00574d40` has exactly two code xrefs: `0x005542a9` in `sub_554210` and `0x0058b42f` in this parser.
- Parser literals have single xrefs from this parser:
  - `0x0062ddfc` `%I\n</RunRegistry=` from `0x0058b1c7`
  - `0x0062de10` `%c%c%c%c%c%c` from `0x0058b2f9`
  - `0x0062de20` `dumb%c%c` from `0x0058b332`
  - `0x0062de2c` `%c%c%c` from `0x0058b355`
- `"baram"` at `0x00622f4c` has two xrefs: `0x00554276` and this parser at `0x0058b3fc`.

`get_int` confirms:

- `u32le(0x0062da48) == 0x0049e1c0`, TerminalPane primary vtable slot `+0x38`.
- `u32le(0x0062da50) == 0x0049e210`, TerminalPane primary vtable slot `+0x40`.
- `u32le(0x0062da80) == 5812528`, i.e. `0x0058b130`.
- `u32le(0x0067a7ec) == 0`, matching zero-initialized `g_packetSender` storage.
- `u32le(0x0069bdf8) == 0`, matching zero-initialized `g_pTerminalPane` storage.

## Parser Behavior

The live decompile prototype is `char __thiscall sub_58B130(_DWORD *this, int a2)`.

Source-facing argument decision:

- `a2+0x0c`: packet byte pointer.
- `a2+0x10`: packet byte length.
- Best source-facing type: `SocketPacket *packet`.
- Best signature: `char TerminalPane::ParseTerminalStream(SocketPacket *packet)`.

The loop reads each input byte while `packet->length > 0`, switches on parser state, and returns `1` except for the early `RunRegistry` success case, which also returns `1`.

State details:

- State `0`: idle.
  - BEL `0x07`: writes BEL to `stderr` through `__acrt_iob_func(2)` and `putc`.
  - ESC `0x1b`: compares bytes at `data+2` with `%I\n</RunRegistry=` for length `0x11`; match returns `1`, mismatch enters state `1`.
  - IAC `0xff`: enters state `4`.
- State `1`: escape-command dispatch.
  - `(`, `)`, `*`, `+`: enters state `3`.
  - `S`: if `g_pConfig+0x2918f8` is disabled or `rand() >= 0x1fff`, enters state `6` and calls `SetSocketConnectionFlag(g_packetSender, 1)`.
  - `C`: same gate, enters state `6` and calls `SetSocketConnectionFlag(g_packetSender, 0)`.
  - default: resets state to `0`.
- State `3`: one-byte charset/escape tail; resets state to `0`.
- State `4`: telnet IAC.
  - `0xfd`: enters state `5`.
  - otherwise resets to `0`.
- State `5`: telnet option response.
  - Option `0x18`: formats bytes `ff fb 18 ff fa 18`, queues that string, sends single byte command `0`, then formats `dumb ff f0` and queues it.
  - Other options: formats `ff fc <option>` and queues it.
  - Then resets state to `0`.
- State `6`: accepted terminal stream handoff.
  - Calls `PostSocketModeByteCommand(g_packetSender, 0)`.
  - Calls `Thread::WaitForQueueDrain(g_packetSender)`.
  - Calls two adjusted TerminalPane virtual slots through the full-object pointer `this-40`: vtable offsets `+0x38` and `+0x40`.
  - Allocates `0x454` bytes and calls `sub_4F6700(v10, 1)`, matching the MainMenuPane construction/handoff path.
  - Calls `g_pSoundManager->PlaySample(0x191, 100)`.
  - Formats/sends `"baram"` through `QueueAndSendPacket(g_packetSender, Src, 5)`.
  - Calls `SendPositionUpdate(g_packetSender)`.
  - Calls the close/deferred-close wrapper on the full object pointer.
  - Stops processing the current packet.

## Source-Quality Decisions

### Ownership And Placement

Accepted owner: [UID:0000OI] `TerminalPane`.

Rejected owners:

- `Socket`: owns the command/send helpers and `g_packetSender`, but the parser state, vtable slot, `TerminalPane` full-object adjustment, and terminal handoff behavior are `TerminalPane` owned.
- `MainMenuPane`: receives/constructs the next login UI path after parser success, but does not own the parser.
- `SoundManager`: is only the `PlaySample(0x191, 100)` dependency.
- `Thread`: owns the queue-drain primitive only.
- read-only data pages: own literals/vtable bytes as generated data, not source parser behavior.
- no-owner/non-emitting: rejected because the function is source-authored, vtable-referenced, and routed through a valid TerminalPane source file.

### Final Method Name And Callback Slot

Accepted:

- `TerminalPane::ParseTerminalStream(SocketPacket *packet)`
- Virtual/parser callback slot name: `ParseTerminalStream`

Rationale:

- The function has no ordinary code callers and one data/vtable xref at `0x0062da80`, so this is a callback/virtual handler, not a free helper reached from source call sites.
- The body is a byte-stream state machine, not a generic socket callback or UI command handler.
- Current target/file/class support docs already converge on `ParseTerminalStream`.

Rejected alternatives:

- `OnTerminalStreamData(SocketPacket *packet)`: plausible event-style wording, but weaker than the parser-specific name already adopted by support docs.
- `OnSocketPacket`, `HandlePacket`, or `Receive`: too broad and loses the terminal/telnet/parser behavior.
- raw `sub_58B130`: only for IDA traceability, not source-facing docs.

### Packet Type And Signature

Accepted:

- `SocketPacket *packet`
- `packet->data` at offset `+0x0c`
- `packet->length` at offset `+0x10`
- return type `char`

Amendment dependency recheck:

- No formal `struct SocketPacket` or `class SocketPacket` declaration was found in current `by-class`, `by-type`, `by-memory`, or generated C++ outputs.
- `PacketEvent` is already used by several opcode/object-list event handlers where the payload pointer is enough, but this TerminalPane callback reads both `+0x0c` data and `+0x10` length and is already documented by the TerminalPane target/class/aggregate pages as a raw stream packet callback.
- Keep `SocketPacket` here rather than forcing the callback into the opcode `PacketEvent` family. The exact implementation repair is to document the shared receive wrapper as data pointer `+0x0c` and length `+0x10` on the TerminalPane target/class support pages, not to add a target-local struct to this function page.

This no longer blocks first-draft C++. The method body can reference `SocketPacket *packet` and its two accepted fields while the implementation callback synchronizes the class/support pages at report-level detail.

### Parser State Field

Accepted field name:

- `m_terminalParserState`

Accepted offsets:

- adjusted callback receiver offset: `this+0x1cc`, observed as `this[115]` in the decompile.
- full `TerminalPane` object offset: `+0x26c`.

Rationale:

- The decompile uses `_DWORD *this` and accesses `this[115]`.
- State-6 success path uses `this - 40`, i.e. `0xa0` bytes earlier, for full-object virtual calls and close.
- The `0xa0` adjustment matches TerminalPane's secondary/adjusted vtable arrangement documented by the TerminalPane class/vtable pages.

Use `unsigned int m_terminalParserState` or `int m_terminalParserState` consistently with the final class declaration. For this report, the source-facing name is resolved; the exact signedness is not behavior-significant because observed states are small non-negative constants.

### Helper And Global Names

Use these source-facing names in the target/support docs:

| Address/global | Source-facing name | Owner |
| --- | --- | --- |
| `0x0067a7ec` | `g_packetSender` as `Socket *` | Socket |
| `0x0067a7c8` | `g_pConfig` | Config |
| `g_pConfig+0x2918f8` | terminal parser random/jitter gate | Config field, descriptive name accepted |
| `0x0067a7d0` | `g_pSoundManager` | SoundManager |
| `0x0069bdf8` | `g_pTerminalPane` | TerminalPane |
| `0x00574cf0` | `SetSocketConnectionFlag` | Socket |
| `0x00574c40` | `QueueTransportStringCommand` | Socket |
| `0x00574cb0` | `SendSingleByteCommand` | Socket |
| `0x00574c20` | `PostSocketModeByteCommand` | Socket |
| `0x00596620` | `Thread::WaitForQueueDrain` | Thread base/queue |
| `0x00574bb0` | `Socket::QueueAndSendPacket` | Socket |
| `0x00574d40` | `SendPositionUpdate` | Socket/position helper page |
| `0x0057a5c0` | `SoundManager::PlaySample` | SoundManager |
| `0x00443a00` | safe formatting wrapper / `_sprintf_s` style helper | CRT/project wrapper |
| `0x004f6700` | MainMenuPane construction/handoff path | MainMenuPane |
| `0x0049dad0` | `CloseDialogPane` / deferred close wrapper | dialog framework |
| `0x0062da48 -> 0x0049e1c0` | `DialogPane::OnDestroy()` | inherited TerminalPane primary vtable slot `+0x38` |
| `0x0062da50 -> 0x0049e210` | `DialogPane::OnHide()` | inherited TerminalPane primary vtable slot `+0x40` |

Do not use generated `CashShopRequest *` aliases for `0x0067a7ec`.

### Range And Split

No split is recommended.

- IDA modeled function: `0x0058b130` size `0x31c`.
- Half-open function end: `0x0058b44c`.
- Existing filename uses last-byte style `0x0058b44b`; do not rename unless the supervisor wants project-wide half-open filename normalization.
- The target is an exact function child under the broader [UID:0001JB] TerminalPane/setup aggregate.

## Formal C++ Disposition After Amendment

Full first-draft method-body C++ is implementation-ready for the next callback. The earlier no-code marker recommendation is superseded and should not be applied.

Named dependency resolution:

1. Adjusted virtual slots `+0x38/+0x40`: current MCP reads TerminalPane primary vtable cells `0x0062da48 -> 0x0049e1c0` and `0x0062da50 -> 0x0049e210`; current `DialogPane` docs formalize these as inherited `OnDestroy()` and `OnHide()`. Use those calls in the method body.
2. Shared receive-buffer type: keep the existing `SocketPacket *packet` signature and fields `packet->data`/`packet->length`; implementation should document this receive wrapper on the TerminalPane target/class support pages rather than creating a target-local struct.
3. TerminalPane class/field sufficiency: current `by-class/TerminalPane.md` already lists `char ParseTerminalStream(SocketPacket *packet)` and `m_terminalParserState` at full-object `+0x26c`. The implementation callback should keep that shape and make the target body use it.
4. Helper declarations: all externally owned calls have accepted source-facing names in Socket, Thread, SoundManager, MainMenuPane, DialogPane, or close-support docs. Missing generated declarations are support-page synchronization work, not a reason to leave this target blank.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
char TerminalPane::ParseTerminalStream(SocketPacket *packet)
{
    if (packet->length <= 0) {
        return 1;
    }

    for (int byteIndex = 0; byteIndex < packet->length; ++byteIndex) {
        const unsigned char value = packet->data[byteIndex];

        switch (m_terminalParserState) {
        case 0:
            if (value == 0x07) {
                putc(0x07, stderr);
            } else if (value == 0x1b) {
                if (strncmp(reinterpret_cast<const char *>(packet->data + 2),
                            "%I\n</RunRegistry=",
                            0x11) == 0) {
                    return 1;
                }
                m_terminalParserState = 1;
            } else if (value == 0xff) {
                m_terminalParserState = 4;
            }
            break;

        case 1:
            if (value == '(' || value == ')' || value == '*' || value == '+') {
                m_terminalParserState = 3;
            } else if (value == 'S') {
                if (!g_pConfig->terminalParserRandomGate || rand() >= 0x1fff) {
                    m_terminalParserState = 6;
                    g_packetSender->SetSocketConnectionFlag(1);
                }
            } else if (value == 'C') {
                if (!g_pConfig->terminalParserRandomGate || rand() >= 0x1fff) {
                    m_terminalParserState = 6;
                    g_packetSender->SetSocketConnectionFlag(0);
                }
            } else {
                m_terminalParserState = 0;
            }
            break;

        case 3:
            m_terminalParserState = 0;
            break;

        case 4:
            m_terminalParserState = (value == 0xfd) ? 5 : 0;
            break;

        case 5: {
            char response[64];
            if (value == 0x18) {
                sprintf_s(response, sizeof(response), "%c%c%c%c%c%c",
                          0xff, 0xfb, 0x18, 0xff, 0xfa, 0x18);
                g_packetSender->QueueTransportStringCommand(response);
                g_packetSender->SendSingleByteCommand(0);
                sprintf_s(response, sizeof(response), "dumb%c%c", 0xff, 0xf0);
            } else {
                sprintf_s(response, sizeof(response), "%c%c%c",
                          0xff, 0xfc, value);
            }
            g_packetSender->QueueTransportStringCommand(response);
            m_terminalParserState = 0;
            break;
        }

        case 6: {
            g_packetSender->PostSocketModeByteCommand(0);
            g_packetSender->WaitForQueueDrain();
            OnDestroy();
            OnHide();

            MainMenuPane *mainMenuPane = new MainMenuPane(1);
            (void)mainMenuPane;

            g_pSoundManager->PlaySample(0x191, 100);

            char outgoingPacket[128];
            sprintf_s(outgoingPacket, sizeof(outgoingPacket), "baram");
            g_packetSender->QueueAndSendPacket(outgoingPacket, 5);
            g_packetSender->SendPositionUpdate();
            CloseDialog();
            return 1;
        }

        default:
            break;
        }
    }

    return 1;
}
```

Do not add a separate no-code marker. If the implementation callback discovers a validator naming mismatch, repair the relevant support declaration/name at report-level detail in the same edit batch rather than blanking this target.

## Support Pages Checked

Required pages checked:

- `by-file/TerminalPane.md`
- `by-class/TerminalPane.md`
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`
- `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
- `by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md`

Additional directly related pages checked:

- `by-class/DialogPane.md`
- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`
- `by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`
- `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`
- `by-file/SoundManager.md`
- Socket helper pages for `0x00574c20`, `0x00574c40`, `0x00574cb0`, `0x00574cf0`, and `0x00574bb0`
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` for the `Thread::WaitForQueueDrain` naming correction
- MainMenu/close-support pages covering `0x004f6700` and `0x0049dad0`
- `by-global/g_pTerminalPane.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Executed B-agent reports used as leads, not authority:

- `executed-b-agent-research/B006/0001JB-TerminalPaneAndSetup-source-quality.md`
- `executed-b-agent-research/B003/0003G7-SharedBaramPacketLiteral-post-migration.md`
- Current executed/support reports for Socket, SoundManager, MainMenuPane, and related globals where searched.

Current by-docs are already mostly consistent on source placement, packet offsets, and parser name. The implementation callback should update stale "medium/open" wording on [UID:0001JC], insert the first-draft formal C++ body above, and synchronize a short B009 note into the TerminalPane file/class/aggregate support pages.

## Recommended Implementation Edits

Target page `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`:

- Raise metadata to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`.
- Add a 2026-06-27 B009 current MCP evidence section with session `b001_000241_20260627`.
- Replace "medium/open" language for final name/signature with accepted `TerminalPane::ParseTerminalStream(SocketPacket *packet)`.
- Record `SocketPacket` fields `+0x0c` data and `+0x10` length.
- Record `m_terminalParserState` at adjusted `+0x1cc`, full-object `+0x26c`.
- Add the helper/global name map above.
- Add the full state-6 success branch from current decompile, including inherited adjusted-slot calls `OnDestroy()` and `OnHide()`, `PlaySample(0x191, 100)`, `"baram"` length `5`, `SendPositionUpdate`, and close wrapper.
- Insert the exact first-draft `RECONSTRUCTION_CPP CODE` method body from this report.
- Update score rationale to explain that first-draft C++ is now present because the named dependency blockers were investigated and resolved in this amendment.

Support docs:

- `by-file/TerminalPane.md`: add B009 current-session note that the parser name/signature/type/field/helper map are accepted and that [UID:0001JC] now carries a first-draft formal C++ body.
- `by-class/TerminalPane.md`: update the method list/class-shape guidance from provisional to accepted for `char ParseTerminalStream(SocketPacket *packet)` and `m_terminalParserState`; if the class formal block is edited, include those declarations but do not invent unrelated TerminalPane methods.
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`: add B009 support note under parser child coverage, including full success branch and first-draft C++ disposition.
- `by-class/DialogPane.md` / `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`: no required edit if the current `OnDestroy()` / `OnHide()` wording is still present; if touched for cross-reference clarity, only add a short note that TerminalPane's success path uses these inherited primary-vtable slots.
- `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`: optional but useful B009 xref refresh for parser literal sites and current session id.
- `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`: no score or ownership change needed; optional note that current session reconfirms this parser as one of two direct callers.
- `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`: no required ownership change; optional note to replace stale MCP-unavailable wording if still visible in the exact edited section.
- `by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md`: no required edit; existing singleton/global boundary is consistent.
- `g_packetSender`, `g_pSoundManager`, and `g_pConfig` support pages: no required edit for this target; they already support the names/types used here.

Do not edit generated reports manually. Let scoped validators refresh generated state.

## Expected Scoped Validators After Implementation

Run scoped validators only after the supervisor accepts this report and sends an implementation callback. Use `--wait-generated` where generated freshness matters.

Suggested sequence:

> Executable block R001 was removed from this report and preserved verbatim in [0001JC-TerminalPaneStreamParser-source-quality-removed.md](0001JC-TerminalPaneStreamParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional `SendPositionUpdate` or read-only-data wording is edited, validate those pages in the same scoped manner.

## Implementation Tracking Checklist

- [x] `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`: metadata raised to `88/90`, owner/emitter preserved, B009 current MCP evidence added. Proof: target metadata now records `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, with current-session MCP evidence for `b001_000241_20260627`.
- [x] Target parser name/signature accepted as `TerminalPane::ParseTerminalStream(SocketPacket *packet)`. Proof: target summary/status and formal code block use that source-facing signature.
- [x] Target packet fields documented as `SocketPacket` data `+0x0c` and length `+0x10`. Proof: target and support pages now record the accepted shared receive-wrapper fields.
- [x] Target parser state documented as `m_terminalParserState`, adjusted `+0x1cc`, full object `+0x26c`. Proof: target, class, file, and aggregate support pages carry the accepted field name/offsets.
- [x] Target helper/global map updated with source-facing names and rejected alias notes. Proof: target page maps `g_packetSender`, `g_pConfig`, `g_pSoundManager`, Socket helpers, queue drain, sound, menu handoff, close helper, and inherited DialogPane slots; generated `CashShopRequest *` aliases remain rejected.
- [x] Target state-6 success branch updated from current decompile, including inherited adjusted-slot calls `OnDestroy()` and `OnHide()`, `PlaySample(0x191, 100)`, `"baram"` length `5`, `SendPositionUpdate`, and close wrapper. Proof: target behavior notes and formal body include the full branch.
- [x] Target formal `RECONSTRUCTION_CPP CODE` block receives the exact first-draft method body from this report. Proof: validator refreshed generated `auto-generated/NexusTK/login/TerminalPane.cpp` with `char TerminalPane::ParseTerminalStream(SocketPacket *packet)`.
- [x] No formal no-code marker remains for [UID:0001JC]. Proof: target has a nonblank `RECONSTRUCTION_CPP CODE` block; stale blank/no-code wording scan over edited by-* pages returned no matches.
- [x] Adjusted virtual-slot dependency recorded as resolved: TerminalPane vtable `+0x38/+0x40` are inherited `DialogPane::OnDestroy()` / `DialogPane::OnHide()`. Proof: target and support pages preserve the vtable-cell evidence and call names.
- [x] Shared receive-wrapper dependency recorded as resolved for this implementation: keep `SocketPacket *packet`, document data `+0x0c` and length `+0x10`, and do not add a target-local struct. Proof: no target-local packet struct was added; target/support docs record the accepted wrapper fields.
- [x] `by-file/TerminalPane.md` synchronized at report-level detail. Proof: file page now states the parser child emits first-draft C++ and carries the accepted signature, field, state, and handoff details.
- [x] `by-class/TerminalPane.md` synchronized at report-level detail. Proof: class page now records the accepted method body location, `SocketPacket` fields, `m_terminalParserState`, and inherited `OnDestroy()`/`OnHide()` handoff.
- [x] `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` synchronized at report-level detail. Proof: aggregate page now records the parser child as the emission surface and carries the accepted state-6/parser support facts.
- [x] `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` receives optional current-session literal/xref refresh. Proof: page now records the current parser-literal xrefs and the boundary that this page remains literal/source-data support while the parser child emits code.
- [x] Optional `SendPositionUpdate`/read-only/global support docs either updated or explicitly recorded as no-change after implementation review. Proof: no edits required. `SendPositionUpdate` already records the parser caller at `0x0058b42f`; TerminalPhone read-only data already covers the vtable/data boundary; Terminal/TextEdit globals already cover singleton/global ownership; `g_packetSender`, `g_pSoundManager`, and `g_pConfig` pages already support the names/types and the `g_pConfig+0x2918f8` parser gate; DialogPane pages already formalize `OnDestroy()` and `OnHide()`.
- [x] Scoped validators run for every edited by-* page with generated output current. Proof: see validator table below; every edited by-* page was validated with `--apply --wait-generated --queue-timeout 240`.
- [x] Generated tracker/coverage rows checked after validator refresh; no manual generated-file edits. Proof: generated `TerminalPane.cpp` header shows validator command `000000004661`, refreshed `2026-06-27T22:23:16-04:00`, with [UID:0001JC] at `Completion:88 | Confidence:90`; generated/project files were touched only by validator refresh.
- [x] No leases remain held after implementation. Proof: final release attempt returned `Rejected[No active lease]` for all five edited by-* pages, and `current_leases.md` contains no B009 rows.

## Implementation Callback Results

Edited by-* pages:

- `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`
- `by-file/TerminalPane.md`
- `by-class/TerminalPane.md`
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`

Validator runs:

| Page | command_id | timestamp | result |
| --- | --- | --- | --- |
| `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md` | `000000004657` | `2026-06-27T22:22:10-04:00` | exit `0`, `ok:1`, `generated_refresh:completed` |
| `by-file/TerminalPane.md` | `000000004658` | `2026-06-27T22:22:26-04:00` | exit `0`, `ok:1`, `generated_refresh:completed` |
| `by-class/TerminalPane.md` | `000000004659` | `2026-06-27T22:22:42-04:00` | exit `0`, `ok:1`, `generated_refresh:completed` |
| `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` | `000000004660` | `2026-06-27T22:22:57-04:00` | exit `0`, `ok:1`, `generated_refresh:completed` |
| `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` | `000000004661` | `2026-06-27T22:23:16-04:00` | exit `0`, `ok:1`, `generated_refresh:completed` |

Validator-owned diagnostics remained pre-existing/stale-support diagnostics and did not block the scoped file runs. The validator also refreshed the generated TerminalPane output and related tracker/coverage state; no generated files, project-level generated files, coverage reports, validator state, tool state, or IDA DB were edited manually.

## Final Status

Implementation callback complete. The accepted [UID:0001JC] source-quality report was applied to the target and required support docs, the target now emits the accepted first-draft `TerminalPane::ParseTerminalStream(SocketPacket *packet)` body at `88/90`, generated output is current through scoped validators, optional support no-edit proof is recorded, and B009 holds no leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001JC-TerminalPaneStreamParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001JC-TerminalPaneStreamParser-source-quality.md","timestamp":"2026-06-27T22:26:51","uid":"0001JC"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JC-TerminalPaneStreamParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0001JC-TerminalPaneStreamParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
