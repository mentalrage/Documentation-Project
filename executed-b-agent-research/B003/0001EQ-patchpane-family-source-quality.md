** TARGET-REPORT-UID:0001EQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001EQ] PatchPane / PatchPane2 Source-Quality Report

Assignment: `B003-goal2-patchpane-family-source-quality-0001EQ-20260617`

Primary target:

- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](../../../by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- Starting score: `82/88`
- Starting metadata: `CANONICAL_OWNER:0000MH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MH`
- Recommended score: `87/91`
- Recommended metadata: keep `CANONICAL_OWNER:0000MH`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`
- Recommended source placement for the family: `NexusTK/patch/PatchPane.cpp`
- Recommended formal C++ for this aggregate: leave blank

## Executive Recommendation

[UID:0001EQ] should not remain a reconstructable/emitting aggregate. The page is valuable and now clears the documentation-quality gate as a source-family split/index, but it should be non-emitting because it spans two classes, nested helper types, compiler adjustor thunks, switch-table data, padding, and a raw/no-entry helper body. Emitting C++ from the aggregate would duplicate exact child pages and would force unresolved child-level source names into one artificial function cluster.

The best supervisor action is:

1. Convert [UID:0001EQ] from `RECONSTRUCTABLE:TRUE` / `EMITTER_UIDS:0000MH` to `RECONSTRUCTABLE:FALSE` / blank `EMITTER_UIDS`.
2. Raise [UID:0001EQ] to `COMPLETION:87`, `CONFIDENCE:91` as a non-emitting split/index and boundary authority.
3. Keep exact source-bearing children under [UID:0000A9] `PatchPane`, [UID:0000AA] `PatchPane2`, and [UID:0000MH] `PatchPane.cpp`.
4. Keep formal C++ blank for [UID:0001EQ]. Use child pages for future method-level C++ only after their field/helper/API names clear their own gates.

This resolves the sub-85 issue without pretending the aggregate is a single source method. The current primary doc already says "Do not emit aggregate C++"; the header and coverage row are the stale pieces.

## Scope And Files Checked

Primary and direct support docs checked:

- [UID:0001EQ] aggregate page.
- [UID:0000MH] `by-file/PatchPane.md`.
- [UID:0000A9] `by-class/PatchPane.md`.
- [UID:0000AA] `by-class/PatchPane2.md`.
- [UID:0000AB] `PatchPane::PatchFileData`.
- [UID:0000AC] `PatchPane::PatchFileSlice`.
- Child pages [UID:0001ER], [UID:0001ES], [UID:0001ET], [UID:0001EU], [UID:0001EV], [UID:0001EW], [UID:0002R7], [UID:0001EX], [UID:0001EY], [UID:0001EZ], [UID:0001F0], [UID:0003OC].
- [UID:0001YF] `PatchPaneVtableFamily`.
- [UID:0001VJ] `PatchPane2Layout`.
- [UID:000264] `PatchPaneReadOnlyData`.
- [UID:0000RZ] `g_pPatchPane2`.
- [UID:0000RQ] `g_pMiscWorkThread`.
- [UID:00022D] `PatchPane2DownloadPathJoinHelper`.
- [UID:0001CJ] `MiscWorkThreadAndNotifications`.
- [UID:0000HG] `Application`.
- `by-project-structure/proposed-source-tree.md`.
- Existing executed B reports under `tools/leaser/Agents/*/research/executed`.
- Current coverage rows in `by-memory/-coverage-report.md`.
- Generated output path `auto-generated/NexusTK/patch/PatchPane.cpp`.

Existing executed-report search found no prior direct B report for [UID:0001EQ]. The only relevant prior B003 lead was `executed/older/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md`, which supports `g_pPatchPane2` as a PatchPane/PatchPane2 module singleton and not an Application-owned slot.

## Aggregate Shape And Split Policy

The aggregate covers the updater family from the first `PatchPane` constructor through the `PatchPane2` scalar deleting destructor:

| Range | Classification | Existing child/status | Recommendation |
| --- | --- | --- | --- |
| `0x005470b0-0x005473ec` | `PatchPane` constructor | aggregate table only | Source method belongs to [UID:0000A9]; no aggregate C++.
| `0x005473f0-0x005474e5` | `PatchPane` destructor | aggregate table only | Source method belongs to [UID:0000A9].
| `0x005474f0-0x00547850` | secondary-vtable packet callback | [UID:0001ER] | Keep child; best name `PatchPane::HandlePatchResponsePacket`.
| `0x00547860-0x00547946` | action/timer callback | aggregate table only | Source method belongs to [UID:0000A9]; best name `HandlePatchTimerAction` or existing `HandlePatchAction`.
| `0x00547950-0x00547978` | status-change virtual | aggregate table only | Source method belongs to [UID:0000A9]; name `OnPatchStatusChanged` is defensible.
| `0x00547980-0x00547a58` | alert/close/exit helper | aggregate table only | Source method belongs to [UID:0000A9]; name `ShowPatchAlertAndExit` is defensible.
| `0x00547a60-0x00547b6f` | patch script request sender | aggregate table only | Source method belongs to [UID:0000A9]; name `SendPatchScriptRequest` is defensible.
| `0x00547b70-0x00547cdd` | pending patch-entry request sender | aggregate table only | Source method belongs to [UID:0000A9]; name `SendPendingPatchEntryRequests` is defensible.
| `0x00547e10-0x00547f31` | received patch file writer | aggregate table only | Source method belongs to [UID:0000A9]; name `WriteReceivedPatchFile` is defensible.
| `0x00547f40-0x0054825f` | patch script parser | aggregate table only | Source method belongs to [UID:0000A9]; name `ParsePatchScriptGetRules` is defensible.
| `0x00548270-0x0054839e` | patch info writer / patcher launcher | aggregate table only | Source method belongs to [UID:0000A9]; name `WritePatchInfoAndLaunchPatcher` is defensible.
| `0x005483a0-0x005484da` | `PatchFileSlice` methods | [UID:0001ES], [UID:0001ET], vector deleting destructor | Nested [UID:0000AC]; no aggregate C++.
| `0x005484db-0x005484f1` | compiler adjustor thunks | [UID:0001EU] | Ignored/generated support.
| `0x00548500-0x00548555` | `PatchFileData` scalar deleting destructor | [UID:0003OC] | Nested [UID:0000AB]; no aggregate C++.
| `0x00548560-0x00548684` | `PatchPane` scalar deleting destructor | aggregate table only | Source method belongs to [UID:0000A9].
| `0x00548690-0x00548a05` | `PatchPane2` constructor | aggregate table only | Source method belongs to [UID:0000AA].
| `0x00548a80-0x00548f1a` | secondary-vtable download work-event handler | [UID:0001EV] | Keep child; best name `PatchPane2::HandleDownloadWorkEvent`.
| `0x00548f1c-0x00548f30` | jump table/data | ignored row exists | Generated data for [UID:0001EV], not handwritten source.
| `0x00548f30-0x00548f41` | secondary-vtable work-event predicate | [UID:0001EW] | Keep child; best name `PatchPane2::AcceptsDownloadWorkEvent`.
| `0x00548f50-0x00548f71` | active file close helper | aggregate table only | Source method belongs to [UID:0000AA]; name `CloseActivePatchFile` is defensible.
| `0x00548f80-0x0054901e` | finish/exit helper | aggregate table only | Source method belongs to [UID:0000AA]; name `FinishAndExit` is defensible.
| `0x00549020-0x00549080` | raw helper-shaped body, no modeled entry | [UID:0002R7] | Keep exact raw child; no further split; no formal C++.
| `0x00549080-0x00549214` | close/delete/rename helper, no direct xrefs | [UID:0001EX] | Keep exact child; no further split; no aggregate C++.
| `0x00549220-0x005492cf` | send download request | [UID:0001EY] | Keep exact child; best name `PatchPane2::SendDownloadRequest`.
| `0x005492d0-0x00549338` | write-error helper | aggregate table only | Source method belongs to [UID:0000AA]; name `ReportWriteError` is defensible.
| `0x00549340-0x0054934b` | `g_pPatchPane2` clear helper | [UID:0001EZ] | Keep child; cleanup/unwind helper.
| `0x0054934b-0x00549361` | compiler adjustor thunks | [UID:0001F0] | Ignored/generated support.
| `0x00549370-0x0054940e` | `PatchPane2` scalar deleting destructor | aggregate table only | Source method belongs to [UID:0000AA].
| `0x0054940f-0x00549410` | alignment | ignored row exists | Boundary before ImageLoaders-owned PCX decoder.

No new split is required for this assignment. The raw/source-bearing islands named in the prompt already have safe child pages or are explicitly aggregate-owned class methods. The blocker was not missing split work; it was stale aggregate metadata that still made [UID:0001EQ] an emitter despite its own body saying not to emit.

## Source Placement

Best current placement is `NexusTK/patch/PatchPane.cpp` through [UID:0000MH].

Evidence:

- `by-project-structure/proposed-source-tree.md` contains `patch/PatchPane.cpp`.
- [UID:0000MH] proposes `patch/PatchPane.cpp` / `patch/PatchPane.h`.
- `PatchPane` and `PatchPane2` are contiguous in the executable, share the patch/update read-only island, and are both constructed from the startup patch-decision path in `sub_4F6D80`.
- [UID:0000RZ] `g_pPatchPane2` is published/cleared by `PatchPane2` constructor/destructor/cleanup paths, supporting module ownership by PatchPane/PatchPane2 rather than Application.
- `PatchPane2` is tied to the patcher workflow, not to generic dialog UI or `MiscWorkThread`; `MiscWorkThread` is the HTTP/download service called by the request helper.
- Generated/source-tree context currently has `auto-generated/NexusTK/patch/PatchPane.cpp`, but that file is zero bytes. This confirms generated output omission; it is not evidence that the aggregate should become an artificial code emitter.

Rejected alternatives:

- `Application.cpp`: Application decides whether to construct the patch UI, but the constructors, vtables, packet/request helpers, patch script parser, and patcher launch code are all patch module behavior.
- `MiscWorkThread.cpp`: only owns async work queue/service mechanics. `PatchPane2` builds request paths and consumes work events but owns the patch dialog state machine.
- Separate mandatory `PatchPane2.cpp`: possible as a later migration choice, but not required now. There is no independent source-tree route or file doc for it, and the strongest current documentation route is the PatchPane module. Treat companion `PatchPane2.cpp` as optional migration shape, not a score or ownership blocker.
- `PacketBuffer` or network module: packet writers/readers are callees; opcode `0x48` and response `0x40` semantics belong to the patch workflow.

## Packet, Patcher, And Download Semantics

PatchPane packet flow:

- `PatchPane::SendPatchScriptRequest` at `0x00547a60` sends opcode `0x48`, subtype `0`, with the current script/path string and resets current patch-entry storage.
- `PatchPane::SendPendingPatchEntryRequests` at `0x00547b70` sends opcode `0x48`, subtype `1`, for pending entries and marks each requested `PatchFileSlice`.
- `PatchPane::~PatchPane` and `PatchPane::ShowPatchAlertAndExit` send opcode `0x48`, subtype `2`, as close/cancel/termination.
- `PatchPane::HandlePatchResponsePacket` at `0x005474f0` consumes responses gated by leading byte `0x40`; subtype `0` sets up patch-entry slice storage, subtype `1` receives slice payload data, and subtype `2` reports failure through localized alert/exit.

Patch script / patcher flow:

- The original `PatchPane` path downloads patch scripts, writes received patch files, parses `getpatcher` and `get` rules from `Patch/Script`, writes `Patch/Info`, and launches `patcher.exe` with `ShellExecuteExA` verb `runas`.
- Best helper names from current evidence are `ParsePatchScriptGetRules`, `WritePatchInfoAndLaunchPatcher`, `WriteReceivedPatchFile`, and `ShowPatchAlertAndExit`.
- Localized language ids observed in support docs include `174`, `175`, `176`, and `157` for success/exit/failure/pass-threshold paths.

PatchPane2 download flow:

- Constructor parses a packed descriptor with two version/path components, a byte count, and 256-byte filename records.
- Tail fields from [UID:0001VJ] remain the best source field directions:
  - `+0x26c`: final patcher path, initialized from `Patcher.exe`.
  - `+0x270`: temporary patcher path, initialized from `Patcher.exe.new`.
  - `+0x274/+0x278/+0x27c`: vector of download filenames.
  - `+0x280`: current filename index.
  - `+0x284`: active output `FILE*`.
  - `+0x288`: retry/pass counter, threshold `10`.
  - `+0x28c/+0x290`: request/version path components formatted as `%d/%d/%s`.
- `PatchPane2::SendDownloadRequest` at `0x00549220` formats `%d/%d/%s`, calls [UID:00022D] to copy/append the selected path and suffix, then queues work through `g_pMiscWorkThread`.
- [UID:00022D] should stay PatchPane2-owned support or inline/string-expression support despite physical adjacency near FolderTreePane. Its only confirmed caller is `0x0054928d` inside `PatchPane2::SendDownloadRequest`.
- `PatchPane2::HandleDownloadWorkEvent` consumes work events with magic `0x68747470` (`"http"` little-endian) and subtypes `0-4` for open, chunk write, final close/rename/launch, advance/retry, and error text.

Nested helper field directions:

- `PatchPane::PatchFileSlice` is a 0x10-byte element. Best field names are `requestIssued` or `requested` at `+0x04`, `payloadLength` at `+0x08`, and `payloadData` at `+0x0c`. `completeFlag` is rejected because completion is inferred by populated payload pointers and the pending sender marks the byte before receipt.
- `PatchPane::PatchFileData` has only destructor-visible layout at present. Best high-probability name for `+0x208` is `backingStore` or `buffer`, but formal member names should remain provisional until producer/allocation code is audited.

## Raw And No-Xref Island Resolution

The raw/no-xref issues do not prevent [UID:0001EQ] from clearing 85 as a non-emitting index, but they do prevent aggregate C++ and continue to cap some child first-draft code.

`0x00549020-0x00549080`:

- IDA `lookup_funcs` reports no function object at `0x00549020` or `0x0054907f`.
- Existing [UID:0002R7] documents exact raw bytes, unique full-range signature, index/pass-counter behavior, language id `157`, and outgoing call to `PatchPane2::FinishAndExit`.
- I rechecked PE-level references to `0x00549020`: no absolute VA hits, no RVA hits, and no `E8`/`E9`/`0F 8x` relative branch hits.
- Best classification: real source-authored helper-shaped bytes, probably an unused/out-of-line `AdvanceDownloadIndex` variant or a recovery artifact from an inlined helper, but with no proven callable entry.
- Rejected alternative: split or promote as a normal method now. There is already a raw child; entry liveness is not proven.
- Impact: caps [UID:0002R7] formal C++ and PatchPane2 class final declaration, but does not cap [UID:0001EQ] once [UID:0001EQ] is correctly non-emitting.

`0x00549080-0x00549214`:

- IDA models `sub_549080` with size `0x194`; [UID:0001EX] owns it.
- IDA reports no direct callers; PE scan found no absolute/RVA/relative entry hits to `0x00549080`.
- The same close/delete/rename behavior appears inline in [UID:0001EV] subtype `2`, so this may be unused out-of-line helper code, a devirtualized/inlined helper remainder, or a function whose entry is only referenced by data not recovered as a normal xref.
- Best classification: source-shaped PatchPane2 helper, exact child remains correct, formal C++ should remain blank until direct liveness and helper API names are settled.
- Impact: does not require a new split and does not block the aggregate index score.

`0x00548a80` and `0x00548f30`:

- These are vtable-only callback entries, not dead code. `0x00548a80` is referenced by `0x00621fb8`; `0x00548f30` is referenced by `0x00621fb4`.
- No direct callers are expected because the work-event interface dispatches through the secondary vtable.
- Best names: `PatchPane2::HandleDownloadWorkEvent` and `PatchPane2::AcceptsDownloadWorkEvent`.
- Rejected alternative: file-local static predicate for `0x00548f30`. It is a vtable slot in the `+0xa0` callback subobject, so it is callback-interface member behavior.

`0x005474f0` and `0x00547860`:

- These are vtable-only `PatchPane` callbacks.
- `0x005474f0` is the secondary-vtable response handler at `0x00621e3c`; best name `PatchPane::HandlePatchResponsePacket`.
- `0x00547860` is the tertiary action/timer callback; best name `PatchPane::HandlePatchAction` or `PatchPane::HandlePatchTimerAction`.

## Heuristic / Inference Reanalysis And Validation

Best defensible source names and directions:

- `0x005474f0`: `PatchPane::HandlePatchResponsePacket`.
  - Evidence checked: IDA function size `0x360`; sole xref at secondary vtable slot `0x00621e3c`; response byte `0x40`; subtype `0/1/2`; `MultiByteToWideChar`, `wcscmp`, slice construction, progress updates, and pending-entry request fan-out.
  - Rejected names: generic `OnPacket` is too broad; server dispatch ownership is wrong because no dispatcher code owns the state mutation.
  - Impact: closes [UID:0000A9] open question enough for class score/confidence, but exact field/API names still block formal child C++.

- `0x00548a80`: `PatchPane2::HandleDownloadWorkEvent`.
  - Evidence checked: IDA function size `0x49a`; sole xref at secondary vtable slot `0x00621fb8`; event magic `0x68747470`; subtype `0-4`; file open/write/rename/launch paths; calls to `SendDownloadRequest`, `ReportWriteError`, and `FinishAndExit`; switch table at `0x00548f1c`.
  - Rejected names: `MainLoop` is a documentation label, not source-facing enough; `MiscWorkThread` ownership is rejected because this mutates PatchPane2 fields.
  - Impact: [UID:0001EV] remains reconstructable, but formal C++ should stay blank pending work-event type and helper names.

- `0x00548f30`: `PatchPane2::AcceptsDownloadWorkEvent` or `PatchPane2::IsDownloadWorkEvent`.
  - Evidence checked: exact seven-instruction stdcall helper, returns `event+4 == 0x16`, vtable slot `0x00621fb4`, no callees.
  - Rejected alternatives: static file-local filter or generic boolean helper; vtable slot evidence proves callback-interface role.
  - Impact: does not block aggregate score; child can remain `82/88` until callback type/name is final.

- `0x00549020`: `PatchPane2::AdvanceDownloadIndexRaw` as documentation name, not a formal method name.
  - Evidence checked: no IDA function, no IDA xrefs, no PE absolute/RVA/relative branch hits, unique raw body signature, exact state fields `+0x274/+0x278/+0x280/+0x288`, failure path to `FinishAndExit`.
  - Rejected alternatives: normal exact-child method emission or deleting the row. The bytes are source-shaped and unique, but entry liveness is not proven.
  - Impact: supports leaving aggregate C++ blank and keeping [UID:0002R7] as raw child. It no longer caps [UID:0001EQ] once [UID:0001EQ] is non-emitting.

- `0x00549080`: `PatchPane2::CloseAndRenameDownloadedFile` / `PatchPane2::CloseAndPromoteDownloadedFile`.
  - Evidence checked: IDA modeled function size `0x194`; field uses `+0x26c/+0x270/+0x284`; `_fclose`, unlink/delete-style helper, `_rename`, `__errno`, `Win32Error`; no IDA direct callers; no PE entry refs; duplicate inline behavior in [UID:0001EV].
  - Rejected alternatives: merge into raw `0x00549020` or treat as padding. It is a modeled function with a unique body and exact child.
  - Impact: exact child remains, but no aggregate code and no formal child C++ until liveness/API names improve.

- [UID:00022D] `0x004b32d0`: PatchPane2 download path join helper.
  - Evidence checked: exact `0x74` helper, only xref from `0x0054928d` inside `SendDownloadRequest`, callee set limited to string copy/length/append helpers.
  - Rejected alternatives: FolderTreePane ownership by address adjacency; the only caller is PatchPane2.
  - Impact: coverage row should be updated from stale `78%` to current doc `86%`; formal C++ remains blank because source may have been inline string operations.

Field/type/layout directions:

- `PatchPane2 +0x26c/+0x270` are final and temp patcher path strings. This is supported by constructor initialization, main-loop file open/rename, close/rename helper, destructor cleanup, and `Patcher.exe` / `Patcher.exe.new` string evidence.
- `PatchPane2 +0x274/+0x278/+0x27c` is a filename vector. Supported by constructor parsing of packed 256-byte filename records, send-request index selection, raw advance helper, main loop, and destructor vector cleanup.
- `PatchPane2 +0x280` is current filename index; `+0x288` is retry/pass counter with threshold `10`; `+0x28c/+0x290` are request/version path components.
- `PatchFileSlice +0x04/+0x08/+0x0c` are best named `requested`, `payloadLength`, and `payloadData`. Stronger names are blocked by producer semantics but the roles are good enough for documentation.
- `PatchFileData +0x208` is a backing buffer/store pointer. Do not overname it yet.

Ownership and source placement:

- [UID:0000MH] `PatchPane` remains correct for the family. Constructors originate from Application startup, but ownership stays with patch/update UI.
- `PatchPane2` should be grouped with PatchPane under `patch/PatchPane.cpp`. A companion `PatchPane2.cpp` is a possible final organization but not a current blocker.
- `g_pMiscWorkThread`, packet writers, string helpers, and `Application` are support callees/callers, not source owners.

Generated-output validation:

- `auto-generated/NexusTK/patch/PatchPane.cpp` exists but is zero bytes.
- Active generated metadata omits [UID:0001ER], [UID:0001EV], and [UID:0001EW], and has a false/generated `0x00549020` method row. Treat generated output as incomplete and polluted.
- Vtables and switch tables should be regenerated from source declarations and control flow, not emitted as handwritten aggregate source.

Score/source-placement/final-C++ impact:

- [UID:0001EQ] can clear the active gate at `87/91` only as a non-emitting split/index. It should not be used as an emitter because it is not a source-level method or class.
- Child pages already carry the exact method evidence. Their remaining field/helper/API naming issues affect those children, not the aggregate boundary decision.
- Formal C++ for [UID:0001EQ] should remain blank. Formal C++ for [UID:0001ER], [UID:0001EV], [UID:0001EX], [UID:0002R7], and [UID:00022D] should also remain blank until each child clears its own final code gate.

## Exact Target-Doc Changes For Supervisor

### [UID:0001EQ] Header

Replace the tracked header values with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave the formal C++ block blank.

### [UID:0001EQ] Status Replacement

Replace the current `## Status` bullet block with:

```markdown
## Status

- Disposition: non-emitting source-family split/index for the PatchPane and PatchPane2 updater module.
- Entity kind: class family cluster / source-boundary review page.
- Likely owner: [UID:0000MH][PatchPane](by-file/PatchPane.md).
- Current generated route: `auto-generated/NexusTK/patch/PatchPane.cpp` exists but is zero bytes; current generated class files are incomplete and polluted by omitted vtable callbacks and a false `0x00549020` method row.
- Source placement: `NexusTK/patch/PatchPane.cpp`. A companion `PatchPane2.cpp` is possible later but is not needed to resolve ownership or score.
- Reconstruction policy: do not emit aggregate C++ for this page. Source-bearing code should emit only from exact children/classes after their own field/helper/API names clear the code gate.
- Confidence: strong for patch/update ownership, exact aggregate boundary, child split coverage, vtable-backed callback reachability, raw `0x00549020` treatment, `g_pPatchPane2` lifecycle, and exclusion of the ImageLoaders-owned `0x00549410` decoder.
```

### [UID:0001EQ] Add Change Entry

Append to `## Changes`:

```markdown
- 2026-06-17 B003 source-quality reanalysis:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MH`; the body already said not to emit aggregate C++ but the validator header and coverage row still treated the mixed family cluster as reconstructable/emitting.
  - After: `COMPLETION:87`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; owner remains [UID:0000MH][PatchPane](by-file/PatchPane.md).
  - Summary/evidence: current IDA and support docs confirm every source-bearing or generated/raw island has exact child or class treatment. `0x005474f0`, `0x00548a80`, and `0x00548f30` are vtable callback bodies; `0x00549020` is an exact raw no-entry child with no IDA or PE entry refs; `0x00549080` is an exact modeled helper with no proven direct callers; compiler thunks, switch-table data, padding, and the ImageLoaders-owned `0x00549410` decoder are excluded. The aggregate is now source-quality as a split/index and should not populate formal C++.
```

## Exact Support-Doc Changes For Supervisor

### [UID:0000A9] PatchPane Open Questions

Replace:

```markdown
## Open Questions

- Decide whether `PatchPane2` should stay in the same original source file or become a companion `PatchPane2.cpp`.
- Name the `0x005474f0` packet response handler after reviewing server packet dispatch callers.
- Reconcile generated base-destructor labels such as `TransferReplyAlert` and other polluted dialog names before header emission.
```

With:

```markdown
## Resolved Source-Quality Notes

- Source placement: group `PatchPane2` with [UID:0000MH][PatchPane](by-file/PatchPane.md) under `patch/PatchPane.cpp`. A companion `PatchPane2.cpp` remains a possible migration shape, but the current source-quality evidence does not require it and it should not block PatchPane ownership or scoring.
- Best source-facing name for `0x005474f0`: `PatchPane::HandlePatchResponsePacket`. Evidence is the secondary-vtable slot at `0x00621e3c`, the leading `0x40` response gate, subtype `0/1/2` behavior, slice allocation/receipt, progress updates, and pending-entry request fan-out. Server packet dispatch is caller/interface context, not owner.
- Generated base-destructor labels such as `TransferReplyAlert` and other polluted dialog names should be treated as generated-name contamination. Use the IDA-backed vtable, range, and child-method evidence for header/source reconstruction.
```

Recommended score change for [UID:0000A9]: `86/85` to `87/88`.

### [UID:0000AA] PatchPane2 Open Questions

Replace:

```markdown
## Open Questions

- Re-own or emit `0x00548a80`; without it, active generated `PatchPane2.cpp` misses the actual download/write event loop.
- Correct or remove the `0x00549020` Wave3 method row.
- Decide whether `0x00548f30` is a static predicate, callback object helper, or file-local work-thread filter.
```

With:

```markdown
## Resolved Source-Quality Notes

- `0x00548a80` is already correctly owned by [UID:0000AA][PatchPane2](by-class/PatchPane2.md) as a secondary-vtable callback. Best source-facing name: `PatchPane2::HandleDownloadWorkEvent`. Vtable-only reachability through `0x00621fb8` is expected for this callback and should not be treated as dead code.
- `0x00549020` should not be treated as a modeled function or trusted Wave3 method row. Keep [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) as an exact raw helper-shaped child with formal C++ blank until entry liveness is proven. Current IDA and PE scans find no function object, no xrefs, no absolute/RVA hits, and no relative branch hits to `0x00549020`.
- `0x00548f30` is the paired secondary-vtable predicate at `0x00621fb4`. Best source-facing name: `PatchPane2::AcceptsDownloadWorkEvent` or `PatchPane2::IsDownloadWorkEvent`. It is not a generic static/file-local helper because it is installed in the `+0xa0` callback subobject vtable.
```

Recommended score change for [UID:0000AA]: `86/85` to `87/88`.

### [UID:0000MH] PatchPane File Page

Recommended status/source-structure wording change:

```markdown
Use `patch/PatchPane.cpp` as the current source-layout route for both `PatchPane` and `PatchPane2`. A companion `PatchPane2.cpp` is possible during migration, but the strongest current evidence keeps both classes in one patch/update module: contiguous executable island, shared vtable/read-only data neighborhood, shared patcher/update literals, common Application startup constructor path, and the `g_pPatchPane2` singleton lifecycle. Do not let the optional companion-file question cap current owner/emitter routing.
```

Recommended score change for [UID:0000MH]: `88/85` to `89/88`.

### [UID:00022D] PatchPane2DownloadPathJoinHelper

No body change is required. Its current doc already supports `86/89`; only the coverage row is stale at `78%`.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001EQ].

Reason: [UID:0001EQ] should become a non-reconstructable/non-emitting split/index. It spans multiple source entities and contains compiler-generated adjustor thunks, switch-table data, padding, exact child methods, nested helper types, and raw/no-entry helper bytes. Any aggregate C++ would be artificial and would duplicate child responsibilities.

Also do not populate first-draft C++ from this report for [UID:0001ER], [UID:0001EV], [UID:0001EW], [UID:0001EX], [UID:0002R7], or [UID:00022D]. Those children have strong behavior evidence, but their formal C++ remains unsafe for the following concrete reasons:

- `PatchPane` packet fields, child/control collection types, allocator/string helper names, and final callback interface names are not source-quality.
- `PatchPane2` work-event type names, string-wrapper APIs, file-open/delete helpers, and original method names are still descriptive rather than recovered.
- `0x00549020` has no proven callable entry.
- `0x00549080` has no direct IDA or PE entry refs and duplicates behavior inline in the main event handler.
- [UID:00022D] may fold into a string expression or inline helper once final string API names are known.

## Score And Metadata Summary

| UID | Current | Recommended | Metadata recommendation |
| --- | --- | --- | --- |
| [UID:0001EQ] | `82/88` | `87/91` | `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, owner [UID:0000MH] retained.
| [UID:0000MH] | `88/85` | `89/88` | Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/patch/"`; clarify optional `PatchPane2.cpp` does not cap routing.
| [UID:0000A9] | `86/85` | `87/88` | Replace open questions with resolved notes; best packet-handler name `HandlePatchResponsePacket`.
| [UID:0000AA] | `86/85` | `87/88` | Replace open questions with resolved notes; best callback names and raw-helper policy.
| [UID:0001ER] | `86/88` | no header change | Coverage row should be aligned to current score and include path/range.
| [UID:0001EV] | `86/88` | no header change | Coverage row should be aligned to current score and include path/range.
| [UID:0001EW] | `82/88` | no header change | Keep below completion gate until callback type/name is final; coverage row can still be made well-formed.
| [UID:0002R7] | `85/88` | no header change | Coverage row should be aligned to current score and include path/range.
| [UID:0001EX] | `86/88` | no header change | Coverage row should be aligned to current score and include path/range.
| [UID:0001EY] | `82/88` | no header change | Exact behavior known; final request queue/string API names still cap completion.
| [UID:0001EZ] | `82/88` | no header change | Exact behavior known; helper spelling/unwind role still cap completion.
| [UID:00022D] | `86/89` | no header change | Coverage row should be aligned to current score.

## Supervisor-Owned Coverage Row Text

Placement context: replace the existing [UID:0001EQ] row in the `0x005470b0` area of `by-memory/-coverage-report.md`. Replace the listed child rows at their existing positions in the same block. Replace [UID:00022D] at its current `0x004b32d0` position.

```markdown
    - [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) 0x004b32d0-0x004b3344 | helper function | PatchPane2DownloadPathJoinHelper : reconstructable : 86% : strong : PatchPane2-only request-path helper called from `PatchPane2::SendDownloadRequest`; exact range, only caller at `0x0054928d`, string copy/length/append callee set, source placement under the PatchPane module, and final string/API-name caveat are documented.
```

```markdown
    - [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) 0x005470b0-0x0054940f | source-family split/index | PatchPaneAndPatchPane2 : non-reconstructable : 87% : strong : B003 source-quality reanalysis resolves this as a non-emitting PatchPane/PatchPane2 updater-family index under [UID:0000MH] `patch/PatchPane.cpp`; exact child pages own source-bearing methods, compiler thunks/switch data/padding stay non-handwritten, `0x00549020` remains exact raw no-entry child [UID:0002R7], and `0x00549410` stays excluded as ImageLoaders-owned PCX decoder.
```

```markdown
    - [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) 0x005474f0-0x00547850 | virtual packet callback | PatchPane::HandlePatchResponsePacket : reconstructable : 86% : strong : Exact secondary-vtable packet callback with response byte `0x40`, subtype `0/1/2` layout, PatchFileSlice vector construction, payload receipt, progress update, pending-request fan-out, no direct code callers, and source-name/field/API caveats documented.
```

```markdown
    - [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) 0x00548a80-0x00548f1a | virtual work-event callback | PatchPane2::HandleDownloadWorkEvent : reconstructable : 86% : strong : Exact secondary-vtable PatchPane2 download callback with `http` event magic, subtype `0-4` open/write/finalize/advance/error handling, switch table boundary at `0x00548f1c`, PatchPane2 field map usage, helper fan-in, and final work-event/string/API-name caveats documented.
```

```markdown
    - [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md) 0x00548f30-0x00548f41 | virtual callback predicate | PatchPane2::AcceptsDownloadWorkEvent : reconstructable : 82% : strong : Exact secondary-vtable predicate returning `event+4 == 0x16`, paired with the PatchPane2 download work-event callback; behavior, vtable slot, no direct callers/callees, and callback-type/name caveat documented.
```

```markdown
    - [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) 0x00549020-0x00549080 | raw helper body | PatchPane2AdvanceDownloadIndexRaw : reconstructable : 85% : strong : Exact raw PatchPane2 index/pass-counter helper-shaped body between `FinishAndExit` and the modeled close/rename helper; IDA and PE scans find no function object, no xrefs, no absolute/RVA hits, and no relative branch hits to `0x00549020`, while unique raw bytes and state/callee behavior are documented.
```

```markdown
    - [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) 0x00549080-0x00549214 | helper method | PatchPane2::CloseAndRenameDownloadedFile : reconstructable : 86% : strong : Exact modeled PatchPane2 close/delete/rename helper with field use at `+0x26c/+0x270/+0x284`, `_fclose`, delete/unlink-style helper, `_rename`, `__errno`, Win32Error throw path, no direct IDA or PE entry refs, duplicate inline main-loop behavior, and final source-name/API/liveness caveats documented.
```

```markdown
    - [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) 0x00549220-0x005492cf | helper method | PatchPane2::SendDownloadRequest : reconstructable : 82% : strong : PatchPane2 request helper with exact modeled boundary, constructor/main-loop callers, `%d/%d/%s` formatting, current vector index/version fields, [UID:00022D] path-join helper call, `g_pMiscWorkThread` queue path, and remaining request-queue/string API name caveats.
```

```markdown
    - [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) 0x00549340-0x0054934b | lifecycle cleanup helper | ClearPatchPane2Singleton : reconstructable : 82% : strong : PatchPane2 lifecycle cleanup helper with exact `0x0b` boundary, constructor-unwind xref, `g_pPatchPane2` clear at `dword_69BA2C`, ordinary destructor counterpart, PatchPane2 parent attachment, and final helper-spelling/unwind-role caveats documented.
```

Rows not listed here do not need score/metadata changes for this assignment.

## Validation Commands

Recommended supervisor validation:

> Executable block R001 was removed from this report and preserved verbatim in [0001EQ-patchpane-family-source-quality-removed.md](0001EQ-patchpane-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/MCP checks performed or recommended to reproduce:

```text
lookup_funcs 0x005470b0 0x005473f0 0x005474f0 0x00547860 0x00547950 0x00547980 0x00547a60 0x00547b70 0x00547e10 0x00547f40 0x00548270 0x005483a0 0x00548410 0x00548500 0x00548560 0x00548690 0x00548a80 0x00548f30 0x00548f50 0x00548f80 0x00549020 0x00549080 0x00549220 0x005492d0 0x00549340 0x00549370 0x00549410
xrefs_to 0x005470b0
xrefs_to 0x005474f0
xrefs_to 0x00548a80
xrefs_to 0x00548f30
xrefs_to 0x00549020
xrefs_to 0x00549080
xrefs_to 0x00549220
xrefs_to 0x0069ba2c
analyze_component 0x005474f0
analyze_component 0x00548a80
analyze_component 0x00549020
analyze_component 0x00549080
analyze_component 0x00549220
make_signature_for_range 0x005470b0 0x00549410
make_signature_for_range 0x00549020 0x00549080
```

PE reference scan performed against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- `0x00549020`: absolute VA hits `0`, RVA hits `0`, relative branch hits `0`.
- `0x00549080`: absolute VA hits `0`, RVA hits `0`, relative branch hits `0`.
- Control target `0x00548f80`: relative branch hits `5` at `0x00548c33`, `0x00548cba`, `0x00548e69`, `0x00549079`, and `0x0054931a`.

## Changed / No-Change Scope

Changed by this assignment: this report file only.

No by-* docs, generated reports, generated source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited. No split was performed because every in-scope island already has an exact child or class-level owner and the safe repair is metadata/policy, not new documentation files.

## Blockers And Follow-Up

No blocker remains for supervisor review of [UID:0001EQ] as a non-emitting split/index at `87/91`.

Useful follow-up work after this report:

- Method-level C++ pass for [UID:0001ER] after `PatchPane` field names and packet/string helper APIs are stabilized.
- Method-level C++ pass for [UID:0001EV] after work-event type names and string/file helper APIs are stabilized.
- Separate raw/liveness investigation for [UID:0002R7] and [UID:0001EX] if final PatchPane2 method C++ is desired.
- Optional source-layout decision later on whether to materialize a companion `PatchPane2.cpp`; current evidence does not require it.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001EQ-patchpane-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001EQ"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001EQ-patchpane-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001EQ-patchpane-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001EQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
