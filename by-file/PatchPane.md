*** UID:0000MH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/patch/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PatchPane

## Status

- Source module: `NexusTK/patch/PatchPane.cpp`
- Proposed header: `patch/PatchPane.h`
- Confidence: source-ready for patcher/update responsibility, singleton ownership, complete PatchPane2 source order, patch-pane island boundaries, and the unified `PatchPane.cpp` route. The former optional companion-file hypothesis is superseded.
- Current validator-owned source: `auto-generated/NexusTK/patch/PatchPane.cpp`; no generated `PatchPane.h` exists under the current CPP-only nested-class convention. The former split `class_PatchPane*.cpp` paths are historical inputs to this unified route.

## File Role

`PatchPane.cpp` likely owned the startup patch/update UI and patch download flow. The module builds the `Auto Patch` dialog, exchanges opcode `0x48` patch packets, writes `Patch/Script` and `Patch/Info`, parses `get` rules, optionally launches `patcher.exe`, and runs the newer file-download patch dialog through `PatchPane2`.

This should stay separate from [UID:0000MF][ParcelPane](by-file/ParcelPane.md). IDA MCP confirms `PatchPane` begins at `0x005470b0`, immediately after the parcel notification cluster. It should also stay separate from [UID:0000HG][Application](by-file/Application.md), which triggers startup patch decisions but should not own the patch dialog implementation.

## Proposed Contents

| Entity | Current range | Historical split generated owner | Current ownership |
| --- | --- | --- | --- |
| [UID:0000A9][PatchPane](by-class/PatchPane.md) | `0x005470b0-0x00548560` plus helper/thunk gaps | `class_PatchPane.cpp` | `PatchPane.cpp` |
| [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) | `0x005483a0-0x005484f0` | `class_PatchPane__PatchFileSlice.cpp` partially | `PatchPane.cpp` nested helper |
| [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) | [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md) | `class_PatchPane__PatchFileData.cpp` | `PatchPane.cpp` nested helper |
| [UID:0000AA][PatchPane2](by-class/PatchPane2.md) | `0x00548690-0x0054940f` | `class_PatchPane2.cpp` | `PatchPane.cpp` |
| [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) | `0x0069ba2c` | `class_PatchPane2.cpp` | `PatchPane.cpp` module global |

## Evidence

- IDA MCP confirms the patch-pane function island from `0x005470b0` through `0x0054940f`; the next function at `0x00549410` is unrelated image/decoder-style code.
- IDA MCP confirms vtable/callback bodies at [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md), [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md), and [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md). The `PatchPane` packet-response handler is the secondary-vtable callback at `0x00621e3c`; 2026-06-27 B008 implementation confirms its exact range, no direct code callers, subtype `0/1/2` behavior, adjacent `0xcc` alignment gaps, big-endian `PacketBufferReadUInt32BE` count/index/length reads, and first-draft `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)` C++ readiness. The `PatchPane2` main loop and predicate are the paired secondary work-event callback slots at `0x00621fb8` and `0x00621fb4`; B009 2026-06-27 implementation confirms the main loop is source-ready as `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)` with formal first-draft C++, exact subtype `0-4` behavior, generated switch-table data at `0x00548f1c-0x00548f30`, no direct code callers, and the expected vtable-only route.
- Constructor callers for `PatchPane` and `PatchPane2` both come from the same application startup function at `0x004f6d80`.
- `PatchPane::PatchPane` constructs [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) at `0x005472d7` for the `Auto Patch` progress UI; progress-bar implementation remains generic `ui/controls` code.
- `PatchPane` uses `Auto Patch`, `Patch/Script`, `Patch/Info`, `patcher.exe`, `runas`, `getpatcher`, `get`, opcode `0x48`, and language ids `0xaf`, `0xb1`, and `0xae`.
- B004 2026-06-27 00024T split: [UID:000487][0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData](by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md) is the shared source-use string child for `runas` and `patcher.exe` update/patch helper literals. The parent [UID:00024T][0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData](by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md) remains a no-owner mixed index, not Application-only data.
- `PatchPane2` uses `g_pPatchPane2`, `g_patchDownloadUrl`, `g_patcherExePath`, a vector of patch filenames, and download requests through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).
- 2026-06-01 IDA MCP confirms generated `0x00549020` is not an IDA-modeled function, but disassembly/bytes show a real raw [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) helper between `FinishAndExit` and the close/rename helper; keep it documented separately from [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md).
- B010 2026-07-04 rechecked [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) with MCP session `nexustk_supervisor_20260704`: `0x00549080` remains modeled as `sub_549080`, size `0x194`, with zero direct xrefs/callers; [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) completed-download state emits the close/delete/rename behavior inline; current generated `PatchPane.cpp` already represents UID0001EX as a covered-by comment rather than an empty marker. Keep that no-active-body route for source migration.
- `PatchFileData` and `PatchFileSlice` are nested support types whose vtables are referenced from the PatchPane range.
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) constructor/destructor pages [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md) and [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md) use the nested class as their direct semantic owner while still emitting through this file root. The nested class declaration belongs in the PatchPane source/header family under `NexusTK/patch/PatchPane.cpp` / `PatchPane.h`; the generated vector/scalar deleting destructor at `0x00548430-0x005484db` is compiler output from `virtual ~PatchFileSlice()` and should not be emitted as handwritten source.
- The resolved nested source order is the complete [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) `PatchPane::PatchFileSlice` declaration followed by the complete [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) `PatchPane::PatchFileData` declaration. That order makes `PatchFileSlice` complete where `PatchFileData::~PatchFileData()` performs `delete[] m_patchEntrySlices`.
- UID0001ER is the resolved producer: subtype `0` allocates `new PatchFileSlice[m_patchFileData.m_patchEntryCount]` with the standard four-byte MSVC array cookie and stores the element pointer in `m_patchFileData.m_patchEntrySlices`. UID0000AB owns the matching `delete[]`; UID0003OC is compiler output from its virtual destructor and must remain a two-line covered-by comment rather than a handwritten ABI helper.
- 2026-06-14 C001 IDA MCP confirms [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md) as the exact half-open nested `PatchFileData` scalar deleting destructor; the previous `0x00548554` endpoint was the final instruction byte, not the project range end.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary/secondary/tertiary vtables for both `PatchPane` and `PatchPane2`, plus the nested `PatchFileData` / `PatchFileSlice` vtables. Current generated metadata reports `vtable_count: 0`, so IDA vtable evidence should take precedence.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) pins the `PatchPane2` tail fields from `+0x26c` through `+0x290`, including final/temp patcher paths, the filename vector, active `FILE*`, retry/index counters, and request version components.

## 2026-06-08 Batch124 Parent-Gate Review

This file is the direct source parent for the module-global [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md). Live IDA MCP rechecked the exact singleton storage and owner neighborhood against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`):

- `0x0069ba2c` remains `dword_69BA2C`, a 4-byte `.data` item initialized to zero/null (`00 00 00 00` / `0`). The older `0xffffffff` wording is superseded by later B003/B011 zero-fill checks.
- `xrefs_to 0x0069ba2c` reports the `PatchPane2` constructor publish/clear pair at `0x005486f4` and `0x005486fb`, the raw cleanup/body reference at `0x00548a6d`, the constructor-EH singleton clear helper at `0x00549340`, and the scalar deleting destructor clear at `0x005493d0`.
- `lookup_funcs` confirms the current owner-side boundaries: constructor `0x00548690` size `0x376`, main loop `0x00548a80` size `0x49a`, constructor-EH clear helper `0x00549340` size `0x0b`, scalar deleting destructor `0x00549370` size `0x9f`, and raw `0x00549020` still not an IDA function.

This evidence raised confidence for file-level ownership to the corrected parent gate. B003's source-quality reanalysis later resolved the current routing at `89/88`: use the PatchPane module for `PatchPane`, `PatchPane2`, nested helpers, and the module singleton, while leaving a companion `PatchPane2.cpp` only as a possible migration shape rather than a current owner/emitter blocker.

## 2026-07-01 B011 Empty-Emitter First Batch

B011 applied the accepted first implementation batch for generated `auto-generated/NexusTK/patch/PatchPane.cpp` while keeping the source route unchanged as `NexusTK/patch/PatchPane.cpp`. This batch promotes [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) to formal first-draft C++, emits [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) as a normal source singleton declaration, and replaces duplicate/generated-data blank emitters with target-specific covered-by or no-standalone-data comments.

Historical B011 state (2026-07-01, superseded for UID0000AB): the first batch did not add formal bodies for [UID:0000A9][PatchPane](by-class/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md), or [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md). UID0003OC research now resolves the nested `PatchFileData` layout, producer, and lifetime, so UID0000AB emits its complete formal class through this file route; the other listed class/API bodies retain their prior dispositions.

Historical B011 first-batch expectation: validator regeneration was to remove markers for [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md), [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md), [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md), [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md), [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md), [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md), [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md), [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md), and [UID:000264][0x00621db8-0x00622030.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md). That batch raised completion/confidence to `90/89`; current validator-owned output is governed by the later implementation receipts, while remaining class/API declaration blanks keep the page below final-audit quality.

## Source-Structure Decision

Use `patch/PatchPane.cpp` as the current source-layout route for both `PatchPane` and `PatchPane2`. A companion `PatchPane2.cpp` is possible during migration, but the strongest current evidence keeps both classes in one patch/update module: contiguous executable island, shared vtable/read-only data neighborhood, shared patcher/update literals, common Application startup constructor path, and the `g_pPatchPane2` singleton lifecycle. Do not let the optional companion-file question cap current owner/emitter routing.

The top-level folder could also be `app/` if the original project was flatter. A distinct `patch/` folder is clearer for reconstruction because it separates updater code from general application shell and login UI.

## Migration Notes

- Keep `0x005474f0` attached through [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) as `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)` and [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) as `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)`, then refresh generated output from the by-memory pages rather than manually editing generated C++. Restore or attach `0x005483a0`, `0x00548410`, `0x005484db`, `0x005484e6`, `0x00548f30`, and `0x00549340` before source migration. Preserve `0x00549080` as [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md)'s covered-by no-active-body comment unless future evidence proves a live source call path.
- Keep generated Wave3 `PatchPane2::AdvancePatchStep` at `0x00549020` rejected as a modeled method. [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) is the exact raw no-entry child: IDA reports no function object or xrefs at `0x00549020`, PE scans found no absolute/RVA/relative branch hits, and the surrounding modeled starts remain `0x00548a80`, `0x00549080`, and `0x00549220`.
- Treat `0x005484db-0x005484f1` and `0x0054934b-0x00549361` as compiler-generated destructor adjustor thunks. They should be documented and ignored, not rewritten as handwritten patcher methods.
- Treat `PatchPane2` generated method names with caution because metadata reports control-character name grade penalties at constructor/destructor rows.
- Keep `PatchPane` packet helpers near [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) only as callees; source ownership is still patch UI/update flow.

## Cross-References

- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md)
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md)
- [UID:0001EU][0x005484db-0x005484f1.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md)
- [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md)
- [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md)
- [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md)
- [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md)
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md)
- [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md)
- [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md)
- [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md)
- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:000487][0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData](by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md)

## UID0002ZP PatchPane2 Source Closure

- The accepted source order is [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md), [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md), [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md), [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), [UID:0004VU][0x00548f50-0x00548f72.PatchPane2ClosePatchFile](by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md), [UID:0004VV][0x00548f80-0x0054901f.PatchPane2FinishAndExit](by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md), [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md), [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md), [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md), [UID:0004VW][0x005492d0-0x00549339.PatchPane2ReportWriteError](by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md), [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md), [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md), and [UID:0004VX][0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor](by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md).
- Source-bearing rows emit through `NexusTK/patch/PatchPane.cpp`. UID0002R7 and UID0001EX remain covered evidence for behavior already emitted in UID0001EV; UID0001EZ, UID0001F0, UID0004VX, and [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md) are compiler products and emit no handwritten source.
- The complete `0x294` class layout is declared once on UID0000AA. [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) remains evidence-only, and the singleton backing [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) remains non-emitting physical storage behind UID0000RZ's sole source definition.
- Constructor/application routing, contiguous address order, neighboring PatchPane ownership, shared vtable/RTTI neighborhood, patcher literals, and the single global lifecycle all support one source module. No independent companion translation unit has a distinct global, class, include boundary, caller family, or source-only data island.
- Historical `m_statusControls` prose is superseded: `this+0x1fc` belongs to inherited DialogPane child-management state, and source callbacks use `GetChild<StaticTextControlPane>(0/1)`. No PatchPane2 member is inserted there.
- Negative source policy excludes explicit vptr stores, global clears in destructors, constructor unwind helpers, `this` adjustments, scalar-delete flags, stack cookies, decompiler labels, raw offsets, and duplicate source bodies.

## UID0002ZP Implementation Callback

- 2026-07-21: raised this file support page from `90/89` to `92/94` without changing its route or unrelated PatchPane/PatchFile inventory. The callback records the complete validator-issued PatchPane2 child union and supersedes the former optional `PatchPane2.cpp` migration hypothesis.

## Changes

- 2026-06-27 B004 00024T shared patcher-string support sync:
  - Score unchanged at `89/88`.
  - Added [UID:000487][0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData](by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md) as the shared source-use string child for `runas` and `patcher.exe` update/patch helper literals, leaving metadata unchanged.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Summary/evidence: the page documents patch/update responsibility, class/helper/global ownership, IDA evidence, vtable/layout types, source-structure decision, migration cautions, and cross-references; confidence remains capped by final folder choice and unresolved Wave3 method-name/body issues.
- 2026-06-08 A005 Batch124 parent-gate refresh:
  - Before: `88/80`, below the corrected confidence gate for [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md).
  - Changed to: `88/85`.
  - Summary/evidence: live IDA MCP reconfirmed exact `g_pPatchPane2` storage, all five singleton xrefs, PatchPane2 constructor/cleanup/destructor boundaries, the main-loop boundary, and the raw `0x00549020` caveat. This page is now a justified direct file parent for the module-global singleton, while broader folder/source-split uncertainty keeps confidence capped at 85.
- 2026-06-17 B003 source-quality reanalysis:
  - Before: `COMPLETION:88`, `CONFIDENCE:85`; the page still treated the possible `PatchPane2.cpp` companion as a confidence cap for current routing.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`.
  - Summary/evidence: B003 confirmed `patch/PatchPane.cpp` as the current route for both classes, with a companion `PatchPane2.cpp` left only as a later migration choice. Evidence includes the contiguous executable island, shared vtable/read-only data neighborhood, patcher/update literals, common Application startup construction, `g_pPatchPane2` lifecycle, and PatchPane/PatchPane2 child ownership.
- 2026-06-18 B003 PatchFileSlice source-quality execution: recorded that [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md) and [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md) should use [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) as direct semantic owner while keeping this file as emitter, and that `0x00548430-0x005484db` is compiler-generated deleting-destructor output from the nested virtual destructor.
- 2026-06-27 B008 PatchPane packet-response implementation:
  - Score unchanged at `89/88`.
  - Recorded that [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) should now emit through this file route as first-draft `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)` C++ after validator refresh. Current generated empty-marker or stale-score state is a generated-output lag, not evidence against the file route.
- 2026-06-27 B009 PatchPane2 main-loop implementation:
  - Score unchanged at `89/88`.
  - Recorded that [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) now emits through this file route as first-draft `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)` C++. The optional `PatchPane2.cpp` companion split remains a later migration choice, not a current owner/emitter or C++ blocker.
- 2026-07-01 B011 empty-emitter implementation:
  - Before: `COMPLETION:89`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:90`, `CONFIDENCE:89`.
  - Summary/evidence: implemented the accepted first batch for nine generated empty markers while preserving source route `NexusTK/patch/PatchPane.cpp`. [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) now has formal first-draft `PatchPane2::SendDownloadRequest()` C++; [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) now emits `PatchPane2 *g_pPatchPane2 = 0;`; [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md), [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md), [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md), [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md), [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md), [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md), and [UID:000264][0x00621db8-0x00622030.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md) now have formal covered-by/no-standalone-data comments. The stale singleton initializer wording is corrected to zero/null. [UID:0000A9][PatchPane](by-class/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md), and [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) remain explicitly excluded from this callback.
- 2026-07-04 B010 [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) support sync:
  - Score unchanged at `90/89`.
  - Summary/evidence: clarified that UID0001EX is already represented in generated `PatchPane.cpp` by the covered-by comment and should not be listed as an active helper that must be restored before migration. MCP session `nexustk_supervisor_20260704` reconfirmed the zero-xref/no-caller state and duplicate inline UID0001EV completed-download behavior; `0x005dfd3b` is now documented by the target as a remove/delete helper through `_wremove`.
- 2026-08-25 B006 UID0003OC implementation callback:
  - Score unchanged at `92/94`; source route remains `NexusTK/patch/PatchPane.cpp`.
  - Summary/evidence: removed the active UID0000AB producer/allocation deferral, fixed nested declaration order as complete `PatchFileSlice` before `PatchFileData`, recorded UID0001ER's standard `new[]` producer and UID0000AB's `delete[]` ownership, and retained UID0003OC as compiler-covered output with no handwritten scalar helper.
