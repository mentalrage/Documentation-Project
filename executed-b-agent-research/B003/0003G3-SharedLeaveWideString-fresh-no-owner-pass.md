** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Fresh No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.
- Required action: no canonical-owner assignment, emitter repair, split, merge, reclassification, IDA-safe name repair, score change, by-* target edit, generated-report edit, or `by-memory/-coverage-report.md` edit is recommended.
- Confidence: high. Current IDA MCP and raw PE evidence prove exactly one UTF-16LE `Leave` literal at `0x00622f1c`, exactly four direct source-use references split across ReconnectDialog-family code and `TerminalPane::OnDisconnect`, no interior references, no ASCII duplicate, no RVA-form references, and no defensible single declaration owner.

This is a valid no-owner-with-emitters pooled-literal case. It is not a non-emitting defect. Final source should spell `L"Leave"` at the semantic consumer call sites when those methods are reconstructed; this by-memory page should not become a standalone global/string declaration.

## Supporting Research

## Target

- Target UID: `0003G3`
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- Address range: `0x00622f1c-0x00622f28`
- Source queue/report row: current Goal 2 no-owner memory sweep from `auto-generated/-ag-memory-coverage.md`.
- Current generated state: `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`.
- Prior report reviewed only as historical context: `tools/leaser/Agents/Agent-B003/research/executed/0003G3-SharedLeaveWideString-current-no-owner-research.md`.
- Active tracker evidence: `tools/leaser/Agents/no_owner_b-agent-tracker.md` contains active and completed historical rows for `0003G3`; the current user assignment required this fresh report at the root of Agent-B003 research.

Current target metadata before:

```text
UID:0003G3
COMPLETION:89
CONFIDENCE:94
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Recommended metadata after:

```text
UID:0003G3
COMPLETION:89
CONFIDENCE:94
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Score impact: no change. Completion/confidence remain `89/94`.

## Executive Recommendation

Keep the target as an exact source-authored UTF-16LE `Leave` button-label literal with no canonical owner and two proven emitter routes:

| Source-use family | Direct xrefs | Emitter route |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor variants | `0x00553c3f`, `0x00553cef` | [UID:0000N0] `by-file/ReconnectDialog.md` |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | [UID:0000N0] `by-file/ReconnectDialog.md` |
| `TerminalPane::OnDisconnect` reconnect/leave prompt | `0x0058b5ac` | [UID:0000OI] `by-file/TerminalPane.md` |

Do not assign [UID:0000N0] `ReconnectDialog`, [UID:0000OI] `TerminalPane`, [UID:0000HE] `AlertPanes`, any class-level page, the physical string-tail map, or a new shared-label file as canonical owner. Each would overclaim a compiler/linker-pooled literal whose observed use crosses independent source roots.

## Supervisor Active Recheck

- Trigger: fresh B003 Goal 2 no-owner memory pass for [UID:0003G3].
- Split repair required: no. The assigned range is already an exact `0x0c` byte child for the UTF-16LE `Leave` literal.
- Every source-bearing child in scope: the assigned item only. Siblings were checked as boundary/context evidence, especially paired [UID:0003G4] `SharedReconnectWideString`.
- Canonical owner repair required: no.
- Emitter repair required: no. The current emitters `0000N0,0000OI` exactly match the proven source-use roots.
- Shared coverage report edit: not needed.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from output routing. It states that `CANONICAL_OWNER` records the direct semantic owner, while `EMITTER_UIDS` routes generated output. It also explicitly allows compiler/linker-pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while using multiple emitters for proven source-use contexts.

`inference_research.md` warns that nearby data and merged strings can be products of linker order, constant pooling, COMDAT behavior, or section layout. I therefore treated the containing `.rdata` island and adjacent strings as boundary/context evidence, not ownership proof. The recommendation is based on exact bytes, xrefs, containing functions, file-root docs, and negative evidence.

Existing documentation assumptions rechecked rather than accepted:

- the false IDA pointer/string labels around `0x00622f1c`;
- the current two-emitter routing;
- whether `AlertPanes` owns caller-provided labels;
- whether the physical container or a new shared-label source file should own this literal;
- whether a split/merge/reclassification is warranted.

## Evidence Standards Used

- IDA MCP session `a001_goal2_class_batch`: `server_health`, `lookup_funcs`, `get_bytes`, `get_string`, `xrefs_to`, `entity_query`, `make_signature_for_range`, `trace_data_flow`, `analyze_component`, `find_bytes`, `find_regex`, `decompile`, and selected `disasm`.
- Raw PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, VA-to-raw conversion, target bytes, whole-file byte-pattern searches, absolute-VA immediate searches, `push imm32` searches, target-RVA search, and interior/boundary negative searches.
- Documentation evidence: target page, current generated coverage rows, `by-memory/-coverage-report.md`, containing map [UID:0003CW], source roots [UID:0000N0], [UID:0000OI], [UID:0000HE], and exact consumer pages [UID:00023O], [UID:00038J], [UID:00038L], [UID:0001JB], [UID:0001JD], and [UID:00012W].

Evidence strength is high for bytes, boundaries, xrefs, emitter routes, and rejected split/merge. Original source declaration style remains inferential because the binary is stripped and string pooling can erase source-level duplication.

## IDA MCP Facts

Live IDA state:

```text
session: a001_goal2_class_batch
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
imagebase: 0x00400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Function membership for target xrefs:

| Query | Function | Size | Documentation interpretation |
| --- | --- | ---: | --- |
| `0x00553c3f` | `sub_553C10` | `0xaf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` |
| `0x00553cef` | `sub_553CC0` | `0xae` | [UID:00038J] `ConnectionClosedDialogMethods` |
| `0x00554359` | `sub_554210` | `0x1f6` | [UID:00038L] `ReconnectDialogMethods` |
| `0x0058b5ac` | `sub_58B470` | `0x170` | [UID:0001JB] `TerminalPaneAndSetup`, `TerminalPane::OnDisconnect` |
| `0x0058b620` | `sub_58B620` | `0x2f` | [UID:0001JD] reconnect/leave callback |
| `0x004a0690` | `sub_4A0690` | `0x47` | `VersatileAlertPane` wrapper |
| `0x0049feb0` | `sub_49FEB0` | `0x6c5` | `AlertPane` core constructor |

Data bytes from `0x00622f1c`:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
bc eb 64 00 00 4b 55 00 10 4b 4f 00
```

Decoded subranges:

| Range | Decoding | Role |
| --- | --- | --- |
| `0x00622f1c-0x00622f28` | UTF-16LE `Leave` | current target |
| `0x00622f28-0x00622f3c` | UTF-16LE `Reconnect` | paired sibling |
| `0x00622f3c-0x00622f44` | UTF-16LE `No` plus alignment | CopyWindow child |
| `0x00622f44-0x00622f4c` | UTF-16LE `Yes` | CopyWindow child |
| `0x00622f4c-0x00622f54` | ANSI `baram` plus alignment | shared packet literal |
| `0x00622f58` | `??_7Region@@6B@` | successor vtable region, outside the string-tail map |

IDA string/name limitations:

| Address | IDA value/name evidence | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | `get_string` returns `L`; trace names `off_622F1C` | false pointer/partial string decode at target start |
| `0x00622f20` | `get_string` returns `ave`; name `aAve` | false interior suffix; zero xrefs |
| `0x00622f28` | `get_string` returns `R`; trace names `off_622F28` | start of paired `Reconnect` sibling |
| `0x00622f2c` | `get_string` returns `connect`; name `aConnect` | false interior suffix of sibling |
| `0x00622f3c` | `get_string` returns `No`; name `aNo` | real successor child |
| `0x00622f4c` | `get_string` returns `baram`; name `aBaram_0` | real ANSI successor child |

`entity_query(strings, 0x00622f1c-0x00622f60)` listed only `baram`, so IDA's strings cache does not reliably model the short wide literals. Raw bytes and xrefs are the stronger evidence.

`make_signature_for_range(0x00622f1c-0x00622f28)` returned a unique signature:

```text
4C 00 65 00 61 00 76 00 65 00 00 00
```

Direct xrefs to `0x00622f1c`:

| Xref | Function | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | `ConnectionClosedDialog` constructor variant passes `Leave` |
| `0x00553cef` | `sub_553CC0` | alternate `ConnectionClosedDialog` constructor path passes `Leave` |
| `0x00554359` | `sub_554210` | `ReconnectDialog::OnButtonClick` replacement alert path passes `Leave` |
| `0x0058b5ac` | `sub_58B470` | `TerminalPane::OnDisconnect` prompt passes `Leave` |

Paired sibling xrefs to `0x00622f28`:

| Xref | Function | Meaning |
| --- | --- | --- |
| `0x00553c44` | `sub_553C10` | paired `Reconnect` label |
| `0x00553cf4` | `sub_553CC0` | paired `Reconnect` label |
| `0x0055435e` | `sub_554210` | paired `Reconnect` label |
| `0x0058b5b1` | `sub_58B470` | paired `Reconnect` label |

Negative xref facts:

```text
0x00622f20: 0 xrefs
0x00622f22: 0 xrefs
0x00622f24: 0 xrefs
0x00622f26: 0 xrefs
0x00622f54: 0 xrefs
0x00622f58: 1 xref, successor Region vtable region at 0x005546c1
```

`trace_data_flow(0x00622f1c, backward, max_depth=2)` reaches exactly the four `push offset off_622F1C` code nodes above, plus nearby `dword_67A750` text/context loads. It does not find a table owner or declaration object.

`analyze_component` over the reconnect/terminal/alert functions reports `off_622F1C` and `off_622F28` as shared globals accessed by `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`. The internal call graph shows reconnect/connection-closed constructors and TerminalPane prompt construction both flowing into alert constructors, but no shared label owner function:

```text
sub_553C10 -> sub_49FEB0
sub_553CC0 -> sub_49FEB0
sub_554210 -> sub_553CC0 and sub_49FEB0
sub_58B470 -> sub_4A0690 and sub_49FEB0
sub_4A0690 -> sub_49FEB0
```

`find_regex` for `Leave`, `Reconnect`, `ConnectionClosed`, `TerminalPane`, `AlertPane`, `.pdb`, `.cpp`, and `RSDS` found RTTI/type strings such as `ConnectionClosedDialog`, `ReconnectDialog`, `TerminalPane`, and `AlertPane`, plus the imported `LeaveCriticalSection`. It did not reveal source-path, PDB, or shared-label declaration evidence for this literal.

## Representative Decompiler / Disassembly Evidence

`sub_553C10` constructs a connection-closed alert and passes the pair to `sub_49FEB0`:

```text
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C); /*0x553c5c*/
```

Disassembly confirms:

```text
0x00553c3f: push offset off_622F1C
0x00553c44: push offset off_622F28
0x00553c49: push dword_67A740
0x00553c4f: push 9Ah
0x00553c54: call sub_4F0350
0x00553c5c: call sub_49FEB0
```

`sub_553CC0` is the alternate constructor path:

```text
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C); /*0x553d09*/
```

`sub_554210` uses the same pair when constructing a replacement connection-closed dialog from the reconnect button path:

```text
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C); /*0x554376*/
```

`sub_58B470` builds the TerminalPane reconnect/leave callback prompt:

```text
v10[2] = sub_58B620; /*0x58b56d*/
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/
```

`sub_58B620` is the callback installed by that prompt. Its nonzero branch calls `sub_5975E0`; its zero branch calls `sub_464E40`.

`sub_4A0690` rejects `AlertPanes` ownership for this literal because it only forwards caller-provided labels into the alert core:

```text
sub_49FEB0(a2, a3, a5, a6); /*0x4a06a6*/
this[156] = a4;             /*0x4a06ae*/
```

The wrapper receives the `Leave`/`Reconnect` pointers from `TerminalPane::OnDisconnect`; it does not load `0x00622f1c` itself.

## PE / Raw Evidence

Raw file inspected:

```text
file: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
sha256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
image_base: 0x00400000
.rdata VA: 0x0060d000
.rdata raw: 0x0020ba00
target VA: 0x00622f1c
target raw: 0x0022191c
```

Raw decoded region:

```text
0x00622f1c-0x00622f28: UTF-16LE "Leave"
0x00622f28-0x00622f3c: UTF-16LE "Reconnect"
0x00622f3c-0x00622f44: UTF-16LE "No"
0x00622f44-0x00622f4c: UTF-16LE "Yes"
0x00622f4c-0x00622f54: ASCII "baram"
0x00622f58: successor Region vtable area
```

Whole-file raw search results:

| Pattern | Count | Hits |
| --- | ---: | --- |
| UTF-16LE `Leave\0` | 1 | VA `0x00622f1c` |
| UTF-16LE `Leave` body | 1 | VA `0x00622f1c` |
| ASCII `Leave\0` | 0 | none |
| absolute VA `0x00622f1c` | 4 | operand bytes at VAs `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad` |
| `push 0x00622f1c` | 4 | instruction starts `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| target RVA `0x00222f1c` | 0 | none |
| absolute VA `0x00622f20` | 0 | none |
| absolute VA `0x00622f22` | 0 | none |
| absolute VA `0x00622f24` | 0 | none |
| absolute VA `0x00622f26` | 0 | none |
| absolute VA `0x00622f28` | 4 | sibling `Reconnect` operand bytes at `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| `push 0x00622f28` | 4 | sibling `Reconnect` instruction starts `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| absolute VA `0x00622f54` | 0 | none |
| absolute VA `0x00622f58` | 1 | successor vtable operand at `0x005546c3` |

The raw evidence independently confirms the live IDA xref set and rejects hidden references, an interior split, a pointer-table owner, a target RVA route, an ASCII duplicate, or a merge into successor data.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed string-tail map | `FALSE` | `NONE` | `89/93` | Keep as non-emitting container |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `SharedLeaveWideString` | Shared `Leave` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Current target; keep unchanged |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `SharedReconnectWideString` | Paired shared `Reconnect` label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Same source-use route |
| `0x00622f3c-0x00622f44` | [UID:0003G5] `CopyWindowNoButtonWideString` | CopyWindow `No` label | `TRUE` | [UID:000039] `CopyWindow` | current docs | Separate successor |
| `0x00622f44-0x00622f4c` | [UID:0003G6] `CopyWindowYesButtonWideString` | CopyWindow `Yes` label | `TRUE` | [UID:000039] `CopyWindow` | current docs | Separate successor |
| `0x00622f4c-0x00622f54` | [UID:0003G7] `SharedBaramPacketLiteral` | Shared `baram` packet literal | `TRUE` | `NONE`; emitters `0000N0,0000OI` | current docs | Separate shared sibling |
| `0x00553c10-0x00553cbf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` | Constructor variant using label pair | `TRUE` | [UID:0000N0] source route | `82/86`; file `87/88` | Reconnect emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J] `ConnectionClosedDialogMethods` | Alternate constructor/handlers | `TRUE` | [UID:000036], file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L] `ReconnectDialogMethods` | Reconnect constructors/handlers | `TRUE` | [UID:0000BR], file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB] `TerminalPaneAndSetup` | Terminal pane/setup aggregate | `TRUE` | [UID:0000OI] | `85/86`; file `87/85` | Terminal emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Callback installed by TerminalPane prompt | `TRUE` | [UID:0000OI] | `85/91` | Confirms TerminalPane route |
| `0x0049feb0-0x004a0686` | [UID:00012W] `AlertPaneCore` | Reusable alert infrastructure | `TRUE` | [UID:00000B], file [UID:0000HE] | `82/90`; file `85/88` | Rejected as label owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `push offset off_622F1C` in `sub_553C10` | Connection-closed constructor passes `Leave` |
| `0x00553c44` | `push offset off_622F28` in `sub_553C10` | paired `Reconnect` |
| `0x00553cef` | `push offset off_622F1C` in `sub_553CC0` | alternate connection-closed constructor passes `Leave` |
| `0x00553cf4` | `push offset off_622F28` in `sub_553CC0` | paired `Reconnect` |
| `0x00554359` | `push offset off_622F1C` in `sub_554210` | reconnect path constructs replacement connection-closed alert |
| `0x0055435e` | `push offset off_622F28` in `sub_554210` | paired `Reconnect` |
| `0x0058b5ac` | `push offset off_622F1C` in `sub_58B470` | TerminalPane disconnect prompt passes `Leave` |
| `0x0058b5b1` | `push offset off_622F28` in `sub_58B470` | paired `Reconnect` |
| `0x004a0690` | `sub_4A0690(..., a5, a6)` calls `sub_49FEB0(a2, a3, a5, a6)` | alert wrapper forwards caller labels; not a label owner |
| `0x0049feb0` | `sub_49FEB0` | shared alert constructor consumes caller-provided labels |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page records the exact bytes, four source-use xrefs, false interior `aAve` artifact, current `CANONICAL_OWNER:NONE`, current emitters, and blank C++.
- [UID:0003CW] `ReconnectTerminalCopyStringTailMap` correctly models the physical island as a non-emitting mixed-owner map over exact children.
- [UID:0003G4] `SharedReconnectWideString` is the paired sibling with the same four source-use sites and same `0000N0,0000OI` emitter route.
- [UID:0000N0] `ReconnectDialog` is a valid by-file source root at `87/88`, path `NexusTK/network/`, and documents the `ConnectionClosedDialog` and `ReconnectDialog` families.
- [UID:0000OI] `TerminalPane` is a valid by-file source root at `87/85`, path `NexusTK/login/`, and documents `TerminalPane::OnDisconnect` and the reconnect/leave callback.
- [UID:0001JD] `TerminalPaneReconnectLeaveCallback` records the `TerminalPane::OnDisconnect` prompt construction that uses the shared `Leave`/`Reconnect` label pair.
- [UID:0000HE] `AlertPanes` and [UID:00012W] `AlertPaneCore` support rejecting alert-infrastructure ownership: the alert constructors are reusable consumers of caller-provided labels, while feature-specific alert text stays with feature modules or use sites.

Existing docs that are stale, incomplete, or contradicted:

- No target-page repair is required. IDA's `off_622F1C` and `aAve` modeling is imperfect, but the target page already explains the false pointer/interior-string artifact, and current IDA/PE evidence confirms that explanation.
- Generated source files for the emitter roots currently exist as output routes; their current source content is not evidence for a standalone declaration on this page.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists the item as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`, with destination display `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- Its emitter table lists [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane`.
- Its no-owner table lists `0000N0`,`0000OI`.
- `auto-generated/-ag-file-coverage.md` maps `0000N0` to `auto-generated/NexusTK/network/ReconnectDialog.cpp` and `0000OI` to `auto-generated/NexusTK/login/TerminalPane.cpp`.
- `by-memory/-coverage-report.md` already documents the no-owner/two-emitter state and rejected canonical owners.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` - accepted

Evidence for:

- This matches current by-structure guidance for pooled/shared literals with no proven single declaration owner.
- Live IDA xrefs prove direct source-use routes in ReconnectDialog-family code and TerminalPane code.
- Raw PE scan confirms one exact UTF-16LE `Leave` spelling, four target absolute/push references, no target RVA references, and no hidden interior refs.
- Both emitter roots are by-file source roots with valid reconstruction paths.
- The paired `Reconnect` sibling has the same four-site route and same two-emitter model.

Evidence against:

- The stripped binary cannot prove whether the original source used repeated local literals, a macro, or a shared constant declaration.

Decision: accepted. The uncertainty blocks canonical ownership but does not block emitter routing because every source-use xref is exact.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner - rejected

Evidence for:

- Three of four direct references are in `ConnectionClosedDialog` / `ReconnectDialog` code.
- The label is semantically central to the connection-loss/reconnect UI.
- The source file owns the connection-closed and reconnect dialog class families.

Evidence against:

- `TerminalPane::OnDisconnect` directly references the same physical label at `0x0058b5ac`.
- No IDA evidence shows TerminalPane delegates the label declaration to `ReconnectDialog`.
- Assigning the largest consumer would violate the pooled-literal rule when another independent source root materially uses the same literal.

Decision: reject as canonical owner; keep as emitter `0000N0`.

### 3. [UID:0000OI] `TerminalPane` as canonical owner - rejected

Evidence for:

- TerminalPane has one direct, material source-use site at `0x0058b5ac`.
- The callback child confirms TerminalPane owns the reconnect/leave decision path consuming the label pair.

Evidence against:

- Three direct refs are outside TerminalPane in reconnect/connection-closed code.
- TerminalPane is a real consumer, not a declaration owner for the reconnect dialog call sites.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### 4. [UID:0000HE] `AlertPanes` / alert infrastructure - rejected

Evidence for:

- All uses eventually flow into alert construction infrastructure.
- `AlertPanes` is a valid shared alert source root.

Evidence against:

- The `Leave` label is caller-supplied feature text, not a generic alert-library literal.
- `sub_4A0690` forwards caller labels to `sub_49FEB0`; it does not reference `0x00622f1c`.
- `AlertPanes.md` explicitly keeps feature-specific reconnect alerts with [UID:0000N0] when feature-coupled.

Decision: reject as owner and emitter for this literal.

### 5. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG] - rejected

Evidence for:

- `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` each own method bodies that use or surround the label.

Evidence against:

- No single class covers all four direct refs.
- The reconnect-side refs span two classes in one source file, and TerminalPane is separate.
- The item is pooled source string data, not class-static storage, a vtable, a member, or a class-specific resource table.

Decision: reject for canonical ownership and do not switch to class-level emitters.

### 6. Physical container [UID:0003CW] or broader [UID:000269] - rejected

Evidence for:

- The target is physically inside those `.rdata` maps.

Evidence against:

- The maps are non-emitting mixed-owner inventory containers.
- Neighboring exact children have different source routes: `No`/`Yes` are CopyWindow-only; `baram` is a separate shared packet literal.
- Address adjacency is weak ownership evidence for pooled strings.

Decision: reject as source owner.

### 7. New shared label/source owner - rejected

Evidence for:

- `Leave` and `Reconnect` are paired at all four prompt sites.
- A shared header macro or named constant is possible in original source.

Evidence against:

- No table, initializer, source/debug name, address-taken global declaration, symbol, or coherent constants module is visible.
- Ordinary string-literal pooling fully explains one physical address used from independent source contexts.
- Current structure rules warn against inventing a standalone owner solely to avoid `NONE`.

Decision: reject. No new file/grouping is recommended.

## Negative Evidence Summary

- No xrefs to false interior `0x00622f20` / `aAve`.
- No raw immediate refs to interior `0x00622f20`, `0x00622f22`, `0x00622f24`, or `0x00622f26`.
- No ASCII `Leave` spelling.
- No target RVA-form references.
- No hidden absolute-VA/push references beyond the four known source-use sites.
- No refs to `0x00622f54`, the end of the mixed string-tail map.
- The next referenced object is the successor Region vtable area at `0x00622f58`, not part of this range.
- No source/debug metadata or source-file string proves a shared declaration owner.
- No alert-infrastructure ownership: alert constructors receive caller-provided labels.
- No one class or file covers all direct xrefs as a semantic declaration owner.
- Address adjacency in the mixed string tail does not prove source ownership.

## Final Recommendation

Exact changes applied or recommended:

- No by-* documentation changes.
- No score changes.
- No split, merge, reclassification, rename, or IDA repair.
- No `by-memory/-coverage-report.md` edit.

Exact metadata to retain:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Retain the current generated memory row:

```markdown
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` |  |
```

Retain the current generated emitter-table row:

```markdown
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |  | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

Retain the current generated no-owner table row:

```markdown
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | no-owner | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | `0000N0`,`0000OI` | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

No `by-memory/-coverage-report.md` replacement is required. If the supervisor wants an explicit retained row, keep the current row:

```markdown
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; B003 post-migration and B001 second-pass reviews confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, no target RVA refs, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

Exact items left no-owner/non-emitting and why:

- [UID:0003G3] remains no-owner but emitting because it is a compiler/linker-pooled literal with proven independent source-use routes and no proven single declaration owner.
- No item in this assignment remains non-emitting; the current target has nonblank valid emitters.

Exact future work outside this assignment scope:

- Revisit only if future PDB/map/source evidence proves a real shared label declaration or constants source file.

## C++ Entry Gate

Minimum numeric/routing gate:

- `RECONSTRUCTABLE:TRUE`: yes.
- Confirmed nonblank emitters: yes, `0000N0,0000OI`.
- Valid emitter chains: yes; both emitters are by-file roots with valid reconstruction paths.
- Combined score: `(89 + 94) / 2 = 91.5`, greater than `85`.

Final source-placement decision: do not enter or recommend standalone `RECONSTRUCTION_CPP` for this by-memory page. The minimum numeric/emitter gate is satisfied, but the source placement is not: this item is a pooled string literal whose correct final source representation is local `L"Leave"` use inside reconstructed consumer functions. A standalone source block here would invent a declaration owner not supported by the evidence. Keep the C++ block blank.

## Follow-Up Actions

- Supervisor actions: mark this fresh B003 recheck complete if accepted. No by-memory or generated coverage edit is required.
- A-agent actions: none for this target.
- B003 future research actions: none for `0003G3` unless new external source/debug evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `89/94`.
- Remaining uncertainty: the stripped binary cannot distinguish repeated local literals from a macro or shared constant. That uncertainty is exactly why `CANONICAL_OWNER:NONE` remains correct; it does not weaken the emitter routes because the source-use sites are exact.

## Validator Results

- Commands run: none.
- Results: not applicable; no by-* documentation files or shared reports were edited.
- Dry runs: none used.
- Unresolved validator warnings/errors: none from this report-only assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003G3-SharedLeaveWideString-fresh-no-owner-pass.md`.
- Modified: none outside the Agent-B003 research folder.
- Renamed: none.
- Moved to executed: none.
- Leases: no leases used or required. The shared lease report showed no active leases, and the only edited file is inside Agent-B003's own research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B003/0003G3-SharedLeaveWideString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
