** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# 0003GY UnreferencedThreadDispatchWrapper Restart No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`, current `COMPLETION:86`, current `CONFIDENCE:86`.
- Required action: no target edit, no owner assignment, no emitter assignment, no reclassification to non-reconstructable, no split, no merge, no rename requirement, no direct `by-memory/-coverage-report.md` edit.
- Confidence: high for the no-change recommendation. Current IDA MCP evidence and raw PE scans independently confirm a real 20-byte function with no inbound xrefs, no VA/RVA/push pointer hits, no vtable/table slot, no caller/source-use route, and only one callee: the generic Thread queue post helper at `0x00596960`.

This is a last-resort no-owner/non-emitting case under the current owner/emitter model. The wrapper is real source-authored NexusTK code, so `RECONSTRUCTABLE:TRUE` remains correct. It should not be routed to generated source yet because no direct semantic owner or defensible source-output route is proven.

## Supporting Research

## Target

- Target UID: `0003GY`
- Target path: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- Target range: `0x0041b2d0-0x0041b2e4`
- Target size: `0x14` bytes
- Entity kind: real but unreferenced thread queue dispatch wrapper.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` line 14 assigns `0003GY` to Agent-B002 for the 2026-06-14 restart no-owner sweep.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-sweep.md`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists the item as `no-owner`, owner `` `NONE` ``, blank emitter fields, no generated output file, and target page `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`.
- Current target metadata: `86/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.

## Executive Recommendation

Keep the target as reconstructable no-owner and non-emitting.

The wrapper is not padding, not a runtime filesystem helper, and not a data artifact. It is a tiny `thiscall` forwarding function:

```asm
0041b2d0  push ebp
0041b2d1  mov  ebp, esp
0041b2d3  push 0
0041b2d5  push [ebp+arg_4]
0041b2d8  push [ebp+arg_0]
0041b2db  call sub_596960
0041b2e0  pop  ebp
0041b2e1  retn 8
```

The best forced semantic candidate is still "some wrapper over the base Thread async dispatch helper", and the best forced file candidate is still `FileDownloader.cpp` by address neighborhood. Neither clears the assignment gate. Thread owns the callee abstraction, but there is no evidence that this specific wrapper was declared by `Thread`. FileDownloader surrounds the target in address order, but the target has no FileDownloader fields, no `dword_67A738` use, no downloader message constants, no caller, no vtable slot, and no data/table reference.

Do not add an emitter. For code pages, an emitter must represent a defensible output route. Here there is no source-use context and no proven declaration owner. Adding `0000JC` or `0000OR` as an emitter would make the item look routed to a source file without evidence that the final source should contain that wrapper.

Do not lower `RECONSTRUCTABLE` to `FALSE`. IDA and raw bytes show real project code that calls a NexusTK Thread helper. It is not ignored padding, not a known CRT/STL implementation, and not an import thunk.

## Supervisor Active Recheck

- Supervisor instruction: restart-pass recheck of current no-owner non-emitting memory target [UID:0003GY].
- Risk called out by supervisor: reconstructable non-emitting items do not surface to generated source.
- Result: the risk is real but still unresolved by evidence. The item should remain visible in no-owner/non-emitting coverage until a caller, vtable/data slot, source symbol, or stronger source-island proof identifies a valid output route.
- Split repair required before final report: no. The target is one IDA-modeled function with exact 0x14-byte bounds and padding on both sides.
- Direct in-scope doc repair required: no. Current target and coverage wording match live evidence.

## Inference Research Guidance Check

- `by-structure.md` requires `CANONICAL_OWNER` to record the direct semantic owner, not the nearest source file or the most convenient generated-output parent.
- `EMITTER_UIDS` are output routes, not ownership. They should remain blank when no source-output route is proven.
- `by-structure.md` also allows `RECONSTRUCTABLE:TRUE` with blank owner/emitter while research continues. That is the correct state for this code page.
- `inference_research.md` treats address adjacency as weak evidence unless reinforced by xrefs, write sites, constructors, section grouping, debug data, or repeated use patterns. Here adjacency to FileDownloader functions is the only FileDownloader-positive signal.
- Existing documentation was treated as a lead, not authority. The current IDA MCP pass reconfirmed the material facts independently.

## Evidence Standards Used

Evidence checked:

- Current target page and current generated coverage rows.
- Prior B001 report, reviewed only as background.
- Current by-structure and inference guidance.
- Candidate parent docs: `Thread`, `FileDownloader`, the mixed FileDownloader dispatch inventory, and exact neighboring memory pages.
- Live IDA MCP: server health, function lookup, bytes, disassembly, decompilation, callees, xrefs, richer xref query, function-name query, string regex search, and byte pattern search.
- Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section mapping, exact body search, direct call encoding search, VA/RVA pointer searches, and `push target` search.
- Negative evidence: no inbound xrefs to the function start, no raw pointer hits, no source/debug string hit, no import match, no vtable/data reference, no caller route, no owner-specific field use, and no interior/tail target evidence.

The evidence is strong enough to reject current owner/emitter assignment. It is not strong enough to prove the original declaration owner or final source name, so the target should not be rescored upward or emitted.

## IDA MCP Facts

Session health:

```text
database: b001_0003gy
module: NexusTK.exe
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Function and boundary facts:

- `lookup_funcs 0x0041b2c9`: not a function.
- `lookup_funcs 0x0041b2d0`: `___std_fs_create_symbolic_link@8`, size `0x14`.
- `lookup_funcs 0x0041b2e4`: not a function.
- `lookup_funcs 0x0041b2f0`: `sub_41B2F0`, size `0x0b`.
- `lookup_funcs 0x0041b270`: `sub_41B270`, size `0x59`.
- `lookup_funcs 0x00596960`: `sub_596960`, size `0x50`.

Byte facts:

- `get_bytes 0x0041b2c0 size 0x40` shows the predecessor function tail through `0x0041b2c8`, seven `0xcc` bytes at `0x0041b2c9-0x0041b2d0`, the exact target body at `0x0041b2d0-0x0041b2e4`, twelve `0xcc` bytes at `0x0041b2e4-0x0041b2f0`, and the `sub_41B2F0` body beginning at `0x0041b2f0`.
- Target body bytes: `55 8B EC 6A 00 FF 75 0C FF 75 08 E8 80 B6 17 00 5D C2 08 00`.
- `find_bytes` for the exact target body returns one match at `0x0041b2d0`.
- `find_bytes` for the direct call encoding `E8 80 B6 17 00` returns one match at `0x0041b2db`.
- `find_bytes` for absolute VA bytes `D0 B2 41 00`, RVA bytes `D0 B2 01 00`, and `push 0x0041b2d0` bytes `68 D0 B2 41 00` returns zero matches.

Disassembly:

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

Hex-Rays decompilation:

```c
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
  return sub_596960(this, a2, a3, 0);
}
```

The `BOOL`, `HANDLE *`, and symbolic-link name are IDA type/name pollution. The code itself only forwards two stack arguments plus literal zero to the Thread queue helper.

Callee facts:

- `callees 0x0041b2d0`: only `sub_596960`.
- `callees 0x00596960`: `sub_556580` and imported `ReleaseSemaphore`.
- `decompile 0x00596960`: stores three supplied arguments into a six-dword stack record, zeros the last three dwords, calls the queue insertion helper, and signals `ReleaseSemaphore(this[3], 1, 0)`.

Xref facts:

- `xrefs_to 0x0041b2d0`: zero.
- `xref_query` with direction `both` for `0x0041b2d0` only reports an internal fallthrough/from-edge from `0x0041b2d0` to `0x0041b2d1`; it reports no inbound reference to the function start.
- `xrefs_to 0x0041b2e4`: zero.
- `xrefs_to 0x0041b2f0`: one code xref from `0x005f670e`, associated by IDA with the `0x0041a670` FileDownloader constructor function.
- `xrefs_to 0x0041b270`: one code xref from `0x0041c21b`, inside `sub_41BDD0`.
- `xrefs_to 0x00596960`: 22 code xrefs, including the three downloader submit helpers, this unreferenced wrapper, MiscWorkThread-style refs, socket/packet-send wrappers, and other queue users. This proves broad generic Thread queue-post fan-in; it does not prove the wrapper's owner.

Stale IDA name facts:

- `func_query` for `std_fs_create_symbolic_link|symbolic` returns two functions: `0x0041b2d0 ___std_fs_create_symbolic_link@8` and `0x0058ea60 ___std_fs_create_symbolic_link@8_0`.
- `lookup_funcs 0x0058ea60`: size `0x14`; `xrefs_to 0x0058ea60`: zero.
- `disasm 0x0058ea60`: same tiny wrapper shape, but calls `sub_58F690`.
- `decompile 0x0058ea60`: `return sub_58F690(a1, a2, 0);`.
- `find_regex '(?i)Symbolic|CreateSymbolic|\.pdb|RSDS|NB10|\.cpp|\.cxx|\.h'`: only `too many symbolic link levels` at `0x633d98` and `CreateSymbolicLinkW` at `0x634034` matched.
- `imports` filtered for symbolic/hardlink/symlink/CreateSymbolic found no matching imports.

The duplicate stale name and lack of import relation reject the filesystem-helper theory for this target.

## Raw PE Facts

Raw executable scanned:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
ImageBase: 0x00400000
```

Mapped locations:

| VA | Section | Raw offset |
| --- | --- | --- |
| `0x0041b2d0` | `.text` | `0x1a6d0` |
| `0x0041b2e4` | `.text` | `0x1a6e4` |
| `0x0041b2f0` | `.text` | `0x1a6f0` |
| `0x00596960` | `.text` | `0x195d60` |
| `0x0058ea60` | `.text` | `0x18de60` |

Raw pattern results:

| Pattern | Result |
| --- | --- |
| Exact target body | Count `1`, at raw `0x1a6d0` / VA `0x0041b2d0`. |
| Direct call encoding `E8 80 B6 17 00` | Count `1`, at raw `0x1a6db` / VA `0x0041b2db`. |
| Absolute target VA `0x0041b2d0` | Count `0`. |
| Target RVA `0x0001b2d0` | Count `0`. |
| `push 0x0041b2d0` | Count `0`. |
| Interior/tail VA checks | No interior/tail target VA hits were printed by the scan. |

Raw PE evidence agrees with IDA: the function body is unique and there is no raw pointer, immediate, or simple push-reference route to the wrapper.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | [UID:0000VN] `by-memory/-ignored.md` | `0xcc` padding after `0x0041b270` | `FALSE` | none | ignored | No split/action needed. |
| `0x0041b2d0-0x0041b2e4` | [UID:0003GY] target page | unreferenced Thread queue forwarding wrapper | `TRUE` | `NONE` | `86/86` | Keep no-owner/non-emitting. |
| `0x0041b2e4-0x0041b2f0` | [UID:0000VN] `by-memory/-ignored.md` | `0xcc` padding before `0x0041b2f0` | `FALSE` | none | ignored | No split/action needed. |
| `0x0041b2f0-0x0041b2fb` | [UID:0000WK] `ClearFileDownloaderRequestGlobal` | FileDownloader constructor-unwind global clear helper | `TRUE` | `0000JC` | `85/92` | Neighbor only; proves contrast. |
| `0x00596960-0x005969b0` | inside [UID:0001JX] `ThreadAndThreadMan` | base Thread async queue post helper | `TRUE` | `0000OR` | aggregate `85/86` | Callee owner is known; wrapper owner is not. |

No child split is warranted for `0003GY`. No merge is warranted with FileDownloader, Thread, or the duplicate stale-name wrapper because those candidates either overclaim ownership or cover different functions.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041b2d0` | `xrefs_to`: zero | No direct caller, vtable/data slot, table entry, or address-taken reference is known. |
| `0x0041b2db` | calls `0x00596960` | Target forwards to the generic Thread async post helper. |
| `0x0041b2e4` | `xrefs_to`: zero | No tail/interior route into successor padding. |
| `0x0041b2f0` | xref from `0x005f670e` | Neighbor has real FileDownloader constructor-unwind evidence that the target lacks. |
| `0x0041b270` | xref from `0x0041c21b` | Predecessor has a real caller and request-dispatch route that the target lacks. |
| `0x00596960` | 22 code xrefs | Generic queue primitive used by downloader, MiscWorkThread, socket/packet helpers, and this wrapper. |
| `0x0058ea60` | `xrefs_to`: zero | Duplicate stale symbolic-link-named wrapper; supports rejecting IDA name as source evidence. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003GY] records `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, exact tiny wrapper behavior, no inbound xrefs, stale IDA name caveat, and Thread as only a forced semantic candidate.
- [UID:0000WI] `0x0041a670-0x0041b69f.FileDownloaderDispatch.md` is a reviewed non-emitting mixed address inventory. It lists `0003GY` as a real child but keeps it parent-blank because no direct owner evidence clears the gate.
- [UID:0000OR] `by-file/Thread.md` and [UID:0000EV] `by-class/Thread.md` own the generic Thread queue helper at `0x00596960` and document broad Thread fan-in. Live IDA confirms the callee role but not target ownership.
- [UID:0000JC] `by-file/FileDownloader.md` and [UID:00004W] `by-class/FileDownloader.md` document the surrounding downloader dispatcher, global lifetime, and request submit helpers. Live IDA confirms those neighbors but not a target xref or owner-specific state use.
- [UID:0002CL] and [UID:0000WK] show the predecessor/successor contrast: they have caller/global-unwind evidence that `0003GY` lacks.

Existing docs that are stale, incomplete, or contradicted:

- The current IDA function name `___std_fs_create_symbolic_link@8` is stale/misleading. The wrapper does not call or import `CreateSymbolicLinkW`, does not process paths, and only forwards to a NexusTK Thread helper.
- No current doc needs a repair for this assignment. The stale IDA-name caveat is already represented on the target page and prior coverage wording.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` line 2744 lists `0003GY` as `no-owner`, owner `NONE`, blank emitter fields, no generated output file.
- `auto-generated/-ag-memory-coverage.md` line 3265 lists it in the no-owner/non-emitting queue with blank emitter data.
- `by-memory/-coverage-report.md` line 125 already contains a correct no-owner/non-emitting explanation. No direct edit is recommended.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- Live IDA reports zero xrefs to the function start.
- Raw PE scan finds zero absolute VA, RVA, or `push target` references.
- The target is not in a vtable, data table, callback table, import thunk, or known source-use path.
- The target touches no owner-specific fields or globals.
- The function body is a generic two-argument wrapper over `0x00596960`; behavior alone does not identify the declaring class/file.
- The current wrapper is below the `90/90+` source-code gate and has no output route.

Evidence against:

- It is real code in a FileDownloader-heavy address neighborhood.
- It calls the known Thread async queue helper, so it is likely a source-authored convenience wrapper around a known abstraction.

Decision:

- Accepted. This is the most defensible current state. It is a real reconstructable item, but there is no reliable source owner or emitter route yet.

### 2. [UID:0000JC] `FileDownloader`

Evidence for:

- The target sits physically between FileDownloader-related children: `0x0041b270` and `0x0041b2f0`.
- The wider [UID:0000WI] aggregate is a FileDownloader dispatch neighborhood.
- If forced to choose a source file from address ordering alone, `FileDownloader.cpp` would be the best candidate.

Evidence against:

- Address adjacency is weak under the project guidance.
- The target is separated from both neighbors by `0xcc` padding.
- No inbound xref reaches the target from FileDownloader code.
- It does not use `dword_67A738`, downloader message IDs `10000-10002`, request payload vtables, WinINet helpers, FileDownloader vtable data, or any FileDownloader field.
- Neighboring FileDownloader items have concrete caller/global/vtable evidence; this target has none.

Decision:

- Rejected as direct canonical owner and emitter. Keep as the best forced file candidate only if future external action requires a provisional guess, but do not apply now.

### 3. [UID:0000OR] / [UID:0000EV] `Thread`

Evidence for:

- The only callee is `sub_596960`, documented as the base Thread async post helper.
- The decompiled shape is a natural two-argument wrapper over a Thread queue primitive: `sub_596960(this, a2, a3, 0)`.
- `Thread` is a valid `85/85+` source/class owner for the callee island.

Evidence against:

- A function calling a Thread method does not prove the wrapper itself was declared by Thread.
- The wrapper is far outside the Thread/ThreadMan island at `0x00596250-0x0059756e`.
- No Thread vtable slot, constructor, class layout reference, raw Thread helper gap, or call site points at `0x0041b2d0`.
- There is a duplicate stale-name wrapper at `0x0058ea60` calling a different helper, showing that this wrapper shape/name can appear outside the Thread island.

Decision:

- Rejected as direct owner/emitter. Thread remains the strongest semantic abstraction for the callee, not the wrapper.

### 4. [UID:0000I1] / [UID:00001I] `CashShopVersionRequest` or [UID:00001H] `CashShopRequest`

Evidence for:

- The predecessor at `0x0041b270` submits a `CashShopVersionRequest` payload.
- The target sits inside a broad address cluster that also contains cash-shop request destructor support.

Evidence against:

- The target allocates no payload, references no request vtable, touches no request fields, and has no caller from request code.
- It passes only two arguments plus zero into the generic Thread helper.
- The known cash-shop submit helper has real caller/message evidence; this target does not.

Decision:

- Rejected.

### 5. Runtime/CRT/STL filesystem helper

Evidence for:

- Current IDA name is `___std_fs_create_symbolic_link@8`.
- IDA strings contain `CreateSymbolicLinkW` and `too many symbolic link levels`.

Evidence against:

- No imports matching symbolic/hardlink/symlink/CreateSymbolic were found.
- The target does not call `CreateSymbolicLinkW`, process paths, set filesystem errors, or call CRT filesystem helpers.
- It calls NexusTK `sub_596960`, a Thread queue post helper.
- IDA also names another unreferenced wrapper at `0x0058ea60` as `___std_fs_create_symbolic_link@8_0`, which calls a different helper and is likewise unreferenced.

Decision:

- Rejected. The IDA name is stale or polluted and should not drive classification.

### Proposed new file/grouping

- Proposed owner/name/path: none recommended.
- Likely full contents if forced: a single unused queue-post convenience wrapper, but that is not enough to justify a new source root or global owner page.
- Candidate related items that belong: none proven. The duplicate stale-name wrapper at `0x0058ea60` is related only by shape/name pollution, not by callee or owner evidence.
- Candidate related items rejected: FileDownloader neighbors, Thread callee island, CashShop request payload helpers, and the `0x0058ea60` duplicate wrapper.
- Standalone, narrow, or broad source-file inference: no new file/grouping should be created from one unreferenced 20-byte wrapper with no caller or metadata.

## Negative Evidence Summary

Checked and rejected:

- Direct callers: none.
- Function-start xrefs: none.
- Raw VA/RVA/push references: none.
- Vtable/table/data slot route: none found by xrefs and raw pointer scans.
- Interior/tail references: no useful route; IDA only reports normal internal sequential code refs when querying interior instructions.
- FileDownloader ownership: only address adjacency supports it; no receiver/global/message/vtable evidence supports it.
- Thread ownership: only callee semantics support it; no declaration/source-owner evidence supports it.
- CashShop ownership: nearby request code exists but target has no payload or request behavior.
- Runtime/filesystem classification: current IDA name is contradicted by behavior and imports.
- Split/merge: target is one exact function with padding on both sides.
- C++ emission: blocked by `86/86`, blank owner/emitter route, and unresolved original declaration/signature/name.

## Final Recommendation

Exact changes applied:

- Created this B002 research report only.
- No by-memory, by-file, by-class, generated, project-level, tracker, or shared coverage file was edited.

Exact parent/emitter assignments recommended:

- Keep `CANONICAL_OWNER:NONE`.
- Keep blank `EMITTER_UIDS`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Keep blank `RECONSTRUCTION_CPP`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep scores at `COMPLETION:86`, `CONFIDENCE:86`.

Exact items left no-owner/non-emitting and why:

- [UID:0003GY] remains no-owner/non-emitting because no caller, xref, table, vtable, raw pointer, source-use route, or owner-specific behavior proves where the wrapper should be declared or emitted.

No target header replacement is needed. Retain:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No generated memory coverage row replacement is required. If the supervisor needs exact current generated row text for comparison, keep:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

No direct `by-memory/-coverage-report.md` edit is required. If the supervisor reapplies shared-report text, keep this row:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

Optional supervisor tracker update after accepting this restart report:

```text
| `0003GY` | 0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003GY-UnreferencedThreadDispatchWrapper-restart-no-owner-research.md` | `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-sweep.md` |
```

## Follow-Up Actions

- Supervisor actions: mark the tracker row complete if this report is accepted; no shared coverage/report edit is needed.
- A-agent actions: none for this target.
- B002 future research actions: only revisit if new evidence appears, such as a hidden indirect table, debug/PDB/source-path metadata, a later IDA analysis xref, or a source-owner audit that proves unused methods from this object file should be emitted through `FileDownloader.cpp`.

## Confidence

- Recommendation confidence: high, approximately `90`.
- Score confidence: keep target score at `86/86`; do not raise. The negative evidence is strong, but the original declaration owner, source name, and reason the dead wrapper survived are still unknown.
- Completion/confidence impact: no page-score change recommended. The report strengthens the no-owner/non-emitting justification but does not add the missing source owner/emitter evidence required to raise the target toward final-source confidence.
- Remaining uncertainty: whether the original source contained an unused FileDownloader method, a derived-thread method, a file-local wrapper, or a linker-retained helper from a neighboring object file. Current binary evidence cannot distinguish those possibilities.

## Validator Results

- Commands run: none.
- Results: not applicable because no validator-managed by-* documentation was edited.
- Dry runs: none used.
- Unresolved validator warnings/errors introduced by this work: none.

## Lease State

- Read current shared lease report before editing; only an unrelated B003 research report lease was active.
- Initial B002 lease request for the target report path was rejected with `Rejected[File not found]`.
- Created a minimal report placeholder so the path could be leased.
- Leased `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003GY-UnreferencedThreadDispatchWrapper-restart-no-owner-research.md` as `B002` before writing this final report body.
- No by-* documentation lease was needed or acquired.
- Report-file lease released after writing and verification; final current-lease check found no active `B002`, `0003GY`, `UnreferencedThreadDispatchWrapper`, or `0041b2d0` entries.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003GY-UnreferencedThreadDispatchWrapper-restart-no-owner-research.md`
- Modified: none outside the B002 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B002/0003GY-UnreferencedThreadDispatchWrapper-restart-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
