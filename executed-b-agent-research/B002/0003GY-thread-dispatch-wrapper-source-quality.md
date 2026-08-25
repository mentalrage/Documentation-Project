** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# B002 Source-Quality Report: [UID:0003GY] UnreferencedThreadDispatchWrapper

Assignment: `B002-goal2-thread-dispatch-wrapper-source-quality-0003GY-20260617`  
Agent: B002  
Date: 2026-06-17  
Primary target: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`

## Recommendation Summary

Keep [UID:0003GY] as a real, reconstructable, non-emitting no-owner helper:

```yaml
COMPLETION: 86
CONFIDENCE: 86
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

The current IDA function name `___std_fs_create_symbolic_link@8` is not credible. The body is a tiny wrapper around the client thread message queue primitive at `0x00596960`, not a filesystem/STL routine. Fresh IDA MCP checks and raw PE scans found no caller, pointer, vtable slot, import/IAT relation, or source-use context for `0x0041b2d0`, so no `Thread`, `FileDownloader`, or derived-thread owner/emitter route is defensible at the current evidence level.

The best source-facing semantic model is a retained dead/private convenience wrapper equivalent to:

```cpp
// Descriptive only. Do not populate the formal target C++ block.
BOOL ThreadDispatchRequestDefaultParamWrapper(Thread *thread, int messageId, void *payload)
{
    return thread->DispatchRequest(messageId, payload, 0);
}
```

That model explains the code but does not establish where the function was declared or emitted in source.

## Current Binary Facts

Current IDA MCP session used: `b003_00018a_ime_comp_20260617` over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. Server health reported image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Function/boundary facts:

- `0x0041b2d0`: IDA function `___std_fs_create_symbolic_link@8`, size `0x14`.
- `0x0041b2e4`: not a function start.
- Preceding live function tail ends before `0x0041b2c9`; bytes `0x0041b2c9-0x0041b2d0` are `0xcc` padding.
- Following bytes `0x0041b2e4-0x0041b2f0` are `0xcc` padding; next function starts at `0x0041b2f0` (`ClearFileDownloaderRequestGlobal`).
- The wrapper body bytes are:

```asm
0041b2d0 55              push ebp
0041b2d1 8b ec           mov  ebp, esp
0041b2d3 6a 00           push 0
0041b2d5 ff 75 0c        push [ebp+0Ch]
0041b2d8 ff 75 08        push [ebp+08h]
0041b2db e8 80 b6 17 00  call 00596960
0041b2e0 5d              pop  ebp
0041b2e1 c2 08 00        retn 8
```

Xref/callee facts:

- `xrefs_to(0x0041b2d0)`: zero.
- `xrefs_to(0x0041b2e4)`: zero.
- `callees(0x0041b2d0)`: only `0x00596960`.
- `xrefs_to(0x00596960)`: 22 code references, including calls from the nearby `0x0041b1e8`, `0x0041b253`, `0x0041b2aa`, `0x0041b2bf`, and this wrapper at `0x0041b2db`.
- `0x00596960` packs a six-dword request record, inserts it through the queue helper at `0x00556580`, and releases `this+0x0c` via `ReleaseSemaphore`.

Hex-Rays decompilation of the wrapper currently prints a polluted type:

```cpp
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
    return sub_596960(this, a2, a3, 0);
}
```

The `HANDLE *` receiver and filesystem name come from the stale symbol/name, not from body evidence.

## Raw PE Scan Evidence

I performed a local PE-aware scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using image base `0x00400000`.

Section facts used by the scan:

- `.text`: `0x00401000-0x0060c000`, raw offset `0x00000400`.
- `.rdata`: starts at `0x0060d000`.
- `.data`: starts at `0x0066d000`.
- `0x0041b2d0` raw file offset: `0x0001a6d0`.

Direct surface results:

- Absolute VA dword hits for `0x0041b2d0`: none.
- RVA dword hits for `0x0041b2d0`: none.
- `E8/E9/0F8x` rel32 branch/call targets to `0x0041b2d0`: none.
- Short-branch target scan produced no real control-flow target to `0x0041b2d0`.
- Exact 20-byte body hit: one, at VA `0x0041b2d0`.
- Wrapper-shape hits for `55 8B EC 6A 00 FF 75 ?? FF 75 ?? E8 .... 5D C2 08 00`: two:
  - `0x0041b2d0 -> 0x00596960`
  - `0x0058ea60 -> 0x0058f690`
- `CreateSymbolicLinkW` string hit: one at VA `0x00634034`, with no import-table match and no call/data relation to this wrapper.

Positive controls:

- `0x00596960` produced 22 real `E8` call-surface hits, matching IDA xrefs.
- `0x0041b2f0` produced the expected constructor/unwind rel32 hit at `0x005f670e`.
- FileDownloader global `dword_67A738` produced nine VA pointer hits, matching IDA data refs.

These controls show the scan was able to find normal call and pointer surfaces in this binary. The negative result for `0x0041b2d0` is therefore meaningful, not merely a tooling blind spot.

## Source-Shape And Parameter Semantics

The receiver is best modeled as a `Thread`-compatible object because `0x00596960` uses:

- `this+0x4c`: queue/storage object passed into the insert helper at `0x00556580`.
- `this+0x0c`: semaphore handle passed to `ReleaseSemaphore`.

The two explicit wrapper parameters are best named:

- `messageId` or `requestCode`: copied into request slot 0.
- `payload`, `param1`, or `requestParam`: copied into request slot 1.

The wrapper forces request slot 2 to zero by pushing `0` before forwarding. The generic callee then zeroes request slots 3-5, so the resulting record is:

```text
{ messageId, payload, 0, 0, 0, 0 }
```

Best descriptive names, in ranked order:

1. `ThreadDispatchRequestDefaultParamWrapper`
2. `ThreadPostRequestDefaultParam`
3. `DispatchRequestDefaultParam`
4. `PostThreadMessage2Arg`

I do not recommend promoting any of these as a formal original name. They are source-quality semantic labels only.

## Ownership And Source-Placement Analysis

### Thread / `NexusTK/util/Thread.cpp`

This is the strongest semantic candidate because the only callee is the generic Thread queue-post helper at `0x00596960`, and support docs already place that helper under Thread/ThreadMan. The wrapper has the same receiver contract as `Thread::DispatchRequest`-style helpers.

Rejected as canonical owner/emitter because:

- The wrapper is outside the known Thread/ThreadMan memory island.
- There is no call, vtable, data pointer, or source-neighbor evidence connecting `0x0041b2d0` to Thread's source file.
- Ownership of a callee does not prove ownership of an unreferenced wrapper around that callee.
- The duplicate stale-name wrapper at `0x0058ea60` shows IDA can assign the same bogus name to unrelated tiny wrappers, so the name is not usable as provenance.

Recommended impact: mention as the best semantic dependency, not the canonical owner.

### FileDownloader / `NexusTK/network/FileDownloader.cpp`

This is the strongest address-neighborhood candidate because the wrapper sits in the broad `FileDownloaderDispatch` span and near FileDownloader submit/clear helpers.

Rejected as canonical owner/emitter because:

- The wrapper does not touch `dword_67A738`, FileDownloader fields, URLs, request state, or FileDownloader-specific message constants.
- Fresh PE and IDA checks found no caller from FileDownloader code and no pointer/data relation.
- Neighboring FileDownloader helpers call `0x00596960` directly; this wrapper is not on their call path.
- The broad aggregate is explicitly a mixed address inventory, not proof of source ownership for every child in the span.

Recommended impact: keep [UID:0000WI] as non-emitting mixed inventory; do not absorb [UID:0003GY] into FileDownloader generated output.

### Derived Thread / Worker-Thread Source-Local Helper

This remains plausible as a historical source shape: a source-local or class-local overload that posts a two-argument message to a Thread-derived worker and defaults the third queue parameter to zero.

Rejected as canonical owner/emitter because no derived class has a caller, vtable slot, table pointer, import thunk, or source-neighbor evidence to this exact address. Assigning it to FileDownloader, CashShopRequest, MiscWorkThread, or another worker would be a guess without differentiating evidence.

### CRT/STL/Filesystem Runtime

Rejected.

Evidence:

- No `CreateSymbolicLinkW` import.
- The only `CreateSymbolicLinkW` string is unrelated `.rdata`.
- The wrapper has no path, wide-string, Win32 error, or filesystem API behavior.
- The body calls a NexusTK Thread queue helper, not a CRT/STL runtime routine.
- A same-shape duplicate at `0x0058ea60` carries the same stale label while calling a different local helper, confirming symbol/name pollution.

### New Narrow Source Grouping

Rejected for now.

There is no cluster of related live helpers around `0x0041b2d0`; it is bounded by padding and unrelated nearby helpers. A new file/grouping for one no-xref wrapper would create source placement noise without improving reconstruction quality.

## Heuristic / Inference Reanalysis And Validation

Best defensible inference:

- [UID:0003GY] is real client code, not padding and not a runtime import thunk.
- It is most likely a source-authored or source-declared convenience wrapper that posts a two-argument request to the generic Thread queue while defaulting the third queue parameter to zero.
- It was retained in the binary even though no current direct caller, pointer, or vtable use survives.
- The current IDA name `___std_fs_create_symbolic_link@8` is stale/misapplied and should be treated as a misleading generated label, not as source provenance.

Evidence checked:

- Current target doc, prior B001/B002/B003 reports, Thread class/file docs, FileDownloader class/file/docs, Thread message dispatch helper docs, aggregate FileDownloader dispatch docs, generated/source-tree output, and ignored padding docs.
- IDA MCP function boundaries, xrefs, callees, decompilation, raw bytes, function-name query, `CreateSymbolicLinkW` string query, and imports query.
- Local PE-aware VA/RVA pointer scans, rel32 branch/call scans, short-branch target scan, exact-body scan, wrapper-shape scan, and positive controls for known live functions/globals.

Rejected alternatives:

- Original filesystem/STL function: contradicted by body, imports, strings, and callee.
- Compiler/runtime artifact: contradicted by ordinary body shape and local Thread queue helper call. It is not an import thunk, EH helper, scalar deleting destructor, adjustor thunk, security-cookie helper, or CRT stub.
- FileDownloader-owned helper: address-neighborhood only; no data/caller/field evidence.
- Thread-owned emitting method: semantic callee relation only; no source-placement or declaration evidence for this exact wrapper.
- Derived-thread-specific helper: plausible pattern, but no candidate can be ranked above another from direct evidence.
- New source file/group: unsupported by cluster evidence.

Validation or contradiction of existing docs:

- Validates the target doc's warning that `___std_fs_create_symbolic_link@8` is misleading.
- Validates prior B001/B002/B003 no-owner/no-emitter recommendation.
- Strengthens the earlier no-pointer/no-xref conclusion with current MCP and PE positive-control scans.
- Refines the semantic description: the wrapper should be described as a two-argument Thread request dispatch wrapper with the third request parameter forced to zero, not merely an "unreferenced wrapper."

Score/source-placement/final-C++ impact:

- The target is already above the numeric 85/85 threshold at `86/86`, but the current C++ gate also requires a nonblank emitter route.
- Because no owner/emitter route is defensible, the score should not be raised solely from semantic confidence.
- Keep `CANONICAL_OWNER:NONE`, blank emitters, and blank formal C++.
- Keep `RECONSTRUCTABLE:TRUE`, because the small body is mechanically reconstructable and source-shaped; lack of owner prevents emission, not understanding.

## First-Draft C++ Recommendation / Final-C++ Policy

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:0003GY].

Reason: the helper's behavior is clear, but the declaration owner/source file is not. Entering formal C++ would create emitted source for a no-owner target and would imply an unsupported class/file placement.

If the supervisor wants an explanatory note only, use this as non-formal pseudocode:

```cpp
// Descriptive only; not for formal RECONSTRUCTION_CPP.
BOOL ThreadDispatchRequestDefaultParamWrapper(Thread *thread, int messageId, void *payload)
{
    return thread->DispatchRequest(messageId, payload, 0);
}
```

Do not attach this to `FileDownloader`, `CashShopRequest`, or `Thread` generated output unless future evidence finds a real caller/pointer/declaration path.

## Exact Metadata Recommendations

For `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`:

```yaml
COMPLETION: 86
CONFIDENCE: 86
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

No child split is needed. Exact range `0x0041b2d0-0x0041b2e4` remains correct. Padding boundaries remain:

- `0x0041b2c9-0x0041b2d0`: seven `0xcc` bytes.
- `0x0041b2e4-0x0041b2f0`: twelve `0xcc` bytes.

## Support-Doc Update Recommendations

Target page update recommended:

Add a 2026-06-17 B002 reanalysis note to [UID:0003GY]:

```markdown
- 2026-06-17 B002 source-quality reanalysis: current MCP session `b003_00018a_ime_comp_20260617` reconfirmed exact `0x14` function body, stale `___std_fs_create_symbolic_link@8` label, zero xrefs to `0x0041b2d0`, zero xrefs to endpoint `0x0041b2e4`, sole callee `0x00596960`, duplicate stale-name wrapper at `0x0058ea60` calling unrelated `0x0058f690`, and `CreateSymbolicLinkW` string with no import/xref relation. Local PE scan found one exact body hit, two wrapper-shape hits, no VA/RVA pointer hits to `0x0041b2d0`, no real branch/call target to the wrapper, and positive-control hits for `0x00596960`, `0x0041b2f0`, and `dword_67A738`. Keep `86/86`, `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:TRUE`, and blank formal C++.
```

Optional support notes:

- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`: keep [UID:0003GY] listed as a real non-emitting child inside the broad mixed inventory, but do not assign it to FileDownloader.
- Thread support docs may mention [UID:0003GY] as a dependency-only semantic wrapper around `0x00596960`; do not make it a Thread-owned emitted child without new caller/declaration evidence.
- `by-memory/-ignored.md`: no change required; existing padding rows are still valid.
- Generated output should not gain a new function for this target.

## Supervisor-Owned Coverage Row Text

`by-memory/-coverage-report.md` is supervisor-owned. I did not edit it. The local coverage report appears stale around this range: it lists [UID:0000WI] as an old reconstructable aggregate row and omits the [UID:0003GY] child plus the two padding rows between [UID:0002CL] and [UID:0000WK].

Recommended replacement for the current [UID:0000WI] row:

```markdown
    - [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) 0x0041a670-0x0041b69f | aggregate | FileDownloaderDispatch : ignored : 88% : strong : Reviewed non-emitting mixed address inventory over FileDownloader construction/dispatch/download helpers plus adjacent Thread-wrapper, runtime string, JsonCpp, CashShop request, padding, and destructor support; exact child pages carry the real source/runtime ownership. Current B002 2026-06-17 reanalysis reconfirmed [UID:0003GY] inside this span is real Thread queue wrapper code but still no-owner/non-emitting, so the aggregate itself remains `RECONSTRUCTABLE:FALSE` and owner/emitter blank.
```

Recommended insertions immediately after the [UID:0002CL] row for `0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md` and before the [UID:0000WK] row for `0x0041b2f0-0x0041b2fa.ClearFileDownloaderRequestGlobal.md`:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2c9-0x0041b2d0 | padding | FileDownloaderSubmitCashShopVersionRequest to UnreferencedThreadDispatchWrapper alignment : ignored : 100% : strong : Seven `0xcc` bytes; current B002 2026-06-17 MCP/PE byte checks reconfirmed no fallthrough into the wrapper.
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Current B002 2026-06-17 reanalysis reconfirmed the stale `___std_fs_create_symbolic_link@8` IDA name is unsupported; the real body is a source-shaped two-argument wrapper that forwards `this`, `messageId`, `payload`, and a forced zero third queue parameter to generic Thread queue post helper `0x00596960`. Fresh IDA and PE scans found no caller, vtable/data slot, VA/RVA pointer, real rel32/short-branch target, import/IAT relation, filesystem behavior, or source-use context, so `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:TRUE`, and blank formal C++ remain correct.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2e4-0x0041b2f0 | padding | UnreferencedThreadDispatchWrapper to ClearFileDownloaderRequestGlobal alignment : ignored : 100% : strong : Twelve `0xcc` bytes; current B002 2026-06-17 MCP/PE byte checks reconfirmed the next live helper begins at `0x0041b2f0`.
```

If the supervisor has a fresher coverage report than the local worktree, apply the same row content only where these rows are still missing or stale.

## Validation Commands

Suggested supervisor validation after applying any doc/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [0003GY-thread-dispatch-wrapper-source-quality-removed.md](0003GY-thread-dispatch-wrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional MCP/PE spot checks:

```text
lookup_funcs: 0x0041b2d0, 0x0041b2e4, 0x00596960, 0x0058ea60
xrefs_to: 0x0041b2d0, 0x0041b2e4, 0x00596960
callees: 0x0041b2d0, 0x00596960
get_bytes: 0x0041b2c0 length 0x40
find_regex: CreateSymbolicLink
imports_query: *CreateSymbolicLink*
```

Expected results are the facts recorded above.

## Changed Files

Created this report only:

- `tools/leaser/Agents/Agent-B002/research/0003GY-thread-dispatch-wrapper-source-quality.md`

No by-* docs, generated reports, source files, IDA database files, generated source, or `by-memory/-coverage-report.md` were edited by B002 for this assignment.

## Blockers And Next Useful Work

No blocker prevents supervisor review. The only evidence that could change the no-owner/no-emitter recommendation would be a new source-map/object-file clue, caller recovered outside normal PE control-flow surfaces, or a table/declaration record tying `0x0041b2d0` to a concrete source file/class. Current IDA and PE evidence do not provide that route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B002/0003GY-thread-dispatch-wrapper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
