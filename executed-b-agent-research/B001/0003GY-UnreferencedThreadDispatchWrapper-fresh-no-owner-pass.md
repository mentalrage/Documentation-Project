** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# [UID:0003GY] UnreferencedThreadDispatchWrapper Fresh No-Owner Pass

## Final Recommendation

Keep [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) unchanged.

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- `COMPLETION:86`
- `CONFIDENCE:86`
- blank `RECONSTRUCTION_CPP`

This is a real 20-byte source-shaped wrapper, but it is still a no-owner/non-emitting item. Current IDA MCP and raw PE evidence show the wrapper preserves the receiver in `ecx`, forwards two stack arguments plus a zero optional argument to the generic Thread queue-post helper at `0x00596960`, and returns with `retn 8`. The evidence does not prove a declaration owner, source-use route, or generated-output emitter for this wrapper.

No owner, emitter, split, merge, reclassification, by-memory document repair, shared coverage-report edit, or required IDA repair is justified by the current evidence. The stale IDA name `___std_fs_create_symbolic_link@8` is misleading, but the documentation already records that it is not filesystem behavior. A future IDA naming-cleanup batch could rename the function to a neutral wrapper name, but that would not change ownership or emission.

## Target And Scope

- Assigned target: [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md)
- Current generated source: `auto-generated/-ag-memory-coverage.md`
- Current generated state: `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Prior report reviewed as historical context only: `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-research.md`
- Current live IDA MCP session used: `a001_goal2_class_batch`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Imagebase: `0x00400000`
- IDA state: auto-analysis ready, Hex-Rays ready

## Evidence Standards Applied

This pass followed the current by-structure owner/emitter model:

- `CANONICAL_OWNER` requires the narrowest defensible original declaration/source owner, not physical adjacency.
- `EMITTER_UIDS` require a proven source-use or generated-output route, not just a callee that is emitted elsewhere.
- `RECONSTRUCTABLE:TRUE` can remain paired with `CANONICAL_OWNER:NONE` and blank emitters if the code is real but there is no defensible output route.
- Final C++ is blocked unless the item is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank `EMITTER_UIDS` that surface to valid generated source without a dead end, and passes the active combined-score/emitter gate. This target fails that gate because `EMITTER_UIDS` is blank.

Existing docs and prior reports were treated as leads. The recommendation above is based on current IDA MCP, current project documentation, and a fresh raw PE scan.

## Current Documentation State

The target page currently has:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The current generated coverage row is:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

The current no-owner/non-emitting generated section also lists:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |  |  |
```

Both generated rows are consistent with the evidence and should remain as-is.

## Live IDA MCP Facts

### Function Boundaries

`lookup_funcs` in current session `a001_goal2_class_batch` reports:

| Query | Result |
| --- | --- |
| `0x0041b2c9` | not a function |
| `0x0041b2d0` | `___std_fs_create_symbolic_link@8`, size `0x14` |
| `0x0041b2db` | inside `0x0041b2d0` |
| `0x0041b2e4` | not a function |
| `0x0041b2f0` | `sub_41B2F0`, size `0x0b` |
| `0x0041b270` | `sub_41B270`, size `0x59` |
| `0x00596960` | `sub_596960`, size `0x50` |
| `0x0058ea60` | `___std_fs_create_symbolic_link@8_0`, size `0x14` |

`get_bytes` around `0x0041b2c0` reports the live bytes:

```text
0x0041b2c9-0x0041b2d0: cc cc cc cc cc cc cc
0x0041b2d0-0x0041b2e4: 55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
0x0041b2e4-0x0041b2f0: cc cc cc cc cc cc cc cc cc cc cc cc
```

This confirms the target is a complete aligned function body with padding on both sides.

### Wrapper Behavior

`disasm 0x0041b2d0` reports:

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

`decompile 0x0041b2d0` returns IDA pseudocode equivalent to:

```c
return sub_596960(this, a2, a3, 0);
```

This snippet is evidence only, not a final-source recommendation.

`callees` reports one callee for the target: `0x00596960` / `sub_596960`.

`decompile 0x00596960` shows the callee builds a six-dword queue record, zeroes the tail, passes it to `sub_556580`, and calls `ReleaseSemaphore(this[3], 1, 0)`. Current Thread documentation treats this as generic base Thread queue infrastructure.

### Xrefs And Route Evidence

`xrefs_to` in current IDA reports:

| Address | Xrefs |
| --- | --- |
| `0x0041b2d0` | `0` |
| `0x0041b2e4` | `0` |
| `0x0041b2f0` | `1` code xref at `0x005f670e` |
| `0x0041b270` | `1` code xref at `0x0041c21b` |
| `0x0058ea60` | `0` |
| `0x00596960` | `22` code xrefs, including `0x0041b2db` inside this target |

The contrast is important. The adjacent FileDownloader-owned predecessor has a caller/receiver route, and the following cleanup helper has a constructor-unwind route. The target itself has no entry xref, no data xref, no function-pointer xref, no vtable path, and no source-use route.

`trace_data_flow 0x0041b2d0 direction=backward max_depth=3` reaches only the target start node and finds no incoming edges.

`analyze_component` over `0x0041b2d0`, `0x00596960`, `0x0041b270`, `0x0041b2f0`, and `0x0058ea60` reports:

- `0x0041b2d0` has one basic block, complexity 1, no strings, no shared globals, and the single edge to `0x00596960`.
- `0x0041b270` also calls `0x00596960`, but it has independent caller/semantic evidence and remains a separate FileDownloader helper.
- `0x0041b2f0` has no callee and writes `dword_67A738 = 0`.
- `0x0058ea60` is another stale-name wrapper, also unreferenced, forwarding two args plus zero to `0x0058f690`.

## PE / Raw Evidence

A fresh PE scan of `NexusTK.exe` produced:

```text
ImageBase: 0x00400000
Target exact bytes: 1 hit at 0x0041b2d0
Wrapper shape: 2 hits at 0x0041b2d0 and 0x0058ea60
Absolute target dword 0x0041b2d0: 0 hits
Target RVA dword 0x0001b2d0: 0 hits
push absolute target 0x0041b2d0: 0 hits
relative call/jump target 0x0041b2d0: 0 hits
ASCII "CreateSymbolicLinkW": 1 hit at 0x00634034
ASCII "___std_fs_create_symbolic_link": 0 hits
```

This independently supports the live IDA result: the target body is unique, but the wrapper idiom is not unique; there are no raw pointer, RVA, push-address, or rel32 branch/call references to the target entry. The filesystem API string exists elsewhere in `.rdata`, but the IDA wrapper name string is absent and the wrapper body has no import/IAT relation to `CreateSymbolicLinkW`.

## Current Documentation Evidence Checked

- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) lists the target as a real unreferenced thread-queue wrapper inside a mixed FileDownloader inventory, while keeping direct ownership unproven.
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](../../../../../by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) has a direct caller at `0x0041c21b`, payload setup, message id `10002`, and FileDownloader receiver evidence. Those positive facts do not exist for `0003GY`.
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) has constructor-unwind evidence and a direct global write to `dword_67A738`. Those positive facts do not exist for `0003GY`.
- [UID:0000OR][Thread](../../../../../by-file/Thread.md), [UID:0000EV][Thread](../../../../../by-class/Thread.md), and [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](../../../../../by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) identify `0x00596960` as generic Thread queue-post infrastructure with broad caller fan-in.
- [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](../../../../../by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) documents the `0x00596960` subrange as an async queue-post helper and records broad non-cash-shop fan-in.
- [UID:00001H][CashShopRequest](../../../../../by-class/CashShopRequest.md) explicitly cautions that `0x00596960` should be treated as generic Thread queue infrastructure unless later class-layout evidence proves otherwise.
- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) documents the FileDownloader dispatcher, request helpers, global, and vtable/literal children, but does not provide a direct source-use route for `0003GY`.

## Function And Child Inventory

| Range | Current state | Decision |
| --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | `0xcc` padding | Already covered by `-ignored`; no repair. |
| `0x0041b2d0-0x0041b2e4` | real 20-byte function | This target; keep as one by-memory function page. |
| `0x0041b2e4-0x0041b2f0` | `0xcc` padding | Already covered by `-ignored`; no repair. |
| `0x0041b2f0-0x0041b2fb` | separate global-clear helper | Keep separate [UID:0000WK][ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md). |

No split is required because the target is already a complete modeled function with exact aligned bounds. No merge is required because the neighbors have different route evidence and are separated by padding.

## Ranked Owner And Emitter Analysis

### Candidate 1: Thread / `util/Thread.cpp` (`0000OR` or `0000EV`)

Evidence for:

- The only callee is the Thread-owned generic async queue-post helper `0x00596960`.
- The wrapper preserves `ecx` as the receiver and pushes an explicit zero third argument, matching a convenience wrapper over the generic queue primitive.
- Thread documentation already owns the callee and describes broad use of `0x00596960` across multiple subsystems.

Evidence against:

- There are no xrefs to the wrapper entry, no vtable/data refs, no RTTI route, no raw pointer refs, and no branch/call refs to the wrapper.
- The target sits outside the main Thread/ThreadMan code island.
- The wrapper accesses no Thread fields directly; it only forwards to a Thread helper.
- A callee owner is not automatically the declaration owner of an otherwise unreferenced caller wrapper.
- The duplicate stale-name wrapper at `0x0058ea60` shows this tiny "two args plus zero" idiom is not unique to this callee/source family.

Decision: Thread is the best forced semantic candidate, but the evidence is not sufficient to assign `CANONICAL_OWNER:0000OR`, `CANONICAL_OWNER:0000EV`, or `EMITTER_UIDS:0000OR`.

### Candidate 2: FileDownloader / `network/FileDownloader.cpp` (`0000JC`)

Evidence for:

- The target is physically located in the broader FileDownloader dispatch inventory.
- The predecessor and successor are FileDownloader-family helpers.

Evidence against:

- The target is separated from both neighbors by `0xcc` padding.
- It has no FileDownloader global access, no `dword_67A738` receiver evidence, no message constant, no payload allocation, no FileDownloader field access, no FileDownloader vtable/data ref, and no caller passing a FileDownloader receiver.
- Adjacent FileDownloader helpers have direct positive route evidence: `0x0041b270` has a caller and payload/message evidence; `0x0041b2f0` has a constructor-unwind xref and global write. This target has neither.

Decision: reject FileDownloader ownership and `EMITTER_UIDS:0000JC`.

### Candidate 3: CashShopRequest / CashShopVersionRequest

Evidence for:

- The predecessor function posts a cash-shop version request.
- Older project history used CashShopRequest naming around the `0x00596960` helper.

Evidence against:

- This wrapper has no cash-shop payload, no request vtable, no message id, no cash-shop caller, and no request-object field evidence.
- Current CashShopRequest documentation treats `0x00596960` as generic Thread queue infrastructure pending stronger class-layout proof.

Decision: reject CashShop ownership and any CashShop emitter.

### Candidate 4: Socket / packet sender routes

Evidence for:

- Several proven Socket/packet helpers call the same `0x00596960` queue primitive.

Evidence against:

- This wrapper has no socket globals, packet buffers, packet opcodes, send-disabled-byte access, command ids, direct callers, or Socket dispatcher consumption path.
- Other Socket wrappers are owned by Socket because they have direct callers and command-consumer evidence; this target does not.

Decision: reject Socket/packet sender ownership and emitters.

### Candidate 5: CRT / std filesystem

Evidence for:

- The current IDA database names the function `___std_fs_create_symbolic_link@8`.

Evidence against:

- The body does not call filesystem APIs, does not use path/string arguments, and does not reference the import or API-resolver string.
- The raw PE scan found the `CreateSymbolicLinkW` string at `0x00634034` but no raw relation from this wrapper to that string or import.
- The raw PE scan found no `___std_fs_create_symbolic_link` string.
- Another unrelated tiny wrapper at `0x0058ea60` carries the same stale IDA name family, supporting a database naming artifact rather than true source identity.

Decision: reject CRT/std filesystem ownership. The stale IDA name is not source evidence.

## Split / Merge / Reclassification Analysis

- Split: not needed. The target is exactly one modeled function of size `0x14`, with padding before and after.
- Merge: not needed. The predecessor and successor have independent route evidence and different semantics; padding separates all three.
- Reclassify as padding/non-code: not valid. IDA models a function, the byte body is executable code, and the callee relation is real.
- Reclassify as non-reconstructable: not justified. The body is source-shaped project code over a project Thread helper. It is reconstructable in principle, but currently has no safe source owner or output route.
- IDA-safe name repair: optional only. The stale IDA name should not drive docs, but a rename would be provenance cleanup rather than a Goal 2 routing fix.

## Score And Code-Entry Impact

Before:

- `COMPLETION:86`
- `CONFIDENCE:86`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- blank `RECONSTRUCTION_CPP`

After recommendation:

- `COMPLETION:86`
- `CONFIDENCE:86`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- blank `RECONSTRUCTION_CPP`

The current average score is `86`, but final C++ entry remains blocked because `EMITTER_UIDS` is blank and no source-output route is proven. Do not add C++ for this item unless a future pass proves a nonblank emitter that surfaces to valid generated source without a dead end.

## Exact Required Edits

No by-memory, by-file, by-class, by-global, generated, or shared coverage-report edits are required.

Do not edit `by-memory/-coverage-report.md` for this item based on the current evidence. The existing shared coverage row remains acceptable because it already states the key current conclusion: real unreferenced queue wrapper, stale filesystem name unsupported, no caller/vtable/source-island/raw pointer/branch/import/source-use route, keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.

Supervisor-owned generated coverage state should remain:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

No replacement row is requested.

## Validation And Lease State

- Files changed by this pass: this research report only.
- by-* docs edited by this pass: none.
- `by-memory/-coverage-report.md` edited by this pass: no.
- Normal validator: not run, because no by-* documentation or shared coverage files were changed by this pass.
- Lease state: no lease acquired; this report is inside Agent-B001's own research folder, and no shared/by-* files were edited.
- Workspace note: `git -C source-3/project-documentation status --short` currently shows pre-existing shared/by-memory state outside this report (`by-memory/-coverage-report.md` modified and the target by-memory page untracked). Those files were read as evidence only and were not changed or reverted by this pass.

## Confidence

Recommendation confidence: `86/100`.

The behavior, exact bytes, boundaries, callee, and lack of xrefs/pointers/branches are strongly supported by current IDA MCP and PE evidence. Confidence remains below final owner/emitter level because the wrapper is real source-shaped code and may have been an unreferenced inline/out-of-line convenience wrapper in some original source file, but current evidence does not identify that file or a safe generated-output route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
