** TARGET-REPORT-UID:00028G **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00028G CppRttiTypeDescriptorData Advanced-Scan Research

## Finalized Report / Current Recommendation

- Current recommendation: treat the Advanced-Error-Scan finding as a real document-text token gap that has now been repaired in the target page.
- Final disposition: keep [UID:00028G] `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++.
- Required action: no `by-memory/-coverage-report.md` edit is required. The stale line in `auto-generated/by-memory-tool-report.md` should clear only after that generated report is refreshed by its owning tool.
- Confidence: `92` for the recommendation that this is only a scanner-text repair, not an owner/emitter/range/split problem.

## Supporting Research

## Target

- Target UID: `00028G`
- Target path: `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan line `231`, `missing document text for CppRttiTypeDescriptorData`.
- Current supervisor classification: single-target B002 Advanced-Error-Scan investigation from current generated report.
- Current scores and parent state before/after repair: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters. Scores and routing were unchanged.

## Executive Recommendation

The page was already substantively correct: the range is a compiler/linker-generated MSVC RTTI `type_info` descriptor and decorated-name pool spanning project classes, JsonCpp classes, STL/Dinkumware templates, COM/error records, and standard exceptions. No single source owner or emitter route is defensible for the whole range.

The scanner finding was real because the file body used the human-readable title `C++ RTTI Type Descriptor Data` but did not include the exact filename/topic token `CppRttiTypeDescriptorData` outside generated/path contexts. I repaired that by adding a `Document label: CppRttiTypeDescriptorData` summary bullet and a change note. No split, merge, owner assignment, emitter assignment, reclassification, or IDA-safe rename is warranted.

## Supervisor Active Recheck

- Supervisor instruction: inspect `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md` for the Advanced-Error-Scan finding `missing document text for CppRttiTypeDescriptorData`.
- Split repair: not required. The target is a coherent compiler-generated RTTI descriptor/name pool, and the predecessor/successor pages confirm the current half-open bounds.
- Source-bearing children: none in this range. Source-owned declarations live on class/file/type pages and cause the compiler to regenerate RTTI; this memory page itself should not emit source.

## Inference Research Guidance Check

`by-structure.md` requires separating semantic ownership from generated-output routing. It also identifies pure RTTI/compiler artifacts as `compiler/linker-generated` documentation evidence that should not be hand-ported as source. `inference_research.md` cautions against using address adjacency alone as source ownership evidence and treats RTTI/metadata as ABI/toolchain output unless source declarations are the actual object being documented.

Existing documentation was treated as a lead, not authority. IDA MCP rechecked the name inventory, descriptor bytes, string samples, xrefs, and adjacent range boundary facts before accepting the existing no-owner/non-emitting conclusion.

## Evidence Standards Used

- IDA MCP facts: `server_health`, `entity_query`, `get_bytes`, `get_string`, `get_int`, and `xrefs_to` against session `b001_0003gy`.
- Local tool fact: `int_convert.py 6508664` confirmed decimal `6508664` as hexadecimal `0x635078` (shown with leading zero in docs as `0x00635078`).
- Documentation facts: current target page, predecessor/successor by-memory pages, `.data` section container, client-libraries runtime/third-party page, `auto-generated/-ag-memory-coverage.md`, `auto-generated/by-memory-tool-report.md`, and `by-memory/-coverage-report.md`.
- Negative evidence: no project write/initializer route, no source-level data object, and no single project class/file that can own a range containing NexusTK, JsonCpp, STL, COM, and standard-exception descriptors.

## IDA MCP Facts

- Session health: `server_health` returned `status=ok`, module `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, and `strings_cache_ready=true`.
- Function/range facts: `entity_query(kind=names, min_addr=0x006738c0, max_addr=0x0067a730, count=8)` returned total `1508` named addresses in the half-open range.
- First name facts: first anchors are `??_R0?AVLObject@@@8` at `0x006738c0`, `aAvlobject` at `0x006738c8`, `??_R0?AVCashShopVersionRequest@@@8` at `0x006738d8`, `aAvcashshopvers` at `0x006738e0`, `??_R0?AVBaseRequest@@@8` at `0x00673900`, and `aAvbaserequest` at `0x00673908`.
- Data/table/padding facts: `get_bytes(0x006738c0, 64)` begins `78 50 63 00 00 00 00 00` followed by `.?AVLObject@@`, then another descriptor lead and `.?AVCashShopVersionRequest@@`.
- Descriptor lead facts: `get_int` with `u32le` at `0x006738c0`, `0x006738d8`, and `0x0067a70c` returned `6508664`, i.e. `0x00635078` after `int_convert.py` verification.
- String facts: `get_string(0x006738c8)` returned `.?AVLObject@@`; `get_string(0x006738e0)` returned `.?AVCashShopVersionRequest@@`; `get_string(0x0067a714)` returned `.?AVbad_exception@std@@`.
- Tail boundary facts: `get_bytes(0x0067a70c, 36)` shows the final `.?AVbad_exception@std@@` descriptor record; `get_bytes(0x0067a730, 16)` returns all zero bytes belonging to the successor CRT/global storage.
- Xref facts: `xrefs_to(0x006738c0)` returns only data xrefs from `0x00640348`, `0x00649e10`, and `0x0064f14c`; `xrefs_to(0x0067a70c)` returns one runtime EH reference from `??$FindHandler@V__FrameHandler3@@@@...` at `0x005cc28b` plus data xrefs from `0x00654578`, `0x0065459c`, and `0x00669464`; `xrefs_to(0x0067a730)` returns the successor CRT accessor at `0x0041b9a0`.
- Negative IDA facts: the representative xrefs are RTTI/class-hierarchy metadata and exception support references, not source-level project reads/writes that would imply a handwritten data object.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00672eb4-0x006738c0` | [UID:00028F] `by-memory/0x00672eb4-0x006738c0.MsvcDinkumwareRuntimeMutableData.md` | predecessor MSVC/Dinkumware mutable runtime state | false | none | `88/91` | no edit; confirms start boundary before RTTI |
| `0x006738c0-0x0067a730` | [UID:00028G] `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md` | compiler-generated RTTI descriptor/name pool | false | none | `88/91` | repaired exact document label text |
| `0x0067a730-0x0067a738` | [UID:00028H] `by-memory/0x0067a730-0x0067a738.CrtStdioOptionsStorage.md` | successor CRT local stdio options storage | false | none | `90/85` | no edit; confirms successor boundary |
| `0x0066d000-0x0069d000` | [UID:0001Z8] `by-memory/0x0066d000-0x0069d000.DataSection.md` | `.data` section audit container | false | none | `72/89` | no edit; container only, not direct semantic owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006738c0` | data xrefs from `0x00640348`, `0x00649e10`, `0x0064f14c` | RTTI/class hierarchy metadata references the first type descriptor |
| `0x0067a70c` | runtime EH reference at `0x005cc28b` inside `??$FindHandler@V__FrameHandler3@@@@...`; data xrefs from `0x00654578`, `0x0065459c`, `0x00669464` | final standard exception RTTI descriptor is compiler/runtime exception metadata |
| `0x0067a730` | data xref from `sub_41B9A0` at `0x0041b9a0` | successor CRT stdio-options storage starts at the exact end of the RTTI pool |

## Documentation Evidence And IDA Status

- Existing target page supports the conclusion: it already documents the half-open range, named-address count, representative descriptor bytes, string samples, JsonCpp/STL/runtime spread, data xrefs, predecessor boundary, successor boundary, non-reconstructable state, and non-emitting policy.
- Existing target page was incomplete for scanner wording: before this pass it did not contain the exact token `CppRttiTypeDescriptorData` in the body/title text that the Advanced-Error-Scan checks.
- `auto-generated/-ag-memory-coverage.md` lines `3199` and `3702` list [UID:00028G] as `not_reconstructable`, `CANONICAL_OWNER:NONE`, blank emitters, and no output. This generated state remains correct.
- `by-memory/-coverage-report.md` line `4038` already includes the label `CppRttiTypeDescriptorData` and a correct ignored compiler RTTI description. No supervisor replacement is needed there.
- `auto-generated/by-memory-tool-report.md` line `231` still contains the stale scanner finding because that generated report was not directly edited and was not refreshed by the file validator. It should clear when the Advanced-Error-Scan source report is regenerated.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, no emitters, non-reconstructable

- Evidence for: the range is compiler/linker-generated RTTI metadata, not a source-authored object; live IDA shows dense `??_R0?...@8` descriptors and decorated names; xrefs are RTTI/class-hierarchy/EH metadata; source categories span NexusTK classes, JsonCpp, STL/Dinkumware, COM, and standard exceptions.
- Evidence against: source declarations in many classes indirectly cause this data to exist in a rebuilt binary.
- Decision: accepted. Indirect regeneration from many declarations does not create one canonical owner or an emitter route for this memory page.

### 2. Assign to `.data` section container [UID:0001Z8]

- Evidence for: the range physically lives inside `.data`, and [UID:0001Z8] is the broad section inventory.
- Evidence against: `CANONICAL_OWNER` must be the narrowest direct semantic owner, not a physical section container. [UID:0001Z8] is explicitly non-reconstructable and mixed.
- Decision: rejected as canonical owner.

### 3. Assign to one project class/file, JsonCpp, or client_libraries

- Evidence for: the pool contains names for project classes and third-party/runtime types, and [UID:0001QE] documents the runtime/third-party dependency context.
- Evidence against: no one class, file, or library owns the whole pool. The pool is a compiler product spanning independent declarations and library/runtime metadata.
- Decision: rejected for the whole range. Individual class/type pages can use this range as evidence, but this page should remain an evidence/index item.

### Proposed new file/grouping

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: no source file should own these bytes. Neighboring [UID:00028F] and [UID:00028H] remain separate runtime/CRT pages.
- Candidate related items rejected: per-class RTTI child splits were rejected because no current source-owned child needs an exact range, and the current page already documents the pool coherently.
- Standalone, narrow, or broad source-file inference: no source-file inference. The compiler/linker emits this pool from many declarations.

## Negative Evidence Summary

- Address adjacency to `.data` children does not prove source ownership; predecessor and successor are separate runtime/CRT ranges.
- Consumer/read xrefs do not prove ownership here; representative references are metadata/EH references, not project initialization or handwritten reads/writes.
- The presence of NexusTK class names does not make this a NexusTK-authored global. The same pool also contains JsonCpp, STL/Dinkumware, COM, and standard-exception descriptors.
- No emitter UID should be added because `RECONSTRUCTABLE:FALSE` pages must not emit source, and source declarations elsewhere will be responsible for any regenerated RTTI.

## Final Recommendation

- Exact changes applied:
  - Added the summary bullet `Document label: CppRttiTypeDescriptorData` to `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md`.
  - Added a `2026-06-14 B002 Advanced-Error-Scan` change note explaining the exact-token repair and unchanged scores/routing.
- Exact parent assignments applied or recommended: none. Keep `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: none. Keep blank `EMITTER_UIDS`.
- Exact items left no-owner/non-emitting and why: [UID:00028G] remains no-owner/non-emitting because it is a compiler/linker-generated RTTI descriptor pool with no single source owner and no source output route.
- Exact future work outside this assignment: generated `auto-generated/by-memory-tool-report.md` can be refreshed by its owning generation process to remove the stale Advanced-Error-Scan row.

## Supervisor-Owned Shared-Report Text

No direct edit to `by-memory/-coverage-report.md` is needed. Retain the existing row:

```text
    - [UID:00028G][0x006738c0-0x0067a730.CppRttiTypeDescriptorData](by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md) 0x006738c0-0x0067a730 | compiler RTTI data | CppRttiTypeDescriptorData : ignored : 88% : strong : MSVC C++ RTTI type descriptors and decorated type-name strings; live IDA rechecked 1508 named anchors, representative descriptor bytes, JsonCpp/STL/template/runtime samples, data xrefs, and boundaries before CRT stdio-options storage; ignored as compiler/linker-generated metadata regenerated from source declarations and runtime/compiler settings.
```

## Follow-Up Actions

- Supervisor actions: none for `by-memory/-coverage-report.md`; optionally regenerate `auto-generated/by-memory-tool-report.md` so the stale Advanced-Error-Scan finding clears.
- A-agent actions: none required for this target.
- B002 future research actions: none for this target unless a future class/type page needs a narrow RTTI evidence anchor.

## Confidence

- Recommendation confidence: `92`. The scanner gap was directly observed and repaired; live IDA and current docs independently support the unchanged non-reconstructable/no-owner state.
- Score confidence: retain target `88/91`. The page is strong but not exhaustive over all `1508` named descriptors, so no score increase is recommended.
- Remaining uncertainty: exact byte-for-byte RTTI regeneration depends on final toolchain/class declaration matching, but that uncertainty does not affect this page's non-emitting documentation disposition.

## Validator Results

- Validator command run, no dry run:

> Executable block R001 was removed from this report and preserved verbatim in [00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md](00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

- Result summary: `scanned markdown files: 1`, `ok: 1`, `autogen_report_noop: 7`, `auto-generated/-ag-memory-coverage.md unchanged`.
- Validator-owned side effects reported: `autogen_registry_rebuild: 1` and `projected_stats_update: 1`; the validator reported `project-level/-auto-completion-stats.md updated projected path completion section`.
- Unresolved validator warnings/errors: none for the target page.

## Lease State

- Lease command run before editing:

> Executable block R002 was removed from this report and preserved verbatim in [00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md](00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

- Release command run after validation:

> Executable block R003 was removed from this report and preserved verbatim in [00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md](00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

- Final lease state: `Agent-B002/current_leases.md` reports no active leases.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B002/research/00028G-CppRttiTypeDescriptorData-advanced-scan.md`
- Modified:
  - `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md`
- Validator-owned generated/state side effects reported:
  - `project-level/-auto-completion-stats.md` projected path completion section updated.
  - validator registry rebuilt by the validator command.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00028G-CppRttiTypeDescriptorData-advanced-scan.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00028G"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00028G-CppRttiTypeDescriptorData-advanced-scan-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00028G-CppRttiTypeDescriptorData-advanced-scan.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00028G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
