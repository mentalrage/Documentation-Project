*** UID:0000A9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PatchPane

## Status

- Confidence: strong for updater dialog responsibility, packet callback ownership, method island boundaries, source placement, and generated-name pollution rejection; medium-high for final helper and field names.
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
| `0x005474f0-0x00547850` | [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) | `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)` handles opcode-like `0x40` patch responses, allocates entry slices, appends received data, updates progress, drives pending requests, and now has first-draft C++ in the child page. |
| `0x00547860-0x00547946` | `HandlePatchAction` | On timer/event, writes completed patch data, parses script rules, sends next script request, or launches patcher. |
| `0x00547950-0x00547978` | `OnPatchStatusChanged` | Displays localized patch failure/status alert when event code `2` arrives. |
| `0x00547980-0x00547a58` | `ShowPatchAlertAndExit` | Shows alert, sends close packet, closes dialog/session, and exits the application. |
| `0x00547a60-0x00547b6f` | `SendPatchScriptRequest` | Sends opcode `0x48/0` with script path and resets current patch-entry storage. |
| `0x00547b70-0x00547cdd` | `SendPendingPatchEntryRequests` | Keeps up to four patch entry downloads in flight using opcode `0x48/1`. |
| `0x00547e10-0x00547f31` | `WritePatchDataFile` | Writes all received patch entry buffers to the requested output path. |
| `0x00547f40-0x0054825f` | `ParsePatchScriptGetRules` | Reads `Patch/<source>`, validates printable lines, extracts `get`/`getpatcher` rules, and rewrites the script. |
| `0x00548270-0x0054839e` | `LaunchPatcherProcess` | Writes `Patch/Info`, ShellExecs `patcher.exe` with `runas`, and exits through a localized alert. |
| `0x005484db-0x005484f1` | [UID:0001EU][0x005484db-0x005484f1.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary vtable thunks forwarding to `0x00548560`; document and ignore for handwritten source. |
| `0x00548560-0x00548684` | scalar deleting destructor | Sends close packet, releases patch-entry storage, resets nested `PatchFileData`, destroys base, and optionally deletes. |

## Nested Helpers

- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) stores one downloaded patch entry buffer.
- [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md) is an embedded `PatchFileData m_patchFileData` object beginning at `PatchPane+0x26c`. Its `0x20c`-byte layout contains the nested vptr at `+0x0`, `m_currentPatchName[256]` at `+0x4`, `m_patchEntryCount` at `+0x204`, and `m_patchEntrySlices` at `+0x208`; those nested offsets correspond to outer offsets `+0x26c`, `+0x270`, `+0x470`, and `+0x474`.
- Constructor/destructor vptr writes and the adjacent `PatchFileData` RTTI identify composition rather than another `PatchPane` base. The packet-response handler allocates `m_patchFileData.m_patchEntrySlices` as `new PatchFileSlice[count]`, and the nested virtual destructor releases that storage with `delete[]`.

## Evidence Notes

- IDA MCP confirms `0x005470b0` is the first patch function after the parcel pane cluster and confirms all listed starts.
- `PatchPane::PatchPane` is called from the application startup/patch decision function at `0x004f6d80`.
- `0x005474f0` is a real IDA function and central packet response handler with vtable data xref `0x00621e3c`. 2026-06-27 B008 source-quality implementation confirms it as `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)`, with payload read from raw `event+0x0c`, subtype `0/1/2` packet handling, secondary-this owner normalization, adjacent `0xcc` padding at `0x005474e6-0x005474f0` and `0x00547850-0x00547860`, corrected `PacketBufferReadUInt32BE` / big-endian dword reads, and formal first-draft C++ in [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md).
- `0x005483a0` and `0x00548410` are the source-authored [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) constructor and non-deleting destructor. They now use the nested class as direct semantic owner, emit through [UID:0000MH][PatchPane](by-file/PatchPane.md), and carry first-draft C++. The adjacent `0x00548430-0x005484db` vector/scalar deleting destructor is compiler-generated output from `virtual ~PatchFileSlice()` and should be documented/ignored rather than emitted as handwritten source.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary vtable at `0x00621dcc`, the secondary vtable at `0x00621e2c`, and the tertiary vtable at `0x00621e5c`. Current generated metadata reports `vtable_count: 0`, so use the IDA-backed vtable doc for inheritance/callback reconstruction.
- 2026-06-14 C001 IDA MCP session `b001_0003gy` reconfirmed the method island and sizes from `0x005470b0` through `0x00548560`, including constructor `0x33d`, destructor `0xf6`, packet callback `0x360`, action/status/alert helpers, script request/pending-entry request helpers, write/parse/launch helpers, `PatchFileSlice` helpers at `0x005483a0` and `0x00548410`, and scalar deleting destructor `0x125`.
- `analyze_component` shows the patch action helper at `0x00547860` calling `WritePatchDataFile`, `SendPatchScriptRequest`, `ShowPatchAlertAndExit`, `LaunchPatcherProcess`, and `ParsePatchScriptGetRules`; it also records the `getpatcher`/`get` script-parser strings and the `runas`/`patcher.exe` launch strings.
- `xrefs_to 0x005470b0` shows a single constructor caller at `0x004f7370` inside the application startup patch-decision function. `xrefs_to 0x005474f0` shows only the secondary-vtable data reference at `0x00621e3c`, matching callback-dispatch ownership rather than a normal direct call.
- `xrefs_to` for `0x00621dcc`, `0x00621e2c`, and `0x00621e5c` shows each `PatchPane` vtable head written or referenced from constructor, destructor, and scalar deleting destructor. The adjustor thunk pair at `0x005484db`/`0x005484e6` forwards to scalar deleting destructor `0x00548560`, so it remains compiler-generated support.
- `entity_query(kind=names)` places `??_7PatchFileData@PatchPane@@6B@` immediately before the three `PatchPane` vtable heads and `aAutoPatch` immediately after, supporting the current nested-helper/source-family grouping.

## Resolved Source-Quality Notes

- Source placement: group `PatchPane2` with [UID:0000MH][PatchPane](by-file/PatchPane.md) under `patch/PatchPane.cpp`. A companion `PatchPane2.cpp` remains a possible migration shape, but the current source-quality evidence does not require it and it should not block PatchPane ownership or scoring.
- Best source-facing name for `0x005474f0`: `PatchPane::HandlePatchResponsePacket`. Evidence is the secondary-vtable slot at `0x00621e3c`, the leading `0x40` response gate, subtype `0/1/2` behavior, slice allocation/receipt, progress updates, and pending-entry request fan-out. Server packet dispatch is caller/interface context, not owner.
- Best current source-facing signature for `0x005474f0`: `bool PatchPane::HandlePatchResponsePacket(const PacketEvent *event)`. The packet payload pointer is loaded from raw `event+0x0c`, so the C++ should use `event->payload`; the method returns `true` for handled subtypes `0` and `1`, and `false` for marker mismatch, subtype `2` failure, or unsupported subtype.
- Best current field/helper directions for the handler are `m_patchFileData.m_currentPatchName` at `PatchPane+0x270`, `m_patchFileData.m_patchEntryCount` at `PatchPane+0x470`, `m_patchFileData.m_patchEntrySlices` at `PatchPane+0x474`, inherited `m_controlManager` at `PatchPane+0x1fc`, `PacketBufferReadUInt32BE` for count/index/length reads, `PatchPane::SendPendingPatchEntryRequests`, `PatchPane::ShowPatchAlertAndExit`, `ProgressBarControlPane::SetCurrentValue`, and an inferred TextEdit/StaticText-family `SetText` accessor for status control `0`.
- Generated base-destructor labels such as `TransferReplyAlert` and other polluted dialog names should be treated as generated-name contamination. Use the IDA-backed vtable, range, and child-method evidence for header/source reconstruction.
- B011 empty-emitter implementation keeps the [UID:0000A9] class-level formal body blank. The first batch removes duplicate/generated-data empty markers and emits child/global bodies, but it does not attempt a partial `PatchPane` class declaration because the full class declaration/API surface remains a later source-declaration pass.
- UID0003OC implementation keeps the [UID:0000A9] class-level formal body blank for the same full-class-declaration reason. The complete nested `PatchFileData` declaration is emitted in [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md), with `PatchFileSlice` ordered before it in the shared source route.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md)
- [UID:0001EU][0x005484db-0x005484f1.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md)
- [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md)
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md)
- [UID:00000D][Application](by-class/Application.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed dialog responsibility, packet handling, patch-file write/parse/launch methods, nested helper notes, and vtable evidence.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- 2026-06-01 update: raised to `COMPLETION:86`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, parent `[UID:0000MH][PatchPane](by-file/PatchPane.md)` after the packet-response handler gained exact IDA-backed boundary, vtable, touched-state, callee, and alignment evidence.
- Evidence: constructor/destructor, packet response handler, script request/parse/write helpers, pending-entry requests, patcher launch, scalar deleting destructor, nested storage helpers, vtable family, and open generated-source omissions are documented; confidence remains below final-source quality because helper names and active generated output are still incomplete.
- 2026-06-14 C001 refreshed low-confidence batch:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed the complete `PatchPane` method island through `0x00548560`, the single application startup constructor caller, secondary-vtable-only packet callback, action-helper internal call graph, script/launch strings, vtable-head xrefs, and nested helper adjacency. Confidence clears the strict gate, but final C++ remains blank because helper/field names, active generated omissions, and the `PatchPane`/`PatchPane2` source split are not source-quality complete.
- 2026-06-17 B003 source-quality reanalysis:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`, with open questions about PatchPane2 source placement, the packet-response handler name, and generated-name pollution.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`.
  - Summary/evidence: B003 resolved the source placement to `patch/PatchPane.cpp` for current routing, named `0x005474f0` as `PatchPane::HandlePatchResponsePacket`, rejected server-dispatch ownership and generated polluted destructor labels, and confirmed remaining field/API names belong to child-level C++ readiness rather than class ownership.
- 2026-06-18 B003 PatchFileSlice source-quality execution: updated the class evidence for [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) so `0x005483a0` and `0x00548410` are source-authored nested-class constructor/destructor bodies with first-draft C++, while `0x00548430-0x005484db` is compiler-generated deleting-destructor output from the virtual destructor declaration.
- 2026-06-27 B008 PatchPane packet-response implementation:
  - Score unchanged at `87/88`.
  - Synchronized [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) as formal first-draft C++ ready. The child page now records `PatchPane::HandlePatchResponsePacket(const PacketEvent *event)`, big-endian `PacketBufferReadUInt32BE` reads for entry count/index/length, source-facing field names for current patch name/count/slice array/control manager, status/progress control roles, and the remaining inferred-name/access caveats.
- 2026-07-01 B011 empty-emitter implementation:
  - Score unchanged at `87/88`.
  - Summary/evidence: support-only sync records that the [UID:0000A9] class-level formal body remains excluded from the first empty-emitter callback. Child/global emitters are handled through their own target pages; the full `PatchPane` class declaration remains a later class/API pass.
- 2026-08-25 B006 UID0003OC implementation callback:
  - Score unchanged at `87/88`.
  - Summary/evidence: synchronized the embedded `PatchFileData m_patchFileData` topology at outer `+0x26c`, its exact nested/outer field offsets, composition evidence, array producer and `delete[]` lifetime, and source-facing `m_patchFileData.*` field qualification. The class-level formal body remains blank while the complete nested class emits through [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md).
