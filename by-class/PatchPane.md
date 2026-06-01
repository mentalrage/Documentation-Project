*** UID:0000A9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane

## Status

- Confidence: strong for updater dialog responsibility, packet callback ownership, and method island boundaries; medium for final helper and field names.
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Current recovered file: `source-3/simroot_v2/class_PatchPane.cpp`
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Class Purpose

`PatchPane` is the original `Auto Patch` startup dialog. It requests patch scripts and patch entries from the server, writes received data into the `Patch` directory, parses script `get` rules, and either launches `patcher.exe` or asks the application to exit after displaying an alert.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x005470b0-0x005473ec` | `PatchPane::PatchPane` | Builds the `Auto Patch` dialog, copies the patch info blob, optionally launches the external patcher, and requests `%d/%d/Script`. |
| `0x005473f0-0x005474e5` | `~PatchPane` | Sends patch close packet `0x48/2`, releases patch entries, and chains to dialog/base teardown. |
| `0x005474f0-0x00547850` | [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) | Handles opcode-like `0x40` patch responses, allocates entry slices, appends received data, updates progress, and drives pending requests. Not emitted in active `class_PatchPane.cpp`. |
| `0x00547860-0x00547946` | `HandlePatchAction` | On timer/event, writes completed patch data, parses script rules, sends next script request, or launches patcher. |
| `0x00547950-0x00547978` | `OnPatchStatusChanged` | Displays localized patch failure/status alert when event code `2` arrives. |
| `0x00547980-0x00547a58` | `ShowPatchAlertAndExit` | Shows alert, sends close packet, closes dialog/session, and exits the application. |
| `0x00547a60-0x00547b6f` | `SendPatchScriptRequest` | Sends opcode `0x48/0` with script path and resets current patch-entry storage. |
| `0x00547b70-0x00547cdd` | `SendPendingPatchEntryRequests` | Keeps up to four patch entry downloads in flight using opcode `0x48/1`. |
| `0x00547e10-0x00547f31` | `WritePatchDataFile` | Writes all received patch entry buffers to the requested output path. |
| `0x00547f40-0x0054825f` | `ParsePatchScriptGetRules` | Reads `Patch/<source>`, validates printable lines, extracts `get`/`getpatcher` rules, and rewrites the script. |
| `0x00548270-0x0054839e` | `LaunchPatcherProcess` | Writes `Patch/Info`, ShellExecs `patcher.exe` with `runas`, and exits through a localized alert. |
| `0x005484db-0x005484f0` | [UID:0001EU][0x005484db-0x005484f0.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary vtable thunks forwarding to `0x00548560`; document and ignore for handwritten source. |
| `0x00548560-0x00548684` | scalar deleting destructor | Sends close packet, releases patch-entry storage, resets nested `PatchFileData`, destroys base, and optionally deletes. |

## Nested Helpers

- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) stores one downloaded patch entry buffer.
- [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) owns backing storage for received patch data.

## Evidence Notes

- IDA MCP confirms `0x005470b0` is the first patch function after the parcel pane cluster and confirms all listed starts.
- `PatchPane::PatchPane` is called from the application startup/patch decision function at `0x004f6d80`.
- `0x005474f0` is a real IDA function and central packet response handler with vtable data xref `0x00621e3c`, but active generated source omits it from `class_PatchPane.cpp`. 2026-06-01 IDA MCP confirms the exact `0x005474f0-0x00547850` range, no direct code callers, subtype `0/1/2` packet handling, secondary-this owner normalization, and adjacent `0xcc` padding at `0x005474e6-0x005474f0` and `0x00547850-0x00547860`.
- `0x005483a0` and `0x00548410` are constructor/destructor helpers for `PatchPane::PatchFileSlice`; active Wave3 only emits the vector deleting destructor.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary vtable at `0x00621dcc`, the secondary vtable at `0x00621e2c`, and the tertiary vtable at `0x00621e5c`. Current generated metadata reports `vtable_count: 0`, so use the IDA-backed vtable doc for inheritance/callback reconstruction.

## Open Questions

- Decide whether `PatchPane2` should stay in the same original source file or become a companion `PatchPane2.cpp`.
- Name the `0x005474f0` packet response handler after reviewing server packet dispatch callers.
- Reconcile generated base-destructor labels such as `TransferReplyAlert` and other polluted dialog names before header emission.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md)
- [UID:0001EU][0x005484db-0x005484f0.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md)
- [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md)
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md)
- [UID:00000D][Application](by-class/Application.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed dialog responsibility, packet handling, patch-file write/parse/launch methods, nested helper notes, and vtable evidence.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- 2026-06-01 update: raised to `COMPLETION:86`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, parent `[UID:0000MH][PatchPane](by-file/PatchPane.md)` after the packet-response handler gained exact IDA-backed boundary, vtable, touched-state, callee, and alignment evidence.
- Evidence: constructor/destructor, packet response handler, script request/parse/write helpers, pending-entry requests, patcher launch, scalar deleting destructor, nested storage helpers, vtable family, and open generated-source omissions are documented; confidence remains below final-source quality because helper names and active generated output are still incomplete.
