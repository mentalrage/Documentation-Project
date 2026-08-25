** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
**FINAL RECOMMENDATION: Keep [UID:0003G3] unchanged as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, with blank C++.**

This is a valid pooled-literal/source-use route, not an unresolved non-emitting defect. Fresh IDA MCP and raw PE evidence reconfirm one exact UTF-16LE `Leave` cell at `0x00622f1c`, exactly four direct source-use references, no interior/suffix references, no RVA-form references, no ASCII duplicate, and no defensible single declaration owner across the ReconnectDialog/ConnectionClosedDialog and TerminalPane source families.

No canonical owner assignment, emitter change, split, merge, reclassification, IDA repair, score change, by-memory edit, generated-report edit, or `by-memory/-coverage-report.md` replacement row is recommended. No project files need editing beyond this B003 research report.

## Target

- Assignment: `B003-goal2-noowner-verification-0003G3`
- Target UID: `0003G3`
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- Final report path: `tools/leaser/Agents/Agent-B003/research/0003G3-SharedLeaveWideString-goal2-verification.md`
- Coverage source checked: `auto-generated/-ag-memory-coverage.md`
- Prior report used only as evidence: `Agent-B001/research/executed/0003G3-SharedLeaveWideString-live-goal2-no-owner-pass.md`
- Current target state: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank C++.

## Evidence Summary

The current state is still correct:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
RECONSTRUCTION_CPP CODE: blank
```

`CANONICAL_OWNER:NONE` is correct because the binary evidence proves shared use of one pooled literal, not a source-level shared declaration. `EMITTER_UIDS:0000N0,0000OI` is correct because current IDA evidence proves semantic source-use contexts in both file roots:

| Emitter | File root | Evidence |
| --- | --- | --- |
| `0000N0` | `NexusTK/network/ReconnectDialog.cpp` | `ConnectionClosedDialog` constructor paths at `0x00553c3f` and `0x00553cef`, plus `ReconnectDialog::OnButtonClick` replacement dialog path at `0x00554359`. |
| `0000OI` | `NexusTK/login/TerminalPane.cpp` | `TerminalPane::OnDisconnect` reconnect/leave prompt construction at `0x0058b5ac`. |

The item should remain reconstructable because the source-level semantics are the `L"Leave"` button label at those use sites. The page should keep blank C++ because adding standalone code would invent a shared declaration that current evidence does not prove; final source should spell or otherwise materialize the label in the consuming contexts.

## Current Documentation State

- The target page already documents the exact `0x00622f1c-0x00622f28` range, byte decoding, false IDA string labels, four direct use sites, and the two-emitter no-owner decision.
- `auto-generated/-ag-memory-coverage.md` lists [UID:0003G3] as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`, with both [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane` shown in the emitter summary.
- `by-memory/-coverage-report.md` already has an accurate row for [UID:0003G3], including the no-owner/two-emitter rationale and rejected candidates. No replacement text is required.
- [UID:0003CW] `ReconnectTerminalCopyStringTailMap` is correctly `RECONSTRUCTABLE:FALSE` as a mixed map over `Leave`, `Reconnect`, `No`, `Yes`, and `baram`; exact child pages carry the real source literals.
- [UID:0000N0] `ReconnectDialog` is a valid file root at `87/88`; [UID:0000OI] `TerminalPane` is a valid file root at `87/85`; [UID:0000HE] `AlertPanes` is a valid infrastructure file root at `85/88` but does not own feature-provided labels.

## Fresh IDA MCP Evidence

IDA MCP endpoint used: `http://127.0.0.1:63317/mcp`.

Session state:

```text
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Byte and string facts:

- `get_bytes(0x00622f1c, 0x58)` begins:
  `4c 00 65 00 61 00 76 00 65 00 00 00`, decoding as UTF-16LE `Leave`.
- The surrounding string-tail bytes decode as `Leave`, `Reconnect`, `No`, `Yes`, and ANSI `baram`.
- `entity_query` over `0x00622f10-0x00622f70` shows false/off-by-interior names `aAve` at `0x00622f20` and `aConnect` at `0x00622f2c`; only `baram` is visible to the IDA string cache in this local range.
- `get_string` similarly reports `L` at `0x00622f1c` and `ave` at `0x00622f20`, confirming IDA's string-cache split is a decode artifact rather than a source-boundary fact.

Xref facts:

| Address | Xrefs | Meaning |
| --- | --- | --- |
| `0x00622f1c` | `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` | Exactly four direct uses of the target `Leave` cell. |
| `0x00622f20`, `0x00622f22`, `0x00622f24`, `0x00622f26` | none | No interior/suffix child and no refs to false `aAve`. |
| `0x00622f28` | `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` | Paired `Reconnect` sibling at the same four semantic sites. |
| `0x00622f2c` | none | No refs to false `aConnect` interior suffix. |
| `0x00622f54` | none | Clean tail-map end. |

Function membership:

| Use address | IDA function | Current documented role |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10`, size `0xaf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant`, routed through [UID:0000N0]. |
| `0x00553cef` | `sub_553CC0`, size `0xae` | [UID:00038J] `ConnectionClosedDialogMethods`, routed through [UID:0000N0]. |
| `0x00554359` | `sub_554210`, size `0x1f6` | [UID:00038L] `ReconnectDialogMethods`, routed through [UID:0000N0]. |
| `0x0058b5ac` | `sub_58B470`, size `0x170` | [UID:0001JB] `TerminalPaneAndSetup` / `TerminalPane::OnDisconnect`, routed through [UID:0000OI]. |

Decompiler snippets confirm the use-site shape:

```text
sub_553C10: sub_49FEB0(sub_4F0350(154), dword_67A740, &off_622F28, &off_622F1C)
sub_553CC0: sub_49FEB0(sub_4F0350(154), arg,           &off_622F28, &off_622F1C)
sub_554210: sub_49FEB0(sub_4F0350(154), dword_67A740, &off_622F28, &off_622F1C)
sub_58B470: sub_4A0690(sub_4F0350(157), callback...,  &off_622F28, &off_622F1C)
```

This confirms the label is passed at feature prompt construction sites. The alert constructors are downstream consumers of caller-supplied labels, not declaration owners.

## Raw PE Evidence

Raw executable checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

- Image base: `0x400000`.
- Target RVA: `0x00222f1c`.
- Target file offset: `0x0022191c`.
- Section: `.rdata`.
- Raw bytes at the file offset begin:
  `4c 00 65 00 61 00 76 00 65 00 00 00 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00`.

Raw pattern search results:

| Pattern | Count | Matches |
| --- | ---: | --- |
| UTF-16LE `Leave\0` | 1 | file `0x22191c` / VA `0x00622f1c` |
| `push 0x00622f1c` bytes `68 1C 2F 62 00` | 4 | VAs `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| Absolute VA bytes `1C 2F 62 00` | 4 | operands at VAs `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad` |
| RVA bytes `1C 2F 22 00` | 0 | none |
| ASCII `Leave\0` | 0 | none |

This independently confirms the IDA evidence: one physical target literal and four direct absolute-immediate uses.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with emitters `0000N0,0000OI`

Evidence for:

- Direct xrefs split across two source file roots, not one declaration owner.
- Both emitters clear the current strict parent-side score gate.
- The same four use sites pair `Leave` with [UID:0003G4] `SharedReconnectWideString`.
- Raw PE and IDA agree on unique target bytes and exactly four absolute-immediate uses.
- Current by-structure and supervisor rules explicitly allow no-owner pooled literals with multiple proven emitters.

Evidence against:

- The stripped binary cannot prove whether original source repeated `L"Leave"`, used a macro, or had a private helper constant before pooling.

Decision: accepted. This uncertainty blocks a canonical owner but does not block emitter routing.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner

Evidence for:

- Covers three of four direct references.
- Owns `ConnectionClosedDialog` and `ReconnectDialog` classes and is a strong `87/88` file root.

Evidence against:

- Does not own `TerminalPane::OnDisconnect` at `0x0058b5ac`.
- Assigning canonical ownership to the largest consumer would hide a real TerminalPane source-use context.

Decision: reject as canonical owner; keep as emitter.

### 3. [UID:0000OI] `TerminalPane` as canonical owner

Evidence for:

- Owns the terminal disconnect prompt and callback setup at `0x0058b470`.
- Valid `87/85` file root under `NexusTK/login/`.

Evidence against:

- Covers only one of four direct target references.
- Does not own the two `ConnectionClosedDialog` constructor paths or the `ReconnectDialog` replacement-dialog path.

Decision: reject as canonical owner; keep as emitter.

### 4. [UID:0000HE] `AlertPanes` as canonical owner

Evidence for:

- `AlertPane` and `VersatileAlertPane` constructors receive these label pointers.
- `AlertPanes` is a valid shared dialog infrastructure file root.

Evidence against:

- The labels are caller-provided feature prompt labels.
- `AlertPanes.md` and `proposed-source-tree.md` explicitly keep feature-specific reconnect alerts with feature modules.
- IDA decompilation shows feature code passes the labels into alert constructors; no alert-owned static label table or initializer is present.

Decision: reject.

### 5. Class-level parents

Evidence for:

- [UID:000036] `ConnectionClosedDialog`, [UID:0000BR] `ReconnectDialog`, and [UID:0000EG] `TerminalPane` each own part of the use-site behavior.

Evidence against:

- No class covers all four source-use refs.
- The current output-routing need is file-root emission, not a single class-owned shared declaration.

Decision: reject as canonical owners for this pooled literal.

### 6. [UID:0003CW] physical string-tail map or new shared-label file

Evidence for:

- The physical map contains the target, and a shared-label source file is theoretically possible.

Evidence against:

- [UID:0003CW] is a mixed `RECONSTRUCTABLE:FALSE` index spanning ReconnectDialog, TerminalPane, CopyWindow, and shared packet-literal children.
- No IDA symbol, pointer table, initializer, object, or source-tree evidence supports a standalone shared-label declaration.

Decision: reject.

## Split, Merge, Reclassification, And Repair Review

- No split needed: `0x00622f1c-0x00622f28` is already the exact UTF-16LE `Leave` child; interior addresses have no refs.
- No merge needed: sibling `Reconnect`, CopyWindow `No`/`Yes`, and ANSI `baram` children have distinct source-use evidence and are already modeled under the non-emitting map.
- No reclassification needed: `string-data`, `RECONSTRUCTABLE:TRUE`, and source-authored pooled literal handling remain accurate.
- No IDA repair needed: false names `aAve`/`aConnect` are already documented decode artifacts and do not require IDA-side edits for this assignment.
- No coverage-row change needed: the existing shared coverage row already captures the material decision.

## Exact Recommended Changes

No project documentation changes are recommended beyond creating this report.

Recommended target metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No `by-memory/-coverage-report.md` replacement, insert, or delete text is needed.

## Validation And Execution Notes

- Read current `Agent-B003/goal.md`, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and the tracker context.
- Checked current target page, generated memory coverage row, shared memory coverage row, containing map, prior B001 report, relevant file roots, class pages, consumer pages, and proposed source tree entries.
- Used fresh IDA MCP for server health, byte reads, string/name queries, xrefs, function lookup, disassembly/decompiler confirmation, and byte-pattern search.
- Used raw PE byte search as a second route for uniqueness and reference-count evidence.
- No dry runs were used.
- No validator command was required because this is report-only and no by-* docs were changed.
- No lease was required because the only created file is inside `Agent-B003/research`.

## Confidence

Recommendation confidence: high, `95/100`.

The remaining uncertainty is only the normal stripped-binary limitation: original source could have used repeated literals, a macro, or a private constant before linker pooling. Current evidence does not justify inventing that declaration, so `CANONICAL_OWNER:NONE` plus proven emitter routes is the strongest current output-emission model.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B003/research/0003G3-SharedLeaveWideString-goal2-verification.md`

Modified:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B003/0003G3-SharedLeaveWideString-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
