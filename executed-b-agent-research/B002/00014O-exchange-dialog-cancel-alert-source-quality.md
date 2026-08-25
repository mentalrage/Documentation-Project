** TARGET-REPORT-UID:00014O **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014O ExchangeDialog Cancel Alert Helper Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00014O] `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md` assigned to [UID:00004R] `ExchangeDialog`, keep it reconstructable, and keep `EMITTER_UIDS:00004R`.
- Final disposition: source-authored or source-declared helper body retained in the binary, but no direct start xrefs. Treat it as an ExchangeDialog-owned retained duplicate/out-of-line helper for the dispatcher cancel path, not as RankingDialog, ExchangeAlertPane, AddItemDialog, padding, or compiler-only glue.
- Required action: update the target page evidence/gate language and coverage row, but do not populate the formal `RECONSTRUCTION_CPP CODE` block yet.
- Confidence: high for owner, range, packet fields, singleton/global roles, and generated-pollution rejection; medium-high for final source-facing helper signature because no direct caller proves how the original source referenced the out-of-line body.

## Supporting Research

## Target
- Target UID: `00014O`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md`.
- Source queue/report row: supervisor assignment `B002-goal2-exchange-dialog-cancel-alert-source-quality-00014O-20260617`.
- Current supervisor state from refreshed stats: `82/88`, reconstructable true, owner/emitter [UID:00004R] `ExchangeDialog`, generated output route `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Current page state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, blank C++ block.

## Executive Recommendation
- Best direct owner remains [UID:00004R] `ExchangeDialog`. The helper decodes an exchange server cancel/termination message, replaces the exchange alert, closes the exchange dialog, and closes any active add-item picker.
- Best source route remains [UID:00004R] -> [UID:0000J9] `ExchangeDialog` -> `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Recommended score after applying the evidence update: `COMPLETION:86`, `CONFIDENCE:89`. This clears the combined code-entry minimum, but the source shape still blocks formal C++ population.
- Do not split or rename the current target. Clarify the range as final byte `0x004ade5e`, half-open IDA function extent `0x004add40-0x004ade5f`, followed by one `0xcc` alignment byte at `0x004ade5f` before [UID:00014P] at `0x004ade60`.
- Do not attach this to [UID:0000J9] directly as canonical owner: the narrow semantic owner is the `ExchangeDialog` class. The file UID is the emission root through the existing class route.

## Supervisor Active Recheck
- The supervisor assigned only `00014O`; no split repair was required.
- The target is a single IDA-modeled function, not a mixed aggregate. Its adjacent raw money helper ends before it, and [UID:00014P] begins after one alignment byte.
- Every source-bearing child in scope is already a separate page. This report recommends documentation/source-quality edits only; no by-* docs, generated reports, source files, IDA DB, or coverage report were edited.

## Inference Research Guidance Check
- `by-structure.md` requires the narrowest true owner and separates semantic ownership from output routing. That supports `CANONICAL_OWNER:00004R` and `EMITTER_UIDS:00004R`.
- `inference_research.md` cautions that adjacency and generated names are leads, not proof. The owner decision here is not adjacency-only: it is supported by packet semantics, `g_pExchangeAlertPane`, `g_pAddItemDialog`, alert constructor calls, duplicate dispatcher behavior, and ExchangeDialog class/file docs.
- Existing documentation was treated as a lead. The target page's main behavior is validated, but its old "below 95/95 gate" language is stale under the current combined-score rule, and the generated `RankingDialog` ownership is rejected.

## Heuristic / Inference Reanalysis And Validation
- Helper identity and generated name:
  - Best inference: `ExchangeDialog::ShowExchangeCancelAlert` or `ExchangeDialog::HandleCancelAlertPacket`, descriptive rather than proven original.
  - Evidence checked: IDA decompile at `0x004add40`, no xrefs to the helper start, `ExchangeDialog` fields/globals, `ExchangeAlertPane` constructor call at `0x004ade18`, and duplicate dispatcher case `4` at `0x004ad5a9-0x004ad681`.
  - Rejected alternatives: `RankingDialog::HandleRankingAlertMessage` from `simroot_v2/class_RankingDialog.cpp`; `ExchangeAlertPane` method; `AddItemDialog` helper; compiler thunk/padding.
  - Validation of existing docs: existing `ExchangeDialogCancelAlertHelper` name is defensible as a descriptive page name. It should not be treated as original proof.
  - Impact: owner/emitter stay unchanged; final C++ should remain blank because the source-facing function name and whether it was called, inlined, or retained out-of-line remain unresolved.

- Packet layout and field meanings:
  - Best inference: the helper takes a pointer to an already selected exchange packet payload. It does not validate opcode/subcommand. The dispatcher validates opcode `0x42` / 66 decimal (Verified with int_convert.py) and subcommand `0x04` / 4 decimal (Verified with int_convert.py) before running the equivalent cancel path.
  - Evidence checked: helper reads length from `packet+3`, copies message bytes from `packet+4`, and does not read `packet+0`, `packet+1`, or `packet+2`; dispatcher case `4` performs the opcode/subcommand dispatch before the same decode/alert/close sequence.
  - Rejected alternatives: length at `packet+2`, null-terminated packet string, UTF-16 packet string. None match IDA instructions.
  - Impact: target page should record `packet+3` as byte length and `packet+4` as narrow message payload.

- String conversion semantics:
  - Best inference: the narrow message is in process ANSI code page (`CodePage 0`, `CP_ACP`), not UTF-8 and not already UTF-16. The helper copies exactly the byte length, null-terminates the local char buffer, calls `MultiByteToWideChar(0, 0, bytes, length, wide, 0x100)`, then null-terminates the wide buffer at `(unsigned char)return`.
  - Evidence checked: disassembly at `0x004add96-0x004addcb`; `0x100` is 256 decimal (Verified with int_convert.py). The machine code `movzx eax, al` after `MultiByteToWideChar` proves the low-byte return behavior.
  - Rejected alternatives: `-1` null-terminated conversion, caller-supplied UTF-16, or Korean string resource literal. The text is server packet payload, not a static `.rdata` literal.
  - Impact: completion can rise because the exact string conversion is now validated. Final C++ still needs a deliberate representation because the low-byte return behavior is decompiler-shaped but binary-real.

- ExchangeAlertPane/global singleton ownership:
  - Best inference: `0x0069b330` is `g_pExchangeAlertPane`, owned by `ExchangeDialog.cpp`/`ExchangeAlertPane`.
  - Evidence checked: `xrefs_to 0x0069b330` returns nine refs: dispatcher `0x004ad611`/`0x004ad739`, cancel helper `0x004addd3`, ready helper `0x004adf51`, constructor `0x004b04ff`/`0x004b0506`, clear/destructor/close helper `0x004b0860`, `0x004b09d6`, `0x004b0b20`. Existing [UID:0000QV] and [UID:0002VZ] docs agree.
  - Rejected alternatives: item-dialog or mix-dialog singleton. Adjacent `0x0069b328` and `0x0069b32c` are different slots.
  - Impact: owner/emitter route through ExchangeDialog is strong.

- Add-item cleanup semantics:
  - Best inference: after closing the exchange dialog, the helper closes an active `AddItemDialog` picker if `dword_69B328` is nonzero. This is cleanup of a dependent picker, not ownership of the helper by ItemDialogs.
  - Evidence checked: `xrefs_to 0x0069b328` includes reads at dispatcher `0x004ad670` and helper `0x004ade32`, plus AddItemDialog publish/accessor/destructor refs. The helper calls the generic close/remove helper `0x0049dad0` on the active pointer.
  - Rejected alternatives: `dword_69B328` as exchange alert pointer, or as reason to move `00014O` to `ItemDialogs`.
  - Impact: target docs should name this as AddItemDialog cleanup only.

- Duplicate/no-direct-xref relationship:
  - Best inference: `00014O` is a retained out-of-line duplicate/helper for the dispatcher cancel path. The live packet dispatcher already contains equivalent source behavior in subcommand `4`.
  - Evidence checked: `xref_query(to 0x004add40)` and `xrefs_to 0x004add40` return zero xrefs; `decompile 0x004ad320` case `4` repeats the decode, alert replacement, ExchangeDialog close, and add-item cleanup sequence.
  - Rejected alternatives: direct caller missed in ordinary code, vtable slot, jump-table entry, or padding. IDA has a normal function object for `0x004add40`, but no code/data xrefs to its start.
  - Impact: this is the main final-C++ blocker. Emitting a formal standalone method now could duplicate behavior incorrectly unless the broader ExchangeDialog source decides whether to keep an out-of-line helper, inline it, or route dispatcher case `4` through it.

- Source-authored helper versus compiler artifact:
  - Best inference: source-authored or source-declared helper body retained by the build, possibly because the source helper was inlined into the dispatcher while an out-of-line copy remained. It is not compiler-only glue.
  - Evidence checked: full SEH/stack-cookie function prologue, local message buffers, real Win32/API calls, owner-specific globals, allocation and constructor calls, closing UI state, and source-neighborhood placement.
  - Rejected alternatives: scalar deleting destructor, adjustor thunk, padding/alignment, switch table, or runtime library helper.
  - Impact: keep `RECONSTRUCTABLE:TRUE`; do not reclassify as ignored. Still keep C++ blank until source integration is safe.

- Generated-output pollution:
  - Best inference: active docs are more reliable than `simroot_v2` for this target.
  - Evidence checked: `simroot_v2/class_RankingDialog.cpp` still emits `// NTK_ScopedInstall(HandleRankingAlertMessage, 0x004add40)` and a `RankingDialog::HandleRankingAlertMessage` body, while by-class `RankingDialog.md` already flags `0x004add40` and `0x004ade60` as unrelated generated inclusions. `simroot_v2/class_ExchangeDialog.cpp` omits `00014O` and still uses stale `DL_20` resource names.
  - Rejected alternatives: moving target to RankingDialog because generated output says so, or trusting generated ExchangeDialog omissions as non-existence.
  - Impact: recommend adding a clearer support-doc note that `0x004add40` and `0x004ade60` are ExchangeDialog helpers, not ranking helpers.

- Score/source-placement/final-C++ impact:
  - Best defensible score after report evidence is `86/89`: report evidence supports ownership, range, packet semantics, globals, route, and duplicate-source interpretation, but remains below final-audit and still blocked for formal C++.
  - Existing docs validated: owner, main behavior, packet length/source bytes, no-direct-xref caveat, ExchangeAlertPane constructor, AddItemDialog cleanup, and sibling [UID:00014P] relationship.
  - Existing docs to revise: stale "95/95 gate" wording, missing `0x0049eb90` slide/animation close callee note, generated RankingDialog pollution note, and coverage row's "below reconstruction gate" phrasing.
  - Final C++: do not populate the formal C++ block yet even though the recommended score would clear the minimum numeric gate.

## Evidence Standards Used
- IDA MCP facts: `idb_open`, `lookup_funcs`, `decompile`, `xref_query`, `xrefs_to`, `callees`, `insn_query`, `get_bytes`, and `int_convert` on 2026-06-17 against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Documentation evidence: target page, [UID:00014L], [UID:00014P], [UID:00014V], [UID:00014K], [UID:00004R], [UID:0000J9], [UID:00004Q], [UID:0000QV], [UID:0002VZ], [UID:0002AY], proposed source tree, generated coverage, and prior B001 reports for `00014T`/`00014V`.
- Generated evidence: `source-3/simroot_v2` and `project-documentation/auto-generated/-ag-memory-coverage.md`, treated as leads and pollution checks only.
- Negative evidence: no xrefs to `0x004add40`, generated RankingDialog ownership mismatch, no evidence that `00014O` is an alert class method, no evidence that AddItemDialog cleanup makes ItemDialogs the owner.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs 0x004add40` -> `sub_4ADD40`, size `0x11f` / 287 bytes (Verified with int_convert.py).
  - `lookup_funcs 0x004ade5e` -> same function; `0x004ade5f` -> not a function; `0x004ade60` -> `sub_4ADE60`.
  - `get_bytes 0x004ade50` shows final epilogue bytes ending `5d c2 04 00 cc 55 8b ec...`, so `0x004ade5c-0x004ade5e` is `retn 4`, `0x004ade5f` is `0xcc`, and `0x004ade60` starts the ready helper prologue.
  - `get_bytes 0x004add30` shows `retn 4` then twelve `0xcc` bytes before the `0x004add40` prologue, matching separation from [UID:00014N].
- Behavior facts:
  - Decompile shows `packet+3` byte length, `packet+4` source bytes, local `CHAR[256]`, local `WCHAR[256]`, and `MultiByteToWideChar`.
  - Allocation is `0x270` / 624 bytes (Verified with int_convert.py), followed by `sub_4B0490(message, this, off_613A18, 0)`.
  - `off_613A18` is [UID:0001OC] shared UTF-16 `OK`.
  - The helper reads `g_pExchangeAlertPane`, closes it through the virtual close path if present, calls `0x0049eb90` slide/animation close, calls `0x0049dad0` generic close/remove on `this`, then closes `g_pAddItemDialog` if present.
- Xref facts:
  - `xref_query(to 0x004add40)` reports zero xrefs.
  - `xref_query(to 0x004ade60)` also reports zero xrefs, matching the sibling duplicate-helper pattern.
  - `xrefs_to 0x004b0490` reports constructor calls from dispatcher `0x004ad656`/`0x004ad775`, cancel helper `0x004ade18`, and ready helper `0x004adf8d`.
  - `xrefs_to 0x0069b328` includes cancel helper read `0x004ade32`; `xrefs_to 0x0069b330` includes cancel helper read `0x004addd3`.
- Negative IDA facts:
  - No ordinary caller, vtable slot, or data pointer to `0x004add40` was found.
  - No IDA evidence supports the generated `RankingDialog::HandleRankingAlertMessage` ownership.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ad320-0x004ad7b3` | `00014L` `ExchangeDialogPacketDispatcher` | Live virtual exchange packet dispatcher; includes cancel subcommand case | True | `00004R` | `84/90` | supporting context |
| `0x004add40-0x004ade5e` final-byte style, half-open `0x004add40-0x004ade5f` | `00014O` target | Retained cancel-alert helper/out-of-line duplicate | True | `00004R` | current `82/88`, recommend `86/89` | keep attached, no formal C++ |
| `0x004ade5f-0x004ade60` | none | One `0xcc` alignment byte | False | none | n/a | document as padding/boundary |
| `0x004ade60-0x004adfab` | `00014P` `ExchangeDialogReadyAlertHelper` | Retained ready-alert sibling helper | True | `00004R` | `82/88` | supporting context |
| `0x004b0490-0x004b0ba5` | `00014V` `ExchangeDialogTail` | Mixed exchange/item/mix/control tail inventory | False | none | `90/92` | supporting context |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004add40` | zero xrefs to start | Retained helper is not directly called by current IDA static graph. |
| `0x004ad5a9-0x004ad681` | dispatcher case `4` | Equivalent live cancel path inside [UID:00014L]. |
| `0x004addd3` | read `0x0069b330` | Checks active exchange alert singleton. |
| `0x004ade18` | call `0x004b0490` | Constructs `ExchangeAlertPane`. |
| `0x004ade2d` | call `0x0049dad0` | Closes/removes the ExchangeDialog. |
| `0x004ade32` | read `0x0069b328` | Checks active AddItemDialog singleton. |
| `0x004ade3c` | call `0x0049dad0` | Closes/removes active AddItemDialog if present. |

## Documentation Evidence And IDA Status
- Executed B-report search:
  - Searched `Agent-B001/research/executed`, `Agent-B002/research/executed`, and `Agent-B003/research/executed` for `00014O`, `0x004add40`, `ExchangeDialogCancelAlertHelper`, contained/sibling `00014P`, `00014L`, and `00014V` terms.
  - No executed report for `00014O` itself was found.
  - Prior reports found and used only as leads: B001 `00014T-ItemExchangeMixDialogs.md`, B001 `00014V-ExchangeDialogTail.md`, and B001 `000342-SharedReturnTrueVirtualHelper.md`. Their split/container conclusions for the overlapping exchange/item tail are consistent with current IDA checks, but they do not replace the direct `00014O` analysis above.
- Existing docs that support the conclusion:
  - [UID:00014O] already records packet length/message decode, alert replacement, AddItemDialog cleanup, no-direct-xref caveat, and ExchangeDialog ownership. IDA MCP revalidated those claims.
  - [UID:00014L] documents the live dispatcher cancel case and duplicate relationship. IDA MCP revalidated the subcommand `4` body.
  - [UID:00004R] and [UID:0000J9] describe `ExchangeDialog.cpp` as owning exchange live trade, packet dispatcher, money, ready/cancel flow, `ExchangeAlertPane`, and `g_pExchangeAlertPane`.
  - [UID:0000QV] and [UID:0002VZ] support the exchange-alert singleton name and owner.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page and several owner pages still say final C++ remains blank "below the 95/95 gate". The current rule is combined score plus emitter route; the actual blocker is source shape/no-xref duplicate risk, not the old gate.
  - The target callee summary should mention `0x0049eb90` as the slide/animation close path before `0x0049dad0`, not only generic dialog close.
  - `simroot_v2/class_RankingDialog.cpp` incorrectly emits `0x004add40` as `RankingDialog::HandleRankingAlertMessage`. This is generated pollution, not source ownership.
  - `simroot_v2/class_ExchangeDialog.cpp` omits `00014O` and uses stale `DL_20` names; the resource docs and ExchangeDialog docs already correct this to `DLGEXC1.*`.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` lists [UID:00014O] as emitting through `00004R` to `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` currently exists but is zero bytes because the relevant code blocks are blank.
  - `by-memory/-coverage-report.md` row for `00014O` is stale if the supervisor accepts the recommended evidence update.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog
- Evidence for: `this` is the ExchangeDialog instance, packet fields are exchange server packet fields, helper closes ExchangeDialog, helper shares behavior with the ExchangeDialog packet dispatcher, and the class page already owns the sibling cancel/ready helpers.
- Evidence against: no direct xrefs to the helper start. This weakens source-callgraph confidence but not semantic ownership.
- Decision: accepted as canonical owner.

### 2. [UID:0000J9] ExchangeDialog.cpp
- Evidence for: this is the source root for `ExchangeDialog`, `ExchangeAlertPane`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `g_pExchangeAlertPane`; proposed path is `NexusTK/ui/dialogs/`.
- Evidence against: by-structure says canonical owner should be the narrow class when the helper belongs directly to a class. File UID is the emission root, not the direct semantic owner.
- Decision: accepted as route through `00004R`, not as direct canonical owner.

### 3. [UID:00004Q] ExchangeAlertPane
- Evidence for: the helper constructs an `ExchangeAlertPane` and closes any existing active alert.
- Evidence against: it decodes an exchange packet, closes `ExchangeDialog`, and closes `AddItemDialog`; it is the producer/caller of alert UI, not an alert method.
- Decision: rejected as direct owner.

### 4. [UID:0000KE] ItemDialogs / [UID:000007] AddItemDialog
- Evidence for: helper closes `dword_69B328` if active.
- Evidence against: that is dependent cleanup after exchange cancellation. AddItemDialog does not own packet decode or exchange alert creation.
- Decision: rejected as direct owner.

### 5. RankingDialog generated owner
- Evidence for: stale `simroot_v2/class_RankingDialog.cpp` emits a generated `HandleRankingAlertMessage` at `0x004add40`.
- Evidence against: IDA behavior uses exchange globals/classes, docs already flag generated RankingDialog pollution, and no ranking state or ranking vtable refs appear in the helper.
- Decision: rejected. This should be recorded as generated-source pollution if not already tracked strongly enough.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file or grouping is recommended.
- Likely full contents: existing `ExchangeDialog.cpp` already covers the correct feature file contents.
- Candidate related items that belong: `00014L`, `00014M`, `00014N`, `00014O`, `00014P`, `ExchangeAlertPane`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, `g_pExchangeAlertPane`, and exchange resource/vtable children.
- Candidate related items rejected: `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, `MyItemListPane`, and `FunctionObjects` remain in their established source owners except where ExchangeDialog consumes them.
- Standalone, narrow, or broad source-file inference: narrow helper inside a broad existing feature file, not standalone.

## Negative Evidence Summary
- No xrefs to `0x004add40` means no direct static proof of source call sites.
- The dispatcher already contains the equivalent cancel path; final source must not blindly emit both a helper and a duplicate dispatcher block as if both are necessarily hand-called.
- Generated `RankingDialog` ownership is contradicted by IDA behavior and current by-* docs.
- AddItemDialog singleton cleanup is a consumer/cleanup relationship, not owner evidence.
- Physical adjacency to ExchangeDialog helps, but the decisive evidence is the combined packet/global/class behavior.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00014O] yet.

The target would clear the minimum numeric/emitter gate if rescored to `86/89`, but final source is blocked by a concrete source-shape issue: IDA proves no direct xrefs to the helper start while the dispatcher inlines the same cancel path. The safer source-integration decision belongs to a broader `ExchangeDialog.cpp` reconstruction pass that can decide whether the original code had an inline helper with a retained out-of-line copy, a private uncalled method, or duplicated packet-handler source.

Non-populate draft shape for future use only:

```cpp
// Do not paste into RECONSTRUCTION_CPP yet.
// Descriptive source shape only; method and dependency names are not final.
void ExchangeDialog::HandleCancelAlertPacket(const unsigned char *packet)
{
    char text[256];
    wchar_t message[256];

    unsigned int length = packet[3];
    memmove(text, packet + 4, length);
    text[length] = 0;

    int converted = MultiByteToWideChar(CP_ACP, 0, text, length, message, 256);
    message[(unsigned char)converted] = 0;

    if (g_pExchangeAlertPane)
        g_pExchangeAlertPane->Close(1);

    new ExchangeAlertPane(message, this, g_szDialogOk, 0);

    this->SlideClose();
    CloseDialogPane(this);

    if (g_pAddItemDialog)
        CloseDialogPane(g_pAddItemDialog);
}
```

Concrete reasons not to populate now:
- No direct xref proves the source call shape.
- The dispatcher already contains the live cancel behavior.
- `SlideClose`, `CloseDialogPane`, `ExchangeAlertPane::Close`, and `g_szDialogOk` are descriptive placeholders, not final project names.
- The exact return type is likely source-level `void`, but the binary returns the last close helper's `eax` incidentally and no caller consumes it.

## Final Recommendation
- Exact changes recommended for target metadata:
  - `COMPLETION:86`
  - `CONFIDENCE:89`
  - keep `CANONICAL_OWNER:00004R`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00004R`
  - keep `RECONSTRUCTION_CPP CODE` blank
- Exact documentation changes recommended:
  - Replace old `95/95` gate wording with the current combined-score/emitter gate plus the source-shape blocker.
  - Add the 2026-06-17 IDA evidence for no xrefs, exact byte boundary, dispatcher duplicate case, `0x0049eb90` slide close, and generated RankingDialog pollution.
  - Clarify range wording: current filename's `0x004ade5e` is the final byte; IDA half-open function extent is `0x004add40-0x004ade5f`; `0x004ade5f` is a one-byte alignment pad before `0x004ade60`.
- Exact parent assignments recommended: no change.
- Exact items left no-owner/non-emitting and why: none for this target. Broad [UID:00014V] remains non-emitting as already accepted, but `00014O` itself stays emitting with blank code until source shape is safe.

## Coverage Row Recommendation
Do not edit `by-memory/-coverage-report.md` directly in this report-only task. If the supervisor accepts the score/source-quality update, replace the current `00014O` row in address order after [UID:00014N] and before [UID:00014P] with:

```text
    - [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) 0x004add40-0x004ade5e | helper | ExchangeDialogCancelAlertHelper : reconstructable : 86% : strong : ExchangeDialog cancel-alert packet helper; 2026-06-17 IDA recheck confirms `0x11f` / 287-byte function size (Verified with int_convert.py), `packet+3` byte length, `packet+4` CP_ACP message copy/convert, active exchange-alert replacement, ExchangeDialog slide/close, AddItemDialog close cleanup, no direct start xrefs, and duplicate dispatcher subcommand-4 source-shape blocker. Keep formal C++ blank until ExchangeDialog source integration decides retained out-of-line helper versus inlined dispatcher helper.
```

## Support Docs To Update
- Target page [UID:00014O]: apply the evidence/gate/score changes above.
- [UID:00014K] `ExchangeDialog` aggregate and [UID:00004R] class page: replace old "below 95/95 gate" phrasing for `00014O` and `00014P` with current source-shape blocker wording when those pages are next edited.
- [UID:0000J9] `ExchangeDialog` file page: add or strengthen the note that `0x004add40`/`0x004ade60` are ExchangeDialog helpers despite stale RankingDialog generated output.
- [UID:0000MZ] / `RankingDialog` docs if edited later: keep the generated-pollution note and explicitly identify `0x004add40` as [UID:00014O] if useful.
- `wave3_data_issues.md` or equivalent generated-data issue ledger: optional follow-up for `class_RankingDialog.cpp` falsely owning `0x004add40` and `0x004ade60`, plus `class_ExchangeDialog.cpp` omitting the IDA-confirmed helpers.

## Follow-Up Actions
- Supervisor actions:
  - Apply the metadata/body/coverage row recommendations if accepted.
  - Do not paste the illustrative C++ into the formal target C++ block.
  - Re-run targeted validation after applying by-* edits.
- A-agent actions:
  - When working ExchangeDialog source, decide whether dispatcher case `4` should call a private helper or remain inlined while `00014O` represents a retained out-of-line clone.
  - Avoid using `simroot_v2/class_RankingDialog.cpp` as authority for `0x004add40`.
- B002 future research actions:
  - A sibling pass on [UID:00014P] should apply the same current-gate/source-shape reasoning.

## Confidence
- Recommendation confidence: high for owner/emitter and score update; medium-high for no-populate C++ decision.
- Score confidence: `86/89` is justified by exact function/range/behavior/owner evidence, but not higher because source-facing names, direct reachability, and final integration remain unresolved.
- Remaining uncertainty: original helper name, source return type, whether this was an inline helper with retained out-of-line body, and final names for alert/close/slide methods.

## Validator Results
- Validator was not run because this was report-only work and no by-* pages were edited.
- IDA MCP validation commands/evidence used:
  - `idb_open` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - `lookup_funcs` for `0x004add40`, `0x004ade5e`, `0x004ade5f`, `0x004ade60`, `0x004ad320`, `0x004b0490`
  - `decompile` for `0x004add40`, `0x004ad320`, `0x004b0490`, `0x0049dad0`, `0x0049eb90`
  - `xref_query` / `xrefs_to` for `0x004add40`, `0x004ade60`, `0x004b0490`, `0x0069b328`, `0x0069b330`
  - `callees 0x004add40`
  - `insn_query` for `0x004add40-0x004ade60`
  - `get_bytes` for `0x004add30`, `0x004add40`, `0x004ade50`
  - `int_convert` for `0x11f`, `0x270`, `0x100`, `0x42`, `0x04`, `0x4a`, `0xa0`, and `0x30c`
- Recommended post-edit validation:

> Executable block R001 was removed from this report and preserved verbatim in [00014O-exchange-dialog-cancel-alert-source-quality-removed.md](00014O-exchange-dialog-cancel-alert-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00014O-exchange-dialog-cancel-alert-source-quality.md`
- Modified:
  - None outside the assigned B002 research folder.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00014O-exchange-dialog-cancel-alert-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00014O"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014O-exchange-dialog-cancel-alert-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00014O-exchange-dialog-cancel-alert-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
