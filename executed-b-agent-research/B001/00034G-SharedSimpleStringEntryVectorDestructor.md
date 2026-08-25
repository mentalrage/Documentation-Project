** TARGET-REPORT-UID:00034G **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00034G SharedSimpleStringEntryVectorDestructor Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:00034G] `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md` as ignored/non-emitting compiler-template vector destructor support. Keep `AUTOGEN_PARENT_UID` blank. Do not assign it to `SpelledPane`, `FolderTreePane`, `VectorHelpers`, `StringUtil`, or the containing FolderTree aggregate.
- Final disposition: no split required. The exact `0x004b5760-0x004b57dd` function is a single shared physical destructor body for 12-byte record-vector storage; source-level reconstruction belongs in the two source contexts that use such vectors, not in this helper page.
- Required action already applied in by-memory docs: `00034G` is now `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:FALSE`, parent blank; [UID:000157] `FolderTreePaneTreeAndSortHelpers` stays `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank; [UID:0000VN] `-ignored.md` now records `0x004b5760-0x004b57dd`.
- Confidence: `93/100` for non-emitting/shared-helper classification; `96/100` for exact function boundary and behavior; `88/100` for the inferred source-level record-vector owner model because original source type names are not preserved.
- Supervisor coverage-report action: keep the exact rows below as the required coverage-report text for this decision. Restart audit on 2026-06-12 found the current `by-memory/-coverage-report.md` already contains these rows near the [UID:000157] block. I did not edit the coverage report in the restart audit.

```markdown
    - [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) 0x004b3350-0x004b5c3f | mixed split inventory | FolderTreePaneTreeAndSortHelpers : ignored : 88% : strong : B001-056 leaves this parent-blank non-emitting inventory at `88/90`; exact child pages carry source-bearing behavior, while shared child [UID:00034G] is now ignored/non-emitting vector destructor support. IDA confirms the aggregate crosses FolderTree traversal/sort/storage methods, compiler cleanup helpers, padding, and a shared SpelledPane/FolderTree vector destructor, so no single direct parent should own the whole span.
        - [UID:00034G][0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor](by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md) 0x004b5760-0x004b57dd | compiler-template vector destructor | SharedSimpleStringEntryVectorDestructor : ignored : 89% : very-strong : B001-056 reclassified this exact `0x7d` / 125-byte body (Verified with `tools\int_convert.py`) as non-emitting 12-byte record-vector destructor support: direct JSON-RPC IDA MCP confirms the `sub_582B70` element cleanup loop, `0x0c` / 12-byte stride, aligned-free validation, vector triplet zeroing, one ordinary SpelledPane destructor call at `0x0057382c`, one FolderTreePane EH cleanup jump at `0x005fea1d`, no data refs, and no literal-address hits. Source-level reconstruction belongs in the SpelledPane entry-vector member and FolderTreePane local directory-entry vector code; do not emit or parent this helper as standalone source.
```

## Supporting Research

## Target

- Target UID: `00034G`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md`
- Source queue/report row: Supervisor assignment B001-056 for `reviewed-85-but-ownership-unknown-under-review`.
- Current supervisor context: A002 Batch 241 had raised this child to `87/89`, but it remained parent-blank after rejecting `FolderTreePane`, `VectorHelpers`, `StringUtil`, and the below-gate nearby vector-support aggregate as direct owners.
- Starting state before this pass: `COMPLETION:87`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, parent blank.
- Ending state after this pass: `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:FALSE`, parent blank.

## Executive Recommendation

The correct structural answer is not a new parent assignment. The exact function is shared compiler/template destructor support for a 12-byte record vector whose first field is a string object/handle and whose remaining 8 bytes are owner-specific metadata. IDA proves one ordinary call from `SpelledPane` member-vector destruction and one EH cleanup jump from a `FolderTreePane::FindFirstVisibleChild` local vector cleanup. Those are two source contexts, not one source owner.

The source-level replacement is:

- Reconstruct the `SpelledPane` member vector at `this+0x178` in the `SpelledPane` source/class docs.
- Reconstruct the FolderTree local directory-entry vector in the `FindFirstVisibleChild`/directory-entry sort and traversal code.
- Let ordinary C++ container/member lifetime emit or eliminate equivalent destructor support. Do not hand-port `sub_4B5760` as a source function.

No split is required because the target is an exact IDA function with clean `0xcc`/padding boundaries and a single coherent emitted behavior. The repair was a reclassification, not a range split.

## Supervisor Active Recheck

- Supervisor instruction: research B001-056 one target only, using direct IDA MCP JSON-RPC evidence as authoritative, and do not stop at unknown ownership.
- Split decision: no new child pages were needed. The target was already an exact child page for the function body `0x004b5760-0x004b57dd`.
- In-scope repair performed: target page, containing aggregate row/rationale, and ignored ledger now all agree that `00034G` is non-emitting shared vector destructor support.
- Coverage-report handling: `by-memory/-coverage-report.md` remains untouched; exact replacement rows are provided at the top of this report.

## Inference Research Guidance Check

`inference_research.md` and `by-structure.md` require separating IDA facts, documentation evidence, and ownership inference. They also allow `RECONSTRUCTABLE:FALSE` and ignored-ledger handling for compiler-generated support when emitting source for the physical function would be misleading.

Existing documentation was treated as a lead only. The earlier page correctly captured the two xrefs and 12-byte cleanup behavior, but its `RECONSTRUCTABLE:TRUE` state implied a source-authored helper still needed an owner. Direct IDA evidence supports the stronger structural answer: the physical helper is compiler/template support and should be ignored as a standalone reconstruction unit.

## Evidence Standards Used

- Direct IDA MCP JSON-RPC endpoint documented in `by-structure.md`: `lookup_funcs`, `decompile`, `disasm`, `callers`, `callees`, `xrefs_to`, and read-only `py_eval`.
- Local numeric conversion check: `tools\int_convert.py` for `0x7d`, `0x0c`, `0x1000`, `0x178`, `0x174`, `0x24`, `0x262`, and `0x53`.
- Documentation evidence: existing `00034G`, containing aggregate `000157`, SpelledPane destructor/vector helper pages, FolderTree vector-support aggregate, `VectorHelpers`, `StringUtil`, `SimpleUStringVector`, `SpelledPane`, and `FolderTreePane`.
- Negative evidence: no data refs, no literal-address hits, no pointer-table/vtable references, no single ordinary caller family, and no source-facing utility API evidence.

## IDA MCP Facts

- IDB metadata from direct JSON-RPC: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x400000`, size `0x2b3000`, md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs 0x004b5760`: `sub_4B5760`, exact range `0x004b5760-0x004b57dd`, size `0x7d` / 125 bytes (Verified with `tools\int_convert.py`).
- Function boundary bytes: byte before target at `0x004b575f` is `0xcc`; bytes after `0x004b57dd` begin with three `0xcc` padding bytes before the separate `0x004b57e0` cleanup thunk.
- `decompile` and `disasm` show the exact behavior:
  - load vector begin/end/capacity from `[ecx]`, `[ecx+4]`, and `[ecx+8]`;
  - loop from begin to end in `0x0c` / 12-byte steps (Verified with `tools\int_convert.py`);
  - call `sub_582B70` for each record's leading string field;
  - compute allocation byte count from the capacity delta;
  - validate MSVC aligned large-allocation metadata for allocations at least `0x1000` / 4096 bytes (Verified with `tools\int_convert.py`);
  - free through `sub_5C7526`;
  - zero the vector triplet;
  - call `__invalid_parameter_noinfo_noreturn` only on failed aligned-free validation.
- `callers 0x004b5760`: only ordinary call is `0x0057382c` in `sub_573820`.
- `xrefs_to 0x004b5760`: two code refs total:
  - `0x0057382c`, ordinary call from [UID:00039G] `SpelledPaneScalarDeletingDestructor`;
  - `0x005fea1d`, EH cleanup jump in a tail chunk associated with `sub_4B1D50`.
- Function chunk inventory for the EH xref maps `0x005fea1d` to `sub_4B1D50` chunks `0x004b1d50-0x004b253a`, `0x004b57e0-0x004b57e8`, and `0x005fe97a-0x005fea81`. The local instruction sequence is `lea ecx,[ebp+Block]; jmp sub_4B5760`.
- `py_eval` negative checks found no data refs to `0x004b5760` and no literal-address byte hits for `60 57 4B 00` in `.text`.
- `callees 0x004b5760`: `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b5760-0x004b57dd` | [UID:00034G] `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md` | shared 12-byte record-vector destructor support | `FALSE` | blank | `89/93` | Reclassified ignored/non-emitting in this pass |
| `0x004b3350-0x004b5c3f` | [UID:000157] `FolderTreePaneTreeAndSortHelpers` | mixed split inventory containing FolderTree methods, helpers, padding, and shared support | `FALSE` | blank | `88/90` | Parent remains non-emitting inventory |
| `0x00573820-0x00573873` | [UID:00039G] `SpelledPaneScalarDeletingDestructor` | ordinary SpelledPane destructor that destroys member vector at `this+0x178` | `TRUE` | [UID:0000DK] `SpelledPane` | `87/92` | Source-bearing owner context for one use |
| `0x004b1d50` function family | existing FolderTreePane core docs | `FindFirstVisibleChild` local directory-entry vector cleanup context | source-bearing parent method, helper cleanup non-emitting | FolderTreePane context | documented elsewhere | Source-bearing owner context for the other use |
| `0x004b5cf0`, `0x004b5de0`, `0x004b5ec0` | [UID:00022E] `FolderTreePaneVectorSupportHelpers` | adjacent 12-byte vector support reused by FolderTree/SpelledPane paths | mixed | not accepted as direct parent | `78/86` | Below gate and mixed helper cluster |
| `0x00573880`, `0x00573900` | [UID:00039H], [UID:00039I] | SpelledPane 12-byte entry-vector copy/erase helpers | `FALSE` | blank | `84/91` each | Supporting evidence for SpelledPane vector instantiation pattern |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00573826` | `lea ecx,[esi+178h]` | SpelledPane destructor forms `this+0x178` member-vector address |
| `0x0057382c` | `call sub_4B5760` | ordinary call, one normal caller |
| `0x00573831` | `lea ecx,[esi+174h]` | adjacent SpelledPane member cleanup confirms vector sits beside other SpelledPane state |
| `0x005fea17` | `lea ecx,[ebp+Block]` | FolderTree local vector address for EH cleanup |
| `0x005fea1d` | `jmp sub_4B5760` | EH cleanup tail jump, not an ordinary source call |
| `0x004b5cf0` refs | `0x004b420c`, `0x0057320c` | 12-byte range-destroy helper reused by FolderTree insert and SpelledPane insert |
| `0x004b5de0` refs | `0x004b4152`, `0x004b4163` | 12-byte copy helper used by FolderTree directory-entry insert |
| `0x004b5ec0` refs | `0x004b421a`, `0x0057321a` | 12-byte free-storage helper reused by FolderTree insert and SpelledPane insert |
| `0x00573880` refs | `0x00573151`, `0x00573162` | SpelledPane vector copy helper reached from vector insert |
| `0x00573900` ref | `0x0056be70` | SpelledPane vector erase helper reached from pane logic |

## Documentation Evidence And IDA Status

- [UID:00034G] existing page: correctly identified exact function bounds, 12-byte record cleanup, two xrefs, and blank parent. IDA confirms those facts. The stale part was `RECONSTRUCTABLE:TRUE`, which treated emitted compiler/template support as a source helper needing ownership.
- [UID:000157] `FolderTreePaneTreeAndSortHelpers`: correctly treated the containing range as non-emitting mixed inventory. IDA confirms this target is only address-neighborhood context and that the normal ordinary caller is outside FolderTreePane.
- [UID:000240] `LookGroupSpelledDestructorVectorHelpers`: documents SpelledPane destructor/copy/erase/insert helper island. IDA confirms `0x00573820` calls this target for storage at `this+0x178`.
- [UID:00039G] `SpelledPaneScalarDeletingDestructor`: source-bearing SpelledPane destructor page. IDA confirms the direct call. This supports SpelledPane as a source context but not as the sole physical-helper owner.
- [UID:00039H] and [UID:00039I]: document adjacent non-emitting SpelledPane vector copy/erase helpers. IDA confirms the same 12-byte record-vector layout pattern.
- [UID:00022E] `FolderTreePaneVectorSupportHelpers`: useful nearby evidence for 12-byte vector helper reuse, but the page is below gate and itself mixed. IDA supports using it as context only, not as parent.
- [UID:0000P3] `VectorHelpers`: broad utility/header-style grouping. IDA does not show a source-facing utility API, symbol, or ownership signal for this exact target.
- [UID:0000OB] `StringUtil` and [UID:0000DA] `SimpleUStringVector`: relevant because `sub_582B70` destroys the first string field. IDA contradicts direct ownership because the container stride is 12 bytes, not the documented 4-byte `SimpleUStringVector` slot layout.

## Ranked Ownership Analysis

### 1. Ignored/non-emitting compiler-template vector destructor support

- Evidence for: exact compiler-shaped vector triplet destructor body, per-record string cleanup, aligned free validation, no data refs, no pointer-table refs, one ordinary SpelledPane call, one FolderTree EH cleanup jump, and no single source context covering both uses.
- Evidence against: the helper has an ordinary call from `SpelledPane`, so it is not EH-only dead code. That does not make it source-authored; it means the emitted helper is reused for one member-vector destructor and one local-vector cleanup.
- Decision: accepted. This is the only disposition that fits both IDA xrefs and by-structure ownership rules without inventing a false parent.

### 2. [UID:0000DK] `SpelledPane`

- Evidence for: the only ordinary direct call is from `SpelledPaneScalarDeletingDestructor`; IDA proves the target destroys member storage at `this+0x178`; nearby SpelledPane vector insert/copy/erase helpers use the same 12-byte record pattern.
- Evidence against: IDA also proves the physical body is reached from FolderTree EH cleanup. `SpelledPane` owns its member-vector source declaration and destructor path, not the shared emitted helper body. Assigning the by-memory helper to `SpelledPane` would hide the FolderTree source context.
- Decision: rejected as direct parent; accepted as one source-level use.

### 3. [UID:0000JG] / [UID:00005A] `FolderTreePane` and [UID:000157] containing aggregate

- Evidence for: EH cleanup xref is associated with `sub_4B1D50`, a FolderTreePane function; containing aggregate is a FolderTreePane neighborhood; related vector helpers are adjacent to FolderTree sort/insert logic.
- Evidence against: the target's only ordinary call is outside FolderTreePane, and FolderTree's direct evidence is an EH cleanup tail for a local vector. The aggregate is already non-emitting and mixed. FolderTree owns a local vector use, not the shared helper as a direct source function.
- Decision: rejected as direct parent; accepted as one source-level use.

### 4. [UID:0000P3] `VectorHelpers`

- Evidence for: semantic helper is vector-support-like and shared across two contexts.
- Evidence against: no IDA symbol, source API, caller convention, or table evidence proves an original utility source file. The page is a broad evidence bucket, and using it would create a source owner from a compiler artifact.
- Decision: rejected.

### 5. [UID:0000OB] `StringUtil` / [UID:0000DA] `SimpleUStringVector`

- Evidence for: each record's first field is cleaned through `sub_582B70`, so string lifetime is involved.
- Evidence against: the target destroys 12-byte records, not a vector of 4-byte `SimpleUStringVector` slots. The extra 8 bytes are owner-specific metadata, making this a record-vector destructor rather than StringUtil container code.
- Decision: rejected.

### Proposed new file/grouping

- Proposed owner/name/path: none.
- Likely full contents if one were forced: a broad compiler-template vector-instantiation grouping for 12-byte string-leading records. That is not an original source file; it would duplicate compiler output and become a sink for unrelated template instantiations.
- Candidate related items that belong conceptually but should not form a source file: `0x004b5cf0`, `0x004b5de0`, `0x004b5ec0`, `0x00573880`, `0x00573900`, and `0x00572fd0`.
- Decision: do not create a new source owner. Keep source-level vector declarations in `SpelledPane` and `FolderTreePane`.

## Negative Evidence Summary

- No data refs to `0x004b5760`.
- No literal-address byte hits for `60 57 4B 00` in `.text`.
- No vtable or pointer-table slot references.
- No ordinary FolderTree caller; FolderTree evidence is EH cleanup.
- No second ordinary SpelledPane-only call family beyond the scalar deleting destructor.
- No source-tree or documentation evidence for a standalone 12-byte-vector helper source file.
- `StringUtil` is only a callee dependency through the string field destructor; it is not the container owner.
- `VectorHelpers` is too broad and lacks a source-facing API signal for this exact body.

## Final Recommendation

- Exact changes applied:
  - [UID:00034G] changed from `87/89`, `RECONSTRUCTABLE:TRUE`, parent blank to `89/93`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - [UID:000157] updated its child row, confidence rationale, and change log to reflect `00034G` as non-emitting shared vector support.
  - [UID:0000VN] `by-memory/-ignored.md` now records `0x004b5760-0x004b57dd`.
- Exact parent assignments applied or recommended: none. Parent must remain blank.
- Exact items left unassigned and why: `00034G` remains parent-blank because the physical helper is shared by two source contexts and should not emit source as a standalone item.
- Exact future work outside this assignment: supervisor should apply the two coverage-report replacement rows at the top of this report.

## Follow-Up Actions

- Supervisor actions:
  - Replace the stale `000157` and `00034G` rows in `by-memory/-coverage-report.md` with the exact rows listed in the finalized recommendation.
  - Close B001-056 as reclassified/ignored rather than ownership-unknown.
- A-agent actions:
  - When reconstructing `SpelledPane`, keep the `this+0x178` member-vector lifetime in source-level class/member logic.
  - When reconstructing FolderTreePane `FindFirstVisibleChild`, keep the local directory-entry vector lifetime in source-level function logic.
- B001 future research actions: none for this target.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: `89/93` is defensible because exact bounds, behavior, reference set, negative evidence, ownership rejection, and ignored-ledger path are all documented and validated.
- Remaining uncertainty: original source type names for the two 12-byte record vectors are inferred rather than symbol-proven. That uncertainty affects naming precision, not the non-emitting disposition.

## Validator Results

- Initial attempted command, not counted as validation evidence, failed because it used the wrong script path from the workspace root:
  - `python tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md --apply --queue-timeout 120`
  - Result: Python could not open `E:\NTK\GhidraBridge\tools\validator.py`.
- Final validation commands:
  - `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md --apply --queue-timeout 120`
  - Result: `ok: 1`; `completion_update 00034G ... 89`; `confidence_update 00034G ... 93`; `autogen_registry_update 00034G ... true -> false`.
  - `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md --apply --queue-timeout 120`
  - Result: `ok: 1`; score unchanged; validator rebuilt registry and reported autogen coverage reports unchanged.
  - `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\-ignored.md --apply --queue-timeout 120`
  - Result: `ok: 1`; `reference_index_add 00034G by-memory/-ignored.md by-memory/-ignored.md`; validator rebuilt registry and reported autogen coverage reports unchanged.
- Validator side effects reported by the tool: `project-level/-auto-completion-stats.md` projected section update and `tools/validator.ini` autogen registry rebuild. No manual edits were made to generated/project-level files.
- 2026-06-12 restart audit commands:
  - `python "E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py" --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md" --queue-timeout 120`
  - `python "E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py" --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md" --queue-timeout 120`
  - `python "E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py" --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-ignored.md" --queue-timeout 120`
  - Results: all three dry-run validations reported `ok: 1`. Each dry run also reported unrelated stale autogen registry entries for `0003DJ`-`0003DM`; no `00034G`, `000157`, or `0000VN` validation error was reported.
- 2026-06-12 restart audit IDA MCP spot-check:
  - Active IDA session: `a001-b276`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - Current MCP schema requires `database=<session_id>`; `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `disasm` were re-run read-only.
  - Results reconfirmed `sub_4B5760` at `0x004b5760`, size `0x7d`; exactly two code xrefs at `0x0057382c` in `sub_573820` and `0x005fea1d` in `sub_4B1D50`; callees `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`; decompilation/disassembly still show the 12-byte stride loop, aligned-free validation, vector triplet zeroing, and no new ownership signal.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B001/research/00034G-SharedSimpleStringEntryVectorDestructor.md`
- Modified:
  - `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md`
  - `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`
  - `by-memory/-ignored.md`
- Validator-reported side effects:
  - `tools/validator.ini` registry rebuild.
  - `project-level/-auto-completion-stats.md` projected stats update.
- Not modified:
  - `by-memory/-coverage-report.md`
  - `tools/leaser/Agents/Supervisor_notes.md`

## Leases

- Lease command used before edits:
  - `python leaser.py B001 lease "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md" "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md" "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-ignored.md"`
- Final lease release command:
  - `python leaser.py B001 unlease` from `source-3\project-documentation\tools\leaser`
  - Result: `B001: No active leases`
- Final lease status: no active B001 leases in `current_leases.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00034G-SharedSimpleStringEntryVectorDestructor.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:22","uid":"00034G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
