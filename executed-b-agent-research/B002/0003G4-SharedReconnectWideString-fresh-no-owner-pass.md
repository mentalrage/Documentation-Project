** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Fresh No-Owner Pass

## Final Recommendation

Keep [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` unchanged.

- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `RECONSTRUCTION_CPP`.
- Owner/emitter decision: this is a valid no-owner pooled literal with two proven source-use emitters. Do not force [UID:0000N0] `ReconnectDialog` or [UID:0000OI] `TerminalPane` as a canonical owner.
- Required edits: none for the target page, related by-* docs, generated reports, or `by-memory/-coverage-report.md`.
- Score impact: unchanged, before `89/94`, after `89/94`.
- C++ entry: minimum metadata gate is met (`RECONSTRUCTABLE:TRUE`, nonblank emitters, valid file-root routes, `(89 + 94) / 2 = 91.5 > 85`), but this pass should not add standalone C++. The safe final source shape is the literal `L"Reconnect"` at each reconstructed semantic use site unless later source/debug evidence proves a named shared declaration.
- Confidence: high. Current IDA MCP, raw PE scans, and current docs all agree on exact bytes, four source-use references, no false-interior reference, no target RVA references, and no referenced later duplicate.

## Target And Scope

- Agent: `Agent-B002`.
- Assignment: fresh Goal 2 no-owner memory pass for one target only.
- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Target range: `0x00622f28-0x00622f3c`.
- Prior report reviewed as evidence only: `tools/leaser/Agents/Agent-B001/research/executed/0003G4-SharedReconnectWideString-current-no-owner-research.md`.
- Current tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` active row assigns `0003G4` to `Agent-B002`.
- Current generated coverage row: `auto-generated/-ag-memory-coverage.md` reports no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`.

Current target header checked:

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

## Evidence Standards

I applied the current `by-structure.md` owner/emitter model:

- `CANONICAL_OWNER` is semantic declaration/source ownership, not the nearest generated root.
- `EMITTER_UIDS` is output routing and may contain multiple proven source-use roots.
- Pooled string literals may stay `CANONICAL_OWNER:NONE` when no single declaration owner is defensible.
- Do not create a synthetic shared owner solely to remove `NONE`.
- Reconstruction C++ requires the combined-score plus confirmed-emitter gate, but that gate is only minimum eligibility.

I also applied `inference_research.md` guidance that merged string literals and constant pools are informative compiler/linker output, not proof of a human source grouping.

Evidence checked:

- Current target page.
- Current generated memory coverage and no-owner sections.
- Current shared `by-memory/-coverage-report.md` row.
- Current emitter docs for [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane`.
- Rejected shared framework candidate [UID:0000HE] `AlertPanes`.
- Containing map [UID:0003CW] and sibling exact children [UID:0003G3], [UID:0003G5], [UID:0003G6], and [UID:0003G7].
- Live IDA MCP evidence from session `a001_goal2_class_batch`.
- Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## IDA Facts

Live IDA MCP session:

```text
session_id: a001_goal2_class_batch
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Target bytes from `get_bytes 0x00622f1c size 0x48`:

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

IDA xrefs to the target:

| Target | Xref | Function | Source-use interpretation |
| --- | --- | --- | --- |
| `0x00622f28` | `0x00553c44` | `sub_553C10` | `ConnectionClosedDialog` constructor variant passes the reconnect label. |
| `0x00622f28` | `0x00553cf4` | `sub_553CC0` | alternate `ConnectionClosedDialog` constructor path passes the reconnect label. |
| `0x00622f28` | `0x0055435e` | `sub_554210` | `ReconnectDialog` button path constructs a replacement connection-closed prompt. |
| `0x00622f28` | `0x0058b5b1` | `sub_58B470` | `TerminalPane::OnDisconnect` constructs the reconnect/leave prompt path. |

Paired `Leave` xrefs:

```text
0x00622f1c <- 0x00553c3f in sub_553C10
0x00622f1c <- 0x00553cef in sub_553CC0
0x00622f1c <- 0x00554359 in sub_554210
0x00622f1c <- 0x0058b5ac in sub_58B470
```

Negative refs:

```text
xrefs_to 0x00622f2c: 0
xrefs_to 0x00622f30: 0
xrefs_to 0x00622f34: 0
xrefs_to 0x00622f38: 0
xrefs_to 0x006288a2: 0
xrefs_to 0x006288b0: 0
```

Sibling refs checked for split boundaries:

```text
0x00622f3c ("No")  -> 0x00553ebb, 0x005544c5
0x00622f44 ("Yes") -> 0x00553ec0, 0x005544ca
0x00622f4c ("baram") -> 0x00554276, 0x0058b3fc
0x00622f54 -> 0 refs
```

Function lookup:

| Query | IDA function |
| --- | --- |
| `0x00553c44` | `sub_553C10`, start `0x00553c10`, size `0xaf` |
| `0x00553cf4` | `sub_553CC0`, start `0x00553cc0`, size `0xae` |
| `0x0055435e` | `sub_554210`, start `0x00554210`, size `0x1f6` |
| `0x0058b5b1` | `sub_58B470`, start `0x0058b470`, size `0x170` |
| `0x0049feb0` | `sub_49FEB0`, alert builder, size `0x6c5` |
| `0x004a0690` | `sub_4A0690`, wrapper into `sub_49FEB0`, size `0x47` |
| `0x00622f28`, `0x00622f2c`, `0x006288a2`, `0x006288b0` | not functions |

Relevant decompiler lines:

```text
sub_553C10:
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C); /*0x553c5c*/

sub_553CC0:
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C); /*0x553d09*/

sub_554210:
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C); /*0x554376*/

sub_58B470:
v10[2] = sub_58B620; /*0x58b56d*/
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/
```

Scoped `insn_query` found exactly one `push offset off_622F28` in each relevant function at:

```text
0x00553c44
0x00553cf4
0x0055435e
0x0058b5b1
```

The same scoped query found no operand use of false interior address `0x00622f2c` inside `sub_553C10` or `sub_58B470`.

Component analysis over `sub_553C10`, `sub_553CC0`, `sub_554210`, `sub_58B470`, `sub_49FEB0`, and `sub_4A0690` reported:

```text
0x622f1c off_622F1C accessed_by sub_553C10, sub_553CC0, sub_554210, sub_58B470
0x622f28 off_622F28 accessed_by sub_553C10, sub_553CC0, sub_554210, sub_58B470
sub_58B470 -> sub_4A0690 -> sub_49FEB0
```

This confirms that the target is materially shared by the ReconnectDialog/ConnectionClosedDialog family and the TerminalPane disconnect path.

## Raw PE Evidence

Raw file:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247E04E20B65D6414C7238AA8FF5515
imagebase: 0x00400000
```

Relevant PE section mapping:

```text
.text  VA 0x00001000 raw 0x00000400
.rdata VA 0x0020d000 raw 0x0020ba00
```

The target maps to raw `0x221928` / VA `0x00622f28`.

Pattern scan results:

| Pattern | Result |
| --- | --- |
| UTF-16LE `Reconnect\0` | two hits: raw `0x221928`/VA `0x00622f28`, raw `0x2272b0`/VA `0x006288b0` |
| UTF-16LE `kServerReconnect\0` | one hit: raw `0x2272a2`/VA `0x006288a2` |
| `push 0x00622f28` (`68 28 2f 62 00`) | four hits: `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| absolute dword `0x00622f28` | four hits at the immediate operands: `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| target RVA dword `0x00222f28` | zero hits |
| false interior absolute dword `0x00622f2c` | zero hits |
| absolute dword `0x006288a2` | zero hits |
| absolute dword `0x006288b0` | zero hits |
| ASCII `Reconnect\0` | zero hits |
| `.pdb` / `.cpp` ASCII metadata strings | zero hits |

The later `0x006288b0` spelling is only the suffix of `kServerReconnect` at `0x006288a2`; no code/data reference points to either the full `kServerReconnect` storage or that suffix.

## Current Documentation Evidence

The target page already documents:

- Exact bytes for UTF-16LE `Reconnect`.
- IDA's `off_622F28` and interior `aConnect` names as string-pooling artifacts.
- Four xrefs at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.
- The second `Reconnect` spelling at `0x006288b0` as outside the child range.
- Current `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000N0,0000OI`.

[UID:0000N0] `ReconnectDialog` is a valid emitter:

- `by-file/ReconnectDialog.md` owns `network/ReconnectDialog.cpp`.
- Current generated file coverage routes it to `auto-generated/NexusTK/network/ReconnectDialog.cpp`.
- It covers `ConnectionClosedDialog` and `ReconnectDialog` method children that contain three target refs.

[UID:0000OI] `TerminalPane` is a valid emitter:

- `by-file/TerminalPane.md` owns `login/TerminalPane.cpp`.
- Current generated file coverage routes it to `auto-generated/NexusTK/login/TerminalPane.cpp`.
- It covers `TerminalPane::OnDisconnect`, which contains the fourth target ref and stores the callback at `0x0058b56d`.

Generated root files exist:

```text
auto-generated/NexusTK/network/ReconnectDialog.cpp
auto-generated/NexusTK/login/TerminalPane.cpp
```

Both current files are zero-length because the relevant reconstruction C++ blocks are blank, not because the emitter routes are dead ends.

[UID:0000HE] `AlertPanes` is not a better owner or emitter. Its own documentation keeps feature-specific reconnect alerts with [UID:0000N0] `ReconnectDialog`, and live IDA shows this literal is used in feature-specific prompt construction, not in generic alert infrastructure.

## Owner And Emitter Reasoning

Rejected canonical owner [UID:0000N0] `ReconnectDialog`:

- It accounts for three of four direct refs.
- It is the strongest source root for `ConnectionClosedDialog` and `ReconnectDialog`.
- It does not account for the independent `TerminalPane::OnDisconnect` source-use ref at `0x0058b5b1`.
- Assigning it as canonical owner would overclaim a pooled label used by another file root.

Rejected canonical owner [UID:0000OI] `TerminalPane`:

- It accounts for the terminal disconnect prompt use.
- It does not account for the three `ConnectionClosedDialog`/`ReconnectDialog` refs.
- Assigning it as canonical owner would overclaim the dialog-family uses.

Rejected canonical owner [UID:0000HE] `AlertPanes`:

- The helper calls eventually build alert UI, but the use sites are feature-specific.
- The current `AlertPanes` doc explicitly leaves reconnect alerts with `ReconnectDialog`.
- No evidence shows a generic shared alert label declaration in `AlertPanes`.

Rejected class-level owners:

- `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` each explain part of the use set.
- No single class owns all source uses.
- The item is a pooled string literal, not a vtable, field, or class-local static with class-specific declaration evidence.

Rejected new shared source file/global owner:

- No PDB/source metadata is present.
- No xref targets a standalone named declaration.
- The raw duplicate at `0x006288b0` is not referenced and is a suffix of `kServerReconnect`, so it does not prove a shared label module.
- Creating a shared constants file would be a reconstruction convenience, not source-quality evidence.

Accepted emitters:

- `0000N0` because three direct source-use contexts route to `network/ReconnectDialog.cpp`.
- `0000OI` because one direct source-use context routes to `login/TerminalPane.cpp`.

This matches `by-structure.md`: no canonical owner is defensible, but multiple source-use emitters are proven.

## Split, Merge, Reclassification, And Name Repair

No split is required.

- The target is exactly the UTF-16LE `Reconnect` storage at `0x00622f28-0x00622f3c`.
- The interior IDA name `aConnect` at `0x00622f2c` has zero refs and is only a suffix artifact.
- The later `Reconnect` spelling at `0x006288b0` is outside this range and unreferenced.

No merge is required.

- The containing [UID:0003CW] map is correctly `RECONSTRUCTABLE:FALSE` as a mixed string/data map.
- Sibling `Leave` and `baram` are also shared across the same two emitter roots, but they are distinct literals with their own ranges.
- Sibling `No`/`Yes` route to CopyWindow and should not merge with this target.

No reclassification is required.

- The target is source-authored string data and remains `RECONSTRUCTABLE:TRUE`.
- It is not a compiler-only map, vtable, RTTI record, padding span, pointer table, or ignored aggregate.

No IDA-safe name repair is required.

- `off_622F28` and `aConnect` are misleading, but the docs already identify them as artifacts.
- The target filename and title are accurate enough for current coverage tooling.

## Coverage Rows And Supervisor-Owned Text

No shared-report change is required. The current `auto-generated/-ag-memory-coverage.md` row is correct:

```text
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
```

No `by-memory/-coverage-report.md` replacement is required. If the supervisor wants to refresh provenance later, the existing row can be updated to mention this B002 fresh pass, but the current row's technical content is still accurate and does not need repair for this assignment.

No `by-*` metadata/body edits are recommended.

## Validation And Leases

- Changed files: this report only.
- Leases: none used. The only edited file is inside `Agent-B002/research`; no by-* or generated project documentation files were edited.
- Validation: not run because no validator-managed by-* documentation was changed.
- Dry runs: none used.

## Final Status

`0003G4` should remain a no-owner multi-emitter pooled literal:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
RECONSTRUCTION_CPP: blank
COMPLETION/CONFIDENCE: 89/94 unchanged
```

This result is independently supported by current IDA MCP evidence and raw PE evidence, not just by the prior B001 report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B002/0003G4-SharedReconnectWideString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
