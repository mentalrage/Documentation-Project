** TARGET-REPORT-UID:000140 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000140 FileErrorCopyMessage Source-Quality Report

Assignment: `B006-report-000140-FileErrorCopyMessage-source-quality-20260627`

Target: [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](../../../../../by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)

Mode: report-only research pass. No by-* target/support docs, generated reports, validator state, coverage reports, or IDA DB state were edited.

## Current Target State

- Current target metadata is `COMPLETION:85`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00004X`, `EMITTER_UIDS:00004X`, and blank formal C++.
- The target is already attached to [UID:00004X][FileError](../../../../../by-class/FileError.md), which routes to [UID:0000J5][Error](../../../../../by-file/Error.md) / `NexusTK/util/Error.cpp`.
- The current target file is modified in the worktree before this report pass. This report does not claim or revert those edits.
- Current generated state is stale: `auto-generated/NexusTK/util/Error.cpp` still has an empty marker for UID `000140` at `78/88`, and `auto-generated/-ag-research-tracker.md` still lists `78/88`. Those are validator/generated outputs and must not be edited manually.

## Evidence Checked

- Read the target page, FileError class page, Error file page, ErrorWrappers aggregate, FileError constructor child, ErrorHierarchyVtables, ErrorObjectLayouts, ErrorHierarchyVtableData, ErrorMessageCopyMessage sibling, ErrorDestructorAndNameHelpers, executed B002/B013/B012 reports, project guidance, and the required B-agent workflow/Rule 26 references.
- Used live IDA MCP over session `015dfb2d-653b-48c9-8e5a-b136be8afb26`, database `80de0a67`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` reports `status: ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Used local `tools/int_convert.py`; conversions below marked as verified were checked through that tool.

## Live IDA Findings

- `lookup_funcs` reports `sub_4A6480` at `0x004a6480`, size `0x19`; `0x004a6499` is not a function. Verified with `int_convert.py`: `0x19 = 25`.
- `analyze_function 0x004a6480` reports one basic block, cyclomatic complexity 1, no callers, one callee `_wcscpy_s`, and one data xref to the function from `0x006193e0`.
- Decompiler output is `errno_t __thiscall sub_4A6480(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)` returning `wcscpy_s(Destination, SizeInWords, this + 2)`.
- Disassembly is the exact one-block copy helper: `lea eax, [ecx+4]`, push source/size/destination, call `_wcscpy_s`, clean three pushed arguments, `retn 8`.
- The decompiler's `this + 2` is because it types `this` as `const wchar_t *`; the instruction source is byte offset `+0x04`. Verified with `int_convert.py`: `0x04 = 4`.
- `get_bytes 0x004a6480 size 25` returns `55 8b ec 8d 41 04 50 ff 75 0c ff 75 08 e8 c5 71 12 00 83 c4 0c 5d c2 08 00`.
- `get_bytes 0x004a6470 size 48` shows the preceding cleanup island bytes, five `0xcc` bytes before the helper, the full helper body, and seven `0xcc` bytes after `0x004a6499`.
- `lookup_funcs` reports the preceding island `sub_4A6470` at `0x004a6470`, size `0x0b`, and no function at `0x004a647b`; verified with `int_convert.py`: `0x0b = 11`.
- `analyze_function 0x004a6470` and `disasm 0x004a6470` show it writes `Error::vftable` (`0x00619344`) to `[ecx]` and tail-jumps to inherited cleanup `0x004f4a90`. It is not padding and is not part of UID `000140`.
- `get_bytes 0x006193d0 size 24` decodes the FileError RTTI/vtable row as RTTI pointer `0x00646d60`, destructor slot `0x004a6970`, inherited runtime slot `0x004f4b10`, no-op slot `0x0041b6c0`, message slot `0x004a6480`, and name slot `0x004a6a70`.
- `xrefs_to 0x004a6480` reports one data ref from `0x006193e0`; `find_bytes "80 64 4A 00"` finds the helper VA only at `0x006193e0`, and `find_bytes "80 64 0A 00"` finds no RVA-form hit.
- `xrefs_to 0x006193d4` reports the FileError constructor vtable store at `0x004a6445`; `find_bytes "D4 93 61 00"` finds the vtable-base immediate at `0x004a6447`.
- `analyze_function` and `disasm` for `0x004a6430` confirm the constructor calls base setup, writes `FileError::vftable`, formats into `this + 2` with buffer count `0x50` and max count `0x4e`, then writes the terminator at `+0xa2`. Verified with `int_convert.py`: `0x50 = 80`, `0x4e = 78`, `0xa4 = 164`, and `0xa0 = 160`.
- `analyze_function 0x004a6970` confirms FileError's scalar deleting destructor vtable slot uses the same FileError table route and then resets to the base `Error` vtable during cleanup.

## Slot And Declaration Findings

- The live decompiler still shows the shared `+0x0c` slot return split:
  - `0x004a6100`, `0x004a61e0`, `0x004a6290`, `0x004a6360`, and `0x004a64d0` decompile as `int __thiscall` formatter-style implementations.
  - `0x004a6410`, `0x004a6480`, `0x004a6670`, `0x004a6780`, and `0x004a6840` decompile as `_wcscpy_s` / `errno_t` stored-message copy helpers.
- The best current source-facing common name is `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const`, with `CopyErrorMessage` only a possible project-wide alternative if standardized consistently.
- The current best target-level return choice is `int`: formatter siblings already decompile as `int`, stored-message helpers return `errno_t` from `wcscpy_s`, and both are ABI-compatible integer status returns. This rejects `void` and rejects a target-local isolated `errno_t` declaration for this report's formal first-draft source.
- The FileError field shape is strong: vptr at `+0x00`, inline wide message at byte offset `+0x04`, 80 wide characters, and object size evidence consistent with `4 + 160 = 164`. The exact original member spelling remains inferred, but `m_message` is already used by accepted FileError constructor reconstruction.

## Revised Source Declaration Investigation

The initial report treated the unstandardized `+0x0c` hierarchy declaration as a final C++ blocker. Supervisor review correctly rejects that as insufficient under the current B-agent rule. After chasing the blocker through the target, sibling, and hierarchy docs, the best-supported current first-draft source for this target is safe enough to recommend.

Code-entry gate:

- UID `000140` is `RECONSTRUCTABLE:TRUE`.
- It has nonblank `EMITTER_UIDS:00004X`, and [UID:00004X][FileError](../../../../../by-class/FileError.md) routes to [UID:0000J5][Error](../../../../../by-file/Error.md) / `NexusTK/util/Error.cpp`.
- Current target score `85/89` has average `87`, above the current `(COMPLETION + CONFIDENCE) / 2 > 85` minimum gate.
- The helper has exact range, padding, callee, vtable route, constructor pairing, and field-layout evidence; no sibling/aggregate outside this UID owns the same method body.

Name decision:

- `FormatErrorMessage` is the best current common name because ErrorWrappers and ErrorHierarchyVtables use it for the shared `+0x0c` message-output slot across formatting and stored-message implementations.
- `CopyErrorMessage` is rejected for UID `000140` as the formal first-draft name because current docs identify it as a local/consumer label, especially in WinMain, and because it describes only the stored-message family, not the formatter family.
- `GetErrorText` is rejected because it is documented as local behavior for Internet-style wrappers and does not name the whole `+0x0c` virtual family.
- `CopyMessage`, `FileErrorCopyMessage`, `sub_4A6480`, `Destination`, `SizeInWords`, and `this + 2` are rejected for final draft source because they are target labels or decompiler-shaped names.

Return decision:

- `int` is the best first-draft hierarchy return. Formatter siblings decompile as `int`, stored-message siblings return CRT status values, and `errno_t` is integer-compatible with the observed `eax` return.
- `void` is unsafe because the helper returns the `wcscpy_s` status in `eax`, and sibling formatter implementations also preserve integer results.
- A target-local `errno_t` return is too narrow for this formal first-draft because it would make FileError differ from the formatter siblings without evidence that the source hierarchy declared covariant or otherwise per-class return spelling. The safer current source declaration is one integer-returning virtual interface.

Argument and field decision:

- `wchar_t *destination` and `size_t destinationChars` are the best source-facing arguments. They match the current support-doc spelling, avoid IDA's `Destination` / `SizeInWords` decompiler names, and describe the caller-owned wide buffer plus element count.
- `const` is justified because the function only reads the FileError inline message and writes to the caller buffer; current IDA types `this` as `const wchar_t *`, and the shared docs already model this as a const message-output virtual.
- `m_message` is the best field name. It is inferred rather than symbol-proven, but it is already accepted in the source-ready FileError constructor and is backed by the constructor's `m_message[80]` formatting/terminator evidence plus this helper's `[ecx+4]` copy source.
- `wcscpy_s` is the source-facing CRT call. `_wcscpy_s` is the import/IDA callee spelling; final C++ should not use the import-label form unless the rest of the reconstructed source standardizes on that spelling.

Sibling policy re-check:

- [UID:00013Z][ErrorMessageCopyMessage](../../../../../by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) currently keeps formal C++ blank for the same "shared declaration not standardized" reason. That policy was accepted under an earlier cautious pass but is stale under the current supervisor rule when used as a final blocker by itself.
- The consistent repair direction is to give [UID:00013Z] an equivalent `FormatErrorMessage` first-draft implementation under `ErrorMessage`, using the same integer-returning interface and its `wchar_t[256]` inline message field. That sibling repair is not performed in this B006 report-only revision, but UID `000140` should not inherit the stale blank-C++ policy.
- A formal comment marker is also rejected for UID `000140`: this range is not covered by another UID's emitted code and has an exact method body that can be represented in source. A marker such as "covered by another UID" would be false and would hide a required vtable method from generated output.

## Ownership And Source Disposition

Ranked disposition:

1. [UID:00004X][FileError](../../../../../by-class/FileError.md) is the correct canonical owner. The vtable row, constructor vtable write, inline buffer, destructor row, and class/file route all converge on FileError.
2. [UID:0000J5][Error](../../../../../by-file/Error.md) / `NexusTK/util/Error.cpp` is the correct source file route through the FileError class.
3. [UID:00013X][ErrorWrappers](../../../../../by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), ErrorHierarchyVtables, ErrorObjectLayouts, and ErrorHierarchyVtableData are support/aggregate docs, not canonical owners for this exact helper.
4. Archive/open, LogoPlayerPane, StdioFile, and DAT-related callers are consumers that construct or throw `FileError`; they do not own this vtable method.
5. No-owner/no-emitter fallback is rejected. The target is live through the FileError vtable slot even though it has no direct code callers.

## C++ Recommendation

Insert formal first-draft C++ for UID `000140`.

Exact `RECONSTRUCTION_CPP CODE:BEGIN` / `END` content for supervisor-approved insertion:

```cpp
int FileError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const
{
    return wcscpy_s(destination, destinationChars, m_message);
}
```

This body is exact for the current target range: it emits the `wcscpy_s(destination, destinationChars, m_message)` call represented by `0x004a6480-0x004a6499`, returns the integer CRT status in `eax`, uses the accepted FileError inline field name, and avoids IDA/decompiler-shaped names. It does not emit constructor, vtable, destructor, cleanup-island, base-class, or sibling-slot code outside this UID's range.

Recommended metadata after implementation callback:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00004X`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00004X`
- formal C++ block contains the exact method body above

Rationale: completion can rise to source-ready first-draft level because the report closes the exact boundary, vtable route, padding, constructor pairing, pointer-route, generated-output, owner/emitter, inline layout, and formal method-body decisions. Confidence can rise because the current live MCP evidence agrees with prior target/class/support evidence. Confidence remains below final audit because the original symbol name and exact historical declaration are still inferred rather than source-symbol-proven, but that uncertainty is no longer a blocker to first-draft source.

## Implementation Notes For Supervisor Callback

- Update only the target page unless the supervisor deliberately wants support-doc provenance synchronized. The existing support docs already contain the key policy: FileError owner, inline `wchar_t[80]`, vtable slot `0x006193e0 -> 0x004a6480`, generated omission, and `+0x0c` declaration blocker.
- If support docs are touched, preserve and synchronize this exact evidence on FileError, Error, ErrorWrappers, ErrorHierarchyVtables, ErrorObjectLayouts, and ErrorHierarchyVtableData without changing their current broader scores solely for UID `000140`.
- Insert the exact UID `000140` formal C++ block recommended above. Also update target prose to say `FormatErrorMessage` / `int` are current best first-draft source choices, while the support docs may still note that the hierarchy declaration remains inferred rather than original-symbol-proven.
- Treat [UID:00013Z] blank-C++ policy as stale under current review rules. Do not edit [UID:00013Z] in this callback unless the supervisor explicitly expands scope, but record the consistent repair direction if support docs mention sibling policy.
- Generated outputs and research tracker rows should be refreshed by validator/generator flow, not manually edited.

## Implementation Callback Checklist

- [x] In [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](../../../../../by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md), updated metadata to `COMPLETION:90` and `CONFIDENCE:92` while preserving `CANONICAL_OWNER:00004X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004X`, and blank `EMITTER_POSITION_OPTIONAL`. Target validator proof: command `000000003951`, timestamp `2026-06-27T08:19:59-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Inserted this exact formal `RECONSTRUCTION_CPP CODE:BEGIN` / `END` body for UID `000140`:

```cpp
int FileError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const
{
    return wcscpy_s(destination, destinationChars, m_message);
}
```

- [x] Added `## 2026-06-27 B006 Source-Quality Refresh` to the target with MCP session `015dfb2d-653b-48c9-8e5a-b136be8afb26`, database `80de0a67`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health status: ok`, imagebase `0x400000`, ready auto-analysis, ready Hex-Rays, and ready strings cache.
- [x] Recorded exact target body proof: `lookup_funcs` `sub_4A6480` size `0x19` / 25 bytes, no function at `0x004a6499`, one-block decompile returning `wcscpy_s(Destination, SizeInWords, this + 2)`, disassembly with `[ecx+4]`, `_wcscpy_s` callee, no direct callers, data ref at `0x006193e0`, VA-only `find_bytes "80 64 4A 00"` route, and no RVA-form `find_bytes "80 64 0A 00"` hit.
- [x] Recorded the FileError vtable bytes/dwords from `0x006193d0`: RTTI `0x00646d60`, destructor `0x004a6970`, runtime slot `0x004f4b10`, no-op slot `0x0041b6c0`, message slot `0x004a6480`, and name slot `0x004a6a70`.
- [x] Recorded constructor pairing: `xrefs_to 0x006193d4` at `0x004a6445`, constructor range `0x004a6430-0x004a646f`, `find_bytes "D4 93 61 00"` at `0x004a6447`, buffer count `0x50` / 80, max count `0x4e` / 78, object size `0xa4` / 164, inline payload `0xa0` / 160, and terminator at `+0xa2`.
- [x] Recorded padding and adjacent-helper boundary: separate cleanup island `0x004a6470-0x004a647b`, five `0xcc` bytes before UID `000140`, seven `0xcc` bytes after `0x004a6499`, and B005 cleanup-island evidence kept outside this target body.
- [x] Added revised source-declaration analysis: `FormatErrorMessage` as current best common `+0x0c` name, `int` as safest first-draft hierarchy return, `destination` / `destinationChars` as source-facing arguments, `m_message` as accepted FileError field, `const` justified by read-only object access, and `wcscpy_s` as source-facing CRT spelling.
- [x] Preserved rejected alternatives: `CopyErrorMessage`, `GetErrorText`, `CopyMessage`, `FileErrorCopyMessage`, `sub_4A6480`, `Destination`, `SizeInWords`, `this + 2`, `void`, and target-local `errno_t` are rejected for this formal first draft.
- [x] Added sibling-policy correction: [UID:00013Z][ErrorMessageCopyMessage](../../../../../by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) remains out of scope for this callback, but its older blank-C++ reasoning must not force UID `000140` blank; the consistent future repair direction is an equivalent integer-returning `ErrorMessage::FormatErrorMessage` first draft.
- [x] Explicitly rejected a formal comment marker for UID `000140` because the range is not covered by another UID and should emit its own vtable method body.
- [x] Updated target score rationale for `90/92`: exact boundary, decompile/disassembly, `_wcscpy_s` body, no-caller/vtable-only liveness, constructor pairing, `find_bytes` proof, inline wide-message offset, FileError vtable dwords, adjacent boundary, owner/source route, rejected alternatives, sibling-policy correction, comment-marker rejection, and formal first-draft C++ are now documented; original symbol/declaration uncertainty still keeps confidence below final audit.
- [x] Synchronized support docs where the accepted target facts were missing, weaker, or contradictory: [FileError](../../../../../by-class/FileError.md), [Error](../../../../../by-file/Error.md), [ErrorWrappers](../../../../../by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), [ErrorHierarchyVtables](../../../../../by-type/by-vtable/ErrorHierarchyVtables.md), [ErrorObjectLayouts](../../../../../by-type/by-struct/ErrorObjectLayouts.md), and [ErrorHierarchyVtableData](../../../../../by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md). No support-doc score changes were made. A fixed-string stale-text scan over the target plus these six support docs found no active `000140` blanking/deferral wording after cleanup.
- [x] Validator/generator proof for the target and changed support docs:
  - Target `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md`: command `000000003951`, timestamp `2026-06-27T08:19:59-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, with `autogen_cpp_update: 1`, `autogen_report_update: 1`, `memory_auto_coverage_update: 1`, `research_tracker_update: 1`, and projected stats refresh.
  - `by-class/FileError.md`: command `000000004019`, timestamp `2026-06-27T08:36:10-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `by-file/Error.md`: command `000000004020`, timestamp `2026-06-27T08:36:22-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`: command `000000004021`, timestamp `2026-06-27T08:36:32-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `by-type/by-vtable/ErrorHierarchyVtables.md`: command `000000004022`, timestamp `2026-06-27T08:36:42-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `by-type/by-struct/ErrorObjectLayouts.md`: command `000000004023`, timestamp `2026-06-27T08:36:52-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
  - `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`: command `000000004024`, timestamp `2026-06-27T08:37:02-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Validator side-effect proof: each fresh support validator run reported `autogen_backup_create: 3`, `autogen_registry_rebuild: 1`, `autogen_registry_stale: 137`, `memory_coverage_metadata_missing_file: 136`, `projected_stats_update: 1`, and `stats_incremental_noop: 1`. The first support run also reported `memory_auto_coverage_update: 1`. These stale/missing registry warnings are pre-existing unrelated project state and did not block `ok: 1`.
- [x] Confirmed generated output refreshed through validator flow, not manual edits: `auto-generated/NexusTK/util/Error.cpp` now has `validator-command-id: 000000004024`, `validator-refreshed-at: 2026-06-27T08:37:02-04:00`, and contains the UID `000140` `int FileError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` body returning `wcscpy_s(destination, destinationChars, m_message)`.
- [x] Lease proof: target lease was acquired for the target edit/validator batch and released after target validator command `000000003951`. Support leases were reacquired after the earlier `by-file/Error.md` conflict cleared, validation was rerun under fresh leases with commands `000000004019` through `000000004024`, and all six support leases were released immediately after the validator batch. Final shared `current_leases.md` check showed no active B006 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/000140-FileErrorCopyMessage-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/000140-FileErrorCopyMessage-source-quality.md","timestamp":"2026-06-27T08:40:14","uid":"000140"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
