** TARGET-REPORT-UID:0001MS **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MS SendWieldPacket Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: update [UID:0001MS] to a source-bearing private Wield packet helper with first-draft C++.
- Best direct owner: [UID:0000G4][WieldInputPane](../../../../../by-class/WieldInputPane.md).
- Source route: emit through [UID:0000G4] into [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md), generated as `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Best source-facing helper shape: `static int SendWieldPacket(unsigned char itemSlot)`, with the observed ABI recorded as `int __stdcall(char)` / `retn 4`.
- Best behavior summary: builds a 128-byte local packet scratch buffer, writes opcode `0x12`, writes one selected item-slot byte, writes a local-only terminator at packet byte `2`, and queues exactly two bytes through `Socket *g_packetSender`.
- Metadata recommendation: raise from `84/90` to `87/91`, keep `CANONICAL_OWNER:0000G4`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000G4`, and populate `RECONSTRUCTION_CPP CODE`.
- Final disposition: no split, no rename, no no-code proof. The old "blank because below 95/95" reasoning is stale under the active `(COMPLETION + CONFIDENCE) / 2 > 85` code-entry gate.

## Target
- Target UID: `0001MS`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b6500-0x005b6560.SendWieldPacket.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\0001MS-SendWieldPacket-source-quality.md`
- Current target metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000G4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G4`, blank C++.
- Current parent/gate state: [UID:0000G4] `WieldInputPane` is `86/90`, [UID:0000KC] `ItemActionInputPanes` is `90/85`, and the target's current average is already `87`. The route clears the active code-entry gate.

## Evidence Checked
- Rule sources: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `Agent-B012/goal.md`, `by-structure.md`, and `inference_research.md`.
- Target/support docs: target page, `WieldInputPane` by-class page, `0x005b62d0-0x005b64fa.WieldInputPane`, `ItemActionInputPanes`, `SendWearPacket`, `WearInputPane`, `g_packetSender`, `QueueAndSendPacket`, `PacketBufferScalarBigEndianWriteHelpers`, `g_activeUserStatusPane`, and `UserStatusPaneSummaryFields`.
- Exported function data: `resources/exported_data/functions/0x005b6500.json`, `0x005b6410.json`, `0x005b62d0.json`, `0x005b66a0.json`, `0x005b6760.json`, `0x00575380.json`, and `0x00574bb0.json`.
- Generated marker check: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` currently has empty emitter markers for `0000G4`, `0001MR`, and `0001MS`; target marker still shows `84/90`.
- Coverage check: `by-memory/-coverage-report.md` line for `0001MS` still records `84% : strong` and has no C++ readiness/current gate wording.
- Numeric conversions: `0x60` = 96, `0xea` = 234, `0xc7` = 199, `0x11` = 17, `0x12` = 18, `0x1e` = 30, `0x2d` = 45 (`'-'`), `0x41` = 65 (`'A'`), `0x5a` = 90 (`'Z'`), `0x61` = 97 (`'a'`), `0x7a` = 122 (`'z'`), `0x26` = 38, `0x34` = 52, `0x80` = 128, `0x284` = 644. Verified with `int_convert.py`.
- Live MCP status: direct MCP call to `127.0.0.1:13337/mcp` failed with "Unable to connect to the remote server" in this session. This report uses existing recorded live IDA evidence, exported function JSON, and current support docs. The key facts are internally consistent across those sources.

## Current Binary Facts
- IDA/exported target name: `sub_5B6500`; Ghidra name: `FUN_005b6500`.
- Exact range: `0x005b6500-0x005b6560`, size `0x60` / 96 bytes. Verified with `int_convert.py`.
- IDA signature: `int __stdcall(char)`. Ghidra signature: `undefined __stdcall FUN_005b6500(undefined1 param_1)`.
- Direct caller: exactly one recorded code ref, `0x005b64e6` inside `WieldInputPane::OnSubmitInput`.
- Callees: `0x00575380` packet byte writer, `0x00574bb0` queue/send wrapper, and security-cookie check.
- Decompiler body:

```cpp
int __stdcall sub_5B6500(char a1)
{
  char Src;
  _BYTE v3[127];

  sub_575380(18, &Src);
  sub_575380(a1, v3);
  v3[1] = 0;
  return sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2);
}
```

- Boundary evidence already recorded in the target/support docs: six bytes of `0xcc` padding at `0x005b64fa-0x005b6500`; `WearInputPane` starts cleanly at `0x005b6560`.
- The helper does not read `ecx`; it is not a virtual or ordinary instance method.

## Caller / Reachability
- The sole caller is [UID:0001MR] `WieldInputPane::OnSubmitInput` at `0x005b64e6`.
- Caller behavior:
  - Requires exactly one typed input character through inherited `CharInputPane` helpers.
  - `'-'` (`0x2d` / 45 decimal) sends opcode `0x12` with selector `0` inline, not through this helper. Verified with `int_convert.py`.
  - Lowercase `a-z` (`0x61-0x7a`) maps to selectors `1-26`.
  - Uppercase `A-Z` (`0x41-0x5a`) maps to selectors `27-52` by subtracting `0x26` / 38. Verified with `int_convert.py`.
  - The normal mapped selector must be between `1` and `*(g_activeUserStatusPane + 0x284)`.
  - Only the normal validated slot path calls this helper.
- `UserStatusPaneSummaryFields` names `+0x284` as the inventory slot count / maximum item-slot selector byte. It is initialized to `52` (`0x34`) and read by Wield, Wear, Throw, Use, Eat, ChangeItemSlot, and MyItemListPane flows. Verified with `int_convert.py`.
- The target is reachable through a normal vtable method call into `WieldInputPane::OnSubmitInput`; it is not dead raw padding and not an unreferenced sibling helper.

## Packet / Protocol Behavior
- Outbound packet bytes sent by this helper: `[0x12, itemSlot]`, length `2`.
- Opcode `0x12` is the Wield item/weapon command in this item-action outgoing packet family. It should not be conflated with the unrelated inbound/server `0x12` enum namespace in `MapServerPacketOpcode.md`.
- The `'-'` branch in `WieldInputPane::OnSubmitInput` sends the same opcode `0x12` with selector `0`. Best interpretation: clear/unwield/no selected weapon selector path.
- Sibling Wear behavior uses opcode `0x1e` (`30` decimal), not `0x12`; target-specific evidence and `g_packetSender` support docs both record Wield `0x12` and Wear `0x1e`. Verified with `int_convert.py`.
- Existing `SendWearPacket` touched-state text has a stale typo saying the neighboring Wield helper sends opcode `0x18`. That should be corrected to `0x12`.
- The third local byte (`packet[2]`) is a scratch terminator/safety byte outside the counted packet payload. `QueueAndSendPacket` receives length `2`.

## Helper / Global / Type Resolution
- `sub_575380` is already documented by [UID:0003YJ] as `PacketBufferWriteUInt8`.
  - Observed ABI/source type to use in IDA: `char __cdecl PacketBufferWriteUInt8(unsigned char value, unsigned char *out)`.
  - It writes one payload byte and a spare zero byte immediately after it. The spare zero is not part of the send length.
- `sub_574BB0` is already documented by [UID:0001HU] as `Socket::QueueAndSendPacket`.
  - Observed IDA signature: `int __thiscall(_BYTE *this, void *Src, __int16 packetSize)`.
  - Source-facing call should be `g_packetSender->QueueAndSendPacket(packet, 2)`.
  - It copies `packetSize` bytes, appends a terminator in the queued copy, and dispatches Socket command `8`.
- `dword_67A7EC` is [UID:0000Q5] `g_packetSender`.
  - Best current source-facing type: `Socket *`.
  - Do not use generated `g_pCashShopRequest`, `DAT_0067a7ec`, or `dword_67A7EC` as final target names. The real `g_pCashShopRequest` storage is separate at `0x0067a738`.
- `dword_69AE0C` is [UID:0000PS] `g_activeUserStatusPane`.
  - For this caller, `+0x284` is best described as `m_inventorySlotCount` or `m_itemSlotCount`; exact original field spelling is not proven.
- Inherited `CharInputPane` helpers at `0x004f2310` and `0x004f2300` remain support-level final-name caveats. Best contextual roles are input length/count check and one-character copy/read, respectively. They do not block target C++ because the target helper does not call them directly.

## Heuristic / Inference Reanalysis And Validation
- Source-bearing versus no-code:
  - Evidence checked: exact IDA-modeled function, real caller, packet send body, non-padding boundaries, reconstructable metadata, and valid emitter chain.
  - Decision: source-bearing code. This is not compiler glue and not a no-code item.
  - Impact: populate first-draft C++. The old below-95 no-code/blank-C++ explanation should be removed.
- Helper name and placement:
  - Evidence checked: target title, caller flow, Wield class page, ItemActionInputPanes file grouping, sibling Wear packet helper, opcode family, and one-caller xref.
  - Best name: `SendWieldPacket`.
  - Best source shape: private file-scope/static helper near `WieldInputPane` code, emitted under the WieldInputPane route. It can be documented as a static-style private helper owned by `WieldInputPane`, not as a virtual instance method.
  - Rejected alternatives: `sub_5B6500`/`FUN_005b6500` because support docs resolve the role; `WearInputPane` ownership because Wear starts at `0x005b6560`; central `ProtocolSend` ownership because the only business owner is the Wield prompt; `Socket`/`PacketBuffer` ownership because those are utility callees.
- Signature and return type:
  - Evidence checked: IDA `int __stdcall(char)`, `retn 4`, caller assigning the low byte of the helper result, and sibling inline `'-'` path assigning the low byte of `QueueAndSendPacket`.
  - Best source-facing signature: `static int SendWieldPacket(unsigned char itemSlot)`.
  - ABI note: IDA type should preserve `__stdcall` if the database tracks calling convention. Source may omit it if the project default calling convention explains the `retn 4`.
  - Rejected alternatives: `void` because the IDA body returns the queue/send result and the caller consumes the low byte; member `WieldInputPane::SendWieldPacket` non-static because the body does not read `this`.
- Packet opcode and protocol name:
  - Evidence checked: target body, caller inline zero-selector branch, sibling Wear body, `g_packetSender` examples, and `MapServerPacketOpcode` namespace conflict.
  - Best descriptive protocol name: `WieldItem` / `WieldItemOpcode` for outbound item-action command byte `0x12`.
  - Rejected alternatives: stale `0x18`, inbound server `0x12`, logout/quit interpretation of `'-'`, or Wear opcode conflation.
- Buffer ownership and size:
  - Evidence checked: target stack locals `char Src` + `_BYTE v3[127]`, packet helper zeroing behavior, and `QueueAndSendPacket` copy/terminator behavior.
  - Best source buffer shape: local `unsigned char packet[128]`; writes to bytes `0`, `1`, and local terminator byte `2`; sends length `2`.
  - Rejected alternatives: heap-owned buffer, global packet buffer, or sent NUL-terminated string packet. No caller or callee owns the stack buffer after return.
- WieldInputPane ownership/callers:
  - Evidence checked: single direct caller at `0x005b64e6`, Wield constructor/vtable docs, prompt id `13`, slot conversion, and boundary before Wear.
  - Decision: owner/emitter remains `0000G4`. This is stronger than assigning directly to the file parent because the helper is only used by Wield behavior.
- Source file route:
  - Evidence checked: [UID:0000KC] proposed source file and contents table, generated marker file, Wield/Wear/Drop/Give/Throw/Eat sibling grouping.
  - Decision: route through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`; no new source file, split, or module move.
- Generated-name cleanup:
  - Evidence checked: support docs for packet writer, queue/send, global sender, active user status pane, and caller docs.
  - Decision: target/support docs should not leave `sub_575380`, `sub_574BB0`, `dword_67A7EC`, `dword_69AE0C`, `DAT_0067a7ec`, or `CashShopRequest` as unresolved final names for this target.
- Open questions:
  - Exact original enum/constant spelling for opcode `0x12` remains unproven. Use literal `0x12` in the first draft and prose name `WieldItem`/`WieldItemOpcode`.
  - Exact original field spelling for `UserStatusPane +0x284` remains unproven. Use role wording `inventory slot count / maximum item-slot selector`.
  - Exact original helper declaration may have used project default calling convention instead of an explicit `__stdcall`. Preserve the ABI in IDA notes; keep source draft readable.
  - These are naming polish questions, not blockers for code entry.

## First-Draft C++ Recommendation
Populate [UID:0001MS] `RECONSTRUCTION_CPP CODE` with this source-style draft:

```cpp
static int SendWieldPacket(unsigned char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x12, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 2);
}
```

Source-shape notes:
- The local `packet[128]` mirrors the observed stack scratch span; using `packet[3]` would be behaviorally enough but less faithful to the compiled source shape.
- Keep `PacketBufferWriteUInt8` calls rather than simplifying to direct byte assignments, because the binary calls the shared out-of-line helper twice.
- The literal `0x12` can later become a coordinated protocol constant if the item-action opcode enum is recovered.
- If the project style requires explicit calling conventions for file-local helpers, use `static int __stdcall SendWieldPacket(unsigned char itemSlot)` without changing the body.

## Exact Metadata / Target Doc Recommendations
Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000G4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000G4
RECONSTRUCTION_CPP CODE: populate with the first-draft C++ above
```

Recommended target status additions/replacements:

```text
- Entity kind: private Wield packet-send helper.
- Best source-facing shape: file-scope/static helper `static int SendWieldPacket(unsigned char itemSlot)`; observed ABI is `int __stdcall(char)`.
- Likely source module: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), emitted through [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md) into `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Helper dependencies: [UID:0003YJ] `PacketBufferWriteUInt8`, [UID:0001HU] `Socket::QueueAndSendPacket`, and [UID:0000Q5] `Socket *g_packetSender`.
- Behavior: writes outbound Wield opcode `0x12` (18 decimal, Verified with int_convert.py), writes one validated inventory slot selector, writes a local-only scratch terminator, and sends exactly two bytes.
- Caller context: [UID:0001MR] `WieldInputPane::OnSubmitInput` validates slot letters against [UID:0000PS] `g_activeUserStatusPane +0x284` before calling this helper; the `'-'` zero-selector path sends opcode `0x12`, selector `0`, inline.
```

Recommended target reconstruction-note replacement:

```text
- `RECONSTRUCTABLE:TRUE` because this is NexusTK-owned packet-send source code required by the Wield input path.
- The active C++ code-entry gate is satisfied: target is reconstructable, emitter route `0000G4` is nonblank and surfaces through `ItemActionInputPanes.cpp`, and the target score average is above 85. The prior blank-C++ explanation based on a `95/95` gate is stale.
- Remaining uncertainty is limited to original enum/constant spelling for opcode `0x12`, exact `UserStatusPane +0x284` field spelling, and whether the project source wrote an explicit `__stdcall` keyword. These do not block first-draft C++.
```

## Exact Support-Doc Recommendations
- [UID:0000G4] `WieldInputPane`: keep owner/file route, but replace stale below-95 C++ wording with current-gate wording for the helper. Add that [UID:0001MS] is code-ready and should emit through the Wield route.
- [UID:0001MR] `0x005b62d0-0x005b64fa.WieldInputPane`: update the adjacent-helper and reconstruction notes to say the helper now has first-draft C++ readiness under the active gate; keep the class cluster C++ decision separate if broader constructor/input handler names still need review.
- [UID:0000KC] `ItemActionInputPanes`: update the proposed contents row for Wield to reference [UID:0001MS] as a code-ready private helper with outbound opcode `0x12` and first-draft source route through `WieldInputPane`.
- [UID:0002YP] `0x005b6760-0x005b67c0.SendWearPacket`: fix the stale touched-state typo for [UID:0001MS]. Exact replacement row:

```text
| [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) | Previous packet helper | Neighboring wield helper sends opcode `0x12` with a validated slot selector from the preceding `WieldInputPane` group. |
```

- [UID:0000Q5] `g_packetSender`: no required factual change; it already records Wield `0x12`, selector `0` inline, helper `0x005b6500`, Wear `0x1e`, and `Socket *` type. It can optionally link this source-quality report if supervisor wants traceability.
- [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`: no required change. If implementation touches type recommendations, preserve value-first target ABI for `PacketBufferWriteUInt8` as `unsigned char value, unsigned char *out`.

## Exact by-memory Coverage Replacement Row
Supervisor-owned replacement for the current [UID:0001MS] row in `by-memory/-coverage-report.md`; B012 did not edit the file:

```text
    - [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) 0x005b6500-0x005b6560 | private helper | SendWieldPacket : reconstructable : 87% : very strong : B012 2026-06-19 source-quality reanalysis confirms the WieldInputPane-owned normal validated-slot packet helper: exact 0x60 / 96-byte function, single caller at 0x005b64e6, no ecx read, int __stdcall(char) one-argument helper ABI, six-byte 0xcc pre-padding and clean WearInputPane boundary at 0x005b6560, opcode 0x12 (18 decimal, Verified with int_convert.py) plus selector byte, local-only scratch terminator, two-byte send length, PacketBufferWriteUInt8, Socket *g_packetSender / QueueAndSendPacket, UserStatusPane +0x284 slot-count validation in the caller, source route through WieldInputPane -> ItemActionInputPanes.cpp, and first-draft C++ readiness under the active combined-score/emitter gate.
```

## IDA Rename / Type / Comment Recommendations
- Rename `sub_5B6500` to `SendWieldPacket`.
- Apply/record target type: `int __stdcall SendWieldPacket(unsigned char itemSlot)`.
- Comment at target start: `Builds outbound Wield item packet {0x12, itemSlot}; caller validates itemSlot; '-' / selector 0 path is sent inline by WieldInputPane::OnSubmitInput.`
- Rename/type packet byte writer if not already applied: `PacketBufferWriteUInt8(unsigned char value, unsigned char *out)`.
- Rename/type queue send if not already applied: `int Socket::QueueAndSendPacket(const void *packet, short packetSize)`.
- Rename/type sender global if not already applied: `Socket *g_packetSender` at `0x0067a7ec`.
- Add caller comment at `0x005b64e6`: `Validated normal Wield slot path; SendWieldPacket sends opcode 0x12 with selector 1..m_itemSlotCount.`
- Add field comment at `g_activeUserStatusPane +0x284`: `inventory slot count / maximum item-slot selector byte` (exact source spelling unresolved).

## Validation Commands Needed After Implementation
Run file-mode validation for every edited by-* doc, then refresh generated output/coverage:

> Executable block R001 was removed from this report and preserved verbatim in [0001MS-SendWieldPacket-source-quality-removed.md](0001MS-SendWieldPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the banned coverage-row replacement separately, validate that file under supervisor ownership:

> Executable block R002 was removed from this report and preserved verbatim in [0001MS-SendWieldPacket-source-quality-removed.md](0001MS-SendWieldPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\0001MS-SendWieldPacket-source-quality.md`
- Modified: none outside Agent-B012 research.
- Not edited: target by-memory doc, support by-* docs, generated output, and `by-memory/-coverage-report.md`.

## Confidence
- Recommendation confidence: high for behavior, range, caller, owner/emitter route, packet helper/global names, and C++ readiness.
- Remaining uncertainty: exact original constant spelling for opcode `0x12`, exact original spelling of the `UserStatusPane +0x284` field, and whether the source explicitly spelled `__stdcall`. These are not blockers.
- Score confidence: `87/91` is justified by exact binary behavior and resolved helper/global names while staying below final-audit scores because original source spelling is inferred/descriptive rather than symbol-proven.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001MS-SendWieldPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0001MS"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MS-SendWieldPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0001MS-SendWieldPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
