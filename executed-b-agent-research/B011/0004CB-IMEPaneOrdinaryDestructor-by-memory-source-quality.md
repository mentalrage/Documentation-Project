** TARGET-REPORT-UID:0004CB **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004CB] IMEPaneOrdinaryDestructor By-Memory Source-Quality Report

## Final Recommendation

Implement [UID:0004CB] as the source-bearing ordinary `IMEPane::~IMEPane()` body through [UID:00006H] `IMEPane` into [UID:0000K5] `IMEPanes`.

The current blank state is a split-callback deferral, not a no-code proof. Live MCP confirms `sub_4E8000` is a modeled `0x98` byte ordinary destructor body that restores the `IMEPane` vtables, releases the three root child-pane slots, tears down the embedded focus list, clears `g_pIMEPane`, and runs `Pane` base teardown. The scalar deleting wrapper [UID:00031K] remains compiler ABI support around this source destructor and should stay comment-only.

Recommended target metadata after supervisor callback:

- Change `COMPLETION:82` to `COMPLETION:88`.
- Change `CONFIDENCE:89` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00006H`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00006H`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank unless the validator assigns an insertion position.

Do not raise higher yet. The child slots, focus-list ownership, singleton clear, helper names, and wrapper relationship are strong, but exact original source spelling for pane release and the low-level member-destructor ordering remain final-audit confidence caps.

## Target

- Target UID: [UID:0004CB].
- Target path: `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`.
- Assignment: `B011-report-0004CB-IMEPaneOrdinaryDestructor-by-memory-20260701`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue row: `82/89`, combined `85.5`, reconstructable `true`, reports `0`.
- Current generated output lead: `auto-generated/NexusTK/input/IMEPanes.cpp`, validator command `000000004120`, refreshed `2026-07-01T18:04:12-04:00`.

## Current Target State

- Current metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Current owner/route text: target already names [UID:00006H] `IMEPane` as direct owner and source route [UID:00006H] -> [UID:0000K5] `IMEPanes`.
- Current blocker wording: the page says formal C++ stays blank because no child-specific formal body was accepted when the split child was created on `2026-06-30`.
- Current generated state: `IMEPanes.cpp` contains the [UID:00006H] `IMEPane` class shell with `virtual ~IMEPane();`, populated [UID:0004CE] `IMEPane::HandleIMEMessage`, and [UID:00031K] scalar-wrapper comment saying source output is covered by `IMEPane::~IMEPane()`, but it has no UID0004CB marker/body yet.

## Evidence Checked

### Current Docs And Generated Inputs

- `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`.
- `by-class/IMEPane.md`.
- `by-file/IMEPanes.md`.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Sibling/support pages: [UID:0004CA] `IMEPaneConstructor`, [UID:0004CC] `IMEPaneSetFocusPane`, [UID:0004CE] `IMEPaneHandleIMEMessage`, [UID:00031G] `IMEPaneFocusCaretAnchorHelper`, [UID:00031K] `IMEPaneScalarDeletingDestructor`, [UID:0000R7] `g_pIMEPane`, [UID:0001PS] `0x0069b458-0x0069b45c.g_pIMEPane`, [UID:000079] `List`, [UID:000192] `ListNonDeletingDestructor`, [UID:0000MC] `Pane`, and [UID:0001EA] `PaneCore`.
- Generated output: `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Tracker/generated coverage: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-memory-coverage.md`.

### Old / Executed Report Search

Searched existing reports with `0004CB`, `0x004e8000`, `0x004e8098`, `IMEPaneOrdinaryDestructor`, `IMEPane`, and `IMEPanes`.

Relevant leads checked:

- `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`: created UID0004CB as an exact split child and intentionally left `EMITTER_UIDS` blank until a child-specific body pass.
- `executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md`: rechecked `IMEPane::IMEPane`, `IMEPane::~IMEPane`, and UID0004CE, proving `statusPane +0xf8`, `activeChildPane +0xfc`, `candidatePane +0x100`, and no status branch in UID0004CE.
- `tools/leaser/Agents/Agent-B008/research/0004CA-IMEPaneConstructor-by-memory-source-quality.md`: current sibling constructor lead, treated only as lead material, not implementation authority. It aligns with live MCP that `focusPaneList` is constructed at `+0x104` as `List(4,4)`.
- `tools/leaser/Agents/SpecialReports/benchmark-*0004CC-IMEPaneSetFocusPane-source-quality.md`: support leads for `focusPaneList`, `focusPaneCount`, and List API naming. These are not accepted target reports for UID0004CB.
- Current `List` and `Pane` docs: `0x004f30e0` is accepted `List::~List()`, and `0x00544690` is accepted `Pane::MarkForDeletion`.

Old reports were treated as leads. Current docs and live MCP evidence below are the proof for this report.

### IDA MCP Facts

MCP was mandatory and was available for this pass.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Active database from `idb_list` MCP id `1210`: `supervisor_resume_20260629`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, `is_analyzing:false`.
- Initial MCP calls without `database` returned `"database is required"`; after `idb_list`, calls with `database:"supervisor_resume_20260629"` succeeded. This was schema/session correction, not MCP unavailability.
- `lookup_funcs` MCP id `1221`:
  - `0x004e8000` -> `sub_4E8000`, size `0x98`.
  - `0x004e8098` -> not a function.
  - `0x004f30e0` -> `sub_4F30E0`, size `0x59`.
  - `0x00544690` -> `sub_544690`, size `0x1d`.
  - `0x00544580` -> `sub_544580`, size `0x107`.
- `decompile 0x004e8000` MCP id `1212`: reads `this[62]` (`+0xf8`), writes the three `IMEPane` vtable views, conditionally calls `sub_544690` for `this[62]`, `this[63]`, and `this[64]`, calls `sub_4F30E0(this + 65)`, writes `unk_69B458 = 0`, and calls `sub_544580(this)`.
- `disasm 0x004e8000` MCP id `1213`: confirms child slot reads at `0x004e8025`, `0x004e804e`, `0x004e805d`; child release calls at `0x004e8049`, `0x004e8058`, `0x004e8067`; `List::~List()` call at `0x004e8072` on `esi+0x104`; singleton clear at `0x004e8079`; and `Pane` teardown at `0x004e8083`.
- `analyze_function 0x004e8000` MCP id `1214`: reports prototype `void __thiscall(_DWORD *this)`, size `152`, callees `sub_544690`, `sub_544580`, and `sub_4F30E0`, no direct callers, 9 basic blocks, cyclomatic complexity 3.
- `decompile 0x004f30e0` MCP id `1215`: confirms `sub_4F30E0` is `List::~List()`, freeing `this[4]` through `GetMemoryMan` / `FreeBufferMemory` and then running `LObject` teardown.
- `xrefs_to` MCP id `1222`:
  - `0x004e8000` has no direct xrefs. This does not prove dead/no-code because the scalar deleting destructor at `0x004e8720` is vtable/thunk reached and duplicates the ordinary cleanup.
  - `0x004e8720` has xrefs from adjustor thunks `0x004e860e`, `0x004e8619`, and vtable data `0x0061c4fc`.
  - `0x004f30e0` has 13 refs, including UID0004CB at `0x004e8072` and UID00031K at `0x004e8799`.
  - `0x0069b458` has 17 data refs, including constructor publish/fallback at `0x004e7f68` / `0x004e7f6f`, UID0004CB clear at `0x004e8079`, root dispatcher read at `0x004e8391`, singleton clear helper at `0x004e85b0`, and scalar-wrapper clear at `0x004e87a0`.
- `get_bytes` MCP id `1223`: `0x004e8000-0x004e8098` bytes cover exactly the modeled function; `0x004e8098` begins `0xcc` padding before the next function; `0x0069b458` bytes are `00 00 00 00`.
- `decompile/disasm 0x004e7f20` MCP ids `1231` and `1232`: constructor support confirms `focusPaneList` is constructed at `+0x104` with `List(4,4)`, child slots `+0xf8/+0xfc/+0x100` are zeroed, and singleton publication pairs with UID0004CB clear.

## Positive Evidence Summary

- The target is a real modeled function at `0x004e8000`, size `0x98`, with exact end boundary `0x004e8098` and post-function `0xcc` padding.
- The function is the ordinary destructor body for [UID:00006H] `IMEPane`, not a scalar deleting wrapper. UID00031K is the wrapper and already documents that source output belongs to `IMEPane::~IMEPane()` and owned members.
- The three child slots match current accepted class fields:
  - `this[62]` / complete `+0xf8` -> `statusPane`.
  - `this[63]` / complete `+0xfc` -> `activeChildPane`.
  - `this[64]` / complete `+0x100` -> `candidatePane`.
- The child release helper is `Pane::MarkForDeletion` at `0x00544690`, already supported by Pane docs. The destructor has no child-slot zero stores after those calls, which is expected because the root object is being torn down.
- The focus-list cleanup is the accepted `List::~List()` body at `0x004f30e0`, reached on complete object `IMEPane +0x104`.
- The singleton clear writes zero to [UID:0000R7] `g_pIMEPane` / [UID:0001PS] storage at `0x0069b458`.
- The final `sub_544580(this)` is `Pane` base teardown and should not be handwritten in source C++.
- Absence of direct xrefs to `0x004e8000` is not no-code proof. The vtable route reaches UID00031K scalar deleting wrapper, which emits the same ordinary destructor cleanup and optional delete-flag behavior.

## Negative Evidence Summary

- No evidence supports leaving `EMITTER_UIDS` blank. The blank state came from the B008 split callback deferral, and this pass supplies the child-specific body review.
- No evidence supports a handwritten scalar deleting destructor method. UID00031K remains compiler ABI glue around this ordinary destructor.
- No evidence supports moving ownership to [UID:0000K5] directly, [UID:000079] `List`, [UID:0000MC] `Pane`, [UID:0000R7] `g_pIMEPane`, or any child-pane class. Those are route/support/dependency pages.
- Do not write vtable stores, SEH/security-cookie code, the `Pane` base destructor call, scalar delete flags, optional operator delete, or direct `sub_` names in the formal C++.
- Do not add `statusPane = NULL`, `activeChildPane = NULL`, or `candidatePane = NULL` to the destructor body. MCP/disassembly show no child-slot zero stores in UID0004CB after the release calls.

## Source Shape

Recommended formal C++ uses current source-facing class fields and the accepted Pane helper name. It intentionally omits vtable restoration, the embedded `List` destructor call, and `Pane` base teardown because those are compiler/member/base cleanup under the current class shell. The binary places the `List::~List()` call before the singleton clear; the paired constructor already has similar source-order lowering around `focusPaneList(4,4)`. That ordering nuance caps confidence but does not justify no-code or raw helper source.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0004CB]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEPane::~IMEPane()
{
    if (statusPane != NULL) {
        statusPane->MarkForDeletion();
    }

    if (activeChildPane != NULL) {
        activeChildPane->MarkForDeletion();
    }

    if (candidatePane != NULL) {
        candidatePane->MarkForDeletion();
    }

    g_pIMEPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale for source choices:

- `statusPane`, `activeChildPane`, and `candidatePane` are the current accepted fields for `+0xf8`, `+0xfc`, and `+0x100`.
- `MarkForDeletion()` is the accepted source-facing name for `0x00544690` in Pane docs. This target should document the helper explicitly rather than hiding it behind raw `sub_544690`.
- The focus-list teardown is represented by the `List focusPaneList` owned member and current List docs; do not handwrite `focusPaneList.~List()` in the formal block unless a later supervisor chooses a lower-level class-shell correction.
- `g_pIMEPane = NULL` maps the singleton clear at `0x004e8079`.
- The formal body does not clear child fields, because the object is destructing and the binary does not store zero to those slots.

Rejected formal alternatives:

- `delete statusPane; delete activeChildPane; delete candidatePane;`: rejected for this target because the direct helper is the accepted `Pane::MarkForDeletion` function and no scalar deleting destructor calls occur inside UID0004CB.
- Explicit `focusPaneList.~List();`: rejected from first-draft formal source under the current class shell because `focusPaneList` is declared as an owned `List` member. The observed call remains important evidence and should be recorded in prose.
- Explicit `Pane::~Pane();`, vtable writes, raw `sub_544690`, raw `sub_4F30E0`, raw `sub_544580`, or scalar-delete flag logic: rejected as compiler/lowered implementation detail.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`.

Implementation callback should:

- Change metadata from `COMPLETION:82`, `CONFIDENCE:89`, blank `EMITTER_UIDS` to `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`.
- Preserve `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block above.
- Update the Item Summary to state that the ordinary destructor now emits through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`.
- Replace stale "formal C++ remains blank until child-specific C++ is accepted" wording with this report's current proof.
- Record exact MCP evidence: function size/bounds, child slots/release calls, focus-list `List::~List()` call, singleton clear, base teardown, no direct xrefs, scalar wrapper route, and current zero bytes at `g_pIMEPane`.
- Preserve rejected alternatives: no-code, scalar-wrapper merge, direct by-file ownership, raw helper names, explicit vtable/EH/base/scalar-delete code, and child-slot zeroing.

## Recommended Support Doc Changes

Support path: `by-class/IMEPane.md`.

- No metadata change recommended.
- Add or amend method/evidence notes for [UID:0004CB]: it is now an emitting `IMEPane::~IMEPane()` body; releases `statusPane`, `activeChildPane`, and `candidatePane` through `Pane::MarkForDeletion`; relies on owned `focusPaneList` cleanup; clears `g_pIMEPane`; and leaves scalar-delete flag/delete behavior to [UID:00031K].
- Preserve the current class fields and add clarification that `focusPaneCount +0x110` is the embedded `focusPaneList` count slot / source-facing alias, not a separate destructor-cleared field.

Support path: `by-file/IMEPanes.md`.

- No metadata change recommended.
- Update Proposed Contents / Evidence Notes / Changes for [UID:0004CB] from non-emitting split child to emitting `IMEPane::~IMEPane()` routed through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`.
- Preserve source route [UID:00006H] -> [UID:0000K5] and generated expectation that `IMEPanes.cpp` should contain the UID0004CB marker/body after validation.

Support path: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.

- No metadata change recommended.
- Update the UID0004CB covered-range row to record `88/91`, formal destructor C++ populated, exact `0x98` function, child-pane release, focus-list teardown evidence, singleton clear, scalar-wrapper separation, and rejected no-code/direct-file/aggregate alternatives.
- Keep aggregate formal C++ as comment plus `[[CHILDREN]]`; do not duplicate the destructor body on the aggregate page.

Support path: `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.

- No metadata change recommended.
- Amend the proof comment/prose only if needed to point at UID0004CB as the now-formal ordinary destructor body. Preserve comment-only/no-handwritten-wrapper disposition.

Already-present support, no callback edit required unless the supervisor explicitly broadens scope:

- `by-global/g_pIMEPane.md` and `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` already record current zero storage and UID0004CB singleton clear at `0x004e8079`.
- `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md` already resolves `0x004f30e0` as `List::~List()`.
- `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-class/Pane.md`, and `by-file/Pane.md` already resolve `0x00544690` as `Pane::MarkForDeletion` and `0x00544580` as `Pane` teardown.
- `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md` remains a separate sibling target and should not be edited by this callback unless the supervisor adds it.

## Score And Metadata Recommendation

Current target:

- `COMPLETION:82`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00006H`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank

Recommended target after callback:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00006H`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006H`
- `EMITTER_POSITION_OPTIONAL:` blank

Rationale:

- Completion rises because the current split-callback deferral is resolved with exact formal C++, function boundary, field mapping, helper names, singleton clear, focus-list/member cleanup evidence, wrapper separation, rejected alternatives, and generated-output expectations.
- Confidence rises because live MCP, current by-* docs, constructor/destructor pairing, List/Panecore helper docs, g_pIMEPane xrefs, and scalar-wrapper route all agree on the target identity and behavior.
- Confidence remains below final-audit level because exact original spelling of the child release method and final class-shell/member-lifecycle ordering are inferred from project naming/support rather than symbol-proven.

## Open Questions With Attempted Resolution

- Exact original child release spelling: current Pane docs name `0x00544690` as `Pane::MarkForDeletion`. UID0004CE's accepted source uses `delete` for similar release behavior, but this target's direct helper evidence favors `MarkForDeletion()` in the formal destructor to avoid hiding a known helper.
- Focus-list cleanup placement: binary calls `List::~List()` before clearing `g_pIMEPane`. Current class docs model `focusPaneList` as an owned `List` member and UID00031K says source output is covered by `IMEPane::~IMEPane()`, owned members, and the class declaration. First draft therefore omits explicit `focusPaneList.~List()` while preserving the observed call in prose.
- Direct caller absence: no xrefs to `0x004e8000` were found, but scalar wrapper/vtable route and constructor/destructor pairing explain ordinary destructor reachability. This is not no-code proof.

## Validator Results

No validators were run. This is a report-only assignment and no target/support by-* docs were edited.

Recommended callback validators, all from `E:\NTK\GhidraBridge\source-3\project-documentation` with generated wait where `IMEPanes.cpp` freshness matters:

> Executable block R001 was removed from this report and preserved verbatim in [0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality-removed.md](0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated refresh result after callback:

- `auto-generated/NexusTK/input/IMEPanes.cpp` became equal/newer than B011's final relevant validator command. Initial post-validation header matched command `000000004200` / `2026-07-02T04:34:58-04:00`; later validator refresh advanced it to command `000000004205` / `2026-07-02T04:40:07-04:00`.
- The generated file contains `// UID:0004CB | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` followed by `IMEPane::~IMEPane()`.
- UID0004CB is no longer absent from generated output or non-emitting because `EMITTER_UIDS:00006H` and formal C++ are populated.
- Existing sibling bodies/comments remained present, including UID0004CE and UID00031K.

## Changed Files

- Report created during the initial report-only pass: `tools/leaser/Agents/Agent-B011/research/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md`.
- Callback-modified by-* docs: `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`, `by-class/IMEPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, and `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.
- Callback-modified report file: `tools/leaser/Agents/Agent-B011/research/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md`.
- Leases: B011 used short leases for the approved by-* edit/validator batch and released them after validation. A first partial lease attempt hit active B006 support-doc leases and was immediately released before waiting.
- Validators: scoped validators ran for all five edited by-* docs; command IDs `000000004196` through `000000004200` all exited `0` with `ok: 1` and `generated_refresh: completed`.
- Excluded from manual edits: generated files, generated reports, coverage reports, project-level generated reports, validator/tool state, supervisor ledgers, queues, archives, lock files, by-project-structure docs, and IDA DB. Generated/project-level/tool-owned side effects came only from validator runs.

## Claim And Incorporation Ledger

| Claim ID | Claim / fact to preserve | Evidence | Destination / exclusion | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | Current target is `82/89`, owner [UID:00006H], reconstructable true, blank emitter/formal C++, and tracker row combined `85.5`. | Target metadata; generated tracker/coverage rows. | [UID:0004CB] Status / Score Rationale. | incorporate | applied |
| C02 | Generated `IMEPanes.cpp` command `000000004120`, refreshed `2026-07-01T18:04:12-04:00`, has no UID0004CB marker/body yet. | Generated header and searches for `0004CB` / `IMEPane::~IMEPane`; UID00031K comment only. | [UID:0004CB] Generated notes; [UID:0000K5] Evidence/Changes. | incorporate | applied |
| C03 | Live MCP was available: database `supervisor_resume_20260629`, worker PID `14860`; initial no-database calls were schema/session errors, not outage. | MCP id `1210` `idb_list`; corrected calls ids `1212` through `1232`. | [UID:0004CB] Evidence. | incorporate | applied |
| C04 | UID0004CB exact boundary is `0x004e8000-0x004e8098`, size `0x98`, with `0xcc` padding after. | MCP ids `1221`, `1213`, `1223`. | [UID:0004CB] Evidence/Boundary; [UID:000189] row. | incorporate | applied |
| C05 | The body releases child slots `+0xf8`, `+0xfc`, and `+0x100`, mapped to `statusPane`, `activeChildPane`, and `candidatePane`. | MCP ids `1212`, `1213`; current [UID:00006H] and [UID:0004CE] docs. | [UID:0004CB] Behavior/Formal C++; [UID:00006H] method notes. | incorporate | applied |
| C06 | Child release helper is `Pane::MarkForDeletion` at `0x00544690`; direct formal code should call `MarkForDeletion()`. | MCP ids `1212`, `1213`, `1221`; PaneCore/Pane docs. | [UID:0004CB] Formal C++; [UID:00006H] Evidence. | incorporate | applied |
| C07 | No child-slot null stores occur in UID0004CB; do not add `statusPane = NULL`, `activeChildPane = NULL`, or `candidatePane = NULL` to destructor C++. | MCP disasm id `1213`. | [UID:0004CB] Reconstruction Notes/Formal C++ rationale. | incorporate | applied |
| C08 | Focus-list cleanup is the accepted `List::~List()` call at `0x004f30e0` on complete object `+0x104`. | MCP ids `1212`, `1213`, `1215`, `1222`; [UID:000192] docs. | [UID:0004CB] Evidence; [UID:00006H] support. | incorporate | applied |
| C09 | Formal destructor should not explicitly call `focusPaneList.~List()` under the current class shell; preserve focus-list teardown in prose/member cleanup evidence. | Current [UID:00006H] class shell; [UID:000192] List docs; UID00031K comment; MCP ids `1213`, `1231`, `1232`. | [UID:0004CB] Source Shape/Reconstruction Notes. | incorporate | applied |
| C10 | UID0004CB clears [UID:0000R7] `g_pIMEPane` at `0x004e8079`; storage bytes are currently zero/null. | MCP ids `1212`, `1213`, `1222`, `1223`; [UID:0001PS] doc. | [UID:0004CB] Formal C++; [UID:0000R7]/[UID:0001PS] already-present support. | incorporate | applied |
| C11 | `Pane` base teardown at `0x00544580` is compiler/base cleanup and must not be handwritten. | MCP ids `1212`, `1213`, `1221`; Pane docs. | [UID:0004CB] Reconstruction Notes. | incorporate | applied |
| C12 | Absence of direct xrefs to `0x004e8000` is not no-code proof; scalar wrapper UID00031K has vtable/thunk route and duplicates cleanup. | MCP id `1222`; [UID:00031K] page/generated comment. | [UID:0004CB] Negative evidence; [UID:00031K] support note. | incorporate | applied |
| C13 | Direct owner remains [UID:00006H] `IMEPane`; source file route remains [UID:0000K5] `IMEPanes`. | Target/class/file metadata; by-structure owner rules. | [UID:0004CB] metadata; [UID:00006H]/[UID:0000K5] support. | incorporate | applied |
| C14 | Recommended metadata is `88/91`, `EMITTER_UIDS:00006H`, owner/reconstructable unchanged. | Code gate, MCP evidence, current route, sibling constructor/destructor precedents. | [UID:0004CB] header and Score Rationale. | incorporate | applied |
| C15 | Reject no-code, aggregate-only, direct by-file owner, List/Pane/global/child-pane ownership, and scalar-wrapper merge. | Current docs, MCP role analysis, by-structure rules. | [UID:0004CB] Reconstruction Notes; [UID:0000K5]/[UID:000189] support. | incorporate | applied |
| C16 | [UID:00006H] should record UID0004CB as an emitting destructor and preserve focus list/List-count alias support. | Current class shell, MCP destructor evidence, List layout support. | `by-class/IMEPane.md` Method Notes/Observed State/Evidence. | incorporate | applied |
| C17 | [UID:0000K5] should record UID0004CB as an emitting `IMEPane::~IMEPane()` body routed through [UID:00006H]. | Current file route and generated output absence. | `by-file/IMEPanes.md` Proposed Contents/Evidence/Changes. | incorporate | applied |
| C18 | [UID:000189] aggregate should update the UID0004CB row and keep aggregate formal code as comment plus `[[CHILDREN]]`. | Aggregate split policy; current aggregate row. | `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`. | incorporate | applied |
| C19 | [UID:00031K] scalar deleting destructor remains comment-only/no handwritten wrapper, but should point to UID0004CB as the formal ordinary destructor if prose is touched. | Current scalar page and generated comment; MCP xrefs to wrapper. | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`. | incorporate | applied |
| C20 | g_pIMEPane global/storage, List destructor, and Pane helper docs already contain required supporting facts; no direct edits required for those pages. | Current docs and MCP ids `1215`, `1222`, `1223`. | `by-global/g_pIMEPane.md`, `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`, [UID:000192], Pane docs. | already-present | already-present |
| C21 | Generated files, generated reports, coverage reports, project-level reports, validator/tool state, ledgers, queues, archives, lock files, and IDA DB are excluded from manual edits. | User assignment and workflow. | Implementation checklist/no-edit statement. | not-applicable | excluded-with-reason |

Callback proof: C01-C15 are incorporated in `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` via metadata `88/91`, `EMITTER_UIDS:00006H`, formal `IMEPane::~IMEPane()` C++, Behavior/Evidence/Reconstruction Notes/Score Rationale/Changes sections, target validator command `000000004196`, and final generated freshness command `000000004200`. C16 is incorporated in `by-class/IMEPane.md`; C17 in `by-file/IMEPanes.md`; C18 in `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`; C19 in `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`. C20 remains already present in the named support docs and was intentionally not edited. C21 is excluded from manual editing because those files are validator/tool/generated/supervisor-owned or IDA state; generated outputs were refreshed only through approved validator commands.

## Implementation Tracking Checklist

Callback implementation pass completed on 2026-07-02.

- [x] Supervisor validation required before any by-* implementation. Proof: current `goal.md` assigned implementation callback for the already accepted UID0004CB report.
- [x] Edited `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`: metadata is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006H`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Edited `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`: inserted the exact formal `IMEPane::~IMEPane()` C++ body from this report.
- [x] Edited `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`: Item Summary, Status, Behavior, Evidence, Reconstruction Notes, Score Rationale, and Changes now preserve the emitting route, exact range/padding, child release, focus-list cleanup evidence, singleton clear, compiler/base cleanup split, scalar-wrapper separation, no child-slot null stores, and rejected alternatives.
- [x] Edited `by-class/IMEPane.md`: Method Notes, Observed State, Evidence Notes, and Changes now record UID0004CB as the emitting destructor, the three child slots, `Pane::MarkForDeletion`, owned `focusPaneList` cleanup, `focusPaneCount +0x110` list-count alias, singleton clear, and scalar-wrapper separation.
- [x] Edited `by-file/IMEPanes.md`: Proposed Contents, Evidence Notes, and Changes now record UID0004CB as an emitting `IMEPane::~IMEPane()` body through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`; no metadata changed.
- [x] Edited `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: Covered Ranges, split/source-placement row, and Changes now record UID0004CB `88/91`, formal destructor C++ populated, exact `0x98` boundary, child release slots, focus-list teardown, singleton clear, scalar-wrapper separation, and rejected alternatives; aggregate formal C++ remains comment plus `[[CHILDREN]]`.
- [x] Edited `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`: formal proof comment, Reconstruction Notes, and Changes now point to UID0004CB as the formal ordinary destructor while preserving comment-only/no-handwritten-wrapper disposition and metadata.
- [x] Confirmed no manual edits were made to `by-global/g_pIMEPane.md`, `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`, `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`, Pane support docs, generated files, generated reports, coverage reports, project-level generated reports, validator/tool state, ledgers, queues, archives, lock files, or IDA DB. Generated outputs changed only through validator.
- [x] Ran `python .\tools\validator.py --mode file --file by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004196`, command_timestamp `2026-07-02T04:34:03-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran `python .\tools\validator.py --mode file --file by-class/IMEPane.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004197`, command_timestamp `2026-07-02T04:34:23-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004198`, command_timestamp `2026-07-02T04:34:35-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004199`, command_timestamp `2026-07-02T04:34:47-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran `python .\tools\validator.py --mode file --file by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`: command_id `000000004200`, command_timestamp `2026-07-02T04:34:58-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Inspected `auto-generated/NexusTK/input/IMEPanes.cpp`: initial post-validation header matched final relevant command `validator-command-id: 000000004200`, `validator-refreshed-at: 2026-07-02T04:34:58-04:00`; a later generated refresh advanced the header to `validator-command-id: 000000004205`, `validator-refreshed-at: 2026-07-02T04:40:07-04:00`, which is newer than B011's final relevant command. UID0004CB marker/body and `IMEPane::~IMEPane()` are present; UID00031K comment points to UID0004CB; UID0004CE output remains present.
- [x] Updated this report's Claim And Incorporation Ledger from `proposed` to callback states with proof for every accepted claim.
- [x] Lease proof: first attempted lease at `2026-07-02T08:29:35Z` partially acquired UID0004CB and UID00031K but hit active B006 support-doc leases; those partial leases were released immediately. After B006 leases expired, B011 acquired all five approved by-* leases for the edit/validator batch and released them after validation. Current lease report after release shows no active B011 leases.

## Implementation Callback Work Performed

Final callback status: ready for supervisor `execute_report`.

- Read and followed the current B011 `goal.md` and project `ntk-b-agent-workflow` instructions. The legacy `AUTHOR-AGENT-SPECS` provenance header was preserved unchanged because this accepted report predates the current Medium default.
- Updated only the approved target/support by-* docs and this report. Manual by-* changes were made to `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`, `by-class/IMEPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, and `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`.
- UID0004CB now has metadata `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006H`, blank `EMITTER_POSITION_OPTIONAL`, and the formal `IMEPane::~IMEPane()` C++ body from this report.
- Incorporated the accepted evidence and rejected alternatives into the target/support docs: exact `0x004e8000-0x004e8098` / `0x98` boundary, post-function `0xcc` padding, child-slot release through `Pane::MarkForDeletion`, owned `focusPaneList` / `List::~List()` cleanup evidence, `g_pIMEPane = NULL`, Pane base teardown as compiler/base cleanup, scalar-wrapper separation, no raw helper names, no child-slot nulling statements, no handwritten vtable/EH/base/scalar-delete code, and no no-code/direct-file/aggregate disposition.
- Lease status: an initial lease attempt at `2026-07-02T08:29:35Z` partially acquired UID0004CB and UID00031K but hit active B006 leases on support docs; those partial B011 leases were immediately released. After B006 leases expired, B011 acquired the five approved by-* leases for the edit/validator batch and released them after validation. Final lease report showed no active B011 leases.
- Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`: command `000000004196` at `2026-07-02T04:34:03-04:00` for UID0004CB target, command `000000004197` at `2026-07-02T04:34:23-04:00` for `by-class/IMEPane.md`, command `000000004198` at `2026-07-02T04:34:35-04:00` for `by-file/IMEPanes.md`, command `000000004199` at `2026-07-02T04:34:47-04:00` for the IMEPaneFamily aggregate, and command `000000004200` at `2026-07-02T04:34:58-04:00` for UID00031K scalar wrapper. All exited `0` with `ok: 1` and `generated_refresh: completed`.
- Generated freshness: `auto-generated/NexusTK/input/IMEPanes.cpp` initially matched final relevant B011 command `000000004200` / `2026-07-02T04:34:58-04:00`; a later validator refresh advanced it to command `000000004205` / `2026-07-02T04:40:07-04:00`, which is newer than B011's final relevant command. The generated file contains the UID0004CB marker/body and `IMEPane::~IMEPane()`; UID00031K points to UID0004CB; UID0004CE output remains present.
- No manual edits were made to generated files, coverage reports, project-level generated reports, validator/tool state, supervisor ledgers, queues, locks, archives, by-project-structure docs, or IDA DB. Generated/project-level/tool-owned files changed only as validator-driven side effects during the approved scoped validation batch.
- Did not spawn subagents. No MCP-dependent work was required during this cleanup because the report evidence had already been accepted and the callback implementation had already been substantively verified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004214","destination_path":"executed-b-agent-research/B011/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md","timestamp":"2026-07-02T04:53:57-04:00","uid":"0004CB"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004CB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
