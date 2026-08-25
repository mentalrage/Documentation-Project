** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Required action: no metadata edit, no coverage-row edit, no split, no merge, no reclassification, no parent/source repair, and no IDA repair.
- Score before/after: `89/94` before, `89/94` after.
- Confidence: high. This is the correct no-owner-with-emitters representation for a compiler/linker-pooled source literal with direct source-use evidence in [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), but no proven single declaration owner.

This is not a non-emitting no-owner defect. The current `CANONICAL_OWNER:NONE` remains correct because no one source owner covers all direct uses, while the current emitters are required because both source roots contain exact use sites.

## Supporting Research

## Target

- Target UID: `0003G3`.
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`.
- Assigned report path: `tools/leaser/Agents/Agent-B002/research/0003G3-SharedLeaveWideString-post-migration-recheck.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner row for `0003G3`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row for `0003G3`.
- Current page state: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`.
- Prior reports reviewed as background: `Agent-B003/research/executed/0003G3-SharedLeaveWideString-post-migration.md` and `Agent-B001/research/executed/0003G3-SharedLeaveWideString-second-pass.md`.

## Executive Recommendation

Keep UID `0003G3` as an exact reconstructable UTF-16LE `Leave` button-label literal, emitted through both proven source-use roots:

| Source-use family | Direct refs | Emitter |
| --- | --- | --- |
| `ConnectionClosedDialog` constructor variants | `0x00553c3f`, `0x00553cef` | `0000N0` ReconnectDialog |
| `ReconnectDialog::OnButtonClick` replacement connection-closed path | `0x00554359` | `0000N0` ReconnectDialog |
| `TerminalPane::OnDisconnect` reconnect/leave prompt | `0x0058b5ac` | `0000OI` TerminalPane |

Do not assign a canonical owner to `ReconnectDialog`, `ConnectionClosedDialog`, `TerminalPane`, `AlertPanes`, the mixed string-tail map, or a new shared-label source file. Each single-owner option overclaims a pooled literal that is materially used in more than one source root.

Do not add reconstruction C++. The page is `89/94`, so it is below the active `90/90+` code-entry bar on completion. More importantly, final source should spell the label at the consumer call sites once those method bodies reach source-output quality, not as a standalone address-backed declaration on this data page.

## Supervisor Active Recheck

- Trigger: Goal 2 one-target no-owner memory recheck for `0003G3`.
- Split repair required: no. The target is already an exact `0x0c`-byte `Leave` child and has no interior refs.
- Emitter repair required: no. Both current emitters are still exact and defensible.
- Canonical owner repair required: no. `CANONICAL_OWNER:NONE` remains the strict result.
- Coverage-report edit required: no. Current generated and coverage rows already reflect the no-owner/two-emitter state.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from generated-output routing. It explicitly allows pooled/shared source data to remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while `EMITTER_UIDS` route output through every proven source-use context. That rule is the controlling model here.

`inference_research.md` warns that nearby `.rdata` strings and linker string pooling are not source-file proof. This report treats the adjacent `Reconnect`, `No`, `Yes`, and `baram` strings as boundary/context evidence only. The owner/emitter decision is based on direct xrefs, containing functions, current source-root docs, and negative raw evidence.

Existing documentation was treated as a lead, not authority. The prior B003 and B001 conclusions match the current evidence, but this report refreshed the direct IDA xrefs and raw executable scan independently.

## Evidence Standards Used

- IDA MCP: active database discovery, server health, function lookup, and xrefs to the target, interior offsets, sibling literals, alert constructors, and TerminalPane callback.
- Raw PE scan: exact bytes, exact UTF-16/ASCII string occurrence counts, absolute VA operand hits, push-immediate classification, RVA negative check, interior negative check, and end-boundary negative check.
- Documentation evidence: target page, mixed parent, paired sibling, ReconnectDialog/TerminalPane/AlertPanes file pages, ConnectionClosedDialog/TerminalPane class pages, xref-owner child pages, generated coverage, coverage report, tracker, prior executed reports, `by-structure.md`, `inference_research.md`, and proposed source tree.
- Negative evidence: no interior `0x00622f20`/`0x00622f24` refs, no target RVA refs, no end-boundary refs, no extra source-use operands, no ASCII `Leave`, no common helper/table/global, no AlertPanes-owned literal, and no source/debug breadcrumb proving a shared declaration.

## IDA MCP Facts

Live session:

```text
database: b001_0003gy
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x00400000
auto-analysis: ready
Hex-Rays: ready
```

### Function Lookup

| Address | IDA function result | Meaning |
| --- | --- | --- |
| `0x00553c10` / `0x00553c3f` | `sub_553C10`, size `0xaf` | ConnectionClosedDialog constructor variant; ReconnectDialog file route |
| `0x00553cc0` / `0x00553cef` | `sub_553CC0`, size `0xae` | alternate ConnectionClosedDialog constructor/path; ReconnectDialog file route |
| `0x00554210` / `0x00554359` | `sub_554210`, size `0x1f6` | ReconnectDialog button path; ReconnectDialog file route |
| `0x0058b470` / `0x0058b5ac` | `sub_58B470`, size `0x170` | TerminalPane disconnect prompt; TerminalPane file route |
| `0x0058b620` | `sub_58B620`, size `0x2f` | TerminalPane reconnect/leave callback target |
| `0x004a0690` | `sub_4A0690`, size `0x47` | callback-backed alert wrapper; infrastructure, not label owner |
| `0x0049feb0` | `sub_49FEB0`, size `0x6c5` | shared AlertPane initializer; infrastructure, not label owner |
| `0x00622f1c`, `0x00622f20`, `0x00622f28`, `0x00622f54` | not functions | `.rdata` string island |

### Xrefs

IDA MCP `xrefs_to(0x00622f1c)` returns exactly four direct data xrefs:

| Xref | IDA function | Source-use decision |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` | ReconnectDialog emitter |
| `0x00553cef` | `sub_553CC0` | ReconnectDialog emitter |
| `0x00554359` | `sub_554210` | ReconnectDialog emitter |
| `0x0058b5ac` | `sub_58B470` | TerminalPane emitter |

Sibling and boundary xrefs:

| Address | IDA xrefs | Meaning |
| --- | --- | --- |
| `0x00622f20` | 0 | false interior `aAve`/suffix is not a child |
| `0x00622f24` | 0 | no tail/interior ref |
| `0x00622f28` | four refs at `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` | paired `Reconnect` literal uses match `Leave` |
| `0x00622f2c` | 0 | false `connect` suffix is not an owner/split lead |
| `0x00622f3c` | two refs | separate CopyWindow `No` child |
| `0x00622f44` | two refs | separate CopyWindow `Yes` child |
| `0x00622f4c` | two refs at `0x00554276`, `0x0058b3fc` | separate shared `baram` child |
| `0x00622f54` | 0 | clean successor boundary |
| `0x004a0690` | two code refs, including `0x0058b5c5` | TerminalPane uses alert wrapper; wrapper does not own labels |
| `0x0049feb0` | 96 code refs | broad shared alert infrastructure, not feature-label ownership |
| `0x0058b620` | one data xref at `0x0058b56d` | TerminalPane callback object target |

Optional IDA MCP `search_text`, `trace_data_flow`, `decompile`, and `disasm` calls were attempted after the successful xref/function pass but returned `ida mcp offline`. I did not use those failed calls as evidence. The successful IDA xrefs/function lookups and the raw executable scan are sufficient for this ownership/emitter decision.

## Raw PE Facts

Executable scanned:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
Image base: 0x00400000
Target VA: 0x00622f1c
Target file offset: 0x22191c
Target section: .rdata
```

Target bytes:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
```

Decoded surrounding island `0x00622f1c-0x00622f54`:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

Raw scan results:

| Pattern/check | Count | Hits |
| --- | ---: | --- |
| UTF-16LE `Leave\0` | 1 | `0x00622f1c` |
| UTF-16LE `Leave` without terminator | 1 | `0x00622f1c` |
| ASCII `Leave\0` | 0 | none |
| target VA `0x00622f1c` as dword | 4 | operands at `0x00553c40`, `0x00553cf0`, `0x0055435a`, `0x0058b5ad` |
| `push 0x00622f1c` | 4 | instructions at `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` |
| interior VA `0x00622f20` | 0 | none |
| interior VA `0x00622f24` | 0 | none |
| target RVA `0x00222f1c` | 0 | none |
| end boundary `0x00622f54` | 0 | none |
| sibling VA `0x00622f28` | 4 | paired `Reconnect` operands at `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| UTF-16LE `Reconnect\0` | 2 | `0x00622f28`, separate later spelling `0x006288b0` |
| ASCII `Reconnect\0` | 0 | none |

Raw evidence independently confirms the exact IDA xref set and finds no hidden source-use route, pointer table, RVA-form owner, or interior split candidate.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner / emitter | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | pooled UTF-16LE `Leave` label | TRUE | owner `NONE`; emitters `0000N0,0000OI` | `89/94` | keep unchanged |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | paired pooled UTF-16LE `Reconnect` label | TRUE | owner `NONE`; emitters `0000N0,0000OI` | `89/94` | sibling confirms same prompt pair |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | mixed string-tail index | FALSE | none | `89/93` | keep non-emitting container |
| `0x00553c10-0x00553cbf` | [UID:00023O][ConnectionClosedDialogConstructorVariant](../../../../../by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | constructor variant using label pair | TRUE | `0000N0` route | `82/86` | ReconnectDialog emitter evidence |
| `0x00553cc0-0x00553e5b` | [UID:00038J][ConnectionClosedDialogMethods](../../../../../by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | alternate constructor/handlers | TRUE | class `000036`, emitter chain to `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x00553f40-0x005544b8` | [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | reconnect button/timeout cluster | TRUE | class `0000BR`, emitter chain to `0000N0` | `86/89` | ReconnectDialog emitter evidence |
| `0x0058af50-0x0058c350` | [UID:0001JB][TerminalPaneAndSetup](../../../../../by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) | terminal setup/disconnect prompt block | TRUE | `0000OI` | `85/86` | TerminalPane emitter evidence |
| `0x0058b620-0x0058b64f` | [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) | reconnect/leave callback installed by TerminalPane | TRUE | `0000OI` | `85/91` | confirms terminal prompt route |

## Documentation Evidence And IDA Status

- Target page: documents the exact bytes, four source-use xrefs, false interior IDA names, no canonical owner, and current two-emitter route. Fresh IDA/raw evidence confirms it.
- Parent [UID:0003CW] `ReconnectTerminalCopyStringTailMap`: documents the mixed `Leave`/`Reconnect`/`No`/`Yes`/`baram` island and exact child split. Fresh IDA/raw evidence confirms no target split or parent merge is needed.
- [UID:0000N0] `ReconnectDialog`: file root `NexusTK/network/ReconnectDialog.cpp`, `87/88`, owns connection-closed/reconnect dialog code and is a valid emitter for the first three target xrefs. IDA confirms those xrefs are in reconnect/connection-closed functions.
- [UID:0000OI] `TerminalPane`: file root `NexusTK/login/TerminalPane.cpp`, `87/85`, owns TerminalPane disconnect/callback flow and is a valid emitter for the fourth target xref. IDA confirms that xref is in `sub_58B470` and the callback target is stored at `0x0058b56d`.
- [UID:0000HE] `AlertPanes`: owns shared alert infrastructure, not feature-specific reconnect/terminal labels. IDA confirms alert constructors are infrastructure fan-in: `sub_49FEB0` has broad xrefs, and `sub_4A0690` forwards caller-supplied labels.
- Proposed source tree: places `TerminalPane.cpp` under `login/`, `ReconnectDialog.cpp` under `network/`, and `AlertPanes.cpp` under `ui/dialogs/`; it explicitly keeps feature-specific reconnect alerts out of generic AlertPanes unless later evidence proves otherwise.
- Generated state: `auto-generated/-ag-memory-coverage.md` lists `0003G3` as no-owner with owner `NONE`, emitters `0000N0`,`0000OI`, and current generated display path `auto-generated/NexusTK/network/ReconnectDialog.cpp`. The explicit emitter field is the authoritative multi-route state.
- Coverage report: the current child row under [UID:0003CW] already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, the four source-use refs, and rejected canonical owners.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` - accepted

Evidence for:

- Matches `by-structure.md` for pooled/shared literals with no single proven declaration owner.
- IDA xrefs prove exactly four direct uses split across ReconnectDialog-family code and TerminalPane code.
- Raw PE scan confirms no hidden refs, no target RVA refs, and no interior refs.
- Both emitter roots clear the file-root gate and have valid reconstruction paths.
- The paired `Reconnect` sibling has the same four-site prompt-pair shape.

Evidence against:

- The stripped binary cannot prove whether original source used repeated local string literals, a macro, or a private shared constant.

Decision: accept. That uncertainty blocks canonical ownership but not emitter routing.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner - rejected

Evidence for:

- Three of four xrefs are in connection-closed/reconnect dialog code.
- The literal is semantically central to reconnect/leave prompt text.
- `ReconnectDialog.md` owns the relevant connection-loss class family.

Evidence against:

- `TerminalPane::OnDisconnect` directly pushes the same physical string at `0x0058b5ac`.
- No IDA evidence shows TerminalPane delegates the literal declaration to ReconnectDialog.
- By-structure warns against forcing ownership to the consumer with the most xrefs when other consumers materially use the pooled item.

Decision: reject as canonical owner; keep as emitter `0000N0`.

### 3. [UID:0000OI] `TerminalPane` as canonical owner - rejected

Evidence for:

- TerminalPane has a direct source-use site and owns the callback-backed reconnect/leave flow around it.

Evidence against:

- Three direct xrefs are outside TerminalPane.
- TerminalPane is a material source-use context, not the single declaration owner for the reconnect/connection-closed call sites.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### 4. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG] - rejected

Evidence for:

- These classes own method bodies around the xref sites.

Evidence against:

- No one class covers all direct refs.
- The literal is pooled string data, not a vtable, class member, or class-static data object.
- The reconnect-side refs span more than one class in the same source file, making file-level output routing the correct emitter representation.

Decision: reject for canonical ownership and do not change emitters to class UIDs.

### 5. [UID:0000HE] `AlertPanes` / reusable alert infrastructure - rejected

Evidence for:

- The call sites invoke alert construction helpers, and TerminalPane uses the callback-backed `sub_4A0690` wrapper.

Evidence against:

- `Leave` is feature-specific prompt text supplied by callers, not alert-library-owned data.
- IDA shows `sub_4A0690` and `sub_49FEB0` are broad alert infrastructure; they do not own the literal.
- AlertPanes documentation and proposed source-tree guidance keep reconnect/connection alerts with feature modules.

Decision: reject as owner and emitter.

### 6. New shared-label source owner - rejected

Evidence for:

- `Leave` and `Reconnect` are paired labels at four prompt sites.

Evidence against:

- No source/debug metadata, initializer, table, global declaration, address-taken object, or coherent constants module exists.
- Literal pooling fully explains one physical address reused by independent source contexts.
- Creating a new owner solely to avoid `NONE` would violate the pooled-literal rule.

Decision: reject. Do not create a new file/grouping.

### 7. Reclassify as non-reconstructable/non-emitting - rejected

Evidence for:

- None.

Evidence against:

- The bytes are source-authored UI label text and have exact source-use contexts.
- Current emitters are proven.

Decision: reject.

## Split / Merge / IDA Repair Decision

No split is required:

- The target is exactly `L"Leave"` plus terminator in `0x00622f1c-0x00622f28`.
- IDA and raw scans show no refs to `0x00622f20` or `0x00622f24`.
- The successor at `0x00622f28` is already split as `SharedReconnectWideString`.

No merge is required:

- The parent is a mixed non-emitting string-tail map with children that have different owners/routes.
- Merging would hide the route distinction between shared reconnect/terminal labels and CopyWindow-only labels.

No IDA repair is required:

- The false interior/suffix labels are already documented.
- Function boundaries and xrefs are sufficient for routing.
- IDA-side renaming is not needed to make this documentation decision.

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

No `by-memory/-coverage-report.md` replacement is needed. Retain the current row:

```text
            - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000N0,0000OI; B003 post-migration and B001 second-pass reviews confirm exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at `0x00622f20`, no target RVA refs, and exactly four source-use refs paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md) are emitters only, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, the mixed map, and a new shared-label owner are rejected as canonical owners.
```

Retain the current generated no-owner row:

```markdown
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` |  |
```

## Follow-Up Actions

- Supervisor actions: none required for this target.
- A-agent actions: none required for this target.
- Future research: revisit only if new PDB/map/source evidence proves a real shared label declaration or constants module. Current binary evidence supports no-owner multi-emitter routing.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: keep `89/94`.
- Remaining uncertainty: the stripped binary cannot prove whether original source used two local `L"Leave"` literals, a macro, or a private shared constant. That uncertainty is the reason for `CANONICAL_OWNER:NONE`; it does not weaken the emitter route because the source-use sites are exact.

## Validator Results

- Validator not run. No by-* files or coverage files were edited, and the final recommendation is no change.
- No dry-run validator mode was used.
- No memory-range validator mode was used.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003G3-SharedLeaveWideString-post-migration-recheck.md`.
- Modified: none outside Agent-B002 research.
- Renamed: none.
- Moved to executed: none.

## Blockers

None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B002/0003G3-SharedLeaveWideString-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
