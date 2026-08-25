** TARGET-REPORT-UID:00002A **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00002A] ClanDepMoneyInputDialog source-quality report

Report-only B-agent pass for:

- Target: `source-3/project-documentation/by-class/ClanDepMoneyInputDialog.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/00002A-ClanDepMoneyInputDialog-source-quality.md`
- Status: report created only. No target/support by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Final Recommendation

Keep [UID:00002A] as the direct class owner for the deposit-money modal dialog, keep the current Clan source route, raise the class page from `84/88` to `86/90`, and keep formal class-level C++ blank with a target-specific no-code proof.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000I8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I8
```

Recommended source route:

```text
NexusTK/social/Clan.cpp
```

[UID:0000IA] `ClanDialogs` remains a useful split candidate, but it is not the current direct emitter. [UID:0000I8] `Clan` is still the stronger current source owner because it owns the clan status pane, packet dispatcher, modal dialog family, opcode `0x4b` helper strip, modal vtables, and current generated route.

Class-level formal C++ should remain blank for this target. The exact submitter child [UID:0002NS] already emits the method body, and the raw constructor child [UID:00021V] remains constructor-shaped source evidence with no proven entry route. A class declaration/constructor shape is now defensible for documentation, but not safe as final class-page emission until the project settles class/header emission and the `Clan.cpp` versus `ClanDialogs.cpp` split.

## Evidence Checked

- Read target [UID:00002A] `by-class/ClanDepMoneyInputDialog.md`.
- Read child pages:
  - [UID:00021V] `0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor`
  - [UID:0002NS] `0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney`
  - [UID:00021I] `0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers`
  - [UID:00010K] `0x00488fe0-0x004895fe.ClanNameDialogSubmitters`
- Read support docs:
  - [UID:0000I8] `Clan`
  - [UID:0000IA] `ClanDialogs`
  - [UID:00002J] `ClanNameInputDialog`
  - [UID:00002O] `ClanWidMoneyInputDialog`
  - [UID:0002NT] `ClanWidMoneyInputDialogRawConstructor`
  - [UID:0002NU] `ClanWidMoneyInputDialogSubmitWithdrawMoney`
  - [UID:0001X9] `ClanDialogVtableFamily`
  - [UID:0003HE] `ClanModalDialogVtables`
  - [UID:0001TY] `ClanInputDialogLayouts`
  - [UID:00010J] `ClanNameInputDialogCore`
  - [UID:00021C] `ClanStatusPacketDispatcher`
  - [UID:00021S] `ClanStatusPacketDialogHandlers`
  - [UID:0001HZ] `PacketBufferHelpers`
  - [UID:0001HU] `QueueAndSendPacket`
  - [UID:0001P0] `g_packetSender`
- Read prior B001 reports:
  - `0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`
  - `older/00021D-00021J-clan-opcode4b-packet-helper-source-quality.md`
  - `older/0002NX-0002O1-clan-name-raw-constructor-source-placement.md`
- Checked current `by-memory/-coverage-report.md` child rows and current `by-class/-coverage-report.md` target row.
- Performed read-only PE/Capstone checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Attempted IDA MCP at `http://127.0.0.1:13337/mcp`; current result was `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Verified number conversions with `tools/int_convert.py` for `0x26c`, `0x35`, `0x82`, `0x80`, `0x4b`, `0x04`, `0x0b`, `0xa0`, `0xa4`, and `0x5c`.

## Target Findings

### Class Role

`ClanDepMoneyInputDialog` is a `ClanNameInputDialog` derivative for clan-bank money deposit submission. It has no proven unique data fields beyond inherited dialog state; the class identity is carried by derived vtables and the `OnSubmitText` override.

Best source-facing declaration shape, for documentation:

```cpp
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);
    int OnSubmitText(const wchar_t *text) override;
};
```

Best source-facing constructor shape, for documentation:

```cpp
ClanDepMoneyInputDialog::ClanDepMoneyInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

This constructor shape is strong because both the raw constructor-shaped body and active inline construction sites pass one stack argument into `ClanNameInputDialog::ClanNameInputDialog`. The base constructor [UID:00010J] reads the argument as packet bytes: prompt length at `packet+3` and prompt bytes at `packet+4`. Therefore the constructor argument should be `const unsigned char *packet` or an eventual clan packet wrapper type, not an integer id.

### Raw Constructor `0x00488fa0`

Range:

```text
0x00488fa0-0x00488fd5
```

Local PE/Capstone reconfirms:

```text
0x00488fa0  push ebp
0x00488fa5  push dword ptr [ebp+8]
0x00488fad  call 0x00488b40
0x00488fb2  mov dword ptr [esi], 0x00615998
0x00488fba  mov dword ptr [esi+0xa0], 0x006159fc
0x00488fc4  mov dword ptr [esi+0xa4], 0x00615a2c
0x00488fd2  ret 4
0x00488fd5-0x00488fe0  eleven 0xcc alignment bytes
```

The body is real constructor-shaped project code:

- Saves `this` in `ESI`.
- Forwards the stack argument to `ClanNameInputDialog::ClanNameInputDialog` at `0x00488b40`.
- Installs the `ClanDepMoneyInputDialog` primary vtable at `+0x00`.
- Installs secondary/tertiary vtable views at `+0xa0` / 160 and `+0xa4` / 164, verified with `int_convert.py`.
- Returns `this` and cleans one stack argument.

Reachability remains unresolved in the negative direction:

- Current target docs and prior live IDA checks report no function object at `0x00488fa0`.
- Current target docs and prior live IDA checks report no xrefs, pointer-byte matches, immediate matches, or data-reference matches for the raw start.
- B004 local PE scan found zero absolute VA hits, zero RVA hits, and zero rel32 `call`/`jmp`/conditional-branch hits to `0x00488fa0`.
- B004 local PE scan found zero absolute VA/RVA/rel32 hits to the padding boundary `0x00488fd5`.

This does not make the bytes compiler glue or padding. It means the raw constructor should remain class-owned, reconstructable evidence, but formal constructor C++ should not be emitted from [UID:00021V] or the class page until a route/source-shape decision is accepted.

### Active Construction Sites

B004 local PE scan found the expected vtable-store references for `ClanDepMoneyInputDialog`:

| Vtable | Store instruction sites |
| --- | --- |
| `0x00615998` primary | `0x00485120`, `0x00487de4`, `0x00488fb2` |
| `0x006159fc` secondary | `0x00485126`, `0x00487dea`, `0x00488fba` |
| `0x00615a2c` tertiary | `0x00485130`, `0x00487df4`, `0x00488fc4` |

The first two groups are active inline construction contexts:

- `0x0048511b` calls `ClanNameInputDialog::ClanNameInputDialog`, then `0x00485120/0x00485126/0x00485130` write the derived vtables.
- `0x00487ddf` calls `ClanNameInputDialog::ClanNameInputDialog`, then `0x00487de4/0x00487dea/0x00487df4` write the derived vtables.

This proves live construction behavior without proving a live call to raw start `0x00488fa0`. The best source inference is retained out-of-line constructor-shaped code plus inline construction sites that duplicate the same sequence.

### Submitter `0x00488fe0`

Range:

```text
0x00488fe0-0x00489062
```

B004 local PE scan found exactly one absolute reference to the active submitter: vtable slot `0x006159f4`.

Source-facing signature:

```cpp
int ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *text)
```

Evidence:

- [UID:00010J] `ClanNameInputDialog::OnButtonClick` reads control id `4` and dispatches primary vtable slot `+0x5c` / 92, verified with `int_convert.py`.
- The slot for this derived class is `0x006159f4 -> 0x00488fe0`.
- No direct code callers are expected because this is a virtual submit callback.
- [UID:0002NS] already emits this method body after B001 source-quality execution.

Observed behavior:

- Stack argument `[ebp+8]` is the submitted wide text pointer.
- Calls CRT `_wtol` / `__wtol` at `0x005cea43` to convert the amount.
- Writes opcode `0x4b` / 75 / ASCII `K`, subtype `0x04` / 4, and action `0x01` through `PacketBufferWriteUInt8`.
- Writes the amount through `0x005753f0`, now documented as `PacketBufferWriteUInt32BE`.
- Loads `g_packetSender` from `0x0067a7ec`, best typed as `Socket *`.
- Calls `0x00574bb0` / `Socket::QueueAndSendPacket` with length `7`.

Source detail worth adding to docs if implementation touches [UID:0002NS]: the binary reserves a `0x80` / 128-byte local packet buffer, verified with `int_convert.py`, even though only seven bytes are sent. The accepted B001 first-draft `unsigned char packet[8]` is behavior-equivalent, but a source-family-faithful draft may prefer `unsigned char packet[128]` to match the clan name-submitters' fixed packet buffer pattern.

### Retained Raw Helper Mirror [UID:00021I]

[UID:00021I] is not the class method.

It contains raw subtype `4` helpers:

- Action `0`: `{ 0x4b, 4, 0 }`, three-byte dialog request.
- Action `1`: `{ 0x4b, 4, 1, uint32 amount }`, seven-byte amount submit.

The action `1` body mirrors the active [UID:0002NS] submitter packet shape, but B001 and current B004 checks support the retained/no-route helper model:

- No IDA function objects or inbound xrefs to the raw helper starts.
- No PE exact-start VA/RVA/rel32 route hits to `0x00485780` or `0x004857f0`.
- The active class submitter is vtable-backed at `0x00488fe0`.

Recommended wording: [UID:00021I] is a retained/no-route `Clan.cpp` helper mirror of deposit-money request/submit behavior; it should not be used as evidence to move or rename the class method.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best decision | Evidence | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Class source owner | Keep [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp` | Clan page owns modal dialog family, opcode `0x4b` helper strip, status dispatcher, modal vtables; current class route already clears gate. | Do not switch to [UID:0000IA] `ClanDialogs` yet; it is a documented split candidate, not stronger current owner. Do not route through [UID:00010K] aggregate. |
| Constructor argument | `const unsigned char *packet` or eventual clan packet wrapper | Raw ctor forwards `[ebp+8]` to base; [UID:00010J] base reads prompt length at `packet+3` and prompt bytes at `packet+4`. | Reject `int clanId` / `parentPaneId` style names for this class; the argument is byte-buffer input, not an id. |
| Raw constructor liveness | Retained out-of-line constructor-shaped body, no proven raw-entry route | Local PE scan: zero VA/RVA/rel32 hits to `0x00488fa0`; docs report no IDA function/xrefs/pointer matches. | Do not ignore as padding/compiler glue; body has source-authored constructor semantics. Do not emit as final constructor body yet. |
| Active construction | Inline construction sites duplicate ctor sequence | Stores at `0x00485120/26/30` and `0x00487de4/ea/f4` after base constructor call. | Do not claim the raw constructor is the live construction entry. |
| Submit virtual name | `OnSubmitText(const wchar_t *text)` | Base slot `+0x5c`, sibling B001 report, active vtable slot `0x006159f4`. | `SubmitDepositMoney` remains a role/page label, not the shared virtual name. |
| `_wtol` helper | CRT `_wtol` / `__wtol` | B001 and current child docs identify `0x005cea43`; submitter passes text pointer. | Reject product helper names like `ConvertSubmittedAmount`. |
| Amount writer | `PacketBufferWriteUInt32BE` | [UID:0001HZ] split and [UID:0002NS] current doc; money packet offsets `+3..+6` are big-endian. | Reject stale little-endian wording and raw `sub_5753F0` as final name. |
| Sender/global | `g_packetSender`, best current type `Socket *` | [UID:0001P0] documents Socket-owned lifetime; [UID:0001HU] documents `QueueAndSendPacket`. | Reject generated `CashShopRequest *` aliases for this class. |
| Vtable family labels | `ClanDepMoneyInputDialog` primary/secondary/tertiary views | Decorated modal vtable family docs, store refs, and submit slot data ref. | Do not collapse into broad [UID:0001X9] mixed aggregate; exact modal child [UID:0003HE] carries the source-local vtable route. |
| Class-level C++ | Keep formal block blank; document review-only declaration/ctor shape | Child [UID:0002NS] emits method body; raw constructor child is no-code; class/header emission policy not settled. | Emitting a class declaration in `Clan.cpp` now may duplicate/invalidate child method placement and overclaim header/source split. |

## First-Draft C++ Policy

The method-level first draft is already in [UID:0002NS]:

```cpp
int ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[8];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x04);
    PacketBufferWriteUInt8(packet + 2, 0x01);
    PacketBufferWriteUInt32BE(packet + 3, amount);
    packet[7] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 7);
}
```

For this class page, do not populate formal `RECONSTRUCTION_CPP CODE` yet. Target-specific no-code proof:

- The class page is an ownership/declaration summary, not the exact body page for `OnSubmitText`.
- The exact method body is already emitted by [UID:0002NS], which is the narrowest executable-range owner.
- The constructor-shaped raw child [UID:00021V] has no current raw-entry route and should not emit standalone constructor C++.
- The active construction behavior occurs inline at open sites, so emitting a class-page constructor body would overstate the raw constructor's liveness unless the source model intentionally treats retained out-of-line constructor bodies as emitted source.
- A correct class declaration likely belongs in a header or class-declaration emission policy shared by the clan modal dialog family. The current by-class route emits into `Clan.cpp`, and inserting a declaration without coordinated `[[CHILDREN]]` placement risks generated-output pollution.

If the supervisor later chooses to emit class declarations from by-class pages, use the review-only shape shown in the Target Findings section, preferably with the child method bodies emitted after the declaration rather than inside it.

## Recommended Target Doc Changes

Recommended exact changes for `by-class/ClanDepMoneyInputDialog.md`:

- Change scores to `COMPLETION:86`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000I8`.
- Replace "class-level C++ remains blank because the raw constructor/class declaration is not final" with the target-specific no-code proof above.
- Add source-facing class/constructor shape:

```cpp
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);
    int OnSubmitText(const wchar_t *text) override;
};
```

```cpp
ClanDepMoneyInputDialog::ClanDepMoneyInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

- In the raw constructor method note, state that the stack argument is packet bytes forwarded to the base constructor, not an integer.
- Add B004 current PE evidence:
  - zero VA/RVA/rel32 route hits to `0x00488fa0`;
  - active submitter absolute reference only at vtable slot `0x006159f4`;
  - derived vtable stores at active inline sites `0x00485120/0x00485126/0x00485130` and `0x00487de4/0x00487dea/0x00487df4`, plus raw constructor stores at `0x00488fb2/0x00488fba/0x00488fc4`.
- In the submitter method note, keep `OnSubmitText(const wchar_t *text)`, `_wtol`, opcode `0x4b`, subtype `4`, action `1`, `PacketBufferWriteUInt32BE`, `g_packetSender`, and seven-byte send.
- Add or preserve the [UID:00021I] mirror note: action `1` helper mirrors the live submitter but is retained/no-route and not the class method.
- Add a 2026-06-19 B004 change note explaining this source-quality pass and why class-level formal C++ remains blank.

## Recommended Support-Doc Changes

Only update support docs if the accepted implementation compares them and finds missing or contradicted details.

### [UID:00021V] Raw constructor

Recommended if touched:

- Update the constructor argument wording from "single argument" to "single packet pointer argument forwarded to `ClanNameInputDialog::ClanNameInputDialog`."
- Add B004 PE evidence: zero VA/RVA/rel32 hits to `0x00488fa0`; active inline construction stores at `0x00485120` and `0x00487de4`.
- Keep formal C++ blank.

### [UID:0002NS] Submitter

Recommended if touched:

- Preserve current formal C++ and `OnSubmitText(const wchar_t *text)` naming.
- Optional source-family note: the binary reserves a `0x80` / 128-byte local packet buffer even though the sent length is seven bytes. The current `packet[8]` formal draft is behavior-equivalent; `packet[128]` may better match sibling submitter source style if the project later normalizes local buffer sizes.

### [UID:0000I8] Clan

Recommended if touched:

- Add that `ClanDepMoneyInputDialog` constructor parameter is packet bytes from the clan packet dispatcher/open path.
- Keep `ClanDepMoneyInputDialog` under the current social/Clan modal-dialog family and retain [UID:0000IA] only as split candidate.

### [UID:0000IA] ClanDialogs

Recommended if touched:

- Add no route change; this remains a split candidate. The current direct route for [UID:00002A] remains [UID:0000I8].

### [UID:0001TY] ClanInputDialogLayouts

Recommended if touched:

- Add [UID:00002A] as another explicit no-unique-fields derived class: it uses inherited `ClanNameInputDialog` control-host/text submission behavior and only overrides `OnSubmitText`.

### [UID:0003HE] ClanModalDialogVtables

Recommended if touched:

- Under `ClanDepMoneyInputDialog`, call out primary vtable slot `+0x5c` / 92 as `OnSubmitText(const wchar_t *)`, with data entry `0x006159f4 -> 0x00488fe0`.

## Coverage Report Text

No `by-memory/-coverage-report.md` replacement is needed for this class-only report. The relevant child memory rows for [UID:00021V], [UID:00010K], and [UID:0002NS] already reflect the current B001/C001 state and should stay unchanged unless the supervisor accepts a child-page implementation change.

If the supervisor updates class coverage, replace the [UID:00002A] row in `by-class/-coverage-report.md` with:

```text
- [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md) : reconstructable : 86% : very strong : B004 source-quality recheck keeps the Clan/social owner route, resolves the constructor parameter as `const unsigned char *packet` forwarded to `ClanNameInputDialog`, confirms local PE zero VA/RVA/rel32 route hits to raw constructor start `0x00488fa0`, one active submitter vtable data ref at `0x006159f4`, inline construction stores at `0x00485120`/`0x00487de4` plus raw constructor stores at `0x00488fb2`, submit slot `+0x5c` as `OnSubmitText(const wchar_t *)`, CRT `_wtol` amount conversion, big-endian `PacketBufferWriteUInt32BE`, seven-byte queued send through Socket-owned `g_packetSender`, retained [UID:00021I] mirror as no-route helper not class method, and target-specific class-level no-code proof because the child method emits while raw constructor/header declaration emission remains not final-source safe.
```

## Validation Commands Needed

No validator was run in this report-only pass because no by-* docs were edited.

If accepted for implementation, run from `source-3/project-documentation` for each touched file:

> Executable block R001 was removed from this report and preserved verbatim in [00002A-ClanDepMoneyInputDialog-source-quality-removed.md](00002A-ClanDepMoneyInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run these only if the corresponding support docs are touched:

> Executable block R002 was removed from this report and preserved verbatim in [00002A-ClanDepMoneyInputDialog-source-quality-removed.md](00002A-ClanDepMoneyInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Coverage rows are supervisor-owned. If class coverage is updated, validate:

> Executable block R003 was removed from this report and preserved verbatim in [00002A-ClanDepMoneyInputDialog-source-quality-removed.md](00002A-ClanDepMoneyInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not edit `by-memory/-coverage-report.md` for this report.

## IDA Rename / Type / Comment Recommendations

Recommended IDA actions:

| Target | Recommendation | Confidence |
| --- | --- | ---: |
| `0x00488fa0` | Do not create a normal IDA function solely to improve display; add a comment if possible: `unreferenced retained ClanDepMoneyInputDialog constructor-shaped body` | High |
| `0x00488fa0` future type if function is later created | `ClanDepMoneyInputDialog *__thiscall ClanDepMoneyInputDialog::ClanDepMoneyInputDialog(const unsigned char *packet)` | Medium-high |
| `0x00488fe0` | Prefer source name `ClanDepMoneyInputDialog::OnSubmitText`; keep role alias `SubmitDepositMoney` in comments/search labels | High |
| `0x00488fe0` type | `int __thiscall ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *text)` | High |
| `0x006159f4` | Comment vtable slot as `OnSubmitText(const wchar_t *) -> 0x00488fe0` | High |
| `0x005cea43` | CRT `_wtol` / `__wtol` | High |
| `0x00575380` | `PacketBufferWriteUInt8` | High |
| `0x005753f0` | `PacketBufferWriteUInt32BE` | High |
| `0x00574bb0` | `Socket::QueueAndSendPacket` / queued packet send wrapper | High |
| `0x0067a7ec` | `g_packetSender`, current type `Socket *` with sender-interface caveat | High |
| `0x00485120` and `0x00487de4` | Comment as inline `ClanDepMoneyInputDialog` construction after `ClanNameInputDialog` base constructor call | High |
| `0x00485780` / `0x004857f0` | Retained helper labels `SendClanDepositMoneyDialogRequestPacket` and `SendClanDepositMoneySubmitPacket(uint32_t amount)` if modeled; keep no-route caveat | Medium-high |

Remaining uncertainty:

- Exact original header placement for the class declaration remains open.
- Exact original spelling of the packet pointer type remains open; `const unsigned char *packet` is the strongest current descriptive type.
- Exact class-page emission mechanics for declarations and child method insertion are not settled; this is why formal class C++ should remain blank.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00002A-ClanDepMoneyInputDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00002A"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00002A-ClanDepMoneyInputDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00002A-ClanDepMoneyInputDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00002A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
