** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# B001 Research Report: 0003GY UnreferencedThreadDispatchWrapper Current Source Routing

Assignment id: `B001-goal2-thread-dispatch-wrapper-current-source-routing-0003GY-20260618`

Target: [UID:0003GY] `source-3/project-documentation/by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`

Report-only output path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-current-source-routing.md`

## Current Recommendation

Keep the target metadata unchanged:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

The current page's no-owner / no-emitter conclusion is still the best supported state. The function is a real wrapper over the Thread queue-post primitive at `0x00596960`, but I found no current source route that makes the wrapper itself a Thread-owned, FileDownloader-owned, runtime/filesystem-owned, derived-worker-owned, or new-source-family-owned emission unit. It still fails the current code-entry gate because `EMITTER_UIDS` is blank even though the score pair is above 85/85 and the behavior is mechanically reconstructable.

No by-* page, generated report/source, IDA DB, or `by-memory/-coverage-report.md` file was edited for this report.

## Direct Target Facts Rechecked

The target page currently identifies the body as:

```asm
0041b2d0 55              push ebp
0041b2d1 8b ec           mov  ebp, esp
0041b2d3 6a 00           push 0
0041b2d5 ff 75 0c        push dword ptr [ebp+0x0c]
0041b2d8 ff 75 08        push dword ptr [ebp+0x08]
0041b2db e8 80 b6 17 00  call 0x00596960
0041b2e0 5d              pop  ebp
0041b2e1 c2 08 00        ret  8
```

Equivalent descriptive decompilation:

```c
return sub_596960(this, a2, a3, 0);
```

This is a `__thiscall`-style wrapper with two explicit stack arguments and an implicit receiver in `ecx`. It supplies a constant fourth argument of `0` to the queue-post helper at `0x00596960`.

The stale IDA name `___std_fs_create_symbolic_link@8` remains misleading. The body does not manipulate paths, wide strings, filesystem flags, `CreateSymbolicLinkW`, `CreateSymbolicLinkA`, Win32 file handles, reparse points, or CRT/std filesystem data. The local PE import and string-reference checks below found a runtime API-name string route for `CreateSymbolicLinkW`, not a code or ownership route for this wrapper.

The byte neighborhood remains a split island:

```text
0x0041b2c0: previous FileDownloader-family helper tail
0x0041b2c9-0x0041b2d0: int3 padding
0x0041b2d0-0x0041b2e4: target wrapper
0x0041b2e4-0x0041b2f0: int3 padding
0x0041b2f0-0x0041b2fb: FileDownloader global clear helper
```

Physical adjacency to FileDownloader code is real, but the target lacks the caller/global/vtable/source-route evidence that makes the neighboring FileDownloader helpers ownable.

## Current Supporting Docs Reanalyzed

I reread the current target and supporting docs rather than relying only on older executed reports. The following docs are the relevant current state:

| Doc | Current relevance to 0003GY |
| --- | --- |
| `by-file/Thread.md` [UID:0000OR] | Owns `util/Thread.cpp` and the Thread/ThreadMan source root. It now treats `0x00596960` as a generic queue-post primitive used across packet/download/helper wrappers. It explicitly treats `0003GY` as dependency-only and not emitted by Thread because the wrapper has no caller, pointer, vtable, source-neighbor, or declaration evidence proving Thread.cpp output. |
| `by-class/Thread.md` [UID:0000EV] | Assigns `0x00596960-0x00596ae8` to Thread, including async/sync message post helpers. It mentions `0003GY` reaching `0x00596960` but keeps it as a non-emitted dependency wrapper. |
| `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` [UID:0001JY] | Despite the stale generated title, the current doc describes `0x00596960` as an async queue-post helper that builds a six-dword record in the queue at `this+0x4c` and releases the semaphore at `this+0x0c`. It records broad fan-in, which supports the callee's Thread ownership but not this wrapper's source placement. |
| `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` [UID:0001JX] | Current Thread island doc records `0x00596960` as a Thread async post helper and keeps derived classes in feature modules. It supports `0x00596960` being Thread-owned, not automatic ownership of this orphan wrapper. |
| `by-file/FileDownloader.md` [UID:0000JC] | Owns FileDownloader source and the real FileDownloader helper family. It acknowledges mixed nearby code and helper-ownership caveats. It does not provide a source route for `0003GY`. |
| `by-class/FileDownloader.md` [UID:00004W] | Lists confirmed FileDownloader methods by vtable/global/caller evidence. The target is not a confirmed method. |
| `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` [UID:0000WI] | Mixed non-emitting inventory for the surrounding island. It already records `0003GY` as real but unreferenced, with no caller, vtable/data slot, VA/RVA pointer, rel32/short branch, import/IAT relation, FileDownloader field/global access, or filesystem behavior tying it to FileDownloader. |
| `by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimap.md` [UID:0002CJ] | Nearby FileDownloader submit helper. It has a direct caller passing `dword_67A738` and calls `sub_596960(this, 10000, payload, 0)`. This is a positive contrast for what target lacks. |
| `by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitFittingRoom.md` [UID:0002CK] | Nearby FileDownloader submit helper. It has a direct caller passing `dword_67A738` and calls `sub_596960(this, 10001, payload, 0)`. Target lacks this route. |
| `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopPreview.md` [UID:0002CL] | Nearby FileDownloader submit helper. It has a direct caller passing `dword_67A738` and calls `sub_596960(this, 10002, payload/null, 0)`. Target is immediately after padding but has no equivalent caller/global route. |
| `by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md` [UID:0000WK] | Nearby FileDownloader global-clear helper. It writes `dword_67A738 = 0` and has a known jump from `0x005f670e`. Target lacks this global and branch route. |
| `by-global/g_pCashShopRequest.md` [UID:0000QH] | Documents `0x0067a738` as the FileDownloader/CashShopRequest global. The target has no reference to it. |
| `by-file/MiscWorkThread.md` [UID:0000LG] and `by-class/MiscWorkThread.md` [UID:00008I] | Current docs assign other `0x00596960` callers to MiscWorkThread because those wrappers have singleton/vtable/caller routes. No route reaches this wrapper. |
| `by-class/CashShopRequest.md` [UID:00001H] | Current doc says `0x00596960` should be treated as generic Thread unless later proof appears. CashShopRequest owns other raw/no-xref helpers only when class/vtable/cluster evidence exists. No target route. |
| `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md` [UID:0001HT] and `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` [UID:0001HU] | These show how Socket/packet send wrappers that call `0x00596960` can be source-routed when receiver globals, command consumers, and field initialization prove a module owner. Target has no comparable evidence. |
| `by-file/ProtocolSend.md` [UID:0000MV] and `by-file/Session.md` [UID:0000NP] | Current placeholders remain `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and are not source roots for generic Thread queue wrappers. They do not justify creating a route for target. |
| `by-file/File.md` and `by-file/PathUtil.md` | Current filesystem utility source roots exist for actual file/path helpers. They provide no symbolic-link or wrapper route for target. |
| `by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md` [UID:00024B], `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md` [UID:000273], and `by-memory/0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md` [UID:0002AJ] | Current runtime docs explain where API-name strings and runtime API-pointer initialization live. This supports rejecting the stale `std_fs_create_symbolic_link` name for the target. |
| `by-memory/-coverage-report.md` | Current coverage already contains the target row and the adjacent padding rows. No coverage replacement is needed. |

I also checked generated-source/simroot surfaces only as a pollution check, not as source-ownership authority. No current generated source route for `0x0041b2d0` surfaced. Generated Thread/source maps still route `0x00596960` itself through Thread-style `DispatchRequest` naming, which is consistent with the current docs but does not make this orphan wrapper emit.

## Local PE Scan Recheck

IDA MCP was attempted at `http://127.0.0.1:13337/mcp`, but the endpoint was not reachable in this session. I did not edit the IDA database. Because live MCP was unavailable, this pass used current docs plus a local PE scan and treated the 2026-06-17 live-IDA facts already incorporated in the target/support docs as the current live-IDA baseline.

Local PE scanned:

```text
Path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
SHA256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
Image base: 0x00400000
Size: 2679296 bytes
```

Sections used for address translation:

```text
.text  0x00401000-0x0060c600  raw 0x00000400+0x20b600
.rdata 0x0060d000-0x0066c200  raw 0x0020ba00+0x05f200
.data  0x0066d000-0x0069ce24  raw 0x0026ac00+0x00d800
.rsrc  0x0069d000-0x006b2e00  raw 0x00278400+0x015e00
```

Target raw file offset:

```text
VA 0x0041b2d0 -> file offset 0x0001a6d0
```

Target bytes:

```text
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
```

Neighborhood bytes from `0x0041b2c0-0x0041b300`:

```text
9c b6 17 00 5e 8b e5 5d c3 cc cc cc cc cc cc cc
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
cc cc cc cc cc cc cc cc cc cc cc cc
c7 05 38 a7 67 00 00 00 00 00 c3 cc cc cc cc cc
```

Direct surface checks for the target address:

| Check | Result |
| --- | --- |
| Absolute little-endian VA dword `0x0041b2d0` anywhere in file | No hits |
| Little-endian RVA dword `0x0001b2d0` anywhere in file | No hits |
| `push 0x0041b2d0` immediate pattern | No hits |
| Generic immediate dword surface for `0x0041b2d0` | No hits |
| Direct `call rel32`, `jmp rel32`, or `jcc rel32` targeting `0x0041b2d0` | No hits |
| Short branch targeting `0x0041b2d0` | No real hits |
| Absolute VA/RVA pointer to endpoint `0x0041b2e4` | No hits |
| Absolute VA/RVA pointer to successor `0x0041b2f0` | No hits |

One naive byte-pattern scan saw a false short-branch candidate inside the target at `0x0041b2d6`; it is the `0x75` byte in the operand of `ff 75 0c` (`push [ebp+0x0c]`), not an instruction-boundary branch. I do not count it as an xref.

Positive controls confirm the scanner was capable of finding real routes:

| Positive control | Result |
| --- | --- |
| Direct jump to successor helper `0x0041b2f0` | Found rel32 jump at `0x005f670e` |
| Immediate/global surface for `dword_67A738` (`0x0067a738`) | Found 9 hits, including neighboring clear at `0x0041b2f2` and known FileDownloader-family references |
| Direct calls to callee `0x00596960` | Found 22 call sites |

The 22 direct call sites to `0x00596960` found in the PE scan are:

```text
0x0041b1e8
0x0041b253
0x0041b2aa
0x0041b2bf
0x0041b2db
0x00453a92
0x005282ed
0x0052838e
0x005283cb
0x00574aed
0x00574b0d
0x00574b26
0x00574b5d
0x00574b7a
0x00574b9b
0x00574c05
0x00574c2c
0x00574c94
0x00574cbc
0x00574d31
0x00574e2e
0x005752af
```

These support the current Thread primitive model for `0x00596960`, but they do not create a reverse route into this orphan wrapper.

Exact target-body scan:

```text
Only exact body hit: 0x0041b2d0
```

Wrapper-shape scan for `55 8b ec 6a 00 ff 75 ?? ff 75 ?? e8 .... 5d c2 08 00`:

```text
0x0041b2d0 -> 0x00596960
0x0058ea60 -> 0x0058f690
```

The duplicate same-shape wrapper at `0x0058ea60` has bytes:

```text
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 20 0c 00 00 5d c2 08 00
```

This duplicate shape weakens any claim that the target's tiny wrapper pattern alone identifies a source owner. It shows the compiler emitted the same default-argument wrapper pattern for a different callee elsewhere.

`CreateSymbolicLink` checks:

| Check | Result |
| --- | --- |
| Import name containing `CreateSymbolicLink`, `Symbolic`, or `std_fs` | No hits |
| ASCII string `CreateSymbolicLinkW` | Found at `0x00634034` |
| Wide string `CreateSymbolicLinkW` | No hits |
| ASCII string `CreateSymbolicLinkA` | No hits |
| String `___std_fs_create_symbolic_link` | No hits |

The only `CreateSymbolicLinkW` string route found in this pass is:

```text
String VA: 0x00634034
Pointer/immediate use: 0x005c710d
```

Bytes around `0x005c7100` include a push of `0x00634034` followed by runtime pointer-initialization behavior. This address falls in the MSVC runtime/import-support area already documented by `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md` and the runtime `.rdata` / `.data` tail docs. This is a runtime API-name/pointer-initializer route, not a relation to the target at `0x0041b2d0`.

## Hidden Route Recheck

Static PE evidence found no table, vtable, direct branch, or immediate pointer route to the target:

```text
No VA pointer to 0x0041b2d0.
No RVA pointer to 0x0041b2d0.
No push-immediate target reference.
No direct rel32 call/jump/jcc target.
No real short branch target.
No pointer-table or vtable-style slot containing the target address in .rdata or .data.
No import/IAT route to CreateSymbolicLink*.
No dword_67A738 reference inside the target body.
No FileDownloader field/global access inside the target body.
```

A theoretically computed call could synthesize `0x0041b2d0` arithmetically at runtime, but this is not a source route under the current evidence ladder. There is no static table entry, no receiver type, no caller, and no doc-supported dispatcher that computes this exact helper address. The positive controls above found real references for adjacent FileDownloader globals and helper successors, so the absence for target is meaningful rather than a scanner failure.

## Ownership / Source Routing Outcomes

### Thread / Thread.cpp

Thread remains the best semantic dependency for the callee, not the wrapper.

Positive evidence:

```text
0x0041b2d0 calls 0x00596960.
0x00596960 is currently modeled as a Thread async queue-post primitive.
The wrapper shape is consistent with a default-argument forwarding helper around a Thread dispatch/post method.
```

Blocking evidence:

```text
No caller reaches 0x0041b2d0.
No pointer/vtable/table slot contains 0x0041b2d0.
No source-neighbor evidence places this wrapper inside the Thread/ThreadMan island.
No current Thread doc claims the wrapper as emitted Thread output.
The wrapper is physically in the FileDownloader mixed island, not inside the Thread range.
The callee's owner is not automatically the wrapper's owner when no callsite, declaration, or source-level overload relation is visible.
```

Conclusion: do not set `CANONICAL_OWNER:0000OR` or `EMITTER_UIDS:0000OR`. At most, describe the helper in prose as an unreferenced forwarding wrapper around `Thread::DispatchRequest` / the Thread queue-post primitive.

### FileDownloader / CashShopRequest Global Island

FileDownloader remains rejected as owner/emitter.

Positive evidence:

```text
The target is physically between FileDownloader-family helpers.
Neighboring helpers at 0x0041b180, 0x0041b200, and 0x0041b270 call the same Thread queue primitive.
The successor helper at 0x0041b2f0 is FileDownloader-family and clears dword_67A738.
```

Blocking evidence:

```text
The target does not read or write dword_67A738.
The target has no caller passing dword_67A738 as receiver.
The target does not use FileDownloader constants 10000/10001/10002.
The target does not access FileDownloader fields.
The target is not in the FileDownloader vtable/method list.
The target has no direct caller, jump, pointer slot, or table entry.
The target's body is generic and receives the message id/payload from its caller rather than encoding a downloader operation.
```

Conclusion: do not set FileDownloader/CashShopRequest global ownership for target. The FileDownloader docs are correct to keep it as mixed-neighbor real code without emission.

### Derived Worker Families

Derived worker families such as MiscWorkThread, Socket/packet send, CashShopRequest, and FileDownloader submit helpers all contain wrappers or helpers that can call `0x00596960`. Current docs assign those where separate evidence exists: known callers, singletons, globals, vtables, dispatcher command consumers, field initialization, or source-neighbor clusters.

The target has none of those anchors. It is not justified as MiscWorkThread, Socket, CashShopRequest, packet send, FileDownloader, or another derived-worker wrapper.

### Runtime / Filesystem

Runtime/filesystem ownership remains rejected.

Positive evidence for the stale name:

```text
IDA's current/stale symbol string for the target is `___std_fs_create_symbolic_link@8`.
The PE contains the ASCII API-name string `CreateSymbolicLinkW` at 0x00634034.
```

Blocking evidence:

```text
The target body performs no filesystem operation.
No CreateSymbolicLink* import exists.
No CreateSymbolicLinkA string exists.
No wide CreateSymbolicLinkW string exists.
No `___std_fs_create_symbolic_link` string exists in the scanned PE.
The only `CreateSymbolicLinkW` string route found points into MSVC runtime API-pointer initialization at 0x005c710d.
The documented runtime/string areas are separate from the target.
The target calls Thread queue primitive 0x00596960, not a runtime filesystem helper.
```

Conclusion: keep the stale name only as a warning in evidence notes. Do not use it as source-facing name, owner, or reconstruction identity.

### New Narrow Utility / Source Family

A new source group is not justified.

Rejected candidates:

```text
ProtocolSend/Session: current docs are placeholders with `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and no generic Thread queue helper ownership.
PathUtil/File: real filesystem utility roots exist, but target has no file/path behavior.
ThreadDispatchWrapper.cpp or similar one-function utility: no source path, no caller, no type declaration, no table entry, and no cohesive family beyond this orphan wrapper.
```

Conclusion: a new owner would be an unsupported artifact of wanting to emit reconstructable code. It would reduce metadata accuracy.

## Heuristic / Inference Reanalysis And Validation

Evidence classification under the current inference standard:

| Evidence item | Type | Weight | Disposition |
| --- | --- | --- | --- |
| Exact target bytes and call to `0x00596960` | Direct fact | Strong for behavior | Suitable for target doc and already present at functional detail. |
| `0x00596960` current Thread primitive model | Current support-doc fact plus inference | Strong for callee owner | Already present in Thread docs; supports dependency only. |
| No direct calls/xrefs/pointers/table slots to target in PE scan | Negative direct scan evidence | Strong negative for reachability/source route | Already present from B002/B003 at same general detail; this pass adds current PE hash/path and scan controls. |
| No `dword_67A738` reference inside target | Direct body fact plus positive-control scan | Strong negative for FileDownloader ownership | Already present in target/support docs; validated again. |
| Target physically adjacent to FileDownloader helpers | Direct layout fact | Weak positive for FileDownloader | Already present, but insufficient under inference ladder. |
| Neighboring FileDownloader helpers call `0x00596960` | Direct support-doc fact | Medium contextual evidence | Already present; positive contrast only. |
| Stale IDA name `___std_fs_create_symbolic_link@8` | Tool name fact | Weak and contradicted | Must not drive owner/name/C++; already warned in target. |
| `CreateSymbolicLinkW` string at `0x00634034` | Direct PE string fact | Weak unless routed | Current pass routes it to runtime initializer, so it is excluded as target evidence. |
| Runtime pointer-initializer reference at `0x005c710d` | Direct PE fact | Strong against target filesystem route | Suitable as optional detail if supervisor wants to expand stale-name rejection. |
| Wrapper-shape duplicate at `0x0058ea60` | Direct PE fact | Medium negative against owner-by-shape | Already generally present from B002; this pass reconfirmed bytes. |
| Absence from generated/simroot source | Non-authoritative pollution check | Weak negative | Not used as authority, but consistent with no current source route. |
| IDA MCP unavailability this pass | Process fact | Limits this pass | Current docs already contain live-IDA rechecks from 2026-06-17. |

Inference validation:

1. Callee ownership does not imply wrapper ownership. The strongest positive fact is that the wrapper calls the Thread primitive at `0x00596960`. Current docs already assign the primitive to Thread, but the target has no callsite, declaration, table slot, or source-neighbor route to prove the wrapper belongs in Thread output.
2. Physical adjacency does not imply FileDownloader ownership. Neighboring FileDownloader helpers have positive route evidence: `dword_67A738`, known callers, constants, field/global behavior, and successor jumps. The target has only adjacency and a generic call.
3. Stale symbolic-link naming is contradicted by behavior and PE surfaces. `CreateSymbolicLinkW` exists only as a runtime API-name string with a runtime initializer reference; the target has no import, string, or code path to it.
4. Hidden table/vtable routes were rechecked with PE scans. No pointer slot, direct branch, or immediate surface exists for the target. This does not mathematically exclude arbitrary arithmetic synthesis, but it excludes the normal static routes required for source-facing ownership under the project inference rules.
5. A new source root is not justified by a single orphan wrapper. The project already has valid roots for Thread, FileDownloader, runtime, filesystem, ProtocolSend placeholders, and derived workers. None can own this wrapper without a source route, and creating a one-item root would be weaker than leaving owner blank.

Rule 26 disposition:

```text
Already present at same-or-greater decision detail:
- stale IDA name is misleading
- exact wrapper behavior
- no current caller/xref/pointer/vtable/source route
- no FileDownloader global/field behavior
- no filesystem behavior
- Thread is callee owner/dependency only
- FileDownloader adjacency is insufficient
- keep owner/emitter/C++ blank

New or refreshed details suitable for optional incorporation:
- PE path/hash/section context for this B001 pass
- explicit current PE scan positive controls
- explicit 22 call-site list for 0x00596960 from the local scan
- `CreateSymbolicLinkW` string route to runtime initializer at 0x005c710d
- endpoint false-positive explanation for the naive short-branch byte at 0x0041b2d6

Explicitly excluded as owner/emitter evidence:
- generated/simroot absence, because B001 instructions prohibit relying on generated source as authority
- arbitrary computed-call speculation, because no static route or current doc evidence supports it
- stale IDA name, because behavior and runtime string routing contradict it
```

## First-Draft C++ Recommendation Or Exact Do-Not-Populate Proof

Do not populate formal `RECONSTRUCTION_CPP` for `0003GY`.

Exact proof:

```text
The target is mechanically reconstructable, but source placement is not proven.
The current code-entry gate requires a nonblank EMITTER_UIDS route surfacing to valid source.
No current caller, pointer, vtable, table slot, import, global, source-neighbor, or declaration route identifies a valid emitter.
Thread owns the callee 0x00596960, but current Thread docs explicitly keep this wrapper dependency-only.
FileDownloader owns adjacent helpers, but target lacks the FileDownloader receiver/global/caller evidence those helpers have.
Runtime/filesystem ownership is contradicted by body and import/string routing.
Creating a new one-function source family would be unsupported.
Therefore formal C++ emission would manufacture source placement not present in the evidence.
```

If a future supervisor note needs a non-emitting descriptive sketch, the only safe form is behavior-only pseudocode, not formal reconstruction:

```cpp
// Descriptive only. Do not use as formal RECONSTRUCTION_CPP without a proven emitter.
bool ThreadDispatchRequestDefaultParamWrapper(Thread *thread, unsigned int messageId, void *payload) {
    return thread->DispatchRequest(messageId, payload, 0);
}
```

Naming guidance:

```text
Safe descriptive names:
- UnreferencedThreadDispatchWrapper
- ThreadDispatchRequestDefaultParamWrapper

Names to avoid:
- ___std_fs_create_symbolic_link@8
- create_symbolic_link
- filesystem/path helper names
- FileDownloader method names
- CashShopRequest method names
```

Type guidance:

```text
Receiver: best described only as Thread-like or queue-owner-like.
arg_0: message/request id or dispatch code, not a FileDownloader-specific constant in this wrapper.
arg_4: payload/context pointer.
constant fourth argument: 0, likely default sync/flag/callback argument depending on final Thread helper naming.
```

Do not promote this sketch into by-memory formal C++ unless a future pass finds at least one of:

```text
A real caller that identifies the receiver type/source module.
A pointer/table/vtable slot containing 0x0041b2d0.
A source declaration/overload relation tying this exact wrapper to Thread.cpp.
A validated computed-dispatch route that specifically targets 0x0041b2d0.
A current support doc establishing a narrow source family with more than this orphan wrapper.
```

## Exact Supervisor Changes Needed

Required metadata changes: none.

Exact target metadata to keep:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Coverage changes needed: none. The current `by-memory/-coverage-report.md` already contains the target row and adjacent padding rows for this address band. Do not edit coverage for this assignment.

Support-doc changes needed: none required for correctness. Current Thread, FileDownloader, FileDownloaderDispatch, runtime, ProtocolSend/Session, PathUtil/File, and global docs already support the no-owner/no-emitter decision.

Optional target-page note if the supervisor wants this B001 current-source-routing pass incorporated under the target page's change log:

```text
- 2026-06-18 B001 current-source-routing recheck: local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) reconfirmed the exact `0x0041b2d0` body as the only exact-body hit, found two same-shape wrappers (`0x0041b2d0 -> 0x00596960`, `0x0058ea60 -> 0x0058f690`), found no VA/RVA/immediate pointer or real direct branch/call target to `0x0041b2d0`, found 22 direct calls to `0x00596960`, found no `CreateSymbolicLink*` import, and routed the only `CreateSymbolicLinkW` string use to the MSVC runtime/API initializer area at `0x005c710d`. IDA MCP was unreachable in this B001 session, so current live-IDA facts remain those already incorporated from 2026-06-17. Keep `86/86`, `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:TRUE`, and blank formal C++.
```

No exact replacement text is needed for coverage or support docs because the current state already represents the recommended decision. If the optional note is accepted, it should be appended as provenance only; it should not change owner, emitter, score, or C++ fields.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-current-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
