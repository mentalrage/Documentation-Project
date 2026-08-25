** TARGET-REPORT-UID:0001M2 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B006 Source-Quality Report: UID 0001M2 - SendTakeOffPacket

Assignment: `B006 new report-only assignment`, target [UID:0001M2].

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b27c0-0x005b2827.SendTakeOffPacket.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0001M2-SendTakeOffPacket-source-quality.md`

Report-only result: no by-* documentation files and no `by-memory/-coverage-report.md` edits were made.

## Finalized Report / Current Recommendation

Current recommendation:

- Keep [UID:0001M2] as a source-authored free helper named `SendTakeOffPacket`.
- Keep `CANONICAL_OWNER:0000KC` and `EMITTER_UIDS:0000KC`.
- Keep generated route `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Raise target metadata from `85/87` to `89/90`.
- Populate first-draft C++ in the implementation callback.

Best-supported source-facing signature:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector);
```

First-draft C++ recommendation:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector)
{
    char packet[128];

    if (g_activeDialogCount <= 0) {
        PacketBufferWriteUInt8(0x1f, packet);
        PacketBufferWriteUInt8(equipmentSlotSelector, packet + 1);
        packet[2] = 0;
        g_packetSender->QueueAndSendPacket(packet, 2);
    }
}
```

This should be emitted as a file-level helper, not as `TakeOffInputPane::SendTakeOffPacket` and not as `SelfLookPane::SendTakeOffPacket`. Because `SelfLookPane::OnMouseClick` calls the helper from a different source family, the eventual source tree needs a shared declaration in an item-action/equipment command header or equivalent. The implementation body still belongs with `ItemActionInputPanes.cpp` under the current reconstructed source tree.

## Evidence Inputs And Limits

Read and applied:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B006/goal.md`
- `tools/leaser/Agents/Agent-B006/notes.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`
- Target and support by-* docs listed below.

Live IDA MCP status:

- Checked `http://127.0.0.1:13337/mcp`.
- Result: `ERROR=Unable to connect to the remote server`.
- This report therefore does not claim fresh live IDA MCP verification for this session.

Machine evidence used:

- Local IDA exports:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

Important limitation:

- Existing by-* pages contain prior live IDA MCP evidence from June 2026. This report rechecked those claims against current docs and local IDA exports. It did not add a new live MCP session.

Numeric conversions verified with `tools/int_convert.py`:

- `0x67` = decimal `103`.
- `0x1f` = decimal `31`.
- `0x2` = decimal `2`.
- `0x84` = decimal `132`.
- `0x83` = decimal `131`.
- `0x82` = decimal `130`.
- `0x10` = decimal `16`.
- `0x38` = decimal `56`.
- `0x41` = decimal `65`.
- `0x2e` = decimal `46`.
- `0x17` = decimal `23`.
- `0x1a` = decimal `26`.
- `0x1e` = decimal `30`.
- `0x12` = decimal `18`.
- `0x2d` = decimal `45`.

## Target Current State

Current target header:

```text
UID:0001M2
COMPLETION:85
CONFIDENCE:87
CANONICAL_OWNER:0000KC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KC
```

Current target C++ block is blank.

Current generated route:

```text
| [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) | emits | `0000KC` | `0000KC` |  | no | `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` | `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md` |  |
```

Current generated C++ output has only an empty marker:

```cpp
// UID:0001M2 | by-memory\0x005b27c0-0x005b2827.SendTakeOffPacket.md | Completion:85 | Confidence:87 | Empty Emitter Marker
```

Current target page still says "Do not emit reconstructed C++ yet" because it references an older `90/90+` code-entry gate and because the source helper name/declaration placement were unresolved. Under the current `by-structure.md` gate, this target is eligible for first-draft C++ because it is reconstructable, has a nonblank emitter route to a valid by-file source root, and `(85 + 87) / 2 = 86`, which is greater than `85`.

## Exact Half-Open Range Recheck

The exact range should remain:

```text
0x005b27c0-0x005b2827
```

Local IDA export evidence:

```asm
.text:005B27C0 sub_5B27C0 proc near
.text:005B27C0 Src= byte ptr -84h
.text:005B27C0 var_83= byte ptr -83h
.text:005B27C0 var_82= byte ptr -82h
.text:005B27C0 var_4= dword ptr -4
.text:005B27C0 arg_0= byte ptr  8
.text:005B27C0 push    ebp
.text:005B27C1 mov     ebp, esp
.text:005B27C3 sub     esp, 84h
.text:005B27C9 mov     eax, ___security_cookie
.text:005B27CE xor     eax, ebp
.text:005B27D0 mov     [ebp+var_4], eax
.text:005B27D3 cmp     byte_69B380, 0
.text:005B27DA jg      short loc_5B2819
.text:005B27DC lea     eax, [ebp+Src]
.text:005B27E2 push    eax
.text:005B27E3 push    1Fh
.text:005B27E5 call    sub_575380
.text:005B27EA lea     eax, [ebp+var_83]
.text:005B27F0 push    eax
.text:005B27F1 movsx   eax, [ebp+arg_0]
.text:005B27F5 push    eax
.text:005B27F6 call    sub_575380
.text:005B27FB mov     ecx, dword_67A7EC
.text:005B2801 lea     eax, [ebp+Src]
.text:005B2807 add     esp, 10h
.text:005B280A mov     [ebp+var_82], 0
.text:005B2811 push    2
.text:005B2813 push    eax
.text:005B2814 call    sub_574BB0
.text:005B2819 loc_5B2819:
.text:005B2819 mov     ecx, [ebp+var_4]
.text:005B281C xor     ecx, ebp
.text:005B281E call    @__security_check_cookie@4
.text:005B2823 mov     esp, ebp
.text:005B2825 pop     ebp
.text:005B2826 retn
.text:005B2826 sub_5B27C0 endp
.text:005B2827 align 10h
.text:005B2830 sub_5B2830 proc near
```

Range conclusions:

- The function starts exactly at `0x005b27c0`.
- The epilogue ends with `retn` at `0x005b2826`.
- The half-open exclusive end is `0x005b2827`.
- `0x005b2827-0x005b2830` is alignment before `sub_5B2830`.
- The current target range length is `0x67` / decimal `103`, verified with `tools/int_convert.py`.
- Do not merge this helper into `0x005b2830`.
- Do not merge this helper backward into `0x005b2720`.
- Do not split this helper; it is one source-level packet helper body plus compiler security-cookie code.

Local `.map` export confirms:

```text
sub_568CB0
sub_5B27C0
sub_5B2830
dword_67A7EC
byte_69B380
```

## Local Decompilation Recheck

Local `.c` export decompiles the target as:

```c
int __cdecl sub_5B27C0(char a1)
{
  int result; // eax
  char Src; // [esp+0h] [ebp-84h] BYREF
  _BYTE v3[127]; // [esp+1h] [ebp-83h] BYREF

  if ( byte_69B380 <= 0 )
  {
    sub_575380(31, &Src);
    sub_575380(a1, v3);
    v3[1] = 0;
    return sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2);
  }
  return result;
}
```

Source-quality interpretation:

- `Src` plus `v3[127]` is a 128-byte packet scratch buffer.
- The binary uses `sub esp, 0x84`: 128 bytes of packet buffer plus the stack-cookie local.
- `sub_575380` is now documented as `PacketBufferWriteUInt8`.
- `sub_574BB0` is now documented as `Socket::QueueAndSendPacket` / `QueueAndSendPacket`.
- `dword_67A7EC` is now documented as `g_packetSender`, best current source type `Socket *`.
- `byte_69B380` is now documented as `g_activeDialogCount`, a signed/bias dialog activity gate byte.
- The decompiler's `int` return is not source-significant. The gate-positive path returns an undefined `result`, which strongly favors a source `void` helper whose return register is incidental.

The local `.lst` body uses `movsx eax, [ebp+arg_0]`. This supports `char` or `signed char` for the source parameter, not `unsigned char`. All known selector constants are positive small values, but the signed-byte codegen is still a useful source-shape signal.

## Packet Opcode / Subtype / Selector Semantics

Packet layout emitted by this helper:

| Byte offset | Value | Meaning |
| ---: | --- | --- |
| `0` | `0x1f` / decimal `31` | Take-off / equipment-removal opcode. |
| `1` | `equipmentSlotSelector` | One-based equipment selector. |

Send length:

- Exact send length is `0x2` / decimal `2`, verified with `tools/int_convert.py`.
- `packet[2] = 0` is a local scratch terminator and is not sent.

Subtype decision:

- There is no third packet byte and no separate subtype field in this helper.
- The second byte is not a mode/subcommand in the same sense as throw opcode `0x17` mode bytes or change-slot opcode `0x30` subcommands.
- The second byte is best named `equipmentSlotSelector` or `takeOffSelector`.

Selector semantics:

- Selectors are one-based equipment-removal IDs.
- Valid selectors documented through the TakeOff key table are:
  - `1, 2, 3, 4, 6, 7, 8, 13, 14, 16, 20, 21, 22, 23`.
- [UID:0000PX] / [UID:0001OF] document `g_equipmentSlotKeys` at `0x00630bd8` as a fixed 23-entry UTF-16 lookup table:
  - `wash#nlr####fm#c###[]12`
- In `TakeOffInputPane::ProcessUnequipCommand`, the table maps typed lowercase/symbol keys to selector `index + 1`.
- The uppercase `A` all-equipment branch is not a table entry. It explicitly calls this helper for the fourteen valid selector IDs.
- `SelfLookPane::OnMouseClick` maps clicked equipment slots to the same selector set and then calls this helper.

Rejected packet interpretations:

- Not a two-byte string. It is sent by explicit length `2`.
- Not a null-terminated command buffer. The terminator is local-only.
- Not a packet-buffer length-prefixed record. The helper writes two scalar bytes and passes length `2`.
- Not a general item action opcode. It is specifically the equipment take-off/remove command.
- Not a ProtocolSend-owned packet routine solely because it calls the network queue helper. The implementation sits in the item-action/equipment source neighborhood and is called by equipment UI paths.

## Caller Set Recheck

Local export scan for `call sub_5B27C0` found exactly 28 direct call sites:

```text
COUNT=28
0x005690b0
0x005690bf
0x005690ce
0x005690dd
0x005690ec
0x005690fb
0x0056910a
0x00569119
0x00569128
0x00569137
0x00569146
0x00569170
0x0056917f
0x0056918e
0x005b2873
0x005b287a
0x005b2881
0x005b2888
0x005b288f
0x005b2896
0x005b289d
0x005b28a4
0x005b28ab
0x005b28b2
0x005b28b9
0x005b28c0
0x005b28c7
0x005b28ce
```

### TakeOffInputPane Caller Group

`TakeOffInputPane::ProcessUnequipCommand` at `0x005b2830` calls this helper only for the uppercase `A` all-equipment branch.

Call sequence from local `.lst`:

```asm
.text:005B286B cmp     ax, 41h ; 'A'
.text:005B286F jnz     short loc_5B28E5
.text:005B2871 push    1
.text:005B2873 call    sub_5B27C0
.text:005B2878 push    2
.text:005B287A call    sub_5B27C0
.text:005B287F push    3
.text:005B2881 call    sub_5B27C0
.text:005B2886 push    4
.text:005B2888 call    sub_5B27C0
.text:005B288D push    6
.text:005B288F call    sub_5B27C0
.text:005B2894 push    7
.text:005B2896 call    sub_5B27C0
.text:005B289B push    8
.text:005B289D call    sub_5B27C0
.text:005B28A2 push    0Dh
.text:005B28A4 call    sub_5B27C0
.text:005B28A9 push    0Eh
.text:005B28AB call    sub_5B27C0
.text:005B28B0 push    10h
.text:005B28B2 call    sub_5B27C0
.text:005B28B7 push    14h
.text:005B28B9 call    sub_5B27C0
.text:005B28BE push    15h
.text:005B28C0 call    sub_5B27C0
.text:005B28C5 push    16h
.text:005B28C7 call    sub_5B27C0
.text:005B28CC push    17h
.text:005B28CE call    sub_5B27C0
.text:005B28D3 add     esp, 38h
```

The all-equipment selector list is:

```text
1, 2, 3, 4, 6, 7, 8, 13, 14, 16, 20, 21, 22, 23
```

Important nuance:

- `TakeOffInputPane::ProcessUnequipCommand` does not call this helper for the typed single-slot table match.
- The single-slot branch scans `g_equipmentSlotKeys`, computes `index + 1`, checks `g_activeDialogCount <= 0`, and builds the same opcode `0x1f` packet inline.
- Therefore, target [UID:0001M2] is a shared "send selector" helper, but it is not the only opcode `0x1f` send site.

### SelfLookPane Caller Group

`SelfLookPane::OnMouseClick` at `0x00568cb0` calls this helper in equipment-click branches. Local `.lst` shows fourteen calls:

| Call site | Pushed selector | Context |
| --- | ---: | --- |
| `0x005690b0` | `4` | SelfLook equipment-click switch branch. |
| `0x005690bf` | `2` | SelfLook equipment-click switch branch. |
| `0x005690ce` | `3` | SelfLook equipment-click switch branch. |
| `0x005690dd` | `1` | SelfLook equipment-click switch branch. |
| `0x005690ec` | `22` | SelfLook equipment-click switch branch. |
| `0x005690fb` | `7` | SelfLook equipment-click switch branch. |
| `0x0056910a` | `8` | SelfLook equipment-click switch branch. |
| `0x00569119` | `20` | SelfLook equipment-click switch branch. |
| `0x00569128` | `21` | SelfLook equipment-click switch branch. |
| `0x00569137` | `23` | SelfLook equipment-click switch branch. |
| `0x00569146` | `14` | SelfLook equipment-click switch branch. |
| `0x00569170` | `6` | SelfLook equipment-click switch branch. |
| `0x0056917f` | `13` | SelfLook equipment-click switch branch. |
| `0x0056918e` | `16` | SelfLook equipment-click switch branch. |

The set matches the TakeOff all-equipment set:

```text
1, 2, 3, 4, 6, 7, 8, 13, 14, 16, 20, 21, 22, 23
```

Interpretation:

- `SelfLookPane` is a proven caller, not the owner of this helper.
- The helper's implementation address and neighboring source family are `ItemActionInputPanes`.
- `SelfLookPane` should document the selector mapping and call dependency, but should not absorb the helper.

## `g_packetSender` Name / Type Reanalysis

Accepted name:

```cpp
g_packetSender
```

Accepted best current type:

```cpp
Socket *g_packetSender
```

Evidence:

- [UID:0000Q5] and [UID:0001P0] document `dword_67A7EC` as `g_packetSender`.
- Socket constructor/destructor/unwind/scalar-deleting paths are the only observed writers.
- `QueueAndSendPacket` is now attached to [UID:0000DD][Socket] and consumed by `Socket::HandleSocketCommand` command `8`.
- Feature packet builders, including this helper, are consumers only.

Rejected names/types:

- Reject `g_pCashShopRequest` for this storage. Current global docs explicitly identify that as generated alias pollution; real `g_pCashShopRequest` is separate storage at `0x0067a738`.
- Reject feature-local ownership by `TakeOffInputPane`, `SelfLookPane`, or `ItemActionInputPanes` for the global itself. Those modules read the global to send packets.
- Reject a new packet-sender global owner for this target. Socket lifecycle ownership is already supported.

Source C++ impact:

- The target helper should call through `g_packetSender`.
- The target helper should not introduce a local sender object, a cash-shop request object, or a null check not present in the binary.

## `g_activeDialogCount` Name / Type Reanalysis

Accepted documentation name:

```cpp
g_activeDialogCount
```

Best current source declaration direction:

```cpp
extern char g_activeDialogCount;
```

or a signed-byte typedef if the project later defines one.

Evidence:

- [UID:0000PQ] and [UID:0001PH] document `byte_69B380` as `g_activeDialogCount`.
- DialogPane constructor/destructor are the mutators.
- Inventory, spell inventory, and take-off/item action code are consumers.
- The target instruction is `cmp byte_69B380, 0` followed by signed `jg`.
- The exact memory page records initial byte `0xff`.

Source C++ impact:

- The target gate should be represented as:

```cpp
if (g_activeDialogCount <= 0) {
    ...
}
```

- Do not model it as `uint8_t` in this helper. An unsigned `0xff` interpretation would break the documented initial inactive state.
- The final global declaration may need a signed/bias note in the DialogPane-owned global docs, but that is not a target C++ blocker.

Rejected owner interpretations:

- Reject ItemActionInputPanes ownership for this global. This target reads it only as a gate.
- Reject SelfLookPane ownership. It is a caller family, not the dialog lifetime owner.
- Reject Socket ownership. The global gates UI action sends before the Socket queue call.

## Ownership And Source Placement

Recommended target owner/emitter remains:

```text
CANONICAL_OWNER:0000KC
EMITTER_UIDS:0000KC
```

Recommended source route remains:

```text
auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp
```

Ranking:

### 1. ItemActionInputPanes file-level helper - accepted

Evidence for:

- Current target owner/emitter is [UID:0000KC].
- Current generated route is `ItemActionInputPanes.cpp`.
- The target is located in the item-action input pane address neighborhood.
- Neighboring TakeOff, Wield, Wear, Throw, Eat, Drop, Give, and ChangeSlot packet helpers all belong to the item-action command family.
- `g_equipmentSlotKeys` is also routed through ItemActionInputPanes.
- The helper is not an instance method: it is `__cdecl`, has no `this`, and takes one stack byte argument.

Evidence against:

- `SelfLookPane::OnMouseClick` calls it from a panel source family.

Decision:

- Keep file-level ItemActionInputPanes ownership.
- Document the cross-source declaration requirement.
- Do not mark it as a private `static` helper unless a future source-layout pass folds SelfLookPane and ItemActionInputPanes into one translation unit.

### 2. TakeOffInputPane class method - rejected

Evidence for:

- The helper sits inside the TakeOffInputPane memory cluster.
- `TakeOffInputPane::ProcessUnequipCommand` calls it for the all-equipment branch.
- The target name and opcode semantics are take-off-specific.

Evidence against:

- The function has no `this` pointer and no class state access.
- `SelfLookPane::OnMouseClick` calls it fourteen times.
- The typed single-slot TakeOff branch duplicates the packet build inline instead of treating this helper as a class virtual/member API.

Decision:

- Do not set `CANONICAL_OWNER:0000EC`.
- Keep `TakeOffInputPane` as a caller/consumer and semantic context.

### 3. SelfLookPane class/file - rejected

Evidence for:

- `SelfLookPane::OnMouseClick` contributes fourteen direct calls.
- The self-look equipment panel can remove equipment from click branches.

Evidence against:

- The target implementation is not located in the SelfLookPane address cluster.
- It has no SelfLookPane state access.
- SelfLookPane is one caller family, not the implementation owner.
- SelfLookPane already has its own packet helper island; this target is not in that island.

Decision:

- Do not assign this helper to [UID:0000CU] or [UID:0000NL].
- Add support-doc cross-reference details there, but leave implementation under [UID:0000KC].

### 4. ProtocolSend / network module - rejected for now

Evidence for:

- The helper sends a packet through the shared network sender.
- It is called by more than one UI source family.

Evidence against:

- [UID:0000MV][ProtocolSend] is currently a placeholder with `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and no distinct source-unit proof.
- The helper is feature-specific: opcode `0x1f`, equipment selectors, take-off semantics.
- The source neighborhood strongly matches item-action input panes.
- Many feature packet builders call `QueueAndSendPacket`; that does not make them network-owned.

Decision:

- Do not create/promote a `ProtocolSend` owner for this target.
- If a future broad protocol helper source is proven, this helper can be revisited, but current evidence favors item-action/equipment source placement.

### 5. New `EquipmentActionPackets.cpp` helper file - possible but not recommended now

Evidence for:

- This helper is shared by TakeOff and SelfLook equipment UI.
- A small equipment packet helper header/source could be a plausible original design.

Evidence against:

- No current by-file owner or proposed tree node exists for such a source file.
- The implementation address is embedded in the item-action input pane module neighborhood.
- Existing generated route is valid and clears the gate.

Decision:

- Do not recommend a new file at this time.
- Record a shared declaration/header caveat only.

## Heuristic / Inference Reanalysis And Validation

### Generated Function Name

Observed generated/IDA names:

- `sub_5B27C0`
- target title `SendTakeOffPacket`

Best source-facing name:

```cpp
SendTakeOffPacket
```

Validation:

- Opcode `0x1f` is documented as equipment take-off/removal in target, TakeOffInputPane, and g_packetSender docs.
- The helper receives a selector byte and sends exactly the take-off packet shape.
- Existing target and support docs already use `SendTakeOffPacket`; current evidence validates rather than contradicts that name.

Rejected alternatives:

- `TakeOffInputPane::SendTakeOffPacket`: rejected because no `this` and SelfLook callers.
- `SelfLookPane::SendTakeOffPacket`: rejected because implementation neighborhood and item-action semantics.
- `SendEquipmentClickPacket`: too caller-specific to SelfLook and misses typed/all-equipment TakeOff caller.
- `SendUnequipPacket`: semantically good but less consistent with existing command name and target title.
- `SendEquipmentActionPacket`: too broad for opcode `0x1f`.
- `ProtocolSendTakeOffPacket`: no ProtocolSend source-unit proof.

Remaining uncertainty:

- Exact original symbol spelling is not proven. `SendTakeOffPacket` is a descriptive/inferred source name and the best supported current spelling.

Impact:

- This uncertainty does not block first-draft C++. The helper name is already target-canonical and behaviorally exact.

### Helper Linkage / Static-ness

Candidates:

- File-level helper with external linkage or shared header declaration.
- File-local `static` helper in `ItemActionInputPanes.cpp`.
- Class-static method on `TakeOffInputPane`.
- Class method on `SelfLookPane`.

Best direction:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector);
```

with a shared declaration available to `SelfLookPane`.

Validation:

- Cross-source caller evidence makes private `static` linkage unsafe unless future source layout folds both caller families into the same translation unit.
- `__cdecl` plus no `this` supports a free helper.
- File-level ItemActionInputPanes implementation is still the best body placement.

Rejected:

- Private `static` helper: rejected for current source tree because SelfLookPane calls it.
- Class-static `TakeOffInputPane::SendTakeOffPacket`: possible source style but not supported by address neighborhood plus `SelfLookPane` caller split.

Impact:

- First-draft body should omit `static` in the formal code recommendation.
- Support docs should mention a header/shared declaration requirement.

### Parameter Name And Type

Candidates:

- `char selector`
- `char equipmentSlotSelector`
- `signed char equipmentSlotSelector`
- `unsigned char slot`
- `int slot`
- enum-backed `EquipmentSlotSelector`

Best first-draft signature:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector)
```

Validation:

- Local `.lst` defines `arg_0= byte ptr 8`.
- Local `.lst` uses `movsx`, which supports signed `char` codegen.
- Callers push positive selector constants only.
- The selector is one-based equipment slot/removal ID, not a typed key and not a packet subtype.

Rejected:

- `unsigned char`: semantically safe for positive values, but less faithful to `movsx` source shape.
- `int`: caller pushes 32-bit constants, but callee treats only a byte argument and IDA labels `arg_0` as `byte ptr`.
- raw `slot`: acceptable but less precise than `equipmentSlotSelector`.

Possible later refinement:

- If the project creates an enum or typedef, use a char-backed equipment selector type. The current target C++ should not invent that type.

### Local Buffer Shape

Candidates:

- `char packet[3]`
- `char packet[128]`
- PacketBuffer object/class
- `AUTOBUF`

Best first-draft shape:

```cpp
char packet[128];
```

Validation:

- Local `.lst` stack frame reserves `0x84` / decimal `132`: 128-byte packet scratch buffer plus 4-byte security-cookie local.
- Local `.c` export shows `char Src` followed by `_BYTE v3[127]`.
- Many packet helpers in this project use a larger stack scratch buffer and explicit send length.

Rejected:

- `char packet[3]`: behaviorally enough but not source-shape faithful to the 128-byte local buffer.
- A modern `std::array`: not plausible for the surrounding mid-2000s C++ source style and not supported by local docs.
- A full class object: not supported by this function's simple stack layout.

### Packet Writer Helper Name

Observed generated name:

- `sub_575380`

Best current source-facing name:

```cpp
PacketBufferWriteUInt8
```

Validation:

- [UID:0003YJ] documents `0x00575380-0x00575391` as `PacketBufferWriteUInt8`.
- The target calls it twice, once for opcode and once for selector.
- The helper writes a byte plus spare zero; the target still explicitly writes the final local terminator.

Rejected:

- Direct `packet[0] = ...; packet[1] = ...;` as the primary first draft: behaviorally equivalent but does not reflect the observed function calls.
- `WriteByteToPacket` or `EncodeByte`: acceptable descriptive names but less aligned with current PacketBuffer support docs.

Impact:

- Target C++ should use `PacketBufferWriteUInt8` unless the accepted implementation callback chooses a different PacketBuffer API spelling consistently with [UID:0003YJ].

### Queue/Send Helper Name

Observed generated name:

- `sub_574BB0`

Best current source-facing call:

```cpp
g_packetSender->QueueAndSendPacket(packet, 2);
```

Validation:

- [UID:0001HU] documents `0x00574bb0-0x00574c13` as `QueueAndSendPacket`, attached to `Socket`.
- [UID:0000Q5] and [UID:0001P0] document `g_packetSender` as `Socket *`.
- This target sets `ecx = dword_67A7EC`, pushes packet pointer and length, then calls `sub_574BB0`, matching a `thiscall` style method call on the sender object.

Rejected:

- `CashShopRequest::QueueAndSendPacket`: stale generated alias.
- `ProtocolSend::Send`: no source-unit proof.
- `SendRawData`: wrong layer; `QueueAndSendPacket` queues command `8`, while final transport send is deeper in Socket.

### Dialog Gate Meaning

Observed generated name:

- `byte_69B380`

Accepted documentation name:

- `g_activeDialogCount`

Best C++ expression:

```cpp
if (g_activeDialogCount <= 0)
```

Validation:

- The instruction sequence uses signed `jg` to skip sends when the byte is positive.
- DialogPane constructor/destructor mutate the byte.
- Multiple UI modules consume the byte as an action gate.
- Initial `0xff` requires signed/bias interpretation.

Rejected:

- `if (!g_activeDialogCount)`: would not match the `<= 0` / signed positive-only block semantics.
- `if (g_activeDialogCount == 0)`: misses initial `0xff` inactive case.
- `uint8_t g_activeDialogCount`: conflicts with signed compare and initial `0xff`.

### Caller Meaning

Best interpretation:

- This helper is a shared equipment-removal packet sender used by:
  - TakeOff all-equipment branch.
  - SelfLook equipment-click branches.

Rejected:

- "Called by TakeOff typed-command logic" without nuance: current coverage row is too broad. Only the `A` all-equipment branch calls this helper; the typed single-slot branch emits the same packet inline after table scan.
- "SelfLook owns the helper because it has equal call count": rejected. Call count is consumer evidence, not ownership proof.

### C++ Readiness

Current gate:

- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KC`
- valid source route through `ItemActionInputPanes.cpp`
- average score `(85 + 87) / 2 = 86`, greater than `85`

Resolved source-quality blockers:

- Exact range and padding are documented and rechecked.
- Full direct caller set is documented and locally rechecked.
- Opcode/selector/length semantics are resolved.
- `g_packetSender` and `g_activeDialogCount` names are resolved enough for first-draft code.
- Owner/source route is resolved enough for current source generation.
- Helper name/signature is resolved enough for first-draft code.

Remaining caveats:

- Exact original symbol spelling is inferred/descriptive.
- Final shared declaration/header placement remains open.
- `g_activeDialogCount` final declaration type is DialogPane-owned and still has a signed/bias caveat.
- A future char-backed selector enum could replace the raw `char`.

Impact:

- These caveats should cap score below final audit, but they do not block first-draft C++.

## First-Draft C++ Recommendation

Recommended target C++:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector)
{
    char packet[128];

    if (g_activeDialogCount <= 0) {
        PacketBufferWriteUInt8(0x1f, packet);
        PacketBufferWriteUInt8(equipmentSlotSelector, packet + 1);
        packet[2] = 0;
        g_packetSender->QueueAndSendPacket(packet, 2);
    }
}
```

Expected support declarations, if not already present in generated source:

```cpp
class Socket;

extern Socket *g_packetSender;
extern char g_activeDialogCount;

void PacketBufferWriteUInt8(int value, char *out);
void SendTakeOffPacket(char equipmentSlotSelector);
```

If `Socket::QueueAndSendPacket` is not yet available as a member declaration in generated code, use the project-accepted declaration from [UID:0001HU]. Do not invent a `CashShopRequest` receiver type.

Do not add:

- A `this` parameter.
- A null-check around `g_packetSender`.
- A `return` value.
- A `ProtocolSend` wrapper.
- A modern `std::array` buffer.
- A switch over selectors.

The target's job is only to send the selector already chosen by callers.

## Proposed Score / Metadata

Recommended target metadata after implementation callback:

```text
COMPLETION:89
CONFIDENCE:90
CANONICAL_OWNER:0000KC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KC
```

Score rationale:

- Raise completion because the report resolves the prior source-name/signature/declaration-placement blocker enough for first-draft C++, clarifies packet selector semantics, distinguishes caller roles, and updates the stale code-entry gate.
- Raise confidence because local IDA exports confirm the exact body, callers, and packet construction, and current support docs resolve the two key globals and packet helper names.
- Keep below `95+` because exact original symbol spelling, final shared header placement, final `g_activeDialogCount` declaration convention, and final selector enum/type remain inferred.

Recommended status:

- `reconstructable`
- source-ready
- not final-audit complete

## Exact Supervisor-Owned Coverage Row

Current exact row in `by-memory/-coverage-report.md`:

```text
    - [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) 0x005b27c0-0x005b2827 | packet-helper | SendTakeOffPacket : reconstructable : 76% : strong : Shared opcode `0x1f` selector-byte helper gated by `g_activeDialogCount`, called by TakeOff typed-command logic and SelfLook equipment-click paths.
```

The row is stale relative to the current target header `85/87` and imprecise about the TakeOff caller role.

Recommended replacement row:

```text
    - [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) 0x005b27c0-0x005b2827 | packet-helper | SendTakeOffPacket : reconstructable : 89% : very strong : B006 source-quality pass resolves this as file-level `void SendTakeOffPacket(char equipmentSlotSelector)` under `ItemActionInputPanes.cpp`: local IDA exports confirm the exact `0x005b27c0-0x005b2827` / `0x67`-byte function, 128-byte packet scratch buffer, signed-byte selector argument, `g_activeDialogCount <= 0` gate, opcode `0x1f` plus one-based equipment selector byte, explicit two-byte send through `g_packetSender->QueueAndSendPacket`, and `0x005b2827-0x005b2830` padding; caller set is exactly 28 direct calls, fourteen from `TakeOffInputPane::ProcessUnequipCommand`'s uppercase `A` all-equipment branch and fourteen from `SelfLookPane::OnMouseClick` equipment-click branches, while the typed single-slot TakeOff table path emits the same packet inline; `TakeOffInputPane` and `SelfLookPane` class ownership, ProtocolSend ownership, and new helper-file promotion are rejected for the implementation body, with only a shared declaration/header caveat remaining, so first-draft C++ is ready through `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
```

## Exact Support-Doc Checklist

Target by-memory page:

- File: `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`
- Set `COMPLETION:89`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000KC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KC`.
- Replace the stale "do not emit reconstructed C++ yet" note with the current code-entry gate analysis.
- Add the first-draft C++ body from this report.
- Add local IDA-export evidence for the body shape:
  - `sub esp, 0x84`
  - `byte_69B380` signed positive gate
  - `sub_575380(0x1f, packet)`
  - `movsx` byte selector
  - `sub_575380(selector, packet + 1)`
  - `packet[2] = 0`
  - `sub_574BB0(dword_67A7EC, packet, 2)`
  - `0x005b2827` alignment end.
- Clarify that the target helper is called by TakeOff's uppercase `A` all-equipment branch, not by every typed TakeOff path.
- Clarify that `TakeOffInputPane::ProcessUnequipCommand` single-slot key-table branch emits the same opcode `0x1f` packet inline.
- Add the exact 28-call inventory or a summarized table with all call addresses.
- Name the parameter `equipmentSlotSelector`.
- Document that `char` is preferred over `unsigned char` because the body uses `movsx`.
- Document that the source helper should be `void`, and that decompiler `int` return is incidental.

`by-file/ItemActionInputPanes.md`:

- Keep score `90/85` unless the implementation reviewer decides the file-level helper-name resolution justifies a small confidence bump. Broader raw helper and source-name caps still remain.
- In the `TakeOffInputPane` proposed-contents row, update the helper wording to "file-level shared helper `void SendTakeOffPacket(char equipmentSlotSelector)`".
- In boundary notes, replace "final helper source placement remains open" with "implementation body remains file-level ItemActionInputPanes; shared declaration/header placement remains open because SelfLookPane calls it".
- Add that this helper is source-ready and no longer blocked by the old `90/90+` gate.
- Add that ProtocolSend promotion is rejected absent distinct source-unit proof.

`by-class/TakeOffInputPane.md`:

- Keep current class owner/emitter and score unless separately reworking class C++.
- Update the method/helper table row for `SendTakeOffPacket` to mention:
  - free helper, not class method;
  - signature `void SendTakeOffPacket(char equipmentSlotSelector)`;
  - called by uppercase `A` all-equipment branch;
  - typed single-slot branch scans `g_equipmentSlotKeys` and emits the same packet inline.
- Replace any "source ownership remains shared/open" wording with a more precise split:
  - implementation body remains ItemActionInputPanes file-level;
  - declaration/header placement remains shared/open.

`by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`:

- Keep main owner/emitter [UID:0000EC] and score unless a broader method-C++ pass is performed.
- Update packet behavior to distinguish:
  - `A` branch calls [UID:0001M2] fourteen times;
  - key-table single-slot branch writes opcode `0x1f` inline after table match.
- Cross-reference this report's recommended target score and source-ready decision.
- Preserve the existing split/range map.

`by-class/SelfLookPane.md`:

- Keep current class owner/emitter and score.
- Add a support note under method split or packet/input evidence that `SelfLookPane::OnMouseClick` calls [UID:0001M2] fourteen times for equipment-click unequip selectors.
- Make clear this is a dependency on the item-action equipment helper, not ownership transfer.

`by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md`:

- Add the fourteen [UID:0001M2] call addresses and selector mapping:
  - `0x005690b0 -> 4`
  - `0x005690bf -> 2`
  - `0x005690ce -> 3`
  - `0x005690dd -> 1`
  - `0x005690ec -> 22`
  - `0x005690fb -> 7`
  - `0x0056910a -> 8`
  - `0x00569119 -> 20`
  - `0x00569128 -> 21`
  - `0x00569137 -> 23`
  - `0x00569146 -> 14`
  - `0x00569170 -> 6`
  - `0x0056917f -> 13`
  - `0x0056918e -> 16`
- State that the selector set matches the valid TakeOff selector set but the order follows SelfLook equipment-click switch cases.
- Keep C++ blank unless a full OnMouseClick source-quality pass resolves event/slot field names.

`by-file/SelfLookPane.md`:

- Add a small dependency note that SelfLook equipment-click removal uses the shared ItemActionInputPanes helper [UID:0001M2].
- Do not add this helper to SelfLookPane proposed contents as an owned item.

`by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`:

- No mandatory score or metadata change.
- Optional support sync: add that [UID:0001M2]'s first-draft C++ now uses `g_packetSender->QueueAndSendPacket(packet, 2)` with `Socket *` as the best current type.
- Keep existing `Socket *` caveat and reject stale `CashShopRequest *` aliases.

`by-global/g_activeDialogCount.md` and `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md`:

- No mandatory score or metadata change.
- Optional support sync: add that [UID:0001M2]'s first-draft source uses the signed gate `g_activeDialogCount <= 0`.
- Keep the final declaration caveat due initial `0xff`.

`by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`:

- No mandatory score or metadata change.
- Optional support sync: add [UID:0001M2] as a focused `PacketBufferWriteUInt8` consumer that writes opcode `0x1f` and one selector byte.

`by-global/g_equipmentSlotKeys.md` and `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`:

- No mandatory score or metadata change.
- Optional support sync: clarify that [UID:0001M2] consumes the same selector IDs but does not read the table directly.

`auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`:

- After accepted implementation callback and validator/autogen refresh, the `UID:0001M2` marker should contain the first-draft C++ body instead of an empty marker.
- Do not manually edit generated output.

## Validator Baseline / Result

Scoped non-mutating validator baseline was applicable because the target is an existing by-memory page and this was report-only work.

Command:

> Executable block R001 was removed from this report and preserved verbatim in [0001M2-SendTakeOffPacket-source-quality-removed.md](0001M2-SendTakeOffPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
apply: False
uid phase: True
reference phase: False
scanned markdown files: 1
ok: 1
stats_incremental_skip: 1
ok           0001M2 by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md UID header exists
stats_incremental_skip 0001M2 project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

No `--apply` was used.

## Open-Question Closure

Closed or best-inferred:

- Exact half-open range: closed as `0x005b27c0-0x005b2827`.
- Caller set: closed as exactly 28 direct calls in local exports, matching existing docs.
- Packet opcode: closed as `0x1f` / decimal `31`.
- Packet length: closed as `2`.
- Selector meaning: closed as one-based equipment take-off selector.
- Packet subtype: closed as none; second byte is selector.
- `dword_67A7EC`: closed as `g_packetSender`, best current type `Socket *`.
- `byte_69B380`: closed as `g_activeDialogCount`, signed/bias dialog activity gate.
- Source helper role: closed as free/file-level equipment take-off packet helper.
- Owner: closed as file-level [UID:0000KC][ItemActionInputPanes].
- C++ eligibility: closed as eligible under current combined-score/emitter gate.

Still open but not blocking first-draft C++:

- Exact original symbol spelling of `SendTakeOffPacket`.
- Whether the final declaration lives in `ItemActionInputPanes.h`, a small equipment-action header, or a broader shared UI command header.
- Whether a final enum/typedef replaces raw `char equipmentSlotSelector`.
- Exact global declaration type for `g_activeDialogCount`, owned by DialogPane docs.
- Exact PacketBuffer API spelling if [UID:0003YJ] later chooses a different final name.

Score/source impact:

- These remaining items justify keeping the target below final-audit scores.
- They do not justify keeping the formal target C++ block blank after implementation acceptance.

## Changed Files

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0001M2-SendTakeOffPacket-source-quality.md
```

Not edited:

- Target by-memory doc.
- Any by-* support doc.
- `by-memory/-coverage-report.md`.
- Generated output.
- Project-level reports.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001M2-SendTakeOffPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0001M2"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001M2-SendTakeOffPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001M2-SendTakeOffPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001M2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
