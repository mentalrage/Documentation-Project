** TARGET-REPORT-UID:00014P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014P ExchangeDialog Ready Alert Helper Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00014P] `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md` assigned to [UID:00004R] `ExchangeDialog`, keep it reconstructable, and keep `EMITTER_UIDS:00004R`.
- Final disposition: source-authored or source-declared ExchangeDialog ready/confirm packet helper retained in the binary, with no direct start xrefs and with equivalent behavior duplicated inside the live packet dispatcher subcommand `5`.
- Required action: update the target page evidence/gate language, score, button-helper identity, and coverage row, but do not populate the formal `RECONSTRUCTION_CPP CODE` block yet.
- Confidence: high for owner, range, packet fields, ready-state offsets, alert singleton ownership, and generated RankingDialog rejection; medium-high for final source-facing helper signature because no direct caller proves how the retained out-of-line body was referenced in source.

## Supporting Research

## Target
- Target UID: `00014P`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md`.
- Source queue/report row: supervisor assignment `B002-goal2-exchange-dialog-ready-alert-source-quality-00014P-20260617`.
- Current supervisor state: `82/88`, reconstructable true, owner/emitter [UID:00004R] `ExchangeDialog`.
- Current page state read before this report: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, blank C++ block.
- Generated output route: [UID:00004R] `ExchangeDialog` -> [UID:0000J9] `ExchangeDialog` -> `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.

## Executive Recommendation
- Best direct owner remains [UID:00004R] `ExchangeDialog`. The helper mutates ExchangeDialog ready/confirm fields, invokes ExchangeDialog's virtual button-state update through a generic DialogPane refresh wrapper, constructs an `ExchangeAlertPane`, and closes the active exchange dialog.
- Best source route remains [UID:00004R] -> [UID:0000J9] `ExchangeDialog` -> `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Recommended score after applying the evidence update: `COMPLETION:86`, `CONFIDENCE:89`. This clears the current combined numeric/emitter code-entry minimum, but final C++ population remains blocked by the no-direct-xref retained-helper/source-shape issue.
- Do not split or rename the target. Clarify the range as final byte `0x004adfab`, half-open IDA function extent `0x004ade60-0x004adfac`, followed by four `0xcc` padding bytes at `0x004adfac-0x004adfb0` before `ExchangeDialog::OnControlFocusChange`.
- Do not attach this directly to [UID:0000J9] as canonical owner. The narrow semantic owner is the `ExchangeDialog` class; the file UID is the emission root through the existing class route.

## Supervisor Active Recheck
- The supervisor assigned only `00014P`; no split repair was required.
- The target is a single IDA-modeled function, not a mixed aggregate. It starts immediately after the one-byte `0xcc` pad following [UID:00014O] and ends before four bytes of padding at `0x004adfac`.
- Every source-bearing child in scope is already a separate page. This report recommends documentation/source-quality edits only; no by-* docs, generated reports, source files, IDA DB, or coverage report were edited.

## Inference Research Guidance Check
- `by-structure.md` separates semantic ownership from emitted-output routing. That supports `CANONICAL_OWNER:00004R` and `EMITTER_UIDS:00004R`.
- The current code-entry rule is `RECONSTRUCTABLE:TRUE`, nonblank emitter route to a valid source root, and `(COMPLETION + CONFIDENCE) / 2 > 85`. The recommended `86/89` score clears the minimum gate, but `by-structure.md` also requires final source shape, names, boundaries, and dependencies to be source-quality before C++ is populated.
- `inference_research.md` cautions that generated names and adjacency are leads, not proof. The owner decision here is not adjacency-only: it is supported by field writes, packet semantics, `ExchangeAlertPane` construction, `g_pExchangeAlertPane` xrefs, the dispatcher duplicate path, and ExchangeDialog class/file docs.
- Existing documentation was treated as a lead. The target page's main behavior is validated, but its old "button-state helper" wording is imprecise and its old final-code gate language is stale under the current rule.

## Heuristic / Inference Reanalysis And Validation
- Helper identity and source-facing name:
  - Best inference: `ExchangeDialog::HandleReadyAlertPacket` or `ExchangeDialog::ShowExchangeReadyAlert`, descriptive rather than proven original.
  - Evidence checked: IDA decompile at `0x004ade60`, no xrefs to the helper start, equivalent dispatcher case `5`, ExchangeDialog field offsets, `ExchangeAlertPane` constructor call at `0x004adf8d`, and close path calls at `0x004adf9b`/`0x004adfa2`.
  - Rejected alternatives: generated `RankingDialog::HandleRankingRewardResponse`, `ExchangeAlertPane` method, generic DialogPane helper, compiler thunk, padding, or dead data.
  - Validation of existing docs: `ExchangeDialogReadyAlertHelper` is a defensible descriptive page name. It should not be treated as proof of an original function name.
  - Impact: owner/emitter stay unchanged; final C++ remains blank until the broader ExchangeDialog source integration decides how to represent the retained out-of-line duplicate.

- Packet layout and field meanings:
  - Best inference: the helper receives a pointer to an already selected exchange packet payload. It does not validate opcode or subcommand itself. The live dispatcher validates opcode `0x42` / 66 decimal and subcommand `0x05` / 5 decimal before running the equivalent ready path.
  - `packet+2`: ready-side/status selector. Nonzero means the peer/remote side is ready and sets `this+0x272` to `1`. Zero means the local ready acknowledgement path and writes `0x0100` to `this+0x270`, clearing byte `+0x270` and setting byte `+0x271`.
  - `packet+3`: one-byte message length, read only after the state gates say both sides are ready.
  - `packet+4`: narrow message bytes copied into a local `CHAR[256]`.
  - Rejected alternatives: `packet+2` as ranking reward result code, `packet+3` as wide-character length, or null-terminated packet text. None match the IDA data flow.
  - Impact: target documentation should name `packet+2` as a ready-side/status byte, not a generic result code.

- Ready/confirm state field names around `this+0x270..0x272`:
  - Best inference: `this+0x270` is a low byte for local offer/ready request state, `this+0x271` is the local ready-confirmed byte, and `this+0x272` is the peer/remote ready-confirmed byte. These are descriptive names, not recovered original member names.
  - Evidence checked: constructor initializes `word [this+0x270] = 0` and `byte [this+0x272] = 0`; `OnButtonAction` writes `byte [this+0x270] = 1` after sending opcode `0x4A` subcommand `4` or `5`; `UpdateButtonStates` reads bytes `+0x270`, `+0x271`, and `+0x272` as three independent state bits; the ready helper sets `+0x272` for nonzero `packet+2` and writes `0x0100` to `+0x270` for zero `packet+2`.
  - Rejected alternatives: one 16-bit opaque `m_rewardStatusFlags`, a RankingDialog reward state, or a single boolean ready flag. The independent byte reads/writes disprove those shapes.
  - Impact: the docs can raise confidence by replacing vague "local/remote state word" language with a packed ready-state cluster, while still marking original field names as inferred.

- Button-state helper identity:
  - Best inference: `0x0049fe20` is a generic `DialogPane` selected-control refresh/repaint wrapper, not an ExchangeDialog-specific helper. Its source-facing descriptive name is closer to `DialogPane::RefreshSelectedControlAfterStateUpdate`.
  - Evidence checked: `decompile 0x0049fe20` calls the object's vtable slot `+0x4c`, then compares selected-control byte `+0x101`, expands the control rect by four pixels, and invalidates/redraws if visual state changed. `xref_query(to 0x0049fe20)` shows ten callers across DialogPane/modeless paths plus dispatcher `0x004ad6ba` and helper `0x004adec1`.
  - Exchange-specific effect: for an ExchangeDialog object, vtable slot `0x00619d78` points to `0x004ad200`, the actual `ExchangeDialog::UpdateButtonStates` method. Thus the current docs are directionally correct that button state is refreshed, but the direct callee's identity should be corrected.
  - Rejected alternatives: source method `ExchangeDialog::UpdateButtonStates` at `0x0049fe20`, pure button enable helper, or RankingDialog refresh method.
  - Impact: target page should name `0x0049fe20` as a DialogPane refresh wrapper that invokes ExchangeDialog's virtual button-state method.

- String conversion semantics:
  - Best inference: the alert message is a byte-counted ANSI/process-code-page packet string. The helper copies exactly `packet[3]` bytes from `packet+4`, null-terminates the local narrow buffer, calls `MultiByteToWideChar(0, 0, bytes, length, wide, 256)`, and null-terminates the wide buffer at the low byte of the conversion result.
  - Evidence checked: decompile at `0x004adf0a-0x004adf49`; `0x100` is 256 decimal (Verified with `int_convert`); the decompiler casts the `MultiByteToWideChar` result to `unsigned __int8` before indexing the wide buffer.
  - Rejected alternatives: UTF-8-specific conversion, packet UTF-16, and `-1` null-terminated conversion.
  - Impact: the first-draft C++ should preserve counted-copy semantics and low-byte termination if used later.

- ExchangeAlertPane and `g_pExchangeAlertPane` names/ownership:
  - Best inference: `0x0069b330` is `g_pExchangeAlertPane`, and the helper constructs `ExchangeAlertPane` through `0x004b0490`.
  - Evidence checked: `xref_query(to 0x0069b330)` returns nine refs: dispatcher `0x004ad611`/`0x004ad739`, cancel helper `0x004addd3`, ready helper `0x004adf51`, constructor publish/fallback refs `0x004b04ff`/`0x004b0506`, clear helper `0x004b0860`, destructor clear `0x004b09d6`, and close-active helper `0x004b0b20`. `xref_query(to 0x004b0490)` shows calls at dispatcher `0x004ad656`/`0x004ad775`, cancel helper `0x004ade18`, and ready helper `0x004adf8d`.
  - Rejected alternatives: item-dialog singleton or mix-dialog singleton. Adjacent slots `0x0069b328` and `0x0069b32c` are separate active item/mix dialog pointers.
  - Impact: owner/emitter route through ExchangeDialog stays strong, and [UID:00033Z] remains the correct exact close-active helper for `0x004b0b20`.

- Add-item cleanup distinction from sibling [UID:00014O]:
  - Best inference: the ready helper does not perform AddItemDialog cleanup. That cleanup belongs to the cancel helper and dispatcher subcommand `4`.
  - Evidence checked: decompile `0x004ade60` contains no `0x0069b328` read; sibling `0x004add40` and dispatcher case `4` do.
  - Rejected alternatives: inheriting the cancel-helper cleanup semantics into this target or moving the ready helper toward ItemDialogs.
  - Impact: 00014P should mention only ExchangeAlertPane replacement and ExchangeDialog close, not AddItemDialog close.

- Duplicate/no-direct-xref relationship:
  - Best inference: `00014P` is a retained out-of-line duplicate/helper for the dispatcher ready path. The live packet dispatcher already contains equivalent source behavior in subcommand `5`.
  - Evidence checked: `xref_query(to 0x004ade60)` reports zero xrefs. Dispatcher `0x004ad320` has only the vtable data xref at `0x00619d9c` and contains the same ready-state, message decode, alert replacement, slide, and close sequence at case `5`.
  - Rejected alternatives: ordinary direct caller, vtable slot, jump table entry, or padding. IDA has a normal function object at `0x004ade60`, but no code/data xref to its start.
  - Impact: this is the main final-C++ blocker. Emitting a formal standalone method now could duplicate behavior incorrectly unless the broader ExchangeDialog source decides retained helper versus inlined dispatcher source.

- Source-authored helper versus compiler artifact:
  - Best inference: source-authored or source-declared helper body retained by the build, possibly because the source helper was inlined into the dispatcher while an out-of-line copy remained. It is not compiler-only glue.
  - Evidence checked: normal function prologue, security-cookie local buffer use, real packet field parsing, Win32 `MultiByteToWideChar`, owner-specific field writes, singleton use, allocation/constructor call, slide/close path, and a clean modeled function size.
  - Rejected alternatives: scalar deleting destructor, adjustor thunk, switch table, alignment, or runtime library helper.
  - Impact: keep `RECONSTRUCTABLE:TRUE`; do not reclassify as ignored. Still keep formal C++ blank until source integration is safe.

- Generated RankingDialog pollution:
  - Best inference: active docs and IDA evidence are authoritative; `simroot_v2/class_RankingDialog.cpp` is polluted for `0x004ade60`.
  - Evidence checked: `class_RankingDialog.cpp` emits `// NTK_ScopedInstall(HandleRankingRewardResponse, 0x004ade60)` and names `m_rewardClaimed`, `m_rewardAvailable`, and `m_rewardStatusFlags`, but the live IDA function uses ExchangeDialog offsets and `g_pExchangeAlertPane`. `by-class/RankingDialog.md` and `by-file/RankingDialog.md` already flag `0x004add40` and `0x004ade60` as ExchangeDialog outliers.
  - Rejected alternatives: moving `00014P` to RankingDialog because generated source says so, or trusting `class_ExchangeDialog.cpp` omission as evidence that the helper is not exchange code.
  - Impact: support docs should keep the generated-pollution note. Migration must not import the generated RankingDialog body for this address.

- Exact range/padding:
  - Best inference: keep current filename/range, but clarify final-byte versus half-open notation.
  - Evidence checked: `lookup_funcs 0x004ade60` returns `sub_4ADE60`, size `0x14c` / 332 bytes (Verified with `int_convert`); `0x004adfab` resolves inside the same function; `0x004adfac` is not a function; `0x004adfb0` starts `sub_4ADFB0`. `get_bytes 0x004adfa0` shows `mov ecx, edi; call 0x0049dad0; jmp common epilogue` followed by four `0xcc` bytes and the next prologue at `0x004adfb0`.
  - Rejected alternatives: ending at `0x004adfa4`, absorbing the four `0xcc` bytes, or merging with `OnControlFocusChange`.
  - Impact: target docs should state half-open extent `0x004ade60-0x004adfac`, final byte `0x004adfab`, padding `0x004adfac-0x004adfb0`.

- Score/source-placement/final-C++ impact:
  - Best defensible score after report evidence is `86/89`: packet fields, field offsets, helper identity, range, singleton ownership, generated pollution, and duplicate relationship are now materially resolved.
  - Existing docs validated: owner, reconstructability, main ready-state behavior, message decode, active exchange-alert replacement, no-direct-xref caveat, and sibling relationship with [UID:00014O].
  - Existing docs to revise: old final-code gate phrasing, vague `0x0049fe20` "button-state helper" wording, range/padding branch note, and generated RankingDialog pollution emphasis if support pages are touched.
  - Final C++: do not populate the formal C++ block yet even though the recommended score clears the minimum numeric gate.

## Evidence Standards Used
- IDA MCP facts: `idb_open`, `lookup_funcs`, `decompile`, `xref_query`, `callees`, `insn_query`, `disasm`, `get_bytes`, and `int_convert` on 2026-06-17 against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Documentation evidence: target page, [UID:00014L], [UID:00014O], [UID:00014V], [UID:00014K], [UID:00004R], [UID:0000J9], [UID:00004Q], [UID:0000QV], [UID:0002VZ], [UID:00033Z], `DialogPane` aggregate/layout docs, proposed source tree, generated coverage, and executed B reports.
- Generated evidence: `source-3/simroot_v2` and `project-documentation/auto-generated/-ag-memory-coverage.md`, treated as leads and pollution checks only.
- Negative evidence: no xrefs to `0x004ade60`, generated RankingDialog ownership mismatch, no evidence that `00014P` is an alert class method, and no evidence that the four `0xcc` bytes after `0x004adfab` belong to this function body.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs 0x004ade60` -> `sub_4ADE60`, size `0x14c` / 332 bytes (Verified with `int_convert`).
  - `lookup_funcs 0x004adfab` -> same function.
  - `lookup_funcs 0x004adfac` -> not a function.
  - `lookup_funcs 0x004adfb0` -> `sub_4ADFB0`, size `0xa3`.
  - `get_bytes 0x004ade50` shows [UID:00014O] ending with `5d c2 04 00 cc` followed by the `0x004ade60` prologue.
  - `get_bytes 0x004adfa0` shows the ready helper tail and four `0xcc` bytes before `0x004adfb0`.
- Behavior facts:
  - Decompile `0x004ade60` shows `packet+2` ready-side/status handling, `packet+3` length, `packet+4` message bytes, local `CHAR[256]` and `WCHAR[256]` buffers, `MultiByteToWideChar`, `g_pExchangeAlertPane` close-active path, allocation of `0x270` / 624 bytes, `ExchangeAlertPane` construction, slide animation, and generic close/remove.
  - Decompile `0x004ad320` case `5` repeats the same behavior with `this-0xa0` adjustment from the dispatcher vtable view.
  - Decompile `0x004ad0b0` writes `byte [this+0x270] = 1` after sending opcode `0x4A` subcommand `4` or `5`.
  - Decompile `0x004ad200` reads bytes `this+0x270`, `this+0x271`, `this+0x272`, and `this+0x278` to enable/disable controls `1`, `2`, `3`, and `6`.
  - Decompile `0x0049fe20` proves a generic DialogPane refresh wrapper that calls vtable slot `+0x4c` and repaints the selected control when its visual state changes.
- Xref facts:
  - `xref_query(to 0x004ade60)` reports zero xrefs.
  - `xref_query(to 0x004add40)` also reports zero xrefs, matching the sibling retained-helper pattern.
  - `xref_query(to 0x004ad320)` reports one data/vtable xref at `0x00619d9c`.
  - `xref_query(to 0x0049fe20)` reports ten callers, including dispatcher `0x004ad6ba` and ready helper `0x004adec1`.
  - `xref_query(to 0x004b0b20)` reports callers `0x004ad741` in the dispatcher and `0x004adf59` in this helper.
  - `xref_query(to 0x004b0490)` reports alert constructor calls at dispatcher `0x004ad656`/`0x004ad775`, cancel helper `0x004ade18`, and ready helper `0x004adf8d`.
  - `xref_query(to 0x0069b330)` reports the nine expected exchange-alert singleton refs, including this helper at `0x004adf51`.
- Negative IDA facts:
  - No ordinary caller, vtable slot, jump table entry, or data pointer to `0x004ade60` was found.
  - No IDA evidence supports the generated `RankingDialog::HandleRankingRewardResponse` ownership.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ad320-0x004ad7b3` | `00014L` `ExchangeDialogPacketDispatcher` | Live virtual exchange packet dispatcher; includes ready subcommand case `5` | True | `00004R` | `84/90` | supporting context |
| `0x004add40-0x004ade5e` | `00014O` `ExchangeDialogCancelAlertHelper` | Retained cancel-alert helper/out-of-line duplicate | True | `00004R` | `86/89` | supporting sibling |
| `0x004ade5f-0x004ade60` | none | One `0xcc` alignment byte | False | none | n/a | boundary before this target |
| `0x004ade60-0x004adfab` final-byte style, half-open `0x004ade60-0x004adfac` | `00014P` target | Retained ready-alert helper/out-of-line duplicate | True | `00004R` | current `82/88`, recommend `86/89` | keep attached, no formal C++ |
| `0x004adfac-0x004adfb0` | none | Four `0xcc` alignment bytes | False | none | n/a | boundary before `0x004adfb0` |
| `0x004b0b20-0x004b0b31` | `00033Z` `ExchangeAlertPaneCloseActiveHelper` | Closes active exchange alert singleton | True | `00004Q` | `85/90` | callee/support |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ade60` | zero xrefs to start | Retained helper is not directly called by current IDA static graph. |
| `0x004ad686-0x004ad78a` | dispatcher case `5` | Equivalent live ready path inside [UID:00014L]. |
| `0x004adec1` | call `0x0049fe20` | DialogPane selected-control refresh wrapper; invokes ExchangeDialog virtual update slot. |
| `0x004adf51` | read `0x0069b330` | Checks active exchange alert singleton. |
| `0x004adf59` | call `0x004b0b20` | Closes active `ExchangeAlertPane` if present. |
| `0x004adf8d` | call `0x004b0490` | Constructs new `ExchangeAlertPane`. |
| `0x004adf9b` | call `0x0049eb90` | Runs generic slide animation close path. |
| `0x004adfa2` | call `0x0049dad0` | Removes/closes the `ExchangeDialog` through global UI state. |

## Documentation Evidence And IDA Status
- Executed B-report search:
  - Searched `Agent-B001/research/executed`, `Agent-B002/research/executed`, and `Agent-B003/research/executed` for `00014P`, `0x004ade60`, `ExchangeDialogReadyAlertHelper`, sibling `00014O`, dispatcher `00014L`, and tail `00014V`.
  - No executed report for `00014P` itself was found.
  - Prior reports found and used only as leads: B002 `00014O-exchange-dialog-cancel-alert-source-quality.md`, B001 `00014T-ItemExchangeMixDialogs.md`, B001 `00014V-ExchangeDialogTail.md`, and B001 `000342-SharedReturnTrueVirtualHelper.md`.
- Existing docs that support the conclusion:
  - [UID:00014P] already records owner, packet fields, ready-state flow, message decode, active-alert replacement, and no-direct-xref caveat. IDA MCP revalidated those claims with refinements.
  - [UID:00014L] documents the live dispatcher ready case and duplicate relationship. IDA MCP revalidated subcommand `5`.
  - [UID:00004R] and [UID:0000J9] describe `ExchangeDialog.cpp` as owning exchange live trade, packet dispatcher, money, ready/cancel flow, `ExchangeAlertPane`, and `g_pExchangeAlertPane`.
  - [UID:0000QV], [UID:0002VZ], and [UID:00033Z] support the exchange-alert singleton name, exact storage, and close-active helper.
  - [UID:00012R] `DialogPane` documents `0x0049fe20` as the selected-control repaint helper, resolving the target's vague helper identity.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page and some owner pages still imply formal C++ remains blank only because of an old `95/95` threshold. Under the current rule, the actual blocker is source shape/no-xref duplicate risk.
  - Target wording that calls `0x0049fe20` a "button-state update helper" should be corrected to a DialogPane refresh wrapper that invokes ExchangeDialog's virtual `UpdateButtonStates` slot.
  - Target boundary note should cite the tail branch at `0x004adfa7` and padding at `0x004adfac-0x004adfb0`, not an imprecise branch-at-`0x004adfa4` note.
  - `simroot_v2/class_RankingDialog.cpp` incorrectly emits `0x004ade60` as `RankingDialog::HandleRankingRewardResponse`.
  - `simroot_v2/class_ExchangeDialog.cpp` omits `00014P`; the staged `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` currently exists as a zero-byte file because formal code blocks remain blank.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog
- Evidence for: `this` is an ExchangeDialog base pointer, packet fields are exchange server packet fields, the helper mutates ExchangeDialog ready-state fields, invokes ExchangeDialog's virtual button-state method through DialogPane, constructs `ExchangeAlertPane`, and closes ExchangeDialog.
- Evidence against: no direct xrefs to the helper start. This weakens source-callgraph confidence but not semantic ownership.
- Decision: accepted as canonical owner.

### 2. [UID:0000J9] ExchangeDialog.cpp
- Evidence for: this is the source root for `ExchangeDialog`, `ExchangeAlertPane`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `g_pExchangeAlertPane`; proposed path is `NexusTK/ui/dialogs/`.
- Evidence against: by-structure favors the narrow class as canonical owner when the helper belongs directly to that class. File UID is the emission root, not the direct semantic owner.
- Decision: accepted as route through `00004R`, not as direct canonical owner.

### 3. [UID:00004Q] ExchangeAlertPane
- Evidence for: the helper closes an active exchange alert and constructs a new `ExchangeAlertPane`.
- Evidence against: it parses an exchange packet, owns ExchangeDialog field transitions, and closes ExchangeDialog. It is a producer/caller of alert UI, not an alert-pane method.
- Decision: rejected as direct owner.

### 4. [UID:00003T] DialogPane / [UID:00012R] DialogPane aggregate
- Evidence for: the helper calls generic DialogPane helper `0x0049fe20`, slide helper `0x0049eb90`, and close helper `0x0049dad0`.
- Evidence against: those are base infrastructure callees. The packet parsing and state fields are ExchangeDialog-specific.
- Decision: rejected as direct owner; retained as dependency/support evidence.

### 5. RankingDialog generated owner
- Evidence for: stale `simroot_v2/class_RankingDialog.cpp` emits `HandleRankingRewardResponse` at `0x004ade60`.
- Evidence against: IDA behavior uses exchange globals/classes and ExchangeDialog offsets; RankingDialog docs already flag this as generated pollution; no ranking vtable, ranking singleton, or reward collection state appears in the helper.
- Decision: rejected. Do not migrate this body into `RankingDialog.cpp`.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file or grouping is recommended.
- Likely full contents: existing `ExchangeDialog.cpp` already covers the correct feature file contents.
- Candidate related items that belong: `00014L`, `00014M`, `00014N`, `00014O`, `00014P`, `ExchangeAlertPane`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, `g_pExchangeAlertPane`, and exchange resource/vtable children.
- Candidate related items rejected: `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, `MyItemListPane`, generic DialogPane, and RankingDialog remain in their established owners except where ExchangeDialog consumes them.
- Standalone, narrow, or broad source-file inference: narrow helper inside a broad existing feature file, not standalone.

## Negative Evidence Summary
- No xrefs to `0x004ade60` means no direct static proof of source call sites.
- The dispatcher already contains the equivalent ready path; final source must not blindly emit both a helper and a duplicate dispatcher block as if both are necessarily hand-called.
- Generated `RankingDialog` ownership is contradicted by IDA behavior and current by-* docs.
- The ready helper does not touch `dword_69B328`, so AddItemDialog cleanup from [UID:00014O] must not be copied into this target.
- Physical adjacency to ExchangeDialog helps, but the decisive evidence is the combined packet/field/global/class behavior.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00014P] yet.

The target would clear the minimum numeric/emitter gate if rescored to `86/89`, but final source is blocked by a concrete source-shape issue: IDA proves no direct xrefs to the helper start while the dispatcher inlines the same ready path. The safer source-integration decision belongs to a broader `ExchangeDialog.cpp` reconstruction pass that can decide whether the original code had an inline helper with a retained out-of-line copy, a private uncalled method, or duplicated packet-handler source.

Non-populate draft shape for future use only:

```cpp
// Do not paste into RECONSTRUCTION_CPP yet.
// Descriptive source shape only; method, field, and dependency names are not final.
void ExchangeDialog::HandleReadyAlertPacket(const unsigned char *packet)
{
    unsigned char readySide = packet[2];

    if (readySide != 0) {
        m_remoteReadyConfirmed = 1;
        if (m_localReadyConfirmed != 1) {
            RefreshSelectedControlAfterStateUpdate();
            return;
        }
    } else {
        unsigned char wasRemoteReady = m_remoteReadyConfirmed;
        m_readyStateWord = 0x0100;
        if (wasRemoteReady != 1) {
            RefreshSelectedControlAfterStateUpdate();
            return;
        }
    }

    char text[256];
    wchar_t message[256];

    unsigned int length = packet[3];
    memmove(text, packet + 4, length);
    text[length] = 0;

    int converted = MultiByteToWideChar(CP_ACP, 0, text, length, message, 256);
    message[(unsigned char)converted] = 0;

    if (g_pExchangeAlertPane)
        CloseActiveExchangeAlertPane();

    new ExchangeAlertPane(message, this, g_szDialogOk, 0);

    this->SlideClose();
    CloseDialogPane(this);
}
```

Concrete reasons not to populate now:
- No direct xref proves the source call shape.
- The dispatcher already contains the live ready behavior.
- `RefreshSelectedControlAfterStateUpdate`, `m_readyStateWord`, `m_localReadyConfirmed`, `m_remoteReadyConfirmed`, `SlideClose`, `CloseDialogPane`, `CloseActiveExchangeAlertPane`, and `g_szDialogOk` are descriptive placeholders, not final project names.
- The exact return type is likely source-level `void`, but no caller consumes it because no caller is statically proven.
- The source integration must decide whether dispatcher case `5` should call a private helper or remain inlined while `00014P` represents a retained out-of-line clone.

## Final Recommendation
- Exact changes recommended for target metadata:
  - `COMPLETION:86`
  - `CONFIDENCE:89`
  - keep `CANONICAL_OWNER:00004R`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00004R`
  - keep `RECONSTRUCTION_CPP CODE` blank
- Exact documentation changes recommended:
  - Replace old gate wording with the current combined-score/emitter gate plus the source-shape blocker.
  - Add the 2026-06-17 IDA evidence for no xrefs, exact range/padding, dispatcher duplicate case, `0x0049fe20` identity, `0x0049eb90` slide close, and generated RankingDialog pollution.
  - Clarify packet field language for `packet+2`, `packet+3`, and `packet+4`.
  - Clarify ready-state fields at `this+0x270..0x272` as a packed state cluster with descriptive, not original-proof, names.
- Exact parent assignments recommended: no change.
- Exact items left no-owner/non-emitting and why: none for this target. Broad [UID:00014V] remains non-emitting as already accepted, but `00014P` itself stays emitting with blank code until source shape is safe.

## Coverage Row Recommendation
Do not edit `by-memory/-coverage-report.md` directly in this report-only task. If the supervisor accepts the score/source-quality update, replace the current `00014P` row in address order after [UID:00014O] and before [UID:00014Q] with:

```text
    - [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md) 0x004ade60-0x004adfab | helper | ExchangeDialogReadyAlertHelper : reconstructable : 86% : strong : ExchangeDialog ready/confirm alert packet helper; 2026-06-17 IDA recheck confirms `0x14c` / 332-byte function size (Verified with int_convert.py), `packet+2` local/remote ready-side byte, `packet+3` byte length, `packet+4` CP_ACP message copy/convert, `this+0x270..0x272` packed local/remote ready-state updates, generic DialogPane selected-control refresh wrapper `0x0049fe20` invoking ExchangeDialog `UpdateButtonStates`, active exchange-alert replacement, no direct start xrefs, and duplicate dispatcher subcommand-5 source-shape blocker. Keep formal C++ blank until ExchangeDialog source integration decides retained out-of-line helper versus inlined dispatcher helper.
```

## Support Docs To Update
- Target page [UID:00014P]: apply the evidence/gate/score changes above.
- [UID:00014K] `ExchangeDialog` aggregate and [UID:00004R] class page: update the ready-alert helper row and remaining-caveat language to reflect the current source-shape blocker, the resolved `0x0049fe20` identity, and the packed ready-state field interpretation.
- [UID:0000J9] `ExchangeDialog` file page: add or strengthen the note that `0x004ade60` is an ExchangeDialog retained ready helper despite stale RankingDialog generated output.
- [UID:00014L] packet dispatcher: if edited, clarify that subcommand `5` contains the live duplicate of this helper and calls the generic DialogPane refresh wrapper at `0x0049fe20`.
- [UID:00012R] `DialogPane` aggregate: no required change found; it already describes `0x0049fe20` as selected-control repaint helper. Cross-linking from the target page is enough.
- [UID:0000MZ] / RankingDialog docs: already flag `0x004ade60` as an ExchangeDialog outlier. Keep that note if those pages are edited.
- `wave3_data_issues.md`: already records RankingDialog pollution and ExchangeDialog helper omissions; optional follow-up can mention this accepted `00014P` source-quality pass.

## Follow-Up Actions
- Supervisor actions:
  - Apply the metadata/body/coverage row recommendations if accepted.
  - Do not paste the illustrative C++ into the formal target C++ block.
  - Re-run targeted validation and memory coverage refresh after applying by-* edits.
- A-agent actions:
  - When reconstructing ExchangeDialog source, decide whether dispatcher case `5` should call a private helper or remain inlined while `00014P` represents a retained out-of-line clone.
  - Avoid using `simroot_v2/class_RankingDialog.cpp` as authority for `0x004ade60`.
- B002 future research actions:
  - None required for `00014P` unless the supervisor later asks for a broader ExchangeDialog dispatcher/source-integration pass.

## Confidence
- Recommendation confidence: high for owner/emitter and score update; medium-high for no-populate C++ decision.
- Score confidence: `86/89` is justified by exact function/range/behavior/owner evidence, but not higher because source-facing names, direct reachability, and final integration remain unresolved.
- Remaining uncertainty: original helper name, whether this was an inline helper with retained out-of-line body, and final source member names for `this+0x270..0x272` and the DialogPane refresh wrapper.

## Validator Results
- Validator was not run because this was report-only work and no by-* pages were edited.
- IDA MCP validation commands/evidence used:
  - `idb_open` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - `lookup_funcs` for `0x004ade60`, `0x004adfab`, `0x004adfac`, `0x004adfb0`, `0x004ad320`, `0x004add40`, `0x0049fe20`, `0x004b0b20`, `0x004b0490`, `0x004ad200`, `0x004ad0b0`, `0x0049dad0`, and `0x0049eb90`
  - `decompile` for `0x004ade60`, `0x004ad320`, `0x004ad0b0`, `0x004ad200`, `0x004ada20`, `0x0049fe20`, `0x004b0b20`, `0x0049eb90`, and `0x0049dad0`
  - `xref_query` for `0x004ade60`, `0x004add40`, `0x004ad320`, `0x004adfb0`, `0x0049fe20`, `0x004b0b20`, `0x0069b330`, `0x004b0490`, `0x0049eb90`, and `0x0049dad0`
  - `callees` for `0x004ade60`, `0x004ad320`, `0x0049fe20`, `0x004ad200`, and `0x004ad0b0`
  - `disasm` for `0x004ac8a0`
  - `insn_query` over `0x004ac8a0-0x004ae052` and `0x004ade60-0x004adfac`
  - `get_bytes` for `0x004ade50`, `0x004adfa0`, and `0x004adfb0`
  - `int_convert` for `0x14c`, `0x270`, `0x271`, `0x272`, `0x100`, `0x42`, `0x4a`, `0x5`, `0xa0`, `0x274`, `0x278`, `0x493`, and `0x8e`
- Recommended post-edit validation:

> Executable block R001 was removed from this report and preserved verbatim in [00014P-exchange-dialog-ready-alert-source-quality-removed.md](00014P-exchange-dialog-ready-alert-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00014P-exchange-dialog-ready-alert-source-quality.md`
- Modified:
  - None outside the assigned B002 research folder.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00014P-exchange-dialog-ready-alert-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00014P"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014P-exchange-dialog-ready-alert-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00014P-exchange-dialog-ready-alert-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
