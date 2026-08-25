** TARGET-REPORT-UID:0002A9 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002A9 TargetSelectionModeFlags Source-Quality Research

Agent: Agent-B009  
Assignment: B009-report-0002A9-target-selection-mode-flags-20260625  
Target: [UID:0002A9] `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`  
Mode: report-only, no leases, no by-* edits, no generated or coverage edits  
IDA MCP endpoint used: `http://127.0.0.1:13337/mcp`

## Current recommendation

Update [UID:0002A9] from a provisional flag cluster to an implementation-ready static-data declaration page for two file-scope booleans owned by [UID:0000OH] `TargetSelectionInputPanes`.

Recommended source-facing names:

- `0x0069bed9`: `s_selectObjectTargetModeActive`
- `0x0069beda`: `s_targetObjectTargetModeActive`

`s_targetObjectMapSelectionActive` is a useful semantic alias for prose because the byte is set while forwarding into map-selection/target-dispatch mode, but it should not be the primary formal declaration name. The `TargetObjectWithKeyboardPane` class, the paired saved-target dword `s_targetObjectTargetId`, and accepted B005 TargetObject wording all point to `s_targetObjectTargetModeActive` as the more consistent source-facing declaration.

Do not split this target. Keep `0x0069bed8` and `0x0069bedb-0x0069bedf` documented as unreferenced zero allocation/alignment bytes inside the existing binary coverage range. Current evidence does not justify dummy source variables or explicit padding declarations for those bytes.

Populate formal C++ now. This target satisfies the active by-structure C++ gate: it is reconstructable, has nonblank owner/emitter metadata, has direct file placement, and its current `(COMPLETION + CONFIDENCE) / 2` is `87`, above the active `>85` threshold. This report resolves the remaining names/declaration/packing blockers.

Recommended target metadata after incorporation:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000OH` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000OH` unchanged
- `EMITTER_POSITION_OPTIONAL:` blank unchanged
- `Nested:0` unchanged

Recommended item summary:

```text
Two TargetSelectionInputPanes file-scope mode bools: `s_selectObjectTargetModeActive` at `0x0069bed9` and `s_targetObjectTargetModeActive` at `0x0069beda`; surrounding bytes are unreferenced zero allocation/alignment bytes in the same static-data range.
```

## MCP availability and session facts

The supervisor-required IDA MCP endpoint was available and responsive.

- MCP `initialize` and `tools/list` succeeded against `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` returned active session `80de0a67`.
- `server_health` for `80de0a67` returned healthy:
  - module: `NexusTK.exe`
  - IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - imagebase: `0x400000`
  - `auto_analysis_ready: true`
  - `hexrays_ready: true`
  - `strings_cache_ready: true`

No IDA DB edits, renames, comments, types, function creation, or process-management actions were made.

## Evidence checked

Primary documents:

- [UID:0002A9] `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`
- [UID:0000OH] `by-file/TargetSelectionInputPanes.md`
- [UID:0001L8] `by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md`
- [UID:0000CT] `by-class/SelectObjectWithKeyboardPane.md`
- [UID:0000ED] `by-class/TargetObjectWithKeyboardPane.md`
- [UID:0002AB] `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`
- [UID:0002AA] `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md`
- [UID:0001LB], [UID:0001LD], [UID:0001LH], [UID:0001LI], [UID:0001LK], and [UID:00036U] exact handler/helper pages
- Executed B005 SelectObject and TargetObject reports, plus B013 ItemWho report as negative evidence

Current MCP evidence:

- `xrefs_to 0x0069bed8` returned `0` refs.
- `xrefs_to 0x0069bed9` returned `9` refs: `0x5a6f6f`, `0x5ad4ad`, `0x5ad52a`, `0x5ad560`, `0x5ad660`, `0x5af6c4`, `0x5af79f`, `0x5af7eb`, and `0x5afebe`.
- `xrefs_to 0x0069beda` returned `8` refs: `0x5a5e9a`, `0x5a6f76`, `0x5ad4b4`, `0x5ad567`, `0x5ad63e`, `0x5affc4`, `0x5b008e`, and `0x5b0745`.
- `xrefs_to` for every byte from `0x0069bedb` through `0x0069bedf` returned `0` refs.
- `xrefs_to 0x0069bee0` returned `4` refs into UserPane/local-player-name helpers, proving the next independent object boundary.
- `get_bytes 0x0069bed8 size 72` returned all zero bytes through the local-name buffer lead-in.
- Direct address-pattern search found `9` matches for `d9 be 69 00`, `8` matches for `da be 69 00`, `0` matches for `d8 be 69 00` and `db/de...df be 69 00`, and `4` matches for `e0 be 69 00`.
- `entity_query(kind=names/globals, 0x0069bed0-0x0069bf40)` returned zero named entities/globals, so no original symbol names are present in the IDB window.

Relevant decompilation evidence:

- `sub_5AF5F0` (`SelectObjectWithKeyboardPane` constructor) clears `unk_69BED9` at `0x005af6c4`.
- `sub_5AF710` (`SelectObjectWithKeyboardPane::OnKeyEvent`) clears `unk_69BED9` on Enter and cancel paths at `0x005af79f` and `0x005af7eb`.
- `sub_5AFE70` (`SelectObjectWithKeyboardPane` forward-tab helper) sets `unk_69BED9 = 1` at `0x005afebe` after resolving `unk_69BF28` and priming active map target state.
- `sub_5AFEF0` (`TargetObjectWithKeyboardPane` constructor) clears `unk_69BEDA` at `0x005affc4`.
- `sub_5B0010` (`TargetObjectWithKeyboardPane::OnKeyEvent`) clears `unk_69BEDA` on cancel at `0x005b008e` and calls `sub_5B06F0` on Tab/`v` forwarding.
- `sub_5B06F0` (`TargetObjectWithKeyboardPane` dispatch-forward helper) sets `unk_69BEDA = 1` at `0x005b0745` and copies `unk_69BF2C` to `unk_69BF30`.
- `sub_5AD450` clears both bytes when exiting active target-selection mode and otherwise constructs `SelectObjectWithKeyboardPane`.
- `sub_5AD500` compares/clears `unk_69BED9`, clears `unk_69BEDA`, or sets `unk_69BEDA = 1` while entering TargetObject map-selection state and updating `unk_69BF2C/unk_69BF30`.
- `sub_5AD660` gates target-object navigation when `unk_69BED9 != 1`; this is a cross-flow guard proving the two adjacent bytes are separate mode flags, not aliases.
- `sub_5A5BD0` compares `unk_69BEDA == 1` before dispatching `sub_5AD660` versus `sub_5AD500`, and later clears both bytes at `0x005a6f6f`/`0x005a6f76`.

## Positive evidence

The two live bytes are independent file-scope flags:

- `0x0069bed9` is written only by SelectObject setup/cleanup and shared UserPane cleanup paths. Its best name is `s_selectObjectTargetModeActive`.
- `0x0069beda` is written by TargetObject setup/cleanup and shared UserPane cleanup paths. Its best formal name is `s_targetObjectTargetModeActive`, with `s_targetObjectMapSelectionActive` retained as a semantic alias.
- Both are absolute `.data` byte accesses. None are object-relative fields on `SelectObjectWithKeyboardPane`, `TargetObjectWithKeyboardPane`, `MapPane`, or `UserPane`.
- The saved-target dword pair supports the same naming split: `dword_69BF28` is `s_selectObjectTargetId`, while `dword_69BF2C` is `s_targetObjectTargetId`.
- Accepted B005 reports already converged on these names from SelectObject and TargetObject method-body evidence.

The binary range is still useful as one target:

- The live flags are adjacent and share direct owner/emitter [UID:0000OH].
- The unreferenced surrounding bytes have no separate name, xref, function owner, or direct address encoding.
- Splitting into one-byte pages would create padding-only children around two adjacent source declarations and would not improve source placement.
- The next object starts at `0x0069bee0` and belongs to [UID:0002AA] `LocalPlayerNameWideBuffer`, with a different owner [UID:0000P1].

## Negative evidence and rejected alternatives

Rejected `struct TargetSelectionModeFlags`:

- No code takes the address of the cluster as a unit.
- No xref reads or writes a word/dword covering both bytes.
- No IDB name, global entity, or type evidence exists for a grouped record.
- The handlers reason about the two flags by separate source families: SelectObject and TargetObject.

Rejected explicit source padding or dummy variables:

- `0x0069bed8` and `0x0069bedb-0x0069bedf` have no current xrefs and no direct address-constant matches.
- Adding `char pad[...]`, `bool unused`, or a fake named byte would overfit final binary layout and invent source not evidenced by current code.
- These bytes should remain documented as binary allocation/alignment coverage, not emitted as source declarations.

Rejected class-member fields:

- All accesses are absolute-address byte refs, not `this + offset`.
- UserPane and shared target-selection helpers can clear both flags without an object receiver.
- The pane class docs correctly treat the flags as file-scope state consumed by methods.

Rejected generic names such as `s_targetSelectionModeActive`:

- There are two distinct bytes with separate set/clear ownership.
- Generic naming collapses the SelectObject and TargetObject flows and loses the pairing with `s_selectObjectTargetId` and `s_targetObjectTargetId`.

Rejected UserPane, MapPane, and generic DataSection ownership:

- UserPane clears the flags but does not own the target-selection pane source family.
- MapPane provides lookup/highlight/temporary target-state dependencies, but the mode flags are owned by the target-selection input panes that enter/exit those modes.
- The broad DataSection page is only a container; it should not own declaration C++ for this specific static-data child.

Rejected no-code/blank formal C++:

- The current page already clears the active code gate.
- The remaining blockers were exact names and declaration shape; this pass resolves them with source-facing names and a two-bool declaration.
- Blank C++ would preserve a stale blocker after the evidence now supports declarations.

## Ranked source declarations

1. `static bool s_selectObjectTargetModeActive = false;` and `static bool s_targetObjectTargetModeActive = false;`  
   Best match. This uses file-scope storage in `TargetSelectionInputPanes.cpp`, keeps the two flows distinct, matches accepted B005 names, and avoids invented padding.

2. `static bool s_selectObjectTargetModeActive;` and `static bool s_targetObjectTargetModeActive;` without explicit initializers  
   Semantically equivalent in C++ because file-scope statics zero-initialize. Less explicit for this documentation page, which is proving zero initial storage.

3. `static bool s_targetObjectMapSelectionActive = false;` for the second byte  
   Acceptable as an explanatory alias only. It describes the mode, but it is less consistent with the class and saved-target naming family than `s_targetObjectTargetModeActive`.

4. A packed struct or byte array  
   Rejected. There is no grouped access evidence and it would imply a source-level aggregate not currently proved.

5. Any explicit padding declaration  
   Rejected. No source-facing dummy bytes are proved.

## Source placement

Direct source route stays [UID:0000OH] `TargetSelectionInputPanes` / `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.

The flags should be documented near the saved-target globals and keyboard selector singleton globals in this module. Class-level docs can mention the flags as dependencies, but declaration ownership remains file-scope because both class methods and shared UserPane/target-selection helpers touch the bytes.

No source move is recommended to `UserPane.cpp`, `MapPane.cpp`, `DataSection`, or a by-global singleton page.

## First-draft C++ readiness

Formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0002A9]:

```cpp
static bool s_selectObjectTargetModeActive = false;
static bool s_targetObjectTargetModeActive = false;
```

This is declaration-only formal C++. It intentionally omits `0x0069bed8` and `0x0069bedb-0x0069bedf`; those bytes remain binary allocation/alignment coverage in the target prose, not source declarations.

## Score rationale

Recommended `90/91`, not higher:

- Completion rises because the report resolves the previous explicit blockers: final source-facing names, declaration shape, packing/no-split treatment, owner/emitter route, and C++ eligibility.
- Confidence rises because current MCP evidence reconfirms exact xrefs, direct address encodings, decompiled set/clear/compare sites, zero direct refs to padding bytes, and independent next-object boundary.
- Scores should not exceed low 90s because no original source symbols are recovered and the exact original spelling of `targetMode` versus `mapSelection` remains inferred from behavior and accepted naming conventions, not from debug symbols or strings.

## Implementation recommendations

Update [UID:0002A9] `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`:

- Change `COMPLETION:86` to `COMPLETION:90`.
- Change `CONFIDENCE:88` to `CONFIDENCE:91`.
- Keep owner/emitter metadata unchanged.
- Insert the formal C++ block above.
- Replace provisional summary language with the recommended item summary.
- Update status/confidence/autogen notes so they no longer say final names/declarations are unresolved.
- Update storage rows:
  - `0x0069bed8`: unreferenced zero allocation/alignment byte; no source declaration.
  - `0x0069bed9`: `s_selectObjectTargetModeActive`.
  - `0x0069beda`: `s_targetObjectTargetModeActive`; mention `s_targetObjectMapSelectionActive` as semantic alias only.
  - `0x0069bedb-0x0069bedf`: unreferenced zero allocation/alignment bytes; no source declaration.
- Add B009 MCP evidence and score rationale.

Update [UID:0000OH] `by-file/TargetSelectionInputPanes.md`:

- Add a B009 support note that [UID:0002A9] now emits two file-scope bool declarations.
- Refine the static-data row for temporary target-selection mode flags to include the declaration names, not only "two active bytes."
- Keep score `89/85` unchanged unless the supervisor wants a broader file-level rescore; the file-level split/original-file-name uncertainty remains outside this target.

Update [UID:0001Z8] `by-memory/0x0066d000-0x0069d000.DataSection.md`:

- Replace the stale child-work note saying [UID:0002A9] still needs final declaration/name decisions.
- Add a B009 note that [UID:0002A9] is now resolved as two TargetSelectionInputPanes static bool declarations with surrounding no-source allocation/alignment bytes.
- Do not change DataSection score unless a broader data-section child queue pass is in scope.

No required edits found for:

- [UID:0000CT] `by-class/SelectObjectWithKeyboardPane.md`: already records `s_selectObjectTargetModeActive`.
- [UID:0000ED] `by-class/TargetObjectWithKeyboardPane.md`: already records `s_targetObjectTargetModeActive` / `s_targetObjectMapSelectionActive`.
- [UID:0002AB] `TargetSelectionSavedTargetGlobals`: already has the paired saved-target names.
- [UID:0002AA] `LocalPlayerNameWideBuffer`: only serves as next-boundary evidence.

Do not edit generated reports, project-level generated files, validator state/cache, IDA DB files, or any `-coverage-report.md` file during incorporation.

## Validator plan for implementation callback

Run scoped validators after the implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002A9-TargetSelectionModeFlags-source-quality-removed.md](0002A9-TargetSelectionModeFlags-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If validator syntax differs in the active repo scripts, keep the same three-file scope and use the repo-supported equivalent.

## Implementation tracking checklist

- [x] Leased `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` only when ready to edit it immediately.
  - Proof: `python leaser.py B009 lease ...TargetSelectionModeFlags.md ...TargetSelectionInputPanes.md ...DataSection.md` returned `Success` for this file at the start of the edit/validator batch.
- [x] Updated [UID:0002A9] metadata to `COMPLETION:90`, `CONFIDENCE:91`; kept owner/emitter `0000OH`, reconstructable `TRUE`, optional emitter position blank, and `Nested:0`.
  - Proof: `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OH`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- [x] Inserted formal C++ declarations:
  - [x] `static bool s_selectObjectTargetModeActive = false;`
  - [x] `static bool s_targetObjectTargetModeActive = false;`
  - Proof: both declarations are present between the formal `RECONSTRUCTION_CPP CODE:BEGIN/END` lines in [UID:0002A9].
- [x] Updated [UID:0002A9] item summary, storage table, evidence, reconstruction/autogen notes, score rationale, and changes log with B009 MCP proof.
  - Proof: [UID:0002A9] now records B009 session `80de0a67`, xrefs for `0x0069bed9`/`0x0069beda`, zero refs/pattern matches for allocation bytes, `0x0069bee0` next-boundary refs, decompiled set/clear/compare sites, direct address-pattern checks, no named global/entity evidence, accepted declarations, rejected grouped-struct/class-member/padding/DataSection ownership alternatives, score rationale, and a 2026-06-25 B009 change-log entry.
- [x] Released the [UID:0002A9] lease immediately after edit/validator batch.
  - Proof: `python leaser.py B009 unlease ...TargetSelectionModeFlags.md ...TargetSelectionInputPanes.md ...DataSection.md` returned `Success`; the post-release `current_leases.md` check had no B009 rows.
- [x] Leased `by-file/TargetSelectionInputPanes.md` only when ready to edit it immediately.
  - Proof: the same B009 lease command returned `Success` for `by-file/TargetSelectionInputPanes.md`.
- [x] Added B009 support evidence to [UID:0000OH] that [UID:0002A9] now emits two file-scope bool declarations and retains surrounding no-source allocation/alignment bytes.
  - Proof: `by-file/TargetSelectionInputPanes.md` File Role, Proposed Contents row, Boundary Notes, and Changes now name `s_selectObjectTargetModeActive`, `s_targetObjectTargetModeActive`, prose-only alias `s_targetObjectMapSelectionActive`, no-source bytes `0x0069bed8`/`0x0069bedb-0x0069bedf`, B009 xrefs, next-object boundary, and rejected alternatives.
- [x] Released the [UID:0000OH] lease immediately after edit/validator batch.
  - Proof: B009 `unlease` returned `Success`; final lease report has no B009 rows.
- [x] Leased `by-memory/0x0066d000-0x0069d000.DataSection.md` only when ready to edit it immediately.
  - Proof: the same B009 lease command returned `Success` for `by-memory/0x0066d000-0x0069d000.DataSection.md`.
- [x] Replaced stale DataSection child-work text that says [UID:0002A9] still needs final declaration/name decisions.
  - Proof: `by-memory/0x0066d000-0x0069d000.DataSection.md` now says [UID:0002A9] is resolved as two `TargetSelectionInputPanes.cpp` static bool declarations with surrounding no-source allocation/alignment bytes, and the Changes section records the stale-note replacement.
- [x] Released the DataSection lease immediately after edit/validator batch.
  - Proof: B009 `unlease` returned `Success`; final lease report has no B009 rows.
- [x] Left [UID:0000CT], [UID:0000ED], [UID:0002AB], and [UID:0002AA] untouched because the accepted report found no required edits and no direct contradiction appeared during implementation.
  - Proof: implementation changed only [UID:0002A9], [UID:0000OH], [UID:0001Z8], and this report checklist. The class/global/local-player pages already served as supporting context or boundary evidence at same-or-greater needed detail.
- [x] Ran scoped validators for the edited files listed above.
  - Proof: `python .\tools\validator.py --mode file --file "by-memory\0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md" --apply --queue-timeout 240 --wait-generated` from `source-3/project-documentation` returned exit code `0`, `command_id: 000000001740`, `command_timestamp: 2026-06-25T16:34:56-04:00`, `ok: 1`, and `generated_refresh: completed` with matching generated refresh id/timestamp.
  - Proof: `python .\tools\validator.py --mode file --file "by-file\TargetSelectionInputPanes.md" --apply --queue-timeout 240 --wait-generated` returned exit code `0`, `command_id: 000000001741`, `command_timestamp: 2026-06-25T16:35:21-04:00`, `ok: 1`, and `generated_refresh: completed` with matching generated refresh id/timestamp. Existing validator diagnostics included `missing_ref_uid: 40` for already-referenced prompt/helper UIDs not present in `validator.ini`.
  - Proof: `python .\tools\validator.py --mode file --file "by-memory\0x0066d000-0x0069d000.DataSection.md" --apply --queue-timeout 240 --wait-generated` returned exit code `0`, `command_id: 000000001744`, `command_timestamp: 2026-06-25T16:35:37-04:00`, `ok: 1`, and `generated_refresh: completed` with matching generated refresh id/timestamp. Existing validator diagnostics included two `missing_ref_target` rows for stale [UID:00027W] target path `by-memory/0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md`.
- [x] Confirmed no leases remain active for Agent-B009 after validation.
  - Proof: `tools/leaser/Agents/current_leases.md` read after release has no `B009` rows.
- [x] Did not manually edit `auto-generated/*`, `project-level/*`, `tools/leaser` state files, validator state/cache, IDA DB files, `by-memory/-coverage-report.md`, or any other `-coverage-report.md` file.
  - Proof: only manual edits were the three authorized by-* docs and this Agent-B009 report checklist. Validator-owned commands updated generated/autogen state as normal.
- [x] Coverage/tracker note: no manual coverage-report edit is required.
  - Proof: validator-owned generated refresh completed for all three scoped validators; no manual coverage/tracker row text is needed from B009.

## Report-only work log

- Created this report in `tools/leaser/Agents/Agent-B009/research/`.
- Took no leases.
- Edited no target/support by-* files.
- Ran no validators because this was report-only research.
- Used current IDA MCP evidence; did not continue from fallback-only documentation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002A9-TargetSelectionModeFlags-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002A9-TargetSelectionModeFlags-source-quality.md","timestamp":"2026-06-25T16:39:48","uid":"0002A9"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002A9-TargetSelectionModeFlags-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002A9-TargetSelectionModeFlags-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002A9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
