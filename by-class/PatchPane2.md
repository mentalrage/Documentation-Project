*** UID:0000AA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane2

## Status

- Confidence: strong for alternate patch download dialog behavior, vtable callback ownership, and tail-field usage; medium for exact method/helper names.
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md), possibly original `PatchPane2.cpp`
- Current recovered file: `source-3/simroot_v2/class_PatchPane2.cpp`
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- Reconstructable: yes; class semantics are NexusTK-owned patch/update UI code. No class C++ declaration is emitted yet because the main-loop ownership repair, exact method names, and final source-file split are still below the 95% code-emission threshold.

## Class Purpose

`PatchPane2` is the newer or alternate patch download dialog. It parses a packed patch-data buffer, builds a simple status/count/cancel dialog, keeps a vector of file names, downloads files through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), writes temporary files, renames them into place, and exits through a shared completion/error path.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00548690-0x00548a05` | `PatchPane2::PatchPane2` | Builds the dialog, sets [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md), parses version/file list, stores base URL/path strings, and sends the first request. |
| `0x00548a80-0x00548f1a` | [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) | Excluded from active Wave3 output; handles work-thread events, opens output file, writes chunks, closes/renames files, advances files/passes, and handles errors. |
| `0x00548f30-0x00548f41` | [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md) | Returns true when event field `+4` is `22`. |
| `0x00548f50-0x00548f71` | `ClosePatchFile` | Closes the active `FILE*`. |
| `0x00548f80-0x0054901e` | `FinishAndExit` | Optionally shows an alert, closes dialog, cleans main-menu/session state, and requests application exit. |
| `0x00549020-0x00549080` | [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) | Raw unmodeled helper-shaped body that advances file index/pass counter or exits after the retry threshold. |
| `0x00549080-0x00549214` | [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) | Closes the active file, converts wide paths, unlinks target, renames temp to final, and throws `Win32Error` on failure. |
| `0x00549220-0x005492cf` | [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) | Formats `%d/%d/%s` and sends a [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) HTTP-get request. |
| `0x005492d0-0x00549338` | `ReportWriteError` | Formats `Error writing %s` and exits through `FinishAndExit`. |
| `0x00549340-0x0054934b` | [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) | Clears `g_pPatchPane2`. |
| `0x0054934b-0x00549360` | [UID:0001F0][0x0054934b-0x00549360.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md) | Compiler-generated secondary/tertiary vtable thunks forwarding to `0x00549370`; document and ignore for handwritten source. |
| `0x00549370-0x0054940e` | scalar deleting destructor | Closes active file, destroys file vector and strings, clears `g_pPatchPane2`, destroys base, and optionally deletes. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- Generated metadata says `0x00548a80` is the main patching loop and marks it excluded, matching IDA decompilation. 2026-06-01 IDA MCP confirms it as `sub_548A80` with exact range `0x00548a80-0x00548f1a`, a single vtable xref at `0x00621fb8`, no direct code callers, subtype `0-4` work-event dispatch, touched owner fields at `+0x26c/+0x270/+0x274/+0x280/+0x284/+0x288`, and generated switch-table data at `0x00548f1c-0x00548f30`.
- `0x00548f30` is the paired work-event predicate slot at `0x00621fb4`; 2026-06-01 IDA MCP confirms the complete seven-instruction helper returns whether byte `event+4` equals `0x16`, with no direct callers, no callees, and `0xcc` alignment at `0x00548f41-0x00548f50`.
- IDA MCP reports no modeled function and no xrefs at generated `PatchPane2::AdvancePatchStep` start `0x00549020`, but 2026-06-01 disassembly/byte review confirms a real unmodeled helper-shaped body at [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md). IDA modeled helper starts remain `0x00549080` and `0x00549220`.
- `0x00549080` is the close/delete/rename helper: 2026-06-01 IDA MCP confirms exact range `0x00549080-0x00549214`, owner fields `+0x26c/+0x270/+0x284`, no direct callers, duplicate inline behavior in the main loop subtype `2`, Win32Error throw paths, and `0xcc` padding at `0x00549214-0x00549220`.
- Constructor caller evidence points back to the same application startup patch decision function that constructs `PatchPane`.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary vtable at `0x00621f40`, the secondary work-event vtable at `0x00621fa0`, and the tertiary vtable at `0x00621fd0`. Generated metadata currently reports `vtable_count: 0` and should not be trusted for polymorphism.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) documents the IDA-backed tail fields at `+0x26c-+0x290`, including the final/temp patcher paths, filename vector, active `FILE*`, index/retry counters, and version components.

## Open Questions

- Re-own or emit `0x00548a80`; without it, active generated `PatchPane2.cpp` misses the actual download/write event loop.
- Correct or remove the `0x00549020` Wave3 method row.
- Decide whether `0x00548f30` is a static predicate, callback object helper, or file-local work-thread filter.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md)
- [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md)
- [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md)
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md)
- [UID:0001F0][0x0054934b-0x00549360.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md)
- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)

## Changes

- 2026-05-31 reconstructable metadata repair:
  - What existed before: the class page was documented and listed as reconstructable in coverage, but validator metadata still had blank `RECONSTRUCTABLE`.
  - What it was changed to: set `RECONSTRUCTABLE:TRUE` so child layout/type docs can attach to the class without validator parent-ineligible errors.
  - Summary/evidence: IDA MCP and existing page evidence confirm `PatchPane2` is NexusTK-owned patch/update UI code; C++ remains blank because final source shape and method names are not audit-complete.

- Before: completion/confidence metadata were `0/0` even though the page already documented the alternate patch dialog, main loop, work-thread helpers, file close/rename/send/error helpers, singleton, vtables, layout, and open issues.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- 2026-06-01 update: raised to `COMPLETION:86`, `CONFIDENCE:82` after the main loop gained exact IDA-backed range, vtable, event-state, touched-field, callee, and switch-table evidence.
- Evidence: constructor, excluded main loop, work-event predicate, close/finish/rename/request/error helpers, scalar deleting destructor, `g_pPatchPane2`, `g_pMiscWorkThread`, vtable family, and layout doc are recorded; confidence remains below final-source quality because active generated output omits the core main loop and has a false `0x00549020` row.
