** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# 0003GY UnreferencedThreadDispatchWrapper Live Goal 2 No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` unchanged.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Required action: no owner, emitter, split, merge, reclassification, score change, or `by-memory/-coverage-report.md` edit is recommended.
- Confidence: `86/100`. The function body, boundaries, callee, and absence of source-use references are strongly supported by live IDA MCP and raw PE evidence; the exact original declaration owner remains unproven.

This is a reconstructable no-owner/non-emitting item for a specific reason: the body is real NexusTK source-shaped code, but the current binary evidence does not prove a direct declaration owner or a generated-output route. Under the current by-structure model, `RECONSTRUCTABLE:TRUE` records that the code would need to be recreated if its source context is recovered, while blank `EMITTER_UIDS` prevents the validator from placing a guessed wrapper into `Thread.cpp`, `FileDownloader.cpp`, or any other output file. Emitting it through the best semantic callee owner would be worse than leaving it non-emitting because there is no caller, vtable slot, raw pointer, branch target, or source-use context proving that route.

## Supporting Research

## Target

- Target UID: `0003GY`
- Target path: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, Active 2026-06-14 Live Goal 2 No-Owner Memory Pass.
- Current supervisor classification: assigned to Agent-B001 for fresh no-owner/non-emitting memory review.
- Current scores and parent state: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Current generated coverage state: `auto-generated/-ag-memory-coverage.md` lists the item as `no-owner` with `CANONICAL_OWNER:NONE` and blank emitter fields.

## Executive Recommendation

Keep the target as a single exact by-memory function page. Do not split it: live IDA MCP reports `0x0041b2d0` as one `0x14`-byte function, decimal 20 verified with `int_convert.py`, with padding before and after the body. Do not merge it into the neighboring FileDownloader helper pages because the predecessor and successor have positive FileDownloader evidence that this target lacks.

The strongest forced semantic candidate is [UID:0000EV] `Thread` / [UID:0000OR] `Thread.cpp`, because the only callee is the generic queue-post helper at `0x00596960`. That is not enough for assignment. A callee owner is not automatically the declaration owner of an unreferenced wrapper.

## Supervisor Active Recheck

- The active tracker row assigns [UID:0003GY] to Agent-B001 with current report path `Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-live-goal2-no-owner-pass.md`.
- This was treated as a fresh pass. Prior B-agent reports were read only as evidence leads.
- No split repair was required. The target is already an exact function body, and the surrounding spans are either padding or separately documented functions.

## Inference Research Guidance Check

`inference_research.md` and `by-structure.md` affected the recommendation in three ways:

- Consumer/callee evidence alone is not ownership proof. The call to `0x00596960` makes `Thread` the best semantic candidate, but it does not prove this wrapper was declared in `Thread.cpp`.
- Address adjacency is weak evidence. The target sits inside a broader FileDownloader address inventory, but it has no FileDownloader-specific caller, global, field, message id, vtable ref, or data ref.
- Reconstructable items can stay no-owner/non-emitting while the owner/emitter route is not defensible. This is not a "do nothing" disposition; it is a deliberate block against emitting guessed source.

IDA facts, documentation evidence, and inference are separated below. Existing documentation assumptions were treated as uncertain until checked against live IDA.

## Evidence Standards Used

Evidence used:

- IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `trace_data_flow`, `get_bytes`, `find_bytes`, `entity_query`, and `imports_query`.
- Raw PE scan of `NexusTK.exe` for exact bytes, wrapper-shape bytes, absolute VA/RVA dwords, push-address patterns, and rel8/rel32 branch targets.
- Current project docs for Thread, FileDownloader, adjacent by-memory children, and generated coverage state.
- Negative evidence: no callers, no inbound xrefs, no target VA/RVA byte hits, no branch targets, no vtable/data refs, no filesystem import relation, no source-use context.

## IDA MCP Facts

- IDA session: `a001_goal2_class_batch`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Binary path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Imagebase: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Function and boundary facts:

| Query | IDA MCP result |
| --- | --- |
| `0x0041b2c9` | not a function |
| `0x0041b2d0` | `___std_fs_create_symbolic_link@8`, size `0x14` / decimal 20 verified with `int_convert.py` |
| `0x0041b2db` | inside `0x0041b2d0` |
| `0x0041b2e4` | not a function |
| `0x0041b2f0` | `sub_41B2F0`, size `0x0b` / decimal 11 verified with `int_convert.py` |
| `0x0041b270` | `sub_41B270`, size `0x59` / decimal 89 verified with `int_convert.py` |
| `0x00596960` | `sub_596960`, size `0x50` / decimal 80 verified with `int_convert.py` |
| `0x0058ea60` | `___std_fs_create_symbolic_link@8_0`, size `0x14` / decimal 20 verified with `int_convert.py` |

Disassembly of the target:

```asm
0041b2d0  push ebp
0041b2d1  mov ebp, esp
0041b2d3  push 0
0041b2d5  push [ebp+arg_4]
0041b2d8  push [ebp+arg_0]
0041b2db  call sub_596960
0041b2e0  pop ebp
0041b2e1  retn 8
```

IDA decompilation of the target is equivalent to:

```c
return sub_596960(this, a2, a3, 0);
```

This snippet is evidence only, not a final reconstruction recommendation.

Callee facts:

- `analyze_function 0x0041b2d0`: one basic block, cyclomatic complexity 1, no strings, no constants, no callers, one callee: `sub_596960`.
- `analyze_function 0x00596960`: queue-post helper that builds a six-dword request record, calls `sub_556580`, and calls `ReleaseSemaphore(this[3], 1, 0)`.
- `xrefs_to 0x00596960`: 22 code xrefs across downloader, MiscWorkThread, socket/packet-send, and this unreferenced wrapper. That broad fan-in supports generic Thread helper ownership for the callee, not direct ownership for the caller wrapper.

Xref facts:

| Address | IDA MCP xrefs |
| --- | --- |
| `0x0041b2d0` | `0` inbound xrefs from `xrefs_to`; `xref_query both` reports only an internal function-flow edge from `0x0041b2d0` to `0x0041b2d1` |
| `0x0041b2e4` | `0` xrefs |
| `0x0041b2f0` | one code xref at `0x005f670e`, tied to FileDownloader constructor unwind |
| `0x0041b270` | one code xref at `0x0041c21b`, a positive FileDownloader submit-helper route |
| `0x0058ea60` | no inbound xrefs; separate same-shape wrapper calling `0x0058f690` |
| `0x00634034` `CreateSymbolicLinkW` string | one data xref from `?initialize_pointers@@YAHXZ` at `0x005c710c`, not from this wrapper |

Byte facts:

- `get_bytes 0x0041b2c0 size 64` shows `0xcc` padding at `0x0041b2c9-0x0041b2d0`, target bytes at `0x0041b2d0-0x0041b2e4`, `0xcc` padding at `0x0041b2e4-0x0041b2f0`, and then the `dword_67A738 = 0` helper at `0x0041b2f0`.
- `find_bytes` exact target bytes found one match: `0x0041b2d0`.
- `find_bytes` for the generic wrapper shape found two matches: `0x0041b2d0` and `0x0058ea60`.
- `find_bytes` for little-endian VA `D0 B2 41 00` found zero matches.
- `find_bytes` for little-endian RVA `D0 B2 01 00` found zero matches.

Filesystem-name negative facts:

- `entity_query` strings finds `CreateSymbolicLinkW` at `0x00634034` and `too many symbolic link levels` at `0x00633d98`.
- `imports_query` for `CreateSymbolicLink` and `Symbolic` finds no imports.
- The only xref to the `CreateSymbolicLinkW` string is in `?initialize_pointers@@YAHXZ`, not this wrapper.
- The target has no string refs, no import refs, no path handling, and no filesystem behavior. The IDA name is stale or misapplied.

Raw PE scan facts:

- Exact target bytes: one file hit at VA `0x0041b2d0`.
- Wrapper-shape bytes: two hits, `0x0041b2d0 -> 0x00596960` and `0x0058ea60 -> 0x0058f690`.
- Absolute target dword `0x0041b2d0`: zero hits.
- Target RVA dword `0x0001b2d0`: zero hits.
- `push 0x0041b2d0`: zero hits.
- Rel8/rel32 branch or call target to `0x0041b2d0`: zero hits.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | `by-memory/-ignored.md` | `0xcc` alignment padding | false | none | 100/strong | Already covered; no change |
| `0x0041b2d0-0x0041b2e4` | [UID:0003GY] target | Unreferenced queue-post wrapper | true | none | 86/86 | Keep no-owner/non-emitting |
| `0x0041b2e4-0x0041b2f0` | `by-memory/-ignored.md` | `0xcc` alignment padding | false | none | 100/strong | Already covered; no change |
| `0x0041b2f0-0x0041b2fb` | [UID:0000WK] `ClearFileDownloaderRequestGlobal` | FileDownloader constructor-unwind global clear | true | [UID:0000JC] | 85/92 | Separate neighbor; not part of target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041b2d0` | no inbound code/data xrefs | No proven source-use route or emitter |
| `0x0041b2db` | call to `0x00596960` | Only semantic clue: generic Thread queue post |
| `0x00596960` | 22 code xrefs | Callee is a generic shared queue primitive |
| `0x0041b270` | caller at `0x0041c21b` | Positive FileDownloader evidence exists for predecessor, not for target |
| `0x0041b2f0` | xref from `0x005f670e` | Positive FileDownloader constructor-unwind evidence exists for successor, not for target |
| `0x0058ea60` | no inbound xrefs | Same tiny wrapper idiom appears elsewhere without proving same owner |
| `0x00634034` | xref from `?initialize_pointers@@YAHXZ` | Symbolic-link string belongs elsewhere, not to the target |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0003GY] target page already records exact range, stale IDA name caveat, Thread callee, no xrefs, and `CANONICAL_OWNER:NONE`.
- [UID:0000WI] `FileDownloaderDispatch` records this item as a real unreferenced child inside a mixed address inventory, not as a FileDownloader-owned child.
- [UID:0002CL] `FileDownloaderSubmitCashShopVersionRequest` has the positive caller/message/payload evidence missing from `0003GY`.
- [UID:0000WK] `ClearFileDownloaderRequestGlobal` has the positive unwind/global-write evidence missing from `0003GY`.
- [UID:0000EV], [UID:0000OR], [UID:0001JX], and [UID:0001JY] document `0x00596960` as generic Thread queue infrastructure with broad fan-in.

Existing docs that are stale, incomplete, or contradicted:

- IDA's current `___std_fs_create_symbolic_link@8` function name is contradicted by the target body and by live string/import/xref checks.
- The surrounding FileDownloader aggregate is useful as a physical inventory but must not be treated as direct ownership proof for this target.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently reports `0003GY` as `no-owner` with blank emitters. That is correct for this pass.
- `by-memory/-coverage-report.md` current row remains acceptable. No replacement row is requested:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

## Ranked Ownership Analysis

### 1. Thread / util/Thread.cpp

Evidence for:

- The only callee is `0x00596960`, documented and live-confirmed as a generic Thread queue-post primitive.
- The target preserves `ecx` as the receiver and pushes two stack arguments plus a zero optional argument, matching a convenience wrapper over a queue-post helper.
- Thread docs and live xrefs show `0x00596960` is broad shared infrastructure, not FileDownloader-only or CashShop-only code.

Evidence against:

- No caller, vtable/data reference, raw VA/RVA pointer, branch target, or source-use context reaches `0x0041b2d0`.
- The wrapper sits outside the main Thread/ThreadMan code island.
- The wrapper has no direct Thread field access; it only delegates to a Thread helper.
- The same wrapper shape exists at `0x0058ea60` for a different callee, also unreferenced, proving the tiny idiom is not unique owner evidence.

Decision:

- Best forced semantic candidate, but assignment is below the by-structure owner/emitter gate. Do not set `CANONICAL_OWNER:0000EV`, `CANONICAL_OWNER:0000OR`, or `EMITTER_UIDS:0000OR`.

### 2. FileDownloader / network/FileDownloader.cpp

Evidence for:

- The target is physically located inside the broader [UID:0000WI] FileDownloader dispatch/support inventory.
- Neighboring functions before and after the target are FileDownloader-related.

Evidence against:

- The target is separated from both neighbors by `0xcc` padding.
- It has no FileDownloader global access, no `dword_67A738` receiver evidence, no downloader message id, no payload allocation, no FileDownloader vtable/data ref, and no caller passing the FileDownloader singleton.
- The predecessor `0x0041b270` and successor `0x0041b2f0` each have positive FileDownloader route evidence. This target does not.

Decision:

- Rejected as direct owner and emitter. Do not set `CANONICAL_OWNER:0000JC`, `CANONICAL_OWNER:00004W`, `EMITTER_UIDS:0000JC`, or `EMITTER_UIDS:00004W`.

### 3. CashShopRequest / CashShopVersionRequest

Evidence for:

- The predecessor posts cash-shop version message `10002`.
- Historical generated naming around `0x00596960` has included CashShopRequest pollution.

Evidence against:

- This wrapper has no payload object, no request vtable, no message id, no cash-shop caller, and no request field evidence.
- Current Thread/CashShop docs treat `0x00596960` as generic Thread queue infrastructure unless stronger class-layout evidence proves otherwise.

Decision:

- Rejected. No CashShop owner or emitter is justified.

### 4. Socket / packet sender routes

Evidence for:

- Several socket/packet helpers call the same queue primitive at `0x00596960`.

Evidence against:

- The target has no `g_packetSender` access, packet buffer handling, command id, send-disabled flag access, transport consumer route, direct caller, or Socket vtable/data ref.

Decision:

- Rejected. Shared callee use does not imply Socket ownership.

### 5. CRT / std filesystem

Evidence for:

- IDA names the function `___std_fs_create_symbolic_link@8`.

Evidence against:

- The body does not call filesystem APIs, does not use paths, does not reference `CreateSymbolicLinkW`, and has no import/IAT relation.
- `imports_query` found no `CreateSymbolicLink` import.
- `CreateSymbolicLinkW` exists as a string at `0x00634034`, but its only live xref is from `?initialize_pointers@@YAHXZ`, not from this wrapper.
- The same stale-name family appears on the unrelated same-shape wrapper at `0x0058ea60`.

Decision:

- Rejected. The IDA name is a stale or misapplied label, not source ownership evidence.

### Proposed new file/grouping

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: none proven.
- Candidate related items rejected: `0x0058ea60` is same-shape unreferenced wrapper evidence, but it calls `0x0058f690` and has no xrefs. This supports an idiom pattern, not a coherent original source file.
- Standalone, narrow, or broad source-file inference: rejected. A single unreferenced forwarding wrapper with no source-use route is not enough to justify creating a new source file, global owner, or grouping.

## Negative Evidence Summary

Checked and rejected:

- FileDownloader physical adjacency: rejected because no target-specific FileDownloader evidence exists.
- Thread callee ownership: accepted as semantic clue, rejected as direct owner proof.
- Vtable/data route: no target refs found.
- Raw pointer route: no target VA/RVA dword hits and no push-address hits.
- Branch route: raw PE scan found no rel8/rel32 calls or jumps to `0x0041b2d0`.
- Import/filesystem route: no import relation and no target xref to symbolic-link strings.
- Split requirement: rejected because the range is one exact function, with padding before/after and separate neighboring functions.

## Final Recommendation

Exact changes applied or recommended:

- Created this report only.
- No by-memory, by-class, by-file, by-global, generated, project-level, or coverage-report edits recommended.

Exact parent assignments applied or recommended:

- Keep `CANONICAL_OWNER:NONE`.
- Keep blank `EMITTER_UIDS`.
- Keep blank `RECONSTRUCTION_CPP CODE`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `COMPLETION:86` and `CONFIDENCE:86`.

Exact items left no-owner/non-emitting and why:

- [UID:0003GY] remains no-owner/non-emitting because it is real source-shaped code with no proven direct declaration owner or output route. The best forced candidate is Thread, but current evidence is only a callee relationship plus wrapper shape. That is insufficient for a canonical owner or emitter.

Exact future work outside this assignment scope:

- A future IDA naming-cleanup pass may rename `___std_fs_create_symbolic_link@8` to a neutral local helper name, but that would not change owner/emitter state.
- If a future pass finds a source-level caller, vtable entry, debug symbol, object-file map evidence, or raw branch/pointer route to `0x0041b2d0`, rerun the owner/emitter gate then.

## Follow-Up Actions

- Supervisor actions: mark the live tracker row complete-no-change for this pass if this report is accepted.
- A-agent actions: none for current evidence.
- B001 future research actions: none for this exact target unless new route evidence appears.

## Confidence

- Recommendation confidence: `86/100`.
- Score confidence: keep existing `86/86`; the page is well enough documented for the no-owner/non-emitting decision, but not final-audit quality.
- Remaining uncertainty: the wrapper may have had an original declaration in `Thread.cpp`, `FileDownloader.cpp`, or another source file, but current stripped-binary evidence does not identify that declaration or an output route.

## Validator Results

- Commands run: none.
- Results: validator not run because no by-* documentation, shared coverage, generated report, or project-level file was edited.
- Any unresolved validator warnings/errors: not applicable.

## Lease State

- No lease acquired. The only edited file is this Agent-B001 research report, which does not require a lease under `goal.md`.
- No shared by-* file was edited.
- `by-memory/-coverage-report.md` was not edited, in compliance with the active supervisor ban.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-live-goal2-no-owner-pass.md`
- Modified: none outside this new report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
