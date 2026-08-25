** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Second-Pass Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Required action: no metadata, coverage-row, split, merge, reclassification, parent repair, or IDA repair action is recommended.
- Score before/after: `89/94` before, `89/94` after.
- Confidence: high. The current no-owner-with-emitters state is valid under the current owner/emitter model because live IDA and raw PE evidence prove source-use contexts in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md), while no single semantic declaration owner is proven.

This is not a no-owner/non-emitting defect. It is the intended representation for a compiler/linker-pooled source literal with multiple proven source-use file roots and no defensible single declaration owner.

## Supporting Research

## Target

- Target UID: `0003G3`.
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`.
- Assignment: `B001-0003G3-second-pass`.
- Current generated state: no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, reconstructable.
- Current page state: `COMPLETION:89`, `CONFIDENCE:94`, `RECONSTRUCTABLE:TRUE`, no reconstruction C++.
- Prior report reviewed as background: `tools/leaser/Agents/Agent-B003/research/executed/0003G3-SharedLeaveWideString-post-migration.md`.
- Earlier B001 report reviewed as historical background: `tools/leaser/Agents/Agent-B001/research/executed/0003G3-SharedLeaveWideString-B001-0003G3.md`.

## Executive Recommendation

Keep UID `0003G3` as a reconstructable pooled UTF-16 button-label literal with no canonical owner and two emitter routes.

The physical bytes at `0x00622f1c-0x00622f28` represent UTF-16LE `Leave`. Live IDA MCP and a fresh raw PE scan show exactly four direct `push 0x00622f1c` source-use sites:

| Source-use family | Addresses | Emitter |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor variants | `0x00553c3f`, `0x00553cef` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) |
| `TerminalPane::OnDisconnect` reconnect/leave prompt | `0x0058b5ac` | [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |

Do not assign a canonical owner to `ReconnectDialog`, `ConnectionClosedDialog`, `TerminalPane`, `AlertPanes`, the physical string-tail map, or a new shared-label owner. Each would overclaim the pooled literal. The final source should eventually spell `L"Leave"` naturally at the proven call sites when those consumer method pages reach source-code entry quality.

## Supervisor Active Recheck

- Trigger: second-pass audit of the current no-owner-with-emitters state for `0003G3`.
- Split repair required: no. The target is already an exact 12-byte UTF-16 string child.
- Emitter repair required: no. The current emitters `0000N0,0000OI` are justified and should stay.
- Canonical owner repair required: no. The correct current state remains `CANONICAL_OWNER:NONE`.
- Coverage-report edit: not needed. `by-memory/-coverage-report.md` already has a current row reflecting the no-owner/two-emitter state.

## Inference Research Guidance Check

`by-structure.md` now separates semantic ownership from generated-output routing. It explicitly allows compiler/linker-pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts. That rule directly applies here.

`inference_research.md` cautions that `.rdata` adjacency and pooled strings are weak source-file evidence. This report therefore treats neighboring `Reconnect`, `No`, `Yes`, and `baram` strings as boundary/context evidence only. Ownership and routing are based on exact bytes, direct xrefs, containing functions, source-root docs, and negative evidence.

Existing documentation was treated as evidence, not authority. The prior B003 result was rechecked against the current target page, source-root docs, sibling/container docs, generated coverage, live IDA MCP, and raw PE facts.

## Evidence Standards Used

- Live IDA MCP evidence from session `b001_0003gy`: database health, exact bytes, IDA string decoding, xrefs, function lookup, component graph, listing text search, data-flow trace, decompiler snippets, and source/debug string search.
- Fresh raw PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, byte decoding, exact string occurrence counts, target VA/RVA scans, push-immediate scans, and sibling `Reconnect` operand comparison.
- Documentation evidence: `by-structure.md`, `inference_research.md`, proposed source tree, target page, prior reports, current generated rows, coverage row, and by-file/by-class/by-memory consumer pages.
- Negative evidence: no refs to false interior `0x00622f20`, no ASCII `Leave` spelling, no target RVA refs, no source/debug metadata, no common owner/helper/table, and no one consumer covering all four refs.

## IDA MCP Facts

IDA MCP state:

```text
database: b001_0003gy
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x00400000
auto-analysis: ready
Hex-Rays: ready
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

This decodes as UTF-16LE `Leave`, UTF-16LE `Reconnect`, UTF-16LE `No` plus padding, UTF-16LE `Yes`, and ANSI `baram`.

IDA's string decoder currently reports:

| Address | IDA value | Interpretation |
| --- | --- | --- |
| `0x00622f1c` | `L` | False partial decode at target start |
| `0x00622f20` | `ave` | False interior suffix, not a real child |
| `0x00622f28` | `R` | False partial decode at sibling start |
| `0x00622f2c` | `connect` | False interior suffix of `Reconnect` |
| `0x00622f3c` | `No` | Real successor child |
| `0x00622f44` | `Y` | False partial decode at `Yes` start |
| `0x00622f4c` | `baram` | Real ANSI successor child |

### Xrefs

`xrefs_to(0x00622f1c)` returns exactly four xrefs:

| Address | IDA function | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | `ConnectionClosedDialog` constructor variant source use |
| `0x00553cef` | `sub_553CC0` | alternate `ConnectionClosedDialog` constructor/source path |
| `0x00554359` | `sub_554210` | `ReconnectDialog::OnButtonClick` replacement alert path |
| `0x0058b5ac` | `sub_58B470` | `TerminalPane::OnDisconnect` reconnect/leave prompt |

`xrefs_to(0x00622f28)` returns the paired sibling `Reconnect` refs at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.

`xrefs_to(0x00622f20)` returns zero xrefs. The `aAve`/`ave` interior name is an IDA typing artifact and does not need a split, owner, or emitter.

Sibling context:

| Address | String | Xref shape |
| --- | --- | --- |
| `0x00622f1c` | `Leave` | Shared by ReconnectDialog-family and TerminalPane |
| `0x00622f28` | `Reconnect` | Same four sites as `Leave` |
| `0x00622f3c` | `No` | CopyWindow-only successor child |
| `0x00622f44` | `Yes` | CopyWindow-only successor child |
| `0x00622f4c` | `baram` | Shared reconnect/terminal packet literal |

### Listing Search

`search_text("off_622F1C")` over the relevant code region found exactly:

```text
0x00553c3f  sub_553C10  push offset off_622F1C
0x00553cef  sub_553CC0  push offset off_622F1C
0x00554359  sub_554210  push offset off_622F1C
0x0058b5ac  sub_58B470  push offset off_622F1C
```

`search_text("off_622F28")` found the paired `Reconnect` pushes:

```text
0x00553c44  sub_553C10  push offset off_622F28
0x00553cf4  sub_553CC0  push offset off_622F28
0x0055435e  sub_554210  push offset off_622F28
0x0058b5b1  sub_58B470  push offset off_622F28
```

`trace_data_flow(0x00622f1c, backward, max_depth=2)` reaches the same four code sites and then the preceding alert text/context loads. It does not reveal a table owner or a hidden source declaration.

### Function / Component Evidence

`lookup_funcs` maps the xref sites to:

| Address | Function | Size |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | `0xaf` |
| `0x00553cef` | `sub_553CC0` | `0xae` |
| `0x00554359` | `sub_554210` | `0x1f6` |
| `0x0058b5ac` | `sub_58B470` | `0x170` |
| `0x0058b620` | `sub_58B620` | `0x2f` |
| `0x004a0690` | `sub_4A0690` | `0x47` |
| `0x0049feb0` | `sub_49FEB0` | `0x6c5` |

`analyze_component` over the reconnect, terminal, and alert constructor functions confirms:

- `sub_553C10` and `sub_553CC0` call `sub_49FEB0`.
- `sub_554210` calls `sub_553CC0` and `sub_49FEB0`.
- `sub_58B470` calls `sub_4A0690` and `sub_49FEB0`.
- `sub_4A0690` calls `sub_49FEB0`.
- Shared globals include `off_622F1C` and `off_622F28` accessed by `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`.
- `sub_58B620` calls only `sub_5975E0` and `sub_464E40`, matching the TerminalPane reconnect/leave callback role.

Decompiled snippets with address markers:

```text
0x00553c10:
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C); /*0x553c5c*/

0x00553cc0:
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C); /*0x553d09*/

0x00554210:
sub_443A00(Buffer, 0x80u, "baram", (char)v12); /*0x554287*/
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C); /*0x554376*/

0x0058b470:
v10[2] = sub_58B620; /*0x58b56d*/
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/

0x0058b620:
if ( a1 ) return sub_5975E0(0, 0, 0, 0); /*0x58b637*/
else return sub_464E40(); /*0x58b646*/

0x004a0690:
sub_49FEB0(a2, a3, a5, a6); /*0x4a06a6*/
```

Inference from these facts:

- The first three `Leave` uses are reconnect/connection-closed feature code routed by `ReconnectDialog.cpp`.
- The fourth use is a TerminalPane-owned callback prompt.
- `AlertPanes` supplies reusable alert constructors, but the feature modules supply the label data.

### Source / Debug Metadata Search

`find_regex("(?i)\\.pdb|RSDS|NB10|\\.cpp|\\.cxx|\\.h")` returned no matches in the IDA string cache. No source/debug breadcrumb proves a declaration owner or a shared-label source file.

## Fresh Raw PE Facts

Raw PE scan target:

```text
Executable: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Imagebase: 0x00400000
Target VA: 0x00622f1c
Target section: .rdata
Target file offset: 0x22191c
```

Section map:

```text
.text  0x00401000-0x0060c600 raw 0x400+0x20b600
.rdata 0x0060d000-0x0066c200 raw 0x20ba00+0x5f200
.data  0x0066d000-0x0069ce24 raw 0x26ac00+0xd800
.rsrc  0x0069d000-0x006b2e00 raw 0x278400+0x15e00
```

Target bytes:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
```

Raw scan results:

| Pattern | Count | Hits |
| --- | ---:| --- |
| UTF-16LE `Leave\0` | 1 | `0x00622f1c` |
| UTF-16LE `Leave` without terminator | 1 | `0x00622f1c` |
| ASCII `Leave\0` | 0 | none |
| target VA bytes `1c 2f 62 00` | 4 | `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad` |
| `push 0x00622f1c` bytes | 4 | `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| target RVA bytes | 0 | none |
| false interior VA `0x00622f20` | 0 | none |
| sibling `Reconnect` VA bytes | 4 | `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| `push 0x00622f28` bytes | 4 | `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| UTF-16LE `Reconnect\0` | 2 | `0x00622f28`, `0x006288b0` |
| ASCII `Reconnect\0` | 0 | none |

The raw scan independently confirms the IDA xref set and does not reveal any hidden source-use, pointer table, RVA-form reference, or interior split candidate.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Non-emitting mixed string-tail map | `FALSE` | `NONE` | `89/93` | Keep as container |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | Shared `Leave` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Current target; keep unchanged |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | Shared `Reconnect` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Paired sibling; same route |
| `0x00622f3c-0x00622f44` | [UID:0003G5][CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | CopyWindow `No` label | `TRUE` | CopyWindow route | current docs | Separate successor |
| `0x00622f44-0x00622f4c` | [UID:0003G6][CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | CopyWindow `Yes` label | `TRUE` | CopyWindow route | current docs | Separate successor |
| `0x00622f4c-0x00622f54` | [UID:0003G7][SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | Shared `baram` packet literal | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/93` | Related shared sibling |
| `0x00553c10-0x00553cbf` | [UID:00023O][ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | Constructor variant using label pair | `TRUE` | `0000N0` route | `82/86`; file `87/88` | ReconnectDialog emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J][ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Alternate constructor and handlers | `TRUE` | class `000036`, file `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L][ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Reconnect button/timeout method cluster | `TRUE` | class `0000BR`, file `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB][TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) | Terminal pane setup and disconnect prompt | `TRUE` | `0000OI` | `85/86`; file `87/85` | TerminalPane emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD][TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) | Callback installed by TerminalPane prompt | `TRUE` | `0000OI` | `85/91` | Confirms TerminalPane route |

## Documentation Evidence And IDA Status

Supporting docs:

- Target page records exact bytes, four IDA xrefs, false `aAve` artifact, no canonical owner, and current `EMITTER_UIDS:0000N0,0000OI`.
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) is `87/88`, has `CANONICAL_OWNER:FILE`, routes to `NexusTK/network/`, and owns the `ConnectionClosedDialog`/`ReconnectDialog` source family.
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md) is `87/85`, has `CANONICAL_OWNER:FILE`, routes to `NexusTK/login/`, and owns the terminal disconnect prompt and callback family.
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md) owns reusable alert/dialog infrastructure but keeps feature-specific reconnect alerts with feature modules unless broader evidence proves common alert-helper ownership.
- [UID:0001JD][TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) records the callback-object construction and the prompt-label pushes from `TerminalPane::OnDisconnect`.
- [UID:0003G4][SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) has the same four-site source-use shape and has already been second-pass reviewed as no-owner/two-emitter.
- `by-project-structure/proposed-source-tree.md` places `ReconnectDialog.cpp` under `network/`, `TerminalPane.cpp` under `login/`, and `AlertPanes.cpp` under `ui/dialogs/`, while explicitly keeping feature-specific reconnect alerts out of `AlertPanes`.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0003G3] as `no-owner` with owner `NONE`, emitters `0000N0`,`0000OI`, and generated destination display `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- The generated emitter table also lists both [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md).
- `by-memory/-coverage-report.md` already has a child row under [UID:0003CW] documenting `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, the four source-use refs, and rejected canonical owners.

No stale documentation requiring action was found for this target. The prior report text describes adding emitters; that recommendation has already been applied.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` - accepted

Evidence for:

- This matches `by-structure.md` for pooled/shared literals with no proven single declaration owner.
- Direct code refs prove both ReconnectDialog-family and TerminalPane source-use contexts.
- Both source-file emitters clear the route gate and have valid reconstruction paths.
- Fresh raw PE scan confirms exactly four target immediates, no hidden refs, no target RVA refs, and no interior split refs.
- The paired `Reconnect` sibling has the same route and was independently reviewed as no-owner/two-emitter.

Evidence against:

- Original source could have used a shared macro/header constant or repeated local literals; stripped binary evidence cannot distinguish those perfectly.

Decision: accepted. The uncertainty blocks canonical ownership, not emitter routing.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner - rejected

Evidence for:

- Three of four direct uses are in `ConnectionClosedDialog` / `ReconnectDialog` code.
- The label is semantically central to connection-loss and reconnect UI.
- `ReconnectDialog` owns the connection/reconnect class family and singleton globals.

Evidence against:

- `TerminalPane::OnDisconnect` directly uses the same physical label in a TerminalPane-owned callback prompt.
- No IDA evidence shows TerminalPane delegates this label declaration to `ReconnectDialog`.
- Choosing `ReconnectDialog` as canonical owner would force ownership to the majority consumer, which `by-structure.md` explicitly warns against for pooled literals.

Decision: reject as canonical owner; keep as emitter `0000N0`.

### 3. [UID:0000OI] `TerminalPane` as canonical owner - rejected

Evidence for:

- TerminalPane has one direct, material source-use site at `0x0058b5ac`.
- `TerminalPane::OnDisconnect` constructs the reconnect/leave prompt and installs callback `sub_58B620`.

Evidence against:

- Three direct refs are outside TerminalPane in connection/reconnect dialog code.
- TerminalPane is a real consumer, not the declaration owner for the reconnect/connection-closed call sites.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### 4. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG] - rejected

Evidence for:

- `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` each own method bodies that use or surround the literal.

Evidence against:

- No class covers all four refs.
- The literal is pooled source string data, not a vtable, member field, or class-static object tied to one class declaration.
- The reconnect-side three refs span two classes in one source file, so a file-level emitter is clearer than class-level routing.

Decision: reject for canonical ownership and do not use as emitters for this pooled literal.

### 5. [UID:0000HE] `AlertPanes` / `VersatileAlertPane` - rejected

Evidence for:

- The call sites use alert/dialog construction infrastructure.
- TerminalPane calls `sub_4A0690`, the callback-backed `VersatileAlertPane` constructor shape, which itself calls `sub_49FEB0`.

Evidence against:

- `Leave` is feature-specific prompt text, not a generic alert-library declaration.
- `AlertPanes.md` and proposed source-tree guidance keep reconnect/connection alerts with feature modules.
- `sub_4A0690` forwards caller-supplied labels; it does not reference or own `0x00622f1c`.

Decision: reject as owner and emitter.

### 6. New shared label/source owner - rejected

Evidence for:

- `Leave` and `Reconnect` are paired at four prompt sites.
- A source header or macro could have defined shared button labels.

Evidence against:

- No table, initializer, source/debug name, address-taken global, or coherent constants module is present.
- Ordinary string literal pooling fully explains one physical address used by independent source contexts.
- `by-structure.md` warns not to invent a standalone global/helper file solely to avoid `NONE`.

Decision: reject. No new owner/file should be created.

### 7. Reclassify as non-reconstructable/non-emitting - rejected

Evidence for:

- None.

Evidence against:

- The item is source-authored UI text and has exact source-use contexts.
- Current emitters are proven. This is not compiler-only padding, dead data, or an ignored container.

Decision: reject.

## Split / Merge / IDA Repair Decision

No split is recommended:

- The target range is exactly one UTF-16LE `Leave` literal plus terminator from `0x00622f1c-0x00622f28`.
- The false interior `0x00622f20` has zero xrefs.
- The successor starts at `0x00622f28` and is already split as [UID:0003G4].

No merge is recommended:

- The broader [UID:0003CW] page is a mixed non-emitting map over shared reconnect/terminal strings, CopyWindow-only strings, and shared packet text.
- Adjacent children have different ownership/routing semantics.

No reclassification is recommended:

- The target is source-authored/source-declared string data that should be recreated through call-site source, not ignored.

No IDA repair is required for this assignment:

- The false IDA labels are documented.
- Function boundaries and xrefs are sufficient for ownership/routing.
- Renaming IDA items is not required to make the documentation decision.

## Negative Evidence Summary

- No xrefs to false interior `0x00622f20`.
- No ASCII `Leave` spelling.
- No target RVA references.
- No hidden `push`/absolute-VA references beyond the four known source-use sites.
- No source/debug metadata (`.pdb`, `RSDS`, `NB10`, `.cpp`, `.cxx`, `.h`) was found by IDA string search.
- No table/global declaration owns the label pair.
- No AlertPanes-specific literal ownership: alert constructors receive labels from feature callers.
- No one class or file covers all direct xrefs as a semantic owner.
- Address adjacency alone cannot make the containing map a source owner.

## Exact Required Changes

No changes are required.

Retain target metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Retain the current `by-memory/-coverage-report.md` row:

```text
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; live IDA MCP and B003 raw PE scan confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

No reconstruction C++ should be added by this B report. The item is `89/94`, but final source belongs at the consumer call sites after those methods' signatures, names, and surrounding bodies are ready under the current `90/90+` source-code gate.

## Follow-Up Actions

- Supervisor actions: none required for this target.
- A-agent actions: none required for this target.
- Future research: revisit only if future PDB/map/source evidence proves a real shared label declaration or constants module. Current binary evidence supports pooled literal emission through proven source-use files.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: keep `89/94`.
- Remaining uncertainty: the stripped binary cannot prove whether original source wrote repeated local `L"Leave"` literals, a macro, or a shared constant. That uncertainty is exactly why `CANONICAL_OWNER:NONE` remains correct, but it does not weaken the emitter route because the source-use sites are exact.

## Validator Results

- Validator not run. No by-* files or coverage files were edited, and the final recommendation is no change.
- No dry-run validator mode was used.
- No memory-range validator mode was used.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G3-SharedLeaveWideString-second-pass.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.

## Blockers

None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B001/0003G3-SharedLeaveWideString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
