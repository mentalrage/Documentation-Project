** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# 0003GY UnreferencedThreadDispatchWrapper Goal 2 Verification

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` unchanged.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP CODE`.
- Required action: no owner, emitter route, split, merge, reclassification, score change, IDA repair, C++ entry, or `by-memory/-coverage-report.md` row change is justified.
- Confidence: high for no-change verification. The function body and boundaries are direct IDA facts; the absence of inbound source-use evidence is supported by IDA xrefs, trace, byte-pattern, raw PE branch-target, and pointer scans.

This item remains a legitimate reconstructable no-owner/non-emitting memory row. The body is real NexusTK source-shaped code, not padding or CRT filesystem code, but no current evidence proves a direct declaration owner or generated-output route. The best forced semantic candidate is [UID:0000EV] `Thread` / [UID:0000OR] `Thread.cpp` because the wrapper calls the generic `0x00596960` queue-post helper. That is still callee-only evidence, not ownership evidence. Emitting this wrapper through `Thread.cpp`, `FileDownloader.cpp`, or a synthetic source file would invent a route that the binary does not currently expose.

No replacement text is needed for `by-memory/-coverage-report.md`. The current row remains acceptable:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

## Supporting Research

## Target

- Target UID: `0003GY`
- Target path: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- Coverage source: `auto-generated/-ag-memory-coverage.md`
- Current supervisor row: `tools/leaser/Agents/Supervisor_notes.md`, `B001-goal2-noowner-verification-0003GY`, assigned fresh Goal 2 no-owner verification pass.
- Current generated state: reconstructable no-owner memory row, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no code.
- Current target scores: `COMPLETION:86`, `CONFIDENCE:86`.
- Prior report used only as evidence lead: `tools/leaser/Agents/Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-live-goal2-no-owner-pass.md`.

## Executive Recommendation

Keep `0003GY` as one exact by-memory function page. The range is already narrow: IDA reports one `0x14` / decimal 20-byte function at `0x0041b2d0` (Verified with `int_convert.py`) with `0xcc` padding before and after it. There is no mixed subrange to split and no adjacent range to merge into the target.

Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`. The wrapper is reconstructable because it is source-shaped project code that forwards to the generic Thread queue primitive, but it has no caller, no data/vtable/function-pointer reference, no raw branch target, no VA/RVA pointer, no receiver-origin route, and no source-use context. Without any route into the wrapper, there is no defensible emitter.

## Supervisor Active Recheck

- Fresh assignment rechecked current documentation and IDA evidence instead of adopting prior report conclusions.
- No split repair was required. The target is one modeled function and both neighboring spans are already accounted for as padding or separate exact functions.
- No by-* documentation edits were made. No lease was needed because this report is inside the Agent-B001 research folder.
- `by-memory/-coverage-report.md` was not edited.

## Inference Research Guidance Check

The B001 goal and inference guidance require a ranked ownership decision, not a passive "unknown" answer. I therefore ranked the plausible owners below and rejected each acting change with current evidence.

The decisive rule from `by-structure.md` is that `CANONICAL_OWNER` is semantic ownership and `EMITTER_UIDS` is output routing. A reconstructable page can remain no-owner/non-emitting when NexusTK-owned code is real but no source owner or emitter chain is defensible. Consumer or callee evidence alone is not enough, and address adjacency is weak evidence unless supported by calls, xrefs, vtables, constructor/destructor paths, or data ownership.

Existing docs were treated as leads only. Current IDA facts confirm the body and lack of references; documentation supplies the current candidate-owner context for Thread and FileDownloader.

## Evidence Standards Used

Evidence used in this pass:

- Current docs: target page, generated memory coverage row, `by-memory/-coverage-report.md`, FileDownloader inventory and exact neighbor pages, Thread class/file pages, Thread dispatch aggregate, `client_threading`, `client_network`, and proposed source tree.
- IDA MCP: `server_health`, `lookup_funcs`, `disasm`, `decompile`, `analyze_function`, `callees`, `xrefs_to`, `get_bytes`, `make_signature_for_range`, `find_bytes`, `trace_data_flow`, `entity_query`, and `imports_query`.
- Local byte checks: `tools/int_convert.py` for sizes, plus a `.text` raw PE branch-target scan for direct rel32 calls/jumps, short branches, and near conditional branches to `0x0041b2d0`.
- Negative evidence: no xrefs, no raw branch target, no pointer encodings, no import/IAT relation, no symbolic-link behavior, no source-use context, no vtable/data slot, and no fallthrough from neighbors due to padding.

## IDA MCP Facts

Current IDA session:

```text
database: a001_goal2_class_batch
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x00400000
auto-analysis ready: true
Hex-Rays ready: true
strings cache ready: true
```

Function and boundary facts:

| Query | Current IDA result |
| --- | --- |
| `0x0041b2c9` | not a function |
| `0x0041b2d0` | `___std_fs_create_symbolic_link@8`, size `0x14` / decimal 20 (Verified with `int_convert.py`) |
| `0x0041b2db` | inside function `0x0041b2d0` |
| `0x0041b2e4` | not a function |
| `0x0041b2f0` | `sub_41B2F0`, size `0x0b` / decimal 11 (Verified with `int_convert.py`) |
| `0x0041b270` | `sub_41B270`, size `0x59` / decimal 89 (Verified with `int_convert.py`) |
| `0x00596960` | `sub_596960`, size `0x50` / decimal 80 (Verified with `int_convert.py`) |
| `0x0058ea60` | `___std_fs_create_symbolic_link@8_0`, size `0x14` / decimal 20 (Verified with `int_convert.py`) |

Target bytes:

```text
55 8B EC 6A 00 FF 75 0C FF 75 08 E8 80 B6 17 00 5D C2 08 00
```

Surrounding bytes from `0x0041b2c0` confirm `0xcc` padding at `0x0041b2c9-0x0041b2d0`, the target body at `0x0041b2d0-0x0041b2e4`, and `0xcc` padding at `0x0041b2e4-0x0041b2f0` before the separate `sub_41B2F0` helper.

Target disassembly:

```asm
0x41b2d0  push ebp
0x41b2d1  mov ebp, esp
0x41b2d3  push 0
0x41b2d5  push [ebp+arg_4]
0x41b2d8  push [ebp+arg_0]
0x41b2db  call sub_596960
0x41b2e0  pop ebp
0x41b2e1  retn 8
```

Target decompilation:

```c
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
  return sub_596960(this, a2, a3, 0);
}
```

The decompiler type/name is not accepted as source truth. The body has no filesystem behavior; it preserves `ecx`, forwards two stack arguments, supplies a zero fourth argument, calls the generic queue post helper, and returns with `retn 8`.

`analyze_function 0x0041b2d0`:

```text
name: ___std_fs_create_symbolic_link@8
prototype: BOOL __thiscall(HANDLE *this, int, int)
callees: sub_596960
callers: none
strings: none
constants: none
basic blocks: 1
cyclomatic complexity: 1
```

Filtered `0x00596960` decompilation:

```c
BOOL __thiscall sub_596960(HANDLE *this, int a2, int a3, int a4)
{
  _DWORD Src[6];
  sub_556580(Src);
  return ReleaseSemaphore(this[3], 1, 0);
}
```

IDA xrefs:

| Target | Xref count | Meaning |
| --- | ---: | --- |
| `0x0041b2d0` | 0 | no caller/data route to this wrapper |
| `0x0041b2e4` | 0 | no endpoint/fallthrough route |
| `0x0041b2f0` | 1 | separate constructor-unwind FileDownloader clear helper at `0x005f670e` |
| `0x0041b270` | 1 | separate FileDownloader submit helper caller at `0x0041c21b` |
| `0x00596960` | 22 | broad generic Thread queue-post fan-in; includes the target call at `0x0041b2db` |
| `0x0058ea60` | 0 | same-shape stale-name wrapper elsewhere, also unreferenced |
| `0x00634034` `CreateSymbolicLinkW` string | 1 | data xref from `?initialize_pointers@@YAHXZ` at `0x005c710c`, not from this wrapper |

`find_bytes` and signature facts:

| Query | Result |
| --- | --- |
| exact target bytes | one hit: `0x0041b2d0` |
| wildcard wrapper shape `55 8B EC 6A 00 FF 75 ? FF 75 ? E8 ? ? ? ? 5D C2 08 00` | two hits: `0x0041b2d0`, `0x0058ea60` |
| `make_signature_for_range` exact operands | unique |
| `make_signature_for_range` wildcard operands | not unique |
| little-endian VA `D0 B2 41 00` | zero hits |
| little-endian RVA `D0 B2 01 00` | zero hits |
| `push 0x0041b2d0` bytes `68 D0 B2 41 00` | zero hits |

Raw `.text` PE branch-target scan:

| Branch kind | Hits targeting `0x0041b2d0` |
| --- | ---: |
| rel32 `call` / `jmp` | 0 |
| short branch / short jump | 0 |
| near conditional branch | 0 |

Symbolic-link negative facts:

- `entity_query(strings)` finds `CreateSymbolicLinkW` at `0x00634034` and `too many symbolic link levels` at `0x00633d98`.
- `imports_query` for `Symbolic` finds no imports.
- The only xref to `CreateSymbolicLinkW` is from `?initialize_pointers@@YAHXZ`, not this wrapper.
- The target has no string refs, no import refs, no path arguments, no Windows filesystem API calls, and no error translation.

`trace_data_flow` facts:

- Backward trace from `0x0041b2d0` reaches only the start node and no edges.
- Forward trace follows only local instruction flow from `0x0041b2d0` through the wrapper body.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | `by-memory/-ignored.md` | `0xcc` alignment padding | false | none | 100/strong | no change |
| `0x0041b2d0-0x0041b2e4` | [UID:0003GY] target | unreferenced two-arg plus zero queue-post wrapper | true | `NONE` | `86/86` | keep no-owner/non-emitting |
| `0x0041b2e4-0x0041b2f0` | `by-memory/-ignored.md` | `0xcc` alignment padding | false | none | 100/strong | no change |
| `0x0041b2f0-0x0041b2fb` | [UID:0000WK] `ClearFileDownloaderRequestGlobal` | FileDownloader constructor-unwind global clear | true | [UID:0000JC] | `85/92` | separate neighbor, not part of target |
| `0x0041b270-0x0041b2c9` | [UID:0002CL] `FileDownloaderSubmitCashShopVersionRequest` | message `10002` submit helper | true | [UID:0000JC] | `82/86` | separate predecessor with positive caller evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041b2d0` | no inbound IDA xrefs | no current source-use route |
| `0x0041b2db` | call to `0x00596960` | only positive semantic clue: generic Thread queue post |
| `0x00596960` | 22 code xrefs across downloader, MiscWorkThread/socket/packet-send helpers, and the target | callee is shared Thread infrastructure, not proof of caller-wrapper ownership |
| `0x0041b270` | caller `0x0041c21b` | predecessor has FileDownloader receiver evidence that the target lacks |
| `0x0041b2f0` | xref `0x005f670e` | successor has FileDownloader constructor-unwind evidence that the target lacks |
| `0x0058ea60` | no inbound IDA xrefs | duplicate stale-name wrapper shape elsewhere; does not prove owner |
| `0x00634034` | data xref from `?initialize_pointers@@YAHXZ` | symbolic-link string belongs to API-resolver area, not this wrapper |

## Documentation Evidence And IDA Status

Existing docs that support no change:

- Target page records the current state: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no code, stale filesystem-name caveat, no xrefs, and Thread callee.
- `auto-generated/-ag-memory-coverage.md` lists `0003GY` as `no-owner` with `NONE`, blank emitter fields, no generated path, and no code.
- `by-memory/-coverage-report.md` already describes the correct no-owner/non-emitting rationale.
- [UID:0000WI] `0x0041a670-0x0041b69f.FileDownloaderDispatch` is now a non-emitting mixed inventory and lists this exact child as parent-blank.
- [UID:0000OR] `Thread`, [UID:0000EV] `Thread`, and [UID:0001JY] `Thread Message Dispatch Helpers` document `0x00596960` as generic Thread infrastructure with broad fan-in.
- [UID:0000JC] `FileDownloader` and [UID:00004W] `FileDownloader` document positive evidence for the adjacent submit/cleanup helpers, but also preserve boundary cautions around shared Thread helpers.
- `by-project-structure/proposed-source-tree.md` explicitly says `Thread.cpp` owns `0x00596960` unless later evidence proves otherwise, while `FileDownloader.cpp` owns the HTTP downloader dispatcher.

Existing docs that are stale, incomplete, or contradicted:

- IDA's `___std_fs_create_symbolic_link@8` target name is contradicted by the current body, strings, imports, and xrefs.
- Any inference that the wrapper belongs to FileDownloader solely because it sits inside the broader `0x0041a670-0x0041b69f` address inventory is too weak. The aggregate is explicitly mixed and non-emitting.
- The best source-facing declaration name remains unknown because no caller or source-use context survives.

## Ranked Ownership Analysis

### 1. Thread / `util/Thread.cpp`

Evidence for:

- The only callee is `0x00596960`, currently documented as generic `Thread` queue-post infrastructure.
- The wrapper preserves `ecx` as a receiver and passes two explicit arguments plus a zero optional argument, matching a thin overload over a queue-post helper.
- `Thread.cpp`, `Thread` class, `ThreadAndThreadMan`, and `Thread Message Dispatch Helpers` all clear the ownership gate for the callee family.

Evidence against:

- No caller, vtable/data reference, function pointer, branch target, raw VA/RVA pointer, or source-use context reaches `0x0041b2d0`.
- The target is outside the main Thread/ThreadMan code island.
- The body does not access Thread fields directly; all Thread semantics are inherited from the callee.
- The same wildcard wrapper idiom appears at `0x0058ea60` and is also unreferenced, showing that wrapper shape plus stale IDA name is not unique owner evidence.

Decision:

- Best forced semantic candidate, but still rejected for assignment. Do not set `CANONICAL_OWNER:0000EV`, `CANONICAL_OWNER:0000OR`, or `EMITTER_UIDS:0000OR`.

### 2. FileDownloader / `network/FileDownloader.cpp`

Evidence for:

- The wrapper is physically located in the broader FileDownloader dispatch/support address inventory.
- The immediate predecessor and successor are FileDownloader-related children.
- Neighboring FileDownloader submit helpers call the same `0x00596960` queue-post primitive.

Evidence against:

- The wrapper is isolated from both neighbors by `0xcc` padding.
- It has no FileDownloader global access, no `dword_67A738` receiver evidence, no message id, no payload allocation, no FileDownloader vtable/data ref, and no caller passing the FileDownloader singleton.
- The predecessor `0x0041b270` and successor `0x0041b2f0` each have positive FileDownloader evidence. This target has none.
- The containing aggregate [UID:0000WI] is explicitly a non-emitting mixed inventory, not a direct ownership claim.

Decision:

- Rejected. Do not set `CANONICAL_OWNER:0000JC`, `CANONICAL_OWNER:00004W`, `EMITTER_UIDS:0000JC`, or `EMITTER_UIDS:00004W`.

### 3. CashShopRequest / CashShopVersionRequest

Evidence for:

- The physical predecessor allocates a `CashShopVersionRequest` payload and posts message `10002`.
- Some historical generated names around queue-post helpers have CashShopRequest pollution.

Evidence against:

- The target has no payload object, no request vtable, no message id, no cash-shop caller, no request fields, and no class-specific evidence.
- Current docs have moved the generic queue primitive to Thread and the adjacent submit helper to FileDownloader dispatch.

Decision:

- Rejected. No cash-shop owner or emitter is justified.

### 4. Socket / packet send request queue

Evidence for:

- Socket and packet-send helpers are among the 22 callers of the same `0x00596960` queue-post primitive.

Evidence against:

- The target has no `g_packetSender` access, packet buffer handling, command id, send-disabled flag access, Socket vtable/data ref, or direct caller.

Decision:

- Rejected. Shared callee fan-in does not make this wrapper Socket-owned.

### 5. CRT / `std::filesystem` symbolic-link helper

Evidence for:

- IDA currently names the target `___std_fs_create_symbolic_link@8`.
- A separate `.rdata` string `CreateSymbolicLinkW` exists at `0x00634034`.

Evidence against:

- The wrapper body has no filesystem API call, no path handling, no error translation, and no string/import references.
- `imports_query` finds no symbolic-link import.
- The `CreateSymbolicLinkW` string is referenced by `?initialize_pointers@@YAHXZ`, not by the target.
- The same stale-name wrapper shape appears at `0x0058ea60`.

Decision:

- Reject the IDA name as stale or misapplied. Do not reclassify the target as CRT/std filesystem code.

### 6. New file/grouping

Evidence for:

- The wrapper is real retained code and could reflect a source-level overload or template-like adapter.

Evidence against:

- No additional related items are provably tied to this wrapper. The only same-shape duplicate calls a different callee and has no xrefs. There is no table, vtable, source path, object-file cluster, debug breadcrumb, caller cluster, or shared data group to define a new owner.

Decision:

- Do not create a new source file, by-file page, by-class page, or grouping for a one-function unreferenced wrapper.

## Negative Evidence Summary

Checked and rejected:

- IDA inbound xrefs to `0x0041b2d0`: none.
- IDA endpoint xrefs to `0x0041b2e4`: none.
- Data-flow backward route into `0x0041b2d0`: none.
- Raw rel32 calls/jumps, short branches, and near conditional branches to `0x0041b2d0`: none.
- Little-endian target VA and RVA pointer encodings: none.
- `push 0x0041b2d0` immediate pattern: none.
- Vtable/data slot evidence: none found through xrefs or pointer scans.
- Receiver-origin route: none; no caller sets `ecx`.
- FileDownloader evidence: absent for the target, present only for neighbors.
- Thread evidence: present only through callee `0x00596960`, not through direct ownership.
- Filesystem/CRT evidence: contradicted by behavior and string/import checks.
- Split need: absent; function is exact and has padding boundaries.
- Merge need: absent; neighbors have separate positive owners/evidence.

## Final Recommendation

Exact changes recommended:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Exact items left no-owner/non-emitting:

- [UID:0003GY] remains no-owner/non-emitting because it is real reconstructable project-shaped code with no proven direct declaration owner and no proven output route.

Future evidence that would change the recommendation:

- A caller, vtable/data slot, function pointer table, raw branch/pointer target, debug/source path, object-file map, source-use context, or receiver-origin route into `0x0041b2d0`.
- If such evidence appears, rerun the owner/emitter gate and prefer the proven caller/source owner over the current callee-only Thread inference.

## Follow-Up Actions

- Supervisor: no coverage row change is requested.
- A-agents: do not emit this wrapper into `Thread.cpp` or `FileDownloader.cpp` until a source-use route is found.
- Future B001 research: if a broader stale `___std_fs_create_symbolic_link@8` naming repair pass is opened, include both `0x0041b2d0` and `0x0058ea60`, but do not treat stale IDA names as ownership evidence.

## Confidence

- Recommendation confidence: high.
- Score confidence: current `86/86` remains reasonable. The target has strong exact-body and negative-route evidence but not enough source-context evidence to raise confidence toward final-audit levels.
- Remaining uncertainty: the original source declaration name and file are unknown. The uncertainty is not enough to assign a speculative owner or emitter.

## Validator Results

- Validator commands run: none.
- Reason: this pass made no by-* metadata or generated-output edits and the assignment did not require split repair.
- Dry runs: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-goal2-verification.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
