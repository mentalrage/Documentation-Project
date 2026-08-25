** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `RECONSTRUCTION_CPP`.
- Required action: no by-* edit, no `by-memory/-coverage-report.md` edit, no split, no merge, no reclassification, no IDA-safe-name repair.
- Confidence: high. Current IDA MCP and raw PE evidence reconfirm exact bytes, the four source-use refs, the paired `Leave` refs, the false-interior negative refs, and the unreferenced later `kServerReconnect` suffix.
- Scores: unchanged. Before `89/94`; after `89/94`.
- C++ gate: minimum gate is met (`RECONSTRUCTABLE:TRUE`, confirmed nonblank emitters, valid generated file roots, `(89 + 94) / 2 = 91.5 > 85`), but this pass should not enter or recommend standalone C++. The safe final source placement is `L"Reconnect"` at the future reconstructed ReconnectDialog/ConnectionClosedDialog and TerminalPane use sites unless source/debug evidence later proves a named shared declaration.

This is a correct no-owner pooled UTF-16 button-label literal. It is not non-emitting: it must route through both proven source-use file roots.

## Supporting Research

## Target

- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Target range: `0x00622f28-0x00622f3c`.
- Target size: `0x14` bytes.
- Entity kind: `string-data`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, current 2026-06-14 no-owner sweep row assigning `0003G4` to Agent-B001.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B003/research/executed/0003G4-SharedReconnectWideString-current-no-owner-research.md`.
- Current generated state: no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`.

Current target header:

```text
*** UID:0003G4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Executive Recommendation

Keep `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI`.

The target is UTF-16LE `Reconnect`. Current IDA shows three source-use refs in the `ReconnectDialog`/`ConnectionClosedDialog` source family and one source-use ref in `TerminalPane::OnDisconnect`. Both families are valid emitters. Neither family owns all observed uses, and no third shared declaration/source owner is proven.

## Supervisor Active Recheck

The active assignment requested a fresh Goal 2 no-owner ownership/emitter review for a reconstructable no-owner item with multiple emitters:

```text
[UID:0003G4] by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md
Current state: CANONICAL_OWNER:NONE, EMITTER_UIDS:0000N0,0000OI
```

No split repair was needed. The target is already one exact string child under the mixed [UID:0003CW] `ReconnectTerminalCopyStringTailMap`. Current bytes and xrefs confirm the existing range.

## Inference Research Guidance Check

`by-structure.md` was applied as follows:

- `CANONICAL_OWNER` is the semantic declaration/source owner, not merely the generated output path or the consumer with the most xrefs.
- `EMITTER_UIDS` is source-output routing. Multiple emitters are valid when the target has no defensible single canonical owner but has multiple proven source-use contexts.
- Pooled string literals may remain `CANONICAL_OWNER:NONE` with multiple emitters.
- C++ entry requires `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitters that surface to valid generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`; that is minimum eligibility, not permission to add weak standalone code.

`inference_research.md` was applied by treating final `.rdata` adjacency and string pooling as evidence requiring xref and negative-evidence validation, not as proof of one source file or shared constants module.

## Evidence Standards Used

Evidence checked:

- Current target page and current generated memory coverage rows.
- Current `by-memory/-coverage-report.md` row.
- Emitter file docs: [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane`.
- Rejected shared framework candidate: [UID:0000HE] `AlertPanes`.
- Current containing map and sibling pages: `SharedLeaveWideString`, `CopyWindowNoButtonWideString`, `CopyWindowYesButtonWideString`, and `SharedBaramPacketLiteral`.
- Live IDA MCP: bytes, xrefs, function lookup, decompilation, and component analysis.
- Raw PE scan: target bytes, literal occurrence counts, absolute immediate/reference patterns, RVA references, false-interior references, later-string references, and debug/source metadata strings.

The evidence is strong because IDA xrefs, decompiler call sites, component analysis, and raw PE reference scans all agree on the same four target-address uses.

## IDA MCP Facts

Live database/session:

- Session: `b001_0002bd`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Status: active worker; analysis not running.

### Bytes

`get_bytes 0x00622f1c size 0x48` returned the current tail:

```text
0x00622f1c: 4c 00 65 00 61 00 76 00 65 00 00 00
0x00622f28: 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
0x00622f3c: 4e 00 6f 00 00 00 00 00
0x00622f44: 59 00 65 00 73 00 00 00
0x00622f4c: 62 61 72 61 6d 00 00 00
```

Decoded:

```text
0x00622f1c: UTF-16LE "Leave"
0x00622f28: UTF-16LE "Reconnect"
0x00622f3c: UTF-16LE "No" plus alignment
0x00622f44: UTF-16LE "Yes"
0x00622f4c: ANSI "baram" plus alignment
```

`get_bytes 0x006288a2 size 0x40` returned UTF-16LE `kServerReconnect` at `0x006288a2`; the `Reconnect` suffix begins at `0x006288b0`. This is a separate storage occurrence and has no refs.

### Xrefs

Target refs:

| Target address | Xref | Function | Meaning |
| --- | --- | --- | --- |
| `0x00622f28` | `0x00553c44` | `sub_553C10` | ConnectionClosedDialog constructor variant passes `Reconnect`. |
| `0x00622f28` | `0x00553cf4` | `sub_553CC0` | Alternate ConnectionClosedDialog constructor path passes `Reconnect`. |
| `0x00622f28` | `0x0055435e` | `sub_554210` | ReconnectDialog button handler creates a replacement prompt using `Reconnect`. |
| `0x00622f28` | `0x0058b5b1` | `sub_58B470` | TerminalPane disconnect path passes `Reconnect`. |

Paired `Leave` refs:

| Target address | Xref | Function |
| --- | --- | --- |
| `0x00622f1c` | `0x00553c3f` | `sub_553C10` |
| `0x00622f1c` | `0x00553cef` | `sub_553CC0` |
| `0x00622f1c` | `0x00554359` | `sub_554210` |
| `0x00622f1c` | `0x0058b5ac` | `sub_58B470` |

Negative/interior refs:

```text
xrefs_to 0x00622f2c: 0
xrefs_to 0x00622f30: 0
xrefs_to 0x00622f34: 0
xrefs_to 0x00622f38: 0
xrefs_to 0x006288a2: 0
xrefs_to 0x006288b0: 0
```

Sibling refs:

```text
xrefs_to 0x00622f3c ("No"): 0x00553ebb, 0x005544c5
xrefs_to 0x00622f44 ("Yes"): 0x00553ec0, 0x005544ca
xrefs_to 0x00622f4c ("baram"): 0x00554276, 0x0058b3fc
```

The sibling refs support the existing split: `No`/`Yes` belong to CopyWindow paths, while `baram` is a separate reconnect/terminal packet literal.

### Function Lookup

| Query | IDA function result |
| --- | --- |
| `0x00553c10`, `0x00553c44` | `sub_553C10`, size `0xaf` |
| `0x00553cc0`, `0x00553cf4` | `sub_553CC0`, size `0xae` |
| `0x00554210`, `0x0055435e` | `sub_554210`, size `0x1f6` |
| `0x0058b470`, `0x0058b5b1` | `sub_58B470`, size `0x170` |
| `0x0058b620` | `sub_58B620`, size `0x2f` |
| `0x00622f28`, `0x00622f2c`, `0x006288a2`, `0x006288b0` | not functions |

### Decompiler Evidence

ReconnectDialog/ConnectionClosedDialog source-use sites:

```text
sub_553C10:
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C); /*0x553c5c*/

sub_553CC0:
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C); /*0x553d09*/

sub_554210:
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C); /*0x554376*/
```

TerminalPane source-use site:

```text
sub_58B470:
v10[2] = sub_58B620; /*0x58b56d*/
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/
```

The callback:

```text
sub_58B620:
if ( a1 )
  return sub_5975E0(0, 0, 0, 0);
else
  return sub_464E40();
```

This confirms `TerminalPane` is not merely adjacent; it creates a TerminalPane callback object and passes the shared label pair into a callback-backed alert wrapper.

### Component Analysis

`analyze_component` over the four source-use functions plus alert constructors reports shared globals:

```text
0x622f1c off_622F1C accessed_by sub_553C10, sub_553CC0, sub_554210, sub_58B470
0x622f28 off_622F28 accessed_by sub_553C10, sub_553CC0, sub_554210, sub_58B470
```

It also shows `sub_58B470 -> sub_4A0690 -> sub_49FEB0`, while the three reconnect/connection-closed sites call `sub_49FEB0` directly. This supports source-use routing through ReconnectDialog and TerminalPane, not generic ownership by AlertPanes.

## Raw PE Facts

Raw file: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE/reference facts:

| Check | Result |
| --- | --- |
| Image base | `0x00400000` |
| Target VA | `0x00622f28` |
| Target raw offset | `0x00221928` |
| UTF-16LE `Reconnect\0` | 2 hits: `0x00622f28`, `0x006288b0` |
| UTF-16LE `kServerReconnect\0` | 1 hit: `0x006288a2` |
| ASCII `Reconnect\0` | 0 hits |
| `push 0x00622f28` | 4 hits: `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| absolute target VA operand `0x00622f28` | 4 hits: `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| target RVA `0x00222f28` | 0 hits |
| false interior `0x00622f2c` | 0 hits |
| later full string `0x006288a2` | 0 hits |
| later suffix `0x006288b0` | 0 hits |
| metadata strings `RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, `.cc` | 0 hits |

The raw scan independently confirms the four target use sites and gives no source/debug metadata that would override the pooled-literal conclusion.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f28-0x00622f3c` | `0003G4` target | UTF-16LE `Reconnect` button label | true | owner `NONE`; emitters `0000N0,0000OI` | `89/94` | keep current state |
| `0x00622f1c-0x00622f54` | `0003CW` containing map | mixed physical string-tail map | false | `NONE`, no emitters | `89/93` | correct non-emitting split index |
| `0x00622f1c-0x00622f28` | `0003G3` | UTF-16LE `Leave` paired label | true | owner `NONE`; emitters `0000N0,0000OI` | `89/94` | sibling supports same source-use split |
| `0x00622f3c-0x00622f44` | `0003G5` | UTF-16LE `No` CopyWindow label | true | CopyWindow class/source route | `86/strong` | separate sibling, not target owner |
| `0x00622f44-0x00622f4c` | `0003G6` | UTF-16LE `Yes` CopyWindow label | true | CopyWindow class/source route | `86/strong` | separate sibling, not target owner |
| `0x00622f4c-0x00622f54` | `0003G7` | ANSI `baram` packet literal | true | owner `NONE`; emitters `0000N0,0000OI` | `89/94` | separate shared sibling |
| `0x00553c10-0x00553cbf` | `00023O` | ConnectionClosedDialog constructor variant | true | ReconnectDialog source family | documented | target use site |
| `0x00553cc0-0x00553e5b` | `00038J` | ConnectionClosedDialog methods | true | ReconnectDialog source family | documented | target use site |
| `0x00553f40-0x005544b8` | `00038L` | ReconnectDialog methods | true | ReconnectDialog source family | documented | target use site |
| `0x0058af50-0x0058c350` | `0001JB` | TerminalPane and setup | true | TerminalPane source family | documented | target use site |
| `0x0058b620-0x0058b64f` | `0001JD` | TerminalPane reconnect/leave callback | true | TerminalPane source family | documented | paired callback |

## Documentation Evidence And IDA Status

Existing docs confirmed by current IDA:

- Target page already records exact bytes, four source-use refs, false interior `aConnect`, and later `kServerReconnect` suffix. Current IDA/PE evidence confirms this.
- `by-file/ReconnectDialog.md` is [UID:0000N0], `87/88`, `NexusTK/network/`, and covers `ConnectionClosedDialog` plus `ReconnectDialog` reconnect/session alert code.
- `by-file/TerminalPane.md` is [UID:0000OI], `87/85`, `NexusTK/login/`, and covers the pre-login terminal disconnect/reconnect alert path.
- `by-file/AlertPanes.md` is [UID:0000HE], `85/88`, `NexusTK/ui/dialogs/`, and owns reusable alert infrastructure rather than feature-specific reconnect prompt text.
- Generated file coverage marks `0000N0` and `0000OI` as generated roots. Local staged output files exist at `auto-generated/NexusTK/network/ReconnectDialog.cpp` and `auto-generated/NexusTK/login/TerminalPane.cpp`; both are currently zero length because no final C++ has been entered, not because the emitter chain is dead.

Generated memory coverage current no-owner row:

```markdown
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
```

Generated emitted/no-owner route row:

```markdown
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |  | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

These rows are correct.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI`

Evidence for:

- Four direct IDA xrefs to `0x00622f28` are split across ReconnectDialog-family functions and TerminalPane.
- Decompiler output shows all four use sites pass `Reconnect` paired with `Leave` into alert construction.
- Raw PE scan finds exactly four `push 0x00622f28` encodings and no target RVA refs.
- No source/debug metadata, named shared object, initializer table, or owner module is present.
- Current by-structure rules explicitly allow `NONE` plus multiple emitters for pooled literals with multiple proven source-use contexts.

Evidence against:

- No material counter-evidence. It leaves declaration ownership unresolved, but unresolved canonical ownership is the accurate state for this pooled literal.

Decision:

- Accepted. Keep current state.

### 2. [UID:0000N0] `ReconnectDialog`

Evidence for:

- Three of four xrefs are in `ConnectionClosedDialog`/`ReconnectDialog` functions.
- `ReconnectDialog.md` clears the parent gate at `87/88` and is a valid generated root at `NexusTK/network/`.
- `sub_553C10`, `sub_553CC0`, and `sub_554210` each pass `&off_622F28` as a button label.

Evidence against:

- `TerminalPane::OnDisconnect` has a material direct use at `0x0058b5b1`.
- Xref majority is not declaration ownership proof.
- Assigning `CANONICAL_OWNER:0000N0` would overclaim the TerminalPane source-use path.

Decision:

- Reject as canonical owner. Keep as emitter.

### 3. [UID:0000OI] `TerminalPane`

Evidence for:

- `sub_58B470` builds a TerminalPane callback object (`v10[2] = sub_58B620`) and passes `&off_622F28` into `sub_4A0690`.
- `TerminalPane.md` clears the parent gate at `87/85` and is a valid generated root at `NexusTK/login/`.

Evidence against:

- TerminalPane accounts for one of four target xrefs.
- The other three source-use refs are in the ReconnectDialog-family.
- Assigning `CANONICAL_OWNER:0000OI` would overclaim ReconnectDialog/ConnectionClosedDialog use sites.

Decision:

- Reject as canonical owner. Keep as emitter.

### 4. [UID:0000HE] `AlertPanes`

Evidence for:

- The target is passed to alert/prompt builder routines (`sub_49FEB0`, `sub_4A0690`).
- `AlertPanes.md` owns generic alert infrastructure and is a valid generated root.

Evidence against:

- No direct target xref is inside AlertPanes-owned code.
- The label is feature-specific reconnect/terminal text, not reusable alert framework text.
- AlertPanes docs explicitly keep feature-specific reconnect alerts with their feature modules.

Decision:

- Reject as canonical owner and emitter.

### 5. Class-level owners

Evidence for:

- `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` class docs explain the functions around the use sites.

Evidence against:

- No single class covers all four source-use refs.
- The current target is a physical pooled literal, not a class-owned static member proven by source/debug evidence.
- Output needs file roots `0000N0` and `0000OI`.

Decision:

- Reject for canonical ownership of the pooled literal.

### 6. New shared-label/source owner

Evidence for:

- The same physical string is shared.

Evidence against:

- No IDA or PE evidence proves a real `ReconnectButtonLabels`, `ReconnectPromptStrings`, or similar source unit.
- Creating a new owner solely to avoid `NONE` is forbidden by current by-structure guidance.

Decision:

- Reject.

## Split / Merge / Reclassification Analysis

- Split: rejected. `0x00622f28-0x00622f3c` is the exact UTF-16LE `Reconnect` string plus terminator. There are no xrefs to `0x00622f2c`, `0x00622f30`, `0x00622f34`, or `0x00622f38`.
- Merge: rejected. Merging into `0003CW` would combine `Leave`, `Reconnect`, `No`, `Yes`, and `baram`, which have different use sets and ownership routes.
- Reclassify: rejected. The target is source-authored string data, not a pointer, vtable, function, padding, or container.
- Rename/IDA repair: rejected. `SharedReconnectWideString` is accurate. IDA `off_622F28` and interior `aConnect` are decode artifacts already documented.
- Range repair: rejected. IDA bytes and raw PE offset `0x00221928` confirm the current `0x14` byte range.

## Negative Evidence Summary

Checked and rejected:

- ReconnectDialog as sole canonical owner: overclaims TerminalPane source use.
- TerminalPane as sole canonical owner: overclaims ReconnectDialog/ConnectionClosedDialog source use.
- AlertPanes as owner: generic alert infrastructure receives labels but does not define this feature-specific text.
- Class-level owner: no single class spans the full use set.
- New shared-label owner: no declaration/source evidence.
- False interior `aConnect` at `0x00622f2c`: no IDA xrefs and no raw absolute refs.
- Later `Reconnect` at `0x006288b0`: unreferenced suffix of `kServerReconnect` at `0x006288a2`.
- Target RVA references: none found.
- Source/debug metadata: no `RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, or `.cc` strings found in raw PE.

## Exact Required Edits

No by-* documentation edits are required.

No `by-memory/-coverage-report.md` replacement is required. Retain the current row:

```markdown
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very strong : UTF-16LE `Reconnect` pooled button-label literal; B001 post-migration and B003 second-pass reviews keep `CANONICAL_OWNER:NONE` because ReconnectDialog, TerminalPane, AlertPanes, class-level parents, and a speculative shared-label owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000N0,0000OI` because live IDA/PE evidence proves source-use contexts in `ReconnectDialog.cpp` / `ConnectionClosedDialog` prompt construction (`0x00553c44`, `0x00553cf4`, `0x0055435e`) and `TerminalPane::OnDisconnect` (`0x0058b5b1`); exact target bytes and four absolute target-VA immediates are confirmed, no refs target false interior `aConnect` at `0x00622f2c`, no target RVA refs, and the later `0x006288b0` spelling is only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`.
```

Optional provenance-refresh-only replacement, if the supervisor wants this 2026-06-14 B001 pass reflected in the shared report:

```markdown
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very strong : UTF-16LE `Reconnect` pooled button-label literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000N0,0000OI`; 2026-06-14 B001 current no-owner research reconfirmed source-use contexts in `ReconnectDialog.cpp` / `ConnectionClosedDialog` prompt construction (`0x00553c44`, `0x00553cf4`, `0x0055435e`) and `TerminalPane::OnDisconnect` (`0x0058b5b1`), exact target bytes at `0x00622f28-0x00622f3c`, four raw `push 0x00622f28` encodings at those same VAs, zero refs to false interior `aConnect` at `0x00622f2c`, zero target RVA refs, and the later `0x006288b0` spelling as only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`; no single canonical owner, AlertPanes owner, class-level owner, speculative shared-label owner, split, merge, reclassification, or IDA repair is justified.
```

Generated memory coverage row should remain:

```markdown
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
```

## Follow-Up Actions

- Supervisor actions: none required for correctness. Optional provenance-only shared-row refresh text is provided above.
- A-agent actions: none.
- B001 future research actions: none for this target unless new source/debug evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `89/94`.
- Remaining uncertainty: the stripped binary cannot prove whether the original source repeated `L"Reconnect"` at each use site or used an unobserved named shared constant before linker pooling. That uncertainty is exactly why `CANONICAL_OWNER:NONE` is the correct current model.

## Validator Results

- Commands run: none.
- Result: validator not applicable because only this Agent-B001 research report was created.
- Dry runs: none used.

## Lease State

- Leases used: none.
- Reason: no by-* documentation or shared coverage file was edited; the only changed file is inside Agent-B001's own research folder.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G4-SharedReconnectWideString-current-no-owner-research.md`.
- Modified: none outside the new B001 report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B001/0003G4-SharedReconnectWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
