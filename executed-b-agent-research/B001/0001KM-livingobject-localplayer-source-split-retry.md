** TARGET-REPORT-UID:0001KM **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KM LivingObjectPaneLocalPlayerExtensions Source Split Retry

Assignment: `B001-goal2-memorytool-livingobject-localplayer-source-split-0001KM-20260616-retry`  
Target: [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`  
Agent: `Agent-B001`  
Date: 2026-06-16

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001KM] as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and no C++.
- Final disposition: executable report-only split recommendation for the remaining largest leaf `0x005a5b79-0x005a87e0`.
- Required action: supervisor should create seven exact child pages, add six ignored spans, update the parent/support docs listed below, insert the exact coverage block, validate, then rerun `memory_ranges.py report`.
- Confidence: strong. The retry byte-audited every internal gap, checked current docs, checked local IDA decompile cache for the four UserPane virtuals, scanned raw absolute and rel32 references, and separated source-authored children from generated switch-table bytes.

This report replaces the earlier incomplete closeout. There are no below-gate proposed reconstructable children left in this recommendation.

## Report-Only Lease Correction

- This retry is report-only. Do not directly edit `by-*`, `by-memory/-coverage-report.md`, or `by-memory/-ignored.md` from B001 for this task.
- 2026-06-16 correction: `python .\tools\leaser\leaser.py Supervisor unlease` returned `Supervisor: No active leases` after the generated lease report showed no active `Supervisor` rows.
- The only lease needed for this correction was the report file itself, acquired as `Agent-B001`: `tools/leaser/Agents/Agent-B001/research/0001KM-livingobject-localplayer-source-split-retry.md`.
- The by-* rows, ignored-ledger entries, support-doc updates, and validation commands below are supervisor-executable recommendation text only.

## Supervisor Rejection Fix Summary

1. Complete child markdown: this report provides full markdown text for the recommended exact pages [UID:0003V8]-[UID:0003VE].
2. Below-gate children fixed: `UserPaneHandleKeyEvent` and `UserPaneHandleServerMessage` are now researched to `86/88`, with exact decompiler/callee/switch-table evidence. No proposed reconstructable child is below `85/85`.
3. Gap byte audit fixed: every byte in `0x005a5b79-0x005a87e0` is classified. Two gaps are pure `0xcc`, two are compiler-generated switch-table spans with trailing `0xcc`, and the last former gap contains a raw `LivingObjectPane` helper plus padding.
4. Coverage rows fixed: exact supervisor-owned coverage insert rows are supplied using real UID allocation assumptions [UID:0003V8]-[UID:0003VE].
5. Support-doc edits fixed: exact updates are supplied for [UID:0001KM], [UID:0001KL] `UserPane`, `by-class/UserPane.md`, `by-file/UserPane.md`, and the needed `LivingObjectPane` support docs for [UID:0003VE].
6. No future-pass punt: the remaining largest leaf is fully decomposed here. The only future work is final C++ quality work after these exact docs exist and validate.

## Target

- Target UID: [UID:0001KM]
- Target path: `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- Source queue row: `B001-goal2-memorytool-livingobject-localplayer-source-split-0001KM-20260616-retry`
- Current supervisor classification: rejected retry, same target reassigned for executable split report.
- Current target score/state: `88/88`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.

The parent state remains correct. The work below only resolves the current largest memory-tool leaf inside that parent.

## Evidence Standards Used

Documentation evidence checked:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-structure.md`
- `by-memory/-guidance.md`
- `auto-generated/by-memory-tool-report.md`
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`
- [UID:0001KM] target page.
- [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`
- [UID:0000FQ] `by-class/UserPane.md`
- [UID:0000P1] `by-file/UserPane.md`
- [UID:00007B] `by-class/LivingObjectPane.md`
- [UID:0000KU] `by-file/LivingObjectPane.md`
- [UID:0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`

Binary and IDA evidence checked:

- Raw PE byte audit of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; image base `0x400000`, `.text` VA `0x00401000-0x0060d000`.
- Local IDA decompile cache for `0x005a5b80`, `0x005a5bd0`, `0x005a76c0`, and `0x005a83b0` under `C:\Users\admin\Desktop\CTools\Output\ida\decompile\`.
- Raw absolute pointer scans and rel32 call/jump scans over `.text`.
- Current project docs record prior live IDA `lookup_funcs`, `xrefs_to`, `callees`, and vtable evidence for this area. No IDA database edits were made in this retry.

UID allocation assumption:

- Current `tools/validator.ini` is occupied through [UID:0003V7].
- This executable recommendation assumes the supervisor allocates the next seven UIDs, [UID:0003V8] through [UID:0003VE], in the order shown here based on current `tools/validator.ini` (`last_used_uid = 0003V7`). If any UID is consumed before application, allocate the next available IDs but preserve this range/order mapping throughout child docs, support docs, ignored rows, and coverage rows.

## Complete Byte/Range Audit For 0x005a5b79-0x005a87e0

| Range | Classification | Owner / disposition | Evidence |
| --- | --- | --- | --- |
| `0x005a5b79-0x005a5b80` | padding | ignored | PE bytes are seven `0xcc` bytes after [UID:0003UE]. |
| `0x005a5b80-0x005a5bc7` | source method | [UID:0003V8] `UserPaneOnBoundsChanged`, owner/emitter [UID:0000FQ] | IDA decompile cache size `0x47`; vtable/data pointer `0x0062ef18`; existing UserPane docs list exact method. |
| `0x005a5bc7-0x005a5bd0` | padding | ignored | PE bytes are nine `0xcc` bytes before `0x005a5bd0`. |
| `0x005a5bd0-0x005a7422` | source method | [UID:0003V9] `UserPaneHandleKeyEvent`, owner/emitter [UID:0000FQ] | IDA decompile cache size `0x1852`; vtable/data pointer `0x0062ef98`; decompiler shows key/modifier gates, command switches, input-pane creation, packet sends, and calls into LivingObjectPane dependencies. |
| `0x005a7422-0x005a76c0` | compiler-generated switch tables and alignment | [UID:0003VA], ignored/non-emitting | Bytes start with `66 90`, contain 81 dword-like entries pointing back inside `0x005a5bd0-0x005a7422`, byte selector maps, and end with `0x005a76bc-0x005a76c0` `0xcc`. |
| `0x005a76c0-0x005a82bd` | source method | [UID:0003VB] `UserPaneHandleServerMessage`, owner/emitter [UID:0000FQ] | IDA decompile cache size `0xbfd`; vtable/data pointer `0x0062efa0`; decompiler shows packet opcode dispatch and delegation to LivingObjectPane packet handlers. |
| `0x005a82bd-0x005a83b0` | compiler-generated switch tables and alignment | [UID:0003VC], ignored/non-emitting | Bytes begin with `0f 1f 00`, contain 25 dword-like entries pointing back inside `0x005a76c0-0x005a82bd`, selector bytes, and end with `0x005a83a4-0x005a83b0` `0xcc`. |
| `0x005a83b0-0x005a87ad` | source method | [UID:0003VD] `UserPaneHandleAnimationStep`, owner/emitter [UID:0000FQ] | IDA decompile cache size `0x3fd`; vtable/data pointer `0x0062efc4`; decompiler shows animation/timer dispatch and calls to LivingObjectPane movement helpers. |
| `0x005a87ad-0x005a87b0` | padding | ignored | PE bytes are three `0xcc` bytes after `0x005a83b0-0x005a87ad`. |
| `0x005a87b0-0x005a87d5` | raw source helper | [UID:0003VE] `LivingObjectPaneGetActiveLinkedRecordByIndexRaw`, owner/emitter [UID:00007B] | Bytes decode as a compact thiscall helper checking `index < [ecx+0x13eb18]`, returning `&records[index]` only when the record active byte is nonzero. Raw pointer/rel32 scan found no absolute or branch/call xrefs to `0x005a87b0`. |
| `0x005a87d5-0x005a87e0` | padding | ignored | PE bytes are eleven `0xcc` bytes before [UID:0003UF] `0x005a87e0`. |

The prior single leaf `0x005a5b79-0x005a87e0` disappears if these child pages and ignored rows are applied.

## IDA / Decompiler Facts

Function facts:

- `0x005a5b80` decompiles as `char __thiscall sub_5A5B80(int this, _DWORD *a2)`, size 71, ending at `0x005a5bc7`. It compares/replaces cached bounds at `this+68`, updates geometry at `this+84`, then forwards the bounds to the child/base pane at `this+4`.
- `0x005a5bd0` decompiles as `char __thiscall sub_5A5BD0(int this, int a2)`, size 6226, ending at `0x005a7422`. It gates on local state and key modifiers, normalizes key input, dispatches command cases, creates chat/say/target/action input panes, sends several command packets, calls `sub_5A3AE0`, `sub_5A2E00`, `sub_5AD360`, `sub_5A58C0`, and uses UserPane slot-label helpers `0x005a40d0` and `0x005a4310`.
- `0x005a76c0` decompiles as `char __fastcall sub_5A76C0(char *a1, int a2, WCHAR *a3)`, size 3069, ending at `0x005a82bd`. It initializes a message state flag and switches on the first payload byte, delegating many living-object packet bodies to `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abda0`, `0x005ac070`, `0x005ac280`, and local position helper `0x005a5a90`.
- `0x005a83b0` decompiles as `char __thiscall sub_5A83B0(int this, int a2, int a3, int a4)`, size 1021, ending at `0x005a87ad`. It switches over animation/timer event ids, advances movement frame state, invokes LivingObjectPane movement/timer helpers `0x005a36f0`, `0x005a3770`, `0x005a5a90`, and MapPane/timer helpers.
- `0x005a87b0` is not currently modeled as a function in project docs, but the bytes are function-shaped:

```asm
0x005a87b0  55                  push ebp
0x005a87b1  8b ec               mov ebp, esp
0x005a87b3  0f b6 55 08         movzx edx, byte ptr [ebp+8]
0x005a87b7  3b 91 18 eb 13 00   cmp edx, [ecx+0x13eb18]
0x005a87bd  7d 10               jge 0x005a87cf
0x005a87bf  8b 81 14 eb 13 00   mov eax, [ecx+0x13eb14]
0x005a87c5  c1 e2 04            shl edx, 4
0x005a87c8  03 c2               add eax, edx
0x005a87ca  80 38 00            cmp byte ptr [eax], 0
0x005a87cd  75 02               jne 0x005a87d1
0x005a87cf  33 c0               xor eax, eax
0x005a87d1  5d                  pop ebp
0x005a87d2  c2 04 00            retn 4
```

Xref facts:

- Raw scan found exactly one absolute pointer to `0x005a5b80` at `0x0062ef18`.
- Raw scan found exactly one absolute pointer to `0x005a5bd0` at `0x0062ef98`.
- Raw scan found exactly one absolute pointer to `0x005a76c0` at `0x0062efa0`.
- Raw scan found exactly one absolute pointer to `0x005a83b0` at `0x0062efc4`.
- Raw scan found no absolute pointer hit and no rel32 call/jump/conditional branch target to `0x005a87b0`.
- Raw scan found rel32 call targets to `0x005a87e0` from `0x005ab2ea` and `0x005ab637`, confirming the successor is the modeled LivingObjectPane linked-record cleanup method, not table/padding.

Switch-table facts:

- `0x005a7422-0x005a76c0` contains dword target runs at `0x005a7424-0x005a7438`, `0x005a7484-0x005a74ac`, `0x005a7528-0x005a7620`, and `0x005a76ac-0x005a76bc`; all 81 dword-like values point inside the owning key handler `0x005a5bd0-0x005a7422`.
- `0x005a82bd-0x005a83b0` contains one 25-entry dword target run at `0x005a82c0-0x005a8324`; all dword-like values point inside the owning server-message handler `0x005a76c0-0x005a82bd`.

## Function / Child Inventory

| UID | Range | Role | Reconstructable | Direct parent | Score | Owner/emitter decision |
| --- | --- | --- | --- | --- | --- | --- |
| 0003V8 | `0x005a5b80-0x005a5bc7` | UserPane bounds virtual | TRUE | [UID:0000FQ] UserPane | `86/89` | Assign owner/emitter [UID:0000FQ]. |
| 0003V9 | `0x005a5bd0-0x005a7422` | UserPane key dispatcher virtual | TRUE | [UID:0000FQ] UserPane | `86/88` | Assign owner/emitter [UID:0000FQ]. |
| 0003VA | `0x005a7422-0x005a76c0` | UserPane key-dispatch switch tables | FALSE | generated by [UID:0003V9] | `86/90` | No owner/emitter; ignored standalone. |
| 0003VB | `0x005a76c0-0x005a82bd` | UserPane server-message dispatcher virtual | TRUE | [UID:0000FQ] UserPane | `86/88` | Assign owner/emitter [UID:0000FQ]. |
| 0003VC | `0x005a82bd-0x005a83b0` | UserPane server-message switch tables | FALSE | generated by [UID:0003VB] | `86/90` | No owner/emitter; ignored standalone. |
| 0003VD | `0x005a83b0-0x005a87ad` | UserPane animation/update virtual | TRUE | [UID:0000FQ] UserPane | `86/88` | Assign owner/emitter [UID:0000FQ]. |
| 0003VE | `0x005a87b0-0x005a87d5` | raw LivingObjectPane linked-record lookup helper | TRUE | [UID:00007B] LivingObjectPane | `85/86` | Assign owner/emitter [UID:00007B]. |

All reconstructable children in this recommendation clear `85/85`, and their direct parents also clear the gate:

- [UID:0000FQ] `by-class/UserPane.md` is `86/86`, emitter [UID:0000P1].
- [UID:0000P1] `by-file/UserPane.md` is `89/85`.
- [UID:00007B] `by-class/LivingObjectPane.md` is `85/85`, emitter [UID:0000KU].
- [UID:0000KU] `by-file/LivingObjectPane.md` is `88/85`.

Final C++ remains blank for all new pages. The reconstructable method pages meet the minimum score/emitter gate, but final source-quality names, field layouts, packet names, and exact helper signatures remain too provisional for final-output C++.

## Ranked Ownership Analysis

### 1. UserPane class/file for `0x005a5b80-0x005a87ad`

Evidence for:

- Existing [UID:0001KL], [UID:0000FQ], [UID:0000P1], and [UID:0002YU] docs all name these four modeled functions as `UserPane` virtuals.
- Raw pointer scan finds the function addresses only in UserPane vtable slots: `0x0062ef18`, `0x0062ef98`, `0x0062efa0`, and `0x0062efc4`.
- IDA decompile cache classifies all four functions with vtable class `NexusTK:UserPane`.
- The bodies are UI/event dispatcher methods: bounds update, key input, server-message routing, and animation-step routing.

Evidence against:

- Several callees are `LivingObjectPane` helpers. This is dependency evidence, not owner evidence, because UserPane is the local UI dispatcher and contains/uses living-object state.

Decision: accept. Exact method children [UID:0003V8], [UID:0003V9], [UID:0003VB], and [UID:0003VD] route to [UID:0000FQ].

### 2. Compiler-generated switch-table pages for `0x005a7422-0x005a76c0` and `0x005a82bd-0x005a83b0`

Evidence for:

- Both spans are not executable source methods. They consist of alignment, dword target runs pointing back into the immediately preceding UserPane method, byte selector maps, and trailing `0xcc`.
- Existing by-structure rules classify jump tables and alignment as compiler/linker-generated binary output, not standalone handwritten source.

Evidence against:

- They are in `.text`, not `.rdata`, so they must be explicitly accounted for in memory coverage.

Decision: create exact ignored/non-reconstructable pages [UID:0003VA] and [UID:0003VC], plus `by-memory/-ignored.md` ledger rows.

### 3. LivingObjectPane class/file for `0x005a87b0-0x005a87d5`

Evidence for:

- The raw helper uses `ecx + 0x13eb14` and `ecx + 0x13eb18`, the linked-record pointer/count fields used by adjacent LivingObjectPane linked-record cleanup helpers.
- The helper is directly adjacent to [UID:0003UF] `LivingObjectPaneClearAllLinkedRecords` and [UID:0003UG] `LivingObjectPaneClearLinkedRecordByIndex`.
- It returns a linked-record pointer only when the index is in range and the record active byte is nonzero, which is the same movement/linked-record state family documented on [UID:0001KM].

Evidence against:

- Raw scan found no absolute pointer hit and no rel32 branch/call target to `0x005a87b0`; source reachability is unproven.
- IDA did not model it as a function in the current docs.

Decision: accept as a raw LivingObjectPane helper at `85/86`, owner/emitter [UID:00007B], with C++ blank and explicit no-xref caveat. It is not safe to ignore as padding or compiler-generated table data.

### 4. Rejected: keep the whole leaf as a UserPane aggregate

Evidence for:

- Most of the leaf is UserPane-owned.

Evidence against:

- The leaf contains non-source switch tables and one raw LivingObjectPane helper. Keeping it as one reconstructable UserPane page would cross source families and leave compiler bytes mixed with source methods.

Decision: reject. Split exact children and ignored spans.

## Full Child Markdown Text

Create these seven files exactly, subject only to validator-required UID formatting if the supervisor allocates different UIDs.

### `by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md`

```markdown
*** UID:0003V8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a5b80-0x005a5bc7 UserPane OnBoundsChanged

## Status

- Address range: `0x005a5b80-0x005a5bc7`
- Entity kind: method
- Direct owner: [UID:0000FQ][UserPane](by-class/UserPane.md)
- Source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Containing aggregate: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- Split-index context: [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md)
- Rebuild handling: source-authored UserPane virtual method. C++ remains blank until final field/helper names are settled.

## Behavior

This virtual method receives a bounds rectangle, compares it against the cached rectangle at `this + 0x44`, and returns early if the bounds are unchanged. When the bounds changed, it copies the new rectangle into the cache, updates the child geometry at `this + 0x54` when needed, and forwards the bounds to the base/child pane at `this + 4`.

## Evidence

- IDA decompile cache `0x005a5b80.json` reports `sub_5A5B80`, size `0x47`, ending at `0x005a5bc7`.
- The decompiler shows calls to `0x004b7ed0` for rectangle comparison, `0x005546f0` for the child geometry check, and `0x00554800` for child/base bounds update.
- Raw pointer scan finds one absolute pointer to this method at `0x0062ef18`, matching [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md).
- The preceding span `0x005a5b79-0x005a5b80` is seven `0xcc` bytes, and the following span `0x005a5bc7-0x005a5bd0` is nine `0xcc` bytes, so the method boundary is closed.

## Ownership

Assign to [UID:0000FQ][UserPane](by-class/UserPane.md). The direct class parent is `86/86`, the source file [UID:0000P1][UserPane](by-file/UserPane.md) is `89/85`, and the only pointer evidence is the UserPane vtable slot. LivingObjectPane is only the neighboring split-index context.

## Score Rationale

Completion `86` reflects exact byte boundaries, decompiler behavior, vtable evidence, surrounding padding, owner/source placement, and support-doc integration. Confidence `89` is strong because all checked evidence points to a UserPane virtual, with only final field/helper names unresolved.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as the exact UserPane bounds-change child inside the remaining [UID:0001KM] largest leaf.
  - Evidence: byte audit, IDA decompile cache, raw vtable pointer scan, and current UserPane support docs.
```

### `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md`

```markdown
*** UID:0003V9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a5bd0-0x005a7422 UserPane HandleKeyEvent

## Status

- Address range: `0x005a5bd0-0x005a7422`
- Entity kind: method
- Direct owner: [UID:0000FQ][UserPane](by-class/UserPane.md)
- Source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Switch-table child: [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md)
- Rebuild handling: source-authored UserPane key/input dispatcher. Do not emit final C++ yet because field, packet, and helper names remain provisional.

## Behavior

This is the central local-player key dispatcher for `UserPane`. It rejects input during disabled/local-blocked states, normalizes the incoming key byte through `std::ctype<char>::do_narrow`, checks modifier bits, and dispatches key cases for local movement, attack/direction packets, hotkey/macro execution, item/spell/command input panes, chat/say input panes, target-selection state, right-click/help/damage/click-to-move option toggles, and miscellaneous UI panels.

Important delegated calls include:

- [UID:0003UD][0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md) for space/action handling.
- [UID:0003U6][0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement](by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md) for arrow-key movement dispatch.
- [UID:0003V0][0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket](by-memory/0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket.md) for directional attack sends.
- [UID:0003UB][0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction.md) for hotkey slot execution.
- UserPane slot-label helpers at `0x005a40d0` and `0x005a4310` for prompt text.

## Evidence

- IDA decompile cache `0x005a5bd0.json` reports `sub_5A5BD0`, size `0x1852`, ending at `0x005a7422`.
- Cache metadata classifies it as a `NexusTK:UserPane` virtual and lists 60 callees.
- The decompiler shows major switches at `0x005a5cbb`, `0x005a5db3`, and `0x005a5f05`, plus a nested movement-direction switch at `0x005a6e7b`.
- Raw pointer scan finds exactly one absolute pointer to the method at `0x0062ef98`, matching the UserPane vtable data page.
- The following [UID:0003VA] span is compiler-generated switch-table data for this method; it contains 81 dword-like target values that all point back inside this method.
- The preceding span `0x005a5bc7-0x005a5bd0` is nine `0xcc` bytes, so the start boundary is closed.

## Ownership

Assign to [UID:0000FQ][UserPane](by-class/UserPane.md). LivingObjectPane, SayInputPanes, Chatting, Quit, BlockListen, and other pane classes are callees/dependencies or allocated prompt classes, not the owner of this virtual dispatcher. [UID:0000FQ] is `86/86`, and [UID:0000P1] is `89/85`, so the strict gate is satisfied.

## Source-Quality Blockers Checked

- Field names: this retry checked the decompiler locals and current UserPane docs. Large offsets such as `this + 13052xx`, `this + 12616xx`, and input-event offsets remain behavior-named only.
- Helper names: callees were checked against current child docs. Movement/action helpers are properly left under LivingObjectPane; prompt constructors remain separate class/file dependencies.
- Packet names: command packet writes through `0x00574bb0` and helper encoders remain opcode/behavior-named rather than source-quality protocol names.
- Switch tables: [UID:0003VA] covers the compiler-generated table bytes and should be regenerated from this method's source switch logic.

## Score Rationale

Completion `86` is justified by exact function boundary, decompiler behavior, vtable slot, major switch/case structure, callee inventory, owner/source placement, and separated switch-table child. Confidence `88` is justified because class/vtable/source evidence is direct; it stays below final-source confidence because the method is large and still has provisional field, event, packet, and helper names.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md)
- [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as the exact UserPane key-handler child inside the remaining [UID:0001KM] largest leaf.
  - Evidence: byte audit, IDA decompile cache, raw vtable pointer scan, current UserPane support docs, and separated compiler switch-table child.
```

### `by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md`

```markdown
*** UID:0003VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a7422-0x005a76c0 UserPane HandleKeyEvent Switch Tables

## Status

- Address range: `0x005a7422-0x005a76c0`
- Entity kind: jump-table / switch-table data
- Owner method: [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md)
- Disposition: ignored as standalone source; source should regenerate this from the `UserPane::OnKeyEvent` switch logic.
- Rebuild handling: compiler-generated binary support data, not handwritten source.

## Byte Layout

- `0x005a7422-0x005a7424`: `66 90` alignment.
- `0x005a7424-0x005a7438`: five dword target entries into [UID:0003V9].
- `0x005a7438-0x005a7484`: selector/byte-table data.
- `0x005a7484-0x005a74ac`: ten dword target entries into [UID:0003V9].
- `0x005a74ac-0x005a7528`: selector/byte-table data.
- `0x005a7528-0x005a7620`: sixty-two dword target entries into [UID:0003V9].
- `0x005a7620-0x005a76ac`: selector/byte-table data.
- `0x005a76ac-0x005a76bc`: four dword target entries into [UID:0003V9].
- `0x005a76bc-0x005a76c0`: four `0xcc` alignment bytes before [UID:0003VB].

## Evidence

- Raw PE byte audit shows non-padding table bytes followed by `0xcc` tail alignment.
- Dword scan found 81 dword-like entries in this span, all pointing inside [UID:0003V9] `0x005a5bd0-0x005a7422`.
- IDA decompile cache for [UID:0003V9] shows multiple switches whose generated tables occupy this successor span.
- The next modeled/source function begins at [UID:0003VB] `0x005a76c0`.

## Ownership And Rebuild Handling

Do not assign owner/emitter metadata. This page is `RECONSTRUCTABLE:FALSE` because it is compiler-generated switch data. Rebuild the source-level key dispatch in [UID:0003V9], and let the compiler emit equivalent switch tables.

## Score Rationale

Completion `86` records exact boundaries, byte layout, target-run counts, owner method, ignored standalone disposition, and support-doc/coverage handling. Confidence `90` is high because all dword-like targets point back into the owner method and the tail alignment is byte-proven.

## Cross-References

- [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)
- [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as exact ignored switch-table child for the UserPane key handler.
  - Evidence: raw PE byte audit, dword-target scan, and IDA decompiler switch structure.
```

### `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`

```markdown
*** UID:0003VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a76c0-0x005a82bd UserPane HandleServerMessage

## Status

- Address range: `0x005a76c0-0x005a82bd`
- Entity kind: method
- Direct owner: [UID:0000FQ][UserPane](by-class/UserPane.md)
- Source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Switch-table child: [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md)
- Rebuild handling: source-authored UserPane server-message dispatcher. C++ remains blank until final packet/event names and field layouts are source-quality.

## Behavior

This virtual method dispatches server-message payloads routed to the local user pane. It initializes local message state when first entered, reads the payload pointer, switches on the first payload byte, and either performs UserPane-local state/UI updates or delegates packet bodies to LivingObjectPane packet handlers.

Delegated LivingObjectPane packet handlers include:

- `0x005aa480` player settings packet.
- `0x005aa710` spell-slot update packet.
- `0x005aac80` server-entry/login-state packet.
- `0x005ab090` and `0x005ab410` movement correction packets.
- `0x005ab860` chat-message packet.
- `0x005abda0` UI panel switch/open packet.
- `0x005ac070` message-show packet.
- `0x005ac280` linked-object/player companion packet.

The dispatcher itself remains UserPane-owned because it is a virtual method in the UserPane vtable and routes messages into the local UI/player surface.

## Evidence

- IDA decompile cache `0x005a76c0.json` reports `sub_5A76C0`, size `0xbfd`, ending at `0x005a82bd`.
- Cache metadata classifies it as a `NexusTK:UserPane` virtual and lists 52 callees.
- The decompiler shows a switch on `*payload`, including direct returns into the LivingObjectPane packet-handler children listed above.
- Raw pointer scan finds exactly one absolute pointer to the method at `0x0062efa0`, matching the UserPane vtable data page.
- The following [UID:0003VC] span contains 25 dword-like target values that all point back inside this method.

## Ownership

Assign to [UID:0000FQ][UserPane](by-class/UserPane.md). The LivingObjectPane packet handlers are callee/dependency bodies, not owner evidence for the dispatcher. [UID:0000FQ] and [UID:0000P1] both clear the strict gate.

## Source-Quality Blockers Checked

- Packet names: the first-byte opcode cases and delegated handlers were checked against current docs, but final protocol subtype names remain provisional.
- Field names: local state offsets and large record fields remain offset/behavior named.
- Helper names: UI/pane helpers and packet-buffer parsers are documented as dependencies where current docs exist, but exact original names are not recovered.
- Switch tables: [UID:0003VC] covers the compiler-generated table bytes for this dispatcher.

## Score Rationale

Completion `86` is justified by exact boundary, decompiler opcode-switch behavior, callee inventory, vtable slot, owner/source placement, and separated switch-table child. Confidence `88` is strong because the vtable and body role are direct; it remains below final-source confidence because packet subtypes and field names are still provisional.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md)
- [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as the exact UserPane server-message dispatcher child inside the remaining [UID:0001KM] largest leaf.
  - Evidence: byte audit, IDA decompile cache, raw vtable pointer scan, current UserPane support docs, and separated compiler switch-table child.
```

### `by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md`

```markdown
*** UID:0003VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a82bd-0x005a83b0 UserPane HandleServerMessage Switch Tables

## Status

- Address range: `0x005a82bd-0x005a83b0`
- Entity kind: jump-table / switch-table data
- Owner method: [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)
- Disposition: ignored as standalone source; source should regenerate this from the `UserPane::OnServerMessage` switch logic.
- Rebuild handling: compiler-generated binary support data, not handwritten source.

## Byte Layout

- `0x005a82bd-0x005a82c0`: `0f 1f 00` alignment.
- `0x005a82c0-0x005a8324`: twenty-five dword target entries into [UID:0003VB].
- `0x005a8324-0x005a83a4`: selector/byte-table data.
- `0x005a83a4-0x005a83b0`: twelve `0xcc` alignment bytes before [UID:0003VD].

## Evidence

- Raw PE byte audit shows non-padding table bytes followed by `0xcc` tail alignment.
- Dword scan found 25 dword-like entries in this span, all pointing inside [UID:0003VB] `0x005a76c0-0x005a82bd`.
- IDA decompile cache for [UID:0003VB] shows the server-message opcode switch whose generated table occupies this successor span.
- The next source method begins at [UID:0003VD] `0x005a83b0`.

## Ownership And Rebuild Handling

Do not assign owner/emitter metadata. This page is `RECONSTRUCTABLE:FALSE` because it is compiler-generated switch data. Rebuild the source-level server-message dispatch in [UID:0003VB], and let the compiler emit equivalent switch tables.

## Score Rationale

Completion `86` records exact boundaries, byte layout, target-run count, owner method, ignored standalone disposition, and support-doc/coverage handling. Confidence `90` is high because every dword-like target points back into the owner method and the tail alignment is byte-proven.

## Cross-References

- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)
- [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as exact ignored switch-table child for the UserPane server-message dispatcher.
  - Evidence: raw PE byte audit, dword-target scan, and IDA decompiler switch structure.
```

### `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`

```markdown
*** UID:0003VD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a83b0-0x005a87ad UserPane HandleAnimationStep

## Status

- Address range: `0x005a83b0-0x005a87ad`
- Entity kind: method
- Direct owner: [UID:0000FQ][UserPane](by-class/UserPane.md)
- Source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Rebuild handling: source-authored UserPane animation/update virtual method. C++ remains blank until final animation field names and helper signatures are settled.

## Behavior

This virtual method handles local-user animation/update events. The decompiler shows dispatch on event ids, per-frame movement phase updates, movement timer scheduling/refresh behavior, map-position helper calls, and calls into LivingObjectPane movement helpers for walk animation and directional animation.

Important callees include `0x0053bf40`, `0x0053c070`, `0x00597910`, `0x005a5a90`, `0x005a36f0`, `0x005a3770`, `0x005058b0`, and `0x005055e0`.

## Evidence

- IDA decompile cache `0x005a83b0.json` reports `sub_5A83B0`, size `0x3fd`, ending at `0x005a87ad`.
- Cache metadata classifies it as a `NexusTK:UserPane` virtual and lists 11 callees.
- The decompiler shows a switch at `0x005a83c1` with cases including animation/timer ids `20`, `1097094982`, and `1148076358`.
- Raw pointer scan finds exactly one absolute pointer to this method at `0x0062efc4`, matching the UserPane vtable data page.
- The following `0x005a87ad-0x005a87b0` bytes are three `0xcc` padding bytes before the raw LivingObjectPane helper [UID:0003VE].

## Ownership

Assign to [UID:0000FQ][UserPane](by-class/UserPane.md). LivingObjectPane helpers are callees for local-player movement state, while the virtual dispatch slot and method role are UserPane-owned. [UID:0000FQ] and [UID:0000P1] both clear the strict gate.

## Score Rationale

Completion `86` is justified by exact boundary, decompiler event/timer behavior, vtable slot, callee inventory, owner/source placement, and successor padding/raw-helper separation. Confidence `88` is strong because vtable and support docs agree; it remains below final-source confidence because animation field names and helper signatures are still provisional.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md)
- [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as the exact UserPane animation/update virtual child inside the remaining [UID:0001KM] largest leaf.
  - Evidence: byte audit, IDA decompile cache, raw vtable pointer scan, and current UserPane support docs.
```

### `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`

```markdown
*** UID:0003VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005a87b0-0x005a87d5 LivingObjectPane GetActiveLinkedRecordByIndex Raw

## Status

- Address range: `0x005a87b0-0x005a87d5`
- Entity kind: raw helper
- Direct owner: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- Source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Containing split index: [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md)
- Rebuild handling: likely source-authored LivingObjectPane helper. C++ remains blank because no current xref proves source reachability and linked-record field names are provisional.

## Behavior

This compact helper takes an index byte argument, checks whether the index is below the linked-record count at `this + 0x13eb18`, computes `this->linkedRecords + index * 0x10` from the pointer at `this + 0x13eb14`, and returns that record pointer only when the record's first byte is nonzero. Otherwise it returns zero.

## Byte Evidence

```asm
0x005a87b0  55                  push ebp
0x005a87b1  8b ec               mov ebp, esp
0x005a87b3  0f b6 55 08         movzx edx, byte ptr [ebp+8]
0x005a87b7  3b 91 18 eb 13 00   cmp edx, [ecx+0x13eb18]
0x005a87bd  7d 10               jge 0x005a87cf
0x005a87bf  8b 81 14 eb 13 00   mov eax, [ecx+0x13eb14]
0x005a87c5  c1 e2 04            shl edx, 4
0x005a87c8  03 c2               add eax, edx
0x005a87ca  80 38 00            cmp byte ptr [eax], 0
0x005a87cd  75 02               jne 0x005a87d1
0x005a87cf  33 c0               xor eax, eax
0x005a87d1  5d                  pop ebp
0x005a87d2  c2 04 00            retn 4
```

## Evidence

- Raw byte audit shows `0x005a87ad-0x005a87b0` is three `0xcc` bytes before this helper, and `0x005a87d5-0x005a87e0` is eleven `0xcc` bytes before [UID:0003UF].
- Raw pointer and rel32 scans found no absolute pointer hit and no branch/call target to `0x005a87b0`; this is a raw/no-xref helper in the current binary evidence.
- The helper uses the same linked-record pointer/count field neighborhood as adjacent LivingObjectPane linked-record helpers [UID:0003UF][0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords](by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md) and [UID:0003UG][0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex](by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md).
- The successor [UID:0003UF] has rel32 callers from movement packet handlers, proving the successor boundary is a real LivingObjectPane method start rather than table data.

## Ownership

Assign to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). The field offsets, record stride, and immediate adjacency to `ClearAllLinkedRecords` and `ClearLinkedRecordByIndex` outweigh the lack of current xrefs. Do not attach this helper to [UID:0000FQ][UserPane](by-class/UserPane.md); the preceding UserPane virtual ends at `0x005a87ad`, and the helper's state is LivingObjectPane linked-record state.

## Score Rationale

Completion `85` reflects exact bytes, closed padding boundaries, behavior-level disassembly, raw no-xref scan, adjacent owner evidence, and support-doc/coverage placement. Confidence `86` is strong enough for owner/emitter routing but capped by the lack of entry xrefs and unresolved final linked-record field names.

## Cross-References

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md)
- [UID:0003UF][0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords](by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md)
- [UID:0003UG][0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex](by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md)

## Changes

- 2026-06-16 B001 retry executable split:
  - Created as the exact raw LivingObjectPane helper found inside the previous `0x005a87ad-0x005a87e0` gap.
  - Evidence: byte audit, raw pointer/rel32 no-xref scan, and adjacent linked-record helper ownership.
```

## Exact Ignored Ledger Text

Add this block to `by-memory/-ignored.md` near the existing `0x005a...` local-player alignment entries. This is a new insert, not a replacement.

```markdown
- `0x005a5b79-0x005a5b80`, `0x005a5bc7-0x005a5bd0`, `0x005a7422-0x005a76c0`, `0x005a82bd-0x005a83b0`, `0x005a87ad-0x005a87b0`, and `0x005a87d5-0x005a87e0` - UserPane/LivingObjectPane local-player event-band padding and switch-table support.
  - Why ignored: these spans are not standalone handwritten source. `0x005a5b79-0x005a5b80`, `0x005a5bc7-0x005a5bd0`, `0x005a87ad-0x005a87b0`, and `0x005a87d5-0x005a87e0` are pure `0xcc` alignment. `0x005a7422-0x005a76c0` is compiler-generated switch/jump-table and selector-map data for [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md). `0x005a82bd-0x005a83b0` is compiler-generated switch/jump-table and selector-map data for [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md).
  - Evidence: 2026-06-16 B001 retry raw PE byte audit over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `0x005a7422-0x005a76c0` has 81 dword-like entries pointing back inside [UID:0003V9] plus tail `0xcc`, and `0x005a82bd-0x005a83b0` has 25 dword-like entries pointing back inside [UID:0003VB] plus tail `0xcc`.
  - Replacement/procurement: rebuild [UID:0003V9] and [UID:0003VB] as source-level switch logic and let the compiler regenerate equivalent table/alignment bytes; ignore pure alignment bytes.
```

## Exact Coverage Insert Rows

Do not replace or delete the existing [UID:0001KM], [UID:0003UE], or [UID:0003UF] rows. Insert this exact block under [UID:0001KM] after the existing [UID:0003UE] row and before the existing [UID:0003UF] row.

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a5b79-0x005a5b80 | padding | UserPane event-band alignment after LivingObjectPane warp helper : ignored : 100% : strong : 2026-06-16 B001 retry byte audit shows seven `0xcc` bytes after [UID:0003UE] and before [UID:0003V8].
        - [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md) 0x005a5b80-0x005a5bc7 | method | UserPaneOnBoundsChanged : reconstructable : 86% : strong : Exact UserPane bounds-change virtual; IDA decompile cache reports size 0x47, raw pointer scan finds vtable slot 0x0062ef18, and surrounding padding is byte-proven.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a5bc7-0x005a5bd0 | padding | UserPane bounds-to-key handler alignment : ignored : 100% : strong : 2026-06-16 B001 retry byte audit shows nine `0xcc` bytes before [UID:0003V9].
        - [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md) 0x005a5bd0-0x005a7422 | method | UserPaneHandleKeyEvent : reconstructable : 86% : strong : Exact UserPane key/input dispatcher; IDA decompile cache reports size 0x1852, vtable slot 0x0062ef98, key/modifier switch behavior, prompt/input-pane creation, command packets, and LivingObjectPane callee dependencies with final field/protocol names still unresolved.
        - [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md) 0x005a7422-0x005a76c0 | jump-table | UserPaneHandleKeyEventSwitchTables : ignored : 86% : very-strong : Compiler-generated switch/jump-table and selector-map bytes for [UID:0003V9]; B001 byte audit found 81 dword-like entries pointing back inside the owner method plus `0x005a76bc-0x005a76c0` tail padding.
        - [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) 0x005a76c0-0x005a82bd | method | UserPaneHandleServerMessage : reconstructable : 86% : strong : Exact UserPane server-message dispatcher; IDA decompile cache reports size 0xbfd, vtable slot 0x0062efa0, opcode dispatch, and calls to LivingObjectPane packet handler children as dependencies rather than ownership.
        - [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md) 0x005a82bd-0x005a83b0 | jump-table | UserPaneHandleServerMessageSwitchTables : ignored : 86% : very-strong : Compiler-generated switch/jump-table and selector-map bytes for [UID:0003VB]; B001 byte audit found 25 dword-like entries pointing back inside the owner method plus `0x005a83a4-0x005a83b0` tail padding.
        - [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) 0x005a83b0-0x005a87ad | method | UserPaneHandleAnimationStep : reconstructable : 86% : strong : Exact UserPane animation/update virtual; IDA decompile cache reports size 0x3fd, vtable slot 0x0062efc4, animation/timer event dispatch, and LivingObjectPane movement helper callees.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a87ad-0x005a87b0 | padding | UserPane animation handler to raw LivingObjectPane helper alignment : ignored : 100% : strong : 2026-06-16 B001 retry byte audit shows three `0xcc` bytes before [UID:0003VE].
        - [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) 0x005a87b0-0x005a87d5 | raw-helper | LivingObjectPaneGetActiveLinkedRecordByIndexRaw : reconstructable : 85% : strong : Exact raw LivingObjectPane linked-record active-check helper; byte audit decodes index/count/pointer/active-byte logic over `this+0x13eb14/0x13eb18`, raw pointer/rel32 scans find no entry xrefs, and adjacency ties it to [UID:0003UF]/[UID:0003UG].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a87d5-0x005a87e0 | padding | LivingObjectPane raw linked-record helper alignment : ignored : 100% : strong : 2026-06-16 B001 retry byte audit shows eleven `0xcc` bytes before [UID:0003UF].
```

Expected effect: `auto-generated/by-memory-tool-report.md` should stop listing `0x005a5b79-0x005a87e0` as a largest leaf.

## Exact Support-Doc Edits

### [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

Add these entries to `## Exact Child Pages` after [UID:0003UE] and before [UID:0003UF]:

```markdown
- [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md)
- [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md)
- [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md)
- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)
- [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md)
- [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md)
- [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md)
```

Add this paragraph to `## Neighboring Exclusions`:

```markdown
- 2026-06-16 B001 retry fully split the former memory-tool leaf `0x005a5b79-0x005a87e0`: [UID:0003V8], [UID:0003V9], [UID:0003VB], and [UID:0003VD] are UserPane virtual methods; [UID:0003VA] and [UID:0003VC] are ignored compiler switch-table spans; [UID:0003VE] is a raw LivingObjectPane linked-record helper; the remaining bytes are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry executable leaf split:
  - What existed before: `auto-generated/by-memory-tool-report.md` still listed `0x005a5b79-0x005a87e0` as the largest remaining leaf under this non-emitting split index.
  - Changed to: recommended exact child pages [UID:0003V8]-[UID:0003VE] plus ignored rows that fully classify the leaf into UserPane methods, UserPane switch-table bytes, a raw LivingObjectPane helper, and padding.
  - Summary/evidence: B001 byte-audited every former gap, checked IDA decompile cache for the four UserPane virtuals, scanned raw absolute and rel32 xrefs, and confirmed [UID:0003VE] is source-authored LivingObjectPane linked-record logic rather than padding.
```

### [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`

Add this section after `## IDA Function Map`:

```markdown
## Exact Child Pages For 0x005a5b80-0x005a87ad

- [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md)
- [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md)
- [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md)
- [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)
- [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md)
- [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md)

2026-06-16 B001 retry byte-audited the complete local event band. The `0x005a7422-0x005a76c0` and `0x005a82bd-0x005a83b0` spans are compiler-generated switch-table bytes owned by the preceding UserPane methods, not standalone source methods. The raw helper at `0x005a87b0-0x005a87d5` belongs to LivingObjectPane linked-record state and is intentionally not a UserPane child.
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry exact local event-band split:
  - Scores remain `85/86`.
  - Added exact children [UID:0003V8], [UID:0003V9], [UID:0003VA], [UID:0003VB], [UID:0003VC], and [UID:0003VD] for the UserPane virtual/switch-table band inside `0x005a5b80-0x005a87ad`.
  - Evidence: raw byte audit, IDA decompile cache for the four virtual methods, raw vtable pointer scan at `0x0062ef18`, `0x0062ef98`, `0x0062efa0`, and `0x0062efc4`, and switch-table target scans.
```

### [UID:0000FQ] `by-class/UserPane.md`

Replace method-family rows for the four virtuals with linked rows:

```markdown
| `OnBoundsChanged` | [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md) | Updates cached bounds and invalidates child geometry. |
| `OnKeyEvent` | [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md), switch-table child [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md) | Handles local-player keyboard commands and dispatches related panes/packets. |
| `OnServerMessage` | [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), switch-table child [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md) | Handles server message payloads routed to the local user pane. |
| `OnAnimationStep` | [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md) | Handles animation/update ticks. |
```

Add this evidence bullet:

```markdown
- 2026-06-16 B001 retry split the former `0x005a5b79-0x005a87e0` leaf into exact UserPane method children [UID:0003V8], [UID:0003V9], [UID:0003VB], and [UID:0003VD], ignored switch-table children [UID:0003VA] and [UID:0003VC], and a separate LivingObjectPane raw helper [UID:0003VE]. Scores remain `86/86`; this was an exact child/support update, not a full class rescore.
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry local event-band child split:
  - Scores remain `86/86`.
  - Added exact child links for [UID:0003V8]-[UID:0003VD] and recorded [UID:0003VE] as a LivingObjectPane exclusion.
  - Evidence: byte-audited `0x005a5b79-0x005a87e0`, checked IDA decompile cache for the four UserPane virtuals, and confirmed the only absolute pointers to the method starts are UserPane vtable slots.
```

### [UID:0000P1] `by-file/UserPane.md`

Replace the file-contents rows for the local event methods with:

```markdown
| `OnBoundsChanged` / `OnKeyEvent` | [UID:0003V8][0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged](by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md), [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md), [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md) | Geometry update and key-driven local player commands; switch-table bytes are compiler-generated from the key dispatcher source. |
| `OnServerMessage` | [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md) | Handles server message payloads routed to the local user pane; switch-table bytes are compiler-generated from the server-message dispatcher source. |
| `OnAnimationStep` / `OnClipBounds` | [UID:0003VD][0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep](by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md), `0x005a8840-0x005a88cf` | Animation update and clipping behavior. The raw `0x005a87b0-0x005a87d5` helper between them belongs to LivingObjectPane linked-record state, not UserPane. |
```

Add this evidence bullet:

```markdown
- 2026-06-16 B001 retry resolves the prior [UID:0001KM] memory-tool leaf inside the UserPane event band: exact method children [UID:0003V8], [UID:0003V9], [UID:0003VB], and [UID:0003VD] route to this file through [UID:0000FQ]; switch-table children [UID:0003VA] and [UID:0003VC] are compiler-generated/non-emitting; [UID:0003VE] is excluded to LivingObjectPane. File scores remain `89/85`.
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry local event-band child split:
  - Scores remain `89/85`.
  - Added exact child links for UserPane event-band method pages [UID:0003V8], [UID:0003V9], [UID:0003VB], and [UID:0003VD], plus ignored switch-table children [UID:0003VA] and [UID:0003VC].
  - Evidence: B001 byte audit, IDA decompile cache for the method bodies, raw vtable pointer scan, and existing UserPane class/file source placement.
```

### [UID:00007B] `by-class/LivingObjectPane.md`

Update the `Local movement and commands` family row to include [UID:0003VE]:

```markdown
| Local movement and commands | `0x005a2de0-0x005a8e66`, including [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) | Viewport position, movement send path, walk animation setup, spell/command slot use, action gate, warp, linked-record lookup/cleanup, screen update, and movement packet send. |
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry raw linked-record helper:
  - Scores remain `85/85`.
  - Added [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) as a local movement/linked-record helper.
  - Evidence: raw byte audit decodes `this+0x13eb14/0x13eb18` linked-record pointer/count logic, no pointer/rel32 xrefs to the raw helper start, and adjacency to [UID:0003UF]/[UID:0003UG].
```

### [UID:0000KU] `by-file/LivingObjectPane.md`

Replace the `Movement history helpers` contents row with:

```markdown
| Movement history helpers | [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md), `0x005a87e0`, `0x005a8810`, `0x005a9310` | Keep with living-object movement/prediction state. |
```

Update the `Player movement and prediction` row to include [UID:0003VE]:

```markdown
| Player movement and prediction | `0x005a2e00`, `0x005a5a90`, [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md), `0x005a87e0`, `0x005a8810`, `0x005a8cf0`, `0x005a9310`, `0x005ab090`, `0x005ab410` | Sends movement/facing packets, records prediction history, queries/clears linked records, handles server correction, and warps local position. |
```

Add this `## Changes` entry:

```markdown
- 2026-06-16 B001 retry raw linked-record helper:
  - Scores remain `88/85`.
  - Added [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) as a local movement/linked-record helper.
  - Evidence: B001 byte audit and no-xref scan classify the helper as source-authored linked-record logic, not UserPane code or padding, with direct adjacency to `0x005a87e0` and `0x005a8810`.
```

## Validation Order

Supervisor should apply docs in this order:

1. Create new child pages [UID:0003V8]-[UID:0003VE].
2. Update `by-memory/-ignored.md`.
3. Update [UID:0001KM], [UID:0001KL], `by-class/UserPane.md`, `by-file/UserPane.md`, `by-class/LivingObjectPane.md`, and `by-file/LivingObjectPane.md`.
4. Insert the coverage block into `by-memory/-coverage-report.md`.
5. Run validators.
6. Run memory-ranges report.

Suggested validation commands:

> Executable block R001 was removed from this report and preserved verbatim in [0001KM-livingobject-localplayer-source-split-retry-removed.md](0001KM-livingobject-localplayer-source-split-retry-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation result:

- All scoped validators should return `ok:1`.
- `auto-generated/by-memory-tool-report.md` should no longer list `0x005a5b79-0x005a87e0`.
- No new Barrier, General, Filename, or Advanced errors should appear for [UID:0001KM].
- [UID:0001KM] should remain non-emitting and should not produce C++.

## Changed Files

Report-only in this B001 turn:

- Modified: `tools/leaser/Agents/Agent-B001/research/0001KM-livingobject-localplayer-source-split-retry.md`

No by-* docs, generated reports, IDA database state, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, or shared ledgers were edited by B001 in this retry.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-retry.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001KM"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KM-livingobject-localplayer-source-split-retry-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-retry.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
