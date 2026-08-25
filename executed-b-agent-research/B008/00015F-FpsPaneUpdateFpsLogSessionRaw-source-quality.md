** TARGET-REPORT-UID:00015F **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B008 Report: UID 00015F FpsPaneUpdateFpsLogSessionRaw Source Quality

Assignment: `B008-report-00015F-fps-pane-update-fps-log-session-raw-20260625`

Target: [UID:00015F] `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md`

Report-only constraints observed:

- No leases were taken.
- No subagents were spawned.
- No IDA database edits were made.
- No by-* documentation, generated/project-level files, validator state/cache, coverage reports, or IDA DB files were edited.
- IDA MCP endpoint `http://127.0.0.1:13337/mcp` was available and used for the evidence pass.

## Executive Recommendation

Keep UID `00015F` as reconstructable FpsPane source, owned and emitted by [UID:00005F] `FpsPane`. The current first-draft C++ body is the right source shape and should be retained: `FpsPane::UpdateFpsLogSession(bool startNew)` calling `StartLogSession()` and `WriteLogSummary()` is more plausible source than preserving three duplicated raw bodies in the emitted toggle method.

Recommended target metadata after incorporation:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `88` | `89` | Current MCP pass confirms the raw boundary, 190-instruction body, neighbor function inventory, helper duplicate relationship, string/global xrefs, body hash, and negative pointer-route search. |
| `CONFIDENCE` | `88` | `89` | Ownership/source placement are strongly corroborated by current live IDA evidence; confidence remains capped below final audit because no direct caller, xref, function object, or literal pointer reaches the raw entry. |
| `CANONICAL_OWNER` | `00005F` | `00005F` | Direct semantic owner is the `FpsPane` class. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored diagnostics method body with active formal C++ already present. |
| `EMITTER_UIDS` | `00005F` | `00005F` | The class emits the method; file [UID:0000JK] remains the source root. |
| `RECONSTRUCTION_CPP` | populated | retain as-is | The current helper-call draft is source-facing and should not be replaced by duplicated raw logging code. |

Do not raise this past `89/89` until a live route to `0x004b64a0` is recovered. The current no-route result has been actively investigated and is a final-audit score cap, not a blocker to owner, emitter, reconstructability, or first-draft C++.

## Current Target State

The live target header already reads:

- `COMPLETION:88`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00005F`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005F`
- Formal C++: `void FpsPane::UpdateFpsLogSession(bool startNew)`

The current body:

```cpp
void FpsPane::UpdateFpsLogSession(bool startNew)
{
    Rect rect(10, 10, 490, 22);

    if (startNew && !IsVisible()) {
        StartLogSession();
        SetFrameRect(&rect, 0, 0, g_pFpsPaneParentPane);
        m_frameCount = 0;
        m_updateTimer.StartTimer(0, 1000, 0, 0);
        return;
    }

    WriteLogSummary();
    Hide();
    m_updateTimer.RemoveTimer();
}
```

This should remain. `g_pFpsPaneParentPane` is still a descriptive dependency name for [UID:0000T6] `MainUiLayerSlots` address `0x0069b37c`; the dependency is not FpsPane-owned storage.

## IDA MCP Provenance

Endpoint: `http://127.0.0.1:13337/mcp`

Active IDB session:

- Session ID: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready`: `true`
- `hexrays_ready`: `true`
- `strings_cache_ready`: `true`
- `strings_cache_size`: `2067`

MCP tools used: `server_health`, `lookup_funcs`, `entity_query`, `decompile`, `insn_query`, `xrefs_to`, `get_bytes`, `get_string`, and `find_bytes`.

## Binary Boundary Evidence

Current `lookup_funcs` results:

| Address | Result |
| --- | --- |
| `0x004b6470` | function `sub_4B6470`, size `0x29` |
| `0x004b64a0` | not a function |
| `0x004b67a7` | not a function |
| `0x004b67b0` | function `sub_4B67B0`, size `0xfb` |
| `0x004b68b0` | function `sub_4B68B0`, size `0x100` |
| `0x004b69b0` | not a function |
| `0x004b6adc` | not a function |
| `0x004b6ae0` | not a function |
| `0x004b6c2b` | function `sub_4B6C2B`, size `0xb` |
| `0x004b6c36` | function `sub_4B6C36`, size `0xb` |
| `0x004b6c50` | function `sub_4B6C50`, size `0x5f` |

`entity_query` over `0x004b6400-0x004b6cc0` returns only these function starts in the FpsPane island: `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, `0x004b6c50`, plus the next unrelated Boost exception destructor at `0x004b6cb0`.

`decompile` results:

| Address | Result |
| --- | --- |
| `0x004b64a0` | failed, no function/decompile body |
| `0x004b69b0` | failed, no function/decompile body |
| `0x004b6ae0` | failed, no function/decompile body |
| `0x004b67b0` | succeeds, `void __thiscall sub_4B67B0(int this)` |
| `0x004b68b0` | succeeds, `char __thiscall sub_4B68B0(int this, int a2, int a3, int a4)` |
| `0x004b6c2b` | succeeds, `_DWORD *__thiscall sub_4B6C2B(_DWORD *this, char a2)` |

`insn_query` bounded ranges:

| Range | Count | First | Last | Function metadata |
| --- | ---: | --- | --- | --- |
| `0x004b64a0-0x004b67a8` | 190 | `0x4b64a0` | `0x4b67a7` | all entries `fn:null` |
| `0x004b69b0-0x004b6ae0` | 70 | `0x4b69b0` | `0x4b6adc` | all entries `fn:null` |
| `0x004b6ae0-0x004b6c2b` | 84 | `0x4b6ae0` | `0x4b6c2a` | all entries `fn:null` |

The target body begins with the normal thiscall/security-cookie prologue:

- `0x004b64a0`: `push ebp`
- `0x004b64a1`: `mov ebp, esp`
- `0x004b64a3`: `sub esp, 18h`
- `0x004b64a6`: `mov eax, ___security_cookie`
- `0x004b64ba`: `mov edi, ecx`

The body splits on the byte argument and visibility:

- `0x004b64c6`: `cmp byte ptr [ebp+8], 0`
- `0x004b64ca`: false argument jumps to finalize path at `0x004b6645`
- `0x004b64d2`: calls `sub_544C50` for the visible-state check
- `0x004b64d9`: already-visible jumps to finalize path at `0x004b6645`

It has two real return sites and alignment:

- `0x004b6642`: start-path `retn 4`
- `0x004b67a4`: finalize-path `retn 4`
- `0x004b67a7`: alignment before `0x004b67b0` modeled paint method

Byte evidence:

| Address | Size | SHA-256 | Head | Tail |
| --- | ---: | --- | --- | --- |
| `0x004b64a0` | 776 | `5dfaffba35e1013a192cd1c812c0c135b0544b94a515d10f148dfb75c6de596e` | `55 8b ec 83 ec 18 a1 24 2f 67 00 33 c5 89 45 fc` | `fc 33 cd 5f e8 8e 0f 11 00 8b e5 5d c2 04 00 cc` |
| `0x004b69b0` | 304 | `01eb262fd8ce115c25c0e944d9cf072fc0a831e3daa447532daff61ba0844a73` | `55 8b ec 51 57 8b f9 ff 15 0c d5 60 00 83 3d 90` | `da 66 00 00 00 00 00 5f 8b e5 5d c3 cc cc cc cc` |
| `0x004b6ae0` | 331 | `93961235a91a75d1f83b1948791f7d46150a9ccce1bd98019c57375390b6fd81` | `55 8b ec 51 80 3d 38 b3 69 00 00 56 8b f1 0f 84` | `ff 75 fc e8 49 ba 11 00 83 c4 40 5e 8b e5 5d c3` |

Boundary bytes before and after the target remain stable:

- `0x004b6490`: prior body tail/jump then `cc` padding before the `0x004b64a0` prologue.
- `0x004b67a0`: finalize epilogue `mov esp, ebp; pop ebp; retn 4; cc...` followed by the `0x004b67b0` prologue.

## Xrefs, Data Flow, And Helper Relationship

No xrefs reach the exact target start or final alignment address:

| Address | Current xref count |
| --- | ---: |
| `0x004b64a0` | 0 |
| `0x004b67a7` | 0 |
| `0x004b69b0` | 0 |
| `0x004b6ae0` | 0 |

Positive neighbor/control xrefs remain consistent:

| Address | Current xrefs |
| --- | --- |
| `0x004b67b0` | data xref `0x61a664` |
| `0x004b68b0` | data xref `0x61a6a0` |
| `0x004b6c2b` | data xref `0x61a66c` |
| `0x004b6c36` | data xref `0x61a69c` |
| `0x004b6c50` | code xrefs from `0x4b6c31` and `0x4b6c3c`, data xref `0x61a620` |

The global refs prove FpsPane diagnostics ownership and pair this target with the retained helper bodies:

| Global | Xrefs |
| --- | --- |
| `0x0066da90` / `g_fpsDebugActive` | `0x4b64e5`, `0x4b65f5`, `0x4b69bd`, `0x4b6acd` |
| `0x0069b338` / `g_fpsLogEnabled` | `0x4b653f`, `0x4b6645`, `0x4b6a17`, `0x4b6ae4` |
| `0x0069b37c` / `MainUiLayerSlots` dependency | target use at `0x4b65ff`, plus Main UI setup/consumer refs outside this class |

The string xrefs are exactly paired between the target body and the retained helpers:

| String/data address | Role | Current xrefs |
| --- | --- | --- |
| `0x0061a6a4` | `FPSDATA-%d-%d-%d-%d-%d.txt` | `0x4b6588`, `0x4b6a60` |
| `0x0061a6c0` | `"w"` | `0x4b6595`, `0x4b6a6d` |
| `0x0061a6c4` | `***NEW_CLIENT***\n` | `0x4b65a4`, `0x4b6a7c` |
| `0x0061a6d8` | CP949 start timestamp literal/data | `0x4b65d9`, `0x4b6ab1` |
| `0x0061a700` | `"a"` | `0x4b6652`, `0x4b6af4` |
| `0x0061a704` | divider | `0x4b6667`, `0x4b6b09` |
| `0x0061a720` | CP949 elapsed-time literal/data | `0x4b6690`, `0x4b6b32` |
| `0x0061a734` | `minFPS : %5.1f\n` | `0x4b66b0`, `0x4b6b52` |
| `0x0061a744` | `maxFPS : %5.1f\n` | `0x4b66d0`, `0x4b6b72` |
| `0x0061a754` | `aveFPS : %5.1f\n` | `0x4b670b`, `0x4b6bad` |
| `0x0061a764` | `aveLivingObject  : %d\n` | `0x4b6727`, `0x4b6bc9` |
| `0x0061a77c` | `aveBalloonObject : %d\n` | `0x4b6743`, `0x4b6be5` |
| `0x0061a794` | `aveStaticObject  : %d\n` | `0x4b675f`, `0x4b6c01` |
| `0x0061a7ac` | closing divider | `0x4b676c`, `0x4b6c0e` |
| `0x0061a7c8` | UTF-16-ish `"%5.1f FPS"` display format | `0x4b67f7` in `OnPaint` |

`get_string` returns normal strings for the ASCII rows above and returns `No string at address` for `0x0061a6d8` and `0x0061a720`. Do not use that null result to delete or relabel those rows. The xrefs prove they are still consumed as FpsPane diagnostic literal/data rows; their current docs correctly treat them as CP949/non-normal-string data.

## Pointer-Route Search

`find_bytes` was run for loaded-image VA, RVA, and raw-offset little-endian forms of the target start/end and helper starts. All checked patterns returned zero matches:

- `0x004b64a0`: `a0 64 4b 00`, `a0 64 0b 00`, `a0 58 0b 00`
- `0x004b67a7`: `a7 67 4b 00`, `a7 67 0b 00`, `a7 5b 0b 00`
- end-exclusive `0x004b67a8`: `a8 67 4b 00`, `a8 67 0b 00`, `a8 5b 0b 00`
- `0x004b69b0`: `b0 69 4b 00`, `b0 69 0b 00`, `b0 5d 0b 00`
- `0x004b6ae0`: `e0 6a 4b 00`, `e0 6a 0b 00`, `e0 5e 0b 00`

This closes the obvious static route checks for this pass. The remaining live-entry question is real, but it is no longer an uninvestigated blocker.

## Heuristic And Inference Reanalysis

Rejected alternatives:

- ParcelPane ownership: rejected. The body uses FpsPane diagnostics globals, FpsPane layout fields, FpsPane logging strings, FpsPane pane show/hide flow, and the FpsPane timer subobject.
- MapPane/ObjectList ownership: rejected. Those systems are only diagnostic data sources for object counts in the FpsPane statistics pipeline.
- MainUiLayerSlots ownership: rejected. `0x0069b37c` is a parent/layer dependency consumed at `0x004b65ff`, not the owner of the method, fields, strings, globals, or vtables.
- Compiler thunk/destructor/scalar-delete explanation: rejected. The body has source-like session logic, file I/O, dual branch flow, diagnostics state, and `retn 4`; neighbor thunk/destructor functions are separately modeled at `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`.
- Dead padding/data: rejected. The body decodes as 190 coherent instructions with a thiscall prologue, security cookie, two returns, and stable code/data refs.
- Forced merge into helper-only pages: rejected. The target is the active session-toggle method. The helper pages at `0x004b69b0` and `0x004b6ae0` remain retained/private helper bodies or old helper implementations duplicated/inlined into the toggle method. They support the source helper-call draft but do not replace UID `00015F`.

Positive route:

- Direct semantic owner: [UID:00005F] `FpsPane`.
- Source file/root: [UID:0000JK] `FpsPane`, path `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Emitter: [UID:00005F] `FpsPane`.
- Formal source name: `FpsPane::UpdateFpsLogSession(bool startNew)`.
- Helper names: `StartLogSession()` and `WriteLogSummary()` are source-facing and already supported by child pages [UID:00015I] and [UID:00015J].

## Source Placement And Support-Doc Recommendations

Target page:

- Add a 2026-06-25 B008 evidence subsection recording MCP session `80de0a67`, exact function inventory, decompile results, instruction counts, xrefs, byte hash, pointer-route search, and CP949 `get_string` caveat.
- Raise target score to `89/89` if the evidence subsection is incorporated.
- Retain `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F`.
- Retain the current formal C++ body unchanged.
- Tighten the item summary to emphasize source-facing `UpdateFpsLogSession(bool)`, current raw/no-route state, FpsPane-local fields/globals/strings, helper duplicate relationship, and one-second timer/show-hide flow.

Support pages:

- `by-class/FpsPane.md`: update the method row/evidence notes to mention the 2026-06-25 B008 current MCP pass and the recommended target `89/89`; no class score change is required.
- `by-file/FpsPane.md`: update the placement notes only if the target score/summary changes; keep `NexusTK/ui/diagnostics/FpsPane.cpp`.
- `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`: add a short B008 refresh note for UID `00015F`; keep aggregate score unchanged unless the supervisor wants a separate aggregate review.
- `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md`: fix the stale `Item Summary` phrase saying "blank C++ pending raw-start resolution"; formal C++ exists and should remain. The no-route result is a liveness cap, not a C++ blocker.
- `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md`: fix the same stale `Item Summary` phrase; formal `FpsPane::WriteLogSummary()` C++ exists and should remain.
- Do not manually edit `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, or any `-coverage-report.md`. These files currently have stale `76/82` or `emits_code:false` rows for UID `00015F`; let validator/autogen refresh them under supervisor-authorized implementation workflow.

No filename rename is required for this report. The `Raw` suffix remains an acceptable boundary-status signal while the source-facing method name and formal C++ are already clear in the page body.

## First-Draft C++ Readiness

The target is first-draft C++ ready and already populated. The source should stay compact:

- `StartLogSession()` represents the duplicated start/reset/log-file creation body.
- `WriteLogSummary()` represents the duplicated append-summary body.
- `SetFrameRect`, `Hide`, `IsVisible`, `m_updateTimer.StartTimer`, and `m_updateTimer.RemoveTimer` remain descriptive names until the inherited Pane/timer declarations are finalized.
- `g_pFpsPaneParentPane` remains descriptive for the [UID:0000T6] `MainUiLayerSlots` dependency, not FpsPane storage.

Do not expand the target C++ into raw `fprintf`/`fopen_s` blocks. The child helper pages carry the source-facing helper bodies, and this toggle method should call them.

## Validation Plan For Supervisor Callback

No validators were run during this report-only pass because no by-* docs were edited.

If the report is accepted and by-* docs are edited, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed file. Minimum expected validator set for the recommended scope:

> Executable block R001 was removed from this report and preserved verbatim in [00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality-removed.md](00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only validators for files actually changed if the supervisor narrows implementation scope. Autogen/rescore refresh is supervisor-owned; do not hand edit generated files, project-level files, validator state/cache, or coverage reports.

## Residual Caps

The unresolved cap is precise and actively checked:

- No IDA function object at `0x004b64a0`.
- No decompile body for `0x004b64a0`.
- No xrefs to `0x004b64a0` or `0x004b67a7`.
- No loaded-image VA/RVA/raw-offset little-endian pointer hits for `0x004b64a0`, `0x004b67a7`, or `0x004b67a8`.
- No live route to helper raw starts `0x004b69b0` or `0x004b6ae0`.

These facts cap final-audit confidence, but they do not block source ownership, emitter routing, or formal C++ retention.

## Implementation Tracking Checklist

Implementation state: applied by Agent-B008 on 2026-06-25 after supervisor acceptance. The by-* docs were leased for edit/validator batches; the final unlease attempt found no active B008 leases remaining, and the current lease reports have no `B008`/FpsPane rows.

- [x] Update [UID:00015F] `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` with a 2026-06-25 B008 MCP evidence subsection covering session `80de0a67`, function/decompile map, 190-instruction target body, helper instruction counts, xrefs, byte SHA-256, pointer-route sweep, and CP949 string caveat.
  - Proof: target page now has `Rechecked on 2026-06-25 by Agent-B008`, session `80de0a67`, modeled/raw function map, decompile failures/success controls, `190`/`70`/`84` instruction counts, target SHA-256 `5dfaffba35e1013a192cd1c812c0c135b0544b94a515d10f148dfb75c6de596e`, current global/string xrefs, pointer-route negatives, and `get_string` caveat for `0x0061a6d8` / `0x0061a720`.
- [x] Change [UID:00015F] `COMPLETION` from `88` to `89` and `CONFIDENCE` from `88` to `89`; leave `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F` unchanged.
  - Proof: target header now reads `COMPLETION:89`, `CONFIDENCE:89`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F`.
- [x] Retain the existing `FpsPane::UpdateFpsLogSession(bool startNew)` formal C++ body unchanged.
  - Proof: the target formal block still contains the same helper-call body with `StartLogSession()`, `SetFrameRect(&rect, 0, 0, g_pFpsPaneParentPane)`, `m_updateTimer.StartTimer(0, 1000, 0, 0)`, `WriteLogSummary()`, `Hide()`, and `m_updateTimer.RemoveTimer()`.
- [x] Tighten the [UID:00015F] item summary to describe source-facing `UpdateFpsLogSession(bool)`, raw/no-route status, FpsPane-local evidence, helper duplicate relationship, and timer show/hide flow.
  - Proof: final target `Item Summary` now reads `FpsPane::UpdateFpsLogSession(bool) raw/no-route session toggle; MCP-backed FpsPane fields/globals, paired helper/log strings, timer show/hide flow, and no live entry route.`
  - Validator caveat: normal file/generated-refresh validator modes repopulated this by-memory summary from older manual coverage metadata. Full validator command `000000001072` passed before the final summary reapply; later `--uid-only` (`000000001087`) and `--reference-only` (`000000001093`) attempts demonstrated the stale backfill behavior while deferred generated-refresh work was still active. After the queue went idle, the accepted summary was reapplied and validated with `--uid-only --no-generated-refresh` command `000000001166`, exit `0`, `ok: 1`, generated refresh skipped; a 15-second post-validation check preserved the accepted source summary.
- [x] Add a short B008 refresh note to `by-class/FpsPane.md`; no class score change required.
  - Proof: class method row, method child gate, evidence notes, and change log now record target `89/89`, retained formal C++, MCP session `80de0a67`, target SHA-256, helper instruction counts, paired xrefs, and no-route as liveness cap. Class score was left unchanged.
- [x] Add or update the short placement note in `by-file/FpsPane.md` only if the target score/summary is changed; keep source root `NexusTK/ui/diagnostics/FpsPane.cpp`.
  - Proof: file proposed-contents row, evidence section, and change log now record UID `00015F` as `89/89` after B008 and keep `NexusTK/ui/diagnostics/FpsPane.cpp` as the accepted source root.
- [x] Add a short B008 refresh note to `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`; keep aggregate score unchanged unless separately reviewed.
  - Proof: aggregate covered-range row, remaining-cap note, and change log now record target `89/89`, 190-instruction body, target SHA-256, paired helper/global/string refs, and zero function/caller/pointer route. Aggregate score stayed unchanged.
- [x] Fix stale `Item Summary` wording in `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` so it no longer says "blank C++ pending raw-start resolution"; retain formal helper C++ and the no-route liveness cap.
  - Proof: final helper `Item Summary` now reads `MCP-backed retained private/source-facing FPS log-session reset helper with FpsPane parent, formal C++ present, raw no-route liveness cap, exact neighbor padding, and paired UpdateFpsLogSession/global/string refs.`
  - Validator caveat: normal file/generated-refresh validator modes blanked this summary from stale manual coverage metadata. Full validator command `000000001076` passed before the final summary reapply; later `--uid-only` (`000000001088`) and `--reference-only` (`000000001094`) attempts preserved exit success but did not keep the accepted summary while deferred generated-refresh work was still active. After the queue went idle, the accepted summary was reapplied and validated with `--uid-only --no-generated-refresh` command `000000001165`, exit `0`, `ok: 1`, generated refresh skipped; a 15-second post-validation check preserved the accepted source summary.
- [x] Fix stale `Item Summary` wording in `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` so it no longer says "blank C++ pending raw-start resolution"; retain formal helper C++ and the no-route liveness cap.
  - Proof: final helper `Item Summary` now reads `MCP-backed retained private/source-facing FPS summary writer with FpsPane parent, formal WriteLogSummary C++ present, raw no-route liveness cap, exact thunk boundary, and paired UpdateFpsLogSession/global/string refs.`
  - Validator caveat: normal file/generated-refresh validator modes repopulated this summary from older manual coverage metadata. Full validator command `000000001077` passed before the final summary reapply; later `--uid-only` (`000000001089`) and `--reference-only` (`000000001095`) attempts showed the same stale backfill behavior while deferred generated-refresh work was still active. After the queue went idle, the accepted summary was reapplied and validated with `--uid-only --no-generated-refresh` command `000000001167`, exit `0`, `ok: 1`, generated refresh skipped; a 15-second post-validation check preserved the accepted source summary.
- [x] Do not manually edit generated files, project-level files, validator state/cache, IDA DB, or any `-coverage-report.md`.
  - Proof: no manual edits were made to generated/project-level/coverage/tool-state/IDA DB files. Scoped validators reported normal tool-owned side effects, including `projected_stats_update`, `autogen_registry_update`, `reference_source_path_update`, and deferred generated refresh; those side effects were produced by validator commands, not manual edits.
- [x] Run scoped validators for every changed by-* doc from `source-3/project-documentation` and record command, exit code, warning count, and side effects.
  - Full file validators, all from `E:\NTK\GhidraBridge\source-3\project-documentation`, all exited `0` with `ok: 1`:
    - `python .\tools\validator.py --mode file --file by-memory\0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md --apply --queue-timeout 240`: command `000000001072`, timestamp `2026-06-25T03:49:01-04:00`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class\FpsPane.md --apply --queue-timeout 240`: command `000000001073`, timestamp `2026-06-25T03:49:05-04:00`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-file\FpsPane.md --apply --queue-timeout 240`: command `000000001074`, timestamp `2026-06-25T03:49:06-04:00`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004b6410-0x004b6caf.FpsPaneDiagnostics.md --apply --queue-timeout 240`: command `000000001075`, timestamp `2026-06-25T03:49:08-04:00`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md --apply --queue-timeout 240`: command `000000001076`, timestamp `2026-06-25T03:49:09-04:00`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md --apply --queue-timeout 240`: command `000000001077`, timestamp `2026-06-25T03:49:15-04:00`, generated refresh deferred.
  - Additional validator probes for the three summary-header files:
    - `--uid-only` commands `000000001087`, `000000001088`, and `000000001089` exited `0` with `ok: 1`, generated refresh skipped by `--uid-only`, but repopulated stale summary metadata.
    - `--reference-only` commands `000000001093`, `000000001094`, and `000000001095` exited `0`, generated refresh skipped by `--reference-only`; target command `000000001093` retained the known `missing_ref_uid 0003BJ` diagnostic. These commands also demonstrated that another header-mutating validator pass would not preserve the accepted summaries.
    - Final idle-queue summary validators `000000001165` (start helper), `000000001166` (target), and `000000001167` (write helper) ran with `--uid-only --no-generated-refresh`; all exited `0` with `ok: 1`, reported generated refresh skipped, and the accepted summaries remained stable after a 15-second queue-idle check.
  - Known validator diagnostics/side effects: old `00015I` raw-suffixed path references remain in some validator diagnostics; command `000000001076` produced broad pre-existing `by-memory/-coverage-report.md` missing-target diagnostics while updating the renamed `00015I` path references. No manual coverage report edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality.md","timestamp":"2026-06-25T04:20:15","uid":"00015F"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
