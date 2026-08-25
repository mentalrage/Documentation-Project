** TARGET-REPORT-UID:0002EJ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 Source-Quality Report: [UID:0002EJ] BoardListDialogCore

Assignment: `B004-report-board-list-dialog-core-source-quality-0002EJ-mcp-20260623`  
Target: `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md`  
Report date: 2026-06-23  
Agent: B004  
Task type: report-only MCP-backed research

## Finalized Report / Current Recommendation

Raise [UID:0002EJ] from `COMPLETION:85`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00000Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000Z`, and the blank emitter position unchanged.

The current MCP pass resolves the prior source-quality blockers enough to add first-draft C++ to the target. The target is a coherent BoardListDialog method island: constructor, command dispatcher, selected-board opener, and selection-dependent button updater. The old unresolved names can now be source-facing rather than generated/IDA-facing:

- `this+0x1fc`: inherited dialog control host/container; recommend source spelling `m_controls` or helper accessors such as `GetControl`.
- `this+0x270`: inherited `DialogInSession` session pointer; BoardListDialog callers make `BulletinSession *session` the best local spelling, with the base type still `DialogSession *`.
- selected-row state: control id `3` returns the `BoardListPane`/list control, its list state is at `+0x108`, selected index is at `+0x134`, and selected entry word 0 is the board id.
- command ids: command `1` opens the selected board; command `2` closes all dialogs through the session.
- packet constants: opcode `0x3b` / 59, subcommand `0x02`, selected board id as big-endian u16, sentinel `0x7fff`, and mode byte `0xec` when `g_useEpfAssets == 1` else `0xf0`; send length is 7 bytes.
- `dword_67A7EC`: source-facing `Socket *g_packetSender`, not `g_pNetworkManager`, `CashShopRequest`, or raw `dword_67A7EC`.
- `byte_66DA97`: source-facing `g_useEpfAssets`, not the generated `g_useHighResLayout` or raw byte name.
- `dword_67A748`: source-facing `UserPane *g_pUserPane`; field `+0x214` is the active dialog host pane used by sibling dialog/screen-dimmer paths.
- `0x004a0f40`: `DialogSession::CloseAllDialogs`.
- `0x004a12b0`: `CreateScreenDimmer`, not a DialogInSession transition method.

Support documentation should be synchronized in `by-class/BoardListDialog.md`, `by-file/BoardDialogs.md`, and the parent inventory `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`. `by-class/BoardListPane.md` and `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md` already carry the essential activation callback route, but they may receive a narrow cross-link during implementation if the supervisor wants the now-source-ready method name propagated.

## Current Target State

The target currently records:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00000Z`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000Z`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++

The target's existing evidence already identifies the four functions and their padding, but it keeps C++ blank because field names, packet/config names, and source declarations were considered unresolved. The current MCP pass closes those blockers to a first-draft standard while retaining final-spelling caveats as confidence caps, not code-entry blockers.

## Supervisor Active Recheck

MCP was used as required.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module input path from `server_health`: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true
- Strings cache size: 2067
- Binary SHA-256 from `survey_binary`: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Binary MD5 from `survey_binary`: `4247e04e20b65d6414c7238aa8ff5515`
- Segments from `survey_binary`: `.text 0x00401000-0x0060d000`, `.idata 0x0060d000-0x0060d670`, `.rdata 0x0060d670-0x0066d000`, `.data 0x0066d000-0x0069d000`

No MCP outage occurred during this pass.

## Inference Research Guidance Check

The prior blockers were treated as research work, not as final no-change reasons:

- Field names were rechecked against MCP decompilation/disassembly, BoardListDialog generated output, BoardListPane callback docs, DialogInSession layout docs, UserPane/global docs, PacketBuffer helper docs, and sibling NewArticleDialog behavior.
- Packet/protocol names were resolved to source-facing constants at the call site instead of leaving generated names or raw byte names.
- Source declarations were checked against vtable slots, command callback ABI, constructor callers, sibling dialog command callbacks, and generated output as a lead only.
- C++ readiness was judged under the current code-entry gate, not under final-header exactness.
- Split/child alternatives were re-evaluated against function boundaries and padding fences.

The result is not a no-change disposition. The target can improve and can carry first-draft source-shaped C++.

## Evidence Standards Used

Evidence was separated into:

- MCP facts: session-backed function boundaries, decompilation, disassembly, xrefs, bytes, and strings.
- Documentation facts: current by-* pages for BoardListDialog, BoardListPane, BoardDialogs, DialogInSession, PacketBuffer helpers, Socket send helper, globals, and sibling dialogs.
- Generated-output leads: `simroot_v2` and auto-generated C++ were used only to compare source-shape candidates and reject stale names.
- Inference: field spellings and high-level helper names where no symbol exists. Inference is allowed here because the dataflow and owner route are now bounded and cross-checked.

## Function / Child Inventory

| Range | MCP name | Size | Role | Notes |
|---|---:|---:|---|---|
| `0x00472070-0x00472869` | `sub_472070` | `0x7f9` | BoardListDialog constructor | Calls `DialogInSession(session, 2, 0)`, parses board-list packet, builds controls, sets vtables. |
| `0x00472869-0x00472870` | none | 7 bytes | padding | `cc` fence. |
| `0x00472870-0x00472898` | `sub_472870` | `0x28` | command dispatcher | Command `1` calls opener; command `2` calls `DialogSession::CloseAllDialogs`; returns `retn 8`. |
| `0x00472898-0x004728a0` | none | 8 bytes | padding | `cc` fence. |
| `0x004728a0-0x00472999` | `sub_4728A0` | `0xf9` | selected-board opener | Reads selected board id, serializes packet, sends through `g_packetSender`, records active dialog host, creates screen dimmer. |
| `0x00472999-0x004729a0` | none | 7 bytes | padding | `cc` fence. |
| `0x004729a0-0x004729dd` | `sub_4729A0` | `0x3d` | button-state updater | Enables/disables command id `1` button based on list selection count. |
| `0x004729dd-0x004729e0` | none | 3 bytes | padding | `cc` fence before BoardListPane island. |

MCP `lookup_funcs` at `0x004729dd` and `0x004729e0` confirms no hidden function at the exact target end and that the successor belongs to the next BoardListPane range, not this target.

## Direct Xref / Caller Inventory

MCP `xrefs_to` results:

- `0x00472070`: two code callers:
  - `0x00471604` inside `sub_471550`
  - `0x00471921` inside `sub_4718A0`
- `0x00472870`: one data xref from vtable slot `0x00613c90`
- `0x004728a0`: two code xrefs:
  - `0x0047288f` from the command dispatcher
  - `0x00472b5e` from BoardListPane activation/double-click handling
- `0x004729a0`: one data xref from vtable slot `0x00613c94`
- BoardListDialog vtable bases stored by the constructor:
  - `0x00613c48` referenced at `0x004720cd`
  - `0x00613cac` referenced at `0x004720d3`
  - `0x00613cdc` referenced at `0x004720dd`

The direct route supports BoardListDialog ownership rather than BoardListPane, BulletinSession, or a non-owner aggregate.

## MCP Facts: Constructor `0x00472070`

MCP decompilation and disassembly show a source-authored constructor with normal object construction rather than a compiler-only thunk:

- Calls `sub_4A1400((_BYTE *)this, a2, 2, 0)` at `0x004720c8`. Current DialogInSession docs identify this as the base constructor storing session data at `+0x270`, dialog pane config id `2`, and dialog type `0`.
- Stores BoardListDialog vtable bases at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Branches on `byte_66DA97 == 1`, now normalized to `g_useEpfAssets`.
- Reads a title length byte from the packet, copies multibyte title text, converts through `MultiByteToWideChar`, and sets the dialog title through `sub_49DB30`.
- Reads an item-count byte after the title and allocates a `0x14c` / 332-byte BoardListPane object.
- Initializes the pane with control/config id `0x202` / 514, item count, width `360`, row height `14`, and boolean flags.
- Iterates the packet entries. Each entry begins with a big-endian u16 board id, then a one-byte text length and text bytes. The constructor converts the item text and appends an entry whose first word is the board id.
- Adds a background image/control, the open/close image buttons, and the list control.
- EPF/current layout uses resource string `DL`, button image ids `17` and `15`, open button rect `(144,381)-(207,405)`, close button rect `(231,381)-(294,405)`, and list rect `(25,56)-(430,356)`.
- Legacy layout uses `DL`/`NP` resource strings, open button rect `(149,316)-(221,332)`, close button rect `(226,316)-(298,332)`, and list rect `(36,71)-(410,295)`.
- Final calls set hover/control routing: control id `3` as the list, command/control id `1` as the open button, command/control id `2` as the close button, then apply the caller-provided rectangle/position.

The constructor callers sit in the Board/Bulletin dialog open path; this supports a source signature using `BulletinSession *session` locally, while acknowledging the base constructor type is `DialogSession *`.

## MCP Facts: Command Dispatcher `0x00472870`

MCP decompilation:

```c
if (a4 == 1)
    sub_4728A0(this);
else if (a4 == 2)
    sub_4A0F40(*(this + 0x270), ...);
```

MCP disassembly adds the ABI detail:

- The first stack argument is the command id.
- The second stack argument is unused in this function.
- The function returns with `retn 8`, matching a two-argument command callback shape.
- Command `1` calls `0x004728a0`.
- Command `2` loads `this+0x270` and calls `0x004a0f40`.

Current support docs identify `0x004a0f40` as `DialogSession::CloseAllDialogs`, not the older generated `CloseSession` spelling. The recommended first-draft signature is therefore:

```cpp
void BoardListDialog::OnCommand(int commandId, int unusedNotifyCode);
```

`OnCommand` is preferred over `OnButtonCommand` because it matches existing BoardDialogs by-* convention and sibling dialog pages. The unused second parameter should be kept in the implementation detail or noted in text because the raw virtual callback consumes 8 bytes of stack arguments.

## MCP Facts: Selected-Board Opener `0x004728a0`

MCP decompilation and disassembly show:

- `this+0x1fc` is used as the inherited control host/container.
- The function asks the control host for control id `3`.
- The returned control wrapper's `+0x108` points to list/selection state.
- The selected index is read from `+0x134`.
- Negative selected index exits without sending.
- A selected entry is retrieved through `sub_4F3DC0`; current ListPane docs identify this as the indexed entry accessor / `ListPane::GetItem`, not a raw memory helper.
- The selected entry's first word is the board id.
- Packet serialization is:
  - `PacketBufferWriteUInt8(0x3b, packet)` / opcode 59
  - `PacketBufferWriteUInt8(0x02, packet + 1)` / subcommand 2
  - `PacketBufferWriteUInt16BE(boardId, packet + 2)`
  - `PacketBufferWriteUInt16BE(0x7fff, packet + 4)`
  - byte at payload offset 6 is `0xec` when `g_useEpfAssets == 1`, otherwise `0xf0`
  - a local scratch byte at offset 7 is zeroed by helper behavior, but `QueueAndSendPacket` is called with length 7
- The send call is `Socket::QueueAndSendPacket(g_packetSender, packet, 7)`.
- If `this+0x270` is non-null:
  - if `g_pUserPane` is non-null, `g_pUserPane + 0x214` receives `this`
  - session byte/flag at `+0x100` is set to `1`
  - `CreateScreenDimmer()` is called

The raw decompiler return type is `int` because it carries through selected-index/callee residue. The source operation is side-effecting and should be represented as `void BoardListDialog::OpenSelectedBoard()`.

## MCP Facts: Button-State Updater `0x004729a0`

MCP decompilation and disassembly show:

- Gets control id `1` from the control host at `this+0x1fc`; this is the open/confirm button.
- Gets control id `3`; this is the BoardListPane/list control.
- Uses the returned list wrapper's `+0x108` list state.
- Calls `sub_4F3E20`; current ListPane docs identify this as `ListPane::GetSelectionCount`.
- If selection count is greater than zero, the button vtable slot `+0x4c` is tail-called.
- Otherwise vtable slot `+0x50` is tail-called.

The source role is `BoardListDialog::UpdateButtonState()` enabling or disabling the open button based on whether the list has a selected row.

## Helper / Global / Field Name Resolution

| Raw evidence | Recommended source-facing name | Reason |
|---|---|---|
| `this+0x1fc` | `m_controls`, `GetControl`, or inherited control host | Used uniformly to resolve control ids `1`, `2`, and `3` through vslot `+0x10`; source docs should avoid raw offset. |
| `this+0x270` | `m_session` / `GetSession()` / `BulletinSession *session` | DialogInSession layout identifies this as session data pointer; BoardListDialog callers are bulletin-session routes. |
| control id `1` | open/confirm button | Constructor creates the image button and final setup marks id `1`; updater enables/disables this button. |
| control id `2` | close/cancel button | Command dispatcher closes all dialogs for command `2`; constructor creates second image button. |
| control id `3` | board list pane/control | Constructor creates list, command opener and updater both query id `3`. |
| selected index `+0x134` | list selected row index | Guarded against `< 0`; then used as index into `ListPane::GetItem`. |
| `dword_67A7EC` | `g_packetSender` | `by-global/g_packetSender.md` and QueueAndSendPacket support docs identify the Socket owner and reject generated CashShop/network aliases. |
| `byte_66DA97` | `g_useEpfAssets` | Current global doc identifies the EPF/current asset selector and StartupWindow writer. |
| `dword_67A748` | `g_pUserPane` | Current global doc identifies UserPane ownership; `+0x214` is the active dialog host pane used by sibling dialog/screen-dimmer paths. |
| `0x004a0f40` | `DialogSession::CloseAllDialogs` | Current BulletinSession/DialogSession docs supersede older generated `CloseSession`. |
| `0x004a12b0` | `CreateScreenDimmer` | Current ScreenDimmer factory page identifies this as a standalone helper, not a session transition method. |
| `0x00575380` | `PacketBufferWriteUInt8` | Current packet helper page identifies scalar u8 write helper; raw ABI is value first, destination second. |
| `0x005753a0` | `PacketBufferWriteUInt16BE` | Current packet helper page identifies big-endian u16 write helper. |
| `0x00574bb0` | `Socket::QueueAndSendPacket` | Current Socket page identifies queue/send behavior and explicit payload size. |
| `0x004f3dc0` | `ListPane::GetItem` / indexed entry accessor | Current ListPane docs identify indexed item retrieval. |
| `0x004f3e20` | `ListPane::GetSelectionCount` | Current ListPane docs identify selection count/selected-state count. |

Generated aliases such as `g_useHighResLayout`, `g_pNetworkManager`, `g_pPlayerData`, `DialogInSession::TransitionState`, and `DialogInSession::CloseSession` should be treated as stale/generated leads, not final target wording.

## Heuristic / Inference Reanalysis And Validation

The strongest remaining inferences are exact original C++ spellings for fields and methods. Those cap confidence but do not block first-draft C++:

- `OnCommand` vs `OnButtonCommand`: MCP proves the command callback shape and ids; by-* sibling convention favors `OnCommand`. The generated `OnButtonCommand` name is less authoritative and should not drive by-* naming.
- `OpenSelectedBoard` vs `OnConfirmSelection`: MCP proves both command id `1` and BoardListPane activation call the same method. `OpenSelectedBoard` describes both routes better than a button-only name.
- `m_controls` / `GetControl`: no symbol proves the field spelling, but the control-host role is direct and repeated in all three methods. Source C++ may use the project-local helper/accessor style chosen by the target implementer.
- `m_dialogTransitionPending` / session `+0x100`: exact field spelling remains inferred, but the sibling NewArticleDialog and CreateScreenDimmer route make the source role bounded: set a session modal/dialog transition flag before creating the screen dimmer.
- `m_activeDialogHostPane` at `g_pUserPane +0x214`: exact field spelling is inferred, but the UserPane and ScreenDimmer pages already establish this as an active dialog host pane route. It is safe to use source-facing wording and retain the offset caveat.

The strict score-blocker review does not support leaving the target at 85. All reasonable current routes were checked: MCP boundaries, vtable slots, direct callers, BoardListPane callback, sibling dialog behavior, helper pages, global pages, generated output, and prior reports.

## Inference Claim Ledger

| Claim | Type | Evidence | Score impact |
|---|---|---|---|
| The target is a BoardListDialog method island. | Direct | Constructor vtables, vtable slots, callers, BoardListPane callback, current by-* class docs. | Raises completion. |
| Command callback receives two stack args but only uses command id. | Direct | `0x00472870` disassembly returns `retn 8`; first arg drives branch; second unused. | Improves C++ signature detail. |
| Command `1` opens selected board and command `2` closes all dialogs. | Direct | MCP decompile/disasm of `0x00472870`; support doc for `0x004a0f40`. | Improves behavior certainty. |
| Packet opcode/subcommand are `0x3b`/`0x02`. | Direct | MCP decompile/disasm of `0x004728a0`; packet helper docs. | Resolves protocol blocker. |
| `byte_66DA97` means `g_useEpfAssets`. | Cross-doc direct/inferred name | Global page and target xrefs. | Replaces generated stale alias. |
| `dword_67A7EC` means `g_packetSender`. | Cross-doc direct/inferred name | Global page and Socket send helper page. | Replaces raw/global alias. |
| `dword_67A748 + 0x214` is active dialog host pane. | Cross-doc inference | UserPane/global page, ScreenDimmer route, sibling NewArticleDialog. | Confidence cap, not code blocker. |
| `this+0x270` is session pointer. | Cross-doc direct | DialogInSession layout and base constructor docs. | Supports constructor and command C++. |
| `this+0x1fc` is control host. | Direct behavior/inferred name | Repeated vslot `+0x10` control lookups by ids 1/3. | Confidence cap only. |
| Formal C++ should be source-shaped and not raw vtable/manual allocation code. | Rule/application | Reconstructable target, owner/emitter route, current code-entry gate. | Adds first-draft C++. |

## Positive Evidence Summary

- Current MCP session `80de0a67` confirms all four function boundaries and padding fences.
- Constructor callers route into Board/Bulletin dialog creation paths.
- Vtable slots directly route command and update virtual methods.
- BoardListPane activation routes directly to `OpenSelectedBoard`, proving the method is not button-only.
- Packet serialization is fully bounded: opcode, subcommand, board id, sentinel, mode byte, and send length.
- Helper/global docs now provide source-facing names for all old raw globals and helper calls.
- Sibling NewArticleDialog supports the same UserPane active-dialog host and CreateScreenDimmer pattern.
- The target remains a coherent exact class island; there is no hidden raw helper or unrelated owner inside the range.

## Negative Evidence / Rejected Alternatives

- Reject BoardListPane as owner. BoardListPane calls `0x004728a0` for activation, but it does not own the BoardListDialog constructor, command callback, or update vtable slots.
- Reject BulletinSession as owner. The session path constructs the dialog and supplies session state, but the code is BoardListDialog method code.
- Reject DialogSession/DialogInSession as owner. `+0x270`, `CloseAllDialogs`, and base construction are dependencies; vtable/caller evidence keeps the methods on BoardListDialog.
- Reject UserPane as owner. `g_pUserPane +0x214` receives the active dialog host pointer, but this is a consumer/host dependency only.
- Reject Socket/PacketBuffer as owner. Packet serialization and send helpers are callees; the source action remains selected-board open inside BoardListDialog.
- Reject ScreenDimmer as owner. `CreateScreenDimmer` is a follow-up visual/modal effect after queuing the packet.
- Reject `g_pNetworkManager`, `g_pPlayerData`, `g_useHighResLayout`, `DialogInSession::TransitionState`, and `CloseSession` as final names. They are generated-output aliases or stale approximations superseded by current by-* pages.
- Reject no-owner/non-emitting disposition. The target is reconstructable, has a canonical owner/emitter, and now has enough current source-quality evidence for first-draft C++.
- Reject range split. All internal gaps are `cc` padding between same-class methods, and the successor `0x004729e0` is the BoardListPane island.

## Ranked Ownership Analysis

1. `BoardListDialog` / [UID:00000Z] - best owner and emitter. Constructor vtables, vtable slots, command/update methods, selected-board method, and current documentation all converge here.
2. `BoardDialogs` source file - plausible source file placement for generated output and support docs, but too broad to be the canonical owner of this exact method island.
3. `BulletinSession` - constructs and hosts the dialog but does not own the class methods.
4. `BoardListPane` - provides activation callback into `OpenSelectedBoard`; not owner of the target.
5. `DialogSession` / `DialogInSession` - base/session dependency; not class owner.
6. `UserPane`, `Socket`, `PacketBuffer`, `ScreenDimmer`, globals - dependencies only.
7. no-owner/non-emitting - rejected because the exact target is source-authored, class-owned, reconstructable, and above the code-entry gate.

## Source Placement

The best placement remains the BoardListDialog class under the BoardDialogs source-family. The target should emit through [UID:00000Z], while `by-file/BoardDialogs.md` records the broader source-file relationship.

The source file likely contains BoardListDialog, BoardListPane, NewArticleDialog, and related board/article dialog helpers. This target should not be moved to a packet or global owner just because it serializes a packet. The packet send is a UI action in response to opening a selected board.

## Range / Split / Padding / Reclassification Analysis

No split is recommended.

- `0x00472070-0x00472869`: constructor
- `0x00472869-0x00472870`: 7-byte `cc` padding
- `0x00472870-0x00472898`: command callback
- `0x00472898-0x004728a0`: 8-byte `cc` padding
- `0x004728a0-0x00472999`: selected-board opener
- `0x00472999-0x004729a0`: 7-byte `cc` padding
- `0x004729a0-0x004729dd`: button updater
- `0x004729dd-0x004729e0`: 3-byte `cc` padding before BoardListPane

The existing exact-child target is valid. Reclassification to non-emitting aggregate would lose useful class-level source output and is not supported by the evidence.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are part of this report-only assignment. If a supervisor later chooses to apply IDA names, recommended read-only naming candidates are:

- `sub_472070` -> `BoardListDialog::BoardListDialog`
- `sub_472870` -> `BoardListDialog::OnCommand`
- `sub_4728A0` -> `BoardListDialog::OpenSelectedBoard`
- `sub_4729A0` -> `BoardListDialog::UpdateButtonState`
- `dword_67A7EC` -> `g_packetSender`
- `byte_66DA97` -> `g_useEpfAssets`
- `dword_67A748` -> `g_pUserPane`

Type comments should preserve the offset caveats for `this+0x1fc`, `this+0x270`, session `+0x100`, and `g_pUserPane +0x214`.

## Recommended Target / Support Doc Changes If Accepted

Target `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
- Add a dated 2026-06-23 B004 MCP-backed source-quality evidence section with session `80de0a67`, IDB path, executable hash/provenance, function inventory, padding, callers, vtable slots, decompile/disassembly facts, helper/global name resolution, and generated-output caveats.
- Replace stale raw/global wording with source-facing names: `g_packetSender`, `g_useEpfAssets`, `g_pUserPane`, `CreateScreenDimmer`, `DialogSession::CloseAllDialogs`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `ListPane::GetItem`, and `ListPane::GetSelectionCount`.
- Add first-draft source-shaped C++ for constructor, `OnCommand`, `OpenSelectedBoard`, and `UpdateButtonState`.
- Preserve rejected alternatives and score-cap rationale.

Support `by-class/BoardListDialog.md`:

- Update method table and narrative to show that the old field/protocol/name blockers have been resolved to first-draft quality.
- Record the two-argument raw callback shape for `OnCommand`, while using source-facing `commandId` and unused notify/control parameter wording.
- Add field/global/helper name resolution and remaining confidence caps.
- Recommend matching metadata improvement if the class page score currently trails the evidence; the page should no longer say C++ is blocked solely by unresolved field names.

Support `by-file/BoardDialogs.md`:

- Add a support note that [UID:0002EJ] is now first-draft C++ ready and remains BoardListDialog-owned within the BoardDialogs source-family.
- Preserve that BoardDialogs is a broad source-file bucket and not the canonical exact-memory owner.

Support `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`:

- Update the child inventory row for [UID:0002EJ] from `85/88` to `88/90`.
- Note that the BoardListDialog child now has MCP-backed normalized helper/global names and first-draft C++ readiness.

Optional/support already sufficient unless an implementation callback requests synchronization:

- `by-class/BoardListPane.md` and `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md` already document the activation callback into `0x004728a0`; update only if the supervisor wants the final method name `BoardListDialog::OpenSelectedBoard` copied there.
- `by-global/g_packetSender.md`, `by-global/g_useEpfAssets.md`, `by-global/g_pCollectionData.md`, PacketBuffer helper docs, Socket send helper docs, DialogSession docs, and CreateScreenDimmer docs already contain same-or-greater source facts for their owned items.

## Score / Metadata Recommendation

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00000Z`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000Z`
- `EMITTER_POSITION_OPTIONAL:` blank

Completion rises because the target can now carry source-shaped C++ and the old unresolved packet/global/helper blockers are closed. Confidence rises because live MCP confirms the function boundaries, callers, vtable slots, disassembly, decompilation, and xrefs, and support docs resolve helper/global names.

Do not raise above 90 confidence yet because exact original header spellings remain inferred for the control container field, session transition flag at `+0x100`, active dialog host field at `g_pUserPane +0x214`, and method spelling alternatives. These are bounded source-name caveats, not C++ blockers.

## First-Draft C++ Recommendation

Add first-draft source-shaped C++ to the target. The block should avoid decompiler artifacts, raw vtable stores, manual base-pointer writes, and generated stale aliases.

Recommended draft:

```cpp
namespace
{
    constexpr int kBoardListOpenCommand = 1;
    constexpr int kBoardListCloseCommand = 2;
    constexpr int kBoardListOpenButtonId = 1;
    constexpr int kBoardListCloseButtonId = 2;
    constexpr int kBoardListPaneId = 3;
    constexpr unsigned char kOpenBoardOpcode = 0x3b;
    constexpr unsigned char kOpenBoardSubcommand = 0x02;
    constexpr unsigned short kOpenBoardLimit = 0x7fff;
    constexpr unsigned char kOpenBoardEpfMode = 0xec;
    constexpr unsigned char kOpenBoardLegacyMode = 0xf0;

    unsigned short ReadBoardIdBE(const unsigned char *cursor)
    {
        return static_cast<unsigned short>((cursor[0] << 8) | cursor[1]);
    }

    void DecodeBoardText(wchar_t *out, unsigned int outCount, const unsigned char *text, unsigned int length)
    {
        // Source placeholder for the MultiByteToWideChar-backed conversion used by the binary.
        ConvertBoardDialogText(out, outCount, text, length);
    }
}

BoardListDialog::BoardListDialog(BulletinSession *session, const Rect &bounds, const unsigned char *packetData)
    : DialogInSession(session, 2, 0)
{
    const unsigned int titleLength = packetData[0];
    wchar_t title[256] = {};
    DecodeBoardText(title, 256, packetData + 1, titleLength);
    SetTitle(title);

    const unsigned int itemCount = packetData[titleLength + 1];
    BoardListPane *listPane = new BoardListPane(0x202, itemCount, 360, 14, false, true);

    const unsigned char *cursor = packetData + titleLength + 2;
    for (unsigned int index = 0; index < itemCount; ++index)
    {
        BoardListEntry entry = {};
        entry.boardId = ReadBoardIdBE(cursor);
        cursor += 2;

        const unsigned int textLength = *cursor++;
        DecodeBoardText(entry.text, 257, cursor, textLength);
        cursor += textLength;

        listPane->AddEntry(entry);
    }

    if (g_useEpfAssets == 1)
    {
        AddBackgroundImage("DL");
        AddImageButton(kBoardListOpenButtonId, Rect(144, 381, 207, 405), 17);
        AddImageButton(kBoardListCloseButtonId, Rect(231, 381, 294, 405), 15);
        AddControl(kBoardListPaneId, listPane, Rect(25, 56, 430, 356));
    }
    else
    {
        AddBackgroundImage("DL");
        AddImageButton(kBoardListOpenButtonId, Rect(149, 316, 221, 332), 17);
        AddImageButton(kBoardListCloseButtonId, Rect(226, 316, 298, 332), 15);
        AddControl(kBoardListPaneId, listPane, Rect(36, 71, 410, 295));
    }

    SetHoverControl(kBoardListPaneId);
    SetActiveControl(kBoardListOpenButtonId);
    SetCurrentControl(kBoardListCloseButtonId);
    SetBounds(bounds);
}

void BoardListDialog::OnCommand(int commandId, int unusedNotifyCode)
{
    (void)unusedNotifyCode;

    if (commandId == kBoardListOpenCommand)
    {
        OpenSelectedBoard();
    }
    else if (commandId == kBoardListCloseCommand)
    {
        if (m_session != nullptr)
            m_session->CloseAllDialogs();
    }
}

void BoardListDialog::OpenSelectedBoard()
{
    BoardListPane *listPane = static_cast<BoardListPane *>(GetControl(kBoardListPaneId));
    if (listPane == nullptr)
        return;

    const int selectedIndex = listPane->GetSelectedIndex();
    if (selectedIndex < 0)
        return;

    const BoardListEntry *entry = listPane->GetItem(selectedIndex);
    if (entry == nullptr)
        return;

    unsigned char packet[8] = {};
    PacketBufferWriteUInt8(kOpenBoardOpcode, packet);
    PacketBufferWriteUInt8(kOpenBoardSubcommand, packet + 1);
    PacketBufferWriteUInt16BE(entry->boardId, packet + 2);
    PacketBufferWriteUInt16BE(kOpenBoardLimit, packet + 4);
    PacketBufferWriteUInt8(g_useEpfAssets == 1 ? kOpenBoardEpfMode : kOpenBoardLegacyMode, packet + 6);

    g_packetSender->QueueAndSendPacket(packet, 7);

    if (m_session != nullptr)
    {
        if (g_pUserPane != nullptr)
            g_pUserPane->m_activeDialogHostPane = this;

        m_session->m_dialogTransitionPending = true;
        CreateScreenDimmer();
    }
}

void BoardListDialog::UpdateButtonState()
{
    ButtonPane *openButton = static_cast<ButtonPane *>(GetControl(kBoardListOpenButtonId));
    BoardListPane *listPane = static_cast<BoardListPane *>(GetControl(kBoardListPaneId));
    if (openButton == nullptr || listPane == nullptr)
        return;

    if (listPane->GetSelectionCount() > 0)
        openButton->Enable();
    else
        openButton->Disable();
}
```

Implementation notes for this C++:

- `BulletinSession *session`, `m_session`, `m_dialogTransitionPending`, `m_activeDialogHostPane`, `BoardListEntry`, and helper names are source-facing placeholders for now; keep offset evidence in prose.
- The constructor control helper names should match the local by-* style during implementation if the target already uses a different source helper vocabulary.
- Do not emit manual vtable stores, raw `operator new(0x14c)` calls, IDA temporary names, or raw offsets in the formal C++ block.
- `packet[8]` is intentional because helper writes zero scratch bytes after scalar values; the send length remains exactly 7.

## C++ / No-Code Gate

The target passes the current code-entry gate:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS:00000Z`
- average score currently `(85 + 88) / 2 = 86.5`, already above 85
- recommended score `(88 + 90) / 2 = 89`

No-code disposition is rejected. The current evidence supports first-draft C++ while keeping exact-source-spelling caveats in prose.

## Exact Supervisor-Owned Coverage Text

If the supervisor accepts the score change, replace the existing [UID:0002EJ] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md) 0x00472070-0x004729dd | class constructor plus virtual methods | BoardListDialogCore : reconstructable : 88% : strong : MCP session 80de0a67 confirms BoardListDialog constructor/command/open/update functions, constructor callers, vtable slots, internal padding, BoardListPane activation xref, normalized g_useEpfAssets/g_packetSender/g_pUserPane dependencies, selected-board packet 0x3b/0x02 length 7, and first-draft BoardListDialog C++ readiness.
```

Do not edit any `-coverage-report.md` file during the report-only phase.

## Validators Expected After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* document. Expected minimum if accepted:

> Executable block R001 was removed from this report and preserved verbatim in [0002EJ-BoardListDialogCore-source-quality-removed.md](0002EJ-BoardListDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add validators for `by-class\BoardListPane.md` or `by-memory\0x004729e0-0x00472bf5.BoardListPaneCore.md` only if those optional support docs are edited.

## Changed Files In This Report-Only Pass

- `tools/leaser/Agents/Agent-B004/research/0002EJ-BoardListDialogCore-source-quality.md`

No by-* docs, generated/project-level files, IDA DB/tool state, or coverage files were edited.

## Implementation Tracking Checklist

- [x] Lease and update `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md`: metadata to `88/90`, dated MCP evidence, function inventory, xrefs, field/helper/global resolution, rejected alternatives, score rationale, and first-draft C++.
  - Proof: B004 lease acquired, then target metadata changed to `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable kept unchanged. Added first-draft source-shaped C++ in the managed reconstruction block for constructor, `OnCommand`, `OpenSelectedBoard`, and `UpdateButtonState`. Added `2026-06-23 B004 MCP-Backed Source-Quality Recheck`, updated behavior/source-name sections, score rationale, and change log with session `80de0a67`, hash/provenance, four function ranges, no-boundary function proof, padding, constructor callers, vtable slots, BoardListPane activation xref, packet `0x3b`/`0x02` length `7`, `g_useEpfAssets`, `g_packetSender`, `g_pUserPane`, `DialogSession::CloseAllDialogs`, `CreateScreenDimmer`, packet/ListPane helpers, generated-alias rejections, and confidence caps.
- [x] Lease and update `by-class/BoardListDialog.md`: method names/signatures, command callback ABI, source-facing field/global names, no-longer-blocked C++ readiness, and remaining confidence caps.
  - Proof: B004 lease acquired, then class metadata raised to `88/90`; owner/emitter unchanged. Updated status, class shape, method table, evidence notes, score rationale, remaining confidence caps, and change log. The page now records `OnCommand(int commandId, int unusedNotifyCode)`, raw `retn 8` callback ABI, `this+0x1fc` control host, `this+0x270` session pointer, control ids `1`/`2`/`3`, `g_useEpfAssets`, `g_packetSender`, `g_pUserPane`, `DialogSession::CloseAllDialogs`, `CreateScreenDimmer`, packet helper/ListPane names, selected-board packet constants, generated-alias rejections, and that method-body C++ now lives on [UID:0002EJ].
- [x] Lease and update `by-file/BoardDialogs.md`: record [UID:0002EJ] as first-draft C++ ready inside the BoardDialogs source-family while keeping exact ownership on BoardListDialog.
  - Proof: B004 lease acquired, then `BoardListDialog` proposed-content row, IDA/MCP evidence, score rationale, and change log updated. The page now records [UID:0002EJ] as first-draft C++ ready and [UID:00000Z] BoardListDialog-owned inside this BoardDialogs source-family; the by-file score remains `86/87` because broader file partitioning is still the cap.
- [x] Lease and update `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`: child row and parent note for [UID:0002EJ] score/evidence/C++ readiness.
  - Proof: B004 lease acquired, then exact child inventory row updated to [UID:0002EJ] `88/90`; function/helper map now notes first-draft C++ for constructor, `OnCommand`, `OpenSelectedBoard`, and `UpdateButtonState`; IDA MCP evidence and change log now record session `80de0a67`, boundaries, padding, xrefs, normalized names, selected-board packet, and non-emitting aggregate status unchanged.
- [x] Check `by-class/BoardListPane.md` and `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`; update only if they lack the `BoardListDialog::OpenSelectedBoard` activation relationship at same-or-greater detail, otherwise record already-present proof.
  - Proof: no edit needed. `by-class/BoardListPane.md` already states the owned relationship and method note that `OnItemDoubleClick` / activation virtual `0x00472b50-0x00472b63` climbs owner/container links and tail-jumps to `BoardListDialog::OpenSelectedBoard` at `0x004728a0`. `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md` already states `0x00472b50` is the activation/double-click virtual, vtable slot `0x00613d64`, with two owner/container virtual `+0x1c` lookups and tail jump to [UID:0002EJ]'s selected-board opener at `0x004728a0`.
- [x] Leave the exact [UID:0002EJ] coverage replacement row for supervisor-owned application; do not edit `-coverage-report.md`.
  - Proof: no `-coverage-report.md` file was edited. Exact replacement row remains in this report's `Exact Supervisor-Owned Coverage Text` section for supervisor application.
- [x] Run scoped validator for every changed by-* doc and record command, exit code, and `ok` count.
  - Proof: from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - `python .\tools\validator.py --mode file --file by-memory\0x00472070-0x004729dd.BoardListDialogCore.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects included completion/confidence updates, autogen registry update for [UID:0002EJ], reference-index adds, `project-level/-auto-completion-stats.md` projected stats update/stats row removal, validator-owned `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` update, and validator backup `tools/validator_autogen_backup/20260623-163302`.
    - `python .\tools\validator.py --mode file --file by-class\BoardListDialog.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects included completion/confidence updates for [UID:00000Z], stats row removals/projected stats update, validator-owned `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` update, and backup `tools/validator_autogen_backup/20260623-163330`.
    - `python .\tools\validator.py --mode file --file by-file\BoardDialogs.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects included one UID link insertion for [UID:0002EJ] and projected stats update; autogen output was otherwise unchanged.
    - `python .\tools\validator.py --mode file --file by-memory\0x00472070-0x00477790.BoardArticleDialogs.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects included two UID link insertions for [UID:0002EJ] and projected stats update; autogen output was otherwise unchanged.
- [x] Release all leases immediately after the edit/validator batch and record lease status in the implementation callback response.
  - Proof: `python leaser.py B004 unlease` released `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md`, `by-class/BoardListDialog.md`, `by-file/BoardDialogs.md`, and `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`; `current_leases.md` then reported `No active leases.`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002EJ-BoardListDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002EJ"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002EJ-BoardListDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002EJ-BoardListDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002EJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
