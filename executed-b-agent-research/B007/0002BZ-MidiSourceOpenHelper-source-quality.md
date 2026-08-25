** TARGET-REPORT-UID:0002BZ **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID 0002BZ - MidiSourceOpenHelper Source-Quality Research

## Finalized Report / Current Recommendation

UID `0002BZ` should move from a blank C++ target to a formal source-facing helper named `MidiOpenSource`, emitted under [UID:0000LD] `MidiPlayer`. The recommended contract is `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)`.

The current blocker is resolved by separating the raw helper's incidental register result from the source-facing helper contract. Live MCP evidence shows the raw bytes at `0x00526f10-0x00526f57` either call the adapter/DATFile open virtual slot and store `INVALID_HANDLE_VALUE`, or call the `CreateFileW` dispatch slot and store the returned handle. No entry xrefs reach `0x00526f10`, and the real loader at `0x005273a0` performs equivalent open logic inline, then performs readiness/size validation separately. Therefore the existing generated/support pattern `if (MidiOpenSource(document, path) != 0) return 0;` is the stale part, not a reason to keep UID `0002BZ` blank.

Recommended target metadata after implementation:

| Field | Current | Recommended |
|---|---:|---:|
| Completion | 85 | 88 |
| Confidence | 90 | 90 |
| Average | 87.5 | 89.0 |
| `CANONICAL_OWNER` | `0000LD` | `0000LD` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000LD` | `0000LD` |

Do not raise this target into the 95+ band. The source behavior is now strong enough for a formal reconstruction, but original symbol names, exact source-file split, and project-defined `MidiDocument`/adapter types remain unrecovered.

## Supporting Research

Primary support came from the target page, the parent MIDI SMF aggregate, the current `MidiPlayer` by-file page, the sibling source helpers, the loader support page, the Wide API dispatch table, prior executed B-agent reports, current generated output, and live IDA MCP.

Documents checked:

| Path | Use |
|---|---|
| `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md` | Target state, current score, raw disassembly notes, existing blocker |
| `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md` | Parent/child inventory, exact range and padding context |
| `by-file/MidiPlayer.md` | Canonical owner/emitter, accepted helper/type vocabulary, open follow-up status |
| `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md` | Loader support currently using the stale boolean source-open abstraction |
| `by-global/WideApiDispatchTable.md` | `0x0069be34` is the `CreateFileW` dispatch pointer slot |
| `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | Formal declaration style for `g_pfnCreateFileW` |
| `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md` | Neighboring close helper vocabulary and `INVALID_HANDLE_VALUE` convention |
| `by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md` | Neighboring source helper vocabulary and DATFile/file split |
| `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md` | Neighboring raw-read helper vocabulary and adapter/file split |
| `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md` | Readiness/size helper needed to repair the loader support page |
| `auto-generated/NexusTK/audio/MidiPlayer.cpp` | Current generated output still has an empty UID `0002BZ` marker and a stale source-open call |
| `auto-generated/-ag-research-tracker.md` | Tracker row confirms current 85/90, average 87.5, reconstructable true, report count 0 |

Prior reports checked:

| Report | Useful evidence |
|---|---|
| `executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md` | Identified UID `0002BZ` as a second-batch follow-up because raw return semantics conflicted with the generated boolean source-open abstraction |
| `executed-b-agent-research/B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md` | Earlier stale `static int MidiOpenSource(...)` prototype and loader call that should now be repaired |
| `executed-b-agent-research/B001/0002C1-MidiSourceSeekHelper-empty-emitter-source-quality.md` | Confirms surrounding source helper family and accepted `MidiOpenSource` name lead |
| `executed-b-agent-research/B012/0002BY-MidiTrackBufferPrimeReset-source-quality.md` | Independent note that `0x00526f10` is not modeled as an IDA function |
| `executed-b-agent-research/B007/0002BS-MidiExactReadHelper-source-quality.md` | Historical lead for the helper list including `MidiOpenSource`; superseded on return type |

## Target

Target UID: `0002BZ`

Target path: `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`

Range: `0x00526f10-0x00526f57`

Adjacent padding: `0x00526f57-0x00526f60` is `0xCC` alignment before the next helper at `0x00526f60`.

Current owner/emitter route: [UID:0000LD] `MidiPlayer`, with `RECONSTRUCTABLE:TRUE` and nonblank `EMITTER_UIDS:0000LD`.

Current formal C++ block: blank.

## Current Target State

The page currently documents UID `0002BZ` at `85/90`, average `87.5`. It correctly states that the raw helper opens adapter-backed or Win32 file-backed MIDI sources, that there are no IDA entry xrefs, and that the `CreateFileW` call goes through the startup-installed dispatch slot at `0x0069be34`.

The current score rationale leaves the target below formal C++ because the adapter/context type and source-facing helper declaration were considered unsafe. That caution was valid while the loader support page still modeled the helper as `static int MidiOpenSource(...)` with a boolean failure test. Current evidence resolves that specific blocker: the target helper should be a side-effect open helper, and the readiness/failure test belongs in the loader via UID `0002C3` `MidiSourceIsReady`.

Current generated output still contains an empty marker for UID `0002BZ` and only a call to `MidiOpenSource(document, path)` in the loader. It does not contain an implementation or prototype for `MidiOpenSource`.

## Heuristic / Inference Reanalysis And Validation

The target is a source-authored raw helper shape, not compiler padding or a thunk. The range has a function-like prologue, two source branches, side effects on the same `MidiDocument` fields used by neighboring helpers, and a single `retn 4` on both paths. IDA has not modeled it as a function, and no xrefs target the entry. This means the raw register return should not be treated as a stable source contract without corroboration.

The important inference is the source-facing signature. Raw EAX contains the adapter open return on the adapter path and the Win32 file handle on the file path, but no caller is known to consume this mixed value. The modeled loader at `0x005273a0` instead performs open side effects inline and then validates the opened source separately. That makes `static void MidiOpenSource(...)` the best source abstraction:

- It preserves exact side effects on `document->fileHandle`.
- It avoids inventing a mixed return type that no caller uses.
- It composes with the existing `MidiSourceIsReady(document)` helper, which already performs the DATFile readiness check or Win32 file-size/invalid-handle validation.
- It repairs the stale generated/support boolean call without forcing a merge of UID `0002BZ` into the loader.

Rejected alternatives:

| Alternative | Why rejected |
|---|---|
| `static int MidiOpenSource(...)` returning nonzero failure | Contradicted by raw file path, where success returns a non-invalid handle, and by loader decompilation where validation is separate |
| `static HANDLE MidiOpenSource(...)` | Contradicted by adapter path, where the adapter open result is not a Win32 handle and `document->fileHandle` is set to `INVALID_HANDLE_VALUE` |
| Inline all open logic only in UID `0002C7` | The raw helper is a distinct reconstructable range with owner/emitter metadata and a local helper role in the sibling source-helper family |
| Keep target blank until exact type names are recovered | The existing by-file and sibling docs already accept role-based `MidiDocument`, DATFile/source fields, and helper names; exact original names remain a confidence cap, not a completion blocker |

## Evidence Standards Used

Direct evidence was required for raw instructions, range boundaries, cross-reference state, and dispatch-slot identity. Live IDA MCP was used for those facts with narrow address-bounded calls, small limits, and schema-current responses.

Documentation evidence was used only where it is already incorporated into by-* pages or executed reports and was cross-checked against live MCP where the point affected the recommendation.

Inference was used for source-facing names, source placement, and the `void` helper contract. Each inference is grounded in direct raw side effects, loader decompilation, sibling helper conventions, and the current owner/emitter graph. No broad or unbounded IDA queries were used.

## Evidence Checked

Live MCP state:

- `initialize` succeeded against `ida-pro-mcp 1.0.0`.
- `idb_list` identified active session `supervisor_recovery_20260705`.
- `server_health` reported IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.

MCP calls and findings:

| MCP query | Result |
|---|---|
| `lookup_funcs` for `0x00526f10`, `0x00526f57`, `0x00526f60`, `0x00527000`, `0x005273a0`, `0x0041a2d0`, `0x0041a2f3` | `0x00526f10`, `0x00526f57`, and `0x00526f60` are not modeled functions; `0x00527000` is `sub_527000`; `0x005273a0` is `sub_5273A0`; `0x0041a2d0/0x0041a2f3` are inside `sub_41A280` |
| `insn_query 0x00526f10-0x00526f60` | Exact raw body and padding confirmed |
| `get_bytes 0x00526f10 size 80` | Bytes confirm body ends at `0x00526f57` followed by `0xCC` padding through `0x00526f60` |
| `xrefs_to 0x00526f10` | Zero entry xrefs |
| `xrefs_to 0x0069be34` | Includes initializer write at `0x0041a2f8`, target consumer at `0x00526f49`, loader consumer at `0x00527400`, and other Wide API dispatch consumers |
| `get_global_value 0x0069be34` | Static image value is `0x0`, consistent with runtime startup dispatch initialization |
| `insn_query 0x0041a2d0-0x0041a320` | `0x0041a2f3` loads `CreateFileW`; `0x0041a2f8` stores it to `unk_69BE34` |
| `decompile 0x005273a0` | Loader opens source inline, stores the handle/sentinel, then separately validates readiness/size |
| `decompile 0x00526f10` | Fails because IDA does not model the raw helper as a function |
| `type_query` for `Midi`, `SMF`, `Track` | No project-defined MIDI document/source adapter/track types recovered in IDA types |

Key raw instruction facts for UID `0002BZ`:

| Address | Fact |
|---|---|
| `0x00526f10` | Prologue starts raw helper body |
| `0x00526f16` | Tests `document->datFileSource` / adapter-backed flag at `this+0x14` |
| `0x00526f1c-0x00526f25` | Adapter path loads subobject at `this+0x18` and calls virtual slot `+0x0c` with `path` |
| `0x00526f28` | Adapter path stores `0xFFFFFFFF` to `this+0x2c` |
| `0x00526f34-0x00526f49` | File path pushes `CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)` arguments and calls `unk_69BE34` |
| `0x00526f4f` | File path stores returned handle to `this+0x2c` |
| `0x00526f57` | Body ends; padding begins |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | At assignment time UID `0002BZ` was `85/90`, blank formal C++, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000LD`, and `EMITTER_UIDS:0000LD`; callback implementation moves it to formal C++ and `88/90`. | High | Target page and tracker row line `1571` at assignment time; target page after callback. | `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md` / metadata, Current Target State, score rationale. | incorporate | applied |
| C02 | The exact target body is `0x00526f10-0x00526f57`; `0x00526f57-0x00526f60` is padding before the next helper. | High | MCP `insn_query 0x00526f10-0x00526f60`, `get_bytes 0x00526f10 size 80`, parent aggregate padding rows, sibling start at `0x00526f60`. | Target page / evidence notes and B007 Source-Open Implementation; parent aggregate / child inventory and padding notes. | incorporate | applied |
| C03 | IDA does not model `0x00526f10`, `0x00526f57`, or `0x00526f60` as functions, and `0x00526f10` has zero entry xrefs. | High | MCP `lookup_funcs` and `xrefs_to 0x00526f10`. | Target page / evidence notes, 2026-07-05 implementation note, and score rationale. | incorporate | applied |
| C04 | The adapter-backed branch tests `this+0x14`, calls the adapter/DATFile virtual open slot at `[this+0x18]+0x0c` with `path`, stores `0xFFFFFFFF` to `this+0x2c`, and returns. | High | MCP `insn_query` addresses `0x00526f16-0x00526f31`; sibling helper field conventions. | Target page / formal C++ block, behavior notes, and 2026-07-05 implementation note. | incorporate | applied |
| C05 | The Win32 file branch calls `CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)` through the dispatch slot and stores the returned handle to `this+0x2c`. | High | MCP `insn_query` addresses `0x00526f34-0x00526f54`; Wide API dispatch docs. | Target page / formal C++ block, behavior notes, and dispatch-slot evidence. | incorporate | applied |
| C06 | `0x0069be34` is the startup-installed `CreateFileW` dispatch pointer and should be rendered as `g_pfnCreateFileW`, not `dword_69BE34` or `unk_69BE34`. | High | MCP `insn_query 0x0041a2d0-0x0041a320` shows `CreateFileW` loaded and stored at `0x0041a2f8`; MCP `xrefs_to 0x0069be34`; `by-global/WideApiDispatchTable.md`; Wide API pointer-table formal declaration. | Target page / formal C++ block and Source-State Notes; `by-file/MidiPlayer.md` / source-quality declaration note; `by-global/WideApiDispatchTable.md` / no edit because already present. | incorporate for target/by-file; already-present for Wide API docs | applied |
| C07 | The source-facing helper should be `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)`, because the raw EAX value is mixed and no caller consumes it. | High | Raw branch behavior, zero entry xrefs, loader decompilation, sibling `MidiSourceIsReady` separation. | Target page / formal C++ block; `by-file/MidiPlayer.md` / MIDI SMF Source-Quality Declarations. | incorporate | applied |
| C08 | Prior `static int MidiOpenSource(...)` and boolean-return assumptions are stale and should be preserved only as historical/superseded evidence. | High | Current generated loader call before callback, UID `0002C7` page open question, B001/B013 prior reports, live loader decompilation. | Target page / reconstruction notes; UID `0002C7` page / Open Questions and Changes; parent aggregate and `by-file/MidiPlayer.md` / historical B013 follow-up notes. | historicalize and reject-stale | applied |
| C09 | UID `0002C7` loader support should call `MidiOpenSource(document, path);` and then validate with `if (!MidiSourceIsReady(document)) return 0;`. | High | MCP `decompile 0x005273a0` opens inline and validates separately; UID `0002C3` formal `MidiSourceIsReady` already models readiness/size. | `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md` / formal C++ block, detailed notes, open questions, and change notes. | incorporate | applied |
| C10 | UID `0002C3` `MidiSourceIsReady` is the correct support dependency for the loader repair, not an added error check inside `MidiOpenSource`. | High | UID `0002C3` formal C++ and loader decompilation. | UID `0002C7` page / loader C++ and reconstruction notes; target page / notes explaining no error checking in open helper. | incorporate | applied |
| C11 | Target score should move to `88/90`; confidence remains capped at `90`; do not raise into 95+ final-audit territory. | Medium-high | Resolved return-contract blocker, complete raw body and support repair, but no recovered original types/source split and no IDA function model. | Target page / score metadata and score rationale; generated tracker refreshed by validator, not by hand. | incorporate for target; not-applicable for manual tracker edit | applied |
| C12 | Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`. | High | Current target metadata, by-file owner graph, sibling helper family, generated `MidiPlayer.cpp` route. | Target page / metadata; `by-file/MidiPlayer.md` / source-family notes. | already-present for metadata, incorporate evidence notes if missing | already-present |
| C13 | Source placement remains private file-scope helper code in `NexusTK/audio/MidiPlayer.cpp`. | Medium-high | UID `0000LD` by-file page, sibling helper output, source-family context, generated output path. | Target page / reconstruction notes; `by-file/MidiPlayer.md` / MIDI SMF source-quality declarations. | incorporate | applied |
| C14 | DATFile/source adapter pages, a `MidiPlayer` class method, UID `0002C7` loader ownership, UID `00023B` parent ownership, and a new `MidiSMFDocument.cpp` owner are rejected for this target. | Medium-high | Receiver is `MidiDocument` source context, target metadata points to UID `0000LD`, no stronger source-file evidence, loader contains equivalent inline logic but does not own raw range. | Target page / reconstruction notes; parent aggregate / child disposition; `by-file/MidiPlayer.md` / source-quality declaration note. | incorporate rejected alternatives | applied |
| C15 | Parent aggregate UID `00023B` should update UID `0002BZ` from second-batch follow-up to formal helper emitted as `MidiOpenSource`, while preserving the exact range and padding. | Medium-high | Parent aggregate current child inventory, target C++ recommendation, B013 second-batch row now resolved for this child. | `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md` / autogen status, child inventory, name conclusions, child disposition, open questions, and changes. | incorporate | applied |
| C16 | `by-file/MidiPlayer.md` should update the private helper declaration/follow-up cleanup to `static void MidiOpenSource(MidiDocument* document, const wchar_t* path);` and remove UID `0002BZ` from the remaining empty/follow-up marker list after implementation. | Medium-high | Current by-file helper declaration section, generated empty marker, target recommendation, B013 follow-up history. | `by-file/MidiPlayer.md` / MIDI SMF Source-Quality Declarations, remaining follow-up list, score rationale, open questions, and changes. | incorporate | applied |
| C17 | Exact original names/types for `MidiDocument`, the adapter/DATFile source member, and the source-file split are not recovered; role-based names remain acceptable but cap confidence. | Medium | MCP `type_query` for `Midi`, `SMF`, `Track`, local by-type searches, by-file accepted role-based vocabulary. | Target page / reconstruction notes and score rationale; `by-file/MidiPlayer.md` / source-family caveat. | incorporate | applied |
| C18 | Generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` should not be edited manually; after scoped validators refresh output, it should contain `static void MidiOpenSource(...)`, no UID `0002BZ` empty marker, and the repaired loader sequence. | Medium | Pre-callback generated file showed UID `0002BZ` empty marker and stale call; workflow forbids manual generated edits; post-callback generated header and `rg` checks. | Generated output check only after implementation validators; no manual generated-file edit. | not-applicable | excluded-with-reason |
| C19 | Manual coverage reports and validator-owned tracker files do not need hand-authored replacement text for this assignment. | High | Assignment override and B-agent workflow forbid manual `-coverage-report.md`, generated/project-level, and validator-state edits; validator refreshed generated/project files as side effects. | Manual coverage/tracker docs / no edit; generated tracker refresh remains validator/supervisor lifecycle side effect. | not-applicable | excluded-with-reason |
| C20 | Remaining family blockers UID `0002B1`, UID `0001CE`, UID `0001CG`, and UID `0002C4` are out of scope for this target and should remain separate follow-ups unless their own evidence is incorporated. | Medium-high | `by-file/MidiPlayer.md` remaining marker list and B013 report; this report's evidence only resolves UID `0002BZ`. | `by-file/MidiPlayer.md` / follow-up list; parent aggregate / remaining sibling follow-up language. | incorporate scope note; not-applicable for resolving those UIDs | applied |
| C21 | B007 did not run `execute_report`, dry-run execution variants, lifecycle/archive commands, manual report moves, manual validator-state edits, manual generated edits, or archive commands. Scoped validators only were run during the callback. | High | Tool history for report-only pass and callback; assignment constraints; validator command outputs `000000007170` through `000000007174`; lease report after release shows no active leases. | This report / Validator Results, Changed Files, Implementation Tracking Checklist. | incorporate lifecycle status | applied |

## Positive Evidence Summary

- The target has exact raw behavior bounded to `0x00526f10-0x00526f57`.
- The side effects align with neighboring source helpers: `MidiSourceCloseHelper`, `MidiSourceSeekHelper`, `MidiSourceRawReadHelper`, and `MidiSourceSizeReadyHelper`.
- The Wide API dispatch evidence identifies `unk_69BE34` as the named `g_pfnCreateFileW` slot.
- Loader decompilation explains why the target's raw return value was confusing: source open and source readiness are separate operations.
- The target already has a valid owner/emitter route to `MidiPlayer`, `RECONSTRUCTABLE:TRUE`, and average above the C++ gate threshold.
- No active evidence supports moving this helper to DATFile, a class page, or a new file owner.

## Negative Evidence Summary

- IDA does not model `0x00526f10` as a function, and there are no entry xrefs.
- No project-defined IDA type exists for `MidiDocument`, the adapter/DATFile source subobject, or exact source helper names.
- Prior reports and support pages contain stale `static int MidiOpenSource(...)` leads that must not be copied forward.
- The current generated file still has an empty UID `0002BZ` marker and a stale loader call shape.
- The target should remain below final-audit confidence because original source names and source-file split are not recovered.

## Ranked Ownership Analysis

1. [UID:0000LD] `MidiPlayer` - best owner and emitter. This page already owns the MIDI SMF helper family, accepted helper/type vocabulary, and generated output route. UID `0002BZ` already names it as canonical owner and emitter.
2. [UID:00023B] `MidiFileReaderAndSMFParserHelpers` - useful parent aggregate, but not a source emitter. It should inventory the helper and track follow-up state, not own the source output.
3. [UID:0002C7] `MidiSMFDocumentLoadHelper` - support page that must be repaired. It contains equivalent open logic inline in live decompilation, but it does not own the raw helper range.
4. DATFile/source adapter pages - rejected. The helper consumes a DATFile/source adapter interface, but the receiver and surrounding file-backed path are the MIDI document/source helper family.
5. `MidiPlayer` class page - rejected as canonical placement. The raw receiver is a `MidiDocument`/source context helper, not the public `MidiPlayer` object.
6. New `MidiSMFDocument.cpp` or separate source file - rejected for this pass. It remains historically plausible as a source split, but there is no stronger file-level evidence than current UID `0000LD` ownership.

## Source Placement

Recommended source placement is still `NexusTK/audio/MidiPlayer.cpp` under [UID:0000LD] `MidiPlayer`.

The target should be emitted as a private file-scope helper near the other source helpers. It should use the same source-facing field and helper vocabulary already accepted in sibling pages:

- `MidiDocument* document`
- `document->datFileSource`
- `document->datFile`
- `document->fileHandle`
- `INVALID_HANDLE_VALUE`
- `g_pfnCreateFileW`

No support evidence justifies a new by-file owner, a move to a DATFile page, or a class-method reconstruction.

## First-Draft C++ Recommendation

Recommended formal insertion text for UID `0002BZ`:

```cpp
static void MidiOpenSource(MidiDocument* document, const wchar_t* path)
{
    if (document->datFileSource != 0) {
        document->datFile.Open(path);
        document->fileHandle = INVALID_HANDLE_VALUE;
        return;
    }

    document->fileHandle = g_pfnCreateFileW(path,
                                            GENERIC_READ,
                                            FILE_SHARE_READ,
                                            NULL,
                                            OPEN_EXISTING,
                                            FILE_ATTRIBUTE_NORMAL,
                                            NULL);
}
```

Notes for implementation:

- Keep the return type `void`.
- Do not test the return value in callers.
- Use `g_pfnCreateFileW` rather than `dword_69BE34` or `unk_69BE34`.
- Keep `FILE_ATTRIBUTE_NORMAL` for raw `0x80`.
- Keep `INVALID_HANDLE_VALUE` for raw `0xFFFFFFFF`.
- Do not add error checking to this helper; readiness and file-size validation belong to `MidiSourceIsReady`.

## Final Recommendation

Implement UID `0002BZ` with the `static void MidiOpenSource(...)` formal C++ block above, raise the target score to `88/90`, and update support docs so the loader no longer treats `MidiOpenSource` as a boolean/int failure-return helper.

This is not a fallback-only recommendation. MCP was available and supplied the direct raw-body, cross-reference, dispatch-slot, and loader-decompilation evidence needed to resolve the report-only assignment.

## Recommended Target Doc Changes

For `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`:

- Update score metadata from `85/90` to `88/90`.
- Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`.
- Replace the blank formal C++ block with the `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)` code from this report.
- Add a source-quality note dated `2026-07-05` stating that B007 live MCP resolved the source-facing return-type blocker: the raw mixed EAX result is incidental because no entry xrefs consume it, and source readiness belongs to UID `0002C3`.
- Add the exact MCP facts for:
  - no IDA function at `0x00526f10`/`0x00526f57`;
  - zero xrefs to `0x00526f10`;
  - exact branch behavior and `this+0x2c` store;
  - `0x0069be34` startup initialization from `CreateFileW`;
  - loader `0x005273a0` opening inline then validating separately.
- Preserve the existing warning that exact adapter/source type names are not recovered.
- Remove or revise wording that keeps the C++ block blank solely because `MidiOpenSource` declaration/return semantics are unsafe.

## Recommended Support Doc Changes

For `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`:

- Replace the stale loader source-open fragment:

```cpp
if (MidiOpenSource(document, path) != 0) {
    return 0;
}
```

with:

```cpp
MidiOpenSource(document, path);
if (!MidiSourceIsReady(document)) {
    return 0;
}
```

- Update open questions and change notes to mark the UID `0002BZ` source-open abstraction as resolved by the `void` helper plus UID `0002C3` readiness check.
- Preserve the current loader score unless the implementing agent finds additional loader-specific changes beyond this support repair.

For `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`:

- Update the child inventory for UID `0002BZ` from second-batch follow-up to formal helper emitted as `MidiOpenSource`.
- Preserve the exact range `0x00526f10-0x00526f57` and padding `0x00526f57-0x00526f60`.
- Remove statements that say UID `0002BZ` remains blocked by the source-open return conflict.
- No parent score increase is required for this targeted implementation, but a small completion increase would be defensible if the supervisor wants aggregate scores to track child completion.

For `by-file/MidiPlayer.md`:

- Update the private helper/declaration list to use `static void MidiOpenSource(MidiDocument* document, const wchar_t* path);` where a prototype is shown.
- Remove UID `0002BZ` from the remaining empty/follow-up marker list after the target implementation is incorporated.
- Add a brief note that B013's source-open conflict was resolved by treating open as side-effect-only and delegating failure/readiness validation to `MidiSourceIsReady`.
- Keep UID `0002B1`, UID `0001CE`, UID `0001CG`, and UID `0002C4` as separate follow-ups if they are still unresolved at implementation time.

For generated output:

- Do not manually edit `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- After normal validator/application flow, confirm the refreshed generated file contains `static void MidiOpenSource(...)`, no UID `0002BZ` empty marker, and the repaired loader call sequence.

No change is needed for `by-global/WideApiDispatchTable.md`; it already supports the named `g_pfnCreateFileW` slot.

## Score And Metadata Recommendation

Recommended target score: `88/90`.

Rationale:

- Completion should increase from 85 to 88 because the formal helper body, source-facing return type, owner/emitter route, dispatch pointer identity, and support-doc repair are now all specified.
- Confidence should stay at 90 because the original source symbol/type names and source-file split remain inferred, and IDA still does not model the raw helper as a function.
- The combined score remains above the reconstruction gate but below final-audit territory.

Metadata:

| Field | Recommendation |
|---|---|
| `CANONICAL_OWNER` | Keep `0000LD` |
| `RECONSTRUCTABLE` | Keep `TRUE` |
| `EMITTER_UIDS` | Keep `0000LD` |
| `EMITTER_POSITION_OPTIONAL` | Leave unchanged/blank unless the support validator requires ordering near source helpers |
| `C++` | Add formal `static void MidiOpenSource(...)` block |

## Open Questions With Attempted Resolution

Open question: Is the raw helper return value meaningful?

Attempted resolution: MCP found no entry xrefs to `0x00526f10`, while the real loader decompilation opens the source inline and validates separately. The mixed adapter result / Win32 handle in EAX is therefore not a safe source contract. Treat as resolved for this target by using a `void` helper and moving validation to `MidiSourceIsReady`.

Open question: What is the exact source type of `document->datFile` or the adapter-backed source?

Attempted resolution: MCP `type_query` and local by-type searches did not recover a project-defined MIDI document/source adapter type. Sibling docs already use role-based `MidiDocument` and DATFile/source field names. This remains a confidence cap but not a completion blocker.

Open question: Should the helper live in a separate `MidiSMFDocument` source file?

Attempted resolution: No current by-file, generated output, or MCP evidence supports a stronger owner than UID `0000LD` `MidiPlayer`. Keep `NexusTK/audio/MidiPlayer.cpp` placement.

Open question: Does this require resolving UID `0002B1` or other remaining empty markers first?

Attempted resolution: No. UID `0002B1` and related declaration cleanup remain important for the broader generated file, but UID `0002BZ` can be implemented with current accepted `MidiDocument`, `MidiSourceIsReady`, and `g_pfnCreateFileW` vocabulary. The implementing agent should avoid broad family claims until the other markers are resolved.

## Validator Results

Initial report-only pass: no validators were run before Gate1. MCP was available and used successfully, so this report is not based on fallback-only evidence.

Implementation callback scoped validators were run from `source-3/project-documentation` after the accepted target/support by-* content was present:

| Scope | Command | command_id | command_timestamp | Exit | ok | Reported side effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| Target UID0002BZ | `python .\tools\validator.py --mode file --file by-memory\0x00526f10-0x00526f57.MidiSourceOpenHelper.md --apply --queue-timeout 240` | `000000007170` | `2026-07-05T15:26:40-04:00` | 0 | 1 | `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred` |
| Loader support UID0002C7 | `python .\tools\validator.py --mode file --file by-memory\0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md --apply --queue-timeout 240` | `000000007171` | `2026-07-05T15:26:46-04:00` | 0 | 1 | `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred` |
| Parent aggregate UID00023B | `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --queue-timeout 240` | `000000007172` | `2026-07-05T15:26:57-04:00` | 0 | 1 | `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred` |
| Owner/support by-file UID0000LD | `python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --queue-timeout 240` | `000000007173` | `2026-07-05T15:27:06-04:00` | 0 | 1 | `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred` |

Queue/freshness check:

| Command | command_id | command_timestamp | Exit | Result |
| --- | --- | --- | ---: | --- |
| `python .\tools\validator.py --queue-status` | `000000007174` | `2026-07-05T15:27:34-04:00` | 0 | Worker running; queued jobs `0`; processing jobs `0`; queued generated refresh jobs `0`; processing generated refresh jobs `0`; generated refresh results `6282`. |

Generated freshness:

- `auto-generated/NexusTK/audio/MidiPlayer.cpp` refreshed through validator side effects, not by hand. Header is `validator-command-id: 000000007173`, `validator-refreshed-at: 2026-07-05T15:27:06-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Generated `MidiPlayer.cpp` contains UID0002BZ at line `1004`, formal `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)` at line `1005`, `g_pfnCreateFileW` at line `1013`, and the loader sequence `MidiOpenSource(document, path);` / `if (!MidiSourceIsReady(document)) {` at lines `1263-1264`.
- `rg` for `EMPTY`, `empty marker`, and `UID:0002BZ` in generated `MidiPlayer.cpp` returned only the UID0002BZ emitted-code marker at line `1004`; no UID0002BZ empty marker remained.
- `auto-generated/-ag-research-tracker.md` refreshed through validator side effects with `validator-command-id: 000000007173`, `validator-refreshed-at: 2026-07-05T15:27:06-04:00`; UID0002BZ row reports `88/90`, average `89.0`, reconstructable `true`, report count `0`.
- `auto-generated/-ag-memory-coverage.md` refreshed through validator side effects with `validator-command-id: 000000007172`, `validator-refreshed-at: 2026-07-05T15:26:57-04:00`; UID0002BZ row reports `coded`, owner/emitter `0000LD`, generated path `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- `auto-generated/-ag-coverage-report-by-memory.md` refreshed through validator side effects with `validator-command-id: 000000007172`, `validator-refreshed-at: 2026-07-05T15:26:57-04:00`; UID0002BZ row reports `emits_code:true` and the updated side-effect-only `MidiOpenSource` summary.

No `execute_report`, dry-run execution variant, lifecycle/archive command, report move, manual generated edit, manual coverage edit, manual project-level generated edit, or manual validator-state edit was run.

## Changed Files

Hand-edited implementation/report files in this callback lifecycle:

- `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`: target metadata and formal `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)` C++; MCP/source-quality evidence; score and confidence cap rationale; stale boolean-return history.
- `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`: loader support repair to `MidiOpenSource(document, path);` followed by `if (!MidiSourceIsReady(document)) { return 0; }`; historical `static int`/boolean model rejected-stale.
- `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`: parent aggregate child inventory and disposition updated so UID0002BZ is formal `MidiOpenSource`; exact range/padding preserved; UID0002C4 remains separate follow-up.
- `by-file/MidiPlayer.md`: source-quality declaration and follow-up cleanup updated so UID0002BZ is no longer a remaining empty/follow-up marker; UID0002B1, UID0001CE, UID0001CG, and UID0002C4 remain separate follow-ups.
- `tools/leaser/Agents/Agent-B007/research/0002BZ-MidiSourceOpenHelper-source-quality.md`: callback bookkeeping update to this report's Claim And Incorporation Ledger, Validator Results, Changed Files, generated freshness notes, lease status, and Implementation Tracking Checklist.

Validator-owned/generated side effects observed from the scoped validators:

- `project-level/-auto-completion-stats.md`: validators reported `projected_stats_update: 1` for commands `000000007170` through `000000007173`.
- `auto-generated/NexusTK/audio/MidiPlayer.cpp`: refreshed by deferred generated refresh from command `000000007173`.
- `auto-generated/-ag-research-tracker.md`: refreshed by deferred generated refresh from command `000000007173`.
- `auto-generated/-ag-memory-coverage.md`: refreshed by deferred generated refresh from command `000000007172`.
- `auto-generated/-ag-coverage-report-by-memory.md`: refreshed by deferred generated refresh from command `000000007172`.

These generated/project-level updates were validator side effects only. B007 did not hand-edit generated output, project-level generated reports, manual `-coverage-report.md` files, validator registry/state files, queue files, lock files, lifecycle/archive files, or executed-report folders.

Leases:

- Pre-callback resume check: `tools/leaser/Agents/current_leases.md` showed no active leases.
- Validation/edit-batch lease acquired as `B007` for the four target/support docs: target UID0002BZ, loader support UID0002C7, parent aggregate UID00023B, and `by-file/MidiPlayer.md`.
- Lease release command for the same four docs returned `Success` for all four paths.
- Post-release `tools/leaser/Agents/current_leases.md` showed no active leases.

Report execution/lifecycle status:

- `execute_report`: not run.
- `execute_report` dry-run/status/probing variants: not run.
- Registry lifecycle commands such as `execute-rescan-reports`, `execute-confirm-change`, `executed-reassign`, `invalidate_execute`, `executed-mark-invalid`, `executed-mark-needs-revalidation`, or `executed-clear-revalidation`: not run.
- Manual report moves into `research/executed/` or `executed-b-agent-research/`: not performed.
- Archive commands or archive-folder edits: not performed.
- Scoped by-* validators: run only for the four changed target/support docs listed above.
- Generated-file edits or validator-state edits: not performed manually.

## Implementation Tracking Checklist

Initial report-only pass, Gate1 accepted:

- [x] Supervisor Gate1 validation completed before target/support by-* implementation; accepted Gate1 artifact hash was `E5E8ACF15D934A64CF5870CD9B771FDDF24355E1A1ADAB512F400F818873B62C`.
- [x] Assignment state recorded: UID `0002BZ`, path `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`, assignment-time score `85/90`, average `87.5`, blank C++, `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`.
- [x] Evidence recorded: MCP `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `get_global_value`, `decompile`, and `type_query`; target/support docs; generated `MidiPlayer.cpp`; tracker row; prior B001/B007/B012/B013 reports.
- [x] Claim And Incorporation Ledger contained claim ID, claim, confidence, evidence, destination doc/section, action, and report-only verification state for target, support, generated-output, stale-history, and explicit-exclusion claims.
- [x] Target score/metadata decision recorded: raise UID0002BZ to `88/90`, keep owner/emitter/reconstructable metadata, leave `EMITTER_POSITION_OPTIONAL` blank unless validator ordering requires otherwise.
- [x] Target C++ decision recorded: replace blank formal C++ with `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)` using adapter open plus `INVALID_HANDLE_VALUE`, or `g_pfnCreateFileW` to store the Win32 handle.
- [x] Source-quality facts recorded: exact raw range `0x00526f10-0x00526f57`, padding `0x00526f57-0x00526f60`, no IDA function model, zero entry xrefs, adapter branch, file branch, dispatch slot `0x0069be34`, loader inline-open/readiness split, and type-query negative evidence.
- [x] Source placement and exclusions recorded: private file-scope helper under [UID:0000LD] `MidiPlayer` / `NexusTK/audio/MidiPlayer.cpp`; reject DATFile/source-adapter ownership, `MidiPlayer` class-method ownership, UID0002C7 loader ownership, UID00023B parent ownership, and a new `MidiSMFDocument.cpp` owner.
- [x] Support changes identified: UID0002C7 loader repair, UID00023B aggregate inventory/follow-up repair, `by-file/MidiPlayer.md` helper declaration and follow-up cleanup, and no edit for `by-global/WideApiDispatchTable.md` because `g_pfnCreateFileW` support was already present.
- [x] Stale/historical assumptions recorded: B001/B013 `static int MidiOpenSource(...)` and `if (MidiOpenSource(document, path) != 0)` must be preserved as rejected-stale history rather than copied forward.
- [x] Validators and generated expectations recorded: scoped validators for the four changed by-* docs; generated `MidiPlayer.cpp` should emit UID0002BZ, remove the empty marker, and show `MidiOpenSource` followed by `MidiSourceIsReady`.
- [x] Manual coverage/tracker non-applicability recorded: no manual `-coverage-report.md`, generated tracker, project-level generated file, validator-state, generated C++ edit, lifecycle/archive edit, or executed-report edit authorized.

Implementation callback pass, Gate2 candidate:

- [x] Callback authorization received after Gate1 pass. No implementation callback item is blocked by Gate1 status.
- [x] Lease state checked before the validation/bookkeeping resume: `tools/leaser/Agents/current_leases.md` showed no active leases.
- [x] Short B007 lease acquired for the four target/support docs and released after scoped validators; release command returned `Success` for all four paths, and the post-release lease report showed no active leases.
- [x] Target page updated at `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`: score is `88/90`; `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, and blank `EMITTER_POSITION_OPTIONAL` are preserved; the Item Summary, behavior notes, source-state notes, evidence, reconstruction notes, cross-references, and changes carry the UID0002BZ source-open implementation details.
- [x] Exact formal target C++ is present in the target's formal `RECONSTRUCTION_CPP CODE` block:

```cpp
static void MidiOpenSource(MidiDocument* document, const wchar_t* path)
{
    if (document->datFileSource != 0) {
        document->datFile.Open(path);
        document->fileHandle = INVALID_HANDLE_VALUE;
        return;
    }

    document->fileHandle = g_pfnCreateFileW(path,
                                            GENERIC_READ,
                                            FILE_SHARE_READ,
                                            NULL,
                                            OPEN_EXISTING,
                                            FILE_ATTRIBUTE_NORMAL,
                                            NULL);
}
```

- [x] Target page incorporates MCP facts at report-level detail: exact raw range/padding, no IDA function model, zero entry xrefs, adapter virtual open branch, file branch through `g_pfnCreateFileW`, startup `CreateFileW` initializer, loader inline-open plus separate readiness validation, type-query negative evidence, and confidence caps.
- [x] UID0002C7 loader support repaired in `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`: formal C++ now uses `MidiOpenSource(document, path);` followed by `if (!MidiSourceIsReady(document)) { return 0; }`; detailed notes, reconstruction notes, open questions, and changes mark the boolean-return model rejected-stale.
- [x] UID00023B parent aggregate repaired in `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`: UID0002BZ now emits formal side-effect-only `MidiOpenSource`, exact range `0x00526f10-0x00526f57` and padding `0x00526f57-0x00526f60` remain, and source-open return semantics are no longer listed as an active blocker. UID0002C4 remains a separate follow-up.
- [x] `by-file/MidiPlayer.md` support repaired: UID0002BZ is documented as private file-scope `static void MidiOpenSource(MidiDocument* document, const wchar_t* path)`, removed from the remaining empty/follow-up marker list, and UID0002B1, UID0001CE, UID0001CG, and UID0002C4 are preserved as separate follow-ups.
- [x] `by-global/WideApiDispatchTable.md` was intentionally not edited because the accepted report said `g_pfnCreateFileW` support was already present; the target/by-file docs use the named dispatch pointer.
- [x] Stale/historical evidence preserved while superseded: target, loader, parent aggregate, and by-file docs explicitly reject the historical `static int MidiOpenSource(...)` / boolean-return model as stale current truth.
- [x] Explicit exclusions preserved: the implementation does not move UID0002BZ to DATFile/source adapter docs, a `MidiPlayer` class method, UID0002C7, UID00023B, a new source file, or unrelated sibling targets.
- [x] Claim And Incorporation Ledger updated from `proposed` to callback states: `applied`, `already-present`, and `excluded-with-reason`; no accepted claim is `blocked`.
- [x] Scoped validators run and recorded above: `000000007170`, `000000007171`, `000000007172`, and `000000007173`, all exit `0`, all `ok: 1`.
- [x] Generated freshness checked after deferred refresh: queue-status command `000000007174` found no queued or processing jobs; generated `MidiPlayer.cpp` header matches command `000000007173`, emits UID0002BZ formal C++, has no UID0002BZ empty marker, and the loader uses `MidiOpenSource` plus `MidiSourceIsReady`.
- [x] Generated tracker/coverage freshness checked as validator side effects: research tracker row reports UID0002BZ `88/90`, average `89.0`; memory coverage reports UID0002BZ `coded`; by-memory coverage reports `emits_code:true`.
- [x] No manual generated output, generated tracker, project-level generated file, manual `-coverage-report.md`, validator registry/state, queue/lock, executed-report folder, archive folder, or lifecycle history edit was performed.
- [x] No `execute_report`, dry-run/status/probing variant, registry lifecycle command, manual report move, or archive command was run. Stop condition for this agent is `READY_FOR_SUPERVISOR_GATE2_REVIEW` per supervisor callback instruction.
- [x] Remaining blockers: none for accepted UID0002BZ callback scope. No accepted checklist item remains unapplied; remaining UID0002B1, UID0001CE, UID0001CG, and UID0002C4 work is explicitly out of scope for this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000007179","destination_path":"executed-b-agent-research/B007/0002BZ-MidiSourceOpenHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002BZ-MidiSourceOpenHelper-source-quality.md","timestamp":"2026-07-05T15:37:51-04:00","uid":"0002BZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
