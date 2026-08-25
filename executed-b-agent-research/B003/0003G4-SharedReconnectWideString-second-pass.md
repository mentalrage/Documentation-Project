** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Second-Pass Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Required action: no metadata, coverage-row, split, merge, reclassification, or IDA repair action is recommended.
- Score before/after: `89/94` before, `89/94` after.
- Confidence: high. The no-owner-with-emitters state is valid under the current owner/emitter model because direct evidence proves source-use contexts in [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), while no single semantic declaration owner is proven.

## Supporting Research

## Target

- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Assignment: `B003-0003G4-second-pass`.
- Current generated state: no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`; generated reports display the current output path as `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- Current page state: `COMPLETION:89`, `CONFIDENCE:94`, `RECONSTRUCTABLE:TRUE`, no reconstruction C++.
- Prior report reviewed as background: `tools/leaser/Agents/Agent-B001/research/executed/0003G4-SharedReconnectWideString-post-migration.md`.

## Executive Recommendation

Keep this item as a reconstructable pooled UTF-16 button label with no canonical owner and two emitter routes.

The physical bytes at `0x00622f28-0x00622f3c` represent UTF-16LE `Reconnect`. IDA-documented xrefs and a fresh PE scan show exactly four direct `push 0x00622f28` source-use sites:

| Source-use family | Addresses | Emitter |
| --- | --- | --- |
| ConnectionClosedDialog constructor variants | `0x00553c44`, `0x00553cf4` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| ReconnectDialog replacement connection-closed path | `0x0055435e` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) |
| TerminalPane disconnect prompt | `0x0058b5b1` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) |

Do not assign a canonical owner to `ReconnectDialog`, `ConnectionClosedDialog`, `TerminalPane`, `AlertPanes`, the physical string-tail map, or a newly invented shared-label owner. Each would overclaim the pooled literal. The source should eventually spell `L"Reconnect"` naturally at the proven call sites when those consumer method pages reach code-entry quality.

## Supervisor Active Recheck

- Trigger: second-pass audit of current no-owner-with-emitters state for `0003G4`.
- Split repair required: no. The target is an exact 20-byte UTF-16 string child. The containing [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) is already a non-emitting mixed container.
- Emitter repair required: no. The current emitters `0000N0,0000OI` are justified and should stay.
- Canonical owner repair required: no. The correct current state is still `CANONICAL_OWNER:NONE`.
- Coverage-report edit: not needed. `by-memory/-coverage-report.md` already has a current row reflecting the no-owner/two-emitter state.

## Inference Research Guidance Check

[by-structure.md](../../../../../by-structure.md) now separates semantic ownership from generated-output routing. It explicitly allows compiler/linker-pooled string literals to remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts. This is not the same as non-emitting.

[inference_research.md](../../../../../inference_research.md) cautions that `.rdata` adjacency and pooled strings are weak ownership evidence. This report therefore treats the nearby `Leave`, `No`, `Yes`, and `baram` strings as boundary/context evidence only. Ownership and routing are based on direct refs and documented call-site behavior.

Existing documentation was treated as evidence, not authority. The prior B001 report was rechecked against the current target page, source-root docs, consumer pages, generated rows, and fresh raw PE facts.

## Evidence Standards Used

- Live IDA MCP evidence collected on 2026-06-13 from `http://127.0.0.1:13337/mcp`: active database session `b001_0003gy`, exact bytes, xrefs, containing functions, decompilation summaries, callback construction, no interior refs, later-suffix negative evidence, and consumer source-family facts.
- Fresh PE evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, byte decoding, exact string occurrence counts, absolute VA/RVA scans, and target-range pointer scans.
- Documentation evidence: `by-structure.md`, `inference_research.md`, proposed source tree, target page, prior report, current generated rows, coverage row, and by-file/by-class/by-memory consumer pages.
- Negative evidence: no refs to false interior `0x00622f2c`, no target RVA refs, no refs to later `kServerReconnect` suffix, no common owner/helper/table, and no one consumer covering all four refs.

No IDB mutation was performed. One broad `search_text` query for `622F28` timed out, but the targeted `xrefs_to`, `lookup_funcs`, `get_bytes`, `get_string`, `find_bytes`, `entity_query`, `disasm`, and `analyze_function` calls below succeeded and cover the required checks.

## IDA MCP Facts

Live IDA MCP setup:

- `initialize` succeeded and reported `ida-pro-mcp` protocol `2025-06-18`.
- `tools/list` was rechecked before use. Current schemas require `database` arguments, and `decompile`/`disasm` use singular `addr`; calls were adapted to the live schema as required by [by-structure.md](../../../../../by-structure.md).
- `idb_list` reported one active session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, backend `worker`, `is_analyzing:false`.
- `server_health(database=b001_0003gy)` returned `status:ok`, `imagebase:0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

Target bytes and IDA string state:

- `get_bytes(0x00622f28, 20)` returned `52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00`.
- The bytes decode as UTF-16LE `Reconnect`.
- `get_string` returned narrow fragments (`R` at `0x00622f28`, `connect` at `0x00622f2c`, `k` at `0x006288a2`, and `R` at `0x006288b0`), confirming IDA's string typing is a tail artifact here. The byte decode, not the narrow string labels, is the authoritative text evidence.
- `entity_query(kind=names, 0x00622f1c-0x00622f54)` returned IDA names `aAve` at `0x00622f20`, `aConnect` at `0x00622f2c`, `aNo` at `0x00622f3c`, and `aBaram_0` at `0x00622f4c`. These are typing/name artifacts and adjacent child names, not source ownership evidence for `0003G4`.

Live `xrefs_to` and negative interior checks:

- `xrefs_to 0x00622f28` returned exactly four data refs:
  - `0x00553c44` in `sub_553C10` (`0x00553c10`, size `0xaf`), matching [UID:00023O][ConnectionClosedDialogConstructorVariant](../../../../../by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md).
  - `0x00553cf4` in `sub_553CC0` (`0x00553cc0`, size `0xae`), matching [UID:00038J][ConnectionClosedDialogMethods](../../../../../by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md).
  - `0x0055435e` in `sub_554210` (`0x00554210`, size `0x1f6`), matching [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md).
  - `0x0058b5b1` in `sub_58B470` (`0x0058b470`, size `0x170`), matching [UID:0001JB][TerminalPaneAndSetup](../../../../../by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md).
- `xrefs_to 0x00622f1c` returned the same four containing functions at `0x00553c3f`, `0x00553cef`, `0x00554359`, and `0x0058b5ac`, proving the `Leave`/`Reconnect` pair is consumed together at the prompt sites.
- `xrefs_to` for `0x00622f2c`, `0x00622f30`, `0x00622f34`, and `0x00622f38` each returned zero xrefs. This closes the false-interior `aConnect` and inside-target split lead.
- `xrefs_to` for `0x006288a2` and `0x006288b0` each returned zero xrefs. The later spelling is not a source-use or ownership route for this target.
- Adjacent successor checks stayed separate: `xrefs_to 0x00622f3c` and `0x00622f44` returned CopyWindow-related refs, and `xrefs_to 0x00622f4c` returned refs in `sub_554210` and `sub_58B130`; they do not merge into `0003G4`.

Live raw-pattern checks through IDA MCP:

- `find_bytes` for the UTF-16LE `Reconnect` byte sequence returned two spellings: `0x00622f28` and `0x006288b0`.
- `find_bytes` for little-endian absolute VA `28 2F 62 00` returned four operand-byte matches: `0x00553c45`, `0x00553cf5`, `0x0055435f`, and `0x0058b5b2`. These are the immediate operands of the four `push offset off_622F28` instructions at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.
- `find_bytes` for target RVA `28 2F 22 00`, interior VAs `2C/30/34/38 2F 62 00`, later `kServerReconnect` VA `A2 88 62 00`, and later suffix VA `B0 88 62 00` returned zero matches.

Containing function and consumer facts:

- `lookup_funcs` confirmed the four source-use addresses belong to `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`. `0x00622f28`, `0x00622f2c`, `0x006288a2`, and `0x006288b0` are not functions.
- `analyze_function 0x00553c10` decompiled `sub_553C10` as a constructor-like `ConnectionClosedDialog` setup that calls `sub_49FEB0(v2, dword_67A740, &off_622F28, &off_622F1C)`, then installs `ConnectionClosedDialog` vtables. This is a `ReconnectDialog.cpp`/connection-closed prompt source-use context.
- `analyze_function 0x00553cc0` decompiled `sub_553CC0` as the alternate constructor-like path calling `sub_49FEB0(v3, a2, &off_622F28, &off_622F1C)`, then installing `ConnectionClosedDialog` vtables. Its callers include `sub_4F6A60`, `sub_554210`, and `sub_554410`.
- `analyze_function 0x00554210` decompiled `sub_554210` with both the `baram` packet branch and the replacement connection-closed prompt branch; the prompt branch calls `sub_49FEB0(v8, v11, &off_622F28, &off_622F1C)` or reaches `sub_553CC0`. This supports [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) as an emitter, not as sole canonical owner.
- `analyze_function 0x0058b470` decompiled the terminal disconnect path as constructing a `PlainMemberFunctionObject<void (TerminalPane::*)(unsigned long),TerminalPane>`, setting its target to `sub_58B620`, then calling `sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C)`. This supports [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) as an independent emitter.
- `disasm 0x0058b620` confirmed the callback function is `sub_58B620` (`0x0058b620`, size `0x2f`); it branches on its argument and either calls `sub_5975E0` from a `TerminalPane` offset path or calls `sub_464E40` via `unk_67AB1C`. It is callback context, not the declaration owner for the pooled string.

## Fresh Raw PE Facts

Raw PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

```text
imagebase=0x00400000
target_section=.rdata
target_va=0x00622f28
target_rva=0x00222f28
target_file_offset=0x00221928
target_bytes=52 00 65 00 63 00 6F 00 6E 00 6E 00 65 00 63 00 74 00 00 00
```

String occurrence scan:

```text
UTF16_Reconnect_NUL_count=2
  0x00622f28
  0x006288b0
ASCII_Reconnect_NUL_count=0
UTF16_kServerReconnect_NUL_count=1
  0x006288a2
UTF16_Leave_NUL_count=1
  0x00622f1c
UTF16_No_NUL_count=1
  0x00622f3c
UTF16_Yes_NUL_count=1
  0x00622f44
```

Target absolute-VA refs:

```text
0x00553c44: push 0x00622f28
0x00553cf4: push 0x00622f28
0x0055435e: push 0x00622f28
0x0058b5b1: push 0x00622f28
```

Negative raw scans:

```text
TARGET_RVA_0x00222f28_hits=0
INTERIOR_0x00622f2c_hits=0
INTERIOR_0x00622f30_hits=0
INTERIOR_0x00622f34_hits=0
INTERIOR_0x00622f38_hits=0
KSERVER_RECONNECT_0x006288a2_hits=0
LATER_RECONNECT_SUFFIX_0x006288b0_hits=0
dword_values_pointing_inside_target_va_range=4
dword_values_pointing_inside_target_rva_range=0
```

Boundary/context bytes:

```text
0x00622f1c: 4C 00 65 00 61 00 76 00 65 00 00 00 52 00 65 00
0x00622f2c: 63 00 6F 00 6E 00 6E 00 65 00 63 00 74 00 00 00
0x00622f3c: 4E 00 6F 00 00 00 00 00 59 00 65 00 73 00 00 00
0x00622f4c: 62 61 72 61 6D 00 00 00 BC EB 64 00 00 4B 55 00
```

The successor `No`, `Yes`, and `baram` references belong to separate child pages, confirming no split/merge is needed for `0003G4`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Non-emitting mixed string-tail map | `FALSE` | `NONE` | `89/93` | Keep as container. |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](../../../../../by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | Shared `Leave` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Sibling precedent; no change. |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | Shared `Reconnect` prompt label | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/94` | Current target; keep unchanged. |
| `0x00622f3c-0x00622f44` | [UID:0003G5][CopyWindowNoButtonWideString](../../../../../by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | CopyWindow `No` label | `TRUE` | CopyWindow class/file route | current docs | Separate successor. |
| `0x00622f44-0x00622f4c` | [UID:0003G6][CopyWindowYesButtonWideString](../../../../../by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | CopyWindow `Yes` label | `TRUE` | CopyWindow class/file route | current docs | Separate successor. |
| `0x00622f4c-0x00622f54` | [UID:0003G7][SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | Shared `baram` packet literal | `TRUE` | `NONE`; emitters `0000N0,0000OI` | `89/93` | Sibling precedent; no change. |
| `0x006288a2` | no target child in this assignment | UTF-16LE `kServerReconnect` | unknown | no refs | not scored | Negative context only. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c44` | `push 0x00622f28` in `ConnectionClosedDialog` constructor variant | ReconnectDialog file-root source use. |
| `0x00553cf4` | `push 0x00622f28` in alternate `ConnectionClosedDialog` constructor path | ReconnectDialog file-root source use. |
| `0x0055435e` | `push 0x00622f28` in `ReconnectDialog::OnButtonClick` replacement-alert path | ReconnectDialog file-root source use. |
| `0x0058b5b1` | `push 0x00622f28` in `TerminalPane::OnDisconnect` | TerminalPane file-root source use. |
| `0x00622f2c` | zero VA/RVA refs | False `aConnect` suffix is not a separate child/owner. |
| `0x006288a2`, `0x006288b0` | zero VA/RVA refs | Later `kServerReconnect` occurrence is not a source-use route for this target. |

## Documentation Evidence And IDA Status

Supporting docs:

- Target page records exact bytes, four IDA xrefs, the false `aConnect` artifact, prior PE audits, the no-owner decision, and current `EMITTER_UIDS:0000N0,0000OI`.
- [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) is `87/88`, has `CANONICAL_OWNER:FILE`, and routes to `NexusTK/network/`. It owns the ConnectionClosedDialog/ReconnectDialog source family and singleton globals.
- [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) is `87/85`, has `CANONICAL_OWNER:FILE`, and routes to `NexusTK/login/`. It owns the pre-login terminal disconnect/reconnect prompt and callback.
- [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md) keeps feature-specific reconnect alerts with [UID:0000N0], rejecting generic alert ownership for this label.
- [UID:0001JD][TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) records the callback construction and prompt-label pushes from `TerminalPane::OnDisconnect`.
- Current generated and coverage rows already list `0003G4` as no-owner with emitters `0000N0,0000OI`.

No stale documentation requiring action was found for this target. The only historical mismatch is in the prior report text, which describes changing blank emitters to `0000N0,0000OI`; that recommendation has already been applied.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI`

Evidence for:

- Matches `by-structure.md` for pooled/shared literals with no proven single declaration owner.
- Direct code refs prove both ReconnectDialog-family and TerminalPane source-use contexts.
- Both file roots clear the 85/85 route gate and have valid source paths.
- Fresh PE scan confirms exactly four target immediates and no hidden refs to suffixes, RVAs, or the later spelling.
- Sibling pages `0003G3` and `0003G7` now use the same no-owner/two-emitter model for the same feature boundary.

Evidence against:

- Original source could have used an unrecovered shared macro/header constant. No binary or documentation evidence currently proves that source shape.

Decision: accepted.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner

Evidence for:

- Three of four direct uses are in ConnectionClosedDialog/ReconnectDialog code.
- The label is semantically central to reconnect/connection-closed UI.
- `ReconnectDialog` owns the connection/reconnect singleton globals and the active reconnect flow.

Evidence against:

- `TerminalPane::OnDisconnect` directly uses the same physical label in a terminal-owned callback prompt.
- No IDA-documented helper or shared declaration owned by `ReconnectDialog` is used by TerminalPane for this label.
- Choosing ReconnectDialog as canonical owner would force ownership to the majority consumer.

Decision: rejected as canonical owner; retained as emitter `0000N0`.

### 3. [UID:0000OI] `TerminalPane` as canonical owner

Evidence for:

- TerminalPane has one direct, material source-use site at `0x0058b5b1`.
- The target participates in a terminal-owned reconnect/leave callback prompt.

Evidence against:

- Three direct refs are outside TerminalPane in connection/reconnect dialog code.
- TerminalPane is a consumer of the pooled label, not a declaration owner for the ReconnectDialog-family call sites.

Decision: rejected as canonical owner; retained as emitter `0000OI`.

### 4. Class-level owners [UID:000036], [UID:0000BR], or [UID:0000EG]

Evidence for:

- Each class owns specific method bodies that use or are adjacent to the label.

Evidence against:

- No single class covers all four refs.
- `EMITTER_UIDS` should route output to source roots for this pooled literal. File roots are clearer because the label is shared across two classes inside `ReconnectDialog.cpp` plus TerminalPane.

Decision: rejected for canonical ownership and not used as emitters.

### 5. [UID:0000HE] `AlertPanes`

Evidence for:

- All call sites use alert/dialog construction infrastructure.

Evidence against:

- `AlertPanes.md` explicitly keeps feature-specific reconnect alerts with their feature modules.
- The label text is feature-specific, not generic alert infrastructure.
- No common generic alert label table or declaration is documented.

Decision: rejected.

### 6. New shared label/source owner

Evidence for:

- `Leave` and `Reconnect` are paired at four prompt sites.
- A source header or macro could have defined shared button labels.

Evidence against:

- No pointer table, static object, source-file cluster, debug/source breadcrumb, or additional label group proves such an owner.
- Ordinary string pooling fully explains one physical address used by independent source contexts.
- Inventing a new owner would add unsupported source structure.

Decision: rejected for current action.

### 7. Reclassify as non-reconstructable/non-emitting

Evidence for:

- None.

Evidence against:

- The literal is source-authored UI text and has live source-use contexts.
- Current emitters are proven. This is not a dead/non-emitting reconstructable item.

Decision: rejected.

## Negative Evidence Summary

- No refs to false interior `aConnect` at `0x00622f2c`.
- No RVA-form refs to `0x00222f28`.
- No refs to interior addresses `0x00622f30`, `0x00622f34`, or `0x00622f38`.
- No refs to the later `kServerReconnect` start `0x006288a2` or its `Reconnect` suffix `0x006288b0`.
- No ASCII `Reconnect` spelling in the raw PE.
- No common helper or declaration owner that spans ReconnectDialog-family and TerminalPane source-use sites.
- No boundary issue: successor `No`, `Yes`, and `baram` children have their own refs and ownership/routing decisions.

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

Retain current `by-memory/-coverage-report.md` row:

```text
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very-strong : UTF-16LE `Reconnect` pooled button-label literal; B001-0003G4 post-migration recheck keeps `CANONICAL_OWNER:NONE` because ReconnectDialog, TerminalPane, AlertPanes, class-level parents, and a speculative shared-label owner each overclaim declaration ownership, but recommends `EMITTER_UIDS:0000N0,0000OI` because live IDA/PE evidence proves source-use contexts in `ReconnectDialog.cpp` / `ConnectionClosedDialog` prompt construction (`0x00553c44`, `0x00553cf4`, `0x0055435e`) and `TerminalPane::OnDisconnect` (`0x0058b5b1`); exact target bytes and four absolute target-VA immediates are confirmed, no refs target false interior `aConnect` at `0x00622f2c`, and the later `0x006288b0` spelling is only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`.
```

## Follow-Up Actions

- Supervisor actions: none required for this target.
- A-agent actions: none required for this target.
- Future research: if future source/debug/map evidence proves a real shared label header or constants module, revisit canonical ownership for the `Leave`/`Reconnect` pair. Current binary evidence does not justify that owner.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: keep `89/94`.
- Remaining uncertainty: original spelling form. The source may have repeated local `L"Reconnect"` literals, or it may have used an unrecovered shared constant/macro. This does not change the correct current metadata because the physical pooled literal has no proven declaration owner and the two output routes are proven.

## Validator Results

- Validator not run. No by-* files were edited and the final recommendation is no change.
- Live IDA MCP verification was run against active session `b001_0003gy` on `NexusTK.exe`; only inspection tools were used.
- Git status could not be used because no `.git` metadata is visible from `E:\NTK\GhidraBridge` or `E:\NTK\GhidraBridge\source-3`; file-level checks were used instead.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B003/research/0003G4-SharedReconnectWideString-second-pass.md`.
- Modified: none outside Agent-B003 research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B003/0003G4-SharedReconnectWideString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
