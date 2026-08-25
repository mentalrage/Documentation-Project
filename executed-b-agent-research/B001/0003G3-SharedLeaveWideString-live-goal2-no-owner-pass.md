** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Ownership / Source-Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N0,0000OI`.
- Required action: no canonical owner assignment, emitter change, split, merge, reclassification, child-page creation, IDA repair, score change, coverage-row replacement, or by-* documentation edit is recommended.
- Confidence: high. Fresh IDA MCP evidence again proves one exact UTF-16LE `Leave` literal, exactly four direct source-use refs, no interior refs, no RVA-form target refs, no ASCII duplicate, and no single declaration owner across the ReconnectDialog-family and TerminalPane source roots.

Recommended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
RECONSTRUCTION_CPP:
```

This is a valid no-owner-with-emitters pooled-literal case. It is not a non-emitting defect. The rebuilt source should spell `L"Leave"` at the semantic use sites in [UID:0000N0] `ReconnectDialog.cpp` / `ConnectionClosedDialog` code and [UID:0000OI] `TerminalPane.cpp`; the by-memory item should not become a standalone global/string declaration.

Do not edit `by-memory/-coverage-report.md`. The current row remains accurate:

```text
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; B003 post-migration and B001 second-pass reviews confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, no target RVA refs, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

## Supporting Research

## Target

- Target UID: `0003G3`
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- Address range: `0x00622f1c-0x00622f28`
- Current supervisor classification: live Goal 2 no-owner memory item with existing emitters.
- Current state reviewed: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active `2026-06-14 Live Goal 2 No-Owner Memory Pass`.
- Prior report treated as evidence only: `Agent-B003/research/executed/0003G3-SharedLeaveWideString-fresh-no-owner-pass.md`.
- Final report path: `tools/leaser/Agents/Agent-B001/research/0003G3-SharedLeaveWideString-live-goal2-no-owner-pass.md`.

The current target page was treated as documentation evidence, not proof. The final recommendation below is based on current docs plus fresh IDA MCP verification.

## Executive Recommendation

Keep the existing unusual output model: `CANONICAL_OWNER:NONE` with two emitters.

The target is an exact `0x0c` / 12-byte UTF-16LE `Leave` literal child (Verified with `tools/int_convert.py`). IDA confirms the target bytes are unique and that all direct uses pass the target as a button label paired with [UID:0003G4] `SharedReconnectWideString`.

The four direct use sites split across two real source roots:

| Source-use family | Direct xrefs | Correct emitter |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor paths | `0x00553c3f`, `0x00553cef` | [UID:0000N0] `by-file/ReconnectDialog.md` |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | [UID:0000N0] `by-file/ReconnectDialog.md` |
| `TerminalPane::OnDisconnect` reconnect/leave prompt | `0x0058b5ac` | [UID:0000OI] `by-file/TerminalPane.md` |

No canonical owner should be assigned. `ReconnectDialog` owns three use sites but not the terminal disconnect prompt. `TerminalPane` owns the terminal prompt but not the connection/reconnect dialog constructors. `AlertPanes` owns reusable alert infrastructure, but not the caller-provided feature labels. The physical parent is a mixed, non-emitting string-tail map.

## Supervisor Active Recheck

The user assigned this target as Agent-B001's next live Goal 2 no-owner memory pass on 2026-06-14 and required this exact report path. The tracker active row lists `0003G3` as assigned to Agent-B001 with prior B003 report as evidence only.

No split repair is required. The current target is already the exact `Leave` child. The containing [UID:0003CW] `0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap` is already a non-emitting mixed map with exact children for `Leave`, `Reconnect`, `No`, `Yes`, and `baram`.

No by-* edit was made. The only output is this research report in Agent-B001's own folder.

## Inference Research Guidance Check

`by-structure.md` and the supervisor override distinguish canonical source ownership from emitter routing. For source-authored data with no defensible single canonical declaration owner, especially compiler/linker-pooled strings, `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` is valid when IDA proves multiple source-use contexts.

`inference_research.md` warns that address adjacency and merged `.rdata` layout do not prove source ownership. For this target, the decisive evidence is not its physical adjacency to `Reconnect`, `No`, `Yes`, or `baram`. The decisive evidence is the exact xref distribution and the owning function families.

Evidence separation used here:

- IDA facts: bytes, decoded range, xrefs, function membership, disassembly, signatures, byte-pattern searches, trace/data-flow, and component analysis.
- Documentation evidence: current by-memory target/container/sibling pages, source file roots, class pages, exact consumer pages, generated coverage rows, and coverage report row.
- Inference: the final source should repeat or otherwise materialize `L"Leave"` at semantic use sites rather than model one address-stable shared global.

## Evidence Standards Used

Evidence sources used:

- IDA MCP `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `make_signature_for_range`, `trace_data_flow`, `analyze_component`, and `disasm`.
- Current `by-memory` target, sibling, parent, and consumer pages.
- Current `by-file` and `by-class` pages for `ReconnectDialog`, `ConnectionClosedDialog`, `TerminalPane`, and `AlertPanes`.
- Current `auto-generated/-ag-memory-coverage.md` and `by-memory/-coverage-report.md` rows.
- `tools/int_convert.py` for numeric conversions.

This is strong enough for a no-change recommendation because the byte pattern, direct xrefs, function ownership, source-root docs, and negative interior/RVA/ASCII evidence all agree.

## IDA MCP Facts

Fresh MCP session facts:

```text
session_id: a001_goal2_class_batch
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
module: NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Byte review at `0x00622f1c` returned the whole local string-tail island:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
bc eb 64 00 00 4b 55 00 10 4b 4f 00 c0 b6 41 00 08 ec 64 00
```

Decoded context:

| Range | Bytes / decoding | Interpretation |
| --- | --- | --- |
| `0x00622f1c-0x00622f28` | UTF-16LE `Leave` | Current target. |
| `0x00622f28-0x00622f3c` | UTF-16LE `Reconnect`, `0x14` / 20 bytes (Verified with `tools/int_convert.py`) | Paired sibling button label. |
| `0x00622f3c-0x00622f44` | UTF-16LE `No` plus alignment | CopyWindow child. |
| `0x00622f44-0x00622f4c` | UTF-16LE `Yes` | CopyWindow child. |
| `0x00622f4c-0x00622f54` | ANSI `baram` plus alignment | Shared packet literal child. |
| `0x00622f54` | no string, no xrefs | End of string-tail map. |
| `0x00622f58` | successor table/vtable region | Region successor, outside this target and outside the tail map. |

IDA string-cache caveat:

| Address | `get_string` result | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | `L` | False partial decode of target. |
| `0x00622f20` | `ave` | False interior suffix; not a separate source string. |
| `0x00622f28` | `R` | False partial decode of sibling. |
| `0x00622f2c` | `connect` | False interior suffix of sibling. |
| `0x00622f3c` | `No` | Real successor child. |
| `0x00622f44` | `Y` | False partial decode of `Yes`. |
| `0x00622f4c` | `baram` | Real ANSI successor child. |

Signature/search facts:

| Check | Result |
| --- | --- |
| `make_signature_for_range(0x00622f1c, 0x00622f28)` | Unique signature `4C 00 65 00 61 00 76 00 65 00 00 00`. |
| `find_bytes` exact UTF-16LE target pattern | One match at `0x00622f1c`. |
| `find_bytes` absolute target VA `1C 2F 62 00` | Four matches at immediate operands `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad`. |
| `find_bytes` full `push imm32` pattern `68 1C 2F 62 00` | Four matches at instruction starts `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac`. |
| `find_bytes` target RVA `1C 2F 22 00` | Zero matches. |
| `find_bytes` ASCII `Leave\0` | Zero matches. |

Xref facts:

| Address | Xrefs | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | Four xrefs: `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` | All known target uses. |
| `0x00622f20`, `0x00622f22`, `0x00622f24`, `0x00622f26` | Zero xrefs | No interior/tail child. |
| `0x00622f28` | Four xrefs paired with target: `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` | Paired `Reconnect` label. |
| `0x00622f2c` | Zero xrefs | No false-interior `aConnect` source string. |
| `0x00622f54` | Zero xrefs | Tail-map boundary is clean. |
| `0x00622f58` | One successor xref in `sub_554680` | Outside target/map; not an owner clue. |

Function membership:

| Query / xref | IDA function | Size | Documentation role |
| --- | --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | `0xaf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant`. |
| `0x00553cef` | `sub_553CC0` | `0xae` | [UID:00038J] `ConnectionClosedDialogMethods`. |
| `0x00554359` | `sub_554210` | `0x1f6` | [UID:00038L] `ReconnectDialogMethods`, button handler path. |
| `0x0058b5ac` | `sub_58B470` | `0x170` | [UID:0001JB] `TerminalPaneAndSetup`, `TerminalPane::OnDisconnect`. |
| `0x0058b620` | `sub_58B620` | `0x2f` | [UID:0001JD] TerminalPane reconnect/leave callback target. |
| `0x0049feb0` | `sub_49FEB0` | `0x6c5` | AlertPane core constructor. |
| `0x004a0690` | `sub_4A0690` | `0x47` | VersatileAlertPane wrapper. |

Trace/data-flow:

`trace_data_flow(0x00622f1c, backward, max_depth=2)` reached exactly the same four `push offset off_622F1C` nodes and their adjacent `dword_67A750` text/context loads. It did not reveal a table owner, initializer, or shared declaration object.

Component analysis:

- `analyze_component` over `sub_553C10`, `sub_553CC0`, `sub_554210`, `sub_58B470`, `sub_49FEB0`, and `sub_4A0690` reported shared globals `off_622F1C` and `off_622F28` accessed by `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`.
- Internal call graph edges flow from the feature constructors/handlers into alert constructors: `sub_553C10 -> sub_49FEB0`, `sub_553CC0 -> sub_49FEB0`, `sub_554210 -> sub_553CC0` and `sub_49FEB0`, `sub_58B470 -> sub_4A0690` and `sub_49FEB0`, and `sub_4A0690 -> sub_49FEB0`.
- This supports `AlertPanes` as downstream infrastructure, not as owner of the caller-supplied `Leave` label.

## Direct Xref / Caller Inventory

Representative disassembly snippets:

```text
sub_553C10:
0x00553c39: mov ecx, dword_67A750
0x00553c3f: push offset off_622F1C
0x00553c44: push offset off_622F28
0x00553c49: push dword_67A740
0x00553c4f: push 9Ah
0x00553c54: call sub_4F0350
0x00553c5c: call sub_49FEB0

sub_553CC0:
0x00553ce9: mov ecx, dword_67A750
0x00553cef: push offset off_622F1C
0x00553cf4: push offset off_622F28
0x00553cf9: push [ebp+arg_0]
0x00553cfc: push 9Ah
0x00553d01: call sub_4F0350
0x00553d09: call sub_49FEB0

sub_554210:
0x00554353: mov ecx, dword_67A750
0x00554359: push offset off_622F1C
0x0055435e: push offset off_622F28
0x00554363: push dword_67A740
0x00554369: push 9Ah
0x0055436e: call sub_4F0350
0x00554376: call sub_49FEB0

sub_58B470:
0x0058b5a6: mov ecx, dword_67A750
0x0058b5ac: push offset off_622F1C
0x0058b5b1: push offset off_622F28
0x0058b5b6: push esi
0x0058b5b7: push ebx
0x0058b5b8: push 9Dh
0x0058b5bd: call sub_4F0350
0x0058b5c3: mov ecx, edi
```

The first three snippets are in the ReconnectDialog/ConnectionClosedDialog source family. The fourth is TerminalPane's disconnect prompt construction. All four use the same physical `Leave` cell but belong to different source roots.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `SharedLeaveWideString` | Pooled UTF-16LE `Leave` button label | `TRUE` | `NONE` | `89/94` | Keep no-owner with emitters `0000N0,0000OI`. |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `SharedReconnectWideString` | Paired pooled UTF-16LE `Reconnect` button label | `TRUE` | `NONE` | `89/94` | Same two-emitter no-owner pattern. |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed string-tail map over `Leave`, `Reconnect`, `No`, `Yes`, `baram` | `FALSE` | `NONE` | `89/93` | Correct non-emitting container. |
| `0x00553c10-0x00553cbf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` | One connection-closed constructor use site | `TRUE` | `0000N0` | `82/86` | ReconnectDialog-family source-use evidence. |
| `0x00553cc0-0x00553e5b` | [UID:00038J] `ConnectionClosedDialogMethods` | Alternate constructor/handlers | `TRUE` | `000036` -> `0000N0` | `86/89` | ReconnectDialog-family source-use evidence. |
| `0x00553f40-0x005544b8` | [UID:00038L] `ReconnectDialogMethods` | Reconnect constructors/button/timeout methods | `TRUE` | `0000BR` -> `0000N0` | `86/89` | ReconnectDialog-family source-use evidence. |
| `0x0058af50-0x0058c350` | [UID:0001JB] `TerminalPaneAndSetup` | TerminalPane/TerminalSetup block | `TRUE` | `0000OI` | `85/86` | TerminalPane source-use evidence. |
| `0x0058b620-0x0058b64f` | [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Callback installed by the terminal prompt | `TRUE` | `0000OI` | `85/91` | Confirms TerminalPane-specific prompt behavior. |

## Documentation Evidence And IDA Status

Current docs that support this recommendation:

- [UID:0003G3] already records `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N0,0000OI`.
- [UID:0003CW] records the physical parent as a non-emitting mixed string-tail map and lists exact children.
- [UID:0003G4] uses the same no-owner/two-emitter model for the paired `Reconnect` label.
- [UID:0000N0] `ReconnectDialog` is a scored `87/88` source-file root under `NexusTK/network/`.
- [UID:0000OI] `TerminalPane` is a scored `87/85` source-file root under `NexusTK/login/`.
- [UID:0000HE] `AlertPanes` is a scored `85/88` reusable alert infrastructure root, but its own page explicitly keeps feature-specific reconnect alerts with the feature modules.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0003G3] as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`.
- The generated emitter-summary row names both [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane`.
- `by-memory/-coverage-report.md` contains the current row quoted in the final recommendation section. It needs no replacement.

Current documentation caveats not requiring repair:

- IDA's `off_622F1C` / `aAve` labels are false typing/string-cache artifacts. The current docs already explain them, and no IDA-side rename is required for this report.
- The generated memory coverage display path shows `auto-generated/NexusTK/network/ReconnectDialog.cpp`; the emitter list still contains both source-use UIDs. This is not a reason to collapse ownership or change emitters.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000N0,0000OI`

Evidence for:

- Fresh IDA confirms four direct source-use refs, split three-to-one across ReconnectDialog-family and TerminalPane code.
- The exact literal bytes are unique, but source use is not unique to one module.
- The sibling `Reconnect` label has the same four paired source-use sites.
- Both emitter file roots clear the current parent-side score gate.
- The supervisor's strange owner/emitter split rule explicitly allows pooled strings to remain no-owner while emitting through all proven source-use contexts.

Evidence against:

- It is less tidy than a single canonical owner, and the generated output path display picks one representative file.
- The stripped binary cannot prove whether original source used repeated literals or a private shared constant before pooling.

Decision: accept. This is the best and current model.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner

Evidence for:

- Covers three of four xrefs.
- Owns the `ConnectionClosedDialog` and `ReconnectDialog` classes that create or recreate the connection-closed prompt.
- Source file root is strong at `87/88`.

Evidence against:

- Does not own `TerminalPane::OnDisconnect` at `0x0058b5ac`.
- Assigning it as canonical owner would hide a real terminal source-use site.
- The literal is caller-provided alert label data, not a reconnect module global with writer/initializer evidence.

Decision: reject as canonical owner; retain as emitter.

### 3. [UID:0000OI] `TerminalPane` as canonical owner

Evidence for:

- Owns the terminal disconnect prompt and callback setup.
- Source file root clears the current gate at `87/85`.

Evidence against:

- Covers only one of four target xrefs.
- Does not own `ConnectionClosedDialog` constructor paths or `ReconnectDialog::OnButtonClick`.

Decision: reject as canonical owner; retain as emitter.

### 4. [UID:0000HE] `AlertPanes` as canonical owner

Evidence for:

- AlertPane/VersatileAlertPane constructors consume the labels after the feature code pushes them.
- It is a valid scored reusable alert source root.

Evidence against:

- The labels are caller-provided feature prompt labels, not alert infrastructure constants.
- `AlertPanes.md` explicitly keeps feature-specific reconnect alerts with feature modules unless later xrefs prove a common alert-helper source.
- Component analysis shows the feature functions pass the labels into alert constructors; downstream infrastructure consumption is not source declaration ownership.

Decision: reject.

### 5. Class-level parents

Evidence for:

- [UID:000036] `ConnectionClosedDialog`, [UID:0000BR] `ReconnectDialog`, and [UID:0000EG] `TerminalPane` each own part of the behavior.

Evidence against:

- No class owns all four uses.
- The final emission route for this shared literal is file-level source-use routing, not a single class-owned declaration.

Decision: reject as canonical owner candidates.

### 6. [UID:0003CW] physical string-tail map

Evidence for:

- Physically contains all bytes.
- Documents the exact local string island.

Evidence against:

- It is already correctly classified `RECONSTRUCTABLE:FALSE` and non-emitting.
- The same map includes CopyWindow `No`/`Yes` and shared `baram` with different source routes.

Decision: reject.

### 7. New shared-label owner/source file

Evidence for:

- A shared prompt-label helper or constants header is theoretically possible.

Evidence against:

- No IDA symbol, initializer, pointer table, source-tree entry, or xref pattern supports such a declaration.
- All observed uses are immediate pushes at semantic call sites.
- Creating a shared owner would invent source structure to explain compiler/linker string pooling.

Decision: reject.

## Negative Evidence Summary

Checked and rejected:

- Interior split: `xrefs_to` found zero refs to `0x00622f20`, `0x00622f22`, `0x00622f24`, and `0x00622f26`.
- Tail/boundary split: `xrefs_to(0x00622f54)` returned zero refs.
- False IDA suffix string `aAve`: zero refs to `0x00622f20`.
- ASCII duplicate: `find_bytes` found no ASCII `Leave\0`.
- RVA-form target refs: `find_bytes` found zero matches for `1C 2F 22 00`.
- Standalone shared declaration: trace/data-flow found only the four push sites and adjacent text/context loads.
- Largest-consumer ownership: `ReconnectDialog` covers most uses but not TerminalPane.
- Generic alert ownership: alert constructors consume labels but do not originate them.
- Mixed-container ownership: [UID:0003CW] spans unrelated source owners and is correctly non-emitting.

## Final Recommendation

Exact recommended changes:

- No by-* edits.
- No coverage-report edits.
- No generated-report edits.
- No score changes.
- No IDA repair.
- No new child pages.

Exact state to retain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
```

Why no-owner/multiple-emitter is correct:

- `CANONICAL_OWNER:NONE` avoids falsely assigning one declaration owner to a pooled string used by two independent source roots.
- `EMITTER_UIDS:0000N0,0000OI` prevents the reconstructable literal from becoming non-emitting and records the two proven source-use file roots.
- The item is reconstructable because the source-level semantics are a `L"Leave"` button label at feature prompt construction sites, even though the binary has one pooled `.rdata` cell.

## Follow-Up Actions

Supervisor actions:

- Mark this B001 report as complete-no-change if using the tracker.
- Do not apply a `by-memory/-coverage-report.md` replacement for this item.

A-agent actions:

- If future method-level C++ is entered for [UID:00023O], [UID:00038J], [UID:00038L], or [UID:0001JB], spell the label as source-level `L"Leave"` at the semantic prompt construction site rather than introducing a shared address-based global.

B001 future research:

- No further B001 split/ownership action is needed for [UID:0003G3] unless new source or IDA evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: current `89/94` remains justified.
- Remaining uncertainty: the stripped binary cannot prove whether the original source repeated `L"Leave"` literals, used a local macro, or had an unmodeled private shared constant that was later folded. No current evidence supports acting on that uncertainty.

## Validator Results

No validator command was required. This was a report-only confirmation and no by-* files were changed.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0003G3-SharedLeaveWideString-live-goal2-no-owner-pass.md`

Modified:

- None.

Leases:

- None required. The only new file is in Agent-B001's own research folder.

Worktree note:

- Before this report was created, scoped status already showed dirty/untracked files for generated coverage, `by-memory/-coverage-report.md`, the target by-memory page, and the tracker. Those files were not edited or reverted by this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B001/0003G3-SharedLeaveWideString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
