** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.
- Required action: no canonical-owner assignment, emitter repair, split, merge, reclassification, IDA-safe name repair, score change, by-* target edit, generated-report edit, or `by-memory/-coverage-report.md` edit is recommended.
- Confidence: high. Current IDA MCP and raw PE evidence prove exactly one physical UTF-16LE `Leave` spelling at `0x00622f1c`, exactly four source-use refs split across ReconnectDialog-family code and `TerminalPane::OnDisconnect`, no interior or RVA references, and no defensible single declaration owner.

This is a valid no-owner-with-emitters pooled-literal case, not a non-emitting defect. Final source should spell `L"Leave"` at the semantic consumer call sites when those consumer methods are reconstructed; this data page should not become a standalone global/string declaration.

## Supporting Research

## Target

- Target UID: `0003G3`
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- Source queue/report row: current Goal 2 no-owner ownership/emitter research assignment from generated memory coverage.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists this target as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank C++.
- Prior reports reviewed only as historical context: B001/B002/B003 executed reports for `0003G3`, including `Agent-B002/research/executed/0003G3-SharedLeaveWideString-current-no-owner-research.md` and `Agent-B001/research/executed/0003G3-SharedLeaveWideString-second-pass.md`.

## Executive Recommendation

Keep the target as an exact source-authored UTF-16LE `Leave` button-label literal with no canonical owner and two proven emitter routes:

| Source-use family | Direct xrefs | Emitter route |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor variants | `0x00553c3f`, `0x00553cef` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| `TerminalPane::OnDisconnect` reconnect/leave prompt | `0x0058b5ac` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) |

Do not assign [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md), class-level pages, the physical string-tail map, or a new shared-label file as canonical owner. Each would overclaim a compiler/linker-pooled literal whose observed use crosses independent source roots.

## Supervisor Active Recheck

- Trigger: fresh B003 current-state recheck for [UID:0003G3].
- Split repair required: no. The range is already an exact `0x0c`-byte UTF-16LE `Leave` child inside a non-emitting mixed string-tail map.
- Every source-bearing child in scope: the assigned item only. Siblings were checked as boundary/context evidence, especially paired [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md).
- Emitter repair required: no. The current emitters `0000N0,0000OI` exactly match the proven source-use roots.
- Canonical owner repair required: no. The correct current state remains `CANONICAL_OWNER:NONE`.
- Shared coverage report edit: not needed.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from output routing. It explicitly allows compiler/linker-pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts. This target fits that rule: one physical `.rdata` cell is referenced by reconnect/connection-closed code and by TerminalPane code.

`inference_research.md` warns that merged string literals and constant pools can be produced by compiler/linker behavior rather than by a human placing one variable in one source file. I therefore treated the containing `.rdata` island and neighboring strings as boundary/context evidence only. Ownership/routing conclusions below are based on exact bytes, direct xrefs, containing functions, source-root docs, and negative evidence.

Existing documentation assumptions treated as uncertain until rechecked:

- the false IDA string/pointer labels at `0x00622f1c` and `0x00622f20`;
- the current two-emitter routing;
- whether `AlertPanes` owns caller-provided labels;
- whether a new shared label source file is warranted.

## Evidence Standards Used

- Current IDA MCP session `b001_0002bd`: `server_health`, `get_bytes`, `get_string`, `make_signature_for_range`, `entity_query`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `find_bytes`, and selected `decompile`.
- Raw PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, VA-to-raw conversion, target bytes, whole-file byte-pattern searches, absolute-VA immediate searches, target-RVA search, and interior/boundary negative searches.
- Documentation evidence: target page, generated coverage rows, `by-memory/-coverage-report.md`, [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md), ReconnectDialog/ConnectionClosedDialog/TerminalPane consumer docs, [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md), and the paired [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md).
- Evidence strength: strong for bytes, range, xrefs, emitter routes, and rejected split/merge; necessarily inferential for original declaration style because the binary is stripped and string pooling can erase source-level literal duplication.

## IDA MCP Facts

Live IDA session state:

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

### Function / Range Facts

`lookup_funcs` maps the four target xrefs and alert callback support to:

| Query | Function | Size | Documentation interpretation |
| --- | --- | ---: | --- |
| `0x00553c3f` | `sub_553C10` | `0xaf` | [UID:00023O][ConnectionClosedDialogConstructorVariant](../../../../../by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) |
| `0x00553cef` | `sub_553CC0` | `0xae` | [UID:00038J][ConnectionClosedDialogMethods](../../../../../by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) |
| `0x00554359` | `sub_554210` | `0x1f6` | [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) |
| `0x0058b5ac` | `sub_58B470` | `0x170` | `TerminalPane::OnDisconnect` inside [UID:0001JB][TerminalPaneAndSetup](../../../../../by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) |
| `0x0058b620` | `sub_58B620` | `0x2f` | [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) |
| `0x004a0690` | `sub_4A0690` | `0x47` | `VersatileAlertPane` wrapper forwards caller labels |
| `0x0049feb0` | `sub_49FEB0` | `0x6c5` | reusable `AlertPane` constructor infrastructure |

### Data / Table / Padding Facts

`get_bytes` over `0x00622f1c-0x00622f54` returned:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

Decoded contents:

- `0x00622f1c-0x00622f28`: UTF-16LE `Leave`
- `0x00622f28-0x00622f3c`: UTF-16LE `Reconnect`
- `0x00622f3c-0x00622f44`: UTF-16LE `No` plus alignment
- `0x00622f44-0x00622f4c`: UTF-16LE `Yes`
- `0x00622f4c-0x00622f54`: ANSI `baram` plus alignment

`make_signature_for_range(0x00622f1c-0x00622f28, wildcard_operands=false)` returned a unique signature:

```text
4C 00 65 00 61 00 76 00 65 00 00 00
```

IDA string/name limitations:

| Address | IDA value/name | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | `L` / `off_622F1C` | false pointer/partial decode at target start |
| `0x00622f20` | `ave` / `aAve` | false interior suffix; zero xrefs |
| `0x00622f28` | `R` / `off_622F28` | paired `Reconnect` sibling start |
| `0x00622f2c` | `connect` / `aConnect` | false interior suffix of `Reconnect` |
| `0x00622f3c` | `No` / `aNo` | real successor child |
| `0x00622f44` | `Y` | `Yes` successor start |
| `0x00622f4c` | `baram` / `aBaram_0` | real ANSI successor child |

`entity_query(names, 0x00622f1c-0x00622f60)` found `aAve`, `aConnect`, `aNo`, `aBaram_0`, and successor `Region` vtable name at `0x00622f58`; it did not reveal a hidden source label declaration.

### Xref Facts

`xrefs_to(0x00622f1c)` returns exactly four xrefs:

| Xref | Function | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | `ConnectionClosedDialog` constructor variant uses `Leave` |
| `0x00553cef` | `sub_553CC0` | alternate `ConnectionClosedDialog` constructor path uses `Leave` |
| `0x00554359` | `sub_554210` | `ReconnectDialog::OnButtonClick` replacement alert path uses `Leave` |
| `0x0058b5ac` | `sub_58B470` | `TerminalPane::OnDisconnect` prompt uses `Leave` |

The paired sibling [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) has matching refs:

| Xref | Function | Meaning |
| --- | --- | --- |
| `0x00553c44` | `sub_553C10` | paired `Reconnect` label |
| `0x00553cf4` | `sub_553CC0` | paired `Reconnect` label |
| `0x0055435e` | `sub_554210` | paired `Reconnect` label |
| `0x0058b5b1` | `sub_58B470` | paired `Reconnect` label |

Negative IDA xref facts:

- `xrefs_to(0x00622f20)`: none.
- `xrefs_to(0x00622f22)`: none.
- `xrefs_to(0x00622f24)`: none.
- `xrefs_to(0x00622f26)`: none.
- `xrefs_to(0x00622f54)`: none.

### Data-Flow And Decompiler Facts

`trace_data_flow(0x00622f1c, backward, max_depth=2)` reaches the four code nodes above, all as `push offset off_622F1C`, with preceding `dword_67A750` text/context loads. It does not find a table owner or source declaration object.

`analyze_component` over `0x00553c10`, `0x00553cc0`, `0x00554210`, `0x0058b470`, `0x0058b620`, `0x004a0690`, and `0x0049feb0` reports:

- `off_622F1C` and `off_622F28` are shared globals accessed by `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`.
- `sub_553C10`, `sub_553CC0`, and `sub_554210` call `sub_49FEB0`.
- `sub_58B470` calls `sub_4A0690` and `sub_49FEB0`.
- `sub_4A0690` calls `sub_49FEB0`.
- `sub_58B620` calls only `sub_464E40` and `sub_5975E0`, matching the reconnect/leave callback role.

Representative decompiler lines:

```text
0x00553c10: sub_49FEB0(v2, v4, &off_622F28, &off_622F1C);
0x00553cc0: sub_49FEB0(v3, a2, &off_622F28, &off_622F1C);
0x00554210: sub_49FEB0(v8, v11, &off_622F28, &off_622F1C);
0x0058b470: v10[2] = sub_58B620; sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C);
0x0058b620: nonzero branch calls sub_5975E0(...); zero branch calls sub_464E40();
0x004a0690: sub_49FEB0(a2, a3, a5, a6);
```

Inference from those facts:

- `ReconnectDialog`/`ConnectionClosedDialog` code supplies the `Reconnect`/`Leave` labels directly to alert construction.
- `TerminalPane::OnDisconnect` supplies the same label pair to callback-backed alert construction.
- `AlertPanes` owns reusable constructors that receive caller labels; it does not own this feature text.

## Raw PE Evidence

Raw file inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Section mapping:

| Section | VA | Raw pointer | Raw size |
| --- | --- | --- | --- |
| `.text` | `0x00401000` | `0x400` | `0x20b600` |
| `.rdata` | `0x0060d000` | `0x20ba00` | `0x5f200` |
| `.data` | `0x0066d000` | `0x26ac00` | `0xd800` |
| `.rsrc` | `0x0069d000` | `0x278400` | `0x15e00` |

Target mapping:

- VA `0x00622f1c` maps to raw offset `0x22191c`.
- Target and sibling bytes at raw `0x22191c` are:

```text
4c 00 65 00 61 00 76 00 65 00 00 00 52 00 65 00
63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00 59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

Whole-file raw search:

| Pattern | Count | Hits |
| --- | ---: | --- |
| UTF-16LE `Leave\0` | 1 | raw `0x22191c` / VA `0x00622f1c` |
| UTF-16LE `Leave` without terminator | 1 | raw `0x22191c` / VA `0x00622f1c` |
| ASCII `Leave\0` | 0 | none |
| absolute VA `0x00622f1c` | 4 | operand bytes at VAs `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad` |
| `push 0x00622f1c` | 4 | VAs `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| interior `0x00622f20` | 0 | none |
| interior `0x00622f22` | 0 | none |
| interior `0x00622f24` | 0 | none |
| interior `0x00622f26` | 0 | none |
| sibling absolute VA `0x00622f28` | 4 | operand bytes at VAs `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| `push 0x00622f28` | 4 | VAs `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| boundary `0x00622f54` | 0 | none |
| target RVA `0x00222f1c` | 0 | none |

The raw PE evidence independently confirms the IDA xrefs and rejects hidden references, a pointer-table owner, an RVA-form route, an ASCII duplicate, an interior split, or a merge with successor data.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Mixed string-tail map | `FALSE` | `NONE` | `89/93` | Keep as non-emitting container |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | Shared `Leave` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Current target; keep unchanged |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | Paired shared `Reconnect` label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Same source-use route |
| `0x00622f3c-0x00622f44` | [UID:0003G5][CopyWindowNoButtonWideString](../../../../../by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | CopyWindow `No` label | `TRUE` | [UID:000039][CopyWindow](../../../../../by-class/CopyWindow.md) | current docs | Separate successor |
| `0x00622f44-0x00622f4c` | [UID:0003G6][CopyWindowYesButtonWideString](../../../../../by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | CopyWindow `Yes` label | `TRUE` | [UID:000039][CopyWindow](../../../../../by-class/CopyWindow.md) | current docs | Separate successor |
| `0x00622f4c-0x00622f54` | [UID:0003G7][SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | Shared `baram` packet literal | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Related shared sibling |
| `0x00553c10-0x00553cbf` | [UID:00023O][ConnectionClosedDialogConstructorVariant](../../../../../by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | Constructor variant using label pair | `TRUE` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) | `82/86`; file `87/88` | Reconnect emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J][ConnectionClosedDialogMethods](../../../../../by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Alternate constructor/handlers | `TRUE` | [UID:000036][ConnectionClosedDialog](../../../../../by-class/ConnectionClosedDialog.md), file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Reconnect constructors/handlers | `TRUE` | [UID:0000BR][ReconnectDialog](../../../../../by-class/ReconnectDialog.md), file [UID:0000N0] | `86/89` | Reconnect emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB][TerminalPaneAndSetup](../../../../../by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) | Terminal pane/setup aggregate | `TRUE` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) | `85/86`; file `87/85` | Terminal emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) | Callback installed by TerminalPane prompt | `TRUE` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) | `85/91` | Confirms TerminalPane route |
| `0x0049feb0-0x004a0686` | [UID:00012W][AlertPaneCore](../../../../../by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md) | Reusable alert infrastructure | `TRUE` | [UID:00000B][AlertPane](../../../../../by-class/AlertPane.md), file [UID:0000HE] | `82/90`; file `85/88` | Rejected as label owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `push offset off_622F1C` in `sub_553C10` | Reconnect/connection-closed constructor passes `Leave` |
| `0x00553c44` | `push offset off_622F28` in `sub_553C10` | paired `Reconnect` label |
| `0x00553cef` | `push offset off_622F1C` in `sub_553CC0` | alternate connection-closed constructor passes `Leave` |
| `0x00553cf4` | `push offset off_622F28` in `sub_553CC0` | paired `Reconnect` label |
| `0x00554359` | `push offset off_622F1C` in `sub_554210` | reconnect path constructs replacement connection-closed alert |
| `0x0055435e` | `push offset off_622F28` in `sub_554210` | paired `Reconnect` label |
| `0x0058b5ac` | `push offset off_622F1C` in `sub_58B470` | TerminalPane disconnect prompt passes `Leave` |
| `0x0058b5b1` | `push offset off_622F28` in `sub_58B470` | paired `Reconnect` label |
| `0x004a0690` | `sub_4A0690(..., a5, a6)` calls `sub_49FEB0(a2, a3, a5, a6)` | alert wrapper forwards caller labels; not a label owner |
| `0x0049feb0` | `sub_49FEB0` | shared alert constructor consumes caller-provided labels |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page records the exact bytes, four source-use xrefs, false interior `aAve` artifact, no canonical owner, current emitters, and blank C++.
- [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) is a valid source-file root at `87/88`, `CANONICAL_OWNER:FILE`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`; it owns the `ConnectionClosedDialog` and `ReconnectDialog` source family.
- [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) is a valid source-file root at `87/85`, `CANONICAL_OWNER:FILE`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`; it owns `TerminalPane::OnDisconnect` and the reconnect/leave callback.
- [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) directly records the prompt-label construction from `TerminalPane::OnDisconnect`.
- [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md) supports rejecting alert infrastructure as owner: it explicitly keeps feature-specific reconnect alerts with feature modules, while `AlertPaneCore`/`VersatileAlertPane` are reusable consumers of caller labels.
- [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) correctly remains a non-emitting mixed map over children with different source routes.

Existing docs that are stale, incomplete, or contradicted:

- No target-page repair is needed. IDA's false `off_622F1C` / `aAve` naming remains imperfect, but the docs already explain it and current evidence confirms the explanation.
- Generated source files for `ReconnectDialog.cpp`, `TerminalPane.cpp`, and `AlertPanes.cpp` currently exist as zero-length placeholders; generated-source surface therefore does not add C++ placement evidence.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` current memory row lists the item as `no-owner`, owner `NONE`, emitters `0000N0`,`0000OI`, destination display `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- The generated emitter table lists both [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md).
- `by-memory/-coverage-report.md` already documents the current no-owner/two-emitter state and the rejected canonical owners.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` - accepted

Evidence for:

- This matches current `by-structure.md` guidance for pooled/shared literals with no proven single declaration owner.
- Live IDA xrefs prove direct source-use routes in ReconnectDialog-family code and TerminalPane code.
- Raw PE scan confirms one exact UTF-16 `Leave` spelling, exactly four target absolute/push references, no target RVA refs, and no hidden interior refs.
- Both emitter roots clear the source-route gate and have valid reconstruction paths.
- The paired `Reconnect` sibling has the same four-site route and same two-emitter model.

Evidence against:

- The stripped binary cannot prove whether original source used repeated local literals, a shared macro, or a shared constant declaration.

Decision: accepted. The uncertainty blocks canonical ownership; it does not block emitter routing because every source-use xref is exact.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner - rejected

Evidence for:

- Three of four refs are in `ConnectionClosedDialog` / `ReconnectDialog` code.
- The label is semantically central to the connection-loss/reconnect UI.
- The source file owns both relevant reconnect alert classes and singleton globals.

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
- TerminalPane is one real consumer, not a declaration owner for the reconnect dialog call sites.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### 4. [UID:0000HE] `AlertPanes` / alert infrastructure - rejected

Evidence for:

- All uses eventually flow into alert construction infrastructure.
- `AlertPanes` is a valid shared alert source root.

Evidence against:

- The `Leave` label is caller-supplied feature text, not a generic alert-library literal.
- `sub_4A0690` forwards caller labels to `sub_49FEB0`; it does not reference `0x00622f1c` itself.
- `AlertPanes.md` explicitly keeps reconnect alerts with [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) when feature-coupled.

Decision: reject as owner and emitter for this literal.

### 5. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG] - rejected

Evidence for:

- `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` each own method bodies that use or surround the label.

Evidence against:

- No single class covers all four refs.
- The reconnect-side refs span two classes in one source file, and TerminalPane is separate.
- The item is pooled source string data, not class-static storage, a vtable, a member, or a class-specific resource table.

Decision: reject for canonical ownership and do not switch to class-level emitters.

### 6. Physical container [UID:0003CW] or broader [UID:000269] - rejected

Evidence for:

- The target is physically inside those `.rdata` maps.

Evidence against:

- The maps are non-emitting mixed-owner inventory containers.
- Neighboring exact children have different routes: `No`/`Yes` are CopyWindow-only; `baram` is a separate shared packet literal.
- Address adjacency is weak ownership evidence for pooled strings.

Decision: reject as source owner.

### 7. New shared label/source owner - rejected

Evidence for:

- `Leave` and `Reconnect` are paired at all four prompt sites.
- A shared header macro or named constant is possible in original source.

Evidence against:

- No table, initializer, source/debug name, address-taken global, symbol, or coherent constants module is visible.
- Ordinary string-literal pooling fully explains one physical address used from independent source contexts.
- Current structure rules warn against inventing a standalone owner solely to avoid `NONE`.

Decision: reject. No new file/grouping is recommended.

## Negative Evidence Summary

- No xrefs to false interior `0x00622f20` / `aAve`.
- No raw immediate refs to interior `0x00622f20`, `0x00622f22`, `0x00622f24`, or `0x00622f26`.
- No ASCII `Leave` spelling.
- No target RVA-form references.
- No hidden absolute-VA/push references beyond the four known source-use sites.
- No refs to `0x00622f54` boundary.
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

No `by-memory/-coverage-report.md` replacement is required. If the supervisor wants an explicit retained row, keep the current row:

```markdown
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; B003 post-migration and B001 second-pass reviews confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, no target RVA refs, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

Exact items left no-owner/non-emitting and why:

- [UID:0003G3] remains no-owner but emitting because it is a compiler/linker-pooled literal with proven independent source-use routes and no proven single declaration owner.
- No item in this assignment remains non-emitting; current emitters are nonblank and valid.

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

- Supervisor actions: mark this B003 recheck complete if accepted. No by-memory or generated coverage edit is required.
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

- Created: `tools/leaser/Agents/Agent-B003/research/0003G3-SharedLeaveWideString-current-no-owner-research.md`.
- Modified: none outside the Agent-B003 research folder.
- Renamed: none.
- Moved to executed: none.
- Leases: no leases used or required; the shared lease report showed no active leases before report creation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B003/0003G3-SharedLeaveWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
