** TARGET-REPORT-UID:00028I **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00028I g_pFittingRoomDialog Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00028I] `0x0067a73c-0x0067a740.g_pFittingRoomDialog` as a reconstructable four-byte fitting-room dialog singleton pointer owned and emitted through [UID:0000JE] `FittingRoom`.
- Final disposition: target-only documentation/source-quality update is recommended. Add the formal global declaration `FittingRoomDialog *g_pFittingRoomDialog;` to the target's `RECONSTRUCTION_CPP CODE` block, raise metadata to `89/91`, and preserve the remaining class-layout caveat as a limit on full `FittingRoomDialog` declarations, not on the singleton pointer declaration.
- Required action: implementation callback should edit only `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`, unless the supervisor asks for optional support cross-reference wording.
- Confidence: high for storage, owner/emitter, xref inventory, and global declaration; lower only for the complete `FittingRoomDialog` field/base layout, which is outside this target's four-byte declaration.

## Supporting Research
- Lifecycle/status notes: this is a new report-only research artifact for UID00028I. No implementation, validation, lifecycle, archive, or execute-report command was run during this pass.
- Current MCP session used: `c9ac3d5b`, not stale session `31debdf2`.
- Report-only boundary observed: no `by-*`, generated, coverage, validator-state, lifecycle-state, archive, or supervisor-ledger files were edited.

## Target
- Target UID: `00028I`.
- Target path: `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> not-covered reconstructable row for UID00028I at `85/88`, average `86.5`, `true`, no executed B report.
- Current supervisor classification: report-only B-agent source-quality research first.
- Current scores and parent state: target page is `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JE`, `Nested:0`, blank formal C++; parent [UID:0000JE] `FittingRoom` is `88/90` with `NexusTK/cashshop/` route.

## Current Target State
- Existing metadata: UID00028I, `85/88`, owner/emitter [UID:0000JE] `FittingRoom`, reconstructable true, blank emitter position, blank formal C++ block.
- Existing owner/emitter/reconstructable state: correct and should remain unchanged. The global is a source-level singleton pointer in `.data`, not compiler padding or a child function.
- Existing C++/emitter state: emitter route is valid but generated coverage reports `emits_code:false` because the formal C++ block is empty.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: the page says C++ is withheld until dialog layout/adjusted-receiver audit. Current evidence supports keeping that caveat for full class layout, but it is too broad for a global declaration using an incomplete `FittingRoomDialog` type.
- Related target/support docs checked: [UID:0000JE] `by-file/FittingRoom.md`, [UID:000050] `by-class/FittingRoomDialog.md`, [UID:0001OP] adjacent `g_pFileDownloader` storage, executed B reports for FileDownloader/fitting-room core/list-pane/item-state leads, generated tracker/coverage rows, and project stats.
- Current artifact/lifecycle status: report-only artifact created in `tools/leaser/Agents/Agent-B009/research/`; supervisor Gate 1 review is required before implementation.

## Executive Recommendation
- Best direct owner: [UID:0000JE] `FittingRoom`, because the storage is a file/module-level global singleton for the fitting-room dialog feature. It is referenced by constructor/destructor/cleanup, fitting-room request/list-pane code, and the UserPane open-state check.
- Target action: keep owner/emitter/reconstructable fields unchanged; add the exact formal global declaration; raise scores to `89/91`.
- Blocked condition removed: the complete class-layout audit is still pending, but a pointer declaration only requires the class name and singleton role, both already supported by current class and file docs plus live IDA.

## Supervisor Active Recheck
- Trigger: current supervisor/user assignment directed Agent-B009 to produce the report-only source-quality report first for UID00028I and later confirmed MCP restored with session `c9ac3d5b`.
- Split requirement: no split is required. The target is exactly one four-byte data slot `0x0067a73c-0x0067a740` between adjacent singleton pointers.
- Source-bearing children in scope: none. The target is a data singleton declaration; source-bearing behavior remains in existing function/method pages.

## Inference Research Guidance Check
- `by-structure.md` says source-quality investigation continues past `85/85` and C++ may be written only as exact formal block insertion text. This report therefore recommends a formal declaration block, not a standalone snippet.
- Existing documentation assumptions treated as uncertain: the old claim that any final C++ must wait for full dialog layout was rechecked. It is valid for full class layout but not for a four-byte pointer declaration.
- IDA fact: current bytes, xrefs, and decompiler output identify `dword_67A73C` as zero-initialized pointer storage written by the constructor and cleared by teardown paths.
- Documentation evidence: `FittingRoom` and `FittingRoomDialog` already own the feature route and class name; FileDownloader reports treat `0x0067a73c` as a separate fitting-room dialog pointer.
- Inference: source-level declaration should be a module-scope `FittingRoomDialog *g_pFittingRoomDialog;`.
- Wave2/Wave3: `FittingRoom.md` mentions Wave3 only as historical lead material; no stale Wave2/Wave3 artifact was used as authority.

## Heuristic / Inference Reanalysis And Validation
- Global name/type: `g_pFittingRoomDialog` / `FittingRoomDialog *` is inferred but strongly validated by constructor vtable stores, class docs, method inventory, and every xref role. It is source-facing and not an IDA-only `dword_` name.
- Source placement: file-level `FittingRoom` ownership is better than direct class ownership because a global singleton declaration belongs in the fitting-room module source/header context while the class page owns methods/layout.
- C++ readiness: the exact storage is four bytes, zero-initialized, xref-complete, and routed to a valid emitter. A global declaration does not require final offsets such as `+0x504`, `+0x790`, or `+0x7a8`.
- Rejected alternatives: `FileDownloader` is rejected as owner because it only consumes fitting-room state in item-shop request paths; `FittingRoomDialog` class page is rejected as direct owner for the global declaration because the module owns file-scope singleton state; adjacent `g_pFileDownloader`/`g_pBackPane` slots are rejected by exact xref and boundary evidence; no-owner/non-emitting is rejected because owner and emitter gates are met.
- Remaining unresolved issue: complete `FittingRoomDialog` inheritance/field layout remains below final, so do not add a full class declaration here.

## Evidence Standards Used
- Evidence types used: current IDA MCP `server_health`, `lookup_funcs`, `get_bytes`, `get_global_value`, `xrefs_to`, `find_bytes`, and targeted `analyze_function`; current by-* target/support docs; generated tracker/coverage rows; executed B reports as leads only.
- Strength: storage, xrefs, constructor/destructor clears, and owner route are direct binary/documentation facts. The only inferential layer is whether the source spelling used `g_pFittingRoomDialog`; that is already the project-wide source-facing name and matches existing support docs.
- Tool limits: `analyze_function` for the constructor truncated after enough early-body evidence to show the singleton write, vtable stores, and important field initializers; full constructor body is documented in child pages and not required for this global declaration.

## Evidence Checked
- IDA MCP checks performed against session `c9ac3d5b`: `server_health`; `lookup_funcs` for `0x0041bdd0`, `0x0041d440`, `0x0041d490`, `0x005a5bd0`, and `0x0067a73c`; `get_bytes` for `0x0067a730` size `48`; `get_global_value` for `0x0067a73c`; `xrefs_to` for `0x0067a73c` with limit `50`; `find_bytes` for VA bytes `3c a7 67 00` and RVA bytes `3c a7 27 00`; `analyze_function` for `0x0041bdd0`, `0x0041d440`, and `0x0041d490`.
- by-* docs and generated reports checked: target page, `by-file/FittingRoom.md`, `by-class/FittingRoomDialog.md`, adjacent `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.
- Old reports searched as leads with terms `00028I`, `0x0067a73c`, `67a73c`, `g_pFittingRoomDialog`, `dword_67A73C`, and `FittingRoomDialog`; matching executed FileDownloader/fitting-room reports were used only after current evidence checks.
- Negative checks performed: `lookup_funcs` confirms `0x0067a73c` is not a function; RVA byte pattern `3c a7 27 00` returns zero matches; adjacent-slot and FileDownloader ownership alternatives were checked and rejected.
- Failed/skipped checks during report-only research: no scoped validator was run before Gate 1. Implementation callback later ran the scoped file validator recorded under `Validator Results`. No lifecycle command was run. No broad unbounded MCP list/search/callgraph/type/batch-analysis call was used.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00028I is exact zero-initialized four-byte storage at `0x0067a73c-0x0067a740`. | High | MCP `get_bytes 0x0067a730 size 48`, `get_global_value 0x0067a73c -> 0x0`; target doc. | Target `Storage And Lifetime`, `Live IDA Evidence`, score rationale. | Applied/refresh detail. | applied: target `Live IDA Evidence` now records session `c9ac3d5b`, all-zero byte window, and global value. |
| C2 | The target has exactly 16 direct xrefs in current IDA. | High | MCP `xrefs_to 0x0067a73c limit 50` returned 16, `more:false`; VA byte pattern found 16 matches. | Target `Live IDA Evidence`, `Cross-References`. | Applied/refresh detail. | applied: target now records full 16-xref inventory, `more:false`, VA byte matches, and zero RVA matches. |
| C3 | Constructor `sub_41BDD0` writes `this` to `dword_67A73C` and guard-clears it. | High | MCP `analyze_function 0x0041bdd0` shows `dword_67A73C=this` at `0x41be26`, clear at `0x41be2d`, FittingRoomDialog vtable stores. | Target lifetime/evidence. | Applied. | applied: target `Live IDA Evidence` and `Reconstruction Notes` record constructor publish/guard-clear and vtable context. |
| C4 | Teardown clears are `sub_41D440`, raw `0x41c2eb`, and scalar deleting destructor `sub_41D490` at `0x41d52e`. | High | MCP xref set and `analyze_function` for `0x41d440`/`0x41d490`. | Target lifetime/evidence. | Applied/kept. | applied: target records raw clear, tiny helper body, and scalar deleting destructor clear. |
| C5 | File-level owner/emitter [UID:0000JE] `FittingRoom` remains correct. | High | Target metadata, support docs, xref roles, parent `88/90` route. | Target metadata/source placement. | Left unchanged. | already-present/applied: owner/emitter/reconstructable/nested metadata unchanged; source-placement reasoning expanded. |
| C6 | Formal C++ should be added as `FittingRoomDialog *g_pFittingRoomDialog;`. | Medium-high | Exact storage, owner/emitter route, average score >85, class name established in [UID:000050], declaration does not require full layout. | Target formal `RECONSTRUCTION_CPP CODE`. | Applied. | applied: formal block contains exactly `FittingRoomDialog *g_pFittingRoomDialog;`. |
| C7 | Raise target from `85/88` to `89/91`. | Medium-high | C++ readiness, refreshed current MCP evidence, already mature support docs. | Target metadata/score rationale. | Applied. | applied: metadata and score rationale now `89/91`; validator confirmed completion/confidence updates. |
| C8 | No support-doc edit is required by this report. | Medium-high | `FittingRoom`, `FittingRoomDialog`, FileDownloader reports already contain pointer role and owner route. | Support docs. | Not applicable. | not applicable: no support docs edited because the target was coherent and the report's support-doc conclusion remained correct. |

## Positive Evidence Summary
- Direct facts: current IDA health is OK for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; bytes around the target are zero; target value is `0`; xrefs are exactly the documented 16; constructor/destructor/cleanup paths write or clear the slot.
- Corroborating documentation: `FittingRoom` owns the source module; `FittingRoomDialog` documents singleton lifetime and method inventory; FileDownloader/item-shop reports use `g_pFittingRoomDialog` only as fitting-room state, not as downloader ownership.
- Strongest inference chain: a module-level fitting-room global that is written by the dialog constructor, cleared by dialog teardown, and read by fitting-room UI/request paths should emit as `FittingRoomDialog *g_pFittingRoomDialog;` in the fitting-room source route.

## IDA MCP Facts
- Function/range facts: `lookup_funcs` returns `sub_41BDD0` at `0x41bdd0` size `0x480`, `sub_41D440` at `0x41d440` size `0xb`, `sub_41D490` at `0x41d490` size `0xe2`, `sub_5A5BD0` at `0x5a5bd0` size `0x1852`, and `0x0067a73c` is not a function.
- Data/table/padding facts: `get_bytes 0x0067a730 size 48` returns all zero bytes, covering adjacent pointer slots; `get_global_value 0x0067a73c` returns `0x0`.
- Xref facts: `xrefs_to 0x0067a73c` returns 16 data xrefs and `more:false`: `0x41ad75`, `0x41b0ba`, `0x41b258`, `0x41be26`, `0x41be2d`, `0x41c2eb`, `0x41d440`, `0x41d52e`, `0x41ee16`, `0x41f108`, `0x41f48e`, `0x41fc38`, `0x41fd04`, `0x4201a8`, `0x420d03`, `0x5a7239`.
- Vtable/global/type facts: constructor analysis shows FittingRoomDialog vtable stores immediately after publishing the global; destructor analysis restores FittingRoomDialog vtables before clearing item/version/request state and `dword_67A73C`.
- Negative IDA facts: RVA pattern `3c a7 27 00` has zero matches; no function starts at `0x0067a73c`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067a73c-0x0067a740` | [UID:00028I] `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md` | global pointer singleton | TRUE | [UID:0000JE] `FittingRoom` | implemented `89/91` | target |
| `0x0067a738-0x0067a73c` | [UID:0001OP] adjacent stale `g_pCashShopRequest` / `g_pFileDownloader` | neighboring FileDownloader pointer | TRUE | [UID:0000JC] `FileDownloader` | `89/91` | boundary evidence only |
| `0x0067a740-0x0067a744` | `g_pBackPane` | neighboring UI singleton pointer | TRUE | not in scope | not rechecked | boundary evidence only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad75` in `sub_41AA00` | data read | DownloadCashShopVersion uses active fitting-room dialog state. |
| `0x0041b0ba` in `sub_41AE20` | data read | DownloadCashShopCatalog compares/uses fitting-room active request state. |
| `0x0041b258` in `sub_41B200` | data read | catalog submit helper stores active request through dialog when present. |
| `0x0041be26` in `sub_41BDD0` | data write | constructor publishes `this` to the singleton. |
| `0x0041be2d` in `sub_41BDD0` | data write | constructor guard/fallback clears the singleton. |
| `0x0041c2eb` | data write, no containing IDA function | raw cleanup/unwind clear near constructor tail. |
| `0x0041d440` in `sub_41D440` | data write | tiny clear helper sets singleton to zero. |
| `0x0041d52e` in `sub_41D490` | data write | scalar deleting destructor clears singleton after item-state cleanup. |
| `0x0041ee16` in `sub_41EE10` | data read | list-pane scroll-bar update reads dialog/item-state state. |
| `0x0041f108` in `sub_41F100` | data read | list-pane reset scroll position reads dialog/item-state state. |
| `0x0041f48e` in `sub_41F2B0` | data read | list-pane paint reads dialog/item-state/catalog state. |
| `0x0041fc38` in `sub_41FBA0` | data read | key-scroll path reads active dialog/list state. |
| `0x0041fd04`, `0x004201a8` in `sub_41FCD0` | data reads | input event path reads fitting-room item-state/selection state. |
| `0x00420d03` in `sub_420D00` | data read | selection-index validation reads dialog item-state/catalog. |
| `0x005a7239` in `sub_5A5BD0` | data read | UserPane checks whether the fitting-room dialog is already open before construction/dispatch. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page already records zero storage, 16 xrefs, constructor/destructor/cleanup writes, request/list-pane readers, and owner route; `FittingRoom.md` records the fitting-room source module; `FittingRoomDialog.md` records singleton lifetime and class method inventory.
- Existing docs that are stale, incomplete, or contradicted: target C++ withholding text is too broad. Full class-layout C++ should remain withheld, but the singleton pointer declaration is now source-quality ready.
- Generated/coverage report state: `auto-generated/-ag-research-tracker.md` lists UID00028I as not-covered reconstructable at `85/88`, average `86.5`; `auto-generated/-ag-coverage-report-by-memory.md` reports `emits_code:false` because the formal block is blank.

## Ranked Ownership Analysis

### 1. [UID:0000JE] FittingRoom
- Evidence for: feature source route owns FittingRoomDialog, list-pane, item-state, and singleton context; parent is `88/90`; xrefs are fitting-room constructor/destructor/list/request/UserPane open-state uses; source module route is already documented.
- Evidence against: the pointer names a class, so class support is important, but file-scope singleton declarations normally live at source-module/global level.
- Decision: keep as canonical owner and emitter.

### 2. [UID:000050] FittingRoomDialog
- Evidence for: constructor publishes the pointer, destructor clears it, and class docs explicitly document singleton lifetime.
- Evidence against: the global slot is not a method body or class layout field; direct class ownership would blur module-level static/global storage with class methods.
- Decision: support/context only, not canonical owner for this by-memory global.

### 3. [UID:0000JC] FileDownloader / adjacent [UID:0001OP]
- Evidence for: downloader helpers read/write fitting-room fields through the pointer during item-shop version/catalog flows.
- Evidence against: all downloader references are consumers of fitting-room state; adjacent `0x0067a738` is a separate FileDownloader singleton with its own nine-xref matrix and different owner.
- Decision: rejected as owner.

### 4. No-owner / non-emitting
- Evidence for: full class layout remains incomplete.
- Evidence against: exact storage, xrefs, owner route, source name, pointer type, and declaration shape are sufficiently supported.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new owner/file. Keep route through `NexusTK/cashshop/FittingRoom.cpp`.
- Likely full contents: the single declaration for this target only; method bodies remain in existing child pages.
- Candidate related items that belong: none to add. Adjacent singleton pointers remain separate pages.
- Candidate related items rejected: `g_pFileDownloader`, `g_pBackPane`, FileDownloader worker helpers, list-pane methods, and full `FittingRoomDialog` class layout.
- Standalone, narrow, or broad source-file inference: narrow module-level global declaration.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/cashshop/FittingRoom.cpp` route through [UID:0000JE] `FittingRoom`; declaration text may also imply a corresponding header/external declaration in final project organization, but this by-memory page should emit only its exact declaration.
- Why this placement fits source-tree and subsystem context: the pointer lifetime and readers are all fitting-room UI/item-shop state, while the file parent already groups the dialog/list/catalog/download controls.
- Rejected placements: `FileDownloader.cpp`, `ItemCatalog.cpp`, generic UI core, `by-global/g_pCashShopRequest`, and no-owner/non-emitting.
- Remaining placement uncertainty: exact header-vs-cpp split for the final project is not proven, but the current emitter route handles reconstructed output through `FittingRoom.cpp`.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target is `0x0067a73c-0x0067a740`, a single four-byte dword/pointer slot; `get_bytes 0x0067a730 size 48` shows the surrounding singleton run is zero-initialized.
- Children/subranges: none.
- Padding/table/data/code distinctions: this is `.data` pointer storage, not code and not padding.
- Parent/container impact: no split or reclassification is needed.

## Negative Evidence Summary
- `0x0067a73c` is not a function and has no child function inventory.
- RVA pointer-byte pattern `3c a7 27 00` has zero matches; VA immediate pattern has exactly the same 16 code matches as the xref inventory, so no hidden pointer table was found in the bounded evidence.
- Consumer reads in FileDownloader/list-pane/UserPane do not prove those consumers own the storage; constructor/destructor lifetime and fitting-room source route dominate ownership.
- Adjacent `0x0067a738` FileDownloader and `0x0067a740` BackPane slots are separate singleton pointers and should not be merged with this target.
- Full class-layout uncertainty does not block a pointer declaration, but it still blocks a complete class declaration in this target.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: source-facing declaration `FittingRoomDialog *g_pFittingRoomDialog;`. If IDA edits are ever requested by a supervisor, a data name/type could align with this, but this report does not request IDA DB edits.
- Evidence for each proposed name/type/comment: FittingRoomDialog constructor/destructor/vtable evidence and support docs.
- Items intentionally left unchanged and why: no IDA database rename/type/comment edits during report-only research.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The page is reconstructable, has a valid nonblank emitter route, and current score average is already greater than `85`; the recommendation raises evidence/scores further.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FittingRoomDialog *g_pFittingRoomDialog;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable.
- Reason it preserves exact original behavior: it declares the zero-initialized singleton pointer represented by the exact four-byte `.data` slot; it adds no behavior.
- Reason it matches plausible original precompiled source shape: a late-1990s/early-2000s UI feature module commonly keeps a process-wide dialog singleton pointer as a file/global declaration.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `FittingRoomDialog *g_pFittingRoomDialog` replaces `dword_67A73C`.
- Naming/coding style convention used and evidence for consistency: existing project global pointer naming uses `g_p...`, adjacent support pages use `g_pFittingRoomDialog`, and the class name is established as `FittingRoomDialog`.
- Reason code should remain blank, if applicable: not applicable for this target after current reanalysis.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended: update UID00028I target page with current MCP session `c9ac3d5b` evidence, 16-xref inventory, all-zero byte window, VA/RVA byte search results, constructor/destructor/clear analyses, rejected alternatives, formal C++ declaration, and revised score rationale.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:0000JE`, `EMITTER_UIDS:0000JE`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, and blank emitter position unchanged.
- Exact items left no-owner/non-emitting and why: none in this target.
- Exact future work outside assignment scope: full `FittingRoomDialog` class layout and header/cpp split can remain future work for the class page/method family; it should not block this global declaration.

## Recommended Target Doc Changes
- Target path: `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`.
- Exact report facts to incorporate: current MCP session `c9ac3d5b` health/path; lookup facts for `sub_41BDD0`, `sub_41D440`, `sub_41D490`, `sub_5A5BD0`, and non-function `0x0067a73c`; zero bytes at `0x0067a730-0x0067a760`; `get_global_value 0x0067a73c -> 0x0`; full 16-xref inventory; VA byte pattern 16 matches and RVA pattern zero matches; constructor write/guard-clear; tiny clear helper; scalar deleting destructor clear; rejected FileDownloader/class-only/no-owner alternatives.
- Metadata/score/owner/emitter/reconstructable/C++ changes: change `COMPLETION:85` to `COMPLETION:89`; change `CONFIDENCE:88` to `CONFIDENCE:91`; keep owner/emitter/reconstructable fields unchanged; insert exact formal C++ declaration above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve full class-layout caveat as a reason not to emit a full class declaration; remove or narrow wording that claims the singleton declaration itself must remain blank.

## Recommended Support Doc Changes
- Applicable support path: none required.
- Exact report facts to incorporate: not applicable because [UID:0000JE] and [UID:000050] already support the owner/class route, and FileDownloader support docs already treat this as a fitting-room state global.
- Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation
- Current score/metadata: `85/88`, owner/emitter [UID:0000JE], reconstructable true, blank C++.
- Recommended score/metadata: `89/91`, same owner/emitter/reconstructable fields, formal pointer declaration.
- Score rationale and reason not higher/lower: completion rises because the remaining emitter blocker is resolved and current MCP evidence refreshes bytes/xrefs/writers/readers. Confidence rises because pointer type/name and source route are strongly corroborated. Scores stay below final because complete class layout, exact original header placement, and final inherited base/field names are not fully proven.
- Score-improvement attempt: the prior blocker was "final declaration/type should wait for dialog layout and adjusted-receiver audit." Current research separated pointer declaration from full class layout and found the pointer declaration safe.
- Metadata fields to change or leave unchanged: change only completion/confidence and C++ block; leave UID, owner, reconstructable, emitters, emitter position, item path, and nested state unchanged.

## Open Questions With Attempted Resolution
- Open question: does multiple inheritance/adjusted receiver block declaring the singleton as `FittingRoomDialog *`? Evidence checked: constructor publishes unadjusted `this` to `dword_67A73C`, then writes FittingRoomDialog vtable groups; destructor clears the same global; class docs already use this class name. Resolution: no, it blocks only complete layout declarations.
- Open question: should this be class-owned instead of file-owned? Evidence checked: by-structure ownership guidance and support docs. Resolution: no, file-level source module ownership is better for a module/global singleton declaration.
- Open question: should support docs change? Evidence checked: `FittingRoom.md`, `FittingRoomDialog.md`, FileDownloader reports. Resolution: no required support edit; existing support is coherent.
- Remaining unresolved: exact original header placement is unknown. Score/C++ impact: not blocking for current by-memory formal declaration.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. The relevant tracker and generated coverage rows are validator/generated outputs and must not be manually edited by this B-agent report-only pass.
- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated/coverage files are out of scope; updates should flow from target doc changes and validator/generator refresh after supervisor-approved implementation.

## Follow-Up Actions
- Supervisor actions: Gate 1 review this report; if accepted, send implementation callback for target-only edit and scoped validator.
- A-agent actions: none required.
- B009 future research actions: after callback, update target doc and this report checklist/ledger, run only the scoped file validator requested by supervisor, and release any lease immediately.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high for `89/91`.
- Remaining uncertainty: exact original header/cpp split and full `FittingRoomDialog` layout.

## Validator Results
- Commands run: `python .\tools\validator.py --mode file --file by-memory\0x0067a73c-0x0067a740.g_pFittingRoomDialog.md --apply --queue-timeout 240`.
- Results: command_id `000000005349`, command_timestamp `2026-07-03T11:45:11-04:00`, exit code `0`, `ok: 1`.
- Validator details: scanned markdown files `1`; `completion_update 00028I ... 89`; `confidence_update 00028I ... 91`; `autogen_registry_update` recorded hash `7f95bbfa7b3363d7a2b6923c3dfb5151224fd3304cbce04153d0abcb5a37a7d8` and `blank -> block`; `uid_link_insert 0000JE`; `reference_index_add 0000JC`; `stats_row_remove` for UID00028I from `Low_Completion_Reconstructable`, `Low_Both_Reconstructable`, and `by-memory_Reconstructable`; `projected_stats_update: 1`; `stats_rescore_recommended: 1`; `generated_refresh: deferred`; generated_refresh_command_id `000000005349`, generated_refresh_timestamp `2026-07-03T11:45:11-04:00`.
- Any unresolved validator warnings/errors: no validator errors or warning lines; only `stats_rescore_recommended` advisory.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B009/research/00028I-g_pFittingRoomDialog-source-quality.md`.
- Modified: `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`; `tools/leaser/Agents/Agent-B009/research/00028I-g_pFittingRoomDialog-source-quality.md`.
- Renamed: none.
- Report execution: not run.

## Implementation Tracking Checklist

Implementation callback:
- [x] Supervisor validation required before implementation. Gate 1 passed for SHA256 `90E7BF91C2F67AAC8FEB62EA7F195FBD8180C5ED85560730DC6A4BC2E593BB0A`; implementation callback received.
- [x] Target/support docs to update: target-only edit applied to `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`; no support doc edit required because support docs were already coherent.
- [x] Current target state and actual evidence checked recorded: target now records current MCP session `c9ac3d5b`, health/path, bytes/value/xrefs/find-bytes/analyze-function facts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger rows C1-C8 updated above.
- [x] Metadata/score changes to apply: changed `85/88 -> 89/91`; owner/emitter/reconstructable/nested metadata remained unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: target now narrows the class-layout caveat to full class/header declarations only and no longer blocks the singleton pointer declaration.
- [x] Owner/emitter/reconstructable changes to apply: none; confirmed unchanged in target metadata.
- [x] Split/rename/new-child changes to apply: none; exact four-byte slot remained intact.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement through [UID:0000JE] expanded; no split/reclassification or IDA DB edit requested.
- [x] First-draft C++ or no-code proof to apply: applied exact formal declaration `FittingRoomDialog *g_pFittingRoomDialog;`.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable; no import directive.
- [x] Exact target/support doc facts to incorporate at report-level detail: target incorporates MCP session `c9ac3d5b`, full 16 xrefs, zero bytes/value, function analyses, VA/RVA byte search, and rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: target preserves class-layout caveat only as a full-layout blocker and preserves FileDownloader/class-only/no-owner/adjacent-slot rejections.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no new Wave2/Wave3 dependency was added.
- [x] Open questions to close or document as evidence-backed unresolved: header placement and full class layout remain unresolved but nonblocking for this declaration.
- [x] Scoped validator to run only during implementation callback: ran command_id `000000005349`, exit `0`, `ok:1`.
- [x] Generated-refresh status to report after implementation callback: validator reported `generated_refresh: deferred` with validator-owned registry/projected-stat side effects only; no manual generated or coverage edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000005350","destination_path":"executed-b-agent-research/B009/00028I-g_pFittingRoomDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00028I-g_pFittingRoomDialog-source-quality.md","timestamp":"2026-07-03T11:49:21-04:00","uid":"00028I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
