** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_header_missing **
# 0x005971ad-0x005974e0 ThreadMan Watch-List Raw Cluster

Agent: B001
Date: 2026-06-16
Scope: research-only pass for the raw unknown row immediately after `[UID:0001K3] ThreadManWorkerEntry` and before `[UID:0001K4] ClearThreadManSingleton`.

No `by-memory/-coverage-report.md` or other `by-*` documentation files were edited for this task.

## Recommendation

Recommend split/create/ignore, not no-op:

- Ignore `0x005971ad-0x005971b0` as three-byte `0xcc` alignment padding.
- Create one exact child page for `0x005971b0-0x005974da` named `ThreadManWatchListRawHelpers`.
- Ignore `0x005974da-0x005974e0` as six-byte `0xcc` alignment padding before `ClearThreadManSingleton`.
- Do not make separate top-level pages for `0x005971f0`, `0x00597230`, or the later internal starts in the first pass. They are real helper-body starts and should be listed inside the proposed child page, but there are no function objects, no start xrefs, and no pointer constants proving separate source-level call sites. A single exact raw-helper island matches the existing `ThreadManRawMessageWrappers` treatment and avoids nine low-context child pages.

Internal starts that should be documented in the child page:

| Start | End | Proposed internal label | Summary |
| --- | --- | --- | --- |
| `0x005971b0` | `0x005971ec` | `FindWatchRecordIndexByThreadObjectRaw` | `thiscall` helper; loops `this->watchList`, compares `ThreadManWatchRecord+0x00`, returns index or `-1`. |
| `0x005971f0` | `0x0059722d` | `FindWatchRecordIndexByIdentityRaw` | Same list scan, but compares `ThreadManWatchRecord+0x08` against the identity argument. |
| `0x00597230` | `0x005972e9` | `ScanWatchListTimeoutsRaw` | Scans all records, arms pending records with `timeGetTime()+10000`, and fatal-exits on overdue records using `L"Possibly dead thread 0x%p"`. |
| `0x005972f0` | `0x0059735f` | `CheckSingleWatchRecordTimeoutRaw` | Single-record version of the timeout/fatal-exit check. |
| `0x00597360` | `0x00597397` | `AddWatchRecordRaw` | Builds a 0x14-byte `ThreadManWatchRecord` from thread object, register context, and `Thread+0x60`; inserts through the watch-list vtable. |
| `0x005973a0` | `0x005973de` | `RemoveWatchRecordByThreadObjectRaw` | Finds by `record+0x00`; removes matching index through the watch-list vtable. |
| `0x005973e0` | `0x0059742f` | `ClearThreadObjectWatchPendingRaw` | Finds by `record+0x00`; clears `watchdogPending` when `deadlineTick != -1`. |
| `0x00597430` | `0x00597481` | `MarkIdentityWatchBlockedRaw` | Finds by `record+0x08`; sets `watchdogPending=1` and `deadlineTick=-1`. |
| `0x00597490` | `0x005974da` | `ClearIdentityWatchPendingRaw` | Finds by `record+0x08`; clears `watchdogPending`. |

## Evidence Scope

Docs inspected:

- `by-memory/-coverage-report.md` around the `ThreadAndThreadMan` block.
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
- `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`
- `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
- `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`
- `by-type/by-struct/ThreadManLayout.md`
- `by-type/by-struct/ThreadManWatchRecord.md`
- `by-type/by-enum/ThreadManMessageId.md`
- `by-class/ThreadMan.md`
- `by-file/Thread.md`
- `by-global/g_pThreadMan.md`

Live evidence used the local IDA MCP JSON-RPC endpoint at `http://127.0.0.1:13337/mcp`, session `a002_goal65_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready. I did not modify the IDA database.

MCP checks used: `lookup_funcs`, `entity_query`, `get_bytes`, `insn_query`, `xref_query`, `find_bytes`, `make_signature`, `make_signature_for_range`, and `analyze_batch`.

Generated source did not resolve names: `auto-generated/NexusTK/util/Thread.cpp` is zero length, and text searches there cannot identify the original helper names. This is a naming limitation, not a blocker; the byte-level behavior and owner are still classifiable.

## Boundary Findings

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x00597100-0x005971ad` | Existing worker entry | Existing page and live IDA confirm `ThreadManWorkerEntry` ends at `0x005971ad`. |
| `0x005971ad-0x005971b0` | Padding | Raw bytes are exactly `cc cc cc`; disassembly emits only alignment before the first helper prologue at `0x005971b0`. |
| `0x005971b0-0x005974da` | Source-shaped raw helper island | Decodes cleanly as nine aligned helper bodies using `ThreadMan+0x10` and `ThreadManWatchRecord` fields. Bodies have normal MSVC prologues/returns, list-vtable calls, `timeGetTime`, `FatalAppExitW`, and the shared dead-thread literal. |
| `0x005974da-0x005974e0` | Padding | Raw bytes are six `0xcc` bytes after the final helper `ret` and before `sub_5974E0`. |
| `0x005974e0-0x005974eb` | Existing singleton-clear thunk | Existing ignored compiler cleanup page remains the correct successor. |

Live `lookup_funcs` reported no function at `0x005971ad`, `0x005971b0`, `0x005971f0`, `0x00597230`, `0x00597270`, `0x005972b0`, `0x00597300`, `0x00597350`, `0x00597390`, `0x005973d0`, `0x00597400`, `0x00597440`, `0x00597480`, or `0x005974d0`. `entity_query` over `0x005970df-0x005974f0` found only `sub_597100`, `sub_5974E0`, and `sub_5974F0`, so the cluster has no IDA function records.

`xref_query` found zero xrefs to all nine candidate helper starts:

- `0x005971b0`
- `0x005971f0`
- `0x00597230`
- `0x005972f0`
- `0x00597360`
- `0x005973a0`
- `0x005973e0`
- `0x00597430`
- `0x00597490`

`find_bytes` found no VA or RVA pointer-byte hits for those starts. Checked VA patterns such as `b0 71 59 00`, `f0 71 59 00`, `30 72 59 00`, and RVA patterns such as `b0 71 19 00`, `f0 71 19 00`, `30 72 19 00`, with the same no-hit result across the later starts.

`make_signature` returned unique signatures for each helper start. This supports that the bytes are real distinct code bodies, not repeated padding or accidental data decoding.

## Internal Padding

The proposed aggregate page should record these internal alignment gaps:

| Range | Bytes | Recommendation |
| --- | --- | --- |
| `0x005971ec-0x005971f0` | 4 | Internal `0xcc` helper alignment. |
| `0x0059722d-0x00597230` | 3 | Internal `0xcc` helper alignment. |
| `0x005972e9-0x005972f0` | 7 | Internal `0xcc` helper alignment. |
| `0x0059735f-0x00597360` | 1 | Internal `0xcc` helper alignment. |
| `0x00597397-0x005973a0` | 9 | Internal `0xcc` helper alignment. |
| `0x005973de-0x005973e0` | 2 | Internal `0xcc` helper alignment. |
| `0x0059742f-0x00597430` | 1 | Internal `0xcc` helper alignment. |
| `0x00597481-0x00597490` | 15 | Internal `0xcc` helper alignment. |

Do not add these internal gaps as separate global ignored rows if the supervisor accepts the single `0x005971b0-0x005974da` child page. If the supervisor instead requires page-per-helper children, these internal gaps should become ignored padding rows too.

## Source-Shape Analysis

This is not compiler-generated glue. The bodies implement project-specific `ThreadMan` watch-list logic:

- Most bodies use `ecx` as the `ThreadMan *this` pointer and load `this+0x10`, matching `ThreadManLayout.md` for the `watchList` field.
- Record field accesses match `ThreadManWatchRecord.md`: `+0x00 threadObject`, `+0x04 registerContext`, `+0x08 threadIdentity`, `+0x0c watchdogPending`, and `+0x10 deadlineTick`.
- The add helper copies a thread identity from `Thread+0x60`, builds a 0x14-byte stack record, clears pending/deadline fields, and inserts it into the list.
- The timeout helpers use `timeGetTime`, the literal `L"Possibly dead thread 0x%p"` at `0x0062e300`, formatter/copy helper `sub_41B9B0`, and `FatalAppExitW`, matching the known worker-loop timeout behavior.
- The mark/clear helpers line up with `ThreadManMessageId.md` message effects for `0x0464-0x0468`.

The cluster is also not just unreachable random bytes. It is coherent, unique, MSVC-shaped code with exact helper boundaries. The remaining uncertainty is reachability and original source names, because IDA has no function records, no xrefs to starts, and no pointer constants.

`ThreadManWorkerLoop` at `0x00596e10-0x005970df` contains inlined or duplicated versions of the same operations: watch-record insert, remove, clear-by-thread, mark-by-identity, clear-by-identity, and dead-thread scanning. That strongly suggests this cluster is source-authored `ThreadMan` private helper code retained in the binary but not referenced through ordinary direct calls in this build, or old out-of-line helper code duplicated by inlining into the worker loop.

## Proposed Metadata

Primary child page:

```text
UID: NEW_THREADMAN_WATCH_RAW
Path: by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md
Range: 0x005971b0-0x005974da
Title: ThreadManWatchListRawHelpers
Construct type: raw helper island
Reconstructable: TRUE
Canonical owner/emitter: [UID:0000OR] Thread / by-file/Thread.md
Semantic class owner: [UID:0000EW] ThreadMan / by-class/ThreadMan.md
Completion: 86
Confidence: 87, strong
Final C++: keep blank for now
```

Why final C++ should stay blank: behavior is reconstructable, but original helper names are not present, no call sites or function records prove live source-level entry points, and the known live worker loop already contains duplicated/inlined source behavior. The page should preserve exact bytes, internal split starts, and likely C++ pseudocode notes without emitting new source until a later pass decides whether these helpers should be recreated as private methods, dead retained functions, or ignored duplicates after source migration.

Padding metadata:

```text
Range: 0x005971ad-0x005971b0
Title: ThreadManWorkerEntryToWatchListRawHelpersPadding
Construct type: padding
Reconstructable: FALSE
Owner/emitter: [UID:0000VN] -ignored
Completion: 100
Confidence: strong
Reason: exactly three 0xcc bytes between existing worker entry and first helper body.

Range: 0x005974da-0x005974e0
Title: ThreadManWatchListRawHelpersToClearSingletonPadding
Construct type: padding
Reconstructable: FALSE
Owner/emitter: [UID:0000VN] -ignored
Completion: 100
Confidence: strong
Reason: exactly six 0xcc bytes between final helper return and ClearThreadManSingleton.
```

## Coverage Rows For Supervisor

Replace the current unknown coverage row:

```text
    - 0x005971ad-0x005974e0 | raw ThreadMan/watch-list helper cluster : unknown : 25% : medium : A002 2026-06-16 support refresh found three-byte padding at 0x005971ad-0x005971b0 followed by raw helper-shaped ThreadMan/watch-list bytes at 0x005971b0, 0x005971f0, and 0x00597230 before modeled singleton clear 0x005974e0. IDA reports no function records, no xrefs to candidate starts, and no VA/RVA pointer-byte hits; needs exact child page/split pass before final ThreadMan source migration.
```

with:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005971ad-0x005971b0 | padding | ThreadManWorkerEntryToWatchListRawHelpersPadding : ignored : 100% : strong : B001 2026-06-16 live IDA MCP byte/disassembly check shows exactly three `0xcc` bytes after [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md) and before the helper-shaped prologue at `0x005971b0`; no source-owned bytes in this span.
    - [UID:NEW_THREADMAN_WATCH_RAW][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md) 0x005971b0-0x005974da | raw helper island | ThreadManWatchListRawHelpers : reconstructable : 86% : strong : B001 2026-06-16 live IDA MCP split nine aligned raw ThreadMan watch-list helper bodies at `0x005971b0`, `0x005971f0`, `0x00597230`, `0x005972f0`, `0x00597360`, `0x005973a0`, `0x005973e0`, `0x00597430`, and `0x00597490`; no IDA function objects, no xrefs to starts, and no VA/RVA pointer-byte hits, but bytes decode as source-authored ThreadMan helper logic using `ThreadMan+0x10`, `ThreadManWatchRecord` fields, `timeGetTime`, `FatalAppExitW`, and `L"Possibly dead thread 0x%p"`. Route source/emitter ownership through [UID:0000OR][Thread](by-file/Thread.md) with semantic class owner [UID:0000EW][ThreadMan](by-class/ThreadMan.md); keep final C++ blank pending original helper names/reachability.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005974da-0x005974e0 | padding | ThreadManWatchListRawHelpersToClearSingletonPadding : ignored : 100% : strong : B001 2026-06-16 live IDA MCP byte/disassembly check shows exactly six `0xcc` bytes after the raw helper return at `0x005974d9` and before [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md).
```

Optional aggregate row refresh for `[UID:0001JX]` if the supervisor wants the parent summary to reflect the new split:

```text
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) 0x00596250-0x0059756e | aggregate | ThreadAndThreadMan : reconstructable : 86% : strong : Thread.cpp/ThreadMan code island; B001 2026-06-16 split the former raw unknown `0x005971ad-0x005974e0` into ignored outer padding plus a reconstructable raw ThreadMan watch-list helper island at `0x005971b0-0x005974da`, with internal helper starts documented and final C++ blank pending original helper names/reachability. Existing constructor, lifecycle, wrapper, worker-loop, worker-entry, singleton-clear thunk, and scalar deleting destructor children remain the active reconstruction map.
```

## Ignored Ledger Text For Supervisor

Suggested additions to `by-memory/-ignored.md`:

```text
- `0x005971ad-0x005971b0` - ThreadMan worker-entry to raw watch-list helper alignment padding.
  - Why ignored: reviewed non-emitting `0xcc` alignment bytes between the exact `ThreadManWorkerEntry` body and the first raw ThreadMan watch-list helper body.
  - Evidence: B001 2026-06-16 live IDA MCP `get_bytes` and `insn_query` showed exactly `cc cc cc` at `0x005971ad-0x005971af`, followed by a normal helper prologue at `0x005971b0`; `ThreadManWorkerEntry` ends at `0x005971ad`.
  - Replacement/procurement: no source reconstruction; preserve neighboring source-owned ranges through [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md) and the proposed `[UID:NEW_THREADMAN_WATCH_RAW]` helper page.

- `0x005974da-0x005974e0` - ThreadMan raw watch-list helper to singleton-clear alignment padding.
  - Why ignored: reviewed non-emitting `0xcc` alignment bytes between the final raw ThreadMan watch-list helper return and the existing singleton-clear cleanup thunk.
  - Evidence: B001 2026-06-16 live IDA MCP `get_bytes` and `insn_query` showed six `0xcc` bytes at `0x005974da-0x005974df`, with `ClearThreadManSingleton` beginning at `0x005974e0`.
  - Replacement/procurement: no source reconstruction; preserve neighboring source-owned/evidence ranges through the proposed `[UID:NEW_THREADMAN_WATCH_RAW]` helper page and [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md).
```

## Strict Page-Per-Helper Alternative

If the supervisor decides every internal helper start must be a separate child page, use this exact split instead of the single aggregate child:

| Page range | Title | Reconstructable | Owner/emitter | C++ |
| --- | --- | --- | --- | --- |
| `0x005971b0-0x005971ec` | `ThreadManFindWatchRecordIndexByThreadObjectRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x005971ec-0x005971f0` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x005971f0-0x0059722d` | `ThreadManFindWatchRecordIndexByIdentityRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x0059722d-0x00597230` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x00597230-0x005972e9` | `ThreadManScanWatchListTimeoutsRaw` | TRUE, 86/87 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x005972e9-0x005972f0` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x005972f0-0x0059735f` | `ThreadManCheckSingleWatchRecordTimeoutRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x0059735f-0x00597360` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x00597360-0x00597397` | `ThreadManAddWatchRecordRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x00597397-0x005973a0` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x005973a0-0x005973de` | `ThreadManRemoveWatchRecordByThreadObjectRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x005973de-0x005973e0` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x005973e0-0x0059742f` | `ThreadManClearThreadObjectWatchPendingRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x0059742f-0x00597430` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x00597430-0x00597481` | `ThreadManMarkIdentityWatchBlockedRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |
| `0x00597481-0x00597490` | padding | FALSE, 100 strong | `[UID:0000VN] -ignored` | Blank |
| `0x00597490-0x005974da` | `ThreadManClearIdentityWatchPendingRaw` | TRUE, 85/86 strong | `[UID:0000OR] Thread`, semantic `[UID:0000EW] ThreadMan` | Blank |

I still recommend the single aggregate child page unless a repository rule requires one child per helper body.

## Validation Commands

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying the supervisor-side doc changes:

> Executable block R001 was removed from this report and preserved verbatim in [005971ad-threadman-watch-list-raw-cluster-removed.md](005971ad-threadman-watch-list-raw-cluster-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor refreshes parent owner docs too, validate those explicitly:

> Executable block R002 was removed from this report and preserved verbatim in [005971ad-threadman-watch-list-raw-cluster-removed.md](005971ad-threadman-watch-list-raw-cluster-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B001/005971ad-threadman-watch-list-raw-cluster.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
