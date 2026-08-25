** TARGET-REPORT-UID:00013A **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00013A] AddEmployeeItemDialog source-quality report

Assignment: `B004-goal2-add-employee-item-dialog-source-quality-00013A-20260618`
Target: `by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md`
Report-only path: `tools/leaser/Agents/Agent-B004/research/00013A-AddEmployeeItemDialog-source-quality.md`
Agent: `Agent-B004`
Date: 2026-06-18

## Executive Recommendation

Raise [UID:00013A] from `84/88` to `88/90`, keep `CANONICAL_OWNER:000006`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:000006`, and populate first-draft C++ for the source-authored `AddEmployeeItemDialog::OnButtonClick` behavior plus the ordinary empty derived destructor.

Do not emit source C++ for the disputed raw constructor island [UID:000139] at `0x004a4ae0`. Current local PE evidence and existing IDA-backed docs support it as retained constructor-shaped duplicate/orphan evidence with no direct route. The live construction path is the inline allocation/base-constructor/vtable-patch sequence in `EmployeeDialogPane::OnButtonAction` around `0x004a339f`, with the owner pointer stored at `+0x270`.

Do not emit handwritten source for the adjustor thunks at `0x004a4cb1-0x004a4cf3`, the padding at `0x004a4cf3-0x004a4d00`, or the scalar deleting destructor wrapper flags at `0x004a4d00-0x004a4d3b`. The source-facing destructor is an empty/default `AddEmployeeItemDialog::~AddEmployeeItemDialog()` whose compiler wrapper calls the base `AddItemDialog` destructor and performs scalar/vector delete according to flag bits.

The stale target wording that calls `0x005975e0` an employee command helper should be replaced. `0x005975e0` is the generic `TimerHandler::ScheduleTimer` wrapper also documented by [UID:0001K8] and [UID:0002HI]. In this target, the add-item command is queued as event id `5` through the owner object's `+0xa4` timer/event subobject; the later employee command sender is `EmployeeDialogPane::SendCommand` at `0x004a2c80`.

## Evidence Inputs

- Local PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- PE image base: `0x00400000`
- `.text`: RVA `0x00001000`, virtual size `0x20b4ac`, raw pointer `0x00000400`, raw size `0x20b600`
- `.rdata`: RVA `0x0020d000`, raw pointer `0x0020ba00`
- `.data`: RVA `0x0026d000`, raw pointer `0x0026ac00`
- VA-to-file-offset formula for `.text`: `raw = 0x400 + ((VA - 0x400000) - 0x1000)`
- IDA MCP status: `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded : False`, so this pass used the local PE, existing IDA-backed by-* docs, and local dword/rel32 scans.

## Exact Range, Raw Offsets, Bytes, Padding

The assigned half-open target envelope is `0x004a4b20-0x004a4d3b`, raw file offset `0x000a3f20-0x000a413b`, length `0x21b`, SHA256 `779c4745617ad63413430211e8f2425d7ec5e171decc1dfd30d436c3332be6ff`.

Range map:

| Range | Raw offset | Length | SHA256 | Interpretation |
|---|---:|---:|---|---|
| `0x004a4adb-0x004a4ae0` | `0x000a3edb` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` | Five `int3` bytes before raw constructor island. |
| `0x004a4ae0-0x004a4b20` | `0x000a3ee0` | `0x40` | `73190900bca25f34c5ab42e731898e3deecc5a0bf199f03e82e53b053c021ffb` | [UID:000139] retained constructor-shaped raw island plus trailing `cc`. |
| `0x004a4b20-0x004a4cb1` | `0x000a3f20` | `0x191` | `32f26bec6c40197762cb6ce520d1b87c3a376bc936955b9859ac9d34b541197d` | `AddEmployeeItemDialog::OnButtonClick`, source-authored. |
| `0x004a4cb1-0x004a4cc7` | `0x000a40b1` | `0x16` | `ac08ecacead0e68884cf73f6b4d455d9f53d16f2c2e01dc6f4d7bb75e925785b` | AddEmployee secondary/tertiary adjustor thunks. |
| `0x004a4cc7-0x004a4cf3` | `0x000a40c7` | `0x2c` | `9424c92852184add8f5d3ff40aee8d5d2455de5bc9e163603df5bf33aff7054a` | Sibling EmployeeDialogPane and EmployeeItemProperty adjustor thunks. |
| `0x004a4cf3-0x004a4d00` | `0x000a40f3` | `0xd` | `0d0bb866505bc0e2d4276fcdee1afdc8887662d04cce9e4bbb4c10fba6d0f1ce` | Thirteen `int3` padding bytes. |
| `0x004a4d00-0x004a4d3b` | `0x000a4100` | `0x3b` | `2c5d218acd133e62acdc08c1afeacb5fe3c773916af4028a47b12809334209d1` | Scalar deleting destructor wrapper. |
| `0x004a4d3b-0x004a4d40` | `0x000a413b` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` | Five `int3` bytes before next function. |

Raw bytes for the disputed constructor island and target envelope:

```text
004a4ae0: 55 8b ec 51 56 6a 00 8b f1 6a 00 89 75 fc e8 cd
004a4af0: 99 00 00 8b 45 08 89 86 70 02 00 00 8b c6 c7 06
004a4b00: d4 90 61 00 c7 86 a0 00 00 00 34 91 61 00 c7 86
004a4b10: a4 00 00 00 64 91 61 00 5e 8b e5 5d c2 04 00 cc

004a4b20: 55 8b ec 6a ff 68 68 d9 5f 00 64 a1 00 00 00 00
004a4b30: 50 81 ec 08 06 00 00 a1 24 2f 67 00 33 c5 89 45
004a4b40: f0 53 56 57 50 8d 45 f4 64 a3 00 00 00 00 8b f1
004a4b50: 8b 4d 08 8b c1 83 e8 01 74 10 ff 75 0c 51 8b ce
004a4b60: e8 cb 9d 00 00 e9 29 01 00 00 8b 8e fc 01 00 00
004a4b70: 6a 03 8b 01 ff 50 10 68 00 01 00 00 8b 00 8b b8
004a4b80: 08 01 00 00 8d 85 f0 f9 ff ff 50 8b cf e8 ee f2
004a4b90: 04 00 83 f8 01 7e 42 68 70 02 00 00 e8 ff fe 04
004a4ba0: 00 83 c4 04 89 85 ec f9 ff ff c7 45 fc 00 00 00
004a4bb0: 00 85 c0 0f 84 aa 00 00 00 6a 00 68 18 3a 61 00
004a4bc0: 56 68 9c 92 61 00 8b c8 e8 e3 b2 ff ff c7 45 fc
004a4bd0: ff ff ff ff e9 ac 00 00 00 ff b5 f0 f9 ff ff 8b
004a4be0: cf e8 da f1 04 00 8b 9e 70 02 00 00 8b f8 0f b6
004a4bf0: 0f 51 8b 0d 48 a7 67 00 e8 73 ec 0f 00 c7 83 20
004a4c00: 04 00 00 00 00 00 00 80 b8 ec 01 00 00 00 74 5c
004a4c10: 8b 0d 50 a7 67 00 68 f7 00 00 00 e8 30 b7 04 00
004a4c20: 50 8d 85 f0 fd ff ff 68 00 01 00 00 50 e8 7e 6d
004a4c30: f7 ff 68 74 02 00 00 e8 64 fe 04 00 83 c4 10 89
004a4c40: 85 ec f9 ff ff c7 45 fc 01 00 00 00 85 c0 74 13
004a4c50: 0f b6 0f 51 53 8d 8d f0 fd ff ff 51 8b c8 e8 0d
004a4c60: fb ff ff c7 45 fc ff ff ff ff eb 19 ff b0 e8 01
004a4c70: 00 00 0f be 07 8d 8b a4 00 00 00 50 6a 00 6a 05
004a4c80: e8 5b 29 0f 00 8b ce e8 04 9f ff ff 8b ce e8 3d
004a4c90: 8e ff ff 8b 4d f4 64 89 0d 00 00 00 00 59 5f 5e
004a4ca0: 5b 8b 4d f0 33 cd e8 84 2a 12 00 8b e5 5d c2 08
004a4cb0: 00

004a4cb1: 81 e9 a0 00 00 00 e9 44 00 00 00 81 e9 a4 00 00
004a4cc1: 00 e9 39 00 00 00 81 e9 a0 00 00 00 e9 6e 00 00
004a4cd1: 00 81 e9 a4 00 00 00 e9 63 00 00 00 81 e9 a0 00
004a4ce1: 00 00 e9 48 01 00 00 81 e9 a4 00 00 00 e9 3d 01
004a4cf1: 00 00 cc cc cc cc cc cc cc cc cc cc cc cc cc 55
004a4d01: 8b ec 56 8b f1 e8 f5 9b 00 00 8b 45 08 a8 01 74
004a4d11: 22 a8 04 75 10 56 e8 a4 fd 04 00 83 c4 04 8b c6
004a4d21: 5e 5d c2 04 00 68 74 02 00 00 56 e8 6f 69 f7 ff
004a4d31: 83 c4 08 8b c6 5e 5d c2 04 00 cc cc cc cc cc
```

## Instruction Shape And Behavior

`0x004a4b20-0x004a4cb1` is a `thiscall` handler with two stack parameters and `ret 8`. The first parameter is the button/action id. If it is not `1`, the method forwards directly to `AddItemDialog::OnButtonClick` at `0x004ae930` and returns. This proves the base AddItemDialog fallback path.

For button id `1`, the method:

1. Reads the child/control manager at `this + 0x1fc`, asks for child id `3`, and follows the returned control to its list/selection object at `+0x108`.
2. Calls the shared selected-index collector at `0x004f3e80(list, localSelectedBytes, 0x100)`.
3. If selected count is greater than one, allocates `0x270` bytes and constructs an `AlertPane` through `0x0049feb0` with text pointer `0x0061929c`, owner `this`, OK string pointer `0x00613a18`, and trailing zero. The English source-facing meaning is "Cannot add multiple items at once"; the OK string is the shared dialog OK resource.
4. If selected count is `<= 1`, calls the selected-row helper at `0x004f3dc0(list, selectedBytes[0])`. The first byte of that row is the selected item/inventory slot. The binary does not special-case zero selected rows.
5. Reads `EmployeeDialogPane *owner` from `this + 0x270`, proving the derived field documented in [UID:0001TN].
6. Calls the current-user item lookup through global `dword_67A748` and function `0x005a3870(selectedSlot)`.
7. Clears `owner + 0x420` to zero. Best source-facing name is `m_pendingQuantity` or `m_pendingItemCount`.
8. Tests item metadata byte `item + 0x1ec`. A nonzero value means this item needs quantity input. This is best named `requiresQuantityPrompt` or `isStackCountPromptItem`, not a generic unknown flag.
9. For quantity-input items, obtains localized resource id `247` from `dword_67A750` via `0x004f0350`, formats/copies it with `0x0041b9b0`, allocates `0x274` bytes, and constructs `EmployeeQuantityInputDialogPane` through `0x004a4770(prompt, owner, selectedSlot)`. Existing resource docs identify id `247` as "Add how many?".
10. For non-quantity-input items, pushes `item + 0x1e8`, signed selected slot, `0`, and event id `5`, sets `ecx = owner + 0xa4`, and calls `0x005975e0`. This is a generic TimerHandler schedule call on the owner's event/timer subobject, not the employee packet sender itself. Existing docs show `EmployeeDialogPane::SendCommand` at `0x004a2c80` later handles command kind `5`.
11. For all handled button-id-1 paths, calls `0x0049eb90(this)` and `0x0049dad0(this)`. Existing DialogPane docs support `0x0049eb90` as the slide-close animation helper and `0x0049dad0` as the shared close/destroy path.

`0x004a4cb1-0x004a4cc7` is exactly two compiler adjustor thunks for AddEmployee secondary and tertiary vtable views:

```asm
004a4cb1  sub ecx, 0xa0
004a4cb7  jmp 0x004a4d00
004a4cbc  sub ecx, 0xa4
004a4cc2  jmp 0x004a4d00
```

`0x004a4cc7-0x004a4cf3` is four sibling class thunks, not AddEmployee source:

```asm
004a4cc7  sub ecx, 0xa0 ; EmployeeDialogPane secondary -> 0x004a4d40
004a4cd2  sub ecx, 0xa4 ; EmployeeDialogPane tertiary -> 0x004a4d40
004a4cdd  sub ecx, 0xa0 ; EmployeeItemProperty secondary -> 0x004a4e30
004a4ce8  sub ecx, 0xa4 ; EmployeeItemProperty tertiary -> 0x004a4e30
```

`0x004a4cf3-0x004a4d00` is padding only.

`0x004a4d00-0x004a4d3b` is a scalar deleting destructor wrapper:

1. Saves `this`.
2. Calls base `AddItemDialog` destructor at `0x004ae900`.
3. Tests delete flag bit `0x01`.
4. If bit `0x01` is clear, returns `this` without freeing memory.
5. If bit `0x01` is set and bit `0x04` is clear, calls ordinary delete/free at `0x004f4ac0(this)`.
6. If bit `0x01` and bit `0x04` are both set, calls the sized/vector-style delete helper at `0x0041b6a0(this, 0x274)`.
7. Returns `this`, `ret 4`.

The source-facing destructor is therefore empty/default except for base destruction; the delete flags and object-size path are compiler wrapper details.

## Constructor Dispute Resolution

[UID:000139] at `0x004a4ae0-0x004a4b20` is constructor-shaped and source-authored in content:

```asm
004a4ae0  push ebp
004a4ae8  push 0
004a4aea  push 0
004a4aef  call 0x004ae4c0          ; AddItemDialog base constructor
004a4af5  mov eax, [ebp+8]
004a4af8  mov [esi+0x270], eax     ; owner EmployeeDialogPane *
004a4afe  mov dword ptr [esi], 0x006190d4
004a4b04  mov dword ptr [esi+0xa0], 0x00619134
004a4b0e  mov dword ptr [esi+0xa4], 0x00619164
004a4b1c  ret 4
004a4b1f  int3
```

However, current evidence does not support treating it as the live construction route:

- Local dword scan found zero pointer-table/vtable/callback data hits to `0x004a4ae0`.
- Local rel32 scan found zero call/jump/jcc routes to `0x004a4ae0`.
- Existing IDA-backed target docs report no IDA function at `0x004a4ae0`, previous function ending before it, next function starting at `0x004a4b20`, and no direct xrefs to the raw constructor start.
- The live inline construction path at `0x004a339f` calls the same base constructor `0x004ae4c0`, stores the same three vtable addresses, and stores the same owner pointer at `+0x270`. Its inline path is already documented by [UID:0000TT].
- Positive controls worked: local rel32 scans found the fan-in to `0x004ae4c0`, `0x004a4770`, `0x005975e0`, `0x0049eb90`, and `0x0049dad0`, and dword scans found vtable slot refs for `0x004a4b20`, `0x004a4cb1`, `0x004a4cbc`, and `0x004a4d00`. Therefore the no-route result for `0x004a4ae0` is meaningful, not a broken scanner artifact.

Recommendation: keep [UID:000139] documented as retained raw constructor-shaped evidence under `AddEmployeeItemDialog`, but do not emit a standalone constructor call/body from it. If the generator treats [UID:000139] as code-emitting, clear its `EMITTER_UIDS` and add the no-code proof below. Source construction should be represented through the inline `EmployeeDialogPane::OnButtonAction` construction path and class layout docs, not by making 00013A or 000139 call the orphan island.

## Vtable And Reachability Evidence

Local dword hits:

| Value | Hits | Meaning |
|---:|---|---|
| `0x004a4ae0` | none | No pointer-table route to raw constructor island. |
| `0x004a4b20` | `0x0061911c` | Primary vtable slot for `OnButtonClick`. |
| `0x004a4cb1` | `0x00619134` | Secondary vtable slot for AddEmployee adjustor thunk. |
| `0x004a4cbc` | `0x00619164` | Tertiary vtable slot for AddEmployee adjustor thunk. |
| `0x004a4d00` | `0x006190d4` | Primary vtable destructor slot. |
| `0x006190d4` | instruction immediates at `0x004a33a6`, `0x004a4b00` | Primary vtable stores in live inline constructor and raw constructor island. |
| `0x00619134` | instruction immediates at `0x004a33b0`, `0x004a4b0a` | Secondary vtable stores in live inline constructor and raw constructor island. |
| `0x00619164` | instruction immediates at `0x004a33ba`, `0x004a4b14` | Tertiary vtable stores in live inline constructor and raw constructor island. |

Local rel32 hits:

| Target | Hits | Interpretation |
|---:|---|---|
| `0x004a4ae0` | none | No direct call/jump route to raw constructor island. |
| `0x004a4b20` | none | Vtable-only virtual entry; no direct/static caller found. |
| `0x004a4d00` | `0x004a4cb7`, `0x004a4cc2` | AddEmployee adjustor thunks jump to scalar deleting destructor wrapper. |
| `0x004ae4c0` | `0x004a339f`, `0x004a4aee`, plus other AddItemDialog construction users | Positive control and constructor callee. |
| `0x004a4770` | `0x004a24f2`, `0x004a32b6`, `0x004a4c5e` | EmployeeQuantityInputDialogPane construction users. |
| `0x005975e0` | 163 calls | Generic TimerHandler scheduling wrapper, not employee-specific helper. |
| `0x0049eb90` | 74 calls | Shared DialogPane slide-close helper. |
| `0x0049dad0` | 132 calls | Shared DialogPane close/destroy helper. |

Vtable data [UID:0002MH] at `0x006190d0-0x0061916c` supports the target:

- `0x006190d0 -> 0x00646a54`: primary COL.
- `0x006190d4 -> 0x004a4d00`: primary destructor slot.
- `0x0061911c -> 0x004a4b20`: primary `OnButtonClick` slot.
- `0x00619130 -> 0x00646b04`: secondary COL.
- `0x00619134 -> 0x004a4cb1`: secondary adjustor thunk.
- `0x00619160 -> 0x00646b18`: tertiary COL.
- `0x00619164 -> 0x004a4cbc`: tertiary adjustor thunk.

## Direct Answers To Target Open Questions

| Question | Answer |
|---|---|
| Is `0x004a4ae0` the live AddEmployee constructor? | No current route proves it live. It is constructor-shaped retained raw evidence. The live construction path is inline at `0x004a339f` in `EmployeeDialogPane::OnButtonAction`. |
| What is the exact confirmed method/destructor cluster? | `0x004a4b20-0x004a4cb1` source handler, `0x004a4cb1-0x004a4cc7` AddEmployee thunks, `0x004a4cc7-0x004a4cf3` sibling thunks, `0x004a4cf3-0x004a4d00` padding, `0x004a4d00-0x004a4d3b` scalar deleting destructor wrapper. |
| Are vtable refs valid? | Yes. `OnButtonClick` is referenced by primary slot `0x0061911c`; destructor by `0x006190d4`; AddEmployee adjustors by `0x00619134` and `0x00619164`. |
| Should adjustor thunks emit source? | No. They are compiler thunks and are already covered by [UID:00013B]. |
| Should the scalar deleting destructor emit source? | Only as an ordinary empty/default destructor declaration/body if needed. The flag tests and delete/free calls are compiler wrapper details. |
| What is `this + 0x270`? | `EmployeeDialogPane *m_owner`; proven by constructor/raw-constructor stores and handler reads. |
| What is state/control child slot `3`? | The AddItemDialog selection list/control child id used to retrieve the selected item list. |
| What is selected-row byte `row[0]`? | Selected inventory/item slot index. Exact original field name is not proven; source-facing `selectedSlot` is high confidence. |
| What are item fields `+0x1ec` and `+0x1e8`? | `+0x1ec` is a quantity-prompt/stackable-like flag. `+0x1e8` is the count/amount payload passed for direct add command event 5. Field names remain descriptive but behavior is binary-proven. |
| What is `owner + 0x420`? | Pending quantity/count field cleared before queuing or opening quantity prompt. Best name `m_pendingQuantity` or `m_pendingItemCount`. |
| Is `0x005975e0` an employee command helper? | No. It is the generic TimerHandler scheduling wrapper. This target queues event id `5` on `owner + 0xa4`; `EmployeeDialogPane::SendCommand` at `0x004a2c80` is the later employee command sender. |
| What are `0x0049eb90` and `0x0049dad0`? | Shared DialogPane slide-close animation and close/destroy helpers. |
| What are the alert/resource strings? | `0x0061929c` is the AddEmployee multi-selection warning text, English meaning "Cannot add multiple items at once"; `0x00613a18` is the shared OK text; resource id `247` is "Add how many?" for quantity input. |
| Source file placement? | `AddEmployeeItemDialog` belongs with `EmployeeDialogPane` source family. Generic `AddItemDialog` base construction/fallback remains in `ItemDialogs`. |

## Owner And Source Placement Ranking

1. **[UID:000006] `AddEmployeeItemDialog` as canonical owner, [UID:0000J0] `EmployeeDialogPane` as file/source family.** This is the best route. The vtable slots, owner pointer field, EmployeeDialogPane command path, AddEmployee resources, and quantity dialog caller all point to employee-shop UI behavior.
2. **[UID:0000J0] `EmployeeDialogPane` as file-level owner only.** Correct for source placement and inline construction context, but not the canonical owner for the method body because the vtable slot and `this` layout are `AddEmployeeItemDialog`.
3. **[UID:00004C] `EmployeeDialogPane` class as direct owner.** Rejected for 00013A. It owns the parent dialog, command sender, and inline construction site, but this target's `this` pointer is the AddEmployee dialog object and reads `this + 0x270` to reach the parent.
4. **[UID:0000KE] `ItemDialogs` / [UID:000007] `AddItemDialog`.** Rejected as direct owner. `AddItemDialog` is the base class and fallback callee only; the employee owner pointer, employee resources, quantity dialog, and command id `5` are feature-specific.
5. **[UID:00013B] adjustor thunk island or compiler-generated owner.** Rejected for source ownership. The thunk bytes are generated implementation detail.
6. **[UID:000139] raw constructor island as source emitter.** Rejected for source emission until a route appears. It remains useful support evidence for class layout and vtable stores.

## Heuristic / Inference Reanalysis And Validation

Raw-byte proven facts:

- The PE mapping, raw offsets, target byte ranges, body hashes, and padding bytes listed above are derived directly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `0x004a4b20-0x004a4cb1` is a two-argument `thiscall` handler with button-id branch, base fallback, selected-list access through child id `3`, multi-selection alert allocation, selected-row lookup, owner pointer read at `+0x270`, current-user item lookup, item metadata test at `+0x1ec`, quantity dialog construction, generic timer schedule call on `owner + 0xa4`, and DialogPane slide/close calls.
- `0x004a4cb1-0x004a4cc7` contains two AddEmployee adjustor thunks, `0x004a4cc7-0x004a4cf3` contains four sibling thunks, and `0x004a4cf3-0x004a4d00` is padding.
- `0x004a4d00-0x004a4d3b` is a scalar deleting destructor wrapper with ordinary free and `0x274` object-size delete paths.
- The raw constructor island at `0x004a4ae0` calls `0x004ae4c0`, stores `+0x270`, and stores vtables `0x006190d4`, `0x00619134`, and `0x00619164`.
- Local dword/rel32 scans found no direct route to `0x004a4ae0`, and positive controls found expected nearby call/pointer routes.

Existing IDA-backed docs validated:

- [UID:00013A] already records prior IDA function shape for `0x004a4b20`, `0x004a4d00`, and the adjustor thunks; current raw bytes confirm that shape.
- [UID:000139] records the no-function/no-xref dispute for `0x004a4ae0`; current raw scans strengthen that no-route conclusion.
- [UID:0000TT] records the inline construction site at `0x004a339f`; current constructor-byte comparison validates that this live path duplicates the raw constructor's base call/vtable/owner stores.
- [UID:0002MH] records the AddEmployee vtable data; current dword checks confirm the slots used by this target.
- [UID:0001K8] and [UID:0002HI] document `0x005975e0` as generic TimerHandler scheduling; this invalidates the stale target phrase "employee command helper".
- [UID:0003KW] documents `EmployeeDialogPane::SendCommand` at `0x004a2c80`; current behavior shows 00013A queues command kind `5` for that later route rather than sending directly.
- [UID:0001OE], [UID:0001OC], and [UID:0001R9] support the alert text, OK string, and quantity prompt resource interpretation.

High-probability inference:

- `item + 0x1ec` should be described as a quantity-prompt or stack/count flag. The exact original field name is not proven, but the branch target behavior is decisive: nonzero opens `EmployeeQuantityInputDialogPane`; zero queues event id `5` directly with the count payload from `item + 0x1e8`.
- `item + 0x1e8` is best named `count`, `amount`, or `stackCount` payload. It is pushed as the fourth TimerHandler parameter for direct add-command event `5`.
- `owner + 0x420` is best named `m_pendingQuantity` or `m_pendingItemCount`; it is cleared before either quantity prompt or direct event queue.
- The child id `3` is the AddItemDialog item-selection list. Exact original member names for the child manager and row record are not proven, so first-draft C++ should mark `m_controls`, `FindControl`, `SelectionRow`, and `selectedSlot` as descriptive.
- Source placement belongs in the EmployeeDialogPane source file family because all feature-specific behavior is employee-dialog-specific even though the base fallback and constructor callee are in `ItemDialogs`.

Rejected alternatives:

- **Emit `AddEmployeeItemDialog::AddEmployeeItemDialog` from `0x004a4ae0`.** Rejected. No local dword/rel32 route and no existing IDA xref/function support. The live inline construction site already covers source construction behavior.
- **Treat `0x005975e0` as an employee command helper.** Rejected. It has 163 broad call sites and is documented as generic TimerHandler scheduling. The employee-specific command sender is `0x004a2c80`.
- **Parent 00013A to `ItemDialogs` or `AddItemDialog`.** Rejected. The base class is involved only through fallback/destruction/construction; the handler behavior is employee-specific.
- **Emit adjustor thunk C++ or scalar-deleting-wrapper C++.** Rejected. Those are compiler artifacts. Source C++ should include only the virtual handler and at most an ordinary empty/default destructor.
- **Keep target below 85 because field names are descriptive.** Rejected. The remaining uncertainty is original naming only. Behavior, range, owner, source route, vtable route, constructor dispute, and compiler-artifact exclusions are strong enough for `88/90`.

Remaining score cap:

The score should not exceed `88/90` in this pass because IDA MCP was offline for fresh live xrefs, exact original selected-row/item-record C++ type names are not proven, and the assigned target remains a mixed span that includes generated thunks/padding alongside source-authored methods. These are precision caps, not blockers to first-draft C++.

## First-Draft C++ Recommendation

Names marked with `descriptive` below are not proven original names. The behavior and call ordering are raw-byte proven.

```cpp
void AddEmployeeItemDialog::OnButtonClick(int buttonId, int buttonParam)
{
    if (buttonId != 1) {
        AddItemDialog::OnButtonClick(buttonId, buttonParam);
        return;
    }

    // Descriptive member names. The binary retrieves child/control id 3,
    // then follows the returned control to its selection-list object.
    ItemSelectionList *list = m_controls->GetControl(3)->m_selectionList;

    unsigned char selectedRows[0x100];
    int selectedCount = list->GetSelectedRows(selectedRows, 0x100);

    if (selectedCount > 1) {
        new AlertPane(
            kCannotAddMultipleEmployeeItemsText,
            this,
            kDialogOkButtonText,
            0);

        SlideClose();
        CloseDialog();
        return;
    }

    SelectionRow *row = list->GetSelectedRow(selectedRows[0]);
    signed char selectedSlot = static_cast<signed char>(row->slot);

    EmployeeDialogPane *owner = m_owner;
    ItemRecord *item = g_pCurrentUserPane->GetInventoryItem(selectedSlot);

    owner->m_pendingQuantity = 0;

    if (item->requiresQuantityPrompt) {
        char prompt[0x100];
        FormatString(prompt, sizeof(prompt), g_resourceManager->GetString(247));

        new EmployeeQuantityInputDialogPane(prompt, owner, selectedSlot);
    } else {
        owner->m_timerHandler.ScheduleTimer(
            5,
            0,
            selectedSlot,
            item->stackCount);
    }

    SlideClose();
    CloseDialog();
}

AddEmployeeItemDialog::~AddEmployeeItemDialog()
{
}
```

No constructor C++ should be emitted from [UID:000139] for this target. If a class-level draft wants to show construction, it should show the source-level allocation/construction at `EmployeeDialogPane::OnButtonAction` / [UID:0000TT], with a note that the compiler also retained a duplicate constructor-shaped island at `0x004a4ae0` that has no current route.

## Exact Target Incorporation Text

Recommended metadata for [UID:00013A]:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:000006
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000006
```

Replace the target's current high-level status paragraph with:

```text
This range is now source-quality for the AddEmployeeItemDialog virtual click handler and ordinary destructor, with compiler artifacts explicitly excluded from handwritten source. B004 2026-06-18 local PE recheck maps the half-open span as `0x004a4b20-0x004a4cb1` source-authored `OnButtonClick`, `0x004a4cb1-0x004a4cc7` AddEmployee adjustor thunks, `0x004a4cc7-0x004a4cf3` sibling adjustor thunks, `0x004a4cf3-0x004a4d00` `int3` padding, and `0x004a4d00-0x004a4d3b` scalar deleting destructor wrapper. The handler is vtable-reached through primary slot `0x0061911c`, uses child id `3` for the AddItemDialog selection list, rejects multiple selected rows with AlertPane text `0x0061929c` and shared OK `0x00613a18`, uses `this + 0x270` as `EmployeeDialogPane *owner`, tests selected item metadata byte `+0x1ec` to choose quantity prompt versus direct add, queues direct add command event `5` through the owner's `+0xa4` TimerHandler subobject via generic scheduler `0x005975e0`, and then uses shared DialogPane slide/close helpers `0x0049eb90` and `0x0049dad0`. The old "employee command helper" name for `0x005975e0` is rejected; the employee command sender is the later `EmployeeDialogPane::SendCommand` path at `0x004a2c80`.
```

Add or replace the constructor-dispute paragraph with:

```text
The raw constructor-shaped island [UID:000139] at `0x004a4ae0-0x004a4b20` remains valid layout evidence but is not the live source construction route. Local PE dword and rel32 scans found no pointer, vtable, call, jump, or conditional-branch route to `0x004a4ae0`, matching prior IDA-backed no-function/no-xref notes. The live AddEmployee allocation path is the inline construction sequence at `0x004a339f`, which calls `AddItemDialog` construction, stores the same three AddEmployee vtables, and stores the same owner pointer at `+0x270`. Do not emit standalone source C++ for `0x004a4ae0` unless future evidence finds a caller or table route.
```

Add the first-draft C++ block from this report under `RECONSTRUCTION_CPP` for [UID:00013A].

## Exact Support Recommendations

[UID:000006] `AddEmployeeItemDialog` class page:

```text
2026-06-18 B004 source-quality closure: the disputed raw constructor island [UID:000139] is retained constructor-shaped evidence only; no local dword/rel32 route and prior IDA no-function/no-xref evidence support keeping it out of final handwritten C++. The live object construction path remains the inline `EmployeeDialogPane::OnButtonAction` sequence [UID:0000TT]. The source-authored AddEmployee behavior is [UID:00013A] `OnButtonClick`, which uses `this + 0x270` as the owning `EmployeeDialogPane *`, child id `3` as the AddItemDialog selection list, selected row byte `0` as the inventory slot, item byte `+0x1ec` as the quantity-prompt/stack-count flag, item dword `+0x1e8` as the direct-add count payload, owner field `+0x420` as pending quantity/count, and generic TimerHandler scheduling at `0x005975e0` on `owner + 0xa4` to queue employee command kind `5`. The actual packet/command sender remains `EmployeeDialogPane::SendCommand` at `0x004a2c80`.
```

Recommended class metadata if the supervisor updates support scores with this closure:

```text
COMPLETION:88
CONFIDENCE:90
```

[UID:0001TN] `AddEmployeeItemDialogLayout` support page:

```text
2026-06-18 B004 constructor/source-route closure: object size `0x274`, base `AddItemDialog` extent `0x270`, and derived owner field `+0x270` are validated by both the inline live construction path at `0x004a339f` and the retained raw constructor-shaped island at `0x004a4ae0`. No current local PE dword/rel32 route or existing IDA-backed xref evidence makes the raw island callable. Source placement is EmployeeDialogPane for the derived AddEmployee class behavior, while generic base AddItemDialog construction/fallback/destruction remains ItemDialogs.
```

[UID:000139] raw constructor page:

```text
2026-06-18 B004 no-code proof: local PE dword scans found no pointer-table/vtable/callback hit to `0x004a4ae0`, and rel32 call/jump/jcc scans found no route to `0x004a4ae0`. Positive controls found the expected routes to `0x004ae4c0`, `0x004a4770`, `0x005975e0`, `0x0049eb90`, and `0x0049dad0`. The raw bytes are constructor-shaped and remain valuable layout evidence, but source emission should stay blank/non-emitting unless a future route is found. The live construction behavior is represented by [UID:0000TT] around `0x004a339f`.
```

Recommended [UID:000139] metadata if generator policy requires non-emitting retained evidence to have blank emitters:

```text
CANONICAL_OWNER:000006
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
```

[UID:00013B] `EmployeeDialogAdjustorThunks`:

```text
2026-06-18 B004 revalidation: bytes `0x004a4cb1-0x004a4cc7` are the AddEmployee secondary/tertiary destructor adjustors, bytes `0x004a4cc7-0x004a4cf3` are sibling EmployeeDialogPane and EmployeeItemProperty adjustors, and `0x004a4cf3-0x004a4d00` is `int3` padding. These bytes are compiler-generated and should not be emitted as source C++.
```

[UID:0000J0] `EmployeeDialogPane` file page:

```text
AddEmployeeItemDialog source placement resolved by B004 2026-06-18: the derived AddEmployee item-picker behavior belongs in the EmployeeDialogPane source family because it stores and uses `EmployeeDialogPane *owner`, opens EmployeeQuantityInputDialogPane, uses employee-dialog resource id `247`, and queues employee command kind `5` for EmployeeDialogPane::SendCommand. Generic AddItemDialog base fallback and base destruction remain ItemDialogs dependencies, not the direct source owner for the AddEmployee override.
```

[UID:0000KE] `ItemDialogs` file page:

```text
AddEmployeeItemDialog cross-reference clarified by B004 2026-06-18: ItemDialogs owns generic AddItemDialog construction, fallback button handling, and base destruction. The AddEmployeeItemDialog override [UID:00013A] is employee-dialog-specific and should remain emitted through the EmployeeDialogPane source family.
```

No support change is required for [UID:0001K8] or [UID:0002HI]; those docs already support the corrected `0x005975e0` TimerHandler interpretation.

## Exact Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. Replace the existing [UID:00013A] row currently near the AddEmployee group, immediately after the [UID:000139] row, with:

```text
    - [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) 0x004a4b20-0x004a4d3b | method/destructor range | AddEmployeeItemDialog : reconstructable : 88% : strong : B004 2026-06-18 source-quality pass raw-verified OnButtonClick `0x004a4b20-0x004a4cb1`, AddEmployee adjustor thunks `0x004a4cb1-0x004a4cc7`, sibling compiler thunks `0x004a4cc7-0x004a4cf3`, thunk padding `0x004a4cf3-0x004a4d00`, scalar deleting destructor `0x004a4d00-0x004a4d3b`, vtable refs, base fallback, selection/alert/quantity paths, owner pointer `+0x270`, item flag/count offsets `+0x1ec/+0x1e8`, generic TimerHandler queue event `5` through owner `+0xa4`, DialogPane slide/close helpers, and first-draft C++ for the source-authored handler/destructor while excluding raw constructor [UID:000139], thunks, and padding from handwritten source.
```

If the supervisor also updates the stale [UID:000139] coverage row to match current constructor-route closure, replace it with:

```text
    - [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) 0x004a4ae0-0x004a4b20 | retained raw constructor-shaped evidence | AddEmployeeItemDialogRawConstructor : reconstructable/non-emitting : 85% : strong : Raw constructor-shaped bytes call `AddItemDialog` construction, store owner `+0x270`, and patch vtables `0x006190d4/0x00619134/0x00619164`, but B004 2026-06-18 local PE dword/rel32 scans and prior IDA no-function/no-xref evidence find no route to `0x004a4ae0`; live construction is represented by inline path `0x004a339f`, so standalone constructor C++ should remain blank unless a future caller/table route is found.
```

## Validator Commands And Results

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [00013A-AddEmployeeItemDialog-source-quality-removed.md](00013A-AddEmployeeItemDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: `TcpTestSucceeded : False`. IDA MCP was unavailable for fresh live xrefs.

> Executable block R002 was removed from this report and preserved verbatim in [00013A-AddEmployeeItemDialog-source-quality-removed.md](00013A-AddEmployeeItemDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.

Local Python PE dump/disassembly/hash scripts were used against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` to derive the raw offsets, bytes, hashes, dword scans, and rel32 scans recorded above. Positive-control scans found expected routes to known callees and vtable slots, so the no-route conclusion for `0x004a4ae0` is supported.

> Executable block R003 was removed from this report and preserved verbatim in [00013A-AddEmployeeItemDialog-source-quality-removed.md](00013A-AddEmployeeItemDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: confirmed the target page still has `84/88`, formal C++ blank, and the coverage row still says `84%` with stale "employee command helper" wording. No generated or coverage file was edited.

## Changed Files

Only this report file was created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\00013A-AddEmployeeItemDialog-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00013A-AddEmployeeItemDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00013A"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013A-AddEmployeeItemDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00013A-AddEmployeeItemDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
