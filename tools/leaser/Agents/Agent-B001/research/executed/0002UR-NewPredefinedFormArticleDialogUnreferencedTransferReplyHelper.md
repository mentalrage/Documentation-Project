# 0002UR NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper Ownership / Reachability Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002UR] as a reconstructable source-shaped retained alternate transfer-reply helper, score `85/90`, with `AUTOGEN_PARENT_UID` blank.
- Final disposition: not compiler glue, not padding, not a `TransferReplyPredefinedAlert` method, and not currently reachable through any IDA-visible call, vtable slot, raw VA/RVA pointer, or immediate reference.
- Required action: accept the B001-030 repair to `0002UR`, keep it parent-blank, and do not assign it until a direct `NewPredefinedFormArticleDialog` parent clears `85/85` and the project decides whether retained unreferenced alternate helpers should emit with the source cluster.
- Confidence: high for the binary facts and no-live-reference conclusion; medium-high for the source-treatment inference because original source policy for retained unreferenced helpers is still project-level, not IDA-provable.

## Supporting Research

## Target

- Target UID: `0002UR`
- Target path: `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
- Source queue/report row: B001-030 assignment from supervisor; `reviewed-no-85-under-review`.
- Starting state: `82/88`, `RECONSTRUCTABLE:TRUE`, parent blank. Batch108 had raised the page from `80/86` but left it below gate because no live xref/callback/raw pointer path or source-dead-code decision was proven.
- Final state after B001-030 edits: `85/90`, `RECONSTRUCTABLE:TRUE`, parent blank.

## Executive Recommendation

`0x00478aa0-0x00478bd9` is best modeled as a retained source-authored alternate packet-layout helper in the `NewPredefinedFormArticleDialog` cluster. It is function-shaped application code with SEH/security-cookie setup, packet parsing, ANSI-to-wide conversion, allocation, and `TransferReplyPredefinedAlert` vtable installation. The additional IDA work resolves live reachability negatively enough to raise the child to `85/90`, but it does not justify assignment.

The exact blocker is parent-side, not child evidence. Direct `NewPredefinedFormArticleDialog` candidates are below strict `85/85`: [UID:0000LT] is `88/80`, [UID:000098] is `84/80`, and [UID:0000ZL] is `82/86`. [UID:0000F6][TransferReplyPredefinedAlert] is `85/88`, but it is not the direct owner: `0002UR` constructs that alert, while the real alert virtual action is `0x004790a0` with vtable slot `0x006141f0`.

No split was needed. The exact child page already existed and the range is exact.

## Supervisor Active Recheck

- Supervisor asked for decisive checks only: raw VA/RVA pointer scan for `0x00478aa0`, direct xrefs/callers, vtable neighborhood around the live sibling and alert action, comparison with `0002UQ`, and parent gate state for `0000LT`, `000098`, `0000ZL`, and `0000F6`.
- Those checks were completed. They support repairing the target child to `85/90` but not assigning it.
- This is the final B001-030 report. No other target was started.

## Inference Research Guidance Check

The inference rule used here is: lack of absolute original-source proof is not enough to stop, but negative evidence must be weighed against positive structural evidence. The positive source evidence is the full application-level function body, exact alert construction behavior, and repeated pattern in the earlier `NewArticleDialog` pair. The negative reachability evidence is unusually strong because live siblings in the same neighborhood do have visible `.rdata` pointer slots while `0x00478aa0` does not.

Existing docs were treated as hypotheses. The old target page correctly recorded no xrefs and no raw pointer hits, but still left source treatment unresolved. B001-030 changes that to the best defensible inference: retained unreferenced alternate helper, source-shaped and reconstructable, but non-emitting/parent-blank until a direct parent clears gate and retained-helper emission policy is settled.

## Evidence Standards Used

- IDA MCP: `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `search data_ref`, `search code_ref`, `search immediate`, `find_insn_operands`, `decompile`, and `disasm`.
- IDAPython through IDA MCP: raw little-endian VA/RVA pointer scan across loaded segments and vtable slot dumps.
- Documentation evidence: target page, live sibling `0002UQ`, aggregate `0000ZL`, class `000098`, file parent `0000LT`, alert class `0000F6`, alert action `0000ZN`, `BulletinReplyAlerts`, generated coverage, and coverage report.
- Negative evidence was treated as meaningful because comparable live functions in the same local hierarchy have visible data/vtable references.

## IDA MCP Facts

- IDB identity: `NexusTK.exe`, base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function facts: `sub_478AA0` is `0x00478aa0-0x00478bd9`, size `0x139`, terminal `retn 4`. Neighboring live sibling `sub_478940` is `0x153`; submit helper `sub_478BE0` is `0x3ae`; event handler `sub_4782B0` is `0xb3`; alert action `sub_4790A0` is `0x6f`; raw constructor `0x00479050` is not an IDA function.
- Boundary facts: target has `0xcc` alignment before and after; previous docs and current disassembly agree on exact range.
- Decompilation facts: `0x00478940` checks `to_char_type(a2 + 1) == 6`, then reads mode at `a2 + 2`, length at `a2 + 3`, bytes at `a2 + 4`. `0x00478aa0` omits the subcommand guard and reads mode at `a2`, length at `a2 + 1`, bytes at `a2 + 2`.
- Shared behavior facts: `0x00478940` and `0x00478aa0` have the same callee set, including `sub_516030`, `unknown_libname_11`, `sub_4A1360`, `std::_Narrow_char_traits<char,int>::to_char_type`, `sub_516220`, `MultiByteToWideChar`, `sub_4F4AA0`, `sub_49FEB0`, and `@__security_check_cookie@4`.
- Alert construction facts: target allocates `0x274` bytes, passes `off_613A18` to `sub_49FEB0`, installs `TransferReplyPredefinedAlert` vtables at `0x00614194`, `0x006141fc`, and `0x0061422c`, and stores the reply mode byte at alert offset `0x270`.
- Direct xrefs/callers: IDA reports no ordinary callers and no `xrefs_to` for `0x00478aa0`. `0x00478940` has data xref `0x006140ac`; `0x004782b0` has data xref `0x006140e8`; `0x004790a0` has data xref `0x006141f0`; `0x00478be0` has a code caller at `0x0047827e`.
- Raw pointer scan: IDAPython segment scan found `0x00478940 -> 0x006140ac`, `0x004782b0 -> 0x006140e8`, and `0x004790a0 -> 0x006141f0`. It found no VA or RVA pointer hits for `0x00478aa0`.
- Search facts: `search data_ref`, `search code_ref`, and `search immediate` found no target hits for `0x00478aa0` or RVA `0x78aa0`; the same searches found the expected live sibling/action pointer slots for `0x00478940` and `0x004790a0`.
- Vtable facts: local vtable dump around `0x00614050` and `0x00614194` shows `0x006140ac = 0x00478940`, `0x006140e8 = 0x004782b0`, and `0x006141f0 = 0x004790a0`. No checked slot contains `0x00478aa0`.
- Analog pattern: earlier `NewArticleDialog` functions show the same pair: `0x004772f0` is a `0x153`-byte vtable-backed handler with slot `0x0061400c`; `0x00477450` is a `0x139`-byte shifted-layout helper with no xrefs and no raw VA/RVA pointer hits.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00478aa0-0x00478bd9` | `0002UR` / `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md` | Retained alternate packet-layout transfer-reply alert helper | `TRUE` | blank | `85/90` | Repaired; not assigned because parent gate/source-emission policy blocks. |
| `0x00478940-0x00478a93` | `0002UQ` | Live vtable-backed predefined transfer-reply packet handler | `TRUE` | `0000LT` in existing doc | `78/86` | Comparator only in this pass; below current strict gate and should be separately audited if supervisor wants sibling cleanup. |
| `0x004777a0-0x00478f8e` | `0000ZL` | NewPredefinedFormArticleDialog aggregate | `TRUE` | `0000LT` | `82/86` | Updated wording only; still below direct parent gate for `0002UR`. |
| `NewPredefinedFormArticleDialog` class | `000098` | Class-level owner candidate | `TRUE` | `0000LT` | `84/80` | Updated wording only; still below strict parent gate. |
| `NewPredefinedFormArticleDialog` file | `0000LT` | File-level owner candidate | n/a | n/a | `88/80` | Best source file if emitted, but confidence below parent gate. |
| `TransferReplyPredefinedAlert` class | `0000F6` | Constructed alert object and action owner | `TRUE` | `0000HW` | `85/88` | Rejected as direct owner of `0002UR`; it owns alert constructor/action, not the helper that creates the alert. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00478aa0` | no callers, no `xrefs_to`, no data/code/immediate hits, no raw VA/RVA hits | No current live reachability path in IDA-visible code/data. |
| `0x00478940` | data pointer at `0x006140ac` | Live sibling is vtable-backed; this is the contrast case. |
| `0x004782b0` | data pointer at `0x006140e8` | Event handler has a vtable slot in the same class neighborhood. |
| `0x004790a0` | data pointer at `0x006141f0` | Actual `TransferReplyPredefinedAlert` virtual action is vtable-owned by the alert class. |
| `0x00478be0` | code caller at `0x0047827e` | Submit helper is directly called from button handler. |
| `0x00614194`, `0x006141fc`, `0x0061422c` | stores from `0x478b99`, `0x478b9f`, `0x478ba9` | Target installs alert vtables but is not itself stored in those vtables. |
| `0x004772f0` / `0x00477450` | `0x004772f0 -> 0x0061400c`; `0x00477450` no pointer hits | Earlier article-dialog analog supports retained alternate helper pattern. |

## Documentation Evidence And IDA Status

- Target page supported exact behavior and prior no-xref scans but had not reached final disposition. It now records the decisive B001-030 negative reachability evidence and score repair.
- `0002UQ` is a useful live comparator: it is the same helper body plus a subcommand guard and has the expected vtable/data pointer. It was not repaired in this pass because the supervisor narrowed the task to `0002UR`; its `78/86` score and old parent assignment remain a separate cleanup candidate.
- `0000ZL` previously said `0x00478aa0` reachability remained unresolved. It now records the negative reachability result while keeping its own `82/86` score.
- `000098` previously said `0002UR` was kept out until reachability was proven. It now says reachability was resolved negatively but source-emission/parent gate remain blocked.
- Generated memory coverage still listed `0002UR` as unassigned at the beginning of this pass. The validator file scan reported autogen reports unchanged, so generated report refresh is a later generated-state concern, not a manual edit.

## Ranked Ownership Analysis

### 1. Retained `NewPredefinedFormArticleDialog` alternate helper

- Evidence for: address locality inside the exact dialog aggregate; identical callee set and alert construction pattern to live sibling `0002UQ`; packet-field shift consistent with an alternate handler/helper form; constructs `TransferReplyPredefinedAlert` using the dialog `this`; analogous retained/unreferenced shifted helper exists in the earlier `NewArticleDialog` area.
- Evidence against: no live pointer/callback path, and direct parent docs are below `85/85`.
- Decision: accepted as best source/behavior inference. Repaired child to `85/90`; keep parent blank.

### 2. Stripped callback target or missed dispatch table

- Evidence for: the function has a callback-like signature and sits next to a live vtable handler.
- Evidence against: no callers, no xrefs, no raw VA/RVA pointer hits, no immediate hits, no vtable slot, and live comparators in the same area do have `.rdata` pointer slots.
- Decision: rejected for current assignment. A future real pointer/callback discovery would change the decision.

### 3. `TransferReplyPredefinedAlert` direct ownership

- Evidence for: target allocates and initializes a `TransferReplyPredefinedAlert`.
- Evidence against: the target is not in the alert vtable; the real alert virtual action is `0x004790a0` at slot `0x006141f0`; construction use is consumer evidence, not ownership proof.
- Decision: rejected as direct parent. `0000F6` clears `85/85`, but assigning `0002UR` there would be semantically wrong.

### 4. Compiler-generated glue, padding, or non-reconstructable dead bytes

- Evidence for: no live refs can sometimes indicate dead code.
- Evidence against: the body is complete handwritten-style application logic with packet parsing, SEH frame, buffer conversion, allocation, helper calls, and vtable stores. It is not an adjustor thunk, scalar deleting destructor, jump table, alignment, or runtime helper.
- Decision: rejected. Keep `RECONSTRUCTABLE:TRUE`.

### Proposed New File / Grouping

No new file or grouping is recommended. If this helper is ever emitted, the best existing source file candidate is `ui/dialogs/NewPredefinedFormArticleDialog.cpp` under [UID:0000LT]. The likely broader contents are the already documented constructor, parser, button/event/paint handlers, live transfer reply handler, retained alternate helper, and submit body. Current evidence does not justify creating a separate source owner for one unreferenced helper.

## Negative Evidence Summary

- No ordinary direct callers to `0x00478aa0`.
- No `xrefs_to 0x00478aa0`.
- No `search data_ref`, `search code_ref`, or `search immediate` hits for `0x00478aa0`.
- No raw little-endian VA or RVA pointer hits for `0x00478aa0` across loaded segments.
- No checked vtable slot around `NewPredefinedFormArticleDialog` or `TransferReplyPredefinedAlert` contains `0x00478aa0`.
- The live sibling, event handler, and alert action all do have pointer slots, so the absence for `0x00478aa0` is meaningful rather than a general limitation of the scan.

## Final Recommendation

- Exact changes applied: raised `0002UR` from `82/88` to `85/90`; documented negative reachability, analog pair evidence, score rationale, and parent-gate blocker; updated `0000ZL` and `000098` wording so they no longer preserve old "reachability unresolved" text.
- Exact parent assignment applied: none. `AUTOGEN_PARENT_UID` remains blank for `0002UR`.
- Exact items left unassigned and why: `0002UR` remains unassigned because direct `NewPredefinedFormArticleDialog` parent candidates are below `85/85`, and `TransferReplyPredefinedAlert` is not the direct owner.
- Future work outside this assignment: audit/repair `0002UQ` under the strict gate if desired; repair `0000LT`/`000098`/`0000ZL` only with broader evidence; decide project-wide policy for retained unreferenced alternate helpers.

## Follow-Up Actions

- Supervisor: review and accept `0002UR` as `85/90`, reconstructable, parent blank.
- A-agent: do not assign `0002UR` to `0000F6`; only revisit assignment after direct `NewPredefinedFormArticleDialog` parent docs clear `85/85` or a real callback pointer is found.
- B001 future research: if assigned later, compare `0002UQ` and the earlier `NewArticleDialog` pair as a family-level retained-helper policy question.

## Confidence

- Recommendation confidence: high for parent-blank and no-current-live-pointer conclusion.
- Score confidence: `85/90` is defensible. Completion is not higher because original source-emission policy remains open and direct parent candidates are below gate.
- Remaining uncertainty: whether the original source intentionally retained the alternate helper and whether rebuilt source should emit it. IDA can prove the body and absence of current references; it cannot prove the original developer's emission intent.

## Validator Results

- `python tools\validator.py --mode file --file "by-memory\0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md" --apply`
  - Result: exit `0`; scanned `1`; `ok: 1`; `completion_update 0002UR ... 85`; `confidence_update 0002UR ... 90`; autogen reports unchanged.
- `python tools\validator.py --mode file --file "by-memory\0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md" --apply`
  - Result: exit `0`; scanned `1`; `ok: 1`; autogen reports unchanged.
- `python tools\validator.py --mode file --file "by-class\NewPredefinedFormArticleDialog.md" --apply`
  - Result: exit `0`; scanned `1`; `ok: 1`; `stats_row_update 000098 project-level/-auto-completion-stats.md Low_Confidence`; autogen reports unchanged.
- Unresolved validator warnings/errors: none for the targeted file scans. The validator emitted its normal `autogen_cpp_noop` lines for unrelated roots.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002UR-NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
- Modified directly: `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
- Modified directly: `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
- Modified directly: `by-class/NewPredefinedFormArticleDialog.md`
- Validator-derived updates reported: `project-level/-auto-completion-stats.md` and validator registry metadata.
- Renamed: none.
- Moved to executed: none.
