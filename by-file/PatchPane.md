*** UID:0000MH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/patch/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PatchPane

## Status

- Proposed module: `patch/PatchPane.cpp` or original flat `PatchPane.cpp`
- Proposed header: `patch/PatchPane.h`
- Confidence: strong for patcher/update responsibility, singleton ownership, and patch-pane island boundaries; medium for final folder and `PatchPane`/`PatchPane2` source split.
- Current generated sources: `class_PatchPane.cpp`, `class_PatchPane2.cpp`, `class_PatchPane__PatchFileData.cpp`, `class_PatchPane__PatchFileSlice.cpp`

## File Role

`PatchPane.cpp` likely owned the startup patch/update UI and patch download flow. The module builds the `Auto Patch` dialog, exchanges opcode `0x48` patch packets, writes `Patch/Script` and `Patch/Info`, parses `get` rules, optionally launches `patcher.exe`, and runs the newer file-download patch dialog through `PatchPane2`.

This should stay separate from [UID:0000MF][ParcelPane](by-file/ParcelPane.md). IDA MCP confirms `PatchPane` begins at `0x005470b0`, immediately after the parcel notification cluster. It should also stay separate from [UID:0000HG][Application](by-file/Application.md), which triggers startup patch decisions but should not own the patch dialog implementation.

## Proposed Contents

| Entity | Current range | Current generated owner | Proposed ownership |
| --- | --- | --- | --- |
| [UID:0000A9][PatchPane](by-class/PatchPane.md) | `0x005470b0-0x00548560` plus helper/thunk gaps | `class_PatchPane.cpp` | `PatchPane.cpp` |
| [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) | `0x005483a0-0x005484f0` | `class_PatchPane__PatchFileSlice.cpp` partially | `PatchPane.cpp` nested helper |
| [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) | `0x00548500-0x00548554` | `class_PatchPane__PatchFileData.cpp` | `PatchPane.cpp` nested helper |
| [UID:0000AA][PatchPane2](by-class/PatchPane2.md) | `0x00548690-0x0054940e` | `class_PatchPane2.cpp` | `PatchPane.cpp` or `PatchPane2.cpp` companion |
| [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) | `0x0069ba2c` | `class_PatchPane2.cpp` | `PatchPane.cpp` module global |

## Evidence

- IDA MCP confirms the patch-pane function island from `0x005470b0` through `0x0054940f`; the next function at `0x00549410` is unrelated image/decoder-style code.
- IDA MCP confirms omitted but real vtable/callback bodies at [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md), [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md), and [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md). The `PatchPane` packet-response handler is the secondary-vtable callback at `0x00621e3c`; 2026-06-01 IDA MCP confirms its exact range, no direct code callers, subtype `0/1/2` behavior, and adjacent `0xcc` alignment gaps. The `PatchPane2` main loop and predicate are the paired secondary work-event callback slots at `0x00621fb8` and `0x00621fb4`; the same pass confirms their exact ranges, no direct code callers, subtype `0-4` behavior, generated switch-table data at `0x00548f1c-0x00548f30`, and predicate test `event+4 == 0x16`.
- Constructor callers for `PatchPane` and `PatchPane2` both come from the same application startup function at `0x004f6d80`.
- `PatchPane::PatchPane` constructs [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) at `0x005472d7` for the `Auto Patch` progress UI; progress-bar implementation remains generic `ui/controls` code.
- `PatchPane` uses `Auto Patch`, `Patch/Script`, `Patch/Info`, `patcher.exe`, `runas`, `getpatcher`, `get`, opcode `0x48`, and language ids `0xaf`, `0xb1`, and `0xae`.
- `PatchPane2` uses `g_pPatchPane2`, `g_patchDownloadUrl`, `g_patcherExePath`, a vector of patch filenames, and download requests through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).
- 2026-06-01 IDA MCP confirms generated `0x00549020` is not an IDA-modeled function, but disassembly/bytes show a real raw [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) helper between `FinishAndExit` and the close/rename helper; keep it documented separately from [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md).
- `PatchFileData` and `PatchFileSlice` are nested support types whose vtables are referenced from the PatchPane range.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary/secondary/tertiary vtables for both `PatchPane` and `PatchPane2`, plus the nested `PatchFileData` / `PatchFileSlice` vtables. Current generated metadata reports `vtable_count: 0`, so IDA vtable evidence should take precedence.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) pins the `PatchPane2` tail fields from `+0x26c` through `+0x290`, including final/temp patcher paths, the filename vector, active `FILE*`, retry/index counters, and request version components.

## 2026-06-08 Batch124 Parent-Gate Review

This file is the direct source parent for the module-global [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md). Live IDA MCP rechecked the exact singleton storage and owner neighborhood against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`):

- `0x0069ba2c` remains `dword_69BA2C`, a 4-byte `.data` item initialized to `0xffffffff`.
- `xrefs_to 0x0069ba2c` reports the `PatchPane2` constructor publish/clear pair at `0x005486f4` and `0x005486fb`, the raw cleanup/body reference at `0x00548a6d`, the compact clear helper at `0x00549340`, and the scalar deleting destructor clear at `0x005493d0`.
- `lookup_funcs` confirms the current owner-side boundaries: constructor `0x00548690` size `0x376`, main loop `0x00548a80` size `0x49a`, clear helper `0x00549340` size `0x0b`, scalar deleting destructor `0x00549370` size `0x9f`, and raw `0x00549020` still not an IDA function.

This evidence raises confidence for file-level ownership to the corrected parent gate. The score is capped at `88/85` because the exact original folder and whether `PatchPane2` had a companion `.cpp` remain source-layout questions, but the singleton belongs to this patch/update module rather than `Application`, `ParcelPane`, or `MiscWorkThread`.

## Source-Structure Decision

Use `patch/PatchPane.cpp` as the current source-layout hypothesis. `PatchPane2` may have been a separate `PatchPane2.cpp` in the original project, but it is part of the same updater subsystem and should be migrated as a companion, not left as an unrelated UI dialog.

The top-level folder could also be `app/` if the original project was flatter. A distinct `patch/` folder is clearer for reconstruction because it separates updater code from general application shell and login UI.

## Migration Notes

- Restore or attach `0x005474f0`, `0x005483a0`, `0x00548410`, `0x005484db`, `0x005484e6`, `0x00548a80`, `0x00548f30`, `0x00549080`, and `0x00549340` before source migration.
- Reconcile Wave3 `PatchPane2::AdvancePatchStep` at `0x00549020`; IDA reports no function there and instead confirms helper logic in `0x00548a80` plus real starts at `0x00549080` and `0x00549220`.
- Treat `0x005484db-0x005484f0` and `0x0054934b-0x00549360` as compiler-generated destructor adjustor thunks. They should be documented and ignored, not rewritten as handwritten patcher methods.
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
- [UID:0001EU][0x005484db-0x005484f0.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md)
- [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md)
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md)
- [UID:0001F0][0x0054934b-0x00549360.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md)
- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Summary/evidence: the page documents patch/update responsibility, class/helper/global ownership, IDA evidence, vtable/layout types, source-structure decision, migration cautions, and cross-references; confidence remains capped by final folder choice and unresolved Wave3 method-name/body issues.
- 2026-06-08 A005 Batch124 parent-gate refresh:
  - Before: `88/80`, below the corrected confidence gate for [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md).
  - Changed to: `88/85`.
  - Summary/evidence: live IDA MCP reconfirmed exact `g_pPatchPane2` storage, all five singleton xrefs, PatchPane2 constructor/cleanup/destructor boundaries, the main-loop boundary, and the raw `0x00549020` caveat. This page is now a justified direct file parent for the module-global singleton, while broader folder/source-split uncertainty keeps confidence capped at 85.
