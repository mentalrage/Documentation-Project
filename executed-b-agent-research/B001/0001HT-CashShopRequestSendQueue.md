** TARGET-REPORT-UID:0001HT **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001HT] CashShopRequestSendQueue Split Ownership Report

## Final Recommendation

Keep [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](../../../../../by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) as a parent-blank, non-emitting Socket send/status helper container:

- `RECONSTRUCTABLE:FALSE`
- `COMPLETION:88`
- `CONFIDENCE:92`
- no `AUTOGEN_PARENT_UID`

Assign every source-bearing child in the range to [UID:0000DD][Socket](../../../../../by-class/Socket.md). The direct parent gate clears because Socket is `86/85` and [UID:0000NS][Socket](../../../../../by-file/Socket.md) is `88/85`. The former CashShopRequest owner is stale generated/search context only; Thread owns the queue primitive at `0x00596960`, not the Socket command wrappers; no new ProtocolSend/request-sender parent is justified for this target.

The split is now executable:

- Created [UID:0003AZ] `0x00574b90-0x00574ba4.PostSocketReceiveCommand`, `86/90`, parent `0000DD`.
- Created [UID:0003B0] `0x00574c20-0x00574c35.PostSocketModeByteCommand`, `86/90`, parent `0000DD`.
- Created [UID:0003B1] `0x00574c40-0x00574ca1.QueueTransportStringCommand`, `86/90`, parent `0000DD`.
- Created [UID:0003B2] `0x00574cb0-0x00574cc5.SendSingleByteCommand`, `86/90`, parent `0000DD`.
- Created [UID:0003B3] `0x00574cd0-0x00574cdb.IsSocketConnectedState`, `86/90`, parent `0000DD`.
- Created [UID:0003B4] `0x00574ce0-0x00574cf0.SetSocketSendDisabled`, `86/90`, parent `0000DD`.
- Created [UID:0003B5] `0x00574cf0-0x00574d00.SetSocketConnectionFlag`, `86/90`, parent `0000DD`.
- Repaired [UID:0001HV] `SendRawDataRaw` from parent-blank `86/89` to Socket-owned `87/90`, with the raw-start no-caller caveat preserved.
- Repaired [UID:0001HW] `SendPositionUpdate` from aggregate-parented `86/88` to Socket-owned `87/90`.
- Repaired [UID:0001HX] `BuildAndSendFriendNameListSync` from aggregate-parented `86/89` to Socket-owned `87/90`.
- Repaired [UID:0001HY] `GetConnectionStatus` from aggregate-parented `86/89` to Socket-owned `87/90`.
- [UID:0001HU] `QueueAndSendPacket` was already Socket-owned at `89/91` and remains unchanged.

Do not edit `by-memory/-coverage-report.md` directly from B001. The supervisor should replace the stale `0001HT` block with the exact rows below.

## Exact by-memory/-coverage-report.md Replacement Rows

Replace the current `0001HT` block at `by-memory/-coverage-report.md` lines containing `0001HT` through `0001HY`. Keep the preceding and following unrelated rows as-is.

```markdown
    - [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) 0x00574b90-0x00575377 | Socket send/status split inventory | CashShopRequestSendQueue : not_reconstructable : 88% : very-strong : B001-051 split execution converted this range to a parent-blank non-emitting Socket send/status helper container. Exact children carry Socket ownership; live IDA MCP confirmed all modeled/raw starts, all internal `0xcc` gaps, `g_packetSender` receiver and Socket-lifetime writes, `Socket::HandleSocketCommand` command consumers `7/8/9/10/11/14`, Socket field ownership for `this+0x3aa48/+0x3aa4d/+0x3aa4e/+0x3aa4f`, and rejected CashShopRequest/Thread as direct owners.
    - [UID:0003AZ][0x00574b90-0x00574ba4.PostSocketReceiveCommand](by-memory/0x00574b90-0x00574ba4.PostSocketReceiveCommand.md) 0x00574b90-0x00574ba4 | Socket command helper | PostSocketReceiveCommand : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms exact `sub_574B90` bounds, command `7` dispatch through `0x00596960`, two direct callers that pass `g_packetSender`, Socket-lifetime receiver evidence, and `Socket::HandleSocketCommand` case `7` as the consumer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574ba4-0x00574bb0 | padding | PostSocketReceiveCommand to QueueAndSendPacket alignment : ignored : 100% : strong : IDA confirms twelve `0xcc` bytes.
    - [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) 0x00574bb0-0x00574c13 | Socket send helper | QueueAndSendPacket : reconstructable : 89% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); live IDA reconfirmed exact boundary, allocator/copy/dispatch callees, 416 direct refs across 197 modeled callers, surrounding `0xcc` alignment, `g_packetSender` Socket-lifetime write evidence, and `Socket::HandleSocketCommand` case `8` as the queued-packet consumer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574c13-0x00574c20 | padding | QueueAndSendPacket to PostSocketModeByteCommand alignment : ignored : 100% : strong : IDA confirms thirteen `0xcc` bytes.
    - [UID:0003B0][0x00574c20-0x00574c35.PostSocketModeByteCommand](by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md) 0x00574c20-0x00574c35 | Socket command helper | PostSocketModeByteCommand : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms command `9` dispatch, five direct refs, direct/simple-alias `g_packetSender` receiver origin, and `Socket::HandleSocketCommand` case `9` writing a Socket state byte.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574c35-0x00574c40 | padding | PostSocketModeByteCommand to QueueTransportStringCommand alignment : ignored : 100% : strong : IDA confirms eleven `0xcc` bytes.
    - [UID:0003B1][0x00574c40-0x00574ca1.QueueTransportStringCommand](by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md) 0x00574c40-0x00574ca1 | Socket command helper | QueueTransportStringCommand : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms string allocation/copy/null-termination, command `10` dispatch, eight refs through direct or alias `g_packetSender`, and Socket dispatcher command `10` consuming and freeing the queued string.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574ca1-0x00574cb0 | padding | QueueTransportStringCommand to SendSingleByteCommand alignment : ignored : 100% : strong : IDA confirms fifteen `0xcc` bytes.
    - [UID:0003B2][0x00574cb0-0x00574cc5.SendSingleByteCommand](by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md) 0x00574cb0-0x00574cc5 | Socket command helper | SendSingleByteCommand : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms command `11` dispatch, one direct `g_packetSender` caller, and Socket dispatcher command `11` sending the byte through Winsock, mode-6 callback, or `WriteFile` transport.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574cc5-0x00574cd0 | padding | SendSingleByteCommand to IsSocketConnectedState alignment : ignored : 100% : strong : IDA confirms eleven `0xcc` bytes.
    - [UID:0003B3][0x00574cd0-0x00574cdb.IsSocketConnectedState](by-memory/0x00574cd0-0x00574cdb.IsSocketConnectedState.md) 0x00574cd0-0x00574cdb | Socket status helper | IsSocketConnectedState : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms the `this+0x3aa48 == 5` test, two direct `g_packetSender` callers, Socket constructor initialization of the state byte, and Socket transport consumers.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574cdb-0x00574ce0 | padding | IsSocketConnectedState to SetSocketSendDisabled alignment : ignored : 100% : strong : IDA confirms five `0xcc` bytes.
    - [UID:0003B4][0x00574ce0-0x00574cf0.SetSocketSendDisabled](by-memory/0x00574ce0-0x00574cf0.SetSocketSendDisabled.md) 0x00574ce0-0x00574cf0 | Socket status helper | SetSocketSendDisabled : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms setter for `this+0x3aa4e`, seven direct `g_packetSender` callers, and use of the same byte as the send guard in Socket queued-packet helpers.
    - [UID:0003B5][0x00574cf0-0x00574d00.SetSocketConnectionFlag](by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md) 0x00574cf0-0x00574d00 | Socket status helper | SetSocketConnectionFlag : reconstructable : 86% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms setter for `this+0x3aa4d`, one direct `g_packetSender` caller, Socket constructor initialization of the surrounding word, and Socket transport field-family use.
    - [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) 0x00574d00-0x00574d3f | Socket raw command helper | SendRawDataRaw : reconstructable : 87% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md) by best-defensible structure; IDA confirms the raw allocate-copy-dispatch body, request code `0x0e`, exact bytes, no modeled function/callers/code refs/data refs/direct `.text` calls/pointer hits to the raw start, one-byte `0xcc` boundary, and `Socket::HandleSocketCommand` case `14` as the matching queued raw-data consumer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574d3f-0x00574d40 | padding | SendRawDataRaw to SendPositionUpdate alignment : ignored : 100% : strong : IDA confirms one `0xcc` byte.
    - [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) 0x00574d40-0x00574e44 | Socket send helper | SendPositionUpdate : reconstructable : 87% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms exact range, reconnect/terminal callers at `0x005542a9` and `0x0058b42f`, `g_packetSender` receiver origin, 8-byte position/status packet, send-disabled guard, request-code `8`, and Socket dispatcher command `8` consumer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00574e44-0x00574e50 | padding | SendPositionUpdate to BuildAndSendFriendNameListSync alignment : ignored : 100% : strong : IDA confirms twelve `0xcc` bytes.
    - [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) 0x00574e50-0x0057536b | Socket send helper | BuildAndSendFriendNameListSync : reconstructable : 87% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms exact range, opcode `0x77` friend/name-list upload, 20 config slots, dedup/tree helper path, defined callers `0x00508b14` and `0x0053f8ed`, raw code ref `0x005143ad`, direct/alias `g_packetSender` receiver origin, send-disabled guard, request-code `8`, and Socket dispatcher command `8` consumer.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0057536b-0x00575370 | padding | BuildAndSendFriendNameListSync to GetConnectionStatus alignment : ignored : 100% : strong : IDA confirms five `0xcc` bytes.
    - [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) 0x00575370-0x00575377 | Socket status helper | GetConnectionStatus : reconstructable : 87% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); IDA confirms exact two-instruction getter, returns `this+0x3aa4f`, three `g_packetSender` code refs, no callees, Socket late-state field-family evidence, and the following `0x00575377-0x00575380` bytes are outside this parent range.
```

## Supporting Research

### Target

- Target UID: `0001HT`
- Target path: `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
- Supervisor assignment: B001-051 `[UID:0001HT] CashShopRequestSendQueue`
- Starting state: aggregate `85/87`, `RECONSTRUCTABLE:TRUE`, parent blank; children `0001HW`, `0001HX`, and `0001HY` were temporarily parented to `0001HT`, causing strict-gate debt because `0001HT` was not in the validator parent graph as a real source owner.
- Final master state: parent-blank, `RECONSTRUCTABLE:FALSE`, `88/92`.

### Function / Child Inventory

| UID | Range | Page | Direct parent | Score | Status |
|---|---:|---|---|---:|---|
| `0003AZ` | `0x00574b90-0x00574ba4` | `PostSocketReceiveCommand` | `Socket` class | `86/90` | created and assigned |
| `0001HU` | `0x00574bb0-0x00574c13` | `QueueAndSendPacket` | `Socket` class | `89/91` | already assigned |
| `0003B0` | `0x00574c20-0x00574c35` | `PostSocketModeByteCommand` | `Socket` class | `86/90` | created and assigned |
| `0003B1` | `0x00574c40-0x00574ca1` | `QueueTransportStringCommand` | `Socket` class | `86/90` | created and assigned |
| `0003B2` | `0x00574cb0-0x00574cc5` | `SendSingleByteCommand` | `Socket` class | `86/90` | created and assigned |
| `0003B3` | `0x00574cd0-0x00574cdb` | `IsSocketConnectedState` | `Socket` class | `86/90` | created and assigned |
| `0003B4` | `0x00574ce0-0x00574cf0` | `SetSocketSendDisabled` | `Socket` class | `86/90` | created and assigned |
| `0003B5` | `0x00574cf0-0x00574d00` | `SetSocketConnectionFlag` | `Socket` class | `86/90` | created and assigned |
| `0001HV` | `0x00574d00-0x00574d3f` | `SendRawDataRaw` | `Socket` class | `87/90` | repaired and assigned |
| `0001HW` | `0x00574d40-0x00574e44` | `SendPositionUpdate` | `Socket` class | `87/90` | repaired and assigned |
| `0001HX` | `0x00574e50-0x0057536b` | `BuildAndSendFriendNameListSync` | `Socket` class | `87/90` | repaired and assigned |
| `0001HY` | `0x00575370-0x00575377` | `GetConnectionStatus` | `Socket` class | `87/90` | repaired and assigned |

All internal non-code gaps are `0xcc` alignment. No source-bearing modeled start inside the target remains aggregate-only.

### IDA MCP Facts

- IDA target: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Modeled function inventory inside `0x00574b90-0x00575377`: `0x00574b90-0x00574ba4`, `0x00574bb0-0x00574c13`, `0x00574c20-0x00574c35`, `0x00574c40-0x00574ca1`, `0x00574cb0-0x00574cc5`, `0x00574cd0-0x00574cdb`, `0x00574ce0-0x00574cf0`, `0x00574cf0-0x00574d00`, `0x00574d40-0x00574e44`, `0x00574e50-0x0057536b`, and `0x00575370-0x00575377`.
- Raw helper `0x00574d00-0x00574d3f` remains outside any IDA function. Its body calls `0x00516030`, `0x00516050`, `0x00516220`, and `0x00596960`, dispatching command `0x0e`, then returns with `retn 8`.
- Padding checks: `0x00574ba4-0x00574bb0`, `0x00574c13-0x00574c20`, `0x00574c35-0x00574c40`, `0x00574ca1-0x00574cb0`, `0x00574cc5-0x00574cd0`, `0x00574cdb-0x00574ce0`, `0x00574d3f-0x00574d40`, `0x00574e44-0x00574e50`, and `0x0057536b-0x00575370` are `0xcc`.
- `sub_596960` builds a six-dword request record, enqueues it through the object field at `this+76`, and signals the semaphore at `this+12`. This supports Thread ownership of the queue primitive only.
- `Socket::HandleSocketCommand` at `0x00575e60` consumes the posted commands: `7` receive/event dispatch, `8` queued packet send/free, `9` Socket byte write, `10` queued string consumer/free, `11` one-byte transport send, and `14` raw-data size/buffer consumer.
- `g_packetSender` / `dword_67A7EC` has 489 refs and only five write-like refs, all in Socket constructor/destructor/unwind/scalar-destructor code: `0x00574828`, `0x0057482f`, `0x00574aaf`, `0x005794c0`, and `0x00579676`.
- `g_pCashShopRequest` / `dword_67A738` is separate; its write refs are in the FileDownloader/CashShopRequest lifetime path and do not overlap `g_packetSender`.
- Receiver-origin scan: every direct caller to `0x00574b90`, `0x00574bb0`, `0x00574cb0`, `0x00574cd0`, `0x00574ce0`, `0x00574cf0`, `0x00574d40`, `0x00574e50`, and `0x00575370` passes `dword_67A7EC`. `0x00574c20` and `0x00574c40` have only direct or simple alias `dword_67A7EC` receivers.
- Field-use scan: Socket constructor `0x005747e0` initializes the late field family at `this+0x3aa48`, `this+0x3aa4d`, and `this+0x3aa4f`; Socket transport methods read/use these same bytes. Helpers in this range read or set `this+0x3aa48`, `this+0x3aa4d`, `this+0x3aa4e`, and `this+0x3aa4f`.
- No helper start in this range has data refs, vtable refs, or pointer-table refs supporting CashShopRequest. The absence is neutral for non-virtual methods, but it removes the only likely source of direct CashShopRequest ownership proof.

### Ownership Analysis

Socket is the only owner with positive binary evidence across receiver lifetime, dispatcher command semantics, and object field ownership. The helper family is not merely "called by Socket"; it is invoked on the Socket-lifetime sender object and consumed by Socket's command dispatcher.

Thread remains a callee dependency. The queue primitive at `0x00596960` should stay with [UID:0000OR][Thread](../../../../../by-file/Thread.md), but that does not make the command wrappers Thread methods. The wrappers encode Socket-specific command IDs and Socket fields before handing work to the generic queue.

CashShopRequest is weaker than Socket. Existing CashShopRequest docs and generated labels are useful search leads, but direct IDA evidence separates `g_pCashShopRequest` from `g_packetSender`, gives Socket the packet-sender lifetime writes, and gives Socket the dispatcher/field consumers. Treat CashShopRequest as stale generated ownership for this target.

ProtocolSend or a new request-sender parent is also weaker. The current binary evidence does not show a separate constructor/lifetime/global/vtable anchor for such an owner, while it does show Socket lifetime and dispatcher anchors. Creating a new parent here would obscure the stronger existing Socket owner.

The raw child [UID:0001HV] is the only reachability caveat. It has no caller, table, pointer, or direct-call proof at `0x00574d00`, but it shares the same allocator/copy/dispatch shape and posts command `14`, which Socket consumes. Leaving it parentless would be less executable than assigning it to Socket with the explicit no-reachability caveat.

### Validator Results

Commands were run from `E:\NTK\GhidraBridge`:

- Initial UID assignment for the seven new child pages:
  - `python source-3/project-documentation/tools/validator.py --mode file --file <new child page> --apply`
  - Result: exit `0` for each; validator assigned UIDs `0003AZ`, `0003B0`, `0003B1`, `0003B2`, `0003B3`, `0003B4`, and `0003B5`.
- Final validation for target pages:
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574b90-0x00574ba4.PostSocketReceiveCommand.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574cd0-0x00574cdb.IsSocketConnectedState.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574ce0-0x00574cf0.SetSocketSendDisabled.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md --apply` -> exit `0`
  - `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00575370-0x00575377.GetConnectionStatus.md --apply` -> exit `0`

Each run also printed the existing validator-generated no-op line `autogen_cpp_noop 0000J5 auto-generated/NexusTK/util/Error.cpp no assembled code for root`; this is not a validation error from the edited pages. The generated memory coverage now shows `0003AZ`, `0003B0` through `0003B5`, `0001HV`, `0001HW`, `0001HX`, and `0001HY` as `assigned` to `0000DD`, `0001HU` unchanged as assigned to `0000DD`, and `0001HT` as `not_reconstructable`; no `autogen_parent_unknown` rows remain for this target.

### Leases Used

- Leased the existing parent and editable existing children before edits: `0001HT`, `0001HV`, `0001HW`, `0001HX`, and `0001HY`.
- Leased the existing parent before creating new child files, then validated the new files to assign UIDs.
- After the new files existed, leased all new child pages before changing metadata.
- Refreshed leases for the full target-page set before the final validator pass, including `0001HU` as a read/validation sanity check.
- No conflicting lease was reported for the target files.

### Changed Files

- `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
- `by-memory/0x00574b90-0x00574ba4.PostSocketReceiveCommand.md`
- `by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md`
- `by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md`
- `by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md`
- `by-memory/0x00574cd0-0x00574cdb.IsSocketConnectedState.md`
- `by-memory/0x00574ce0-0x00574cf0.SetSocketSendDisabled.md`
- `by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md`
- `by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md`
- `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`
- `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md`
- `by-memory/0x00575370-0x00575377.GetConnectionStatus.md`
- `tools/leaser/Agents/Agent-B001/research/0001HT-CashShopRequestSendQueue.md`
- Validator-generated registry/report updates occurred in `tools/validator.ini` and `auto-generated/-ag-memory-coverage.md`, with validator backup directories created under `tools/validator_autogen_backup/`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001HT-CashShopRequestSendQueue.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001HT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
