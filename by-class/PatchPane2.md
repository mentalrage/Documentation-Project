*** UID:0000AA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WorkThreadNotification;

class PatchPane2 : public DialogPane, public Singleton<PatchPane2> {
public:
    explicit PatchPane2(const unsigned char *patchInfo);
    virtual ~PatchPane2();

    virtual bool AcceptsDownloadWorkEvent(const WorkThreadNotification *event);
    virtual bool HandleDownloadWorkEvent(const WorkThreadNotification *event);

private:
    void ClosePatchFile();
    void FinishAndExit(const wchar_t *message);
    void SendDownloadRequest();
    void ReportWriteError(const wchar_t *path);

    StringBase<wchar_t> m_finalPatchPath;
    StringBase<wchar_t> m_tempPatchPath;
    std::vector<StringBase<wchar_t> > m_patchFileNames;
    unsigned int m_currentDownloadIndex;
    FILE *m_activePatchFile;
    unsigned int m_downloadPassCount;
    unsigned int m_patchVersionMajor;
    unsigned int m_patchVersionMinor;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PatchPane2

## Status

- Confidence: source-ready for the alternate patch download dialog, its inheritance, complete tail layout, callback ownership, helper split, compiler-only artifacts, and `PatchPane.cpp` placement.
- Source file: [UID:0000MH][PatchPane](by-file/PatchPane.md). The former optional-companion-file hypothesis is superseded by the complete contiguous `PatchPane` / `PatchPane2` source-family evidence.
- Current recovered file: `source-3/simroot_v2/class_PatchPane2.cpp`
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- Reconstructable: yes. The managed block now emits the evidence-backed human class declaration, with direct `DialogPane` and EBO `Singleton<PatchPane2>` inheritance, four source methods, four private helpers, and the exact `+0x26c-+0x290` tail fields. Compiler-only scalar deletion, adjustor thunks, EH cleanup, and vtable data remain intentionally outside handwritten class source.

## Class Purpose

`PatchPane2` is the newer or alternate patch download dialog. It parses a packed patch-data buffer, builds a simple status/count/cancel dialog, keeps a vector of file names, downloads files through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), writes temporary files, renames them into place, and exits through a shared completion/error path.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00548690-0x00548a06` | [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md) | Builds the dialog, sets [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md), parses version/file list, stores base URL/path strings, and sends the first request. |
| `0x00548a10-0x00548a7d` | [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md) | Ordinary source destructor: closes an active patch file, destroys vector/string members, clears the singleton, and chains through the bases without scalar-delete mechanics. |
| `0x00548a80-0x00548f1a` | [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) | Source-ready `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)`; handles HTTP work-thread events, opens output file, writes chunks, closes/renames files, advances files/passes, launches `patcher.exe`, and handles errors. |
| `0x00548f30-0x00548f41` | [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md) | Returns true when event field `+4` is `22`. |
| `0x00548f50-0x00548f72` | [UID:0004VU][0x00548f50-0x00548f72.PatchPane2ClosePatchFile](by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md) | Closes the active `FILE*` and clears the member. |
| `0x00548f80-0x0054901f` | [UID:0004VV][0x00548f80-0x0054901f.PatchPane2FinishAndExit](by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md) | Optionally shows an alert, closes dialog, cleans main-menu/session state, and requests application exit. |
| `0x00549020-0x00549080` | [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) | Raw unmodeled helper-shaped body that advances file index/pass counter or exits after the retry threshold; B011 keeps it as a formal covered-by comment because [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) emits the source-level logic. |
| `0x00549080-0x00549214` | [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) | Closes the active file, converts wide paths, removes/deletes the target, renames temp to final, and throws `Win32Error` on failure; keep it as a formal covered-by comment because [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) emits the inline completed-download source path and current MCP still reports no direct xrefs/callers for this helper. |
| `0x00549220-0x005492cf` | [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) | Source-ready `PatchPane2::SendDownloadRequest()`; formats the request suffix with `m_patchVersionMajor` / `m_patchVersionMinor` (`+0x28c/+0x290`) and `m_finalPatchPath`, calls [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) as a [UID:0000OA][StringBase](by-file/StringBase.md)-owned wide `operator+` / two-StringBase concatenation helper for the selected download vector entry, and queues a `MiscWorkThread::RequestHTTPGet` / `GetHttp` work item. |
| `0x005492d0-0x00549339` | [UID:0004VW][0x005492d0-0x00549339.PatchPane2ReportWriteError](by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md) | Formats `Error writing %s` and exits through `FinishAndExit`; older `0x00549338` prose was an inclusive/stale endpoint, while live MCP reports the half-open function range ending at `0x00549339`. |
| `0x00549340-0x0054934b` | [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) | Constructor-EH cleanup helper that clears `g_pPatchPane2`; document but do not emit as a PatchPane2 source method. |
| `0x0054934b-0x00549361` | [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md) | Compiler-generated secondary/tertiary vtable thunks forwarding to `0x00549370`; document and ignore for handwritten source. |
| `0x00549370-0x0054940f` | [UID:0004VX][0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor](by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md) | Compiler wrapper over the ordinary destructor plus conditional `operator delete`; it has no handwritten source body. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- Generated metadata says `0x00548a80` is the main patching loop and marks it excluded, matching IDA decompilation. 2026-06-01 IDA MCP confirms it as `sub_548A80` with exact range `0x00548a80-0x00548f1a`, a single vtable xref at `0x00621fb8`, no direct code callers, subtype `0-4` work-event dispatch, touched owner fields at `+0x26c/+0x270/+0x274/+0x280/+0x284/+0x288`, and generated switch-table data at `0x00548f1c-0x00548f30`.
- `0x00548f30` is the paired work-event predicate slot at `0x00621fb4`; 2026-06-01 IDA MCP confirms the complete seven-instruction helper returns whether byte `event+4` equals `0x16`, with no direct callers, no callees, and `0xcc` alignment at `0x00548f41-0x00548f50`.
- IDA MCP reports no modeled function and no xrefs at generated `PatchPane2::AdvancePatchStep` start `0x00549020`, but 2026-06-01 disassembly/byte review confirms a real unmodeled helper-shaped body at [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md). IDA modeled helper starts remain `0x00549080` and `0x00549220`.
- `0x00549080` is the close/delete/rename helper: 2026-06-01 IDA MCP confirms exact range `0x00549080-0x00549214`, owner fields `+0x26c/+0x270/+0x284`, no direct callers, duplicate inline behavior in the main loop subtype `2`, Win32Error throw paths, and `0xcc` padding at `0x00549214-0x00549220`.
- B010 2026-07-04 MCP session `nexustk_supervisor_20260704` reconfirms [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) as modeled `sub_549080`, size `0x194`, with zero `xrefs_to` and no `analyze_function` callers. The same session confirms [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) completed-download `case 2` performs `fclose`, the remove/delete helper, `_rename`, and `__errno` inline without referencing `0x00549080`; helper `0x005dfd3b` decompiles as a narrow-path wrapper through `__acrt_copy_path_to_wide_string`, `_wremove`, and `_free_base`. This resolves UID0001EX to a covered-by/no-active-body method note rather than a pending standalone C++ blocker.
- Constructor caller evidence points back to the same application startup patch decision function that constructs `PatchPane`.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the primary vtable at `0x00621f40`, the secondary work-event vtable at `0x00621fa0`, and the tertiary vtable at `0x00621fd0`. Generated metadata currently reports `vtable_count: 0` and should not be trusted for polymorphism.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) documents the IDA-backed tail fields at `+0x26c-+0x290`, including the final/temp patcher paths, filename vector, active `FILE*`, index/retry counters, and version components. B011 names the two version words `m_patchVersionMajor` and `m_patchVersionMinor` for the accepted `SendDownloadRequest` first-draft body; these are source-facing inferred names, not recovered original private spellings.
- 2026-06-08 Batch124 live IDA MCP reconfirms the singleton side of this class: `0x0069ba2c` is a 4-byte `.data` slot now documented as zero/null (`00 00 00 00` / `0`), with older `0xffffffff` wording superseded by B003/B011 zero-fill checks. Xrefs include constructor writes/clears at `0x005486f4` and `0x005486fb`, raw cleanup/body reference at `0x00548a6d`, singleton clear helper write at `0x00549340`, and scalar deleting destructor clear at `0x005493d0`. Function lookup also reconfirms constructor `0x00548690` size `0x376`, main loop `0x00548a80` size `0x49a`, clear helper `0x00549340` size `0x0b`, destructor `0x00549370` size `0x9f`, and raw `0x00549020` not being an IDA function.
- B009 2026-06-27 source-ready implementation pass resolves the main loop as `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)` with formal C++ on [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md). MCP session `398b87c1` reconfirmed the secondary-vtable route `0x00621fb8 -> 0x00548a80`, paired predicate route `0x00621fb4 -> 0x00548f30`, no direct code callers, state `0-4` HTTP notification behavior, and owner-relative tail-field map at `+0x26c-+0x290`. Its old `m_statusControls` label at `+0x1fc` is superseded: `+0x1fc` belongs to inherited `DialogPane` child-management state, and source uses `GetChild<StaticTextControlPane>(0/1)` rather than a PatchPane2 data member.

## Resolved Source-Quality Notes

- `0x00548a80` is correctly owned by [UID:0000AA][PatchPane2](by-class/PatchPane2.md) as a secondary-vtable callback. Best source-facing name: `PatchPane2::HandleDownloadWorkEvent`; [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) now carries formal first-draft C++. Vtable-only reachability through `0x00621fb8` is expected for this callback and should not be treated as dead code.
- `0x00549020` is not a modeled or source-bearing function and must not be trusted as a Wave3 method row. [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) is retained as exact raw machine evidence covered by the main-loop case-3 source. IDA and PE scans find no function object, xref, absolute/RVA hit, or relative branch target, so no independent handwritten declaration/body is emitted.
- `0x00549080` should not be emitted as an active `PatchPane2::CloseAndRenameDownloadedFile()` body from this class page. Current MCP shows a real modeled helper but no live caller, while [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) already emits the source-level close/delete/rename behavior inline. Keep [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) as reconstructable PatchPane2 evidence with a covered-by formal comment.
- `0x00548f30` is the paired secondary-vtable predicate at `0x00621fb4`. Best source-facing name: `PatchPane2::AcceptsDownloadWorkEvent` or `PatchPane2::IsDownloadWorkEvent`. It is not a generic static/file-local helper because it is installed in the `+0xa0` callback subobject vtable.
- B011 promoted [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) after resolving its call sites, StringBase concatenation callee, and `RequestHTTPGet` wrapper. The later UID0002ZP callback supersedes B011's then-valid blank-class disposition: inheritance, callback declarations, field types, source order, and full layout are now resolved and emitted here.

## UID0002ZP Callback Closure

- RTTI and vtable evidence establish `PatchPane2 : public DialogPane, public Singleton<PatchPane2>`. The singleton PMD is `+0x26c`; this is an empty-base location, not a stored singleton pointer or vptr field.
- The complete object size is `0x294`. The `DialogPane` subobject and EBO singleton occupy the prefix through `+0x26c`; source-owned members are `StringBase<wchar_t>` final/temp paths at `+0x26c/+0x270`, a three-pointer `std::vector<StringBase<wchar_t> >` at `+0x274/+0x278/+0x27c`, `unsigned int` index at `+0x280`, `FILE *` at `+0x284`, and three `unsigned int` values at `+0x288/+0x28c/+0x290` for pass count and major/minor version.
- The generated `this+0x1fc` accesses are inherited `DialogPane` child storage. Constructor resources establish child indices `0` and `1` as `StaticTextControlPane`; source-clean callbacks therefore use `GetChild<StaticTextControlPane>(0/1)`. The historical synthetic `m_statusControls` field is rejected because it duplicates inherited state and would corrupt the proven tail layout.
- Source order is the global slot, class declaration, constructor, ordinary destructor, main callback, predicate, close helper, finish helper, raw covered evidence, completed-download covered evidence, request helper, write-error helper, constructor-EH cleanup, adjustor thunks, and scalar deleting wrapper. Only source-authored items receive declarations or method bodies.
- Negative evidence excludes an independent `PatchPane2.cpp`, a stored singleton field, a PatchPane2-owned child-manager field, an active raw helper, an active duplicate rename helper, handwritten EH cleanup, handwritten adjustor thunks, handwritten scalar deletion, and explicit vptr/delete-flag/cookie/decompiler mechanics.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md)
- [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md)
- [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md)
- [UID:0004VU][0x00548f50-0x00548f72.PatchPane2ClosePatchFile](by-memory/0x00548f50-0x00548f72.PatchPane2ClosePatchFile.md)
- [UID:0004VV][0x00548f80-0x0054901f.PatchPane2FinishAndExit](by-memory/0x00548f80-0x0054901f.PatchPane2FinishAndExit.md)
- [UID:0004VW][0x005492d0-0x00549339.PatchPane2ReportWriteError](by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md)
- [UID:0004VX][0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor](by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md)
- [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md)
- [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md)
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md)
- [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md)
- [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)

## UID0002ZP Implementation Callback

- 2026-07-21: raised only this class support page from `87/88` to `92/94`, assigned source position `20`, and installed the accepted complete managed declaration. The callback preserves every earlier range, vtable, helper, singleton, and source-quality observation while resolving the former blank-class and optional-companion hypotheses.
- All six newly split source/compiler rows use validator-issued UIDs `0004VS`, `0004VT`, `0004VU`, `0004VV`, `0004VW`, and `0004VX`; no provisional token or guessed UID remains.

## Changes

- 2026-05-31 reconstructable metadata repair:
  - What existed before: the class page was documented and listed as reconstructable in coverage, but validator metadata still had blank `RECONSTRUCTABLE`.
  - What it was changed to: set `RECONSTRUCTABLE:TRUE` so child layout/type docs can attach to the class without validator parent-ineligible errors.
  - Summary/evidence: IDA MCP and existing page evidence confirm `PatchPane2` is NexusTK-owned patch/update UI code; C++ remains blank because final source shape and method names are not audit-complete.

- Before: completion/confidence metadata were `0/0` even though the page already documented the alternate patch dialog, main loop, work-thread helpers, file close/rename/send/error helpers, singleton, vtables, layout, and open issues.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- 2026-06-01 update: raised to `COMPLETION:86`, `CONFIDENCE:82` after the main loop gained exact IDA-backed range, vtable, event-state, touched-field, callee, and switch-table evidence.
- Evidence: constructor, excluded main loop, work-event predicate, close/finish/rename/request/error helpers, scalar deleting destructor, `g_pPatchPane2`, `g_pMiscWorkThread`, vtable family, and layout doc are recorded; confidence remains below final-source quality because active generated output omits the core main loop and has a false `0x00549020` row.
- 2026-06-08 A005 Batch124 parent-gate refresh:
  - Before: `86/82`.
  - Changed to: `86/85`.
  - Summary/evidence: live IDA MCP reconfirmed the `g_pPatchPane2` lifecycle xrefs, constructor/main-loop/clear-helper/destructor boundaries, and raw `0x00549020` non-function caveat. Confidence now clears the corrected gate for class-owned PatchPane2 helper children; final C++ remains below threshold because several source names and the `PatchPane.cpp` versus companion-file split are still provisional.
- 2026-06-17 B003 source-quality reanalysis:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`, with open questions about main-loop ownership, raw `0x00549020`, and predicate source form.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`.
  - Summary/evidence: B003 resolved `0x00548a80` as `PatchPane2::HandleDownloadWorkEvent`, `0x00548f30` as a secondary-vtable predicate (`AcceptsDownloadWorkEvent` / `IsDownloadWorkEvent`), and `0x00549020` as an exact raw no-entry child, while keeping formal C++ blocked until event/string/file helper APIs and raw-entry liveness are settled.
- 2026-06-17 B003 helper follow-up executed by supervisor:
  - Score unchanged at `87/88`; method notes now record [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) as the `GetHttp` request producer and [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) as non-emitting constructor-EH cleanup.
  - Summary/evidence: live IDA reanalysis confirmed `0x00549220` field/path/vector/MiscWorkThread queue evidence and `0x00549340` single constructor-unwind xref at `0x00605eb1`.
- 2026-06-26 B010 [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) source-owner correction:
  - Score unchanged at `87/88`.
  - Summary/evidence: method notes now preserve [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) as a callee used by `PatchPane2::SendDownloadRequest`, but no longer imply that the concatenation body is PatchPane2-owned source. B010's accepted MCP-backed pass routes [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) to [UID:0000OA][StringBase](by-file/StringBase.md) as a wide two-StringBase `operator+` / concatenation helper; PatchPane2 remains the consumer and owner of request formatting, vector-index selection, and `g_pMiscWorkThread` queueing.
- 2026-06-27 B009 [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) source-ready implementation:
  - Score unchanged at `87/88`.
  - Summary/evidence: recorded [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) as formal first-draft `PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)` C++ through the existing PatchPane file route, preserved vtable-only reachability as expected callback evidence, added source-facing field names for the download-loop state, and corrected the write-error helper endpoint from stale inclusive-style `0x005492d0-0x00549338` to half-open `0x005492d0-0x00549339`.
- 2026-07-01 B011 empty-emitter implementation:
  - Score unchanged at `87/88`.
  - Summary/evidence: updated [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) as formal first-draft `PatchPane2::SendDownloadRequest()` C++, named `+0x28c/+0x290` as inferred `m_patchVersionMajor`/`m_patchVersionMinor`, corrected singleton storage wording to zero/null, and documented [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) and [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) as formal covered-by comments rather than active helper bodies. The [UID:0000AA] class body remains intentionally blank for this callback.
- 2026-07-04 B010 [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) source-quality callback:
  - Score unchanged at `87/88`.
  - Summary/evidence: refreshed the method/evidence notes with MCP session `nexustk_supervisor_20260704`, which reconfirmed `sub_549080` size `0x194`, zero direct xrefs/callers, exact `+0x26c/+0x270/+0x284` field flow, duplicate inline UID0001EV completed-download behavior, and `0x005dfd3b` as a remove/delete helper through `_wremove`. UID0001EX remains a covered-by no-active-body page, not a class-level method body blocker.
