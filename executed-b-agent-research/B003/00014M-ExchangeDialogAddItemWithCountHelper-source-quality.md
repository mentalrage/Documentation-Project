** TARGET-REPORT-UID:00014M **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014M ExchangeDialogAddItemWithCountHelper Source-Quality Report

## Finalized Report / Current Recommendation

- Assignment id: `B003-goal2-exchange-dialog-add-item-with-count-source-quality-00014M-20260618`.
- Supervisor submission id: `019edb92-6e4a-7c03-8d45-00014m-b003`.
- Target: [UID:00014M] `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`.
- Current target state: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00004R`, `EMITTER_UIDS:00004R`, blank formal C++.
- Current recommendation: keep [UID:00014M] assigned to [UID:00004R] `ExchangeDialog`, keep it reconstructable, keep `EMITTER_UIDS:00004R`, raise to `COMPLETION:86`, `CONFIDENCE:90`, and keep formal `RECONSTRUCTION_CPP CODE` blank for now.
- Final disposition: `0x004ada90` is an IDA-modeled, source-authored/source-declared ExchangeDialog helper body that constructs an `AddItemWithCountDialog` from exchange packet subcommand `1`. It has no direct branch, no embedded VA/RVA pointer, no vtable/table route, and the live packet dispatcher already contains the equivalent constructor path inline. Treat it as a retained out-of-line helper or retained duplicate of an inlined dispatcher helper, not as `ItemDialogs` implementation, not as compiler glue, and not as padding.
- Required action: update the target/support evidence, score, stale C++ gate wording, and coverage row. Do not populate the formal C++ block until a broader `ExchangeDialog.cpp` source integration decides whether dispatcher subcommand `1` should call a helper or remain inline while this range represents a retained out-of-line clone.
- Confidence: high for range, body, callee set, no-static-route finding, owner/emitter route, packet byte role, and `this+0x26c` field role; medium-high for original source call shape because no static xref proves whether the retained body was ever called in final linked code.

## Evidence Checked

- Required instructions read:
  - `tools/leaser/Agents/Agent-B003/goal.md`.
  - `tools/leaser/Agents/Supervisor.md`.
  - `tools/leaser/Agents/Agent-B003/notes.md`.
  - `by-structure.md`.
  - `inference_research.md`.
- Target/support docs checked:
  - [UID:00014M] `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`.
  - [UID:00014L] `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`.
  - [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
  - [UID:00014N] `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`.
  - [UID:00014O] `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md`.
  - [UID:00014P] `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md`.
  - [UID:00004R] `by-class/ExchangeDialog.md`.
  - [UID:0000J9] `by-file/ExchangeDialog.md`.
  - [UID:000008] `by-class/AddItemWithCountDialog.md`.
  - [UID:0000KE] `by-file/ItemDialogs.md`.
  - [UID:00033S] `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`.
  - [UID:00033T] `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`.
  - [UID:0003NE] `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`.
- Generated/read-only state checked:
  - `by-memory/-coverage-report.md` current row for [UID:00014M].
  - `auto-generated/-ag-memory-coverage.md` current row for [UID:00014M].
  - `project-level/-auto-completion-stats.md` current `00014M` score row.
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, which currently exists but has length `0`.
  - `simroot_v2/class_ExchangeDialog.cpp`, which omits this helper and contains stale `DL_20` resource names elsewhere.
- Executed B-agent research searched:
  - `Agent-B002/research/executed/00014O-exchange-dialog-cancel-alert-source-quality.md`.
  - `Agent-B002/research/executed/00014P-exchange-dialog-ready-alert-source-quality.md`.
  - `Agent-B001/research/executed/older/00014T-ItemExchangeMixDialogs.md`.
  - Search terms included `00014M`, `0x004ada90`, `ExchangeDialogAddItemWithCount`, and `AddItemWithCount`.
- IDA MCP status:
  - Tried `tools/list` at `http://127.0.0.1:13337/mcp`.
  - Result: unavailable in this session, `Unable to connect to the remote server`.
  - Impact: this report uses existing MCP-backed documentation as prior evidence and adds direct PE/Capstone verification against the executable. No IDA DB edits were attempted.
- Raw executable checked:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Size: `2679296`.
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`.
  - SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - PE image base: `0x00400000`.
  - `.text`: `0x00401000-0x0060c4ac`, raw `0x400`, raw size `0x20b600`.
  - Capstone version: `5.0.7`.
- Integer conversions checked with `tools/int_convert.py`:
  - `0x274` is decimal `628` (Verified with int_convert.py).
  - `0x72` is decimal `114` (Verified with int_convert.py).
  - `0xa0` is decimal `160` (Verified with int_convert.py).
  - `0x1cc` is decimal `460` (Verified with int_convert.py).
  - `0x26c` is decimal `620` (Verified with int_convert.py).
  - `0x4a` is decimal `74` (Verified with int_convert.py).
  - `0x42` is decimal `66` (Verified with int_convert.py).

## Raw PE / Capstone Facts

### Boundary And Body

- Raw bytes at `0x004ada80-0x004ada83` are the previous method epilogue `5d c2 04 00`.
- Raw bytes at `0x004ada84-0x004ada90` are `0xcc` padding before the target.
- The primary target body is exactly `0x004ada90-0x004adb02`, size `0x72` / 114 bytes (Verified with int_convert.py).
- Raw bytes at `0x004adb02-0x004adb10` are fourteen `0xcc` padding bytes before the next raw exchange code island at `0x004adb10`.
- The body starts with a normal `push ebp; mov ebp, esp` frame, installs an SEH registration, saves `esi`, loads `this` from `ecx`, and ends with `ret 4`.
- Calling convention: `__thiscall` with primary `ExchangeDialog *this` in `ecx`, one stack argument at `[ebp+8]` interpreted as a packet pointer, and return value in `eax`.
- Return semantics: returns the `AddItemWithCountDialog` constructor result if allocation succeeds; returns `0` when allocation returns null.

### Primary Body Disassembly Summary

Observed instruction flow:

```text
0x004ada90: prologue / C++ EH registration
0x004adab4: esi = ecx
0x004adab6: eax = [ebp+8]
0x004adab9: eax += 2
0x004adabc: push eax
0x004adabd: call 0x00575470
0x004adac2: push 0x274
0x004adac7: [ebp+8] = al
0x004adaca: call 0x004f4aa0
0x004adacf: add esp, 8
0x004adad2: [ebp-0x10] = eax
0x004adad5: [ebp-4] = 0
0x004adadc: test eax, eax
0x004adade: je 0x004adaf0
0x004adae0: push [ebp+8]
0x004adae3: ecx = eax
0x004adae5: push [esi+0x26c]
0x004adaeb: call 0x004af040
0x004adaf0: restore fs:[0] / epilogue
0x004adaff: ret 4
```

Primary body callees:

- `0x00575470`: byte reader / `std::_Narrow_char_traits<char,int>::to_char_type`-style helper. Capstone confirms it reads `al = *[ebp+8]` and returns.
- `0x004f4aa0`: allocation wrapper. The target passes `0x274` / 628 bytes (Verified with int_convert.py).
- `0x004af040`: `AddItemWithCountDialog` constructor/core.

### EH / Cleanup Chunk

- The target body pushes handler immediate `0x005fe3b4`.
- Raw disassembly of the nearby EH support region confirms:
  - `0x005fe3a9`: cleanup stub loads `[ebp-0x10]`, pushes it, calls `0x004f4ac0`, pops `ecx`, and returns.
  - `0x005fe3b4`: EH cookie/handler code loads the registration record, validates cookie through `0x005c772f`, loads `0x0065c890`, and jumps to `0x005c956c`.
- Interpretation: the far chunk is compiler C++ EH support for freeing the allocated object if the constructor path throws. It is evidence that the helper is source-level C++ allocation/construction code, not an adjustor thunk or padding. It is not separate handwritten source for the target body.

### Xref / Route Scans

Direct PE scans against `.text` and the full file found:

- Rel32 `call`/`jmp`/long-conditional-branch targets to `0x004ada90`: `0` hits.
- Full-file dword scan for absolute VA `0x004ada90`: `0` hits.
- Full-file dword scan for RVA `0x000ada90`: `0` hits.
- Full-file dword scan for target end VA `0x004adb02`: `0` hits.
- Full-file dword scan for constructor VA `0x004af040`: `0` hits, as expected because both known constructor uses are rel32 calls.
- Rel32 calls to `0x004af040`: exactly two hits:
  - `0x004ad3bf` inside [UID:00014L] dispatcher subcommand `1`.
  - `0x004adaeb` inside [UID:00014M] target helper.

Conclusion: there is no current static PE evidence for a direct caller, data pointer, vtable slot, jump table entry, or computed-call pointer table route to `0x004ada90`. This validates and strengthens the existing no-xref status. It does not prove the source never declared the helper; it proves the current linked binary has no static inbound route that ordinary code, data, vtable, jump-table, or pointer scans can defend.

## Dispatcher Comparison

[UID:00014L] dispatcher subcommand `1` contains an inline equivalent of the helper:

```text
0x004ad380: lea eax, [esi+2]
0x004ad383: push eax
0x004ad384: call 0x00575470
0x004ad389: push 0x274
0x004ad38e: [ebp-0x860] = al
0x004ad394: call 0x004f4aa0
0x004ad399: add esp, 8
0x004ad39c: [ebp-0x864] = eax
0x004ad3a2: [ebp-4] = 0
0x004ad3a9: test eax, eax
0x004ad3ab: je 0x004ad6bf
0x004ad3b1: push [ebp-0x860]
0x004ad3b7: ecx = eax
0x004ad3b9: push [ebx+0x1cc]
0x004ad3bf: call 0x004af040
0x004ad3c4: al = 1
0x004ad3c6: jmp dispatcher epilogue
```

Equivalence:

- Both paths read byte `packet+2` through `0x00575470`.
- Both allocate `0x274` / 628 bytes (Verified with int_convert.py).
- Both call `0x004af040` with the allocated object as `ecx`.
- Both pass the exchange session id and the packet byte to the constructor.

Differences:

- [UID:00014M] uses primary `ExchangeDialog *this` and reads `[this+0x26c]`.
- [UID:00014L] is a virtual packet dispatcher reached through a secondary ExchangeDialog vtable view. It reads `[this+0x1cc]`.
- [UID:0003NE] documents ExchangeDialog vtable views at `0x00619d2c` primary, `0x00619d8c` secondary, and `0x00619dbc` tertiary. The constructor stores the secondary view at object offset `+0xa0`. Therefore dispatcher `[secondary_this+0x1cc]` resolves to primary object `[this+0x26c]` because `0xa0 + 0x1cc = 0x26c`. This resolves the apparent field-offset conflict.
- [UID:00014M] returns the dialog pointer or `0`; [UID:00014L] converts recognized subcommand `1` to dispatcher return `true` and ignores the constructor result.

Best source-shape inference:

- The target is likely an out-of-line copy of a small source helper that the compiler duplicated or inlined into dispatcher subcommand `1`, or a private helper retained by the build even though the final static dispatch path no longer calls it.
- A completely unrelated dead function is weaker because the body is byte-for-byte aligned with the live subcommand semantics and uses the same constructor path.
- A compiler-only artifact is rejected because the body is ordinary C++ UI/source behavior with allocation, packet parsing, and class-specific field access.

## Packet, Field, Type, And Lifetime Interpretation

- Best helper name: `ExchangeDialog::OpenAddItemWithCountDialog`.
  - Status: descriptive/high-probability, not original-name proof.
  - Reason: the helper constructs and opens/creates the count-aware add-item dialog from an already selected exchange server packet. It does not validate opcode or dispatch subcommand itself.
- Best signature:

```cpp
AddItemWithCountDialog *ExchangeDialog::OpenAddItemWithCountDialog(const unsigned char *packet);
```

- Receiver type:
  - Primary `ExchangeDialog *` for [UID:00014M].
  - The dispatcher comparison must record the secondary-facet receiver adjustment but should not rename [UID:00014M] as an EventHandler method. The helper itself reads the primary object layout directly.
- `this+0x26c`:
  - Best name: `m_exchangeId` or `m_exchangeSessionId`.
  - Evidence: constructor stores the exchange id there; send/cancel/money paths serialize the same field into opcode `0x4A`; [UID:00014M] passes it to `AddItemWithCountDialog`; [UID:00014L] reaches the same field through secondary `this+0x1cc`.
  - Rejected alternatives: item id, dialog pointer, count, or control id. The value is a dword context/session id passed through exchange packet flows.
- `packet+2` in [UID:00014M]:
  - Best name: `itemType`, `selectedItemType`, or `selectedItemToken`.
  - Recommended documentation wording: "selected item/type byte from exchange server packet subcommand `1`."
  - Evidence: the dispatcher validates opcode `0x42` / 66 decimal (Verified with int_convert.py) and subcommand `1` before using `packet+2`; [UID:00014M] receives an already selected packet pointer and reads `packet+2` directly; `AddItemWithCountDialog` stores the byte at its own `this+0x270`; the dialog action later serializes that stored byte into client opcode `0x4A` / 74 decimal (Verified with int_convert.py), subcommand `2`, together with the exchange id and user-entered count.
  - Rejected alternatives:
    - Count: rejected because the user-entered count is parsed later from the dialog control, clamped to `255`, and sent separately.
    - Opcode or subcommand: rejected because dispatcher opcode/subcommand are `packet+0` and `packet+1`.
    - Local/remote side: rejected because money/ready helpers use side/status bytes differently and this byte is stored in the item-count dialog as the selected item/type token.
- Return type/lifetime:
  - The helper returns the constructed `AddItemWithCountDialog *` or null. No persistent field is written by [UID:00014M].
  - Current callers are absent. If a source caller existed, it may have ignored the returned pointer, matching existing dialog-construction style where UI/dialog infrastructure owns the object after construction. The dispatcher inline block ignores the constructor result and only returns `true`.
- AddItemWithCountDialog constructor relationship:
  - Constructor entry `0x004af040` is reached only from dispatcher `0x004ad3bf` and target helper `0x004adaeb`.
  - Constructor stores the passed dword context at AddItemWithCountDialog `this+0x26c` and the passed byte at AddItemWithCountDialog `this+0x270`.
  - AddItemWithCountDialog action path reads those fields, parses count input through the `%hu` format string, clamps count to `255`, and sends an eight-byte opcode `0x4A`/subcommand `2` packet containing context, item/type byte, count byte, and terminator.

## Heuristic / Inference Reanalysis And Validation

- Helper identity and generated/source-facing name:
  - Best inference: `ExchangeDialog::OpenAddItemWithCountDialog(const unsigned char *packet)` returning `AddItemWithCountDialog *`.
  - Evidence checked: target disassembly, dispatcher case `1`, AddItemWithCountDialog constructor/action docs, constructor call sites, no target start xrefs, and ExchangeDialog support pages.
  - Rejected alternatives: `ExchangeDialogAddItemWithCountHelper` as original proof, `HandlePacket` as too broad, `AddItemWithCountDialog` constructor ownership, `ItemDialogs` free helper, compiler thunk, padding.
  - Impact: target page should use `OpenAddItemWithCountDialog` as the best descriptive name, while explicitly stating that the original method name is not proven.

- Owner/source route:
  - Best inference: direct semantic owner remains [UID:00004R] `ExchangeDialog`; source route remains [UID:00004R] -> [UID:0000J9] `ExchangeDialog.cpp`.
  - Evidence checked: the helper reads ExchangeDialog state, uses the ExchangeDialog packet stream, duplicates the ExchangeDialog dispatcher subcommand `1`, and does not implement AddItemWithCountDialog behavior beyond constructing it.
  - Rejected alternatives:
    - [UID:000008] `AddItemWithCountDialog`: rejected because that class owns constructor/action/count serialization internals, not the exchange packet helper that decides to open it.
    - [UID:0000KE] `ItemDialogs`: rejected for the same reason; exchange is a consumer of the picker, not the picker implementation owner.
    - [UID:0000J9] as canonical owner: rejected as too broad for `CANONICAL_OWNER`; file remains the generated source root through the class.
    - `CANONICAL_OWNER:NONE`: rejected because class-specific state and source route are strong.
  - Impact: metadata owner/emitter should not change.

- Hidden caller/table/vtable route:
  - Best inference: no defensible route currently exists.
  - Evidence checked: existing MCP-backed docs report no callers/xrefs; current raw PE scan found no rel32 branch target to `0x004ada90`, no full-file VA dword, no RVA dword, no end-VA pointer, and no constructor-start dword table. [UID:0003NE] vtable docs place the dispatcher at `0x00619d9c`, not this helper.
  - Rejected alternatives: direct call missed by docs, vtable entry, switch/jump-table entry, raw pointer table, embedded callback pointer, export-like table.
  - Impact: this is the main formal-C++ blocker. It does not block ownership or reconstructability, but it blocks claiming the final source call graph.

- Duplicate dispatcher relationship:
  - Best inference: retained out-of-line helper or retained duplicate of a source helper that is inlined into [UID:00014L] dispatcher subcommand `1`.
  - Evidence checked: [UID:00014L] case `1` uses the same packet byte, allocation size, constructor, and session id, but via secondary-facet `this+0x1cc`; [UID:00014M] uses primary `this+0x26c`.
  - Rejected alternatives:
    - Independent live helper: no caller route.
    - Pure dead code unrelated to dispatcher: behavior matches dispatcher too closely.
    - IDA bad function creation: raw boundaries, prologue, EH setup, allocation, constructor, return, and padding all support a real function.
  - Impact: keep reconstructable true and score can rise; keep formal C++ blank until ExchangeDialog integration decides helper call versus inline dispatcher.

- `packet+2` semantics:
  - Best inference: selected item/type token for a stack-count item in exchange add-item flow.
  - Evidence checked: dispatcher opcode/subcommand layout, target byte read, constructor storage at AddItemWithCountDialog `+0x270`, action serialization in opcode `0x4A` subcommand `2`.
  - Rejected alternatives: count, opcode, subcommand, ready-side/status byte, money-side byte.
  - Impact: target and dispatcher docs should stop saying only "converted packet byte" and should record the stronger selected item/type-token role.

- `this+0x26c` and dispatcher `this+0x1cc`:
  - Best inference: both are the same primary `ExchangeDialog::m_exchangeId` / `m_exchangeSessionId`, reached through different `this` views.
  - Evidence checked: [UID:0003NE] vtable view documentation, constructor stores for primary/secondary/tertiary views, target primary access, dispatcher secondary access, ExchangeDialog packet send paths.
  - Rejected alternatives: two different fields, typo in current docs, AddItemWithCountDialog-local field.
  - Impact: update [UID:00014L] support text if edited so subcommand `1` says `this+0x1cc` is the secondary-facet view of primary `this+0x26c`.

- C++ EH cleanup role:
  - Best inference: compiler-generated C++ EH cleanup for the `operator new` plus constructor call.
  - Evidence checked: target pushes handler `0x005fe3b4`; raw disassembly shows cleanup stub `0x005fe3a9` calling `0x004f4ac0` on `[ebp-0x10]`.
  - Rejected alternatives: separate source helper, callback table, unrelated runtime island.
  - Impact: document as boundary/support evidence only; do not split into a source child.

- Generated-output state:
  - Best inference: generated output is not authoritative here. The `auto-generated/-ag-memory-coverage.md` row reports an emitter route to `ExchangeDialog.cpp`, but generated `ExchangeDialog.cpp` is currently zero length because formal C++ blocks are blank. `simroot_v2/class_ExchangeDialog.cpp` omits [UID:00014M].
  - Rejected alternatives: generated omission means non-reconstructable or wrong owner. Existing IDA/PE evidence proves a real source-bearing body.
  - Impact: keep route metadata but do not force code population merely to make generated output non-empty.

- Current docs validated:
  - Exact range, IDA-modeled function status, allocation size, constructor call, no-xref caveat, ExchangeDialog ownership, ItemDialogs consumer/implementation split, and AddItemWithCountDialog field storage are all validated.
- Current docs to revise:
  - Replace stale "final C++ blank below 95/95 gate" wording with the current combined-score/emitter gate plus target-specific source-shape blocker.
  - Strengthen the no-xref evidence from "IDA reports no xrefs" to include raw PE no-rel32/no-VA/no-RVA findings.
  - Resolve `this+0x26c` versus dispatcher `this+0x1cc` using secondary-vtable adjustment.
  - Replace "packet byte" with "selected item/type byte" or equivalent descriptive field.
  - State that [UID:00014M] is source-authored/source-declared retained helper body, not raw/no-function code. The no-route issue is reachability, not function boundary.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog

- Evidence for:
  - The helper reads the exchange session id from ExchangeDialog primary object offset `+0x26c`.
  - It consumes an exchange server packet subcommand payload.
  - The live ExchangeDialog packet dispatcher duplicates its behavior in subcommand `1`.
  - Existing class/file pages document the ExchangeDialog packet dispatcher, money, ready/cancel, and add-item dialog invocation as ExchangeDialog responsibilities.
  - [UID:00004R] and [UID:0000J9] clear the owner/emitter gate.
- Evidence against:
  - No direct start xref proves the exact source call site.
  - The object constructed belongs to `AddItemWithCountDialog`.
- Decision:
  - Accepted as direct semantic owner. Constructor consumption does not transfer ownership to the constructed class.

### 2. [UID:0000J9] ExchangeDialog file

- Evidence for:
  - It is the correct source root for `ExchangeDialog.cpp`.
  - The helper belongs inside the exchange feature file.
- Evidence against:
  - `CANONICAL_OWNER` should be the narrow class when the helper is a class member/helper.
- Decision:
  - Accepted only as emission root through [UID:00004R], not direct canonical owner.

### 3. [UID:000008] AddItemWithCountDialog / [UID:0000KE] ItemDialogs

- Evidence for:
  - The helper allocates `0x274` / 628 bytes (Verified with int_convert.py) and calls `AddItemWithCountDialog` constructor `0x004af040`.
  - The selected item/type byte is stored in the dialog object and later sent in the dialog's packet helper.
- Evidence against:
  - The helper reads ExchangeDialog state and dispatch-packet payload; it does not implement count-dialog controls or packet serialization.
  - Existing `ItemDialogs` docs explicitly keep reusable item-picker implementations separate from the live ExchangeDialog window.
  - B001 `00014T` research records `0x004af040` callers `0x004ad3bf` and `0x004adaeb` as Exchange code constructing `AddItemWithCountDialog`, not ownership of its implementation by Exchange.
- Decision:
  - Rejected as target owner. Keep as callee/support dependency.

### 4. NONE / Non-emitting / Padding / Compiler-only

- Evidence for:
  - No caller route to the target entry is proven.
- Evidence against:
  - The code is a complete IDA-modeled function with ordinary C++ source behavior, EH cleanup, allocation, constructor call, and clean boundaries.
  - ExchangeDialog owner/source route is strong.
- Decision:
  - Rejected. The target is reconstructable and class-owned, but formal C++ population is currently unsafe.

## Recommended Metadata And Score Changes

Recommended [UID:00014M] metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- Raise completion from `84` to `86` because this pass resolves the open source-facing name/signature direction, the `packet+2` selected item/type role, the `this+0x26c` field conflict with dispatcher `this+0x1cc`, exact PE route-negative evidence, EH cleanup role, and generated-output policy.
- Raise confidence from `88` to `90` because boundary/body/callee/negative-route facts are now independently checked by raw PE/Capstone in addition to existing MCP-backed docs.
- Do not raise higher because no direct caller or pointer route proves the original source call shape, and formal source integration with [UID:00014L] remains unresolved.
- Do not change owner/emitter. The narrow semantic owner remains [UID:00004R] `ExchangeDialog`; the file root remains [UID:0000J9].
- Do not split or rename. The current range is exact and single-purpose. The EH cleanup chunk is compiler support, not a source child.

Support-score recommendations:

- [UID:00004R] `ExchangeDialog`: no score change required. Add a support note for [UID:00014M] if edited.
- [UID:0000J9] `ExchangeDialog`: no score change required. Add a support note that `00014M` matches the retained duplicate-helper pattern already accepted for `00014O` and `00014P`.
- [UID:00014L] packet dispatcher: no immediate score change required, but if edited, update subcommand `1` wording to record the secondary-facet `this+0x1cc` explanation and duplicate [UID:00014M] relationship.
- [UID:000008] `AddItemWithCountDialog`: no score change required. Existing docs already record the two constructor call sites and the dialog fields; optional wording can use this report's `selected item/type byte` label.
- [UID:0000KE] `ItemDialogs`: no score change required.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00014M] yet.

The target clears the current numeric/emitter minimum if rescored to `86/90`, but the blocker is concrete and target-specific: raw PE/Capstone confirms no direct branch, no VA/RVA pointer, no vtable entry, no jump-table entry, and no static route to the helper start, while [UID:00014L] dispatcher subcommand `1` already contains equivalent source behavior inline. Pasting this as a formal standalone method now would likely make generated `ExchangeDialog.cpp` contain both a dispatcher inline constructor path and an unreferenced helper body before the broader ExchangeDialog source model decides whether the original source had a helper call, an inlined helper with retained out-of-line copy, or a private dead method retained by the linker.

Non-populate draft shape for future use only:

```cpp
// Do not paste into RECONSTRUCTION_CPP yet.
// Descriptive source shape only. Use only if the broader ExchangeDialog
// source integration decides to keep the retained out-of-line helper.
AddItemWithCountDialog *ExchangeDialog::OpenAddItemWithCountDialog(const unsigned char *packet)
{
    const unsigned char selectedItemType = packet[2];

    AddItemWithCountDialog *dialog =
        static_cast<AddItemWithCountDialog *>(operator new(0x274));
    if (dialog == 0) {
        return 0;
    }

    return new (dialog) AddItemWithCountDialog(m_exchangeId, selectedItemType);
}
```

Draft caveats:

- `OpenAddItemWithCountDialog`, `selectedItemType`, and `m_exchangeId` are descriptive source-quality names, not original-name proof.
- `operator new(0x274)` reflects the exact allocation size. If final project declarations know `sizeof(AddItemWithCountDialog)`, use that source-level type instead of the literal.
- The final source may instead express dispatcher subcommand `1` inline and leave [UID:00014M] as a retained out-of-line clone in documentation until binary-recreation policy for unreferenced retained methods is decided.

## Exact Supervisor Changes Required

### Target Page [UID:00014M]

Recommended placement: add a new change/evidence subsection near the current `Raw Code Evidence` and update the `Boundary And Open Questions` / `Changes` wording.

Exact insertion text:

```text
## 2026-06-18 B003 Source-Quality Recheck

B003 rechecked the target against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) after IDA MCP was unavailable in-session. Direct PE/Capstone inspection confirms the primary body `0x004ada90-0x004adb02` is `0x72` / 114 bytes (Verified with int_convert.py), preceded by `0x004ada84-0x004ada90` `0xcc` padding and followed by `0x004adb02-0x004adb10` `0xcc` padding. The body is a normal primary-object `__thiscall` helper ending in `ret 4`; the stack argument is a packet pointer and `eax` returns the constructed dialog pointer or `0`.

The helper reads `packet+2` through `0x00575470`, allocates `0x274` / 628 bytes for `AddItemWithCountDialog` (Verified with int_convert.py), and calls constructor `0x004af040` with primary ExchangeDialog `this+0x26c` plus the selected item/type byte. The best descriptive signature is `AddItemWithCountDialog *ExchangeDialog::OpenAddItemWithCountDialog(const unsigned char *packet)`. The byte at `packet+2` is not a count; it is the selected item/type token stored by `AddItemWithCountDialog` at `this+0x270` and later serialized in the dialog action packet `0x4A/2` with the user-entered count.

Raw PE route scans found no rel32 branch target to `0x004ada90`, no full-file absolute VA dword `0x004ada90`, no RVA dword `0x000ada90`, and no end-pointer dword `0x004adb02`. The only rel32 calls to `AddItemWithCountDialog` constructor `0x004af040` are dispatcher subcommand `1` at `0x004ad3bf` and this helper at `0x004adaeb`. The live dispatcher block at `0x004ad380-0x004ad3c6` duplicates the helper's packet-byte read, `0x274` allocation, and constructor call. Its `[this+0x1cc]` access is the secondary-vtable receiver view of the same primary ExchangeDialog field at `this+0x26c` because the secondary view is installed at object offset `+0xa0`.

The target remains ExchangeDialog-owned and reconstructable, but formal C++ should stay blank for now under the current combined-score/emitter policy. The blocker is not the stale `95/95` gate; it is the concrete source-shape issue that no static caller/table/vtable route reaches the helper while the dispatcher already contains the equivalent subcommand body. Treat this range as a retained out-of-line helper or retained duplicate of an inlined dispatcher helper until the broader `ExchangeDialog.cpp` reconstruction decides whether dispatcher case `1` should call a private helper or remain inline.
```

Exact metadata change:

```text
COMPLETION:84 -> 86
CONFIDENCE:88 -> 90
CANONICAL_OWNER:00004R unchanged
RECONSTRUCTABLE:TRUE unchanged
EMITTER_UIDS:00004R unchanged
RECONSTRUCTION_CPP remains blank
```

Recommended replacement for stale final-C++ sentence:

```text
Final C++ remains blank even though the target clears the current combined-score/emitter minimum after the B003 recheck. The target-specific blocker is source shape: no static route reaches `0x004ada90`, while [UID:00014L] dispatcher subcommand `1` contains the equivalent constructor path inline. Do not populate standalone formal C++ until the ExchangeDialog source integration decides retained helper versus inlined dispatcher representation.
```

### [UID:00014L] Packet Dispatcher

Recommended placement: update subcommand `1` row or add a short note under `Behavior` / `Evidence`.

Exact replacement for the subcommand `1` table row:

```text
| `1` | Reads selected item/type byte `packet+2`, allocates `0x274` / 628 bytes for `AddItemWithCountDialog` (Verified with int_convert.py), and constructs the picker through `0x004af040`. The block duplicates [UID:00014M]'s retained helper body. It reads exchange id at secondary-facet `this+0x1cc`, which is the same primary ExchangeDialog field as `this+0x26c` because the dispatcher is reached through the `+0xa0` vtable view. |
```

No score change required for [UID:00014L].

### [UID:00004R] ExchangeDialog Class

Recommended placement: update the `Method Notes` row for `OpenAddItemWithCountDialog`.

Exact replacement row:

```text
| `OpenAddItemWithCountDialog` | [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) | IDA-modeled retained helper that opens `AddItemWithCountDialog` from exchange server packet subcommand `1`; B003 PE/Capstone recheck found no direct/static/table route to the helper start, and [UID:00014L] dispatcher subcommand `1` contains the equivalent constructor path inline. |
```

Recommended addition to remaining caveats:

```text
- [UID:00014M] is now resolved as an ExchangeDialog-owned retained add-item-with-count helper, not an ItemDialogs implementation owner. Its behavior and fields are understood, but formal C++ remains blank until the broader `ExchangeDialog.cpp` integration decides retained out-of-line helper versus inlined dispatcher source shape.
```

No class score change required.

### [UID:0000J9] ExchangeDialog File

Recommended placement: add to `Boundary Notes` near the existing omitted helper bullets.

Exact insertion text:

```text
- 2026-06-18 B003 rechecked [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md): the helper is a real `0x72` / 114-byte IDA-modeled ExchangeDialog body (Verified with int_convert.py) that reads `packet+2` as a selected item/type byte, allocates `0x274` / 628 bytes for `AddItemWithCountDialog` (Verified with int_convert.py), and passes primary `this+0x26c` exchange id to constructor `0x004af040`. Direct PE scans found no branch or VA/RVA pointer route to `0x004ada90`; dispatcher subcommand `1` contains the equivalent constructor path inline and reaches the same exchange-id field through secondary-facet `this+0x1cc`. Keep this helper ExchangeDialog-owned, but keep formal C++ blank until the dispatcher/helper integration shape is decided.
```

No file score change required.

### [UID:00014K] ExchangeDialog Aggregate

Recommended placement: update the covered-range row for [UID:00014M].

Exact replacement row:

```text
| [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) | `ExchangeDialog` add-with-count helper | IDA-modeled retained helper that opens `AddItemWithCountDialog` from packet subcommand `1`; no static route to helper start is currently found, and dispatcher subcommand `1` duplicates the constructor path inline. |
```

No aggregate score change required.

### [UID:000008] AddItemWithCountDialog

Optional support update only; no score change required.

Recommended insertion under `Evidence Notes`:

```text
- 2026-06-18 B003 rechecked [UID:00014M] and confirmed the two constructor callers remain dispatcher `0x004ad3bf` and retained ExchangeDialog helper `0x004adaeb`. Both pass the exchange id plus the selected item/type byte from exchange packet `packet+2`; this byte is the value stored at AddItemWithCountDialog `this+0x270` and later serialized in opcode `0x4A` subcommand `2` with the user-entered count.
```

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly in this report-only task.

Placement context: replace the existing [UID:00014M] row in address order after [UID:00014L] and before [UID:00014N].

Exact replacement row:

```text
    - [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) 0x004ada90-0x004adb02 | helper | ExchangeDialogAddItemWithCountHelper : reconstructable : 86% : strong : ExchangeDialog retained add-item-with-count helper; 2026-06-18 B003 PE/Capstone recheck confirms `0x72` / 114-byte body (Verified with int_convert.py), primary-object `__thiscall` `ret 4`, `0x004ada84-0x004ada90` and `0x004adb02-0x004adb10` padding, C++ EH cleanup/handler at `0x005fe3a9`/`0x005fe3b4`, `packet+2` selected item/type byte read through `0x00575470`, `0x274` / 628-byte `AddItemWithCountDialog` allocation (Verified with int_convert.py), constructor call `0x004af040` with primary ExchangeDialog exchange id `this+0x26c`, zero direct branch/VA/RVA pointer routes to helper start, and duplicate dispatcher subcommand-1 constructor path at `0x004ad380-0x004ad3c6` using secondary-facet `this+0x1cc` for the same field. Keep owner/emitter [UID:00004R] and keep formal C++ blank until ExchangeDialog source integration decides retained out-of-line helper versus inlined dispatcher helper.
```

## Validation Commands For Supervisor

After applying target/support/coverage changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [00014M-ExchangeDialogAddItemWithCountHelper-source-quality-removed.md](00014M-ExchangeDialogAddItemWithCountHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional [UID:000008] support note is applied, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00014M-ExchangeDialogAddItemWithCountHelper-source-quality-removed.md](00014M-ExchangeDialogAddItemWithCountHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Remaining Blockers

- No behavior, boundary, ownership, packet-byte, or field-role blocker remains for [UID:00014M].
- The only remaining blocker is final source integration:
  - No static route reaches `0x004ada90`.
  - Dispatcher subcommand `1` contains the same constructor path inline.
  - The final `ExchangeDialog.cpp` reconstruction must decide whether to model the live dispatcher case as a call to `OpenAddItemWithCountDialog`, keep the dispatcher inline while documenting [UID:00014M] as a retained out-of-line clone, or preserve a private unreferenced method to recreate retained binary bytes.
- This blocker caps completion and blocks formal C++ population for [UID:00014M] now. It does not block `CANONICAL_OWNER:00004R`, `EMITTER_UIDS:00004R`, or `RECONSTRUCTABLE:TRUE`.
- IDA MCP was unavailable in this session. Existing MCP-backed docs plus raw PE/Capstone evidence were sufficient for this recommendation. If MCP becomes available, a final supervisor/A-agent pass can rerun `lookup_funcs`, `xrefs_to`, `callers`, and `decompile` for `0x004ada90` and `0x004ad320`, but no current recommendation depends on an unverified MCP-only claim.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B003/research/00014M-ExchangeDialogAddItemWithCountHelper-source-quality.md`
- Modified:
  - None. This was report-only work.
- Not edited:
  - by-* docs.
  - generated reports/source.
  - IDA DB.
  - `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00014M-ExchangeDialogAddItemWithCountHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00014M"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014M-ExchangeDialogAddItemWithCountHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00014M-ExchangeDialogAddItemWithCountHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
