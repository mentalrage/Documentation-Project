** TARGET-REPORT-UID:0001EV **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Research Report: [UID:0001EV] PatchPane2 Main Loop Source Quality

**TARGET_UID:** 0001EV  
**TARGET_PATH:** `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`  
**AGENT:** Agent-B009  
**REPORT_DATE:** 2026-06-27  
**ASSIGNMENT:** `B009-report-0001EV-PatchPane2MainLoop-source-quality-20260627`  
**MODE:** report-only research; no target/support by-* docs edited  
**MCP_SESSION:** `398b87c1` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`  
**MCP_STATUS:** live evidence pass completed; `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

## Executive Recommendation

[UID:0001EV] should remain owned and emitted by PatchPane2/PatchPane and should be promoted from a blank-C++ eligible target to a source-ready formal first-draft target.

Recommended target metadata:

```yaml
COMPLETION: 90
CONFIDENCE: 91
CANONICAL_OWNER: 0000AA
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000AA
EMITTER_POSITION_OPTIONAL:
```

Recommended source-facing function name:

```cpp
bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)
```

The existing owner/emitter route is correct. This routine is a PatchPane2 secondary-vtable work-event callback reached through data xref `0x00621fb8 -> 0x00548a80`, not a directly called free helper. It consumes HTTP work-thread notifications, mutates only PatchPane2 download/session fields, updates PatchPane2 UI controls, and calls PatchPane2 helpers. It should continue to emit through `[UID:0000AA] PatchPane2` into `NexusTK/patch/PatchPane.cpp`.

The primary blank-C++ blocker is resolved. Live MCP verified the exact function boundary, callback slot, switch table, notification state handling, field writes, file open/write/close/rename/error behavior, retry/pass logic, and localized exit paths. Remaining names are source-facing inferred names, not a reason to keep the formal C++ block blank under the current code-entry gate.

## Evidence Used

Live MCP evidence came from active session `398b87c1`:

- `idb_list`: active session `398b87c1`, filename `NexusTK.exe.i64`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status ok, module `NexusTK.exe`, imagebase `0x400000`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`:
  - `0x00548a80 -> sub_548A80`, size `0x49a` / 1178 bytes.
  - `0x00548f1a` and `0x00548f1c` are not function starts.
  - `0x00548f30 -> sub_548F30`, size `0x11`.
  - `0x00549020` is not a function.
  - `0x00549080 -> sub_549080`, size `0x194`.
  - `0x00549220 -> sub_549220`, size `0xaf`.
  - `0x005492d0 -> sub_5492D0`, size `0x69`; the half-open end is `0x00549339`, not `0x00549338`.
- `xrefs_to` / `xref_query`:
  - `0x00548a80` has no direct code callers and one data xref at `0x00621fb8`.
  - `0x00548f1c` is the switch table used by `0x00548ad9`.
  - `0x00548f30` has the paired secondary-vtable data xref at `0x00621fb4`.
  - `0x00549020` has zero xrefs and remains raw no-function code/data.
  - `0x00549080` has zero direct xrefs and remains modeled separately from the inlined main-loop close/rename logic.
  - `0x00549220` is called by the constructor at `0x005489e0` and by the main loop at `0x00548c71`, `0x00548c9b`, and `0x00548cc1`.
  - `0x005492d0` is called by the main loop at `0x00548b16` and `0x00548bc7`.
  - `0x00548f50` is called by the main loop at `0x00548c0d` and `0x00548c47`.
  - `0x00548f80` is called by the main loop at `0x00548c33`, `0x00548cba`, `0x00548e69`, raw body `0x00549079`, and `0x0054931a`.
- `analyze_function 0x00548a80`: decompiler prototype `char __thiscall(int this, int)`, no callers, data xref through `0x00621fb8`, 49 basic blocks, cyclomatic complexity 10, string refs `runas` and `patcher.exe`.
- `decompile 0x00548a80`: full state-machine proof for HTTP notification subtypes 0 through 4 and default return.
- `decompile 0x00548f50`: closes and clears PatchPane2 active `FILE *` at owner `+0x284`.
- `decompile 0x00548f80`: displays optional exit/error text, sleeps, and tears down dialog/session state.
- `decompile 0x005492d0`: formats `L"Error writing %s"` and calls the PatchPane2 finish/exit helper.
- `get_bytes`:
  - `0x00548a7d`: three bytes of `0xcc` padding before the target function.
  - `0x00548f1a`: `66 90` two-byte alignment after the target body, followed by the switch table at `0x00548f1c`.
  - `0x00549338`: final byte of `sub_5492D0`/alignment context; padding begins at `0x00549339`.
  - `0x0060df28`: bytes prove UTF-16LE `L"wb"` even though one string view showed narrow `"w"`.
- `get_int`:
  - secondary vtable slot `0x00621fb4 -> 0x00548f30`.
  - secondary vtable slot `0x00621fb8 -> 0x00548a80`.
  - jump table `0x00548f1c -> 0x00548ae0`, `0x00548f20 -> 0x00548b94`, `0x00548f24 -> 0x00548ccd`, `0x00548f28 -> 0x00548c3f`, `0x00548f2c -> 0x00548c07`.
- `search_text` / `find_regex`:
  - `Error writing %s` is UTF-16LE at `0x0062200c`, xref `0x005492fb`.
  - No original `PatchPane2::HandleDownloadWorkEvent`, `PatchPane.cpp`, or comparable source-method symbol string was recovered.
- `make_signature_for_range 0x00548a80-0x00548f1a`: unique signature was produced for the exact target range.
- `tools/int_convert.py` verified decimal/hex conversions used in this report, including `0x49a == 1178`, `0xa0 == 160`, `0x400 == 1024`, `0x0a == 10`, `0x9d == 157`, `0xae == 174`, and owner/secondary field offset conversions.

## Current Target State

The target already has the right high-level ownership:

- `CANONICAL_OWNER: 0000AA`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000AA`
- Current target score before implementation: `COMPLETION:86`, `CONFIDENCE:88`
- Current formal `RECONSTRUCTION_CPP` block: blank

The generated output state is stale/generated and must not be edited manually:

- `auto-generated/-ag-research-tracker.md` still reports the row with older `80/86` metadata and output count zero.
- `auto-generated/-ag-memory-coverage.md` reports owner/emitter `0000AA` and generated output `auto-generated/NexusTK/patch/PatchPane.cpp`, but marks code as absent.
- `auto-generated/NexusTK/patch/PatchPane.cpp` currently contains an `Empty Emitter Marker` for `[UID:0001EV]`.

These generated rows are validator-owned. The implementation callback should update source by-* docs and run validators; it should not edit generated files directly.

## Function Boundary And Range

The documented target range is correct:

- Start: `0x00548a80`
- End: `0x00548f1a`
- Size: `0x49a` / 1178 bytes

Boundary proof:

- `0x00548a7d-0x00548a7f` is `0xcc` padding.
- `0x00548a80` starts `sub_548A80`.
- `0x00548f1a` contains `66 90` alignment.
- `0x00548f1c` begins the target's jump table, not a separate function.
- `0x00548f30` starts the paired predicate callback `sub_548F30`.

The target should keep the current half-open range `0x00548a80-0x00548f1a`. The switch table at `0x00548f1c-0x00548f30` is target-owned evidence/padding-adjacent data and should be described, but it should not be merged into the executable-code target range.

## Callback Shape

The best source shape is a PatchPane2 method callback:

```cpp
bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)
```

IDA sees the target as `char __thiscall(int this, int)`. The `this` pointer in the target is the PatchPane2 secondary callback subobject at owner offset `+0xa0` / 160. The routine repeatedly subtracts 160 to call full-object PatchPane2 helpers. This supports a source-facing PatchPane2 method rather than a free function, global dispatcher, MiscWorkThread method, or raw no-owner callback.

The only direct reachability is the vtable data route:

- `0x00621fb4 -> 0x00548f30` for the predicate callback.
- `0x00621fb8 -> 0x00548a80` for this handler callback.

No direct code caller was found for `0x00548a80`. That is expected for a vtable-dispatched work-event callback and is not a reason to demote ownership or reconstructability.

## State Machine

The first gate is the work-event channel/magic:

- Binary value: `0x68747470` / 1752462448.
- Little-endian byte order is `70 74 74 68`; source-facing meaning is HTTP channel `"http"`.
- If `event + 8` does not match this value, the function returns `false` / `0`.

After the HTTP gate, the target treats `event + 0x0c` as an `httpget::Notification *` and switches on `notification + 0x04`. The best source-facing enum route is `HttpGetNotificationState`:

- `0`: started/open-file path.
- `1`: data-chunk/write path.
- `2`: completed/close-delete-rename-launch path.
- `3`: read/open URL failure, advance-or-retry path.
- `4`: InternetOpen failure/error-message path.
- default: quiet handled return `true`.

### State 0: Started

Behavior:

- Opens the temp patch path at secondary `this + 0x1d0`, owner `+0x270`, with UTF-16LE mode `L"wb"` from `0x0060df28`.
- Stores the resulting `FILE *` at secondary `this + 0x1e4`, owner `+0x284`.
- If the open fails, calls `PatchPane2::ReportWriteError(this - 0xa0, tempPath)` at `0x005492d0`.
- Updates UI/control slot 0 with final patch path from secondary `this + 0x1cc`, owner `+0x26c`.
- Formats and updates UI/control slot 1 with a zero byte-count string. The string ref at `0x00610634` is `"0"`; the decompiler still passes `_ftell(activeFile)` through the local formatter sequence.
- Returns `true`.

### State 1: DataChunk

Behavior:

- Treats the notification payload as an `_AUTOBUF<unsigned char> *`.
- Reads payload data pointer from payload `+0x04` and size from payload `+0x08`.
- Calls `_fwrite(data, 1, size, m_activePatchFile)`.
- If the number of bytes written differs from the payload size, calls `PatchPane2::ReportWriteError(this - 0xa0, tempPath)`.
- Formats current `ftell(m_activePatchFile)` with `L"%d"` from `0x00610660`.
- Updates UI/control slot 1 with the formatted byte count.
- Returns `true`.

### State 2: Completed

Behavior:

- Calls `_fclose(m_activePatchFile)`, clears owner `+0x284` to null, and throws `Win32Error` if close returns `EOF` / `-1`.
- Converts the final path at owner `+0x26c` and invokes a delete/unlink style helper before rename.
- Converts the final and temp paths and calls `_rename(tempPath, finalPath)`.
- Treats rename failure as fatal only when `_rename` fails and `errno != ENOENT` / `2`; this preserves the binary's missing-file tolerance.
- Builds a `SHELLEXECUTEINFOA` with:
  - `cbSize = 60`
  - `lpVerb = "runas"` at `0x00612f24`
  - `lpFile = "patcher.exe"` at `0x00612f2c`
  - `lpParameters = Locale`
  - `nShow = 1`
- Calls `ShellExecuteExA`.
- Calls `PatchPane2::FinishAndExit(GetLanguageText(174))`; the language id is `0xae` / 174.
- Returns `true`.

### State 3: ReadOrOpenUrlFailed

Behavior:

- Calls `PatchPane2::ClosePatchFile()`.
- Compares owner `+0x280` current index against the final available vector index computed from owner `+0x274/+0x278`.
- If not at the last entry, increments owner `+0x280`, calls `PatchPane2::SendDownloadRequest()`, and returns `true`.
- If at the last entry and owner `+0x288` pass/retry count is less than `10`, resets owner `+0x280` to zero, increments owner `+0x288`, calls `PatchPane2::SendDownloadRequest()`, and returns `true`.
- If at the last entry and owner `+0x288 >= 10`, calls `PatchPane2::FinishAndExit(GetLanguageText(157))`, then still falls through to call `PatchPane2::SendDownloadRequest()` before returning `true`.

The last point is important. The binary does not return immediately after the threshold failure UI; it performs the failure exit call and then calls `SendDownloadRequest()` on the shared tail.

### State 4: InternetOpenFailed

Behavior:

- Calls `PatchPane2::ClosePatchFile()`.
- Creates a stack buffer of 1024 wide characters.
- Invokes a virtual method at payload vtable slot `+0x0c` to format/copy the error message into that stack buffer.
- Calls `PatchPane2::FinishAndExit(message)`.
- Returns `true`.

### Default

Unknown HTTP notification states return `true` without further action.

## Field Mapping And Source Names

IDA decompiles this routine relative to the secondary callback subobject. The implementation should document both raw and owner-relative offsets:

| Secondary Offset | Owner Offset | Recommended Source Name | Evidence |
|---:|---:|---|---|
| `+0x15c` | `+0x1fc` | `m_statusControls` or existing PatchPane2 control collection name | state 0/1 UI text updates |
| `+0x1cc` | `+0x26c` | `m_finalPatchPath` | displayed in state 0, delete/rename target in state 2 |
| `+0x1d0` | `+0x270` | `m_tempPatchPath` | opened in state 0, write-error path in states 0/1, rename source in state 2 |
| `+0x1d4` | `+0x274` | `m_patchFileNames._Myfirst` or collection begin | vector begin used in state 3 |
| `+0x1d8` | `+0x278` | `m_patchFileNames._Mylast` or collection end | vector end used in state 3 |
| `+0x1dc` | `+0x27c` | `m_patchFileNames._Myend` or collection capacity | vector layout/capacity |
| `+0x1e0` | `+0x280` | `m_currentDownloadIndex` | increment/reset in state 3 |
| `+0x1e4` | `+0x284` | `m_activePatchFile` | file pointer set, written, closed, cleared |
| `+0x1e8` | `+0x288` | `m_downloadPassCount` | retry/pass count compared against 10 and incremented |

The report supports replacing generic prose such as `this + 0x1e0` and `this + 0x1e4` with owner-level field names while preserving offsets. The field names above are source-ready inferred names; no original private member names were recovered.

## Helper Relationships

The target has these important helper relationships:

- `0x00548f30` / `[UID:0001EW]`: paired predicate callback. It should remain separate, source-facing `PatchPane2::AcceptsDownloadWorkEvent` or equivalent.
- `0x00548f50`: close-and-clear active file helper, source-facing `PatchPane2::ClosePatchFile`.
- `0x00548f80`: exit/finish helper, source-facing `PatchPane2::FinishAndExit`.
- `0x00549020`: raw no-function region with no xrefs. Do not promote it to a standalone emitted helper from this report.
- `0x00549080` / `[UID:0001EX]`: modeled close/delete/rename helper with no direct xrefs. The main loop duplicates equivalent close/delete/rename behavior inline; do not merge this helper into the target.
- `0x00549220` / `[UID:0001EY]`: send-download-request helper, called by the constructor and by the main loop in state 3.
- `0x005492d0`: write-error helper, currently referenced by target/support docs with stale range `0x005492d0-0x00549338`. Live MCP proves actual function size `0x69`, half-open range `0x005492d0-0x00549339`. It formats `L"Error writing %s"` at `0x0062200c` and calls `PatchPane2::FinishAndExit`.

Implementation should either create/update a support target for `0x005492d0-0x00549339.PatchPane2ReportWriteError.md` or, if the project requires a separate queue allocation first, at minimum fix stale range prose in accepted support docs and note the live boundary. The old `0x00549338` endpoint is an inclusive/stale endpoint, not the correct half-open by-memory path.

## Source Placement

Recommended placement remains:

```text
NexusTK/patch/PatchPane.cpp
```

Do not create a mandatory `PatchPane2.cpp` route from this target. `by-file/PatchPane.md` already owns the PatchPane/PatchPane2 family, and the active generated file is `auto-generated/NexusTK/patch/PatchPane.cpp`. No original source-file string was recovered that proves a separate `PatchPane2.cpp`. The callback mutates PatchPane2 state and calls PatchPane2 methods, but that is a class ownership fact, not a separate file-placement fact.

## Rejected Alternatives And Negative Evidence

These alternatives should remain rejected in target/support docs:

- No direct dispatcher/caller route was found for `0x00548a80`. Reachability is vtable data only through `0x00621fb8`, which is expected for this callback shape.
- No original source symbol, method name, or source file string was found for the target.
- No proof supports making this a MiscWorkThread-owned function. MiscWorkThread posts HTTP notifications; PatchPane2 consumes them here.
- No proof supports a standalone Game-style module, no-owner fallback, or non-emitting fallback. The routine is strongly PatchPane2-owned and already has a valid emitter.
- No proof supports merging raw `0x00549020` into this target or promoting it as a direct helper. It is raw no-function and has zero xrefs in the live IDB.
- No proof supports using `0x00549080` as the called close/rename implementation from this main loop. Live xrefs show zero direct callers for `0x00549080`; the main loop duplicates close/delete/rename behavior inline.
- Generated tracker and generated C++ rows are validator-owned. Do not edit them manually.

## Formal First-Draft C++ Recommendation

The following block is the exact recommended target `RECONSTRUCTION_CPP CODE` body for `[UID:0001EV]`. It is not a side example. It should be inserted into the target's multiline C++ block during the implementation callback, with the inline `RECONSTRUCTION_CPP:` value left blank.

```cpp
bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)
{
    if (event->m_channel != kHttpNotification)
        return false;

    const httpget::Notification *notification =
        static_cast<const httpget::Notification *>(event->m_payload);

    switch (notification->m_state) {
    case httpget::Started:
    {
        m_activePatchFile = _wfopen(m_tempPatchPath.c_str(), L"wb");
        if (m_activePatchFile == 0)
            ReportWriteError(m_tempPatchPath.c_str());

        m_statusControls->GetAt(0)->SetText(m_finalPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"0", ftell(m_activePatchFile));
        m_statusControls->GetAt(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::DataChunk:
    {
        const _AUTOBUF<unsigned char> *chunk =
            static_cast<const _AUTOBUF<unsigned char> *>(notification->m_payload);

        if (fwrite(chunk->data(), 1, chunk->size(), m_activePatchFile) != chunk->size())
            ReportWriteError(m_tempPatchPath.c_str());

        StringBase<wchar_t> byteCount;
        byteCount.FormatWide(L"%d", ftell(m_activePatchFile));
        m_statusControls->GetAt(1)->SetText(byteCount.c_str());
        return true;
    }

    case httpget::Completed:
    {
        FILE *file = m_activePatchFile;
        const int closeResult = fclose(file);
        m_activePatchFile = 0;
        if (closeResult == EOF)
            throw Win32Error();

        StringBase<char> finalPath(m_finalPatchPath);
        _unlink(finalPath.c_str());

        StringBase<char> renameTarget(m_finalPatchPath);
        StringBase<char> renameSource(m_tempPatchPath);
        if (rename(renameSource.c_str(), renameTarget.c_str()) != 0 && errno != ENOENT)
            throw Win32Error();

        SHELLEXECUTEINFOA executeInfo = {};
        executeInfo.cbSize = sizeof(executeInfo);
        executeInfo.lpVerb = "runas";
        executeInfo.lpFile = "patcher.exe";
        executeInfo.lpParameters = Locale;
        executeInfo.nShow = SW_SHOWNORMAL;
        ShellExecuteExA(&executeInfo);

        FinishAndExit(GetLanguageText(174));
        return true;
    }

    case httpget::ReadOrOpenUrlFailed:
        ClosePatchFile();

        if (m_currentDownloadIndex < m_patchFileNames.size() - 1) {
            ++m_currentDownloadIndex;
            SendDownloadRequest();
            return true;
        }

        if (m_downloadPassCount >= 10)
            FinishAndExit(GetLanguageText(157));
        else {
            m_currentDownloadIndex = 0;
            ++m_downloadPassCount;
        }

        SendDownloadRequest();
        return true;

    case httpget::InternetOpenFailed:
    {
        ClosePatchFile();

        wchar_t message[1024];
        const Error *error = static_cast<const Error *>(notification->m_payload);
        error->FormatErrorMessage(message, 1024);
        FinishAndExit(message);
        return true;
    }

    default:
        return true;
    }
}
```

Notes for implementation:

- The source-facing names are inferred and should be used consistently across the target/support docs: `HandleDownloadWorkEvent`, `m_finalPatchPath`, `m_tempPatchPath`, `m_patchFileNames`, `m_currentDownloadIndex`, `m_activePatchFile`, `m_downloadPassCount`, `ClosePatchFile`, `FinishAndExit`, `SendDownloadRequest`, and `ReportWriteError`.
- `kHttpNotification` represents the binary value `0x68747470`.
- `httpget::Started/DataChunk/Completed/ReadOrOpenUrlFailed/InternetOpenFailed` should match the existing `HttpGetNotificationState` support doc names if those exact enum spellings differ.
- `m_statusControls->GetAt(...)->SetText(...)`, `_AUTOBUF::data()`, `_AUTOBUF::size()`, `StringBase::FormatWide`, `GetLanguageText`, and `Error::FormatErrorMessage` are source-facing API names inferred from local behavior. They can be harmonized to established local names during implementation, but the behavior must not be compressed or dropped.

## Support Incorporation Plan

During implementation callback, apply the report details at report-level factual detail to these docs:

1. `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`
   - Set `COMPLETION:90` and `CONFIDENCE:91`.
   - Keep owner/emitter route `0000AA`, `RECONSTRUCTABLE:TRUE`.
   - Update Item Summary and status to cite MCP session `398b87c1`.
   - Record exact boundary/padding and jump-table ownership notes.
   - Replace generic offset prose with owner-relative field names while preserving raw offsets.
   - Correct subtype 3 behavior: threshold failure calls `FinishAndExit(157)` and then still calls `SendDownloadRequest()`.
   - Add `0x005492d0-0x00549339` write-error helper evidence.
   - Insert the formal C++ block above.

2. `by-class/PatchPane2.md`
   - Update method inventory for `0x00548a80` to source-ready `PatchPane2::HandleDownloadWorkEvent`.
   - Preserve vtable-only callback shape and no-direct-caller evidence.
   - Add field inventory updates for final path, temp path, file list, current index, active file, pass count.
   - Fix stale `PatchPane2ReportWriteError` range from `0x005492d0-0x00549338` to half-open `0x005492d0-0x00549339`, or explicitly mark old endpoint as superseded.
   - Note that `0x00549020` remains raw no-function and `0x00549080` remains no-direct-xref modeled helper.

3. `by-file/PatchPane.md`
   - Add that `[UID:0001EV]` is source-ready for `NexusTK/patch/PatchPane.cpp`.
   - Keep the source-placement rationale in PatchPane/PatchPane2 family docs.
   - Note no recovered proof for mandatory `PatchPane2.cpp`.

4. `by-type/by-struct/PatchPane2Layout.md`
   - Update field inventory names for owner offsets `+0x26c`, `+0x270`, `+0x274/+0x278/+0x27c`, `+0x280`, `+0x284`, and `+0x288`.
   - Add live main-loop writes/reads as evidence.

5. `by-type/by-vtable/PatchPaneVtableFamily.md`
   - Add MCP session `398b87c1` evidence for secondary vtable slots `0x00621fb4` and `0x00621fb8`.
   - Mark the handler slot as source-ready and vtable-only.

6. `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`
   - Update the child row for `[UID:0001EV]` to source-ready instead of blank-C++ blocked.
   - Fix stale `0x005492d0-0x00549338` write-error range to half-open `0x005492d0-0x00549339`, or mark the stale endpoint as superseded.
   - Preserve the aggregate as non-reconstructable split/index documentation.

7. `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md`
   - Preserve its separate predicate ownership.
   - Add paired-callback relationship to the now source-ready main handler.
   - Do not force predicate C++ unless that target is separately accepted.

8. `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`
   - Preserve raw no-function/no-xref status.
   - Add that state 3 of `[UID:0001EV]` covers the source-ready index/pass-count flow and that the threshold branch still sends another request after failure UI.

9. `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`
   - Preserve no-direct-xref evidence.
   - Add that `[UID:0001EV]` duplicates close/delete/rename behavior inline and should not be described as calling this helper.

10. `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md`
    - Confirm main-loop callsites `0x00548c71`, `0x00548c9b`, `0x00548cc1`.
    - Preserve helper C++ disposition unless separately accepted.

11. `by-memory/0x005492d0-0x00549339.PatchPane2ReportWriteError.md`
    - If allowed by supervisor validation, create this missing support doc with a new UID allocation through the normal validator/leaser workflow.
    - Recommended metadata if created: owner/emitter `0000AA`, reconstructable true, source-facing name `PatchPane2::ReportWriteError`, range `0x005492d0-0x00549339`, evidence string `L"Error writing %s"` at `0x0062200c`, xref `0x005492fb`, callers `0x00548b16` and `0x00548bc7`.
    - If creation is not in the callback scope, update existing support docs to state the half-open range and leave creation as a follow-up.

## Blockers Resolved

Resolved:

- Live MCP evidence was available and used. This is not an offline-only report.
- Exact target boundary and padding were verified.
- Exact vtable slot route was verified.
- Exact notification state machine was recovered.
- File open/write/close/rename/ShellExecute/error behavior was recovered.
- State 3 retry/pass-count logic was clarified, including the post-failure `SendDownloadRequest()` call.
- Field offsets were mapped from secondary-subobject offsets to owner offsets.
- Formal first-draft C++ is now justified for the target.

Still open but not blocking target C++:

- Original private field names were not recovered. The report provides source-facing inferred names.
- Original method symbol string was not recovered. The report provides the best source-facing name and preserves negative evidence.
- Exact source API names for local collection/string/error wrappers may need local style harmonization during implementation, but behavior is sufficiently proven for a formal draft.
- Missing dedicated write-error support doc may need supervisor-approved file creation. Existing support docs can still be corrected to the live half-open range.

## Implementation Tracking Checklist

Report-only state:

- [x] Read `goal.md` and project-level `ntk-b-agent-workflow` instructions.
- [x] Did not spawn subagents.
- [x] Did not edit target/support by-* docs.
- [x] Did not edit generated reports, generated C++ files, project-level reports, coverage reports, validator/tool state, or IDA DB.
- [x] Took no leases during report-only research.
- [x] Completed live MCP-backed evidence pass against session `398b87c1`.

Implementation callback checklist:

- [x] Lease only the accepted target/support file set being edited immediately; do not take reservation leases.
  - Proof: successful B009 lease batch covered only the accepted implementation files: `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`, `by-class/PatchPane2.md`, `by-file/PatchPane.md`, `by-type/by-struct/PatchPane2Layout.md`, `by-type/by-vtable/PatchPaneVtableFamily.md`, `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`, `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md`, `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`, `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`, and `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md`.
- [x] Update `[UID:0001EV]` metadata to `COMPLETION:90`, `CONFIDENCE:91`, owner/emitter unchanged.
  - Proof: `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md` now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AA`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000AA`.
- [x] Insert the exact formal first-draft C++ block into the target `RECONSTRUCTION_CPP CODE` block, leaving inline `RECONSTRUCTION_CPP:` blank.
  - Proof: the target formal block now contains `bool PatchPane2::HandleDownloadWorkEvent(const WorkThreadNotification *event)` and the inline header value remains blank.
- [x] Update target behavior, evidence, field mapping, boundary/padding, and rejected-alternatives sections from this report.
  - Proof: the target now records the B009 source-ready implementation evidence, vtable-only route, jump-table/padding facts, state 0-4 behavior, owner-relative field names, stale generated-state caveat, and corrected state 3 pass-threshold fallthrough to `SendDownloadRequest()`.
- [x] Update accepted support docs at report-level detail; do not compress the findings into a short summary.
  - Proof: updated `by-class/PatchPane2.md`, `by-file/PatchPane.md`, `by-type/by-struct/PatchPane2Layout.md`, `by-type/by-vtable/PatchPaneVtableFamily.md`, `by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`, `by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md`, `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`, `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`, and `by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md` with the accepted source-ready route, helper relationships, field/split/range details, and generated-state corrections.
- [x] Correct or supersede stale `0x005492d0-0x00549338` write-error range to live half-open `0x005492d0-0x00549339`.
  - Proof: support docs now identify `0x005492d0-0x00549339` as the live half-open `PatchPane2::ReportWriteError` range and describe the old `0x00549338` endpoint as stale/inclusive where needed. No child page was created because safe UID/registration was outside this callback; the exact future child recommendation is recorded instead.
- [x] Run the required validators from `source-3/project-documentation`, including target validation with `--wait-generated`.
  - Proof: reran all changed by-* files with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --wait-generated`; every command exited `0` with `ok: 1`.
- [x] Record validator command ids/timestamps/ok counts in this report's checklist after implementation.
  - Proof:
    - `by-memory\0x00548a80-0x00548f1a.PatchPane2MainLoop.md`: command_id `000000004511`, timestamp `2026-06-27T20:59:54-04:00`, `ok: 1`, exit `0`.
    - `by-class\PatchPane2.md`: command_id `000000004513`, timestamp `2026-06-27T21:00:14-04:00`, `ok: 1`, exit `0`.
    - `by-file\PatchPane.md`: command_id `000000004517`, timestamp `2026-06-27T21:00:33-04:00`, `ok: 1`, exit `0`.
    - `by-type\by-struct\PatchPane2Layout.md`: command_id `000000004520`, timestamp `2026-06-27T21:00:51-04:00`, `ok: 1`, exit `0`.
    - `by-type\by-vtable\PatchPaneVtableFamily.md`: command_id `000000004523`, timestamp `2026-06-27T21:01:12-04:00`, `ok: 1`, exit `0`.
    - `by-memory\0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`: command_id `000000004526`, timestamp `2026-06-27T21:01:33-04:00`, `ok: 1`, exit `0`.
    - `by-memory\0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md`: command_id `000000004529`, timestamp `2026-06-27T21:01:53-04:00`, `ok: 1`, exit `0`.
    - `by-memory\0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`: command_id `000000004532`, timestamp `2026-06-27T21:02:14-04:00`, `ok: 1`, exit `0`.
    - `by-memory\0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`: command_id `000000004535`, timestamp `2026-06-27T21:02:35-04:00`, `ok: 1`, exit `0`.
    - `by-memory\0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md`: command_id `000000004538`, timestamp `2026-06-27T21:02:55-04:00`, `ok: 1`, exit `0`.
- [x] Confirm generated refresh state; do not manually edit generated output.
  - Proof: each scoped validator above returned `generated_refresh: completed` with matching `generated_refresh_command_id` and `generated_refresh_timestamp`. The generated `auto-generated/NexusTK/patch/PatchPane.cpp` header refreshed through validator generation and shows `validator-command-id: 000000004540`, `validator-refreshed-at: 2026-06-27T21:03:05-04:00`, which is newer than the target validator command `000000004511`.
- [x] Release all B009 leases immediately after the edit/validator batch.
  - Proof: B009 unlease command succeeded for all ten leased paths, and `current_leases.md` had no remaining `B009` rows immediately afterward.
- [x] Return `FINISHED_IMPLEMENTATION` only after validation passes and no active B009 lease remains.
  - Proof: all accepted implementation items are checked above; all validators passed; generated output was validator-refreshed; no active B009 lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001EV-PatchPane2MainLoop-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001EV-PatchPane2MainLoop-source-quality.md","timestamp":"2026-06-27T21:24:14","uid":"0001EV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
