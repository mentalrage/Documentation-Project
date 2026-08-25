** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# [UID:0003GY] UnreferencedThreadDispatchWrapper Current No-Owner Research

## Final Recommendation

Keep [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) unchanged.

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- `COMPLETION:86`
- `CONFIDENCE:86`
- blank `RECONSTRUCTION_CPP`

This is a real 20-byte source-shaped NexusTK helper that preserves the receiver in `ecx`, forwards two stack arguments plus a zero optional argument to the generic Thread queue-post helper at `0x00596960`, then returns with `retn 8`. It is not padding, not a FileDownloader-specific function, and not CRT/std filesystem code despite the stale IDA name.

The item should remain no-owner/non-emitting because current live IDA MCP and PE evidence still finds no caller, function-pointer reference, vtable slot, RTTI path, raw branch/call target, receiver-origin route, import relation, or source-use context that proves a direct canonical owner or generated-output emitter route. Thread is the best forced semantic candidate, but the evidence proves the callee's owner, not this wrapper's declaration owner.

## Target And Scope

- Assigned target: [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md)
- Current generated state: `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Generated coverage rows checked: `auto-generated/-ag-memory-coverage.md` main table and no-owner/non-emitting section
- Shared coverage row checked: `by-memory/-coverage-report.md`
- Prior reports read as historical context only:
  - `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md`
  - tracker references to earlier Agent-B001/B002/B003 no-owner passes
- Live binary used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`
- Live IDA MCP session used: `b001_0002bd`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready

## Evidence Standards

This pass used the current owner/emitter model:

- `CANONICAL_OWNER` requires the narrowest defensible declaration/source owner, not address adjacency.
- `EMITTER_UIDS` require proven generated-output routing or source-use contexts, not merely a callee that already emits elsewhere.
- A reconstructable no-owner item may remain blank-emitter only after plausible owner/emitter candidates are ranked and rejected.
- Final C++ entry is blocked unless the target is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank `EMITTER_UIDS` that surface to valid generated source output, and satisfies the active combined-score/emitter gate. This target has blank emitters, so C++ entry remains blocked even though its current score average is above 85.

Existing documentation and prior reports were treated as leads. The conclusion below is based on current IDA MCP, PE/raw scan, and current project docs.

## Current Documentation State

The target page currently records:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The page already captures the main live facts: exact range `0x0041b2d0-0x0041b2e4`, stale IDA filesystem name, body forwarding to `0x00596960`, Thread as the best forced semantic candidate, FileDownloader adjacency as weak evidence only, and no xref/table/source-island evidence for a direct owner.

`auto-generated/-ag-memory-coverage.md` still lists the item as no-owner with blank emitters:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

The no-owner/non-emitting subsection also still lists it:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |  |  |
```

## Live IDA MCP Facts

### Function Boundary

`lookup_funcs` in session `b001_0002bd` reports:

| Query | Result |
| --- | --- |
| `0x0041b2c9` | not a function |
| `0x0041b2d0` | function `___std_fs_create_symbolic_link@8`, size `0x14` |
| `0x0041b2db` | inside the same `0x0041b2d0` function |
| `0x0041b2e4` | not a function |
| `0x0041b2f0` | next function `sub_41B2F0`, size `0x0b` |
| `0x0041b270` | previous modeled submit helper `sub_41B270`, size `0x59` |
| `0x00596960` | callee `sub_596960`, size `0x50` |
| `0x0058ea60` | duplicate stale-name wrapper `___std_fs_create_symbolic_link@8_0`, size `0x14` |

`get_bytes 0x0041b2c9 size 0x27` reports:

```text
cc cc cc cc cc cc cc
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
cc cc cc cc cc cc cc cc cc cc cc cc
```

That confirms seven `0xcc` bytes before the function, the exact 20-byte body at `0x0041b2d0-0x0041b2e4`, and twelve `0xcc` bytes before the following helper at `0x0041b2f0`.

### Body And Callee

`decompile 0x0041b2d0` returns:

```c
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
  return sub_596960(this, a2, a3, 0); /*0x41b2e0*/
}
```

The IDA prototype and name are artifacts. The behavior is a simple receiver-preserving queue wrapper.

`decompile 0x00596960` returns a generic queue-post primitive shape:

```c
BOOL __thiscall sub_596960(HANDLE *this, int a2, int a3, int a4)
{
  _DWORD Src[6];

  Src[0] = a2;
  Src[1] = a3;
  Src[2] = a4;
  memset(&Src[3], 0, 12);
  sub_556580(Src);
  return ReleaseSemaphore(this[3], 1, 0);
}
```

`analyze_component` confirms `0x0041b2d0` has one basic block, complexity 1, no strings, no globals, and a single callee edge to `0x00596960`. It also confirms `0x0041b270 -> 0x00596960` as an adjacent but separate submit-helper edge, while `0x0041b2f0` has no callee.

### Xrefs

`xrefs_to` reports:

| Address | Xref result |
| --- | --- |
| `0x0041b2d0` | zero cross-references |
| `0x0041b2e4` | zero cross-references |
| `0x0041b2f0` | one code xref at `0x005f670e` from FileDownloader constructor/unwind context |
| `0x0041b270` | one code xref at `0x0041c21b` from a known submit-helper caller |
| `0x00596960` | 22 code xrefs across downloader, MiscWorkThread/socket/packet-send-style wrappers, including the call at `0x0041b2db` |
| `0x0058ea60` | zero cross-references |

This contrast matters: the adjacent FileDownloader helper and following global-clear helper have direct route evidence, but `0003GY` does not.

### Duplicate Stale IDA Name

`lookup_funcs` and `decompile` show another stale-name wrapper at `0x0058ea60`:

```c
int __stdcall __std_fs_create_symbolic_link(int a1, int a2)
{
  return sub_58F690(a1, a2, 0); /*0x58ea70*/
}
```

It has the same tiny "forward two args plus zero" wrapper shape but forwards to a different callee and also has zero xrefs. This weakens the IDA `___std_fs_create_symbolic_link` name as ownership evidence; the name is not a reliable semantic signal for `0003GY`.

## PE / Raw Evidence

A current PE byte scan of `NexusTK.exe` with imagebase `0x00400000` found:

```text
Exact target body hits: 1 => 0x0041b2d0 raw 0x0001a6d0
Wrapper shape hits: 2
  0x0041b2d0 raw 0x0001a6d0 -> callee 0x00596960
  0x0058ea60 raw 0x0018de60 -> callee 0x0058f690
Absolute VA pointer 0x0041b2d0 hits: 0
RVA pointer 0x0001b2d0 hits: 0
push absolute VA hits: 0
Relative branch/call/jump hits into 0x0041b2d0: 0
```

This independently supports the IDA result: the function body is unique at the exact target address, the broader wrapper idiom is not unique, and there is no raw pointer or branch/call evidence routing execution or data to this wrapper.

## Documentation Evidence Checked

- [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) is a mixed, non-reconstructable inventory. It lists `0003GY` as a real unreferenced thread queue wrapper bounded by padding and explicitly says Thread is the best forced semantic candidate but direct ownership is unproven.
- [UID:0000OR][Thread](../../../../../by-file/Thread.md) is scored `89/85`, owns the utility thread module, and records `0x00596960` as the generic queue post primitive emitted by current Thread generated output.
- [UID:0000EV][Thread](../../../../../by-class/Thread.md) is scored `86/85`, owned by `0000OR`, and lists `0x00596960-0x00596ae8` as async/sync message-post helpers.
- [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](../../../../../by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) currently treats the `0x00596960` helper as Thread-owned dispatch infrastructure, not as a cash-shop-only method.
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](../../../../../by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) records broad Thread queue/wait evidence and 22 callers for `0x00596960` across multiple subsystems.
- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) documents the FileDownloader dispatcher, request-submit helpers, `dword_67A738` lifetime, and vtable/literal children. It does not list `0003GY` as a FileDownloader child.
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](../../../../../by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) has direct caller and queue-message evidence that `0003GY` lacks.
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) has direct constructor/unwind xref evidence that `0003GY` lacks.
- [UID:00001H][CashShopRequest](../../../../../by-class/CashShopRequest.md) explicitly treats `0x00596960` as likely generic Thread queue infrastructure unless later evidence proves otherwise.

## Function And Child Inventory

| Range | Status | Decision |
| --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | padding | Seven `0xcc` bytes; no child needed. |
| `0x0041b2d0-0x0041b2e4` | real function | This target; exact aligned 20-byte wrapper. |
| `0x0041b2e4-0x0041b2f0` | padding | Twelve `0xcc` bytes; no child needed. |
| `0x0041b2f0-0x0041b2fb` | separate function | [UID:0000WK][ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md), already separately documented. |

No split is needed. The target is already a complete function-sized child with padding on both sides. No merge is needed because the predecessor, target, and successor have different xref/ownership evidence.

## Ranked Ownership And Emitter Analysis

### Best Forced Candidate: Thread / `util/Thread.cpp`

Evidence for:

- The wrapper does nothing except call the Thread-owned queue-post primitive at `0x00596960`.
- It preserves `ecx` as the receiver and supplies an explicit zero third payload field, matching a convenience overload/wrapper over a generic async queue post.
- Current Thread docs and IDA evidence place `0x00596960` in a broad base Thread queue-helper family with 22 callers across multiple subsystems.

Evidence against assignment:

- There are no xrefs, vtable slots, RTTI routes, raw pointer references, or branch/call targets to this wrapper.
- The function is physically outside the main `0x00596250-0x0059756e` Thread/ThreadMan island.
- The wrapper has no Thread-specific field access beyond passing `this` into the callee. A callee relationship alone does not prove where the wrapper was declared.
- The duplicate wrapper shape at `0x0058ea60` shows this tiny forwarder idiom can appear with unrelated callees and cannot be used alone as source-owner proof.

Decision: Thread remains the best forced semantic candidate, but not enough to set `CANONICAL_OWNER:0000OR` or `0000EV`, and not enough to emit under `0000OR`.

### Second Candidate: FileDownloader / `network/FileDownloader.cpp`

Evidence for:

- The wrapper sits inside the broad `0x0041a670-0x0041b69f` FileDownloader dispatch inventory.
- It is adjacent to FileDownloader request-submit and constructor-unwind support helpers.

Evidence against assignment:

- It is separated from both neighbors by `0xcc` padding.
- It has no `dword_67A738` access, no downloader message ID, no payload allocation, no FileDownloader fields, no FileDownloader vtable/data ref, and no caller that passes the FileDownloader singleton.
- Nearby FileDownloader-owned helpers have concrete positive evidence: `0x0041b270` has a caller at `0x0041c21b`, while `0x0041b2f0` has a constructor/unwind xref at `0x005f670e`. This wrapper has none.

Decision: reject FileDownloader ownership. Address adjacency is not enough under by-structure rules.

### Rejected Candidate: CashShopRequest / CashShopVersionRequest

Evidence for:

- The predecessor function allocates a version request and posts a cash-shop downloader message.
- Older queue-helper docs historically used CashShopRequest names around the `0x00596960` region.

Evidence against assignment:

- This wrapper has no payload construction, no cash-shop vtable, no request fields, no known cash-shop callers, and no message constant.
- Current CashShopRequest documentation explicitly says `0x00596960` should be treated as generic Thread queue infrastructure unless later evidence proves a specific override/wrapper.

Decision: reject.

### Rejected Candidate: Socket / Packet Sender

Evidence for:

- Some proven socket/packet send wrappers call the same generic queue-post primitive.

Evidence against assignment:

- This wrapper has no socket globals, packet buffer references, packet opcodes, caller route, or command-dispatch evidence.
- Other socket/packet wrappers are owned because they have direct callers and source-use routes; this target does not.

Decision: reject.

### Rejected Candidate: CRT / std Filesystem

Evidence for:

- IDA currently names the function `___std_fs_create_symbolic_link@8`.

Evidence against assignment:

- The body has no filesystem path handling, no Windows filesystem API call, no error translation, no import/IAT relation, and no string use.
- It calls the NexusTK Thread queue helper at `0x00596960`.
- A second stale-name wrapper exists at `0x0058ea60` with a different callee and zero xrefs, showing the name is not reliable here.

Decision: reject runtime/filesystem reclassification and reject using the IDA name as a source-name repair target.

## Emitter Decision

Leave `EMITTER_UIDS` blank.

No generated-output route is proven. The wrapper has zero IDA xrefs, zero PE pointer hits, zero raw branch/call/jump hits into the target, no table slot, no receiver-origin path, and no source-use context. The Thread callee's emitter route does not make this wrapper emit under Thread, and the FileDownloader/CashShop/Socket candidates have no route to this exact wrapper.

This is not a shared literal/data case where `CANONICAL_OWNER:NONE` plus multiple emitters is warranted. It is code with no proven source-use route.

## Reconstruction And Reclassification Decision

Keep `RECONSTRUCTABLE:TRUE`. The body is real project/source-shaped helper code with exact boundaries and clear behavior. Reclassifying it as padding, ignored runtime support, or non-reconstructable would hide a real helper that may become placeable if later caller/table/debug/source evidence is found.

Do not add or recommend final C++. The active code-entry gate is blocked by blank `EMITTER_UIDS`, and the source placement/name remain unproven.

## Alternatives Rejected

- Assign to Thread now: rejected because only the callee is proven Thread-owned; this wrapper's declaration owner is not.
- Assign to FileDownloader now: rejected because physical adjacency is the only supporting fact and direct FileDownloader evidence is absent.
- Assign to CashShopRequest/CashShopVersionRequest: rejected because there is no payload, vtable, message, field, or caller evidence.
- Assign to Socket/packet sender: rejected because there is no socket global, opcode, packet buffer, or caller route.
- Add one or more emitters with `CANONICAL_OWNER:NONE`: rejected because no source-use output context is proven.
- Reclassify as non-reconstructable or ignored runtime code: rejected because the function is source-shaped project code that calls project Thread infrastructure.
- Split further: rejected because this is a single one-basic-block function bounded by padding.
- Merge into the FileDownloader aggregate: rejected because the exact child split is correct and the aggregate is a mixed non-reconstructable inventory.
- Apply an IDA-safe rename as required repair: rejected as unnecessary for documentation. `UnreferencedThreadDispatchWrapper_41B2D0` would be a safe hygiene name if an IDA naming pass is authorized, but no documentation or ownership decision depends on it.

## Exact Required Edits

No by-memory, by-file, by-class, by-global, by-type, generated coverage, or shared coverage edits are required.

The target metadata should remain:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No C++ body should be added.

## Supervisor-Owned Shared Report Text

No edit to `by-memory/-coverage-report.md` is needed. The existing row is acceptable and should remain in place. If the supervisor wants explicit retained text, keep the row as currently written:

```text
- [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

No replacement row is proposed for `auto-generated/-ag-memory-coverage.md`; it should continue to show `no-owner`, `NONE`, and blank emitters until validator generation changes from future documentation evidence.

## Validation

- Normal validator `--apply`: not run, because no by-* or shared project documentation file was edited. This pass creates only this B001 research report.
- Dry runs used: none.
- IDA database edits: none.
- C++ code entry: none; blocked by blank `EMITTER_UIDS`.

## Changed Files

- Added `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-research.md`

No target documentation was changed, so before/after scores remain `COMPLETION:86`, `CONFIDENCE:86`.

## Lease State

No lease was acquired. This report is inside the Agent-B001 research folder, and no leased by-* documentation file was edited.

## Confidence

Final recommendation confidence: high for keeping the current no-owner/non-emitting state.

The evidence is strong for exact function bounds, body semantics, callee identity, stale IDA name rejection, zero xrefs, zero raw pointer/branch references, no split/merge need, and blank emitter routing. It remains below final-source certainty because the original declaration owner and source-facing helper name are still unproven. The specific evidence that would change this recommendation is a real caller, vtable/function-pointer/data reference, source/debug symbol, receiver-origin proof, or a validated generated-source route to this exact wrapper.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
