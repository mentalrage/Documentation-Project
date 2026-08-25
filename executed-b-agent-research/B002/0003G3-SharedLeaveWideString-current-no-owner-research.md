** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Required action: no canonical-owner assignment, emitter repair, split, merge, reclassification, IDA-safe-name repair, score change, target-page edit, or coverage-row replacement is recommended.
- Confidence: high. Current IDA MCP and raw PE evidence prove one exact UTF-16LE `Leave` literal, exactly four direct source-use refs split across reconnect/connection-closed code and `TerminalPane::OnDisconnect`, no interior/RVA/ASCII hidden refs, and no single defensible declaration owner.

This is a valid no-owner-with-emitters pooled-literal case, not a non-emitting defect. Final project source should spell `L"Leave"` at the semantic consumer call sites when those methods are reconstructed, but the pooled `.rdata` cell should not be assigned to one canonical owner or emitted as a standalone global.

## Supporting Research

## Target

- Target UID: `0003G3`.
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, current active 2026-06-14 no-owner memory sweep row for Agent-B002.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B001/research/executed/0003G3-SharedLeaveWideString-current-no-owner-sweep.md`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists this target as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`.
- Current scores and metadata: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`.

## Executive Recommendation

Keep the target as an exact source-authored UTF-16LE `Leave` button-label literal with no canonical owner and two emitter routes.

The current evidence proves the same physical literal is used by:

| Source-use family | Xrefs | Emitter route |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor variants | `0x00553c3f`, `0x00553cef` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| `TerminalPane::OnDisconnect` callback alert path | `0x0058b5ac` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) |

Do not assign [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md), class-level pages, the physical string-tail map, or a new shared-label file as canonical owner. Each would overclaim a compiler/linker-pooled literal whose exact source-use contexts cross source roots.

## Supervisor Active Recheck

- Trigger: current Goal 2 B-agent assignment for [UID:0003G3].
- Split repair required: no. The range is already an exact `0x0c`-byte UTF-16LE `Leave` child.
- Emitter repair required: no. Both current emitters are still proven by live xrefs, function behavior, source-root docs, and valid by-file paths.
- Canonical owner repair required: no. The correct current state remains `CANONICAL_OWNER:NONE`.
- Coverage-report edit required: no. The current `by-memory/-coverage-report.md` row is accurate and should be retained.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from generated-output routing. It explicitly allows compiler/linker-pooled string literals to remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for every proven source-use route. That rule directly applies because the binary has one physical `Leave` cell referenced from two independent source-file roots.

`inference_research.md` warns that `.rdata` adjacency and pooled strings are weak source-file evidence. I treated the containing string island and neighboring `Reconnect`, `No`, `Yes`, and `baram` literals as boundary/context evidence only. The owner/emitter recommendation is based on exact bytes, direct xrefs, containing functions, decompiler snippets, source-root docs, and negative evidence.

Existing documentation and prior reports were used as leads, not authority. The current conclusion was rechecked against live IDA MCP evidence on 2026-06-14.

## Evidence Standards Used

- IDA MCP tools against live session `b001_0002bd`: `server_health`, `get_bytes`, `get_string`, `make_signature_for_range`, `xrefs_to`, `find_bytes`, `find`, `lookup_funcs`, `entity_query`, `trace_data_flow`, `find_regex`, `decompile`, `disasm`, and `analyze_component`.
- Raw PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, raw byte read, exact byte-pattern search, absolute-VA push search, interior-address negative searches, boundary negative search, and RVA negative search.
- Documentation evidence: target page, current generated coverage rows, `by-memory/-coverage-report.md`, parent/sibling string pages, ReconnectDialog/ConnectionClosedDialog/TerminalPane/AlertPanes file and class pages, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Generated-source surface check: `ReconnectDialog.cpp`, `TerminalPane.cpp`, and `AlertPanes.cpp` exist under `auto-generated/NexusTK`, but are currently zero-length placeholders; searches for `SharedLeaveWideString`, `0x00622f1c`, and `L"Leave"` under generated source returned no hits.

## IDA MCP Facts

IDA MCP state:

```text
database: b001_0002bd
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
imagebase: 0x400000
auto-analysis: ready
Hex-Rays: ready
strings cache: ready, 2067 strings
```

### Bytes And Decoding

`get_bytes` over `0x00622f1c-0x00622f54` returned:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

This decodes as UTF-16LE `Leave`, UTF-16LE `Reconnect`, UTF-16LE `No` plus padding, UTF-16LE `Yes`, and ANSI `baram`. The target signature `0x00622f1c-0x00622f28` is unique:

```text
4C 00 65 00 61 00 76 00 65 00 00 00
```

IDA string/name decoding remains offset-biased:

| Address | IDA value/name | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | `L` / `off_622F1C` | false pointer/partial decode at target start |
| `0x00622f20` | `ave` / `aAve` | false interior suffix, zero xrefs |
| `0x00622f28` | `R` / `off_622F28` | paired `Reconnect` sibling start |
| `0x00622f2c` | `connect` / `aConnect` | false interior suffix of `Reconnect` |
| `0x00622f3c` | `No` / `aNo` | real successor child |
| `0x00622f44` | `Y` | `Yes` successor start |
| `0x00622f4c` | `baram` / `aBaram_0` | real ANSI successor child |

`entity_query strings` in the island lists only `baram`, confirming IDA's string-cache limitation here and not contradicting the byte-level UTF-16 decoding.

### Xrefs

`xrefs_to(0x00622f1c)` returns exactly four xrefs:

| Xref | IDA function | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10`, size `0xaf` | `ConnectionClosedDialog` constructor variant use |
| `0x00553cef` | `sub_553CC0`, size `0xae` | alternate `ConnectionClosedDialog` constructor use |
| `0x00554359` | `sub_554210`, size `0x1f6` | `ReconnectDialog::OnButtonClick` replacement alert use |
| `0x0058b5ac` | `sub_58B470`, size `0x170` | `TerminalPane::OnDisconnect` reconnect/leave prompt use |

The paired `Reconnect` sibling at `0x00622f28` has matching xrefs at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.

Negative xrefs:

| Address | Result |
| --- | --- |
| `0x00622f20` | zero xrefs |
| `0x00622f22` | zero xrefs |
| `0x00622f24` | zero xrefs |
| `0x00622f26` | zero xrefs |
| `0x00622f54` | zero xrefs to the target/successor boundary |

### Binary Pattern And Immediate Searches

IDA `find_bytes` and `find` results:

| Pattern / query | Count | Hits |
| --- | ---:| --- |
| UTF-16LE `Leave\0` bytes `4C 00 65 00 61 00 76 00 65 00 00 00` | 1 | `0x00622f1c` |
| UTF-16LE `Leave` without terminator | 1 | `0x00622f1c` |
| ASCII `Leave\0` | 0 | none |
| `push 0x00622f1c` bytes `68 1C 2F 62 00` | 4 | `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| VA dword `0x00622f1c` bytes `1C 2F 62 00` | 4 | embedded in the same four push sites |
| interior dwords `0x00622f20`, `0x00622f22`, `0x00622f24`, `0x00622f26` | 0 | none |
| `push 0x00622f28` bytes `68 28 2F 62 00` | 4 | paired `Reconnect` pushes |
| boundary dword `0x00622f54` | 0 | none |
| target RVA dword `0x00222f1c` | 0 | none |

`trace_data_flow(0x00622f1c, backward, max_depth=2)` reaches the same four code sites and the preceding `dword_67A750` text-source loads. It does not reveal a table owner or hidden declaration.

`find_regex('\.pdb|RSDS|NB10|\.cpp|\.cxx|\.h')` over IDA strings returned zero matches, so no source/debug breadcrumb proves a declaration owner or shared-label source file.

### Decompiler And Call-Flow Evidence

Filtered decompiler snippets:

```text
0x00553c10:
v2 = sub_4F0350(154);                         /*0x553c54*/
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C); /*0x553c5c*/

0x00553cc0:
v3 = sub_4F0350(154);                         /*0x553d01*/
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C); /*0x553d09*/

0x00554210:
v8 = sub_4F0350(154);                         /*0x55436e*/
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C);/*0x554376*/

0x0058b470:
v10[2] = sub_58B620;                          /*0x58b56d*/
v11 = sub_4F0350(157);                        /*0x58b5bd*/
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/

0x004a0690:
sub_49FEB0(a2, a3, a5, a6);                   /*0x4a06a6*/
```

Inference from these facts:

- The reconnect/connection-closed functions supply the `Reconnect`/`Leave` label pair directly to alert construction.
- `TerminalPane::OnDisconnect` supplies the same label pair to the callback-backed `VersatileAlertPane` path, which forwards caller labels to the same alert initializer.
- `AlertPanes` owns reusable alert constructors, not the feature-specific label literals.

`analyze_component` over `0x00553c10`, `0x00553cc0`, `0x00554210`, `0x0058b470`, `0x004a0690`, and `0x0049feb0` reports `off_622F1C` and `off_622F28` as shared globals accessed by `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`. The internal call graph has `sub_553C10`, `sub_553CC0`, and `sub_554210` calling `sub_49FEB0`; `sub_58B470` calling `sub_4A0690`; and `sub_4A0690` calling `sub_49FEB0`.

## Raw PE Evidence

Raw file inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

```text
imagebase: 0x400000
target VA: 0x00622f1c
target RVA: 0x222f1c
section: .rdata, VA 0x20d000, raw pointer 0x20ba00
raw offset: 0x22191c
target bytes: 4c 00 65 00 61 00 76 00 65 00 00 00 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00 ...
```

Whole-file raw search:

| Pattern | Count | Raw hits |
| --- | ---:| --- |
| UTF-16LE `Leave\0` | 1 | `0x22191c` |
| UTF-16LE `Leave` without terminator | 1 | `0x22191c` |
| ASCII `Leave\0` | 0 | none |
| `push 0x00622f1c` | 4 | `0x15303f`, `0x1530ef`, `0x153759`, `0x18a9ac` |
| embedded absolute `0x00622f1c` | 4 | same operands |
| interior absolute `0x00622f20`, `0x00622f22`, `0x00622f24`, `0x00622f26` | 0 | none |
| `push 0x00622f28` | 4 | `0x153044`, `0x1530f4`, `0x15375e`, `0x18a9b1` |
| boundary absolute `0x00622f54` | 0 | none |
| target RVA `0x00222f1c` | 0 | none |

This independently confirms the IDA xref set and rejects an interior split, hidden pointer-table owner, RVA-form reference, ASCII duplicate, or merge with the sibling/boundary data.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Mixed string-tail map | `FALSE` | `NONE` | `89/93` | Keep as non-emitting container |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | Shared `Leave` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Current target; keep unchanged |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | Paired shared `Reconnect` label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Same source-use route |
| `0x00622f3c-0x00622f44` | [UID:0003G5][CopyWindowNoButtonWideString](../../../../../by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | CopyWindow `No` label | `TRUE` | [UID:000039][CopyWindow](../../../../../by-class/CopyWindow.md) | `86/91` | Separate successor |
| `0x00622f44-0x00622f4c` | [UID:0003G6][CopyWindowYesButtonWideString](../../../../../by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | CopyWindow `Yes` label | `TRUE` | [UID:000039][CopyWindow](../../../../../by-class/CopyWindow.md) | `86/91` | Separate successor |
| `0x00622f4c-0x00622f54` | [UID:0003G7][SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | Shared ANSI packet literal | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Related shared sibling |
| `0x00553c10-0x00553cbf` | [UID:00023O][ConnectionClosedDialogConstructorVariant](../../../../../by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | Constructor using label pair | `TRUE` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) | `82/86`; file `87/88` | Reconnect emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J][ConnectionClosedDialogMethods](../../../../../by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Alternate constructor/handlers | `TRUE` | [UID:000036][ConnectionClosedDialog](../../../../../by-class/ConnectionClosedDialog.md), file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Reconnect constructors/handlers | `TRUE` | [UID:0000BR][ReconnectDialog](../../../../../by-class/ReconnectDialog.md), file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB][TerminalPaneAndSetup](../../../../../by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) | Terminal pane/setup aggregate | `TRUE` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) | `85/86`; file `87/85` | Terminal emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) | Callback installed by TerminalPane prompt | `TRUE` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) | `85/91` | Confirms TerminalPane route |
| `0x0049feb0-0x004a0686` | [UID:00012W][AlertPaneCore](../../../../../by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md) | Reusable alert infrastructure | `TRUE` | [UID:00000B][AlertPane](../../../../../by-class/AlertPane.md), file [UID:0000HE] | `82/90`; file `85/88` | Rejected as label owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10`, `push offset off_622F1C` | reconnect/connection-closed constructor passes `Leave` to alert initializer |
| `0x00553c44` | `sub_553C10`, `push offset off_622F28` | paired `Reconnect` label at same call site |
| `0x00553cef` | `sub_553CC0`, `push offset off_622F1C` | alternate connection-closed constructor passes `Leave` |
| `0x00553cf4` | `sub_553CC0`, `push offset off_622F28` | paired `Reconnect` label |
| `0x00554359` | `sub_554210`, `push offset off_622F1C` | reconnect button/timeout path constructs replacement connection-closed alert |
| `0x0055435e` | `sub_554210`, `push offset off_622F28` | paired `Reconnect` label |
| `0x0058b5ac` | `sub_58B470`, `push offset off_622F1C` | TerminalPane disconnect prompt passes `Leave` |
| `0x0058b5b1` | `sub_58B470`, `push offset off_622F28` | paired `Reconnect` label |
| `0x004a0690` | `sub_4A0690(a2, a3, callback, primary, secondary)` | alert wrapper forwards caller labels; does not own them |
| `0x0049feb0` | `sub_49FEB0` | alert constructor consumes caller-provided labels broadly; does not declare this feature text |

## Documentation Evidence And IDA Status

- Target page supports the conclusion: it records exact bytes, four source-use xrefs, false `aAve` artifact, no canonical owner, and `EMITTER_UIDS:0000N0,0000OI`. Current IDA checks confirm those core facts.
- [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) supports the reconnect emitter route. It is a valid source-file root at `87/88` with path `NexusTK/network/`, and it owns the `ConnectionClosedDialog` / `ReconnectDialog` source family.
- [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) supports the terminal emitter route. It is a valid source-file root at `87/85` with path `NexusTK/login/`, and it owns `TerminalPane::OnDisconnect` plus the reconnect/leave callback.
- [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md) supports rejecting alert infrastructure as owner. It owns reusable alert classes and the proposed source tree keeps feature-specific alert subclasses with feature modules unless later evidence proves a common alert-helper source.
- [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) is a paired sibling with the same four-site route and the same no-owner/two-emitter decision.
- [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) correctly remains a non-emitting mixed string-tail container because exact children carry different source routes.
- `by-project-structure/proposed-source-tree.md` places `ReconnectDialog.cpp` under `network/`, `TerminalPane.cpp` under `login/`, and `AlertPanes.cpp` under `ui/dialogs/`.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0003G3] as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`, destination display `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- The generated emitter table lists both [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md).
- `by-memory/-coverage-report.md` already documents `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, the four source-use refs, and rejected canonical owners.

No stale documentation requiring direct repair was found for this target.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` - accepted

Evidence for:

- This matches the current by-structure rule for pooled/shared literals with no proven single declaration owner.
- Live IDA xrefs prove three reconnect/connection-closed source-use sites and one TerminalPane source-use site.
- IDA and raw PE byte-pattern searches prove exactly one UTF-16 `Leave` spelling and exactly four `push 0x00622f1c` references.
- Both emitter roots clear the source-route gate and have valid reconstruction paths: [UID:0000N0] is `87/88`, `NexusTK/network/`; [UID:0000OI] is `87/85`, `NexusTK/login/`.
- The paired `Reconnect` sibling has the same use-site shape and same accepted route.

Evidence against:

- The stripped binary cannot prove whether the original source used repeated local literals, a macro, or a small shared constant.

Decision: accepted. The uncertainty blocks canonical ownership; it does not block emitter routing because every source-use xref is exact.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner - rejected

Evidence for:

- Three of four direct refs are in `ConnectionClosedDialog` and `ReconnectDialog` code.
- The label is semantically central to connection-loss and reconnect UI.
- The source file owns both classes and related reconnect singleton state.

Evidence against:

- `TerminalPane::OnDisconnect` directly uses the same physical literal at `0x0058b5ac`.
- No IDA evidence shows TerminalPane delegates the label declaration to `ReconnectDialog`.
- Assigning the majority consumer would violate the pooled-literal rule when another independent source root materially uses the same literal.

Decision: reject as canonical owner; keep as emitter `0000N0`.

### 3. [UID:0000OI] `TerminalPane` as canonical owner - rejected

Evidence for:

- `TerminalPane::OnDisconnect` has a direct, material xref at `0x0058b5ac`.
- The callback child [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) confirms TerminalPane owns the reconnect/leave decision path that consumes the label pair.

Evidence against:

- Three direct refs are outside TerminalPane in reconnect/connection-closed code.
- TerminalPane is one real source-use context, not a declaration owner for the reconnect dialog call sites.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### 4. [UID:0000HE] `AlertPanes` / alert infrastructure - rejected

Evidence for:

- All use sites eventually call `AlertPane`/`VersatileAlertPane` constructors.
- `AlertPanes` is a valid shared alert source root.

Evidence against:

- `Leave` is caller-supplied feature text, not a generic alert-library literal.
- `sub_4A0690` forwards caller labels into `sub_49FEB0`; it does not reference `0x00622f1c` itself.
- Alert infrastructure has broad fan-in and should not own every caller-provided button label.

Decision: reject as owner and emitter for this literal.

### 5. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG] - rejected

Evidence for:

- Each class owns at least one method body that uses or surrounds the literal.

Evidence against:

- No single class covers all four refs.
- The reconnect-side refs span two classes in one source file, and the TerminalPane ref is a separate class/source root.
- The literal is pooled source string data, not a vtable, field, or class-static object tied to one class declaration.

Decision: reject for canonical ownership and do not use class-level emitters for this no-owner pooled literal.

### 6. Physical container [UID:0003CW] or aggregate [UID:000269] - rejected

Evidence for:

- The target is physically inside those `.rdata` maps.

Evidence against:

- The maps are mixed-owner/non-emitting inventory containers.
- Neighboring children have different routes: `No`/`Yes` are CopyWindow, while `Leave`/`Reconnect` are reconnect/terminal shared, and `baram` is a separate shared packet literal.
- Address adjacency is weak evidence for pooled strings.

Decision: reject as source owner.

### 7. New shared label/source owner - rejected

Evidence for:

- `Leave` and `Reconnect` are paired at all four prompt sites.
- A shared header macro or constant is possible in original source.

Evidence against:

- No table, initializer, source/debug name, local-static object, or coherent constants module is visible.
- Ordinary string-literal pooling fully explains one physical address used by independent source contexts.
- by-structure guidance warns not to invent a standalone owner solely to avoid `NONE`.

Decision: reject. No new source file/grouping is recommended.

### 8. Split, merge, or reclassify - rejected

Evidence for:

- None.

Evidence against:

- The range is already exactly one UTF-16LE literal plus terminator.
- Interior starts `0x00622f20`, `0x00622f22`, `0x00622f24`, and `0x00622f26` have zero IDA xrefs and zero immediate hits.
- The end `0x00622f28` is already the paired `Reconnect` sibling, not part of the `Leave` child.
- The item is source-authored UI text with proven source-use routes, so it remains reconstructable.

Decision: no split, merge, or reclassification.

## Negative Evidence Summary

- No refs to false interior `0x00622f20` / `aAve`.
- No refs or raw immediates to interior starts `0x00622f22`, `0x00622f24`, or `0x00622f26`.
- No ASCII `Leave` spelling.
- No target RVA-form references.
- No hidden absolute-VA/push references beyond the four known source-use sites.
- No xrefs to `0x00622f54` successor boundary.
- No source/debug metadata or name proves a shared declaration owner.
- No AlertPanes ownership: alert constructors receive labels from feature callers.
- No single class or file covers all direct xrefs as a semantic declaration owner.
- Address adjacency in the mixed string island does not prove source ownership.

## Code-Entry Gate

The metadata clears the minimum numeric/routing gate: `RECONSTRUCTABLE:TRUE`, nonblank emitters, valid emitter chains to by-file roots, and `(89 + 94) / 2 = 91.5`. Even so, no final C++ should be entered on this by-memory page during this pass. The page represents a compiler/linker-pooled literal, and the correct source form is the literal expression at each consumer call site. A standalone declaration on this page would overstate a source owner and duplicate data outside the actual method-range pages. The generated source files for the two routes are also currently zero-length placeholders, so the consumer methods are not ready for final source insertion here.

## Final Recommendation

- Exact changes applied or recommended: no by-* changes are needed. This B002 research report is the only created file.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: keep `EMITTER_UIDS:0000N0,0000OI`.
- Exact items left no-owner/non-emitting and why: [UID:0003G3] remains no-owner but emitting because it is a compiler/linker-pooled literal with proven independent source-use routes and no proven single declaration owner.
- Exact future work outside this assignment scope: revisit only if future source/debug/PDB/map evidence proves a real shared label declaration or constants source file.

Retain target metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Retain the current `auto-generated/-ag-memory-coverage.md` memory row:

```text
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` |  |
```

Retain the current generated emitter-table row:

```text
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |  | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

Retain the current no-owner list row:

```text
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | no-owner | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | `0000N0`,`0000OI` | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

Retain the current `by-memory/-coverage-report.md` row; no replacement is required:

```text
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; B003 post-migration and B001 second-pass reviews confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, no target RVA refs, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

Suggested tracker close-out row for supervisor application, if desired:

```text
| `0003G3` | 0x00622f1c-0x00622f28.SharedLeaveWideString | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003G3-SharedLeaveWideString-current-no-owner-research.md` | `Agent-B001/research/executed/0003G3-SharedLeaveWideString-current-no-owner-sweep.md` |
```

## Follow-Up Actions

- Supervisor actions: no by-memory or coverage-report edit required. Optional tracker close-out row is provided above.
- A-agent actions: none required for this target.
- B002 future research actions: none for this target unless new debug/source evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `89/94`.
- Remaining uncertainty: stripped binary evidence cannot distinguish repeated local literals from a macro or shared constant. That uncertainty is exactly why `CANONICAL_OWNER:NONE` remains correct. It does not weaken the emitter route because every source-use xref is exact and current.

## Validator Results

- Validator not run. No by-* files, generated files, project-level files, or coverage reports were edited.
- No dry runs were used.
- Report-only verification performed after writing: required sections, ASCII-only text, expected metadata/coverage text, and relative link targets.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003G3-SharedLeaveWideString-current-no-owner-research.md`.
- Modified: none outside Agent-B002 research.
- Renamed: none.
- Moved to executed: none.
- Leases: none needed; per `goal.md`, own-agent research reports do not require leases.

## Blockers

None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B002/0003G3-SharedLeaveWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
