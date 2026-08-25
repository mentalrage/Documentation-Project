** TARGET-REPORT-UID:0003UT **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UT **
# B004 Source-Quality Report: UID 0003UT LivingObjectPaneHandleUIPanelSwitchPacket

Assignment: `B004-goal2-livingobject-ui-panel-switch-packet-source-quality-0003UT-20260619`

Target: [UID:0003UT] `by-memory/0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md`

Report-only constraint honored: I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

## Executive Decision

[UID:0003UT] should remain a `LivingObjectPane` packet handler owned/emitted through [UID:00007B] `LivingObjectPane`, with source placement in `NexusTK/map/LivingObjectPane.cpp`.

Best source-facing method name:

`bool LivingObjectPane::HandleUIPanelSwitchPacket(const uint8_t *serverPayload)`

The exact original parameter typedef is not recovered. The caller passes the message payload pointer, not the whole event object: [UID:0003VB] `UserPane::HandleServerMessage` loads `edi = event+0x0c payload`, pushes `edi`, normalizes the receiver to the embedded `LivingObjectPane` subobject via `ecx = ebx - 0xa0`, and calls `0x005abda0`.

Resolved dispatch route:

- Upstream server opcode is `0x3e` (`'>'`).
- `UserPane::HandleServerMessage` subtracts `4` from `payload[0]`, indexes byte table `0x005a8324`, then dispatches through dword table `0x005a82c0`.
- Opcode `0x3e` maps to compact switch index `15`, target `0x005a7dd5`.
- `0x005a7dd5` pushes the payload pointer and calls `0x005abda0` at `0x005a7ddc`.
- Local PE rel32 scan found exactly one direct call to `0x005abda0`, at `0x005a7ddc`.

Resolved target payload:

- The handler initializes a packet cursor to `1` and calls `0x00575710(payload, &cursor)`.
- Therefore `payload[0]` is the already-dispatched server opcode `0x3e`; `payload[1]` is the UI-panel action byte.
- The action byte is accepted for values `0..8`; values `>8` are no-op success.
- Values `1`, `3`, and `5` are also no-op success entries in both layout modes.
- The target always returns success (`al = 1`) including no-op and invalid action cases.

Recommended score and metadata:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `87` | `90` |
| `CANONICAL_OWNER` | `00007B` | keep `00007B` |
| `RECONSTRUCTABLE` | `TRUE` | keep `TRUE` |
| `EMITTER_UIDS` | `00007B` | keep `00007B` |
| `RECONSTRUCTION_CPP` | blank | keep blank for now |

Completion should rise because opcode, payload byte, two layout-mode action tables, direct caller, direct dependencies, switch-table subrange, and support-doc work are now resolved. Confidence should rise because the core behavior is raw-byte proven in the local PE and agrees with existing `LivingObjectPane`/`GeneralPurposePanel`/`UserPane` docs. Completion should not rise higher until the `SelfLookPane +0x232c` member and helper `0x005acfe0` are documented source-quality.

## Evidence Checked

Static executable basis:

- Local executable: `E:\NTK\Resources\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- Target raw offset: `0x001ab1a0`

IDA MCP availability:

- Attempted `http://127.0.0.1:13337/mcp` JSON-RPC `tools/list`.
- Result: timed out / unavailable in this session.
- I therefore used existing IDA-backed docs plus a fresh local PE/Capstone disassembly. The report explicitly separates current raw PE evidence from prior IDA documentation evidence.

Target and support docs read:

- [UID:0003UT] target page.
- [UID:0003VB] `UserPaneHandleServerMessage`.
- [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`.
- [UID:00007B] `LivingObjectPane` class page.
- [UID:0000KU] `LivingObjectPane` file page.
- [UID:00015X] `GeneralPurposePanelSwitchActiveTab`.
- [UID:00015W] `GeneralPurposePanelChildAccessors`.
- [UID:00015Y] `GeneralPurposePanel2SwitchActiveChild`.
- [UID:0000JQ] `GeneralPurposePanel` file page.
- [UID:0000R0] `g_pGeneralPurposePanel`.
- [UID:0000R1] `g_pGeneralPurposePanel2`.
- [UID:0000PN] `FrameChromeSlots`.
- [UID:0000SW] `g_useEpfAssets`.
- [UID:0000Q5] `g_packetSender`.
- [UID:0001HU] `QueueAndSendPacket`.
- [UID:0001HS] `SocketLifecycle`.
- [UID:0002RG] `SelfLookPaneViewToggleRaw`.
- [UID:0000CU] `SelfLookPane` class page.
- [UID:0000NL] `SelfLookPane` file page.
- Agent reports for [UID:0003US], [UID:0003UV], [UID:0003UU], [UID:00018H], and the old [UID:0001KM] split audit.

Searches/checks performed:

- Searched `by-memory`, `by-file`, `by-class`, `by-global`, and agent reports for `0003UT`, `0x005abda0`, `0x005abee8`, `0x005abf30`, `0x005acfe0`, `sub_5ABDA0`, panel-switch strings, and helper/global addresses.
- Scanned `.text` for rel32 calls to `0x005abda0`, `0x005acfe0`, `0x004b8650`, `0x004b85f0`, `0x004b89a0`, `0x00574bb0`, and related targets.
- Parsed the `UserPane::HandleServerMessage` compact switch byte table and dword dispatch table.
- Parsed the two target action dword tables at `0x005abee8` and `0x005abf0c`.
- Searched `by-memory/-coverage-report.md` and `auto-generated/-ag-memory-coverage.md` for current rows.

Validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality-removed.md](0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code `0`.
- `mode: file`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target line: `ok 0003UT by-memory/0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md UID header exists`

The validator emitted normal dry-run/autogen status lines and did not modify files.

## Function Boundary And Split/Range Decisions

Target function:

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x005abda0-0x005abee8` | modeled function body | Existing target page records B001 live IDA `lookup_funcs` start `0x005abda0`, size `0x148`, end `0x005abee8`; local PE bytes decode as one `__thiscall` body ending in `ret 4`. |

Neighboring bytes:

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x005abd99-0x005abda0` | alignment before target | Local PE pre-bytes show preceding function epilogue ending before seven `0xcc` bytes. Not part of this target. |
| `0x005abee8-0x005abf0c` | compiler dword jump table A | Nine dword table entries used by `jmp dword ptr [eax*4 + 0x005abee8]` at `0x005abdd2` when `g_useEpfAssets == 1`. |
| `0x005abf0c-0x005abf30` | compiler dword jump table B | Nine dword table entries used by `jmp dword ptr [eax*4 + 0x005abf0c]` at `0x005abe2c` when `g_useEpfAssets != 1`. |
| `0x005abf30` | next prologue | Local PE bytes show `55 8b ec 56 ...`; this is the next function-shaped body, not target table data. |

Decision:

- Keep [UID:0003UT] range exactly `0x005abda0-0x005abee8`.
- Do not widen [UID:0003UT] to include `0x005abee8-0x005abf30`; IDA function size and existing by-memory target exclude those bytes.
- Add a supervisor-owned ignored/compiler-data row for `0x005abee8-0x005abf30`, or create an exact compiler switch-table child if the project prefers explicit switch-table pages. The current evidence supports `-ignored.md` compiler switch-table coverage because the bytes are two plain dword jump tables with no source-authored logic.

## Disassembly-Derived Behavior

Function prologue and mode branch:

```asm
005abda0  push ebp
005abda1  mov  ebp, esp
005abda3  push ecx
005abda4  cmp  byte ptr [0x66da97], 1
005abdab  lea  eax, [ebp-4]
005abdae  push esi
005abdaf  push eax
005abdb0  push dword ptr [ebp+8]
005abdb3  mov  esi, ecx
005abdb5  mov  dword ptr [ebp-4], 1
005abdbc  jne  0x005abe18
```

Interpretation:

- `ecx` is `LivingObjectPane *this`, saved in `esi`.
- `[ebp+8]` is the server payload pointer.
- Local cursor starts at `1`.
- `0x0066da97` is [UID:0000SW] `g_useEpfAssets`.
- If `g_useEpfAssets == 1`, the current/EPF table at `0x005abee8` is used.
- If `g_useEpfAssets != 1`, the legacy table at `0x005abf0c` is used.

EPF/current branch:

```asm
005abdbe  call 0x00575710
005abdc3  movzx eax, al
005abdc6  add esp, 8
005abdc9  cmp eax, 8
005abdcc  ja  0x005abedf
005abdd2  jmp dword ptr [eax*4 + 0x005abee8]
```

Legacy branch:

```asm
005abe18  call 0x00575710
005abe1d  movzx eax, al
005abe20  add esp, 8
005abe23  cmp eax, 8
005abe26  ja  0x005abedf
005abe2c  jmp dword ptr [eax*4 + 0x005abf0c]
```

Both branches call `0x00575710(payload, &cursor)` with `cursor = 1`, so the switch byte is `payload[1]`.

Direct target actions:

- `0x004b8650`: [UID:00015X] `GeneralPurposePanel::SwitchActiveTab(index, showFlag)`.
- `0x004b85f0`: [UID:00015W] `GeneralPurposePanel::GetChildPaneByIndex(index)`.
- `0x005a50a0`: [UID:00001D]/[UID:0000HX] `EnsureNormalBulletinSession` / `EnsureBulletinSession_5A50A0`.
- `0x005acfe0`: recommended helper name `LivingObjectPane::SendUIPanelSwitchAckPacket`.
- `0x00575710`: packet-byte read with cursor, best local alias `PacketReadUInt8AtCursor`.

## Packet Action Table

`GeneralPurposePanel` child order from current docs:

| Index | Panel child |
| ---: | --- |
| `0` | self look |
| `1` | user look/profile |
| `2` | inventory |
| `3` | spell inventory |
| `4` | group |
| `5` | collection |
| `6` | option |

Action byte mapping:

| `payload[1]` | Current / EPF mode (`g_useEpfAssets == 1`) | Legacy mode (`g_useEpfAssets != 1`) | Evidence |
| ---: | --- | --- | --- |
| `0` | `GeneralPurposePanel::SwitchActiveTab(2, 0)` - inventory | same | `0x005abe33`: loads `g_pGeneralPurposePanel`, pushes `0`, pushes `2`, calls `0x004b8650`. |
| `1` | no-op success | no-op success | Table entries jump to default return at `0x005abedf`. |
| `2` | `GeneralPurposePanel::SwitchActiveTab(3, 0)` - spell inventory | same | EPF `0x005abdd9`; legacy `0x005abe4b`; both push `3`, `0`, call `0x004b8650`. |
| `3` | no-op success | no-op success | Table entries jump to default return. |
| `4` | send ACK, then `GetChildPaneByIndex(0)->+0x232c = 0` | send ACK, then `GetChildPaneByIndex(0)->+0x232c = 1` | EPF `0x005abdf1`; legacy `0x005abe63`. |
| `5` | no-op success | no-op success | Table entries jump to default return. |
| `6` | `EnsureNormalBulletinSession()` | same | `0x005abe8a` calls `0x005a50a0` on `this`. |
| `7` | send ACK, then `GetChildPaneByIndex(0)->+0x232c = 1` | send ACK, then `GetChildPaneByIndex(0)->+0x232c = 3` | EPF `0x005abe63`; legacy `0x005abe9a`. |
| `8` | send ACK, then `GetChildPaneByIndex(0)->+0x232c = 2` | same | `0x005abec1`. |
| `>8` | no-op success | no-op success | `cmp eax, 8; ja 0x005abedf`. |

The `SelfLookPane` child state write is deliberately recorded as `+0x232c`, not as a final field name. Existing SelfLookPane docs validate adjacent view/cache state at `+0x2328` and `+0x233c`, but I did not find source-quality documentation for `+0x232c`. The best current interpretation is a server-requested self-look subview or pending self-look mode field, with values selected by server action and layout mode. It is not the `GeneralPurposePanel` active child index, and it is not the target packet opcode.

## Helper `0x005acfe0`

The target calls `0x005acfe0` exactly four times:

- `0x005abdf3`
- `0x005abe65`
- `0x005abe9c`
- `0x005abec3`

Local PE direct-call scan found no other calls to `0x005acfe0`.

Disassembly:

```asm
005acfe0  push ebp
005acfe1  mov  ebp, esp
005acfe3  sub  esp, 0x14
005acff0  lea  eax, [ebp-0x14]
005acff3  push eax
005acff4  push 0x2d
005acff6  call 0x00575380
005acffb  lea  eax, [ebp-0x13]
005acffe  push eax
005acfff  push 0
005ad001  call 0x00575380
005ad006  mov  ecx, dword ptr [0x67a7ec]
005ad00c  lea  eax, [ebp-0x14]
005ad012  mov  byte ptr [ebp-0x12], 0
005ad016  push 2
005ad018  push eax
005ad019  call 0x00574bb0
```

Interpretation:

- `0x00575380` is `PacketBufferWriteUInt8` / byte writer.
- It builds bytes `{ 0x2d, 0x00 }`.
- It writes a local terminator at byte 2, but sends explicit length `2`; the terminator is not sent.
- `0x0067a7ec` is [UID:0000Q5] `g_packetSender`, best type `Socket *`.
- `0x00574bb0` is [UID:0001HU] `QueueAndSendPacket`.

Best helper name:

`LivingObjectPane::SendUIPanelSwitchAckPacket()`

Rejected helper names:

- `CashShopRequest::meth_0x574bb0`: stale generated ownership for the send funnel.
- `SendFaceDirectionPacket` / movement helper: wrong opcode and no movement-history state.
- `SendOpcode2DAndStoreExtra`: adjacent opcode `0x2d` documentation exists elsewhere, but this helper only sends `{0x2d,0}` and does not store the extra-value slots described for `0x005a4f70`.
- `GeneralPurposePanel` helper: body has a `LivingObjectPane` caller-only route and sends a server ACK before self-look state writes; it is not panel-composition logic.

Implementation decision:

- Create an exact support child for `0x005acfe0-0x005ad02c` if a UID is available.
- Keep it owned by [UID:00007B] `LivingObjectPane`.
- Do not merge its body into [UID:0003UT] in documentation, because it is a distinct function with its own prologue, stack cookie, packet buffer, and send call.

## Heuristic / Inference Reanalysis And Validation

### Compiler/generated names

`sub_5ABDA0`

- Best source-facing name: `LivingObjectPane::HandleUIPanelSwitchPacket`.
- Evidence: Existing [UID:0001KM] table already names `HandleUIPanelSwitchPacket`; [UID:0003VB] direct dispatch calls it from server opcode `0x3e`; body switches a one-byte panel action and calls panel helpers.
- Rejected: `UserPane::HandleUIPanelSwitchPacket`. The caller is `UserPane::HandleServerMessage`, but it normalizes `ecx` to `ebx - 0xa0`, matching the embedded `LivingObjectPane` subobject used by the sibling packet handlers. Existing `LivingObjectPane` class/file docs list this as a server packet handler.

`sub_5ACFE0`

- Best source-facing name: `LivingObjectPane::SendUIPanelSwitchAckPacket`.
- Evidence: Only direct callers are the four self-look action branches inside `0x005abda0`; body sends fixed two-byte opcode `0x2d,0` through `g_packetSender`.
- Rejected: generic `SendOpcode2DAndStoreExtra`, because no storage write occurs here. Rejected Socket/CashShop owner, because Socket owns the queue-send funnel, not the feature packet body.

`sub_4B8650`

- Best source-facing name: `GeneralPurposePanel::SwitchActiveTab`.
- Evidence: [UID:00015X] and [UID:0000JQ] document the seven-child side-panel shell, active-index storage, EPF/legacy geometry, broad side-panel callers, and stale `SpellOneArgInputPane` owner rejection.
- In this target it is a dependency, not target ownership evidence.

`sub_4B85F0`

- Best source-facing name: `GeneralPurposePanel::GetChildPaneByIndex`.
- Evidence: [UID:00015W] documents `this[index + 1]`, `g_useEpfAssets` child-count branch, and the child order. Target calls it only with index `0`, then writes into the returned self-look child.
- Rejected: treating the return as a generic pane with no type. Context and child-order docs make `SelfLookPane` the best current receiver type for index `0`; the member at `+0x232c` still needs exact naming.

`sub_5A50A0`

- Best source-facing name: `EnsureNormalBulletinSession` / `EnsureBulletinSession_5A50A0`.
- Evidence: `BulletinSession` class/file docs identify `0x005a50a0-0x005a5103` as a shared lazy initializer used by UI input/panel paths to open the normal bulletin session.
- Rejected: panel switch helper. This is action byte `6` only and belongs to BulletinSession support.

`sub_575710`

- Best source-facing role: packet byte read with cursor, local alias `PacketReadUInt8AtCursor`.
- Evidence: Target initializes cursor `1`, passes payload pointer plus cursor pointer, and switches on returned `al`; B004 prior `0001AZ` evidence also used cursor `1` with `0x00575710`.
- Final original helper name remains unresolved; this is a packet parsing dependency, not owner evidence.

`sub_575380`

- Best source-facing role: `PacketBufferWriteUInt8`.
- Evidence: Multiple B-agent packet helper reports normalize it as byte writer; `0x005acfe0` uses it to write `0x2d` and `0`.

`sub_574BB0`

- Best source-facing name: `QueueAndSendPacket`.
- Evidence: [UID:0001HU] documents exact body, Socket ownership, request code `8`, and wide feature caller fan-in.

### Globals, fields, and unclear types

`0x0066da97`

- Best name: [UID:0000SW] `g_useEpfAssets`.
- Evidence: Target compares byte against `1`; support docs define it as current EPF/high-layout versus legacy EPD/layout selector with initial value `1`.
- Ownership: StartupWindow-owned global; dependency only.
- Rejected: target-local mode field or panel-specific flag. The global has hundreds of cross-subsystem refs and only a startup write.

`0x0067a874`

- Best name: [UID:0000R0] `g_pGeneralPurposePanel`.
- Evidence: Target loads it before every `0x004b8650` and `0x004b85f0` call; docs define active seven-child side-panel singleton.
- Ownership: `GeneralPurposePanel.cpp`; dependency only.

`0x0067a7ec`

- Best name/type: [UID:0000Q5] `g_packetSender`, `Socket *`.
- Evidence: `0x005acfe0` sends through it; Socket docs own lifetime writes; `QueueAndSendPacket` owns the queue funnel.
- Ownership: `Socket`; dependency only.

`SelfLookPane +0x232c`

- Best current name: `m_serverRequestedViewMode` or `m_pendingServerViewMode` as a temporary documentation alias only.
- Evidence: Target gets GeneralPurposePanel child `0` and writes values `0`, `1`, `2`, or `3` at offset `+0x232c` after sending ACK. Adjacent SelfLookPane docs validate `+0x2328` as active view-mode state and `+0x233c` as a view/cache toggle. This makes `+0x232c` very likely SelfLookPane view-related state.
- What cannot be safely concluded: I did not find a source-quality doc that names `+0x232c`, explains why legacy action `7` maps to `3`, or proves whether it is a pending mode, server-requested mode, button/subview id, or a separate view cache selector.
- Score/C++ impact: this is the main target-level formal C++ blocker.

`payload[1]`

- Best name: `panelAction` or `panelSwitchAction`.
- Evidence: It selects inventory/spell tabs, self-look mode writes, or BulletinSession open.
- Rejected: `packet subtype` if that implies a nested opcode byte. The upstream opcode is `payload[0] == 0x3e`; `payload[1]` is an action byte within that packet.

### Ownership and source placement

Owner retained as [UID:00007B] `LivingObjectPane`.

Positive evidence:

- Existing [UID:0001KM], [UID:00007B], and [UID:0000KU] docs list this address in the local-player server packet handler family.
- Direct caller normalizes from `UserPane` to `LivingObjectPane` subobject before the call.
- Sibling packet handlers around `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab860`, `0x005ac070`, and `0x005ac280` are `LivingObjectPane` packet handlers reached from the same dispatcher.
- The target performs packet-body semantics and delegates to UI feature modules.

Rejected owners:

- `UserPane`: only owns the virtual server-message dispatcher and UI surface. It calls this handler but does not own the packet-body method.
- `GeneralPurposePanel`: owns panel composition and switching helpers. The target calls it as a dependency and does not operate on a `GeneralPurposePanel` receiver.
- `SelfLookPane`: target writes one SelfLookPane field through child `0`, but packet parsing and ACK behavior remain `LivingObjectPane` responsibilities.
- `BulletinSession`: only action byte `6` calls its lazy initializer.
- `Socket`: only ACK helper sends through `g_packetSender`; Socket owns transport, not feature packet construction.
- `StartupWindow` / `g_useEpfAssets`: global layout-mode dependency only.

### Caller/reachability

Best call route:

```asm
005a7727  movzx eax, byte ptr [edi]       ; payload[0]
005a772a  add   eax, -4
005a772d  cmp   eax, 0x7f
005a7736  movzx eax, byte ptr [eax + 0x005a8324]
005a773d  jmp   dword ptr [eax*4 + 0x005a82c0]
...
005a7dd5  push  edi
005a7dd6  lea   ecx, [ebx - 0xa0]
005a7ddc  call  0x005abda0
```

Parsed dispatch table result:

| Server opcode | Compact switch index | Target |
| ---: | ---: | --- |
| `0x3e` (`'>'`) | `15` | `0x005a7dd5`, direct call to `0x005abda0` |

No alternate direct call route to `0x005abda0` was found in `.text`. This is a live direct handler, unlike the retained duplicate/no-live-route [UID:0003US] user-list helper.

### Open questions closed or capped

Packet subtype:

- Closed. Upstream opcode is `0x3e`; target action byte is `payload[1]`.

Panel mode names:

- Partially closed. GeneralPurposePanel tab names are exact enough: inventory `2`, spell inventory `3`, self-look child `0`.
- SelfLookPane `+0x232c` values remain exact numeric states with a strong view-mode inference but no final original field name.

Helper declarations:

- Closed enough for ownership and behavior. `0x005acfe0` is a private `LivingObjectPane` ACK sender. It needs its own support child before formal C++ should refer to it by name.

Source placement:

- Closed. Target belongs to `LivingObjectPane.cpp`; dependencies remain in their own modules.

Switch table range:

- Closed. `0x005abee8-0x005abf30` should be covered as compiler switch-table data, not merged into the source method body.

First-draft C++:

- Not eligible for formal target insertion yet. The exact no-code proof is below.

## First-Draft C++ Recommendation / Exact No-Code Proof

Do not emit formal `RECONSTRUCTION_CPP` for [UID:0003UT] in this implementation callback yet.

Exact no-code proof:

1. The method behavior is clear, but one effect writes `SelfLookPane +0x232c`, and no current source-quality page names that field or validates all four numeric values. Existing SelfLookPane docs validate adjacent `+0x2328` and `+0x233c`, not `+0x232c`.
2. The target calls real helper `0x005acfe0` four times. This helper has no exact by-memory child yet. Inlining it into [UID:0003UT] would misrepresent the binary call graph; naming it in C++ before creating/documenting its page would invent a declaration without support.
3. The target's compiler jump tables are outside the current target range at `0x005abee8-0x005abf30`. The source body can of course be represented as `switch`, but the coverage model should first account for the compiler-data range so future validators and reviewers do not treat the table bytes as an unclassified gap or a hidden function.
4. The formal parameter type remains `const uint8_t *payload` by caller evidence. The original project packet reader type/signature for `0x00575710` is still not recovered. A first draft could use a descriptive `PacketReadUInt8AtCursor`, but the helper declaration would still be inferred.

Safe implementation after support updates:

```cpp
bool LivingObjectPane::HandleUIPanelSwitchPacket(const uint8_t *payload)
{
    int cursor = 1;
    const uint8_t action = PacketReadUInt8AtCursor(payload, &cursor);

    if (g_useEpfAssets == 1) {
        switch (action) {
        case 0:
            g_pGeneralPurposePanel->SwitchActiveTab(2, false);
            return true;
        case 2:
            g_pGeneralPurposePanel->SwitchActiveTab(3, false);
            return true;
        case 4:
            SendUIPanelSwitchAckPacket();
            static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 0;
            return true;
        case 6:
            EnsureNormalBulletinSession();
            return true;
        case 7:
            SendUIPanelSwitchAckPacket();
            static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 1;
            return true;
        case 8:
            SendUIPanelSwitchAckPacket();
            static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 2;
            return true;
        default:
            return true;
        }
    }

    switch (action) {
    case 0:
        g_pGeneralPurposePanel->SwitchActiveTab(2, false);
        return true;
    case 2:
        g_pGeneralPurposePanel->SwitchActiveTab(3, false);
        return true;
    case 4:
        SendUIPanelSwitchAckPacket();
        static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 1;
        return true;
    case 6:
        EnsureNormalBulletinSession();
        return true;
    case 7:
        SendUIPanelSwitchAckPacket();
        static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 3;
        return true;
    case 8:
        SendUIPanelSwitchAckPacket();
        static_cast<SelfLookPane *>(g_pGeneralPurposePanel->GetChildPaneByIndex(0))->m_serverRequestedViewMode = 2;
        return true;
    default:
        return true;
    }
}
```

This is implementation-planning pseudocode only. Do not paste it into the target C++ block until `SendUIPanelSwitchAckPacket`, `SelfLookPane +0x232c`, and the packet-reader declaration are documented source-quality.

## Target / Support Implementation Checklist

Target [UID:0003UT] `by-memory/0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md`:

1. Update score to `COMPLETION:88`, `CONFIDENCE:90`.
2. Keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
3. Keep formal C++ blank with the exact no-code proof above.
4. Replace the summary with resolved behavior: `UserPane::HandleServerMessage` opcode `0x3e` calls this handler; the handler reads `payload[1]` and selects panel actions by `g_useEpfAssets`.
5. Add the action table from this report.
6. Add direct dependency list: `g_useEpfAssets`, `g_pGeneralPurposePanel`, `GeneralPurposePanel::SwitchActiveTab`, `GeneralPurposePanel::GetChildPaneByIndex`, `SelfLookPane +0x232c`, `EnsureNormalBulletinSession`, `SendUIPanelSwitchAckPacket`, packet read helper.
7. Add split/range note: local jump tables at `0x005abee8-0x005abf30` are compiler-generated table data outside the current function range.
8. Replace generic open questions with closed/capped items: only `SelfLookPane +0x232c`, exact packet reader typedef, and ACK helper child declaration block formal C++.

Support docs:

1. [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`:
   - Update `0x005abda0` row from generic UI panel switch/open packet to opcode `0x3e` handler with `payload[1]` action map.
   - Add `0x005acfe0-0x005ad02c` as a helper candidate: `SendUIPanelSwitchAckPacket`, called only by [UID:0003UT], sends `{0x2d,0}` length `2`.
   - Add `0x005abee8-0x005abf30` compiler switch-table coverage note.
2. [UID:00007B] `LivingObjectPane` class page:
   - In local player settings/server packets family, note that [UID:0003UT] is now opcode `0x3e` with `payload[1]` action map.
   - Add dependency caveat: GeneralPurposePanel, SelfLookPane, BulletinSession, Socket/QueueAndSendPacket are dependencies, not owner routes.
3. [UID:0000KU] `LivingObjectPane` file page:
   - Update server packet handler row or notes with opcode `0x3e`, action table summary, and ACK helper candidate.
4. [UID:0003VB] `UserPaneHandleServerMessage`:
   - Add exact dispatch mapping: opcode `0x3e` compact index `15`, target `0x005a7dd5`, direct call `0x005a7ddc`.
   - Preserve ownership: dispatcher stays `UserPane`, target stays `LivingObjectPane`.
5. [UID:00015X] `GeneralPurposePanelSwitchActiveTab`:
   - Optional caller note: [UID:0003UT] calls it with tab `2` inventory and tab `3` spell inventory.
6. [UID:00015W] `GeneralPurposePanelChildAccessors`:
   - Optional caller note: [UID:0003UT] fetches child index `0` self look before writing `+0x232c`.
7. [UID:0000CU] / [UID:0000NL] `SelfLookPane` docs:
   - Add a pending field note for `SelfLookPane +0x232c`, written by [UID:0003UT] after ACK for action bytes `4`, `7`, and `8`.
   - Keep the final member name provisional; do not conflate it with documented `+0x2328` active view mode.
8. New helper child if UID is allocated:
   - Create `by-memory/0x005acfe0-0x005ad02c.LivingObjectPaneSendUIPanelSwitchAckPacket.md`.
   - Set owner/emitter to [UID:00007B].
   - Document fixed packet `{0x2d,0}`, unsent local terminator, `g_packetSender`, `QueueAndSendPacket`, only-callers-from-[UID:0003UT] evidence, and blank C++ until packet writer prototypes are source-quality.
9. [UID:0001HU] `QueueAndSendPacket` or [UID:0000Q5] `g_packetSender`:
   - Optional support note that `0x005acfe0` is a feature packet builder caller with length `2`; this is not ownership evidence.
10. `by-memory/-ignored.md`:
   - Add compiler-data row for `0x005abee8-0x005abf30` or create an exact switch-table child, depending on supervisor preference.

## Supervisor-Owned Coverage Rows

Current live `by-memory/-coverage-report.md`:

- Contains [UID:0001KM] at line 3375.
- Contains [UID:0003VB] at line 3378 and [UID:0003US] at line 3379.
- Does not contain [UID:0003UT] in the live report.
- `auto-generated/-ag-memory-coverage.md` does contain stale emitted rows for [UID:0003UR], [UID:0003US], [UID:0003UT], [UID:0003UU], and [UID:0003UW].

Insert the [UID:0003UT] row under [UID:0001KM] after [UID:0003US] and before later `0x005ac...` children, preserving low-to-high address order:

```markdown
        - [UID:0003UT][0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md) 0x005abda0-0x005abee8 | server packet handler | LivingObjectPaneHandleUIPanelSwitchPacket : reconstructable : 88% : very-strong : B004 2026-06-19 source-quality pass resolves UserPane::HandleServerMessage opcode `0x3e` / `'>'` as the only direct route to this LivingObjectPane handler, packet cursor `payload[1]` as the panel-switch action byte, `g_useEpfAssets`-selected EPF versus legacy payload tables for values `0..8`, GeneralPurposePanel tab switches for inventory index `2` and spell inventory index `3`, self-look child lookup through `g_pGeneralPurposePanel` index `0` with `SelfLookPane +0x232c` mode writes, BulletinSession lazy-open via `0x005a50a0` for action `6`, and ACK helper `0x005acfe0` sending opcode `0x2d` subtype `0` through `g_packetSender`/`QueueAndSendPacket` before self-look mode writes. Owner/emitter stay [UID:00007B] `LivingObjectPane`; GeneralPurposePanel, SelfLookPane, BulletinSession, Socket, `g_useEpfAssets`, and FrameChrome are dependencies; formal C++ remains blank until `0x005acfe0` and `SelfLookPane +0x232c` field names are source-quality.
```

Also add the compiler-data coverage row immediately after [UID:0003UT] if using ignored rows for switch tables:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005abee8-0x005abf30 | compiler switch tables | LivingObjectPane UI panel switch payload jump tables : ignored : 100% : strong : B004 2026-06-19 PE/Capstone check confirms two nine-entry dword jump tables used only by [UID:0003UT]: table A at `0x005abee8` is selected by `g_useEpfAssets == 1` at `0x005abdd2`, table B at `0x005abf0c` is selected by legacy mode at `0x005abe2c`, entries map payload action values `0..8` to in-function branch targets, and the next function prologue starts at `0x005abf30`.
```

If the supervisor later inserts [UID:0003UU], [UID:0003UV], and [UID:0003UW] rows into the same subtree, preserve this local order:

1. [UID:0003UT] `0x005abda0-0x005abee8`
2. ignored switch tables `0x005abee8-0x005abf30`
3. any existing/proposed rows for `0x005abf30-0x005abff2`, `0x005ac000-0x005ac061`, and alignment if those bodies are documented
4. [UID:0003UU] `0x005ac070-0x005ac1a8`
5. raw/helper rows around `0x005ac1b0-0x005ac280`
6. [UID:0003UW] `0x005ac280-0x005ac69b`

## Final Recommendation

Promote [UID:0003UT] to `88/90`, keep it owned/emitted by [UID:00007B] `LivingObjectPane`, and keep C++ blank until two support items are implemented:

- exact helper page for `0x005acfe0-0x005ad02c` as `LivingObjectPane::SendUIPanelSwitchAckPacket`;
- SelfLookPane support note or exact field documentation for `+0x232c`.

The old open questions are no longer generic future work:

- packet opcode is resolved as `0x3e`;
- action byte is resolved as `payload[1]`;
- `g_useEpfAssets` selects the two action tables;
- `GeneralPurposePanel` tab indices are resolved for inventory/spell inventory;
- direct route is proven by one rel32 call at `0x005a7ddc`;
- owner/source placement remains `LivingObjectPane.cpp`;
- compiler table bytes require a separate coverage row.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UT","source_path":"executed-b-agent-research/B004/0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
