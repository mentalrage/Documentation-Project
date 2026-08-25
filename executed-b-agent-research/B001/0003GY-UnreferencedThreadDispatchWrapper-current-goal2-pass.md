** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# [UID:0003GY] UnreferencedThreadDispatchWrapper Current Goal 2 Pass

## Final Recommendation

Keep [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) unchanged:

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- `COMPLETION:86`
- `CONFIDENCE:86`
- blank `RECONSTRUCTION_CPP`

This is a real 20-byte project helper that forwards two arguments plus zero into the generic Thread queue-post primitive at `0x00596960`. It is not padding and not CRT filesystem code. It should remain no-owner/non-emitting because current IDA evidence still finds no caller, table slot, pointer reference, raw branch/call target, import relation, receiver-origin route, or source-use context that proves a direct source owner or output emitter.

The stale IDA name `___std_fs_create_symbolic_link@8` is misleading. An optional IDA database hygiene rename to `UnreferencedThreadDispatchWrapper_41B2D0` would be safe, but no project documentation repair is required because the current by-memory page already rejects the stale filesystem interpretation.

## Target And Scope

- Assigned target: [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md)
- Current generated coverage state: `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current generated no-owner/non-emitting row: present in `auto-generated/-ag-memory-coverage.md`
- Prior reports read as background only:
  - `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md`
  - `Agent-B003/research/executed/0003GY-UnreferencedThreadDispatchWrapper-second-pass.md`
- Live evidence session used for this pass: IDA MCP session `b001_0003gy`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.

## Evidence Standards

This pass used the current B-agent by-structure rules:

- `CANONICAL_OWNER` means the narrowest defensible semantic declaration owner, not the nearest address neighborhood.
- `EMITTER_UIDS` means proven source-output routing, not "callee belongs to this file."
- `CANONICAL_OWNER:NONE` is correct when source-shaped code exists but no direct owner route clears the evidence gate.
- Blank `EMITTER_UIDS` is correct when no source-use/output route is proven.
- Code-entry recommendations require `90/90+`; this page is `86/86`, so C++ remains blank.
- Existing docs and prior reports were treated as leads. Live IDA MCP and current docs were rechecked.

## Current Documentation State

The target page currently records:

- UID `0003GY`
- exact range `0x0041b2d0-0x0041b2e4`
- `COMPLETION:86`, `CONFIDENCE:86`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- no C++ body

The page already states the correct core facts: the IDA name is stale, the body forwards to `0x00596960`, Thread is the best forced semantic candidate, FileDownloader adjacency is weak, and no xref/table/source-island evidence proves a direct owner.

Current generated coverage rows also match that state:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |  |  |
```

## Live IDA MCP Facts

### Function Boundary

`lookup_funcs` reports:

- `0x0041b2d0`: function `___std_fs_create_symbolic_link@8`, size `0x14`
- `0x0041b2e4`: not a function
- `0x0041b2f0`: next function `sub_41B2F0`, size `0x0b`
- `0x0041b270`: previous function `sub_41B270`, size `0x59`
- `0x00596960`: generic queue helper `sub_596960`, size `0x50`

Byte evidence for the target is exact:

```text
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
```

The surrounding bytes show:

- `0x0041b2c9-0x0041b2d0`: seven `0xcc` bytes before the wrapper
- `0x0041b2d0-0x0041b2e4`: the target function
- `0x0041b2e4-0x0041b2f0`: twelve `0xcc` bytes after the wrapper
- `0x0041b2f0`: the following FileDownloader unwind/global-clear helper starts

### Body

Disassembly:

```asm
push ebp
mov  ebp, esp
push 0
push [ebp+arg_4]
push [ebp+arg_0]
call sub_596960
pop  ebp
retn 8
```

Hex-Rays decompile:

```c
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
  return sub_596960(this, a2, a3, 0);
}
```

The prototype/name are IDA artifacts; the behavior is a simple queue wrapper.

### Callee

`callees 0x0041b2d0` lists only `sub_596960`.

`analyze_function 0x00596960` decompiles the callee as a generic Thread queue-post primitive:

```c
Src[0] = a2;
Src[1] = a3;
Src[2] = a4;
memset(&Src[3], 0, 12);
sub_556580(Src);
return ReleaseSemaphore(this[3], 1, 0);
```

`xrefs_to 0x00596960` reports 22 code refs spread across downloader, MiscWorkThread, Socket, and packet-send/request wrappers. This broad fan-in supports generic Thread ownership for the callee, but it does not prove the wrapper's direct declaration owner.

### Xrefs And Raw References

Current live checks found:

- `xrefs_to 0x0041b2d0`: zero refs
- `xrefs_to 0x0041b2e4`: zero refs
- exact target body signature: one hit at `0x0041b2d0`
- wildcard wrapper shape `55 8B EC 6A 00 FF 75 ?? FF 75 ?? E8 ?? ?? ?? ?? 5D C2 08 00`: two hits, `0x0041b2d0` and unrelated duplicate-name wrapper `0x0058ea60`
- target VA dword `D0 B2 41 00`: zero hits
- target RVA dword `D0 B2 01 00`: zero hits
- `push 0x0041b2d0` pattern: zero hits

The duplicate stale-name function at `0x0058ea60` also has no callers and forwards to unrelated `sub_58F690`, which further weakens the IDA filesystem name as evidence.

### Filesystem-Name Check

`entity_query` for `std_fs|symbolic_link` finds only:

- `0x0041b2d0` named `___std_fs_create_symbolic_link@8`
- `0x0058ea60` named `___std_fs_create_symbolic_link@8_0`

`find_regex CreateSymbolicLinkW` finds a string at `0x00634034`, with one xref from `?initialize_pointers@@YAHXZ` at `0x005c710c`. `imports_query CreateSymbolicLink*` and `imports_query *Symbolic*` return no imports. There is no call, pointer, branch, import/IAT, or behavior link between the string/API resolver area and this wrapper.

## Related Documentation Cross-Check

[UID:0000OR][Thread](../../../../../by-file/Thread.md) and [UID:0000EV][Thread](../../../../../by-class/Thread.md) document `0x00596960` as the generic asynchronous queue-post helper owned by base Thread infrastructure. [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](../../../../../by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) currently records `CANONICAL_OWNER:0000OR`, `EMITTER_UIDS:0000OR`, and describes `0x00596960-0x005969b0` as packing a six-dword request record, queueing it, and releasing the semaphore.

[UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) and [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) correctly identify the neighboring FileDownloader helpers. The adjacent previous helper [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](../../../../../by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) is FileDownloader-owned because it has a caller passing `dword_67A738`, constructs a `CashShopVersionRequest`, and posts message `10002`. The following helper [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) is FileDownloader-owned because it clears `dword_67A738` and is reached from FileDownloader constructor-unwind code at `0x005f670e`.

`0003GY` lacks those FileDownloader-specific facts. It has no `dword_67A738` access, no downloader message constant, no payload construction, no FileDownloader fields, and no unwind xref.

Socket queue wrappers provide a useful contrast. [UID:0003AZ][0x00574b90-0x00574ba4.PostSocketReceiveCommand](../../../../../by-memory/0x00574b90-0x00574ba4.PostSocketReceiveCommand.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) call the same generic queue primitive but are Socket-owned because direct callers, receiver-origin, global lifetime, and dispatcher-command evidence prove Socket source use. No equivalent route exists for `0003GY`.

## Function And Child Inventory

| Range | Current disposition | Current evidence decision |
| --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | padding | Seven `0xcc` bytes before target. |
| `0x0041b2d0-0x0041b2e4` | real function | This target, exact aligned 20-byte wrapper. |
| `0x0041b2e4-0x0041b2f0` | padding | Twelve `0xcc` bytes before following helper. |
| `0x0041b2f0-0x0041b2fb` | separate helper | FileDownloader unwind/global-clear helper with its own UID and owner. |

No split is needed. The target is already an exact function-sized child bounded by padding.

## Ownership And Emitter Decision

### Best Forced Candidate: Thread

Thread is the best semantic candidate because the target does nothing except forward to the Thread-owned queue-post primitive at `0x00596960`, preserving `ecx` as the receiver and supplying a zero optional field.

Thread still should not be assigned as `CANONICAL_OWNER` because the evidence proves only the callee's owner, not the wrapper's declaration owner. There is no caller, vtable entry, RTTI route, function-pointer route, source island, receiver-origin fact, or class-specific field access tying this exact wrapper to [UID:0000EV][Thread](../../../../../by-class/Thread.md) rather than a derived class, file-local helper, or dead overload.

### Emitter Decision

`EMITTER_UIDS` should remain blank. No source-output route is proven. The wrapper has zero callers and no table/pointer/branch/source-use context. The Thread callee's emitter route does not make this wrapper an emitter, and no FileDownloader/Socket/CashShop route reaches this wrapper.

### Reconstruction Decision

`RECONSTRUCTABLE:TRUE` remains correct. This is source-shaped project code with clear behavior and exact boundaries. It is not ready for C++ entry because the active code-entry gate is `90/90+`, while this item remains `86/86` and lacks owner/source-placement proof.

## Alternatives Rejected

- Assign to [UID:0000OR][Thread](../../../../../by-file/Thread.md): rejected for now. The callee is Thread-owned, but the wrapper itself has no direct owner proof.
- Assign to [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md): rejected. Physical adjacency is not enough, and the wrapper lacks `dword_67A738`, downloader message IDs, FileDownloader fields, FileDownloader callers, and unwind evidence.
- Assign to CashShopRequest/CashShopVersionRequest: rejected. The wrapper does not allocate payloads, install request vtables, post known cash-shop downloader messages, or have cash-shop-specific callers.
- Assign to Socket: rejected. Socket has proven command-post wrappers elsewhere, but this target has no Socket caller, global receiver, dispatcher case, or command ID evidence.
- Reclassify as CRT/filesystem/runtime: rejected. The stale IDA name is not supported by behavior, imports, strings, or xrefs.
- Merge back into the FileDownloader aggregate: rejected. The exact child split is correct and the parent aggregate is a mixed inventory.
- Split further: rejected. The target is a single aligned basic-block wrapper with a complete function object and padding on both sides.

## Exact Required Edits

No by-memory, by-file, by-class, by-global, by-type, or generated/shared coverage edits are required.

Target page should remain:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No C++ should be entered.

## Supervisor-Owned Shared Report Text

No edit to `by-memory/-coverage-report.md` is needed. The current row is accurate. If supervisor wants explicit retained text, keep the row exactly as follows at the current position between the `0x0041b2c9-0x0041b2d0` and `0x0041b2e4-0x0041b2f0` padding rows:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

No replacement row is proposed for `auto-generated/-ag-memory-coverage.md`; it should continue to show `no-owner`, `NONE`, and blank emitters.

## Validation

- Normal validator `--apply`: not run, because no in-scope project documentation files were edited. This pass creates only this B001 research report.
- Dry runs: none used.
- C++ code-entry gate: not met; no C++ emitted.

## Lease State

No lease was acquired because no leased project documentation file was edited. A current lease check for `B001`, `0003GY`, `0041b2d0`, and `UnreferencedThreadDispatchWrapper` returned no matching active lease entries.

## Changed Files

- Added `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md`

## Confidence

Final research score: `86/86`, matching the target page.

The conclusion is strong for exact function bounds, body behavior, callee identity, non-filesystem classification, zero inbound xrefs, and blank emitter routing. It remains below `90/90+` because the original declaration owner and source-facing helper name are still unproven.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
