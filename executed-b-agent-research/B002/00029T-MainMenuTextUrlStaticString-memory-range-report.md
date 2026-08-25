** TARGET-REPORT-UID:00029T **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00029T MainMenuTextUrlStaticString Memory-Range Advanced-Scan Report

## Finalized Report / Current Recommendation

- Current recommendation: the scanner complaint is real because the target body does not contain the exact filename/topic token `MainMenuTextUrlStaticString`. This is primarily a scanner-visible label/text gap, but the audit also found stale raw-byte evidence and legacy ownership wording that should be repaired with the same text-only pass.
- Final disposition: keep current header routing as-is: `CANONICAL_OWNER:0000LG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LG`, blank C++.
- Required action: do not split, merge, reclassify, or change the range. Recommended follow-up is a target-page text repair plus a supervisor-owned `by-memory/-coverage-report.md` row replacement.
- Confidence: `90` overall. The owner/emitter route and boundaries are strongly supported; the only reason this is not higher is that the target page currently contains a stale `ff ff ff ff` raw-byte claim contradicted by current IDA/PE evidence.

## Supporting Research

## Target

- Target UID: `00029T`
- Target path: `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan line `232`
- Exact scanner complaint: `0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md: missing document text for MainMenuTextUrlStaticString`
- Current supervisor classification: `Supervisor_notes.md` marks this as `error-repair-assigned` to B002 for `B002-MR-00029T`.
- Current header state:
  - `COMPLETION:88`
  - `CONFIDENCE:92`
  - `CANONICAL_OWNER:0000LG`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000LG`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `RECONSTRUCTION_CPP CODE:` blank

## Executive Recommendation

The item should remain a reconstructable source-declared static string/object handle routed through [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). Current IDA confirms the same six direct refs documented by the page: startup construction, two packet writer paths, two `ProcessNCAUpdate` reader refs, and cleanup. `MiscWorkThread` remains the best semantic owner because its NCA worker is the only reader/consumer and it owns the fallback NCA confirm-user URL literal at [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md).

The current filename is legacy but not immediately harmful. The page title already uses the more accurate semantic name `NCA Auth Confirm-User URL Override Static String`. To clear the scanner without a coordinated rename, add explicit body text for the retained filename label `MainMenuTextUrlStaticString`.

Do not add reconstruction C++. The item is `88/92`, below the active `90/90+` code-entry completion gate, and the final source-level declaration spelling/type shape is still not fully recovered.

## Supervisor Active Recheck

- Supervisor instruction: audit whether the Advanced-Error-Scan finding is only a memory-ranges scanner-visible label/title mismatch or a real documentation/range/name/owner/emitter issue.
- Split repair: not required. The four-byte range is exact and has clean predecessor/successor xref separation.
- Direct edits: none performed by B002 because this assignment explicitly forbids direct by-* edits.
- In-scope source-bearing child: [UID:00029T] only. It remains source-bearing/reconstructable but should keep blank final C++ until the code gate is met.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership (`CANONICAL_OWNER`) from output routing (`EMITTER_UIDS`). Under that rule, the current `0000LG` / `0000LG` header is coherent: `MiscWorkThread` is both the semantic owner of the NCA URL override storage and the eventual output route.

The same guidance says legacy `AUTOGEN_PARENT_UID` wording should be interpreted as old combined ownership/output terminology. The target body still says `Autogen parent` and `Assign AUTOGEN_PARENT_UID:0000LG`; those body sentences should be rewritten to current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology even though the header metadata is already correct.

`inference_research.md` cautions that writer xrefs alone are not ownership proof. That matters here: `MainMenuPane` and `MapPane` write packet subtype-3 text into the slot, but the semantic URL behavior is in `ProcessNCAUpdate`, and the paired fallback URL object is already `MiscWorkThread`-routed.

## Evidence Standards Used

- Current documentation: target page, `MiscWorkThread`, `MainMenuPane`, `MapPane`, `StaticStringContainerCleanupThunks`, `NcauthConfirmUserUrlObfuscated`, `SurfacePixelFormatFlags`, `proposed-source-tree.md`, `Supervisor_notes.md`, generated memory coverage, and manual memory coverage.
- Current IDA MCP evidence from session `b001_0003gy`: `server_health`, `get_bytes`, `get_int`, `xrefs_to`, `lookup_funcs`, and selected `decompile` calls.
- Raw PE evidence: local PE section-table parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Numeric conversion: `int_convert.py 0x4` confirms the half-open range size is decimal `4` bytes (Verified with int_convert.py).
- Negative evidence: no xrefs to `0x0069b3cc`; successor `0x0069b3d4` has separate surface/render xrefs; no current evidence supports a split or non-`MiscWorkThread` owner.

## IDA MCP Facts

- `server_health` on session `b001_0003gy` returned `status=ok`, module `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, and `auto_analysis_ready=true`.
- `get_bytes` returned:
  - `0x0069b3cc`: `00 00 00 00`
  - `0x0069b3d0`: `00 00 00 00`
  - `0x0069b3d4`: `00 00 00 00`
- `get_int(0x0069b3d0, u32le)` returned `0`.
- Raw PE section parse shows `.data` has virtual range `0x0066d000-0x0069ce24` and raw file range `0x0026ac00-0x00278400`; `0x0069b3d0` is in the virtual zero-fill tail beyond initialized raw bytes. This supports the current zero image bytes and contradicts the target page's current `ff ff ff ff` raw-data block.
- `xrefs_to(0x0069b3d0)` returned exactly six refs:
  - `0x00419f50` in `sub_419F50`, size `0x16`
  - `0x00502ece` in `sub_502E30`, size `0x22c`
  - `0x0051404e` in `sub_513DA0`, size `0x2ef`
  - `0x00527c71` in `sub_527BB0`, size `0x2f4`
  - `0x00527c7f` in `sub_527BB0`, size `0x2f4`
  - `0x0060c250` in `sub_60C250`, size `0xa`
- Boundary xrefs:
  - `xrefs_to(0x0069b3cc)` returned none.
  - `xrefs_to(0x0069b3d4)` returned seven separate refs in surface/render code, including refs inside `0x00558840` and `0x005595d0`.
- `lookup_funcs` confirmed the same current function bounds: `0x00419f50-0x00419f66`, `0x00502e30-0x0050305c`, `0x00513da0-0x0051408f`, `0x00527bb0-0x00527ea4`, and `0x0060c250-0x0060c25a`.
- `decompile(0x00419f50)` shows:

```c
sub_582A80(&dword_69B3D0);
return atexit(sub_60C250);
```

- `decompile(0x0060c250)` shows:

```c
sub_582B30(&dword_69B3D0);
```

- `decompile(0x00502e30)` shows subtype `3` calling `sub_575A90(...)`, then assigning to `dword_69B3D0` through `sub_582BB0((void **)&dword_69B3D0, v4)`.
- `decompile(0x00513da0)` shows the same subtype `3` pattern with `sub_582BB0((void **)&dword_69B3D0, v13)`.
- `decompile(0x00527bb0)` shows `ProcessNCAUpdate` testing `sub_584CF0(&dword_69B3D0)`, copying `sub_584540(&dword_69B3D0)` into `szUrl` when present, and otherwise decoding/formatting the fallback URL bytes at `0x0066de30`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b3ac-0x0069b3d0` | [UID:00029S] `TimerMgrStaticObjectStorage` | predecessor static object storage | true | `0000OT` | `85/strong` in coverage | separate owner; ends at target start |
| `0x0069b3d0-0x0069b3d4` | [UID:00029T] `MainMenuTextUrlStaticString` | NCA confirm-user URL override static string/object handle | true | `0000LG` | `88/92` header | target; text/evidence repair recommended |
| `0x0069b3d4-0x0069b3d8` | [UID:00029U] `SurfacePixelFormatFlags` | successor render mode flags | true | `0000OC` | `85/very-strong` in coverage | separate successor xrefs |
| `0x005277c0-0x005285dd` | [UID:0001CJ] `MiscWorkThreadAndNotifications` | worker/notification function family containing `ProcessNCAUpdate` | true | `0000LG` | documented owner family | supports route |
| `0x0066de30-0x0066de6c` | [UID:00027S] `NcauthConfirmUserUrlObfuscated` | fallback NCA confirm-user URL literal | true | `0000LG` | `82/88` | confirms paired owner context |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00419f50` | `sub_582A80(&dword_69B3D0)` and `atexit(sub_60C250)` | runtime construction and cleanup registration for the static string handle |
| `0x00502ece` | `sub_502E30`, MainMenu ANSI text packet helper | packet subtype-3 writer, not semantic owner |
| `0x0051404e` | `sub_513DA0`, MapPane packet helper | packet subtype-3 writer, not semantic owner |
| `0x00527c71` / `0x00527c7f` | `sub_527BB0`, `ProcessNCAUpdate` | semantic reader: tests and copies override URL before fallback |
| `0x0060c250` | `sub_60C250` cleanup thunk | destroys the same static string handle |
| `0x0069b3d4` successor | refs in `0x00558840` / `0x005595d0` family | separate surface/render global begins immediately after target |

## Documentation Evidence And IDA Status

- Target page supports current route: header already has `CANONICAL_OWNER:0000LG`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LG`.
- Target page supports semantic name: title and interpretation identify the object as an NCA confirm-user URL override static string, not MainMenu-owned UI text.
- Target page is scanner-incomplete: no exact body occurrence of `MainMenuTextUrlStaticString` was found with `Select-String -SimpleMatch`.
- Target page has stale terminology: `Autogen parent` and `Assign AUTOGEN_PARENT_UID:0000LG` should be rewritten to current owner/emitter language.
- Target page has stale byte evidence: current IDA and raw PE evidence show image-time zero bytes at `0x0069b3d0`, not `ff ff ff ff`. The construction call remains real; any nonzero sentinel must be described as runtime constructor state, not raw image data.
- `auto-generated/-ag-memory-coverage.md` line `2637` is current: it lists [UID:00029T] as `emits`, owner `0000LG`, emitter `0000LG`, output route `auto-generated/NexusTK/app/MiscWorkThread.cpp`, and no reconstruction code.
- `by-memory/-coverage-report.md` line `4151` is stale: it still says `85%` and `remains unassigned because ownership is split across MainMenuPane, MapPane, and auth/update code`. That contradicts the target header and generated memory coverage.
- `by-project-structure/proposed-source-tree.md` places `MiscWorkThread.cpp` under `NexusTK/app/` and describes it as the owner of folder browsing, HTTP fetch, and NCA auth/update tasks.

## Ranked Ownership Analysis

### 1. [UID:0000LG] MiscWorkThread

- Evidence for: owns `ProcessNCAUpdate`; only semantic reader of the override URL slot; owns paired fallback URL object [UID:00027S]; parent file is `86/85` and clears the gate; generated memory coverage already routes [UID:00029T] to `NexusTK/app/MiscWorkThread.cpp`.
- Evidence against: packet writer xrefs are in `MainMenuPane` and `MapPane`.
- Decision: accepted. Writers update worker-owned state; semantic ownership belongs to the worker that consumes the URL.

### 2. [UID:0000L0] MainMenuPane

- Evidence for: current filename is `MainMenuTextUrlStaticString`, and `sub_502E30` writes packet subtype-3 text to the slot.
- Evidence against: one writer does not own the URL semantics; `MapPane` has a parallel writer; `ProcessNCAUpdate` is the only reader and uses the fallback URL object in the same owner family.
- Decision: rejected as canonical owner/emitter.

### 3. [UID:0000L3] MapPane

- Evidence for: `sub_513DA0` also writes subtype-3 packet text to the slot.
- Evidence against: same issue as `MainMenuPane`; this is a producer/adapter path, not the semantic URL consumer.
- Decision: rejected as canonical owner/emitter.

### 4. `CANONICAL_OWNER:NONE` with multiple emitters

- Evidence for: there are multiple writer contexts.
- Evidence against: this is not a shared literal with independent source-use output contexts. It is one mutable static object with a single semantic consumer and paired fallback constant in `MiscWorkThread`.
- Decision: rejected. Keep single owner/emitter `0000LG`.

### Proposed new file/grouping

- Proposed owner/name/path: none.
- Likely full contents: not applicable; `MiscWorkThread.cpp` already covers the NCA worker and fallback URL context.
- Candidate related items that belong: [UID:00027S] fallback URL object already belongs to `MiscWorkThread`; [UID:00029T] should stay with the same source family.
- Candidate related items rejected: `MainMenuPane` and `MapPane` packet helpers are producers but not owners.
- Standalone, narrow, or broad source-file inference: no new source file needed.

## Negative Evidence Summary

- No split is warranted because the range is exactly one four-byte storage handle, with no subrange xref split.
- No range expansion is warranted because `0x0069b3cc` has no xrefs and `0x0069b3d4` has separate surface/render xrefs.
- No title replacement is required for semantics because the title is already more accurate than the filename.
- No metadata route change is required: current target header and generated memory coverage already agree on `0000LG`.
- No final C++ should be emitted yet because the item has `COMPLETION:88`, below the active `90/90+` code-entry gate, and original declaration spelling remains provisional.

## Exact Recommended Edits

### Target Page Text Repair

Do not directly apply in this B002 pass. When a documentation agent or supervisor edits the target page, apply these changes to `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`.

Add a scanner-visible label bullet near the current status/candidate-owner text:

```markdown
- Scanner-visible filename label: `MainMenuTextUrlStaticString`. This legacy filename label is retained for generated/report stability; the semantic documentation label is `NcauthConfirmUserUrlOverrideStaticString`, and the current canonical owner/emitter route is [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
```

Replace the current `Autogen Status` section with current terminology:

```markdown
## Autogen Status

- Reconstructable: true. This is source-declared static object storage with startup construction and registered cleanup.
- Canonical owner: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). B001-050 and the current B002 recheck found that `MainMenuPane` and `MapPane` write this slot as packet-state adapters, while `MiscWorkThread::ProcessNCAUpdate` is the only semantic reader/consumer and already owns the fallback NCA URL object.
- Emitter: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
- Reconstruction status: no final C++ emitted. Preserve as a static string/object declaration once the item reaches the active `90/90+` code-entry gate and the original declaration spelling/source shape are defensible.
```

Replace the current raw-data block:

````markdown
## Raw Data

```text
0x0069b3d0: 00 00 00 00
```
````

Replace the stale byte evidence bullets with:

```markdown
- 2026-06-14 B002 live IDA MCP `get_bytes(0x0069b3d0, 4)` returns `00 00 00 00`, and `get_int(0x0069b3d0, u32le)` returns `0`.
- 2026-06-14 B002 raw PE section-table check confirms `0x0069b3d0` lies in the virtual zero-fill tail of `.data`: the section virtual range is `0x0066d000-0x0069ce24`, while initialized raw bytes end before this address. Treat earlier `ff ff ff ff` text as stale or as runtime-constructor state if corroborated separately, not as image-time raw data.
```

Replace the first sentence of `Assignment Decision` with:

```markdown
Keep `CANONICAL_OWNER:0000LG` and `EMITTER_UIDS:0000LG` for [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
```

Then keep the existing rationale that `MainMenuPane` and `MapPane` are packet-state writers while `ProcessNCAUpdate` is the semantic reader.

Add a change note:

```markdown
- 2026-06-14 B002 memory-ranges advanced-scan audit:
  - Recommended repair: add scanner-visible `MainMenuTextUrlStaticString` body text, replace legacy `AUTOGEN_PARENT_UID` wording with current `CANONICAL_OWNER` / `EMITTER_UIDS` wording, and correct raw image bytes from stale `ff ff ff ff` to current zero-filled image bytes.
  - Summary/evidence: current IDA MCP session `b001_0003gy` confirms six direct refs to `0x0069b3d0`, clean boundaries at `0x0069b3cc` and `0x0069b3d4`, construction through `sub_582A80`, cleanup through `sub_582B30`, packet writes in `MainMenuPane` and `MapPane`, and semantic reads in `ProcessNCAUpdate`. Header owner/emitter route remains `0000LG`.
```

### Supervisor-Owned Coverage Row

Do not directly edit `by-memory/-coverage-report.md` in this B002 pass. Replace only the existing [UID:00029T] row near the `00029S` / `00029U` neighbors with:

```text
    - [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) 0x0069b3d0-0x0069b3d4 | static string/object handle | NcauthConfirmUserUrlOverrideStaticString : reconstructable : 88% : very-strong : One-word NCA confirm-user URL override static string/object handle routed to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); current B002 recheck confirmed image-time zero bytes in the virtual `.data` tail, six direct refs for startup construction, cleanup, MainMenuPane/MapPane subtype-3 packet assignments, and `ProcessNCAUpdate` reads, plus clean boundaries before [UID:00029U][0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags](by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md). Retain the legacy filename label `MainMenuTextUrlStaticString` until a coordinated rename pass.
```

### Optional Coordinated Rename

No immediate rename is required. If the supervisor wants names to converge later, the better semantic filename is:

```text
by-memory/0x0069b3d0-0x0069b3d4.NcauthConfirmUserUrlOverrideStaticString.md
```

That rename should be coordinated through normal validator/UID-reference tooling because many current docs and generated reports still reference the legacy `MainMenuTextUrlStaticString` filename.

## Final Recommendation

- Exact changes applied: none to by-* files; report only.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:0000LG`.
- Exact emitter assignments applied or recommended: keep `EMITTER_UIDS:0000LG`.
- Exact items left no-owner/non-emitting: none. This item is owned and routed.
- Exact future work outside this assignment: a permitted editor should apply the target text/evidence repair, run normal validator `--apply` on the target page, and supervisor should apply the coverage row replacement above.

## Follow-Up Actions

- Supervisor actions: apply or assign the target text repair and coverage row replacement; optionally schedule a coordinated filename rename.
- A-agent actions: after editing the target page, run `validator.py --mode file --file <target> --apply`; do not add C++ until the item reaches the `90/90+` code-entry gate.
- B002 future research actions: none needed unless the optional rename or final static declaration shape becomes a separate ownership/source-layout question.

## Confidence

- Recommendation confidence: `90`.
- Owner/emitter confidence: `92`, matching the target header and current IDA xref roles.
- Scanner-label confidence: `100`; exact body search found no `MainMenuTextUrlStaticString`, and the generated report line is exact.
- Raw-byte correction confidence: `94`; current IDA bytes, current IDA integer value, and PE section mapping all support zero-filled image bytes.
- Remaining uncertainty: whether the original C++ declaration name was closer to `MainMenuTextUrlStaticString` or `NcauthConfirmUserUrlOverrideStaticString` remains unresolved. The latter is a better descriptive documentation name, not a recovered original symbol.

## Validator Results

- Commands run: none.
- Results: not applicable; B002 did not edit by-* files for this report-only assignment.
- Unresolved validator warnings/errors: none observed in this pass. The existing generated `auto-generated/by-memory-tool-report.md` line will remain until target text is repaired and the memory-ranges report is regenerated.

## Lease State

- No lease was acquired because no leased-scope file was edited.
- `Agent-B002/current_leases.md` was read at the start of the pass and reported no active leases.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B002/research/00029T-MainMenuTextUrlStaticString-memory-range-report.md`
- Modified:
  - none outside the B002 research folder
- Renamed:
  - none
- Moved to executed:
  - none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00029T-MainMenuTextUrlStaticString-memory-range-report.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00029T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
