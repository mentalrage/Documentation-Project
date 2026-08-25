** TARGET-REPORT-UID:0002QD **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002QD HandlePasswordChangeReply Empty-Emitter Source-Quality Report

## Final Recommendation

Status: `FINISHED_REPORT`.

Assignment id: `B002-report-0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-20260628`.

Target: [UID:0002QD] `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`.

Report path: `tools/leaser/Agents/Agent-B002/research/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md`.

Current source target state: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000I3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I3`, formal `RECONSTRUCTION_CPP CODE` blank.

Generated tracker/output state checked in this pass is stale relative to the source target page: `auto-generated/-ag-coverage-report-by-memory.md` still shows [UID:0002QD] at `80/88` with `emits_code:false`, and `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` still has the [UID:0002QD] empty emitter marker. This should be resolved by applying this report and running the target validator with `--wait-generated`.

Recommended target state after implementation: raise [UID:0002QD] to `COMPLETION:91`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:0000I3`; keep `RECONSTRUCTABLE:TRUE`; keep `EMITTER_UIDS:0000I3`; keep `EMITTER_POSITION_OPTIONAL` blank; insert the formal C++ block below exactly into the target's `RECONSTRUCTION_CPP CODE` block.

Disposition: source-authored `ChangePasswordDialogPane::HandlePasswordChangeReply` method, emitted through [UID:0000I3] `ChangePasswordDialogPane`. The empty-emitter marker is no longer justified. The prior C001 blockers are closed to implementation level: packet layout is behaviorally exact, control IDs route to source-facing password-change fields, virtual slot `+0x58` is the inherited `DialogPane::SetHoverControl(int)` method, close helpers are `SlideCloseVertical()` and `CloseDialog()`, the alert OK label is `kDialogOkButtonText`, and the best source shape is a `bool ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)` method.

## Current Evidence Checked

Documentation checked:

- Target [UID:0002QD] `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`.
- Parent aggregate [UID:00022W] `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`.
- File owner [UID:0000I3] `by-file/ChangePasswordDialogPane.md`.
- Class owner [UID:00001L] `by-class/ChangePasswordDialogPane.md`.
- Core/dispatcher support [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`.
- Active sender [UID:0002QC] `by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md`.
- Sibling [UID:0002QE] `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`.
- Shared `DialogPane` declaration/layout docs [UID:00003T] `by-class/DialogPane.md` and [UID:0001U4] `by-type/by-struct/DialogPaneLayout.md`.
- Shared OK label [UID:0001OC] `by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md`.
- Shared `g_pScreenDimmer` support docs [UID:00029D] `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md` and [UID:0000S5] `by-global/g_pScreenDimmer.md`.
- Prior executed/source-quality reports for related create-user reply handlers, especially [UID:000444] `NewUserDialogPane2HandleCreateUserReply`, whose accepted formal block uses `bool HandleCreateUserReply(const unsigned char *packet)`, local packet-message helpers, and source-facing result-group helper names.
- Current generated files/reports as read-only evidence: `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md`.

IDA MCP was mandatory and available. Current MCP provenance:

- MCP JSON-RPC `initialize` id `101`: server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- MCP `idb_list` id `102`: live session `supervisor_20260628_resume`, active `true`, backend `worker`, owned/adopted `true`, PID/worker PID `5124`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP `server_health` id `103`: `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string cache size `2067`.
- MCP `tools/list` id `104` confirmed current schemas for `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, and `analyze_function`.

Current numeric conversions were verified with `tools/int_convert.py` batch JSON:

- `0x221` = 545, `0x1ff` = 511, `0x26` = 38, `0x58` = 88, `0x270` = 624, `0x100` = 256, `0xff` = 255, `0x1fc` = 508, `0x214` = 532, `0x4c` = 76, `0x24` = 36. All decimal values in this report marked as converted use this tool output.

No by-* docs, generated files, project-level reports, manual coverage reports, validator/tool state, or IDA DB state were edited. No subagents were spawned.

## Live MCP Facts

Function inventory, MCP id `105`:

| Address | Current IDA name | Size/result |
| --- | --- | --- |
| `0x004febf0` | `sub_4FEBF0` | function size `0x221` / 545 bytes (Verified with `tools/int_convert.py`) |
| `0x004fee11` | none | not a function; target exclusive end |
| `0x004fee14` | none | switch-support data, not a function |
| `0x004fee40` | `sub_4FEE40` | sibling function size `0x1ff` / 511 bytes (Verified with `tools/int_convert.py`) |
| `0x004fe530` | `sub_4FE530` | dispatcher size `0x26` / 38 bytes (Verified with `tools/int_convert.py`) |
| `0x0049fc00` | `sub_49FC00` | inherited dialog control-id update helper size `0x4c` / 76 bytes (Verified with `tools/int_convert.py`) |
| `0x0049eb90` | `sub_49EB90` | `DialogPane::SlideCloseVertical` support helper |
| `0x0049dad0` | `sub_49DAD0` | close/dismiss helper used as `CloseDialog()` in current `DialogPane` declaration |
| `0x0049feb0` | `sub_49FEB0` | `AlertPane` constructor helper |
| `0x004f4aa0` | `sub_4F4AA0` | operator-new/allocation wrapper |
| `0x00516220` | `sub_516220` | memmove wrapper |
| `0x0069ae08` | none | `g_pScreenDimmer` global, not a function |

Important correction: current MCP still reports raw `sub_4FEBF0` and `sub_4FEE40`. The older C001 prose saying the IDA DB was saved with `ChangePasswordDialogPane_HandlePasswordChangeReply` and `ChangePasswordDialogPane_HandlePasswordChangeReplySimple` labels is stale for the current active session. The source-facing names remain correct, but by-* docs should not rely on a current saved-IDB rename as proof.

Dispatcher route, MCP ids `107`, `116`, and `120`:

- `decompile 0x004fe530` gives `if (**(_BYTE **)(a2 + 12) == 2) return sub_4FEBF0(this - 40, *(_DWORD *)(a2 + 12)); else return 0;`.
- `xrefs_to 0x004febf0` reports exactly one xref: code xref `0x004fe551` from `sub_4FE530`.
- The dispatcher function itself has vtable/data route evidence in the ChangePasswordDialogPane primary vtable family; the direct vtable slot for the dispatcher remains separate from this report's method body.

Target body, MCP ids `106`, `109`, `114`, `116`, `117`, and `118`:

- `analyze_function 0x004febf0` reports prototype `char __thiscall(int *this, int)`, size 545, 25 basic blocks, cyclomatic complexity 9, stack buffers `CHAR MultiByteStr[256]` and `WCHAR WideCharStr[256]`.
- The body calls `sub_516030`, byte-load helper `std::_Narrow_char_traits<char,int>::to_char_type`, `sub_516220`, `MultiByteToWideChar`, `sub_4F4AA0`, `sub_49FEB0`, `sub_49EB90`, `sub_49DAD0`, `___report_rangecheckfailure`, and security-cookie support.
- The first live operation after setup checks `unk_69AE08` / `g_pScreenDimmer` and calls the object's first vtable slot with flag `1`. This is source-facing `if (g_pScreenDimmer != NULL) delete g_pScreenDimmer;`, not a new local helper and not a raw `unk_` access.
- The result byte is `packet[1]`.
- Nonzero results go through a compiler switch at `0x004fec64`; success/result zero bypasses the switch.
- The message length is the byte at `packet[2]`; the message payload starts at `packet + 3`.
- Both branches copy exactly `packet[2]` bytes from `packet + 3` into a 256-byte local ANSI buffer, append an ANSI NUL, call `MultiByteToWideChar(0, 0, messageBytes, length, wideMessage, 256)`, append a wide NUL at the returned character count, and if nonempty allocate `0x270` / 624 bytes (Verified with `tools/int_convert.py`) then call `AlertPane::AlertPane(wideMessage, this, &off_613A18, 0)`.
- Success/result zero additionally calls `sub_49EB90(this, ..., this)` and `sub_49DAD0(this)`, source-facing `SlideCloseVertical(); CloseDialog();`.
- The target returns handled (`1`) for both success and all nonzero result values after this dispatcher has called it. A `bool` return is source-compatible with the `al` return behavior and matches accepted create-user reply-handler style.

Switch support and bytes:

- `xrefs_to 0x004fee14` reports one data xref at `0x004fec64` from inside `sub_4FEBF0`.
- `xrefs_to 0x004fee24` reports one data xref at `0x004fec5d` from inside `sub_4FEBF0`.
- `get_bytes 0x004fee11` shows the exact three-byte alignment `0f 1f 00`, then jump targets/classification data through `0x004fee38`, then `0xcc` padding before `0x004fee40`.
- The first four switch dwords at `0x004fee14` decode to case targets `0x004fec6b`, `0x004fec79`, `0x004fec72`, and `0x004fec86`, matching the three control-id groups and default path. This is compiler output for the C++ `switch`, not a source-authored data table.

Control-update helper resolution:

- The target indirect call is `(*(this->vtable + 88))(this, controlId)`, i.e. virtual slot `+0x58` / 88 decimal (Verified with `tools/int_convert.py`).
- `get_bytes 0x0061d6f0` over the ChangePasswordDialogPane primary vtable region shows the primary slot at `0x0061d704` contains `0x0049fc00`.
- MCP id `112` decompiled `0x0049fc00`: it reads current inherited control id at `this+0x214`, uses `DialogPane::m_controlManager` at `this+0x1fc`, deactivates the old control through child virtual slot `+0x58`, activates the new control through child virtual slot `+0x5c`, then stores the new id at `this+0x214`.
- [UID:00003T] `DialogPane` current declaration names this helper `SetHoverControl(int controlId)`, and [UID:0001U4] names `+0x214` as `m_activeControlId` with hover/control-role aliases. Therefore the target should not call a raw vtable slot, and it should not be documented only as generic "state/focus"; the best source-facing method call is `SetHoverControl(3/4/5)`.

Result-code to control mapping:

| Result codes | Binary action | Source-facing interpretation |
| --- | --- | --- |
| `3`, `4`, `14`, `16`, `17`, `18`, `20`, `21` | calls slot `+0x58` with `3` | account-name control route; use `IsPasswordChangeAccountNameReplyError(result)` then `SetHoverControl(3)` |
| `15` | calls slot `+0x58` with `4` | current-password control route; use `IsPasswordChangeCurrentPasswordReplyError(result)` then `SetHoverControl(4)` |
| `5`, `6`, `7`, `8`, `9` | calls slot `+0x58` with `5` | new-password control route; use `IsPasswordChangeNewPasswordReplyError(result)` then `SetHoverControl(5)` |
| `0` | no control update | success path; show optional message, slide close vertically, close dialog |

The exact original protocol enum labels are not recovered, but that no longer blocks formal C++: the accepted project style for similar create-user reply handlers uses source-facing grouping predicates with numeric cases when exact server enum names are unavailable. The control roles are not guesswork; current `decompile 0x004fe560` MCP id `119` proves controls `3`, `4`, `5`, and `6`, with the active sender using only controls `3`, `4`, and `5` as `accountName`, `currentPassword`, and `newPassword`, while control `6` is confirmation-only.

Alert and close helper resolution:

- `get_bytes 0x00613a18` returns UTF-16LE `4f 00 4b 00 00 00 00 00`, i.e. `L"OK"` plus terminator/padding. [UID:0001OC] names the shared source-facing label `kDialogOkButtonText` in recent accepted C++ and documents broad shared alert usage. Use `kDialogOkButtonText`, not `off_613A18`.
- MCP id `121` decompiled `0x0049dad0` as a small wrapper through `dword_67A74C`; the current `DialogPane` class declaration exposes it as `CloseDialog()`.
- MCP id `122` decompiled `0x0049eb90`; current [UID:00012U] `DialogPaneSlideAnimation` and generated `DialogPane.cpp` expose this as `SlideCloseVertical()`.

Sibling and negative evidence:

- MCP id `108` decompiled [UID:0002QE] `0x004fee40-0x004ff03f`: same packet `[1]/[2]/[3]` reply/message pattern, same `g_pScreenDimmer`, same `AlertPane`, same `SlideCloseVertical()`/`CloseDialog()` success close, but simpler nonzero mapping where result `3..8` sets control `5`.
- MCP id `116` reports `xrefs_to 0x004fee40` as zero. This is still a sibling/retained-route caveat, not evidence against [UID:0002QD]'s active dispatcher path.
- MCP id `116` reports no direct xrefs to vtable data slot `0x0061d704` or dispatcher slot `0x0061d71c`, which is expected for vtable data slots and not a contradiction; raw bytes and function decompilation provide the relevant slot target evidence.

Boundary evidence:

- `get_bytes 0x004febe2` shows fourteen `0xcc` bytes before [UID:0002QD]'s `55 8b ec` prologue.
- `get_bytes 0x004fee11` shows the three-byte alignment, switch support bytes, and `0xcc` padding before the sibling at `0x004fee40`.
- `get_bytes 0x004ff03f` shows one trailing `0xcc` byte before the next function prologue at `0x004ff040`.

## Heuristic / Inference Reanalysis

### Source Owner And Emitter

Best owner/emitter remains [UID:0000I3] `ChangePasswordDialogPane`.

Evidence for:

- The active dispatcher [UID:0002QA] at `0x004fe530` calls this exact target for packet type `2`.
- The active sender [UID:0002QC] is called by `SubmitPasswordChange` at `0x004fe778` and sends controls `3/4/5` as `accountName`, `currentPassword`, and `newPassword`.
- This handler's nonzero result-code groups map directly back to those same controls.
- The helper cluster [UID:00022W] physically groups the active sender, primary reply handler, sibling reply handler, retained account-id variant, and local compiler switch table.
- [UID:0000I3] already clears the direct parent/emitter gate at `85/88`.

Rejected alternatives:

- Socket/network owner: rejected. Socket owns `g_packetSender` and queue/send helpers, but this target is UI reply behavior with control selection, alert ownership, and dialog close side effects.
- PacketBuffer owner: rejected. This target reads raw reply bytes and does UI handling; packet scalar helpers are not the semantic owner.
- AlertPane/DialogPane owner: rejected. They provide construction, OK label, control-state, and close helpers; the caller-specific packet result mapping belongs to `ChangePasswordDialogPane`.
- MainMenuPane/OpenChangePasswordDialog owner: rejected. Those construct/launch the dialog; this target is the dialog's packet reply method.
- No-owner/non-emitting disposition: rejected. The target is actively reached by dispatcher code at `0x004fe551`, has a source-facing method body, and now has a valid formal C++ block.
- RankingDialog/source pollution: rejected for both this target and sibling context. Current behavior is password-change packet and dialog-control handling, with no ranking caller/registration evidence.

### Packet Layout And Result Enum Names

Resolved implementation-level packet layout:

- `packet[1]`: result/status byte.
- `packet[2]`: ANSI message byte length.
- `packet + 3`: ANSI message bytes.

The exact source enum names for result values `3`, `4`, `5`, `6`, `7`, `8`, `9`, `14`, `15`, `16`, `17`, `18`, `20`, and `21` are not recovered from strings or caller-side docs. That is not a remaining C++ blocker. The behavior is stronger than enum-name evidence: current MCP proves the result groups and current support docs prove the destination controls. The formal code should use source-facing grouping helper names and numeric `case` labels, matching accepted create-user reply handler practice.

### Control Helper And Field Names

The prior "virtual slot +0x58" blocker is closed.

`0x0049fc00` is not `SelectControlById` and not a raw focus-only helper. It is the inherited active/hover control-id setter now exposed as `DialogPane::SetHoverControl(int)`. It reads `m_controlManager` at `+0x1fc` / 508 decimal and updates `m_activeControlId` at `+0x214` / 532 decimal (Verified with `tools/int_convert.py` for both offsets). The target's result mapping therefore should be documented as `SetHoverControl(3)`, `SetHoverControl(4)`, and `SetHoverControl(5)`.

### Close And Alert Helpers

The prior close-helper blocker is closed.

The source-level success path is:

- show nonempty server message through `new AlertPane(message.c_str(), this, kDialogOkButtonText, 0)`;
- call `SlideCloseVertical()`;
- call `CloseDialog()`;
- return `true`.

Do not use `sub_49EB90`, `sub_49DAD0`, `off_613A18`, `sub_4F4AA0`, or `sub_49FEB0` in source-facing C++.

### Method Shape

The best formal method signature is:

`bool ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)`

Reasoning:

- The binary receives `this` and one packet pointer argument and returns `al`.
- The handler returns handled for every packet that reaches this exact dispatcher branch.
- Accepted login/create-user reply handlers use `bool HandleCreateUserReply(const unsigned char *packet)` for the same packet-reply style.
- A file-local wrapper is weaker: dispatcher code adjusts the receiver back to the `ChangePasswordDialogPane` object and calls this behavior as a method.

### Stale Assumptions Corrected

- C001's current-IDB rename claim is stale. Current MCP lookup shows `sub_4FEBF0` and `sub_4FEE40`. Keep descriptive source-facing names in docs, but do not cite a current saved rename as evidence.
- The generated tracker row is stale at `80/88`; the source page already has `86/91`. Implementation should update source metadata and rely on validator refresh.
- "state/focus value" wording is incomplete. The virtual call is specifically the inherited `SetHoverControl`/active-control helper at `0x0049fc00`.
- Result-code enum-name uncertainty is not a blank-C++ blocker. The exact groups and destination controls are current MCP facts.

## Exact Formal C++ Recommendation

Insert the following exact text into [UID:0002QD]'s multiline `RECONSTRUCTION_CPP CODE` block. This is not illustrative sample code; it is the recommended formal insertion content.

```cpp
namespace
{
SimpleUString DecodePasswordChangeReplyMessage(const unsigned char *packet)
{
    return SimpleUString::FromMbcString(packet + 3, packet[2]);
}

bool IsPasswordChangeAccountNameReplyError(unsigned char result)
{
    switch (result) {
    case 3:
    case 4:
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
        return true;

    default:
        return false;
    }
}

bool IsPasswordChangeCurrentPasswordReplyError(unsigned char result)
{
    return result == 15;
}

bool IsPasswordChangeNewPasswordReplyError(unsigned char result)
{
    switch (result) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return true;

    default:
        return false;
    }
}

void ShowPasswordChangeReplyText(ChangePasswordDialogPane *dialog, const SimpleUString &message)
{
    if (!message.empty()) {
        new AlertPane(message.c_str(), dialog, kDialogOkButtonText, 0);
    }
}
}

bool ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)
{
    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    const unsigned char result = packet[1];
    const SimpleUString message = DecodePasswordChangeReplyMessage(packet);

    if (result != 0) {
        if (IsPasswordChangeAccountNameReplyError(result)) {
            SetHoverControl(3);
        } else if (IsPasswordChangeCurrentPasswordReplyError(result)) {
            SetHoverControl(4);
        } else if (IsPasswordChangeNewPasswordReplyError(result)) {
            SetHoverControl(5);
        }

        ShowPasswordChangeReplyText(this, message);
        return true;
    }

    ShowPasswordChangeReplyText(this, message);
    SlideCloseVertical();
    CloseDialog();
    return true;
}
```

Rationale for the code block:

- `DecodePasswordChangeReplyMessage` represents the exact `packet[2]` length and `packet+3` MBCS payload conversion, matching accepted `DecodeCreateUserReplyMessage` style.
- The three predicate helpers preserve the exact result-code groups without inventing unproven original protocol enum labels.
- `delete g_pScreenDimmer` is the source-level form of the observed virtual scalar-delete call through the object at `0x0069ae08` with flag `1`.
- `SetHoverControl` is the current `DialogPane` source-facing helper for virtual slot `+0x58`.
- `kDialogOkButtonText` is the accepted shared `OK` label source name for `0x00613a18`.
- `SlideCloseVertical()` and `CloseDialog()` are the accepted source-facing names for `0x0049eb90` and `0x0049dad0`.

## Score And Metadata Rationale

Recommended target metadata:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| `COMPLETION` | `91` | Current MCP resolves the active caller, exact body, switch table ownership, packet layout, result groups, helper names, close path, and formal C++. Remaining incompleteness is only original enum spelling and final support type exactness. |
| `CONFIDENCE` | `92` | Direct dispatcher xref, current decompilation, disassembly/bytes, vtable bytes, support docs, and analogous accepted reply-handler style all agree. Confidence stays below final audit because original result enum labels and exact original helper-local names are inferred. |
| `CANONICAL_OWNER` | `0000I3` | Direct source owner remains `ChangePasswordDialogPane`. |
| `RECONSTRUCTABLE` | `TRUE` | Active source-authored UI packet reply method. |
| `EMITTER_UIDS` | `0000I3` | Emits through generated `NexusTK/login/ChangePasswordDialogPane.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | No special placement needed beyond existing file route. |
| formal C++ | nonblank block above | Clears the empty-emitter disposition. |

Support scores:

- [UID:00022W] `ChangePasswordDialogPacketHelpers` can reasonably rise from `86/88` to `87/89` after implementation because the active primary reply handler now has formal C++ and the helper-name blockers are resolved at support level. Keep aggregate C++ blank because exact child pages own source bodies.
- [UID:0000I3] `ChangePasswordDialogPane` and [UID:00001L] `ChangePasswordDialogPane` can remain `85/88` and `85/89` respectively unless the supervisor wants a small support-sync bump. Their broad class/file declarations, singleton declaration spelling, and folded-vs-standalone source grouping remain broader caps even though [UID:0002QD] itself is source-ready.
- [UID:0002QE] should not be raised by this implementation unless a sibling-specific callback includes formal C++ for it. Current report only updates sibling support evidence and keeps its no-direct-xref caveat.

## Recommended Target And Support Doc Updates

Target [UID:0002QD] `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`:

- Update metadata to `COMPLETION:91`, `CONFIDENCE:92`; keep owner/emitter/reconstructable as [UID:0000I3]/`TRUE`.
- Insert the exact formal C++ block above.
- Replace the stale "Do not enter final C++ yet" wording with the resolved disposition: first-draft formal C++ is ready and should emit through [UID:0000I3].
- Replace "saved IDA name" proof with current-session wording: current IDB still names the function `sub_4FEBF0`, but source-facing name `ChangePasswordDialogPane::HandlePasswordChangeReply` is evidence-backed.
- Preserve exact range `0x004febf0-0x004fee11`, size `0x221` / 545 bytes (Verified with `tools/int_convert.py`), preceding 14-byte `0xcc` padding, following `0x004fee11-0x004fee14` alignment, switch support `0x004fee14-0x004fee38`, and padding before sibling.
- Update result-code table to say the groups call `SetHoverControl(3)`, `SetHoverControl(4)`, or `SetHoverControl(5)`, tied to `accountName`, `currentPassword`, and `newPassword`.
- Document packet layout `[1]` result, `[2]` message length, `[3]` message payload.
- Document source-facing helper decisions for `g_pScreenDimmer`, `SimpleUString::FromMbcString`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical`, and `CloseDialog`.
- Preserve rejected alternatives: Socket/PacketBuffer/DialogPane/AlertPane/MainMenuPane/no-owner/RankingDialog are dependencies or pollution, not direct owners.

Support [UID:00022W] `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`:

- Update [UID:0002QD] row from "final C++ blocked" style wording to "formal source-ready reply method present after B002".
- Preserve aggregate blank C++ and source-family route.
- Record current MCP session `supervisor_20260628_resume`, target xref `0x004fe551`, switch-table refs `0x004fec64` and `0x004fec5d`, sibling no-xref result for `0x004fee40`, current raw IDA names, and the stale C001 saved-rename correction.
- Update reconstruction notes to say [UID:0002QD] now owns the emitted reply method body; the aggregate remains non-emitting/contextual.

Support [UID:0000I3] `by-file/ChangePasswordDialogPane.md`:

- Add a B002 support note that [UID:0002QD] is now source-ready with formal `ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)` C++.
- Replace or qualify the stale "saved IDA labels" sentence with current active-session evidence: current MCP reports raw names, but source-facing labels are still accepted.
- Update packet-helper inventory so [UID:0002QD] has resolved alert/close/control helper names and no longer blocks generated output.
- Keep the file owner route and standalone-vs-folded `login/ChangePasswordDialogPane.cpp` caveat.

Support [UID:00001L] `by-class/ChangePasswordDialogPane.md`:

- Update method row for `HandlePasswordChangeReply` to name packet bytes, result groups, `SetHoverControl`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical`, and `CloseDialog`.
- Preserve `SubmitPasswordChange` controls `3/4/5/6`, with controls `3/4/5` as transmitted fields and control `6` confirmation-only.
- Keep class page formal C++ blank unless a separate class-declaration pass is accepted; exact method body now belongs on [UID:0002QD].

Support [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`:

- Add a support note that the dispatcher branch at `0x004fe551` reaches the now source-ready [UID:0002QD] method and that packet type `2` is the local password-change reply route.
- Keep existing constructor/validation/submit C++ disposition unchanged unless a separate core pass is assigned.

Support [UID:0002QE] `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`:

- Add a cross-note only if implementation scope includes sibling support: current MCP still shows zero xrefs to `0x004fee40`; behavior remains same family with `g_pScreenDimmer`, message decode, `AlertPane`, `SetHoverControl(5)` for result `3..8`, and success `SlideCloseVertical()`/`CloseDialog()`.
- Keep sibling formal C++ blank unless a sibling-specific accepted report resolves its no-direct-route/source-emission policy.

Support [UID:0001OC] `DialogOkButtonString`, [UID:00029D] `g_pScreenDimmer`, and [UID:00003T]/[UID:0001U4] `DialogPane`:

- No required edits. They already provide sufficient source-facing support names. This report uses them as evidence.

Generated/project/manual coverage:

- Do not manually edit generated reports, generated C++, project-level reports, or manual `-coverage-report.md` files. Validator refresh should remove [UID:0002QD]'s empty marker from `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp`.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the supervisor accepts this report and sends an implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-removed.md](0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the first validator with `--wait-generated`, read-only check:

> Executable block R002 was removed from this report and preserved verbatim in [0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-removed.md](0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: [UID:0002QD] appears with emitted formal C++ content and no [UID:0002QD] empty emitter marker. Other unrelated empty markers in the same generated file may remain.

## Implementation Tracking Checklist

Implementation callback proof, 2026-06-28:

- [x] Update [UID:0002QD] metadata to `COMPLETION:91`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000I3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I3`, blank `EMITTER_POSITION_OPTIONAL`. Proof: applied in `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`; validator command `000000005255` reported `ok: 1`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into [UID:0002QD]. Proof: target page formal block now contains `DecodePasswordChangeReplyMessage`, `IsPasswordChangeAccountNameReplyError`, `IsPasswordChangeCurrentPasswordReplyError`, `IsPasswordChangeNewPasswordReplyError`, `ShowPasswordChangeReplyText`, and `ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)` exactly as accepted; generated C++ line checks show the body at `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` lines 108-185 after validator refresh.
- [x] Update [UID:0002QD] prose to resolve the empty-emitter disposition and remove the stale "Do not enter final C++ yet" blocker. Proof: target prose now classifies the range as the source-ready type-2 password-change reply method and documents formal C++ emission through [UID:0000I3].
- [x] Preserve [UID:0002QD] exact range, function size, preceding/following padding, switch support table ownership, and current MCP evidence. Proof: target page preserves `0x004febf0-0x004fee11`, 545-byte size, `0x004fee11-0x004fee14` alignment, `0x004fee14-0x004fee38` switch support, current raw `sub_4FEBF0` MCP status, dispatcher xref, and stale C001 rename correction.
- [x] Update [UID:0002QD] result-code table to use `SetHoverControl(3/4/5)` and account/current/new-password control roles. Proof: target prose and formal C++ classify account-name errors as `3,4,14,16,17,18,20,21`, current-password error as `15`, and new-password errors as `5,6,7,8,9`.
- [x] Update [UID:0002QD] helper naming decisions: `g_pScreenDimmer`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical`, `CloseDialog`, `SimpleUString::FromMbcString`. Proof: target prose and formal C++ use those source-facing names and document the source-facing replacement for raw helper names.
- [x] Mark the stale C001 saved-IDB rename claim as superseded by current MCP raw names while preserving source-facing handler names. Proof: target and support docs now state current MCP still reports raw `sub_4FEBF0`/`sub_4FEE40` while preserving accepted source-facing `ChangePasswordDialogPane::HandlePasswordChangeReply`.
- [x] Update [UID:00022W] aggregate row/prose for [UID:0002QD] formal C++ readiness and keep aggregate C++ blank. Proof: `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md` now records [UID:0002QD] as the emitted reply method body, preserves aggregate blank C++, raises support score to `87/89`, and validator command `000000005256` reported `ok: 1`.
- [x] Update [UID:0000I3] file page packet-helper inventory/source notes for [UID:0002QD] source-ready status and current MCP evidence. Proof: `by-file/ChangePasswordDialogPane.md` now records B002 source-ready status, helper decisions, current raw MCP name correction, and validator command `000000005257` reported `ok: 1`.
- [x] Update [UID:00001L] class method row/support notes for [UID:0002QD] packet layout, result groups, helper names, and close path. Proof: `by-class/ChangePasswordDialogPane.md` method row now records packet bytes `[1]/[2]/[3]`, `SetHoverControl(3/4/5)`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical`, and `CloseDialog`; validator command `000000005258` reported `ok: 1`.
- [x] Update [UID:0002QA] core page with dispatcher branch support to the now source-ready [UID:0002QD]. Proof: `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md` now documents dispatcher branch `0x004fe551` and packet type `2` routing to the source-ready [UID:0002QD]; validator command `000000005260` reported `ok: 1`.
- [x] Update [UID:0002QE] sibling support note only, preserving no-direct-xref caveat and blank formal C++ unless supervisor excludes sibling support from implementation scope. Proof: `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md` now records support sync with current raw `sub_4FEE40`, zero direct xrefs, same-family behavior, `SetHoverControl(5)`, `AlertPane`, close path, and blank formal C++; validator command `000000005261` reported `ok: 1`.
- [x] Run all scoped validators listed above, recording command, working directory, `command_id`, `command_timestamp`, exit code, and `ok` count. Proof: final validator batch from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x004febf0-0x004fee11.HandlePasswordChangeReply.md --apply --queue-timeout 240 --wait-generated` -> command `000000005255`, timestamp `2026-06-28T18:43:20-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md --apply --queue-timeout 240` -> command `000000005256`, timestamp `2026-06-28T18:43:36-04:00`, exit `0`, `ok: 1`, generated refresh deferred; unrelated warning retained for missing ref target [UID:00019W] path `by-memory/0x004ff040-0x00502c0c.ScrolledTextControlPane.md`.
  - `python .\tools\validator.py --mode file --file by-file\ChangePasswordDialogPane.md --apply --queue-timeout 240` -> command `000000005257`, timestamp `2026-06-28T18:43:42-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class\ChangePasswordDialogPane.md --apply --queue-timeout 240` -> command `000000005258`, timestamp `2026-06-28T18:43:51-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md --apply --queue-timeout 240` -> command `000000005260`, timestamp `2026-06-28T18:45:56-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md --apply --queue-timeout 240` -> command `000000005261`, timestamp `2026-06-28T18:46:02-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- [x] After the target validator with `--wait-generated`, read-only confirm `auto-generated/NexusTK/login/ChangePasswordDialogPane.cpp` no longer has [UID:0002QD] as an empty emitter marker. Proof: generated header now shows `validator-command-id: 000000005261`, `validator-refreshed-at: 2026-06-28T18:46:02-04:00`, `validator-refresh-source: deferred-generated-refresh`; [UID:0002QD] appears as `Completion:91 | Confidence:92` with the accepted formal body, and the exact marker check returned `NO_UID0002QD_EMPTY_EMITTER_MARKER`. Unrelated empty markers remain for [UID:00001L], [UID:0002QA], [UID:00022W], [UID:0002QE], and [UID:0002XM].
- [x] Do not edit generated reports, generated C++ by hand, project-level generated files, manual coverage reports, validator/tool state, or IDA DB. Proof: generated/project/tool changes were validator-owned side effects only; no manual edits were made to generated files, project-level generated files, manual coverage reports, validator/leaser state, or IDA DB. MCP remained responsive on session `supervisor_20260628_resume` during the callback, with `idb_list` JSON-RPC probe `701/702` confirming active worker PID `5124`.

## Implementation Callback Closure

Changed files in this callback:

- `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`
- `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`
- `by-file/ChangePasswordDialogPane.md`
- `by-class/ChangePasswordDialogPane.md`
- `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`
- `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`
- `tools/leaser/Agents/Agent-B002/research/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md`

Leases used:

- B002 leased the six by-* files for the immediate edit/validator batch. The first lease batch expired before cleanup, so B002 reacquired fresh leases for the same six by-* files before the final validator batch.
- Final release command from `tools/leaser`: `python .\leaser.py B002 unlease` succeeded for all six by-* paths.
- Read-only checks of `tools/leaser/Agents/Agent-B002/current_leases.md` and `tools/leaser/Agents/current_leases.md` found no remaining B002/target matches after release.

Validators run: all six scoped validators passed as listed in the checklist above. The target generated output was refreshed and later regenerated by validator command `000000005261`; [UID:0002QD] no longer appears as an empty emitter marker and its formal method body is present.

Unapplied blockers: none. Supervisor still owns final verification and `execute_report`; B002 did not run report execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md","timestamp":"2026-06-28T18:51:27","uid":"0002QD"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002QD-HandlePasswordChangeReply-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002QD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
