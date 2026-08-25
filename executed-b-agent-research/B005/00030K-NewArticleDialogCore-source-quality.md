** TARGET-REPORT-UID:00030K **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00030K NewArticleDialogCore Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00030K] as reconstructable source-authored `NewArticleDialog` code owned and emitted through [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).
- Recommended metadata: raise the target from `COMPLETION:85`, `CONFIDENCE:87` to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00008Y`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00008Y`.
- Recommended source route: direct class owner [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md), current file route [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) to `NexusTK/ui/dialogs/BoardDialogs.cpp` unless a later source-file split moves all article-compose dialogs together.
- Formal C++ is now eligible for a first draft under the current combined score and emitter route. The old blockers for post-packet/body-control fields are mostly closed; the remaining cap is exact original field/header names and retained-helper emission policy for raw/no-xref helpers.
- The current target row's `0x004772e0` and `0x00477450` roles are stale. `0x004772e0` is a one-call DialogPane hover-control forwarder. `0x00477450` is a retained shifted transfer-reply payload helper, parallel to the documented NewPredefinedFormArticleDialog `0x00478aa0` helper.
- No by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited in this report-only pass.

## Target

- Assignment id: `B005-goal2-new-article-dialog-core-source-quality-00030K-20260619`
- Target UID: [UID:00030K]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00476c10-0x00477790.NewArticleDialogCore.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00030K-NewArticleDialogCore-source-quality.md`
- Current target state: `85/87`, `CANONICAL_OWNER:00008Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008Y`, blank formal C++.
- Current target disposition: reconstructable NexusTK project code, exact new-article compose dialog cluster.

## Evidence Checked

- Required instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/goal.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/notes.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Target and direct owner docs:
  - `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`
  - `by-class/NewArticleDialog.md`
  - `by-file/BoardDialogs.md`
  - `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
- Source-route and caller docs:
  - `by-class/BulletinSession.md`
  - `by-file/BulletinSession.md`
  - `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
  - `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
  - `by-class/DialogSession.md`
  - `by-class/DialogInSession.md`
- Packet/text/global support docs:
  - `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `by-global/g_packetSender.md`
  - `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`
  - `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`
  - `by-global/SanitizeWideTextForChat.md`
  - `by-global/g_pTextFilter.md`
  - `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
  - `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
  - `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
  - `by-global/CreateScreenDimmer_4A12B0.md`
  - `by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md`
- Alert and analog docs:
  - `by-class/TransferReplyAlert.md`
  - `by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md`
  - `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - `by-class/NewPredefinedFormArticleDialog.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0002UR-NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
- Current generated/report state:
  - `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
- Local exported function data:
  - `resources/exported_data/functions/0x004712f0.json`
  - `resources/exported_data/functions/0x004751c0.json`
  - `resources/exported_data/functions/0x00476c10.json`
  - `resources/exported_data/functions/0x004771b0.json`
  - `resources/exported_data/functions/0x00477220.json`
  - `resources/exported_data/functions/0x004772e0.json`
  - `resources/exported_data/functions/0x004772f0.json`
  - `resources/exported_data/functions/0x00477450.json`
  - `resources/exported_data/functions/0x00477590.json`
  - `resources/exported_data/functions/0x00478940.json`
  - `resources/exported_data/functions/0x00478be0.json`
- Current live IDA MCP availability: attempted `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp`; the session returned `Unable to connect to the remote server`. This report therefore distinguishes current local export/doc facts from older live-IDA facts already recorded in by-* and prior B-agent docs.

## Exact Boundary And Inventory

The exact half-open range remains `0x00476c10-0x00477790`. The predecessor gap before `0x00476c10` and the successor `0x00477790-0x004777a0` padding are already documented by the parent BoardArticleDialogs page and NewPredefinedFormArticleDialog successor.

| Range | Current modeled status | Recommended source-facing role | Current conclusion |
| --- | --- | --- | --- |
| `0x00476c10-0x00477151` | modeled constructor, export size `0x541` | `NewArticleDialog::NewArticleDialog(BulletinSession *session, const wchar_t *title, const Rect &bounds)` | Source-authored constructor/setup. Creates EPF/EPD compose layout, subject/body controls, send/cancel controls, background, vtables, and DialogInSession base state. |
| `0x00477160-0x004771a8` | raw bytes, no exported function object found | `NewArticleDialog::NavigateToPreviousArticleSelection` / `SendPreviousDialogSelectionNavigationRequest` | Source-shaped retained raw helper; no direct entry xrefs currently documented. It calls the shared article navigation helper at `0x004751c0`. Keep under this class, but final C++ visibility remains policy-bound. |
| `0x004771b0-0x00477212` | modeled function, export size `0x62` | `NewArticleDialog::OnCommand(int commandId)` or `HandleButtonClick` | Source-authored command handler. Command `1` submits; command `2` pops/cancels through the session. |
| `0x00477220-0x004772d3` | modeled function, export size `0xb3` | `NewArticleDialog::HandlePostError(int resultCode)` / `OnPostFailed` | Source-authored transfer/post error alert path. Builds `TransferReplyAlert` with mode flag `0`. |
| `0x004772e0-0x004772e9` | modeled one-call function, export size `0x9` | `NewArticleDialog::SetHoverControl(int controlId)` | Current target's "tiny state/count setter" wording is wrong. Export body is only `DialogPane::virt_meth_0x49fc00((DialogPane*)this, param_1)`, matching the NewPredefined `SetHoverControl` sibling. |
| `0x004772f0-0x00477443` | modeled function, export size `0x153` | `NewArticleDialog::HandleTransferReplyPacket(const unsigned char *packet)` | Live/vtable-backed transfer reply handler. Checks packet subcommand byte `packet[1] == 0x06`, then opens `TransferReplyAlert` with packet mode/message. |
| `0x00477450-0x00477589` | modeled function, export size `0x139`, no callers in export | `NewArticleDialog::HandleTransferReplyPayload(const unsigned char *payload)` / retained shifted helper | Current target's "body/control helper" wording is wrong. This is the shifted payload layout version of `0x004772f0`, parallel to NewPredefined `0x00478aa0`. |
| `0x00477590-0x00477790` | modeled function, export size `0x200` | `NewArticleDialog::SubmitArticle(short boardId)` / `SendPostArticlePacket` | Source-authored packet serializer. Reads subject/body controls, validates/sanitizes text, sends opcode `0x3b`, subcommand `4`, board/context id, subject length/text, body length/text, then starts a 15000 ms wait/timeout. |

## Caller, Reachability, And Route Evidence

- Constructor route: `resources/exported_data/functions/0x004712f0.json` shows `BulletinSession::meth_0x4712f0` constructing `NewArticleDialog(this, title, rect)` and pushing the result to the dialog session. The export lists callers at `0x00474020` and `0x00476740`.
- Target constructor caller: the target page records live IDA caller `0x00471371` inside the BulletinSession new-article opening path. The local `0x004712f0` export is the containing modeled function.
- Submit route: `0x004771b0` calls `0x00477590`. The target page records the callsite as `0x004771ee`.
- `0x00477590` has one exported caller, `0x004771b0`; this is expected because only the send/OK command path submits a normal new article.
- `0x004772f0` is not expected to have ordinary callers. Prior B001 reachability work on the NewPredefined retained helper records the earlier NewArticle pair as `0x004772f0` vtable-backed at slot `0x0061400c` and `0x00477450` as the unreferenced shifted helper with no pointer hits.
- `0x00477450` has no exported callers. Prior B001 analog work states the same function had no raw VA/RVA pointer hits when compared with live sibling slots. That negative result is meaningful because live siblings in the same neighborhood do have vtable slots.
- `0x00477160` has no modeled export and the target page records no direct xrefs to the raw start. The role is still source-shaped: the ArticleNavigationHelpers page documents a call edge from `0x004771a2` to `0x004751c0`, the shared article navigation request helper.
- `0x004772e0` has no normal caller evidence in current exports, but its body is a virtual/interface forwarder and its NewPredefined sibling is documented as `SetHoverControl`; no direct caller is required for a vtable/interface method.
- Owner route remains direct class [UID:00008Y][NewArticleDialog]. Dependencies such as `DialogSession`, `TransferReplyAlert`, `PacketBuffer`, `Socket`, and `TextFilter` are callees or constructed/consumed objects, not owners.

## Function-Level Evidence

### Constructor `0x00476c10`

Exported signature:

```cpp
NewArticleDialog *__thiscall NewArticleDialog(
    NewArticleDialog *this,
    undefined4 session,
    short *title,
    int *bounds);
```

Source-facing signature should normalize to:

```cpp
NewArticleDialog::NewArticleDialog(BulletinSession *session,
                                   const wchar_t *title,
                                   const Rect &bounds);
```

Key body facts:

- Calls `DialogInSession(this, session, 2, 4)`. DialogInSession docs establish the pattern as `(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)`.
- Stores NewArticleDialog vtables at `0x00613fb0`, `0x00614014`, and `0x00614044`.
- Branches on `byte_66DA97`, best existing name `g_useEpfAssets`.
- EPF layout branch:
  - Creates an `EPFImageControlPane` resource id `0x14c`, image `"DLGBBS04.EPF"`, palette `"DLGBBS04.PAL"`, using a rectangle derived from the supplied bounds.
  - Creates send/OK button id `0x17` at `(0x90,0x17d)-(0xcf,0x195)`.
  - Creates cancel/back button id `0x16` at `(0xe7,0x17d)-(0x126,0x195)`.
  - Creates title/static text at `(0x5e,0x3a)-(0x196,0x46)` from the `title` argument.
  - Creates subject edit at `(0x5e,0x55)-(0x196,0x61)`.
  - Creates body edit at `(0x19,0x70)-(0x1ae,0x164)`, sets the body byte at `+0x100` to `1`, applies max/limit calls with `0x400` and `4000`, and loads background `"DLGBBS04.EPF"`.
- Legacy EPD layout branch:
  - Loads background `"DLGBBS04.EPD"` and palette `"NPAL8.PAL"`.
  - Creates send/OK button id `0x17` at `(0x95,0x13c)-(0xdd,0x14c)`.
  - Creates cancel/back button id `0x16` at `(0xe2,0x13c)-(0x12a,0x14c)`.
  - Creates title/static text at `(0x83,0x36)-(0x19a,0x42)`.
  - Creates subject edit at `(0x83,0x48)-(0x19a,0x55)`.
  - Creates body edit at `(0x24,0x5b)-(0x19a,0x127)` with the same body limit calls.
- Decompiler labels such as `MiniMapDialog::meth_0x49dc10` are inherited DialogPane helper pollution. Source-facing use should be `DialogPane::AddControl` or the local project's established equivalent.

### Raw navigation helper `0x00477160`

No modeled export exists for this raw start in current exported data. Current target/support docs record:

- raw executable bytes at `0x00477160-0x004771a8`;
- no direct `xrefs_to 0x00477160`;
- a call at `0x004771a2` to shared `0x004751c0`;
- same selected-control/navigation shape used by article navigation and transfer-reply helpers.

Best source-facing name: `NewArticleDialog::NavigateToPreviousArticleSelection` or `SendPreviousDialogSelectionNavigationRequest`.

Best inference: source-shaped retained class helper that asks the dialog session for the previous dialog, extracts its selected article id/control value, and sends a shared article navigation request through `0x004751c0`. It should remain owned by `NewArticleDialog`, but a formal body should either be added with a clear retained-helper note or split to a focused raw child before exact implementation.

### Command handler `0x004771b0`

Exported signature:

```cpp
void __thiscall NewArticleDialog::virt_meth_0x4771b0(NewArticleDialog *this, int commandId);
```

Body facts:

- If `commandId == 1`, loads the dialog/session pointer from the DialogInSession tail field. If present, reads a 16-bit value from session `+0x102`; if absent, uses `0`.
- Calls `0x00477590` with that 16-bit value. Best local name for the value is `boardId` or `boardContextId`; the exact `BulletinSession` field name remains inferred.
- If `g_pCollectionData` / `DAT_0067a748` is non-null, writes `this` at offset `+0x214`. CreateScreenDimmer docs show `0x004a12b0` is the following screen dimmer factory. Best field name is still inferred, such as `m_activeDialogHostPane` or `m_modalDialogPane`.
- Calls `CreateScreenDimmer()` at `0x004a12b0`.
- If `commandId == 2`, and the session pointer is non-null, calls `DialogSession::PopCurrentDialog(false)` at `0x004a10e0`.

Best source-facing name: `NewArticleDialog::OnCommand(int commandId)` or `HandleButtonClick`. Because constructor button resource ids are `0x17` and `0x16`, but this handler receives normalized command ids `1` and `2`, `OnCommand` is safer than naming the parameter `buttonResourceId`.

### Post error handler `0x00477220`

Exported signature:

```cpp
unsigned int __thiscall NewArticleDialog::virt_meth_0x477220(NewArticleDialog *this, int resultCode);
```

Body facts:

- If `resultCode == 0`, checks `0x004a1380` and calls `0x004a1360` when the shared screen/resource state is active.
- Allocates an `AlertPane`/`TransferReplyAlert` object of size `0x274`.
- Constructs the alert with the wide literal `L"Your post didn't go through due to an error."`.
- Installs `TransferReplyAlert` vtables `0x006140f0`, `0x00614158`, and `0x00614188`.
- Stores `0` at alert offset `+0x270`.
- Returns `1` for the handled error branch.

Best source-facing name: `NewArticleDialog::HandlePostError(int resultCode)` or `OnPostFailed`.

### Hover-control forwarder `0x004772e0`

Exported body:

```cpp
void __thiscall NewArticleDialog::virt_meth_0x4772e0(NewArticleDialog *this, int controlId)
{
    DialogPane::virt_meth_0x49fc00((DialogPane *)this, controlId);
}
```

This closes the target's stale open question. It is not a count/state setter. It is the NewArticle sibling of documented [UID:0002UN] `NewPredefinedFormArticleDialogSetHoverControl`.

Best source-facing name: `NewArticleDialog::SetHoverControl(int controlId)`.

### Live transfer reply handler `0x004772f0`

Exported signature:

```cpp
int __thiscall NewArticleDialog::virt_meth_0x4772f0(NewArticleDialog *this, int packet);
```

Body facts:

- Reads byte `packet[1]` and handles the packet only when it equals `0x06`.
- Calls `GetMemoryMan()` and releases the shared screen/resource state if `0x004a1380` says it is active.
- Reads reply mode from `packet[2]`.
- Reads message length from `packet[3]`.
- Copies `messageLength` bytes from `packet + 4`, NUL terminates the local byte buffer, and converts to wide text using `MultiByteToWideChar`.
- Allocates and constructs `TransferReplyAlert`.
- Installs the same `TransferReplyAlert` vtables as the error path and stores the reply mode byte at alert `+0x270`.
- Returns `1` on the handled path.

Best source-facing name: `NewArticleDialog::HandleTransferReplyPacket(const unsigned char *packet)`.

The packet layout for this live handler is:

| Packet offset | Meaning |
| ---: | --- |
| `+0` | outer opcode or packet-local byte, not consumed here |
| `+1` | subcommand, must be `0x06` |
| `+2` | reply/alert mode flag stored to `TransferReplyAlert +0x270` |
| `+3` | byte length of message text |
| `+4` | ANSI/DBCS message bytes converted to UTF-16 |

### Shifted transfer reply payload helper `0x00477450`

Exported signature:

```cpp
unsigned int __thiscall FUN_00477450(void *this, unsigned char *payload);
```

Body facts:

- No callers are listed in the local export.
- Unlike `0x004772f0`, it does not check `payload[1] == 0x06`.
- Reads reply mode from `payload[0]`.
- Reads message length from `payload[1]`.
- Copies bytes from `payload + 2`, converts to wide text, releases the dimmer/resource state, allocates `TransferReplyAlert`, installs alert vtables, and stores the reply mode byte at alert `+0x270`.

Best source-facing name: `NewArticleDialog::HandleTransferReplyPayload(const unsigned char *payload)`.

This is not a body/control helper. The best analogy is the B001-analyzed NewPredefined pair:

- live handler `0x00478940`: checks packet subcommand `0x06`, reads mode at `packet + 2`, length at `packet + 3`, and bytes at `packet + 4`;
- retained helper `0x00478aa0`: starts directly at mode byte, reads length at `payload + 1`, and bytes at `payload + 2`;
- earlier NewArticle pair named in that report: `0x004772f0` has vtable slot `0x0061400c`, while `0x00477450` has no pointer hits.

Conclusion: keep `0x00477450` class-owned and reconstructable, but do not treat it as proof of additional body-control state. It is a retained alternate packet-layout helper. Emitting it as a private helper is reasonable only if the implementation pass decides retained unreferenced helpers are included in source output for this aggregate.

### Submit/send packet body `0x00477590`

Exported signature:

```cpp
void __thiscall NewArticleDialog::meth_0x477590(NewArticleDialog *this, short boardId);
```

Body facts:

- Retrieves control index `4` from the DialogPane control list and reads up to `0xff` UTF-16 characters into the subject buffer.
- Retrieves control index `5` from the DialogPane control list and reads up to `0xfff` UTF-16 characters into the body buffer.
- Calls `ValidateChatInputOrThrowPasswordError` on subject and body.
- Calls `SanitizeWideTextForChat` on subject and body with their measured lengths; support docs place the text-filter global at `0x0067adc8` as `g_pTextFilter`.
- Builds a packet:
  - byte `0`: opcode `0x3b`;
  - byte `1`: subcommand `0x04`;
  - bytes `2..3`: big-endian `boardId` / board context id;
  - byte `4`: subject byte length;
  - bytes after `5`: subject multibyte text;
  - next two bytes: big-endian body byte length;
  - following bytes: body multibyte text.
- Calls `QueueAndSendPacket(g_packetSender, packet, packetLength)`.
- Calls timer/wait helper `0x005975e0` through the local dialog/timer subobject with a `15000` millisecond timeout. Exact source name remains unresolved; use a descriptive `StartTransferTimeout(15000)` until the timer helper is named.
- The local trailing zero written after the packet body is scratch termination outside the counted protocol payload, not a third serialized length field.

Best source-facing name: `NewArticleDialog::SubmitArticle(short boardId)` or `SendPostArticlePacket`. The class docs can use `SubmitArticle`; the memory page can preserve "send post article packet" in prose.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

Best conclusion: [UID:00030K] is source-authored application code and should not remain blank/no-code.

Evidence:

- The target contains a complete constructor, command handler, alert/error handling, transfer reply handlers, packet serializer, and one inherited forwarder. These are normal dialog source methods, not alignment, vtable-only data, or pure compiler thunks.
- The constructor is directly reached from `BulletinSession::OpenNewArticleDialog`.
- The submit body is directly reached from the command handler and sends a documented application packet opcode.
- The live transfer handler has vtable-backed reachability by prior B-agent comparison.
- The two no-direct-xref children are source-shaped retained helpers, not compiler glue. One is a raw navigation helper calling a shared article navigation helper; the other is a shifted transfer-reply helper with a close NewPredefined analog.
- The class/file owner chain is already over the code-entry gate and the current autogen report routes this target through [UID:00008Y] to `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`.

Rejected no-code alternatives:

- Compiler-generated thunk: rejected for all substantial children; only `0x004772e0` is a thin source-visible virtual/interface forwarder, not a generated adjustor thunk.
- Runtime/library code: rejected because packet opcode `0x3b`, dialog resources, vtables, and UI controls are NexusTK application behavior.
- Alert class ownership: rejected because `NewArticleDialog` constructs `TransferReplyAlert`; the alert class owns its own confirm/action method, not this dialog's packet and command handlers.
- Socket/PacketBuffer ownership: rejected because those helpers are serialization dependencies. `NewArticleDialog` owns packet content and timing flow.
- Padding/dead bytes: rejected because modeled functions and raw helper bodies have application-level control flow and callees. No-code proof is therefore not applicable; first-draft C++ is the correct action.

### Name And Signature Recommendations

| Address / item | Best source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x00476c10` | `NewArticleDialog::NewArticleDialog(BulletinSession *session, const wchar_t *title, const Rect &bounds)` | high role, medium exact parameter types | `BulletinSession *` is the concrete caller type; `DialogSession *` is the base constructor type. |
| `0x00477160` | `NewArticleDialog::NavigateToPreviousArticleSelection` | medium | Raw retained helper; exact source visibility and final name need a focused raw child or implementation policy. |
| `0x004771b0` | `NewArticleDialog::OnCommand(int commandId)` | high | `HandleButtonClick` is also acceptable, but `commandId` avoids confusing normalized ids `1/2` with resource ids `0x17/0x16`. |
| `0x00477220` | `NewArticleDialog::HandlePostError(int resultCode)` | high | `OnPostFailed` is a source-style alias; behavior is the failure alert path. |
| `0x004772e0` | `NewArticleDialog::SetHoverControl(int controlId)` | very high | Export body and NewPredefined sibling resolve the old stale wording. |
| `0x004772f0` | `NewArticleDialog::HandleTransferReplyPacket(const unsigned char *packet)` | high | Live handler checks packet subcommand `0x06`. |
| `0x00477450` | `NewArticleDialog::HandleTransferReplyPayload(const unsigned char *payload)` | high role, medium emission policy | Shifted-layout retained helper, not a body/control helper. |
| `0x00477590` | `NewArticleDialog::SubmitArticle(short boardId)` | high | `SendPostArticlePacket` remains useful in prose because the exact packet content is important. |
| `0x004751c0` | `SendArticleNavigationRequest(short boardId, short articleId, unsigned char mode)` | high behavior, medium original name | Shared helper sends opcode `0x3b`, subcommand `2`. |
| `0x004a12b0` | `CreateScreenDimmer()` | high | Existing global page supports this name. |
| `0x004a10e0` | `DialogSession::PopCurrentDialog(bool animateOrUnknown)` | high role, medium argument name | Command `2` passes `false`. |
| `0x00574bb0` | `QueueAndSendPacket(Socket *socket, const void *packet, short length)` | high | Existing Socket support page. |
| `0x00575380` | `PacketBufferWriteUInt8` | high | Existing packet helper page. |
| `0x005753a0` | `PacketBufferWriteUInt16BE` | high | Existing packet helper page. |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError` | high | For source readability inside article code, `ValidateOutboundTextOrThrowPasswordError` may be a local wrapper alias, but the documented helper name should stay. |
| `0x005957c0` | `SanitizeWideTextForChat` | high | Existing sanitizer/global docs. |
| `0x005975e0` | `StartTransferTimeout` / timer schedule helper | medium | Exact timer owner/name remains unresolved; do not freeze a final method name from this target alone. |

### Field, Type, And Global Recommendations

Best-supported fields/globals:

| Item | Recommended source-facing name | Confidence | Evidence / caveat |
| --- | --- | --- | --- |
| `byte_66DA97` | `g_useEpfAssets` | high | Existing docs and layout branch behavior. |
| `dword_67A7EC` | `g_packetSender` / `Socket *g_packetSender` | high | Existing Socket send helper and global page. |
| `0x0067adc8` | `g_pTextFilter` | high | Existing TextFilter singleton slot and sanitizer docs. |
| `DAT_0067a748 + 0x214` | active/modal dialog host pane field | medium | Command handler writes current dialog before `CreateScreenDimmer`; exact owner field name still inferred. |
| DialogInSession tail `+0x270` | `m_session` or `m_dialogSession` | high | DialogInSession docs and command handler session use. |
| DialogInSession tail `+0x26c` | `m_dialogType` | high | Constructor passes/stores dialog type `4`. |
| `BulletinSession +0x102` | `m_currentBoardId` / `m_boardContextId` | medium-high | Command handler sends this 16-bit field as packet word; exact original member name still not proven. |
| DialogPane `+0x1fc` | child/control list | high behavior, medium exact type | Submit body indexes controls `4` and `5`. |
| Control index `4` | subject edit control | high | Submit body reads this control with max `0xff`; constructor creates the subject TextEdit before body. |
| Control index `5` | body edit control | high | Submit body reads this control with max `0xfff`; constructor applies multiline/body limits. |
| Alert `+0x270` | `m_popAfterConfirm` / reply mode flag | medium-high | TransferReplyAlert docs say constructor stores optional pop flag; handlers store server reply mode. Exact field name should be unified in alert class pass. |
| `off_613A18` / `DAT_00613a18` | alert pane button/layout resource | medium | Used by alert construction; exact source name unresolved. |
| `DAT_0060db20` | empty wide string literal | medium-high | Constructor passes it for empty edit initial text. |

Type recommendations:

- Use a real source `Rect`/`Bounds` type for the constructor `bounds` parameter and layout helpers. The export passes an `int *`, but caller `0x004712f0` builds a rectangle object.
- Use `BulletinSession *` in the concrete constructor signature and allow implicit/base conversion to `DialogInSession`.
- Use `TextEditControlPane *` or the project's exact control wrapper type for subject/body controls. The decompiler's `RadioGroupControlPane` label at `0x00498c10` is owner pollution; the constructor creates TextEdit controls.
- Use `TransferReplyAlert *` for the alert object allocated by post error and reply handlers.
- Use `const unsigned char *` or `std::uint8_t const *` for packet/payload handlers until a project packet-view type is established.

### Compiler-Generated And Decompiler Placeholder Cleanup

Names and labels that should not survive into source-quality C++:

- `sub_477590`, `virt_meth_0x4772f0`, `FUN_00477450`, and similar generated labels: replace with source-facing names above.
- `MiniMapDialog::meth_0x49dc10` and `MiniMapDialog::meth_0x49db60`: inherited DialogPane helper pollution; use `DialogPane::AddControl` / background-loading equivalents.
- `RadioGroupControlPane::meth_0x498c10`: stale owner label for TextEdit `GetText` behavior in submit body.
- `CashShopRequest` labels around `QueueAndSendPacket`: stale generated owner pollution; support docs place the send helper on Socket.
- `FUN_00575470`: decompiler/runtime char-traits byte conversion helper. In source, express it as `packet[offset]` byte reads.
- `GetMemoryMan()` calls around alert allocation are allocator infrastructure; do not make them visible source semantics unless the local memory manager wrapper requires it.
- Security-cookie frames, SEH scaffolding, range-check failure helpers, and stack probes should not be hand-authored in reconstruction.

### Source Placement

Best placement remains the current owner chain:

- Direct class: [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).
- Current source/file bucket: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Generated output path: `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`.

Reasoning:

- Constructor caller is `BulletinSession::OpenNewArticleDialog`.
- The class page already lists this exact child and the vtable family records NewArticleDialog vtables at `0x00613fb0`, `0x00614014`, and `0x00614044`.
- The normal NewArticleDialog cluster belongs with board/article dialog UI code. NewPredefinedFormArticleDialog remains adjacent but separate.
- Dependencies do not imply ownership: `TransferReplyAlert` is constructed by the dialog; PacketBuffer/Socket/TextFilter/DialogSession are support modules.

Open placement caveat:

- The current by-file page is a bucket for board/article dialog code. A later split to `ArticleDialogs.cpp` or a dedicated new-article source file is plausible, but this target should not create that split by itself. Keep [UID:0000HT] as the implementation route until a file-level source-split assignment says otherwise.

### Open-Question Closure

Closed by this pass:

- `0x004772e0` is not a compact state/count setter. It is `SetHoverControl`.
- `0x00477450` is not a body/control helper. It is a shifted transfer-reply payload helper.
- The post packet format is now source-quality enough: opcode `0x3b`, subcommand `4`, 16-bit board/context id, 8-bit subject length, subject bytes, 16-bit body length, body bytes.
- Subject/body control roles are now source-quality enough: control index `4` is subject, control index `5` is body, and both go through validation and sanitizer before packet conversion.
- The post error/reply alert object is `TransferReplyAlert`, with mode/pop flag stored at `+0x270`.

Still open and score-capping:

- Exact original names for `BulletinSession +0x102`, `DAT_0067a748 + 0x214`, the DialogPane control-list type, and `0x005975e0` timer/wait helper.
- Exact source visibility for raw `0x00477160` and no-xref `0x00477450`. Both are source-shaped and class-owned, but retained-helper emission policy is a project-level choice.
- Exact final file split among `BoardDialogs.cpp`, `ArticleDialogs.cpp`, and dedicated compose-dialog files.
- Final UI helper names for background loading, control insertion, and TextEdit limit setters.

These remaining questions justify `88/90`, not a no-code block. They do not justify leaving the entire target blank.

## First-Draft C++ Eligibility And Candidate

The target is eligible for first-draft C++ because:

- current average score is already `86.0` and recommended score is `89.0`;
- `RECONSTRUCTABLE:TRUE`;
- `EMITTER_UIDS:00008Y` and generated route are present;
- body-control and packet-field blockers have been reanalyzed;
- no-code alternatives are rejected.

The following is a source-facing first draft for implementation review, not a claim that every helper/type name is final. It intentionally uses descriptive local names for unresolved project helpers and keeps retained-helper policy explicit.

```cpp
namespace {
constexpr int kNewArticleCommandSubmit = 1;
constexpr int kNewArticleCommandCancel = 2;
constexpr unsigned char kBoardPacketOpcode = 0x3b;
constexpr unsigned char kArticleNavigateSubcommand = 0x02;
constexpr unsigned char kArticleSubmitSubcommand = 0x04;
constexpr unsigned char kTransferReplySubcommand = 0x06;
constexpr int kSubjectControlIndex = 4;
constexpr int kBodyControlIndex = 5;
constexpr int kSubmitTimeoutMs = 15000;

std::wstring DecodeReplyMessage(const unsigned char *text, unsigned int length)
{
    char scratch[0x100] = {};
    const unsigned int copyLength = std::min<unsigned int>(length, sizeof(scratch) - 1);
    std::memmove(scratch, text, copyLength);

    wchar_t wide[0x100] = {};
    MultiByteToWideChar(CP_ACP, 0, scratch, -1, wide, static_cast<int>(std::size(wide)));
    return wide;
}
} // namespace

NewArticleDialog::NewArticleDialog(BulletinSession *session,
                                   const wchar_t *title,
                                   const Rect &bounds)
    : DialogInSession(session, 2, 4)
{
    SetBounds(bounds);

    if (g_useEpfAssets == 1) {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, bounds.Width(), bounds.Height()),
                                           0x14c,
                                           L"DLGBBS04.EPF",
                                           L"DLGBBS04.PAL"));
        AddControl(new ImageButtonControlPane(MakeRect(0x90, 0x17d, 0xcf, 0x195), 0x17));
        AddControl(new ImageButtonControlPane(MakeRect(0xe7, 0x17d, 0x126, 0x195), 0x16));
        AddControl(new StaticTextControlPane(MakeRect(0x5e, 0x3a, 0x196, 0x46), title));
        AddControl(new TextEditControlPane(MakeRect(0x5e, 0x55, 0x196, 0x61), L""));

        TextEditControlPane *body =
            new TextEditControlPane(MakeRect(0x19, 0x70, 0x1ae, 0x164), L"");
        body->SetMultiline(true);
        body->SetMaxLength(0x400);
        body->SetTextLimit(4000);
        AddControl(body);
        LoadDialogBackground(L"DLGBBS04.EPF");
    } else {
        AddControl(new ImageControlPane(MakeRect(0, 0, bounds.Width(), bounds.Height()),
                                        L"DLGBBS04.EPD",
                                        L"NPAL8.PAL"));
        AddControl(new ImageButtonControlPane(MakeRect(0x95, 0x13c, 0xdd, 0x14c), 0x17));
        AddControl(new ImageButtonControlPane(MakeRect(0xe2, 0x13c, 0x12a, 0x14c), 0x16));
        AddControl(new StaticTextControlPane(MakeRect(0x83, 0x36, 0x19a, 0x42), title));
        AddControl(new TextEditControlPane(MakeRect(0x83, 0x48, 0x19a, 0x55), L""));

        TextEditControlPane *body =
            new TextEditControlPane(MakeRect(0x24, 0x5b, 0x19a, 0x127), L"");
        body->SetMultiline(true);
        body->SetMaxLength(0x400);
        body->SetTextLimit(4000);
        AddControl(body);
        LoadDialogBackground(L"DLGBBS04.EPD");
    }

    SetDialogMode(2);
    SetHoverControl(4);
}

void NewArticleDialog::NavigateToPreviousArticleSelection()
{
    ArticleDialog *previous = FindPreviousArticleDialog();
    if (previous == nullptr) {
        return;
    }

    const short boardId = GetSession() != nullptr ? GetSession()->m_currentBoardId : 0;
    const short articleId = previous->GetSelectedArticleId();
    const unsigned char mode = g_useEpfAssets == 1 ? previous->GetEpfNavigationMode()
                                                   : previous->GetLegacyNavigationMode();
    SendArticleNavigationRequest(boardId, articleId, mode);
}

void NewArticleDialog::OnCommand(int commandId)
{
    BulletinSession *session = GetSession();

    if (commandId == kNewArticleCommandSubmit) {
        const short boardId = session != nullptr ? session->m_currentBoardId : 0;
        SubmitArticle(boardId);

        if (g_pCollectionData != nullptr) {
            g_pCollectionData->m_activeDialogHostPane = this;
        }
        CreateScreenDimmer();
        return;
    }

    if (commandId == kNewArticleCommandCancel && session != nullptr) {
        session->PopCurrentDialog(false);
    }
}

bool NewArticleDialog::HandlePostError(int resultCode)
{
    if (resultCode != 0) {
        return false;
    }

    if (IsScreenDimmerActive()) {
        ReleaseScreenDimmer();
    }

    new TransferReplyAlert(this,
                           L"Your post didn't go through due to an error.",
                           0);
    return true;
}

void NewArticleDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

bool NewArticleDialog::HandleTransferReplyPacket(const unsigned char *packet)
{
    if (packet[1] != kTransferReplySubcommand) {
        return false;
    }

    return HandleTransferReplyPayload(packet + 2);
}

bool NewArticleDialog::HandleTransferReplyPayload(const unsigned char *payload)
{
    if (IsScreenDimmerActive()) {
        ReleaseScreenDimmer();
    }

    const unsigned char replyMode = payload[0];
    const unsigned char messageLength = payload[1];
    const std::wstring message = DecodeReplyMessage(payload + 2, messageLength);

    new TransferReplyAlert(this, message.c_str(), replyMode);
    return true;
}

void NewArticleDialog::SubmitArticle(short boardId)
{
    wchar_t subjectWide[0x100] = {};
    wchar_t bodyWide[0x1000] = {};

    const unsigned int subjectChars =
        GetTextEditControl(kSubjectControlIndex)->GetText(subjectWide, 0xff);
    const unsigned int bodyChars =
        GetTextEditControl(kBodyControlIndex)->GetText(bodyWide, 0xfff);

    ValidateChatInputOrThrowPasswordError(subjectWide);
    ValidateChatInputOrThrowPasswordError(bodyWide);
    SanitizeWideTextForChat(subjectWide, subjectChars);
    SanitizeWideTextForChat(bodyWide, bodyChars);

    unsigned char packet[0x7fff] = {};
    packet[0] = kBoardPacketOpcode;
    packet[1] = kArticleSubmitSubcommand;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(boardId), packet + 2);

    char subjectBytes[0x100] = {};
    const int subjectByteLength =
        WideCharToMultiByte(CP_ACP, 0, subjectWide, -1, subjectBytes,
                            sizeof(subjectBytes), nullptr, nullptr) - 1;

    packet[4] = static_cast<unsigned char>(subjectByteLength);
    std::memmove(packet + 5, subjectBytes, subjectByteLength);

    char bodyBytes[0x1000] = {};
    const int bodyByteLength =
        WideCharToMultiByte(CP_ACP, 0, bodyWide, -1, bodyBytes,
                            sizeof(bodyBytes), nullptr, nullptr) - 1;

    unsigned char *bodyLengthField = packet + 5 + subjectByteLength;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(bodyByteLength), bodyLengthField);
    std::memmove(bodyLengthField + 2, bodyBytes, bodyByteLength);

    const short packetLength =
        static_cast<short>(subjectByteLength + bodyByteLength + 7);
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    StartTransferTimeout(kSubmitTimeoutMs);
}
```

Implementation notes for this draft:

- `NavigateToPreviousArticleSelection()` is semantically supported but should be tied to the raw helper `0x00477160` with a retained-helper note if inserted.
- `HandleTransferReplyPacket()` calling `HandleTransferReplyPayload()` is a source-facing cleanup of duplicate binary bodies. If the project prefers one function per binary body, duplicate the payload body in both functions instead of introducing a source call edge.
- `GetSession()`, `FindPreviousArticleDialog()`, `GetTextEditControl()`, `LoadDialogBackground()`, `StartTransferTimeout()`, and the exact `TransferReplyAlert` constructor spelling are placeholders for existing local helper APIs.
- The constructor's `SetDialogMode(2)` and `SetHoverControl(4)` names are inferred from helper roles; the raw calls are `0x0049ddd0(this, 2)` and `0x0049fc00(this, 4)`.
- The draft intentionally avoids decompiler labels and compiler-runtime scaffolding.

## Score Recommendation

Recommended score: `COMPLETION:88`, `CONFIDENCE:90`.

Rationale:

- Raise completion from `85` because the largest old blockers are resolved: packet fields, subject/body control roles, `0x004772e0` identity, and `0x00477450` identity.
- Raise confidence from `87` because local exports, support docs, and the NewPredefined analog converge on the same roles.
- Do not raise above `90` completion because exact field/header names and retained-helper emission policy remain open.
- Do not raise confidence above `90` because current live IDA MCP was unavailable for a fresh raw pointer scan in this session; this report relies on existing live-IDA docs plus local exported function data.

## Exact Supervisor-Owned Coverage Row Text

Replace the current [UID:00030K] row in `by-memory/-coverage-report.md` with this exact row when the implementation pass updates the target:

```text
      - [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) 0x00476c10-0x00477790 | class method cluster | NewArticleDialogCore : reconstructable : 88% : very-strong : Assigned to [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) after B005 source-quality reanalysis confirmed the constructor/control layout, command-to-submit route, opcode `0x3b` subcommand `4` post packet format, subject/body control indexes, text validation/sanitization flow, TransferReplyAlert error/reply handlers, corrected `SetHoverControl` identity for `0x004772e0`, and retained-helper treatment for raw `0x00477160` plus shifted no-xref `0x00477450`; first-draft C++ is recommended, with completion capped by retained-helper emission policy and exact source member/header names.
```

Current row observed before this report:

```text
      - [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) 0x00476c10-0x00477790 | class method cluster | NewArticleDialogCore : reconstructable : 85% : strong : Assigned to [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) after child `85/87`, direct class parent `85/86`, and file parent `85/86`; evidence is `BulletinSession` constructor caller `0x00471371`, command-to-send caller `0x004771ee`, primary vtable store `0x00476c56`, raw previous-dialog selected-article helper xref to shared navigation helper, and exact compose-dialog child split.
```

## Target / Support Implementation Checklist

Target page [UID:00030K]:

- Update header scores to `COMPLETION:88` and `CONFIDENCE:90`; keep owner/emitter/reconstructable metadata unchanged.
- Replace Status confidence wording so it no longer says post-packet/body-control names are unresolved as primary blockers.
- Update Covered Range table:
  - `0x004772e0-0x004772e9`: `SetHoverControl` / DialogPane hover-control forwarder.
  - `0x00477450-0x00477589`: retained shifted transfer-reply payload helper, no exported callers.
  - `0x00477590-0x00477790`: `SubmitArticle` / post packet serializer with subject/body controls.
- Add packet layout evidence for `SubmitArticle`: opcode `0x3b`, subcommand `4`, 16-bit board/context id, 8-bit subject length, subject bytes, 16-bit body length, body bytes.
- Add transfer reply layouts for `0x004772f0` and `0x00477450`.
- Add text validation/sanitizer dependencies: `ValidateChatInputOrThrowPasswordError`, `SanitizeWideTextForChat`, `g_pTextFilter`.
- Add first-draft C++ or a compact version of the candidate above to `RECONSTRUCTION_CPP` if the implementation assignment authorizes code insertion.
- Add a Changes entry for B005 2026-06-19 source-quality reanalysis.

Support docs:

- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md):
  - Update method table names for this child, especially `SetHoverControl`, `HandleTransferReplyPayload`, and `SubmitArticle`.
  - Recommended class score after support update: `87/89` or `88/89`, depending on whether class declaration C++ is also refreshed.
  - Keep [UID:00030K] as exact core child and direct owner.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md):
  - Update NewArticleDialog row/evidence to remove the old body-control blocker.
  - No score change is required solely from this target because broader file split remains unresolved; a small confidence bump is defensible if the file page is already being refreshed.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md):
  - Optional: add source-facing method names for the NewArticleDialog slots if the slot table already records the raw addresses.
- [UID:00030H][ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md):
  - Optional: cross-reference `0x00477160` as the NewArticleDialog retained previous-selection navigation helper.
- `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`:
  - Current generated output has an empty marker for NewArticleDialog. After target implementation and validator/autogen refresh, it should emit the new first-draft C++ through [UID:00008Y].
- Coverage/stats:
  - Apply the exact `by-memory/-coverage-report.md` replacement row above.
  - Let validator/autogen update `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md`; do not hand-edit generated reports unless the supervisor workflow explicitly requires it.

Suggested validation commands for the implementation pass:

> Executable block R001 was removed from this report and preserved verbatim in [00030K-NewArticleDialogCore-source-quality-removed.md](00030K-NewArticleDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If first-draft C++ is inserted, also run the normal autogen refresh/validation path used by the supervisor for emitter updates.

## Validator Results

No validator was run because this was a report-only assignment and no by-* or generated docs were edited. The report path was created only under `tools/leaser/Agents/Agent-B005/research/`.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00030K-NewArticleDialogCore-source-quality.md`
- Modified directly: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00030K-NewArticleDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00030K"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00030K-NewArticleDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00030K-NewArticleDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00030K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
