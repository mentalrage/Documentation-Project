** TARGET-REPORT-UID:0002HL **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002HL FileErrorConstructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0002HL] `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md` from a documented constructor page to a first-draft-C++ ready exact by-memory emitter.
- Final disposition: keep `CANONICAL_OWNER:00004X`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004X`; raise target metadata to `COMPLETION:90`, `CONFIDENCE:92`; insert formal reconstruction C++ for `FileError::FileError(const wchar_t *path)`.
- Required action: supervisor validation, then implementation callback to write the target/support documentation updates and scoped validators. B012 did not edit by-* docs in this report-only pass.
- Confidence: high. The remaining uncertainty is original spelling/style inside the broader `Error` hierarchy, not the target's behavior, owner, range, source-facing constructor role, or C++ eligibility.

## Supporting Research

## Target

- Target UID: `0002HL`.
- Target path: `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`.
- Source queue/report row: supervisor-assigned report-only B-agent task from `Agent-B012/goal.md`.
- Current supervisor classification: reconstructable by-memory source-quality target needing blocker resolution, caller/reachability review, type/layout/name inference, related constructor comparison, and first-draft C++ decision.
- Current scores and parent state: target `86/89`; parent class [UID:00004X] `by-class/FileError.md` `85/89`; source owner [UID:0000J5] `by-file/Error.md` `87/85`.

## Current Target State

- Existing metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00004X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004X`, blank formal C++.
- Existing owner/emitter/reconstructable state: direct class owner is `FileError` [UID:00004X], source file route is `Error.cpp` [UID:0000J5], and the target is already a reconstructable emitter through the class.
- Existing C++/emitter state: C++ is blank because older notes treated original parameter/member spelling and hierarchy declaration as not final-source quality.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - Original parameter/member spelling was still described as medium confidence.
  - Class-level declaration and hierarchy-wide `+0x0c` virtual spelling remain broad `Error` hierarchy work.
  - Older generated/manual coverage rows still carry stale lower percentages and generated `Error.cpp` still has stale empty markers.
  - The previously suspected trailing field/status word has already been rejected by B013 and current support docs; it is a defensive final NUL write inside `wchar_t m_message[80]`.
- Related target/support docs checked:
  - `by-class/FileError.md`
  - `by-file/Error.md`
  - `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`
  - `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md`
  - `by-type/by-struct/ErrorObjectLayouts.md`
  - `by-type/by-vtable/ErrorHierarchyVtables.md`
  - `by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md`
  - `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md`
  - related generated `auto-generated/NexusTK/util/Error.cpp` and manual `by-memory/-coverage-report.md` as stale/read-only context.

## Executive Recommendation

The direct owner remains [UID:00004X] `FileError`, with source placement through [UID:0000J5] `util/Error.cpp`. This exact memory page should emit the constructor body, not the class page and not the broad `ErrorWrappers` aggregate. The target is no longer blocked from draft C++ by parameter/member spelling: the best source-facing names are `path` for the constructor argument and `m_message` for the inline wide buffer, based on caller use, format string semantics, B013 layout resolution, and surrounding error-hierarchy documentation.

Do not move this implementation to archive/file consumers. `sub_49C180`, `sub_4F53B0`, and `StdioFile::Open` construct and throw `FileError`, but they are use-sites. They prove the argument role and exception behavior, not source ownership.

## Supervisor Active Recheck

- The active B012 goal requires report-only research first, with no by-* edits, no coverage edits, no IDA DB changes, and MCP-backed evidence.
- Split repair is not required for this target. The range `0x004a6430-0x004a646f` is exact and bounded by `int3` padding before it and a separate cleanup island at `0x004a6470`.
- Every source-bearing child in this target's immediate scope has a disposition:
  - `0x004a6430-0x004a646f` is this constructor and is ready for formal C++.
  - `0x004a6470-0x004a647b` is a separate base-cleanup/unwind island already documented by `Error.md` and `ErrorWrappers`; it is not part of this target range.
  - `0x004a6480-0x004a6499` is [UID:000140] `FileErrorCopyMessage`, a separate vtable-slot helper.

## Inference Research Guidance Check

This pass treats existing by-* docs as leads and rechecks score-blocking issues instead of copying prior uncertainty forward. IDA facts are separated from documentation evidence and source-shape inference. No Wave2/Wave3 source material was used as authority; old generated `Error.cpp` output is treated as stale lead material only.

The important inference decision is that lack of original symbol proof no longer justifies blank target C++. The binary facts and support docs are strong enough to use realistic human source-facing names in the formal C++ block while documenting that exact original spelling is inferred.

## Heuristic / Inference Reanalysis And Validation

- Constructor source name: `FileError::FileError(const wchar_t *path)` is strongly inferred and already supported by current docs. The constructor has one stack argument, all live callers pass file/path strings, the format literal is `L"File not found : %s"`, and `StdioFile::Open` constructs `FileError` on stat/open failure with its `path` argument. `fileName` is plausible, but `path` is the best current project-local choice because support docs already use it and the strongest caller is a file path open routine.
- Inline field name and type: `wchar_t m_message[80]` is strongly inferred and already supported by [UID:0001UE] `ErrorObjectLayouts`. The constructor passes `this + 2` in `wchar_t *` terms, which is byte offset `+0x04`, with capacity `0x50` wide characters and max count `0x4e`, then writes `word ptr [esi+0xa2] = 0`. Offset `+0xa2` is `+0x04 + 79 * 2`, so it terminates `m_message[79]`.
- Formatting helper role: `sub_471110` is CRT wrapper glue around secure wide formatting, not a source-owned NexusTK helper that should be emitted here. Formal source should use a normal CRT call shape rather than preserving `sub_471110`.
- Base setup: `sub_4F4A80` initializes the inherited `LObject`/base vtable state. The human C++ constructor body should not manually write vtables or call `sub_4F4A80`; those effects are compiler output from normal base construction.
- Range and split: the target is exact. The nearby `0x004a6470` cleanup island and `0x004a6480` copy helper are separate ranges and should stay out of this constructor's formal C++.
- Generated output: generated `NexusTK/util/Error.cpp` still reports stale lower score/empty markers. It should refresh after source metadata and C++ are inserted; it is not authority.

Rejected alternatives:

- Leave C++ blank because exact original names are unproven: rejected. The project standard requires realistic human source-facing names when behavior/source shape is recoverable.
- Emit a raw decompiler body with vtable stores, `this + 2`, or `sub_471110`: rejected as reverse-engineered output, not plausible original source.
- Move implementation ownership to archive/file open callers: rejected because callers are exception throw sites, while vtable/layout/constructor clustering place the implementation in the error hierarchy.
- Treat `0x004a6470` as part of this constructor page: rejected because current range is `[0x004a6430,0x004a646f)`, the successor bytes are a distinct cleanup island, and [UID:000140] starts separately at `0x004a6480`.

## Evidence Standards Used

- IDA MCP live session `80de0a67`, endpoint checked 2026-06-26 with listener PID `13684`, worker PID `26892`, `NexusTK.exe.i64`, `is_analyzing:false`.
- IDA function lookup, decompilation, disassembly, callees, xrefs, byte reads, string/literal bytes, and signature generation.
- Current by-* docs for class/file/layout/vtable/source-placement context.
- Negative evidence: boundary bytes, no function at target end, no xref to the end address, no data pointer hit for the constructor VA, string reuse outside the constructor, and separation from successor helper ranges.

The evidence ladder is sufficient because the target behavior is independently supported by decompilation/disassembly, caller contexts, vtable/store data, literal bytes, support docs, and layout math. IDA cannot prove original local names, so `path` and `m_message` remain source-facing inferred names, but that does not block first-draft C++.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `lookup_funcs 0x004a6430` -> `sub_4A6430`, size `0x3f`.
  - `analyze_function 0x004a6430` -> base setup `sub_4F4A80`, vtable store to `FileError::vftable`, call to `sub_471110(this+2, 0x50, 0x4e, aFi, ArgList)`, final NUL write, return `this`, and `retn 4`.
  - `callees 0x004a6430` -> `sub_4F4A80`, `sub_471110`.
  - `xrefs_to 0x004a6430` -> code refs at `0x0049c21a`, `0x004f54df`, `0x00582169`, and `0x005821a8`.
  - `xrefs_to 0x006193d4` -> constructor vtable write at `0x004a6445`.
  - `xrefs_to 0x004a6480` -> `FileError` vtable data ref at `0x006193e0`.
  - `get_bytes` around `0x004a6429-0x004a6485` -> `int3` padding before constructor, exact constructor bytes, `int3` at `0x004a646f`, separate cleanup island at `0x004a6470`, then `int3` padding before `0x004a6480`.
  - `get_bytes 0x006126f4` -> UTF-16 `L"File not found : %s"` at `aFi`.
  - `make_signature_for_range 0x004a6430-0x004a646f` -> unique signature for the constructor body.
  - `analyze_function 0x00471110` -> CRT-style secure wide formatting wrapper around `__stdio_common_vsnwprintf_s`; its return is ignored by this constructor.
  - `analyze_function 0x004f4a80` -> base/vtable setup helper.
  - `analyze_function 0x004a6480` -> `_wcscpy_s(destination, size, this+2)` copy helper for the same inline buffer.
  - `analyze_function 0x005820d0` -> `StdioFile::Open` constructs and throws `FileError` on stat/open failure with the path argument.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target page and support docs listed in `Current Target State`.
  - `rg --files -g '*0002HL*'` found no existing B-agent research report for this UID in the project tree.
- Negative checks performed:
  - No function at `0x004a646f`.
  - No xrefs to `0x004a646f`.
  - No `find_bytes` data pointer hit for little-endian constructor VA `30 64 4A 00`.
  - `aFi`/`L"File not found : %s"` is reused elsewhere, so string adjacency is not treated as ownership proof.
  - Generated `Error.cpp` stale score/empty marker was not treated as authority.
- Failed, unavailable, or intentionally skipped checks and why:
  - No by-* edits, validators, or leases were run in report-only mode.
  - No IDA DB rename/type/comment edits were attempted because the active assignment forbids IDA DB mutation and the report only recommends source-facing documentation/C++ changes.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0002HL` is exactly `FileError::FileError(const wchar_t *path)` | High | One stack argument, `L"File not found : %s"`, file/path caller sites, current `FileError` docs, vtable store | No original symbols; generated output stale; string reused outside constructor | Exact original parameter spelling may differ, but `path` is the best human source-facing name |
| Inline storage is `wchar_t m_message[80]` at byte offset `+0x04` | High | `this+2`, capacity `0x50`, max `0x4e`, final NUL at `+0xa2`, copy helper reads `this+2`, layout docs | Prior trailing-field/status hypothesis rejected by B013/local bytes | Exact original member spelling is inferred; `m_message` matches current support docs |
| Formal target C++ is safe now | High | Owner/emitter/reconstructable already set, average score clears gate, behavior/body exact, names/types defensibly inferred | Class-level hierarchy declaration not complete; generated `Error.cpp` stale | Support docs should keep class-level C++ blank until hierarchy declaration is standardized |
| `sub_471110` should not be emitted as a source helper | High | Wrapper around CRT `__stdio_common_vsnwprintf_s`; current CrtWideVsnprintfWrapper page is nonreconstructable | Source might have used a local formatting wrapper name, but current evidence shows CRT glue | Use normal `_snwprintf_s` source shape in this constructor |
| Caller modules do not own the constructor implementation | High | Compact Error hierarchy cluster, FileError vtable, class/file owner docs, caller throw-site semantics | Archive/file callers are strong use evidence | None for this target |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - Modeled function at `0x004a6430` with exact size `0x3f`.
  - Constructor installs `FileError` vtable and formats into inline buffer.
  - Final NUL store proves an 80-wide-character message buffer and rejects a separate trailing status/flag field.
  - Four construction code refs show real use as thrown `FileError`.
  - Vtable data points to the sibling message-copy helper at `0x004a6480`.
- Corroborating documentation/generated-report evidence:
  - Current `FileError`, `Error`, `ErrorWrappers`, `ErrorObjectLayouts`, and `ErrorHierarchyVtables` docs all place this target inside the shared `util/Error.cpp` hierarchy.
  - Current docs already accept `FileError(const wchar_t *path)` and `wchar_t m_message[80]` as the source-facing direction.
- Strongest inference chain and why it is sufficient:
  - The constructor argument is used only to format a file-not-found message; the strongest caller is `StdioFile::Open(path)` failure handling; the source-facing parameter should be `path`.
  - The buffer/copy-helper pair provide independent confirmation of the member type and offset; `m_message` is the best current project-local member name.

## IDA MCP Facts

- Function/range facts:
  - `sub_4A6430` covers `0x004a6430-0x004a646f`, size `0x3f`.
  - Signature for the range is unique.
  - There is no function at `0x004a646f`.
- Data/table/padding facts:
  - Constructor stores `0x006193d4` as the `FileError` vtable pointer.
  - Bytes before the constructor and after `0x004a647b` are `int3` padding.
  - `0x004a6470-0x004a647b` writes base Error vtable `0x00619344` and jumps to base cleanup; it is a successor island, not part of this page.
- Xref facts:
  - Code refs to constructor at `0x0049c21a`, `0x004f54df`, `0x00582169`, `0x005821a8`.
  - Vtable data ref to copy helper `0x004a6480` at `0x006193e0`.
- Vtable/global/type facts:
  - `FileError` vtable and layout docs align with the constructor and copy helper.
  - `m_message[80]` is supported by constructor and copy-helper access patterns.
- Negative IDA facts:
  - No xrefs to the range end.
  - No direct data-pointer hit for the constructor start.
  - `L"File not found : %s"` is reused, so it is not sole ownership evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a6430-0x004a646f` | [UID:0002HL] `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md` | `FileError` constructor | TRUE | [UID:00004X] `FileError` | `86/89` now; recommend `90/92` | Exact, C++ ready |
| `0x004a6470-0x004a647b` | listed in [UID:0000J5] and [UID:00013X] split candidates | duplicate/base cleanup island | likely compiler/unwind support disposition | `Error` hierarchy | no exact page currently | Separate range; not a blocker for `0002HL` |
| `0x004a6480-0x004a6499` | [UID:000140] `FileErrorCopyMessage` | vtable slot copy helper | TRUE | [UID:00004X] `FileError` | stale coverage lower than docs | Separate helper supporting same buffer layout |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049c21a` / `sub_49C180` | calls `0x004a6430` | Archive/file lookup failure constructs `FileError`; use-site, not owner |
| `0x004f54df` / `sub_4F53B0` | calls `0x004a6430` | Logo/movie load corruption/file error path constructs `FileError`; use-site |
| `0x00582169`, `0x005821a8` / `StdioFile::Open` | calls `0x004a6430` | Stat/open failure constructs `FileError(path)` and throws it |
| `0x004a643a` | calls `sub_4F4A80` | compiler-emitted/base setup |
| `0x004a6455` | calls `sub_471110` | secure wide formatting wrapper |
| `0x006193e0` | data ref to `0x004a6480` | `FileError` message-copy vtable slot |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already records exact constructor behavior and owner route.
  - `FileError.md` records `FileError(const wchar_t *path)` and `wchar_t m_message[80]`.
  - `ErrorObjectLayouts.md` records the 80-wide-character inline message storage.
  - `ErrorHierarchyVtables.md` records the shared error vtable shape and slot policy.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page still says final C++ is intentionally blank due parameter/member spelling. This pass resolves that target-local blocker.
  - `FileError.md` still says the constructor signature and inline buffer declaration are not final enough for C++; that is stale for the exact child but remains partly true for the class-level declaration.
  - Manual `by-memory/-coverage-report.md` row still shows `78%`.
  - Generated `NexusTK/util/Error.cpp` still carries stale lower score/empty marker.
- Generated/coverage report state: generated files are read-only inputs for B012. Supervisor/validator should refresh after by-* implementation.

## Ranked Ownership Analysis

### 1. [UID:00004X] `FileError` via [UID:0000J5] `Error`

- Evidence for: constructor writes `FileError` vtable; sibling copy helper is in the `FileError` vtable slot; support docs place FileError under `util/Error.cpp`; layout/vtable docs match the inline buffer and source cluster.
- Evidence against: exact original header spelling is not recovered.
- Decision: keep as direct canonical owner/emitter. The unresolved original spelling does not defeat owner/emitter or first-draft C++.

### 2. Broad [UID:00013X] `ErrorWrappers` aggregate

- Evidence for: contiguous error-hierarchy executable run contains the constructor and related helpers.
- Evidence against: aggregate spans many derived classes and helper types; by-memory C++ from the aggregate would conflate class methods and helper islands.
- Decision: use only as support/container context. Do not emit this constructor through the aggregate.

### 3. Caller modules such as DAT/archive, LogoPlayerPane, or StdioFile

- Evidence for: multiple call sites construct and throw `FileError`.
- Evidence against: callers do not own the class, vtable, layout, or reusable copy helper. They are consumers.
- Decision: reject as implementation owner; keep as argument/use evidence.

## Source Placement

- Recommended source file/class/global/module placement: `util/Error.cpp`, class `FileError`.
- Why this placement fits source-tree and subsystem context: FileError shares vtable/layout conventions with the compact `Error` hierarchy, uses the shared base setup and copy-helper slot, and is constructed by multiple subsystems.
- Rejected placements and why:
  - `archive/` or `file/` modules: only call/throw the exception.
  - generated one-class file `class_FileError.cpp`: generated structure, not source-layout proof.
  - broad `ErrorWrappers` C++ block: too coarse and would mix unrelated class bodies.
- Remaining placement uncertainty: final project-wide header split and exact virtual method declaration remain hierarchy-level work; they do not block this constructor's by-memory C++ block.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target range is `[0x004a6430,0x004a646f)`, size `0x3f`; the byte at `0x004a646f` is padding/end marker, and `0x004a6470` starts a separate cleanup island.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no child split needed for this target. The cleanup island remains an `Error` hierarchy split candidate already documented elsewhere.
- Padding/table/data/code distinctions: padding before/after helps prove the constructor boundary; vtable data and string data are support evidence, not code in this page.
- Parent/container impact: target remains an exact child of `FileError`; no parent change.

## Negative Evidence Summary

- No direct original symbols or source headers were found for exact parameter/member spelling.
- No data-pointer route to constructor start was found; this is not a liveness blocker because four code call refs exist.
- `aFi` is reused in other code, so string address alone does not establish ownership.
- Generated `Error.cpp` stale markers do not override current by-* and IDA evidence.
- The nearby `0x004a6470` cleanup island is not part of this range and should not be folded into this constructor's C++.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Constructor: `FileError::FileError(const wchar_t *path)`.
  - Member: `wchar_t m_message[80]`.
  - Formatting call in formal C++: `_snwprintf_s(m_message, 80, 78, L"File not found : %s", path);`.
- Evidence for each proposed name/type/comment:
  - `path`: caller contexts and file-not-found format literal.
  - `m_message`: existing Error layout convention, copy-helper source, and inline buffer use.
  - `80`/`78`: direct pushes `0x50` and `0x4e`.
- Items intentionally left unchanged and why:
  - IDA function names `sub_4A6430`, `sub_471110`, and `sub_4F4A80` should remain research aliases only unless a supervisor explicitly authorizes IDA DB edits.
  - The class-level common `+0x0c` virtual name/return remains a hierarchy-wide policy item, not a target-local IDA rename.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested in this report-only assignment.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has an owner/emitter route, clears the 85/85 gate, and the target-local behavior and source-facing names are now sufficiently resolved.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
FileError::FileError(const wchar_t *path)
{
    _snwprintf_s(m_message, 80, 78, L"File not found : %s", path);
    m_message[79] = L'\0';
}
```

- Reason it preserves exact original behavior:
  - The CRT source call matches the observed wrapper arguments: buffer at `+0x04`, buffer count `80`, maximum count `78`, format literal `L"File not found : %s"`, and the incoming path argument.
  - The explicit terminator at `m_message[79]` matches `word ptr [esi+0xa2] = 0`.
  - Compiler-generated vtable writes/base setup are omitted because normal C++ constructor emission handles them.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape:
  - `_snwprintf_s` is a normal Windows CRT secure wide-format call shape for this compiled wrapper.
  - `FileError::FileError(const wchar_t *path)` and `m_message` look like human source, not IDA/decompiler scaffolding.
  - Numeric constants are retained because the binary pushes explicit `80` and `78`; replacing them with undefined project constants would invent unsupported surrounding source.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels:
  - `path` instead of `ArgList`.
  - `m_message` instead of `this + 2` or byte-offset access.
  - `_snwprintf_s` instead of `sub_471110`.
- Naming/coding style convention used and evidence for consistency:
  - `m_` member style matches current `ErrorObjectLayouts`/class docs.
  - Simple C-style CRT function call matches the reconstructed utility/error code style and era.
- Reason code should remain blank, if applicable: not applicable for this exact target. Class-level C++ can remain blank until the full hierarchy declaration is standardized, but this by-memory constructor should no longer be blank.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended:
  - Target [UID:0002HL]: raise to `COMPLETION:90`, `CONFIDENCE:92`.
  - Target [UID:0002HL]: insert the formal C++ block above.
  - Target [UID:0002HL]: update status/reconstruction notes to state that `path`, `m_message[80]`, and first-draft C++ are now target-local resolved/inferred, while original spelling remains noted as inferred.
  - Support [UID:00004X] `FileError`: update notes so the exact child is C++ ready and the class-level C++ remains blank only because class declaration/virtual policy is broader hierarchy work. Recommend raising class to `COMPLETION:87`, `CONFIDENCE:91`.
  - Support [UID:0000J5] `Error`: add a short note that `FileErrorConstructor` can emit through its exact child and that class/aggregate C++ remains blank for hierarchy policy, not target-local uncertainty. No file score change required.
  - Support [UID:00013X] `ErrorWrappers`: add/confirm that `0002HL` emits through exact child; the aggregate should not emit monolithic C++. No score change required.
- Exact parent assignments recommended: no owner/emitter changes.
- Exact items left no-owner/non-emitting and why: none in this target. The successor cleanup island remains separate documented split work.
- Exact future work outside this assignment scope:
  - Hierarchy-wide `Error.h` declaration and common `+0x0c` virtual return/name policy.
  - Separate cleanup island disposition for `0x004a6470-0x004a647b` if supervisor wants an exact child page.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`.
- Exact report facts to incorporate:
  - MCP session `80de0a67` reconfirmed function range, disassembly/decompilation, callers, vtable store, format literal, successor boundary, and CRT wrapper role.
  - `FileError::FileError(const wchar_t *path)` and `wchar_t m_message[80]` are now source-quality inferred enough for this exact child.
  - `sub_471110` should be described as CRT secure wide formatting glue and not emitted as a new NexusTK helper.
  - `0x004a6470` cleanup island and `0x004a6480` copy helper remain separate ranges.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:86 -> 90`.
  - `CONFIDENCE:89 -> 92`.
  - Keep `CANONICAL_OWNER:00004X`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:00004X`.
  - Insert the formal C++ block from this report.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Prior trailing status/flag interpretation is stale and rejected.
  - Generated `Error.cpp` stale empty marker is not authority.
  - Caller modules are use-sites, not owners.

## Recommended Support Doc Changes

- Support path: `by-class/FileError.md`.
  - Exact report facts to incorporate: the exact child [UID:0002HL] is first-draft-C++ ready; target-local constructor signature and inline buffer are now resolved/inferred strongly enough; class-level C++ still waits for full hierarchy declaration and virtual policy.
  - Metadata/link/score/coverage/source-placement changes: recommend `COMPLETION:85 -> 87`, `CONFIDENCE:89 -> 91`; keep owner/emitter [UID:0000J5]; keep class-level C++ blank.
- Support path: `by-file/Error.md`.
  - Exact report facts to incorporate: `FileErrorConstructor` now emits through exact child; broad `ErrorWrappers` aggregate remains no monolithic C++; `0x004a6470` cleanup island remains separate split candidate.
  - Metadata/link/score/coverage/source-placement changes: no required score change.
- Support path: `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`.
  - Exact report facts to incorporate: `0002HL` is exact child C++ emitter; aggregate should keep C++ blank to avoid confluence.
  - Metadata/link/score/coverage/source-placement changes: no required score change.
- Support path: `by-type/by-struct/ErrorObjectLayouts.md`.
  - Exact report facts to incorporate: if not already at equal detail, preserve current `wchar_t m_message[80]` proof from `0002HL` and `000140`.
  - Metadata/link/score/coverage/source-placement changes: no required score change.
- Support path: `by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md`.
  - Exact report facts to incorporate: no required edit if it already states the wrapper is CRT/runtime glue; cite it from target if supervisor wants stronger cross-linking.

## Score And Metadata Recommendation

- Current score/metadata: `86/89`, owner `00004X`, reconstructable true, emitter `00004X`, blank C++.
- Recommended score/metadata: `90/92`, owner `00004X`, reconstructable true, emitter `00004X`, formal C++ inserted.
- Score rationale and reason not higher/lower:
  - Reason higher: this pass resolves the score-limiting target-local blocker. Exact function body, caller path role, message buffer layout, source-facing parameter/member names, formatting helper role, split boundary, owner/emitter, and draft C++ disposition are now all documented with MCP-backed evidence.
  - Reason not higher than `90/92`: exact original source spelling and the full `Error.h` hierarchy declaration remain unproven; class-level virtual declaration policy is broader than this constructor page.
  - Reason not lower: behavior, range, call refs, vtable, layout, and first-draft source body are independently confirmed and no target-local blocker remains.
- Score-improvement attempt:
  - Parameter/member names: resolved by caller/literal/layout evidence to `path` and `m_message`.
  - Formatting helper: resolved to CRT wrapper, not a source-owned helper.
  - Split/range boundary: resolved; cleanup island and copy helper are separate.
  - C++ readiness: resolved; formal block supplied.
  - Caller/ownership: resolved; callers are consumers, implementation owner is FileError/Error.
- Metadata fields to change or leave unchanged:
  - Change only `COMPLETION`, `CONFIDENCE`, and formal C++ for the target.
  - Leave owner/emitter/reconstructable unchanged.

## Open Questions With Attempted Resolution

- Original parameter spelling:
  - Evidence checked: constructor argument use, file/path caller contexts, `StdioFile::Open(path)` decompilation, `L"File not found : %s"` literal, current support docs.
  - Best supported resolution: use `path`.
  - Remaining uncertainty: original source may have used `filename` or `fileName`; this does not block C++ because `path` is a realistic source-facing name and current docs already use it.
- Original member spelling:
  - Evidence checked: buffer offset/capacity, final terminator math, copy-helper source operand, layout docs, class docs.
  - Best supported resolution: use `m_message`.
  - Remaining uncertainty: exact original spelling is not proven; do not keep IDA labels because final source must be human-looking.
- Class-level `Error` declaration:
  - Evidence checked: `FileError`, `Error`, `ErrorWrappers`, layout/vtable docs, sibling copy helpers.
  - Best supported resolution: target C++ can be emitted now; class-level/aggregate C++ may remain blank until hierarchy-wide declaration standardization.
  - Score/C++ impact: caps target at `90/92` rather than higher; does not block the exact child.
- `0x004a6470` cleanup island:
  - Evidence checked: bytes, boundary, support docs, relationship to successor copy helper.
  - Best supported resolution: separate split candidate/unwind cleanup helper, not part of this target.
  - Score/C++ impact: no blocker for this page.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- File/placement: `by-memory/-coverage-report.md`, replace the existing [UID:0002HL] row if the supervisor still maintains this manual report.
- Exact replacement text:

```markdown
        - [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) 0x004a6430-0x004a646f | method | FileErrorConstructor : reconstructable : 90% : very strong : Exact FileError constructor with live MCP range/body/caller/vtable/literal evidence, source-facing `FileError::FileError(const wchar_t *path)` and `wchar_t m_message[80]` inference, separate cleanup/copy-helper boundaries, and formal first-draft C++ ready through the FileError class emitter.
```

- Reason B agent must not apply it directly: B agents are banned from editing manual `-coverage-report.md` files by default; supervisor-owned application only.

## Follow-Up Actions

- Supervisor actions:
  - Verify this implementation callback claim by claim against the accepted report, target/support docs, validator output, and checked checklist.
  - If verification succeeds, execute the report with the validator lifecycle command.
  - Apply the manual coverage row only if still needed after source metadata/validator refresh; B012 did not edit manual `-coverage-report.md` files.
- A-agent actions: none.
- B012 future research actions: only after supervisor callback or a new assignment; no further current-pass target blocker remains.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `90/92`.
- Remaining uncertainty: exact original local/member spelling and class-level virtual declaration policy. These are recorded as inferred/source-shape issues, not blockers to the target's formal C++.

## Validator Results

- Implementation callback validation completed 2026-06-26.
- MCP availability/verification before callback closure:
  - `initialize` and `tools/list` against `http://127.0.0.1:13337/mcp` returned HTTP 200.
  - `idb_list` returned active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
  - `server_health` for `80de0a67` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
  - `lookup_funcs` reconfirmed `0x004a6430` as `sub_4A6430` size `0x3f`, `0x004a646f` as not a function, `0x004a6470` as separate `sub_4A6470` size `0x0b`, and `0x004a6480` as `sub_4A6480` size `0x19`.
- Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md --apply --queue-timeout 240`
    - Exit code: `0`; `command_id:000000003551`; `command_timestamp:2026-06-26T22:17:01-04:00`; `ok:1`.
    - Warnings/errors: none for the target; `generated_refresh:deferred`, `generated_refresh_command_id:000000003551`.
  - `python .\tools\validator.py --mode file --file by-class/FileError.md --apply --queue-timeout 240`
    - Exit code: `0`; `command_id:000000003552`; `command_timestamp:2026-06-26T22:17:07-04:00`; `ok:1`.
    - Warnings/errors: none for the class; `generated_refresh:deferred`, `generated_refresh_command_id:000000003552`.
  - `python .\tools\validator.py --mode file --file by-file/Error.md --apply --queue-timeout 240`
    - Exit code: `0`; `command_id:000000003553`; `command_timestamp:2026-06-26T22:17:15-04:00`; `ok:1`.
    - Warning: four `missing_ref_target 0002ND by-file/Error.md target path does not exist: by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md` diagnostics. This is a pre-existing/stale UID-path diagnostic outside the accepted `0002HL` changes; B012 did not hand-edit validator state or generated annotations.
    - `generated_refresh:deferred`, `generated_refresh_command_id:000000003553`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --queue-timeout 240`
    - Exit code: `0`; `command_id:000000003554`; `command_timestamp:2026-06-26T22:17:31-04:00`; `ok:1`.
    - Warnings/errors: none for the aggregate; `generated_refresh:deferred`, `generated_refresh_command_id:000000003554`.
- Generated refresh state:
  - `python .\tools\validator.py --queue-status` returned `command_id:000000003555`, `command_timestamp:2026-06-26T22:18:13-04:00`, `queued jobs:0`, `processing jobs:0`, `queued generated refresh jobs:0`, and `processing generated refresh jobs:0`.
  - `auto-generated/NexusTK/util/Error.cpp` header is current at `validator-command-id:000000003554`, `validator-refreshed-at:2026-06-26T22:17:31-04:00`, `validator-refresh-source:deferred-generated-refresh`, and includes the [UID:0002HL] `FileError::FileError(const wchar_t *path)` body.
  - `auto-generated/-ag-coverage-report-by-memory.md` header is current at `validator-command-id:000000003554`, `validator-refreshed-at:2026-06-26T22:17:31-04:00`, `validator-refresh-source:deferred-generated-refresh`.
- Validator side effects reported by each scoped file validator: `projected_stats_update` updated `project-level/-auto-completion-stats.md` projected path completion section, and generated refresh was deferred then completed. B012 did not manually edit generated/project-level files or validator/tool state.
- Lease state:
  - B012 leased `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`, `by-class/FileError.md`, `by-file/Error.md`, and `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` immediately before the validator batch.
  - `python .\leaser.py B012 unlease` released all four leases successfully.
  - Final `tools/leaser/Agents/current_leases.md` check reported `No active leases.`

## Changed Files

- Created: `tools/leaser/Agents/Agent-B012/research/0002HL-FileErrorConstructor-source-quality.md`.
- Modified during this implementation callback: this report checklist/results only.
- By-* docs verified as already complete at report-level detail and validated under B012 lease:
  - `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`
  - `by-class/FileError.md`
  - `by-file/Error.md`
  - `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`
- Support docs checked read-only and left unchanged because accepted facts were already present at equal-or-greater detail:
  - `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md`
  - `by-type/by-struct/ErrorObjectLayouts.md`
  - `by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md`
- Renamed: none.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: B012 `goal.md` assignment `B012-implement-0002HL-file-error-constructor-source-quality-20260626` states the supervisor accepted this report and assigned implementation callback mode.
- [x] Target/support docs to update: `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`, `by-class/FileError.md`, and short supporting notes in `by-file/Error.md` plus `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` if not already present at equal detail. Proof: all four files contain the accepted details at report-level detail and were validated with command IDs `000000003551` through `000000003554`.
- [x] Current target state and actual evidence checked recorded: metadata, owner/emitter, blank C++, MCP session `80de0a67`, function body, callers, bytes, format literal, vtable refs, support docs, stale generated/manual coverage context. Proof: target page now records `90/92`, owner/emitter `00004X`, formal C++, MCP evidence through session `80de0a67`, caller/use-site evidence, literal bytes, vtable/copy-helper routes, and stale generated/manual caveats.
- [x] Metadata/score changes to apply: target `86/89 -> 90/92`; recommend support class `85/89 -> 87/91`; no owner/emitter/reconstructable changes. Proof: target header is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00004X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004X`; `by-class/FileError.md` header is `87/91` with owner/emitter `0000J5`.
- [x] Score-limiting blockers researched to resolution: parameter/member names resolved to source-facing `path` and `m_message`; formatting helper resolved to CRT source call; range/split boundary resolved; caller ownership rejected; target C++ readiness resolved. Proof: target `Reconstruction Notes`, `Score Rationale`, and `Changes` sections preserve these decisions, and support docs echo the caller/use-site and hierarchy-declaration caveats.
- [x] Owner/emitter/reconstructable changes to apply: none; keep `CANONICAL_OWNER:00004X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004X`. Proof: target metadata matches exactly after validator `000000003551`.
- [x] Split/rename/new-child changes to apply: none for this target; preserve `0x004a6470` as separate documented cleanup island and `0x004a6480` as separate [UID:000140] helper. Proof: target and aggregate docs record the cleanup island as separate and [UID:000140] as the next exact copy helper; MCP lookup reconfirmed `0x004a6470` and `0x004a6480` as separate functions.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement remains `util/Error.cpp`; no IDA DB edits requested. Proof: `by-file/Error.md`, target, class, and aggregate all keep `util/Error.cpp` placement; B012 made no IDA DB edits.
- [x] First-draft C++ to apply: insert formal `FileError::FileError(const wchar_t *path)` block using `_snwprintf_s(m_message, 80, 78, L"File not found : %s", path);` and `m_message[79] = L'\0';`. Proof: target formal `RECONSTRUCTION_CPP CODE` block and generated `auto-generated/NexusTK/util/Error.cpp` contain the exact block.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP facts, source-facing names, layout math, formatting helper role, caller/use-site distinction, cleanup/copy-helper boundaries, stale generated/manual row caveat. Proof: target page has these at report-level detail; `FileError.md`, `Error.md`, and `ErrorWrappers.md` contain matching support notes.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: trailing status/flag hypothesis rejected; generated `Error.cpp` stale; string reuse is not owner proof; callers are consumers; no pointer route is not a liveness blocker. Proof: target `Reconstruction Notes`, `Negative checks`, and score/history sections preserve these points; support docs keep generated-output and caller-owner caveats.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated one-class `class_FileError.cpp`/Wave3 source layout treated as stale generated structure, not source proof. Proof: target/support docs keep generated one-class output as stale lead/context only; no Wave2/Wave3 source layout was used as authority.
- [x] Open questions to close or document as evidence-backed unresolved: original spelling remains inferred but not blocking; class-level hierarchy declaration remains outside this exact child; cleanup island remains separate split candidate. Proof: target and class docs document the source-facing names as inferred, class-level C++ as blocked by hierarchy declaration policy, and `0x004a6470` as separate cleanup-island work.
- [x] Validators to run during implementation callback: scoped file validation from `source-3/project-documentation` for each changed by-* doc, for example `python .\tools\validator.py --mode file --file by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md --apply --queue-timeout 240`. Proof: validators `000000003551`, `000000003552`, `000000003553`, and `000000003554` all exited `0` with `ok:1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated reports should refresh through validator; optional supervisor-owned manual `by-memory/-coverage-report.md` replacement row supplied above. Proof: generated Error.cpp and generated by-memory coverage both refreshed at command `000000003554`; B012 did not edit manual `by-memory/-coverage-report.md`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` says mode is implementation callback and the supervisor accepted this report.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, class, file, and aggregate docs already contain the accepted details; `FileErrorCopyMessage`, `ErrorObjectLayouts`, and `CrtWideVsnprintfWrapper` were checked and already had equal-or-greater detail for the accepted support facts.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target `90/92` plus formal C++; class `87/91`; owner/emitter unchanged; no split/rename/new-child required.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve the rejected trailing-field, caller-owner, decompiler-shaped output, string-only ownership, stale generated-output, cleanup-island merge, and CRT-wrapper-as-source alternatives.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: exact original spelling and hierarchy-wide declaration policy remain documented unresolved/capping issues, not target-local blockers; cleanup island remains separate split candidate.
- [x] Validators run and results recorded. Proof: validator commands/results are recorded above with command IDs, timestamps, exit codes, `ok` counts, warning detail, and generated-refresh state.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: generated Error.cpp and generated by-memory coverage headers are refreshed at `000000003554`; manual `by-memory/-coverage-report.md` text remains supervisor-owned only.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none remain unapplied. Only unrelated validator warning is stale/missing UID target `0002ND` in `by-file/Error.md`, outside this accepted report's scope and not hand-repaired by B012.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0002HL-FileErrorConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002HL-FileErrorConstructor-source-quality.md","timestamp":"2026-06-26T22:21:46","uid":"0002HL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
