** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Post-Migration Owner / Emitter Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` as `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:TRUE`, but add emitter routes `EMITTER_UIDS:0000N0,0000OI`.
- Final disposition: exact UTF-16LE `Leave` label pooled into `.rdata`; no single semantic declaration owner is defensible, but both `ReconnectDialog.cpp` and `TerminalPane.cpp` are proven source-use contexts.
- Required action: update only metadata/routing and the coverage row through supervisor/normal documentation workflow. Do not split, merge, reclassify, or assign a canonical owner. Do not add reconstruction C++ in this pass.
- Confidence: 92/100 for no canonical owner plus two emitters.

## Supporting Research

## Target

- Target UID: `0003G3`.
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`.
- Required report path: `tools/leaser/Agents/Agent-B003/research/0003G3-SharedLeaveWideString-post-migration.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner/non-emitting row and `tools/leaser/Agents/no_owner_b-agent-tracker.md` assignment `B003-0003G3-post-migration`.
- Historical report reviewed first: `tools/leaser/Agents/Agent-B001/research/executed/0003G3-SharedLeaveWideString-B001-0003G3.md`.
- Current scores and state:
  - `COMPLETION:89`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `EMITTER_POSITION_OPTIONAL:` blank

## Executive Recommendation

B001's historical conclusion remains correct for semantic ownership: do not force the physical pooled literal under `ReconnectDialog`, `TerminalPane`, `AlertPanes`, a class page, the containing map, or a new shared-label owner. The post-migration owner/emitter model changes the routing answer. Under `by-structure.md`, pooled source-authored literals with no single declaration owner can and should keep `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts.

The current blank `EMITTER_UIDS` is acceptable as an interim researched/no-output state while routing is unsettled, but it is not the best final state after this recheck. The source-use contexts are strong enough:

- [UID:0000N0] `by-file/ReconnectDialog.md`, `NexusTK/network/ReconnectDialog.cpp`, covers the three `ConnectionClosedDialog` / `ReconnectDialog` uses at `0x00553c3f`, `0x00553cef`, and `0x00554359`.
- [UID:0000OI] `by-file/TerminalPane.md`, `NexusTK/login/TerminalPane.cpp`, covers the independent `TerminalPane::OnDisconnect` use at `0x0058b5ac`.

Recommended metadata:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not enter `RECONSTRUCTION_CPP CODE` now. The item is `89/94`; confidence is high, but completion is still below the current `90/90+` code-entry gate and the final call-site bodies/callback signatures are not source-final. Routing can be fixed without writing C++.

## Supervisor Active Recheck

- Trigger: post-migration owner/emitter recheck for `B003-0003G3-post-migration`.
- Split repair required: no. The target is already an exact atomic child for `L"Leave"` at `0x00622f1c-0x00622f28`.
- Reclassification required: no. This is source-authored literal data, not a container, padding, section map, compiler/runtime support, or ignored range.
- Final action: route as no-owner/multi-emitter with `EMITTER_UIDS:0000N0,0000OI`.

## Inference Research Guidance Check

- `by-structure.md` now separates canonical semantic ownership from output routing. This directly changes the result from the older `AUTOGEN_PARENT_UID` model.
- Existing docs were treated as leads. The B001 report and target page already proved the no-single-owner case, but their "parent blank" language came from the older combined parent/routing model.
- IDA fact: live IDA MCP records in the target page and executed B001 report show four direct `Leave` xrefs, all paired with `Reconnect`.
- B003 independent fact check: raw PE scanning of `NexusTK.exe` reconfirmed the unique UTF-16 `Leave` spelling and exactly four `push 0x00622f1c` code sites.
- Inference: the binary has one pooled physical literal, while the reconstructed source needs the label in two feature source contexts.

## Evidence Standards Used

- IDA MCP evidence from current documentation: B001 executed report, target page, `TerminalPaneReconnectLeaveCallback`, `TerminalPaneAndSetup`, `ReconnectDialogMethods`, `ConnectionClosedDialogMethods`, and `ReconnectTerminalCopyStringTailMap` all record live IDA MCP evidence for the relevant xrefs, function roles, and source-family placement.
- Raw PE evidence from this B003 pass: byte decoding, exact-string search, absolute-VA search, push-immediate search, RVA negative search, interior-address negative search, and sibling `Reconnect` operand comparison.
- Documentation evidence: current `by-structure.md`, `by-file/ReconnectDialog.md`, `by-file/TerminalPane.md`, `by-file/AlertPanes.md`, current coverage/generated rows, the target page, sibling pages, and containing map page.
- Negative evidence: no source/debug metadata, no single-owner xref set, no interior `aAve` references, no extra pointer table, no AlertPanes-specific label ownership, no synthetic shared constants table.

## IDA MCP Facts

The current target page and B001 report record these live IDA MCP facts from the prior IDA session against `NexusTK.exe`:

- `get_bytes 0x00622f1c size 56` decodes the tail as UTF-16LE `Leave`, UTF-16LE `Reconnect`, UTF-16LE `No`, UTF-16LE `Yes`, and ANSI `baram`.
- `xrefs_to 0x00622f1c` returns exactly four xrefs:
  - `0x00553c3f` inside `sub_553C10`, documented as a `ConnectionClosedDialog` constructor variant.
  - `0x00553cef` inside `sub_553CC0`, documented as a `ConnectionClosedDialog` constructor/method path.
  - `0x00554359` inside `sub_554210`, documented as a `ReconnectDialog::OnButtonClick` candidate path.
  - `0x0058b5ac` inside `sub_58B470`, documented as `TerminalPane::OnDisconnect`.
- `xrefs_to 0x00622f20` returns zero xrefs, so the IDA interior name `aAve` is a decode artifact and not a split/owner target.
- All four `Leave` xrefs are paired with sibling [UID:0003G4] `SharedReconnectWideString` at `0x00622f28`.
- `TerminalPaneReconnectLeaveCallback` records that `TerminalPane::OnDisconnect` stores callback target `sub_58B620` at `0x0058b56d`, then pushes `Leave` at `0x0058b5ac` and `Reconnect` at `0x0058b5b1` before `sub_4F0350` / `sub_4A0690`.
- `ConnectionClosedDialogMethods` and `ReconnectDialogMethods` record the reconnect/leave alert behavior, singleton/vtable setup, and the leave/exit path under the ReconnectDialog source family.

Function/source placement from documentation with live IDA support:

- [UID:0000N0] `ReconnectDialog` is a file root at `NexusTK/network/`, scored `87/88`, with `ConnectionClosedDialog` and `ReconnectDialog` exact children. It covers the three reconnect/connection-closed uses.
- [UID:0000OI] `TerminalPane` is a file root at `NexusTK/login/`, scored `87/85`, with exact terminal aggregate and callback children. It covers the independent terminal prompt use.
- [UID:0000HE] `AlertPanes` is a valid shared alert infrastructure root, but its docs explicitly keep feature-specific reconnect alerts with feature modules unless broader evidence proves common alert-helper ownership.

## PE / Raw Evidence

B003 raw scan target:

```text
Executable: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
Image base: 0x400000
Target VA: 0x00622f1c
Target file offset: 0x22191c
Section: .rdata
```

Bytes at `0x00622f1c`:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

Raw scan results:

_Executable command block removed from the research report; preserved in [0003G3-SharedLeaveWideString-post-migration-removed.md](0003G3-SharedLeaveWideString-post-migration-removed.md)._

The raw operand inventory independently confirms the documented IDA xref set and shows no hidden table owner or extra source-use context for this physical string.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `SharedLeaveWideString` | Pooled UTF-16LE `Leave` label | TRUE | `NONE` | `89/94` | Keep no owner; add emitters `0000N0,0000OI` |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `SharedReconnectWideString` | Paired pooled UTF-16LE `Reconnect` label | TRUE | `NONE` | `89/94` | Same pattern; separate assignment |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed string tail map | FALSE | `NONE` | `89/93` | Correct non-emitting container |
| `0x00553c10-0x00553cbf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` | Reconnect/leave alert constructor variant | TRUE | `0000N0` route | child `82/86`; file `87/88` | ReconnectDialog emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J] `ConnectionClosedDialogMethods` | Alternate constructor/handlers | TRUE | class/file route to `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L] `ReconnectDialogMethods` | Reconnect button/timeout cluster | TRUE | class/file route to `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB] `TerminalPaneAndSetup` | Terminal pane setup and disconnect prompt | TRUE | `0000OI` | `85/86`; file `87/85` | TerminalPane emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Terminal reconnect/leave callback | TRUE | `0000OI` | `85/91` | Confirms terminal prompt route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` pushes `0x00622f1c`; sibling `Reconnect` pushed at `0x00553c44` | ConnectionClosedDialog constructor variant; ReconnectDialog source family |
| `0x00553cef` | `sub_553CC0` pushes `0x00622f1c`; sibling `Reconnect` pushed at `0x00553cf4` | Alternate ConnectionClosedDialog constructor/path; ReconnectDialog source family |
| `0x00554359` | `sub_554210` pushes `0x00622f1c`; sibling `Reconnect` pushed at `0x0055435e` | ReconnectDialog button path constructing replacement connection-closed prompt |
| `0x0058b56d` | `TerminalPane::OnDisconnect` stores `sub_58B620` as callback target | Terminal-specific prompt callback setup |
| `0x0058b5ac` | `TerminalPane::OnDisconnect` pushes `0x00622f1c`; sibling `Reconnect` pushed at `0x0058b5b1` | Independent TerminalPane reconnect/leave prompt use |
| `0x0058b620` | Callback dispatches reconnect vs leave behavior | Confirms TerminalPane's source-use semantics |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page: current bytes, false IDA names, exact four xrefs, and shared ReconnectDialog/TerminalPane source-family use are documented.
- B001 executed report: correctly rejects a single canonical owner, class owner, AlertPanes owner, containing map owner, and synthetic shared-label source file.
- `by-structure.md`: explicitly allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals when multiple source-use contexts are proven.
- `by-file/ReconnectDialog.md`: `UID 0000N0`, `87/88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, and current source file `network/ReconnectDialog.cpp`.
- `by-file/TerminalPane.md`: `UID 0000OI`, `87/85`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, and current source file `login/TerminalPane.cpp`.
- `by-file/AlertPanes.md`: establishes shared alert infrastructure but rejects feature-specific reconnect alerts as generic alert ownership without broader proof.

Existing docs that need updating:

- Target `EMITTER_UIDS:` is blank. That should become `0000N0,0000OI`.
- Target page and coverage row still use old "parent blank" language. That should be updated to "canonical owner none; routed through ReconnectDialog and TerminalPane emitters."
- Generated coverage currently lists 0003G3 as no-owner/non-emitting because the emitter route is blank.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` primary row currently shows:
  - status `no-owner`
  - owner `NONE`
  - blank emitters
  - no generated destination
- `by-memory/-coverage-report.md` current row says parent remains blank and does not mention emitter routing.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` plus emitters `0000N0,0000OI` - accepted

- Evidence for: exact pooled literal; four direct refs split across two valid source roots; no single owner-only xref set; current by-structure rule explicitly models this as no canonical owner but multiple emitters.
- Evidence against: no final source code is ready; original source might have duplicated literals or a local helper constant.
- Decision: accept. This is the correct post-migration representation.

### 2. `CANONICAL_OWNER:NONE` with blank emitters - rejected as final state

- Evidence for: this was valid while the old parent model had no safe way to route pooled strings and remains tolerable while research is unresolved.
- Evidence against: the output contexts are now proven, and by-structure says pooled strings that need to appear in multiple reconstructed source contexts should use multiple emitters once evidence is strong enough.
- Decision: reject as final recommendation. Blank emitters under-represent the item after this recheck.

### 3. Canonical owner [UID:0000N0] `ReconnectDialog` - rejected

- Evidence for: three of four direct xrefs are reconnect/connection-closed source-family code; [UID:0000N0] clears the source-root gate.
- Evidence against: `TerminalPane::OnDisconnect` directly pushes the same literal and constructs its own callback-backed prompt; xref count does not prove declaration ownership for a pooled literal.
- Decision: reject as canonical owner. Accept `0000N0` only as an emitter route.

### 4. Canonical owner [UID:0000OI] `TerminalPane` - rejected

- Evidence for: the terminal use is direct, and the callback page proves TerminalPane-specific reconnect/leave behavior.
- Evidence against: three reconnect/connection-closed refs are outside TerminalPane and are already documented under a separate source root.
- Decision: reject as canonical owner. Accept `0000OI` only as an emitter route.

### 5. [UID:0000HE] `AlertPanes` / `VersatileAlertPane` - rejected

- Evidence for: the terminal path uses `sub_4A0690`, a callback-backed alert constructor shape.
- Evidence against: `Leave` is feature-specific label data, not a generic alert-library declaration; AlertPanes docs explicitly keep reconnect alerts with feature modules; no broad alert fan-in or direct label ownership exists.
- Decision: reject as owner and emitter.

### 6. Class-level owners - rejected

- Evidence for: `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` classes each own part of the behavior.
- Evidence against: no class owns all refs; the literal is not a vtable, method body, class-static data object, or class-local table.
- Decision: reject as canonical owner. Use by-file emitters for the source-use contexts instead.

### 7. New shared-label owner/file - rejected

- Evidence for: `Leave` and `Reconnect` are paired labels, and sibling `baram` is also shared by reconnect/terminal code.
- Evidence against: no table, initializer, source/debug name, address-taken global, or coherent constants module is present. By-structure warns not to invent a standalone owner solely to avoid `NONE` for pooled/shared data.
- Decision: reject.

## Source-Use / Emitter Inventory

Emitter `0000N0` - [UID:0000N0] `by-file/ReconnectDialog.md`

- Route target: `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- Evidence: three exact `push 0x00622f1c` sites at `0x00553c3f`, `0x00553cef`, and `0x00554359` are in documented `ConnectionClosedDialog` / `ReconnectDialog` code.
- Why emitter not owner: the physical pooled literal also has a direct TerminalPane use, so ReconnectDialog cannot be the single semantic declaration owner.
- Decision: include.

Emitter `0000OI` - [UID:0000OI] `by-file/TerminalPane.md`

- Route target: `auto-generated/NexusTK/login/TerminalPane.cpp`.
- Evidence: `TerminalPane::OnDisconnect` pushes `0x00622f1c` at `0x0058b5ac` and installs the TerminalPane reconnect/leave callback at `0x0058b56d`; callback [UID:0001JD] dispatches reconnect vs leave behavior.
- Why emitter not owner: reconnect/connection-closed code has three direct uses outside TerminalPane.
- Decision: include.

Rejected emitter `0000HE` - [UID:0000HE] `by-file/AlertPanes.md`

- Evidence checked: alert constructor infrastructure is used, especially in the terminal path.
- Blocking fact: no direct source-use context for the `Leave` literal belongs to AlertPanes itself; feature modules provide the labels.
- Decision: do not include.

## Negative Evidence Summary

- No xrefs to interior `0x00622f20`; `aAve` is a false string start.
- No ASCII `Leave` spelling.
- No RVA-form references to the target.
- No hidden VA/push references beyond the four documented source-use sites.
- No table/global source object owns the pair.
- No PDB/source-path/debug metadata proves a declaration owner.
- The containing map [UID:0003CW] is a mixed non-emitting index, not a source owner.
- `AlertPanes` owns reusable alert classes, not feature-specific reconnect/terminal button labels.
- A new shared-label file would be speculative and contradicted by the current pooled-literal rule.

## Final Recommendation

Exact metadata/header changes recommended for `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not change `COMPLETION:89` or `CONFIDENCE:94`.

Do not add reconstruction C++:

- The target is not at `90/90+` completion/confidence because completion is `89`.
- The final call-site source spelling and callback/function bodies remain not source-final.
- The emitter route can be fixed now without committing final source code.

Recommended target-page wording update if a future documentation edit is applied:

```text
Routing: `CANONICAL_OWNER:NONE`; emitted through [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md). The physical UTF-16 `Leave` literal is pooled; no single declaration owner is proven, but direct xrefs prove source-use contexts in both source files.
```

Recommended `by-memory/-coverage-report.md` replacement row at the current 0003G3 child position under [UID:0003CW]:

```text
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; live IDA MCP and B003 raw PE scan confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

## Follow-Up Actions

- Supervisor or authorized documentation agent: update `EMITTER_UIDS` to `0000N0,0000OI` and refresh generated reports.
- Supervisor or authorized documentation agent: apply the coverage-row replacement above or regenerate a row reflecting the same route.
- Future B-agent consideration: sibling [UID:0003G4] `SharedReconnectWideString` has the same source-use shape and likely needs the same post-migration emitter route, but it is outside this one-target assignment.

## Confidence

- Recommendation confidence: 92/100.
- Score confidence: keep `89/94`; route evidence is strong, but completion should not be raised solely for emitter routing.
- Remaining uncertainty: stripped-binary evidence cannot prove whether the original source wrote two local `L"Leave"` literals, used a small local constant in one file, or relied on compiler pooling. That uncertainty blocks canonical ownership, but it does not block emitter routing because source-use sites are exact and independently verified.

## Validator Results

- Commands run: none.
- Result: no validator needed because no by-* files or coverage files were edited by B003.
- No dry-run modes were used.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0003G3-SharedLeaveWideString-post-migration.md`
- Modified: none outside Agent-B003 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B003/0003G3-SharedLeaveWideString-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
